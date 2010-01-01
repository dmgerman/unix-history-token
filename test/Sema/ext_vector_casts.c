begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
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
literal|8
argument|) )
argument_list|)
name|short
name|short8
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
name|short8
name|ish8
decl_stmt|;
name|t3
name|vec4_3
decl_stmt|;
name|int
modifier|*
name|ptr
decl_stmt|;
name|int
name|i
decl_stmt|;
name|vec4
operator|=
literal|5.0f
expr_stmt|;
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
name|i
operator|=
operator|(
name|int
operator|)
name|ivec4
expr_stmt|;
comment|// expected-error {{invalid conversion between vector type 'int4' and integer type 'int' of different size}}
name|i
operator|=
name|ivec4
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'int4', expected 'int'}}
name|ivec4
operator|=
operator|(
name|int4
operator|)
name|ptr
expr_stmt|;
comment|// expected-error {{invalid conversion between vector type 'int4' and scalar type 'int *'}}
name|vec4
operator|=
operator|(
name|float4
operator|)
name|vec2
expr_stmt|;
comment|// expected-error {{invalid conversion between ext-vector type 'float4' and 'float2'}}
name|ish8
operator|+=
literal|5
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size ('short8' and 'int')}}
name|ish8
operator|+=
operator|(
name|short
operator|)
literal|5
expr_stmt|;
name|ivec4
operator|*=
literal|5
expr_stmt|;
name|vec4
operator|/=
literal|5.2f
expr_stmt|;
name|vec4
operator|%=
literal|4
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression ('float4' and 'int')}}
name|ivec4
operator|%=
literal|4
expr_stmt|;
name|ivec4
operator|+=
name|vec4
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size ('float4' and 'int4')}}
name|ivec4
operator|+=
operator|(
name|int4
operator|)
name|vec4
expr_stmt|;
name|ivec4
operator|-=
name|ivec4
expr_stmt|;
name|ivec4
operator||=
name|ivec4
expr_stmt|;
name|ivec4
operator|+=
name|ptr
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size ('int4' and 'int *')}}
block|}
end_function

end_unit

