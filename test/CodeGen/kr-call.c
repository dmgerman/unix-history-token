begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-unknown-linux -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test that we don't crash.  The s390x-unknown-linux target happens
end_comment

begin_comment
comment|// to need to set a sext argument attribute on this call, and we need
end_comment

begin_comment
comment|// to make sure that rewriting it correctly keeps that attribute.
end_comment

begin_function_decl
name|void
name|test0_helper
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test0
parameter_list|()
block|{
comment|// CHECK: call void bitcast (void ()* @test0_helper to void (i32)*)(i32 signext 1)
name|test0_helper
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test0_helper
parameter_list|()
block|{}
end_function

end_unit

