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
comment|// RUN: %clang_cc1 -x c++ -std=c++0x -E -dM< /dev/null | FileCheck -check-prefix CXX0X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CXX0X:#define _GNU_SOURCE 1
end_comment

begin_comment
comment|// CXX0X:#define __DEPRECATED 1
end_comment

begin_comment
comment|// CXX0X:#define __GNUG__
end_comment

begin_comment
comment|// CXX0X:#define __GXX_EXPERIMENTAL_CXX0X__ 1
end_comment

begin_comment
comment|// CXX0X:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// CXX0X:#define __cplusplus 199711L
end_comment

begin_comment
comment|// CXX0X:#define __private_extern__ extern
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
comment|// CXX98:#define _GNU_SOURCE 1
end_comment

begin_comment
comment|// CXX98:#define __DEPRECATED 1
end_comment

begin_comment
comment|// CXX98:#define __GNUG__
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
comment|// RUN: %clang_cc1 -x c++ -std=gnu++98 -E -dM< /dev/null | FileCheck -check-prefix GXX98 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GXX98:#define _GNU_SOURCE 1
end_comment

begin_comment
comment|// GXX98:#define __DEPRECATED 1
end_comment

begin_comment
comment|// GXX98:#define __GNUG__
end_comment

begin_comment
comment|// GXX98:#define __GXX_WEAK__ 1
end_comment

begin_comment
comment|// GXX98:#define __cplusplus 1
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
comment|// RUN: %clang_cc1 -fms-extensions -E -dM< /dev/null | FileCheck -check-prefix MSEXT %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSEXT-NOT:#define __STDC__
end_comment

begin_comment
comment|// MSEXT:#define __int16 __INT16_TYPE__
end_comment

begin_comment
comment|// MSEXT:#define __int32 __INT32_TYPE__
end_comment

begin_comment
comment|// MSEXT:#define __int64 __INT64_TYPE__
end_comment

begin_comment
comment|// MSEXT:#define __int8 __INT8_TYPE__
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
comment|// RUN: %clang_cc1 -x objective-c -fobjc-nonfragile-abi -E -dM< /dev/null | FileCheck -check-prefix NONFRAGILE %s
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
comment|// RUN: %clang_cc1 -O1 -E -dM< /dev/null | FileCheck -check-prefix O1 %s
end_comment

begin_comment
comment|//
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
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=arm-none-none< /dev/null | FileCheck -check-prefix ARM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:#define __APCS_32__ 1
end_comment

begin_comment
comment|// ARM:#define __ARMEL__ 1
end_comment

begin_comment
comment|// ARM:#define __ARM_ARCH_6J__ 1
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
comment|// ARM:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// ARM:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// ARM:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// ARM:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// ARM:#define __INT8_TYPE__ char
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
comment|// ARM:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// ARM:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// ARM:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// ARM:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// ARM:#define __LDBL_EPSILON__ 2.2204460492503131e-16
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
comment|// ARM:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// ARM:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// ARM:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// ARM:#define __LDBL_MIN__ 2.2250738585072014e-308
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
comment|// ARM:#define __NO_INLINE__ 1
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
comment|// ARM:#define __SIG_ATOMIC_WIDTH__ 32
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
comment|// ARM:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// ARM:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// ARM:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// ARM:#define __WCHAR_TYPE__ int
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
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=bfin-none-none< /dev/null | FileCheck -check-prefix BFIN %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:#define BFIN 1
end_comment

begin_comment
comment|// BFIN:#define __ADSPBLACKFIN__ 1
end_comment

begin_comment
comment|// BFIN:#define __ADSPLPBLACKFIN__ 1
end_comment

begin_comment
comment|// BFIN:#define __BFIN 1
end_comment

begin_comment
comment|// BFIN:#define __BFIN__ 1
end_comment

begin_comment
comment|// BFIN:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// BFIN:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// BFIN:#define __DBL_DIG__ 15
end_comment

begin_comment
comment|// BFIN:#define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// BFIN:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// BFIN:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// BFIN:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// BFIN:#define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// BFIN:#define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// BFIN:#define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// BFIN:#define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// BFIN:#define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// BFIN:#define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// BFIN:#define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// BFIN:#define __DECIMAL_DIG__ 17
end_comment

