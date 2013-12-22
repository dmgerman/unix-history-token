begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macos10.7.0 -fsyntax-only -verify -fno-lax-vector-conversions %s
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

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|stride4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
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
comment|// expected-error {{assigning to 'int' from incompatible type 'int4'}}
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
comment|// expected-error {{can't convert between vector values of different size ('int4' and 'float4')}}
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

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|float2
name|vecfloat2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{invalid vector element type 'float2'}}
end_comment

begin_function
name|void
name|inc
parameter_list|(
name|float2
name|f2
parameter_list|)
block|{
name|f2
operator|++
expr_stmt|;
comment|// expected-error{{cannot increment value of type 'float2'}}
name|__real
name|f2
decl_stmt|;
comment|// expected-error{{invalid type 'float2' to __real operator}}
block|}
end_function

begin_typedef
typedef|typedef
enum|enum
block|{
name|uchar_stride
init|=
literal|1
block|,
name|uchar4_stride
init|=
literal|4
block|,
name|ushort4_stride
init|=
literal|8
block|,
name|short4_stride
init|=
literal|8
block|,
name|uint4_stride
init|=
literal|16
block|,
name|int4_stride
init|=
literal|16
block|,
name|float4_stride
init|=
literal|16
block|, }
name|PixelByteStride
typedef|;
end_typedef

begin_function_decl
name|stride4
name|RDar15091442_get_stride4
parameter_list|(
name|int4
name|x
parameter_list|,
name|PixelByteStride
name|pixelByteStride
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|stride4
name|RDar15091442_get_stride4
parameter_list|(
name|int4
name|x
parameter_list|,
name|PixelByteStride
name|pixelByteStride
parameter_list|)
block|{
name|stride4
name|stride
decl_stmt|;
comment|// This previously caused an assertion failure.
name|stride
operator|.
name|lo
operator|=
operator|(
operator|(
name|ulong2
operator|)
name|x
operator|)
operator|*
name|pixelByteStride
expr_stmt|;
comment|// no-warning
return|return
name|stride
return|;
block|}
end_function

end_unit

