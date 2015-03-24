begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|c
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|fn
parameter_list|()
block|{
name|c
operator|=
literal|20
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|fn1
parameter_list|()
block|{
return|return
name|fn
argument_list|()
return|;
block|}
end_function

end_unit

