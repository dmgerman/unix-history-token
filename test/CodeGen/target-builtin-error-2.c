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

begin_comment
comment|// Since we do code generation on a function level this needs to error out since
end_comment

begin_comment
comment|// the subtarget feature won't be available.
end_comment

begin_function
name|__m128
name|wombat
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
if|if
condition|(
name|__builtin_cpu_supports
argument_list|(
literal|"avx"
argument_list|)
condition|)
return|return
name|__builtin_ia32_vpermilvarps
argument_list|(
operator|(
name|__v4sf
operator|)
block|{
literal|0.0f
block|,
literal|1.0f
block|,
literal|2.0f
block|,
literal|3.0f
block|}
argument_list|,
operator|(
name|__v4si
operator|)
name|a
argument_list|)
return|;
comment|// expected-error {{'__builtin_ia32_vpermilvarps' needs target feature avx}}
else|else
return|return
operator|(
name|__m128
operator|)
block|{
literal|0
block|,
literal|0
block|}
return|;
block|}
end_function

end_unit

