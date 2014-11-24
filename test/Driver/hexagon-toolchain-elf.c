begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Test standard include paths
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK001 %s
end_comment

begin_comment
comment|// CHECK001: "-cc1" {{.*}} "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include"
end_comment

begin_comment
comment|// CHECK001:   "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include-fixed"
end_comment

begin_comment
comment|// CHECK001:   "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include"
end_comment

begin_comment
comment|// CHECK001-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK002 %s
end_comment

begin_comment
comment|// CHECK002: "-cc1" {{.*}} "-internal-isystem" "[[INSTALL_DIR:.*]]/Inputs/hexagon_tree/qc/bin/../../gnu{{/|\\\\}}hexagon/include/c++/4.4.0"
end_comment

begin_comment
comment|// CHECK002:   "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include"
end_comment

begin_comment
comment|// CHECK002:   "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include-fixed"
end_comment

begin_comment
comment|// CHECK002:   "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include"
end_comment

begin_comment
comment|// CHECK002-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Test -nostdinc, -nostdlibinc, -nostdinc++
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nostdinc \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK003 %s
end_comment

begin_comment
comment|// CHECK003: "-cc1"
end_comment

begin_comment
comment|// CHECK003-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include"
end_comment

begin_comment
comment|// CHECK003-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include-fixed"
end_comment

begin_comment
comment|// CHECK003-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include"
end_comment

begin_comment
comment|// CHECK003-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nostdlibinc \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK004 %s
end_comment

begin_comment
comment|// CHECK004: "-cc1"
end_comment

begin_comment
comment|// CHECK004-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include"
end_comment

begin_comment
comment|// CHECK004-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include-fixed"
end_comment

begin_comment
comment|// CHECK004-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include"
end_comment

begin_comment
comment|// CHECK004-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nostdlibinc \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK005 %s
end_comment

begin_comment
comment|// CHECK005: "-cc1"
end_comment

begin_comment
comment|// CHECK005-NOT: "-internal-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include/c++/4.4.0"
end_comment

begin_comment
comment|// CHECK005-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include"
end_comment

begin_comment
comment|// CHECK005-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/lib/gcc/hexagon/4.4.0/include-fixed"
end_comment

begin_comment
comment|// CHECK005-NOT: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include"
end_comment

begin_comment
comment|// CHECK005-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nostdinc++ \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK006 %s
end_comment

begin_comment
comment|// CHECK006: "-cc1"
end_comment

begin_comment
comment|// CHECK006-NOT: "-internal-isystem" "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/hexagon/include/c++/4.4.0"
end_comment

begin_comment
comment|// CHECK006-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Test -march=<archname> -mcpu=<archname> -mv<number>
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -march=hexagonv3 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK007 %s
end_comment

begin_comment
comment|// CHECK007: "-cc1" {{.*}} "-target-cpu" "hexagonv3"
end_comment

begin_comment
comment|// CHECK007-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"{{.*}} "-march=v3"
end_comment

begin_comment
comment|// CHECK007-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-ld"{{.*}} "-mv3"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv5 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK008 %s
end_comment

begin_comment
comment|// CHECK008: "-cc1" {{.*}} "-target-cpu" "hexagonv5"
end_comment

begin_comment
comment|// CHECK008-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"{{.*}} "-march=v5"
end_comment

begin_comment
comment|// CHECK008-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-ld"{{.*}} "-mv5"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -mv2 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK009 %s
end_comment

begin_comment
comment|// CHECK009: "-cc1" {{.*}} "-target-cpu" "hexagonv2"
end_comment

begin_comment
comment|// CHECK009-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"{{.*}} "-march=v2"
end_comment

begin_comment
comment|// CHECK009-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-ld"{{.*}} "-mv2"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK010 %s
end_comment

begin_comment
comment|// CHECK010: "-cc1" {{.*}} "-target-cpu" "hexagonv4"
end_comment

begin_comment
comment|// CHECK010-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-as"{{.*}} "-march=v4"
end_comment

begin_comment
comment|// CHECK010-NEXT: "{{.*}}/Inputs/hexagon_tree/qc/bin/../../gnu/bin{{/|\\}}hexagon-ld"{{.*}} "-mv4"
end_comment

