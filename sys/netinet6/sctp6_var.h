begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, by Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*	$KAME: sctp6_var.h,v 1.7 2004/08/17 04:06:22 itojun Exp $	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_SCTP6_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_SCTP6_VAR_H_
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet6_sctp6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|sctp6_usrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp6_ctloutput
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|sockopt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp6_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp6_output
name|__P
argument_list|(
operator|(
expr|struct
name|sctp_inpcb
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sctp6_ctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

