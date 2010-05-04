begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -target-feature +ssse3 -verify %s
end_comment

begin_comment
comment|// Temporarily xfail this on windows.
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_function
name|__m64
name|foo
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

end_unit

