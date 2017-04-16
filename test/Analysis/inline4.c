begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|int
name|g
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
comment|// Do not remove block-level expression bindings of caller when analyzing
comment|// in the callee.
if|if
condition|(
literal|1
operator|&&
name|g
argument_list|(
name|a
argument_list|)
condition|)
comment|// The binding of '1&& g(a)' which is an UndefinedVal
comment|// carries important information.
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

