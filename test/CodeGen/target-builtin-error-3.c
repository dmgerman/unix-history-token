begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -S -verify -o - -target-feature +avx
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -triple=x86_64-apple-darwin -emit-obj -target-feature +avx 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err %s
end_comment

begin_comment
comment|// CHECK: 1 error generated
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__m128i
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__v8sf
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m256
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|8
argument|),__aligned__(
literal|16
argument|))
argument_list|)
name|half
name|half8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|16
argument|),__aligned__(
literal|32
argument|))
argument_list|)
name|half
name|half16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|16
argument|),__aligned__(
literal|2
argument|))
argument_list|)
name|half
name|half16U
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|8
argument|),__aligned__(
literal|32
argument|))
argument_list|)
name|float
name|float8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|16
argument|),__aligned__(
literal|64
argument|))
argument_list|)
name|float
name|float16
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|inline
name|half8
name|__attribute__
argument_list|(
operator|(
name|__overloadable__
operator|)
argument_list|)
name|convert_half
argument_list|(
name|float8
name|a
argument_list|)
block|{
return|return
name|__extension__
argument_list|(
argument|{ __m256 __a = (a); (__m128i)__builtin_ia32_vcvtps2ph256((__v8sf)__a, (
literal|0x00
argument|)); }
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_vcvtps2ph256' needs target feature f16c}}
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|half16
name|__attribute__
argument_list|(
operator|(
name|__overloadable__
operator|)
argument_list|)
name|convert_half
argument_list|(
name|float16
name|a
argument_list|)
block|{
name|half16
name|r
decl_stmt|;
name|r
operator|.
name|lo
operator|=
name|convert_half
argument_list|(
name|a
operator|.
name|lo
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_decl_stmt

begin_function
name|void
name|avx_test
parameter_list|(
name|uint16_t
modifier|*
name|destData
parameter_list|,
name|float16
name|argbF
parameter_list|)
block|{
operator|(
operator|(
name|half16U
operator|*
operator|)
name|destData
operator|)
index|[
literal|0
index|]
operator|=
name|convert_half
argument_list|(
name|argbF
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

