begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple thumbv7m-apple-unknown-macho -target-cpu cortex-m3 %s | FileCheck %s -check-prefix CHECK-7M
end_comment

begin_comment
comment|// CHECK-7M: #define __APPLE_CC__
end_comment

begin_comment
comment|// CHECK-7M: #define __APPLE__
end_comment

begin_comment
comment|// CHECK-7M: #define __ARM_ARCH_7M__
end_comment

begin_comment
comment|// CHECK-7M-NOT: #define __MACH__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple thumbv7em-apple-unknown-macho -target-cpu cortex-m4 %s | FileCheck %s -check-prefix CHECK-7EM
end_comment

begin_comment
comment|// CHECK-7EM: #define __APPLE_CC__
end_comment

begin_comment
comment|// CHECK-7EM: #define __APPLE__
end_comment

begin_comment
comment|// CHECK-7EM: #define __ARM_ARCH_7EM__
end_comment

begin_comment
comment|// CHECK-7EM-NOT: #define __MACH__
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple thumbv6m-apple-unknown-macho -target-cpu cortex-m0 %s | FileCheck %s -check-prefix CHECK-6M
end_comment

begin_comment
comment|// CHECK-6M: #define __APPLE_CC__
end_comment

begin_comment
comment|// CHECK-6M: #define __APPLE__
end_comment

begin_comment
comment|// CHECK-6M: #define __ARM_ARCH_6M__
end_comment

begin_comment
comment|// CHECK-6M-NOT: #define __MACH__
end_comment

end_unit

