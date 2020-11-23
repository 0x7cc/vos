//
// Created by xxx on 2020/11/22.
//

#ifndef VOS_VOS_H
#define VOS_VOS_H

// clang-format off

#if __cplusplus
#else

#  ifndef nullptr
#    define nullptr ((void*)0)
#  endif

#  if !defined(_WIN32) || defined(__MINGW64__)
#    define static_assert _Static_assert
#  endif
#endif

typedef signed char        vint8;
typedef short              vint16;
typedef int                vint32;
typedef long long          vint64;
typedef unsigned char      vuint8;
typedef unsigned short     vuint16;
typedef unsigned int       vuint32;
typedef unsigned long long vuint64;
static_assert(sizeof(vint8) == 1, "");
static_assert(sizeof(vint16) == 2, "");
static_assert(sizeof(vint32) == 4, "");
static_assert(sizeof(vint64) == 8, "");
static_assert(sizeof(vuint8) == 1, "");
static_assert(sizeof(vuint16) == 2, "");
static_assert(sizeof(vuint32) == 4, "");
static_assert(sizeof(vuint64) == 8, "");

#if __x86_64__ || _WIN64
  typedef vint64  vint;
  typedef vuint64 vuint;
  typedef vint64  vintptr;
  typedef vuint64 vuintptr;
#elif __i386__ || _WIN32
  typedef vint32  vint;
  typedef vuint32 vuint;
  typedef vint32  vintptr;
  typedef vuint32 vuintptr;
#else
#  error "wtf???"
#endif

// clang-format on

#endif //VOS_VOS_H
