begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: vis.c,v 1.19 2000/01/22 22:42:45 mycroft Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: vis.c,v 1.3 2000/12/10 23:10:48 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_DIAGASSERT
end_ifndef

begin_define
define|#
directive|define
name|_DIAGASSERT
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: vis.c,v 1.19 2000/01/22 22:42:45 mycroft Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<vis.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__weak_alias
end_ifdef

begin_endif
unit|__weak_alias(strsvis,_strsvis) __weak_alias(strsvisx,_strsvisx) __weak_alias(strvis,_strvis) __weak_alias(strvisx,_strvisx) __weak_alias(svis,_svis) __weak_alias(vis,_vis)
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|BELL
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BELL
value|'\a'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BELL
value|'\007'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|isoctal
parameter_list|(
name|c
parameter_list|)
value|(((u_char)(c))>= '0'&& ((u_char)(c))<= '7')
end_define

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|c
parameter_list|)
value|(c == ' ' || c == '\t' || c == '\n')
end_define

begin_define
define|#
directive|define
name|issafe
parameter_list|(
name|c
parameter_list|)
value|(c == '\b' || c == BELL || c == '\r')
end_define

begin_define
define|#
directive|define
name|MAXEXTRAS
value|5
end_define

begin_define
define|#
directive|define
name|MAKEEXTRALIST
parameter_list|(
name|flag
parameter_list|,
name|extra
parameter_list|)
define|\
value|do {									      \ 	char *pextra = extra;						      \ 	if (flag& VIS_SP) *pextra++ = ' ';				      \ 	if (flag& VIS_TAB) *pextra++ = '\t';				      \ 	if (flag& VIS_NL) *pextra++ = '\n';				      \ 	if ((flag& VIS_NOSLASH) == 0) *pextra++ = '\\';		      \ 	*pextra = '\0';							      \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_comment
comment|/*  * This is SVIS, the central macro of vis.  * dst:	      Pointer to the destination buffer  * c:	      Character to encode  * flag:      Flag word  * nextc:     The character following 'c'  * extra:     Pointer to the list of extra characters to be  *	      backslash-protected.  */
end_comment

begin_define
define|#
directive|define
name|SVIS
parameter_list|(
name|dst
parameter_list|,
name|c
parameter_list|,
name|flag
parameter_list|,
name|nextc
parameter_list|,
name|extra
parameter_list|)
define|\
value|do {									      \ 	int isextra, isc;						      \ 	isextra = strchr(extra, c) != NULL;				      \ 	if (!isextra&& isascii(c)&& (isgraph(c) || iswhite(c) ||	      \ 	    ((flag& VIS_SAFE)&& issafe(c)))) {			      \ 		*dst++ = c;						      \ 		break;							      \ 	}								      \ 	isc = 0;							      \ 	if (flag& VIS_CSTYLE) {					      \ 		switch (c) {						      \ 		case '\n':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 'n';		      \ 			break;						      \ 		case '\r':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 'r';		      \ 			break;						      \ 		case '\b':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 'b';		      \ 			break;						      \ 		case BELL:						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 'a';		      \ 			break;						      \ 		case '\v':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 'v';		      \ 			break;						      \ 		case '\t':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 't';		      \ 			break;						      \ 		case '\f':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 'f';		      \ 			break;						      \ 		case ' ':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = 's';		      \ 			break;						      \ 		case '\0':						      \ 			isc = 1; *dst++ = '\\'; *dst++ = '0';		      \ 			if (isoctal(nextc)) {				      \ 				*dst++ = '0';				      \ 				*dst++ = '0';				      \ 			}						      \ 		}							      \ 	}								      \ 	if (isc) break;							      \ 	if (isextra || ((c& 0177) == ' ') || (flag& VIS_OCTAL)) {	      \ 		*dst++ = '\\';						      \ 		*dst++ = (u_char)(((unsigned)(u_char)c>> 6)& 03) + '0';     \ 		*dst++ = (u_char)(((unsigned)(u_char)c>> 3)& 07) + '0';     \ 		*dst++ =			     (c& 07) + '0';    \ 	} else {							      \ 		if ((flag& VIS_NOSLASH) == 0) *dst++ = '\\';		      \ 		if (c& 0200) {						      \ 			c&= 0177; *dst++ = 'M';			      \ 		}							      \ 		if (iscntrl(c)) {					      \ 			*dst++ = '^';					      \ 			if (c == 0177)					      \ 				*dst++ = '?';				      \ 			else						      \ 				*dst++ = c + '@';			      \ 		} else {						      \ 			*dst++ = '-'; *dst++ = c;			      \ 		}							      \ 	}								      \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_comment
comment|/*  * svis - visually encode characters, also encoding the characters  * 	  pointed to by `extra'  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SVIS
end_ifndef

begin_function
name|char
modifier|*
name|svis
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|nextc
parameter_list|,
specifier|const
name|char
modifier|*
name|extra
parameter_list|)
block|{
name|_DIAGASSERT
argument_list|(
name|dst
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|_DIAGASSERT
argument_list|(
name|extra
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|SVIS
argument_list|(
name|dst
argument_list|,
name|c
argument_list|,
name|flag
argument_list|,
name|nextc
argument_list|,
name|extra
argument_list|)
expr_stmt|;
operator|*
name|dst
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * strsvis, strsvisx - visually encode characters from src into dst  *  *	Extra is a pointer to a \0-terminated list of characters to  *	be encoded, too. These functions are useful e. g. to  *	encode strings in such a way so that they are not interpreted  *	by a shell.  *	  *	Dst must be 4 times the size of src to account for possible  *	expansion.  The length of dst, not including the trailing NULL,  *	is returned.   *  *	Strsvisx encodes exactly len bytes from src into dst.  *	This is useful for encoding a block of data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRSVIS
end_ifndef

begin_function
name|int
name|strsvis
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|extra
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|char
modifier|*
name|start
decl_stmt|;
name|_DIAGASSERT
argument_list|(
name|dst
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|_DIAGASSERT
argument_list|(
name|src
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|_DIAGASSERT
argument_list|(
name|extra
operator|!=
name|NULL
argument_list|)
expr_stmt|;
for|for
control|(
name|start
operator|=
name|dst
init|;
operator|(
name|c
operator|=
operator|*
name|src
operator|++
operator|)
operator|!=
literal|'\0'
condition|;
comment|/* empty */
control|)
name|SVIS
argument_list|(
name|dst
argument_list|,
name|c
argument_list|,
name|flag
argument_list|,
operator|*
name|src
argument_list|,
name|extra
argument_list|)
expr_stmt|;
operator|*
name|dst
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dst
operator|-
name|start
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRVISX
end_ifndef

begin_function
name|int
name|strsvisx
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|extra
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|char
modifier|*
name|start
decl_stmt|;
name|_DIAGASSERT
argument_list|(
name|dst
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|_DIAGASSERT
argument_list|(
name|src
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|_DIAGASSERT
argument_list|(
name|extra
operator|!=
name|NULL
argument_list|)
expr_stmt|;
for|for
control|(
name|start
operator|=
name|dst
init|;
name|len
operator|>
literal|0
condition|;
name|len
operator|--
control|)
block|{
name|c
operator|=
operator|*
name|src
operator|++
expr_stmt|;
name|SVIS
argument_list|(
name|dst
argument_list|,
name|c
argument_list|,
name|flag
argument_list|,
name|len
condition|?
operator|*
name|src
else|:
literal|'\0'
argument_list|,
name|extra
argument_list|)
expr_stmt|;
block|}
operator|*
name|dst
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dst
operator|-
name|start
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * vis - visually encode characters  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VIS
end_ifndef

begin_function
name|char
modifier|*
name|vis
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|nextc
parameter_list|)
block|{
name|char
name|extra
index|[
name|MAXEXTRAS
index|]
decl_stmt|;
name|_DIAGASSERT
argument_list|(
name|dst
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|MAKEEXTRALIST
argument_list|(
name|flag
argument_list|,
name|extra
argument_list|)
expr_stmt|;
name|SVIS
argument_list|(
name|dst
argument_list|,
name|c
argument_list|,
name|flag
argument_list|,
name|nextc
argument_list|,
name|extra
argument_list|)
expr_stmt|;
operator|*
name|dst
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * strvis, strvisx - visually encode characters from src into dst  *	  *	Dst must be 4 times the size of src to account for possible  *	expansion.  The length of dst, not including the trailing NULL,  *	is returned.   *  *	Strvisx encodes exactly len bytes from src into dst.  *	This is useful for encoding a block of data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRVIS
end_ifndef

begin_function
name|int
name|strvis
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
name|char
name|extra
index|[
name|MAXEXTRAS
index|]
decl_stmt|;
name|MAKEEXTRALIST
argument_list|(
name|flag
argument_list|,
name|extra
argument_list|)
expr_stmt|;
return|return
operator|(
name|strsvis
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|flag
argument_list|,
name|extra
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRVISX
end_ifndef

begin_function
name|int
name|strvisx
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
name|char
name|extra
index|[
name|MAXEXTRAS
index|]
decl_stmt|;
name|MAKEEXTRALIST
argument_list|(
name|flag
argument_list|,
name|extra
argument_list|)
expr_stmt|;
return|return
operator|(
name|strsvisx
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|len
argument_list|,
name|flag
argument_list|,
name|extra
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

