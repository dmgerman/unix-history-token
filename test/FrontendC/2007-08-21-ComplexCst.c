begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O2 -S %s -o /dev/null
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
specifier|_Complex
name|float
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|()
block|{
name|f
argument_list|(
literal|1.0i
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

