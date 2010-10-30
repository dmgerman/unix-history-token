begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|int
name|dll_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|dll_func
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

