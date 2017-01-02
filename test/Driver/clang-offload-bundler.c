begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Generate all the types of files we can bundle.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -O0 -target powerpc64le-ibm-linux-gnu %s -E -o %t.i
end_comment

begin_comment
comment|// RUN: %clangxx -O0 -target powerpc64le-ibm-linux-gnu -x c++ %s -E -o %t.ii
end_comment

begin_comment
comment|// RUN: %clang -O0 -target powerpc64le-ibm-linux-gnu %s -S -emit-llvm -o %t.ll
end_comment

begin_comment
comment|// RUN: %clang -O0 -target powerpc64le-ibm-linux-gnu %s -c -emit-llvm -o %t.bc
end_comment

begin_comment
comment|// RUN: %clang -O0 -target powerpc64le-ibm-linux-gnu %s -S -o %t.s
end_comment

begin_comment
comment|// RUN: %clang -O0 -target powerpc64le-ibm-linux-gnu %s -c -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -O0 -target powerpc64le-ibm-linux-gnu %s -emit-ast -o %t.ast
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Generate an empty file to help with the checks of empty files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: touch %t.empty
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Generate a couple of files to bundle with.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: echo 'Content of device file 1'> %t.tgt1
end_comment

begin_comment
comment|// RUN: echo 'Content of device file 2'> %t.tgt2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check help message.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-offload-bundler --help | FileCheck %s --check-prefix CK-HELP
end_comment

begin_comment
comment|// CK-HELP: {{.*}}OVERVIEW: A tool to bundle several input files of the specified type<type>
end_comment

begin_comment
comment|// CK-HELP: {{.*}}referring to the same source file but different targets into a single
end_comment

begin_comment
comment|// CK-HELP: {{.*}}one. The resulting file can also be unbundled into different files by
end_comment

begin_comment
comment|// CK-HELP: {{.*}}this tool if -unbundle is provided.
end_comment

begin_comment
comment|// CK-HELP: {{.*}}USAGE: clang-offload-bundler [options]
end_comment

begin_comment
comment|// CK-HELP: {{.*}}-inputs=<string>  - [<input file>,...]
end_comment

begin_comment
comment|// CK-HELP: {{.*}}-outputs=<string> - [<output file>,...]
end_comment

begin_comment
comment|// CK-HELP: {{.*}}-targets=<string> - [<offload kind>-<target triple>,...]
end_comment

begin_comment
comment|// CK-HELP: {{.*}}-type=<string>    - Type of the files to be bundled/unbundled.
end_comment

begin_comment
comment|// CK-HELP: {{.*}}Current supported types are:
end_comment

begin_comment
comment|// CK-HELP: {{.*}}i {{.*}}- cpp-output
end_comment

begin_comment
comment|// CK-HELP: {{.*}}ii {{.*}}- c++-cpp-output
end_comment

begin_comment
comment|// CK-HELP: {{.*}}ll {{.*}}- llvm
end_comment

begin_comment
comment|// CK-HELP: {{.*}}bc {{.*}}- llvm-bc
end_comment

begin_comment
comment|// CK-HELP: {{.*}}s {{.*}}- assembler
end_comment

begin_comment
comment|// CK-HELP: {{.*}}o {{.*}}- object
end_comment

begin_comment
comment|// CK-HELP: {{.*}}gch {{.*}}- precompiled-header
end_comment

begin_comment
comment|// CK-HELP: {{.*}}ast {{.*}}- clang AST file
end_comment

begin_comment
comment|// CK-HELP: {{.*}}-unbundle {{.*}}- Unbundle bundled file into several output files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check errors.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle.i -unbundle 2>&1 | FileCheck %s --check-prefix CK-ERR1
end_comment

begin_comment
comment|// CK-ERR1: error: only one input file supported in unbundling mode.
end_comment

begin_comment
comment|// CK-ERR1: error: number of output files and targets should match in unbundling mode.
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR2
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1 -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR2
end_comment