begin_comment
comment|// BFIN:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// BFIN:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// BFIN:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// BFIN:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// BFIN:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// BFIN:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// BFIN:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// BFIN:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// BFIN:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// BFIN:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// BFIN:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// BFIN:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// BFIN:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// BFIN:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// BFIN:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// BFIN:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// BFIN:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// BFIN:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// BFIN:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// BFIN:#define __INT8_TYPE__ char
end_comment

begin_comment
comment|// BFIN:#define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// BFIN:#define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// BFIN:#define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// BFIN:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// BFIN:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// BFIN:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// BFIN:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// BFIN:#define __LDBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// BFIN:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// BFIN:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// BFIN:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// BFIN:#define __LDBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// BFIN:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// BFIN:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// BFIN:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// BFIN:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// BFIN:#define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// BFIN:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// BFIN:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// BFIN:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// BFIN:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// BFIN:#define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// BFIN:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// BFIN:#define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// BFIN:#define __WINT_WIDTH__ 32
end_comment

begin_comment
comment|// BFIN:#define __bfin 1
end_comment

begin_comment
comment|// BFIN:#define __bfin__ 1
end_comment

begin_comment
comment|// BFIN:#define bfin 1
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
comment|// I386:#define __FLT_EVAL_METHOD__ 0
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
comment|// I386:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// I386:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// I386:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// I386:#define __INT8_TYPE__ char
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
comment|// I386:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// I386:#define __INTPTR_WIDTH__ 32
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
comment|// I386:#define __NO_INLINE__ 1
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
comment|// I386:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// I386:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// I386:#define __UINTMAX_TYPE__ long long unsigned int
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
comment|// I386:#define __nocona 1
end_comment

begin_comment
comment|// I386:#define __nocona__ 1
end_comment

begin_comment
comment|// I386:#define __tune_nocona__ 1
end_comment

begin_comment
comment|// I386:#define i386 1
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
comment|// MSP430:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// MSP430:#define __INT32_C_SUFFIX__ L
end_comment

begin_comment
comment|// MSP430:#define __INT32_TYPE__ long int
end_comment

begin_comment
comment|// MSP430:#define __INT8_TYPE__ char
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_MAX__ 2147483647L
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// MSP430:#define __INTMAX_WIDTH__ 32
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_TYPE__ short
end_comment

begin_comment
comment|// MSP430:#define __INTPTR_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __INT_MAX__ 32767
end_comment

begin_comment
comment|// MSP430:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// MSP430:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// MSP430:#define __LDBL_EPSILON__ 2.2204460492503131e-16
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
comment|// MSP430:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// MSP430:#define __LDBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// MSP430:#define __LONG_LONG_MAX__ 2147483647LL
end_comment

begin_comment
comment|// MSP430:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// MSP430:#define __MSP430__ 1
end_comment

begin_comment
comment|// MSP430:#define __NO_INLINE__ 1
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
comment|// MSP430:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// MSP430:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// MSP430:#define __SIZE_WIDTH__ 16
end_comment

begin_comment
comment|// MSP430:#define __UINTMAX_TYPE__ long unsigned int
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
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=pic16-none-none< /dev/null | FileCheck -check-prefix PIC16 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:#define _CONFIG(conf) asm("CONFIG "#conf)
end_comment

begin_comment
comment|// PIC16:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// PIC16:#define __DBL_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PIC16:#define __DBL_DIG__ 6
end_comment

begin_comment
comment|// PIC16:#define __DBL_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PIC16:#define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PIC16:#define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PIC16:#define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PIC16:#define __DBL_MANT_DIG__ 24
end_comment

begin_comment
comment|// PIC16:#define __DBL_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PIC16:#define __DBL_MAX_EXP__ 128
end_comment

begin_comment
comment|// PIC16:#define __DBL_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PIC16:#define __DBL_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PIC16:#define __DBL_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PIC16:#define __DBL_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PIC16:#define __DECIMAL_DIG__ -1
end_comment

begin_comment
comment|// PIC16:#define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PIC16:#define __FLT_DIG__ 6
end_comment

begin_comment
comment|// PIC16:#define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PIC16:#define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// PIC16:#define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PIC16:#define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PIC16:#define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PIC16:#define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// PIC16:#define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PIC16:#define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// PIC16:#define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PIC16:#define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PIC16:#define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PIC16:#define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PIC16:#define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// PIC16:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PIC16:#define __INT32_C_SUFFIX__ L
end_comment

begin_comment
comment|// PIC16:#define __INT32_TYPE__ long int
end_comment

