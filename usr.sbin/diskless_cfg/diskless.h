begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982,1985,1986,1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socket.h	7.13 (Berkeley) 4/20/91  */
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

begin_define
define|#
directive|define
name|IFNAMSIZ
value|16
end_define

begin_struct
struct|struct
name|ifaliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr
name|ifra_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifra_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * File Handle (32 bytes for version 2), variable up to 1024 for version 3  */
end_comment

begin_define
define|#
directive|define
name|NFS_FHSIZE
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|f
index|[
name|NFS_FHSIZE
index|]
block|}
name|nfsv2fh_t
typedef|;
end_typedef

begin_comment
comment|/*  * Arguments to mount NFS  */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|int
name|sotype
decl_stmt|;
comment|/* Socket type */
name|int
name|proto
decl_stmt|;
comment|/* and Protocol */
name|nfsv2fh_t
modifier|*
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|int
name|wsize
decl_stmt|;
comment|/* write size in bytes */
name|int
name|rsize
decl_stmt|;
comment|/* read size in bytes */
name|int
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS mount option flags  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SOFT
value|0x0001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x0002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x0004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x0008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x0010
end_define

begin_comment
comment|/* set number of request retrys */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HOSTNAME
value|0x0020
end_define

begin_comment
comment|/* set hostname for error printf */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x0040
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCONN
value|0x0080
end_define

begin_comment
comment|/* Don't Connect the socket */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SCKLOCK
value|0x0100
end_define

begin_comment
comment|/* Lock socket against others */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTSCK
value|0x0200
end_define

begin_comment
comment|/* Want a socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SPONGY
value|0x0400
end_define

begin_comment
comment|/* spongy mount (soft for stat and lookup) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_COMPRESS
value|0x0800
end_define

begin_comment
comment|/* Compress nfs rpc xdr */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_LOCKBITS
value|(NFSMNT_SCKLOCK | NFSMNT_WANTSCK)
end_define

end_unit

