begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-apple-macosx10.8.0 -fsyntax-only %s
end_comment

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_comment
comment|// Test that using two macros from emmintrin do not cause a
end_comment

begin_comment
comment|// useless -Wshadow warning.
end_comment

begin_function
name|void
name|rdar10679282
parameter_list|()
block|{
name|__m128i
name|qf
init|=
name|_mm_setzero_si128
argument_list|()
decl_stmt|;
name|qf
operator|=
name|_mm_slli_si128
argument_list|(
name|_mm_add_epi64
argument_list|(
name|qf
argument_list|,
name|_mm_srli_si128
argument_list|(
name|qf
argument_list|,
literal|8
argument_list|)
argument_list|)
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
name|qf
expr_stmt|;
block|}
end_function

end_unit

