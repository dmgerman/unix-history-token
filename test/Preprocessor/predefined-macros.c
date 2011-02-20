begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test verifies that the correct macros are predefined. It currently
end_comment

begin_comment
comment|// only checks for Microsoft macros.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -triple i686-pc-win32 -fms-extensions -fmsc-version=1300 -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: #define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// CHECK: #define _MSC_EXTENSIONS 1
end_comment

begin_comment
comment|// CHECK: #define _MSC_VER 1300
end_comment

begin_comment
comment|// CHECK: #define _M_IX86 600
end_comment

begin_comment
comment|// CHECK: #define _M_IX86_FP
end_comment

begin_comment
comment|// CHECK: #define _WIN32 1
end_comment

end_unit

