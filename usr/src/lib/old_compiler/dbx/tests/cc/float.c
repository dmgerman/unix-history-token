begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test of floats and doubles.  */
end_comment

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
name|float
name|y
decl_stmt|;
name|y
operator|=
literal|3.0
expr_stmt|;
name|x
operator|=
name|f
argument_list|(
name|y
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

