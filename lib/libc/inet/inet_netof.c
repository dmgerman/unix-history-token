begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)inet_netof.c	8.1 (Berkeley) 6/4/93"
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
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_comment
comment|/*  * Return the network number from an internet  * address; handles class a/b/c network #'s.  */
end_comment

begin_function
name|in_addr_t
name|inet_netof
parameter_list|(
name|in
parameter_list|)
name|struct
name|in_addr
name|in
decl_stmt|;
block|{
name|in_addr_t
name|i
init|=
name|ntohl
argument_list|(
name|in
operator|.
name|s_addr
argument_list|)
decl_stmt|;
if|if
condition|(
name|IN_CLASSA
argument_list|(
name|i
argument_list|)
condition|)
return|return
operator|(
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSA_NET
operator|)
operator|>>
name|IN_CLASSA_NSHIFT
operator|)
return|;
elseif|else
if|if
condition|(
name|IN_CLASSB
argument_list|(
name|i
argument_list|)
condition|)
return|return
operator|(
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSB_NET
operator|)
operator|>>
name|IN_CLASSB_NSHIFT
operator|)
return|;
else|else
return|return
operator|(
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSC_NET
operator|)
operator|>>
name|IN_CLASSC_NSHIFT
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Weak aliases for applications that use certain private entry points,  * and fail to include<arpa/inet.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|inet_netof
end_undef

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_netof
argument_list|,
name|inet_netof
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

