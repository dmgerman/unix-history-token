begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ctype.h	8.1 (Berkeley) 6/6/93  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<runetype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_A
value|0x00000100L
end_define

begin_comment
comment|/* Alpha */
end_comment

begin_define
define|#
directive|define
name|_C
value|0x00000200L
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|_D
value|0x00000400L
end_define

begin_comment
comment|/* Digit */
end_comment

begin_define
define|#
directive|define
name|_G
value|0x00000800L
end_define

begin_comment
comment|/* Graph */
end_comment

begin_define
define|#
directive|define
name|_L
value|0x00001000L
end_define

begin_comment
comment|/* Lower */
end_comment

begin_define
define|#
directive|define
name|_P
value|0x00002000L
end_define

begin_comment
comment|/* Punct */
end_comment

begin_define
define|#
directive|define
name|_S
value|0x00004000L
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|_U
value|0x00008000L
end_define

begin_comment
comment|/* Upper */
end_comment

begin_define
define|#
directive|define
name|_X
value|0x00010000L
end_define

begin_comment
comment|/* X digit */
end_comment

begin_define
define|#
directive|define
name|_B
value|0x00020000L
end_define

begin_comment
comment|/* Blank */
end_comment

begin_define
define|#
directive|define
name|_R
value|0x00040000L
end_define

begin_comment
comment|/* Print */
end_comment

begin_define
define|#
directive|define
name|_I
value|0x00080000L
end_define

begin_comment
comment|/* Ideogram */
end_comment

begin_define
define|#
directive|define
name|_T
value|0x00100000L
end_define

begin_comment
comment|/* Special */
end_comment

begin_define
define|#
directive|define
name|_Q
value|0x00200000L
end_define

begin_comment
comment|/* Phonogram */
end_comment

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|__istype((c), (_A|_D))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _A)
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _C)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c),    _D)
end_define

begin_comment
comment|/* ANSI -- locale independent */
end_comment

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _G)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _L)
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _R)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _P)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _S)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|__istype((c),     _U)
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c),    _X)
end_define

begin_comment
comment|/* ANSI -- locale independent */
end_comment

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

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((c& ~0x7F) == 0)
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x7F)
end_define

begin_define
define|#
directive|define
name|digittoint
parameter_list|(
name|c
parameter_list|)
value|__istype((c), 0xFF)
end_define

begin_define
define|#
directive|define
name|isideogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _I)
end_define

begin_define
define|#
directive|define
name|isphonogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _T)
end_define

begin_define
define|#
directive|define
name|isspecial
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _Q)
end_define

begin_define
define|#
directive|define
name|isblank
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _B)
end_define

begin_define
define|#
directive|define
name|isrune
parameter_list|(
name|c
parameter_list|)
value|__istype((c),  0xFFFFFF00L)
end_define

begin_define
define|#
directive|define
name|isnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _D)
end_define

begin_define
define|#
directive|define
name|ishexnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* See comments in<machine/ansi.h> about _BSD_RUNE_T_. */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|unsigned
name|long
name|___runetype
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_RUNE_T_
name|___tolower
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_RUNE_T_
name|___toupper
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|__END_DECLS
comment|/*  * If your compiler supports prototypes and inline functions,  * #define _USE_CTYPE_INLINE_.  Otherwise, use the C library  * functions.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_USE_CTYPE_CLIBRARY_
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
define|#
directive|define
name|_USE_CTYPE_INLINE_
value|1
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_USE_CTYPE_INLINE_
argument_list|)
specifier|static
specifier|inline
name|int
name|__istype
parameter_list|(
name|_BSD_RUNE_T_
name|c
parameter_list|,
name|unsigned
name|long
name|f
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
name|___runetype
argument_list|(
name|c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|runetype
index|[
name|c
index|]
operator|)
operator|&
name|f
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__isctype
parameter_list|(
name|_BSD_RUNE_T_
name|c
parameter_list|,
name|unsigned
name|long
name|f
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
literal|0
else|:
name|_DefaultRuneLocale
operator|.
name|runetype
index|[
name|c
index|]
operator|)
operator|&
name|f
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* _ANSI_LIBRARY is defined by lib/libc/gen/isctype.c. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_LIBRARY
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
name|_BSD_RUNE_T_
name|toupper
parameter_list|(
name|_BSD_RUNE_T_
name|c
parameter_list|)
block|{
return|return
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
name|___toupper
argument_list|(
name|c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|mapupper
index|[
name|c
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|_BSD_RUNE_T_
name|tolower
parameter_list|(
name|_BSD_RUNE_T_
name|c
parameter_list|)
block|{
return|return
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
name|___tolower
argument_list|(
name|c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|maplower
index|[
name|c
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_LIBRARY */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_USE_CTYPE_INLINE_ */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|__istype
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
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
name|_BSD_RUNE_T_
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_RUNE_T_
name|toupper
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_BSD_RUNE_T_
name|tolower
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
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
comment|/* _USE_CTYPE_INLINE_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CTYPE_H_ */
end_comment

end_unit

