begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: net.h,v 1.34 2002/04/03 06:38:38 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_NET_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_NET_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Basic Networking Types  *  * This module is responsible for defining the following basic networking  * types:  *  *		struct in_addr  *		struct in6_addr  *		struct in6_pktinfo  *		struct sockaddr  *		struct sockaddr_in  *		struct sockaddr_in6  *		in_port_t  *  * It ensures that the AF_ and PF_ macros are defined.  *  * It declares ntoh[sl]() and hton[sl]().  *  * It declares inet_aton(), inet_ntop(), and inet_pton().  *  * It ensures that INADDR_LOOPBACK, INADDR_ANY, IN6ADDR_ANY_INIT,  * in6addr_any, and in6addr_loopback are available.  *  * It ensures that IN_MULTICAST() is available to check for multicast  * addresses.  *  * MP:  *	No impact.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	N/A.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	BSD Socket API  *	RFC 2553  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/platform.h>
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
name|ISC_PLATFORM_NEEDNETINETIN6H
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
name|ISC_PLATFORM_NEEDNETINET6IN6H
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

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_HAVEIPV6
end_ifndef

begin_include
include|#
directive|include
file|<isc/ipv6.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVEINADDR6
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVEIPV6
end_ifdef

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
name|IN6_IS_ADDR_V4MAPPED
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4MAPPED
parameter_list|(
name|x
parameter_list|)
define|\
value|(memcmp((x)->s6_addr, in6addr_any.s6_addr, 10) == 0&& \ 	  (x)->s6_addr[10] == 0xff&& (x)->s6_addr[11] == 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_V4COMPAT
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4COMPAT
parameter_list|(
name|x
parameter_list|)
define|\
value|(memcmp((x)->s6_addr, in6addr_any.s6_addr, 12) == 0&& \ 	 ((x)->s6_addr[12] != 0 || (x)->s6_addr[13] != 0 || \ 	  (x)->s6_addr[14] != 0 || \ 	  ((x)->s6_addr[15] != 0&& (x)->s6_addr[15] != 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_LINKLOCAL
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr[0] == 0xfe)&& (((a)->s6_addr[1]& 0xc0) == 0x80))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_SITELOCAL
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_SITELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr[0] == 0xfe)&& (((a)->s6_addr[1]& 0xc0) == 0xc0))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|x
parameter_list|)
define|\
value|(memcmp((x)->s6_addr, in6addr_loopback.s6_addr, 16) == 0)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_HAVEIN6PKTINFO
end_ifndef

begin_comment
unit|struct in6_pktinfo { 	struct in6_addr ipi6_addr;
comment|/* src/dst IPv6 address */
end_comment

begin_comment
unit|unsigned int    ipi6_ifindex;
comment|/* send/recv interface index */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Cope with a missing in6addr_any and in6addr_loopback.  */
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
name|ISC_PLATFORM_NEEDIN6ADDRANY
argument_list|)
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|isc_net_in6addrany
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|in6addr_any
value|isc_net_in6addrany
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|ISC_PLATFORM_NEEDIN6ADDRLOOPBACK
argument_list|)
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|isc_net_in6addrloop
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|in6addr_loopback
value|isc_net_in6addrloop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Fix UnixWare 7.1.1's broken IN6_IS_ADDR_* definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_FIXIN6ISADDR
end_ifdef

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_GEOGRAPHIC
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_GEOGRAPHIC
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xE0) == 0x80)
end_define

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_IPX
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_IPX
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xFE) == 0x04)
end_define

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_LINKLOCAL
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xC0FF) == 0x80FE)
end_define

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_MULTICAST
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xFF) == 0xFF)
end_define

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_NSAP
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_NSAP
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xFE) == 0x02)
end_define

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_PROVIDER
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_PROVIDER
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xE0) == 0x40)
end_define

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_SITELOCAL
end_undef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_SITELOCAL
parameter_list|(
name|a
parameter_list|)
value|(((a)->S6_un.S6_l[0]& 0xC0FF) == 0xC0FE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_FIXIN6ISADDR */
end_comment

begin_comment
comment|/*  * Ensure type in_port_t is defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDPORTT
end_ifdef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|in_port_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If this system does not have MSG_TRUNC (as returned from recvmsg())  * ISC_PLATFORM_RECVOVERFLOW will be defined.  This will enable the MSG_TRUNC  * faking code in socket.c.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_TRUNC
end_ifndef

begin_define
define|#
directive|define
name|ISC_PLATFORM_RECVOVERFLOW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC__IPADDR
parameter_list|(
name|x
parameter_list|)
value|((isc_uint32_t)htonl((isc_uint32_t)(x)))
end_define

begin_define
define|#
directive|define
name|ISC_IPADDR_ISMULTICAST
parameter_list|(
name|i
parameter_list|)
define|\
value|(((isc_uint32_t)(i)& ISC__IPADDR(0xf0000000)) \ 		 == ISC__IPADDR(0xe0000000))
end_define

begin_comment
comment|/***  *** Functions.  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_net_probeipv4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check if the system's kernel supports IPv4.  *  * Returns:  *  *	ISC_R_SUCCESS		IPv4 is supported.  *	ISC_R_NOTFOUND		IPv4 is not supported.  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_net_probeipv6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check if the system's kernel supports IPv6.  *  * Returns:  *  *	ISC_R_SUCCESS		IPv6 is supported.  *	ISC_R_NOTFOUND		IPv6 is not supported.  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_net_ntop
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDNTOP
end_ifdef

begin_define
define|#
directive|define
name|inet_ntop
value|isc_net_ntop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|isc_net_pton
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDPTON
end_ifdef

begin_undef
undef|#
directive|undef
name|inet_pton
end_undef

begin_define
define|#
directive|define
name|inet_pton
value|isc_net_pton
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|isc_net_aton
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDATON
end_ifdef

begin_define
define|#
directive|define
name|inet_aton
value|isc_net_aton
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_NET_H */
end_comment

end_unit

