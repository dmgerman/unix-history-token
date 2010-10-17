begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|deallocate_foo
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|foo
parameter_list|()
block|{
return|return
operator|&
name|deallocate_foo
return|;
block|}
end_function

end_unit

