begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1995, Mike Mitchell  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx.h  *  * $FreeBSD$  */
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
name|IPXPROTO_PXP
value|4
end_define

begin_comment
comment|/* IPX Packet Exchange Protocol */
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
name|IPXPROTO_NETBIOS
value|20
end_define

begin_comment
comment|/* Propagated Packet */
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
name|IPXPORT_NCP
value|0x0451
end_define

begin_comment
comment|/* NW NCP Core Protocol */
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

begin_comment
comment|/*  * Ports< IPXPORT_RESERVED are reserved for privileged  */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_RESERVED
value|0x4000
end_define

begin_comment
comment|/*  * Ports> IPXPORT_WELLKNOWN are reserved for privileged  * processes (e.g. root).  */
end_comment

begin_define
define|#
directive|define
name|IPXPORT_WELLKNOWN
value|0x6000
end_define

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

begin_define
define|#
directive|define
name|SO_IPX_CHECKSUM
value|10
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
comment|/*  * Definitions for IPX Internetwork Packet Exchange Protocol  */
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
name|__packed
struct|;
end_struct

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
value|(((a).s_net[0] == (b).s_net[0])&& ((a).s_net[1] == (b).s_net[1]))
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
value|(((x).x_host.s_host[0] == 0)&& \ 	((x).x_host.s_host[1] == 0)&& ((x).x_host.s_host[2] == 0))
end_define

begin_define
define|#
directive|define
name|ipx_wildnet
parameter_list|(
name|x
parameter_list|)
value|(((x).x_net.s_net[0] == 0xffff)&& \ 	((x).x_net.s_net[1] == 0xffff))
end_define

begin_define
define|#
directive|define
name|ipx_wildhost
parameter_list|(
name|x
parameter_list|)
value|(((x).x_host.s_host[0] == 0xffff)&& \ 	((x).x_host.s_host[1] == 0xffff)&& ((x).x_host.s_host[2] == 0xffff))
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|ipx_addr
name|ipx_addr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ipx_ntoa
parameter_list|(
name|struct
name|ipx_addr
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_IPX_H_ */
end_comment

end_unit

