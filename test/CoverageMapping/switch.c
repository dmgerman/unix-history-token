begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name switch.c %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: foo
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:17 -> [[@LINE+8]]:2 = #0
switch|switch
condition|(
name|i
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+5]]:4 = #1
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+3]]:10 = #2
return|return;
case|case
literal|2
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #3
break|break;
block|}
name|int
name|x
init|=
literal|0
decl_stmt|;
block|}
end_function

begin_function
name|void
name|nop
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: bar
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:17 -> [[@LINE+20]]:2 = #0
switch|switch
condition|(
name|i
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:6 = #1
empty_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE]]:6 = 0
switch|switch
condition|(
name|i
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:4 = #2
block|}
switch|switch
condition|(
name|i
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #3
name|nop
argument_list|()
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE]]:10 = 0
switch|switch
condition|(
name|i
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+2]]:10 = #4
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #5
name|nop
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+4]]:4 = #6
name|nop
argument_list|()
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE+2]]:10 = 0
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #7
name|nop
argument_list|()
expr_stmt|;
block|}
name|nop
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+34]]:2 = #0
name|int
name|i
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+9]]:4 = #1
case|case
literal|0
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+7]]:10 = #2
name|i
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+2]]:10 = #3
name|i
operator|=
literal|2
expr_stmt|;
break|break;
default|default:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #4
break|break;
block|}
switch|switch
condition|(
name|i
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+8]]:4 = #5
case|case
literal|0
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+6]]:10 = #6
name|i
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+3]]:10 = #7
name|i
operator|=
literal|2
expr_stmt|;
default|default:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = (#7 + #8)
break|break;
block|}
switch|switch
condition|(
name|i
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+7]]:4 = #9
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+5]]:11 = #10
case|case
literal|2
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+4]]:11 = (#10 + #11)
name|i
operator|=
literal|11
expr_stmt|;
case|case
literal|3
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+2]]:11 = ((#10 + #11) + #12)
case|case
literal|4
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:11 = (((#10 + #11) + #12) + #13)
name|i
operator|=
literal|99
expr_stmt|;
block|}
name|foo
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|bar
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

