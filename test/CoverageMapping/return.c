begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name return.c %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: func
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:13 -> [[@LINE+3]]:2 = #0
return|return;
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:2 = 0
block|}
end_function

begin_comment
comment|// CHECK-NEXT: func2
end_comment

begin_function
name|void
name|func2
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> {{[0-9]+}}:2 = #0
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:18 -> [[@LINE+2]]:24 = ((#0 + #1) - #2)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:26 -> [[@LINE+1]]:29 = (#1 - #2)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:31 -> {{[0-9]+}}:4 = #1
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:8 -> [[@LINE+1]]:13 = #1
if|if
condition|(
name|i
operator|>
literal|2
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:15 -> [[@LINE+2]]:6 = #2
return|return;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:5 -> {{[0-9]+}}:4 = (#1 - #2)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:8 -> [[@LINE+1]]:14 = (#1 - #2)
if|if
condition|(
name|i
operator|==
literal|3
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:16 -> [[@LINE+2]]:6 = #3
name|int
name|j
init|=
literal|1
decl_stmt|;
block|}
else|else
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+2]]:6 = ((#1 - #2) - #3)
name|int
name|j
init|=
literal|2
decl_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|// CHECK-NEXT: func3
end_comment

begin_function
name|void
name|func3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:19 -> {{[0-9]+}}:2 = #0
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:6 -> [[@LINE+1]]:11 = #0
if|if
condition|(
name|x
operator|>
literal|5
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:13 -> [[@LINE+6]]:4 = #1
while|while
condition|(
name|x
operator|>=
literal|9
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:11 -> [[@LINE]]:17 = #1
return|return;
comment|// CHECK-NEXT: File 0, [[@LINE-1]]:19 -> [[@LINE+2]]:6 = #2
operator|--
name|x
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE+1]]:6 = 0
block|}
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE+1]]:4 = (#1 - #2)
block|}
name|int
name|j
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:2 = (#0 - #2)
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|func
argument_list|()
expr_stmt|;
name|func2
argument_list|()
expr_stmt|;
name|func3
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

