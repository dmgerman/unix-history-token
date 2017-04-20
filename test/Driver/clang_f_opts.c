begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// RUN: %clang -### -S -fasm -fblocks -fbuiltin -fno-math-errno -fcommon -fpascal-strings -fno-blocks -fno-builtin -fmath-errno -fno-common -fno-pascal-strings -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings -fsplit-stack %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS1 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fasm -fblocks -fbuiltin -fno-math-errno -fcommon -fpascal-strings -fno-asm -fno-blocks -fno-builtin -fmath-errno -fno-common -fno-pascal-strings -fno-show-source-location -fshort-enums -fshort-wchar %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS2 %s
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -split-stacks
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fgnu-keywords
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fblocks
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fpascal-strings
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fmath-errno
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-gnu-keywords
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-builtin
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fshort-enums
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fshort-wchar
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-common
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-show-source-location
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS1 %s
end_comment

begin_comment
comment|// WRITE-STRINGS1: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings -Wno-write-strings %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS2 %s
end_comment

begin_comment
comment|// WRITE-STRINGS2-NOT: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings -w %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS3 %s
end_comment

begin_comment
comment|// WRITE-STRINGS3-NOT: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -Wdeprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -Wno-deprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-OFF-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -Wno-deprecated -Wdeprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -w %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -c %s 2>&1 | FileCheck -check-prefix=DEPRECATED-OFF-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -Wdeprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-OFF-CHECK %s
end_comment

begin_comment
comment|// DEPRECATED-ON-CHECK: -fdeprecated-macro
end_comment

begin_comment
comment|// DEPRECATED-OFF-CHECK-NOT: -fdeprecated-macro
end_comment

begin_comment
comment|// RUN: %clang -### -S -ffp-contract=fast %s 2>&1 | FileCheck -check-prefix=FP-CONTRACT-FAST-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ffast-math %s 2>&1 | FileCheck -check-prefix=FP-CONTRACT-FAST-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ffp-contract=off %s 2>&1 | FileCheck -check-prefix=FP-CONTRACT-OFF-CHECK %s
end_comment

begin_comment
comment|// FP-CONTRACT-FAST-CHECK: -ffp-contract=fast
end_comment

begin_comment
comment|// FP-CONTRACT-OFF-CHECK: -ffp-contract=off
end_comment

begin_comment
comment|// RUN: %clang -### -S -funroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-UNROLL-LOOPS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-unroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-NO-UNROLL-LOOPS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-unroll-loops -funroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-UNROLL-LOOPS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -funroll-loops -fno-unroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-NO-UNROLL-LOOPS %s
end_comment

begin_comment
comment|// CHECK-UNROLL-LOOPS: "-funroll-loops"
end_comment

begin_comment
comment|// CHECK-NO-UNROLL-LOOPS: "-fno-unroll-loops"
end_comment

begin_comment
comment|// RUN: %clang -### -S -freroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-REROLL-LOOPS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-reroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-NO-REROLL-LOOPS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-reroll-loops -freroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-REROLL-LOOPS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -freroll-loops -fno-reroll-loops %s 2>&1 | FileCheck -check-prefix=CHECK-NO-REROLL-LOOPS %s
end_comment

begin_comment
comment|// CHECK-REROLL-LOOPS: "-freroll-loops"
end_comment

begin_comment
comment|// CHECK-NO-REROLL-LOOPS-NOT: "-freroll-loops"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-sample-use=%S/Inputs/file.prof %s 2>&1 | FileCheck -check-prefix=CHECK-SAMPLE-PROFILE %s
end_comment

begin_comment
comment|// CHECK-SAMPLE-PROFILE: "-fprofile-sample-use={{.*}}/file.prof"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fauto-profile=%S/Inputs/file.prof %s 2>&1 | FileCheck -check-prefix=CHECK-AUTO-PROFILE %s
end_comment

begin_comment
comment|// CHECK-AUTO-PROFILE: "-fprofile-sample-use={{.*}}/file.prof"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fauto-profile=%S/Inputs/file.prof -fno-profile-sample-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-AUTO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fauto-profile=%S/Inputs/file.prof -fno-auto-profile %s 2>&1 | FileCheck -check-prefix=CHECK-NO-AUTO-PROFILE %s
end_comment

