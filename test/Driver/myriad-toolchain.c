begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target sparc-myriad-rtems-elf %s \
end_comment

begin_comment
comment|// RUN: --gcc-toolchain=%S/Inputs/basic_myriad_tree 2>&1 | FileCheck %s -check-prefix=LINK_WITH_RTEMS
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: Inputs{{.*}}crti.o
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: Inputs{{.*}}crtbegin.o
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: "-L{{.*}}Inputs/basic_myriad_tree/lib/gcc/sparc-myriad-elf/4.8.2/../../..{{/|\\\\}}../sparc-myriad-elf/lib"
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: "-L{{.*}}Inputs/basic_myriad_tree/lib/gcc/sparc-myriad-elf/4.8.2"
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: "--start-group" "-lc" "-lrtemscpu" "-lrtemsbsp" "--end-group" "-lgcc"
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: Inputs{{.*}}crtend.o
end_comment

begin_comment
comment|// LINK_WITH_RTEMS: Inputs{{.*}}crtn.o
end_comment

begin_comment
comment|// RUN: %clang -c -no-canonical-prefixes -### -target sparc-myriad-rtems-elf -x c++ %s \
end_comment

begin_comment
comment|// RUN: --gcc-toolchain=%S/Inputs/basic_myriad_tree 2>&1 | FileCheck %s -check-prefix=COMPILE_CXX
end_comment

begin_comment
comment|// COMPILE_CXX: "-internal-isystem" "{{.*}}/Inputs/basic_myriad_tree/lib/gcc/sparc-myriad-elf/4.8.2/../../../../sparc-myriad-elf/include/c++/4.8.2"
end_comment

begin_comment
comment|// COMPILE_CXX: "-internal-isystem" "{{.*}}/Inputs/basic_myriad_tree/lib/gcc/sparc-myriad-elf/4.8.2/../../../../sparc-myriad-elf/include/c++/4.8.2/sparc-myriad-elf"
end_comment

begin_comment
comment|// COMPILE_CXX: "-internal-isystem" "{{.*}}/Inputs/basic_myriad_tree/lib/gcc/sparc-myriad-elf/4.8.2/../../../../sparc-myriad-elf/include/c++/4.8.2/backward"
end_comment

begin_comment
comment|// RUN: %clang -### -E -target sparc-myriad --sysroot=/yow %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=SLASH_INCLUDE
end_comment

begin_comment
comment|// SLASH_INCLUDE: "-isysroot" "/yow" "-internal-isystem" "/yow/include"
end_comment

begin_comment
comment|// RUN: %clang -### -E -target sparc-myriad --sysroot=/yow %s -nostdinc 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=NO_SLASH_INCLUDE
end_comment

begin_comment
comment|// NO_SLASH_INCLUDE: "-isysroot" "/yow"
end_comment

begin_comment
comment|// NO_SLASH_INCLUDE-NOT: "-internal-isystem" "/yow/include"
end_comment

begin_comment
comment|// RUN: %clang -### -target what-myriad %s 2>&1 | FileCheck %s -check-prefix=BAD_ARCH
end_comment

begin_comment
comment|// BAD_ARCH: the target architecture 'what' is not supported by the target 'myriad'
end_comment

begin_comment
comment|// Ensure that '-target shave' picks a different compiler.
end_comment

begin_comment
comment|// Also check that '-I' is turned into '-i:' for the assembler.
end_comment

begin_comment
comment|// Note that since we don't know where movi tools are installed,
end_comment

begin_comment
comment|// the driver may or may not find a full path to them.
end_comment

begin_comment
comment|// That is, the 0th argument will be "/path/to/my/moviCompile"
end_comment

begin_comment
comment|// or just "moviCompile" depending on whether moviCompile is found.
end_comment

begin_comment
comment|// As such, we test only for a trailing quote in its rendering.
end_comment

begin_comment
comment|// The same goes for "moviAsm".
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -c -### %s -isystem somewhere -Icommon -Wa,-yippee 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=MOVICOMPILE
end_comment

begin_comment
comment|// MOVICOMPILE: moviCompile{{(.exe)?}}" "-S" "-fno-exceptions" "-mcpu=myriad2" "-DMYRIAD2" "-isystem" "somewhere" "-I" "common"
end_comment

begin_comment
comment|// MOVICOMPILE: moviAsm{{(.exe)?}}" "-no6thSlotCompression" "-cv:myriad2" "-noSPrefixing" "-a"
end_comment

begin_comment
comment|// MOVICOMPILE: "-yippee" "-i:somewhere" "-i:common" "-elf"
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -c -### %s -DEFINE_ME -UNDEFINE_ME 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=DEFINES
end_comment

begin_comment
comment|// DEFINES: "-D" "EFINE_ME" "-U" "NDEFINE_ME"
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -c -### %s -Icommon -iquote quotepath -isystem syspath 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=INCLUDES
end_comment

begin_comment
comment|// INCLUDES: "-iquote" "quotepath" "-isystem" "syspath"
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -c -### %s -g -fno-inline-functions \
end_comment

begin_comment
comment|// RUN: -fno-inline-functions-called-once -Os -Wall -MF dep.d \
end_comment

begin_comment
comment|// RUN: -ffunction-sections 2>&1 | FileCheck %s -check-prefix=PASSTHRU_OPTIONS
end_comment

begin_comment
comment|// PASSTHRU_OPTIONS: "-g" "-fno-inline-functions" "-fno-inline-functions-called-once"
end_comment

begin_comment
comment|// PASSTHRU_OPTIONS: "-Os" "-Wall" "-MF" "dep.d" "-ffunction-sections"
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -c %s -o foo.o -### -MD -MF dep.d 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=MDMF
end_comment

begin_comment
comment|// MDMF: "-S" "-fno-exceptions" "-mcpu=myriad2" "-DMYRIAD2" "-MD" "-MF" "dep.d" "-MT" "foo.o"
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -std=gnu++11 -S %s -o foo.o -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=STDEQ
end_comment

begin_comment
comment|// STDEQ: "-S" "-fno-exceptions" "-mcpu=myriad2" "-DMYRIAD2" "-std=gnu++11"
end_comment

begin_comment
comment|// RUN: %clang -target shave-myriad -E -Ifoo %s -o foo.i -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=PREPROCESS
end_comment

begin_comment
comment|// PREPROCESS: "-E" "-mcpu=myriad2" "-DMYRIAD2" "-I" "foo"
end_comment

begin_comment
comment|// RUN: %clang -target sparc-myriad -### --driver-mode=g++ %s 2>&1 | FileCheck %s --check-prefix=STDLIBCXX
end_comment

begin_comment
comment|// STDLIBCXX: "-lstdc++" "-lc" "-lgcc"
end_comment

begin_comment
comment|// RUN: %clang -target sparc-myriad -### -nostdlib %s 2>&1 | FileCheck %s --check-prefix=NOSTDLIB
end_comment

begin_comment
comment|// NOSTDLIB-NOT: crtbegin.o
end_comment

begin_comment
comment|// NOSTDLIB-NOT: "-lc"
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target sparc-myriad 2>&1 | FileCheck -check-prefix=G_SPARC %s
end_comment

begin_comment
comment|// G_SPARC: "-debug-info-kind=limited" "-dwarf-version=2"
end_comment

end_unit

