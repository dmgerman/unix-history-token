begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i686-pc-linux-gnu -### -nostdlib %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NOT: start-group
end_comment

begin_comment
comment|// Most of the toolchains would check for -nostartfiles and -nostdlib
end_comment

begin_comment
comment|// in a short-circuiting boolean expression, so if both of the preceding
end_comment

begin_comment
comment|// options were present, the second would warn about being unused.
end_comment

begin_comment
comment|// RUN: %clang -### -Wno-liblto -nostartfiles -nostdlib -target i386-apple-darwin %s \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck %s -check-prefix=ARGSCLAIMED
end_comment

begin_comment
comment|// ARGSCLAIMED-NOT: warning:
end_comment

begin_comment
comment|// In the presence of -nostdlib, the standard libraries should not be
end_comment

begin_comment
comment|// passed down to link line
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -Wno-liblto -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i686-pc-linux-gnu -nostdlib --rtlib=compiler-rt -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir -lclang_rt.builtins-i686 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-NOSTDLIB %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -Wno-liblto -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i686-pc-linux-gnu --rtlib=compiler-rt -nostdlib -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir -lclang_rt.builtins-i686 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-NOSTDLIB %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-windows-msvc -nostdlib --rtlib=compiler-rt -### -Wno-liblto %s 2>&1 | FileCheck %s -check-prefix CHECK-MSVC-NOSTDLIB
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-windows-msvc --rtlib=compiler-rt -nostdlib -### -Wno-liblto %s 2>&1 | FileCheck %s -check-prefix CHECK-MSVC-NOSTDLIB
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINUX-NOSTDLIB: warning: argument unused during compilation: '--rtlib=compiler-rt'
end_comment

begin_comment
comment|// CHECK-LINUX-NOSTDLIB: "{{(.*[^.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-NOSTDLIB-NOT: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.builtins-i686.a"
end_comment

begin_comment
comment|// CHECK-MSVC-NOSTDLIB: warning: argument unused during compilation: '--rtlib=compiler-rt'
end_comment

end_unit

