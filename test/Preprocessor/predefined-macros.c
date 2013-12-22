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
comment|// RUN:     -fmsc-version=1300 -o - | FileCheck %s --check-prefix=CHECK-MS
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
comment|// CHECK-MS-NOT: #define __GNUC__
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

