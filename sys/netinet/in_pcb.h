begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990, 1993  *	Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)in_pcb.h	7.6 (Berkeley) 6/28/90  *	$Id: in_pcb.h,v 1.5 1993/11/25 01:35:06 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_PCB_H_
value|1
end_define

begin_comment
comment|/*  * Common structure pcb for internet protocol implementation.  * Here are stored pointers to local and foreign host table  * entries, local and foreign socket numbers, and pointers  * up (to a socket structure) and down (to a protocol-specific)  * control block.  */
end_comment

begin_struct
struct|struct
name|inpcb
block|{
name|struct
name|inpcb
modifier|*
name|inp_next
decl_stmt|,
modifier|*
name|inp_prev
decl_stmt|;
comment|/* pointers to other pcb's */
name|struct
name|inpcb
modifier|*
name|inp_head
decl_stmt|;
comment|/* pointer back to chain of inpcb's 					   for this protocol */
name|struct
name|in_addr
name|inp_faddr
decl_stmt|;
comment|/* foreign host table entry */
name|u_short
name|inp_fport
decl_stmt|;
comment|/* foreign port */
name|struct
name|in_addr
name|inp_laddr
decl_stmt|;
comment|/* local host table entry */
name|u_short
name|inp_lport
decl_stmt|;
comment|/* local port */
name|struct
name|socket
modifier|*
name|inp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|caddr_t
name|inp_ppcb
decl_stmt|;
comment|/* pointer to per-protocol pcb */
name|struct
name|route
name|inp_route
decl_stmt|;
comment|/* placeholder for routing entry */
name|int
name|inp_flags
decl_stmt|;
comment|/* generic IP/datagram flags */
name|struct
name|ip
name|inp_ip
decl_stmt|;
comment|/* header prototype; should have more */
name|struct
name|mbuf
modifier|*
name|inp_options
decl_stmt|;
comment|/* IP options */
ifdef|#
directive|ifdef
name|MTUDISC
name|int
name|inp_pmtu
decl_stmt|;
comment|/* path mtu if INP_MTUDISCOVERED */
name|int
name|inp_mtutimer
decl_stmt|;
comment|/* decremented once a minute to 					   try to increase mtu */
name|int
function_decl|(
modifier|*
name|inp_mtunotify
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* function to call when MTU may have 				 * changed */
endif|#
directive|endif
comment|/* MTUDISC */
name|struct
name|ip_moptions
modifier|*
name|inp_moptions
decl_stmt|;
comment|/* IP multicast options */
block|}
struct|;
end_struct

begin_comment
comment|/* flags in inp_flags: */
end_comment

begin_define
define|#
directive|define
name|INP_RECVOPTS
value|0x01
end_define

begin_comment
comment|/* receive incoming IP options */
end_comment

begin_define
define|#
directive|define
name|INP_RECVRETOPTS
value|0x02
end_define

begin_comment
comment|/* receive IP options for reply */
end_comment

begin_define
define|#
directive|define
name|INP_RECVDSTADDR
value|0x04
end_define

begin_comment
comment|/* receive IP dst address */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MTUDISC
end_ifdef

begin_define
define|#
directive|define
name|INP_DISCOVERMTU
value|0x08
end_define

begin_comment
comment|/* practice Path MTU discovery */
end_comment

begin_define
define|#
directive|define
name|INP_MTUDISCOVERED
value|0x10
end_define

begin_comment
comment|/* we were able to get such a route */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTUDISC */
end_comment

begin_define
define|#
directive|define
name|INP_CONTROLOPTS
value|(INP_RECVOPTS|INP_RECVRETOPTS|INP_RECVDSTADDR)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sotorawcb
end_ifdef

begin_comment
comment|/*  * Common structure pcb for raw internet protocol access.  * Here are internet specific extensions to the raw control block,  * and space is allocated to the necessary sockaddrs.  */
end_comment

begin_struct
struct|struct
name|raw_inpcb
block|{
name|struct
name|rawcb
name|rinp_rcb
decl_stmt|;
comment|/* common control block prefix */
name|struct
name|mbuf
modifier|*
name|rinp_options
decl_stmt|;
comment|/* IP options */
name|int
name|rinp_flags
decl_stmt|;
comment|/* flags, e.g. raw sockopts */
define|#
directive|define
name|RINPF_HDRINCL
value|0x1
comment|/* user supplies entire IP header */
name|struct
name|sockaddr_in
name|rinp_faddr
decl_stmt|;
comment|/* foreign address */
name|struct
name|sockaddr_in
name|rinp_laddr
decl_stmt|;
comment|/* local address */
name|struct
name|route
name|rinp_route
decl_stmt|;
comment|/* placeholder for routing entry */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INPLOOKUP_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|INPLOOKUP_SETLOCAL
value|2
end_define

begin_define
define|#
directive|define
name|sotoinpcb
parameter_list|(
name|so
parameter_list|)
value|((struct inpcb *)(so)->so_pcb)
end_define

begin_define
define|#
directive|define
name|sotorawinpcb
parameter_list|(
name|so
parameter_list|)
value|((struct raw_inpcb *)(so)->so_pcb)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* From in_pcb.h: */
end_comment

begin_function_decl
specifier|extern
name|int
name|in_pcballoc
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_pcbbind
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_pcbconnect
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_pcbdisconnect
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_pcbdetach
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_setsockaddr
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_setpeeraddr
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_pcbnotify
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_losing
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_rtchange
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|inpcb
modifier|*
name|in_pcblookup
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MTUDISC
end_ifdef

begin_function_decl
specifier|extern
name|void
name|in_pcbmtu
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_mtunotify
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_bumpmtu
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTUDISC */
end_comment

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
comment|/* _NETINET_IN_PCB_H_ */
end_comment

end_unit

