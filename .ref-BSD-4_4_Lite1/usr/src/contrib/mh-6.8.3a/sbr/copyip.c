begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* copyip.c - copy a string array and return pointer to end */
end_comment

begin_function
name|char
modifier|*
modifier|*
name|copyip
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
specifier|register
name|char
modifier|*
modifier|*
name|p
decl_stmt|,
decl|*
modifier|*
name|q
decl_stmt|;
end_function

begin_block
block|{
while|while
condition|(
operator|*
name|p
condition|)
operator|*
name|q
operator|++
operator|=
operator|*
name|p
operator|++
expr_stmt|;
operator|*
name|q
operator|=
literal|0
expr_stmt|;
return|return
name|q
return|;
block|}
end_block

end_unit

