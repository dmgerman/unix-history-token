begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|getBos1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

