#include "svm.h"
#include "x86_64.h"

#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

// clang-format off
#define CPUID_80000001_ECX_SVM   (1u << 2)
#define CPUID_8000000A_EDX_NP    (1u << 0)        // Nested paging. Indicates support for nested paging. See "Nested Paging."
#define CPUID_8000000A_EDX_SVML  (1u << 2)        // SVM lock. Indicates support for SVM-Lock. See "Enabling SVM."
#define CPUID_8000000A_EDX_NRIP  (1u << 3)        // NRIP save. Indicates support for NRIP save on #VMEXIT. See "State Saved on Exit."

#define PAGE_SIZE                       4096
#define MSR_VM_CR                       0xC0010114
#define SVM_MSR_VM_HSAVE_PA             0xC0010117
#define MSR_VM_CR_SVMDIS                (1UL << 4)
#define EFER_SVME                       (1UL << 12)
#define SVM_INTERCEPT_MISC1_CPUID       (1UL << 18)
#define SVM_INTERCEPT_MISC1_MSR_PROT    (1UL << 28)
#define SVM_INTERCEPT_MISC2_VMRUN       (1UL << 0)
#define SVM_NP_ENABLE_NP_ENABLE         (1UL << 0)
#define SVM_MSR_PERMISSIONS_MAP_SIZE    (PAGE_SIZE * 2)
#define IA32_MSR_PAT    0x00000277
#define IA32_MSR_EFER   0xc0000080

// clang-format on

void v_svm_vmrun (VMCB*);
void v_svm_vmsave (VMCB*);
void v_svm_vmload (VMCB*);
void v_svm_vmmcall (void);
void v_svm_loop (VMCB*);

void svm_vmexit_handler (SvmVMExitContext* ctx) {
}

int svm_load (svmcontext** ctx) {

  cpuid_t cpuid;

  // See: 15.4 Enabling SVM
  {
    v_cpuid (0x80000001, &cpuid);

    if ((cpuid.ecx & CPUID_80000001_ECX_SVM) == 0) {
      AsciiErrorPrint ("CPUID_80000001_ECX_SVM\n");
      return -1;
    }

    v_cpuid (0x8000000A, &cpuid);
    if ((cpuid.edx & CPUID_8000000A_EDX_NRIP) == 0) {
      AsciiErrorPrint ("CPUID_8000000A_EDX_NRIP\n");
      return -2;
    }

    vuint64 vm_cr = v_rdmsr (MSR_VM_CR);
    if (vm_cr & MSR_VM_CR_SVMDIS) {
      if ((cpuid.edx & CPUID_8000000A_EDX_SVML) == 0) {
        AsciiErrorPrint ("The user must change a platform firmware setting to enable SVM.\n");
      } else {
        AsciiErrorPrint ("SVMLock may be unlockable; consult platform firmware or TPM to obtain the key.\n");
      }
      return -3;
    }
  }

  // See: 15.25.3 Enabling Nested Paging
  {
    v_cpuid (0x8000000A, &cpuid);
    if ((cpuid.edx & CPUID_8000000A_EDX_NP) == 0) {
      AsciiErrorPrint ("CPUID_8000000A_EDX_NP.\n");
      return -1;
    }
  }

  AsciiPrint ("svm feature loaded.\n");

  return 0;
}

int svm_unload (svmcontext** ctx) {
  return 0;
}

