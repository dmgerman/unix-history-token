begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******  *	prefix(s1, s2)	check s2 for prefix s1  *	char *s1, *s2;  *  *	return 0 - !=  *	return 1 - ==   */
end_comment

begin_macro
name|prefix
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|s1
operator|++
operator|)
operator|==
operator|*
name|s2
operator|++
condition|)
if|if
condition|(
name|c
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
name|c
operator|==
literal|'\0'
operator|)
return|;
block|}
end_block

end_unit

