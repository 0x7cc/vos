//
// Created by xxx on 2020/11/22.
//

#ifndef VOS_SDK_H
#define VOS_SDK_H

#define VOS_CMD_HOOK_PAGE_VA 348984539
#define VOS_CMD_HOOK_PAGE_PA 228791391

typedef struct
{
  void* src_VA;
  void* dst_VA;
} vos_hook_page_va_t;

typedef struct
{
  void* src_PA;
  void* dst_PA;
} vos_hook_page_pa_t;

int vos_sdk_call (int cmd, const void* arg);

#endif //VOS_SDK_H
