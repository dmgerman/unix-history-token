begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)in.h 1.19 90/07/27 SMI; from UCB 7.5 2/22/88	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Constants and structures defined by the internet system,  * Per RFC 790, September 1981.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_netinet_in_h
end_ifndef

begin_define
define|#
directive|define
name|_netinet_in_h
end_define

begin_define
define|#
directive|define
name|_NETINET_IN_H_
end_define

begin_define
define|#
directive|define
name|_SYS_IN_INCLUDED
end_define

begin_define
define|#
directive|define
name|__IN_HEADER
end_define

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
comment|/* group control protocol */
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
name|IPPROTO_ST
value|5
end_define

begin_comment
comment|/* st */
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
name|IPPROTO_HELLO
value|63
end_define

begin_comment
comment|/* "hello" routing protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ND
value|77
end_define

begin_comment
comment|/* UNOFFICIAL net disk proto */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_OSPF
value|89
end_define

begin_comment
comment|/* Open SPF IGP */
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
comment|/*  * Port/socket numbers: network standard functions  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_ECHO
value|7
end_define

begin_define
define|#
directive|define
name|IPPORT_DISCARD
value|9
end_define

begin_define
define|#
directive|define
name|IPPORT_SYSTAT
value|11
end_define

begin_define
define|#
directive|define
name|IPPORT_DAYTIME
value|13
end_define

begin_define
define|#
directive|define
name|IPPORT_NETSTAT
value|15
end_define

begin_define
define|#
directive|define
name|IPPORT_FTP
value|21
end_define

begin_define
define|#
directive|define
name|IPPORT_TELNET
value|23
end_define

begin_define
define|#
directive|define
name|IPPORT_SMTP
value|25
end_define

begin_define
define|#
directive|define
name|IPPORT_TIMESERVER
value|37
end_define

begin_define
define|#
directive|define
name|IPPORT_NAMESERVER
value|42
end_define

begin_define
define|#
directive|define
name|IPPORT_WHOIS
value|43
end_define

begin_define
define|#
directive|define
name|IPPORT_MTP
value|57
end_define

begin_comment
comment|/*  * Port/socket numbers: host specific functions  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_TFTP
value|69
end_define

begin_define
define|#
directive|define
name|IPPORT_RJE
value|77
end_define

begin_define
define|#
directive|define
name|IPPORT_FINGER
value|79
end_define

begin_define
define|#
directive|define
name|IPPORT_TTYLINK
value|87
end_define

begin_define
define|#
directive|define
name|IPPORT_SUPDUP
value|95
end_define

begin_comment
comment|/*  * UNIX TCP sockets  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_EXECSERVER
value|512
end_define

begin_define
define|#
directive|define
name|IPPORT_LOGINSERVER
value|513
end_define

begin_define
define|#
directive|define
name|IPPORT_CMDSERVER
value|514
end_define

begin_define
define|#
directive|define
name|IPPORT_EFSSERVER
value|520
end_define

begin_comment
comment|/*  * UNIX UDP sockets  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_BIFFUDP
value|512
end_define

begin_define
define|#
directive|define
name|IPPORT_WHOSERVER
value|513
end_define

begin_define
define|#
directive|define
name|IPPORT_ROUTESERVER
value|520
end_define

begin_comment
comment|/* 520+1 also used */
end_comment

begin_comment
comment|/*  * Ports< IPPORT_RESERVED are reserved for  * privileged processes (e.g. root).  * Ports> IPPORT_USERRESERVED are reserved  * for servers, not necessarily privileged.  */
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
comment|/*  * Link numbers  */
end_comment

begin_define
define|#
directive|define
name|IMPLINK_IP
value|155
end_define

begin_define
define|#
directive|define
name|IMPLINK_LOWEXPER
value|156
end_define

begin_define
define|#
directive|define
name|IMPLINK_HIGHEXPER
value|158
end_define

begin_comment
comment|/*  * Internet address  *	This definition contains obsolete fields for compatibility  *	with SunOS 3.x and 4.2bsd.  The presence of subnets renders  *	divisions into fixed fields misleading at best.  New code  *	should use only the s_addr field.  */
end_comment

