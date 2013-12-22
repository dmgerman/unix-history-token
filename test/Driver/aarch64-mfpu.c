begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that different values of -mfpu pick correct AArch64 FPU target-feature(s).
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mfpu=neon %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NEON %s
end_comment

begin_comment
comment|// CHECK-NEON: "-target-feature" "+neon"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mfpu=fp-armv8 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FP-ARMV8 %s
end_comment

begin_comment
comment|// CHECK-FP-ARMV8: "-target-feature" "+fp-armv8"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mfpu=neon-fp-armv8 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NEON-FP-ARMV8 %s
end_comment

begin_comment
comment|// CHECK-NEON-FP-ARMV8: "-target-feature" "+fp-armv8"
end_comment

begin_comment
comment|// CHECK-NEON-FP-ARMV8: "-target-feature" "+neon"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mfpu=crypto-neon-fp-armv8 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRYPTO-NEON-FP-ARMV8 %s
end_comment

begin_comment
comment|// CHECK-CRYPTO-NEON-FP-ARMV8: "-target-feature" "+fp-armv8"
end_comment

begin_comment
comment|// CHECK-CRYPTO-NEON-FP-ARMV8: "-target-feature" "+neon"
end_comment

begin_comment
comment|// CHECK-CRYPTO-NEON-FP-ARMV8: "-target-feature" "+crypto"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mfpu=none %s -### 2>&1 \
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

