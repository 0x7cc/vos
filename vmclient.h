//
// Created by xxx on 2020/11/24.
//

#ifndef VOS__VMCLIENT_H
#define VOS__VMCLIENT_H

typedef struct vmclient vmclient;

int vmclient_load (vmclient**);
int vmclient_unload (vmclient**);
int vmclient_load_ovmf (vmclient*);
int vmclient_luanch (vmclient*);

#endif //VOS__VMCLIENT_H
