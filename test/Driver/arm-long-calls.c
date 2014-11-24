begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-eabi -### -mlong-calls %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-LONG-CALLS
end_comment

begin_comment
comment|// RUN: %clang -target armv7-eabi -### -mlong-calls -mno-long-calls %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-LONG-CALLS
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-backend-option" "-arm-long-calls"
end_comment

begin_comment
comment|// CHECK-LONG-CALLS: "-backend-option" "-arm-long-calls"
end_comment

begin_comment
comment|// CHECK-NO-LONG-CALLS-NOT: "-backend-option" "-arm-long-calls"
end_comment

end_unit

