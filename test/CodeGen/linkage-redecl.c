begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test2_i = internal global i32 99
end_comment

begin_decl_stmt
specifier|static
name|int
name|test2_i
init|=
literal|99
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test2_f
parameter_list|()
block|{
specifier|extern
name|int
name|test2_i
decl_stmt|;
return|return
name|test2_i
return|;
block|}
end_function

begin_comment
comment|// C99 6.2.2p3
end_comment

begin_comment
comment|// PR3425
end_comment

begin_function_decl
specifier|static
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g0
parameter_list|()
block|{
name|f
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{ }
end_function

begin_comment
comment|// still has internal linkage
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @f
end_comment

end_unit

