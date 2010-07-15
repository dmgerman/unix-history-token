begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: true
end_comment

begin_comment
comment|// %llvmgcc -std=gnu99 %s -S |& grep {error: "is greater than the stack alignment" }
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
name|var
index|[
name|a
index|]
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
decl_stmt|;
return|return
literal|4
return|;
block|}
end_function

end_unit

