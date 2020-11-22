//
// Created by xxx on 2020/11/22.
//

#ifndef BOOTX64__PAGE_H
#define BOOTX64__PAGE_H

#include <stdint.h>

#define make_4K_PML4E_item()
#define make_4K_PDPTE_item make_4K_PML4E_item
#define make_4K_PDE_item make_4K_PML4E_item
#define make_4K_PTE_item make_4K_PML4E_item

#define make_2MB_PML4E_item ()
#define make_2MB_PDPTE_item make_2MB_PML4E_item
#define make_2MB_PDE_item make_2MB_PML4E_item
#define make_2MB_PTE_item make_2MB_PML4E_item

#define make_1GB_PML4E_item ()
#define make_1GB_PDPTE_item make_1GB_PML4E_item
#define make_1GB_PDE_item make_1GB_PML4E_item
#define make_1GB_PTE_item make_1GB_PML4E_item

#endif //BOOTX64__PAGE_H
