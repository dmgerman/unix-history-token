begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982,1985,1986,1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)socket.h	7.9 (Berkeley) %G%  */
end_comment

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
name|AF_UNIX
value|1
end_define

begin_comment
comment|/* local to host (pipes, portals) */
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
comment|/* european computer manufacturers */
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
name|AF_MAX
value|20
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
name|PF_UNIX
value|AF_UNIX
end_define

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
name|PF_MAX
value|AF_MAX
end_define

begin_comment
comment|/*  * Maximum queue length specifiable by listen.  */
end_comment

begin_define
define|#
directive|define
name|SOMAXCONN
value|5
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
comment|/* given pointer to struct adatahdr, return pointer to data */
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
comment|/* given pointer to struct adatahdr, return pointer to next adatahdr */
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

end_unit

