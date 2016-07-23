begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test split stack ld flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fsplit-stack \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-I386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINUX-I386: "--wrap=pthread_create"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fsplit-stack \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINUX-X86-64: "--wrap=pthread_create"
end_comment

end_unit

