begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dM -x assembler-with-cpp< /dev/null | FileCheck -check-prefix ASM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ASM:#define __ASSEMBLER__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -E -dM< /dev/null | FileCheck -check-prefix BLOCKS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BLOCKS:#define __BLOCKS__ 1
end_comment

begin_comment
comment|// BLOCKS:#define __block __attribute__((__blocks__(byref)))
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++1z -E -dM< /dev/null | FileCheck -check-prefix CXX1Z %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CXX1Z:#define __GNUG__
end_comment

begin_comment
comment|// CXX1Z:#define __GXX_EXPERIMENTAL_CXX0X__ 1
end_comment

begin_comment
comment|// CXX1Z:#define __GXX_RTTI 1
end_comment

begin_comment
comment|// CXX1Z:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// CXX1Z:#define __cplusplus 201406L
end_comment

begin_comment
comment|// CXX1Z:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++1y -E -dM< /dev/null | FileCheck -check-prefix CXX1Y %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CXX1Y:#define __GNUG__
end_comment

begin_comment
comment|// CXX1Y:#define __GXX_EXPERIMENTAL_CXX0X__ 1
end_comment

begin_comment
comment|// CXX1Y:#define __GXX_RTTI 1
end_comment

begin_comment
comment|// CXX1Y:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// CXX1Y:#define __cplusplus 201402L
end_comment

begin_comment
comment|// CXX1Y:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++11 -E -dM< /dev/null | FileCheck -check-prefix CXX11 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CXX11:#define __GNUG__
end_comment

begin_comment
comment|// CXX11:#define __GXX_EXPERIMENTAL_CXX0X__ 1
end_comment

begin_comment
comment|// CXX11:#define __GXX_RTTI 1
end_comment

begin_comment
comment|// CXX11:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// CXX11:#define __cplusplus 201103L
end_comment

begin_comment
comment|// CXX11:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++98 -E -dM< /dev/null | FileCheck -check-prefix CXX98 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CXX98:#define __GNUG__
end_comment

begin_comment
comment|// CXX98:#define __GXX_RTTI 1
end_comment

begin_comment
comment|// CXX98:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// CXX98:#define __cplusplus 199711L
end_comment

begin_comment
comment|// CXX98:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fdeprecated-macro -E -dM< /dev/null | FileCheck -check-prefix DEPRECATED %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DEPRECATED:#define __DEPRECATED 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -E -dM< /dev/null | FileCheck -check-prefix C99 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C99:#define __STDC_VERSION__ 199901L
end_comment

begin_comment
comment|// C99:#define __STRICT_ANSI__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c11 -E -dM< /dev/null | FileCheck -check-prefix C11 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C11:#define __STDC_UTF_16__ 1
end_comment

begin_comment
comment|// C11:#define __STDC_UTF_32__ 1
end_comment

begin_comment
comment|// C11:#define __STDC_VERSION__ 201112L
end_comment

begin_comment
comment|// C11:#define __STRICT_ANSI__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM< /dev/null | FileCheck -check-prefix COMMON %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// COMMON:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// COMMON:#define __FINITE_MATH_ONLY__ 0
end_comment

begin_comment
comment|// COMMON:#define __GNUC_MINOR__
end_comment

begin_comment
comment|// COMMON:#define __GNUC_PATCHLEVEL__
end_comment

begin_comment
comment|// COMMON:#define __GNUC_STDC_INLINE__ 1
end_comment

begin_comment
comment|// COMMON:#define __GNUC__
end_comment

begin_comment
comment|// COMMON:#define __GXX_ABI_VERSION
end_comment

begin_comment
comment|// COMMON:#define __ORDER_BIG_ENDIAN__ 4321
end_comment

begin_comment
comment|// COMMON:#define __ORDER_LITTLE_ENDIAN__ 1234
end_comment

begin_comment
comment|// COMMON:#define __ORDER_PDP_ENDIAN__ 3412
end_comment

begin_comment
comment|// COMMON:#define __STDC_HOSTED__ 1
end_comment

begin_comment
comment|// COMMON:#define __STDC_VERSION__
end_comment

begin_comment
comment|// COMMON:#define __STDC__ 1
end_comment

begin_comment
comment|// COMMON:#define __VERSION__
end_comment

begin_comment
comment|// COMMON:#define __clang__ 1
end_comment

begin_comment
comment|// COMMON:#define __clang_major__ {{[0-9]+}}
end_comment

begin_comment
comment|// COMMON:#define __clang_minor__ {{[0-9]+}}
end_comment

begin_comment
comment|// COMMON:#define __clang_patchlevel__ {{[0-9]+}}
end_comment

begin_comment
comment|// COMMON:#define __clang_version__
end_comment

begin_comment
comment|// COMMON:#define __llvm__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -E -dM< /dev/null | FileCheck -check-prefix FREESTANDING %s
end_comment

begin_comment
comment|// FREESTANDING:#define __STDC_HOSTED__ 0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=gnu++1z -E -dM< /dev/null | FileCheck -check-prefix GXX1Z %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GXX1Z:#define __GNUG__
end_comment

begin_comment
comment|// GXX1Z:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// GXX1Z:#define __cplusplus 201406L
end_comment

begin_comment
comment|// GXX1Z:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=gnu++1y -E -dM< /dev/null | FileCheck -check-prefix GXX1Y %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GXX1Y:#define __GNUG__
end_comment

begin_comment
comment|// GXX1Y:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// GXX1Y:#define __cplusplus 201402L
end_comment

begin_comment
comment|// GXX1Y:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=gnu++11 -E -dM< /dev/null | FileCheck -check-prefix GXX11 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GXX11:#define __GNUG__
end_comment

begin_comment
comment|// GXX11:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// GXX11:#define __cplusplus 201103L
end_comment

begin_comment
comment|// GXX11:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=gnu++98 -E -dM< /dev/null | FileCheck -check-prefix GXX98 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GXX98:#define __GNUG__
end_comment

begin_comment
comment|// GXX98:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// GXX98:#define __cplusplus 199711L
end_comment

begin_comment
comment|// GXX98:#define __private_extern__ extern
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=iso9899:199409 -E -dM< /dev/null | FileCheck -check-prefix C94 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C94:#define __STDC_VERSION__ 199409L
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -triple i686-pc-win32 -E -dM< /dev/null | FileCheck -check-prefix MSEXT %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSEXT-NOT:#define __STDC__
end_comment

begin_comment
comment|// MSEXT:#define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// MSEXT-NOT:#define _NATIVE_WCHAR_T_DEFINED 1
end_comment

begin_comment
comment|// MSEXT-NOT:#define _WCHAR_T_DEFINED 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -fms-extensions -triple i686-pc-win32 -E -dM< /dev/null | FileCheck -check-prefix MSEXT-CXX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSEXT-CXX:#define _NATIVE_WCHAR_T_DEFINED 1
end_comment

begin_comment
comment|// MSEXT-CXX:#define _WCHAR_T_DEFINED 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -fno-wchar -fms-extensions -triple i686-pc-win32 -E -dM< /dev/null | FileCheck -check-prefix MSEXT-CXX-NOWCHAR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSEXT-CXX-NOWCHAR-NOT:#define _NATIVE_WCHAR_T_DEFINED 1
end_comment

begin_comment
comment|// MSEXT-CXX-NOWCHAR-NOT:#define _WCHAR_T_DEFINED 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x objective-c -E -dM< /dev/null | FileCheck -check-prefix OBJC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// OBJC:#define OBJC_NEW_PROPERTIES 1
end_comment

begin_comment
comment|// OBJC:#define __NEXT_RUNTIME__ 1
end_comment

begin_comment
comment|// OBJC:#define __OBJC__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x objective-c -fobjc-gc -E -dM< /dev/null | FileCheck -check-prefix OBJCGC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// OBJCGC:#define __OBJC_GC__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x objective-c -fobjc-exceptions -E -dM< /dev/null | FileCheck -check-prefix NONFRAGILE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NONFRAGILE:#define OBJC_ZEROCOST_EXCEPTIONS 1
end_comment

begin_comment
comment|// NONFRAGILE:#define __OBJC2__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM< /dev/null | FileCheck -check-prefix O0 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O0:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// O0-NOT:#define __OPTIMIZE_SIZE__
end_comment

begin_comment
comment|// O0-NOT:#define __OPTIMIZE__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fno-inline -O3 -E -dM< /dev/null | FileCheck -check-prefix NO_INLINE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NO_INLINE:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// NO_INLINE-NOT:#define __OPTIMIZE_SIZE__
end_comment

begin_comment
comment|// NO_INLINE:#define __OPTIMIZE__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O1 -E -dM< /dev/null | FileCheck -check-prefix O1 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O1-NOT:#define __OPTIMIZE_SIZE__
end_comment

begin_comment
comment|// O1:#define __OPTIMIZE__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -E -dM< /dev/null | FileCheck -check-prefix Os %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Os:#define __OPTIMIZE_SIZE__ 1
end_comment

begin_comment
comment|// Os:#define __OPTIMIZE__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Oz -E -dM< /dev/null | FileCheck -check-prefix Oz %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Oz:#define __OPTIMIZE_SIZE__ 1
end_comment

begin_comment
comment|// Oz:#define __OPTIMIZE__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fpascal-strings -E -dM< /dev/null | FileCheck -check-prefix PASCAL %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PASCAL:#define __PASCAL_STRINGS__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM< /dev/null | FileCheck -check-prefix SCHAR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SCHAR:#define __STDC__ 1
end_comment

begin_comment
comment|// SCHAR-NOT:#define __UNSIGNED_CHAR__
end_comment

begin_comment
comment|// SCHAR:#define __clang__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -fshort-wchar< /dev/null | FileCheck -check-prefix SHORTWCHAR %s
end_comment

begin_comment
comment|// wchar_t is u16 for targeting Win32.
end_comment

begin_comment
comment|// FIXME: Implement and check x86_64-cygwin.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -fno-short-wchar -triple=x86_64-w64-mingw32< /dev/null | FileCheck -check-prefix SHORTWCHAR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SHORTWCHAR: #define __SIZEOF_WCHAR_T__ 2
end_comment

begin_comment
comment|// SHORTWCHAR: #define __WCHAR_MAX__ 65535
end_comment

