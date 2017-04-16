begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD %s
end_comment

begin_comment
comment|// CHECK-LD: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// Check for --eh-frame-hdr being passed with static linking
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -static %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-STATIC-EH %s
end_comment

begin_comment
comment|// CHECK-LD-STATIC-EH: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-STATIC-EH: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bstatic" "-o" "a.out" "{{.*}}rcrt0.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -pg -pthread %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PG %s
end_comment

begin_comment
comment|// CHECK-PG: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-PG: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}gcrt0.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-lgcc" "-lpthread_p" "-lc_p" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// Check CPU type for MIPS64
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-openbsd -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-MIPS64-CPU %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-openbsd -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-MIPS64EL-CPU %s
end_comment

begin_comment
comment|// CHECK-MIPS64-CPU: "-target-cpu" "mips3"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-CPU: "-target-cpu" "mips3"
end_comment

begin_comment
comment|// Check that the new linker flags are passed to OpenBSD
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -r %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-R %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -s %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-S %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -t %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-T %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -Z %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-Z %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target mips64-unknown-openbsd %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64-LD %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target mips64el-unknown-openbsd %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS64EL-LD %s
end_comment

begin_comment
comment|// CHECK-LD-R: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-R: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-r" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-LD-S: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-S: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-s" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-LD-T: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-T: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-t" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-LD-Z: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-Z: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-Z" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-MIPS64-LD: clang{{.*}}" "-cc1" "-triple" "mips64-unknown-openbsd"
end_comment

begin_comment
comment|// CHECK-MIPS64-LD: ld{{.*}}" "-EB" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-LD: clang{{.*}}" "-cc1" "-triple" "mips64el-unknown-openbsd"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-LD: ld{{.*}}" "-EL" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// Check passing options to the assembler for various OpenBSD targets
end_comment

begin_comment
comment|// RUN: %clang -target amd64-pc-openbsd -m32 -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AMD64-M32 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-openbsd -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-POWERPC %s
end_comment

begin_comment
comment|// RUN: %clang -target sparc-unknown-openbsd -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-SPARC %s
end_comment

begin_comment
comment|// RUN: %clang -target sparc64-unknown-openbsd -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-SPARC64 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-openbsd -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-MIPS64 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-openbsd -fPIC -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-MIPS64-PIC %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-openbsd -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-MIPS64EL %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-openbsd -fPIC -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-MIPS64EL-PIC %s
end_comment

begin_comment
comment|// CHECK-AMD64-M32: as{{.*}}" "--32"
end_comment

begin_comment
comment|// CHECK-POWERPC: as{{.*}}" "-mppc" "-many"
end_comment

begin_comment
comment|// CHECK-SPARC: as{{.*}}" "-32" "-Av8"
end_comment

begin_comment
comment|// CHECK-SPARC64: as{{.*}}" "-64" "-Av9"
end_comment

begin_comment
comment|// CHECK-MIPS64: as{{.*}}" "-mabi" "64" "-EB"
end_comment

begin_comment
comment|// CHECK-MIPS64-PIC: as{{.*}}" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|// CHECK-MIPS64EL: as{{.*}}" "-mabi" "64" "-EL"
end_comment

begin_comment
comment|// CHECK-MIPS64EL-PIC: as{{.*}}" "-mabi" "64" "-EL" "-KPIC"
end_comment

begin_comment
comment|// Check linking against correct startup code when (not) using PIE
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd %s -fno-pie %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -static %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-STATIC-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -static -fno-pie %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-STATIC-PIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -nopie %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-NOPIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -fno-pie -nopie %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-NOPIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -static -nopie %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-NOPIE %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -fno-pie -static -nopie %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-NOPIE %s
end_comment

begin_comment
comment|// CHECK-PIE: "{{.*}}crt0.o"
end_comment

begin_comment
comment|// CHECK-PIE-NOT: "-nopie"
end_comment

begin_comment
comment|// CHECK-STATIC-PIE: "{{.*}}rcrt0.o"
end_comment

begin_comment
comment|// CHECK-STATIC-PIE-NOT: "-nopie"
end_comment

begin_comment
comment|// CHECK-NOPIE: "-nopie" "{{.*}}crt0.o"
end_comment

begin_comment
comment|// Check ARM float ABI
end_comment

begin_comment
comment|// RUN: %clang -target arm-unknown-openbsd -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-FLOAT-ABI %s
end_comment

begin_comment
comment|// CHECK-ARM-FLOAT-ABI: "-mfloat-abi" "soft"
end_comment

end_unit

