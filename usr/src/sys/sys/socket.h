begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	socket.h	6.1	83/07/29	*/
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
value|0x01
end_define

begin_comment
comment|/* turn on debugging info recording */
end_comment

begin_define
define|#
directive|define
name|SO_ACCEPTCONN
value|0x02
end_define

begin_comment
comment|/* socket has had listen() */
end_comment

begin_define
define|#
directive|define
name|SO_REUSEADDR
value|0x04
end_define

begin_comment
comment|/* allow local address reuse */
end_comment

begin_define
define|#
directive|define
name|SO_KEEPALIVE
value|0x08
end_define

begin_comment
comment|/* keep connections alive */
end_comment

begin_define
define|#
directive|define
name|SO_DONTROUTE
value|0x10
end_define

begin_comment
comment|/* just use interface addresses */
end_comment

begin_comment
comment|/* 0x20 was SO_NEWFDONCONN */
end_comment

begin_define
define|#
directive|define
name|SO_USELOOPBACK
value|0x40
end_define

begin_comment
comment|/* bypass hardware when possible */
end_comment

begin_define
define|#
directive|define
name|SO_LINGER
value|0x80
end_define

begin_comment
comment|/* linger on close if data present */
end_comment

begin_define
define|#
directive|define
name|SO_DONTLINGER
value|(~SO_LINGER)
end_define

begin_comment
comment|/* ~SO_LINGER */
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
name|AF_NBS
value|7
end_define

begin_comment
comment|/* nbs protocols */
end_comment

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
name|AF_MAX
value|12
end_define

begin_comment
comment|/*  * Structure used by kernel to store most  * addresses.  */
end_comment

begin_struct
struct|struct
name|sockaddr
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
name|PF_NBS
value|AF_NBS
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
name|PF_MAX
value|12
end_define

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
comment|/*  * Maximum queue length specifiable by listen.  */
end_comment

begin_define
define|#
directive|define
name|SOMAXCONN
value|5
end_define

begin_comment
comment|/*  * Message header for recvmsg and sendmsg calls.  */
end_comment

begin_struct
struct|struct
name|msghdr
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
name|MSG_MAXIOVLEN
value|16
end_define

end_unit

