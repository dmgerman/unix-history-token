begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -arch armv6m -dM -E %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -arch armv7m -dM -E %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -arch armv7em -dM -E %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7m-apple-unknown-macho -dM -E %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
end_comment

begin_comment
comment|// CHECK-NOT: __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
end_comment

end_unit

