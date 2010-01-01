begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep 'shufflevector' | count 1
end_comment

begin_typedef
typedef|typedef
name|int
name|v4si
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|v4si
name|a
parameter_list|(
name|v4si
name|x
parameter_list|,
name|v4si
name|y
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|,
literal|5
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

end_unit

