begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  **	put a string to the standard output  **/
end_comment

begin_macro
name|puts
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
name|c
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|s
init|;
name|c
operator|=
operator|*
name|p
operator|++
condition|;
control|)
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_block

end_unit

