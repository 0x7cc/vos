//
// Created by xxx on 2020/11/22.
//

#ifndef VOS__X86_64_H
#define VOS__X86_64_H

#include "vos.h"

typedef struct
{
  vint32 eax;
  vint32 ebx;
  vint32 ecx;
  vint32 edx;
} cpuid_t;

void __cpuid (vint64, cpuid_t*);

#endif //VOS__X86_64_H
