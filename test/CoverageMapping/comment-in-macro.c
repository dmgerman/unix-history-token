begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|x1
value|""
end_define

begin_comment
comment|// ...
end_comment

begin_define
define|#
directive|define
name|x2
value|return 0
end_define

begin_comment
comment|// CHECK: main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+3]]:2 = #0
name|x1
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:5 = #0
name|x2
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:5 = #0
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 3:12 -> 3:14 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 4:12 -> 4:20 = #0
end_comment

end_unit