begin_comment
comment|// RUN: not %clang -march=hexagonv2 -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-V2 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=hexagonv2  -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-V2 %s
end_comment

begin_comment
comment|// RUN: not %clang -mv2             -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-V2 %s
end_comment

begin_comment
comment|// CHECK-UNKNOWN-V2: error: unknown target CPU 'hexagonv2'
end_comment

begin_comment
comment|// RUN: not %clang -march=hexagonv3 -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-V3 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=hexagonv3  -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-V3 %s
end_comment

begin_comment
comment|// RUN: not %clang -mv3             -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-V3 %s
end_comment

begin_comment
comment|// CHECK-UNKNOWN-V3: error: unknown target CPU 'hexagonv3'
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Test Linker related args
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// Defaults for C
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK011 %s
end_comment

begin_comment
comment|// CHECK011: "-cc1"
end_comment

begin_comment
comment|// CHECK011-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK011-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK011-NOT: "-static"
end_comment

begin_comment
comment|// CHECK011-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK011: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK011: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK011: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK011: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK011: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK011: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK011: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK011: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK011: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK011: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK011: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// Defaults for C++
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK012 %s
end_comment

begin_comment
comment|// CHECK012: "-cc1"
end_comment

begin_comment
comment|// CHECK012-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK012-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK012-NOT: "-static"
end_comment

begin_comment
comment|// CHECK012-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK012: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK012: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK012: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK012: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK012: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK012: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK012: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK012: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK012: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK012: "-lstdc++" "-lm"
end_comment

begin_comment
comment|// CHECK012: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK012: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// Additional Libraries (-L)
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -Lone -L two -L three \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK013 %s
end_comment

begin_comment
comment|// CHECK013: "-cc1"
end_comment

begin_comment
comment|// CHECK013-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK013-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK013: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK013: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK013: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK013: "-Lone" "-Ltwo" "-Lthree"
end_comment

begin_comment
comment|// CHECK013: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK013: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK013: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK013: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK013: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK013: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK013: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK013: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// -static, -shared
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -static \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK014 %s
end_comment

begin_comment
comment|// CHECK014: "-cc1"
end_comment

begin_comment
comment|// CHECK014-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK014-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK014: "-static"
end_comment

begin_comment
comment|// CHECK014: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK014: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK014: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK014: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK014: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK014: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK014: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK014: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK014: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK014: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK014: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -shared \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK015 %s
end_comment

begin_comment
comment|// CHECK015: "-cc1"
end_comment

begin_comment
comment|// CHECK015-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK015-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK015: "-shared" "-call_shared"
end_comment

begin_comment
comment|// CHECK015-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK015-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK015: "{{.*}}/hexagon/lib/v4/G0/initS.o"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4/G0"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/lib/gcc/hexagon/4.4.0/G0"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/hexagon/lib/v4/G0"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/hexagon/lib/G0"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK015: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK015: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK015: "--start-group"
end_comment

begin_comment
comment|// CHECK015-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK015-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK015: "-lgcc"
end_comment

begin_comment
comment|// CHECK015: "--end-group"
end_comment

begin_comment
comment|// CHECK015: "{{.*}}/hexagon/lib/v4/G0/finiS.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -shared \
end_comment

begin_comment
comment|// RUN:   -static \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK016 %s
end_comment

begin_comment
comment|// CHECK016: "-cc1"
end_comment

begin_comment
comment|// CHECK016-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK016-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK016: "-shared" "-call_shared" "-static"
end_comment

begin_comment
comment|// CHECK016-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK016-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK016: "{{.*}}/hexagon/lib/v4/G0/init.o"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4/G0"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/lib/gcc/hexagon/4.4.0/G0"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/hexagon/lib/v4/G0"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/hexagon/lib/G0"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK016: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK016: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK016: "--start-group"
end_comment

begin_comment
comment|// CHECK016-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK016-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK016: "-lgcc"
end_comment

begin_comment
comment|// CHECK016: "--end-group"
end_comment

begin_comment
comment|// CHECK016: "{{.*}}/hexagon/lib/v4/G0/fini.o"
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// -nostdlib, -nostartfiles, -nodefaultlibs
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nostdlib \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK017 %s
end_comment

begin_comment
comment|// CHECK017: "-cc1"
end_comment

