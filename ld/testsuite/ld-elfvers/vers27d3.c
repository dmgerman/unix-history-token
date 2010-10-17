begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|extern
name|void
name|ref
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
name|void
name|_start
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
name|ref
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__start
parameter_list|()
block|{
name|_start
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|start
parameter_list|()
block|{
name|__start
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

