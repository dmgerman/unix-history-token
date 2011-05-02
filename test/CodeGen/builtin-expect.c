begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|y
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|FUNC
parameter_list|()
block|{
comment|// CHECK: [[call:%.*]] = call i32 @y
if|if
condition|(
name|__builtin_expect
argument_list|(
name|x
argument_list|,
name|y
argument_list|()
argument_list|)
condition|)
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://9330105
end_comment

begin_function_decl
name|void
name|isigprocmask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__builtin_expect
argument_list|(
operator|(
name|isigprocmask
argument_list|()
operator|,
literal|0
operator|)
argument_list|,
name|bar
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call void @isigprocmask()
end_comment

begin_comment
comment|// CHECK: [[C:%.*]] = call i64 (...)* @bar()
end_comment

end_unit

