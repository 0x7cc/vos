//
// Created by xxx on 2020/11/22.
//

#include "vmx.h"

#include <Library/UefiLib.h>

struct vmxcontext {
};

int vmx_load (vmxcontext** vmx) {
  AsciiPrint ("vmx feature loaded.");
  return 0;
}

int vmx_unload (vmxcontext** vmx) {
  return 0;
}

int vmx_luanch (vmxcontext* vmx) {
  return 0;
}
