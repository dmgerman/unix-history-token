begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1985, 1986, 1988, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socket.h	8.4 (Berkeley) 2/21/94  * $Id: socket.h,v 1.23 1997/12/21 16:35:11 bde Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOCKET_H_
end_define

begin_comment
comment|/*  * Definitions related to sockets: types, address families, options.  */
end_comment

begin_comment
comment|/*  * Types  */
end_comment

begin_define
define|#
directive|define
name|SOCK_STREAM
value|1
end_define

begin_comment
comment|/* stream socket */
end_comment

begin_define
define|#
directive|define
name|SOCK_DGRAM
value|2
end_define

begin_comment
comment|/* datagram socket */
end_comment

begin_define
define|#
directive|define
name|SOCK_RAW
value|3
end_define

begin_comment
comment|/* raw-protocol interface */
end_comment

begin_define
define|#
directive|define
name|SOCK_RDM
value|4
end_define

begin_comment
comment|/* reliably-delivered message */
end_comment

begin_define
define|#
directive|define
name|SOCK_SEQPACKET
value|5
end_define

begin_comment
comment|/* sequenced packet stream */
end_comment

begin_comment
comment|/*  * Option flags per-socket.  */
end_comment

begin_define
define|#
directive|define
name|SO_DEBUG
value|0x0001
end_define

begin_comment
comment|/* turn on debugging info recording */
end_comment

begin_define
define|#
directive|define
name|SO_ACCEPTCONN
value|0x0002
end_define

begin_comment
comment|/* socket has had listen() */
end_comment

begin_define
define|#
directive|define
name|SO_REUSEADDR
value|0x0004
end_define

begin_comment
comment|/* allow local address reuse */
end_comment

begin_define
define|#
directive|define
name|SO_KEEPALIVE
value|0x0008
end_define

begin_comment
comment|/* keep connections alive */
end_comment

begin_define
define|#
directive|define
name|SO_DONTROUTE
value|0x0010
end_define

begin_comment
comment|/* just use interface addresses */
end_comment

begin_define
define|#
directive|define
name|SO_BROADCAST
value|0x0020
end_define

begin_comment
comment|/* permit sending of broadcast msgs */
end_comment

begin_define
define|#
directive|define
name|SO_USELOOPBACK
value|0x0040
end_define

begin_comment
comment|/* bypass hardware when possible */
end_comment

begin_define
define|#
directive|define
name|SO_LINGER
value|0x0080
end_define

begin_comment
comment|/* linger on close if data present */
end_comment

begin_define
define|#
directive|define
name|SO_OOBINLINE
value|0x0100
end_define

begin_comment
comment|/* leave received OOB data in line */
end_comment

begin_define
define|#
directive|define
name|SO_REUSEPORT
value|0x0200
end_define

begin_comment
comment|/* allow local address& port reuse */
end_comment

begin_define
define|#
directive|define
name|SO_TIMESTAMP
value|0x0400
end_define

begin_comment
comment|/* timestamp received dgram traffic */
end_comment

begin_comment
comment|/*  * Additional options, not kept in so_options.  */
end_comment

begin_define
define|#
directive|define
name|SO_SNDBUF
value|0x1001
end_define

begin_comment
comment|/* send buffer size */
end_comment

begin_define
define|#
directive|define
name|SO_RCVBUF
value|0x1002
end_define

begin_comment
comment|/* receive buffer size */
end_comment

begin_define
define|#
directive|define
name|SO_SNDLOWAT
value|0x1003
end_define

begin_comment
comment|/* send low-water mark */
end_comment

begin_define
define|#
directive|define
name|SO_RCVLOWAT
value|0x1004
end_define

begin_comment
comment|/* receive low-water mark */
end_comment

begin_define
define|#
directive|define
name|SO_SNDTIMEO
value|0x1005
end_define

begin_comment
comment|/* send timeout */
end_comment

begin_define
define|#
directive|define
name|SO_RCVTIMEO
value|0x1006
end_define

begin_comment
comment|/* receive timeout */
end_comment

begin_define
define|#
directive|define
name|SO_ERROR
value|0x1007
end_define

begin_comment
comment|/* get error status and clear */
end_comment

