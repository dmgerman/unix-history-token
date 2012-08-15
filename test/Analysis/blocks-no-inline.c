begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -analyze -analyzer-checker=core,debug.ExprInspection -analyzer-ipa=none -fblocks -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testInvalidation
parameter_list|()
block|{
specifier|__block
name|int
name|i
init|=
literal|0
decl_stmt|;
lambda|^
block|{
operator|++
name|i
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
comment|// Under inlining, we will know that i == 1.
name|clang_analyzer_eval
argument_list|(
name|i
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

end_unit

