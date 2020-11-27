%include "vmx.asm"
%include "svm.asm"

struc cpuid_t
.eax resb 4
.ebx resb 4
.ecx resb 4
.edx resb 4
endstruc

; Table 3-8. Information Returned by CPUID Instruction
; void __fastcall vos_cpuid (uint64_t, struct cpuid_t*);
global vos_cpuid
vos_cpuid:

  push rbx         ; 非易失性寄存器

  mov rax, argv0

  cpuid

  mov dword [argv1 + cpuid_t.eax], eax
  mov dword [argv1 + cpuid_t.ebx], ebx
  mov dword [argv1 + cpuid_t.ecx], ecx
  mov dword [argv1 + cpuid_t.edx], edx

  pop rbx

  ret