begin_define
define|#
directive|define
name|SO_TYPE
value|0x1008
end_define

begin_comment
comment|/* get socket type */
end_comment

begin_comment
comment|/*efine	SO_PRIVSTATE	0x1009		   get/deny privileged state */
end_comment

begin_comment
comment|/*  * Structure used for manipulating linger option.  */
end_comment

begin_struct
struct|struct
name|linger
block|{
name|int
name|l_onoff
decl_stmt|;
comment|/* option on/off */
name|int
name|l_linger
decl_stmt|;
comment|/* linger time */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Level number for (get/set)sockopt() to apply to socket itself.  */
end_comment

begin_define
define|#
directive|define
name|SOL_SOCKET
value|0xffff
end_define

begin_comment
comment|/* options for socket level */
end_comment

begin_comment
comment|/*  * Address families.  */
end_comment

begin_define
define|#
directive|define
name|AF_UNSPEC
value|0
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_define
define|#
directive|define
name|AF_LOCAL
value|1
end_define

begin_comment
comment|/* local to host (pipes, portals) */
end_comment

begin_define
define|#
directive|define
name|AF_UNIX
value|AF_LOCAL
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_define
define|#
directive|define
name|AF_INET
value|2
end_define

begin_comment
comment|/* internetwork: UDP, TCP, etc. */
end_comment

begin_define
define|#
directive|define
name|AF_IMPLINK
value|3
end_define

begin_comment
comment|/* arpanet imp addresses */
end_comment

begin_define
define|#
directive|define
name|AF_PUP
value|4
end_define

begin_comment
comment|/* pup protocols: e.g. BSP */
end_comment

begin_define
define|#
directive|define
name|AF_CHAOS
value|5
end_define

begin_comment
comment|/* mit CHAOS protocols */
end_comment

begin_define
define|#
directive|define
name|AF_NS
value|6
end_define

begin_comment
comment|/* XEROX NS protocols */
end_comment

begin_define
define|#
directive|define
name|AF_ISO
value|7
end_define

begin_comment
comment|/* ISO protocols */
end_comment

begin_define
define|#
directive|define
name|AF_OSI
value|AF_ISO
end_define

begin_define
define|#
directive|define
name|AF_ECMA
value|8
end_define

begin_comment
comment|/* European computer manufacturers */
end_comment

begin_define
define|#
directive|define
name|AF_DATAKIT
value|9
end_define

begin_comment
comment|/* datakit protocols */
end_comment

begin_define
define|#
directive|define
name|AF_CCITT
value|10
end_define

begin_comment
comment|/* CCITT protocols, X.25 etc */
end_comment

begin_define
define|#
directive|define
name|AF_SNA
value|11
end_define

begin_comment
comment|/* IBM SNA */
end_comment

begin_define
define|#
directive|define
name|AF_DECnet
value|12
end_define

begin_comment
comment|/* DECnet */
end_comment

begin_define
define|#
directive|define
name|AF_DLI
value|13
end_define

begin_comment
comment|/* DEC Direct data link interface */
end_comment

begin_define
define|#
directive|define
name|AF_LAT
value|14
end_define

begin_comment
comment|/* LAT */
end_comment

begin_define
define|#
directive|define
name|AF_HYLINK
value|15
end_define

begin_comment
comment|/* NSC Hyperchannel */
end_comment

begin_define
define|#
directive|define
name|AF_APPLETALK
value|16
end_define

begin_comment
comment|/* Apple Talk */
end_comment

begin_define
define|#
directive|define
name|AF_ROUTE
value|17
end_define

begin_comment
comment|/* Internal Routing Protocol */
end_comment

begin_define
define|#
directive|define
name|AF_LINK
value|18
end_define

begin_comment
comment|/* Link layer interface */
end_comment

begin_define
define|#
directive|define
name|pseudo_AF_XTP
value|19
end_define

begin_comment
comment|/* eXpress Transfer Protocol (no AF) */
end_comment

begin_define
define|#
directive|define
name|AF_COIP
value|20
end_define

begin_comment
comment|/* connection-oriented IP, aka ST II */
end_comment

begin_define
define|#
directive|define
name|AF_CNT
value|21
end_define

begin_comment
comment|/* Computer Network Technology */
end_comment

begin_define
define|#
directive|define
name|pseudo_AF_RTIP
value|22
end_define

begin_comment
comment|/* Help Identify RTIP packets */
end_comment

begin_define
define|#
directive|define
name|AF_IPX
value|23
end_define

begin_comment
comment|/* Novell Internet Protocol */
end_comment

begin_define
define|#
directive|define
name|AF_SIP
value|24
end_define

begin_comment
comment|/* Simple Internet Protocol */
end_comment

begin_define
define|#
directive|define
name|pseudo_AF_PIP
value|25
end_define

begin_comment
comment|/* Help Identify PIP packets */
end_comment

begin_define
define|#
directive|define
name|AF_ISDN
value|26
end_define

begin_comment
comment|/* Integrated Services Digital Network*/
end_comment

begin_define
define|#
directive|define
name|AF_E164
value|AF_ISDN
end_define

begin_comment
comment|/* CCITT E.164 recommendation */
end_comment

begin_define
define|#
directive|define
name|pseudo_AF_KEY
value|27
end_define

begin_comment
comment|/* Internal key-management function */
end_comment

begin_define
define|#
directive|define
name|AF_INET6
value|28
end_define

begin_comment
comment|/* IPv6 */
end_comment

begin_define
define|#
directive|define
name|AF_NATM
value|29
end_define

begin_comment
comment|/* native ATM access */
end_comment

begin_define
define|#
directive|define
name|AF_MAX
value|30
end_define

begin_comment
comment|/*  * Structure used by kernel to store most  * addresses.  */
end_comment

begin_struct
struct|struct
name|sockaddr
block|{
name|u_char
name|sa_len
decl_stmt|;
comment|/* total length */
name|u_char
name|sa_family
decl_stmt|;
comment|/* address family */
name|char
name|sa_data
index|[
literal|14
index|]
decl_stmt|;
comment|/* actually longer; address value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SOCK_MAXADDRLEN
value|255
end_define

begin_comment
comment|/* longest possible addresses */
end_comment

begin_comment
comment|/*  * Structure used by kernel to pass protocol  * information in raw sockets.  */
end_comment

begin_struct
struct|struct
name|sockproto
block|{
name|u_short
name|sp_family
decl_stmt|;
comment|/* address family */
name|u_short
name|sp_protocol
decl_stmt|;
comment|/* protocol */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol families, same as address families for now.  */
end_comment

begin_define
define|#
directive|define
name|PF_UNSPEC
value|AF_UNSPEC
end_define

begin_define
define|#
directive|define
name|PF_LOCAL
value|AF_LOCAL
end_define

begin_define
define|#
directive|define
name|PF_UNIX
value|PF_LOCAL
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_define
define|#
directive|define
name|PF_INET
value|AF_INET
end_define

begin_define
define|#
directive|define
name|PF_IMPLINK
value|AF_IMPLINK
end_define

begin_define
define|#
directive|define
name|PF_PUP
value|AF_PUP
end_define

begin_define
define|#
directive|define
name|PF_CHAOS
value|AF_CHAOS
end_define

begin_define
define|#
directive|define
name|PF_NS
value|AF_NS
end_define

begin_define
define|#
directive|define
name|PF_ISO
value|AF_ISO
end_define

begin_define
define|#
directive|define
name|PF_OSI
value|AF_ISO
end_define

begin_define
define|#
directive|define
name|PF_ECMA
value|AF_ECMA
end_define

begin_define
define|#
directive|define
name|PF_DATAKIT
value|AF_DATAKIT
end_define

begin_define
define|#
directive|define
name|PF_CCITT
value|AF_CCITT
end_define

begin_define
define|#
directive|define
name|PF_SNA
value|AF_SNA
end_define

begin_define
define|#
directive|define
name|PF_DECnet
value|AF_DECnet
end_define

begin_define
define|#
directive|define
name|PF_DLI
value|AF_DLI
end_define

begin_define
define|#
directive|define
name|PF_LAT
value|AF_LAT
end_define

begin_define
define|#
directive|define
name|PF_HYLINK
value|AF_HYLINK
end_define

begin_define
define|#
directive|define
name|PF_APPLETALK
value|AF_APPLETALK
end_define

begin_define
define|#
directive|define
name|PF_ROUTE
value|AF_ROUTE
end_define

begin_define
define|#
directive|define
name|PF_LINK
value|AF_LINK
end_define

begin_define
define|#
directive|define
name|PF_XTP
value|pseudo_AF_XTP
end_define

begin_comment
comment|/* really just proto family, no AF */
end_comment

begin_define
define|#
directive|define
name|PF_COIP
value|AF_COIP
end_define

begin_define
define|#
directive|define
name|PF_CNT
value|AF_CNT
end_define

begin_define
define|#
directive|define
name|PF_SIP
value|AF_SIP
end_define

begin_define
define|#
directive|define
name|PF_IPX
value|AF_IPX
end_define

begin_comment
comment|/* same format as AF_NS */
end_comment

begin_define
define|#
directive|define
name|PF_RTIP
value|pseudo_AF_RTIP
end_define

begin_comment
comment|/* same format as AF_INET */
end_comment

begin_define
define|#
directive|define
name|PF_PIP
value|pseudo_AF_PIP
end_define

begin_define
define|#
directive|define
name|PF_ISDN
value|AF_ISDN
end_define

begin_define
define|#
directive|define
name|PF_KEY
value|pseudo_AF_KEY
end_define

begin_define
define|#
directive|define
name|PF_INET6
value|AF_INET6
end_define

begin_define
define|#
directive|define
name|PF_NATM
value|AF_NATM
end_define

begin_define
define|#
directive|define
name|PF_MAX
value|AF_MAX
end_define

begin_comment
comment|/*  * Definitions for network related sysctl, CTL_NET.  *  * Second level is protocol family.  * Third level is protocol number.  *  * Further levels are defined by the individual families below.  */
end_comment

begin_define
define|#
directive|define
name|NET_MAXID
value|AF_MAX
end_define

begin_define
define|#
directive|define
name|CTL_NET_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "unix", CTLTYPE_NODE }, \ 	{ "inet", CTLTYPE_NODE }, \ 	{ "implink", CTLTYPE_NODE }, \ 	{ "pup", CTLTYPE_NODE }, \ 	{ "chaos", CTLTYPE_NODE }, \ 	{ "xerox_ns", CTLTYPE_NODE }, \ 	{ "iso", CTLTYPE_NODE }, \ 	{ "emca", CTLTYPE_NODE }, \ 	{ "datakit", CTLTYPE_NODE }, \ 	{ "ccitt", CTLTYPE_NODE }, \ 	{ "ibm_sna", CTLTYPE_NODE }, \ 	{ "decnet", CTLTYPE_NODE }, \ 	{ "dec_dli", CTLTYPE_NODE }, \ 	{ "lat", CTLTYPE_NODE }, \ 	{ "hylink", CTLTYPE_NODE }, \ 	{ "appletalk", CTLTYPE_NODE }, \ 	{ "route", CTLTYPE_NODE }, \ 	{ "link_layer", CTLTYPE_NODE }, \ 	{ "xtp", CTLTYPE_NODE }, \ 	{ "coip", CTLTYPE_NODE }, \ 	{ "cnt", CTLTYPE_NODE }, \ 	{ "rtip", CTLTYPE_NODE }, \ 	{ "ipx", CTLTYPE_NODE }, \ 	{ "sip", CTLTYPE_NODE }, \ 	{ "pip", CTLTYPE_NODE }, \ 	{ "isdn", CTLTYPE_NODE }, \ 	{ "key", CTLTYPE_NODE }, \ 	{ "inet6", CTLTYPE_NODE }, \ 	{ "natm", CTLTYPE_NODE }, \ }
end_define

begin_comment
comment|/*  * PF_ROUTE - Routing table  *  * Three additional levels are defined:  *	Fourth: address family, 0 is wildcard  *	Fifth: type of info, defined below  *	Sixth: flag(s) to mask with for NET_RT_FLAGS  */
end_comment

begin_define
define|#
directive|define
name|NET_RT_DUMP
value|1
end_define

begin_comment
comment|/* dump; may limit to a.f. */
end_comment

begin_define
define|#
directive|define
name|NET_RT_FLAGS
value|2
end_define

begin_comment
comment|/* by flags, e.g. RESOLVING */
end_comment

begin_define
define|#
directive|define
name|NET_RT_IFLIST
value|3
end_define

begin_comment
comment|/* survey interface list */
end_comment

begin_define
define|#
directive|define
name|NET_RT_MAXID
value|4
end_define

begin_define
define|#
directive|define
name|CTL_NET_RT_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "dump", CTLTYPE_STRUCT }, \ 	{ "flags", CTLTYPE_STRUCT }, \ 	{ "iflist", CTLTYPE_STRUCT }, \ }
end_define

