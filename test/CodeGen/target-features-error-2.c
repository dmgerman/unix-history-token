begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o -
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

end_unit

