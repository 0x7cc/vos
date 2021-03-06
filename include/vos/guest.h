//
// Created by x7cc on 2020/4/24.
//

#ifndef VOS_GUEST_H
#define VOS_GUEST_H

#include "vos/vos.h"
#include "vos/types.h"

typedef struct vos_guest_s
{
  IN vos_uint     num_threads;
  IN vos_uint     num_cpu_cores;
  IN vos_uint     num_mem_pages;
  IN vos_uint     enable_debug;
  IN vos_uint     enable_physical_address_translation;
  OUT vos_uintptr memory_base_tmep;
} vos_guest_t;

/// 在vmm中给guest申请一块内存.
/// \param guest
/// \param size
/// \return         Guest Physical Address
vos_uint guest_malloc (vos_guest_t* guest, vos_uint size);

#endif //VOS_GUEST_H
