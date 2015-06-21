begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -x c++ %s -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|__target__
argument_list|(
operator|(
literal|"sse3"
operator|)
argument_list|)
operator|)
argument_list|)
name|foo
argument_list|(
name|int
name|a
argument_list|)
block|{
name|_mm_mwait
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

