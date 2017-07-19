begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -march works for all supported targets.
end_comment

begin_comment
comment|// RUN: not %clang -target s390x -S -emit-llvm -march=z9 %s -o - 2>&1 | FileCheck --check-prefix=CHECK-Z9 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=z10 %s 2>&1 | FileCheck --check-prefix=CHECK-Z10 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=arch8 %s 2>&1 | FileCheck --check-prefix=CHECK-ARCH8 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=z196 %s 2>&1 | FileCheck --check-prefix=CHECK-Z196 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=arch9 %s 2>&1 | FileCheck --check-prefix=CHECK-ARCH9 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=zEC12 %s 2>&1 | FileCheck --check-prefix=CHECK-ZEC12 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=arch10 %s 2>&1 | FileCheck --check-prefix=CHECK-ARCH10 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=z13 %s 2>&1 | FileCheck --check-prefix=CHECK-Z13 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=arch11 %s 2>&1 | FileCheck --check-prefix=CHECK-ARCH11 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=z14 %s 2>&1 | FileCheck --check-prefix=CHECK-Z14 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=arch12 %s 2>&1 | FileCheck --check-prefix=CHECK-ARCH12 %s
end_comment

begin_comment
comment|// CHECK-Z9: error: unknown target CPU 'z9'
end_comment

begin_comment
comment|// CHECK-Z10: "-target-cpu" "z10"
end_comment

begin_comment
comment|// CHECK-ARCH8: "-target-cpu" "arch8"
end_comment

begin_comment
comment|// CHECK-Z196: "-target-cpu" "z196"
end_comment

begin_comment
comment|// CHECK-ARCH9: "-target-cpu" "arch9"
end_comment

begin_comment
comment|// CHECK-ZEC12: "-target-cpu" "zEC12"
end_comment

begin_comment
comment|// CHECK-ARCH10: "-target-cpu" "arch10"
end_comment

begin_comment
comment|// CHECK-Z13: "-target-cpu" "z13"
end_comment

begin_comment
comment|// CHECK-ARCH11: "-target-cpu" "arch11"
end_comment

begin_comment
comment|// CHECK-Z14: "-target-cpu" "z14"
end_comment

begin_comment
comment|// CHECK-ARCH12: "-target-cpu" "arch12"
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

