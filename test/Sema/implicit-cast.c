begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s
end_comment

begin_function
specifier|static
name|char
modifier|*
name|test1
parameter_list|(
name|int
name|cf
parameter_list|)
block|{
return|return
name|cf
condition|?
literal|"abc"
else|:
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|test2
parameter_list|(
name|int
name|cf
parameter_list|)
block|{
return|return
name|cf
condition|?
literal|0
else|:
literal|"abc"
return|;
block|}
end_function

end_unit

