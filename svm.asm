%include "def.asm"

bits 64


struc SvmVMExitContext
.ax      resb 8
.bx      resb 8
.cx      resb 8
.dx      resb 8
.si      resb 8
.di      resb 8
.r8      resb 8
.r9      resb 8
.r10     resb 8
.r11     resb 8
.r12     resb 8
.r13     resb 8
.r14     resb 8
.r15     resb 8
.flags   resb 8
.vmcbptr resb 8
endstruc



global v_svm_vmrun
global v_svm_vmsave
global v_svm_vmload
global v_svm_vmmcall
global v_svm_loop
extern svm_vmexit_handler

v_svm_vmrun:
  mov rax, argv0
  vmrun
  ret

v_svm_vmsave:
  mov rax, argv0
  vmsave
  ret

v_svm_vmload:
  mov rax, argv0
  vmload
  ret

v_svm_vmmcall:
  vmmcall
  ret

v_svm_loop:
  mov rsp, argv0
  .loop:
    mov rax, rsp
    vmload
    BOCHS_MAGIC_BREAK
    vmrun
    vmsave

    push rbp
    mov rbp, rsp

    sub rsp, SvmVMExitContext_size

    mov [rsp + SvmVMExitContext.vmcbptr], rax
    mov rax, [rax + 0x400 + 0x1f8]             ; vmcb->StateSaveArea.rax
    mov [rsp + SvmVMExitContext.ax], rax
    mov [rsp + SvmVMExitContext.bx], rbx
    mov [rsp + SvmVMExitContext.cx], rcx
    mov [rsp + SvmVMExitContext.dx], rdx
    mov [rsp + SvmVMExitContext.si], rsi
    mov [rsp + SvmVMExitContext.di], rdi
    mov [rsp + SvmVMExitContext.r8], r8
    mov [rsp + SvmVMExitContext.r9], r9
    mov [rsp + SvmVMExitContext.r10], r10
    mov [rsp + SvmVMExitContext.r11], r11
    mov [rsp + SvmVMExitContext.r12], r12
    mov [rsp + SvmVMExitContext.r13], r13
    mov [rsp + SvmVMExitContext.r14], r14
    mov [rsp + SvmVMExitContext.r15], r15

    mov argv0, rsp  ; context

    call svm_vmexit_handler

    cmp rax, 0
    jne .fail      ;

    mov rbx, [rsp + SvmVMExitContext.vmcbptr]
    mov rax, [rsp + SvmVMExitContext.ax]
    mov [rbx + 0x400 + 0x1f8], rax             ; vmcb->StateSaveArea.rax

    mov rax, [rbx + 0 + 0x0c8]                 ; vmcb->ControlArea.NRip
    mov [rbx + 0x400 + 0x178], rax             ; vmcb->StateSaveArea.rip

    ; mov rax, [rbx + 0x400 + 0x0c8]           ; vmcb->StateSaveArea.Rsp
    ; mov [rbx + 0x400 + 0x1d8], rax

    mov rbx, [rsp + SvmVMExitContext.bx]
    mov rcx, [rsp + SvmVMExitContext.cx]
    mov rdx, [rsp + SvmVMExitContext.dx]
    mov rsi, [rsp + SvmVMExitContext.si]
    mov rdi, [rsp + SvmVMExitContext.di]
    mov r8,  [rsp + SvmVMExitContext.r8]
    mov r9,  [rsp + SvmVMExitContext.r9]
    mov r10, [rsp + SvmVMExitContext.r10]
    mov r11, [rsp + SvmVMExitContext.r11]
    mov r12, [rsp + SvmVMExitContext.r12]
    mov r13, [rsp + SvmVMExitContext.r13]
    mov r14, [rsp + SvmVMExitContext.r14]
    mov r15, [rsp + SvmVMExitContext.r15]

    add rsp, SvmVMExitContext_size

    pop rbp
    jmp .loop
  .fail:
  ret
