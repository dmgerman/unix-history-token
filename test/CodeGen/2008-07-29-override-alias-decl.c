begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|int
name|x
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK:  ret i32 1
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"x"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Test that we link to the alias correctly instead of making a new    forward definition. */
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|h
parameter_list|()
block|{
return|return
name|f
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK:  [[call:%.*]] = call i32 (...)* @f()
end_comment

begin_comment
comment|// CHECK:  ret i32 [[call]]
end_comment

end_unit

