begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_macro
name|p2
argument_list|(
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|i
operator|<
literal|5
condition|)
block|{
name|p2
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|p1
argument_list|(
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|p2
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|main
parameter_list|()
block|{
name|i
operator|=
literal|0
expr_stmt|;
name|p1
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

