begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|fake_a_gnumalloc_lib
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|cfree
parameter_list|(
name|void
modifier|*
name|foo
parameter_list|)
block|{
name|free
argument_list|(
name|foo
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

