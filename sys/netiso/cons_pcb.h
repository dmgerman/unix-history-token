begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cons_pcb.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_CONS_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_CONS_PCB_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/cons_pcb.h,v $ */
end_comment

begin_comment
comment|/*  * protocol control block for the connection oriented network service  */
end_comment

begin_comment
comment|/*  * legit port #s for cons "transport" are 0..23 for su users only, and  * 1024..1099 for public users  */
end_comment

begin_define
define|#
directive|define
name|X25_SBSIZE
value|512
end_define

begin_define
define|#
directive|define
name|X25_PORT_RESERVED
value|24
end_define

begin_define
define|#
directive|define
name|X25_PORT_USERMAX
value|1099
end_define

begin_define
define|#
directive|define
name|X25_FACIL_LEN_MAX
value|109
end_define

begin_define
define|#
directive|define
name|X25_PARTIAL_PKT_LEN_MAX
value|(MLEN - sizeof(struct cons_pcb))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ARGO_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|X25_TTL
value|600
end_define

begin_comment
comment|/* 5 min */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_define
define|#
directive|define
name|X25_TTL
value|120
end_define

begin_comment
comment|/* 1 min */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_struct
struct|struct
name|cons_pcb
block|{
name|struct
name|isopcb
name|_co_isopcb
decl_stmt|;
define|#
directive|define
name|co_next
value|_co_isopcb.isop_next
comment|/* prev used for netstat only */
define|#
directive|define
name|co_prev
value|_co_isopcb.isop_prev
define|#
directive|define
name|co_head
value|_co_isopcb.isop_head
define|#
directive|define
name|co_laddr
value|_co_isopcb.isop_laddr
define|#
directive|define
name|co_faddr
value|_co_isopcb.isop_faddr
define|#
directive|define
name|co_lport
value|_co_isopcb.isop_laddr.siso_tsuffix
define|#
directive|define
name|co_fport
value|_co_isopcb.isop_faddr.siso_tsuffix
define|#
directive|define
name|co_route
value|_co_isopcb.isop_route
define|#
directive|define
name|co_socket
value|_co_isopcb.isop_socket
define|#
directive|define
name|co_chanmask
value|_co_isopcb.isop_chanmask
define|#
directive|define
name|co_negchanmask
value|_co_isopcb.isop_negchanmask
define|#
directive|define
name|co_x25crud
value|_co_isopcb.isop_x25crud
define|#
directive|define
name|co_x25crud_len
value|_co_isopcb.isop_x25crud_len
name|u_short
name|co_state
decl_stmt|;
name|u_char
name|co_flags
decl_stmt|;
name|u_short
name|co_ttl
decl_stmt|;
comment|/* time to live timer */
name|u_short
name|co_init_ttl
decl_stmt|;
comment|/* initial value of ttl  */
name|int
name|co_channel
decl_stmt|;
comment|/* logical channel */
name|struct
name|ifnet
modifier|*
name|co_ifp
decl_stmt|;
comment|/* interface */
name|struct
name|protosw
modifier|*
name|co_proto
decl_stmt|;
name|struct
name|ifqueue
name|co_pending
decl_stmt|;
comment|/* queue data to send when connection 						completes*/
define|#
directive|define
name|MAX_DTE_LEN
value|0x7
comment|/* 17 bcd digits */
name|struct
name|dte_addr
name|co_peer_dte
decl_stmt|;
name|struct
name|cons_pcb
modifier|*
name|co_myself
decl_stmt|;
comment|/* DEBUGGING AID */
block|}
struct|;
end_struct

begin_comment
comment|/*  * X.25 Packet types  */
end_comment

begin_define
define|#
directive|define
name|XPKT_DATA
value|1
end_define

begin_define
define|#
directive|define
name|XPKT_INTERRUPT
value|2
end_define

begin_define
define|#
directive|define
name|XPKT_FLOWCONTROL
value|3
end_define

begin_comment
comment|/* not delivered? */
end_comment

begin_comment
comment|/*  * pcb xtates  */
end_comment

begin_define
define|#
directive|define
name|CLOSED
value|0x0
end_define

begin_define
define|#
directive|define
name|LISTENING
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOSING
value|0x2
end_define

begin_comment
comment|/* USABLE STATES MUST BE LAST */
end_comment

begin_define
define|#
directive|define
name|CONNECTING
value|0x3
end_define

