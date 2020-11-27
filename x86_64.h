//
// Created by xxx on 2020/11/22.
//

#ifndef VOS__X86_64_H
#define VOS__X86_64_H

#include "vos.h"

typedef struct
{
  vuint32 eax;
  vuint32 ebx;
  vuint32 ecx;
  vuint32 edx;
} cpuid_t;

static_assert(sizeof(cpuid_t) == 16, "");

void vos_cpuid (vint64, cpuid_t*);

#endif //VOS__X86_64_H
