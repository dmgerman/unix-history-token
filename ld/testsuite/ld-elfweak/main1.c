begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|weak
name|deallocate_foo
end_pragma

begin_decl_stmt
name|int
name|deallocate_foo
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|foobar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|foobar
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

