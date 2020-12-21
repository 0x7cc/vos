//
// Created by xxx on 2020/11/24.
//

#include "vmclient.h"
#include "x86_64.h"
#include "vostd.h"
#include "vmx.h"
#include "svm.h"

#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

struct vmclient {
  union {
    vmxcontext* vmx;
    svmcontext* svm;
  };
  char vendor[16];
};

void printbin (const char* bin, int len) {
  for (int i = 0; i < len; ++i) {
    AsciiPrint ("%02X ", bin[i]);
  }
  AsciiPrint ("\n");
}

int vmclient_load (vmclient** client) {
  int result = -1;

  char vendor[16];

  cpuid_t c;
  v_cpuid (0, &c);
  ((vuint32*)vendor)[0] = c.ebx;
  ((vuint32*)vendor)[1] = c.edx;
  ((vuint32*)vendor)[2] = c.ecx;
  ((vuint32*)vendor)[3] = 0;

  AsciiPrint ("%a\n", vendor);

  vmclient* vmcli;
  vmcli = vmalloc (0x2000);
  gBS->SetMem (vmcli, 0x2000, 0);
  gBS->CopyMem (vmcli->vendor, vendor, 12);

  if (AsciiStrnCmp (vendor, "GenuineIntel", 12) == 0) {
    vmx_load (&(vmcli->vmx));
  } else if (AsciiStrnCmp (vendor, "AuthenticAMD", 12) == 0) {
    svm_load (&(vmcli->svm));
  } else {
    goto err;
  }

  *client = vmcli;
  result  = 0;
err:
  return result;
}

int vmclient_unload (vmclient** vm) {
  return 0;
}

int vmclient_luanch (vmclient* vm) {
  if (AsciiStrnCmp (vm->vendor, "GenuineIntel", 12) == 0) {
    vmx_luanch (vm->vmx);
  }

  if (AsciiStrnCmp (vm->vendor, "AuthenticAMD", 12) == 0) {
    svm_luanch (vm->svm);
  }

  return 0;
}
