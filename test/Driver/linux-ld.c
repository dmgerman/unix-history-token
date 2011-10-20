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
comment|// RUN:     -ccc-host-triple i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-32 %s
end_comment

begin_comment
comment|// CHECK-LD-32: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-LD-32: "{{.*}}/usr/lib/gcc/i386-unknown-linux/4.6.0/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64 %s
end_comment

begin_comment
comment|// CHECK-LD-64: "{{.*}}ld{{(.exe)?}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-LD-64: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/crtbegin.o"
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
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -ccc-host-triple i386-unknown-linux -m32 \
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
comment|// CHECK-32-TO-32: "{{.*}}/usr/lib/gcc/i386-unknown-linux/4.6.0/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple i386-unknown-linux -m64 \
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
comment|// CHECK-32-TO-64: "{{.*}}/usr/lib/gcc/i386-unknown-linux/4.6.0/64/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple x86_64-unknown-linux -m64 \
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
comment|// CHECK-64-TO-64: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple x86_64-unknown-linux -m32 \
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
comment|// CHECK-64-TO-32: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/32/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple i386-unknown-linux -m32 \
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
comment|// CHECK-INSTALL-DIR-32: "{{.*}}/Inputs/fake_install_tree/bin/../lib/gcc/i386-unknown-linux/4.7.0/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple x86_64-unknown-linux -m64 \
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
comment|// CHECK-INSTALL-DIR-64: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/crtbegin.o"
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
comment|// RUN:     -ccc-host-triple i386-unknown-linux -m32 \
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
comment|// CHECK-GCC-VERSION1: "{{.*}}/Inputs/gcc_version_parsing1/bin/../lib/gcc/i386-unknown-linux/4.7/crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION1: "-L{{.*}}/Inputs/gcc_version_parsing1/bin/../lib/gcc/i386-unknown-linux/4.7"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -ccc-host-triple i386-unknown-linux -m32 \
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
comment|// CHECK-GCC-VERSION2: "{{.*}}/Inputs/gcc_version_parsing2/bin/../lib/gcc/i386-unknown-linux/4.7.x/crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION2: "-L{{.*}}/Inputs/gcc_version_parsing2/bin/../lib/gcc/i386-unknown-linux/4.7.x"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -ccc-host-triple i386-unknown-linux -m32 \
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
comment|// CHECK-GCC-VERSION3: "{{.*}}/Inputs/gcc_version_parsing3/bin/../lib/gcc/i386-unknown-linux/4.7.99-rc5/crtbegin.o"
end_comment

begin_comment
comment|// CHECK-GCC-VERSION3: "-L{{.*}}/Inputs/gcc_version_parsing3/bin/../lib/gcc/i386-unknown-linux/4.7.99-rc5"
end_comment

end_unit

