begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
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
literal|"$Id: res_comp.c,v 1.2 2000/02/02 19:59:16 mellon Exp $"
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
file|<ctype.h>
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
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|"minires/minires.h"
end_include

begin_include
include|#
directive|include
file|"arpa/nameser.h"
end_include

begin_comment
comment|/*  * Expand compressed domain name 'comp_dn' to full domain name.  * 'msg' is a pointer to the begining of the message,  * 'eomorig' points to the first location after the message,  * 'exp_dn' is a pointer to a buffer of size 'length' for the result.  * Return size of compressed name or -1 if there was an error.  */
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
name|unsigned
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
comment|/*  * Pack domain name 'exp_dn' in presentation form into 'comp_dn'.  * Return the size of the compressed name or -1.  * 'length' is the size of the array pointed to by 'comp_dn'.  */
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
name|unsigned
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
comment|/*  * Skip over a compressed domain name. Return the size or -1.  */
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
comment|/*  * Verify that a domain name uses an acceptable character set.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Note the conspicuous absence of ctype macros in these definitions.  On  * non-ASCII hosts, we can't depend on string literals or ctype macros to  * tell us anything about network-format data.  The rest of the BIND system  * is not careful about this, but for some reason, we're doing it right here.  */
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

begin_define
define|#
directive|define
name|borderchar
parameter_list|(
name|c
parameter_list|)
value|(alphachar(c) || digitchar(c))
end_define

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

begin_comment
unit|int res_hnok(const char *dn) { 	int ppch = '\0', pch = PERIOD, ch = *dn++;  	while (ch != '\0') { 		int nch = *dn++;  		if (periodchar(ch)) { 			(void)NULL; 		} else if (periodchar(pch)) { 			if (!borderchar(ch)) 				return (0); 		} else if (periodchar(nch) || nch == '\0') { 			if (!borderchar(ch)) 				return (0); 		} else { 			if (!middlechar(ch)) 				return (0); 		} 		ppch = pch, pch = ch, ch = nch; 	} 	return (1); }
comment|/*  * hostname-like (A, MX, WKS) owners can have "*" as their first label  * but must otherwise be as a host name.  */
end_comment

begin_comment
unit|int res_ownok(const char *dn) { 	if (asterchar(dn[0])) { 		if (periodchar(dn[1])) 			return (res_hnok(dn+2)); 		if (dn[1] == '\0') 			return (1); 	} 	return (res_hnok(dn)); }
comment|/*  * SOA RNAMEs and RP RNAMEs can have any printable character in their first  * label, but the rest of the name has to look like a host name.  */
end_comment

begin_comment
unit|int res_mailok(const char *dn) { 	int ch, escaped = 0;
comment|/* "." is a valid missing representation */
end_comment

begin_comment
unit|if (*dn == '\0') 		return (1);
comment|/* otherwise<label>.<hostname> */
end_comment

begin_comment
unit|while ((ch = *dn++) != '\0') { 		if (!domainchar(ch)) 			return (0); 		if (!escaped&& periodchar(ch)) 			break; 		if (escaped) 			escaped = 0; 		else if (bslashchar(ch)) 			escaped = 1; 	} 	if (periodchar(ch)) 		return (res_hnok(dn)); 	return (0); }
comment|/*  * This function is quite liberal, since RFC 1034's character sets are only  * recommendations.  */
end_comment

begin_endif
unit|int res_dnok(const char *dn) { 	int ch;  	while ((ch = *dn++) != '\0') 		if (!domainchar(ch)) 			return (0); 	return (1); }
endif|#
directive|endif
end_endif

end_unit

