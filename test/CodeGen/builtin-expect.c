begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
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

end_unit

