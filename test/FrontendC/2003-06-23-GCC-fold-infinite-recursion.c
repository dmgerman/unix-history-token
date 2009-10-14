begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|double
name|Test
parameter_list|(
name|double
name|A
parameter_list|,
name|double
name|B
parameter_list|,
name|double
name|C
parameter_list|,
name|double
name|D
parameter_list|)
block|{
return|return
operator|-
operator|(
name|A
operator|-
name|B
operator|)
operator|-
operator|(
name|C
operator|-
name|D
operator|)
return|;
block|}
end_function

end_unit

