begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -mkernel -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-KERNEL
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-gnueabi -mno-movt -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-MOVT
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+no-movt"
end_comment

begin_comment
comment|// CHECK-KERNEL: "-target-feature" "+no-movt"
end_comment

begin_comment
comment|// CHECK-NO-MOVT: "-target-feature" "+no-movt"
end_comment

end_unit

