begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is used to test the linker's reporting of undefined    symbols.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|this_function_is_not_defined
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|function
parameter_list|()
block|{
return|return
name|this_function_is_not_defined
argument_list|()
return|;
block|}
end_function

end_unit

