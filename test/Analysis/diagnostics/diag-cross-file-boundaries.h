begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
specifier|static
name|void
name|f
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
block|}
end_function

end_unit