begin_comment
comment|// CK-ERR2: error: number of input files and targets should match in bundling mode.
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.i,%t.tgt1,%t.tgt2 -inputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR3
end_comment

begin_comment
comment|// CK-ERR3: error: only one output file supported in bundling mode.
end_comment

begin_comment
comment|// CK-ERR3: error: number of input files and targets should match in bundling mode.
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu -outputs=%t.i,%t.tgt1,%t.tgt2 -inputs=%t.bundle.i -unbundle 2>&1 | FileCheck %s --check-prefix CK-ERR4
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.i,%t.tgt1 -inputs=%t.bundle.i -unbundle 2>&1 | FileCheck %s --check-prefix CK-ERR4
end_comment

begin_comment
comment|// CK-ERR4: error: number of output files and targets should match in unbundling mode.
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2.notexist -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR5
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.i,%t.tgt1,%t.tgt2 -inputs=%t.bundle.i.notexist -unbundle 2>&1 | FileCheck %s --check-prefix CK-ERR5
end_comment

begin_comment
comment|// CK-ERR5: error: Can't open file {{.+}}.notexist: {{N|n}}o such file or directory
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=invalid -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR6
end_comment

begin_comment
comment|// CK-ERR6: error: invalid file type specified.
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler 2>&1 | FileCheck %s --check-prefix CK-ERR7
end_comment

begin_comment
comment|// CK-ERR7-DAG: clang-offload-bundler: for the -type option: must be specified at least once!
end_comment

begin_comment
comment|// CK-ERR7-DAG: clang-offload-bundler: for the -inputs option: must be specified at least once!
end_comment

begin_comment
comment|// CK-ERR7-DAG: clang-offload-bundler: for the -outputs option: must be specified at least once!
end_comment

begin_comment
comment|// CK-ERR7-DAG: clang-offload-bundler: for the -targets option: must be specified at least once!
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=hxst-powerpcxxle-ibm-linux-gnu,openxp-pxxerpc64le-ibm-linux-gnu,xpenmp-x86_xx-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR8
end_comment

begin_comment
comment|// CK-ERR8: error: invalid target 'hxst-powerpcxxle-ibm-linux-gnu', unknown offloading kind 'hxst', unknown target triple 'powerpcxxle-ibm-linux-gnu'.
end_comment

begin_comment
comment|// CK-ERR8: error: invalid target 'openxp-pxxerpc64le-ibm-linux-gnu', unknown offloading kind 'openxp', unknown target triple 'pxxerpc64le-ibm-linux-gnu'.
end_comment

begin_comment
comment|// CK-ERR8: error: invalid target 'xpenmp-x86_xx-pc-linux-gnu', unknown offloading kind 'xpenmp', unknown target triple 'x86_xx-pc-linux-gnu'.
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=openmp-powerpc64le-linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR9A
end_comment

begin_comment
comment|// RUN: not clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle.i 2>&1 | FileCheck %s --check-prefix CK-ERR9B
end_comment

begin_comment
comment|// CK-ERR9A: error: expecting exactly one host target but got 0.
end_comment

begin_comment
comment|// CK-ERR9B: error: expecting exactly one host target but got 2.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check text bundle. This is a readable format, so we check for the format we expect to find.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.i,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.i
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ii -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.ii,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.ii
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ll -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.ll,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.ll
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=s -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.s,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.s
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=s -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.tgt1,%t.s,%t.tgt2 -outputs=%t.bundle3.unordered.s
end_comment

begin_comment
comment|// RUN: FileCheck %s --input-file %t.bundle3.i --check-prefix CK-TEXTI
end_comment

begin_comment
comment|// RUN: FileCheck %s --input-file %t.bundle3.ii --check-prefix CK-TEXTI
end_comment

begin_comment
comment|// RUN: FileCheck %s --input-file %t.bundle3.ll --check-prefix CK-TEXTLL
end_comment

begin_comment
comment|// RUN: FileCheck %s --input-file %t.bundle3.s --check-prefix CK-TEXTS
end_comment

