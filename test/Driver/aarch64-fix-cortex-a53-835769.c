begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEF %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mfix-cortex-a53-835769 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-YES %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-eabi -mno-fix-cortex-a53-835769 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-android-eabi %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-YES %s
end_comment

begin_comment
comment|// CHECK-DEF-NOT: "-backend-option" "-aarch64-fix-cortex-a53-835769"
end_comment

begin_comment
comment|// CHECK-YES: "-backend-option" "-aarch64-fix-cortex-a53-835769=1"
end_comment

begin_comment
comment|// CHECK-NO: "-backend-option" "-aarch64-fix-cortex-a53-835769=0"
end_comment

end_unit

