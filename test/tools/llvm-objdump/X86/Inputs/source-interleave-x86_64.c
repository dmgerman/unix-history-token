begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|a
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
modifier|*
name|b
init|=
operator|&
name|a
decl_stmt|;
return|return
operator|*
name|b
operator|+
name|foo
argument_list|()
return|;
block|}
end_function

end_unit

