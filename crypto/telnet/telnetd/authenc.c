begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)authenc.c	8.2 (Berkeley) 5/30/95"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUTHENTICATION
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPTION
end_ifdef

begin_comment
comment|/* Above "#ifdef"s actually "or"'ed together. XXX MarkM  */
end_comment

begin_include
include|#
directive|include
file|"telnetd.h"
end_include

begin_include
include|#
directive|include
file|<libtelnet/misc.h>
end_include

begin_function
name|int
name|net_write
parameter_list|(
name|unsigned
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
block|{
if|if
condition|(
name|nfrontp
operator|+
name|len
operator|<
name|netobuf
operator|+
name|BUFSIZ
condition|)
block|{
name|output_datalen
argument_list|(
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
name|len
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|net_encrypt
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ENCRYPTION
name|char
modifier|*
name|s
init|=
operator|(
name|nclearto
operator|>
name|nbackp
operator|)
condition|?
name|nclearto
else|:
name|nbackp
decl_stmt|;
if|if
condition|(
name|s
operator|<
name|nfrontp
operator|&&
name|encrypt_output
condition|)
block|{
call|(
modifier|*
name|encrypt_output
call|)
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s
argument_list|,
name|nfrontp
operator|-
name|s
argument_list|)
expr_stmt|;
block|}
name|nclearto
operator|=
name|nfrontp
expr_stmt|;
endif|#
directive|endif
comment|/* ENCRYPTION */
block|}
end_function

begin_function
name|int
name|telnet_spin
parameter_list|(
name|void
parameter_list|)
block|{
name|ttloop
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|telnet_getenv
parameter_list|(
name|char
modifier|*
name|val
parameter_list|)
block|{
return|return
operator|(
name|getenv
argument_list|(
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|telnet_gets
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
name|__unused
parameter_list|,
name|char
modifier|*
name|result
name|__unused
parameter_list|,
name|int
name|length
name|__unused
parameter_list|,
name|int
name|echo
name|__unused
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENCRYPTION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTHENTICATION */
end_comment

end_unit

