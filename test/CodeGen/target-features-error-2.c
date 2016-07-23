begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o - -D NEED_SSE42
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o - -D NEED_AVX_1
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o - -D NEED_AVX_2
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o - -D NEED_AVX_3
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o - -D NEED_AVX_4
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_if
if|#
directive|if
name|NEED_SSE42
end_if

begin_function
name|int
name|baz
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
return|return
name|_mm256_extract_epi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// expected-error {{always_inline function '_mm256_extract_epi32' requires target feature 'sse4.2', but would be inlined into function 'baz' that is compiled without support for 'sse4.2'}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NEED_AVX_1
end_if

begin_function
name|__m128
name|need_avx
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
return|return
name|_mm_cmp_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_cmpps' needs target feature avx}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NEED_AVX_2
end_if

begin_function
name|__m128
name|need_avx
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
return|return
name|_mm_cmp_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_cmpss' needs target feature avx}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NEED_AVX_3
end_if

begin_function
name|__m128d
name|need_avx
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
return|return
name|_mm_cmp_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_cmppd' needs target feature avx}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NEED_AVX_4
end_if

begin_function
name|__m128d
name|need_avx
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
return|return
name|_mm_cmp_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_cmpsd' needs target feature avx}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

