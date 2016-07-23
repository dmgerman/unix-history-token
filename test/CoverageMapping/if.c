begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name if.c %s | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:12 -> {{[0-9]+}}:2 = #0
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:6 -> [[@LINE+1]]:12 = #0
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|i
operator|=
literal|1
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE]]:19 = #1
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:6 -> [[@LINE+1]]:12 = #0
if|if
condition|(
name|i
operator|==
literal|1
condition|)
name|i
operator|=
literal|2
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE]]:10 = #2
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:6 -> [[@LINE+1]]:12 = #0
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
name|i
operator|=
literal|1
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+2]]:4 = #3
name|i
operator|=
literal|2
expr_stmt|;
block|}
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:6 -> [[@LINE+1]]:12 = #0
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+2]]:4 = #4
name|i
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:10 -> [[@LINE+2]]:4 = (#0 - #4)
name|i
operator|=
literal|3
expr_stmt|;
block|}
name|i
operator|=
name|i
operator|==
literal|0
condition|?
name|i
operator|+
literal|1
else|:
comment|// CHECK-NEXT: File 0, [[@LINE]]:9 -> [[@LINE]]:14 = #5
name|i
operator|+
literal|2
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:9 -> [[@LINE]]:14 = (#0 - #5)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:14 -> [[@LINE+1]]:20 = #6
name|i
operator|=
name|i
operator|==
literal|0
condition|?
name|i
operator|+
literal|12
else|:
name|i
operator|+
literal|10
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:21 -> [[@LINE]]:27 = (#0 - #6)
return|return
literal|0
return|;
block|}
end_function

end_unit

