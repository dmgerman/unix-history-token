begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -### \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-freebsd 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-FREEBSD-LD
end_comment

begin_comment
comment|// CHECK-FREEBSD-LD: ld
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=bfd \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd_tree \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-freebsd \
end_comment

begin_comment
comment|// RUN:     -B%S/Inputs/basic_freebsd_tree/usr/bin 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-FREEBSD-BFD
end_comment

begin_comment
comment|// CHECK-FREEBSD-BFD: Inputs/basic_freebsd_tree/usr/bin{{/|\\+}}ld.bfd
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=gold \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd_tree \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-freebsd \
end_comment

begin_comment
comment|// RUN:     -B%S/Inputs/basic_freebsd_tree/usr/bin 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-FREEBSD-GOLD
end_comment

begin_comment
comment|// CHECK-FREEBSD-GOLD: Inputs/basic_freebsd_tree/usr/bin{{/|\\+}}ld.gold
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=plib \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd_tree \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-freebsd \
end_comment

begin_comment
comment|// RUN:     -B%S/Inputs/basic_freebsd_tree/usr/bin 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-FREEBSD-PLIB
end_comment

begin_comment
comment|// CHECK-FREEBSD-PLIB: error: invalid linker name
end_comment

begin_comment
comment|// RUN: %clang %s -### \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     -B%S/Inputs/basic_android_tree/bin 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-ANDROID-ARM-LD
end_comment

begin_comment
comment|// CHECK-ANDROID-ARM-LD: Inputs/basic_android_tree/bin{{/|\\+}}arm-linux-androideabi-ld
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=bfd \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     -B%S/Inputs/basic_android_tree/bin 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-ANDROID-ARM-BFD
end_comment

begin_comment
comment|// CHECK-ANDROID-ARM-BFD: Inputs/basic_android_tree/bin{{/|\\+}}arm-linux-androideabi-ld.bfd
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=gold \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     -B%S/Inputs/basic_android_tree/bin 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-ANDROID-ARM-GOLD
end_comment

begin_comment
comment|// CHECK-ANDROID-ARM-GOLD: Inputs/basic_android_tree/bin{{/|\\+}}arm-linux-androideabi-ld.gold
end_comment

begin_comment
comment|// RUN: %clang %s -### \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     -gcc-toolchain %S/Inputs/basic_android_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-ANDROID-ARM-LD-TC
end_comment

begin_comment
comment|// CHECK-ANDROID-ARM-LD-TC: Inputs/basic_android_tree/lib/gcc/arm-linux-androideabi/4.4.3/../../../../arm-linux-androideabi/bin{{/|\\+}}ld
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=bfd \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     -gcc-toolchain %S/Inputs/basic_android_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-ANDROID-ARM-BFD-TC
end_comment

begin_comment
comment|// CHECK-ANDROID-ARM-BFD-TC: Inputs/basic_android_tree/lib/gcc/arm-linux-androideabi/4.4.3/../../../../arm-linux-androideabi/bin{{/|\\+}}ld.bfd
end_comment

begin_comment
comment|// RUN: %clang %s -### -fuse-ld=gold \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     -gcc-toolchain %S/Inputs/basic_android_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-ANDROID-ARM-GOLD-TC
end_comment

begin_comment
comment|// CHECK-ANDROID-ARM-GOLD-TC: Inputs/basic_android_tree/lib/gcc/arm-linux-androideabi/4.4.3/../../../../arm-linux-androideabi/bin{{/|\\+}}ld.gold
end_comment

end_unit

