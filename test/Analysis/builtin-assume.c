begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -verify %s
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
name|f
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|__builtin_assume
argument_list|(
name|i
operator|<
literal|10
argument_list|)
expr_stmt|;
name|clang_analyzer_eval
argument_list|(
name|i
operator|<
literal|15
argument_list|)
expr_stmt|;
comment|// expected-warning {{TRUE}}
block|}
end_function

end_unit

