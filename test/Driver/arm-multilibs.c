begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-linux-gnueabi --sysroot=%S/Inputs/multilib_arm_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbv7-linux-gnueabi --sysroot=%S/Inputs/multilib_arm_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-linux-gnueabihf --sysroot=%S/Inputs/multilib_armhf_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARMHF %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbv7-linux-gnueabihf --sysroot=%S/Inputs/multilib_armhf_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARMHF %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7eb-linux-gnueabi --sysroot=%S/Inputs/multilib_armeb_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARMEB %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbv7eb-linux-gnueabi --sysroot=%S/Inputs/multilib_armeb_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARMEB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7eb-linux-gnueabihf --sysroot=%S/Inputs/multilib_armebhf_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARMEBHF %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbv7eb-linux-gnueabihf --sysroot=%S/Inputs/multilib_armebhf_linux_tree -### -c %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ARMEBHF %s
end_comment

begin_comment
comment|// CHECK-ARM: "-internal-externc-isystem" "{{.*}}/usr/include/arm-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-ARMHF: "-internal-externc-isystem" "{{.*}}/usr/include/arm-linux-gnueabihf"
end_comment

begin_comment
comment|// CHECK-ARMEB: "-internal-externc-isystem" "{{.*}}/usr/include/armeb-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-ARMEBHF: "-internal-externc-isystem" "{{.*}}/usr/include/armeb-linux-gnueabihf"
end_comment

end_unit

