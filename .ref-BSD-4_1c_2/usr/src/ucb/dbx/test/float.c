begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|double
name|f
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
return|return
literal|3.14
operator|*
name|x
return|;
block|}
end_function

begin_function
name|main
parameter_list|()
block|{
name|double
name|x
decl_stmt|;
name|x
operator|=
name|f
argument_list|(
literal|3.0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

