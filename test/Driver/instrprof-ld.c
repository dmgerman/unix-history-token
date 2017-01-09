begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test instrumented profiling ld flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fprofile-instr-generate -fuse-ld=ld \
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
comment|// CHECK-LINUX-I386: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-I386: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.profile-i386.a" {{.*}} "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fprofile-instr-generate -fuse-ld=ld \
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
comment|// CHECK-LINUX-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.profile-x86_64.a" {{.*}} "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fprofile-instr-generate -nostdlib -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-NOSTDLIB-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINUX-NOSTDLIB-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-NOSTDLIB-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.profile-x86_64.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-freebsd -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd64_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FREEBSD-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-FREEBSD-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-FREEBSD-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}freebsd{{/|\\\\}}libclang_rt.profile-x86_64.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-I386-SHARED %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINUX-I386-SHARED: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-I386-SHARED: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.profile-i386.a" {{.*}} "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX-X86-64-SHARED %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINUX-X86-64-SHARED: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-X86-64-SHARED: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.profile-x86_64.a" {{.*}} "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-freebsd -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd64_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FREEBSD-X86-64-SHARED %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-FREEBSD-X86-64-SHARED: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-FREEBSD-X86-64-SHARED: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}freebsd{{/|\\\\}}libclang_rt.profile-x86_64.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-apple-darwin14 -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DARWIN-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DARWIN-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DARWIN-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}darwin{{/|\\\\}}libclang_rt.profile_osx.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-apple-darwin14 -fprofile-instr-generate -nostdlib -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DARWIN-NOSTDLIB-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DARWIN-NOSTDLIB-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DARWIN-NOSTDLIB-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}darwin{{/|\\\\}}libclang_rt.profile_osx.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm64-apple-ios -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DARWIN-ARM64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DARWIN-ARM64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DARWIN-ARM64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}darwin{{/|\\\\}}libclang_rt.profile_ios.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target armv7-apple-darwin -mtvos-version-min=8.3 -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-TVOS-ARMV7 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-TVOS-ARMV7: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-TVOS-ARMV7: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}darwin{{/|\\\\}}libclang_rt.profile_tvos.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target armv7s-apple-darwin10 -mwatchos-version-min=2.0 -arch armv7k -fprofile-instr-generate -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-WATCHOS-ARMV7 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-WATCHOS-ARMV7: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-WATCHOS-ARMV7: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}darwin{{/|\\\\}}libclang_rt.profile_watchos.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-pc-win32 -fprofile-instr-generate \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-WINDOWS-I386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-WINDOWS-I386: "{{.*}}link{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-WINDOWS-I386: "{{.*}}clang_rt.profile-i386.lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-pc-win32 -fprofile-instr-generate \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-WINDOWS-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-WINDOWS-X86-64: "{{.*}}link{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-WINDOWS-X86-64: "{{.*}}clang_rt.profile-x86_64.lib"
end_comment

end_unit

