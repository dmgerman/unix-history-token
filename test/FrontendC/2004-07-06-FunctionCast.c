begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
specifier|static
name|int
name|unused_func
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|unused_func
expr_stmt|;
comment|/* avoid compiler warning */
return|return
literal|2
return|;
block|}
end_function

end_unit

