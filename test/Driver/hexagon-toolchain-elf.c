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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK000 %s
end_comment

begin_comment
comment|// CHECK000: "-cc1" {{.*}} "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/include"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK001 %s
end_comment

begin_comment
comment|// CHECK001: "-cc1" {{.*}} "-internal-isystem" "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/include/c++"
end_comment

begin_comment
comment|// CHECK001:   "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/include"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -nostdinc \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK010 %s
end_comment

begin_comment
comment|// CHECK010: "-cc1"
end_comment

begin_comment
comment|// CHECK010-NOT: "-internal-externc-isystem"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -nostdlibinc \
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
comment|// CHECK011-NOT: "-internal-externc-isystem"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -nostdinc++ \
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
comment|// CHECK012-NOT: "-internal-isystem"
end_comment

begin_comment
comment|// CHECK012-DAG: "-internal-externc-isystem" "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/include"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf -fno-integrated-as    \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/qc/bin \
end_comment

begin_comment
comment|// RUN:   --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:   -nostdlibinc \
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
comment|// CHECK013-NOT: "-internal-isystem"
end_comment

begin_comment
comment|// CHECK013-NOT: "-internal-externc-isystem"
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// Test -mcpu=<cpuname> -mv<number>
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv4 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK020 %s
end_comment

begin_comment
comment|// CHECK020: "-cc1" {{.*}} "-target-cpu" "hexagonv4"
end_comment

begin_comment
comment|// CHECK020: hexagon-link{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v4/crt0
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv5 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK021 %s
end_comment

begin_comment
comment|// CHECK021: "-cc1" {{.*}} "-target-cpu" "hexagonv5"
end_comment

begin_comment
comment|// CHECK021: hexagon-link{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v5/crt0
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv55 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK022 %s
end_comment

begin_comment
comment|// CHECK022: "-cc1" {{.*}} "-target-cpu" "hexagonv55"
end_comment

begin_comment
comment|// CHECK022: hexagon-link{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v55/crt0
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK023 %s
end_comment

begin_comment
comment|// CHECK023: "-cc1" {{.*}} "-target-cpu" "hexagonv60"
end_comment

begin_comment
comment|// CHECK023: hexagon-link{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv62 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK024 %s
end_comment

begin_comment
comment|// CHECK024: "-cc1" {{.*}} "-target-cpu" "hexagonv62"
end_comment

begin_comment
comment|// CHECK024: hexagon-link{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v62/crt0
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -O3 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK025 %s
end_comment

begin_comment
comment|// CHECK025: "-ffp-contract=fast"
end_comment

begin_comment
comment|// CHECK025: hexagon-link
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -O3 -ffp-contract=off \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK026 %s
end_comment

begin_comment
comment|// CHECK026-NOT: "-ffp-contract=fast"
end_comment

begin_comment
comment|// CHECK026: hexagon-link
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK030 %s
end_comment

begin_comment
comment|// CHECK030: "-cc1"
end_comment

begin_comment
comment|// CHECK030-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK030-NOT: "-static"
end_comment

begin_comment
comment|// CHECK030-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK030: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK030: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK030: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK030: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK030: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK030: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK030: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK030: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
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
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK031 %s
end_comment

begin_comment
comment|// CHECK031: "-cc1"
end_comment

begin_comment
comment|// CHECK031-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK031-NOT: "-static"
end_comment

begin_comment
comment|// CHECK031-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK031: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK031: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK031: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK031: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK031: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK031: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK031: "-lstdc++" "-lm"
end_comment

begin_comment
comment|// CHECK031: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK031: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -Lone -L two -L three \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK032 %s
end_comment

begin_comment
comment|// CHECK032: "-cc1"
end_comment

begin_comment
comment|// CHECK032-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK032-NOT: "-static"
end_comment

begin_comment
comment|// CHECK032-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK032: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK032: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK032: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK032: "-Lone" "-Ltwo" "-Lthree"
end_comment

begin_comment
comment|// CHECK032: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK032: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK032: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK032: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK032: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -static \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK033 %s
end_comment

begin_comment
comment|// CHECK033: "-cc1"
end_comment

begin_comment
comment|// CHECK033-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK033: "-static"
end_comment

begin_comment
comment|// CHECK033: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK033: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK033: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK033: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK033: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK033: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK033: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK033: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -shared \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK034 %s
end_comment

begin_comment
comment|// CHECK034: "-cc1"
end_comment

begin_comment
comment|// CHECK034-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK034: "-shared" "-call_shared"
end_comment

begin_comment
comment|// CHECK034-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK034-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK034: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/G0/pic/initS.o"
end_comment

