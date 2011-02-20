begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fsyntax-only -target-feature +ssse3 -verify %s
end_comment

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_function
name|__m64
name|test1
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
name|_mm_alignr_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// expected-error {{argument to '__builtin_ia32_palignr' must be a constant integer}}
block|}
end_function

begin_function
name|int
name|test2
parameter_list|(
name|int
name|N
parameter_list|)
block|{
name|__m128i
name|white2
decl_stmt|;
name|white2
operator|=
name|__builtin_ia32_pslldqi128
argument_list|(
name|white2
argument_list|,
name|N
argument_list|)
expr_stmt|;
comment|// expected-error {{argument to '__builtin_ia32_pslldqi128' must be a constant integer}}
return|return
literal|0
return|;
block|}
end_function

end_unit