begin_comment
comment|// SHORTWCHAR: #define __WCHAR_TYPE__ unsigned short
end_comment

begin_comment
comment|// SHORTWCHAR: #define __WCHAR_WIDTH__ 16
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -fno-short-wchar -triple=i686-unknown-unknown< /dev/null | FileCheck -check-prefix SHORTWCHAR2 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -fno-short-wchar -triple=x86_64-unknown-unknown< /dev/null | FileCheck -check-prefix SHORTWCHAR2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SHORTWCHAR2: #define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// SHORTWCHAR2: #define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// Other definitions vary from platform to platform
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=aarch64-none-none< /dev/null | FileCheck -check-prefix AARCH64 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm64-none-none< /dev/null | FileCheck -check-prefix AARCH64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AARCH64:#define _LP64 1
end_comment

begin_comment
comment|// AARCH64-NOT:#define __AARCH64EB__ 1
end_comment

begin_comment
comment|// AARCH64:#define __AARCH64EL__ 1
end_comment

begin_comment
comment|// AARCH64-NOT:#define __AARCH_BIG_ENDIAN 1
end_comment

begin_comment
comment|// AARCH64:#define __ARM_64BIT_STATE 1
end_comment

begin_comment
comment|// AARCH64:#define __ARM_ARCH 8
end_comment

begin_comment
comment|// AARCH64:#define __ARM_ARCH_ISA_A64 1
end_comment

begin_comment
comment|// AARCH64-NOT:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// AARCH64:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// AARCH64:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// AARCH64:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// AARCH64:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// AARCH64:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// AARCH64:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// AARCH64:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// AARCH64:#define __DECIMAL_DIG__ 36
end_comment

begin_comment
comment|// AARCH64:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// AARCH64:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// AARCH64:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// AARCH64:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// AARCH64:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// AARCH64:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// AARCH64:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// AARCH64:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// AARCH64:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// AARCH64:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966L
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_DIG__ 33
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_EPSILON__ 1.92592994438723585305597794258492732e-34L
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MANT_DIG__ 113
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MAX__ 1.18973149535723176508575932662800702e+4932L
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// AARCH64:#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
end_comment

begin_comment
comment|// AARCH64:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// AARCH64:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64:#define __LP64__ 1
end_comment

begin_comment
comment|// AARCH64:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// AARCH64:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_INT128__ 16
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// AARCH64:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// AARCH64:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// AARCH64:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// AARCH64:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// AARCH64:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// AARCH64:#define __WCHAR_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64:#define __WCHAR_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64:#define __WCHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// AARCH64:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// AARCH64:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64:#define __aarch64__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=aarch64_be-none-none< /dev/null | FileCheck -check-prefix AARCH64-BE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm64_be-none-none< /dev/null | FileCheck -check-prefix AARCH64-BE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AARCH64-BE:#define _LP64 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __AARCH64EB__ 1
end_comment

begin_comment
comment|// AARCH64-BE-NOT:#define __AARCH64EL__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __AARCH_BIG_ENDIAN 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __ARM_64BIT_STATE 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __ARM_ARCH 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __ARM_ARCH_ISA_A64 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// AARCH64-BE:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-BE:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// AARCH64-BE:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// AARCH64-BE:#define __DECIMAL_DIG__ 36
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// AARCH64-BE:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64-BE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966L
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_DIG__ 33
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_EPSILON__ 1.92592994438723585305597794258492732e-34L
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MANT_DIG__ 113
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MAX__ 1.18973149535723176508575932662800702e+4932L
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// AARCH64-BE:#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
end_comment

begin_comment
comment|// AARCH64-BE:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// AARCH64-BE:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-BE:#define __LP64__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-BE:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-BE:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_INT128__ 16
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64-BE:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64-BE:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// AARCH64-BE:#define __WCHAR_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-BE:#define __WCHAR_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-BE:#define __WCHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// AARCH64-BE:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64-BE:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-BE:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64-BE:#define __aarch64__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=aarch64-netbsd< /dev/null | FileCheck -check-prefix AARCH64-NETBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define _LP64 1
end_comment

begin_comment
comment|// AARCH64-NETBSD-NOT:#define __AARCH64EB__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __AARCH64EL__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD-NOT:#define __AARCH_BIG_ENDIAN 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __ARM_64BIT_STATE 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __ARM_ARCH 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __ARM_ARCH_ISA_A64 1
end_comment

begin_comment
comment|// AARCH64-NETBSD-NOT:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __DECIMAL_DIG__ 36
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __ELF__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_DIG__ 33
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_EPSILON__ 1.92592994438723585305597794258492732e-34L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MANT_DIG__ 113
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MAX__ 1.18973149535723176508575932662800702e+4932L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __LP64__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __NetBSD__ 1
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// AARCH64-NETBSD:#define __aarch64__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm-none-none< /dev/null | FileCheck -check-prefix ARM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM-NOT:#define _LP64
end_comment

begin_comment
comment|// ARM:#define __APCS_32__ 1
end_comment

begin_comment
comment|// ARM-NOT:#define __ARMEB__ 1
end_comment

begin_comment
comment|// ARM:#define __ARMEL__ 1
end_comment

begin_comment
comment|// ARM:#define __ARM_ARCH_6J__ 1
end_comment

begin_comment
comment|// ARM-NOT:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// ARM:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// ARM:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// ARM:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// ARM:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// ARM:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// ARM:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARM:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARM:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARM:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// ARM:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// ARM:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// ARM:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// ARM:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// ARM:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// ARM:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// ARM:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// ARM:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// ARM:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// ARM:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// ARM:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// ARM:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// ARM:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// ARM:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// ARM:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// ARM:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// ARM:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// ARM:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// ARM:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// ARM:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARM:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// ARM:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// ARM:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARM:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// ARM:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARM:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// ARM:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// ARM:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// ARM:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// ARM:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// ARM:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// ARM:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// ARM:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARM:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARM:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARM:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// ARM:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// ARM:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// ARM:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARM-NOT:#define __LP64__
end_comment

begin_comment
comment|// ARM:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// ARM:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// ARM:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// ARM:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// ARM:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// ARM:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARM:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// ARM:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// ARM:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARM:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// ARM:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARM:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARM:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// ARM:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// ARM:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// ARM:#define __WCHAR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM:#define __WCHAR_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// ARM:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __arm 1
end_comment

begin_comment
comment|// ARM:#define __arm__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=armeb-none-none< /dev/null | FileCheck -check-prefix ARM-BE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM-BE-NOT:#define _LP64
end_comment

begin_comment
comment|// ARM-BE:#define __APCS_32__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __ARMEB__ 1
end_comment

begin_comment
comment|// ARM-BE-NOT:#define __ARMEL__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __ARM_ARCH_6J__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// ARM-BE:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// ARM-BE:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-BE:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM-BE:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// ARM-BE:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// ARM-BE:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// ARM-BE:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-BE:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM-BE:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM-BE:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// ARM-BE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// ARM-BE:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-BE:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM-BE:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM-BE:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-BE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// ARM-BE:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM-BE:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-BE:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-BE:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-BE:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-BE:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-BE:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM-BE:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM-BE:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// ARM-BE:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM-BE:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM-BE:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-BE:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-BE:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-BE:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-BE:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARM-BE:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// ARM-BE:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// ARM-BE:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARM-BE:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// ARM-BE:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// ARM-BE:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// ARM-BE:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM-BE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM-BE:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// ARM-BE:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-BE:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARM-BE-NOT:#define __LP64__
end_comment

begin_comment
comment|// ARM-BE:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// ARM-BE:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// ARM-BE:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// ARM-BE:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// ARM-BE:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-BE:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// ARM-BE:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-BE:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARM-BE:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-BE:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// ARM-BE:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-BE:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// ARM-BE:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-BE:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARM-BE:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-BE:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-BE:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// ARM-BE:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM-BE:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARM-BE:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-BE:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARM-BE:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-BE:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// ARM-BE:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM-BE:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// ARM-BE:#define __WCHAR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-BE:#define __WCHAR_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-BE:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// ARM-BE:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-BE:#define __arm 1
end_comment

begin_comment
comment|// ARM-BE:#define __arm__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm-none-linux-gnueabi -target-feature +soft-float -target-feature +soft-float-abi< /dev/null | FileCheck -check-prefix ARMEABISOFTFP %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARMEABISOFTFP-NOT:#define _LP64
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __APCS_32__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP-NOT:#define __ARMEB__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __ARMEL__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __ARM_ARCH 6
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __ARM_ARCH_6J__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP-NOT:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __ARM_EABI__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __ARM_PCS 1
end_comment

begin_comment
comment|// ARMEABISOFTFP-NOT:#define __ARM_PCS_VFP 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARMEABISOFTFP-NOT:#define __LP64__
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __SOFTFP__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __WCHAR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __WCHAR_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __arm 1
end_comment

begin_comment
comment|// ARMEABISOFTFP:#define __arm__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm-none-linux-gnueabi< /dev/null | FileCheck -check-prefix ARMEABIHARDFP %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARMEABIHARDFP-NOT:#define _LP64
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __APCS_32__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP-NOT:#define __ARMEB__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __ARMEL__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __ARM_ARCH 6
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __ARM_ARCH_6J__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP-NOT:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __ARM_EABI__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __ARM_PCS 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __ARM_PCS_VFP 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARMEABIHARDFP-NOT:#define __LP64__
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP-NOT:#define __SOFTFP__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __WCHAR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __WCHAR_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __arm 1
end_comment

begin_comment
comment|// ARMEABIHARDFP:#define __arm__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm-netbsd-eabi< /dev/null | FileCheck -check-prefix ARM-NETBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM-NETBSD-NOT:#define _LP64
end_comment

begin_comment
comment|// ARM-NETBSD:#define __APCS_32__ 1
end_comment

begin_comment
comment|// ARM-NETBSD-NOT:#define __ARMEB__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __ARMEL__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __ARM_ARCH_6J__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __ARM_DWARF_EH__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __ARM_EABI__ 1
end_comment

begin_comment
comment|// ARM-NETBSD-NOT:#define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// ARM-NETBSD:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// ARM-NETBSD:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// ARM-NETBSD:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// ARM-NETBSD:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// ARM-NETBSD-NOT:#define __LP64__
end_comment