begin_comment
comment|// CHECK-NO-AUTO-PROFILE-NOT: "-fprofile-sample-use={{.*}}/file.prof"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fauto-profile=%S/Inputs/file.prof -fno-profile-sample-use -fauto-profile %s 2>&1 | FileCheck -check-prefix=CHECK-AUTO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fauto-profile=%S/Inputs/file.prof -fno-auto-profile -fprofile-sample-use %s 2>&1 | FileCheck -check-prefix=CHECK-AUTO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-ARCS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-profile-arcs -fprofile-arcs %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-ARCS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-profile-arcs %s 2>&1 | FileCheck -check-prefix=CHECK-NO-PROFILE-ARCS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs -fno-profile-arcs %s 2>&1 | FileCheck -check-prefix=CHECK-NO-PROFILE-ARCS %s
end_comment

begin_comment
comment|// CHECK-PROFILE-ARCS: "-femit-coverage-data"
end_comment

begin_comment
comment|// CHECK-NO-PROFILE-ARCS-NOT: "-femit-coverage-data"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-dir=abc %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-DIR-UNUSED %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ftest-coverage -fprofile-dir=abc %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-DIR-UNUSED %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs -fprofile-dir=abc %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-DIR %s
end_comment

begin_comment
comment|// RUN: %clang -### -S --coverage -fprofile-dir=abc %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-DIR %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs -fno-profile-arcs -fprofile-dir=abc %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-DIR-NEITHER %s
end_comment

begin_comment
comment|// CHECK-PROFILE-DIR: "-coverage-data-file" "abc
end_comment

begin_comment
comment|// CHECK-PROFILE-DIR-UNUSED: argument unused
end_comment

begin_comment
comment|// CHECK-PROFILE-DIR-UNUSED-NOT: "-coverage-data-file" "abc
end_comment

begin_comment
comment|// CHECK-PROFILE-DIR-NEITHER-NOT: argument unused
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-GENERATE-LLVM %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-GENERATE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate=/some/dir %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-GENERATE-DIR %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate=/tmp/somefile.profraw %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-GENERATE-FILE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate -fprofile-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate -fprofile-use=dir %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate -fprofile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate -fprofile-instr-use=file %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fprofile-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fprofile-use=dir %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fprofile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fprofile-instr-use=file %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate=file -fprofile-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate=file -fprofile-use=dir %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate=file -fprofile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate=file -fprofile-instr-use=file %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate=dir -fprofile-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate=dir -fprofile-use=dir %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate=dir -fprofile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate=dir -fprofile-instr-use=file %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate=file -fno-profile-instr-generate %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-GEN %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fprofile-generate %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GENERATE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fprofile-generate=file %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GENERATE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-generate=dir -fno-profile-generate %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-GEN %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-use=file -fno-profile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-use=file -fno-profile-use %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-use=file -fno-profile-use %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-use=file -fno-profile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fcoverage-mapping %s 2>&1 | FileCheck -check-prefix=CHECK-COVERAGE-AND-GEN %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fcoverage-mapping -fno-coverage-mapping %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-COVERAGE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-generate -fcoverage-mapping -fno-coverage-mapping %s 2>&1 | FileCheck -check-prefix=CHECK-DISABLE-COVERAGE %s
end_comment

begin_comment
comment|// CHECK-PROFILE-GENERATE: "-fprofile-instrument=clang"
end_comment

begin_comment
comment|// CHECK-PROFILE-GENERATE-LLVM: "-fprofile-instrument=llvm"
end_comment

begin_comment
comment|// CHECK-PROFILE-GENERATE-DIR: "-fprofile-instrument-path=/some/dir{{/|\\\\}}{{.*}}"
end_comment

begin_comment
comment|// CHECK-PROFILE-GENERATE-FILE: "-fprofile-instrument-path=/tmp/somefile.profraw"
end_comment

begin_comment
comment|// CHECK-NO-MIX-GEN-USE: '{{[a-z=-]*}}' not allowed with '{{[a-z=-]*}}'
end_comment

begin_comment
comment|// CHECK-NO-MIX-GENERATE: '{{[a-z=-]*}}' not allowed with '{{[a-z=-]*}}'
end_comment

begin_comment
comment|// CHECK-DISABLE-GEN-NOT: "-fprofile-instrument=clang"
end_comment

begin_comment
comment|// CHECK-DISABLE-USE-NOT: "-fprofile-instr-use"
end_comment

begin_comment
comment|// CHECK-COVERAGE-AND-GEN: '-fcoverage-mapping' only allowed with '-fprofile-instr-generate'
end_comment

begin_comment
comment|// CHECK-DISABLE-COVERAGE-NOT: "-fcoverage-mapping"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-use %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-USE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-use %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-USE %s
end_comment

begin_comment
comment|// RUN: mkdir -p %t.d/some/dir
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-use=%t.d/some/dir %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-USE-DIR %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-instr-use=/tmp/somefile.prof %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-USE-FILE %s
end_comment

