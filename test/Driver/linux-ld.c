begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// General tests that ld invocations on Linux targets sane. Note that we use
end_comment

begin_comment
comment|// sysroot to make these tests independent of the host system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-32 %s
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

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64 %s
end_comment

begin_comment
comment|// CHECK-LD-64-NOT: warning:
end_comment

begin_comment
comment|// CHECK-LD-64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-LD-64: "--eh-frame-hdr"
end_comment

begin_comment
comment|// CHECK-LD-64: "-m" "elf_x86_64"
end_comment

begin_comment
comment|// CHECK-LD-64: "-dynamic-linker"
end_comment

begin_comment
comment|// CHECK-LD-64: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-LD-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-LD-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-LD-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-LD-64: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-LD-64: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-LD-64: "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
end_comment

begin_comment
comment|// CHECK-LD-64: "-lc"
end_comment

begin_comment
comment|// CHECK-LD-64: "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -static-libgcc \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64-STATIC-LIBGCC %s
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC-NOT: warning:
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "--eh-frame-hdr"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-m" "elf_x86_64"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-dynamic-linker"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-lgcc" "-lgcc_eh"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-lc"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-LIBGCC: "-lgcc" "-lgcc_eh"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -static \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64-STATIC %s
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-NOT: warning:
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-NOT: "--eh-frame-hdr"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-m" "elf_x86_64"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC-NOT: "-dynamic-linker"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-static"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0{{/|\\\\}}crtbeginT.o"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-LD-64-STATIC: "--start-group" "-lgcc" "-lgcc_eh" "-lc" "--end-group"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that flags can be combined. The -static dominates.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -static-libgcc -static \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64-STATIC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/multilib_32bit_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-32-TO-32 %s
end_comment

begin_comment
comment|// CHECK-32-TO-32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "{{.*}}/usr/lib/gcc/i386-unknown-linux/4.6.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../lib32"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-32-TO-32: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m64 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/multilib_32bit_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-32-TO-64 %s
end_comment

begin_comment
comment|// CHECK-32-TO-64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "{{.*}}/usr/lib/gcc/i386-unknown-linux/4.6.0/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/64"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../lib64"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/i386-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-32-TO-64: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux -m64 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/multilib_64bit_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-64-TO-64 %s
end_comment

begin_comment
comment|// CHECK-64-TO-64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../lib64"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-64-TO-64: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/multilib_64bit_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-64-TO-32 %s
end_comment