begin_comment
comment|// ARM-NETBSD:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// ARM-NETBSD:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// ARM-NETBSD:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// ARM-NETBSD:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM-NETBSD:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// ARM-NETBSD:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// ARM-NETBSD:#define __arm 1
end_comment

begin_comment
comment|// ARM-NETBSD:#define __arm__ 1
end_comment

begin_comment
comment|// RUN: %clang -target arm -arch armv7s -x c -E -dM %s -o - | FileCheck --check-prefix=ARM-DARWIN-NO-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -arch armv6m -x c -E -dM %s -o - | FileCheck --check-prefix=ARM-DARWIN-NO-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -arch armv7m -x c -E -dM %s -o - | FileCheck --check-prefix=ARM-DARWIN-NO-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -arch armv7em -x c -E -dM %s -o - | FileCheck --check-prefix=ARM-DARWIN-NO-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbv7-apple-darwin-eabi -arch armv7 -x c -E -dM %s -o - | FileCheck --check-prefix=ARM-DARWIN-NO-EABI %s
end_comment

begin_comment
comment|// ARM-DARWIN-NO-EABI-NOT: #define __ARM_EABI__ 1
end_comment

begin_comment
comment|// Check that -mhwdiv works properly for targets which don't have the hwdiv feature enabled by default.
end_comment

begin_comment
comment|// RUN: %clang -target arm -mhwdiv=arm -x c -E -dM %s -o - | FileCheck --check-prefix=ARMHWDIV-ARM %s
end_comment

begin_comment
comment|// ARMHWDIV-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBHWDIV-THUMB %s
end_comment

begin_comment
comment|// THUMBHWDIV-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target arm -x c -E -dM %s -o - | FileCheck --check-prefix=ARM-FALSE %s
end_comment

begin_comment
comment|// ARM-FALSE-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMB-FALSE %s
end_comment

begin_comment
comment|// THUMB-FALSE-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target arm -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBHWDIV-ARM-FALSE %s
end_comment

begin_comment
comment|// THUMBHWDIV-ARM-FALSE-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mhwdiv=arm -x c -E -dM %s -o - | FileCheck --check-prefix=ARMHWDIV-THUMB-FALSE %s
end_comment

begin_comment
comment|// ARMHWDIV-THUMB-FALSE-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=armv8-none-none< /dev/null | FileCheck -check-prefix ARMv8 %s
end_comment

begin_comment
comment|// ARMv8: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARMv8-NOT: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=armebv8-none-none< /dev/null | FileCheck -check-prefix ARMebv8 %s
end_comment

begin_comment
comment|// ARMebv8: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// ARMebv8-NOT: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbv8< /dev/null | FileCheck -check-prefix Thumbv8 %s
end_comment

begin_comment
comment|// Thumbv8: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// Thumbv8: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbebv8< /dev/null | FileCheck -check-prefix Thumbebv8 %s
end_comment

begin_comment
comment|// Thumbebv8: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// Thumbebv8: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbv5< /dev/null | FileCheck -check-prefix Thumbv5 %s
end_comment

begin_comment
comment|// Thumbv5: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// Thumbv5-NOT: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbv6t2< /dev/null | FileCheck -check-prefix Thumbv6t2 %s
end_comment

begin_comment
comment|// Thumbv6t2: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// Thumbv6t2: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbv7< /dev/null | FileCheck -check-prefix Thumbv7 %s
end_comment

begin_comment
comment|// Thumbv7: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// Thumbv7: #define __thumb2__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbebv7< /dev/null | FileCheck -check-prefix Thumbebv7 %s
end_comment

begin_comment
comment|// Thumbebv7: #define __THUMB_INTERWORK__ 1
end_comment

begin_comment
comment|// Thumbebv7: #define __thumb2__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-none-none< /dev/null | FileCheck -check-prefix I386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386-NOT:#define _LP64
end_comment

begin_comment
comment|// I386:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// I386:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// I386:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// I386:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// I386:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// I386:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// I386:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// I386:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// I386:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// I386:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// I386:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// I386:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// I386:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// I386:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// I386:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// I386:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// I386:#define __FLT_EVAL_METHOD__ 2
end_comment

begin_comment
comment|// I386:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// I386:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// I386:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// I386:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// I386:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// I386:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// I386:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// I386:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// I386:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// I386:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// I386:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// I386:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// I386:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// I386:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// I386:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// I386:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// I386:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// I386:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// I386:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// I386:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// I386:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// I386:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// I386:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// I386:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// I386:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// I386:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// I386:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// I386:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// I386:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// I386:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// I386:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// I386:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// I386:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// I386:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// I386:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// I386:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// I386:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// I386:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// I386:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// I386:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// I386:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// I386:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// I386:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// I386:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// I386:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// I386-NOT:#define __LP64__
end_comment

begin_comment
comment|// I386:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// I386:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// I386:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// I386:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// I386:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// I386:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_LONG_DOUBLE__ 12
end_comment

begin_comment
comment|// I386:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// I386:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// I386:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// I386:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// I386:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// I386:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// I386:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// I386:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// I386:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// I386:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// I386:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// I386:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// I386:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// I386:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// I386:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// I386:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __i386 1
end_comment

begin_comment
comment|// I386:#define __i386__ 1
end_comment

begin_comment
comment|// I386:#define i386 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-pc-linux-gnu -target-cpu pentium4< /dev/null | FileCheck -check-prefix I386-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386-LINUX-NOT:#define _LP64
end_comment

begin_comment
comment|// I386-LINUX:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// I386-LINUX:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-LINUX:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// I386-LINUX:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// I386-LINUX:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// I386-LINUX:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// I386-LINUX:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-LINUX:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// I386-LINUX:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// I386-LINUX:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-LINUX:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// I386-LINUX:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386-LINUX:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-LINUX:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// I386-LINUX:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-LINUX:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// I386-LINUX:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// I386-LINUX:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386-LINUX:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-LINUX:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-LINUX:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-LINUX:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// I386-LINUX:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// I386-LINUX:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// I386-LINUX:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// I386-LINUX:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// I386-LINUX:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// I386-LINUX:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// I386-LINUX:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// I386-LINUX:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-LINUX:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// I386-LINUX-NOT:#define __LP64__
end_comment

begin_comment
comment|// I386-LINUX:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// I386-LINUX:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// I386-LINUX:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// I386-LINUX:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// I386-LINUX:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// I386-LINUX:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_LONG_DOUBLE__ 12
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// I386-LINUX:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386-LINUX:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// I386-LINUX:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-LINUX:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// I386-LINUX:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-LINUX:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// I386-LINUX:#define __i386 1
end_comment

begin_comment
comment|// I386-LINUX:#define __i386__ 1
end_comment

begin_comment
comment|// I386-LINUX:#define i386 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-netbsd< /dev/null | FileCheck -check-prefix I386-NETBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386-NETBSD-NOT:#define _LP64
end_comment

begin_comment
comment|// I386-NETBSD:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// I386-NETBSD:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-NETBSD:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// I386-NETBSD:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// I386-NETBSD:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_EVAL_METHOD__ 2
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// I386-NETBSD:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// I386-NETBSD:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// I386-NETBSD:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// I386-NETBSD:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// I386-NETBSD:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// I386-NETBSD-NOT:#define __LP64__
end_comment

begin_comment
comment|// I386-NETBSD:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// I386-NETBSD:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// I386-NETBSD:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_LONG_DOUBLE__ 12
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// I386-NETBSD:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// I386-NETBSD:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// I386-NETBSD:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// I386-NETBSD:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// I386-NETBSD:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// I386-NETBSD:#define __i386 1
end_comment

begin_comment
comment|// I386-NETBSD:#define __i386__ 1
end_comment

begin_comment
comment|// I386-NETBSD:#define i386 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-netbsd -target-feature +sse2< /dev/null | FileCheck -check-prefix I386-NETBSD-SSE %s
end_comment

begin_comment
comment|// I386-NETBSD-SSE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-netbsd6< /dev/null | FileCheck -check-prefix I386-NETBSD6 %s
end_comment

begin_comment
comment|// I386-NETBSD6:#define __FLT_EVAL_METHOD__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-netbsd6 -target-feature +sse2< /dev/null | FileCheck -check-prefix I386-NETBSD6-SSE %s
end_comment

begin_comment
comment|// I386-NETBSD6-SSE:#define __FLT_EVAL_METHOD__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips-none-none< /dev/null | FileCheck -check-prefix MIPS32BE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS32BE:#define MIPSEB 1
end_comment

begin_comment
comment|// MIPS32BE:#define _ABIO32 1
end_comment

begin_comment
comment|// MIPS32BE-NOT:#define _LP64
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPSEB 1
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_ARCH "mips32r2"
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_ARCH_MIPS32R2 1
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_FPSET 16
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_SIM _ABIO32
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_SZINT 32
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_SZLONG 32
end_comment

begin_comment
comment|// MIPS32BE:#define _MIPS_SZPTR 32
end_comment

begin_comment
comment|// MIPS32BE:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// MIPS32BE:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32BE:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// MIPS32BE:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MIPS32BE:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// MIPS32BE:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// MIPS32BE:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// MIPS32BE:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32BE:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32BE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// MIPS32BE:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32BE:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32BE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// MIPS32BE:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS32BE:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32BE:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32BE:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32BE:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// MIPS32BE:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS32BE:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS32BE:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32BE:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32BE:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32BE:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32BE:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS32BE:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS32BE:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS32BE:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// MIPS32BE:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// MIPS32BE:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS32BE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MIPS32BE:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// MIPS32BE:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32BE:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// MIPS32BE-NOT:#define __LP64__
end_comment

begin_comment
comment|// MIPS32BE:#define __MIPSEB 1
end_comment

begin_comment
comment|// MIPS32BE:#define __MIPSEB__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __PRAGMA_REDEFINE_EXTNAME 1
end_comment

begin_comment
comment|// MIPS32BE:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// MIPS32BE:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// MIPS32BE:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// MIPS32BE:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32BE:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32BE:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __STDC_HOSTED__ 0
end_comment

begin_comment
comment|// MIPS32BE:#define __STDC_VERSION__ 199901L
end_comment

begin_comment
comment|// MIPS32BE:#define __STDC__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS32BE:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS32BE:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// MIPS32BE:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32BE:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// MIPS32BE:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// MIPS32BE:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32BE:#define __clang__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __llvm__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __mips 32
end_comment

