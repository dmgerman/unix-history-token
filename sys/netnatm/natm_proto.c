begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *      Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: natm_proto.c,v 1.3 1996/09/18 00:56:41 chuck Exp $  */
end_comment

begin_comment
comment|/*  * protocol layer for access to native mode ATM  */
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
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
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

begin_function_decl
specifier|static
name|void
name|natm_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|domain
name|natmdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|protosw
name|natmsw
index|[]
init|=
block|{
block|{
operator|.
name|pr_type
operator|=
name|SOCK_STREAM
block|,
operator|.
name|pr_domain
operator|=
operator|&
name|natmdomain
block|,
operator|.
name|pr_protocol
operator|=
name|PROTO_NATMAAL5
block|,
operator|.
name|pr_flags
operator|=
name|PR_CONNREQUIRED
block|,
operator|.
name|pr_usrreqs
operator|=
operator|&
name|natm_usrreqs
block|}
block|,
block|{
operator|.
name|pr_type
operator|=
name|SOCK_DGRAM
block|,
operator|.
name|pr_domain
operator|=
operator|&
name|natmdomain
block|,
operator|.
name|pr_protocol
operator|=
name|PROTO_NATMAAL5
block|,
operator|.
name|pr_flags
operator|=
name|PR_CONNREQUIRED
operator||
name|PR_ATOMIC
block|,
operator|.
name|pr_usrreqs
operator|=
operator|&
name|natm_usrreqs
block|}
block|,
block|{
operator|.
name|pr_type
operator|=
name|SOCK_STREAM
block|,
operator|.
name|pr_domain
operator|=
operator|&
name|natmdomain
block|,
operator|.
name|pr_protocol
operator|=
name|PROTO_NATMAAL0
block|,
operator|.
name|pr_flags
operator|=
name|PR_CONNREQUIRED
block|,
operator|.
name|pr_usrreqs
operator|=
operator|&
name|natm_usrreqs
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|domain
name|natmdomain
init|=
block|{
operator|.
name|dom_family
operator|=
name|AF_NATM
block|,
operator|.
name|dom_name
operator|=
literal|"natm"
block|,
operator|.
name|dom_init
operator|=
name|natm_init
block|,
operator|.
name|dom_protosw
operator|=
name|natmsw
block|,
operator|.
name|dom_protoswNPROTOSW
operator|=
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
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|natmqmaxlen
init|=
literal|1000
comment|/* IFQ_MAXLEN */
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # of packets on queue */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|ifqueue
name|natmintrq
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NATM_STAT
end_ifdef

begin_decl_stmt
name|u_int
name|natm_sodropcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # mbufs dropped due to full sb */
end_comment

begin_decl_stmt
name|u_int
name|natm_sodropbytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of bytes dropped */
end_comment

begin_decl_stmt
name|u_int
name|natm_sookcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # mbufs ok */
end_comment

begin_decl_stmt
name|u_int
name|natm_sookbytes
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
specifier|static
name|void
name|natm_init
parameter_list|(
name|void
parameter_list|)
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
name|NATM_LOCK_INIT
argument_list|()
expr_stmt|;
name|mtx_init
argument_list|(
operator|&
name|natmintrq
operator|.
name|ifq_mtx
argument_list|,
literal|"natm_inq"
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
name|netisr_register
argument_list|(
name|NETISR_NATM
argument_list|,
name|natmintr
argument_list|,
operator|&
name|natmintrq
argument_list|,
name|NETISR_MPSAFE
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|DOMAIN_SET
argument_list|(
name|natm
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

