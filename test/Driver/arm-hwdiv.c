begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that different values of -mhwdiv pick correct ARM hwdiv target-feature(s).
end_comment

begin_comment
comment|// RUN: %clang -### -target arm %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEFAULT %s
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+hwdiv"
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "-target-feature" "+hwdiv-arm"
end_comment

begin_comment
comment|// RUN: %clang -### -target arm %s -mhwdiv=arm -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_comment
comment|// CHECK-ARM: "-target-feature" "+hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-ARM: "-target-feature" "-hwdiv"
end_comment

begin_comment
comment|// RUN: %clang -### -target arm %s -mhwdiv=thumb -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-THUMB %s
end_comment

begin_comment
comment|// CHECK-THUMB: "-target-feature" "-hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-THUMB: "-target-feature" "+hwdiv"
end_comment

begin_comment
comment|// RUN: %clang  -### -target arm %s -mhwdiv=arm,thumb -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM-THUMB %s
end_comment

begin_comment
comment|// CHECK-ARM-THUMB: "-target-feature" "+hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-ARM-THUMB: "-target-feature" "+hwdiv"
end_comment

begin_comment
comment|// RUN: %clang  -### -target arm %s -mhwdiv=thumb,arm -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-THUMB-ARM %s
end_comment

begin_comment
comment|// CHECK-THUMB-ARM: "-target-feature" "+hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-THUMB-ARM: "-target-feature" "+hwdiv"
end_comment

begin_comment
comment|// RUN: %clang -### -target arm %s -mhwdiv=none -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NONE %s
end_comment

begin_comment
comment|// CHECK-NONE: "-target-feature" "-hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-NONE: "-target-feature" "-hwdiv"
end_comment

begin_comment
comment|// Also check the alternative syntax.
end_comment

begin_comment
comment|// RUN: %clang -### -target arm %s --mhwdiv arm -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ALT %s
end_comment

begin_comment
comment|// CHECK-ALT: "-target-feature" "+hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-ALT: "-target-feature" "-hwdiv"
end_comment

begin_comment
comment|// RUN: %clang -### -target arm %s --mhwdiv=arm -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ALT-EQ %s
end_comment

begin_comment
comment|// CHECK-ALT-EQ: "-target-feature" "+hwdiv-arm"
end_comment

begin_comment
comment|// CHECK-ALT-EQ: "-target-feature" "-hwdiv"
end_comment

end_unit

