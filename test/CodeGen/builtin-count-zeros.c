begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - | grep 'cttz' | count 2
end_comment

begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - | grep 'ctlz' | count 2
end_comment

begin_function
name|int
name|a
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|__builtin_ctz
argument_list|(
name|a
argument_list|)
operator|+
name|__builtin_clz
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

