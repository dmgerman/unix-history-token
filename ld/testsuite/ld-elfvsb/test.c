begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|weak
name|main_hidden_data
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|main_hidden_data
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden main_hidden_data");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|main_hidden_func
end_pragma

begin_function_decl
specifier|extern
name|int
name|main_hidden_func
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".hidden main_hidden_func");
end_asm

begin_function
name|int
name|_start
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|&
name|main_hidden_data
operator|!=
literal|0
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|main_hidden_func
operator|!=
literal|0
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|int
name|__start
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|_start
argument_list|()
return|;
block|}
end_function

end_unit

