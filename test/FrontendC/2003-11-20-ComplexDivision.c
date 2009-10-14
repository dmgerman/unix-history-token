begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|int
name|test
parameter_list|()
block|{
name|__complex__
name|double
name|C
decl_stmt|;
name|double
name|D
decl_stmt|;
name|C
operator|/
name|D
expr_stmt|;
block|}
end_function

end_unit

