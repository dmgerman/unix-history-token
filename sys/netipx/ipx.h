begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, Mike Mitchell  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx.h  *  * $Id: ipx.h,v 1.10 1997/04/05 20:05:07 jhay Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPX_H_
end_define

begin_comment
comment|/*  * Constants and Structures  */
end_comment

begin_comment
comment|/*  * Protocols  */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_UNKWN
value|0
end_define

begin_comment
comment|/* Unknown */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_RI
value|1
end_define

begin_comment
comment|/* RIP Routing Information */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_ECHO
value|2
end_define

begin_comment
comment|/* Echo Protocol */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_ERROR
value|3
end_define

begin_comment
comment|/* Error Protocol */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_PXP
value|4
end_define

begin_comment
comment|/* PXP Packet Exchange */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_SPX
value|5
end_define

begin_comment
comment|/* SPX Sequenced Packet */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_NCP
value|17
end_define

begin_comment
comment|/* NCP NetWare Core */
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_RAW
value|255
end_define

begin_comment
comment|/* Placemarker*/
end_comment

begin_define
define|#
directive|define
name|IPXPROTO_MAX
value|256
end_define

begin_comment
comment|/* Placemarker*/
end_comment

begin_comment
comment|/*  * Port/Socket numbers: network standard functions  */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_RI
value|1
end_define

begin_comment
comment|/* NS RIP Routing Information */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_ECHO
value|2
end_define

begin_comment
comment|/* NS Echo */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_RE
value|3
end_define

begin_comment
comment|/* NS Router Error */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_FSP
value|0x0451
end_define

begin_comment
comment|/* NW FSP File Service */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_SAP
value|0x0452
end_define

begin_comment
comment|/* NW SAP Service Advertising */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_RIP
value|0x0453
end_define

begin_comment
comment|/* NW RIP Routing Information */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_NETBIOS
value|0x0455
end_define

begin_comment
comment|/* NW NetBIOS */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_DIAGS
value|0x0456
end_define

begin_comment
comment|/* NW Diagnostics */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_WDOG
value|0x4001
end_define

begin_comment
comment|/* NW Watchdog Packets */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_SHELL
value|0x4003
end_define

begin_comment
comment|/* NW Shell Socket */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_MAX
value|0x8000
end_define

begin_comment
comment|/* Maximum User Addressable Port */
end_comment

begin_comment
comment|/* flags passed to ipx_outputfl as last parameter */
end_comment

begin_define
define|#
directive|define
name|IPX_FORWARDING
value|0x1
end_define

begin_comment
comment|/* most of ipx header exists */
end_comment

begin_define
define|#
directive|define
name|IPX_ROUTETOIF
value|0x10
end_define

begin_comment
comment|/* same as SO_DONTROUTE */
end_comment

begin_define
define|#
directive|define
name|IPX_ALLOWBROADCAST
value|SO_BROADCAST
end_define

begin_comment
comment|/* can send broadcast packets */
end_comment

begin_define
define|#
directive|define
name|IPX_MAXHOPS
value|15
end_define

begin_comment
comment|/* flags passed to get/set socket option */
end_comment

begin_define
define|#
directive|define
name|SO_HEADERS_ON_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|SO_HEADERS_ON_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|SO_DEFAULT_HEADERS
value|3
end_define

begin_define
define|#
directive|define
name|SO_LAST_HEADER
value|4
end_define

begin_define
define|#
directive|define
name|SO_IPXIP_ROUTE
value|5
end_define

begin_define
define|#
directive|define
name|SO_SEQNO
value|6
end_define

begin_define
define|#
directive|define
name|SO_ALL_PACKETS
value|7
end_define

begin_define
define|#
directive|define
name|SO_MTU
value|8
end_define

begin_define
define|#
directive|define
name|SO_IPXTUN_ROUTE
value|9
end_define

begin_comment
comment|/*  * IPX addressing  */
end_comment

