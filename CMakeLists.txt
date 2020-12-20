cmake_minimum_required ( VERSION 3.1 )

project ( vos )

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set ( CMAKE_C_STANDARD 99 )

if (NOT DEFINED ENV{WORKSPACE})
  message (FATAL_ERROR "please run edksetup[.bat|.sh] before cmake")
endif()

message ("$ENV{WORKSPACE}")

add_library (
  vos

  ept.c
  ept.h
  npt.c
  npt.h
  page.h
  sdk.h
  svm.c
  svm.h
  vmclient.c
  vmclient.h
  vmx.c
  vmx.h
  vos.c
  vos.h
  vostd.c
  vostd.h
  x86_64.h
)

target_include_directories ( vos
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
  $ENV{WORKSPACE}/MdePkg
  $ENV{WORKSPACE}/MdePkg/Include
  $ENV{WORKSPACE}/MdePkg/Include/X64
  $ENV{WORKSPACE}/MdePkg/Test/UnitTest/Include
  $ENV{WORKSPACE}/Build/vos/DEBUG_VS2019/X64/vos/vos/DEBUG
  )

target_compile_options(vos PUBLIC /FIAutoGen.h /W4 /WX )

target_compile_definitions ( vos PUBLIC EFIAPI= STRING_ARRAY_NAME= USING_LTO= UEFI_C_SOURCE= )

#############################################################################

add_executable (
  bootx64

  bootx64.c
)

target_link_libraries(bootx64 PUBLIC vos)

message(WARNING "cmakelists.txt is just for the convenience of using the code hint function of the IDE, it cannot let you compile vos.")
