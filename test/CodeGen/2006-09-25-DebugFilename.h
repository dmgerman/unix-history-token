begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|extern
name|int
name|exfunc
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|hfunc1
parameter_list|()
block|{
return|return
name|exfunc
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