begin_comment
comment|// CHECK017-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK017-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK017-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK017-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK017-NOT: init.o
end_comment

begin_comment
comment|// CHECK017: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK017: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK017: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK017: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK017: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK017: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK017-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK017-NOT: "-lm"
end_comment

begin_comment
comment|// CHECK017-NOT: "--start-group"
end_comment

begin_comment
comment|// CHECK017-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK017-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK017-NOT: "-lgcc"
end_comment

begin_comment
comment|// CHECK017-NOT: "--end-group"
end_comment

begin_comment
comment|// CHECK017-NOT: fini.o
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nostartfiles \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK018 %s
end_comment

begin_comment
comment|// CHECK018: "-cc1"
end_comment

begin_comment
comment|// CHECK018-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK018-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK018-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK018-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK018-NOT: init.o
end_comment

begin_comment
comment|// CHECK018: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK018: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK018: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK018: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK018: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK018: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK018: "-lstdc++"
end_comment

begin_comment
comment|// CHECK018: "-lm"
end_comment

begin_comment
comment|// CHECK018: "--start-group"
end_comment

begin_comment
comment|// CHECK018: "-lstandalone"
end_comment

begin_comment
comment|// CHECK018: "-lc"
end_comment

begin_comment
comment|// CHECK018: "-lgcc"
end_comment

begin_comment
comment|// CHECK018: "--end-group"
end_comment

begin_comment
comment|// CHECK018-NOT: fini.o
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -nodefaultlibs \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK019 %s
end_comment

begin_comment
comment|// CHECK019: "-cc1"
end_comment

begin_comment
comment|// CHECK019-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK019-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK019: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK019: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK019: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK019: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK019: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK019: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK019: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK019: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK019: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK019-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK019-NOT: "-lm"
end_comment

begin_comment
comment|// CHECK019-NOT: "--start-group"
end_comment

begin_comment
comment|// CHECK019-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK019-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK019-NOT: "-lgcc"
end_comment

begin_comment
comment|// CHECK019-NOT: "--end-group"
end_comment

begin_comment
comment|// CHECK019: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// -moslib
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -moslib=first -moslib=second \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK020 %s
end_comment

begin_comment
comment|// CHECK020: "-cc1"
end_comment

begin_comment
comment|// CHECK020-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK020-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK020-NOT: "-static"
end_comment

begin_comment
comment|// CHECK020-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK020-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK020: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK020: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK020: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK020: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK020: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK020: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK020: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK020: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK020: "--start-group"
end_comment

begin_comment
comment|// CHECK020: "-lfirst" "-lsecond"
end_comment

begin_comment
comment|// CHECK020-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK020: "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK020: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -moslib=first -moslib=second -moslib=standalone\
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK021 %s
end_comment

begin_comment
comment|// CHECK021: "-cc1"
end_comment

begin_comment
comment|// CHECK021-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK021-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK021-NOT: "-static"
end_comment

begin_comment
comment|// CHECK021-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK021: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK021: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK021: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK021: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK021: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK021: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK021: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK021: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK021: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK021: "--start-group"
end_comment

begin_comment
comment|// CHECK021: "-lfirst" "-lsecond"
end_comment

begin_comment
comment|// CHECK021: "-lstandalone"
end_comment

begin_comment
comment|// CHECK021: "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK021: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// Other args to pass to linker
end_comment

begin_comment
comment|// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -s \
end_comment

begin_comment
comment|// RUN:   -Tbss 0xdead -Tdata 0xbeef -Ttext 0xcafe \
end_comment

begin_comment
comment|// RUN:   -t \
end_comment

begin_comment
comment|// RUN:   -e start_here \
end_comment

begin_comment
comment|// RUN:   -uFoo -undefined Bar \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK022 %s
end_comment

begin_comment
comment|// CHECK022: "-cc1"
end_comment

begin_comment
comment|// CHECK022-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"{{.*}}
end_comment

begin_comment
comment|// CHECK022-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK022: "{{.*}}/hexagon/lib/v4/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK022: "{{.*}}/hexagon/lib/v4/crt0.o"
end_comment

begin_comment
comment|// CHECK022: "{{.*}}/hexagon/lib/v4/init.o"
end_comment

begin_comment
comment|// CHECK022: "-L{{.*}}/lib/gcc/hexagon/4.4.0/v4"
end_comment

