begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)bmove.c	2.1	11/5/80 */
end_comment

begin_expr_stmt
name|bmove
argument_list|(
name|s
argument_list|,
name|d
argument_list|,
name|l
argument_list|)
specifier|register
name|char
operator|*
name|s
operator|,
operator|*
name|d
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|l
operator|--
operator|>
literal|0
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
end_block

end_unit

