begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o %t.o
end_comment

begin_function
name|int
name|test
parameter_list|(
name|_Bool
name|pos
parameter_list|,
name|_Bool
name|color
parameter_list|)
block|{
return|return
literal|0
return|;
return|return
operator|(
name|pos
operator|&&
name|color
operator|)
return|;
block|}
end_function

end_unit