begin_comment
comment|/*  * Maximum queue length specifiable by listen.  */
end_comment

begin_define
define|#
directive|define
name|SOMAXCONN
value|128
end_define

begin_comment
comment|/*  * Message header for recvmsg and sendmsg calls.  * Used value-result for recvmsg, value only for sendmsg.  */
end_comment

begin_struct
struct|struct
name|msghdr
block|{
name|caddr_t
name|msg_name
decl_stmt|;
comment|/* optional address */
name|u_int
name|msg_namelen
decl_stmt|;
comment|/* size of address */
name|struct
name|iovec
modifier|*
name|msg_iov
decl_stmt|;
comment|/* scatter/gather array */
name|u_int
name|msg_iovlen
decl_stmt|;
comment|/* # elements in msg_iov */
name|caddr_t
name|msg_control
decl_stmt|;
comment|/* ancillary data, see below */
name|u_int
name|msg_controllen
decl_stmt|;
comment|/* ancillary data buffer len */
name|int
name|msg_flags
decl_stmt|;
comment|/* flags on received message */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MSG_OOB
value|0x1
end_define

begin_comment
comment|/* process out-of-band data */
end_comment

begin_define
define|#
directive|define
name|MSG_PEEK
value|0x2
end_define

begin_comment
comment|/* peek at incoming message */
end_comment

begin_define
define|#
directive|define
name|MSG_DONTROUTE
value|0x4
end_define

begin_comment
comment|/* send without using routing tables */
end_comment

begin_define
define|#
directive|define
name|MSG_EOR
value|0x8
end_define

begin_comment
comment|/* data completes record */
end_comment

begin_define
define|#
directive|define
name|MSG_TRUNC
value|0x10
end_define

begin_comment
comment|/* data discarded before delivery */
end_comment

begin_define
define|#
directive|define
name|MSG_CTRUNC
value|0x20
end_define

begin_comment
comment|/* control data lost before delivery */
end_comment

begin_define
define|#
directive|define
name|MSG_WAITALL
value|0x40
end_define

begin_comment
comment|/* wait for full request or error */
end_comment

begin_define
define|#
directive|define
name|MSG_DONTWAIT
value|0x80
end_define

begin_comment
comment|/* this message should be nonblocking */
end_comment

begin_define
define|#
directive|define
name|MSG_EOF
value|0x100
end_define

begin_comment
comment|/* data completes connection */
end_comment

begin_define
define|#
directive|define
name|MSG_COMPAT
value|0x8000
end_define

begin_comment
comment|/* used in sendit() */
end_comment

begin_comment
comment|/*  * Header for ancillary data objects in msg_control buffer.  * Used for additional information with/about a datagram  * not expressible by flags.  The format is a sequence  * of message elements headed by cmsghdr structures.  */
end_comment

begin_struct
struct|struct
name|cmsghdr
block|{
name|u_int
name|cmsg_len
decl_stmt|;
comment|/* data byte count, including hdr */
name|int
name|cmsg_level
decl_stmt|;
comment|/* originating protocol */
name|int
name|cmsg_type
decl_stmt|;
comment|/* protocol-specific type */
comment|/* followed by	u_char  cmsg_data[]; */
block|}
struct|;
end_struct

begin_comment
comment|/*  * While we may have more groups than this, the cmsgcred struct must  * be able to fit in an mbuf, and NGROUPS_MAX is too large to allow  * this. */
end_comment

begin_define
define|#
directive|define
name|CMGROUP_MAX
value|16
end_define

begin_comment
comment|/*  * Credentials structure, used to verify the identity of a peer  * process that has sent us a message. This is allocated by the  * peer process but filled in by the kernel. This prevents the  * peer from lying about its identity. (Note that cmcred_groups[0]  * is the effective GID.)  */
end_comment

begin_struct
struct|struct
name|cmsgcred
block|{
name|pid_t
name|cmcred_pid
decl_stmt|;
comment|/* PID of sending process */
name|uid_t
name|cmcred_uid
decl_stmt|;
comment|/* real UID of sending process */
name|uid_t
name|cmcred_euid
decl_stmt|;
comment|/* effective UID of sending process */
name|gid_t
name|cmcred_gid
decl_stmt|;
comment|/* real GID of sending process */
name|short
name|cmcred_ngroups
decl_stmt|;
comment|/* number or groups */
name|gid_t
name|cmcred_groups
index|[
name|CMGROUP_MAX
index|]
decl_stmt|;
comment|/* groups */
block|}
struct|;
end_struct

begin_comment
comment|/* given pointer to struct cmsghdr, return pointer to data */
end_comment

begin_define
define|#
directive|define
name|CMSG_DATA
parameter_list|(
name|cmsg
parameter_list|)
value|((u_char *)((cmsg) + 1))
end_define

begin_comment
comment|/* given pointer to struct cmsghdr, return pointer to next cmsghdr */
end_comment

begin_define
define|#
directive|define
name|CMSG_NXTHDR
parameter_list|(
name|mhdr
parameter_list|,
name|cmsg
parameter_list|)
define|\
value|(((caddr_t)(cmsg) + (cmsg)->cmsg_len + sizeof(struct cmsghdr)> \ 	    (mhdr)->msg_control + (mhdr)->msg_controllen) ? \ 	    (struct cmsghdr *)NULL : \ 	    (struct cmsghdr *)((caddr_t)(cmsg) + ALIGN((cmsg)->cmsg_len)))
end_define

begin_define
define|#
directive|define
name|CMSG_FIRSTHDR
parameter_list|(
name|mhdr
parameter_list|)
value|((struct cmsghdr *)(mhdr)->msg_control)
end_define

begin_comment
comment|/* "Socket"-level control message types: */
end_comment

begin_define
define|#
directive|define
name|SCM_RIGHTS
value|0x01
end_define

begin_comment
comment|/* access rights (array of int) */
end_comment

begin_define
define|#
directive|define
name|SCM_TIMESTAMP
value|0x02
end_define

begin_comment
comment|/* timestamp (struct timeval) */
end_comment

begin_define
define|#
directive|define
name|SCM_CREDS
value|0x03
end_define

begin_comment
comment|/* process creds (struct cmsgcred) */
end_comment

begin_comment
comment|/*  * 4.3 compat sockaddr, move to compat file later  */
end_comment

begin_struct
struct|struct
name|osockaddr
block|{
name|u_short
name|sa_family
decl_stmt|;
comment|/* address family */
name|char
name|sa_data
index|[
literal|14
index|]
decl_stmt|;
comment|/* up to 14 bytes of direct address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 4.3-compat message header (move to compat file later).  */
end_comment

begin_struct
struct|struct
name|omsghdr
block|{
name|caddr_t
name|msg_name
decl_stmt|;
comment|/* optional address */
name|int
name|msg_namelen
decl_stmt|;
comment|/* size of address */
name|struct
name|iovec
modifier|*
name|msg_iov
decl_stmt|;
comment|/* scatter/gather array */
name|int
name|msg_iovlen
decl_stmt|;
comment|/* # elements in msg_iov */
name|caddr_t
name|msg_accrights
decl_stmt|;
comment|/* access rights sent/received */
name|int
name|msg_accrightslen
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|accept
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bind
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|connect
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getpeername
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getsockname
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getsockopt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|listen
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|recv
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|recvfrom
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|recvmsg
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|msghdr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|send
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sendto
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|,
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sendmsg
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|msghdr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setsockopt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shutdown
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|socket
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|socketpair
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
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
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SOCKET_H_ */
end_comment

end_unit