int svm_luanch (svmcontext* ctx) {
  gdtr_t gdtr;
  idtr_t idtr;
  v_sgdt (&gdtr);
  v_sidt (&idtr);

  v_wrmsr (0xc0000080, v_rdmsr (0xC0000080) | EFER_SVME);

  void* MsrPermissionsMap = nullptr;
  VMCB*   host_vmcb         = nullptr;
  VMCB*   guest_vmcb        = nullptr;
  void*   vm_hsave_pa       = nullptr;

  EFI_STATUS status = 0;

  status |= gBS->AllocatePool (EfiRuntimeServicesData, SVM_MSR_PERMISSIONS_MAP_SIZE, (void**)&MsrPermissionsMap);
  status |= gBS->AllocatePool (EfiRuntimeServicesData, sizeof (VMCB), (void**)&host_vmcb);
  status |= gBS->AllocatePool (EfiRuntimeServicesData, sizeof (VMCB), (void**)&guest_vmcb);
  status |= gBS->AllocatePool (EfiRuntimeServicesData, 4096, (void**)&vm_hsave_pa);

  if (EFI_ERROR (status)) {
    AsciiPrint ("EFI_BOOT_SERVICES::AllocatePool(EfiRuntimeServicesData, ...) failed.\n");
    goto err;
  }
  gBS->SetMem ((void*)MsrPermissionsMap, sizeof (SVM_MSR_PERMISSIONS_MAP_SIZE), 0);
  gBS->SetMem (host_vmcb, sizeof (VMCB), 0);
  gBS->SetMem (guest_vmcb, sizeof (VMCB), 0);
  gBS->SetMem (vm_hsave_pa, 4096, 0);

  guest_vmcb->ControlArea.InterceptMisc1 |= SVM_INTERCEPT_MISC1_CPUID;
  guest_vmcb->ControlArea.InterceptMisc2 |= SVM_INTERCEPT_MISC2_VMRUN;
  guest_vmcb->ControlArea.InterceptMisc1 |= SVM_INTERCEPT_MISC1_MSR_PROT;
  guest_vmcb->ControlArea.MsrpmBasePa = (vuintptr)MsrPermissionsMap;
  guest_vmcb->ControlArea.GuestAsid   = 1;
  // guest_vmcb->ControlArea.NpEnable |= SVM_NP_ENABLE_NP_ENABLE;
  guest_vmcb->ControlArea.NCr3        = 0;
  guest_vmcb->StateSaveArea.GdtrBase  = gdtr.base;
  guest_vmcb->StateSaveArea.GdtrLimit = gdtr.limit;
  guest_vmcb->StateSaveArea.IdtrBase  = idtr.base;
  guest_vmcb->StateSaveArea.IdtrLimit = idtr.limit;

  guest_vmcb->StateSaveArea.CsLimit    = 0xFFFFFFFF;
  guest_vmcb->StateSaveArea.DsLimit    = 0xFFFFFFFF;
  guest_vmcb->StateSaveArea.EsLimit    = 0xFFFFFFFF;
  guest_vmcb->StateSaveArea.SsLimit    = 0xFFFFFFFF;
  guest_vmcb->StateSaveArea.CsSelector = (vuint16)v_read_cs () & 0xfff8;
  guest_vmcb->StateSaveArea.DsSelector = (vuint16)v_read_ds () & 0xfff8;
  guest_vmcb->StateSaveArea.EsSelector = (vuint16)v_read_es () & 0xfff8;
  guest_vmcb->StateSaveArea.SsSelector = (vuint16)v_read_ss () & 0xfff8;
  AsciiPrint ("cs access rights : 0x%x\n", v_lar (v_read_cs ()));

  // See Intel: Table 24-2. Format of Access Rights
  guest_vmcb->StateSaveArea.CsAttrib = (vuint16)v_lar (v_read_cs ()) & 0x1FFFF;
  guest_vmcb->StateSaveArea.DsAttrib = (vuint16)v_lar (v_read_ds ()) & 0x1FFFF;
  guest_vmcb->StateSaveArea.EsAttrib = (vuint16)v_lar (v_read_es ()) & 0x1FFFF;
  guest_vmcb->StateSaveArea.SsAttrib = (vuint16)v_lar (v_read_ss ()) & 0x1FFFF;

  guest_vmcb->StateSaveArea.Efer   = v_rdmsr (IA32_MSR_EFER);
  guest_vmcb->StateSaveArea.Cr0    = v_read_cr0 ();
  guest_vmcb->StateSaveArea.Cr2    = v_read_cr2 ();
  guest_vmcb->StateSaveArea.Cr3    = v_read_cr3 ();
  guest_vmcb->StateSaveArea.Cr4    = v_read_cr4 ();
  guest_vmcb->StateSaveArea.Rflags = v_rflags ();
  guest_vmcb->StateSaveArea.Rsp    = 0;
  guest_vmcb->StateSaveArea.Rip    = 0;
  guest_vmcb->StateSaveArea.GPat   = v_rdmsr (IA32_MSR_PAT);

  v_svm_vmsave (guest_vmcb);

  // See: 15.30.4 VM_HSAVE_PA MSR (C001_0117h)
  v_wrmsr (SVM_MSR_VM_HSAVE_PA, (vuintptr)vm_hsave_pa);

  v_svm_vmsave (host_vmcb);

  v_svm_loop (guest_vmcb);
err:
  return 0;
}
