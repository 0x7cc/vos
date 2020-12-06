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

static_assert (sizeof (cpuid_t) == 16, "");

void __stosb (char* buffer, vuint8 n, vuint len);
void __stosw (char* buffer, vuint16 n, vuint len);
void __stosd (char* buffer, vuint32 n, vuint len);
void __stosq (char* buffer, vuint64 n, vuint len);
vuint __lar (vuint);
vuint __read_cr0 (void);
void  __write_cr0 (vuint);
vuint __read_cr1 (void);
void  __write_cr1 (vuint);
vuint __read_cr2 (void);
void  __write_cr2 (vuint);
vuint __read_cr3 (void);
void  __write_cr3 (vuint);
vuint __read_cr4 (void);
void  __write_cr4 (vuint);
vuint __rdmsr (vuint);
void  __wrmsr (vuint, vuint);
vuint __rflags (void);
vuint __eflags (void);
vuint __flags (void);
vuint __read_es (void);
vuint __read_cs (void);
vuint __read_ss (void);
vuint __read_ds (void);
vuint __read_fs (void);
vuint __read_gs (void);
vuint __read_tr (void);
vuint __sgdt (void);
vuint __sldt (void);
vuint __sidt (void);
void  __lgdt (vuintptr);
void  __lldt (vuintptr);
void  __lidt (vuintptr);
void  __cpuid (vint64, cpuid_t*);

#endif //VOS__X86_64_H
