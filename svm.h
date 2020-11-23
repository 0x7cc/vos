//
// Created by xxx on 2020/11/22.
//

#ifndef VOS_SVM_H
#define VOS_SVM_H

#include "vos.h"
#include "npt.h"

typedef struct
{
  vuint64 rax;
  vuint64 rbx;
  vuint64 rcx;
  vuint64 rdx;
  vuint64 rsi;
  vuint64 rdi;
  vuint64 r8;
  vuint64 r9;
  vuint64 r10;
  vuint64 r11;
  vuint64 r12;
  vuint64 r13;
  vuint64 r14;
  vuint64 r15;
  vuint64 flags;
  vuint64 vmcbptr;
} SvmVMExitContext;

#endif //VOS_SVM_H
