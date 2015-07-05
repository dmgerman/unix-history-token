begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -triple i386-apple-darwin10 -o - | FileCheck %s --check-prefix=CHECK-DARWIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -dM -triple x86_64-unknown-linux -o - | FileCheck %s --check-prefix=CHECK-NONDARWIN
end_comment

begin_comment
comment|// CHECK-DARWIN: #define __nonnull _Nonnull
end_comment

begin_comment
comment|// CHECK-DARWIN: #define __null_unspecified _Null_unspecified
end_comment

begin_comment
comment|// CHECK-DARWIN: #define __nullable _Nullable
end_comment

begin_comment
comment|// CHECK-NONDARWIN-NOT: __nonnull
end_comment

begin_comment
comment|// CHECK-NONDARWIN: #define __clang__
end_comment

begin_comment
comment|// CHECK-NONDARWIN-NOT: __nonnull
end_comment

end_unit

