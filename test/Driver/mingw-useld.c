begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target i686-pc-windows-gnu --sysroot=%S/Inputs/mingw_clang_tree/mingw32 %s 2>&1 | FileCheck -check-prefix=CHECK_LD_32 %s
end_comment

begin_comment
comment|// CHECK_LD_32: ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK_LD_32: "i386pe"
end_comment

begin_comment
comment|// CHECK_LD_32-NOT: "-flavor" "gnu"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-pc-windows-gnu --sysroot=%S/Inputs/mingw_clang_tree/mingw32 %s -fuse-ld=lld 2>&1 | FileCheck -check-prefix=CHECK_LLD_32 %s
end_comment

begin_comment
comment|// CHECK_LLD_32-NOT: invalid linker name in argument
end_comment

begin_comment
comment|// CHECK_LLD_32: lld{{(.exe)?}}" "-flavor" "gnu"
end_comment

begin_comment
comment|// CHECK_LLD_32: "i386pe"
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-pc-windows-gnu --sysroot=%S/Inputs/mingw_clang_tree/mingw32 %s -fuse-ld=lld 2>&1 | FileCheck -check-prefix=CHECK_LLD_64 %s
end_comment

begin_comment
comment|// CHECK_LLD_64-NOT: invalid linker name in argument
end_comment

begin_comment
comment|// CHECK_LLD_64: lld{{(.exe)?}}" "-flavor" "gnu"
end_comment

begin_comment
comment|// CHECK_LLD_64: "i386pep"
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-pc-windows-gnu --sysroot=%S/Inputs/mingw_clang_tree/mingw32 %s -fuse-ld=lld 2>&1 | FileCheck -check-prefix=CHECK_LLD_ARM %s
end_comment

begin_comment
comment|// CHECK_LLD_ARM-NOT: invalid linker name in argument
end_comment

begin_comment
comment|// CHECK_LLD_ARM: lld{{(.exe)?}}" "-flavor" "gnu"
end_comment

begin_comment
comment|// CHECK_LLD_ARM: "thumb2pe"
end_comment

end_unit

