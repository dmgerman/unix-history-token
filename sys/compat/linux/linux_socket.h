begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Assar Westerlund  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SOCKET_H_
end_define

begin_comment
comment|/* msg flags in recvfrom/recvmsg */
end_comment

begin_define
define|#
directive|define
name|LINUX_MSG_OOB
value|0x01
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_PEEK
value|0x02
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_DONTROUTE
value|0x04
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_CTRUNC
value|0x08
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_PROXY
value|0x10
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_TRUNC
value|0x20
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_DONTWAIT
value|0x40
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_EOR
value|0x80
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_WAITALL
value|0x100
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_FIN
value|0x200
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_SYN
value|0x400
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_CONFIRM
value|0x800
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_RST
value|0x1000
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_ERRQUEUE
value|0x2000
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_NOSIGNAL
value|0x4000
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_WAITFORONE
value|0x10000
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_CMSG_CLOEXEC
value|0x40000000
end_define

begin_comment
comment|/* Socket-level control message types */
end_comment

begin_define
define|#
directive|define
name|LINUX_SCM_RIGHTS
value|0x01
end_define

begin_define
define|#
directive|define
name|LINUX_SCM_CREDENTIALS
value|0x02
end_define

begin_define
define|#
directive|define
name|LINUX_SCM_TIMESTAMP
value|0x1D
end_define

