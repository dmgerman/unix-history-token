begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name switch.c %s | FileCheck %s
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
comment|// CHECK-NEXT: File 0, [[@LINE]]:17 -> [[@LINE+8]]:2 = #0 (HasCodeBefore = 0)
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:11 = #2 (HasCodeBefore = 0)
return|return;
case|case
literal|2
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #3 (HasCodeBefore = 0)
break|break;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:12 = #1 (HasCodeBefore = 0)
name|int
name|x
init|=
literal|0
decl_stmt|;
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
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+34]]:2 = #0 (HasCodeBefore = 0)
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
case|case
literal|0
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+2]]:10 = #2 (HasCodeBefore = 0)
name|i
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+2]]:10 = #3 (HasCodeBefore = 0)
name|i
operator|=
literal|2
expr_stmt|;
break|break;
default|default:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #4 (HasCodeBefore = 0)
break|break;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:14 = #1 (HasCodeBefore = 0)
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|0
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+2]]:10 = #6 (HasCodeBefore = 0)
name|i
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = #7 (HasCodeBefore = 0)
name|i
operator|=
literal|2
expr_stmt|;
default|default:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:10 = (#7 + #8) (HasCodeBefore = 0)
break|break;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+3]]:14 = #5 (HasCodeBefore = 0)
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE]]:10 = #10 (HasCodeBefore = 0)
case|case
literal|2
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:11 = (#10 + #11) (HasCodeBefore = 0)
name|i
operator|=
literal|11
expr_stmt|;
case|case
literal|3
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE]]:10 = ((#10 + #11) + #12) (HasCodeBefore = 0)
case|case
literal|4
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:11 = (((#10 + #11) + #12) + #13) (HasCodeBefore = 0)
name|i
operator|=
literal|99
expr_stmt|;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+3]]:11 = #9 (HasCodeBefore = 0)
name|foo
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

