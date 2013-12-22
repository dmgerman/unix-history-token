begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t -triple=x86_64-apple-darwin10
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// Make sure this doesn't crash. We used to generate a byval here and wanted to
end_comment

begin_comment
comment|// verify a valid alignment, but we now realize we can use an i16 and let the
end_comment

begin_comment
comment|// backend guarantee the alignment.
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
comment|// CHECK-LABEL: define void @b
end_comment

begin_comment
comment|// CHECK: alloca { i8, i8 }*, align 8
end_comment

begin_comment
comment|// CHECK: call void @a(i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i16 {{.*}})
end_comment

end_unit

