//
// Created by xxx on 2020/11/24.
//

#include "vostd.h"
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

void* vmalloc (vint size) {
  EFI_PHYSICAL_ADDRESS base   = 0;
  EFI_STATUS           status = gBS->AllocatePages (AllocateAnyPages, EfiBootServicesData, EFI_SIZE_TO_PAGES (size), &base);
  if (EFI_ERROR (status)) {
    Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::AllocatePages(AllocateAnyPages, EfiBootServicesData, %d, 0x%016llx).\n", status, EFI_SIZE_TO_PAGES (size), &base);
    return nullptr;
  }
  return (void*)base;
}

void vfree (void* mem, vint size) {
  EFI_STATUS status = gBS->FreePages ((EFI_PHYSICAL_ADDRESS)mem, EFI_SIZE_TO_PAGES (size));
  if (EFI_ERROR (status)) {
    Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::FreePages(0x%016llx, %d).\n", status, EFI_SIZE_TO_PAGES (size));
  }
}
