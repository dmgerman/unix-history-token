begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * From @(#)ctype.h	8.4 (Berkeley) 1/21/94  * From FreeBSD: src/include/ctype.h,v 1.27 2004/06/23 07:11:39 tjr Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|__CTYPE_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_define
define|#
directive|define
name|_CTYPE_A
value|0x00000100L
end_define

begin_comment
comment|/* Alpha */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_C
value|0x00000200L
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_D
value|0x00000400L
end_define

begin_comment
comment|/* Digit */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_G
value|0x00000800L
end_define

begin_comment
comment|/* Graph */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_L
value|0x00001000L
end_define

begin_comment
comment|/* Lower */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_P
value|0x00002000L
end_define

begin_comment
comment|/* Punct */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_S
value|0x00004000L
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_U
value|0x00008000L
end_define

begin_comment
comment|/* Upper */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_X
value|0x00010000L
end_define

begin_comment
comment|/* X digit */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_B
value|0x00020000L
end_define

begin_comment
comment|/* Blank */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_R
value|0x00040000L
end_define

begin_comment
comment|/* Print */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_I
value|0x00080000L
end_define

begin_comment
comment|/* Ideogram */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_T
value|0x00100000L
end_define

begin_comment
comment|/* Special */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_Q
value|0x00200000L
end_define

begin_comment
comment|/* Phonogram */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SW0
value|0x20000000L
end_define

begin_comment
comment|/* 0 width character */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SW1
value|0x40000000L
end_define

begin_comment
comment|/* 1 width character */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SW2
value|0x80000000L
end_define

begin_comment
comment|/* 2 width character */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SW3
value|0xc0000000L
end_define

begin_comment
comment|/* 3 width character */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SWM
value|0xe0000000L
end_define

begin_comment
comment|/* Mask for screen width data */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SWS
value|30
end_define

begin_comment
comment|/* Bits to shift to get width */
end_comment

begin_comment
comment|/* See comments in<sys/_types.h> about __ct_rune_t. */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|unsigned
name|long
name|___runetype
argument_list|(
name|__ct_rune_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__ct_rune_t
name|___tolower
argument_list|(
name|__ct_rune_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__ct_rune_t
name|___toupper
argument_list|(
name|__ct_rune_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_function
name|__END_DECLS
comment|/*  * _EXTERNALIZE_CTYPE_INLINES_ is defined in locale/nomacros.c to tell us  * to generate code for extern versions of all our inline functions.  */
ifdef|#
directive|ifdef
name|_EXTERNALIZE_CTYPE_INLINES_
define|#
directive|define
name|_USE_CTYPE_INLINE_
define|#
directive|define
name|static
define|#
directive|define
name|__inline
endif|#
directive|endif
comment|/*  * Use inline functions if we are allowed to and the compiler supports them.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DONT_USE_CTYPE_INLINE_
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|_USE_CTYPE_INLINE_
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|)
include|#
directive|include
file|<runetype.h>
specifier|static
name|__inline
name|int
name|__maskrune
parameter_list|(
name|__ct_rune_t
name|_c
parameter_list|,
name|unsigned
name|long
name|_f
parameter_list|)
block|{
return|return
operator|(
operator|(
name|_c
operator|<
literal|0
operator|||
name|_c
operator|>=
name|_CACHED_RUNES
operator|)
condition|?
name|___runetype
argument_list|(
name|_c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|__runetype
index|[
name|_c
index|]
operator|)
operator|&
name|_f
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__istype
parameter_list|(
name|__ct_rune_t
name|_c
parameter_list|,
name|unsigned
name|long
name|_f
parameter_list|)
block|{
return|return
operator|(
operator|!
operator|!
name|__maskrune
argument_list|(
name|_c
argument_list|,
name|_f
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__isctype
parameter_list|(
name|__ct_rune_t
name|_c
parameter_list|,
name|unsigned
name|long
name|_f
parameter_list|)
block|{
return|return
operator|(
name|_c
operator|<
literal|0
operator|||
name|_c
operator|>=
name|_CACHED_RUNES
operator|)
condition|?
literal|0
else|:
operator|!
operator|!
operator|(
name|_DefaultRuneLocale
operator|.
name|__runetype
index|[
name|_c
index|]
operator|&
name|_f
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__ct_rune_t
name|__toupper
parameter_list|(
name|__ct_rune_t
name|_c
parameter_list|)
block|{
return|return
operator|(
name|_c
operator|<
literal|0
operator|||
name|_c
operator|>=
name|_CACHED_RUNES
operator|)
condition|?
name|___toupper
argument_list|(
name|_c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|__mapupper
index|[
name|_c
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__ct_rune_t
name|__tolower
parameter_list|(
name|__ct_rune_t
name|_c
parameter_list|)
block|{
return|return
operator|(
name|_c
operator|<
literal|0
operator|||
name|_c
operator|>=
name|_CACHED_RUNES
operator|)
condition|?
name|___tolower
argument_list|(
name|_c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|__maplower
index|[
name|_c
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__wcwidth
parameter_list|(
name|__ct_rune_t
name|_c
parameter_list|)
block|{
name|unsigned
name|int
name|_x
decl_stmt|;
if|if
condition|(
name|_c
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|_x
operator|=
operator|(
name|unsigned
name|int
operator|)
name|__maskrune
argument_list|(
name|_c
argument_list|,
name|_CTYPE_SWM
operator||
name|_CTYPE_R
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|_x
operator|&
name|_CTYPE_SWM
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|(
name|_x
operator|&
name|_CTYPE_SWM
operator|)
operator|>>
name|_CTYPE_SWS
operator|)
return|;
return|return
operator|(
operator|(
name|_x
operator|&
name|_CTYPE_R
operator|)
operator|!=
literal|0
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not using inlines */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|__maskrune
parameter_list|(
name|__ct_rune_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__istype
parameter_list|(
name|__ct_rune_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__isctype
parameter_list|(
name|__ct_rune_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__ct_rune_t
name|__toupper
parameter_list|(
name|__ct_rune_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__ct_rune_t
name|__tolower
parameter_list|(
name|__ct_rune_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__wcwidth
parameter_list|(
name|__ct_rune_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* using inlines */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__CTYPE_H_ */
end_comment

end_unit

