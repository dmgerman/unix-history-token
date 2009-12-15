begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file can be used to see what a native C compiler is generating for a
end_comment

begin_comment
comment|// variety of interesting operations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llc
end_comment

begin_function
name|unsigned
name|int
name|udiv
parameter_list|(
name|unsigned
name|int
name|X
parameter_list|,
name|unsigned
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|/
name|Y
return|;
block|}
end_function

begin_function
name|int
name|sdiv
parameter_list|(
name|int
name|X
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|/
name|Y
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|urem
parameter_list|(
name|unsigned
name|int
name|X
parameter_list|,
name|unsigned
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|%
name|Y
return|;
block|}
end_function

begin_function
name|int
name|srem
parameter_list|(
name|int
name|X
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|%
name|Y
return|;
block|}
end_function

begin_function
name|_Bool
name|setlt
parameter_list|(
name|int
name|X
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|<
name|Y
return|;
block|}
end_function

begin_function
name|_Bool
name|setgt
parameter_list|(
name|int
name|X
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|X
operator|>
name|Y
return|;
block|}
end_function

end_unit

