//
// Created by xxx on 2020/11/22.
//

#include "svm.h"
#include "x86_64.h"

#include <Library/UefiLib.h>

// clang-format off
#define CPUID_80000001_ECX_SVM   (1u << 2)
#define CPUID_8000000A_EDX_NP    (1u << 0)        // Nested paging. Indicates support for nested paging. See “Nested Paging.”
#define CPUID_8000000A_EDX_SVML  (1u << 2)        // SVM lock. Indicates support for SVM-Lock. See “Enabling SVM.”
#define CPUID_8000000A_EDX_NRIP  (1u << 3)        // NRIP save. Indicates support for NRIP save on #VMEXIT. See “State Saved on Exit.”

#define PAGE_SIZE                       4096
#define MSR_VM_CR                       0xC0010114
#define SVM_MSR_VM_HSAVE_PA             0xc0010117
#define MSR_VM_CR_SVMDIS                (1ul << 4)
#define EFER_SVME                       (1ul << 12)
#define SVM_INTERCEPT_MISC1_CPUID       (1UL << 18)
#define SVM_INTERCEPT_MISC1_MSR_PROT    (1UL << 28)
#define SVM_INTERCEPT_MISC2_VMRUN       (1UL << 0)
#define SVM_NP_ENABLE_NP_ENABLE         (1UL << 0)
#define SVM_MSR_PERMISSIONS_MAP_SIZE    (PAGE_SIZE * 2)
#define IA32_MSR_PAT    0x00000277
#define IA32_MSR_EFER   0xc0000080

// clang-format on

void svm_vmexit_handler (SvmVMExitContext* ctx) {
}

int svm_load (svmcontext** ctx) {

  cpuid_t cpuid;

  // See: 15.4 Enabling SVM
  {
    __cpuid (0x80000001, &cpuid);

    if ((cpuid.ecx & CPUID_80000001_ECX_SVM) == 0) {
      AsciiErrorPrint ("CPUID_80000001_ECX_SVM\n");
      return -1;
    }

    __cpuid (0x8000000A, &cpuid);
    if ((cpuid.edx & CPUID_8000000A_EDX_NRIP) == 0) {
      AsciiErrorPrint ("CPUID_8000000A_EDX_NRIP\n");
      return -2;
    }

    vuint64 vm_cr = __rdmsr (MSR_VM_CR);
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
    __cpuid (0x8000000A, &cpuid);
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
  return 0;
}
