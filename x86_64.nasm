%include "vmx.asm"
%include "svm.asm"

global __stosb
global __stosw
global __stosd
global __stosq
global __lar
global __read_cr0
global __write_cr0
global __read_cr1
global __write_cr1
global __read_cr2
global __write_cr2
global __read_cr3
global __write_cr3
global __read_cr4
global __write_cr4
global __rdmsr
global __wrmsr
global __rflags
global __eflags
global __flags
global __read_es
global __read_cs
global __read_ss
global __read_ds
global __read_fs
global __read_gs
global __read_tr
global __sgdt
global __sidt
global __lgdt
global __sldt
global __lldt
global __lidt
global __cpuid

; void (char* buffer, uint8 n, vos_uint len)
__stosb:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosb
  ret

; void (char* buffer, uint16 n, vos_uint len)
__stosw:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosw
  ret

; void (char* buffer, uint32 n, vos_uint len)
__stosd:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosd
  ret

; void (char* buffer, uint64 n, vos_uint len)
__stosq:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosq
  ret

; load access rights.
__lar:
  lar rax, argv0
  ret

__read_cr0:
  mov rax, cr0
  ret

__write_cr0:
  mov rax, argv0
  mov cr0, rax
  ret

__read_cr1:
  mov rax, cr1
  ret

__write_cr1:
  mov rax, argv0
  mov cr1, rax
  ret

__read_cr2:
  mov rax, cr2
  ret

__write_cr2:
  mov rax, argv0
  mov cr2, rax
  ret

__read_cr3:
  mov rax, cr3
  ret

__write_cr3:
  mov rax, argv0
  mov cr3, rax
  ret

__read_cr4:
  mov rax, cr4
  ret

__write_cr4:
  mov rax, argv0
  mov cr4, rax
  ret

__rdmsr:
  mov rcx, argv0
  rdmsr
  shl rdx, 32
  or rax, rdx        ; merge to uint64
  ret

__wrmsr:
  mov rcx, argv0
  mov rax, argv1     ; low part
  mov rdx, argv1
  shr rdx, 32        ; high part
  wrmsr
  ret

__rflags:
__eflags:
__flags:
  pushfq
  pop rax
  ret

__read_es:
  mov rax, es
  ret

__read_cs:
  mov rax, cs
  ret

__read_ss:
  mov rax, ss
  ret

__read_ds:
  mov rax, ds
  ret

__read_fs:
  mov rax, fs
  ret

__read_gs:
  mov rax, gs
  ret

__read_tr:
  push 0
  str [rsp]
  pop rax
  ret

__sgdt:
  sgdt [argv0]
  ret

__sidt:
  sidt [argv0]
  ret

__lgdt:
  lgdt [argv0]
  ret

__sldt:
  sldt [argv0]
  ret

__lldt:
  lldt [argv0]
  ret

__lidt:
  lidt [argv0]
  int 3
  ret



struc cpuid_t
.eax resb 4
.ebx resb 4
.ecx resb 4
.edx resb 4
endstruc

; Table 3-8. Information Returned by CPUID Instruction
; void (uint64_t, struct cpuid_t*);
__cpuid:

  push rbx         ; non-volatile registers.

  mov rax, argv0

  cpuid

  mov dword [argv1 + cpuid_t.eax], eax
  mov dword [argv1 + cpuid_t.ebx], ebx
  mov dword [argv1 + cpuid_t.ecx], ecx
  mov dword [argv1 + cpuid_t.edx], edx

  pop rbx

  ret
