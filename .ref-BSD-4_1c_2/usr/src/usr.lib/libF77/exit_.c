begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|exit_
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|exit
argument_list|(
operator|(
name|int
operator|)
operator|*
name|n
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