begin_comment
comment|// MIPS32BE:#define __mips__ 1
end_comment

begin_comment
comment|// MIPS32BE:#define __mips_fpr 32
end_comment

begin_comment
comment|// MIPS32BE:#define __mips_hard_float 1
end_comment

begin_comment
comment|// MIPS32BE:#define __mips_o32 1
end_comment

begin_comment
comment|// MIPS32BE:#define _mips 1
end_comment

begin_comment
comment|// MIPS32BE:#define mips 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mipsel-none-none< /dev/null | FileCheck -check-prefix MIPS32EL %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS32EL:#define MIPSEL 1
end_comment

begin_comment
comment|// MIPS32EL:#define _ABIO32 1
end_comment

begin_comment
comment|// MIPS32EL-NOT:#define _LP64
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPSEL 1
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_ARCH "mips32r2"
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_ARCH_MIPS32R2 1
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_FPSET 16
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_SIM _ABIO32
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_SZINT 32
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_SZLONG 32
end_comment

begin_comment
comment|// MIPS32EL:#define _MIPS_SZPTR 32
end_comment

begin_comment
comment|// MIPS32EL:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// MIPS32EL:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32EL:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// MIPS32EL:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MIPS32EL:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// MIPS32EL:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// MIPS32EL:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// MIPS32EL:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32EL:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32EL:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// MIPS32EL:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32EL:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32EL:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// MIPS32EL:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS32EL:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32EL:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32EL:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32EL:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// MIPS32EL:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS32EL:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS32EL:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32EL:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32EL:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32EL:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32EL:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS32EL:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS32EL:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS32EL:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// MIPS32EL:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// MIPS32EL:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS32EL:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MIPS32EL:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// MIPS32EL:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS32EL:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// MIPS32EL-NOT:#define __LP64__
end_comment

begin_comment
comment|// MIPS32EL:#define __MIPSEL 1
end_comment

begin_comment
comment|// MIPS32EL:#define __MIPSEL__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __PRAGMA_REDEFINE_EXTNAME 1
end_comment

begin_comment
comment|// MIPS32EL:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// MIPS32EL:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// MIPS32EL:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// MIPS32EL:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// MIPS32EL:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32EL:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS32EL:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS32EL:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// MIPS32EL:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS32EL:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// MIPS32EL:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// MIPS32EL:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS32EL:#define __clang__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __llvm__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __mips 32
end_comment

begin_comment
comment|// MIPS32EL:#define __mips__ 1
end_comment

begin_comment
comment|// MIPS32EL:#define __mips_fpr 32
end_comment

begin_comment
comment|// MIPS32EL:#define __mips_hard_float 1
end_comment

begin_comment
comment|// MIPS32EL:#define __mips_o32 1
end_comment

begin_comment
comment|// MIPS32EL:#define _mips 1
end_comment

begin_comment
comment|// MIPS32EL:#define mips 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips64-none-none< /dev/null | FileCheck -check-prefix MIPS64BE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64BE:#define MIPSEB 1
end_comment

begin_comment
comment|// MIPS64BE:#define _ABI64 3
end_comment

begin_comment
comment|// MIPS64BE:#define _LP64 1
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPSEB 1
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_ARCH "mips64r2"
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_ARCH_MIPS64R2 1
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_SIM _ABI64
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_SZINT 32
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_SZLONG 64
end_comment

begin_comment
comment|// MIPS64BE:#define _MIPS_SZPTR 64
end_comment

begin_comment
comment|// MIPS64BE:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// MIPS64BE:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64BE:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MIPS64BE:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// MIPS64BE:#define __DECIMAL_DIG__ 36
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// MIPS64BE:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// MIPS64BE:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64BE:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64BE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// MIPS64BE:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64BE:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64BE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// MIPS64BE:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS64BE:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64BE:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS64BE:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64BE:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// MIPS64BE:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS64BE:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS64BE:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS64BE:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS64BE:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS64BE:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS64BE:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS64BE:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS64BE:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64BE:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64BE:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS64BE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966L
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_DIG__ 33
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_EPSILON__ 1.92592994438723585305597794258492732e-34L
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MANT_DIG__ 113
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MAX__ 1.18973149535723176508575932662800702e+4932L
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// MIPS64BE:#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
end_comment

begin_comment
comment|// MIPS64BE:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS64BE:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64BE:#define __LP64__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __MIPSEB 1
end_comment

begin_comment
comment|// MIPS64BE:#define __MIPSEB__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __PRAGMA_REDEFINE_EXTNAME 1
end_comment

begin_comment
comment|// MIPS64BE:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64BE:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// MIPS64BE:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// MIPS64BE:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64BE:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64BE:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS64BE:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS64BE:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// MIPS64BE:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64BE:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// MIPS64BE:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS64BE:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// MIPS64BE:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS64BE:#define __clang__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __llvm__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __mips 64
end_comment

begin_comment
comment|// MIPS64BE:#define __mips64 1
end_comment

begin_comment
comment|// MIPS64BE:#define __mips64__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __mips__ 1
end_comment

begin_comment
comment|// MIPS64BE:#define __mips_fpr 64
end_comment

begin_comment
comment|// MIPS64BE:#define __mips_hard_float 1
end_comment

begin_comment
comment|// MIPS64BE:#define __mips_n64 1
end_comment

begin_comment
comment|// MIPS64BE:#define _mips 1
end_comment

begin_comment
comment|// MIPS64BE:#define mips 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips64el-none-none< /dev/null | FileCheck -check-prefix MIPS64EL %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64EL:#define MIPSEL 1
end_comment

begin_comment
comment|// MIPS64EL:#define _ABI64 3
end_comment

begin_comment
comment|// MIPS64EL:#define _LP64 1
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPSEL 1
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_ARCH "mips64r2"
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_ARCH_MIPS64R2 1
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_SIM _ABI64
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_SZINT 32
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_SZLONG 64
end_comment

begin_comment
comment|// MIPS64EL:#define _MIPS_SZPTR 64
end_comment

begin_comment
comment|// MIPS64EL:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// MIPS64EL:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64EL:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MIPS64EL:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// MIPS64EL:#define __DECIMAL_DIG__ 36
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// MIPS64EL:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// MIPS64EL:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64EL:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64EL:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// MIPS64EL:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64EL:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64EL:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// MIPS64EL:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS64EL:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64EL:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS64EL:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64EL:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// MIPS64EL:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS64EL:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MIPS64EL:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// MIPS64EL:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// MIPS64EL:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS64EL:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// MIPS64EL:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS64EL:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS64EL:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64EL:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64EL:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MIPS64EL:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966L
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_DIG__ 33
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_EPSILON__ 1.92592994438723585305597794258492732e-34L
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MANT_DIG__ 113
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MAX__ 1.18973149535723176508575932662800702e+4932L
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// MIPS64EL:#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
end_comment

begin_comment
comment|// MIPS64EL:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS64EL:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64EL:#define __LP64__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __MIPSEL 1
end_comment

begin_comment
comment|// MIPS64EL:#define __MIPSEL__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __PRAGMA_REDEFINE_EXTNAME 1
end_comment

begin_comment
comment|// MIPS64EL:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// MIPS64EL:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// MIPS64EL:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// MIPS64EL:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// MIPS64EL:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64EL:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// MIPS64EL:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MIPS64EL:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// MIPS64EL:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// MIPS64EL:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// MIPS64EL:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS64EL:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// MIPS64EL:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// MIPS64EL:#define __clang__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __llvm__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __mips 64
end_comment

begin_comment
comment|// MIPS64EL:#define __mips64 1
end_comment

begin_comment
comment|// MIPS64EL:#define __mips64__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __mips__ 1
end_comment

begin_comment
comment|// MIPS64EL:#define __mips_fpr 64
end_comment

begin_comment
comment|// MIPS64EL:#define __mips_hard_float 1
end_comment

begin_comment
comment|// MIPS64EL:#define __mips_n64 1
end_comment

begin_comment
comment|// MIPS64EL:#define _mips 1
end_comment

begin_comment
comment|// MIPS64EL:#define mips 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check MIPS arch and isa macros
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips-none-none \
end_comment

begin_comment
comment|// RUN:< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-ARCH-DEF32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS-ARCH-DEF32:#define _MIPS_ARCH "mips32r2"
end_comment

begin_comment
comment|// MIPS-ARCH-DEF32:#define _MIPS_ARCH_MIPS32R2 1
end_comment

begin_comment
comment|// MIPS-ARCH-DEF32:#define _MIPS_ISA _MIPS_ISA_MIPS32
end_comment

begin_comment
comment|// MIPS-ARCH-DEF32:#define __mips_isa_rev 2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips-none-nones \
end_comment

begin_comment
comment|// RUN:            -target-cpu mips32< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-ARCH-32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS-ARCH-32:#define _MIPS_ARCH "mips32"
end_comment

begin_comment
comment|// MIPS-ARCH-32:#define _MIPS_ARCH_MIPS32 1
end_comment

begin_comment
comment|// MIPS-ARCH-32:#define _MIPS_ISA _MIPS_ISA_MIPS32
end_comment

begin_comment
comment|// MIPS-ARCH-32:#define __mips_isa_rev 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips-none-none \
end_comment

begin_comment
comment|// RUN:            -target-cpu mips32r2< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-ARCH-32R2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS-ARCH-32R2:#define _MIPS_ARCH "mips32r2"
end_comment

begin_comment
comment|// MIPS-ARCH-32R2:#define _MIPS_ARCH_MIPS32R2 1
end_comment

begin_comment
comment|// MIPS-ARCH-32R2:#define _MIPS_ISA _MIPS_ISA_MIPS32
end_comment

begin_comment
comment|// MIPS-ARCH-32R2:#define __mips_isa_rev 2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips64-none-none \
end_comment

begin_comment
comment|// RUN:< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-ARCH-DEF64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS-ARCH-DEF64:#define _MIPS_ARCH "mips64r2"
end_comment

begin_comment
comment|// MIPS-ARCH-DEF64:#define _MIPS_ARCH_MIPS64R2 1
end_comment

begin_comment
comment|// MIPS-ARCH-DEF64:#define _MIPS_ISA _MIPS_ISA_MIPS64
end_comment

