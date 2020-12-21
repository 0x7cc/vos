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

#pragma pack(1)
typedef struct gdtr__ {
  vuint16 limit;
  vuint64 base;
} gdtr_t, ldtr_t, idtr_t;
#pragma pack()

static_assert (sizeof (gdtr_t) == 10, "");

void  v_stosb (char* buffer, vuint8 n, vuint len);
void  v_stosw (char* buffer, vuint16 n, vuint len);
void  v_stosd (char* buffer, vuint32 n, vuint len);
void  v_stosq (char* buffer, vuint64 n, vuint len);
// load access rights
vuint v_lar (vuint);
vuint v_read_cr0 (void);
void  v_write_cr0 (vuint);
vuint v_read_cr1 (void);
void  v_write_cr1 (vuint);
vuint v_read_cr2 (void);
void  v_write_cr2 (vuint);
vuint v_read_cr3 (void);
void  v_write_cr3 (vuint);
vuint v_read_cr4 (void);
void  v_write_cr4 (vuint);
vuint v_rdmsr (vuint);
void  v_wrmsr (vuint, vuint);
vuint v_rflags (void);
vuint v_eflags (void);
vuint v_flags (void);
vuint v_read_es (void);
vuint v_read_cs (void);
vuint v_read_ss (void);
vuint v_read_ds (void);
vuint v_read_fs (void);
vuint v_read_gs (void);
vuint v_read_tr (void);
void  v_sgdt (gdtr_t*);
void  v_sldt (ldtr_t*);
void  v_sidt (idtr_t*);
void  v_lgdt (const gdtr_t*);
void  v_lldt (const ldtr_t*);
void  v_lidt (const idtr_t*);
void  v_cpuid (vint64, cpuid_t*);

#endif //VOS__X86_64_H
