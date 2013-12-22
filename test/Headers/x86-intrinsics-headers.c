begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -fno-lax-vector-conversions %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -x c++ %s
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

begin_ifdef
ifdef|#
directive|ifdef
name|__SSE4_2__
end_ifdef

begin_comment
comment|// nmmintrin forwards to smmintrin.
end_comment

begin_include
include|#
directive|include
file|<nmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// immintrin includes all other intel intrinsic headers.
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