begin_comment
comment|// CHECK-PROFILE-USE: "-fprofile-instrument-use-path=default.profdata"
end_comment

begin_comment
comment|// CHECK-PROFILE-USE-DIR: "-fprofile-instrument-use-path={{.*}}.d/some/dir{{/|\\\\}}default.profdata"
end_comment

begin_comment
comment|// CHECK-PROFILE-USE-FILE: "-fprofile-instrument-use-path=/tmp/somefile.prof"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fvectorize %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-vectorize -fvectorize %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fvectorize -fno-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ftree-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-tree-vectorize -fvectorize %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-tree-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ftree-vectorize -fno-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O2 %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Os %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O3 %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-vectorize -O3 %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O1 -fvectorize %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Ofast %s 2>&1 | FileCheck -check-prefix=CHECK-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O0 %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O1 %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Oz %s 2>&1 | FileCheck -check-prefix=CHECK-NO-VECTORIZE %s
end_comment

begin_comment
comment|// CHECK-VECTORIZE: "-vectorize-loops"
end_comment

begin_comment
comment|// CHECK-NO-VECTORIZE-NOT: "-vectorize-loops"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fslp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-slp-vectorize -fslp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-slp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fslp-vectorize -fno-slp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ftree-slp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-tree-slp-vectorize -fslp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-tree-slp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -ftree-slp-vectorize -fno-slp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O2 %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Os %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Oz %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O3 %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-slp-vectorize -O3 %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O1 -fslp-vectorize %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Ofast %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O0 %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -O1 %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE %s
end_comment

begin_comment
comment|// CHECK-SLP-VECTORIZE: "-vectorize-slp"
end_comment

begin_comment
comment|// CHECK-NO-SLP-VECTORIZE-NOT: "-vectorize-slp"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fslp-vectorize-aggressive %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE-AGG %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-slp-vectorize-aggressive -fslp-vectorize-aggressive %s 2>&1 | FileCheck -check-prefix=CHECK-SLP-VECTORIZE-AGG %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-slp-vectorize-aggressive %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE-AGG %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fslp-vectorize-aggressive -fno-slp-vectorize-aggressive %s 2>&1 | FileCheck -check-prefix=CHECK-NO-SLP-VECTORIZE-AGG %s
end_comment

begin_comment
comment|// CHECK-SLP-VECTORIZE-AGG: "-vectorize-slp-aggressive"
end_comment

begin_comment
comment|// CHECK-NO-SLP-VECTORIZE-AGG-NOT: "-vectorize-slp-aggressive"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fextended-identifiers %s 2>&1 | FileCheck -check-prefix=CHECK-EXTENDED-IDENTIFIERS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-extended-identifiers %s 2>&1 | FileCheck -check-prefix=CHECK-NO-EXTENDED-IDENTIFIERS %s
end_comment

begin_comment
comment|// CHECK-EXTENDED-IDENTIFIERS: "-cc1"
end_comment

begin_comment
comment|// CHECK-EXTENDED-IDENTIFIERS-NOT: "-fextended-identifiers"
end_comment

begin_comment
comment|// CHECK-NO-EXTENDED-IDENTIFIERS: error: unsupported option '-fno-extended-identifiers'
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-pascal-strings -mpascal-strings %s 2>&1 | FileCheck -check-prefix=CHECK-M-PASCAL-STRINGS %s
end_comment

begin_comment
comment|// CHECK-M-PASCAL-STRINGS: "-fpascal-strings"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fpascal-strings -mno-pascal-strings %s 2>&1 | FileCheck -check-prefix=CHECK-NO-M-PASCAL-STRINGS %s
end_comment

begin_comment
comment|// CHECK-NO-M-PASCAL-STRINGS-NOT: "-fpascal-strings"
end_comment

begin_comment
comment|// RUN: %clang -### -S -O4 %s 2>&1 | FileCheck -check-prefix=CHECK-MAX-O %s
end_comment

begin_comment
comment|// CHECK-MAX-O: warning: -O4 is equivalent to -O3
end_comment

begin_comment
comment|// CHECK-MAX-O: -O3
end_comment

begin_comment
comment|// RUN: %clang -S -O20 -o /dev/null %s 2>&1 | FileCheck -check-prefix=CHECK-INVALID-O %s
end_comment

begin_comment
comment|// CHECK-INVALID-O: warning: optimization level '-O20' is not supported; using '-O3' instead
end_comment

begin_comment
comment|// RUN: %clang -### -S -finput-charset=iso-8859-1 -o /dev/null %s 2>&1 | FileCheck -check-prefix=CHECK-INVALID-CHARSET %s
end_comment

