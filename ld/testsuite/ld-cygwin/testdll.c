begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|extern
name|void
name|exewrite
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute
argument_list|(
argument|(dllimport)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|global_a
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|dllwrite
parameter_list|(
name|void
parameter_list|)
block|{
name|global_a
operator|=
literal|3
expr_stmt|;
name|exewrite
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|_stdcall
name|testdll_main
parameter_list|(
name|int
name|p1
parameter_list|,
name|unsigned
name|long
name|p2
parameter_list|,
name|void
modifier|*
name|p3
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

end_unit

