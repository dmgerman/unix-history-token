begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipsec.h,v 1.44 2001/03/23 08:08:47 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * IPsec controller part.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IPSEC6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IPSEC6_H_
end_define

begin_include
include|#
directive|include
file|<net/pfkeyv2.h>
end_include

begin_include
include|#
directive|include
file|<netkey/keydb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ipsecstat
name|ipsec6stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
name|ip6_def_policy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_esp_trans_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_esp_net_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_ah_trans_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_ah_net_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_ipsec_ecn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_esp_randpad
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|ipsec6_getpolicybysock
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|socket
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|ipsec6_getpolicybyaddr
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_in_reject_so
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_delete_pcbpolicy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_set_policy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
name|inp
operator|,
name|int
name|optname
operator|,
name|caddr_t
name|request
operator|,
name|size_t
name|len
operator|,
name|int
name|priv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_get_policy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
name|inp
operator|,
name|caddr_t
name|request
operator|,
name|size_t
name|len
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_in_reject
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|tcp6cb
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|size_t
name|ipsec6_hdrsiz
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ip6_hdr
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ipsec6_logpacketstr
name|__P
argument_list|(
operator|(
expr|struct
name|ip6_hdr
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_output_trans
name|__P
argument_list|(
operator|(
expr|struct
name|ipsec_output_state
operator|*
operator|,
name|u_char
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|secpolicy
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_output_tunnel
name|__P
argument_list|(
operator|(
expr|struct
name|ipsec_output_state
operator|*
operator|,
expr|struct
name|secpolicy
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec6_tunnel_validate
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|u_int
operator|,
expr|struct
name|secasvar
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
comment|/*_KERNEL*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETINET6_IPSEC6_H_*/
end_comment

end_unit

