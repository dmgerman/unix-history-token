begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// UNSUPPORTED: system-windows
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: mkdir -p %T/Output
end_comment

begin_comment
comment|// RUN: rm -f %T/Output/orbis-ld
end_comment

begin_comment
comment|// RUN: touch %T/Output/orbis-ld
end_comment

begin_comment
comment|// RUN: chmod +x %T/Output/orbis-ld
end_comment

begin_comment
comment|// RUN: env "PATH=%T/Output:%PATH%" %clang -### -target x86_64-scei-ps4  %s -fuse-ld=gold 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T/Output:%PATH%" %clang -### -target x86_64-scei-ps4  %s -shared 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T/Output:%PATH%" %clang -### -target x86_64-scei-ps4  %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T/Output:%PATH%" %clang -### -target x86_64-scei-ps4  %s -fuse-ld=ps4 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// RUN: env "PATH=%T/Output:%PATH%" %clang -### -target x86_64-scei-ps4  %s -shared \
end_comment

begin_comment
comment|// RUN:     -fuse-ld=ps4 2>&1 | FileCheck --check-prefix=CHECK-PS4-LINKER %s
end_comment

begin_comment
comment|// CHECK-PS4-LINKER: /orbis-ld
end_comment

end_unit

