begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -O3 -S -o - | grep mul
end_comment

begin_comment
comment|// PR1233
end_comment

begin_function
name|float
name|foo
parameter_list|(
name|int
name|w
parameter_list|,
name|float
name|A
index|[]
index|[
name|w
index|]
parameter_list|,
name|int
name|g
parameter_list|,
name|int
name|h
parameter_list|)
block|{
return|return
name|A
index|[
name|g
index|]
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

