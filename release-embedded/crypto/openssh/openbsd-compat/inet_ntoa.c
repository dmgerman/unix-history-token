begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: inet_ntoa.c,v 1.6 2005/08/06 20:30:03 espie Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: lib/libc/net/inet_ntoa.c */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_INET_NTOA
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_INET_NTOA
argument_list|)
end_if

begin_comment
comment|/*  * Convert network-format internet address  * to base 256 d.d.d.d representation.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
name|in
parameter_list|)
block|{
specifier|static
name|char
name|b
index|[
literal|18
index|]
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|in
expr_stmt|;
define|#
directive|define
name|UC
parameter_list|(
name|b
parameter_list|)
value|(((int)b)&0xff)
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|b
argument_list|)
argument_list|,
literal|"%u.%u.%u.%u"
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|2
index|]
argument_list|)
argument_list|,
name|UC
argument_list|(
name|p
index|[
literal|3
index|]
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|b
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(BROKEN_INET_NTOA) || !defined(HAVE_INET_NTOA) */
end_comment

end_unit

