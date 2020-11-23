%include "vmx.asm"
%include "svm.asm"

struc cpuid_t
.eax resb 4
.ebx resb 4
.ecx resb 4
.edx resb 4
endstruc

; Table 3-8. Information Returned by CPUID Instruction
; void __fastcall __cpuid (uint64_t, struct cpuid_t*);
global __cpuid
__cpuid:
  mov rax, argv0

  cpuid

  mov dword [argv0 + cpuid_t.eax], eax
  mov dword [argv0 + cpuid_t.ebx], ebx
  mov dword [argv0 + cpuid_t.ecx], ecx
  mov dword [argv0 + cpuid_t.edx], edx

  ret