begin_comment
comment|// CHECK034: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/G0"
end_comment

begin_comment
comment|// CHECK034: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK034: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK034: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK034: "--start-group"
end_comment

begin_comment
comment|// CHECK034-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK034-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK034: "-lgcc"
end_comment

begin_comment
comment|// CHECK034: "--end-group"
end_comment

begin_comment
comment|// CHECK034: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/G0/pic/finiS.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
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
comment|// RUN:   | FileCheck -check-prefix=CHECK035 %s
end_comment

begin_comment
comment|// CHECK035: "-cc1"
end_comment

begin_comment
comment|// CHECK035-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK035: "-shared" "-call_shared" "-static"
end_comment

begin_comment
comment|// CHECK035-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK035-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK035: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/G0/init.o"
end_comment

begin_comment
comment|// CHECK035: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/G0"
end_comment

begin_comment
comment|// CHECK035: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK035: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK035: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK035: "--start-group"
end_comment

begin_comment
comment|// CHECK035-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK035-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK035: "-lgcc"
end_comment

begin_comment
comment|// CHECK035: "--end-group"
end_comment

begin_comment
comment|// CHECK035: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/G0/fini.o"
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
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -nostdlib \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK036 %s
end_comment

begin_comment
comment|// CHECK036: "-cc1"
end_comment

begin_comment
comment|// CHECK036-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK036-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK036-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK036-NOT: init.o
end_comment

begin_comment
comment|// CHECK036: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK036: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK036: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK036-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK036-NOT: "-lm"
end_comment

begin_comment
comment|// CHECK036-NOT: "--start-group"
end_comment

begin_comment
comment|// CHECK036-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK036-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK036-NOT: "-lgcc"
end_comment

begin_comment
comment|// CHECK036-NOT: "--end-group"
end_comment

begin_comment
comment|// CHECK036-NOT: fini.o
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -nostartfiles \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK037 %s
end_comment

begin_comment
comment|// CHECK037: "-cc1"
end_comment

begin_comment
comment|// CHECK037-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK037-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK037-NOT: crt0.o
end_comment

begin_comment
comment|// CHECK037-NOT: init.o
end_comment

begin_comment
comment|// CHECK037: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK037: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK037: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK037: "-lstdc++"
end_comment

begin_comment
comment|// CHECK037: "-lm"
end_comment

begin_comment
comment|// CHECK037: "--start-group"
end_comment

begin_comment
comment|// CHECK037: "-lstandalone"
end_comment

begin_comment
comment|// CHECK037: "-lc"
end_comment

begin_comment
comment|// CHECK037: "-lgcc"
end_comment

begin_comment
comment|// CHECK037: "--end-group"
end_comment

begin_comment
comment|// CHECK037-NOT: fini.o
end_comment

begin_comment
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -nodefaultlibs \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK038 %s
end_comment

begin_comment
comment|// CHECK038: "-cc1"
end_comment

begin_comment
comment|// CHECK038-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK038: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK038: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK038: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK038: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK038: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK038: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK038-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK038-NOT: "-lm"
end_comment

begin_comment
comment|// CHECK038-NOT: "--start-group"
end_comment

begin_comment
comment|// CHECK038-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK038-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK038-NOT: "-lgcc"
end_comment

begin_comment
comment|// CHECK038-NOT: "--end-group"
end_comment

begin_comment
comment|// CHECK038: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -moslib=first -moslib=second \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK039 %s
end_comment

begin_comment
comment|// CHECK039: "-cc1"
end_comment

begin_comment
comment|// CHECK039-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK039-NOT: "-static"
end_comment

begin_comment
comment|// CHECK039-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK039-NOT: crt0_standalone.o
end_comment

begin_comment
comment|// CHECK039: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK039: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK039: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK039: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK039: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK039: "--start-group"
end_comment

begin_comment
comment|// CHECK039: "-lfirst" "-lsecond"
end_comment

begin_comment
comment|// CHECK039-NOT: "-lstandalone"
end_comment

begin_comment
comment|// CHECK039: "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK039: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -moslib=first -moslib=second -moslib=standalone \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK03A %s
end_comment

begin_comment
comment|// CHECK03A: "-cc1"
end_comment

begin_comment
comment|// CHECK03A-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK03A-NOT: "-static"
end_comment

begin_comment
comment|// CHECK03A-NOT: "-shared"
end_comment

begin_comment
comment|// CHECK03A: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK03A: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK03A: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK03A: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK03A: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK03A: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK03A: "--start-group"
end_comment

begin_comment
comment|// CHECK03A: "-lfirst" "-lsecond"
end_comment

