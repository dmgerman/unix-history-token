begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)strlen.c	4.1 (Berkeley) 12/21/80 */
end_comment

begin_comment
comment|/*  * Returns the number of  * non-NULL bytes in string argument.  */
end_comment

begin_expr_stmt
name|strlen
argument_list|(
name|s
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|n
expr_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|s
operator|++
condition|)
name|n
operator|++
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

end_unit

