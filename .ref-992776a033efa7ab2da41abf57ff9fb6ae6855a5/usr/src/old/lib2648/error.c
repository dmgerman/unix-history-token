begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	error.c	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * error: default handling of errors.  */
end_comment

begin_macro
name|error
argument_list|(
argument|msg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|message
argument_list|(
name|msg
argument_list|)
expr_stmt|;
comment|/* Maybe it would be nice to longjmp somewhere here */
block|}
end_block

end_unit

