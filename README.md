
# VOS UEFI

运行环境要求

  - AMD64

  - VT-x/AMD-v

  - UEFI BIOS

## BUILD

初次编译时，请使用本文指定链接中的版本进行编译，以防编译出现

### Ubuntu 16.04 LTS

```
http://mirrors.163.com/ubuntu-releases/16.04/
```

### UDK 2018

```
https://github.com/tianocore/edk2/releases/tag/vUDK2018
```

#### Install required software from apt

```shell
sudo apt-get install build-essential uuid-dev iasl git gcc-5 nasm python3-distutils
```

#### OpenSSL

```
https://github.com/openssl/openssl/releases/tag/OpenSSL_1_1_0g
```

#### Build BaseTools

```shell
make -C BaseTools
. edksetup.sh
```

#### Setup build shell environment

```shell
export EDK_TOOLS_PATH=`pwd`/BaseTools
. edksetup.sh BaseTools
```

#### Build EFI Applications

```shell
build -p OvmfPkg/OvmfPkgX64.dsc -b DEBUG -a X64 -t GCC5
build -p AppPkg/AppPkg.dsc -b DEBUG -a X64 -t GCC5
build -p AppPkg/AppPkg.dsc -b RELEASE -a X64 -t GCC5
```

## Bootable USB Flash

```shell
...
```

