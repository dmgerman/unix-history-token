begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_ether.h	8.3 (Berkeley) 5/2/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IF_ETHER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IF_ETHER_H_
end_define

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_comment
comment|/*  * Macro to map an IP multicast address to an Ethernet multicast address.  * The high-order 25 bits of the Ethernet address are statically assigned,  * and the low-order 23 bits are taken from the low end of the IP address.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAP_IP_MULTICAST
parameter_list|(
name|ipaddr
parameter_list|,
name|enaddr
parameter_list|)
define|\
comment|/* struct in_addr *ipaddr; */
define|\
comment|/* u_char enaddr[ETHER_ADDR_LEN];	   */
define|\
value|{ \ 	(enaddr)[0] = 0x01; \ 	(enaddr)[1] = 0x00; \ 	(enaddr)[2] = 0x5e; \ 	(enaddr)[3] = ((u_char *)ipaddr)[1]& 0x7f; \ 	(enaddr)[4] = ((u_char *)ipaddr)[2]; \ 	(enaddr)[5] = ((u_char *)ipaddr)[3]; \ }
end_define

begin_comment
comment|/*  * Macro to map an IP6 multicast address to an Ethernet multicast address.  * The high-order 16 bits of the Ethernet address are statically assigned,  * and the low-order 32 bits are taken from the low end of the IP6 address.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAP_IPV6_MULTICAST
parameter_list|(
name|ip6addr
parameter_list|,
name|enaddr
parameter_list|)
define|\
comment|/* struct	in6_addr *ip6addr; */
define|\
comment|/* u_char	enaddr[ETHER_ADDR_LEN]; */
define|\
value|{                                                                       \ 	(enaddr)[0] = 0x33;						\ 	(enaddr)[1] = 0x33;						\ 	(enaddr)[2] = ((u_char *)ip6addr)[12];				\ 	(enaddr)[3] = ((u_char *)ip6addr)[13];				\ 	(enaddr)[4] = ((u_char *)ip6addr)[14];				\ 	(enaddr)[5] = ((u_char *)ip6addr)[15];				\ }
end_define

begin_comment
comment|/*  * Ethernet Address Resolution Protocol.  *  * See RFC 826 for protocol description.  Structure below is adapted  * to resolving internet addresses.  Field names used correspond to  * RFC 826.  */
end_comment

begin_struct
struct|struct
name|ether_arp
block|{
name|struct
name|arphdr
name|ea_hdr
decl_stmt|;
comment|/* fixed-size header */
name|u_char
name|arp_sha
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* sender hardware address */
name|u_char
name|arp_spa
index|[
literal|4
index|]
decl_stmt|;
comment|/* sender protocol address */
name|u_char
name|arp_tha
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* target hardware address */
name|u_char
name|arp_tpa
index|[
literal|4
index|]
decl_stmt|;
comment|/* target protocol address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|arp_hrd
value|ea_hdr.ar_hrd
end_define

begin_define
define|#
directive|define
name|arp_pro
value|ea_hdr.ar_pro
end_define

begin_define
define|#
directive|define
name|arp_hln
value|ea_hdr.ar_hln
end_define

begin_define
define|#
directive|define
name|arp_pln
value|ea_hdr.ar_pln
end_define

begin_define
define|#
directive|define
name|arp_op
value|ea_hdr.ar_op
end_define

begin_struct
struct|struct
name|sockaddr_inarp
block|{
name|u_char
name|sin_len
decl_stmt|;
name|u_char
name|sin_family
decl_stmt|;
name|u_short
name|sin_port
decl_stmt|;
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|struct
name|in_addr
name|sin_srcaddr
decl_stmt|;
name|u_short
name|sin_tos
decl_stmt|;
name|u_short
name|sin_other
decl_stmt|;
define|#
directive|define
name|SIN_PROXY
value|1
block|}
struct|;
end_struct

begin_comment
comment|/*  * IP and ethernet specific routing flags  */
end_comment

begin_define
define|#
directive|define
name|RTF_USETRAILERS
value|RTF_PROTO1
end_define

begin_comment
comment|/* use trailers */
end_comment

begin_define
define|#
directive|define
name|RTF_ANNOUNCE
value|RTF_PROTO2
end_define

begin_comment
comment|/* announce new arp entry */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_char
name|ether_ipmulticast_min
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ether_ipmulticast_max
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|arpintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arpresolve
name|__P
argument_list|(
operator|(
expr|struct
name|arpcom
operator|*
operator|,
expr|struct
name|rtentry
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
name|u_char
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arp_ifinit
name|__P
argument_list|(
operator|(
expr|struct
name|arpcom
operator|*
operator|,
expr|struct
name|ifaddr
operator|*
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

