begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|Foo
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|Foo
modifier|*
name|GetAFoo
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|GetAFoo
argument_list|()
operator|->
name|b
return|;
block|}
end_function

end_unit

