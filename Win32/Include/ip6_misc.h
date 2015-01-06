begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*  * This file contains a collage of declarations for IPv6 from FreeBSD not present in Windows  */
end_comment

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__MINGW32__
end_ifndef

begin_define
define|#
directive|define
name|IN_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|IN_CLASSD(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IN_EXPERIMENTAL
parameter_list|(
name|a
parameter_list|)
value|((((u_int32_t) (a))& 0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|IN_LOOPBACKNET
value|127
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEFINE_ADDITIONAL_IPV6_STUFF
argument_list|)
end_if

begin_comment
comment|/* IPv6 address */
end_comment

begin_struct
struct|struct
name|in6_addr
block|{
union|union
block|{
name|u_int8_t
name|u6_addr8
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|u6_addr16
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|u6_addr32
index|[
literal|4
index|]
decl_stmt|;
block|}
name|in6_u
union|;
define|#
directive|define
name|s6_addr
value|in6_u.u6_addr8
define|#
directive|define
name|s6_addr16
value|in6_u.u6_addr16
define|#
directive|define
name|s6_addr32
value|in6_u.u6_addr32
define|#
directive|define
name|s6_addr64
value|in6_u.u6_addr64
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|_MSC_VER
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEFINE_ADDITIONAL_IPV6_STUFF
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|sa_family_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEFINE_ADDITIONAL_IPV6_STUFF
argument_list|)
end_if

begin_define
define|#
directive|define
name|__SOCKADDR_COMMON
parameter_list|(
name|sa_prefix
parameter_list|)
define|\
value|sa_family_t sa_prefix##family
end_define

begin_comment
comment|/* Ditto, for IPv6.  */
end_comment

begin_struct
struct|struct
name|sockaddr_in6
block|{
name|__SOCKADDR_COMMON
argument_list|(
name|sin6_
argument_list|)
expr_stmt|;
name|u_int16_t
name|sin6_port
decl_stmt|;
comment|/* Transport layer port # */
name|u_int32_t
name|sin6_flowinfo
decl_stmt|;
comment|/* IPv6 flow information */
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
comment|/* IPv6 address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4MAPPED
parameter_list|(
name|a
parameter_list|)
define|\
value|((((u_int32_t *) (a))[0] == 0)&& (((u_int32_t *) (a))[1] == 0)&& \ 	 (((u_int32_t *) (a))[2] == htonl (0xffff)))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|(((u_int8_t *) (a))[0] == 0xff)
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|((((u_int32_t *) (a))[0]& htonl (0xffc00000)) == htonl (0xfe800000))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
define|\
value|(((u_int32_t *) (a))[0] == 0&& ((u_int32_t *) (a))[1] == 0&& \ 	 ((u_int32_t *) (a))[2] == 0&& ((u_int32_t *) (a))[3] == htonl (1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

begin_define
define|#
directive|define
name|ip6_vfc
value|ip6_ctlun.ip6_un2_vfc
end_define

begin_define
define|#
directive|define
name|ip6_flow
value|ip6_ctlun.ip6_un1.ip6_un1_flow
end_define

begin_define
define|#
directive|define
name|ip6_plen
value|ip6_ctlun.ip6_un1.ip6_un1_plen
end_define

begin_define
define|#
directive|define
name|ip6_nxt
value|ip6_ctlun.ip6_un1.ip6_un1_nxt
end_define

begin_define
define|#
directive|define
name|ip6_hlim
value|ip6_ctlun.ip6_un1.ip6_un1_hlim
end_define

begin_define
define|#
directive|define
name|ip6_hops
value|ip6_ctlun.ip6_un1.ip6_un1_hlim
end_define

begin_define
define|#
directive|define
name|nd_rd_type
value|nd_rd_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|nd_rd_code
value|nd_rd_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|nd_rd_cksum
value|nd_rd_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|nd_rd_reserved
value|nd_rd_hdr.icmp6_data32[0]
end_define

begin_comment
comment|/*  *	IPV6 extension headers  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_HOPOPTS
value|0
end_define

begin_comment
comment|/* IPv6 hop-by-hop options	*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPV6
value|41
end_define

begin_comment
comment|/* IPv6 header.  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ROUTING
value|43
end_define

begin_comment
comment|/* IPv6 routing header		*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_FRAGMENT
value|44
end_define

begin_comment
comment|/* IPv6 fragmentation header	*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ESP
value|50
end_define

begin_comment
comment|/* encapsulating security payload */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_AH
value|51
end_define

begin_comment
comment|/* authentication header	*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ICMPV6
value|58
end_define

begin_comment
comment|/* ICMPv6			*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_NONE
value|59
end_define

begin_comment
comment|/* IPv6 no next header		*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_DSTOPTS
value|60
end_define

begin_comment
comment|/* IPv6 destination options	*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PIM
value|103
end_define

begin_comment
comment|/* Protocol Independent Multicast.  */
end_comment

begin_define
define|#
directive|define
name|IPV6_RTHDR_TYPE_0
value|0
end_define

begin_comment
comment|/* Option types and related macros */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_PAD1
value|0x00
end_define

begin_comment
comment|/* 00 0 00000 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_PADN
value|0x01
end_define

begin_comment
comment|/* 00 0 00001 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_JUMBO
value|0xC2
end_define

begin_comment
comment|/* 11 0 00010 = 194 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_JUMBO_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IP6OPT_ROUTER_ALERT
value|0x05
end_define

begin_comment
comment|/* 00 0 00101 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_MLD
value|0
end_define

begin_comment
comment|/* Datagram contains an MLD message */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_RSVP
value|1
end_define

begin_comment
comment|/* Datagram contains an RSVP message */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_ACTNET
value|2
end_define

begin_comment
comment|/* contains an Active Networks msg */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_MINLEN
value|2
end_define

begin_define
define|#
directive|define
name|IP6OPT_BINDING_UPDATE
value|0xc6
end_define

begin_comment
comment|/* 11 0 00110 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_BINDING_ACK
value|0x07
end_define

begin_comment
comment|/* 00 0 00111 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_BINDING_REQ
value|0x08
end_define

begin_comment
comment|/* 00 0 01000 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_HOME_ADDRESS
value|0xc9
end_define

begin_comment
comment|/* 11 0 01001 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_EID
value|0x8a
end_define

begin_comment
comment|/* 10 0 01010 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_TYPE
parameter_list|(
name|o
parameter_list|)
value|((o)& 0xC0)
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_SKIP
value|0x00
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_DISCARD
value|0x40
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_FORCEICMP
value|0x80
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_ICMP
value|0xC0
end_define

begin_define
define|#
directive|define
name|IP6OPT_MUTABLE
value|0x20
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEFINE_ADDITIONAL_IPV6_STUFF
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_ADDRFAMILY
end_ifndef

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME */
name|int
name|ai_family
decl_stmt|;
comment|/* PF_xxx */
name|int
name|ai_socktype
decl_stmt|;
comment|/* SOCK_xxx */
name|int
name|ai_protocol
decl_stmt|;
comment|/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
name|size_t
name|ai_addrlen
decl_stmt|;
comment|/* length of ai_addr */
name|char
modifier|*
name|ai_canonname
decl_stmt|;
comment|/* canonical name for hostname */
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
comment|/* binary address */
name|struct
name|addrinfo
modifier|*
name|ai_next
decl_stmt|;
comment|/* next structure in linked list */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

end_unit