begin_comment
comment|// RUN: FileCheck %s --input-file %t.bundle3.unordered.s --check-prefix CK-TEXTS-UNORDERED
end_comment

begin_comment
comment|// CK-TEXTI: // __CLANG_OFFLOAD_BUNDLE____START__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTI: int A = 0;
end_comment

begin_comment
comment|// CK-TEXTI: test_func(void)
end_comment

begin_comment
comment|// CK-TEXTI: // __CLANG_OFFLOAD_BUNDLE____END__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTI: // __CLANG_OFFLOAD_BUNDLE____START__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTI: Content of device file 1
end_comment

begin_comment
comment|// CK-TEXTI: // __CLANG_OFFLOAD_BUNDLE____END__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTI: // __CLANG_OFFLOAD_BUNDLE____START__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTI: Content of device file 2
end_comment

begin_comment
comment|// CK-TEXTI: // __CLANG_OFFLOAD_BUNDLE____END__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTLL: ; __CLANG_OFFLOAD_BUNDLE____START__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTLL: @A = global i32 0
end_comment

begin_comment
comment|// CK-TEXTLL: define {{.*}}@test_func()
end_comment

begin_comment
comment|// CK-TEXTLL: ; __CLANG_OFFLOAD_BUNDLE____END__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTLL: ; __CLANG_OFFLOAD_BUNDLE____START__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTLL: Content of device file 1
end_comment

begin_comment
comment|// CK-TEXTLL: ; __CLANG_OFFLOAD_BUNDLE____END__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTLL: ; __CLANG_OFFLOAD_BUNDLE____START__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTLL: Content of device file 2
end_comment

begin_comment
comment|// CK-TEXTLL: ; __CLANG_OFFLOAD_BUNDLE____END__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS: # __CLANG_OFFLOAD_BUNDLE____START__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS: .globl {{.*}}test_func
end_comment

begin_comment
comment|// CK-TEXTS: .globl {{.*}}A
end_comment

begin_comment
comment|// CK-TEXTS: # __CLANG_OFFLOAD_BUNDLE____END__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS: # __CLANG_OFFLOAD_BUNDLE____START__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS: Content of device file 1
end_comment

begin_comment
comment|// CK-TEXTS: # __CLANG_OFFLOAD_BUNDLE____END__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS: # __CLANG_OFFLOAD_BUNDLE____START__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS: Content of device file 2
end_comment

begin_comment
comment|// CK-TEXTS: # __CLANG_OFFLOAD_BUNDLE____END__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: # __CLANG_OFFLOAD_BUNDLE____START__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: Content of device file 1
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: # __CLANG_OFFLOAD_BUNDLE____END__ openmp-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: # __CLANG_OFFLOAD_BUNDLE____START__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: .globl {{.*}}test_func
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: .globl {{.*}}A
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: # __CLANG_OFFLOAD_BUNDLE____END__ host-powerpc64le-ibm-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: # __CLANG_OFFLOAD_BUNDLE____START__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: Content of device file 2
end_comment

