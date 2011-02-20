begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o -
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|test
parameter_list|)
block|{
operator|(
name|ptr
operator|-
operator|(
operator|(
name|void
operator|*
operator|)
name|test
operator|+
literal|0x2000
operator|)
operator|)
expr_stmt|;
block|}
end_function

end_unit

