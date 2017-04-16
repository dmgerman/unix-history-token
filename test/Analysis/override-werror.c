begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core -Werror %s -analyzer-store=region -verify
end_comment

begin_comment
comment|// This test case illustrates that using '-analyze' overrides the effect of
end_comment

begin_comment
comment|// -Werror.  This allows basic warnings not to interfere with producing
end_comment

begin_comment
comment|// analyzer results.
end_comment

begin_function
name|char
modifier|*
name|f
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
return|;
comment|// expected-warning{{incompatible pointer types}}
block|}
end_function

begin_function
name|void
name|g
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
operator|!
name|p
condition|)
operator|*
name|p
operator|=
literal|0
expr_stmt|;
comment|// expected-warning{{null}}
block|}
end_function

end_unit

