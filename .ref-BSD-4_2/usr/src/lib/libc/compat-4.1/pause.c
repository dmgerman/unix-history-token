begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pause.c	4.1	83/06/09	*/
end_comment

begin_comment
comment|/*  * Backwards compatible pause.  */
end_comment

begin_macro
name|pause
argument_list|()
end_macro

begin_block
block|{
name|sigpause
argument_list|(
name|sigblock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