begin_define
define|#
directive|define
name|ACKWAIT
value|0x4
end_define

begin_define
define|#
directive|define
name|OPEN
value|0x5
end_define

begin_define
define|#
directive|define
name|MIN_USABLE_STATE
value|CONNECTING
end_define

begin_define
define|#
directive|define
name|cons_NSTATES
value|0x6
end_define

begin_comment
comment|/* type */
end_comment

begin_define
define|#
directive|define
name|CONSF_OCRE
value|0x40
end_define

begin_comment
comment|/* created on OUTPUT */
end_comment

begin_define
define|#
directive|define
name|CONSF_ICRE
value|0x20
end_define

begin_comment
comment|/* created on INPUT */
end_comment

begin_define
define|#
directive|define
name|CONSF_unused
value|0x10
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|CONSF_unused2
value|0x08
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|CONSF_DGM
value|0x04
end_define

begin_comment
comment|/* for dgm use only */
end_comment

begin_define
define|#
directive|define
name|CONSF_XTS
value|0x02
end_define

begin_comment
comment|/* for cons-as-transport-service */
end_comment

begin_define
define|#
directive|define
name|CONSF_LOOPBACK
value|0x01
end_define

begin_comment
comment|/* loopback was on when connection commenced */
end_comment

begin_define
define|#
directive|define
name|X_NOCHANNEL
value|0x80
end_define

begin_struct
struct|struct
name|cons_stat
block|{
name|u_int
name|co_intr
decl_stmt|;
comment|/* input from eicon board */
name|u_int
name|co_restart
decl_stmt|;
comment|/* ecn_restart() request issued to board */
name|u_int
name|co_slowtimo
decl_stmt|;
comment|/* times slowtimo called */
name|u_int
name|co_timedout
decl_stmt|;
comment|/* connections closed by slowtimo */
name|u_int
name|co_ack
decl_stmt|;
comment|/* ECN_ACK indication came from eicon board */
name|u_int
name|co_receive
decl_stmt|;
comment|/* ECN_RECEIVE indication came from eicon board */
name|u_int
name|co_send
decl_stmt|;
comment|/* ECN_SEND request issued to board */
name|u_int
name|co_reset_in
decl_stmt|;
comment|/* ECN_RESET indication came from eicon board */
name|u_int
name|co_reset_out
decl_stmt|;
comment|/* ECN_RESET issued to the eicon board */
name|u_int
name|co_clear_in
decl_stmt|;
comment|/* ECN_CLEAR indication came from eicon board */
name|u_int
name|co_clear_out
decl_stmt|;
comment|/* ECN_CLEAR request issued to board */
name|u_int
name|co_refuse
decl_stmt|;
comment|/* ECN_REFUSE indication came from eicon board */
name|u_int
name|co_accept
decl_stmt|;
comment|/* ECN_ACCEPT indication came from eicon board */
name|u_int
name|co_connect
decl_stmt|;
comment|/* ECN_CONNECT indication came from eicon board */
name|u_int
name|co_call
decl_stmt|;
comment|/* ECN_CALL request issued to board */
name|u_int
name|co_Rdrops
decl_stmt|;
comment|/* bad pkt came from ll */
name|u_int
name|co_Xdrops
decl_stmt|;
comment|/* can't keep up */
name|u_int
name|co_intrpt_pkts_in
decl_stmt|;
comment|/* interrupt packets in */
name|u_int
name|co_avg_qlen
decl_stmt|;
name|u_int
name|co_avg_qdrop
decl_stmt|;
name|u_int
name|co_active
decl_stmt|;
name|u_int
name|co_noresources
decl_stmt|;
name|u_int
name|co_parse_facil_err
decl_stmt|;
name|u_int
name|co_addr_proto_consist_err
decl_stmt|;
name|u_int
name|co_no_copcb
decl_stmt|;
block|}
name|cons_stat
struct|;
end_struct

begin_decl_stmt
name|u_char
name|x25_error_stats
index|[
name|CONL_ERROR_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|consintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reasons for clear are in a data mbuf chained to a clear ecn_request */
end_comment

begin_struct
struct|struct
name|e_clear_data
block|{
name|u_char
name|ecd_cause
decl_stmt|;
name|u_char
name|ecd_diagnostic
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IncStat
parameter_list|(
name|XYZ
parameter_list|)
value|cons_stat.XYZ++
end_define

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

end_unit

