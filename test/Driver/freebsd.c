begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: ppc32-registered-target,ppc64-registered-target
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs powerpc -no-canonical-prefixes \
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
comment|// CHECK-PPC: clang{{.*}}" "-cc1" "-triple" "powerpc-pc-freebsd8"
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
comment|// RUN: %clang  -ccc-clang-archs powerpc64 -no-canonical-prefixes \
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
comment|// CHECK-PPC64: clang{{.*}}" "-cc1" "-triple" "powerpc64-pc-freebsd8"
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
comment|// CHECK-LIB32: clang{{.*}}" "-cc1" "-triple" "i386-pc-freebsd8"
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

end_unit

