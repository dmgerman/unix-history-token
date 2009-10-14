begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_function
name|void
name|bar
parameter_list|()
block|{
name|foo
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|/* Too many arguments passed */
block|}
end_function

end_unit

