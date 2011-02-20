begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep getelementptr
end_comment

begin_function
name|int
modifier|*
name|test
parameter_list|(
name|int
modifier|*
name|X
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|+
name|Y
return|;
block|}
end_function

end_unit