begin_comment
comment|// MIPS-ARCH-DEF64:#define __mips_isa_rev 2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips64-none-none \
end_comment

begin_comment
comment|// RUN:            -target-cpu mips64< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-ARCH-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS-ARCH-64:#define _MIPS_ARCH "mips64"
end_comment

begin_comment
comment|// MIPS-ARCH-64:#define _MIPS_ARCH_MIPS64 1
end_comment

begin_comment
comment|// MIPS-ARCH-64:#define _MIPS_ISA _MIPS_ISA_MIPS64
end_comment

begin_comment
comment|// MIPS-ARCH-64:#define __mips_isa_rev 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=mips64-none-none \
end_comment

begin_comment
comment|// RUN:            -target-cpu mips64r2< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-ARCH-64R2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS-ARCH-64R2:#define _MIPS_ARCH "mips64r2"
end_comment

begin_comment
comment|// MIPS-ARCH-64R2:#define _MIPS_ARCH_MIPS64R2 1
end_comment

begin_comment
comment|// MIPS-ARCH-64R2:#define _MIPS_ISA _MIPS_ISA_MIPS64
end_comment

begin_comment
comment|// MIPS-ARCH-64R2:#define __mips_isa_rev 2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check MIPS float ABI macros
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-FABI-HARD %s
end_comment

begin_comment
comment|// MIPS-FABI-HARD:#define __mips_hard_float 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +soft-float -E -dM -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-FABI-SOFT %s
end_comment

begin_comment
comment|// MIPS-FABI-SOFT:#define __mips_soft_float 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +single-float -E -dM -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-FABI-SINGLE %s
end_comment

begin_comment
comment|// MIPS-FABI-SINGLE:#define __mips_hard_float 1
end_comment

begin_comment
comment|// MIPS-FABI-SINGLE:#define __mips_single_float 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +soft-float -target-feature +single-float \
end_comment

begin_comment
comment|// RUN:   -E -dM -ffreestanding -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-FABI-SINGLE-SOFT %s
end_comment

begin_comment
comment|// MIPS-FABI-SINGLE-SOFT:#define __mips_single_float 1
end_comment

begin_comment
comment|// MIPS-FABI-SINGLE-SOFT:#define __mips_soft_float 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check MIPS features macros
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +mips16 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS16 %s
end_comment

begin_comment
comment|// MIPS16:#define __mips16 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature -mips16 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix NOMIPS16 %s
end_comment

begin_comment
comment|// NOMIPS16-NOT:#define __mips16 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +micromips \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MICROMIPS %s
end_comment

begin_comment
comment|// MICROMIPS:#define __mips_micromips 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature -micromips \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix NOMICROMIPS %s
end_comment

begin_comment
comment|// NOMICROMIPS-NOT:#define __mips_micromips 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +dsp \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-DSP %s
end_comment

begin_comment
comment|// MIPS-DSP:#define __mips_dsp 1
end_comment

begin_comment
comment|// MIPS-DSP:#define __mips_dsp_rev 1
end_comment

begin_comment
comment|// MIPS-DSP-NOT:#define __mips_dspr2 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +dspr2 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-DSPR2 %s
end_comment

begin_comment
comment|// MIPS-DSPR2:#define __mips_dsp 1
end_comment

begin_comment
comment|// MIPS-DSPR2:#define __mips_dsp_rev 2
end_comment

begin_comment
comment|// MIPS-DSPR2:#define __mips_dspr2 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +msa \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-MSA %s
end_comment

begin_comment
comment|// MIPS-MSA:#define __mips_msa 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +nan2008 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-NAN2008 %s
end_comment

begin_comment
comment|// MIPS-NAN2008:#define __mips_nan2008 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature -fp64 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS32-MFP32 %s
end_comment

begin_comment
comment|// MIPS32-MFP32:#define _MIPS_FPSET 16
end_comment

begin_comment
comment|// MIPS32-MFP32:#define __mips_fpr 32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +fp64 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS32-MFP64 %s
end_comment

begin_comment
comment|// MIPS32-MFP64:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS32-MFP64:#define __mips_fpr 64
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +single-float \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS32-MFP32SF %s
end_comment

begin_comment
comment|// MIPS32-MFP32SF:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS32-MFP32SF:#define __mips_fpr 32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +fp64 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips64-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS64-MFP64 %s
end_comment

begin_comment
comment|// MIPS64-MFP64:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS64-MFP64:#define __mips_fpr 64
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature -fp64 -target-feature +single-float \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips64-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS64-NOMFP64 %s
end_comment

begin_comment
comment|// MIPS64-NOMFP64:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS64-NOMFP64:#define __mips_fpr 32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu mips32r6 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-XXR6 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu mips64r6 \
end_comment

begin_comment
comment|// RUN:   -E -dM -triple=mips64-none-none< /dev/null \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix MIPS-XXR6 %s
end_comment

begin_comment
comment|// MIPS-XXR6:#define _MIPS_FPSET 32
end_comment

begin_comment
comment|// MIPS-XXR6:#define __mips_fpr 64
end_comment

begin_comment
comment|// MIPS-XXR6:#define __mips_nan2008 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=msp430-none-none< /dev/null | FileCheck -check-prefix MSP430 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:#define MSP430 1
end_comment

begin_comment
comment|// MSP430-NOT:#define _LP64
end_comment

begin_comment
comment|// MSP430:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// MSP430:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MSP430:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// MSP430:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// MSP430:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// MSP430:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// MSP430:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// MSP430:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MSP430:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MSP430:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MSP430:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MSP430:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MSP430:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MSP430:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// MSP430:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MSP430:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MSP430:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// MSP430:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// MSP430:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// MSP430:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// MSP430:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// MSP430:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// MSP430:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MSP430:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MSP430:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MSP430:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// MSP430:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// MSP430:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// MSP430:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// MSP430:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// MSP430:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// MSP430:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// MSP430:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// MSP430:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MSP430:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// MSP430:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// MSP430:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// MSP430:#define __INT32_C_SUFFIX__ L
end_comment

begin_comment
comment|// MSP430:#define __INT32_FMTd__ "ld"
end_comment

begin_comment
comment|// MSP430:#define __INT32_FMTi__ "li"
end_comment

begin_comment
comment|// MSP430:#define __INT32_MAX__ 2147483647L
end_comment

begin_comment
comment|// MSP430:#define __INT32_TYPE__ long int
end_comment

begin_comment
comment|// MSP430:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MSP430:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// MSP430:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// MSP430:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// MSP430:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MSP430:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MSP430:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MSP430:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// MSP430:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST32_FMTd__ "ld"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST32_FMTi__ "li"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST32_MAX__ 2147483647L
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST32_TYPE__ long int
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// MSP430:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST32_FMTd__ "ld"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST32_FMTi__ "li"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST32_MAX__ 2147483647L
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST32_TYPE__ long int
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// MSP430:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// MSP430:#define __INT_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// MSP430:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// MSP430:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// MSP430:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// MSP430:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// MSP430:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// MSP430:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// MSP430:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// MSP430-NOT:#define __LP64__
end_comment

begin_comment
comment|// MSP430:#define __MSP430__ 1
end_comment

begin_comment
comment|// MSP430:#define __POINTER_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// MSP430:#define __PTRDIFF_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// MSP430:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// MSP430:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_INT__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_POINTER__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_PTRDIFF_T__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_SIZE_T__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_WCHAR_T__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZEOF_WINT_T__ 2
end_comment

begin_comment
comment|// MSP430:#define __SIZE_MAX__ 65535
end_comment

begin_comment
comment|// MSP430:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// MSP430:#define __SIZE_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __UINT16_C_SUFFIX__ U
end_comment

begin_comment
comment|// MSP430:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// MSP430:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MSP430:#define __UINT32_C_SUFFIX__ UL
end_comment

begin_comment
comment|// MSP430:#define __UINT32_MAX__ 4294967295UL
end_comment

begin_comment
comment|// MSP430:#define __UINT32_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MSP430:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MSP430:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// MSP430:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// MSP430:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MSP430:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// MSP430:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MSP430:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// MSP430:#define __UINTPTR_MAX__ 65535
end_comment

begin_comment
comment|// MSP430:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINTPTR_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST32_MAX__ 4294967295UL
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST32_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// MSP430:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST32_MAX__ 4294967295UL
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST32_TYPE__ long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// MSP430:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// MSP430:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// MSP430:#define __WCHAR_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// MSP430:#define __WCHAR_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// MSP430:#define __WINT_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __clang__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=nvptx-none-none< /dev/null | FileCheck -check-prefix NVPTX32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NVPTX32-NOT:#define _LP64
end_comment

begin_comment
comment|// NVPTX32:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// NVPTX32:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX32:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// NVPTX32:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// NVPTX32:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// NVPTX32:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// NVPTX32:#define __FINITE_MATH_ONLY__ 0
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// NVPTX32:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// NVPTX32:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX32:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// NVPTX32:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// NVPTX32:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX32:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// NVPTX32:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX32:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX32:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX32:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// NVPTX32:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// NVPTX32:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// NVPTX32:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// NVPTX32:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX32:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// NVPTX32:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX32:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// NVPTX32:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// NVPTX32:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// NVPTX32:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// NVPTX32:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// NVPTX32:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// NVPTX32:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// NVPTX32:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// NVPTX32:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// NVPTX32:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX32:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX32:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX32:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// NVPTX32:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// NVPTX32:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// NVPTX32:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// NVPTX32:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// NVPTX32:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// NVPTX32:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// NVPTX32:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX32-NOT:#define __LP64__
end_comment

begin_comment
comment|// NVPTX32:#define __NVPTX__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __PRAGMA_REDEFINE_EXTNAME 1
end_comment

begin_comment
comment|// NVPTX32:#define __PTRDIFF_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __PTX__ 1
end_comment

begin_comment
comment|// NVPTX32:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// NVPTX32:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX32:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// NVPTX32:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX32:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX32:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// NVPTX32:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX32:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// NVPTX32:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX32:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// NVPTX32:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// NVPTX32:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX32:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// NVPTX32:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// NVPTX32:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// NVPTX32:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// NVPTX32:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX32:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX32:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// NVPTX32:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// NVPTX32:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// NVPTX32:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX32:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// NVPTX32:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX32:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// NVPTX32:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=nvptx64-none-none< /dev/null | FileCheck -check-prefix NVPTX64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NVPTX64:#define _LP64 1
end_comment

