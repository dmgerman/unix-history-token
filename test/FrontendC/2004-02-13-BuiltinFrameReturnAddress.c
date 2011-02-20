begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep llvm.*address | count 4
end_comment

begin_function
name|void
modifier|*
name|test1
parameter_list|()
block|{
return|return
name|__builtin_return_address
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|test2
parameter_list|()
block|{
return|return
name|__builtin_frame_address
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

