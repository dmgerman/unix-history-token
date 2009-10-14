begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function_decl
specifier|static
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|C
parameter_list|)
name|char
name|C
decl_stmt|;
block|{
return|return
name|C
return|;
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
name|foo
argument_list|(
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

