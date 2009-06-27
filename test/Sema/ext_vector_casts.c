begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
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
name|int
name|int4
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

begin_typedef
typedef|typedef
name|float
name|t3
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
specifier|static
name|void
name|test
parameter_list|()
block|{
name|float2
name|vec2
decl_stmt|;
name|float4
name|vec4
decl_stmt|,
name|vec4_2
decl_stmt|;
name|int4
name|ivec4
decl_stmt|;
name|t3
name|vec4_3
decl_stmt|;
name|vec4
operator|=
operator|(
name|float4
operator|)
literal|5.0f
expr_stmt|;
name|vec4
operator|=
operator|(
name|float4
operator|)
literal|5
expr_stmt|;
name|vec4
operator|=
operator|(
name|float4
operator|)
name|vec4_3
expr_stmt|;
name|ivec4
operator|=
operator|(
name|int4
operator|)
literal|5.0f
expr_stmt|;
name|ivec4
operator|=
operator|(
name|int4
operator|)
literal|5
expr_stmt|;
name|ivec4
operator|=
operator|(
name|int4
operator|)
name|vec4_3
expr_stmt|;
name|vec4
operator|=
operator|(
name|float4
operator|)
name|vec2
expr_stmt|;
comment|// expected-error {{invalid conversion between ext-vector type 'float4' and 'float2'}}
block|}
end_function

end_unit