begin_comment
comment|// PIC16:#define __INT8_TYPE__ char
end_comment

begin_comment
comment|// PIC16:#define __INTMAX_MAX__ 2147483647L
end_comment

begin_comment
comment|// PIC16:#define __INTMAX_TYPE__ long int
end_comment

begin_comment
comment|// PIC16:#define __INTMAX_WIDTH__ 32
end_comment

begin_comment
comment|// PIC16:#define __INTPTR_TYPE__ short
end_comment

begin_comment
comment|// PIC16:#define __INTPTR_WIDTH__ 16
end_comment

begin_comment
comment|// PIC16:#define __INT_MAX__ 32767
end_comment

begin_comment
comment|// PIC16:#define __LDBL_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// PIC16:#define __LDBL_DIG__ 6
end_comment

begin_comment
comment|// PIC16:#define __LDBL_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// PIC16:#define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// PIC16:#define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// PIC16:#define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MANT_DIG__ 24
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MAX_EXP__ 128
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// PIC16:#define __LDBL_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// PIC16:#define __LONG_LONG_MAX__ 2147483647LL
end_comment

begin_comment
comment|// PIC16:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// PIC16:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// PIC16:#define __POINTER_WIDTH__ 16
end_comment

begin_comment
comment|// PIC16:#define __PTRDIFF_TYPE__ int
end_comment

begin_comment
comment|// PIC16:#define __PTRDIFF_WIDTH__ 16
end_comment

begin_comment
comment|// PIC16:#define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// PIC16:#define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// PIC16:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PIC16:#define __SIZE_TYPE__ unsigned int
end_comment

begin_comment
comment|// PIC16:#define __SIZE_WIDTH__ 16
end_comment

begin_comment
comment|// PIC16:#define __UINTMAX_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PIC16:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// PIC16:#define __WCHAR_MAX__ 32767
end_comment

begin_comment
comment|// PIC16:#define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// PIC16:#define __WCHAR_WIDTH__ 16
end_comment

begin_comment
comment|// PIC16:#define __WINT_TYPE__ int
end_comment

begin_comment
comment|// PIC16:#define __WINT_WIDTH__ 16
end_comment

begin_comment
comment|// PIC16:#define __clang__ 1
end_comment

begin_comment
comment|// PIC16:#define __llvm__ 1
end_comment

begin_comment
comment|// PIC16:#define __pic16 1
end_comment

begin_comment
comment|// PIC16:#define _address(Addr) __attribute__((section("Address="#Addr)))
end_comment

begin_comment
comment|// PIC16:#define _interrupt __attribute__((section("interrupt=0x4"))) __attribute__((used))
end_comment

begin_comment
comment|// PIC16:#define _section(SectName) __attribute__((section(SectName)))
end_comment

begin_comment
comment|// PIC16:#define ram __attribute__((address_space(0)))
end_comment

begin_comment
comment|// PIC16:#define rom __attribute__((address_space(1)))
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=powerpc64-none-none -fno-signed-char< /dev/null | FileCheck -check-prefix PPC64 %s
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
comment|// PPC64:#define _BIG_ENDIAN 1
end_comment

begin_comment
comment|// PPC64:#define _LP64 1
end_comment

begin_comment
comment|// PPC64:#define __BIG_ENDIAN__ 1
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
comment|// PPC64:#define __DECIMAL_DIG__ 17
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
comment|// PPC64:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC64:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC64:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// PPC64:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INT8_TYPE__ char
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
comment|// PPC64:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC64:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC64:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC64:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// PPC64:#define __LDBL_EPSILON__ 2.2204460492503131e-16
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
comment|// PPC64:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC64:#define __LDBL_MIN__ 2.2250738585072014e-308
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
comment|// PPC64:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// PPC64:#define __POINTER_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __POWERPC__ 1
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
comment|// PPC64:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC64:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC64:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// PPC64:#define __UINTMAX_TYPE__ long unsigned int
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
comment|// PPC:#define __BIG_ENDIAN__ 1
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
comment|// PPC:#define __DECIMAL_DIG__ 17
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
comment|// PPC:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// PPC:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// PPC:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// PPC:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// PPC:#define __INT8_TYPE__ char
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
comment|// PPC:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// PPC:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// PPC:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// PPC:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// PPC:#define __LDBL_EPSILON__ 2.2204460492503131e-16
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
comment|// PPC:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// PPC:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// PPC:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// PPC:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// PPC:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// PPC:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// PPC:#define __LDBL_MIN__ 2.2250738585072014e-308
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
comment|// PPC:#define __NATURAL_ALIGNMENT__ 1
end_comment

