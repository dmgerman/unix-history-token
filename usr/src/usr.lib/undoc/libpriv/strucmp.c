begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)strucmp.c	4.1	(Melbourne)	82/02/21	*/
end_comment

begin_expr_stmt
name|strucmp
argument_list|(
name|p
argument_list|,
name|q
argument_list|,
name|s
argument_list|)
specifier|register
name|char
operator|*
name|p
operator|,
operator|*
name|q
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|--
name|s
operator|>=
literal|0
condition|)
if|if
condition|(
operator|*
name|p
operator|++
operator|!=
operator|*
name|q
operator|++
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

