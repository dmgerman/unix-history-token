begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* Test problem where bad code was generated with a ?: statement was     in a function call argument */
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|foo
argument_list|(
name|x
argument_list|,
name|x
condition|?
literal|1.0
else|:
literal|12.5
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

