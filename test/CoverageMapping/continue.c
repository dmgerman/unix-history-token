begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name continue.c %s | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:12 -> [[@LINE+21]]:2 = #0
name|int
name|j
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:18 -> [[@LINE+2]]:24 = (#0 + #1)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:26 -> [[@LINE+1]]:29 = #1
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|20
condition|;
operator|++
name|i
control|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:31 -> [[@LINE+17]]:4 = #1
if|if
condition|(
name|i
operator|<
literal|10
condition|)
block|{
comment|// CHECK: File 0, [[@LINE]]:16 -> [[@LINE+13]]:6 = #2
if|if
condition|(
name|i
operator|<
literal|5
condition|)
block|{
comment|// CHECK: File 0, [[@LINE]]:17 -> [[@LINE+3]]:8 = #3
continue|continue;
name|j
operator|=
literal|1
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:9 -> [[@LINE+1]]:8 = 0
block|}
else|else
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+2]]:8 = (#2 - #3)
name|j
operator|=
literal|2
expr_stmt|;
block|}
name|j
operator|=
literal|3
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE+6]]:6 = (#2 - #3)
if|if
condition|(
name|i
operator|<
literal|7
condition|)
block|{
comment|// CHECK: File 0, [[@LINE]]:17 -> [[@LINE+3]]:8 = #4
continue|continue;
name|j
operator|=
literal|4
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:9 -> [[@LINE+1]]:8 = 0
block|}
else|else
name|j
operator|=
literal|5
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE]]:19 = ((#2 - #3) - #4)
name|j
operator|=
literal|6
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE+1]]:6 = ((#2 - #3) - #4)
block|}
else|else
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:7 -> [[@LINE+1]]:12 = (#1 - #2)
name|j
operator|=
literal|7
expr_stmt|;
name|j
operator|=
literal|8
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE+1]]:4 = ((#1 - #3) - #4)
block|}
block|}
end_function

end_unit

