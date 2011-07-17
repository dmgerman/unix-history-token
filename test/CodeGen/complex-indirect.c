begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-apple-darwin10 | FileCheck %s
end_comment

begin_comment
comment|// Make sure this doesn't crash, and that we don't generate a byval alloca
end_comment

begin_comment
comment|// with insufficient alignment.
end_comment

begin_function_decl
name|void
name|a
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|__complex__
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|b
parameter_list|(
name|__complex__
name|char
modifier|*
name|y
parameter_list|)
block|{
name|a
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @b
end_comment

begin_comment
comment|// CHECK: alloca { i8, i8 }*, align 8
end_comment

begin_comment
comment|// CHECK: call void @a(i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, { i8, i8 }* byval align 8
end_comment

end_unit

