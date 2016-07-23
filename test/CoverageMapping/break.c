begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name break.c %s | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:12 -> {{[0-9]+}}:2 = #0
name|int
name|cnt
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:9 -> [[@LINE+1]]:18 = #0
while|while
condition|(
name|cnt
operator|<
literal|100
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:20 -> [[@LINE+3]]:4 = #1
break|break;
operator|++
name|cnt
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE+1]]:4 = 0
block|}
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:9 -> [[@LINE+1]]:18 = #0
while|while
condition|(
name|cnt
operator|<
literal|100
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:20 -> [[@LINE+6]]:4 = #2
block|{
break|break;
operator|++
name|cnt
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE+3]]:4 = 0
block|}
operator|++
name|cnt
expr_stmt|;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:9 -> [[@LINE+1]]:18 = ((#0 + #3) - #4)
while|while
condition|(
name|cnt
operator|<
literal|100
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:20 -> [[@LINE+7]]:4 = #3
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:8 -> [[@LINE+1]]:16 = #3
if|if
condition|(
name|cnt
operator|==
literal|0
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:18 -> [[@LINE+3]]:6 = #4
break|break;
operator|++
name|cnt
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE+1]]:6 = 0
block|}
operator|++
name|cnt
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE+1]]:4 = (#3 - #4)
block|}
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:9 -> [[@LINE+1]]:18 = (#0 + #6)
while|while
condition|(
name|cnt
operator|<
literal|100
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:20 -> [[@LINE+8]]:4 = #5
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:8 -> [[@LINE+1]]:16 = #5
if|if
condition|(
name|cnt
operator|==
literal|0
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:18 -> [[@LINE+2]]:6 = #6
operator|++
name|cnt
expr_stmt|;
block|}
else|else
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+2]]:6 = (#5 - #6)
break|break;
block|}
operator|++
name|cnt
expr_stmt|;
block|}
block|}
end_function

end_unit

