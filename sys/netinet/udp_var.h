begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)udp_var.h	8.1 (Berkeley) 6/10/93  * $Id: udp_var.h,v 1.17 1999/02/16 10:49:52 dfr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_UDP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_UDP_VAR_H_
end_define

begin_comment
comment|/*  * UDP kernel structures and variables.  */
end_comment

begin_struct
struct|struct
name|udpiphdr
block|{
name|struct
name|ipovly
name|ui_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|udphdr
name|ui_u
decl_stmt|;
comment|/* udp header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ui_x1
value|ui_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ui_pr
value|ui_i.ih_pr
end_define

begin_define
define|#
directive|define
name|ui_len
value|ui_i.ih_len
end_define

begin_define
define|#
directive|define
name|ui_src
value|ui_i.ih_src
end_define

begin_define
define|#
directive|define
name|ui_dst
value|ui_i.ih_dst
end_define

begin_define
define|#
directive|define
name|ui_sport
value|ui_u.uh_sport
end_define

begin_define
define|#
directive|define
name|ui_dport
value|ui_u.uh_dport
end_define

begin_define
define|#
directive|define
name|ui_ulen
value|ui_u.uh_ulen
end_define

begin_define
define|#
directive|define
name|ui_sum
value|ui_u.uh_sum
end_define

begin_struct
struct|struct
name|udpcb
block|{
comment|/* XXX - these should be by reference so we can do options quickly */
name|struct
name|ip
name|udb_ip
decl_stmt|;
name|struct
name|udphdr
name|udb_uh
decl_stmt|;
name|struct
name|sockaddr_in
name|udb_conn
decl_stmt|;
name|struct
name|in_hostcache
modifier|*
name|udb_hc
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|udb_queue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|inptoudpcb
parameter_list|(
name|inp
parameter_list|)
value|((struct udpdb *)(inp)->inp_ppcb)
end_define

begin_struct
struct|struct
name|udpstat
block|{
comment|/* input statistics: */
name|u_long
name|udps_ipackets
decl_stmt|;
comment|/* total input packets */
name|u_long
name|udps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|u_long
name|udps_badsum
decl_stmt|;
comment|/* checksum error */
name|u_long
name|udps_badlen
decl_stmt|;
comment|/* data length larger than packet */
name|u_long
name|udps_noport
decl_stmt|;
comment|/* no socket on port */
name|u_long
name|udps_noportbcast
decl_stmt|;
comment|/* of above, arrived as broadcast */
name|u_long
name|udps_fullsock
decl_stmt|;
comment|/* not delivered, input socket full */
name|u_long
name|udpps_pcbcachemiss
decl_stmt|;
comment|/* input packets missing pcb cache */
name|u_long
name|udpps_pcbhashmiss
decl_stmt|;
comment|/* input packets not for hashed pcb */
comment|/* output statistics: */
name|u_long
name|udps_opackets
decl_stmt|;
comment|/* total output packets */
name|u_long
name|udps_fastout
decl_stmt|;
comment|/* output packets on fast path */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Names for UDP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_CHECKSUM
value|1
end_define

begin_comment
comment|/* checksum UDP packets */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_STATS
value|2
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_MAXDGRAM
value|3
end_define

begin_comment
comment|/* max datagram size */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_RECVSPACE
value|4
end_define

begin_comment
comment|/* default receive buffer space */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_PCBLIST
value|5
end_define

begin_comment
comment|/* list of PCBs for UDP sockets */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_MAXID
value|6
end_define

begin_define
define|#
directive|define
name|UDPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "checksum", CTLTYPE_INT }, \ 	{ "stats", CTLTYPE_STRUCT }, \ 	{ "maxdgram", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "pcblist", CTLTYPE_STRUCT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_udp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|udp_usrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|inpcbinfo
name|udbinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|udp_ctlinput
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

begin_decl_stmt
name|void
name|udp_init
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
name|udp_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

