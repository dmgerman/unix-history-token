begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)swab.c	4.1 (Berkeley) %G% */
end_comment

begin_comment
comment|/*  * Swap bytes in 16-bit [half-]words  * for going between the 11 and the interdata  */
end_comment

begin_expr_stmt
name|swab
argument_list|(
name|pf
argument_list|,
name|pt
argument_list|,
name|n
argument_list|)
specifier|register
name|short
operator|*
name|pf
operator|,
operator|*
name|pt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|n
operator|/=
literal|2
expr_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
block|{
operator|*
name|pt
operator|++
operator|=
operator|(
operator|*
name|pf
operator|<<
literal|8
operator|)
operator|+
operator|(
operator|(
operator|*
name|pf
operator|>>
literal|8
operator|)
operator|&
literal|0377
operator|)
expr_stmt|;
name|pf
operator|++
expr_stmt|;
block|}
block|}
end_block

end_unit

