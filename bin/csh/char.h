begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)char.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|_cmap
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NLS
end_ifndef

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_cmap_lower
index|[]
decl_stmt|,
name|_cmap_upper
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_QF
value|0x0001
end_define

begin_comment
comment|/* '" (Forward quotes) */
end_comment

begin_define
define|#
directive|define
name|_QB
value|0x0002
end_define

begin_comment
comment|/* ` (Backquote) */
end_comment

begin_define
define|#
directive|define
name|_SP
value|0x0004
end_define

begin_comment
comment|/* space and tab */
end_comment

begin_define
define|#
directive|define
name|_NL
value|0x0008
end_define

begin_comment
comment|/* \n */
end_comment

begin_define
define|#
directive|define
name|_META
value|0x0010
end_define

begin_comment
comment|/* lex meta characters, sp #'`";&<>()|\t\n */
end_comment

begin_define
define|#
directive|define
name|_GLOB
value|0x0020
end_define

begin_comment
comment|/* glob characters, *?{[` */
end_comment

begin_define
define|#
directive|define
name|_ESC
value|0x0040
end_define

begin_comment
comment|/* \ */
end_comment

begin_define
define|#
directive|define
name|_DOL
value|0x0080
end_define

begin_comment
comment|/* $ */
end_comment

begin_define
define|#
directive|define
name|_DIG
value|0x0100
end_define

begin_comment
comment|/* 0-9 */
end_comment

begin_define
define|#
directive|define
name|_LET
value|0x0200
end_define

begin_comment
comment|/* a-z, A-Z, _ */
end_comment

begin_define
define|#
directive|define
name|_UP
value|0x0400
end_define

begin_comment
comment|/* A-Z */
end_comment

begin_define
define|#
directive|define
name|_LOW
value|0x0800
end_define

begin_comment
comment|/* a-z */
end_comment

begin_define
define|#
directive|define
name|_XD
value|0x1000
end_define

begin_comment
comment|/* 0-9, a-f, A-F */
end_comment

begin_define
define|#
directive|define
name|_CMD
value|0x2000
end_define

begin_comment
comment|/* lex end of command chars, ;&(|` */
end_comment

begin_define
define|#
directive|define
name|_CTR
value|0x4000
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|cmap
parameter_list|(
name|c
parameter_list|,
name|bits
parameter_list|)
define|\
value|(((c)& QUOTE) ? 0 : (_cmap[(unsigned char)(c)]& (bits)))
end_define

begin_define
define|#
directive|define
name|isglob
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _GLOB)
end_define

begin_define
define|#
directive|define
name|isspc
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _SP)
end_define

begin_define
define|#
directive|define
name|ismeta
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _META)
end_define

begin_define
define|#
directive|define
name|iscmdmeta
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _CMD)
end_define

begin_define
define|#
directive|define
name|letter
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : \ 			 (isalpha((unsigned char) (c)) || (c) == '_'))
end_define

begin_define
define|#
directive|define
name|alnum
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : \ 		         (isalnum((unsigned char) (c)) || (c) == '_'))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NLS
end_ifdef

begin_define
define|#
directive|define
name|Isspace
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isspace((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Isdigit
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isdigit((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Isalpha
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isalpha((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Islower
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : islower((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Isupper
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isupper((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Tolower
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : tolower((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Toupper
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : toupper((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Isxdigit
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isxdigit((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Isalnum
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isalnum((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Iscntrl
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : iscntrl((unsigned char) (c)))
end_define

begin_define
define|#
directive|define
name|Isprint
parameter_list|(
name|c
parameter_list|)
value|(((c)& QUOTE) ? 0 : isprint((unsigned char) (c)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Isspace
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _SP|_NL)
end_define

begin_define
define|#
directive|define
name|Isdigit
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _DIG)
end_define

begin_define
define|#
directive|define
name|Isalpha
parameter_list|(
name|c
parameter_list|)
value|(cmap(c,_LET)&& !(((c)& META)&& AsciiOnly))
end_define

begin_define
define|#
directive|define
name|Islower
parameter_list|(
name|c
parameter_list|)
value|(cmap(c,_LOW)&& !(((c)& META)&& AsciiOnly))
end_define

begin_define
define|#
directive|define
name|Isupper
parameter_list|(
name|c
parameter_list|)
value|(cmap(c, _UP)&& !(((c)& META)&& AsciiOnly))
end_define

begin_define
define|#
directive|define
name|Tolower
parameter_list|(
name|c
parameter_list|)
value|(_cmap_lower[(unsigned char)(c)])
end_define

begin_define
define|#
directive|define
name|Toupper
parameter_list|(
name|c
parameter_list|)
value|(_cmap_upper[(unsigned char)(c)])
end_define

begin_define
define|#
directive|define
name|Isxdigit
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _XD)
end_define

begin_define
define|#
directive|define
name|Isalnum
parameter_list|(
name|c
parameter_list|)
value|(cmap(c, _DIG|_LET)&& !(((c)& META)&& AsciiOnly))
end_define

begin_define
define|#
directive|define
name|Iscntrl
parameter_list|(
name|c
parameter_list|)
value|(cmap(c,_CTR)&& !(((c)& META)&& AsciiOnly))
end_define

begin_define
define|#
directive|define
name|Isprint
parameter_list|(
name|c
parameter_list|)
value|(!cmap(c,_CTR)&& !(((c)& META)&& AsciiOnly))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

