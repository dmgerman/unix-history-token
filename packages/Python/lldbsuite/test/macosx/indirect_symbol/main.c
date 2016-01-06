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

begin_function_decl
specifier|extern
name|int
name|reexport_to_indirect
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|indirect_result
init|=
name|call_through_indirect
argument_list|(
literal|20
argument_list|)
decl_stmt|;
comment|// Set breakpoint here to step in indirect.
name|indirect_result
operator|=
name|call_through_indirect
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|int
name|reexport_result
init|=
name|reexport_to_indirect
argument_list|(
literal|20
argument_list|)
decl_stmt|;
comment|// Set breakpoint here to step in reexported.
name|reexport_result
operator|=
name|reexport_to_indirect
argument_list|(
literal|30
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