begin_comment
comment|// NVPTX64:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// NVPTX64:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX64:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __CONSTANT_CFSTRINGS__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// NVPTX64:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// NVPTX64:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// NVPTX64:#define __FINITE_MATH_ONLY__ 0
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// NVPTX64:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// NVPTX64:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX64:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// NVPTX64:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// NVPTX64:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX64:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// NVPTX64:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX64:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX64:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX64:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX64:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// NVPTX64:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// NVPTX64:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// NVPTX64:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// NVPTX64:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX64:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// NVPTX64:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX64:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// NVPTX64:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// NVPTX64:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// NVPTX64:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// NVPTX64:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// NVPTX64:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// NVPTX64:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// NVPTX64:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// NVPTX64:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// NVPTX64:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __INTPTR_FMTd__ "lld"
end_comment

begin_comment
comment|// NVPTX64:#define __INTPTR_FMTi__ "lli"
end_comment

begin_comment
comment|// NVPTX64:#define __INTPTR_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// NVPTX64:#define __INTPTR_TYPE__ long long int
end_comment

begin_comment
comment|// NVPTX64:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// NVPTX64:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// NVPTX64:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// NVPTX64:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// NVPTX64:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// NVPTX64:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// NVPTX64:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// NVPTX64:#define __LP64__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __NVPTX__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __PRAGMA_REDEFINE_EXTNAME 1
end_comment

begin_comment
comment|// NVPTX64:#define __PTRDIFF_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __PTX__ 1
end_comment

begin_comment
comment|// NVPTX64:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// NVPTX64:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// NVPTX64:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX64:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// NVPTX64:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// NVPTX64:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// NVPTX64:#define __SIZE_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX64:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// NVPTX64:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX64:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// NVPTX64:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX64:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// NVPTX64:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// NVPTX64:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// NVPTX64:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// NVPTX64:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// NVPTX64:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// NVPTX64:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// NVPTX64:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __UINTPTR_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// NVPTX64:#define __UINTPTR_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// NVPTX64:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// NVPTX64:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// NVPTX64:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// NVPTX64:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// NVPTX64:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// NVPTX64:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// NVPTX64:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc-none-none -target-cpu 603e< /dev/null | FileCheck -check-prefix PPC603E %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC603E:#define _ARCH_603 1
end_comment

begin_comment
comment|// PPC603E:#define _ARCH_603E 1
end_comment

begin_comment
comment|// PPC603E:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC603E:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPC603E:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC603E-NOT:#define _LP64
end_comment

begin_comment
comment|// PPC603E:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC603E:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// PPC603E:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC603E:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC603E:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC603E:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC603E:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC603E:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC603E:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC603E:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC603E:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC603E:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC603E:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC603E:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC603E:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC603E:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC603E:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC603E:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC603E:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC603E:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC603E:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC603E:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC603E:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC603E:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC603E:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC603E:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC603E:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC603E:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC603E:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC603E:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC603E:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC603E:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC603E:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC603E:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC603E:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC603E:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC603E:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC603E:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC603E:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC603E:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC603E:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC603E:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC603E:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC603E:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC603E:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC603E:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// PPC603E:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC603E:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC603E:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// PPC603E:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC603E:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC603E:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC603E:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC603E:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC603E:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC603E:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC603E:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC603E:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC603E:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC603E-NOT:#define __LP64__
end_comment

begin_comment
comment|// PPC603E:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC603E:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC603E:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC603E:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// PPC603E:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC603E:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC603E:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC603E:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC603E:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC603E:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC603E:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC603E:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC603E:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC603E:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC603E:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC603E:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC603E:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC603E:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC603E:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC603E:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC603E:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC603E:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC603E:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC603E:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC603E:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC603E:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC603E:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC603E:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// PPC603E:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC603E:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC603E:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// PPC603E:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC603E:#define __powerpc__ 1
end_comment

begin_comment
comment|// PPC603E:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr7 -fno-signed-char< /dev/null | FileCheck -check-prefix PPC64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPC64:#define _ARCH_PWR7 1
end_comment

begin_comment
comment|// PPC64:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC64:#define _LP64 1
end_comment

begin_comment
comment|// PPC64:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC64:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// PPC64:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC64:#define __CHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC64:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC64:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC64:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC64:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC64:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC64:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC64:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC64:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC64:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC64:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC64:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC64:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC64:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC64:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC64:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC64:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC64:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC64:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC64:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC64:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC64:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC64:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC64:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC64:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC64:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC64:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC64:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC64:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC64:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC64:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC64:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC64:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:#define __LP64__ 1
end_comment

begin_comment
comment|// PPC64:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC64:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC64:#define __PPC64__ 1
end_comment

begin_comment
comment|// PPC64:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC64:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC64:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC64:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC64:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC64:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC64:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC64:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// PPC64:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC64:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// PPC64:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC64:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC64:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// PPC64:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC64:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// PPC64:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64:#define __ppc64__ 1
end_comment

begin_comment
comment|// PPC64:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64le-none-none -target-cpu pwr7 -fno-signed-char< /dev/null | FileCheck -check-prefix PPC64LE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|// PPC64LE:#define _ARCH_PWR7 1
end_comment

begin_comment
comment|// PPC64LE:#define _CALL_ELF 2
end_comment

begin_comment
comment|// PPC64LE:#define _LITTLE_ENDIAN 1
end_comment

begin_comment
comment|// PPC64LE:#define _LP64 1
end_comment

begin_comment
comment|// PPC64LE:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// PPC64LE:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64LE:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __CHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC64LE:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC64LE:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC64LE:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC64LE:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64LE:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64LE:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64LE:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64LE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC64LE:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64LE:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64LE:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64LE:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64LE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC64LE:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64LE:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64LE:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64LE:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64LE:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64LE:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64LE:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64LE:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64LE:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC64LE:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64LE:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64LE:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64LE:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64LE:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64LE:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// PPC64LE:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64LE:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64LE:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64LE:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC64LE:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC64LE:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC64LE:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64LE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC64LE:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC64LE:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64LE:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64LE:#define __LP64__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __PPC64__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// PPC64LE:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC64LE:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC64LE:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC64LE:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64LE:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC64LE:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC64LE:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64LE:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64LE:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64LE:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64LE:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC64LE:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64LE:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64LE:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC64LE:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64LE:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC64LE:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64LE:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// PPC64LE:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64LE:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC64LE:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64LE:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// PPC64LE:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64LE:#define __ppc64__ 1
end_comment

begin_comment
comment|// PPC64LE:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu a2q -fno-signed-char< /dev/null | FileCheck -check-prefix PPCA2Q %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCA2Q:#define _ARCH_A2 1
end_comment

begin_comment
comment|// PPCA2Q:#define _ARCH_A2Q 1
end_comment

begin_comment
comment|// PPCA2Q:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCA2Q:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCA2Q:#define _ARCH_QP 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-bgq-linux -fno-signed-char< /dev/null | FileCheck -check-prefix PPCBGQ %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCBGQ:#define __THW_BLUEGENE__ 1
end_comment

begin_comment
comment|// PPCBGQ:#define __TOS_BGQ__ 1
end_comment

begin_comment
comment|// PPCBGQ:#define __bg__ 1
end_comment

begin_comment
comment|// PPCBGQ:#define __bgq__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu 630 -fno-signed-char< /dev/null | FileCheck -check-prefix PPC630 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC630:#define _ARCH_630 1
end_comment

begin_comment
comment|// PPC630:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC630:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPC630:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr3 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR3 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR3:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR3:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR3:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power3 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER3 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER3:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER3:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER3:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr4 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR4 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR4:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR4:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR4:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR4:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR4:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power4 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER4 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER4:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER4:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER4:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER4:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER4:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr5 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR5 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR5:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR5:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR5:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR5:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR5:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPWR5:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power5 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER5 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER5:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER5:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER5:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER5:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER5:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPOWER5:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr5x -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR5X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPWR5X:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power5x -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER5X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPOWER5X:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr6 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR6 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPWR6:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power6 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER6 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPOWER6:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr6x -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR6X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPCPWR6X:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power6x -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER6X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPCPOWER6X:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr7 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR7 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|// PPCPWR7:#define _ARCH_PWR7 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power7 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER7 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|// PPCPOWER7:#define _ARCH_PWR7 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu pwr8 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPWR8 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR7 1
end_comment

begin_comment
comment|// PPCPWR8:#define _ARCH_PWR8 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -target-cpu power8 -fno-signed-char< /dev/null | FileCheck -check-prefix PPCPOWER8 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PPCGR 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PPCSQ 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR4 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR5 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR5X 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR6 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR6X 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR7 1
end_comment

begin_comment
comment|// PPCPOWER8:#define _ARCH_PWR8 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-unknown-linux-gnu -fno-signed-char< /dev/null | FileCheck -check-prefix PPC64-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-LINUX:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define _ARCH_PPC64 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define _LP64 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// PPC64-LINUX:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __CHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC64-LINUX:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC64-LINUX:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC64-LINUX:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-LINUX:#define __LP64__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __PPC64__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC64-LINUX:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC64-LINUX:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// PPC64-LINUX:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64-LINUX:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64-LINUX:#define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC64-LINUX:#define __WINT_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64-LINUX:#define __powerpc64__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __powerpc__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __ppc64__ 1
end_comment

begin_comment
comment|// PPC64-LINUX:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc-none-none -fno-signed-char< /dev/null | FileCheck -check-prefix PPC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC-NOT:#define _LP64
end_comment

begin_comment
comment|// PPC:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// PPC:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC:#define __CHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// PPC:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// PPC:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC-NOT:#define __LP64__
end_comment

begin_comment
comment|// PPC:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// PPC:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// PPC:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// PPC:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc-unknown-linux-gnu -fno-signed-char< /dev/null | FileCheck -check-prefix PPC-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC-LINUX:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC-LINUX:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC-LINUX-NOT:#define _LP64
end_comment

begin_comment
comment|// PPC-LINUX:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// PPC-LINUX:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-LINUX:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC-LINUX:#define __CHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC-LINUX:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC-LINUX:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC-LINUX:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC-LINUX:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC-LINUX:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC-LINUX:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-LINUX:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC-LINUX-NOT:#define __LP64__
end_comment

