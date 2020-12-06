cmake_minimum_required ( VERSION 3.1 )

project ( vos )

if (NOT DEFINED ENV{WORKSPACE})
  message (FATAL_ERROR "please run edksetup[.bat|.sh] before cmake")
endif()

message ("$ENV{WORKSPACE}")

add_library (
  bootx64
  
  bootx64.c
  ept.c
  npt.c
  svm.c
  vmclient.c
  vmclient.h
  vmx.c
  vos.c
  vostd.c
  vostd.h
)

target_compile_definitions ( bootx64 PUBLIC EFIAPI= STRING_ARRAY_NAME= USING_LTO= UEFI_C_SOURCE= )

target_include_directories ( bootx64
  PUBLIC
  $ENV{WORKSPACE}/Vlv2TbltDevicePkg/Include
  $ENV{WORKSPACE}/QuarkPlatformPkg/Include
  $ENV{WORKSPACE}/IntelFspWrapperPkg/Include
  $ENV{WORKSPACE}/IntelFsp2Pkg/Include
  $ENV{WORKSPACE}/StdLib/Include
  $ENV{WORKSPACE}/ShellPkg/Include
  $ENV{WORKSPACE}/IntelFrameworkModulePkg/Include
  $ENV{WORKSPACE}/IntelFspPkg/Include
  $ENV{WORKSPACE}/SourceLevelDebugPkg/Include
  $ENV{WORKSPACE}/SecurityPkg/Include
  $ENV{WORKSPACE}/DuetPkg/Include
  $ENV{WORKSPACE}/EmbeddedPkg/Include
  $ENV{WORKSPACE}/IntelSiliconPkg/Include
  $ENV{WORKSPACE}/ArmPkg/Include
  $ENV{WORKSPACE}/CryptoPkg/Include
  $ENV{WORKSPACE}/UefiCpuPkg/Include
  $ENV{WORKSPACE}/ArmVirtPkg/Include
  $ENV{WORKSPACE}/IntelFrameworkPkg/Include
  $ENV{WORKSPACE}/StdLibPrivateInternalFiles/Include
  $ENV{WORKSPACE}/OvmfPkg/Include
  $ENV{WORKSPACE}/EmulatorPkg/Include
  $ENV{WORKSPACE}/ArmPlatformPkg/Include
  $ENV{WORKSPACE}/Omap35xxPkg/Include
  $ENV{WORKSPACE}/PcAtChipsetPkg/Include
  $ENV{WORKSPACE}/NetworkPkg/Include
  $ENV{WORKSPACE}/CorebootModulePkg/Include
  $ENV{WORKSPACE}/BeagleBoardPkg/Include
  $ENV{WORKSPACE}/MdeModulePkg/Include
  $ENV{WORKSPACE}/OptionRomPkg/Include
  $ENV{WORKSPACE}/SignedCapsulePkg/Include
  $ENV{WORKSPACE}/IntelFsp2WrapperPkg/Include
  $ENV{WORKSPACE}/Nt32Pkg/Include
  $ENV{WORKSPACE}/Vlv2DeviceRefCodePkg/Include
  $ENV{WORKSPACE}/MdePkg/Include
  $ENV{WORKSPACE}/MdePkg/Include/X64
  )