begin_union
union|union
name|ipx_host
block|{
name|u_char
name|c_host
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|s_host
index|[
literal|3
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|ipx_net
block|{
name|u_char
name|c_net
index|[
literal|4
index|]
decl_stmt|;
name|u_short
name|s_net
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|ipx_net_u
block|{
name|union
name|ipx_net
name|net_e
decl_stmt|;
name|u_long
name|long_e
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ipx_addr
block|{
name|union
name|ipx_net
name|x_net
decl_stmt|;
name|union
name|ipx_host
name|x_host
decl_stmt|;
name|u_short
name|x_port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket address  */
end_comment

begin_struct
struct|struct
name|sockaddr_ipx
block|{
name|u_char
name|sipx_len
decl_stmt|;
name|u_char
name|sipx_family
decl_stmt|;
name|struct
name|ipx_addr
name|sipx_addr
decl_stmt|;
name|char
name|sipx_zero
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sipx_port
value|sipx_addr.x_port
end_define

begin_comment
comment|/*  * Definitions for IPX Internet Datagram Protocol  */
end_comment

begin_struct
struct|struct
name|ipx
block|{
name|u_short
name|ipx_sum
decl_stmt|;
comment|/* Checksum */
name|u_short
name|ipx_len
decl_stmt|;
comment|/* Length, in bytes, including header */
name|u_char
name|ipx_tc
decl_stmt|;
comment|/* Transport Control (i.e. hop count) */
name|u_char
name|ipx_pt
decl_stmt|;
comment|/* Packet Type (i.e. level 2 protocol) */
name|struct
name|ipx_addr
name|ipx_dna
decl_stmt|;
comment|/* Destination Network Address */
name|struct
name|ipx_addr
name|ipx_sna
decl_stmt|;
comment|/* Source Network Address */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|ipx_netof
parameter_list|(
name|a
parameter_list|)
value|(*(long *)& ((a).x_net))
end_define

begin_comment
comment|/* XXX - not needed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ipx_neteqnn
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a).s_net[0]==(b).s_net[0])&& ((a).s_net[1]==(b).s_net[1]))
end_define

begin_define
define|#
directive|define
name|ipx_neteq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ipx_neteqnn((a).x_net, (b).x_net)
end_define

begin_define
define|#
directive|define
name|satoipx_addr
parameter_list|(
name|sa
parameter_list|)
value|(((struct sockaddr_ipx *)&(sa))->sipx_addr)
end_define

begin_define
define|#
directive|define
name|ipx_hosteqnh
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s).s_host[0] == (t).s_host[0]&& \ 	(s).s_host[1] == (t).s_host[1]&& (s).s_host[2] == (t).s_host[2])
end_define

begin_define
define|#
directive|define
name|ipx_hosteq
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(ipx_hosteqnh((s).x_host,(t).x_host))
end_define

begin_define
define|#
directive|define
name|ipx_nullnet
parameter_list|(
name|x
parameter_list|)
value|(((x).x_net.s_net[0]==0)&& ((x).x_net.s_net[1]==0))
end_define

begin_define
define|#
directive|define
name|ipx_nullhost
parameter_list|(
name|x
parameter_list|)
value|(((x).x_host.s_host[0]==0)&& \ 	((x).x_host.s_host[1]==0)&& ((x).x_host.s_host[2]==0))
end_define

begin_define
define|#
directive|define
name|ipx_wildnet
parameter_list|(
name|x
parameter_list|)
value|(((x).x_net.s_net[0]==0xffff)&& \ 	((x).x_net.s_net[1]==0xffff))
end_define

begin_define
define|#
directive|define
name|ipx_wildhost
parameter_list|(
name|x
parameter_list|)
value|(((x).x_host.s_host[0]==0xffff)&& \ 	((x).x_host.s_host[1]==0xffff)&& ((x).x_host.s_host[2]==0xffff))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
name|int
name|ipxcksum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|ipxdomain
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
name|ipx_host
name|ipx_thishost
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

begin_decl_stmt
specifier|extern
name|long
name|ipx_pexseq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ipxctlerrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipxpcb
name|ipxrawpcb
decl_stmt|;
end_decl_stmt

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
name|int
name|ipx_do_route
name|__P
argument_list|(
operator|(
expr|struct
name|ipx_addr
operator|*
name|src
operator|,
expr|struct
name|route
operator|*
name|ro
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
name|ipx_forward
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
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
name|ipx_output
name|__P
argument_list|(
operator|(
expr|struct
name|ipxpcb
operator|*
name|ipxp
operator|,
expr|struct
name|mbuf
operator|*
name|m0
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
name|void
name|ipx_undo_route
name|__P
argument_list|(
operator|(
expr|struct
name|route
operator|*
name|ro
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
name|mbuf
operator|*
name|nam
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
name|mbuf
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|ipx_addr
name|ipx_addr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ipx_ntoa
name|__P
argument_list|(
operator|(
expr|struct
name|ipx_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

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
comment|/* !_NETIPX_IPX_H_ */
end_comment

end_unit

