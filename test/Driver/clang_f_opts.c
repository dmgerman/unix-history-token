begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// CHECK_OPTIONS2: -fno-gnu-keywords
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fmath-errno
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
comment|// RUN: %clang -### -S -Weverything %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS1 %s
end_comment

begin_comment
comment|// WRITE-STRINGS1: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings -Wno-write-strings %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings -w %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS2 %s
end_comment

begin_comment
comment|// WRITE-STRINGS2-NOT: -fconst-strings
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
comment|// CHECK-INVALID-O: warning: optimization level '-O20' is unsupported; using '-O3' instead
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
comment|// RUN:     -fivopts -fno-ivopts                                              \
end_comment

begin_comment
comment|// RUN:     -fnon-call-exceptions -fno-non-call-exceptions                    \
end_comment

begin_comment
comment|// RUN:     -fpermissive -fno-permissive                                      \
end_comment

begin_comment
comment|// RUN:     -fprefetch-loop-arrays -fno-prefetch-loop-arrays                  \
end_comment

begin_comment
comment|// RUN:     -fprofile-correction -fno-profile-correction                      \
end_comment

begin_comment
comment|// RUN:     -fprofile-dir=bar                                                 \
end_comment

begin_comment
comment|// RUN:     -fprofile-use -fprofile-use=zed -fno-profile-use                  \
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
comment|// RUN:     %s 2>&1 | FileCheck --check-prefix=IGNORE %s
end_comment

begin_comment
comment|// IGNORE-NOT: error: unknown argument
end_comment

end_unit

