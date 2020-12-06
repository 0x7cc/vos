
#include "vos.h"

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/LoadedImage.h>
#include <Guid/FileInfo.h>

EFI_STATUS EFIAPI UefiMain (IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable) {
  EFI_STATUS           status;
  EFI_PHYSICAL_ADDRESS kernelbase = 0x100000;
  UINTN                kernelsize = 0x1000000; // 16 MiB

  // resolution
  {

    EFI_GRAPHICS_OUTPUT_PROTOCOL*         graphics_output      = 0;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* graphics_output_mode = 0;

    gBS->LocateProtocol (&gEfiGraphicsOutputProtocolGuid, NULL, (VOID**)&graphics_output);
    gBS->SetMem ((void*)graphics_output->Mode->FrameBufferBase, graphics_output->Mode->FrameBufferSize, 0);

    Print (
      L"Current Mode:%02d,Version:%x,Format:%d,Horizontal:%d,Vertical:%d,ScanLine:%d,FrameBufferBase:%010lx,FrameBufferSize:%010lx\n",
      graphics_output->Mode->Mode,
      graphics_output->Mode->Info->Version,
      graphics_output->Mode->Info->PixelFormat,
      graphics_output->Mode->Info->HorizontalResolution,
      graphics_output->Mode->Info->VerticalResolution,
      graphics_output->Mode->Info->PixelsPerScanLine,
      graphics_output->Mode->FrameBufferBase,
      graphics_output->Mode->FrameBufferSize);

    struct {
      UINT32 mode;
      UINTN  pixelsize;
    } maxresolution = {0, 0};

    for (UINT32 i = 0; i < graphics_output->Mode->MaxMode; i++) {
      UINTN sizeofinfo;
      graphics_output->QueryMode (graphics_output, i, &sizeofinfo, &graphics_output_mode);
      Print (L"Mode:%02d,Version:%x,Format:%d,Horizontal:%d,Vertical:%d,ScanLine:%d\n",
             i,
             graphics_output_mode->Version,
             graphics_output_mode->PixelFormat,
             graphics_output_mode->HorizontalResolution,
             graphics_output_mode->VerticalResolution,
             graphics_output_mode->PixelsPerScanLine);

      UINT32 pixelsize = graphics_output_mode->HorizontalResolution * graphics_output_mode->VerticalResolution;
      if (maxresolution.pixelsize < pixelsize) {
        maxresolution.mode      = i;
        maxresolution.pixelsize = pixelsize;
      }

      gBS->FreePool (graphics_output_mode);
    }

    graphics_output->SetMode (graphics_output, maxresolution.mode);

    gBS->CloseProtocol (graphics_output, &gEfiGraphicsOutputProtocolGuid, ImageHandle, NULL);
  }

  // load kernel
  {
    status = gBS->AllocatePages (AllocateAddress, EfiBootServicesData, EFI_SIZE_TO_PAGES (kernelsize), &kernelbase);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::AllocatePages(AllocateAddress, EfiBootServicesData, %d, 0x%llx /* 0x%llx */).\n", status, EFI_SIZE_TO_PAGES (kernelsize), &kernelbase, kernelbase);
      goto err;
    }
  }

  // load OVMF.fd
  {
    EFI_FILE_IO_INTERFACE* io;
    EFI_LOADED_IMAGE*      LoadedImage;

    // 在当前启动的分区进行读取操作.
    status = gBS->HandleProtocol (ImageHandle, &gEfiLoadedImageProtocolGuid, (VOID*)&LoadedImage);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::HandleProtocol() gEfiLoadedImageProtocolGuid unsupported.\n", status);
      goto err;
    }

    // 在当前启动的分区进行读取操作.
    status = gBS->HandleProtocol (LoadedImage->DeviceHandle, &gEfiSimpleFileSystemProtocolGuid, (VOID*)&io);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::HandleProtocol() gEfiSimpleFileSystemProtocolGuid unsupported.\n", status);
      goto err;
    }

    // LocateProtocol返回协议链中第一个匹配的协议,不一定是启动时的ESP分区.
    // status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID **) &io);
    // if (EFI_ERROR(status)) {
    //   Print(L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::LocateProtocol() gEfiSimpleFileSystemProtocolGuid unsupported.\n",
    //         status);
    //   goto err;
    // }

    EFI_FILE_PROTOCOL *proto, *ovmfio;
    status = io->OpenVolume (io, &proto);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_FILE_PROTOCOL::OpenVolume() failed.\n", status);
      goto err;
    }

    status = proto->Open (proto, &ovmfio, L"OVMF.fd", EFI_FILE_MODE_READ, 0);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_FILE_PROTOCOL::Open() 'OVMF.fd' failed.\n", status);
      goto err;
    }

    EFI_FILE_INFO* ovmf_info;
    UINTN          BufferSize = sizeof (*ovmf_info) + 128; /* 变长数组 */

    status = gBS->AllocatePool (EfiRuntimeServicesData, BufferSize, (VOID**)&ovmf_info);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::AllocatePool() &ovmf_info failed.\n", status);
      goto err;
    }

    status = ovmfio->GetInfo (ovmfio, &gEfiFileInfoGuid, &BufferSize, ovmf_info);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_FILE_PROTOCOL::GetInfo() &ovmf_info failed.\n", status);
      goto err;
    }

    void* pOvmf = nullptr;
    status      = gBS->AllocatePool (EfiBootServicesData, ovmf_info->FileSize, &pOvmf);
    if (EFI_ERROR (status)) {
      Print (L"EFI_STATUS(0x%llx) EFI_BOOT_SERVICES::AllocatePool(EfiBootServicesData, 0x%llx, 0x%llx).\n", status, ovmf_info->FileSize, &pOvmf);
      goto err;
    }

    UINT64 ovmf_bufsize = ovmf_info->FileSize;
    if (EFI_ERROR (ovmfio->Read (ovmfio, &ovmf_bufsize, pOvmf))) {
      Print (L"EFI_STATUS(0x%llx) EFI_FILE_PROTOCOL::Read() 'OVMF.fd' failed.\n");
      goto err;
    }

    Print (L"OVMF.fd loaded. pOvmf = 0x%llx\n", pOvmf);

    gBS->FreePool (ovmf_info);
    ovmfio->Close (ovmfio);
    proto->Close (proto);
  }

  // memory
  {
    UINTN                  MemMapSize     = 0;
    EFI_MEMORY_DESCRIPTOR* MemMap         = 0;
    UINTN                  MapKey         = 0;
    UINTN                  DescriptorSize = 0;
    UINT32                 DesVersion     = 0;

    gBS->GetMemoryMap (&MemMapSize, MemMap, &MapKey, &DescriptorSize, &DesVersion);
    MemMapSize += DescriptorSize * 5;
    gBS->AllocatePool (EfiRuntimeServicesData, MemMapSize, (VOID**)&MemMap);
    Print (L"Get MemMapSize:%d,DescriptorSize:%d,count:%d\n", MemMapSize, DescriptorSize, MemMapSize / DescriptorSize);
    gBS->SetMem ((void*)MemMap, MemMapSize, 0);
    status = gBS->GetMemoryMap (&MemMapSize, MemMap, &MapKey, &DescriptorSize, &DesVersion);
    Print (L"Get MemMapSize:%d,DescriptorSize:%d,count:%d\n", MemMapSize, DescriptorSize, MemMapSize / DescriptorSize);
    if (EFI_ERROR (status))
      Print (L"status:%018lx\n", status);

    Print (L"UEFI memory map:\n");
    for (int i = 0; i < MemMapSize / DescriptorSize; i++) {
      EFI_MEMORY_DESCRIPTOR* MMap = (EFI_MEMORY_DESCRIPTOR*)((CHAR8*)MemMap + i * DescriptorSize);
      if (MMap->NumberOfPages == 0)
        continue;

      const CHAR16* typestr = L"123";
      switch (MMap->Type) {
        case EfiReservedMemoryType:
          typestr = L"EfiReservedMemoryType";
          break;
        case EfiMemoryMappedIO:
          typestr = L"EfiMemoryMappedIO";
          break;
        case EfiMemoryMappedIOPortSpace:
          typestr = L"EfiMemoryMappedIOPortSpace";
          break;
        case EfiPalCode:
          typestr = L"EfiPalCode";
          break;
        case EfiUnusableMemory:
          typestr = L"EfiUnusableMemory";
          break;
        case EfiACPIReclaimMemory:
          typestr = L"EfiACPIReclaimMemory";
          break;
        case EfiLoaderCode:
          typestr = L"EfiLoaderCode";
          break;
        case EfiLoaderData:
          typestr = L"EfiLoaderData";
          break;
        case EfiBootServicesCode:
          typestr = L"EfiBootServicesCode";
          break;
        case EfiBootServicesData:
          typestr = L"EfiBootServicesData";
          break;
        case EfiRuntimeServicesCode:
          typestr = L"EfiRuntimeServicesCode";
          break;
        case EfiRuntimeServicesData:
          typestr = L"EfiRuntimeServicesData";
          break;
        case EfiConventionalMemory:
          typestr = L"EfiConventionalMemory";
          break;
        case EfiPersistentMemory:
          typestr = L"EfiPersistentMemory";
          break;
        case EfiACPIMemoryNVS:
          typestr = L"EfiACPIMemoryNVS";
          break;
        default:
          typestr = L"Unknow";
          break;
      }

      Print (L"0x%016llx - 0x%016llx : %s\n",
             MMap->PhysicalStart,
             MMap->PhysicalStart + EFI_PAGES_TO_SIZE (MMap->NumberOfPages),
             typestr);
    }
  }

  extern void boot ();
  boot ();

  return EFI_SUCCESS;

err:
  return EFI_LOAD_ERROR;
}
