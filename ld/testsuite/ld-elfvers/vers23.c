begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|extern
name|void
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|bar
argument_list|()
expr_stmt|;
name|foo
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

