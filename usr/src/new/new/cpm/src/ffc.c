begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ffc.c	1.4	83/05/13	*/
end_comment

begin_comment
comment|/*  * If used on a vax (i.e., VAX is defined), this routine simply executes  * the VAX find-first-set instruction.  * Usage:  *	int startbit, field_lth, field, result;  *	result = ffc(startbit,field_lth,field);  *  * startbit is the bit number of the field to start the search,  *		the rightmost bit is number one.  * field_lth is the length of the field in bits.  * field is the actual field  * result is the resulting bit number,  *		e.g. the number of the first clear bit in the field.  * hs 10/29/82  */
end_comment

begin_expr_stmt
name|ffc
argument_list|(
name|start
argument_list|,
name|len
argument_list|,
name|field
argument_list|)
ifndef|#
directive|ifndef
name|VAX
specifier|register
name|long
name|field
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|start
decl_stmt|,
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|start
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|field
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
break|break;
name|field
operator|>>=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|start
decl_stmt|,
name|len
decl_stmt|,
name|field
decl_stmt|;
end_decl_stmt

begin_block
block|{
asm|asm("ffc	4(ap),8(ap),12(ap),r0");
return|return;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

