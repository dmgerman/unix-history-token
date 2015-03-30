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
name|NTP_RFC2553_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_RFC2553_H
end_define

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_function_decl
name|struct
name|addrinfo
modifier|*
name|copy_addrinfo_impl
parameter_list|(
specifier|const
name|struct
name|addrinfo
modifier|*
ifdef|#
directive|ifdef
name|EREALLOC_CALLSITE
comment|/* from ntp_malloc.h */
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|addrinfo
modifier|*
name|copy_addrinfo_list_impl
parameter_list|(
specifier|const
name|struct
name|addrinfo
modifier|*
ifdef|#
directive|ifdef
name|EREALLOC_CALLSITE
comment|/* from ntp_malloc.h */
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|EREALLOC_CALLSITE
end_ifdef

begin_define
define|#
directive|define
name|copy_addrinfo
parameter_list|(
name|l
parameter_list|)
define|\
value|copy_addrinfo_impl((l), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|copy_addrinfo_list
parameter_list|(
name|l
parameter_list|)
define|\
value|copy_addrinfo_list_impl((l), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copy_addrinfo
parameter_list|(
name|l
parameter_list|)
value|copy_addrinfo_impl(l)
end_define

begin_define
define|#
directive|define
name|copy_addrinfo_list
parameter_list|(
name|l
parameter_list|)
value|copy_addrinfo_list_impl(l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If various macros are not defined we need to define them  */
end_comment

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_SS_MAXSIZE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SS_ALIGNSIZE
argument_list|)
end_if

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
value|(sizeof(ntp_uint64_t))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVESALEN
end_ifdef

begin_define
define|#
directive|define
name|_SS_PAD1SIZE
value|(_SS_ALIGNSIZE - sizeof(u_char) - sizeof(ntp_u_int8_t))
end_define

begin_define
define|#
directive|define
name|_SS_PAD2SIZE
value|(_SS_MAXSIZE - sizeof(u_char) - sizeof(ntp_u_int8_t) - \ 				_SS_PAD1SIZE - _SS_ALIGNSIZE)
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
comment|/* ISC_PLATFORM_HAVESALEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_comment
comment|/* max len of IPv6 addr in ascii */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If we don't have the sockaddr_storage structure  * we need to define it  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_SOCKADDR_STORAGE
end_ifndef

begin_struct
struct|struct
name|sockaddr_storage
block|{
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVESALEN
name|ntp_u_int8_t
name|ss_len
decl_stmt|;
comment|/* address length */
name|ntp_u_int8_t
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
name|ntp_uint64_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Finally if the platform doesn't support IPv6 we need some  * additional definitions  */
end_comment

begin_comment
comment|/*  * Flag values for getaddrinfo()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AI_PASSIVE
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !AI_PASSIVE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AI_NUMERICHOST
end_ifndef

begin_comment
comment|/* such as AIX 4.3 */
end_comment

begin_define
define|#
directive|define
name|Z_AI_NUMERICHOST
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Z_AI_NUMERICHOST
value|AI_NUMERICHOST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AI_NUMERICSERV
end_ifndef

begin_comment
comment|/* not in RFC 2553 */
end_comment

begin_define
define|#
directive|define
name|Z_AI_NUMERICSERV
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Z_AI_NUMERICSERV
value|AI_NUMERICSERV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_HAVEIPV6
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|int
name|getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|,
name|struct
name|addrinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeaddrinfo
parameter_list|(
name|struct
name|addrinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Constants for getnameinfo()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_MAXHOST
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flag values for getnameinfo()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_NUMERICHOST
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ISC_PLATFORM_HAVEIPV6 */
end_comment

begin_comment
comment|/*   * Set up some macros to look for IPv6 and IPv6 multicast  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ISC_PLATFORM_HAVEIPV6
argument_list|)
operator|&&
name|defined
argument_list|(
name|WANT_IPV6
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCLUDE_IPV6_SUPPORT
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPV6_JOIN_GROUP
argument_list|)
operator|&&
name|defined
argument_list|(
name|IPV6_LEAVE_GROUP
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCLUDE_IPV6_MULTICAST_SUPPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPV6 Multicast Support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPv6 Support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NTP_RFC2553_H */
end_comment

end_unit

