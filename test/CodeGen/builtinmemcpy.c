begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s -o - | grep "llvm.memcpy"
end_comment

begin_function
name|char
modifier|*
name|x
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__builtin_memcpy
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

end_unit

