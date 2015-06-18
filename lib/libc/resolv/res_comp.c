begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)res_comp.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: res_comp.c,v 1.3.18.2 2005/07/28 07:38:11 marka Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_comment
comment|/*%  * Expand compressed domain name 'src' to full domain name.  *  * \li 'msg' is a pointer to the begining of the message,  * \li 'eom' points to the first location after the message,  * \li 'dst' is a pointer to a buffer of size 'dstsiz' for the result.  * \li Return size of compressed name or -1 if there was an error.  */
end_comment

begin_function
name|int
name|dn_expand
parameter_list|(
specifier|const
name|u_char
modifier|*
name|msg
parameter_list|,
specifier|const
name|u_char
modifier|*
name|eom
parameter_list|,
specifier|const
name|u_char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|int
name|dstsiz
parameter_list|)
block|{
name|int
name|n
init|=
name|ns_name_uncompress
argument_list|(
name|msg
argument_list|,
name|eom
argument_list|,
name|src
argument_list|,
name|dst
argument_list|,
operator|(
name|size_t
operator|)
name|dstsiz
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
operator|&&
name|dst
index|[
literal|0
index|]
operator|==
literal|'.'
condition|)
name|dst
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/*%  * Pack domain name 'exp_dn' in presentation form into 'comp_dn'.  *  * \li Return the size of the compressed name or -1.  * \li 'length' is the size of the array pointed to by 'comp_dn'.  */
end_comment

begin_function
name|int
name|dn_comp
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|u_char
modifier|*
name|dst
parameter_list|,
name|int
name|dstsiz
parameter_list|,
name|u_char
modifier|*
modifier|*
name|dnptrs
parameter_list|,
name|u_char
modifier|*
modifier|*
name|lastdnptr
parameter_list|)
block|{
return|return
operator|(
name|ns_name_compress
argument_list|(
name|src
argument_list|,
name|dst
argument_list|,
operator|(
name|size_t
operator|)
name|dstsiz
argument_list|,
operator|(
specifier|const
name|u_char
operator|*
operator|*
operator|)
name|dnptrs
argument_list|,
operator|(
specifier|const
name|u_char
operator|*
operator|*
operator|)
name|lastdnptr
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*%  * Skip over a compressed domain name. Return the size or -1.  */
end_comment

begin_function
name|int
name|dn_skipname
parameter_list|(
specifier|const
name|u_char
modifier|*
name|ptr
parameter_list|,
specifier|const
name|u_char
modifier|*
name|eom
parameter_list|)
block|{
specifier|const
name|u_char
modifier|*
name|saveptr
init|=
name|ptr
decl_stmt|;
if|if
condition|(
name|ns_name_skip
argument_list|(
operator|&
name|ptr
argument_list|,
name|eom
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|ptr
operator|-
name|saveptr
operator|)
return|;
block|}
end_function

begin_comment
comment|/*%  * Verify that a domain name uses an acceptable character set.  *  * Note the conspicuous absence of ctype macros in these definitions.  On  * non-ASCII hosts, we can't depend on string literals or ctype macros to  * tell us anything about network-format data.  The rest of the BIND system  * is not careful about this, but for some reason, we're doing it right here.  */
end_comment

begin_define
define|#
directive|define
name|PERIOD
value|0x2e
end_define

begin_define
define|#
directive|define
name|hyphenchar
parameter_list|(
name|c
parameter_list|)
value|((c) == 0x2d)
end_define

begin_define
define|#
directive|define
name|bslashchar
parameter_list|(
name|c
parameter_list|)
value|((c) == 0x5c)
end_define

begin_define
define|#
directive|define
name|underscorechar
parameter_list|(
name|c
parameter_list|)
value|((c) == 0x5f)
end_define

begin_define
define|#
directive|define
name|periodchar
parameter_list|(
name|c
parameter_list|)
value|((c) == PERIOD)
end_define

begin_define
define|#
directive|define
name|asterchar
parameter_list|(
name|c
parameter_list|)
value|((c) == 0x2a)
end_define

begin_define
define|#
directive|define
name|alphachar
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0x41&& (c)<= 0x5a) \ 		   || ((c)>= 0x61&& (c)<= 0x7a))
end_define

begin_define
define|#
directive|define
name|digitchar
parameter_list|(
name|c
parameter_list|)
value|((c)>= 0x30&& (c)<= 0x39)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RES_ENFORCE_RFC1034
end_ifdef

begin_define
define|#
directive|define
name|borderchar
parameter_list|(
name|c
parameter_list|)
value|(alphachar(c) || digitchar(c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|borderchar
parameter_list|(
name|c
parameter_list|)
value|(alphachar(c) || digitchar(c) || underscorechar(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|middlechar
parameter_list|(
name|c
parameter_list|)
value|(borderchar(c) || hyphenchar(c))
end_define

begin_define
define|#
directive|define
name|domainchar
parameter_list|(
name|c
parameter_list|)
value|((c)> 0x20&& (c)< 0x7f)
end_define

begin_function
name|int
name|res_hnok
parameter_list|(
specifier|const
name|char
modifier|*
name|dn
parameter_list|)
block|{
name|int
name|pch
init|=
name|PERIOD
decl_stmt|,
name|ch
init|=
operator|*
name|dn
operator|++
decl_stmt|;
while|while
condition|(
name|ch
operator|!=
literal|'\0'
condition|)
block|{
name|int
name|nch
init|=
operator|*
name|dn
operator|++
decl_stmt|;
if|if
condition|(
name|periodchar
argument_list|(
name|ch
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|NULL
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|periodchar
argument_list|(
name|pch
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|borderchar
argument_list|(
name|ch
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|periodchar
argument_list|(
name|nch
argument_list|)
operator|||
name|nch
operator|==
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|!
name|borderchar
argument_list|(
name|ch
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|middlechar
argument_list|(
name|ch
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|pch
operator|=
name|ch
operator|,
name|ch
operator|=
name|nch
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*%  * hostname-like (A, MX, WKS) owners can have "*" as their first label  * but must otherwise be as a host name.  */
end_comment

begin_function
name|int
name|res_ownok
parameter_list|(
specifier|const
name|char
modifier|*
name|dn
parameter_list|)
block|{
if|if
condition|(
name|asterchar
argument_list|(
name|dn
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
if|if
condition|(
name|periodchar
argument_list|(
name|dn
index|[
literal|1
index|]
argument_list|)
condition|)
return|return
operator|(
name|res_hnok
argument_list|(
name|dn
operator|+
literal|2
argument_list|)
operator|)
return|;
if|if
condition|(
name|dn
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|res_hnok
argument_list|(
name|dn
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*%  * SOA RNAMEs and RP RNAMEs can have any printable character in their first  * label, but the rest of the name has to look like a host name.  */
end_comment

begin_function
name|int
name|res_mailok
parameter_list|(
specifier|const
name|char
modifier|*
name|dn
parameter_list|)
block|{
name|int
name|ch
decl_stmt|,
name|escaped
init|=
literal|0
decl_stmt|;
comment|/* "." is a valid missing representation */
if|if
condition|(
operator|*
name|dn
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* otherwise<label>.<hostname> */
while|while
condition|(
operator|(
name|ch
operator|=
operator|*
name|dn
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|!
name|domainchar
argument_list|(
name|ch
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|!
name|escaped
operator|&&
name|periodchar
argument_list|(
name|ch
argument_list|)
condition|)
break|break;
if|if
condition|(
name|escaped
condition|)
name|escaped
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|bslashchar
argument_list|(
name|ch
argument_list|)
condition|)
name|escaped
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|periodchar
argument_list|(
name|ch
argument_list|)
condition|)
return|return
operator|(
name|res_hnok
argument_list|(
name|dn
argument_list|)
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*%  * This function is quite liberal, since RFC1034's character sets are only  * recommendations.  */
end_comment

begin_function
name|int
name|res_dnok
parameter_list|(
specifier|const
name|char
modifier|*
name|dn
parameter_list|)
block|{
name|int
name|ch
decl_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
operator|*
name|dn
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|!
name|domainchar
argument_list|(
name|ch
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_4_COMPAT
end_ifdef

begin_comment
comment|/*%  * This module must export the following externally-visible symbols:  *	___putlong  *	___putshort  *	__getlong  *	__getshort  * Note that one _ comes from C and the others come from us.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS2
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__putlong
end_ifdef

begin_undef
undef|#
directive|undef
name|__putlong
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__putshort
end_ifdef

begin_undef
undef|#
directive|undef
name|__putshort
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|weak
name|putlong
name|=
name|__putlong
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|putshort
name|=
name|__putshort
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS2 */
end_comment

begin_function
name|void
name|__putlong
parameter_list|(
name|u_int32_t
name|src
parameter_list|,
name|u_char
modifier|*
name|dst
parameter_list|)
block|{
name|ns_put32
argument_list|(
name|src
argument_list|,
name|dst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__putshort
parameter_list|(
name|u_int16_t
name|src
parameter_list|,
name|u_char
modifier|*
name|dst
parameter_list|)
block|{
name|ns_put16
argument_list|(
name|src
argument_list|,
name|dst
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|__ultrix__
end_ifndef

begin_function
name|u_int32_t
name|_getlong
parameter_list|(
specifier|const
name|u_char
modifier|*
name|src
parameter_list|)
block|{
return|return
operator|(
name|ns_get32
argument_list|(
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|u_int16_t
name|_getshort
parameter_list|(
specifier|const
name|u_char
modifier|*
name|src
parameter_list|)
block|{
return|return
operator|(
name|ns_get16
argument_list|(
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__ultrix__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*BIND_4_COMPAT*/
end_comment

begin_comment
comment|/*  * Weak aliases for applications that use certain private entry points,  * and fail to include<resolv.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|dn_comp
end_undef

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dn_comp
argument_list|,
name|dn_comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|dn_expand
end_undef

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dn_expand
argument_list|,
name|dn_expand
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*! \file */
end_comment

end_unit