begin_comment
comment|// PPC-LINUX:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// PPC-LINUX:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC-LINUX:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC-LINUX:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC-LINUX:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC-LINUX:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// PPC-LINUX:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-LINUX:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC-LINUX:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-LINUX:#define __WINT_UNSIGNED__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-LINUX:#define __powerpc__ 1
end_comment

begin_comment
comment|// PPC-LINUX:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc-apple-darwin8< /dev/null | FileCheck -check-prefix PPC-DARWIN %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC-DARWIN:#define _ARCH_PPC 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// PPC-DARWIN:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// PPC-DARWIN:#define __DECIMAL_DIG__ 33
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PPC-DARWIN:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// PPC-DARWIN:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_DENORM_MIN__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_DIG__ 31
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_EPSILON__ 4.94065645841246544176568792868221e-324L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MANT_DIG__ 106
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MIN_10_EXP__ (-291)
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MIN_EXP__ (-968)
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LDBL_MIN__ 2.00416836000897277799610805135016e-292L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __MACH__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __ORDER_BIG_ENDIAN__ 4321
end_comment

begin_comment
comment|// PPC-DARWIN:#define __ORDER_LITTLE_ENDIAN__ 1234
end_comment

begin_comment
comment|// PPC-DARWIN:#define __ORDER_PDP_ENDIAN__ 3412
end_comment

begin_comment
comment|// PPC-DARWIN:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __POWERPC__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __PPC__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZE_MAX__ 4294967295UL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __STDC_HOSTED__ 0
end_comment

begin_comment
comment|// PPC-DARWIN:#define __STDC_VERSION__ 199901L
end_comment

begin_comment
comment|// PPC-DARWIN:#define __STDC__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// PPC-DARWIN:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// PPC-DARWIN:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// PPC-DARWIN:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC-DARWIN:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// PPC-DARWIN:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// PPC-DARWIN:#define __powerpc__ 1
end_comment

begin_comment
comment|// PPC-DARWIN:#define __ppc__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=s390x-none-none -fno-signed-char< /dev/null | FileCheck -check-prefix S390X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// S390X:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// S390X:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// S390X:#define __CHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// S390X:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// S390X:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// S390X:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// S390X:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// S390X:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// S390X:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// S390X:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// S390X:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// S390X:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// S390X:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// S390X:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// S390X:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// S390X:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// S390X:#define __DECIMAL_DIG__ 36
end_comment

begin_comment
comment|// S390X:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// S390X:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// S390X:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// S390X:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// S390X:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// S390X:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// S390X:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// S390X:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// S390X:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// S390X:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// S390X:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// S390X:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// S390X:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// S390X:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// S390X:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// S390X:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// S390X:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// S390X:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// S390X:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// S390X:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// S390X:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// S390X:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// S390X:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// S390X:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// S390X:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// S390X:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// S390X:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// S390X:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// S390X:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// S390X:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// S390X:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// S390X:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// S390X:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// S390X:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// S390X:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// S390X:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// S390X:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// S390X:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// S390X:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// S390X:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// S390X:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// S390X:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// S390X:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// S390X:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// S390X:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// S390X:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// S390X:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// S390X:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// S390X:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __LDBL_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966L
end_comment

begin_comment
comment|// S390X:#define __LDBL_DIG__ 33
end_comment

begin_comment
comment|// S390X:#define __LDBL_EPSILON__ 1.92592994438723585305597794258492732e-34L
end_comment

begin_comment
comment|// S390X:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// S390X:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// S390X:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// S390X:#define __LDBL_MANT_DIG__ 113
end_comment

begin_comment
comment|// S390X:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// S390X:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// S390X:#define __LDBL_MAX__ 1.18973149535723176508575932662800702e+4932L
end_comment

begin_comment
comment|// S390X:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// S390X:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// S390X:#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
end_comment

begin_comment
comment|// S390X:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// S390X:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// S390X:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// S390X:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// S390X:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// S390X:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// S390X:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// S390X:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// S390X:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// S390X:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// S390X:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// S390X:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// S390X:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// S390X:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// S390X:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// S390X:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// S390X:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// S390X:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// S390X:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// S390X:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// S390X:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// S390X:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// S390X:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// S390X:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// S390X:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// S390X:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// S390X:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// S390X:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// S390X:#define __s390__ 1
end_comment

begin_comment
comment|// S390X:#define __s390x__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=sparc-none-none< /dev/null | FileCheck -check-prefix SPARC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC-NOT:#define _LP64
end_comment

begin_comment
comment|// SPARC:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// SPARC:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// SPARC:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// SPARC:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// SPARC:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// SPARC:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// SPARC:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// SPARC:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// SPARC:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// SPARC:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// SPARC:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// SPARC:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// SPARC:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// SPARC:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// SPARC:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// SPARC:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// SPARC:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// SPARC:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// SPARC:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// SPARC:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// SPARC:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// SPARC:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// SPARC:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// SPARC:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// SPARC:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// SPARC:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// SPARC:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// SPARC:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// SPARC:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// SPARC:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// SPARC:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// SPARC:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// SPARC:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// SPARC:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// SPARC:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// SPARC:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// SPARC:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// SPARC:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// SPARC:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// SPARC:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// SPARC:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// SPARC:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// SPARC:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// SPARC:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// SPARC:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// SPARC:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// SPARC:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// SPARC:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// SPARC:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// SPARC:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// SPARC:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// SPARC:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// SPARC:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// SPARC:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// SPARC:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// SPARC:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// SPARC:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// SPARC:#define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// SPARC:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// SPARC:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// SPARC:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// SPARC:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// SPARC:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
end_comment

begin_comment
comment|// SPARC:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// SPARC:#define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// SPARC:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// SPARC:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// SPARC:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// SPARC:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// SPARC-NOT:#define __LP64__
end_comment

begin_comment
comment|// SPARC:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// SPARC:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// SPARC:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// SPARC:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// SPARC:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// SPARC:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// SPARC:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// SPARC:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// SPARC:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// SPARC:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// SPARC:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// SPARC:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// SPARC:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// SPARC:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// SPARC:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// SPARC:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// SPARC:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// SPARC:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// SPARC:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// SPARC:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// SPARC:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// SPARC:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// SPARC:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// SPARC:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// SPARC:#define __VERSION__ "4.2.1 Compatible
end_comment

begin_comment
comment|// SPARC:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// SPARC:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// SPARC:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __sparc 1
end_comment

begin_comment
comment|// SPARC:#define __sparc__ 1
end_comment

begin_comment
comment|// SPARC:#define __sparcv8 1
end_comment

begin_comment
comment|// SPARC:#define sparc 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=tce-none-none< /dev/null | FileCheck -check-prefix TCE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE-NOT:#define _LP64
end_comment

begin_comment
comment|// TCE:#define __BIG_ENDIAN__ 1
end_comment

begin_comment
comment|// TCE:#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
end_comment

begin_comment
comment|// TCE:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// TCE:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// TCE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// TCE:#define __DBL_DENORM_MIN__ 1.40129846e-45
end_comment

begin_comment
comment|// TCE:#define __DBL_DIG__ 6
end_comment

begin_comment
comment|// TCE:#define __DBL_EPSILON__ 1.19209290e-7
end_comment

begin_comment
comment|// TCE:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// TCE:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// TCE:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// TCE:#define __DBL_MANT_DIG__ 24
end_comment

begin_comment
comment|// TCE:#define __DBL_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// TCE:#define __DBL_MAX_EXP__ 128
end_comment

begin_comment
comment|// TCE:#define __DBL_MAX__ 3.40282347e+38
end_comment

begin_comment
comment|// TCE:#define __DBL_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// TCE:#define __DBL_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// TCE:#define __DBL_MIN__ 1.17549435e-38
end_comment

begin_comment
comment|// TCE:#define __DECIMAL_DIG__ -1
end_comment

begin_comment
comment|// TCE:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// TCE:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// TCE:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// TCE:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// TCE:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// TCE:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// TCE:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// TCE:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// TCE:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// TCE:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// TCE:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// TCE:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// TCE:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// TCE:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// TCE:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// TCE:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// TCE:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// TCE:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// TCE:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// TCE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// TCE:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// TCE:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// TCE:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// TCE:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// TCE:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// TCE:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// TCE:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// TCE:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// TCE:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// TCE:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// TCE:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// TCE:#define __INTMAX_MAX__ 2147483647L
end_comment

begin_comment
comment|// TCE:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// TCE:#define __INTMAX_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// TCE:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// TCE:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// TCE:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// TCE:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// TCE:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// TCE:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// TCE:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// TCE:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// TCE:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// TCE:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// TCE:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// TCE:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// TCE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __LDBL_DENORM_MIN__ 1.40129846e-45L
end_comment

begin_comment
comment|// TCE:#define __LDBL_DIG__ 6
end_comment

begin_comment
comment|// TCE:#define __LDBL_EPSILON__ 1.19209290e-7L
end_comment

begin_comment
comment|// TCE:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// TCE:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// TCE:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// TCE:#define __LDBL_MANT_DIG__ 24
end_comment

begin_comment
comment|// TCE:#define __LDBL_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// TCE:#define __LDBL_MAX_EXP__ 128
end_comment

begin_comment
comment|// TCE:#define __LDBL_MAX__ 3.40282347e+38L
end_comment

begin_comment
comment|// TCE:#define __LDBL_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// TCE:#define __LDBL_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// TCE:#define __LDBL_MIN__ 1.17549435e-38L
end_comment

begin_comment
comment|// TCE:#define __LONG_LONG_MAX__ 2147483647LL
end_comment

begin_comment
comment|// TCE:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// TCE-NOT:#define __LP64__
end_comment

begin_comment
comment|// TCE:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// TCE:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// TCE:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_DOUBLE__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_LONG_DOUBLE__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_LONG_LONG__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// TCE:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// TCE:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// TCE:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __TCE_V1__ 1
end_comment

begin_comment
comment|// TCE:#define __TCE__ 1
end_comment

begin_comment
comment|// TCE:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// TCE:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// TCE:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// TCE:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// TCE:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// TCE:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// TCE:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// TCE:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// TCE:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// TCE:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// TCE:#define __UINTMAX_MAX__ 4294967295UL
end_comment

