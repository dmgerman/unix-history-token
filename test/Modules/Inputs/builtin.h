begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|p
init|=
operator|&
name|i
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|use_constant_string_builtins
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|""
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin___NSStringMakeConstantString
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

