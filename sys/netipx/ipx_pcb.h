begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, Mike Mitchell  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx_pcb.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPX_PCB_H_
end_define

begin_comment
comment|/*  * IPX protocol interface control block.  */
end_comment

begin_struct
struct|struct
name|ipxpcb
block|{
name|struct
name|ipxpcb
modifier|*
name|ipxp_next
decl_stmt|;
comment|/* doubly linked list */
name|struct
name|ipxpcb
modifier|*
name|ipxp_prev
decl_stmt|;
name|struct
name|ipxpcb
modifier|*
name|ipxp_head
decl_stmt|;
name|struct
name|socket
modifier|*
name|ipxp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|ipx_addr
name|ipxp_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|ipx_addr
name|ipxp_laddr
decl_stmt|;
comment|/* socket's address */
name|caddr_t
name|ipxp_pcb
decl_stmt|;
comment|/* protocol specific stuff */
name|struct
name|route
name|ipxp_route
decl_stmt|;
comment|/* routing information */
name|struct
name|ipx_addr
name|ipxp_lastdst
decl_stmt|;
comment|/* validate cached route for dg socks*/
name|long
name|ipxp_notify_param
decl_stmt|;
comment|/* extra info passed via ipx_pcbnotify*/
name|short
name|ipxp_flags
decl_stmt|;
name|u_char
name|ipxp_dpt
decl_stmt|;
comment|/* default packet type for ipx_output */
name|u_char
name|ipxp_rpt
decl_stmt|;
comment|/* last received packet type by ipx_input() */
block|}
struct|;
end_struct

begin_comment
comment|/* possible flags */
end_comment

begin_define
define|#
directive|define
name|IPXP_IN_ABORT
value|0x1
end_define

begin_comment
comment|/* calling abort through socket */
end_comment

begin_define
define|#
directive|define
name|IPXP_RAWIN
value|0x2
end_define

begin_comment
comment|/* show headers on input */
end_comment

begin_define
define|#
directive|define
name|IPXP_RAWOUT
value|0x4
end_define

begin_comment
comment|/* show header on output */
end_comment

begin_define
define|#
directive|define
name|IPXP_ALL_PACKETS
value|0x8
end_define

begin_comment
comment|/* Turn off higher proto processing */
end_comment

begin_define
define|#
directive|define
name|IPXP_CHECKSUM
value|0x10
end_define

begin_comment
comment|/* use checksum on this socket */
end_comment

begin_define
define|#
directive|define
name|IPX_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|ipxp_lport
value|ipxp_laddr.x_port
end_define

begin_define
define|#
directive|define
name|ipxp_fport
value|ipxp_faddr.x_port
end_define

begin_define
define|#
directive|define
name|sotoipxpcb
parameter_list|(
name|so
parameter_list|)
value|((struct ipxpcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Nominal space allocated to a IPX socket.  */
end_comment

begin_define
define|#
directive|define
name|IPXSNDQ
value|16384
end_define

begin_define
define|#
directive|define
name|IPXRCVQ
value|40960
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ipxpcb
name|ipxpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list */
end_comment

begin_decl_stmt
name|int
name|ipx_pcballoc
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|ipxpcb
operator|*
name|head
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
name|int
name|ipx_pcbbind
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
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
name|int
name|ipx_pcbconnect
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
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
name|ipx_pcbdetach
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
name|void
name|ipx_pcbdisconnect
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
name|struct
name|ipxpcb
modifier|*
name|ipx_pcblookup
name|__P
argument_list|(
operator|(
expr|struct
name|ipx_addr
operator|*
name|faddr
operator|,
name|int
name|lport
operator|,
name|int
name|wildp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_pcbnotify
name|__P
argument_list|(
operator|(
expr|struct
name|ipx_addr
operator|*
name|dst
operator|,
name|int
name|errno
operator|,
name|void
argument_list|(
operator|*
name|notify
argument_list|)
argument_list|(
expr|struct
name|ipxpcb
operator|*
argument_list|)
operator|,
name|long
name|param
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_setpeeraddr
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
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
name|ipx_setsockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
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

begin_comment
comment|/* !_NETIPX_IPX_PCB_H_ */
end_comment

end_unit

