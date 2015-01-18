begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/basic_cross_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=i386-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-I386 %s
end_comment

begin_comment
comment|// CHECK-I386: "-cc1" "-triple" "i386-unknown-linux-gnu"
end_comment

begin_comment
comment|// CHECK-I386: "{{.*}}/Inputs/basic_cross_linux_tree/usr/lib/gcc/i386-unknown-linux-gnu/4.6.0/../../../../i386-unknown-linux-gnu/bin{{/|\\\\}}as" "--32"
end_comment

begin_comment
comment|// CHECK-I386: "{{.*}}/Inputs/basic_cross_linux_tree/usr/lib/gcc/i386-unknown-linux-gnu/4.6.0/../../../../i386-unknown-linux-gnu/bin{{/|\\\\}}ld" {{.*}} "-m" "elf_i386"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/basic_cross_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=x86_64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-X86-64 %s
end_comment

begin_comment
comment|// CHECK-X86-64: "-cc1" "-triple" "x86_64-unknown-linux-gnu"
end_comment

begin_comment
comment|// CHECK-X86-64: "{{.*}}/Inputs/basic_cross_linux_tree/usr/lib/gcc/x86_64-unknown-linux-gnu/4.6.0/../../../../x86_64-unknown-linux-gnu/bin{{/|\\\\}}as" "--64"
end_comment

begin_comment
comment|// CHECK-X86-64: "{{.*}}/Inputs/basic_cross_linux_tree/usr/lib/gcc/x86_64-unknown-linux-gnu/4.6.0/../../../../x86_64-unknown-linux-gnu/bin{{/|\\\\}}ld" {{.*}} "-m" "elf_x86_64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/basic_cross_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=x86_64-unknown-linux-gnux32 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-X32 %s
end_comment

begin_comment
comment|// CHECK-X32: "-cc1" "-triple" "x86_64-unknown-linux-gnux32"
end_comment

begin_comment
comment|// CHECK-X32: "{{.*}}/Inputs/basic_cross_linux_tree/usr/lib/gcc/x86_64-unknown-linux-gnu/4.6.0/../../../../x86_64-unknown-linux-gnu/bin{{/|\\\\}}as" "--x32"
end_comment

begin_comment
comment|// CHECK-X32: "{{.*}}/Inputs/basic_cross_linux_tree/usr/lib/gcc/x86_64-unknown-linux-gnu/4.6.0/../../../../x86_64-unknown-linux-gnu/bin{{/|\\\\}}ld" {{.*}} "-m" "elf32_x86_64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/basic_cross_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=x86_64-unknown-linux-gnu -m32 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-I386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/basic_cross_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=i386-unknown-linux-gnu -m64 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-X86-64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/multilib_32bit_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MULTI32-I386 %s
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-cc1" "-triple" "i386-unknown-linux"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "{{.*}}/Inputs/multilib_32bit_linux_tree/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/bin{{/|\\\\}}as" "--32"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "{{.*}}/Inputs/multilib_32bit_linux_tree/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/bin{{/|\\\\}}ld"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "--sysroot=[[sysroot:.*/Inputs/basic_linux_tree]]"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-m" "elf_i386"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "crti.o" "[[gcc_install:.*/Inputs/multilib_32bit_linux_tree/usr/lib/gcc/i386-unknown-linux/4.6.0]]{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-L[[gcc_install]]"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-L[[gcc_install]]/../../../../i386-unknown-linux/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-L[[gcc_install]]/../../../../i386-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-L[[sysroot]]/lib"
end_comment

begin_comment
comment|// CHECK-MULTI32-I386: "-L[[sysroot]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/multilib_32bit_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MULTI32-X86-64 %s
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-cc1" "-triple" "x86_64-unknown-linux"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "{{.*}}/Inputs/multilib_32bit_linux_tree/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/bin{{/|\\\\}}as" "--64"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "{{.*}}/Inputs/multilib_32bit_linux_tree/usr/lib/gcc/i386-unknown-linux/4.6.0/../../../../i386-unknown-linux/bin{{/|\\\\}}ld"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "--sysroot=[[sysroot:.*/Inputs/basic_linux_tree]]"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-m" "elf_x86_64"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "crti.o" "[[gcc_install:.*/Inputs/multilib_32bit_linux_tree/usr/lib/gcc/i386-unknown-linux/4.6.0]]/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-L[[gcc_install]]/64"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-L[[gcc_install]]/../../../../i386-unknown-linux/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-L[[gcc_install]]"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-L[[gcc_install]]/../../../../i386-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-L[[sysroot]]/lib"
end_comment

begin_comment
comment|// CHECK-MULTI32-X86-64: "-L[[sysroot]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/multilib_64bit_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MULTI64-I386 %s
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-cc1" "-triple" "i386-unknown-linux"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "{{.*}}/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/bin{{/|\\\\}}as" "--32"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "{{.*}}/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/bin{{/|\\\\}}ld"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "--sysroot=[[sysroot:.*/Inputs/basic_linux_tree]]"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-m" "elf_i386"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "crti.o" "[[gcc_install:.*/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0]]/32{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-L[[gcc_install]]/32"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-L[[gcc_install]]/../../../../x86_64-unknown-linux/lib/../lib32"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-L[[gcc_install]]"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-L[[gcc_install]]/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-L[[sysroot]]/lib"
end_comment

begin_comment
comment|// CHECK-MULTI64-I386: "-L[[sysroot]]/usr/lib"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -o %t %s 2>&1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain=%S/Inputs/multilib_64bit_linux_tree/usr \
end_comment

begin_comment
comment|// RUN:   --target=x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MULTI64-X86-64 %s
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-cc1" "-triple" "x86_64-unknown-linux"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "{{.*}}/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/bin{{/|\\\\}}as" "--64"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "{{.*}}/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0/../../../../x86_64-unknown-linux/bin{{/|\\\\}}ld"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "--sysroot=[[sysroot:.*/Inputs/basic_linux_tree]]"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-m" "elf_x86_64"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "crti.o" "[[gcc_install:.*/Inputs/multilib_64bit_linux_tree/usr/lib/gcc/x86_64-unknown-linux/4.6.0]]{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-L[[gcc_install]]"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-L[[gcc_install]]/../../../../x86_64-unknown-linux/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-L[[gcc_install]]/../../../../x86_64-unknown-linux/lib"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-L[[sysroot]]/lib"
end_comment

begin_comment
comment|// CHECK-MULTI64-X86-64: "-L[[sysroot]]/usr/lib"
end_comment

end_unit

