begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: net.h,v 1.3.12.3 2004/03/08 09:05:12 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_NET_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_NET_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Basic Networking Types  *  * This module is responsible for defining the following basic networking  * types:  *  *		struct in_addr  *		struct in6_addr  *		struct sockaddr  *		struct sockaddr_in  *		struct sockaddr_in6  *  * It ensures that the AF_ and PF_ macros are defined.  *  * It declares ntoh[sl]() and hton[sl]().  *  * It declares lwres_net_aton(), lwres_net_ntop(), and lwres_net_pton().  *  * It ensures that INADDR_LOOPBACK, INADDR_ANY and IN6ADDR_ANY_INIT  * are defined.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<lwres/platform.h>
end_include

begin_comment
comment|/* Required for LWRES_PLATFORM_*. */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LWRES_PLATFORM_NEEDNETINETIN6H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in6.h>
end_include

begin_comment
comment|/* Required on UnixWare. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LWRES_PLATFORM_NEEDNETINET6IN6H
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/in6.h>
end_include

begin_comment
comment|/* Required on BSD/OS for in6_pktinfo. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<lwres/lang.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_PLATFORM_HAVEIPV6
end_ifndef

begin_include
include|#
directive|include
file|<lwres/ipv6.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LWRES_PLATFORM_HAVEINADDR6
end_ifdef

begin_define
define|#
directive|define
name|in6_addr
value|in_addr6
end_define

begin_comment
comment|/* Required for pre RFC2133 implementations. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Required for some pre RFC2133 implementations.  * IN6ADDR_ANY_INIT and IN6ADDR_LOOPBACK_INIT were added in  * draft-ietf-ipngwg-bsd-api-04.txt or draft-ietf-ipngwg-bsd-api-05.txt.    * If 's6_addr' is defined then assume that there is a union and three  * levels otherwise assume two levels required.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_ANY_INIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|s6_addr
end_ifdef

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{ { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_LOOPBACK_INIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|s6_addr
end_ifdef

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{ { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_define
define|#
directive|define
name|AF_INET6
value|99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PF_INET6
end_ifndef

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
name|INADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|0x7f000001UL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|LWRES_LANG_BEGINDECLS
specifier|const
name|char
modifier|*
name|lwres_net_ntop
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lwres_net_pton
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lwres_net_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|LWRES_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_NET_H */
end_comment

end_unit

