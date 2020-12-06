
# vos

Supported Platforms

  - AMD64|AArch64

  - VT-x|AMD-v

  - UEFI

## Build vos on Windows

### Install required software

### Setup edk2 on Windows 10

```
https://gist.github.com/0x7cc/9d56c5e19860e5770f0c02e56e880112
```

### Clone

```shell
cd edk2/
git clone https://github.com/0x7cc/vos.git
```

### Build

Setup edk2 environments variables

```shell
edksetup.bat
```

Build

```shell
build -p vos/vos.dsc -t VS2019 -a X64 -b DEBUG
build -p vos/vos.dsc -t VS2019 -a X64 -b RELEASE
```

## Build vos on Ubuntu

### Install required software from apt

```shell
sudo apt-get install build-essential uuid-dev iasl git gcc-5 nasm python3-distutils
```

### Setup edk2 on Ubuntu 16.04 LTS

```
To be continue...
```

### Clone

```shell
cd edk2/
git clone https://github.com/0x7cc/vos.git
```

### Build

Setup edk2 environments variables

```shell
. ./edksetup.sh
```

Build

```shell
build -p vos/vos.dsc -t GCC5 -a X64 -b DEBUG
build -p vos/vos.dsc -t GCC5 -a X64 -b RELEASE
```

## Bootable USB Flash

```shell
To be continue...
```

