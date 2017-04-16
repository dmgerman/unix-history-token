begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Test when entering f1(), we set the right AnalysisDeclContext to Environment.
end_comment

begin_comment
comment|// Otherwise, block-level expr '1&& a' would not be block-level.
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{
if|if
condition|(
literal|1
operator|&&
name|a
condition|)
return|return;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|f1
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

