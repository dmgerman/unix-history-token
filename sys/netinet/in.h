begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in.h	8.3 (Berkeley) 1/3/94  */
end_comment

begin_comment
comment|/*  * Constants and structures defined by the internet system,  * Per RFC 790, September 1981, and numerous additions.  */
end_comment

begin_comment
comment|/*  * Protocols  */
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
name|IPPROTO_TCP
value|6
end_define

begin_comment
comment|/* tcp */
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
name|IPPROTO_PUP
value|12
end_define

begin_comment
comment|/* pup */
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
name|IPPROTO_IDP
value|22
end_define

begin_comment
comment|/* xns idp */
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
name|IPPROTO_EON
value|80
end_define

begin_comment
comment|/* ISO cnlp */
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
name|IPPROTO_RAW
value|255
end_define

begin_comment
comment|/* raw IP packet */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MAX
value|256
end_define

begin_comment
comment|/*  * Local port number conventions:  * Ports< IPPORT_RESERVED are reserved for  * privileged processes (e.g. root).  * Ports> IPPORT_USERRESERVED are reserved  * for servers, not necessarily privileged.  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_RESERVED
value|1024
end_define

begin_define
define|#
directive|define
name|IPPORT_USERRESERVED
value|5000
end_define

begin_comment
comment|/*  * Internet address (a structure for historical reasons)  */
end_comment

begin_struct
struct|struct
name|in_addr
block|{
name|u_long
name|s_addr
decl_stmt|;
block|}
struct|;
end_struct

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
value|(((long)(i)& 0x80000000) == 0)
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
value|(((long)(i)& 0xc0000000) == 0x80000000)
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
value|(((long)(i)& 0xe0000000) == 0xc0000000)
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
value|(((long)(i)& 0xf0000000) == 0xe0000000)
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
value|(((long)(i)& 0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|IN_BADCLASS
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|INADDR_ANY
value|(u_long)0x00000000
end_define

begin_define
define|#
directive|define
name|INADDR_BROADCAST
value|(u_long)0xffffffff
end_define

begin_comment
comment|/* must be masked */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
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
value|(u_long)0xe0000000
end_define

begin_comment
comment|/* 224.0.0.0 */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLHOSTS_GROUP
value|(u_long)0xe0000001
end_define

begin_comment
comment|/* 224.0.0.1 */
end_comment

begin_define
define|#
directive|define
name|INADDR_MAX_LOCAL_GROUP
value|(u_long)0xe00000ff
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
comment|/*  * Socket address, internet style.  */
end_comment

begin_struct
struct|struct
name|sockaddr_in
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
name|char
name|sin_zero
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to describe IP options.  * Used to store options internally, to pass them to a process,  * or to restore options retrieved earlier.  * The ip_dst is used for the first-hop gateway when using a source route  * (this gets put into the header proper).  */
end_comment

begin_struct
struct|struct
name|ip_opts
block|{
name|struct
name|in_addr
name|ip_dst
decl_stmt|;
comment|/* first hop, 0 w/o src rt */
name|char
name|ip_opts
index|[
literal|40
index|]
decl_stmt|;
comment|/* actually variable in size */
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|IP_MAX_MEMBERSHIPS
value|20
end_define

begin_comment
comment|/* per socket; must fit in one mbuf */
end_comment

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
comment|/*  * Definitions for inet sysctl operations.  *  * Third level is protocol number.  * Fourth level is desired variable within that protocol.  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MAXID
value|(IPPROTO_IDP + 1)
end_define

begin_comment
comment|/* don't list to IPPROTO_MAX */
end_comment

begin_define
define|#
directive|define
name|CTL_IPPROTO_NAMES
value|{ \ 	{ "ip", CTLTYPE_NODE }, \ 	{ "icmp", CTLTYPE_NODE }, \ 	{ "igmp", CTLTYPE_NODE }, \ 	{ "ggp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "tcp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ "egp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "pup", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "udp", CTLTYPE_NODE }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "idp", CTLTYPE_NODE }, \ }
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
name|IPCTL_MAXID
value|5
end_define

begin_define
define|#
directive|define
name|IPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "forwarding", CTLTYPE_INT }, \ 	{ "redirect", CTLTYPE_INT }, \ 	{ "ttl", CTLTYPE_INT }, \ 	{ "mtu", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|in_broadcast
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_canforward
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_cksum
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

begin_decl_stmt
name|int
name|in_localaddr
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|in_netof
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_socktrim
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

