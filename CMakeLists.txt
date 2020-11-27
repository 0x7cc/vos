cmake_minimum_required ( VERSION 3.16 )

project ( vos )

add_library ( bootx64
  bootx64.c  ept.c  npt.c  svm.c  vmx.c  vos.c
  vmclient.c vmclient.h vostd.c vostd.h )

target_compile_definitions ( bootx64 PUBLIC EFIAPI= STRING_ARRAY_NAME= USING_LTO= UEFI_C_SOURCE= )

target_include_directories ( bootx64
  PUBLIC
  ../../../Vlv2TbltDevicePkg/Include
  ../../../QuarkPlatformPkg/Include
  ../../../IntelFspWrapperPkg/Include
  ../../../IntelFsp2Pkg/Include
  ../../../StdLib/Include
  ../../../ShellPkg/Include
  ../../../IntelFrameworkModulePkg/Include
  ../../../IntelFspPkg/Include
  ../../../SourceLevelDebugPkg/Include
  ../../../SecurityPkg/Include
  ../../../DuetPkg/Include
  ../../../EmbeddedPkg/Include
  ../../../IntelSiliconPkg/Include
  ../../../ArmPkg/Include
  ../../../CryptoPkg/Include
  ../../../UefiCpuPkg/Include
  ../../../ArmVirtPkg/Include
  ../../../IntelFrameworkPkg/Include
  ../../../StdLibPrivateInternalFiles/Include
  ../../../OvmfPkg/Include
  ../../../EmulatorPkg/Include
  ../../../ArmPlatformPkg/Include
  ../../../Omap35xxPkg/Include
  ../../../PcAtChipsetPkg/Include
  ../../../NetworkPkg/Include
  ../../../CorebootModulePkg/Include
  ../../../BeagleBoardPkg/Include
  ../../../MdeModulePkg/Include
  ../../../OptionRomPkg/Include
  ../../../SignedCapsulePkg/Include
  ../../../IntelFsp2WrapperPkg/Include
  ../../../Nt32Pkg/Include
  ../../../Vlv2DeviceRefCodePkg/Include
  ../../../MdePkg/Include
  ../../../MdePkg/Include/X64

  )

