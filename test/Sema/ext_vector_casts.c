begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macos10.7.0 -fsyntax-only -verify -fno-lax-vector-conversions -Wconversion %s
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
literal|3
argument|) )
argument_list|)
name|float
name|float3
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
name|float3
name|vec3
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
name|vec3
operator|+=
name|vec2
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size}}
name|vec4
operator|+=
name|vec3
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size}}
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
comment|// expected-error {{invalid conversion between vector type 'int4' (vector of 4 'int' values) and integer type 'int' of different size}}
name|i
operator|=
name|ivec4
expr_stmt|;
comment|// expected-error {{assigning to 'int' from incompatible type 'int4' (vector of 4 'int' values)}}
name|ivec4
operator|=
operator|(
name|int4
operator|)
name|ptr
expr_stmt|;
comment|// expected-error {{invalid conversion between vector type 'int4' (vector of 4 'int' values) and scalar type 'int *'}}
name|vec4
operator|=
operator|(
name|float4
operator|)
name|vec2
expr_stmt|;
comment|// expected-error {{invalid conversion between ext-vector type 'float4' (vector of 4 'float' values) and 'float2' (vector of 2 'float' values)}}
name|ish8
operator|+=
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
comment|// expected-error {{invalid operands to binary expression ('float4' (vector of 4 'float' values) and 'int')}}
name|ivec4
operator|%=
literal|4
expr_stmt|;
name|ivec4
operator|+=
name|vec4
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size ('int4' (vector of 4 'int' values) and 'float4' (vector of 4 'float' values))}}
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
comment|// expected-error {{can't convert between vector and non-scalar values ('int4' (vector of 4 'int' values) and 'int *')}}
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
comment|// expected-error{{invalid vector element type 'float2' (vector of 2 'float' values)}}
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
comment|// expected-error{{cannot increment value of type 'float2' (vector of 2 'float' values)}}
name|__real
name|f2
decl_stmt|;
comment|// expected-error{{invalid type 'float2' (vector of 2 'float' values) to __real operator}}
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

begin_comment
comment|// rdar://16196902
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|4
argument|))
argument_list|)
name|float
name|float32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|C3DVector3
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(3)));
end_typedef

begin_function_decl
specifier|extern
name|float32x4_t
name|vabsq_f32
parameter_list|(
name|float32x4_t
name|__a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|C3DVector3
name|Func
parameter_list|(
specifier|const
name|C3DVector3
name|a
parameter_list|)
block|{
return|return
operator|(
name|C3DVector3
operator|)
name|vabsq_f32
argument_list|(
operator|(
name|float32x4_t
operator|)
name|a
argument_list|)
return|;
comment|// expected-error {{invalid conversion between ext-vector type 'float32x4_t' (vector of 4 'float' values) and 'C3DVector3' (vector of 3 'float' values)}}
block|}
end_function

begin_comment
comment|// rdar://16350802
end_comment

begin_typedef
typedef|typedef
name|double
name|double2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
end_typedef

begin_function
specifier|static
name|void
name|splats
parameter_list|(
name|int
name|i
parameter_list|,
name|long
name|l
parameter_list|,
name|__uint128_t
name|t
parameter_list|,
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|)
block|{
name|short8
name|vs
init|=
literal|0
decl_stmt|;
name|int4
name|vi
init|=
name|i
decl_stmt|;
name|ulong2
name|vl
init|=
operator|(
name|unsigned
name|long
operator|)
name|l
decl_stmt|;
name|float2
name|vf
init|=
name|f
decl_stmt|;
name|double2
name|vd
init|=
name|d
decl_stmt|;
name|vs
operator|=
literal|65536
operator|+
name|vs
expr_stmt|;
comment|// expected-warning {{implicit conversion from 'int' to 'short8' (vector of 8 'short' values) changes value from 65536 to 0}}
name|vs
operator|=
name|vs
operator|+
name|i
expr_stmt|;
comment|// expected-warning {{implicit conversion loses integer precision}}
name|vs
operator|=
name|vs
operator|+
literal|1
expr_stmt|;
name|vs
operator|=
name|vs
operator|+
literal|1.f
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size}}
name|vi
operator|=
name|l
operator|+
name|vi
expr_stmt|;
comment|// expected-warning {{implicit conversion loses integer precision}}
name|vi
operator|=
literal|1
operator|+
name|vi
expr_stmt|;
name|vi
operator|=
name|vi
operator|+
literal|2.0
expr_stmt|;
comment|// expected-error {{can't convert between vector values of different size}}
name|vi
operator|=
name|vi
operator|+
literal|0xffffffff
expr_stmt|;
comment|// expected-warning {{implicit conversion changes signedness}}
name|vl
operator|=
name|l
operator|+
name|vl
expr_stmt|;
comment|// expected-warning {{implicit conversion changes signedness}}
name|vl
operator|=
name|vl
operator|+
name|t
expr_stmt|;
comment|// expected-warning {{implicit conversion loses integer precision}}
name|vf
operator|=
literal|1
operator|+
name|vf
expr_stmt|;
name|vf
operator|=
name|l
operator|+
name|vf
expr_stmt|;
name|vf
operator|=
literal|2.0
operator|+
name|vf
expr_stmt|;
name|vf
operator|=
name|d
operator|+
name|vf
expr_stmt|;
comment|// expected-warning {{implicit conversion loses floating-point precision}}
name|vf
operator|=
name|vf
operator|+
literal|0xffffffff
expr_stmt|;
name|vf
operator|=
name|vf
operator|+
literal|2.1
expr_stmt|;
comment|// expected-warning {{implicit conversion loses floating-point precision}}
name|vd
operator|=
name|l
operator|+
name|vd
expr_stmt|;
name|vd
operator|=
name|vd
operator|+
name|t
expr_stmt|;
block|}
end_function

end_unit

