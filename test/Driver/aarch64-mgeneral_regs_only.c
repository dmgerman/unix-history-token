begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the -mgeneral-regs-only option
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mgeneral-regs-only %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FP %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-linux-eabi -mgeneral-regs-only %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FP %s
end_comment

begin_comment
comment|// CHECK-NO-FP: "-target-feature" "-fp-armv8"
end_comment

begin_comment
comment|// CHECK-NO-FP: "-target-feature" "-crypto"
end_comment

begin_comment
comment|// CHECK-NO-FP: "-target-feature" "-neon"
end_comment

end_unit

