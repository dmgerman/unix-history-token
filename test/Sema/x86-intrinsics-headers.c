begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: clang -fsyntax-only -fno-lax-vector-conversions %s
end_comment

begin_comment
comment|// RUN: clang -fsyntax-only -x c++ %s
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MMX__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_include
include|#
directive|include
file|<mm_malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE3__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSSE3__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

