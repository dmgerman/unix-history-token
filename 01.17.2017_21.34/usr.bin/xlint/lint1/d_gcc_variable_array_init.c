begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gcc: variable array initializer */
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|array
index|[
name|i
index|]
decl_stmt|;
while|while
condition|(
name|i
operator|--
condition|)
name|foo
argument_list|(
name|array
index|[
name|i
index|]
operator|=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

