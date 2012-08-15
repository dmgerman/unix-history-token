begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// RUN:   | FileCheck --check-prefix=CHECK-GCC-4-7 %s
end_comment

begin_comment
comment|// CHECK-GCC-4-7: -fuse-init-array
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
comment|// RUN:   | FileCheck --check-prefix=CHECK-GCC-4-6 %s
end_comment

begin_comment
comment|// CHECK-GCC-4-6-NOT:  -fuse-init-array
end_comment

end_unit