begin_comment
comment|// PPC:#define __NO_INLINE__ 1
end_comment

begin_comment
comment|// PPC:#define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __POWERPC__ 1
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
comment|// PPC:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// PPC:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// PPC:#define __UINTMAX_TYPE__ long long unsigned int
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
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=s390x-none-none -fno-signed-char< /dev/null | FileCheck -check-prefix S390X %s
end_comment

begin_comment
comment|//
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
comment|// S390X:#define __DECIMAL_DIG__ 17
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
comment|// S390X:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// S390X:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// S390X:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// S390X:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// S390X:#define __INT8_TYPE__ char
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
comment|// S390X:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// S390X:#define __INTPTR_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// S390X:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// S390X:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// S390X:#define __LDBL_EPSILON__ 2.2204460492503131e-16
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
comment|// S390X:#define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// S390X:#define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// S390X:#define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// S390X:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// S390X:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// S390X:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// S390X:#define __LDBL_MIN__ 2.2250738585072014e-308
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
comment|// S390X:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// S390X:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// S390X:#define __SIZE_WIDTH__ 64
end_comment

begin_comment
comment|// S390X:#define __UINTMAX_TYPE__ long long unsigned int
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
comment|// SPARC:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// SPARC:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// SPARC:#define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// SPARC:#define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// SPARC:#define __INT8_TYPE__ char
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
comment|// SPARC:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// SPARC:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// SPARC:#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// SPARC:#define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// SPARC:#define __LDBL_EPSILON__ 2.2204460492503131e-16
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
comment|// SPARC:#define __LDBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// SPARC:#define __LDBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// SPARC:#define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// SPARC:#define __NO_INLINE__ 1
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
comment|// SPARC:#define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// SPARC:#define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// SPARC:#define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// SPARC:#define __VERSION__ "4.2.1 Compatible Clang Compiler"
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
comment|// TCE:#define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// TCE:#define __DBL_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// TCE:#define __DBL_DIG__ 6
end_comment

begin_comment
comment|// TCE:#define __DBL_EPSILON__ 1.19209290e-7F
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
comment|// TCE:#define __DBL_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// TCE:#define __DBL_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// TCE:#define __DBL_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// TCE:#define __DBL_MIN__ 1.17549435e-38F
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
comment|// TCE:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// TCE:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __INT8_TYPE__ char
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
comment|// TCE:#define __INTPTR_TYPE__ int
end_comment

begin_comment
comment|// TCE:#define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// TCE:#define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// TCE:#define __LDBL_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// TCE:#define __LDBL_DIG__ 6
end_comment

begin_comment
comment|// TCE:#define __LDBL_EPSILON__ 1.19209290e-7F
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
comment|// TCE:#define __LDBL_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// TCE:#define __LDBL_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// TCE:#define __LDBL_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// TCE:#define __LDBL_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// TCE:#define __LONG_LONG_MAX__ 2147483647LL
end_comment

begin_comment
comment|// TCE:#define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// TCE:#define __NO_INLINE__ 1
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
comment|// TCE:#define __SIG_ATOMIC_WIDTH__ 32
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
comment|// TCE:#define __UINTMAX_TYPE__ long unsigned int
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
comment|// X86_64:#define __INT16_TYPE__ short
end_comment

begin_comment
comment|// X86_64:#define __INT32_TYPE__ int
end_comment

begin_comment
comment|// X86_64:#define __INT64_C_SUFFIX__ L
end_comment

begin_comment
comment|// X86_64:#define __INT64_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INT8_TYPE__ char
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
comment|// X86_64:#define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// X86_64:#define __INTPTR_WIDTH__ 64
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
comment|// X86_64:#define __MMX__ 1
end_comment

begin_comment
comment|// X86_64:#define __NO_INLINE__ 1
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
comment|// X86_64:#define __SIG_ATOMIC_WIDTH__ 32
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
comment|// X86_64:#define __UINTMAX_TYPE__ long unsigned int
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
comment|// X86_64:#define __nocona 1
end_comment

begin_comment
comment|// X86_64:#define __nocona__ 1
end_comment

begin_comment
comment|// X86_64:#define __tune_nocona__ 1
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

end_unit

