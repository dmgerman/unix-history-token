begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// These tests try to ensure that the driver operates reasonably when run with
end_comment

begin_comment
comment|// a strange environment. Unfortunately, it requires a normal shell and the
end_comment

begin_comment
comment|// 'env' command.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// The PATH variable is heavily used when trying to find a linker.
end_comment

begin_comment
comment|// RUN: env -i LC_ALL=C LD_LIBRARY_PATH="$LD_LIBRARY_PATH" \
end_comment

begin_comment
comment|// RUN:   %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: env -i LC_ALL=C PATH="" LD_LIBRARY_PATH="$LD_LIBRARY_PATH" \
end_comment

begin_comment
comment|// RUN:   %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-32-NOT: warning:
end_comment

begin_comment
comment|// CHECK-LD-32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-LD-32: "{{.*}}/usr/lib/gcc/i386-unknown-linux/4.6.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-LD-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-LD-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-LD-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-LD-32: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-LD-32: "-L[[SYSROOT]]/usr/lib"
end_comment

end_unit

