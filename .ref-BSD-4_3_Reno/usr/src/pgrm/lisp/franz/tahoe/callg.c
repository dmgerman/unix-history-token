begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * callg_ - call with 'general' argument list for CCI `tahoe'  *  * by P. S. Housel 04/30/86  *  */
end_comment

begin_expr_stmt
name|callg_
argument_list|(
name|funct
argument_list|,
name|arglist
argument_list|)
specifier|register
name|int
argument_list|(
operator|*
name|funct
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* r12 */
end_comment

begin_decl_stmt
specifier|register
name|int
modifier|*
name|arglist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* r11 */
end_comment

begin_block
block|{
specifier|register
name|int
modifier|*
name|argptr
decl_stmt|,
name|n
decl_stmt|;
comment|/* r10, r9 */
name|n
operator|=
operator|(
operator|*
name|arglist
operator|+
literal|1
operator|)
operator|*
literal|4
expr_stmt|;
name|argptr
operator|=
name|arglist
operator|+
operator|*
name|arglist
expr_stmt|;
while|while
condition|(
name|argptr
operator|>
name|arglist
condition|)
block|{
asm|asm("pushl	(r10)");
name|argptr
operator|--
expr_stmt|;
block|}
asm|asm("	calls	r9,(r12)");
block|}
end_block

end_unit

