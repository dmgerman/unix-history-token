begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)privzero.c	4.1	(Melbourne)	82/01/04	*/
end_comment

begin_expr_stmt
name|privzero
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
specifier|register
name|char
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* r11 */
end_comment

begin_expr_stmt
specifier|register
name|size
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* r10 */
end_comment

begin_block
block|{
asm|asm("movc5 $0, (r11), $0, r10, (r11)");
block|}
end_block

end_unit

