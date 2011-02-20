begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep getelementptr
end_comment

begin_function
name|char
modifier|*
name|test
parameter_list|(
name|char
modifier|*
name|C
parameter_list|)
block|{
return|return
name|C
operator|-
literal|1
return|;
comment|// Should turn into a GEP
block|}
end_function

begin_function
name|int
modifier|*
name|test2
parameter_list|(
name|int
modifier|*
name|I
parameter_list|)
block|{
return|return
name|I
operator|-
literal|1
return|;
block|}
end_function

end_unit