begin_comment
comment|// CHECK-INVALID-CHARSET: error: invalid value 'iso-8859-1' in '-finput-charset=iso-8859-1'
end_comment

begin_comment
comment|// RUN: %clang -### -S -fexec-charset=iso-8859-1 -o /dev/null %s 2>&1 | FileCheck -check-prefix=CHECK-INVALID-INPUT-CHARSET %s
end_comment

begin_comment
comment|// CHECK-INVALID-INPUT-CHARSET: error: invalid value 'iso-8859-1' in '-fexec-charset=iso-8859-1'
end_comment

begin_comment
comment|// Test that we don't error on these.
end_comment

begin_comment
comment|// RUN: %clang -### -S -Werror                                                \
end_comment

begin_comment
comment|// RUN:     -falign-functions -falign-functions=2 -fno-align-functions        \
end_comment

begin_comment
comment|// RUN:     -fasynchronous-unwind-tables -fno-asynchronous-unwind-tables      \
end_comment

begin_comment
comment|// RUN:     -fbuiltin -fno-builtin                                            \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-show-location=once                                  \
end_comment

begin_comment
comment|// RUN:     -ffloat-store -fno-float-store                                    \
end_comment

begin_comment
comment|// RUN:     -feliminate-unused-debug-types -fno-eliminate-unused-debug-types  \
end_comment

begin_comment
comment|// RUN:     -fgcse -fno-gcse                                                  \
end_comment

begin_comment
comment|// RUN:     -fident -fno-ident                                                \
end_comment

begin_comment
comment|// RUN:     -fimplicit-templates -fno-implicit-templates                      \
end_comment

begin_comment
comment|// RUN:     -finput-charset=UTF-8                                             \
end_comment

begin_comment
comment|// RUN:     -fexec-charset=UTF-8                                             \
end_comment

begin_comment
comment|// RUN:     -fivopts -fno-ivopts                                              \
end_comment

begin_comment
comment|// RUN:     -fnon-call-exceptions -fno-non-call-exceptions                    \
end_comment

begin_comment
comment|// RUN:     -fpermissive -fno-permissive                                      \
end_comment

begin_comment
comment|// RUN:     -fdefer-pop -fno-defer-pop                                        \
end_comment

begin_comment
comment|// RUN:     -fprefetch-loop-arrays -fno-prefetch-loop-arrays                  \
end_comment

begin_comment
comment|// RUN:     -fprofile-correction -fno-profile-correction                      \
end_comment

begin_comment
comment|// RUN:     -fprofile-values -fno-profile-values                              \
end_comment

begin_comment
comment|// RUN:     -frounding-math -fno-rounding-math                                \
end_comment

begin_comment
comment|// RUN:     -fsee -fno-see                                                    \
end_comment

begin_comment
comment|// RUN:     -ftracer -fno-tracer                                              \
end_comment

begin_comment
comment|// RUN:     -funroll-all-loops -fno-unroll-all-loops                          \
end_comment

begin_comment
comment|// RUN:     -fuse-ld=gold                                                     \
end_comment

begin_comment
comment|// RUN:     -fno-builtin-foobar                                               \
end_comment

begin_comment
comment|// RUN:     -fno-builtin-strcat -fno-builtin-strcpy                           \
end_comment

begin_comment
comment|// RUN:     -fno-var-tracking                                                 \
end_comment

begin_comment
comment|// RUN:     -fno-unsigned-char                                                \
end_comment

begin_comment
comment|// RUN:     -fno-signed-char                                                  \
end_comment

begin_comment
comment|// RUN:     -fstrength-reduce -fno-strength-reduce                            \
end_comment

begin_comment
comment|// RUN:     -finline-limit=1000                                               \
end_comment

begin_comment
comment|// RUN:     -finline-limit                                                    \
end_comment

begin_comment
comment|// RUN:     -flto=1                                                           \
end_comment

begin_comment
comment|// RUN:     -falign-labels                                                    \
end_comment

begin_comment
comment|// RUN:     -falign-labels=100                                                \
end_comment

begin_comment
comment|// RUN:     -falign-loops                                                     \
end_comment

begin_comment
comment|// RUN:     -falign-loops=100                                                 \
end_comment

begin_comment
comment|// RUN:     -falign-jumps                                                     \
end_comment

begin_comment
comment|// RUN:     -falign-jumps=100                                                 \
end_comment

begin_comment
comment|// RUN:     -fexcess-precision=100                                            \
end_comment

begin_comment
comment|// RUN:     -fbranch-count-reg                                                \
end_comment

