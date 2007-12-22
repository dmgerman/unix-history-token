begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2005  *	Hartmut Brandt.  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/lib/support.h,v 1.2 2005/10/06 07:14:59 brandt_h Exp $  *  * Functions that are missing on certain systems. This header file is not  * to be installed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bsnmp_support_h_
end_ifndef

begin_define
define|#
directive|define
name|bsnmp_support_h_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ERR_H
end_ifndef

begin_decl_stmt
name|void
name|err
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|errx
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|warn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|warnx
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETADDRINFO
end_ifndef

begin_struct
struct|struct
name|addrinfo
block|{
name|u_int
name|ai_flags
decl_stmt|;
name|int
name|ai_family
decl_stmt|;
name|int
name|ai_socktype
decl_stmt|;
name|int
name|ai_protocol
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
name|int
name|ai_addrlen
decl_stmt|;
name|struct
name|addrinfo
modifier|*
name|ai_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AI_CANONNAME
value|0x0001
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
specifier|const
name|char
modifier|*
name|gai_strerror
parameter_list|(
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For systems with missing stdint.h or inttypes.h  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INT32_MIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT32_MIN
value|(-0x7fffffff-1)
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
name|INT32_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT32_MAX
value|(0x7fffffff)
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
name|UINT32_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT32_MAX
value|(0xffffffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Systems missing SA_SIZE(). Taken from FreeBSD net/route.h:1.63  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SA_SIZE
end_ifndef

begin_define
define|#
directive|define
name|SA_SIZE
parameter_list|(
name|sa
parameter_list|)
define|\
value|(  (!(sa) || ((struct sockaddr *)(sa))->sa_len == 0) ?	\ 	sizeof(long)		:				\ 	1 + ( (((struct sockaddr *)(sa))->sa_len - 1) | (sizeof(long) - 1) ) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

