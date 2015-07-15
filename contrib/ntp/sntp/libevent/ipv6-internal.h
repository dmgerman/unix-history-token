begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Internal use only: Fake IPv6 structures and values on platforms that  * do not have them */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPV6_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|IPV6_INTERNAL_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|"event2/event-config.h"
end_include

begin_include
include|#
directive|include
file|"evconfig-private.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"event2/util.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/** @file ipv6-internal.h  *  * Replacement types and functions for platforms that don't support ipv6  * properly.  */
ifndef|#
directive|ifndef
name|EVENT__HAVE_STRUCT_IN6_ADDR
struct|struct
name|in6_addr
block|{
name|ev_uint8_t
name|s6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EVENT__HAVE_SA_FAMILY_T
typedef|typedef
name|int
name|sa_family_t
typedef|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EVENT__HAVE_STRUCT_SOCKADDR_IN6
struct|struct
name|sockaddr_in6
block|{
comment|/* This will fail if we find a struct sockaddr that doesn't have 	 * sa_family as the first element. */
name|sa_family_t
name|sin6_family
decl_stmt|;
name|ev_uint16_t
name|sin6_port
decl_stmt|;
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|AF_INET6
define|#
directive|define
name|AF_INET6
value|3333
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PF_INET6
define|#
directive|define
name|PF_INET6
value|AF_INET6
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

