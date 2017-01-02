begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR14355: don't crash
end_comment

begin_comment
comment|// Keep this test in its own file because CodeGenTypes has global state.
end_comment

begin_comment
comment|// CHECK: define void @test10_foo({}* %p1.coerce) [[NUW:#[0-9]+]] {
end_comment

begin_struct_decl
struct_decl|struct
name|test10_B
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|test10_B
name|test10_F3
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|test10_foo
parameter_list|(
name|test10_F3
name|p1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|test10_B
name|test10_b
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test10_bar
parameter_list|()
block|{
name|test10_foo
argument_list|(
name|test10_b
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|test10_B
block|{}
struct|;
end_struct

begin_function
name|void
name|test10_foo
parameter_list|(
name|test10_F3
name|p1
parameter_list|)
block|{
name|p1
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

end_unit

