begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test whether or not the driver instructs the backend to use .init_array
end_comment

begin_comment
comment|// sections for global constructors.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-INIT-ARRAY: -fuse-init-array
end_comment

begin_comment
comment|// CHECK-NO-INIT-ARRAY-NOT: -fuse-init-array
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/fake_install_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -fno-use-init-array \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/fake_install_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -fno-use-init-array -fuse-init-array \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/fake_install_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -fuse-init-array \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target arm-unknown-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target mipsel-unknown-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target aarch64-none-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target aarch64-none-none-eabi \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target arm64-none-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target arm64-none-none-eabi \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1        \
end_comment

begin_comment
comment|// RUN:     -target sparc-sun-solaris2.11 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1        \
end_comment

begin_comment
comment|// RUN:     -target i386-pc-solaris2.11 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INIT-ARRAY %s
end_comment

end_unit

