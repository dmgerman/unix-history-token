begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Id: findsaddr-generic.c,v 1.1 2000/11/23 20:17:12 leres Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* concession to AIX */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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
file|"gnuc.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OS_PROTO_H
end_ifdef

begin_include
include|#
directive|include
file|"os-proto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"findsaddr.h"
end_include

begin_include
include|#
directive|include
file|"ifaddrlist.h"
end_include

begin_include
include|#
directive|include
file|"traceroute.h"
end_include

begin_comment
comment|/*  * Return the source address for the given destination address  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|findsaddr
parameter_list|(
specifier|register
specifier|const
name|struct
name|sockaddr_in
modifier|*
name|to
parameter_list|,
specifier|register
name|struct
name|sockaddr_in
modifier|*
name|from
parameter_list|)
block|{
specifier|register
name|int
name|n
decl_stmt|;
name|struct
name|ifaddrlist
modifier|*
name|al
decl_stmt|;
specifier|static
name|char
name|errbuf
index|[
literal|132
index|]
decl_stmt|;
comment|/* Get the interface address list */
if|if
condition|(
operator|(
name|n
operator|=
name|ifaddrlist
argument_list|(
operator|&
name|al
argument_list|,
name|errbuf
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|errbuf
operator|)
return|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
operator|(
literal|"Can't find any network interfaces"
operator|)
return|;
name|setsin
argument_list|(
name|from
argument_list|,
name|al
operator|->
name|addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Warning: Multiple interfaces found; using %s @ %s\n"
argument_list|,
name|prog
argument_list|,
name|inet_ntoa
argument_list|(
name|from
operator|->
name|sin_addr
argument_list|)
argument_list|,
name|al
operator|->
name|device
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

