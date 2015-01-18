begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-apple-darwin -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|__m128d
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|__m128
name|test__builtin_ia32_cmpps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
name|__builtin_ia32_cmpps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
block|}
end_function

begin_function
name|__m128d
name|test__builtin_ia32_cmppd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__builtin_ia32_cmppd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
block|}
end_function

begin_function
name|__m128
name|test__builtin_ia32_cmpss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
name|__builtin_ia32_cmpss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
block|}
end_function

begin_function
name|__m128d
name|test__builtin_ia32_cmpsd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__builtin_ia32_cmpsd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
block|}
end_function

end_unit