begin_comment
comment|// RUN:     -fcaller-saves                                                    \
end_comment

begin_comment
comment|// RUN:     -fno-default-inline -fdefault-inline                              \
end_comment

begin_comment
comment|// RUN:     -fgcse-after-reload                                               \
end_comment

begin_comment
comment|// RUN:     -fgcse-las                                                        \
end_comment

begin_comment
comment|// RUN:     -fgcse-sm                                                         \
end_comment

begin_comment
comment|// RUN:     -fipa-cp                                                          \
end_comment

begin_comment
comment|// RUN:     -finline-functions-called-once                                    \
end_comment

begin_comment
comment|// RUN:     -fmodulo-sched                                                    \
end_comment

begin_comment
comment|// RUN:     -fmodulo-sched-allow-regmoves                                     \
end_comment

begin_comment
comment|// RUN:     -fpeel-loops                                                      \
end_comment

begin_comment
comment|// RUN:     -frename-registers                                                \
end_comment

begin_comment
comment|// RUN:     -fschedule-insns2                                                 \
end_comment

begin_comment
comment|// RUN:     -fsingle-precision-constant                                       \
end_comment

begin_comment
comment|// RUN:     -ftree_loop_im                                                    \
end_comment

begin_comment
comment|// RUN:     -ftree_loop_ivcanon                                               \
end_comment

begin_comment
comment|// RUN:     -ftree_loop_linear                                                \
end_comment

begin_comment
comment|// RUN:     -funsafe-loop-optimizations                                       \
end_comment

begin_comment
comment|// RUN:     -fuse-linker-plugin                                               \
end_comment

begin_comment
comment|// RUN:     -fvect-cost-model                                                 \
end_comment

begin_comment
comment|// RUN:     -fvariable-expansion-in-unroller                                  \
end_comment

begin_comment
comment|// RUN:     -fweb                                                             \
end_comment

begin_comment
comment|// RUN:     -fwhole-program                                                   \
end_comment

begin_comment
comment|// RUN:     -fno-tree-dce -ftree-dce                                          \
end_comment

begin_comment
comment|// RUN:     -fno-tree-ter -ftree-ter                                          \
end_comment

begin_comment
comment|// RUN:     -fno-tree-vrp -ftree-vrp                                          \
end_comment

begin_comment
comment|// RUN:     -fno-delete-null-pointer-checks -fdelete-null-pointer-checks      \
end_comment

begin_comment
comment|// RUN:     -fno-inline-small-functions -finline-small-functions              \
end_comment

begin_comment
comment|// RUN:     -fno-fat-lto-objects -ffat-lto-objects                            \
end_comment

begin_comment
comment|// RUN:     -fno-merge-constants -fmerge-constants                            \
end_comment

begin_comment
comment|// RUN:     -fno-caller-saves -fcaller-saves                                  \
end_comment

begin_comment
comment|// RUN:     -fno-reorder-blocks -freorder-blocks                              \
end_comment

begin_comment
comment|// RUN:     -fno-schedule-insns2 -fschedule-insns2                            \
end_comment

begin_comment
comment|// RUN:     -fno-stack-check                                                  \
end_comment

begin_comment
comment|// RUN:     -fno-check-new -fcheck-new                                        \
end_comment

begin_comment
comment|// RUN:     -ffriend-injection                                                \
end_comment

begin_comment
comment|// RUN:     -fno-implement-inlines -fimplement-inlines                        \
end_comment

begin_comment
comment|// RUN:     -fstack-check                                                     \
end_comment

begin_comment
comment|// RUN:     -fforce-addr                                                      \
end_comment

begin_comment
comment|// RUN:     -malign-functions=100                                             \
end_comment

begin_comment
comment|// RUN:     -malign-loops=100                                                 \
end_comment

begin_comment
comment|// RUN:     -malign-jumps=100                                                 \
end_comment

begin_comment
comment|// RUN:     %s 2>&1 | FileCheck --check-prefix=IGNORE %s
end_comment

begin_comment
comment|// IGNORE-NOT: error: unknown argument
end_comment

begin_comment
comment|// Test that the warning is displayed on these.
end_comment

begin_comment
comment|// RUN: %clang -###                                                           \
end_comment

begin_comment
comment|// RUN: -finline-limit=1000                                                   \
end_comment

begin_comment
comment|// RUN: -finline-limit                                                        \
end_comment

begin_comment
comment|// RUN: -fexpensive-optimizations                                             \
end_comment

begin_comment
comment|// RUN: -fno-expensive-optimizations                                          \
end_comment

begin_comment
comment|// RUN: -fno-defer-pop                                                        \
end_comment

