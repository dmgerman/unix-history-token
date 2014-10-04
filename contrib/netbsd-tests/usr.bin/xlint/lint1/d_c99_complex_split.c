begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|b
parameter_list|(
name|double
name|a
parameter_list|)
block|{
return|return
name|a
operator|==
literal|0
return|;
block|}
end_function

begin_function
name|void
name|a
parameter_list|(
name|void
parameter_list|)
block|{
name|double
specifier|_Complex
name|z
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|b
argument_list|(
argument|__real__ z
argument_list|)
operator|&&
name|b
argument_list|(
argument|__imag__ z
argument_list|)
condition|)
return|return;
block|}
end_function

end_unit

