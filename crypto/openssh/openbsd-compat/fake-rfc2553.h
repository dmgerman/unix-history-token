begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: fake-rfc2553.h,v 1.12 2005/08/03 05:36:21 dtucker Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2000-2003 Damien Miller.  All rights reserved.  * Copyright (C) 1999 WIDE Project.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Pseudo-implementation of RFC2553 name / address resolution functions  *  * But these functions are not implemented correctly. The minimum subset  * is implemented for ssh use only. For example, this routine assumes  * that ai_family is AF_INET. Don't use it for another purpose.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FAKE_RFC2553_H
end_ifndef

begin_define
define|#
directive|define
name|_FAKE_RFC2553_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_comment
comment|/*  * First, socket and INET6 related definitions   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_SOCKADDR_STORAGE
end_ifndef

begin_define
define|#
directive|define
name|_SS_MAXSIZE
value|128
end_define

begin_comment
comment|/* Implementation specific max size */
end_comment

begin_define
define|#
directive|define
name|_SS_PADSIZE
value|(_SS_MAXSIZE - sizeof (struct sockaddr))
end_define

begin_struct
struct|struct
name|sockaddr_storage
block|{
name|struct
name|sockaddr
name|ss_sa
decl_stmt|;
name|char
name|__ss_pad2
index|[
name|_SS_PADSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ss_family
value|ss_sa.sa_family
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRUCT_SOCKADDR_STORAGE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
define|\
value|(((u_int32_t *)(a))[0] == 0&& ((u_int32_t *)(a))[1] == 0&& \ 	 ((u_int32_t *)(a))[2] == 0&& ((u_int32_t *)(a))[3] == htonl(1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IN6_IS_ADDR_LOOPBACK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_IN6_ADDR
end_ifndef

begin_struct
struct|struct
name|in6_addr
block|{
name|u_int8_t
name|s6_addr
index|[
literal|16
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
comment|/* !HAVE_STRUCT_IN6_ADDR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_SOCKADDR_IN6
end_ifndef

begin_struct
struct|struct
name|sockaddr_in6
block|{
name|unsigned
name|short
name|sin6_family
decl_stmt|;
name|u_int16_t
name|sin6_port
decl_stmt|;
name|u_int32_t
name|sin6_flowinfo
decl_stmt|;
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRUCT_SOCKADDR_IN6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_comment
comment|/* Define it to something that should never appear */
end_comment

begin_define
define|#
directive|define
name|AF_INET6
value|AF_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Next, RFC2553 name / address resolution API  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_NUMERICHOST
end_ifndef

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NI_NAMEREQD
end_ifndef

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|(1<<1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NI_NUMERICSERV
end_ifndef

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|(1<<2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AI_PASSIVE
end_ifndef

begin_define
define|#
directive|define
name|AI_PASSIVE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AI_CANONNAME
end_ifndef

begin_define
define|#
directive|define
name|AI_CANONNAME
value|(1<<1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AI_NUMERICHOST
end_ifndef

begin_define
define|#
directive|define
name|AI_NUMERICHOST
value|(1<<2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NI_MAXSERV
end_ifndef

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
comment|/* !NI_MAXSERV */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NI_MAXHOST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_NODATA
end_ifndef

begin_define
define|#
directive|define
name|EAI_NODATA
value|(INT_MAX - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_MEMORY
end_ifndef

begin_define
define|#
directive|define
name|EAI_MEMORY
value|(INT_MAX - 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_NONAME
end_ifndef

begin_define
define|#
directive|define
name|EAI_NONAME
value|(INT_MAX - 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|EAI_SYSTEM
value|(INT_MAX - 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_ADDRINFO
end_ifndef

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRUCT_ADDRINFO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETADDRINFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|getaddrinfo
end_ifdef

begin_undef
undef|#
directive|undef
name|getaddrinfo
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getaddrinfo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(ssh_getaddrinfo(a,b,c,d))
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GETADDRINFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GAI_STRERROR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_CONST_GAI_STRERROR_PROTO
argument_list|)
end_if

begin_define
define|#
directive|define
name|gai_strerror
parameter_list|(
name|a
parameter_list|)
value|(ssh_gai_strerror(a))
end_define

begin_function_decl
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GAI_STRERROR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FREEADDRINFO
end_ifndef

begin_define
define|#
directive|define
name|freeaddrinfo
parameter_list|(
name|a
parameter_list|)
value|(ssh_freeaddrinfo(a))
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_FREEADDRINFO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETNAMEINFO
end_ifndef

begin_define
define|#
directive|define
name|getnameinfo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|(ssh_getnameinfo(a,b,c,d,e,f,g))
end_define

begin_function_decl
name|int
name|getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|size_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GETNAMEINFO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FAKE_RFC2553_H */
end_comment

end_unit

