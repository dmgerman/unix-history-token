begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|main
parameter_list|()
block|{
name|double
name|x
decl_stmt|;
name|x
operator|=
literal|10.000000000000477
expr_stmt|;
name|printf
argument_list|(
literal|"%30.20f = %x %x\n"
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|x
operator|=
literal|10.000000000000128
expr_stmt|;
name|printf
argument_list|(
literal|"%30.20f = %x %x\n"
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

