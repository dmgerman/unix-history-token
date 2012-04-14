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

end_unit

