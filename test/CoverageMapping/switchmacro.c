begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name switchmacro.c %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|FOO
parameter_list|(
name|x
parameter_list|)
value|(void)x
end_define

begin_comment
comment|// CHECK: foo
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:16 -> {{[0-9]+}}:2 = #0
switch|switch
condition|(
name|i
condition|)
block|{
default|default:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> {{[0-9]+}}:11 = #2
if|if
condition|(
name|i
operator|==
literal|1
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:9 -> [[@LINE]]:15 = #2
return|return
literal|0
return|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE]]:15 = #3
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:5 -> [[@LINE+2]]:8 = (#2 - #3)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:8 -> {{[0-9]+}}:11 = (#2 - #3)
name|FOO
argument_list|(
literal|1
argument_list|)
expr_stmt|;
case|case
literal|0
case|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE+1]]:13 = ((#2 + #4) - #3)
return|return
literal|2
return|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:3 -> [[@LINE+2]]:6 = 0
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:6 -> {{[0-9]+}}:11 = 0
name|FOO
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:3 -> {{[0-9]+}}:11 = #5
name|label
label|:
empty_stmt|;
block|}
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
name|foo
argument_list|(
literal|3
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

