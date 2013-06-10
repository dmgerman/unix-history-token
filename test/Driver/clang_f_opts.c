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
comment|// WRITE-STRINGS3: -fconst-strings
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

end_unit

