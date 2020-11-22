//
// Created by xxx on 2020/11/22.
//

#ifndef VOS_EPT_H
#define VOS_EPT_H

// 4K page

#define make_EPT_4K_PML4E_item(PA, X, W, R) (((PA & 0xFFFFFFFFFFFF) << 12) | ((X & 1) << 10) | ((W & 1) << 1) | ((R & 1) << 0))
#define make_EPT_4K_PDPTE_item make_EPT_4K_PML4E_item
#define make_EPT_4K_PDE_item make_EPT_4K_PML4E_item
#define make_EPT_4K_PTE_item make_EPT_4K_PML4E_item

// 2MB page

#define make_EPT_2MB_PML4E_item(PA, X, W, R)
#define make_EPT_2MB_PDPTE_item make_EPT_2MB_PML4E_item
#define make_EPT_2MB_PDE_item make_EPT_2MB_PML4E_item
#define make_EPT_2MB_PTE_item make_EPT_2MB_PML4E_item

// 1GB page

#define make_EPT_1GB_PML4E_item (PA, X, W, R)
#define make_EPT_1GB_PDPTE_item make_EPT_1GB_PML4E_item
#define make_EPT_1GB_PDE_item make_EPT_1GB_PML4E_item
#define make_EPT_1GB_PTE_item make_EPT_1GB_PML4E_item

#endif //VOS_EPT_H
