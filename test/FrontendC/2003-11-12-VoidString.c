begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|query_newnamebuf
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
operator|(
name|void
operator|)
literal|"query_newnamebuf"
operator|)
expr_stmt|;
block|}
end_function

end_unit

