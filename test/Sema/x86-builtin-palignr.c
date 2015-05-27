begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fsyntax-only -target-feature +ssse3 -target-feature +mmx -verify -triple x86_64-pc-linux-gnu %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fsyntax-only -target-feature +ssse3 -target-feature +mmx -verify -triple i686-apple-darwin10 %s
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
comment|// FIXME: The "incompatible result type" error is due to pr10112 and should
comment|// be removed when that is fixed.
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
comment|// expected-error {{argument to '__builtin_ia32_palignr' must be a constant integer}} expected-error {{incompatible result type}}
block|}
end_function

end_unit

