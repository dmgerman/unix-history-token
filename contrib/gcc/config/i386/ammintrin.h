begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2007 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_comment
comment|/* Implemented from the specification included in the AMD Programmers    Manual Update, version 2.x */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMMINTRIN_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_AMMINTRIN_H_INCLUDED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4A__
end_ifndef

begin_error
error|#
directive|error
literal|"SSE4A instruction set not enabled"
end_error

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We need definitions from the SSE3, SSE2 and SSE header files*/
end_comment

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

begin_decl_stmt
specifier|static
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|)
argument_list|)
name|_mm_stream_sd
argument_list|(
name|double
operator|*
name|__P
argument_list|,
name|__m128d
name|__Y
argument_list|)
block|{
name|__builtin_ia32_movntsd
argument_list|(
name|__P
argument_list|,
operator|(
name|__v2df
operator|)
name|__Y
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|)
argument_list|)
name|_mm_stream_ss
argument_list|(
name|float
operator|*
name|__P
argument_list|,
name|__m128
name|__Y
argument_list|)
block|{
name|__builtin_ia32_movntss
argument_list|(
name|__P
argument_list|,
operator|(
name|__v4sf
operator|)
name|__Y
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|)
argument_list|)
name|_mm_extract_si64
argument_list|(
name|__m128i
name|__X
argument_list|,
name|__m128i
name|__Y
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_extrq
argument_list|(
operator|(
name|__v2di
operator|)
name|__X
argument_list|,
operator|(
name|__v16qi
operator|)
name|__Y
argument_list|)
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_mm_extracti_si64
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|L
parameter_list|)
define|\
value|((__m128i) __builtin_ia32_extrqi ((__v2di)(X), I, L))
end_define

begin_decl_stmt
specifier|static
name|__inline
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|)
argument_list|)
name|_mm_insert_si64
argument_list|(
name|__m128i
name|__X
argument_list|,
name|__m128i
name|__Y
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_insertq
argument_list|(
operator|(
name|__v2di
operator|)
name|__X
argument_list|,
operator|(
name|__v2di
operator|)
name|__Y
argument_list|)
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_mm_inserti_si64
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|I
parameter_list|,
name|L
parameter_list|)
define|\
value|((__m128i) __builtin_ia32_insertqi ((__v2di)(X), (__v2di)(Y), I, L))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SSE4A__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AMMINTRIN_H_INCLUDED */
end_comment

end_unit

