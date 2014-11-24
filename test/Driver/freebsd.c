begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes \
end_comment

begin_comment
comment|// RUN:   -target powerpc-pc-freebsd8 %s    \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/basic_freebsd_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PPC %s
end_comment

begin_comment
comment|// CHECK-PPC: "-cc1" "-triple" "powerpc-pc-freebsd8"
end_comment

begin_comment
comment|// CHECK-PPC: ld{{.*}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-PPC: "--eh-frame-hdr" "-dynamic-linker" "{{.*}}ld-elf{{.*}}" "-o" "a.out" "{{.*}}crt1.o" "{{.*}}crti.o" "{{.*}}crtbegin.o" "-L[[SYSROOT]]/usr/lib" "{{.*}}.o" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "{{.*}}crtend.o" "{{.*}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes \
end_comment

begin_comment
comment|// RUN:   -target powerpc64-pc-freebsd8 %s                              \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/basic_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PPC64 %s
end_comment

begin_comment
comment|// CHECK-PPC64: "-cc1" "-triple" "powerpc64-pc-freebsd8"
end_comment

begin_comment
comment|// CHECK-PPC64: ld{{.*}}" "--sysroot=[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-PPC64: "--eh-frame-hdr" "-dynamic-linker" "{{.*}}ld-elf{{.*}}" "-o" "a.out" "{{.*}}crt1.o" "{{.*}}crti.o" "{{.*}}crtbegin.o" "-L[[SYSROOT]]/usr/lib" "{{.*}}.o" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "{{.*}}crtend.o" "{{.*}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that -m32 properly adjusts the toolchain flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd8 -m32 %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LIB32 %s
end_comment

begin_comment
comment|// CHECK-LIB32: "-cc1" "-triple" "i386-pc-freebsd8"
end_comment

begin_comment
comment|// CHECK-LIB32: ld{{.*}}" {{.*}} "-m" "elf_i386_fbsd"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-freebsd8 -m32 %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -print-search-dirs 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LIB32PATHS %s
end_comment

begin_comment
comment|// CHECK-LIB32PATHS: libraries: ={{.*:?}}/usr/lib32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that the new linker flags are passed to FreeBSD
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd8 -m32 %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LDFLAGS8 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd9 -m32 %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LDFLAGS9 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd10.0 -m32 %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LDFLAGS9 %s
end_comment

begin_comment
comment|// CHECK-LDFLAGS8-NOT: --hash-style=both
end_comment

begin_comment
comment|// CHECK-LDFLAGS8: --enable-new-dtags
end_comment

begin_comment
comment|// CHECK-LDFLAGS9: --hash-style=both
end_comment

begin_comment
comment|// CHECK-LDFLAGS9: --enable-new-dtags
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that we do not pass --hash-style=gnu and --hash-style=both to linker
end_comment

begin_comment
comment|// and provide correct path to the dynamic linker for MIPS platforms.
end_comment

begin_comment
comment|// Also verify that we tell the assembler to target the right ISA and ABI.
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-unknown-freebsd10.0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS %s
end_comment

begin_comment
comment|// CHECK-MIPS: "{{[^" ]*}}ld{{[^" ]*}}"
end_comment

begin_comment
comment|// CHECK-MIPS: "-dynamic-linker" "{{.*}}/libexec/ld-elf.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mipsel-unknown-freebsd10.0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPSEL %s
end_comment

begin_comment
comment|// CHECK-MIPSEL: "{{[^" ]*}}ld{{[^" ]*}}"
end_comment

begin_comment
comment|// CHECK-MIPSEL: "-dynamic-linker" "{{.*}}/libexec/ld-elf.so.1"
end_comment

begin_comment
comment|// CHECK-MIPSEL-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips64-unknown-freebsd10.0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64 %s
end_comment

begin_comment
comment|// CHECK-MIPS64: "{{[^" ]*}}ld{{[^" ]*}}"
end_comment

