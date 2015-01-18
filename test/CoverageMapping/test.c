begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name test.c %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|static_func
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+7]]:2 = #0 (HasCodeBefore = 0)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:18 -> [[@LINE+1]]:24 = (#0 + #1) (HasCodeBefore = 0)
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
comment|// CHECK-NEXT: File 0, [[@LINE]]:26 -> [[@LINE]]:29 = #1 (HasCodeBefore = 0)
name|bar
argument_list|()
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE-1]]:31 -> [[@LINE+1]]:4 = #1 (HasCodeBefore = 0)
block|}
name|static_func
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: foo
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+4]]:2 = #0 (HasCodeBefore = 0)
if|if
condition|(
literal|1
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:9 -> [[@LINE+2]]:4 = #1 (HasCodeBefore = 0)
name|int
name|i
init|=
literal|0
decl_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-NEXT: bar
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+1]]:2 = #0 (HasCodeBefore = 0)
block|}
end_function

begin_comment
comment|// CHECK-NEXT: static_func
end_comment

begin_function
name|void
name|static_func
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK: File 0, [[@LINE]]:20 -> [[@LINE]]:23 = #0 (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: func
end_comment

begin_function
specifier|static
name|void
name|func
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK: File 0, [[@LINE]]:20 -> [[@LINE]]:23 = 0 (HasCodeBefore = 0)
end_comment

end_unit

