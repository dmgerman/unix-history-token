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
comment|// RUN:     -target i386-unknown-linux \
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
comment|// RUN:     -target x86_64-unknown-linux \
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
comment|// RUN:     -target i386-unknown-linux -m32 \
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
comment|// RUN:     -target i386-unknown-linux -m64 \
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
comment|// RUN:     -target x86_64-unknown-linux -m64 \
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
comment|// RUN:     -target x86_64-unknown-linux -m32 \
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
comment|// RUN:     -target x86_64-unknown-linux -m32 \
end_comment

begin_comment
comment|// RUN:     -gcc-toolchain %S/Inputs/multilib_64bit_linux_tree/usr \
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
comment|// CHECK-64-TO-32-SYSROOT: "{{.*}}/usr/lib/gcc/x86_64-unknown-linux/4.6.0/32/crtbegin.o"
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
comment|// RUN:     -target i386-unknown-linux -m32 \
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
comment|// RUN:     -target x86_64-unknown-linux -m64 \
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
comment|// RUN:     -target i386-unknown-linux -m32 \
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
comment|// RUN:     -target i386-unknown-linux -m32 \
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
comment|// RUN:     -target i386-unknown-linux -m32 \
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

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -m32 \
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
comment|// CHECK-GCC-VERSION4: "{{.*}}/Inputs/gcc_version_parsing4/bin/../lib/gcc/i386-unknown-linux/4.7.99/crtbegin.o"
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
comment|// RUN:     -target i386-unknown-linux \
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
comment|// CHECK-UBUNTU-11-04: "{{.*}}/usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5/crtbegin.o"
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
comment|// Test the setup that shipped in SUSE 10.3 on ppc64.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target powerpc64-suse-linux \
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
comment|// CHECK-SUSE-10-3-PPC64: "{{.*}}/usr/lib/gcc/powerpc64-suse-linux/4.1.2/64/crtbegin.o"
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
comment|// RUN:     -target mips-linux-gnu -ccc-clang-archs mips \
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
comment|// RUN:     -target mipsel-linux-gnu -ccc-clang-archs mipsel \
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
comment|// RUN:     -target mips64-linux-gnu -ccc-clang-archs mips64 \
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
comment|// RUN:     -target mips64el-linux-gnu -ccc-clang-archs mips64el \
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
comment|//
end_comment

begin_comment
comment|// Thoroughly exercise the Debian multiarch environment.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i686-linux-gnu \
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
comment|// CHECK-DEBIAN-X86: "{{.*}}/usr/lib/gcc/i686-linux-gnu/4.5/crtbegin.o"
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
comment|// RUN:     -target x86_64-linux-gnu \
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
comment|// CHECK-DEBIAN-X86-64: "{{.*}}/usr/lib/gcc/x86_64-linux-gnu/4.5/crtbegin.o"
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
comment|// RUN:     -target powerpc-linux-gnu \
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
comment|// CHECK-DEBIAN-PPC: "{{.*}}/usr/lib/gcc/powerpc-linux-gnu/4.5/crtbegin.o"
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
comment|// RUN:     -target powerpc64-linux-gnu \
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
comment|// CHECK-DEBIAN-PPC64: "{{.*}}/usr/lib/gcc/powerpc64-linux-gnu/4.5/crtbegin.o"
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
comment|//
end_comment

end_unit

