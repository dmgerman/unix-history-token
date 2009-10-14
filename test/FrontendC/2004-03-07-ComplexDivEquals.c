begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|test
parameter_list|(
name|__complex__
name|double
name|D
parameter_list|,
name|double
name|X
parameter_list|)
block|{
name|D
operator|/=
name|X
expr_stmt|;
block|}
end_function

end_unit

