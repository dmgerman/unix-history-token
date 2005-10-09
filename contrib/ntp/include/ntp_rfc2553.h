begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in.h	8.3 (Berkeley) 1/3/94  */
end_comment

begin_comment
comment|/*  * Compatability shims with the rfc2553 API to simplify ntp.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NTP_RFC2553_H_
end_ifndef

begin_define
define|#
directive|define
name|_NTP_RFC2553_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SS_MAXSIZE
argument_list|)
operator|||
name|defined
argument_list|(
name|_SS_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_IPV6
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_define
define|#
directive|define
name|AF_INET6
value|AF_MAX
end_define

begin_define
define|#
directive|define
name|PF_INET6
value|AF_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TYPE_U_INT8_T
end_ifndef

begin_typedef
typedef|typedef
name|u_char
name|u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32
name|u_int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TYPE_U_INT8_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TYPE_U_INT64_T
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|u_int64_t
block|{
name|u_int32
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u_int64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TYPE_U_INT64_T */
end_comment

begin_comment
comment|/*  * IPv6 address  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_define
define|#
directive|define
name|in6_addr
value|in_addr6
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Don't include any additional IPv6 definitions  * We are defining our own here.  */
end_comment

begin_define
define|#
directive|define
name|ISC_IPV6_H
value|1
end_define

