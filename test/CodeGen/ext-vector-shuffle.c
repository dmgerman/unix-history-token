begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -x cl -emit-llvm -o - | not grep 'extractelement'
end_comment

begin_comment
comment|// RUN: clang-cc %s -x cl -emit-llvm -o - | not grep 'insertelement'
end_comment

begin_comment
comment|// RUN: clang-cc %s -x cl -emit-llvm -o - | grep 'shufflevector'
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|float
name|float2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|float
name|float4
typedef|;
end_typedef

begin_function
name|float2
name|test1
parameter_list|(
name|float4
name|V
parameter_list|)
block|{
return|return
name|V
operator|.
name|xy
operator|+
name|V
operator|.
name|wz
return|;
block|}
end_function

begin_function
name|float4
name|test2
parameter_list|(
name|float4
name|V
parameter_list|)
block|{
name|float2
name|W
init|=
name|V
operator|.
name|ww
decl_stmt|;
return|return
name|W
operator|.
name|xyxy
operator|+
name|W
operator|.
name|yxyx
return|;
block|}
end_function

begin_function
name|float4
name|test3
parameter_list|(
name|float4
name|V1
parameter_list|,
name|float4
name|V2
parameter_list|)
block|{
return|return
call|(
name|float4
call|)
argument_list|(
name|V1
operator|.
name|zw
argument_list|,
name|V2
operator|.
name|xy
argument_list|)
return|;
block|}
end_function

end_unit

