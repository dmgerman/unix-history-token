begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, Mike Mitchell  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx_var.h  *  * $Id: ipx_var.h,v 1.8 1997/08/16 19:15:46 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPX_VAR_H_
end_define

begin_comment
comment|/*  * IPX Kernel Structures and Variables  */
end_comment

begin_struct
struct|struct
name|ipxstat
block|{
name|u_long
name|ipxs_total
decl_stmt|;
comment|/* total packets received */
name|u_long
name|ipxs_badsum
decl_stmt|;
comment|/* checksum bad */
name|u_long
name|ipxs_tooshort
decl_stmt|;
comment|/* packet too short */
name|u_long
name|ipxs_toosmall
decl_stmt|;
comment|/* not enough data */
name|u_long
name|ipxs_forward
decl_stmt|;
comment|/* packets forwarded */
name|u_long
name|ipxs_cantforward
decl_stmt|;
comment|/* packets rcvd for unreachable dest */
name|u_long
name|ipxs_delivered
decl_stmt|;
comment|/* datagrams delivered to upper level*/
name|u_long
name|ipxs_localout
decl_stmt|;
comment|/* total ipx packets generated here */
name|u_long
name|ipxs_odropped
decl_stmt|;
comment|/* lost packets due to nobufs, etc. */
name|u_long
name|ipxs_noroute
decl_stmt|;
comment|/* packets discarded due to no route */
name|u_long
name|ipxs_mtutoosmall
decl_stmt|;
comment|/* the interface mtu is too small */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ipxcksum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ipx_pexseq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipxstat
name|ipxstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipxpcb
name|ipxrawpcb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|ipx_usrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|ripx_usrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_ipx
name|ipx_netmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_ipx
name|ipx_hostmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|ipx_net
name|ipx_zeronet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|ipx_host
name|ipx_zerohost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|ipx_net
name|ipx_broadnet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|ipx_host
name|ipx_broadhost
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipx_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|ipx_abort
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|ipx_cksum
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_control
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_ctlinput
name|__P
argument_list|(
operator|(
name|int
name|cmd
operator|,
expr|struct
name|sockaddr
operator|*
name|arg_as_sa
operator|,
name|void
operator|*
name|dummy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_ctloutput
name|__P
argument_list|(
operator|(
name|int
name|req
operator|,
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|level
operator|,
name|int
name|name
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|value
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_drop
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
operator|,
name|int
name|errno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|ipxpcb
operator|*
name|ipxp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipxintr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_outputfl
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m0
operator|,
expr|struct
name|route
operator|*
name|ro
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_output_type20
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_peeraddr
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_printhost
name|__P
argument_list|(
operator|(
expr|struct
name|ipx_addr
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_sockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_watch_output
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|ifnet
operator|*
name|ifp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_IPX_VAR_H_ */
end_comment

end_unit

