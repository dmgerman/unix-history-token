begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -dM -triple armv7-windows -E %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -dM -fno-signed-char -triple armv7-windows -E %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: #define __WCHAR_TYPE__ unsigned short
end_comment

end_unit