begin_comment
comment|// CHECK022: "-L{{.*}}/lib/gcc/hexagon/4.4.0"
end_comment

begin_comment
comment|// CHECK022: "-L{{.*}}/lib/gcc"
end_comment

begin_comment
comment|// CHECK022: "-L{{.*}}/hexagon/lib/v4"
end_comment

begin_comment
comment|// CHECK022: "-L{{.*}}/hexagon/lib"
end_comment

begin_comment
comment|// CHECK022: "-Tbss" "0xdead" "-Tdata" "0xbeef" "-Ttext" "0xcafe"
end_comment

begin_comment
comment|// CHECK022: "-s"
end_comment

begin_comment
comment|// CHECK022: "-t"
end_comment

begin_comment
comment|// CHECK022: "-u" "Foo" "-undefined" "Bar"
end_comment

begin_comment
comment|// CHECK022: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK022: "-lstdc++" "-lm"
end_comment

begin_comment
comment|// CHECK022: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK022: "{{.*}}/hexagon/lib/v4/fini.o"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// pic, small data threshold
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK023 %s
end_comment

begin_comment
comment|// CHECK023:      "-cc1"
end_comment

begin_comment
comment|// CHECK023:        "-mrelocation-model" "static"
end_comment

begin_comment
comment|// CHECK023-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK023-NOT:    "-G{{[0-9]+}}"
end_comment

begin_comment
comment|// CHECK023-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK023-NOT:    "-G{{[0-9]+}}"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -fpic \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK024 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -fPIC \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK024 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -fPIC \
end_comment

begin_comment
comment|// RUN:   -msmall-data-threshold=8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK024 %s
end_comment

begin_comment
comment|// CHECK024:      "-cc1"
end_comment

begin_comment
comment|// CHECK024-NOT:    "-mrelocation-model" "static"
end_comment

begin_comment
comment|// CHECK024:        "-pic-level" "{{[12]}}"
end_comment

begin_comment
comment|// CHECK024:        "-mllvm" "-hexagon-small-data-threshold=0"
end_comment

begin_comment
comment|// CHECK024-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK024:        "-G0"
end_comment

begin_comment
comment|// CHECK024-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK024:        "-G0"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -G=8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK025 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -G 8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK025 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -msmall-data-threshold=8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK025 %s
end_comment

begin_comment
comment|// CHECK025:      "-cc1"
end_comment

begin_comment
comment|// CHECK025:        "-mrelocation-model" "static"
end_comment

begin_comment
comment|// CHECK025:        "-mllvm" "-hexagon-small-data-threshold=8"
end_comment

begin_comment
comment|// CHECK025-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK025:        "-G8"
end_comment

begin_comment
comment|// CHECK025-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK025:        "-G8"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// pie
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -pie \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK026 %s
end_comment

begin_comment
comment|// CHECK026:      "-cc1"
end_comment

begin_comment
comment|// CHECK026-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK026-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK026:        "-pie"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -pie -shared \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK027 %s
end_comment

begin_comment
comment|// CHECK027:      "-cc1"
end_comment

begin_comment
comment|// CHECK027-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK027-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// CHECK027-NOT:    "-pie"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Misc Defaults
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK028 %s
end_comment

begin_comment
comment|// CHECK028:      "-cc1"
end_comment

begin_comment
comment|// CHECK028:        "-mqdsp6-compat"
end_comment

begin_comment
comment|// CHECK028:        "-Wreturn-type"
end_comment

begin_comment
comment|// CHECK028-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK028-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Test Assembler related args
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf     \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   -gdwarf-2 \
end_comment

begin_comment
comment|// RUN:   -Wa,--noexecstack,--trap \
end_comment

begin_comment
comment|// RUN:   -Xassembler --keep-locals \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK029 %s
end_comment

begin_comment
comment|// CHECK029:      "-cc1"
end_comment

begin_comment
comment|// CHECK029-NEXT: "{{.*}}/bin{{/|\\}}hexagon-as"
end_comment

begin_comment
comment|// CHECK029:      "--noexecstack" "--trap" "--keep-locals"
end_comment

begin_comment
comment|// CHECK029-NEXT: "{{.*}}/bin{{/|\\}}hexagon-ld"
end_comment

end_unit

