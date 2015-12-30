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
name|__m128d
name|foo
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
return|return
name|__builtin_ia32_addsubps
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_addsubps' needs target feature sse3}}
block|}
end_function

end_unit

