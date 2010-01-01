begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
modifier|*
name|a
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
return|return
name|__builtin_return_address
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|b
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
return|return
name|__builtin_return_address
argument_list|(
name|x
argument_list|)
return|;
comment|// expected-error{{the level argument for a stack address builtin must be constant}}
block|}
end_function

begin_function
name|void
modifier|*
name|c
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
return|return
name|__builtin_frame_address
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|d
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
return|return
name|__builtin_frame_address
argument_list|(
name|x
argument_list|)
return|;
comment|// expected-error{{the level argument for a stack address builtin must be constant}}
block|}
end_function

end_unit

