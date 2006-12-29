begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in.h	8.3 (Berkeley) 1/3/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/* Protocols common to RFC 1700, POSIX, and X/Open. */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IP
value|0
end_define

begin_comment
comment|/* dummy for IP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ICMP
value|1
end_define

begin_comment
comment|/* control message protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TCP
value|6
end_define

begin_comment
comment|/* tcp */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_UDP
value|17
end_define

begin_comment
comment|/* user datagram protocol */
end_comment

begin_define
define|#
directive|define
name|INADDR_ANY
value|(u_int32_t)0x00000000
end_define

begin_define
define|#
directive|define
name|INADDR_BROADCAST
value|(u_int32_t)0xffffffff
end_define

begin_comment
comment|/* must be masked */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT8_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint8_t
name|uint8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT8_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT16_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint16_t
name|uint16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT16_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT32_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint32_t
name|uint32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT32_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IN_ADDR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|uint32_t
name|in_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_IN_ADDR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IN_PORT_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|uint16_t
name|in_port_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_IN_PORT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SA_FAMILY_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__sa_family_t
name|sa_family_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SA_FAMILY_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Internet address (a structure for historical reasons). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRUCT_IN_ADDR_DECLARED
end_ifndef

begin_struct
struct|struct
name|in_addr
block|{
name|in_addr_t
name|s_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_STRUCT_IN_ADDR_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Socket address, internet style. */
end_comment

begin_struct
struct|struct
name|sockaddr_in
block|{
name|uint8_t
name|sin_len
decl_stmt|;
name|sa_family_t
name|sin_family
decl_stmt|;
name|in_port_t
name|sin_port
decl_stmt|;
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|char
name|sin_zero
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BYTEORDER_PROTOTYPED
end_ifndef

begin_define
define|#
directive|define
name|_BYTEORDER_PROTOTYPED
end_define

begin_function_decl
name|__BEGIN_DECLS
name|uint32_t
name|htonl
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|htons
parameter_list|(
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ntohl
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ntohs
parameter_list|(
name|uint16_t
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

begin_ifndef
ifndef|#
directive|ifndef
name|_BYTEORDER_FUNC_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_BYTEORDER_FUNC_DEFINED
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|__htonl(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|__htons(x)
end_define

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|__ntohl(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|__ntohs(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|IPPROTO_RAW
value|255
end_define

begin_comment
comment|/* raw IP packet */
end_comment

begin_define
define|#
directive|define
name|INET_ADDRSTRLEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * Constants and structures defined by the internet system,  * Per RFC 790, September 1981, and numerous additions.  */
end_comment

begin_comment
comment|/*  * Protocols (RFC 1700)  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_HOPOPTS
value|0
end_define

begin_comment
comment|/* IP6 hop-by-hop options */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IGMP
value|2
end_define

begin_comment
comment|/* group mgmt protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_GGP
value|3
end_define

begin_comment
comment|/* gateway^2 (deprecated) */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPV4
value|4
end_define

begin_comment
comment|/* IPv4 encapsulation */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPIP
value|IPPROTO_IPV4
end_define

begin_comment
comment|/* for compatibility */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ST
value|7
end_define

begin_comment
comment|/* Stream protocol II */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_EGP
value|8
end_define

begin_comment
comment|/* exterior gateway protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PIGP
value|9
end_define

begin_comment
comment|/* private interior gateway */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_RCCMON
value|10
end_define

begin_comment
comment|/* BBN RCC Monitoring */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_NVPII
value|11
end_define

begin_comment
comment|/* network voice protocol*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PUP
value|12
end_define

begin_comment
comment|/* pup */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ARGUS
value|13
end_define

begin_comment
comment|/* Argus */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_EMCON
value|14
end_define

begin_comment
comment|/* EMCON */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_XNET
value|15
end_define

begin_comment
comment|/* Cross Net Debugger */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_CHAOS
value|16
end_define

begin_comment
comment|/* Chaos*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MUX
value|18
end_define

begin_comment
comment|/* Multiplexing */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MEAS
value|19
end_define

begin_comment
comment|/* DCN Measurement Subsystems */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_HMP
value|20
end_define

begin_comment
comment|/* Host Monitoring */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PRM
value|21
end_define

begin_comment
comment|/* Packet Radio Measurement */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IDP
value|22
end_define

begin_comment
comment|/* xns idp */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TRUNK1
value|23
end_define

begin_comment
comment|/* Trunk-1 */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TRUNK2
value|24
end_define

begin_comment
comment|/* Trunk-2 */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_LEAF1
value|25
end_define

begin_comment
comment|/* Leaf-1 */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_LEAF2
value|26
end_define

begin_comment
comment|/* Leaf-2 */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_RDP
value|27
end_define

begin_comment
comment|/* Reliable Data */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IRTP
value|28
end_define

begin_comment
comment|/* Reliable Transaction */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TP
value|29
end_define

begin_comment
comment|/* tp-4 w/ class negotiation */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_BLT
value|30
end_define

begin_comment
comment|/* Bulk Data Transfer */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_NSP
value|31
end_define

begin_comment
comment|/* Network Services */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_INP
value|32
end_define

begin_comment
comment|/* Merit Internodal */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SEP
value|33
end_define

begin_comment
comment|/* Sequential Exchange */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_3PC
value|34
end_define

begin_comment
comment|/* Third Party Connect */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IDPR
value|35
end_define

begin_comment
comment|/* InterDomain Policy Routing */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_XTP
value|36
end_define

begin_comment
comment|/* XTP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_DDP
value|37
end_define

begin_comment
comment|/* Datagram Delivery */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_CMTP
value|38
end_define

begin_comment
comment|/* Control Message Transport */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TPXX
value|39
end_define

begin_comment
comment|/* TP++ Transport */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IL
value|40
end_define

begin_comment
comment|/* IL transport protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPV6
value|41
end_define

begin_comment
comment|/* IP6 header */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SDRP
value|42
end_define

begin_comment
comment|/* Source Demand Routing */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ROUTING
value|43
end_define

begin_comment
comment|/* IP6 routing header */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_FRAGMENT
value|44
end_define

begin_comment
comment|/* IP6 fragmentation header */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IDRP
value|45
end_define

begin_comment
comment|/* InterDomain Routing*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_RSVP
value|46
end_define

begin_comment
comment|/* resource reservation */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_GRE
value|47
end_define

begin_comment
comment|/* General Routing Encap. */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MHRP
value|48
end_define

begin_comment
comment|/* Mobile Host Routing */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_BHA
value|49
end_define

begin_comment
comment|/* BHA */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ESP
value|50
end_define

begin_comment
comment|/* IP6 Encap Sec. Payload */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_AH
value|51
end_define

begin_comment
comment|/* IP6 Auth Header */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_INLSP
value|52
end_define

begin_comment
comment|/* Integ. Net Layer Security */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SWIPE
value|53
end_define

begin_comment
comment|/* IP with encryption */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_NHRP
value|54
end_define

begin_comment
comment|/* Next Hop Resolution */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MOBILE
value|55
end_define

begin_comment
comment|/* IP Mobility */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TLSP
value|56
end_define

begin_comment
comment|/* Transport Layer Security */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SKIP
value|57
end_define

begin_comment
comment|/* SKIP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ICMPV6
value|58
end_define

begin_comment
comment|/* ICMP6 */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_NONE
value|59
end_define

begin_comment
comment|/* IP6 no next header */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_DSTOPTS
value|60
end_define

begin_comment
comment|/* IP6 destination option */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_AHIP
value|61
end_define

begin_comment
comment|/* any host internal protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_CFTP
value|62
end_define

begin_comment
comment|/* CFTP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_HELLO
value|63
end_define

begin_comment
comment|/* "hello" routing protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SATEXPAK
value|64
end_define

begin_comment
comment|/* SATNET/Backroom EXPAK */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_KRYPTOLAN
value|65
end_define

begin_comment
comment|/* Kryptolan */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_RVD
value|66
end_define

begin_comment
comment|/* Remote Virtual Disk */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPPC
value|67
end_define

begin_comment
comment|/* Pluribus Packet Core */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ADFS
value|68
end_define

begin_comment
comment|/* Any distributed FS */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SATMON
value|69
end_define

begin_comment
comment|/* Satnet Monitoring */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_VISA
value|70
end_define

begin_comment
comment|/* VISA Protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPCV
value|71
end_define

begin_comment
comment|/* Packet Core Utility */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_CPNX
value|72
end_define

begin_comment
comment|/* Comp. Prot. Net. Executive */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_CPHB
value|73
end_define

begin_comment
comment|/* Comp. Prot. HeartBeat */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_WSN
value|74
end_define

begin_comment
comment|/* Wang Span Network */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PVP
value|75
end_define

begin_comment
comment|/* Packet Video Protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_BRSATMON
value|76
end_define

begin_comment
comment|/* BackRoom SATNET Monitoring */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ND
value|77
end_define

begin_comment
comment|/* Sun net disk proto (temp.) */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_WBMON
value|78
end_define

begin_comment
comment|/* WIDEBAND Monitoring */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_WBEXPAK
value|79
end_define

begin_comment
comment|/* WIDEBAND EXPAK */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_EON
value|80
end_define

begin_comment
comment|/* ISO cnlp */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_VMTP
value|81
end_define

begin_comment
comment|/* VMTP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SVMTP
value|82
end_define

begin_comment
comment|/* Secure VMTP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_VINES
value|83
end_define

begin_comment
comment|/* Banyon VINES */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TTP
value|84
end_define

begin_comment
comment|/* TTP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IGP
value|85
end_define

begin_comment
comment|/* NSFNET-IGP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_DGP
value|86
end_define

begin_comment
comment|/* dissimilar gateway prot. */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TCF
value|87
end_define

begin_comment
comment|/* TCF */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IGRP
value|88
end_define

begin_comment
comment|/* Cisco/GXS IGRP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_OSPFIGP
value|89
end_define

begin_comment
comment|/* OSPFIGP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SRPC
value|90
end_define

begin_comment
comment|/* Strite RPC protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_LARP
value|91
end_define

begin_comment
comment|/* Locus Address Resoloution */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MTP
value|92
end_define

begin_comment
comment|/* Multicast Transport */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_AX25
value|93
end_define

begin_comment
comment|/* AX.25 Frames */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPEIP
value|94
end_define

begin_comment
comment|/* IP encapsulated in IP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MICP
value|95
end_define

begin_comment
comment|/* Mobile Int.ing control */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SCCSP
value|96
end_define

begin_comment
comment|/* Semaphore Comm. security */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ETHERIP
value|97
end_define

begin_comment
comment|/* Ethernet IP encapsulation */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ENCAP
value|98
end_define

begin_comment
comment|/* encapsulation header */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_APES
value|99
end_define

begin_comment
comment|/* any private encr. scheme */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_GMTP
value|100
end_define

begin_comment
comment|/* GMTP*/
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IPCOMP
value|108
end_define

begin_comment
comment|/* payload compression (IPComp) */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SCTP
value|132
end_define

begin_comment
comment|/* SCTP */
end_comment

begin_comment
comment|/* 101-254: Partly Unassigned */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PIM
value|103
end_define

begin_comment
comment|/* Protocol Independent Mcast */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_CARP
value|112
end_define

begin_comment
comment|/* CARP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PGM
value|113
end_define

begin_comment
comment|/* PGM */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PFSYNC
value|240
end_define

begin_comment
comment|/* PFSYNC */
end_comment

begin_comment
comment|/* 255: Reserved */
end_comment

begin_comment
comment|/* BSD Private, local use, namespace incursion, no longer used */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_OLD_DIVERT
value|254
end_define

begin_comment
comment|/* OLD divert pseudo-proto */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MAX
value|256
end_define

begin_comment
comment|/* last return value of *_input(), meaning "all job for this pkt is done".  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_DONE
value|257
end_define

begin_comment
comment|/* Only used internally, so can be outside the range of valid IP protocols. */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_DIVERT
value|258
end_define

begin_comment
comment|/* divert pseudo-protocol */
end_comment

begin_comment
comment|/*  * Defined to avoid confusion.  The master value is defined by  * PROTO_SPACER in sys/protosw.h.  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_SPACER
value|32767
end_define

begin_comment
comment|/* spacer for loadable protos */
end_comment

begin_comment
comment|/*  * Local port number conventions:  *  * When a user does a bind(2) or connect(2) with a port number of zero,  * a non-conflicting local port address is chosen.  * The default range is IPPORT_HIFIRSTAUTO through  * IPPORT_HILASTAUTO, although that is settable by sysctl.  *  * A user may set the IPPROTO_IP option IP_PORTRANGE to change this  * default assignment range.  *  * The value IP_PORTRANGE_DEFAULT causes the default behavior.  *  * The value IP_PORTRANGE_HIGH changes the range of candidate port numbers  * into the "high" range.  These are reserved for client outbound connections  * which do not want to be filtered by any firewalls.  Note that by default  * this is the same as IP_PORTRANGE_DEFAULT.  *  * The value IP_PORTRANGE_LOW changes the range to the "low" are  * that is (by convention) restricted to privileged processes.  This  * convention is based on "vouchsafe" principles only.  It is only secure  * if you trust the remote host to restrict these ports.  *  * The default range of ports and the high range can be changed by  * sysctl(3).  (net.inet.ip.port{hi,low}{first,last}_auto)  *  * Changing those values has bad security implications if you are  * using a stateless firewall that is allowing packets outside of that  * range in order to allow transparent outgoing connections.  *  * Such a firewall configuration will generally depend on the use of these  * default values.  If you change them, you may find your Security  * Administrator looking for you with a heavy object.  *  * For a slightly more orthodox text view on this:  *  *            ftp://ftp.isi.edu/in-notes/iana/assignments/port-numbers  *  *    port numbers are divided into three ranges:  *  *                0 -  1023 Well Known Ports  *             1024 - 49151 Registered Ports  *            49152 - 65535 Dynamic and/or Private Ports  *  */
end_comment

begin_comment
comment|/*  * Ports< IPPORT_RESERVED are reserved for  * privileged processes (e.g. root).         (IP_PORTRANGE_LOW)  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_RESERVED
value|1024
end_define

begin_comment
comment|/*  * Default local port range, used by both IP_PORTRANGE_DEFAULT  * and IP_PORTRANGE_HIGH.  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_HIFIRSTAUTO
value|49152
end_define

begin_define
define|#
directive|define
name|IPPORT_HILASTAUTO
value|65535
end_define

begin_comment
comment|/*  * Scanning for a free reserved port return a value below IPPORT_RESERVED,  * but higher than IPPORT_RESERVEDSTART.  Traditionally the start value was  * 512, but that conflicts with some well-known-services that firewalls may  * have a fit if we use.  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_RESERVEDSTART
value|600
end_define

begin_define
define|#
directive|define
name|IPPORT_MAX
value|65535
end_define

begin_comment
comment|/*  * Definitions of bits in internet address integers.  * On subnets, the decomposition of addresses to host and net parts  * is done according to subnet mask, not the masks here.  */
end_comment

begin_define
define|#
directive|define
name|IN_CLASSA
parameter_list|(
name|i
parameter_list|)
value|(((u_int32_t)(i)& 0x80000000) == 0)
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_NET
value|0xff000000
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_NSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_HOST
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_MAX
value|128
end_define

begin_define
define|#
directive|define
name|IN_CLASSB
parameter_list|(
name|i
parameter_list|)
value|(((u_int32_t)(i)& 0xc0000000) == 0x80000000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_NET
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_NSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_HOST
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_MAX
value|65536
end_define

begin_define
define|#
directive|define
name|IN_CLASSC
parameter_list|(
name|i
parameter_list|)
value|(((u_int32_t)(i)& 0xe0000000) == 0xc0000000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSC_NET
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|IN_CLASSC_NSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IN_CLASSC_HOST
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|IN_CLASSD
parameter_list|(
name|i
parameter_list|)
value|(((u_int32_t)(i)& 0xf0000000) == 0xe0000000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSD_NET
value|0xf0000000
end_define

begin_comment
comment|/* These ones aren't really */
end_comment

begin_define
define|#
directive|define
name|IN_CLASSD_NSHIFT
value|28
end_define

begin_comment
comment|/* net and host fields, but */
end_comment

begin_define
define|#
directive|define
name|IN_CLASSD_HOST
value|0x0fffffff
end_define

begin_comment
comment|/* routing needn't know.    */
end_comment

begin_define
define|#
directive|define
name|IN_MULTICAST
parameter_list|(
name|i
parameter_list|)
value|IN_CLASSD(i)
end_define

begin_define
define|#
directive|define
name|IN_EXPERIMENTAL
parameter_list|(
name|i
parameter_list|)
value|(((u_int32_t)(i)& 0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|IN_BADCLASS
parameter_list|(
name|i
parameter_list|)
value|(((u_int32_t)(i)& 0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|(u_int32_t)0x7f000001
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
end_define

begin_comment
comment|/* -1 return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INADDR_UNSPEC_GROUP
value|(u_int32_t)0xe0000000
end_define

begin_comment
comment|/* 224.0.0.0 */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLHOSTS_GROUP
value|(u_int32_t)0xe0000001
end_define

begin_comment
comment|/* 224.0.0.1 */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLRTRS_GROUP
value|(u_int32_t)0xe0000002
end_define

begin_comment
comment|/* 224.0.0.2 */
end_comment

begin_define
define|#
directive|define
name|INADDR_CARP_GROUP
value|(u_int32_t)0xe0000012
end_define

begin_comment
comment|/* 224.0.0.18 */
end_comment

begin_define
define|#
directive|define
name|INADDR_PFSYNC_GROUP
value|(u_int32_t)0xe00000f0
end_define

begin_comment
comment|/* 224.0.0.240 */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLMDNS_GROUP
value|(u_int32_t)0xe00000fb
end_define

begin_comment
comment|/* 224.0.0.251 */
end_comment

begin_define
define|#
directive|define
name|INADDR_MAX_LOCAL_GROUP
value|(u_int32_t)0xe00000ff
end_define

begin_comment
comment|/* 224.0.0.255 */
end_comment

begin_define
define|#
directive|define
name|IN_LOOPBACKNET
value|127
end_define

begin_comment
comment|/* official! */
end_comment

begin_comment
comment|/*  * Options for use with [gs]etsockopt at the IP level.  * First word of comment is data type; bool is stored in int.  */
end_comment

begin_define
define|#
directive|define
name|IP_OPTIONS
value|1
end_define

begin_comment
comment|/* buf/ip_opts; set/get IP options */
end_comment

begin_define
define|#
directive|define
name|IP_HDRINCL
value|2
end_define

begin_comment
comment|/* int; header is included with data */
end_comment

begin_define
define|#
directive|define
name|IP_TOS
value|3
end_define

begin_comment
comment|/* int; IP type of service and preced. */
end_comment

begin_define
define|#
directive|define
name|IP_TTL
value|4
end_define

begin_comment
comment|/* int; IP time to live */
end_comment

begin_define
define|#
directive|define
name|IP_RECVOPTS
value|5
end_define

begin_comment
comment|/* bool; receive all IP opts w/dgram */
end_comment

begin_define
define|#
directive|define
name|IP_RECVRETOPTS
value|6
end_define

begin_comment
comment|/* bool; receive IP opts for response */
end_comment

begin_define
define|#
directive|define
name|IP_RECVDSTADDR
value|7
end_define

begin_comment
comment|/* bool; receive IP dst addr w/dgram */
end_comment

begin_define
define|#
directive|define
name|IP_SENDSRCADDR
value|IP_RECVDSTADDR
end_define

begin_comment
comment|/* cmsg_type to set src addr */
end_comment

begin_define
define|#
directive|define
name|IP_RETOPTS
value|8
end_define

begin_comment
comment|/* ip_opts; set/get IP options */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_IF
value|9
end_define

begin_comment
comment|/* u_char; set/get IP multicast i/f  */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_TTL
value|10
end_define

begin_comment
comment|/* u_char; set/get IP multicast ttl */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_LOOP
value|11
end_define

begin_comment
comment|/* u_char; set/get IP multicast loopback */
end_comment

begin_define
define|#
directive|define
name|IP_ADD_MEMBERSHIP
value|12
end_define

begin_comment
comment|/* ip_mreq; add an IP group membership */
end_comment

begin_define
define|#
directive|define
name|IP_DROP_MEMBERSHIP
value|13
end_define

begin_comment
comment|/* ip_mreq; drop an IP group membership */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_VIF
value|14
end_define

begin_comment
comment|/* set/get IP mcast virt. iface */
end_comment

begin_define
define|#
directive|define
name|IP_RSVP_ON
value|15
end_define

begin_comment
comment|/* enable RSVP in kernel */
end_comment

begin_define
define|#
directive|define
name|IP_RSVP_OFF
value|16
end_define

begin_comment
comment|/* disable RSVP in kernel */
end_comment

begin_define
define|#
directive|define
name|IP_RSVP_VIF_ON
value|17
end_define

begin_comment
comment|/* set RSVP per-vif socket */
end_comment

begin_define
define|#
directive|define
name|IP_RSVP_VIF_OFF
value|18
end_define

begin_comment
comment|/* unset RSVP per-vif socket */
end_comment

begin_define
define|#
directive|define
name|IP_PORTRANGE
value|19
end_define

begin_comment
comment|/* int; range to choose for unspec port */
end_comment

begin_define
define|#
directive|define
name|IP_RECVIF
value|20
end_define

begin_comment
comment|/* bool; receive reception if w/dgram */
end_comment

begin_comment
comment|/* for IPSEC */
end_comment

begin_define
define|#
directive|define
name|IP_IPSEC_POLICY
value|21
end_define

begin_comment
comment|/* int; set/get security policy */
end_comment

begin_define
define|#
directive|define
name|IP_FAITH
value|22
end_define

begin_comment
comment|/* bool; accept FAITH'ed connections */
end_comment

begin_define
define|#
directive|define
name|IP_ONESBCAST
value|23
end_define

begin_comment
comment|/* bool: send all-ones broadcast */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_ADD
value|40
end_define

begin_comment
comment|/* add entry */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_DEL
value|41
end_define

begin_comment
comment|/* delete entry */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_FLUSH
value|42
end_define

begin_comment
comment|/* flush table */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_GETSIZE
value|43
end_define

begin_comment
comment|/* get table size */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_LIST
value|44
end_define

begin_comment
comment|/* list table contents */
end_comment

begin_define
define|#
directive|define
name|IP_FW_ADD
value|50
end_define

begin_comment
comment|/* add a firewall rule to chain */
end_comment

begin_define
define|#
directive|define
name|IP_FW_DEL
value|51
end_define

begin_comment
comment|/* delete a firewall rule from chain */
end_comment

begin_define
define|#
directive|define
name|IP_FW_FLUSH
value|52
end_define

begin_comment
comment|/* flush firewall rule chain */
end_comment

begin_define
define|#
directive|define
name|IP_FW_ZERO
value|53
end_define

begin_comment
comment|/* clear single/all firewall counter(s) */
end_comment

begin_define
define|#
directive|define
name|IP_FW_GET
value|54
end_define

begin_comment
comment|/* get entire firewall rule chain */
end_comment

begin_define
define|#
directive|define
name|IP_FW_RESETLOG
value|55
end_define

begin_comment
comment|/* reset logging counters */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT_CFG
value|56
end_define

begin_comment
comment|/* add/config a nat rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT_DEL
value|57
end_define

begin_comment
comment|/* delete a nat rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT_GET_CONFIG
value|58
end_define

begin_comment
comment|/* get configuration of a nat rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT_GET_LOG
value|59
end_define

begin_comment
comment|/* get log of a nat rule */
end_comment

begin_define
define|#
directive|define
name|IP_DUMMYNET_CONFIGURE
value|60
end_define

begin_comment
comment|/* add/configure a dummynet pipe */
end_comment

begin_define
define|#
directive|define
name|IP_DUMMYNET_DEL
value|61
end_define

begin_comment
comment|/* delete a dummynet pipe from chain */
end_comment

begin_define
define|#
directive|define
name|IP_DUMMYNET_FLUSH
value|62
end_define

begin_comment
comment|/* flush dummynet */
end_comment

begin_define
define|#
directive|define
name|IP_DUMMYNET_GET
value|64
end_define

begin_comment
comment|/* get entire dummynet pipes */
end_comment

begin_define
define|#
directive|define
name|IP_RECVTTL
value|65
end_define

begin_comment
comment|/* bool; receive IP TTL w/dgram */
end_comment

begin_define
define|#
directive|define
name|IP_MINTTL
value|66
end_define

begin_comment
comment|/* minimum TTL for packet or drop */
end_comment

begin_define
define|#
directive|define
name|IP_DONTFRAG
value|67
end_define

begin_comment
comment|/* don't fragment packet */
end_comment

begin_comment
comment|/*  * Defaults and limits for options  */
end_comment

begin_define
define|#
directive|define
name|IP_DEFAULT_MULTICAST_TTL
value|1
end_define

begin_comment
comment|/* normally limit m'casts to 1 hop  */
end_comment

begin_define
define|#
directive|define
name|IP_DEFAULT_MULTICAST_LOOP
value|1
end_define

begin_comment
comment|/* normally hear sends if a member  */
end_comment

begin_comment
comment|/*  * The imo_membership vector for each socket is now dynamically allocated at  * run-time, bounded by USHRT_MAX, and is reallocated when needed, sized  * according to a power-of-two increment.  */
end_comment

begin_define
define|#
directive|define
name|IP_MIN_MEMBERSHIPS
value|31
end_define

begin_define
define|#
directive|define
name|IP_MAX_MEMBERSHIPS
value|4095
end_define

begin_comment
comment|/*  * Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP.  */
end_comment

begin_struct
struct|struct
name|ip_mreq
block|{
name|struct
name|in_addr
name|imr_multiaddr
decl_stmt|;
comment|/* IP multicast address of group */
name|struct
name|in_addr
name|imr_interface
decl_stmt|;
comment|/* local IP address of interface */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument for IP_PORTRANGE:  * - which range to search when port is unspecified at bind() or connect()  */
end_comment

begin_define
define|#
directive|define
name|IP_PORTRANGE_DEFAULT
value|0
end_define

begin_comment
comment|/* default range */
end_comment

begin_define
define|#
directive|define
name|IP_PORTRANGE_HIGH
value|1
end_define

begin_comment
comment|/* "high" - request firewall bypass */
end_comment

begin_define
define|#
directive|define
name|IP_PORTRANGE_LOW
value|2
end_define

begin_comment
comment|/* "low" - vouchsafe security */
end_comment

begin_comment
comment|/*  * Definitions for inet sysctl operations.  *  * Third level is protocol number.  * Fourth level is desired variable within that protocol.  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MAXID
value|(IPPROTO_AH + 1)
end_define

begin_comment
comment|/* don't list to IPPROTO_MAX */
end_comment

begin_define
define|#
directive|define
name|CTL_IPPROTO_NAMES
value|{ \ 	{ "ip", CTLTYPE_NODE }, \ 	{ "icmp", CTLTYPE_NODE }, \ 	{ "igmp", CTLTYPE_NODE }, \ 	{ "ggp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "tcp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ "egp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "pup", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "udp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "idp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "ipsec", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "pim", CTLTYPE_NODE }, \ }
end_define

begin_comment
comment|/*  * Names for IP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|IPCTL_FORWARDING
value|1
end_define

begin_comment
comment|/* act as router */
end_comment

begin_define
define|#
directive|define
name|IPCTL_SENDREDIRECTS
value|2
end_define

begin_comment
comment|/* may send redirects when forwarding */
end_comment

begin_define
define|#
directive|define
name|IPCTL_DEFTTL
value|3
end_define

begin_comment
comment|/* default TTL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|IPCTL_DEFMTU
value|4
end_define

begin_comment
comment|/* default MTU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPCTL_RTEXPIRE
value|5
end_define

begin_comment
comment|/* cloned route expiration time */
end_comment

begin_define
define|#
directive|define
name|IPCTL_RTMINEXPIRE
value|6
end_define

begin_comment
comment|/* min value for expiration time */
end_comment

begin_define
define|#
directive|define
name|IPCTL_RTMAXCACHE
value|7
end_define

begin_comment
comment|/* trigger level for dynamic expire */
end_comment

begin_define
define|#
directive|define
name|IPCTL_SOURCEROUTE
value|8
end_define

begin_comment
comment|/* may perform source routes */
end_comment

begin_define
define|#
directive|define
name|IPCTL_DIRECTEDBROADCAST
value|9
end_define

begin_comment
comment|/* may re-broadcast received packets */
end_comment

begin_define
define|#
directive|define
name|IPCTL_INTRQMAXLEN
value|10
end_define

begin_comment
comment|/* max length of netisr queue */
end_comment

begin_define
define|#
directive|define
name|IPCTL_INTRQDROPS
value|11
end_define

begin_comment
comment|/* number of netisr q drops */
end_comment

begin_define
define|#
directive|define
name|IPCTL_STATS
value|12
end_define

begin_comment
comment|/* ipstat structure */
end_comment

begin_define
define|#
directive|define
name|IPCTL_ACCEPTSOURCEROUTE
value|13
end_define

begin_comment
comment|/* may accept source routed packets */
end_comment

begin_define
define|#
directive|define
name|IPCTL_FASTFORWARDING
value|14
end_define

begin_comment
comment|/* use fast IP forwarding code */
end_comment

begin_define
define|#
directive|define
name|IPCTL_KEEPFAITH
value|15
end_define

begin_comment
comment|/* FAITH IPv4->IPv6 translater ctl */
end_comment

begin_define
define|#
directive|define
name|IPCTL_GIF_TTL
value|16
end_define

begin_comment
comment|/* default TTL for gif encap packet */
end_comment

begin_define
define|#
directive|define
name|IPCTL_MAXID
value|17
end_define

begin_define
define|#
directive|define
name|IPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "forwarding", CTLTYPE_INT }, \ 	{ "redirect", CTLTYPE_INT }, \ 	{ "ttl", CTLTYPE_INT }, \ 	{ "mtu", CTLTYPE_INT }, \ 	{ "rtexpire", CTLTYPE_INT }, \ 	{ "rtminexpire", CTLTYPE_INT }, \ 	{ "rtmaxcache", CTLTYPE_INT }, \ 	{ "sourceroute", CTLTYPE_INT }, \ 	{ "directed-broadcast", CTLTYPE_INT }, \ 	{ "intr-queue-maxlen", CTLTYPE_INT }, \ 	{ "intr-queue-drops", CTLTYPE_INT }, \ 	{ "stats", CTLTYPE_STRUCT }, \ 	{ "accept_sourceroute", CTLTYPE_INT }, \ 	{ "fastforwarding", CTLTYPE_INT }, \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declarations for Standard C */
end_comment

begin_function_decl
name|int
name|in_broadcast
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_canforward
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_localaddr
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_localip
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in libkern */
end_comment

begin_function_decl
name|char
modifier|*
name|inet_ntoa_r
parameter_list|(
name|struct
name|in_addr
name|ina
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in libkern */
end_comment

begin_function_decl
name|void
name|in_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|in_hosteq
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s).s_addr == (t).s_addr)
end_define

begin_define
define|#
directive|define
name|in_nullhost
parameter_list|(
name|x
parameter_list|)
value|((x).s_addr == INADDR_ANY)
end_define

begin_define
define|#
directive|define
name|satosin
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in *)(sa))
end_define

begin_define
define|#
directive|define
name|sintosa
parameter_list|(
name|sin
parameter_list|)
value|((struct sockaddr *)(sin))
end_define

begin_define
define|#
directive|define
name|ifatoia
parameter_list|(
name|ifa
parameter_list|)
value|((struct in_ifaddr *)(ifa))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* INET6 stuff */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|__KAME_NETINET_IN_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|<netinet6/in6.h>
end_include

begin_undef
undef|#
directive|undef
name|__KAME_NETINET_IN_H_INCLUDED_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_IN_H_*/
end_comment

end_unit

