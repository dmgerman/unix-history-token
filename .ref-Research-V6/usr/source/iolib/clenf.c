begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|_clenf
argument_list|(
argument|s
argument_list|)
end_macro

begin_comment
comment|/* counts length of string */
end_comment

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
operator|*
name|s
operator|++
operator|!=
literal|'\0'
condition|;
name|n
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

end_unit

