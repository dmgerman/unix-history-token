begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|char
modifier|*
name|crypt
parameter_list|(
name|k
parameter_list|,
name|s
parameter_list|)
name|char
modifier|*
name|k
decl_stmt|,
decl|*
name|s
decl_stmt|;
end_function

begin_block
block|{
name|write
argument_list|(
literal|2
argument_list|,
literal|"Crypt not present in system\n"
argument_list|,
literal|29
argument_list|)
expr_stmt|;
return|return
operator|(
name|k
operator|)
return|;
block|}
end_block

end_unit

