begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test of dynamic name resolution.  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
literal|2
expr_stmt|;
name|p
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|p
argument_list|(
argument|j
argument_list|)
end_macro

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|k
decl_stmt|;
name|k
operator|=
name|j
expr_stmt|;
block|}
end_block

end_unit

