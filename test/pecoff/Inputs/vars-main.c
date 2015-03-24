begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|var
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|int
name|fn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|int
name|_name_with_underscore
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
return|return
name|var
operator|+
name|fn
argument_list|()
operator|+
name|_name_with_underscore
argument_list|()
return|;
block|}
end_function

end_unit

