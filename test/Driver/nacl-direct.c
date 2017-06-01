begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test clang changes for NaCl Support including:
end_comment

begin_comment
comment|//    include paths, library paths, emulation, default static
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target i686-unknown-nacl -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-I686 %s
end_comment

begin_comment
comment|// CHECK-I686: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-I686: "-fuse-init-array"
end_comment

begin_comment
comment|// CHECK-I686: "-target-cpu" "pentium4"
end_comment

begin_comment
comment|// CHECK-I686: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-I686: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-I686: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}i686-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-I686: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-I686: as{{(.exe)?}}" "--32"
end_comment

begin_comment
comment|// CHECK-I686: ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-I686: "--build-id"
end_comment

begin_comment
comment|// CHECK-I686: "-m" "elf_i386_nacl"
end_comment

begin_comment
comment|// CHECK-I686: "-static"
end_comment

begin_comment
comment|// CHECK-I686: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}lib32"
end_comment

begin_comment
comment|// CHECK-I686: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}i686-nacl{{/|\\\\}}usr{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-I686: "-Lfoo{{/|\\\\}}lib{{/|\\\\}}i686-nacl"
end_comment

begin_comment
comment|// CHECK-I686-NOT: -lpthread
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-nacl -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-x86_64 %s
end_comment

begin_comment
comment|// CHECK-x86_64: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-x86_64: "-fuse-init-array"
end_comment

begin_comment
comment|// CHECK-x86_64: "-target-cpu" "x86-64"
end_comment

begin_comment
comment|// CHECK-x86_64: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-x86_64: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-x86_64: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-x86_64: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-x86_64: as{{(.exe)?}}" "--64"
end_comment

begin_comment
comment|// CHECK-x86_64: ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-x86_64: "--build-id"
end_comment

begin_comment
comment|// CHECK-x86_64: "-m" "elf_x86_64_nacl"
end_comment

begin_comment
comment|// CHECK-x86_64: "-static"
end_comment

begin_comment
comment|// CHECK-x86_64: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-x86_64: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}usr{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-x86_64: "-Lfoo{{/|\\\\}}lib{{/|\\\\}}x86_64-nacl"
end_comment

begin_comment
comment|// CHECK-X86_64-NOT: -lpthread
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target armv7a-unknown-nacl-gnueabihf -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_comment
comment|// CHECK-ARM: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-ARM: "-fuse-init-array"
end_comment

begin_comment
comment|// CHECK-ARM: "-target-cpu" "generic"
end_comment

begin_comment
comment|// CHECK-ARM: "-target-abi" "aapcs-linux"
end_comment

begin_comment
comment|// CHECK-ARM: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK-ARM: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-ARM: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-ARM: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-ARM: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-ARM: as{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ARM: "-mfloat-abi=hard"
end_comment

begin_comment
comment|// CHECK-ARM: ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ARM: "--build-id"
end_comment

begin_comment
comment|// CHECK-ARM: "-m" "armelf_nacl"
end_comment

begin_comment
comment|// CHECK-ARM: "-static"
end_comment

begin_comment
comment|// CHECK-ARM: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-ARM: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}usr{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-ARM: "-Lfoo{{/|\\\\}}lib{{/|\\\\}}arm-nacl"
end_comment

begin_comment
comment|// CHECK-ARM-NOT: -lpthread
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target mipsel-unknown-nacl -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS %s
end_comment

begin_comment
comment|// CHECK-MIPS: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-MIPS: "-fuse-init-array"
end_comment

begin_comment
comment|// CHECK-MIPS: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// CHECK-MIPS: "-target-abi" "o32"
end_comment

begin_comment
comment|// CHECK-MIPS: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK-MIPS: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-MIPS: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-MIPS: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-MIPS: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-MIPS-NOT: as{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS: ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS: "--build-id"
end_comment

begin_comment
comment|// CHECK-MIPS: "-m" "mipselelf_nacl"
end_comment

begin_comment
comment|// CHECK-MIPS: "-static"
end_comment

begin_comment
comment|// CHECK-MIPS: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-MIPS: "-L{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}usr{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK-MIPS: "-Lfoo{{/|\\\\}}lib{{/|\\\\}}mipsel-nacl"
end_comment

begin_comment
comment|// CHECK-MIPS: "-lpnacl_legacy"
end_comment

begin_comment
comment|// CHECK-MIPS-NOT: "-lpthread"
end_comment

begin_comment
comment|// Check that even when the target arch is just "arm" (as will be the case when
end_comment

begin_comment
comment|// it is inferred from the binary name) that we get the right ABI flags
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -o %t.o %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-nacl \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM-NOV7 %s
end_comment

begin_comment
comment|// CHECK-ARM-NOV7: "-triple" "armv7--nacl-gnueabihf"
end_comment

begin_comment
comment|// CHECK-ARM-NOV7: "-target-abi" "aapcs-linux"
end_comment

begin_comment
comment|// CHECK-ARM-NOV7: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK-ARM-NOV7: as{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ARM-NOV7: "-mfloat-abi=hard"
end_comment

begin_comment
comment|// Test clang c++ include dirs and link line when using clang++
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target armv7a-unknown-nacl-gnueabihf -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM-CXX %s
end_comment

begin_comment
comment|// CHECK-ARM-CXX: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-ARM-CXX: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-ARM-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}include{{/|\\\\}}c++{{/|\\\\}}v1"
end_comment

begin_comment
comment|// CHECK-ARM-CXX: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-ARM-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-ARM-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}arm-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-ARM-CXX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target i686-unknown-nacl -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-I686-CXX %s
end_comment

begin_comment
comment|// CHECK-I686-CXX: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-I686-CXX: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-I686-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}include{{/|\\\\}}c++{{/|\\\\}}v1"
end_comment

begin_comment
comment|// CHECK-I686-CXX: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-I686-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}i686-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-I686-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-I686-CXX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-nacl -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-x86_64-CXX %s
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}include{{/|\\\\}}c++{{/|\\\\}}v1"
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}x86_64-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-x86_64-CXX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes -### -o %t.o %s \
end_comment

begin_comment
comment|// RUN:     -target mipsel-unknown-nacl -resource-dir foo 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS-CXX %s
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-resource-dir" "foo"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}include{{/|\\\\}}c++{{/|\\\\}}v1"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-internal-isystem" "foo{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}usr{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-internal-isystem" "{{.*}}{{/|\\\\}}..{{/|\\\\}}mipsel-nacl{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-lnacl"
end_comment

begin_comment
comment|// CHECK-MIPS-CXX: "-lpthread"
end_comment

end_unit

