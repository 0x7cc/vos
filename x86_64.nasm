%include "vmx.asm"
%include "svm.asm"

global v_stosb
global v_stosw
global v_stosd
global v_stosq
global v_lar
global v_read_cr0
global v_write_cr0
global v_read_cr1
global v_write_cr1
global v_read_cr2
global v_write_cr2
global v_read_cr3
global v_write_cr3
global v_read_cr4
global v_write_cr4
global v_rdmsr
global v_wrmsr
global v_rflags
global v_eflags
global v_flags
global v_read_es
global v_read_cs
global v_read_ss
global v_read_ds
global v_read_fs
global v_read_gs
global v_read_tr
global v_sgdt
global v_sidt
global v_lgdt
global v_sldt
global v_lldt
global v_lidt
global v_cpuid

; void (char* buffer, uint8 n, vos_uint len)
v_stosb:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosb
  ret

; void (char* buffer, uint16 n, vos_uint len)
v_stosw:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosw
  ret

; void (char* buffer, uint32 n, vos_uint len)
v_stosd:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosd
  ret

; void (char* buffer, uint64 n, vos_uint len)
v_stosq:
  mov rdi, argv0
  mov rax, argv1
  mov rcx, argv2
  rep stosq
  ret

; load access rights.
v_lar:
  lar rax, argv0
  ret

v_read_cr0:
  mov rax, cr0
  ret

v_write_cr0:
  mov rax, argv0
  mov cr0, rax
  ret

v_read_cr1:
  mov rax, cr1
  ret

v_write_cr1:
  mov rax, argv0
  mov cr1, rax
  ret

v_read_cr2:
  mov rax, cr2
  ret

v_write_cr2:
  mov rax, argv0
  mov cr2, rax
  ret

v_read_cr3:
  mov rax, cr3
  ret

v_write_cr3:
  mov rax, argv0
  mov cr3, rax
  ret

v_read_cr4:
  mov rax, cr4
  ret

v_write_cr4:
  mov rax, argv0
  mov cr4, rax
  ret

v_rdmsr:
  mov rcx, argv0
  rdmsr
  shl rdx, 32
  or rax, rdx        ; merge to uint64
  ret

v_wrmsr:
  mov rcx, argv0
  mov rax, argv1     ; low part
  mov rdx, argv1
  shr rdx, 32        ; high part
  wrmsr
  ret

v_rflags:
v_eflags:
v_flags:
  pushfq
  pop rax
  ret

v_read_es:
  mov rax, es
  ret

v_read_cs:
  mov rax, cs
  ret

v_read_ss:
  mov rax, ss
  ret

v_read_ds:
  mov rax, ds
  ret

v_read_fs:
  mov rax, fs
  ret

v_read_gs:
  mov rax, gs
  ret

v_read_tr:
  push 0
  str [rsp]
  pop rax
  ret

v_sgdt:
  sgdt [argv0]
  ret

v_sidt:
  sidt [argv0]
  ret

v_lgdt:
  lgdt [argv0]
  ret

v_sldt:
  sldt [argv0]
  ret

v_lldt:
  lldt [argv0]
  ret

v_lidt:
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
v_cpuid:

  push rbx         ; non-volatile registers.

  mov rax, argv0
  mov r10, argv1   ; volatile registers.

  cpuid

  mov dword [r10 + cpuid_t.eax], eax
  mov dword [r10 + cpuid_t.ebx], ebx
  mov dword [r10 + cpuid_t.ecx], ecx
  mov dword [r10 + cpuid_t.edx], edx

  pop rbx

  ret
