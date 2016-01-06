begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|extern
name|int
name|call_through_indirect
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|fake_call_through_reexport
parameter_list|(
name|int
name|value
parameter_list|)
block|{
return|return
name|value
operator|+
literal|10
return|;
block|}
end_function

end_unit

