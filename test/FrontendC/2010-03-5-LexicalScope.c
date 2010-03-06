begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -O0 -g %s -o - | grep DW_TAG_lexical_block | count 3
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
condition|)
block|{
name|int
name|j
init|=
literal|2
decl_stmt|;
block|}
else|else
block|{
name|int
name|j
init|=
literal|3
decl_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function

end_unit

