begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test verifies that the correct macros are predefined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -x c++ -E -dM -triple i686-pc-win32 -fms-extensions -fms-compatibility \
end_comment

begin_comment
comment|// RUN:     -fms-compatibility-version=19.00 -std=c++1z -o - | FileCheck -match-full-lines %s --check-prefix=CHECK-MS
end_comment

begin_comment
comment|// CHECK-MS: #define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// CHECK-MS: #define _MSC_EXTENSIONS 1
end_comment

begin_comment
comment|// CHECK-MS: #define _MSC_VER 1900
end_comment

begin_comment
comment|// CHECK-MS: #define _MSVC_LANG 201403L
end_comment

begin_comment
comment|// CHECK-MS: #define _M_IX86 600
end_comment

begin_comment
comment|// CHECK-MS: #define _M_IX86_FP 0
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
comment|// RUN: %clang_cc1 %s -x c++ -E -dM -triple x86_64-pc-win32 -fms-extensions -fms-compatibility \
end_comment

begin_comment
comment|// RUN:     -fms-compatibility-version=19.00 -std=c++14 -o - | FileCheck -match-full-lines %s --check-prefix=CHECK-MS64
end_comment

begin_comment
comment|// CHECK-MS64: #define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// CHECK-MS64: #define _MSC_EXTENSIONS 1
end_comment

begin_comment
comment|// CHECK-MS64: #define _MSC_VER 1900
end_comment

begin_comment
comment|// CHECK-MS64: #define _MSVC_LANG 201402L
end_comment

begin_comment
comment|// CHECK-MS64: #define _M_AMD64 100
end_comment

begin_comment
comment|// CHECK-MS64: #define _M_X64 100
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
comment|// RUN:     -o - | FileCheck -match-full-lines %s --check-prefix=CHECK-MS-STDINT
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-FAST-MATH
end_comment

begin_comment
comment|// CHECK-FAST-MATH: #define __FAST_MATH__ 1
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-FINITE-MATH-ONLY
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-NO-FINITE-MATH-ONLY
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-FINITE-MATH-FLAG-UNDEFINED
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_I386
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_I486
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I486: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
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
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_I586
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_I586: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple armv6 -target-cpu arm1136j-s \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_ARM
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARM: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple armv7 -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_ARMv7
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv7: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple armv6 -target-cpu cortex-m0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_ARMv6
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_ARMv6-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple mips -target-cpu mips2 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_MIPS \
end_comment

begin_comment
comment|// RUN:         --check-prefix=CHECK-SYNC_CAS_MIPS32
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -triple mips64 -target-cpu mips3 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-SYNC_CAS_MIPS \
end_comment

begin_comment
comment|// RUN:         --check-prefix=CHECK-SYNC_CAS_MIPS64
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_MIPS: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_MIPS: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_MIPS: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_MIPS32-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
end_comment

begin_comment
comment|// CHECK-SYNC_CAS_MIPS64: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -x cl \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-CL10
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -x cl -cl-std=CL1.1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-CL11
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -x cl -cl-std=CL1.2 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-CL12
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -x cl -cl-std=CL2.0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-CL20
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -o - -x cl -cl-fast-relaxed-math \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-FRM
end_comment

begin_comment
comment|// CHECK-CL10: #define CL_VERSION_1_0 100
end_comment

begin_comment
comment|// CHECK-CL10: #define CL_VERSION_1_1 110
end_comment

begin_comment
comment|// CHECK-CL10: #define CL_VERSION_1_2 120
end_comment

begin_comment
comment|// CHECK-CL10: #define CL_VERSION_2_0 200
end_comment

begin_comment
comment|// CHECK-CL10: #define __OPENCL_C_VERSION__ 100
end_comment

begin_comment
comment|// CHECK-CL10-NOT: #define __FAST_RELAXED_MATH__ 1
end_comment

begin_comment
comment|// CHECK-CL11: #define CL_VERSION_1_0 100
end_comment

begin_comment
comment|// CHECK-CL11: #define CL_VERSION_1_1 110
end_comment

begin_comment
comment|// CHECK-CL11: #define CL_VERSION_1_2 120
end_comment

begin_comment
comment|// CHECK-CL11: #define CL_VERSION_2_0 200
end_comment

begin_comment
comment|// CHECK-CL11: #define __OPENCL_C_VERSION__ 110
end_comment

begin_comment
comment|// CHECK-CL11-NOT: #define __FAST_RELAXED_MATH__ 1
end_comment

begin_comment
comment|// CHECK-CL12: #define CL_VERSION_1_0 100
end_comment

begin_comment
comment|// CHECK-CL12: #define CL_VERSION_1_1 110
end_comment

begin_comment
comment|// CHECK-CL12: #define CL_VERSION_1_2 120
end_comment

begin_comment
comment|// CHECK-CL12: #define CL_VERSION_2_0 200
end_comment

begin_comment
comment|// CHECK-CL12: #define __OPENCL_C_VERSION__ 120
end_comment

begin_comment
comment|// CHECK-CL12-NOT: #define __FAST_RELAXED_MATH__ 1
end_comment

begin_comment
comment|// CHECK-CL20: #define CL_VERSION_1_0 100
end_comment

begin_comment
comment|// CHECK-CL20: #define CL_VERSION_1_1 110
end_comment

begin_comment
comment|// CHECK-CL20: #define CL_VERSION_1_2 120
end_comment

begin_comment
comment|// CHECK-CL20: #define CL_VERSION_2_0 200
end_comment

begin_comment
comment|// CHECK-CL20: #define __OPENCL_C_VERSION__ 200
end_comment

begin_comment
comment|// CHECK-CL20-NOT: #define __FAST_RELAXED_MATH__ 1
end_comment

begin_comment
comment|// CHECK-FRM: #define __FAST_RELAXED_MATH__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-windows %s -E -dM -o - -x cl \
end_comment

begin_comment
comment|// RUN:   | FileCheck -match-full-lines %s --check-prefix=CHECK-ARM64-WIN
end_comment

begin_comment
comment|// CHECK-ARM64-WIN: #define _M_ARM64 1
end_comment

begin_comment
comment|// CHECK-ARM64-WIN: #define _WIN32 1
end_comment

begin_comment
comment|// CHECK-ARM64-WIN: #define _WIN64 1
end_comment

end_unit