begin_comment
comment|// RUN: -fkeep-inline-functions                                               \
end_comment

begin_comment
comment|// RUN: -fno-keep-inline-functions                                            \
end_comment

begin_comment
comment|// RUN: -freorder-blocks                                                      \
end_comment

begin_comment
comment|// RUN: -falign-functions                                                     \
end_comment

begin_comment
comment|// RUN: -falign-functions=1                                                   \
end_comment

begin_comment
comment|// RUN: -ffloat-store                                                         \
end_comment

begin_comment
comment|// RUN: -fgcse                                                                \
end_comment

begin_comment
comment|// RUN: -fivopts                                                              \
end_comment

begin_comment
comment|// RUN: -fprefetch-loop-arrays                                                \
end_comment

begin_comment
comment|// RUN: -fprofile-correction                                                  \
end_comment

begin_comment
comment|// RUN: -fprofile-values                                                      \
end_comment

begin_comment
comment|// RUN: -frounding-math                                                       \
end_comment

begin_comment
comment|// RUN: -fschedule-insns                                                      \
end_comment

begin_comment
comment|// RUN: -fsignaling-nans                                                      \
end_comment

begin_comment
comment|// RUN: -fstrength-reduce                                                     \
end_comment

begin_comment
comment|// RUN: -ftracer                                                              \
end_comment

begin_comment
comment|// RUN: -funroll-all-loops                                                    \
end_comment

begin_comment
comment|// RUN: -funswitch-loops                                                      \
end_comment

begin_comment
comment|// RUN: -flto=1                                                               \
end_comment

begin_comment
comment|// RUN: -falign-labels                                                        \
end_comment

begin_comment
comment|// RUN: -falign-labels=100                                                    \
end_comment

begin_comment
comment|// RUN: -falign-loops                                                         \
end_comment

begin_comment
comment|// RUN: -falign-loops=100                                                     \
end_comment

begin_comment
comment|// RUN: -falign-jumps                                                         \
end_comment

begin_comment
comment|// RUN: -falign-jumps=100                                                     \
end_comment

begin_comment
comment|// RUN: -fexcess-precision=100                                                \
end_comment

begin_comment
comment|// RUN: -fbranch-count-reg                                                    \
end_comment

begin_comment
comment|// RUN: -fcaller-saves                                                        \
end_comment

begin_comment
comment|// RUN: -fno-default-inline                                                   \
end_comment

begin_comment
comment|// RUN: -fgcse-after-reload                                                   \
end_comment

begin_comment
comment|// RUN: -fgcse-las                                                            \
end_comment

begin_comment
comment|// RUN: -fgcse-sm                                                             \
end_comment

begin_comment
comment|// RUN: -fipa-cp                                                              \
end_comment

begin_comment
comment|// RUN: -finline-functions-called-once                                        \
end_comment

begin_comment
comment|// RUN: -fmodulo-sched                                                        \
end_comment

begin_comment
comment|// RUN: -fmodulo-sched-allow-regmoves                                         \
end_comment

begin_comment
comment|// RUN: -fpeel-loops                                                          \
end_comment

begin_comment
comment|// RUN: -frename-registers                                                    \
end_comment

begin_comment
comment|// RUN: -fschedule-insns2                                                     \
end_comment

begin_comment
comment|// RUN: -fsingle-precision-constant                                           \
end_comment

begin_comment
comment|// RUN: -ftree_loop_im                                                        \
end_comment

begin_comment
comment|// RUN: -ftree_loop_ivcanon                                                   \
end_comment

begin_comment
comment|// RUN: -ftree_loop_linear                                                    \
end_comment

begin_comment
comment|// RUN: -funsafe-loop-optimizations                                           \
end_comment

begin_comment
comment|// RUN: -fuse-linker-plugin                                                   \
end_comment

begin_comment
comment|// RUN: -fvect-cost-model                                                     \
end_comment

begin_comment
comment|// RUN: -fvariable-expansion-in-unroller                                      \
end_comment

begin_comment
comment|// RUN: -fweb                                                                 \
end_comment

begin_comment
comment|// RUN: -fwhole-program                                                       \
end_comment

begin_comment
comment|// RUN: -fcaller-saves                                                        \
end_comment

begin_comment
comment|// RUN: -freorder-blocks                                                      \
end_comment

begin_comment
comment|// RUN: -fdelete-null-pointer-checks                                          \
end_comment

begin_comment
comment|// RUN: -ffat-lto-objects                                                     \
end_comment

begin_comment
comment|// RUN: -fmerge-constants                                                     \
end_comment

begin_comment
comment|// RUN: -finline-small-functions                                              \
end_comment

