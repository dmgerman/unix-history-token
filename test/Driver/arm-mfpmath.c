begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test different values of -mfpmath.
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mfpmath=vfp %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP %s
end_comment

begin_comment
comment|// CHECK-VFP: "-target-feature" "-neonfp"
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mfpmath=vfp2 %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP2 %s
end_comment

begin_comment
comment|// CHECK-VFP2: "-target-feature" "-neonfp"
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mfpmath=vfp3 %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP3 %s
end_comment

begin_comment
comment|// CHECK-VFP3: "-target-feature" "-neonfp"
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mfpmath=vfp4 %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-VFP4 %s
end_comment

begin_comment
comment|// CHECK-VFP4: "-target-feature" "-neonfp"
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mfpmath=neon %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NEON %s
end_comment

begin_comment
comment|// CHECK-NEON: "-target-feature" "+neonfp"
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mfpmath=foo %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ERROR %s
end_comment

begin_comment
comment|// CHECK-ERROR: clang compiler does not support '-mfpmath=foo'
end_comment

begin_comment
comment|// RUN: %clang -target arm-apple-darwin10 -mcpu=arm1136j-s -mfpmath=neon %s -### -c -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MCPU-ERROR %s
end_comment

begin_comment
comment|// CHECK-MCPU-ERROR: error: invalid feature '-mfpmath=neon' for CPU 'arm1136j-s'
end_comment

end_unit

