begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
modifier|*
name|A
parameter_list|,
name|unsigned
name|X
parameter_list|)
block|{
return|return
name|A
index|[
name|X
index|]
return|;
block|}
end_function

end_unit