begin_struct
struct|struct
name|in6_addr
block|{
union|union
block|{
name|u_int8_t
name|__u6_addr8
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|__u6_addr16
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|__u6_addr32
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__u6_addr
union|;
comment|/* 128-bit IP6 address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|s6_addr
value|__u6_addr.__u6_addr8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definition of some useful macros to handle IP6 addresses  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
define|\
value|{{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_any
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIN6_LEN
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SOCKADDR_IN6
end_ifndef

begin_struct
struct|struct
name|sockaddr_in6
block|{
ifdef|#
directive|ifdef
name|HAVE_SA_LEN_IN_STRUCT_SOCKADDR
name|u_int8_t
name|sin6_len
decl_stmt|;
comment|/* length of this struct(sa_family_t)*/
name|u_int8_t
name|sin6_family
decl_stmt|;
comment|/* AF_INET6 (sa_family_t) */
else|#
directive|else
name|short
name|sin6_family
decl_stmt|;
comment|/* AF_INET6 (sa_family_t) */
endif|#
directive|endif
name|u_int16_t
name|sin6_port
decl_stmt|;
comment|/* Transport layer port # (in_port_t)*/
name|u_int32_t
name|sin6_flowinfo
decl_stmt|;
comment|/* IP6 flow information */
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
comment|/* IP6 address */
name|u_int32_t
name|sin6_scope_id
decl_stmt|;
comment|/* scope zone index */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unspecified  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_UNSPECIFIED
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_UNSPECIFIED
parameter_list|(
name|a
parameter_list|)
define|\
value|((*(const u_int32_t *)(const void *)(&(a)->s6_addr[0]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[4]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[8]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[12]) == 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Multicast  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_MULTICAST
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|((a)->s6_addr[0] == 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * RFC 2553: protocol-independent placeholder for socket addresses  */
end_comment

begin_define
define|#
directive|define
name|_SS_MAXSIZE
value|128
end_define

begin_define
define|#
directive|define
name|_SS_ALIGNSIZE
value|(sizeof(u_int64_t))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SA_LEN_IN_STRUCT_SOCKADDR
end_ifdef

begin_define
define|#
directive|define
name|_SS_PAD1SIZE
value|(_SS_ALIGNSIZE - sizeof(u_char) - sizeof(u_int8_t))
end_define

begin_define
define|#
directive|define
name|_SS_PAD2SIZE
value|(_SS_MAXSIZE - sizeof(u_char) - sizeof(u_int8_t) - \ 				_SS_PAD1SIZE - _SS_ALIGNSIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_SS_PAD1SIZE
value|(_SS_ALIGNSIZE - sizeof(short))
end_define

begin_define
define|#
directive|define
name|_SS_PAD2SIZE
value|(_SS_MAXSIZE - sizeof(short) - \ 				_SS_PAD1SIZE - _SS_ALIGNSIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SA_LEN_IN_STRUCT_SOCKADDR */
end_comment

begin_struct
struct|struct
name|sockaddr_storage
block|{
ifdef|#
directive|ifdef
name|HAVE_SA_LEN_IN_STRUCT_SOCKADDR
name|u_int8_t
name|ss_len
decl_stmt|;
comment|/* address length */
name|u_int8_t
name|ss_family
decl_stmt|;
comment|/* address family */
else|#
directive|else
name|short
name|ss_family
decl_stmt|;
comment|/* address family */
endif|#
directive|endif
name|char
name|__ss_pad1
index|[
name|_SS_PAD1SIZE
index|]
decl_stmt|;
name|u_int64_t
name|__ss_align
decl_stmt|;
comment|/* force desired structure storage alignment */
name|char
name|__ss_pad2
index|[
name|_SS_PAD2SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
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

begin_comment
comment|/*  * Error return codes from getaddrinfo()  */
end_comment

begin_define
define|#
directive|define
name|EAI_ADDRFAMILY
value|1
end_define

begin_comment
comment|/* address family for hostname not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_AGAIN
value|2
end_define

begin_comment
comment|/* temporary failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_BADFLAGS
value|3
end_define

begin_comment
comment|/* invalid value for ai_flags */
end_comment

begin_define
define|#
directive|define
name|EAI_FAIL
value|4
end_define

begin_comment
comment|/* non-recoverable failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_FAMILY
value|5
end_define

begin_comment
comment|/* ai_family not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_MEMORY
value|6
end_define

begin_comment
comment|/* memory allocation failure */
end_comment

begin_define
define|#
directive|define
name|EAI_NODATA
value|7
end_define

begin_comment
comment|/* no address associated with hostname */
end_comment

begin_define
define|#
directive|define
name|EAI_NONAME
value|8
end_define

begin_comment
comment|/* hostname nor servname provided, or not known */
end_comment

begin_define
define|#
directive|define
name|EAI_SERVICE
value|9
end_define

begin_comment
comment|/* servname not supported for ai_socktype */
end_comment

begin_define
define|#
directive|define
name|EAI_SOCKTYPE
value|10
end_define

begin_comment
comment|/* ai_socktype not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_SYSTEM
value|11
end_define

begin_comment
comment|/* system error returned in errno */
end_comment

begin_define
define|#
directive|define
name|EAI_BADHINTS
value|12
end_define

begin_define
define|#
directive|define
name|EAI_PROTOCOL
value|13
end_define

begin_define
define|#
directive|define
name|EAI_MAX
value|14
end_define

begin_comment
comment|/*  * Flag values for getaddrinfo()  */
end_comment

begin_define
define|#
directive|define
name|AI_PASSIVE
value|0x00000001
end_define

begin_comment
comment|/* get address to use bind() */
end_comment

begin_define
define|#
directive|define
name|AI_CANONNAME
value|0x00000002
end_define

begin_comment
comment|/* fill ai_canonname */
end_comment

begin_define
define|#
directive|define
name|AI_NUMERICHOST
value|0x00000004
end_define

begin_comment
comment|/* prevent name resolution */
end_comment

begin_comment
comment|/* valid flags for addrinfo */
end_comment

begin_define
define|#
directive|define
name|AI_MASK
define|\
value|(AI_PASSIVE | AI_CANONNAME | AI_NUMERICHOST | AI_ADDRCONFIG)
end_define

begin_define
define|#
directive|define
name|AI_ADDRCONFIG
value|0x00000400
end_define

begin_comment
comment|/* only if any address is assigned */
end_comment

begin_comment
comment|/*  * Constants for getnameinfo()  */
end_comment

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_define
define|#
directive|define
name|NI_MAXSERV
value|32
end_define

begin_comment
comment|/*  * Flag values for getnameinfo()  */
end_comment

begin_define
define|#
directive|define
name|NI_NOFQDN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NI_DGRAM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NI_WITHSCOPEID
value|0x00000020
end_define

begin_decl_stmt
name|int
name|getaddrinfo
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|addrinfo
operator|*
operator|,
expr|struct
name|addrinfo
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getnameinfo
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
name|u_int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
name|char
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
name|void
name|freeaddrinfo
name|P
argument_list|(
operator|(
expr|struct
name|addrinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gai_strerror
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SS_MAXSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NTP_RFC2553_H_ */
end_comment

end_unit

