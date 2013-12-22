begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that different values of -mfpu pick correct ARM FPU target-feature(s).
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEFAULT %s
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+vfp2"
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+vfp3"
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+d16"
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+neon"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=fpa %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FPA %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=fpe2 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FPA %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=fpe3 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FPA %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=maverick %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FPA %s
end_comment

begin_comment
comment|// CHECK-FPA: "-target-feature" "-vfp2"
end_comment

begin_comment
comment|// CHECK-FPA: "-target-feature" "-vfp3"
end_comment

begin_comment
comment|// CHECK-FPA: "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=vfp3-d16 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP3-D16 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=vfpv3-d16 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP3-D16 %s
end_comment

begin_comment
comment|// CHECK-VFP3-D16: "-target-feature" "+vfp3"
end_comment

begin_comment
comment|// CHECK-VFP3-D16: "-target-feature" "+d16"
end_comment

begin_comment
comment|// CHECK-VFP3-D16: "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=vfp %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP %s
end_comment

begin_comment
comment|// CHECK-VFP: "-target-feature" "+vfp2"
end_comment

begin_comment
comment|// CHECK-VFP: "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=vfp3 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP3 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=vfpv3 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP3 %s
end_comment

begin_comment
comment|// CHECK-VFP3: "-target-feature" "+vfp3"
end_comment

begin_comment
comment|// CHECK-VFP3: "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mfpu=neon %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NEON %s
end_comment

begin_comment
comment|// CHECK-NEON: "-target-feature" "+neon"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -msoft-float %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFT-FLOAT %s
end_comment

begin_comment
comment|// CHECK-SOFT-FLOAT: "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mfpu=fp-armv8 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARMV8-SOFT-FLOAT %s
end_comment

begin_comment
comment|// CHECK-ARMV8-SOFT-FLOAT: "-target-feature" "+fp-armv8"
end_comment

begin_comment
comment|// CHECK-ARMV8-SOFT-FLOAT: "-target-feature" "-crypto"
end_comment

begin_comment
comment|// CHECK-ARMV8-SOFT-FLOAT: "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target armv8-linux-gnueabihf -mfpu=fp-armv8 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FP-ARMV8 %s
end_comment

begin_comment
comment|// CHECK-FP-ARMV8-NOT: "-target-feature" "+neon"
end_comment

begin_comment
comment|// CHECK-FP-ARMV8: "-target-feature" "+fp-armv8"
end_comment

begin_comment
comment|// CHECK-FP-ARMV8: "-target-feature" "-neon"
end_comment

begin_comment
comment|// CHECK-FP-ARMV8: "-target-feature" "-crypto"
end_comment

begin_comment
comment|// RUN: %clang -target armv8-linux-gnueabihf -mfpu=neon-fp-armv8 %s -### 2>&1 \
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
comment|// CHECK-NEON-FP-ARMV8: "-target-feature" "-crypto"
end_comment

begin_comment
comment|// RUN: %clang -target armv8-linux-gnueabihf -mfpu=crypto-neon-fp-armv8 %s -### 2>&1 \
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
comment|// RUN: %clang -target armv8-linux-gnueabi -mfpu=none %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FP %s
end_comment

begin_comment
comment|// CHECK-NO-FP: "-target-feature" "-vfp2"
end_comment

begin_comment
comment|// CHECK-NO-FP: "-target-feature" "-vfp3"
end_comment

begin_comment
comment|// CHECK-NO-FP: "-target-feature" "-vfp4"
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

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabihf %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-HF %s
end_comment

begin_comment
comment|// CHECK-HF: "-target-cpu" "arm1136jf-s"
end_comment

end_unit

