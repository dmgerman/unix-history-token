begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|func
operator|=
name|foo
expr_stmt|;
name|func
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

