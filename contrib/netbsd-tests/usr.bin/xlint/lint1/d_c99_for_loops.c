begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* c99 for loops */
end_comment

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
comment|// Test the basic functionality
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|foo
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|// Test that the scope of the iterator is correct
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
continue|continue;
return|return
literal|0
return|;
block|}
end_function

end_unit

