begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -O0 -g %s -o - | grep DW_TAG_typedef | grep float4
end_comment

begin_typedef
typedef|typedef
name|float
name|float4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|volatile
name|float4
name|x
init|=
operator|(
name|float4
operator|)
block|{
literal|0.0f
block|,
literal|1.0f
block|,
literal|2.0f
block|,
literal|3.0f
block|}
decl_stmt|;
name|x
operator|+=
name|x
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

