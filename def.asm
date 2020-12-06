%ifndef VOS_DEFS
%define VOS_DEFS

%define BOCHS_MAGIC_BREAK xchg bx, bx


%define elf64_fastcall_argv0 rdi
%define elf64_fastcall_argv1 rsi
%define elf64_fastcall_argv2 rdx
%define elf64_fastcall_argv3 rcx

%define win64_fastcall_argv0 rcx
%define win64_fastcall_argv1 rdx
%define win64_fastcall_argv2 r8
%define win64_fastcall_argv3 r9

%ifidn __OUTPUT_FORMAT__, elf64
  %define argv0 elf64_fastcall_argv0
  %define argv1 elf64_fastcall_argv1
  %define argv2 elf64_fastcall_argv2
  %define argv3 elf64_fastcall_argv3
%elifidn __OUTPUT_FORMAT__, macho64
  %define argv0 elf64_fastcall_argv0
  %define argv1 elf64_fastcall_argv1
  %define argv2 elf64_fastcall_argv2
  %define argv3 elf64_fastcall_argv3
%elifidn __OUTPUT_FORMAT__, win64
  %define argv0 win64_fastcall_argv0
  %define argv1 win64_fastcall_argv1
  %define argv2 win64_fastcall_argv2
  %define argv3 win64_fastcall_argv3
%else
  %error "Currently only supports x86_64 architecture"
%endif




%endif ; !VOS_DEFS

