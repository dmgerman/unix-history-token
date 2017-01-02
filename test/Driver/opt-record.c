begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S -o FOO -fsave-optimization-record %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -o FOO -fsave-optimization-record %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fsave-optimization-record %s 2>&1 | FileCheck %s -check-prefix=CHECK-NO-O
end_comment

begin_comment
comment|// RUN: %clang -### -fsave-optimization-record %s 2>&1 | FileCheck %s -check-prefix=CHECK-NO-O
end_comment

begin_comment
comment|// RUN: %clang -### -S -fsave-optimization-record -x cuda -nocudainc -nocudalib %s 2>&1 | FileCheck %s -check-prefix=CHECK-NO-O -check-prefix=CHECK-CUDA-DEV
end_comment

begin_comment
comment|// RUN: %clang -### -fsave-optimization-record -x cuda -nocudainc -nocudalib %s 2>&1 | FileCheck %s -check-prefix=CHECK-NO-O -check-prefix=CHECK-CUDA-DEV
end_comment

begin_comment
comment|// RUN: %clang -### -S -o FOO -fsave-optimization-record -foptimization-record-file=BAR.txt %s 2>&1 | FileCheck %s -check-prefix=CHECK-EQ
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK: "-opt-record-file" "FOO.opt.yaml"
end_comment

begin_comment
comment|// CHECK-NO-O: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-O-DAG: "-opt-record-file" "opt-record.opt.yaml"
end_comment

begin_comment
comment|// CHECK-CUDA-DEV-DAG: "-opt-record-file" "opt-record-cuda-{{nvptx64|nvptx}}-nvidia-cuda-sm_20.opt.yaml"
end_comment

begin_comment
comment|// CHECK-EQ: "-cc1"
end_comment

begin_comment
comment|// CHECK-EQ: "-opt-record-file" "BAR.txt"
end_comment

end_unit

