begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|main
parameter_list|()
block|{
name|f
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|f
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|f
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|int
name|ownx
decl_stmt|;
name|ownx
operator|=
name|x
expr_stmt|;
block|}
end_block

end_unit

