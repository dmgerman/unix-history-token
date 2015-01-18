begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -dM -E %s -triple x86_64-none-linux-gnu | FileCheck %s --check-prefix=CHECK-X86
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -dM -E %s -triple armv7-none-eabi | FileCheck %s --check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -dM -E %s -triple thumbv7-none-eabi | FileCheck %s --check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// CHECK-X86-NOT: #define __WCHAR_UNSIGNED__
end_comment

begin_comment
comment|// CHECK-X86: #define __WINT_UNSIGNED__ 1
end_comment

begin_comment
comment|// CHECK-ARM: #define __WCHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// CHECK-ARM-NOT: #define __WINT_UNSIGNED__ 1
end_comment

end_unit

