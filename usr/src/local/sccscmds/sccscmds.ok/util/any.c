begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)any.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	If any character of `s' is `c', return 1 	else return 0. */
end_comment

begin_expr_stmt
name|any
argument_list|(
name|c
argument_list|,
name|s
argument_list|)
specifier|register
name|char
name|c
operator|,
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|s
condition|)
if|if
condition|(
operator|*
name|s
operator|++
operator|==
name|c
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