begin_comment
comment|// CHECK-64-TO-32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/32{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/32"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../lib32"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../.."
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-64-TO-32: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/multilib_64bit_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/multilib_32bit_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-64-TO-32-SYSROOT %s
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/32{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "-L{{[^"]*}}/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0/32"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "-L[[SYSROOT]]/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "-L[[SYSROOT]]/usr/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "-L{{[^"]*}}/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-64-TO-32-SYSROOT: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     -ccc-install-dir %S/Inputs/fake_install_tree/bin \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INSTALL-DIR-32 %s
end_comment

begin_comment
comment|// CHECK-INSTALL-DIR-32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-INSTALL-DIR-32: "{{.*}}/Inputs/fake_install_tree/bin/../lib/gcc/i386-unknown-linux/4.7.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-INSTALL-DIR-32: "-L{{.*}}/Inputs/fake_install_tree/bin/../lib/gcc/i386-unknown-linux/4.7.0"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that with 64-bit builds, we don't actually use the install directory
end_comment

begin_comment
comment|// as its version of GCC is lower than our sysrooted version.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-unknown-linux -m64 \
end_comment

begin_comment
comment|// RUN:     -ccc-install-dir %S/Inputs/fake_install_tree/bin \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-INSTALL-DIR-64 %s
end_comment

begin_comment
comment|// CHECK-INSTALL-DIR-64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-INSTALL-DIR-64: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-INSTALL-DIR-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-unknown-linux/4.6.0"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that we support unusual patch version formats, including missing that
end_comment

begin_comment
comment|// component.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     -ccc-install-dir %S/Inputs/gcc_version_parsing1/bin \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-GCC-VERSION1 %s
end_comment

begin_comment
comment|// CHECK-GCC-VERSION1: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION1: "{{.*}}/Inputs/gcc_version_parsing1/bin/../lib/gcc/i386-unknown-linux/4.7{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION1: "-L{{.*}}/Inputs/gcc_version_parsing1/bin/../lib/gcc/i386-unknown-linux/4.7"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     -ccc-install-dir %S/Inputs/gcc_version_parsing2/bin \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-GCC-VERSION2 %s
end_comment

begin_comment
comment|// CHECK-GCC-VERSION2: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION2: "{{.*}}/Inputs/gcc_version_parsing2/bin/../lib/gcc/i386-unknown-linux/4.7.x{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION2: "-L{{.*}}/Inputs/gcc_version_parsing2/bin/../lib/gcc/i386-unknown-linux/4.7.x"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     -ccc-install-dir %S/Inputs/gcc_version_parsing3/bin \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-GCC-VERSION3 %s
end_comment

begin_comment
comment|// CHECK-GCC-VERSION3: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION3: "{{.*}}/Inputs/gcc_version_parsing3/bin/../lib/gcc/i386-unknown-linux/4.7.99-rc5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION3: "-L{{.*}}/Inputs/gcc_version_parsing3/bin/../lib/gcc/i386-unknown-linux/4.7.99-rc5"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     -ccc-install-dir %S/Inputs/gcc_version_parsing4/bin \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-GCC-VERSION4 %s
end_comment

begin_comment
comment|// CHECK-GCC-VERSION4: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION4: "{{.*}}/Inputs/gcc_version_parsing4/bin/../lib/gcc/i386-unknown-linux/4.7.99{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION4: "-L{{.*}}/Inputs/gcc_version_parsing4/bin/../lib/gcc/i386-unknown-linux/4.7.99"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test a very broken version of multiarch that shipped in Ubuntu 11.04.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/ubuntu_11.04_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBUNTU-11-04 %s
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "{{.*}}/usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "-L[[SYSROOT]]/usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "-L[[SYSROOT]]/usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5/../../../../i386-linux-gnu"
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "-L[[SYSROOT]]/usr/lib/i386-linux-gnu"
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "-L[[SYSROOT]]/usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5/../../../.."
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-UBUNTU-11-04: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check multi arch support on Ubuntu 12.04 LTS.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-unknown-linux-gnueabihf \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/ubuntu_12.04_LTS_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBUNTU-12-04-ARM-HF %s
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "{{.*}}/usr/lib/gcc/arm-linux-gnueabihf/4.6.3/../../../arm-linux-gnueabihf{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "{{.*}}/usr/lib/gcc/arm-linux-gnueabihf/4.6.3/../../../arm-linux-gnueabihf{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "{{.*}}/usr/lib/gcc/arm-linux-gnueabihf/4.6.3{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc/arm-linux-gnueabihf/4.6.3"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc/arm-linux-gnueabihf/4.6.3/../../../arm-linux-gnueabihf"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "-L[[SYSROOT]]/lib/arm-linux-gnueabihf"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "-L[[SYSROOT]]/usr/lib/arm-linux-gnueabihf"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc/arm-linux-gnueabihf/4.6.3/../../.."
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "{{.*}}/usr/lib/gcc/arm-linux-gnueabihf/4.6.3{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM-HF: "{{.*}}/usr/lib/gcc/arm-linux-gnueabihf/4.6.3/../../../arm-linux-gnueabihf{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check Ubuntu 13.10 on x86-64 targeting arm-linux-gnueabihf.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-gnueabihf \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/x86-64_ubuntu_13.10 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-X86-64-UBUNTU-13-10-ARM-HF %s
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "-dynamic-linker" "/lib/ld-linux-armhf.so.3"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8/../../../../arm-linux-gnueabihf/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8/../../../../arm-linux-gnueabihf/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8/../../../../arm-linux-gnueabihf/lib/../lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "-L[[SYSROOT]]/lib/../lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "-L[[SYSROOT]]/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8/../../../../arm-linux-gnueabihf/lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM-HF: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabihf/4.8/../../../../arm-linux-gnueabihf/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check Ubuntu 13.10 on x86-64 targeting arm-linux-gnueabi.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/x86-64_ubuntu_13.10 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-X86-64-UBUNTU-13-10-ARM %s
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "-dynamic-linker" "/lib/ld-linux.so.3"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabi/4.7/../../../../arm-linux-gnueabi/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabi/4.7/../../../../arm-linux-gnueabi/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabi/4.7{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "-L[[SYSROOT]]/usr/lib/gcc-cross/arm-linux-gnueabi/4.7"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "-L[[SYSROOT]]/usr/lib/gcc-cross/arm-linux-gnueabi/4.7/../../../../arm-linux-gnueabi/lib/../lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "-L[[SYSROOT]]/lib/../lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "-L[[SYSROOT]]/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "-L[[SYSROOT]]/usr/lib/gcc-cross/arm-linux-gnueabi/4.7/../../../../arm-linux-gnueabi/lib"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabi/4.7{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-X86-64-UBUNTU-13-10-ARM: "{{.*}}/usr/lib/gcc-cross/arm-linux-gnueabi/4.7/../../../../arm-linux-gnueabi/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check fedora 18 on arm.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=armv7-unknown-linux-gnueabihf \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/fedora_18_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FEDORA-18-ARM-HF %s
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "{{.*}}/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2/../../../../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "{{.*}}/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2/../../../../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "{{.*}}/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "-L[[SYSROOT]]/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2/../../../../lib"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "{{.*}}/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-FEDORA-18-ARM-HF: "{{.*}}/usr/lib/gcc/armv7hl-redhat-linux-gnueabi/4.7.2/../../../../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-unknown-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/ubuntu_12.04_LTS_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBUNTU-12-04-ARM %s
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "{{.*}}/usr/lib/gcc/arm-linux-gnueabi/4.6.1/../../../arm-linux-gnueabi{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "{{.*}}/usr/lib/gcc/arm-linux-gnueabi/4.6.1/../../../arm-linux-gnueabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "{{.*}}/usr/lib/gcc/arm-linux-gnueabi/4.6.1{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "-L[[SYSROOT]]/usr/lib/gcc/arm-linux-gnueabi/4.6.1"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "-L[[SYSROOT]]/usr/lib/gcc/arm-linux-gnueabi/4.6.1/../../../arm-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "-L[[SYSROOT]]/lib/arm-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "-L[[SYSROOT]]/usr/lib/arm-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "-L[[SYSROOT]]/usr/lib/gcc/arm-linux-gnueabi/4.6.1/../../.."
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "{{.*}}/usr/lib/gcc/arm-linux-gnueabi/4.6.1{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-UBUNTU-12-04-ARM: "{{.*}}/usr/lib/gcc/arm-linux-gnueabi/4.6.1/../../../arm-linux-gnueabi{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test the setup that shipped in SUSE 10.3 on ppc64.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=powerpc64-suse-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/suse_10.3_ppc64_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SUSE-10-3-PPC64 %s
end_comment

begin_comment
comment|// CHECK-SUSE-10-3-PPC64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-SUSE-10-3-PPC64: "{{.*}}/usr/lib/gcc/powerpc64-suse-linux/4.1.2/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-SUSE-10-3-PPC64: "-L[[SYSROOT]]/usr/lib/gcc/powerpc64-suse-linux/4.1.2/64"
end_comment

begin_comment
comment|// CHECK-SUSE-10-3-PPC64: "-L[[SYSROOT]]/usr/lib/gcc/powerpc64-suse-linux/4.1.2/../../../../lib64"
end_comment

begin_comment
comment|// CHECK-SUSE-10-3-PPC64: "-L[[SYSROOT]]/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-SUSE-10-3-PPC64: "-L[[SYSROOT]]/usr/lib/../lib64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check dynamic-linker for different archs
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_comment
comment|// CHECK-ARM: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ARM: "-m" "armelf_linux_eabi"
end_comment

begin_comment
comment|// CHECK-ARM: "-dynamic-linker" "{{.*}}/lib/ld-linux.so.3"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-gnueabihf \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM-HF %s
end_comment

begin_comment
comment|// CHECK-ARM-HF: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ARM-HF: "-m" "armelf_linux_eabi"
end_comment

begin_comment
comment|// CHECK-ARM-HF: "-dynamic-linker" "{{.*}}/lib/ld-linux-armhf.so.3"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that we do not pass --hash-style=gnu and --hash-style=both to linker
end_comment

begin_comment
comment|// and provide correct path to the dynamic linker and emulation mode when build
end_comment

begin_comment
comment|// for MIPS platforms.
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS %s
end_comment

begin_comment
comment|// CHECK-MIPS: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS: "-m" "elf32btsmip"
end_comment

begin_comment
comment|// CHECK-MIPS: "-dynamic-linker" "{{.*}}/lib/ld.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPSEL %s
end_comment

begin_comment
comment|// CHECK-MIPSEL: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPSEL: "-m" "elf32ltsmip"
end_comment

begin_comment
comment|// CHECK-MIPSEL: "-dynamic-linker" "{{.*}}/lib/ld.so.1"
end_comment

begin_comment
comment|// CHECK-MIPSEL-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64 %s
end_comment

begin_comment
comment|// CHECK-MIPS64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS64: "-m" "elf64btsmip"
end_comment

begin_comment
comment|// CHECK-MIPS64: "-dynamic-linker" "{{.*}}/lib64/ld.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS64-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64EL %s
end_comment

begin_comment
comment|// CHECK-MIPS64EL: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS64EL: "-m" "elf64ltsmip"
end_comment

begin_comment
comment|// CHECK-MIPS64EL: "-dynamic-linker" "{{.*}}/lib64/ld.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64-linux-gnu -mabi=n32 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64-N32 %s
end_comment

begin_comment
comment|// CHECK-MIPS64-N32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS64-N32: "-m" "elf32btsmipn32"
end_comment

begin_comment
comment|// CHECK-MIPS64-N32: "-dynamic-linker" "{{.*}}/lib32/ld.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS64-N32-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu -mabi=n32 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64EL-N32 %s
end_comment

begin_comment
comment|// CHECK-MIPS64EL-N32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-N32: "-m" "elf32ltsmipn32"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-N32: "-dynamic-linker" "{{.*}}/lib32/ld.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-N32-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Thoroughly exercise the Debian multiarch environment.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i686-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-X86 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "{{.*}}/usr/lib/gcc/i686-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "-L[[SYSROOT]]/usr/lib/gcc/i686-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "-L[[SYSROOT]]/usr/lib/gcc/i686-linux-gnu/4.5/../../../i386-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "-L[[SYSROOT]]/usr/lib/i386-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "-L[[SYSROOT]]/usr/lib/gcc/i686-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-X86-64 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "{{.*}}/usr/lib/gcc/x86_64-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-linux-gnu/4.5/../../../x86_64-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "-L[[SYSROOT]]/usr/lib/x86_64-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "-L[[SYSROOT]]/usr/lib/gcc/x86_64-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-X86-64: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=powerpc-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-PPC %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "{{.*}}/usr/lib/gcc/powerpc-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "-L[[SYSROOT]]/usr/lib/gcc/powerpc-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "-L[[SYSROOT]]/usr/lib/gcc/powerpc-linux-gnu/4.5/../../../powerpc-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "-L[[SYSROOT]]/usr/lib/powerpc-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "-L[[SYSROOT]]/usr/lib/gcc/powerpc-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=powerpc64-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-PPC64 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "{{.*}}/usr/lib/gcc/powerpc64-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "-L[[SYSROOT]]/usr/lib/gcc/powerpc64-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "-L[[SYSROOT]]/usr/lib/gcc/powerpc64-linux-gnu/4.5/../../../powerpc64-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "-L[[SYSROOT]]/usr/lib/powerpc64-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "-L[[SYSROOT]]/usr/lib/gcc/powerpc64-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-PPC64: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-MIPS %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "{{.*}}/usr/lib/gcc/mips-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5/../../../mips-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "-L[[SYSROOT]]/usr/lib/mips-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-MIPSEL %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.5{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5/../../../mipsel-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "-L[[SYSROOT]]/usr/lib/mipsel-linux-gnu"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPSEL: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-MIPS64 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "{{.*}}/usr/lib/gcc/mips-linux-gnu/4.5/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5/64"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-MIPS64EL %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.5/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5/64"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64-linux-gnu -mabi=n32 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-MIPS64-N32 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "{{.*}}/usr/lib/gcc/mips-linux-gnu/4.5/n32{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5/n32"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "-L[[SYSROOT]]/usr/lib/gcc/mips-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64-N32: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu -mabi=n32 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_multiarch_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-MIPS64EL-N32 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.5/n32{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5/n32"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.5/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test linker invocation on Android.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID %s
end_comment

begin_comment
comment|// CHECK-ANDROID: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-ANDROID: "{{.*}}{{/|\\\\}}crtbegin_dynamic.o"
end_comment

begin_comment
comment|// CHECK-ANDROID: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-ANDROID-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID: "-lgcc"
end_comment

begin_comment
comment|// CHECK-ANDROID: "-ldl"
end_comment

begin_comment
comment|// CHECK-ANDROID-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID: "{{.*}}{{/|\\\\}}crtend_android.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-SO %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-SO %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-SO %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-SO %s
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "-Bsymbolic"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "{{.*}}{{/|\\\\}}crtbegin_so.o"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "-lgcc"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "-ldl"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID-SO: "{{.*}}{{/|\\\\}}crtend_so.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -static \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -static \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -static \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -static \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-STATIC %s
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC: "{{.*}}{{/|\\\\}}crtbegin_static.o"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC: "-lgcc"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC-NOT: "-ldl"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID-STATIC: "{{.*}}{{/|\\\\}}crtend_android.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-androideabi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot  \
end_comment

begin_comment
comment|// RUN:     -pie \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=arm-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -pie \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -pie \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i386-linux-android \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -pie \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-PIE %s
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE: "{{.*}}{{/|\\\\}}crtbegin_dynamic.o"
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE: "-lgcc"
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE-NOT: "gcc_s"
end_comment

begin_comment
comment|// CHECK-ANDROID-PIE: "{{.*}}{{/|\\\\}}crtend_android.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check linker invocation on Debian 6 MIPS 32/64-bit.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_6_mips_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-ML-MIPSEL %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/lib/../lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPSEL: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_6_mips_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-ML-MIPS64EL %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib64{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib64{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/64"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib64"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu -mabi=n32 \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/debian_6_mips_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEBIAN-ML-MIPS64EL-N32 %s
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib32{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib32{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "{{.*}}/usr/lib/gcc/mipsel-linux-gnu/4.4/n32{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/n32"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/../../../../lib32"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib/gcc/mipsel-linux-gnu/4.4/../../.."
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/lib"
end_comment

begin_comment
comment|// CHECK-DEBIAN-ML-MIPS64EL-N32: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test linker invocation for Freescale SDK (OpenEmbedded).
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=powerpc-fsl-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/freescale_ppc_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FSL-PPC %s
end_comment

begin_comment
comment|// CHECK-FSL-PPC: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-FSL-PPC: "-m" "elf32ppclinux"
end_comment

begin_comment
comment|// CHECK-FSL-PPC: "{{.*}}{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-FSL-PPC: "{{.*}}{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-FSL-PPC: "-L[[SYSROOT]]/usr/lib"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=powerpc64-fsl-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/freescale_ppc64_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FSL-PPC64 %s
end_comment

begin_comment
comment|// CHECK-FSL-PPC64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-FSL-PPC64: "-m" "elf64ppc"
end_comment

begin_comment
comment|// CHECK-FSL-PPC64: "{{.*}}{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-FSL-PPC64: "{{.*}}{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-FSL-PPC64: "-L[[SYSROOT]]/usr/lib64/powerpc64-fsl-linux/4.6.2/../.."
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that crtfastmath.o is linked with -ffast-math and with -Ofast.
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOCRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -ffast-math \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -funsafe-math-optimizations\
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -Ofast\
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -Ofast -O3\
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOCRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -O3 -Ofast\
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -ffast-math -fno-fast-math \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOCRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -Ofast -fno-fast-math \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -Ofast -fno-unsafe-math-optimizations \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -fno-fast-math -Ofast  \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-unknown-linux -### %s -fno-unsafe-math-optimizations -Ofast \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CRTFASTMATH %s
end_comment

begin_comment
comment|// We don't have crtfastmath.o in the i386 tree, use it to check that file
end_comment

begin_comment
comment|// detection works.
end_comment

begin_comment
comment|// RUN: %clang --target=i386-unknown-linux -### %s -ffast-math \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOCRTFASTMATH %s
end_comment

begin_comment
comment|// CHECK-CRTFASTMATH: usr/lib/gcc/x86_64-unknown-linux/4.6.0{{/|\\\\}}crtfastmath.o
end_comment

begin_comment
comment|// CHECK-NOCRTFASTMATH-NOT: crtfastmath.o
end_comment

begin_comment
comment|// Check that we link in gcrt1.o when compiling with -pg
end_comment

begin_comment
comment|// RUN: %clang -pg --target=x86_64-unknown-linux -### %s \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_linux_tree 2>& 1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PG %s
end_comment

begin_comment
comment|// CHECK-PG: gcrt1.o
end_comment

end_unit

