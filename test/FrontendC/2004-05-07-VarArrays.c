begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|len
parameter_list|,
name|char
name|arr
index|[]
index|[
name|len
index|]
parameter_list|,
name|int
name|X
parameter_list|)
block|{
return|return
name|arr
index|[
name|X
index|]
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

