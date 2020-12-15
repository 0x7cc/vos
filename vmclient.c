//
// Created by xxx on 2020/11/24.
//

#include "vmclient.h"
#include "x86_64.h"
#include "vostd.h"
#include "vmx.h"
#include "svm.h"

#include <Library/UefiLib.h>

struct vmclient {
  union {
    vmxcontext* vmx;
    svmcontext* svm;
  };
};

void printbin (const char* bin, int len) {
  for (int i = 0; i < len; ++i) {
    AsciiPrint ("%02X ", bin[i]);
  }
  AsciiPrint ("\n");
}

int vmclient_load (vmclient** client) {

  char vendor[16];

  cpuid_t c;
  v_cpuid (0, &c);
  ((vuint32*)vendor)[0] = c.ebx;
  ((vuint32*)vendor)[1] = c.edx;
  ((vuint32*)vendor)[2] = c.ecx;
  ((vuint32*)vendor)[3] = 0;

  AsciiPrint (vendor);

  if (AsciiStrnCmp (vendor, "GenuineIntel", 12) == 0) {
    vmclient* vmcli;
    vmcli = vmalloc (0x2000);
    vmx_load (&(vmcli->vmx));

    *client = vmcli;

    return 0;
  }

  if (AsciiStrnCmp (vendor, "AuthenticAMD", 12) == 0) {
    vmclient* vmcli;
    vmcli = vmalloc (0x2000);
    svm_load (&(vmcli->svm));

    *client = vmcli;

    return 0;
  }

  return -1;
}

int vmclient_unload (vmclient** vm) {
  return 0;
}

int vmclient_luanch (vmclient* vm) {
  return 0;
}
