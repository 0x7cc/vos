%include "def.asm"

bits 64


struc VmxVMExitContext
.ax      resb 8
.bx      resb 8
.cx      resb 8
.dx      resb 8
.si      resb 8
.di      resb 8
.ip      resb 8
.r8      resb 8
.r9      resb 8
.r10     resb 8
.r11     resb 8
.r12     resb 8
.r13     resb 8
.r14     resb 8
.r15     resb 8
.flags   resb 8
endstruc