begin_comment
comment|// CK-TEXTS-UNORDERED: # __CLANG_OFFLOAD_BUNDLE____END__ openmp-x86_64-pc-linux-gnu
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check text unbundle. Check if we get the exact same content that we bundled before for each file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=i -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.i,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.i -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.i %t.res.i
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ii -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.ii,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.ii -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.ii %t.res.ii
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ll -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.ll,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.ll -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.ll %t.res.ll
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=s -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.s,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.s -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.s %t.res.s
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=s -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.s,%t.res.tgt2 -inputs=%t.bundle3.s -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.s %t.res.s
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// Check if we can unbundle a file with no magic strings.
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=s -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.s,%t.res.tgt1,%t.res.tgt2 -inputs=%t.s -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.s %t.res.s
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=s -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.s,%t.res.tgt2 -inputs=%t.s -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.s %t.res.s
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check binary bundle/unbundle. The content that we have before bundling must be the same we have after unbundling.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=bc -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.bc,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.bc
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=gch -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.ast,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.gch
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ast -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.ast,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.ast
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ast -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.tgt1,%t.ast,%t.tgt2 -outputs=%t.bundle3.unordered.ast
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=bc -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.bc,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.bc -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.bc %t.res.bc
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=gch -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.gch,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.gch -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.ast %t.res.gch
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ast -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.ast,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bundle3.ast -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.ast %t.res.ast
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ast -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.ast,%t.res.tgt2 -inputs=%t.bundle3.ast -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.ast %t.res.ast
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=ast -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.ast,%t.res.tgt2 -inputs=%t.bundle3.unordered.ast -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.ast %t.res.ast
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// Check if we can unbundle a file with no magic strings.
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=bc -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.bc,%t.res.tgt1,%t.res.tgt2 -inputs=%t.bc -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.bc %t.res.bc
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=bc -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.bc,%t.res.tgt2 -inputs=%t.bc -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.bc %t.res.bc
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check object bundle/unbundle. The content should be bundled into an ELF
end_comment

begin_comment
comment|// section (we are using a PowerPC little-endian host which uses ELF). We
end_comment

begin_comment
comment|// have an already bundled file to check the unbundle and do a dry run on the
end_comment

begin_comment
comment|// bundling as it cannot be tested in all host platforms that will run these
end_comment

begin_comment
comment|// tests.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=o -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -inputs=%t.o,%t.tgt1,%t.tgt2 -outputs=%t.bundle3.o -### -dump-temporary-files 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s --check-prefix CK-OBJ-CMD
end_comment

begin_comment
comment|// CK-OBJ-CMD: private constant [1 x i8] zeroinitializer, section "__CLANG_OFFLOAD_BUNDLE__host-powerpc64le-ibm-linux-gnu"
end_comment

begin_comment
comment|// CK-OBJ-CMD: private constant [{{[0-9]+}} x i8] c"Content of device file 1{{.+}}", section "__CLANG_OFFLOAD_BUNDLE__openmp-powerpc64le-ibm-linux-gnu"
end_comment

begin_comment
comment|// CK-OBJ-CMD: private constant [{{[0-9]+}} x i8] c"Content of device file 2{{.+}}", section "__CLANG_OFFLOAD_BUNDLE__openmp-x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// CK-OBJ-CMD: clang{{(.exe)?}}" "-r" "-target" "powerpc64le-ibm-linux-gnu" "-o" "{{.+}}.o" "{{.+}}.o" "{{.+}}.bc" "-nostdlib"
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=o -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.o,%t.res.tgt1,%t.res.tgt2 -inputs=%s.o -unbundle
end_comment

begin_comment
comment|// RUN: diff %s.o %t.res.o
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=o -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.o,%t.res.tgt2 -inputs=%s.o -unbundle
end_comment

begin_comment
comment|// RUN: diff %s.o %t.res.o
end_comment

begin_comment
comment|// RUN: diff %t.tgt1 %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.tgt2 %t.res.tgt2
end_comment

begin_comment
comment|// Check if we can unbundle a file with no magic strings.
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=o -targets=host-powerpc64le-ibm-linux-gnu,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.o,%t.res.tgt1,%t.res.tgt2 -inputs=%t.o -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.o %t.res.o
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt2
end_comment

begin_comment
comment|// RUN: clang-offload-bundler -type=o -targets=openmp-powerpc64le-ibm-linux-gnu,host-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu -outputs=%t.res.tgt1,%t.res.o,%t.res.tgt2 -inputs=%t.o -unbundle
end_comment

begin_comment
comment|// RUN: diff %t.o %t.res.o
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt1
end_comment

begin_comment
comment|// RUN: diff %t.empty %t.res.tgt2
end_comment

begin_comment
comment|// Some code so that we can create a binary out of this file.
end_comment

begin_decl_stmt
name|int
name|A
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_func
parameter_list|(
name|void
parameter_list|)
block|{
operator|++
name|A
expr_stmt|;
block|}
end_function

end_unit

