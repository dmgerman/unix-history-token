begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This routine is replaced by some modules if they need to do  * cleanup.  All exits in the code call done rather than exit.  */
end_comment

begin_macro
name|done
argument_list|(
argument|status
argument_list|)
end_macro

begin_block
block|{
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

