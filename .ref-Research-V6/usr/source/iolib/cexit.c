begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|cexit
argument_list|(
argument|rcode
argument_list|)
end_macro

begin_block
block|{
comment|/* closes all files and exits */
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|cclose
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|rcode
argument_list|)
expr_stmt|;
comment|/* rcode courtesy of sny */
block|}
end_block

end_unit