begin_comment
comment|// RUN: -ftree-dce                                                            \
end_comment

begin_comment
comment|// RUN: -ftree-ter                                                            \
end_comment

begin_comment
comment|// RUN: -ftree-vrp                                                            \
end_comment

begin_comment
comment|// RUN: -fno-devirtualize                                                     \
end_comment

begin_comment
comment|// RUN: -fno-devirtualize-speculatively                                       \
end_comment

begin_comment
comment|// RUN: %s 2>&1 | FileCheck --check-prefix=CHECK-WARNING %s
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-finline-limit=1000' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-finline-limit' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fexpensive-optimizations' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fno-expensive-optimizations' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fno-defer-pop' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fkeep-inline-functions' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fno-keep-inline-functions' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-freorder-blocks' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-functions' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-functions=1' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ffloat-store' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fgcse' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fivopts' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fprefetch-loop-arrays' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fprofile-correction' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fprofile-values' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-frounding-math' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fschedule-insns' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fsignaling-nans' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fstrength-reduce' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftracer' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-funroll-all-loops' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-funswitch-loops' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: unsupported argument '1' to option 'flto='
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-labels' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-labels=100' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-loops' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-loops=100' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-jumps' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-falign-jumps=100' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fexcess-precision=100' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fbranch-count-reg' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fcaller-saves' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fno-default-inline' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fgcse-after-reload' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fgcse-las' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fgcse-sm' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fipa-cp' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-finline-functions-called-once' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fmodulo-sched' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fmodulo-sched-allow-regmoves' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fpeel-loops' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-frename-registers' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fschedule-insns2' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fsingle-precision-constant' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftree_loop_im' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftree_loop_ivcanon' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftree_loop_linear' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-funsafe-loop-optimizations' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fuse-linker-plugin' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fvect-cost-model' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fvariable-expansion-in-unroller' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fweb' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fwhole-program' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fcaller-saves' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-freorder-blocks' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fdelete-null-pointer-checks' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ffat-lto-objects' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fmerge-constants' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-finline-small-functions' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftree-dce' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftree-ter' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-ftree-vrp' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fno-devirtualize' is not supported
end_comment

begin_comment
comment|// CHECK-WARNING-DAG: optimization flag '-fno-devirtualize-speculatively' is not supported
end_comment

begin_comment
comment|// Test that we mute the warning on these
end_comment

begin_comment
comment|// RUN: %clang -### -finline-limit=1000 -Wno-invalid-command-line-argument              \
end_comment

begin_comment
comment|// RUN:     %s 2>&1 | FileCheck --check-prefix=CHECK-NO-WARNING1 %s
end_comment

begin_comment
comment|// RUN: %clang -### -finline-limit -Wno-invalid-command-line-argument                   \
end_comment

begin_comment
comment|// RUN:     %s 2>&1 | FileCheck --check-prefix=CHECK-NO-WARNING2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -finline-limit \
end_comment

begin_comment
comment|// RUN:     -Winvalid-command-line-argument -Wno-ignored-optimization-argument          \
end_comment

begin_comment
comment|// RUN:     %s 2>&1 | FileCheck --check-prefix=CHECK-NO-WARNING2 %s
end_comment

begin_comment
comment|// CHECK-NO-WARNING1-NOT: optimization flag '-finline-limit=1000' is not supported
end_comment

begin_comment
comment|// CHECK-NO-WARNING2-NOT: optimization flag '-finline-limit' is not supported
end_comment

begin_comment
comment|// Test that an ignored optimization argument only prints 1 warning,
end_comment

begin_comment
comment|// not both a warning about not claiming the arg, *and* about not supporting
end_comment

begin_comment
comment|// the arg; and that adding -Wno-ignored-optimization silences the warning.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fprofile-correction %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-WARNING3 %s
end_comment

begin_comment
comment|// CHECK-NO-WARNING3: optimization flag '-fprofile-correction' is not supported
end_comment

begin_comment
comment|// CHECK-NO-WARNING3-NOT: argument unused
end_comment

begin_comment
comment|// RUN: %clang -### -fprofile-correction -Wno-ignored-optimization-argument %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-WARNING4 %s
end_comment

begin_comment
comment|// CHECK-NO-WARNING4-NOT: not supported
end_comment

begin_comment
comment|// CHECK-NO-WARNING4-NOT: argument unused
end_comment

begin_comment
comment|// RUN: %clang -### -S -fsigned-char %s 2>&1 | FileCheck -check-prefix=CHAR-SIGN1 %s
end_comment

begin_comment
comment|// CHAR-SIGN1-NOT: -fno-signed-char
end_comment

