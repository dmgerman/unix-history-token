begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)imatch.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	initial match 	if `prefix' is a prefix of `string' return 1 	else return 0 */
end_comment

begin_expr_stmt
name|imatch
argument_list|(
name|prefix
argument_list|,
name|string
argument_list|)
specifier|register
name|char
operator|*
name|prefix
operator|,
operator|*
name|string
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|prefix
operator|++
operator|==
operator|*
name|string
operator|++
condition|)
if|if
condition|(
operator|*
name|prefix
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