begin_comment
comment|// CHECK-MIPS64: "-dynamic-linker" "{{.*}}/libexec/ld-elf.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS64-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips64el-unknown-freebsd10.0 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64EL %s
end_comment

begin_comment
comment|// CHECK-MIPS64EL: "{{[^" ]*}}ld{{[^" ]*}}"
end_comment

begin_comment
comment|// CHECK-MIPS64EL: "-dynamic-linker" "{{.*}}/libexec/ld-elf.so.1"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-NOT: "--hash-style={{gnu|both}}"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd8 -static %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-STATIC %s
end_comment

begin_comment
comment|// CHECK-STATIC: crt1.o
end_comment

begin_comment
comment|// CHECK-STATIC: crtbeginT.o
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd8 -shared %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SHARED %s
end_comment

begin_comment
comment|// CHECK-SHARED: crti.o
end_comment

begin_comment
comment|// CHECK-SHARED: crtbeginS.o
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd8 -pie %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PIE %s
end_comment

begin_comment
comment|// CHECK-PIE: pie
end_comment

begin_comment
comment|// CHECK-PIE: Scrt1.o
end_comment

begin_comment
comment|// CHECK-PIE: crtbeginS.o
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-freebsd8 %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/multiarch_freebsd64_tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NORMAL %s
end_comment

begin_comment
comment|// CHECK-NORMAL: crt1.o
end_comment

begin_comment
comment|// CHECK-NORMAL: crtbegin.o
end_comment

begin_comment
comment|// RUN: %clang %s -### -target arm-unknown-freebsd10.0 -no-integrated-as 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_comment
comment|// CHECK-ARM: "-cc1"{{.*}}" "-fsjlj-exceptions"
end_comment

begin_comment
comment|// CHECK-ARM: as{{.*}}" "-mfpu=softvfp"{{.*}}"-matpcs"
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NOT: as{{.*}}" "-mfpu=vfp"
end_comment

begin_comment
comment|// RUN: %clang %s -### -target arm-gnueabi-freebsd10.0 -no-integrated-as 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM-EABI %s
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NOT: "-cc1"{{.*}}" "-fsjlj-exceptions"
end_comment

begin_comment
comment|// CHECK-ARM-EABI: as{{.*}}" "-mfpu=softvfp" "-meabi=5"
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NOT: as{{.*}}" "-mfpu=vfp"
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NOT: as{{.*}}" "-matpcs"
end_comment

begin_comment
comment|// RUN: %clang %s -### -target arm-gnueabihf-freebsd10.0 -no-integrated-as 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ARM-EABIHF %s
end_comment

begin_comment
comment|// CHECK-ARM-EABIHF-NOT: "-cc1"{{.*}}" "-fsjlj-exceptions"
end_comment

begin_comment
comment|// CHECK-ARM-EABIHF: as{{.*}}" "-mfpu=vfp" "-meabi=5"
end_comment

begin_comment
comment|// CHECK-ARM-EABIHF-NOT: as{{.*}}" "-mfpu=softvfp"
end_comment

begin_comment
comment|// CHECK-ARM-EABIHF-NOT: as{{.*}}" "-matpcs"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-freebsd8 %s -### -flto 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LTO %s
end_comment

begin_comment
comment|// CHECK-LTO: ld{{.*}}" "-plugin{{.*}}LLVMgold.so
end_comment

begin_comment
comment|// RUN: %clang -target sparc-unknown-freebsd8 %s -### -fpic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SPARC-PIE %s
end_comment

begin_comment
comment|// CHECK-SPARC-PIE: as{{.*}}" "-KPIC
end_comment

begin_comment
comment|// RUN: %clang -mcpu=ultrasparc -target sparc64-unknown-freebsd8 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SPARC-CPU %s
end_comment

begin_comment
comment|// CHECK-SPARC-CPU: cc1{{.*}}" "-target-cpu" "ultrasparc"
end_comment

begin_comment
comment|// CHECK-SPARC-CPU: as{{.*}}" "-Av9a
end_comment

end_unit

