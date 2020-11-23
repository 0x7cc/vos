#include "vmx.h"
#include "svm.h"
#include "x86_64.h"

void boot () {
  char vendor[13] = {0};

  {
    cpuid_t c;
    __cpuid (0, &c);
    ((vuint32*)vendor)[0] = c.ebx;
    ((vuint32*)vendor)[1] = c.edx;
    ((vuint32*)vendor)[2] = c.ecx;
  }

  while (1)
    ;
}