begin_comment
comment|// TCE:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// TCE:#define __UINTMAX_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// TCE:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// TCE:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// TCE:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// TCE:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// TCE:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// TCE:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// TCE:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// TCE:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// TCE:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// TCE:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// TCE:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// TCE:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// TCE:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// TCE:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// TCE:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __tce 1
end_comment

begin_comment
comment|// TCE:#define __tce__ 1
end_comment

begin_comment
comment|// TCE:#define tce 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-none-none< /dev/null | FileCheck -check-prefix X86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:#define _LP64 1
end_comment

begin_comment
comment|// X86_64-NOT:#define _LP32 1
end_comment

begin_comment
comment|// X86_64:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// X86_64:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// X86_64:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// X86_64:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// X86_64:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// X86_64:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// X86_64:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// X86_64:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// X86_64:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// X86_64:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// X86_64:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// X86_64:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// X86_64:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// X86_64:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// X86_64:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// X86_64:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// X86_64:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// X86_64:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// X86_64:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// X86_64:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// X86_64:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// X86_64:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// X86_64:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// X86_64:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// X86_64:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// X86_64:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// X86_64:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// X86_64:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// X86_64:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// X86_64:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// X86_64:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// X86_64:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// X86_64:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// X86_64:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// X86_64:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// X86_64:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// X86_64:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:#define __LP64__ 1
end_comment

begin_comment
comment|// X86_64-NOT:#define __ILP32__ 1
end_comment

begin_comment
comment|// X86_64:#define __MMX__ 1
end_comment

begin_comment
comment|// X86_64:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// X86_64:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// X86_64:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// X86_64:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// X86_64:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// X86_64:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// X86_64:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// X86_64:#define __SSE2__ 1
end_comment

begin_comment
comment|// X86_64:#define __SSE_MATH__ 1
end_comment

begin_comment
comment|// X86_64:#define __SSE__ 1
end_comment

begin_comment
comment|// X86_64:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// X86_64:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X86_64:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// X86_64:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X86_64:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// X86_64:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// X86_64:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// X86_64:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// X86_64:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// X86_64:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64:#define __amd64 1
end_comment

begin_comment
comment|// X86_64:#define __amd64__ 1
end_comment

begin_comment
comment|// X86_64:#define __x86_64 1
end_comment

begin_comment
comment|// X86_64:#define __x86_64__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-none-none-gnux32< /dev/null | FileCheck -check-prefix X32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X32:#define _ILP32 1
end_comment

begin_comment
comment|// X32-NOT:#define _LP64 1
end_comment

begin_comment
comment|// X32:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// X32:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X32:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X32:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// X32:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// X32:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// X32:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// X32:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X32:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X32:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X32:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// X32:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// X32:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// X32:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// X32:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// X32:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// X32:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// X32:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// X32:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// X32:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// X32:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// X32:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// X32:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X32:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X32:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X32:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// X32:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// X32:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// X32:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// X32:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// X32:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// X32:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// X32:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// X32:#define __ILP32__ 1
end_comment

begin_comment
comment|// X32-NOT:#define __LP64__ 1
end_comment

begin_comment
comment|// X32:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X32:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// X32:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// X32:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// X32:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// X32:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X32:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// X32:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// X32:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// X32:#define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// X32:#define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// X32:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X32:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// X32:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X32:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X32:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X32:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// X32:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// X32:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// X32:#define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// X32:#define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// X32:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X32:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// X32:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X32:#define __INTPTR_FMTd__ "d"
end_comment

begin_comment
comment|// X32:#define __INTPTR_FMTi__ "i"
end_comment

begin_comment
comment|// X32:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X32:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X32:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// X32:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// X32:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X32:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X32:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// X32:#define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// X32:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X32:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// X32:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X32:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X32:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// X32:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X32:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// X32:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// X32:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X32:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// X32:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X32:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// X32:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X32:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// X32:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// X32:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// X32:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X32:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X32:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X32:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// X32:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// X32:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// X32:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// X32:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// X32:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// X32:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// X32:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// X32:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// X32:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// X32:#define __MMX__ 1
end_comment

begin_comment
comment|// X32:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// X32:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// X32:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// X32:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// X32:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// X32:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// X32:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// X32:#define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// X32:#define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// X32:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// X32:#define __SIZE_MAX__ 4294967295U
end_comment

begin_comment
comment|// X32:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// X32:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// X32:#define __SSE2__ 1
end_comment

begin_comment
comment|// X32:#define __SSE_MATH__ 1
end_comment

begin_comment
comment|// X32:#define __SSE__ 1
end_comment

begin_comment
comment|// X32:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X32:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// X32:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X32:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// X32:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X32:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X32:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X32:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// X32:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// X32:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X32:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// X32:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X32:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// X32:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// X32:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// X32:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X32:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// X32:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// X32:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// X32:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X32:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X32:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X32:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// X32:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// X32:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// X32:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// X32:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X32:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// X32:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// X32:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// X32:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// X32:#define __amd64 1
end_comment

begin_comment
comment|// X32:#define __amd64__ 1
end_comment

begin_comment
comment|// X32:#define __x86_64 1
end_comment

begin_comment
comment|// X32:#define __x86_64__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-pc-linux-gnu< /dev/null | FileCheck -check-prefix X86_64-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64-LINUX:#define _LP64 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// X86_64-LINUX:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// X86_64-LINUX:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// X86_64-LINUX:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64-LINUX:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-LINUX:#define __LP64__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __MMX__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SSE2__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SSE_MATH__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __SSE__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// X86_64-LINUX:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64-LINUX:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// X86_64-LINUX:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-LINUX:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64-LINUX:#define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-LINUX:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64-LINUX:#define __amd64 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __amd64__ 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __x86_64 1
end_comment

begin_comment
comment|// X86_64-LINUX:#define __x86_64__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-unknown-freebsd9.1< /dev/null | FileCheck -check-prefix X86_64-FREEBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64-FREEBSD:#define __FreeBSD__ 9
end_comment

begin_comment
comment|// X86_64-FREEBSD:#define __FreeBSD_cc_version 900001
end_comment

begin_comment
comment|// X86_64-FREEBSD:#define __STDC_MB_MIGHT_NEQ_WC__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-netbsd< /dev/null | FileCheck -check-prefix X86_64-NETBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64-NETBSD:#define _LP64 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __DECIMAL_DIG__ 21
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTMAX_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTMAX_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTMAX_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTPTR_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST64_FMTd__ "ld"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST64_FMTi__ "li"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST64_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_DIG__ 18
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MANT_DIG__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MAX_10_EXP__ 4932
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MAX_EXP__ 16384
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MIN_10_EXP__ (-4931)
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MIN_EXP__ (-16381)
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __LP64__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __MMX__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __NO_MATH_INLINES 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __PTRDIFF_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __REGISTER_PREFIX__
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_LONG_DOUBLE__ 16
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_PTRDIFF_T__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_SIZE_T__ 8
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZE_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SSE2__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SSE_MATH__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __SSE__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT64_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTMAX_C_SUFFIX__ UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTMAX_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTPTR_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST64_TYPE__ long unsigned int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __USER_LABEL_PREFIX__
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __amd64 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __amd64__ 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __x86_64 1
end_comment

begin_comment
comment|// X86_64-NETBSD:#define __x86_64__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=sparc64-none-none< /dev/null | FileCheck -check-prefix SPARCV9 %s
end_comment

begin_comment
comment|// SPARCV9:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// SPARCV9:#define __INTMAX_C_SUFFIX__ L
end_comment

begin_comment
comment|// SPARCV9:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// SPARCV9:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// SPARCV9:#define __LONG_MAX__ 9223372036854775807L
end_comment

begin_comment
comment|// SPARCV9:#define __LP64__ 1
end_comment

begin_comment
comment|// SPARCV9:#define __SIZEOF_LONG__ 8
end_comment

begin_comment
comment|// SPARCV9:#define __SIZEOF_POINTER__ 8
end_comment

begin_comment
comment|// SPARCV9:#define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=sparc64-none-openbsd< /dev/null | FileCheck -check-prefix SPARC64-OBSD %s
end_comment

begin_comment
comment|// SPARC64-OBSD:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC64-OBSD:#define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// SPARC64-OBSD:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC64-OBSD:#define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// SPARC64-OBSD:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-pc-kfreebsd-gnu< /dev/null | FileCheck -check-prefix KFREEBSD-DEFINE %s
end_comment

begin_comment
comment|// KFREEBSD-DEFINE:#define __FreeBSD_kernel__ 1
end_comment

begin_comment
comment|// KFREEBSD-DEFINE:#define __GLIBC__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i686-pc-kfreebsd-gnu< /dev/null | FileCheck -check-prefix KFREEBSDI686-DEFINE %s
end_comment

begin_comment
comment|// KFREEBSDI686-DEFINE:#define __FreeBSD_kernel__ 1
end_comment

begin_comment
comment|// KFREEBSDI686-DEFINE:#define __GLIBC__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple i686-pc-linux-gnu -fobjc-runtime=gcc -E -dM< /dev/null | FileCheck -check-prefix GNUSOURCE %s
end_comment

begin_comment
comment|// GNUSOURCE:#define _GNU_SOURCE 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++98 -fno-rtti -E -dM< /dev/null | FileCheck -check-prefix NORTTI %s
end_comment

begin_comment
comment|// NORTTI: __GXX_ABI_VERSION
end_comment

begin_comment
comment|// NORTTI-NOT:#define __GXX_RTTI
end_comment

begin_comment
comment|// NORTTI: __STDC__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-linux-androideabi -E -dM< /dev/null | FileCheck -check-prefix ANDROID %s
end_comment

begin_comment
comment|// ANDROID: __ANDROID__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-unknown-freebsd< /dev/null | FileCheck -check-prefix PPC64-FREEBSD %s
end_comment

begin_comment
comment|// PPC64-FREEBSD-NOT: #define __LONG_DOUBLE_128__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=xcore-none-none< /dev/null | FileCheck -check-prefix XCORE %s
end_comment

begin_comment
comment|// XCORE:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// XCORE:#define __LITTLE_ENDIAN__ 1
end_comment

begin_comment
comment|// XCORE:#define __XS1B__ 1
end_comment

end_unit

