begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -x cl -verify -pedantic -fsyntax-only
end_comment

begin_typedef
typedef|typedef
name|float
name|float8
name|__attribute
typedef|((
name|ext_vector_type
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|float32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|float32_t
name|__neon_float32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__simd128_float32_t
block|{
name|__neon_float32x4_t
name|val
decl_stmt|;
block|}
name|float32x4_t
typedef|;
end_typedef

begin_function
name|float8
name|foo
parameter_list|(
name|float8
name|x
parameter_list|)
block|{
name|float32x4_t
name|lo
decl_stmt|;
name|float32x4_t
name|hi
decl_stmt|;
return|return
call|(
name|float8
call|)
argument_list|(
name|lo
operator|.
name|val
argument_list|,
name|hi
operator|.
name|val
argument_list|)
return|;
block|}
end_function

end_unit

