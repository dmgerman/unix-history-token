begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.DumpTraversal %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|inline_callee
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: --BEGIN FUNCTION--
end_comment

begin_function
name|void
name|inline_caller
parameter_list|()
block|{
comment|// CHECK: --BEGIN FUNCTION--
comment|// CHECK: --BEGIN FUNCTION--
comment|// CHECK: --BEGIN FUNCTION--
name|inline_callee
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: --END FUNCTION--
comment|// CHECK: --END FUNCTION--
comment|// CHECK: --END FUNCTION--
block|}
end_function

begin_comment
comment|// CHECK: --END FUNCTION--
end_comment

begin_function
name|void
name|inline_callee
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
operator|<=
literal|1
condition|)
return|return;
name|inline_callee
argument_list|(
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