begin_struct
struct|struct
name|l_msghdr
block|{
name|l_uintptr_t
name|msg_name
decl_stmt|;
name|l_int
name|msg_namelen
decl_stmt|;
name|l_uintptr_t
name|msg_iov
decl_stmt|;
name|l_size_t
name|msg_iovlen
decl_stmt|;
name|l_uintptr_t
name|msg_control
decl_stmt|;
name|l_size_t
name|msg_controllen
decl_stmt|;
name|l_uint
name|msg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_mmsghdr
block|{
name|struct
name|l_msghdr
name|msg_hdr
decl_stmt|;
name|l_uint
name|msg_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_cmsghdr
block|{
name|l_size_t
name|cmsg_len
decl_stmt|;
name|l_int
name|cmsg_level
decl_stmt|;
name|l_int
name|cmsg_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Ancillary data object information macros */
end_comment

begin_define
define|#
directive|define
name|LINUX_CMSG_ALIGN
parameter_list|(
name|len
parameter_list|)
value|roundup2(len, sizeof(l_ulong))
end_define

begin_define
define|#
directive|define
name|LINUX_CMSG_DATA
parameter_list|(
name|cmsg
parameter_list|)
value|((void *)((char *)(cmsg) + \ 				    LINUX_CMSG_ALIGN(sizeof(struct l_cmsghdr))))
end_define

begin_define
define|#
directive|define
name|LINUX_CMSG_SPACE
parameter_list|(
name|len
parameter_list|)
value|(LINUX_CMSG_ALIGN(sizeof(struct l_cmsghdr)) + \ 				    LINUX_CMSG_ALIGN(len))
end_define

begin_define
define|#
directive|define
name|LINUX_CMSG_LEN
parameter_list|(
name|len
parameter_list|)
value|(LINUX_CMSG_ALIGN(sizeof(struct l_cmsghdr)) + \ 				    (len))
end_define

begin_define
define|#
directive|define
name|LINUX_CMSG_FIRSTHDR
parameter_list|(
name|msg
parameter_list|)
define|\
value|((msg)->msg_controllen>= \ 				    sizeof(struct l_cmsghdr) ? \ 				    (struct l_cmsghdr *) \ 				        PTRIN((msg)->msg_control) : \ 				    (struct l_cmsghdr *)(NULL))
end_define

begin_define
define|#
directive|define
name|LINUX_CMSG_NXTHDR
parameter_list|(
name|msg
parameter_list|,
name|cmsg
parameter_list|)
define|\
value|((((char *)(cmsg) + \ 				    LINUX_CMSG_ALIGN((cmsg)->cmsg_len) + \ 				    sizeof(*(cmsg)))> \ 				    (((char *)PTRIN((msg)->msg_control)) + \ 				    (msg)->msg_controllen)) ? \ 				    (struct l_cmsghdr *) NULL : \ 				    (struct l_cmsghdr *)((char *)(cmsg) + \ 				    LINUX_CMSG_ALIGN((cmsg)->cmsg_len)))
end_define

begin_define
define|#
directive|define
name|CMSG_HDRSZ
value|CMSG_LEN(0)
end_define

begin_define
define|#
directive|define
name|L_CMSG_HDRSZ
value|LINUX_CMSG_LEN(0)
end_define

begin_comment
comment|/* Supported address families */
end_comment

begin_define
define|#
directive|define
name|LINUX_AF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_AF_UNIX
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_AF_INET
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_AF_AX25
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_AF_IPX
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_AF_APPLETALK
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_AF_INET6
value|10
end_define

begin_comment
comment|/* Supported socket types */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOCK_STREAM
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_DGRAM
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_RAW
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_RDM
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_SEQPACKET
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_MAX
value|LINUX_SOCK_SEQPACKET
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_TYPE_MASK
value|0xf
end_define

begin_comment
comment|/* Flags for socket, socketpair, accept4 */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOCK_CLOEXEC
value|LINUX_O_CLOEXEC
end_define

begin_define
define|#
directive|define
name|LINUX_SOCK_NONBLOCK
value|LINUX_O_NONBLOCK
end_define

begin_struct
struct|struct
name|l_ucred
block|{
name|uint32_t
name|pid
decl_stmt|;
name|uint32_t
name|uid
decl_stmt|;
name|uint32_t
name|gid
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
operator|)
end_if

begin_struct
struct|struct
name|linux_accept_args
block|{
name|register_t
name|s
decl_stmt|;
name|register_t
name|addr
decl_stmt|;
name|register_t
name|namelen
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|linux_accept
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|linux_accept_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operations for socketcall */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_BIND
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_CONNECT
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_LISTEN
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_ACCEPT
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_GETSOCKNAME
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_GETPEERNAME
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SOCKETPAIR
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SEND
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_RECV
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SENDTO
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_RECVFROM
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHUTDOWN
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SETSOCKOPT
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_GETSOCKOPT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SENDMSG
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_RECVMSG
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_ACCEPT4
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_RECVMMSG
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_SENDMMSG
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ || (__amd64__&& COMPAT_LINUX32) */
end_comment

begin_comment
comment|/* Socket defines */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOL_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IP
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_TCP
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_UDP
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IPV6
value|41
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IPX
value|256
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_AX25
value|257
end_define

begin_define
define|#
directive|define
name|LINUX_SO_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SO_REUSEADDR
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SO_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SO_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SO_DONTROUTE
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SO_BROADCAST
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SO_SNDBUF
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SO_RCVBUF
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SO_KEEPALIVE
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_SO_OOBINLINE
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SO_NO_CHECK
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SO_PRIORITY
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SO_LINGER
value|13
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_SO_PASSCRED
end_ifndef

begin_comment
comment|/* powerpc differs */
end_comment

begin_define
define|#
directive|define
name|LINUX_SO_PASSCRED
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_SO_PEERCRED
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SO_RCVLOWAT
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_SO_SNDLOWAT
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_SO_RCVTIMEO
value|20
end_define

begin_define
define|#
directive|define
name|LINUX_SO_SNDTIMEO
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINUX_SO_TIMESTAMP
value|29
end_define

begin_define
define|#
directive|define
name|LINUX_SO_ACCEPTCONN
value|30
end_define

begin_comment
comment|/* Socket options */
end_comment

begin_define
define|#
directive|define
name|LINUX_IP_TOS
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_IP_TTL
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_IP_HDRINCL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_IP_OPTIONS
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_IP_MULTICAST_IF
value|32
end_define

begin_define
define|#
directive|define
name|LINUX_IP_MULTICAST_TTL
value|33
end_define

begin_define
define|#
directive|define
name|LINUX_IP_MULTICAST_LOOP
value|34
end_define

begin_define
define|#
directive|define
name|LINUX_IP_ADD_MEMBERSHIP
value|35
end_define

begin_define
define|#
directive|define
name|LINUX_IP_DROP_MEMBERSHIP
value|36
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_CHECKSUM
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_NEXTHOP
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_UNICAST_HOPS
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_MULTICAST_IF
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_MULTICAST_HOPS
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_MULTICAST_LOOP
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_ADD_MEMBERSHIP
value|20
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_DROP_MEMBERSHIP
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_V6ONLY
value|26
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RECVPKTINFO
value|49
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_PKTINFO
value|50
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RECVHOPLIMIT
value|51
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_HOPLIMIT
value|52
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RECVHOPOPTS
value|53
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_HOPOPTS
value|54
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RTHDRDSTOPTS
value|55
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RECVRTHDR
value|56
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RTHDR
value|57
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RECVDSTOPTS
value|58
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_DSTOPTS
value|59
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_RECVPATHMTU
value|60
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_PATHMTU
value|61
end_define

begin_define
define|#
directive|define
name|LINUX_IPV6_DONTFRAG
value|62
end_define

begin_define
define|#
directive|define
name|LINUX_TCP_NODELAY
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_TCP_MAXSEG
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_TCP_KEEPIDLE
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_TCP_KEEPINTVL
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_TCP_KEEPCNT
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_TCP_MD5SIG
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SOCKET_H_ */
end_comment

end_unit

