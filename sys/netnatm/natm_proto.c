begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: natm_proto.c,v 1.3 1996/09/18 00:56:41 chuck Exp $	*/
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *      Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * protocol layer for access to native mode ATM  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netnatm/natm.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|natmdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|natm_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protosw
name|natmsw
index|[]
init|=
block|{
block|{
name|SOCK_STREAM
block|,
operator|&
name|natmdomain
block|,
name|PROTO_NATMAAL5
block|,
name|PR_CONNREQUIRED
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
ifdef|#
directive|ifdef
name|FREEBSD_USRREQS
literal|0
block|,
else|#
directive|else
name|natm_usrreq
block|,
endif|#
directive|endif
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|natm5_sysctl
elif|#
directive|elif
name|defined
argument_list|(
name|FREEBSD_USRREQS
argument_list|)
operator|&
name|natm_usrreqs
endif|#
directive|endif
block|}
block|,
block|{
name|SOCK_DGRAM
block|,
operator|&
name|natmdomain
block|,
name|PROTO_NATMAAL5
block|,
name|PR_CONNREQUIRED
operator||
name|PR_ATOMIC
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
ifdef|#
directive|ifdef
name|FREEBSD_USRREQS
literal|0
block|,
else|#
directive|else
name|natm_usrreq
block|,
endif|#
directive|endif
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|natm5_sysctl
elif|#
directive|elif
name|defined
argument_list|(
name|FREEBSD_USRREQS
argument_list|)
operator|&
name|natm_usrreqs
endif|#
directive|endif
block|}
block|,
block|{
name|SOCK_STREAM
block|,
operator|&
name|natmdomain
block|,
name|PROTO_NATMAAL0
block|,
name|PR_CONNREQUIRED
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
ifdef|#
directive|ifdef
name|FREEBSD_USRREQS
literal|0
block|,
else|#
directive|else
name|natm_usrreq
block|,
endif|#
directive|endif
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|natm0_sysctl
elif|#
directive|elif
name|defined
argument_list|(
name|FREEBSD_USRREQS
argument_list|)
operator|&
name|natm_usrreqs
endif|#
directive|endif
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|natmdomain
init|=
block|{
name|AF_NATM
block|,
literal|"natm"
block|,
name|natm_init
block|,
literal|0
block|,
literal|0
block|,
name|natmsw
block|,
operator|&
name|natmsw
index|[
sizeof|sizeof
argument_list|(
name|natmsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|natmsw
index|[
literal|0
index|]
argument_list|)
index|]
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|natmintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* natm packet input queue */
end_comment

begin_decl_stmt
name|int
name|natmqmaxlen
init|=
name|IFQ_MAXLEN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # of packets on queue */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NATM_STAT
end_ifdef

begin_decl_stmt
name|u_int
name|natm_sodropcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # mbufs dropped due to full sb */
end_comment

begin_decl_stmt
name|u_int
name|natm_sodropbytes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of bytes dropped */
end_comment

begin_decl_stmt
name|u_int
name|natm_sookcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # mbufs ok */
end_comment

begin_decl_stmt
name|u_int
name|natm_sookbytes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of bytes ok */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|natm_init
parameter_list|()
block|{
name|LIST_INIT
argument_list|(
operator|&
name|natm_pcbs
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|natmintrq
argument_list|,
sizeof|sizeof
argument_list|(
name|natmintrq
argument_list|)
argument_list|)
expr_stmt|;
name|natmintrq
operator|.
name|ifq_maxlen
operator|=
name|natmqmaxlen
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_expr_stmt
name|DOMAIN_SET
argument_list|(
name|natm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