begin_comment
comment|// CHECK03A: "-lstandalone"
end_comment

begin_comment
comment|// CHECK03A: "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK03A: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
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
comment|// RUN: %clangxx -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
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
comment|// RUN:   | FileCheck -check-prefix=CHECK03B %s
end_comment

begin_comment
comment|// CHECK03B: "-cc1"
end_comment

begin_comment
comment|// CHECK03B-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK03B: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0_standalone.o"
end_comment

begin_comment
comment|// CHECK03B: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/crt0.o"
end_comment

begin_comment
comment|// CHECK03B: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/init.o"
end_comment

begin_comment
comment|// CHECK03B: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60"
end_comment

begin_comment
comment|// CHECK03B: "-L{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib"
end_comment

begin_comment
comment|// CHECK03B: "-s"
end_comment

begin_comment
comment|// CHECK03B: "-Tbss" "0xdead" "-Tdata" "0xbeef" "-Ttext" "0xcafe"
end_comment

begin_comment
comment|// CHECK03B: "-t"
end_comment

begin_comment
comment|// CHECK03B: "-u" "Foo" "-undefined" "Bar"
end_comment

begin_comment
comment|// CHECK03B: "{{[^"]+}}.o"
end_comment

begin_comment
comment|// CHECK03B: "-lstdc++" "-lm"
end_comment

begin_comment
comment|// CHECK03B: "--start-group" "-lstandalone" "-lc" "-lgcc" "--end-group"
end_comment

begin_comment
comment|// CHECK03B: "{{.*}}/Inputs/hexagon_tree/Tools/bin/../target/hexagon/lib/v60/fini.o"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK040 %s
end_comment

begin_comment
comment|// CHECK040:      "-cc1"
end_comment

begin_comment
comment|// CHECK040-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK040-NOT:  "-G{{[0-9]+}}"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -fpic \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK041 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -fPIC \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK041 %s
end_comment

begin_comment
comment|// CHECK041:      "-cc1"
end_comment

begin_comment
comment|// CHECK041-NOT:  "-mrelocation-model" "static"
end_comment

begin_comment
comment|// CHECK041:      "-pic-level" "{{[12]}}"
end_comment

begin_comment
comment|// CHECK041:      "-mllvm" "-hexagon-small-data-threshold=0"
end_comment

begin_comment
comment|// CHECK041-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK041:      "-G0"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf -fno-integrated-as \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -G=8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK042 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf -fno-integrated-as \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -G 8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK042 %s
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf -fno-integrated-as \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -msmall-data-threshold=8 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK042 %s
end_comment

begin_comment
comment|// CHECK042:      "-cc1"
end_comment

begin_comment
comment|// CHECK042:      "-mrelocation-model" "static"
end_comment

begin_comment
comment|// CHECK042:      "-mllvm" "-hexagon-small-data-threshold=8"
end_comment

begin_comment
comment|// CHECK042-NEXT: llvm-mc
end_comment

begin_comment
comment|// CHECK042:      "-gpsize=8"
end_comment

begin_comment
comment|// CHECK042-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK042:      "-G8"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -pie \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK050 %s
end_comment

begin_comment
comment|// CHECK050:      "-cc1"
end_comment

begin_comment
comment|// CHECK050-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK050:      "-pie"
end_comment

begin_comment
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   -pie -shared \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK051 %s
end_comment

begin_comment
comment|// CHECK051:      "-cc1"
end_comment

begin_comment
comment|// CHECK051-NEXT: hexagon-link
end_comment

begin_comment
comment|// CHECK051-NOT:  "-pie"
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
comment|// RUN: %clang -### -target hexagon-unknown-elf -fno-integrated-as    \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
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
comment|// RUN:   | FileCheck -check-prefix=CHECK060 %s
end_comment

begin_comment
comment|// CHECK060:      "-cc1"
end_comment

begin_comment
comment|// CHECK060-NEXT: llvm-mc
end_comment

begin_comment
comment|// CHECK060:      "--noexecstack" "--trap" "--keep-locals"
end_comment

begin_comment
comment|// CHECK060-NEXT: hexagon-link
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
comment|// RUN: %clang -### -target hexagon-unknown-elf \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/Inputs/hexagon_tree/Tools/bin \
end_comment

begin_comment
comment|// RUN:   -mcpu=hexagonv60 \
end_comment

begin_comment
comment|// RUN:   %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK070 %s
end_comment

begin_comment
comment|// CHECK070:      "-cc1"
end_comment

begin_comment
comment|// CHECK070:      "-Wreturn-type"
end_comment

end_unit

