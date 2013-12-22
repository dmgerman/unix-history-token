begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// PR5599
end_comment

begin_function_decl
name|void
name|test1_f
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test1_g
parameter_list|(
name|void
parameter_list|)
block|{
name|float
name|x
index|[
literal|4
index|]
decl_stmt|;
name|test1_f
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test1_g
end_comment

begin_comment
comment|// CHECK: alloca [4 x float], align 16
end_comment

end_unit

