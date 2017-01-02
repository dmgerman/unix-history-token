begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv6t2-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2-eabi -### -mexecute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2-eabi -### -mexecute-only -mno-execute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-eabi -### -mexecute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-eabi -### -mexecute-only -mno-execute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-eabi -### -mexecute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-eabi -### -mexecute-only -mno-execute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-eabi -### -mexecute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-eabi -### -mexecute-only -mno-execute-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: not %clang -c -target thumbv6m-eabi -mexecute-only %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix CHECK-EXECUTE-ONLY-NOT-SUPPORTED %s
end_comment

begin_comment
comment|// RUN: not %clang -target armv8m.main-eabi -mexecute-only -mno-movt %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY-NO-MOVT
end_comment

begin_comment
comment|// RUN: not %clang -target armv8m.main-eabi -mexecute-only -mlong-calls %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY-LONG-CALLS
end_comment

begin_comment
comment|// -mpure-code flag for GCC compatibility
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2-eabi -### -mpure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2-eabi -### -mpure-code -mno-pure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-eabi -### -mpure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-eabi -### -mpure-code -mno-pure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-eabi -### -mpure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-eabi -### -mpure-code -mno-pure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-eabi -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-eabi -### -mpure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-eabi -### -mpure-code -mno-pure-code %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-NO-EXECUTE-ONLY
end_comment

begin_comment
comment|// RUN: not %clang -c -target thumbv6m-eabi -mpure-code %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix CHECK-EXECUTE-ONLY-NOT-SUPPORTED %s
end_comment

begin_comment
comment|// RUN: not %clang -target armv8m.main-eabi -mpure-code -mno-movt %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY-NO-MOVT
end_comment

begin_comment
comment|// RUN: not %clang -target armv8m.main-eabi -mpure-code -mlong-calls %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EXECUTE-ONLY-LONG-CALLS
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-EXECUTE-ONLY-NOT: "-backend-option" "-arm-execute-only"
end_comment

begin_comment
comment|// CHECK-EXECUTE-ONLY: "-backend-option" "-arm-execute-only"
end_comment

begin_comment
comment|// CHECK-EXECUTE-ONLY-NOT-SUPPORTED: error: execute only is not supported for the thumbv6m sub-architecture
end_comment

begin_comment
comment|// CHECK-EXECUTE-ONLY-NO-MOVT: error: option '-mexecute-only' cannot be specified with '-mno-movt'
end_comment

begin_comment
comment|// CHECK-EXECUTE-ONLY-LONG-CALLS: error: option '-mexecute-only' cannot be specified with '-mlong-calls'
end_comment

end_unit

