
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_STATUS EFIAPI UefiMain (IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable)
{
  EFI_GRAPHICS_OUTPUT_PROTOCOL*         gGraphicsOutput = 0;
  EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* Info            = 0;
  UINTN                                 InfoSize        = 0;
  int                                   i               = 0;

  gBS->LocateProtocol (&gEfiGraphicsOutputProtocolGuid, NULL, (VOID**)&gGraphicsOutput);
  Print (
    L"Current Mode:%02d,Version:%x,Format:%d,Horizontal:%d,Vertical:%d,ScanLine:%d,FrameBufferBase:%010lx,FrameBufferSize:%010lx\n",
    gGraphicsOutput->Mode->Mode,
    gGraphicsOutput->Mode->Info->Version,
    gGraphicsOutput->Mode->Info->PixelFormat,
    gGraphicsOutput->Mode->Info->HorizontalResolution,
    gGraphicsOutput->Mode->Info->VerticalResolution,
    gGraphicsOutput->Mode->Info->PixelsPerScanLine,
    gGraphicsOutput->Mode->FrameBufferBase,
    gGraphicsOutput->Mode->FrameBufferSize);

  for (i = 0; i < gGraphicsOutput->Mode->MaxMode; i++)
  {
    gGraphicsOutput->QueryMode (gGraphicsOutput, i, &InfoSize, &Info);
    Print (L"Mode:%02d,Version:%x,Format:%d,Horizontal:%d,Vertical:%d,ScanLine:%d\n", i, Info->Version, Info->PixelFormat, Info->HorizontalResolution, Info->VerticalResolution, Info->PixelsPerScanLine);
    gBS->FreePool (Info);
  }

  gBS->CloseProtocol (gGraphicsOutput, &gEfiGraphicsOutputProtocolGuid, ImageHandle, NULL);

  while (1)
    ;

  return EFI_SUCCESS;
}
