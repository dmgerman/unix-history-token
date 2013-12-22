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
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=z196 %s 2>&1 | FileCheck --check-prefix=CHECK-Z196 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x -### -S -emit-llvm -march=zEC12 %s 2>&1 | FileCheck --check-prefix=CHECK-ZEC12 %s
end_comment

begin_comment
comment|// CHECK-Z9: error: unknown target CPU 'z9'
end_comment

begin_comment
comment|// CHECK-Z10: "-target-cpu" "z10"
end_comment

begin_comment
comment|// CHECK-Z196: "-target-cpu" "z196"
end_comment

begin_comment
comment|// CHECK-ZEC12: "-target-cpu" "zEC12"
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

