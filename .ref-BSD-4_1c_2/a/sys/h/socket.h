begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	socket.h	4.25	83/01/22	*/
end_comment

begin_comment
comment|/*  * Externally visible attributes of sockets.  */
end_comment

begin_comment
comment|/*  * Socket types.  *  * The kernel implement these abstract (session-layer) socket  * services, with extra protocol on top of network services  * if necessary.  */
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
comment|/* willing to accept connections */
end_comment

begin_define
define|#
directive|define
name|SO_REUSEADDR
value|0x04
end_define

begin_comment
comment|/* allow local address reuse (gag) */
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

begin_define
define|#
directive|define
name|SO_NEWFDONCONN
value|0x20
end_define

begin_comment
comment|/* give new fd on connection */
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
comment|/*  * Generic socket protocol format.  *  * Each process is normally operating in a protocol family,  * whose protocols are used unless the process specifies otherwise.  * Most families supply protocols to the basic socket types.  When  * protocols are not present in the family, the higher level (roughly  * ISO session layer) code in the system layers on the protocols  * to support the socket types.  */
end_comment

begin_struct
struct|struct
name|sockproto
block|{
name|short
name|sp_family
decl_stmt|;
comment|/* protocol family */
name|short
name|sp_protocol
decl_stmt|;
comment|/* protocol within family */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PF_UNSPEC
value|0
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_define
define|#
directive|define
name|PF_UNIX
value|1
end_define

begin_comment
comment|/* UNIX internal protocol */
end_comment

begin_define
define|#
directive|define
name|PF_INET
value|2
end_define

begin_comment
comment|/* internetwork: UDP, TCP, etc. */
end_comment

begin_define
define|#
directive|define
name|PF_IMPLINK
value|3
end_define

begin_comment
comment|/* imp link protocols */
end_comment

begin_define
define|#
directive|define
name|PF_PUP
value|4
end_define

begin_comment
comment|/* pup protocols: e.g. BSP */
end_comment

begin_define
define|#
directive|define
name|PF_CHAOS
value|5
end_define

begin_comment
comment|/* mit CHAOS protocols */
end_comment

begin_define
define|#
directive|define
name|PF_OISCP
value|6
end_define

begin_comment
comment|/* ois communication protocols */
end_comment

begin_define
define|#
directive|define
name|PF_NBS
value|7
end_define

begin_comment
comment|/* nbs protocols */
end_comment

begin_define
define|#
directive|define
name|PF_ECMA
value|8
end_define

begin_comment
comment|/* european computer manufacturers */
end_comment

begin_define
define|#
directive|define
name|PF_DATAKIT
value|9
end_define

begin_comment
comment|/* datakit protocols */
end_comment

begin_define
define|#
directive|define
name|PF_CCITT
value|10
end_define

begin_comment
comment|/* CCITT protocols, X.25 etc */
end_comment

begin_comment
comment|/*  * Generic socket address format.  *  * Each process is also operating in an address family, whose  * addresses are assigned unless otherwise requested.  The address  * family used affects address properties: whether addresses are  * externalized or internalized, location dependent or independent, etc.  * The address can be defined directly if it fits in 14 bytes, or  * a pointer and length can be given to variable length data.  * We give these as two different structures to allow initialization.  */
end_comment

begin_struct
struct|struct
name|sockaddr
block|{
name|short
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
comment|/*  * The first few address families correspond to protocol  * families.  Address families unrelated to protocol families  * are also possible.  */
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
name|AF_OISCP
value|6
end_define

begin_comment
comment|/* ois communication protocols */
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
name|AF_MAX
value|11
end_define

begin_define
define|#
directive|define
name|SOL_SOCKET
value|0xffff
end_define

begin_comment
comment|/* options for socket level */
end_comment

begin_define
define|#
directive|define
name|SOF_OOB
value|0x1
end_define

begin_comment
comment|/* send/recv out-of-band data */
end_comment

begin_define
define|#
directive|define
name|SOF_PREVIEW
value|0x2
end_define

begin_comment
comment|/* look at data, but don't read */
end_comment

begin_define
define|#
directive|define
name|SOF_DONTROUTE
value|0x4
end_define

begin_comment
comment|/* send without routing data */
end_comment

end_unit

