begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|void
modifier|*
name|foo
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
return|;
comment|// break here
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{
name|foo
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

