%include "def.asm"

; int vos_sdk_call (int cmd, const void* arg);
global vos_sdk_call
vos_sdk_call:
  vmcall
  ret

