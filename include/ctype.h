begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ctype.h	8.4 (Berkeley) 1/21/94  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTYPE_H_
end_define

begin_comment
comment|/*  * XXX<runetype.h> brings massive namespace pollution (rune_t and struct  * member names).  */
end_comment

begin_include
include|#
directive|include
file|<runetype.h>
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

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|isalnum
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isalpha
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iscntrl
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isdigit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isgraph
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|islower
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isprint
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ispunct
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isspace
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isupper
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isxdigit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tolower
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|toupper
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_decl_stmt
name|int
name|digittoint
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isascii
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isblank
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ishexnumber
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isideogram
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isnumber
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isphonogram
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isrune
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isspecial
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|toascii
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__END_DECLS
define|#
directive|define
name|__istype
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|(!!__maskrune((c),(f)))
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_A|_CTYPE_D)
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_A)
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_C)
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c), _CTYPE_D)
comment|/* ANSI -- locale independent */
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_G)
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_L)
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_R)
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_P)
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_S)
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_U)
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c), _CTYPE_X)
comment|/* ANSI -- locale independent */
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|__tolower(c)
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|__toupper(c)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
define|#
directive|define
name|digittoint
parameter_list|(
name|c
parameter_list|)
value|__maskrune((c), 0xFF)
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|(((c)& ~0x7F) == 0)
define|#
directive|define
name|isblank
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_B)
define|#
directive|define
name|ishexnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_X)
define|#
directive|define
name|isideogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_I)
define|#
directive|define
name|isnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_D)
define|#
directive|define
name|isphonogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_Q)
define|#
directive|define
name|isrune
parameter_list|(
name|c
parameter_list|)
value|__istype((c), 0xFFFFFF00L)
define|#
directive|define
name|isspecial
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_T)
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x7F)
endif|#
directive|endif
comment|/* See comments in<machine/ansi.h> about _BSD_CT_RUNE_T_. */
name|__BEGIN_DECLS
name|unsigned
name|long
name|___runetype
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_CT_RUNE_T_
name|___tolower
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_CT_RUNE_T_
name|___toupper
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|)
argument_list|)
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
specifier|static
name|__inline
name|int
name|__maskrune
parameter_list|(
name|_BSD_CT_RUNE_T_
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
name|runetype
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
name|__isctype
parameter_list|(
name|_BSD_CT_RUNE_T_
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
name|runetype
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
name|_BSD_CT_RUNE_T_
name|__toupper
parameter_list|(
name|_BSD_CT_RUNE_T_
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
name|mapupper
index|[
name|_c
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|_BSD_CT_RUNE_T_
name|__tolower
parameter_list|(
name|_BSD_CT_RUNE_T_
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
name|maplower
index|[
name|_c
index|]
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

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|__maskrune
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isctype
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_CT_RUNE_T_
name|__toupper
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_CT_RUNE_T_
name|__tolower
name|__P
argument_list|(
operator|(
name|_BSD_CT_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* !_CTYPE_H_ */
end_comment

end_unit

