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
};

void printbin (const char* bin, int len) {
  for (int i = 0; i < len; ++i) {
    AsciiPrint ("%02X ", bin[i]);
  }
  AsciiPrint ("\n");
}

int vmclient_load (vmclient** vm) {

  char vendor[16];

  cpuid_t  c;
  vos_cpuid (0, &c);
  ((vuint32*)vendor)[0] = c.ebx;
  ((vuint32*)vendor)[1] = c.edx;
  ((vuint32*)vendor)[2] = c.ecx;
  ((vuint32*)vendor)[3] = 0;

  AsciiPrint ("%a 0x%016x\n", vendor, vendor);

  if (AsciiStrnCmp (vendor, "GenuineIntel", 12) == 0) {
    AsciiPrint ("vmalloc\n");
    *vm = vmalloc (0x2000);
    return 0;
  }

  if (AsciiStrnCmp (vendor, "AuthenticAMD", 12) == 0) {
    AsciiPrint ("vmalloc\n");
    *vm = vmalloc (0x2000);
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
