begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	exit.c	1.1	83/06/23	*/
end_comment

begin_macro
name|exit
argument_list|(
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|_cleanup
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