begin_comment
comment|// RUN: %clang -### -S -funsigned-char %s 2>&1 | FileCheck -check-prefix=CHAR-SIGN2 %s
end_comment

begin_comment
comment|// CHAR-SIGN2: -fno-signed-char
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-signed-char %s 2>&1 | FileCheck -check-prefix=CHAR-SIGN3 %s
end_comment

begin_comment
comment|// CHAR-SIGN3: -fno-signed-char
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-unsigned-char %s 2>&1 | FileCheck -check-prefix=CHAR-SIGN4 %s
end_comment

begin_comment
comment|// CHAR-SIGN4-NOT: -fno-signed-char
end_comment

begin_comment
comment|// RUN: %clang -### -fshort-wchar -fno-short-wchar %s 2>&1 | FileCheck -check-prefix=CHECK-WCHAR1 -check-prefix=DELIMITERS %s
end_comment

begin_comment
comment|// RUN: %clang -### -fno-short-wchar -fshort-wchar %s 2>&1 | FileCheck -check-prefix=CHECK-WCHAR2 -check-prefix=DELIMITERS %s
end_comment

begin_comment
comment|// Make sure we don't match the -NOT lines with the linker invocation.
end_comment

begin_comment
comment|// Delimiters match the start of the cc1 and the start of the linker lines
end_comment

begin_comment
comment|// DELIMITERS: {{^ *"}}
end_comment

begin_comment
comment|// CHECK-WCHAR1: -fno-short-wchar
end_comment

begin_comment
comment|// CHECK-WCHAR1-NOT: -fshort-wchar
end_comment

begin_comment
comment|// CHECK-WCHAR2: -fshort-wchar
end_comment

begin_comment
comment|// CHECK-WCHAR2-NOT: -fno-short-wchar
end_comment

begin_comment
comment|// DELIMITERS: {{^ *"}}
end_comment

begin_comment
comment|// RUN: %clang -### -fno-experimental-new-pass-manager -fexperimental-new-pass-manager %s 2>&1 | FileCheck --check-prefix=CHECK-PM --check-prefix=CHECK-NEW-PM %s
end_comment

begin_comment
comment|// RUN: %clang -### -fexperimental-new-pass-manager -fno-experimental-new-pass-manager %s 2>&1 | FileCheck --check-prefix=CHECK-PM --check-prefix=CHECK-NO-NEW-PM %s
end_comment

begin_comment
comment|// CHECK-PM-NOT: argument unused
end_comment

begin_comment
comment|// CHECK-NEW-PM: -fexperimental-new-pass-manager
end_comment

begin_comment
comment|// CHECK-NEW-PM-NOT: -fno-experimental-new-pass-manager
end_comment

begin_comment
comment|// CHECK-NO-NEW-PM: -fno-experimental-new-pass-manager
end_comment

begin_comment
comment|// CHECK-NO-NEW-PM-NOT: -fexperimental-new-pass-manager
end_comment

begin_comment
comment|// RUN: %clang -### -S -fstrict-return %s 2>&1 | FileCheck -check-prefix=CHECK-STRICT-RETURN %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-strict-return %s 2>&1 | FileCheck -check-prefix=CHECK-NO-STRICT-RETURN %s
end_comment

begin_comment
comment|// CHECK-STRICT-RETURN-NOT: "-fno-strict-return"
end_comment

begin_comment
comment|// CHECK-NO-STRICT-RETURN: "-fno-strict-return"
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-debug-info-for-profiling -fdebug-info-for-profiling %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-DEBUG %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fdebug-info-for-profiling -fno-debug-info-for-profiling %s 2>&1 | FileCheck -check-prefix=CHECK-NO-PROFILE-DEBUG %s
end_comment

begin_comment
comment|// CHECK-PROFILE-DEBUG: -fdebug-info-for-profiling
end_comment

begin_comment
comment|// CHECK-NO-PROFILE-DEBUG-NOT: -fdebug-info-for-profiling
end_comment

begin_comment
comment|// RUN: %clang -### -S -fallow-editor-placeholders %s 2>&1 | FileCheck -check-prefix=CHECK-ALLOW-PLACEHOLDERS %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-allow-editor-placeholders %s 2>&1 | FileCheck -check-prefix=CHECK-NO-ALLOW-PLACEHOLDERS %s
end_comment

begin_comment
comment|// CHECK-ALLOW-PLACEHOLDERS: -fallow-editor-placeholders
end_comment

begin_comment
comment|// CHECK-NO-ALLOW-PLACEHOLDERS-NOT: -fallow-editor-placeholders
end_comment

end_unit

