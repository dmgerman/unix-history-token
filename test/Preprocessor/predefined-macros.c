begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test verifies that the correct macros are predefined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -triple i686-pc-win32 -fms-extensions -fms-compatibility \
end_comment

begin_comment
comment|// RUN:     -fms-compatibility-version=13.00 -o - | FileCheck %s --check-prefix=CHECK-MS
end_comment

begin_comment
comment|// CHECK-MS: #define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// CHECK-MS: #define _MSC_EXTENSIONS 1
end_comment

begin_comment
comment|// CHECK-MS: #define _MSC_VER 1300
end_comment

begin_comment
comment|// CHECK-MS: #define _M_IX86 600
end_comment

begin_comment
comment|// CHECK-MS: #define _M_IX86_FP
end_comment

begin_comment
comment|// CHECK-MS: #define _WIN32 1
end_comment

begin_comment
comment|// CHECK-MS-NOT: #define __STRICT_ANSI__
end_comment

begin_comment
comment|// CHECK-MS-NOT: GCC
end_comment

begin_comment
comment|// CHECK-MS-NOT: GNU
end_comment

begin_comment
comment|// CHECK-MS-NOT: GXX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -triple x86_64-pc-win32 -fms-extensions -fms-compatibility \
end_comment

begin_comment
comment|// RUN:     -fms-compatibility-version=13.00 -o - | FileCheck %s --check-prefix=CHECK-MS64
end_comment

begin_comment
comment|// CHECK-MS64: #define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// CHECK-MS64: #define _MSC_EXTENSIONS 1
end_comment

begin_comment
comment|// CHECK-MS64: #define _MSC_VER 1300
end_comment

begin_comment
comment|// CHECK-MS64: #define _M_AMD64 1
end_comment

begin_comment
comment|// CHECK-MS64: #define _M_X64 1
end_comment

begin_comment
comment|// CHECK-MS64: #define _WIN64 1
end_comment

begin_comment
comment|// CHECK-MS64-NOT: #define __STRICT_ANSI__
end_comment

begin_comment
comment|// CHECK-MS64-NOT: GCC
end_comment

begin_comment
comment|// CHECK-MS64-NOT: GNU
end_comment

begin_comment
comment|// CHECK-MS64-NOT: GXX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -triple i686-pc-win32 -fms-compatibility \
end_comment

begin_comment
comment|// RUN:     -o - | FileCheck %s --check-prefix=CHECK-MS-STDINT
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT8_MAX__ 127
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INTPTR_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// CHECK-MS-STDINT-NOT:#define __UINT16_C_SUFFIX__ U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT-NOT:#define __UINT8_C_SUFFIX__ U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINTPTR_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINTPTR_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// CHECK-MS-STDINT:#define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -ffast-math -o - \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-FAST-MATH
end_comment

begin_comment
comment|// CHECK-FAST-MATH: #define __FAST_MATH__
end_comment

begin_comment
comment|// CHECK-FAST-MATH: #define __FINITE_MATH_ONLY__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -ffinite-math-only -o - \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-FINITE-MATH-ONLY
end_comment

begin_comment
comment|// CHECK-FINITE-MATH-ONLY: #define __FINITE_MATH_ONLY__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -E -dM -fno-finite-math-only -o - \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-FINITE-MATH-ONLY
end_comment

begin_comment
comment|// CHECK-NO-FINITE-MATH-ONLY: #define __FINITE_MATH_ONLY__ 0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-FINITE-MATH-FLAG-UNDEFINED
end_comment

begin_comment
comment|// CHECK-FINITE-MATH-FLAG-UNDEFINED: #define __FINITE_MATH_ONLY__ 0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple i686 -target-cpu i386 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-SYNC_CAS_I386
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I386-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple i686 -target-cpu i486 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-SYNC_CAS_I486
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple i686 -target-cpu i586 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-SYNC_CAS_I586
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple armv6 -target-cpu arm1136j-s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-SYNC_CAS_ARM
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple armv7 -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-SYNC_CAS_ARMv7
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple armv6 -target-cpu cortex-m0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-SYNC_CAS_ARMv6
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv6-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP
end_comment

end_unit