begin_struct
struct|struct
name|in_addr
block|{
union|union
block|{
struct|struct
block|{
name|u_char
name|s_b1
decl_stmt|,
name|s_b2
decl_stmt|,
name|s_b3
decl_stmt|,
name|s_b4
decl_stmt|;
block|}
name|S_un_b
struct|;
struct|struct
block|{
name|u_short
name|s_w1
decl_stmt|,
name|s_w2
decl_stmt|;
block|}
name|S_un_w
struct|;
name|u_long
name|S_addr
decl_stmt|;
block|}
name|S_un
union|;
define|#
directive|define
name|s_addr
value|S_un.S_addr
comment|/* should be used for all code */
define|#
directive|define
name|s_host
value|S_un.S_un_b.s_b2
comment|/* OBSOLETE: host on imp */
define|#
directive|define
name|s_net
value|S_un.S_un_b.s_b1
comment|/* OBSOLETE: network */
define|#
directive|define
name|s_imp
value|S_un.S_un_w.s_w2
comment|/* OBSOLETE: imp */
define|#
directive|define
name|s_impno
value|S_un.S_un_b.s_b4
comment|/* OBSOLETE: imp # */
define|#
directive|define
name|s_lh
value|S_un.S_un_b.s_b3
comment|/* OBSOLETE: logical host */
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
value|(((long)(i)& 0xe0000000) == 0xe0000000)
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
name|INADDR_LOOPBACK
value|(u_long)0x7F000001
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

begin_define
define|#
directive|define
name|INADDR_UNSPEC_GROUP
value|(u_long)0xe0000000
end_define

begin_comment
comment|/* 224.0.0.0   */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLHOSTS_GROUP
value|(u_long)0xe0000001
end_define

begin_comment
comment|/* 224.0.0.1   */
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
comment|/*  * Define a macro to stuff the loopback address into an Internet address  */
end_comment

begin_define
define|#
directive|define
name|IN_SET_LOOPBACK_ADDR
parameter_list|(
name|a
parameter_list|)
value|{(a)->sin_addr.s_addr  = htonl(INADDR_LOOPBACK); \ 	(a)->sin_family = AF_INET;}
end_define

begin_comment
comment|/*  * Socket address, internet style.  */
end_comment

begin_struct
struct|struct
name|sockaddr_in
block|{
name|short
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
comment|/*  * Options for use with [gs]etsockopt at the IP level.  */
end_comment

begin_define
define|#
directive|define
name|IP_OPTIONS
value|1
end_define

begin_comment
comment|/* set/get IP per-packet options */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_IF
value|2
end_define

begin_comment
comment|/* set/get IP multicast interface  */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_TTL
value|3
end_define

begin_comment
comment|/* set/get IP multicast timetolive */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_LOOP
value|4
end_define

begin_comment
comment|/* set/get IP multicast loopback   */
end_comment

begin_define
define|#
directive|define
name|IP_ADD_MEMBERSHIP
value|5
end_define

begin_comment
comment|/* add  an IP group membership     */
end_comment

begin_define
define|#
directive|define
name|IP_DROP_MEMBERSHIP
value|6
end_define

begin_comment
comment|/* drop an IP group membership     */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ntohl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_comment
comment|/*  * Macros for number representation conversion.  */
end_comment

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ntohl
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
operator|)
end_if

begin_decl_stmt
name|u_short
name|ntohs
argument_list|()
decl_stmt|,
name|htons
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ntohl
argument_list|()
decl_stmt|,
name|htonl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|inetdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|inetsw
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in_addr
name|in_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|u_long
name|in_netof
argument_list|()
decl_stmt|,
name|in_lnaof
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_comment
comment|/*  * Definitions for byte order,  * according to byte significance from low address to high.  */
end_comment

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* mc68000, tahoe, most others */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|BYTE_ORDER
end_endif

begin_comment
comment|/*  * Macros for number representation conversion.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|d
parameter_list|)
value|((d) = ntohl((d)))
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|d
parameter_list|)
value|((d) = ntohs((d)))
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|d
parameter_list|)
value|((d) = htonl((d)))
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|d
parameter_list|)
value|((d) = htons((d)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|d
parameter_list|)
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
comment|/*!_netinet_in_h*/
end_comment

end_unit

