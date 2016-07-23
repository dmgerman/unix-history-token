begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The full path to the gold linker was not found on Windows because the
end_comment

begin_comment
comment|// driver fails to add an .exe extension to the name.
end_comment

begin_comment
comment|// We check that gold linker's full name (with an extension) is specified
end_comment

begin_comment
comment|// on the command line if -fuse-ld=gold, or -shared with no -fuse-ld option
end_comment

begin_comment
comment|// are passed. Otherwise, we check that the PS4's linker's full name is
end_comment

begin_comment
comment|// specified.
end_comment

begin_comment
comment|// REQUIRES: system-windows, x86-registered-target
end_comment

begin_comment
comment|// RUN: touch %T/orbis-ld.exe
end_comment

begin_comment
comment|// RUN: touch %T/orbis-ld.gold.exe
end_comment

begin_comment
comment|// RUN: env "PATH=%T;%PATH%;" %clang -target x86_64-scei-ps4  %s -fuse-ld=gold -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-GOLD %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T;%PATH%;" %clang -target x86_64-scei-ps4  %s -shared -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-GOLD %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T;%PATH%;" %clang -target x86_64-scei-ps4  %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T;%PATH%;" %clang -target x86_64-scei-ps4  %s -fuse-ld=ps4 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T;%PATH%;" %clang -target x86_64-scei-ps4  %s -shared \
end_comment

begin_comment
comment|// RUN:     -fuse-ld=ps4 -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// CHECK-PS4-GOLD: \\orbis-ld.gold
end_comment

begin_comment
comment|// CHECK-PS4-LINKER: \\orbis-ld
end_comment

end_unit

