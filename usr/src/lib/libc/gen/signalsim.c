begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	signalsim.c	4.1	83/06/04	*/
end_comment

begin_comment
comment|/*  * Backwards compatible signal.  */
end_comment

begin_macro
name|signal
argument_list|(
argument|s
argument_list|,
argument|a
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
name|sigvec
argument_list|(
name|s
argument_list|,
name|a
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

