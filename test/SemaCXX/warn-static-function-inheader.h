begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
specifier|static
name|void
name|thing
parameter_list|(
name|void
parameter_list|)
block|{
comment|// expected-warning {{'static' function 'thing' declared in header file should be declared 'static inline'}}
block|}
end_function

end_unit

