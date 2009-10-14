begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o -
end_comment

begin_comment
comment|// rdar://7208839
end_comment

begin_function
specifier|extern
specifier|inline
name|int
name|f1
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
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f1
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

