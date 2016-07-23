begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name loops.cpp %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+8]]:2 = #0
name|int
name|j
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:9 -> [[@LINE+1]]:14 = (#0 + #1)
while|while
condition|(
name|j
operator|<
literal|5
condition|)
operator|++
name|j
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:16 -> [[@LINE]]:19 = #1
name|j
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|j
operator|<
literal|5
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE]]:10 = (#0 + #2)
operator|++
name|j
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:6 -> [[@LINE]]:9 = #2
return|return
literal|0
return|;
block|}
end_function

end_unit

