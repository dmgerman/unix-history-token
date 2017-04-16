begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Test parameter 'a' is registered to LiveVariables analysis data although it
end_comment

begin_comment
comment|// is not referenced in the function body.
end_comment

begin_comment
comment|// Before processing 'return 1;', in RemoveDeadBindings(), we query the liveness
end_comment

begin_comment
comment|// of 'a', because we have a binding for it due to parameter passing.
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|x
operator|=
name|f1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

