begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2008, 2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * Also define LWRES_IPV6_H to keep it from being included if liblwres is  * being used, or redefinition errors will occur.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_IPV6_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Basic Networking Types  *  * This module is responsible for defining the following basic networking  * types:  *  *		struct in_addr  *		struct in6_addr  *		struct in6_pktinfo  *		struct sockaddr  *		struct sockaddr_in  *		struct sockaddr_in6  *		in_port_t  *  * It ensures that the AF_ and PF_ macros are defined.  *  * It declares ntoh[sl]() and hton[sl]().  *  * It declares inet_aton(), inet_ntop(), and inet_pton().  *  * It ensures that INADDR_ANY, IN6ADDR_ANY_INIT, in6addr_any, and  * in6addr_loopback are available.  *  * It ensures that IN_MULTICAST() is available to check for multicast  * addresses.  *  * MP:  *	No impact.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	N/A.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	BSD Socket API  *	RFC2553  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_comment
comment|/*  * Because of some sort of problem in the MS header files, this cannot  * be simple "#include<winsock2.h>", because winsock2.h tries to include  * windows.h, which then generates an error out of mswsock.h.  _You_  * figure it out.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINSOCKAPI_
end_ifndef

begin_define
define|#
directive|define
name|_WINSOCKAPI_
end_define

begin_comment
comment|/* Prevent inclusion of winsock.h in windows.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_include
include|#
directive|include
file|<isc/ipv6.h>
end_include

begin_comment
comment|/*  * This is here because named client, interfacemgr.c, etc. use the name as  * a variable  */
end_comment

begin_undef
undef|#
directive|undef
name|interface
end_undef

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

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_HAVEIN6PKTINFO
end_ifndef

begin_struct
struct|struct
name|in6_pktinfo
block|{
name|struct
name|in6_addr
name|ipi6_addr
decl_stmt|;
comment|/* src/dst IPv6 address */
name|unsigned
name|int
name|ipi6_ifindex
decl_stmt|;
comment|/* send/recv interface index */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1300
end_if

begin_define
define|#
directive|define
name|in6addr_any
value|isc_net_in6addrany
end_define

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

begin_define
define|#
directive|define
name|ISC_IPADDR_ISEXPERIMENTAL
parameter_list|(
name|i
parameter_list|)
define|\
value|(((isc_uint32_t)(i)& ISC__IPADDR(0xf0000000)) \ 		 == ISC__IPADDR(0xf0000000))
end_define

begin_comment
comment|/*  * Fix the FD_SET and FD_CLR Macros to properly cast  */
end_comment

begin_undef
undef|#
directive|undef
name|FD_CLR
end_undef

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|fd
parameter_list|,
name|set
parameter_list|)
value|do { \     u_int __i; \     for (__i = 0; __i< ((fd_set FAR *)(set))->fd_count; __i++) { \ 	if (((fd_set FAR *)(set))->fd_array[__i] == (SOCKET) fd) { \ 	    while (__i< ((fd_set FAR *)(set))->fd_count-1) { \ 		((fd_set FAR *)(set))->fd_array[__i] = \ 		    ((fd_set FAR *)(set))->fd_array[__i+1]; \ 		__i++; \ 	    } \ 	    ((fd_set FAR *)(set))->fd_count--; \ 	    break; \ 	} \     } \ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|FD_SET
end_undef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|fd
parameter_list|,
name|set
parameter_list|)
value|do { \     u_int __i; \     for (__i = 0; __i< ((fd_set FAR *)(set))->fd_count; __i++) { \ 	if (((fd_set FAR *)(set))->fd_array[__i] == (SOCKET)(fd)) { \ 	    break; \ 	} \     } \     if (__i == ((fd_set FAR *)(set))->fd_count) { \ 	if (((fd_set FAR *)(set))->fd_count< FD_SETSIZE) { \ 	    ((fd_set FAR *)(set))->fd_array[__i] = (SOCKET)(fd); \ 	    ((fd_set FAR *)(set))->fd_count++; \ 	} \     } \ } while (0)
end_define

begin_comment
comment|/*  * Windows Sockets errors redefined as regular Berkeley error constants.  * These are usually commented out in Windows NT to avoid conflicts with errno.h.  * Use the WSA constants instead.  * Starting with VC9 (VC++ 2010) many of these are defined incompatibly  * by errno.h -- #undef the conflicting values, which are not relevant to  * Win32.  */
end_comment

begin_undef
undef|#
directive|undef
name|EWOULDBLOCK
end_undef

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|WSAEWOULDBLOCK
end_define

begin_undef
undef|#
directive|undef
name|EINPROGRESS
end_undef

begin_define
define|#
directive|define
name|EINPROGRESS
value|WSAEINPROGRESS
end_define

begin_undef
undef|#
directive|undef
name|EALREADY
end_undef

begin_define
define|#
directive|define
name|EALREADY
value|WSAEALREADY
end_define

begin_undef
undef|#
directive|undef
name|ENOTSOCK
end_undef

begin_define
define|#
directive|define
name|ENOTSOCK
value|WSAENOTSOCK
end_define

begin_undef
undef|#
directive|undef
name|EDESTADDRREQ
end_undef

begin_define
define|#
directive|define
name|EDESTADDRREQ
value|WSAEDESTADDRREQ
end_define

begin_undef
undef|#
directive|undef
name|EMSGSIZE
end_undef

begin_define
define|#
directive|define
name|EMSGSIZE
value|WSAEMSGSIZE
end_define

begin_undef
undef|#
directive|undef
name|EPROTOTYPE
end_undef

begin_define
define|#
directive|define
name|EPROTOTYPE
value|WSAEPROTOTYPE
end_define

begin_undef
undef|#
directive|undef
name|ENOPROTOOPT
end_undef

begin_define
define|#
directive|define
name|ENOPROTOOPT
value|WSAENOPROTOOPT
end_define

begin_undef
undef|#
directive|undef
name|EPROTONOSUPPORT
end_undef

begin_define
define|#
directive|define
name|EPROTONOSUPPORT
value|WSAEPROTONOSUPPORT
end_define

begin_define
define|#
directive|define
name|ESOCKTNOSUPPORT
value|WSAESOCKTNOSUPPORT
end_define

begin_undef
undef|#
directive|undef
name|EOPNOTSUPP
end_undef

begin_define
define|#
directive|define
name|EOPNOTSUPP
value|WSAEOPNOTSUPP
end_define

begin_define
define|#
directive|define
name|EPFNOSUPPORT
value|WSAEPFNOSUPPORT
end_define

begin_undef
undef|#
directive|undef
name|EAFNOSUPPORT
end_undef

begin_define
define|#
directive|define
name|EAFNOSUPPORT
value|WSAEAFNOSUPPORT
end_define

begin_undef
undef|#
directive|undef
name|EADDRINUSE
end_undef

begin_define
define|#
directive|define
name|EADDRINUSE
value|WSAEADDRINUSE
end_define

begin_undef
undef|#
directive|undef
name|EADDRNOTAVAIL
end_undef

begin_define
define|#
directive|define
name|EADDRNOTAVAIL
value|WSAEADDRNOTAVAIL
end_define

begin_undef
undef|#
directive|undef
name|ENETDOWN
end_undef

begin_define
define|#
directive|define
name|ENETDOWN
value|WSAENETDOWN
end_define

begin_undef
undef|#
directive|undef
name|ENETUNREACH
end_undef

begin_define
define|#
directive|define
name|ENETUNREACH
value|WSAENETUNREACH
end_define

begin_undef
undef|#
directive|undef
name|ENETRESET
end_undef

begin_define
define|#
directive|define
name|ENETRESET
value|WSAENETRESET
end_define

begin_undef
undef|#
directive|undef
name|ECONNABORTED
end_undef

begin_define
define|#
directive|define
name|ECONNABORTED
value|WSAECONNABORTED
end_define

begin_undef
undef|#
directive|undef
name|ECONNRESET
end_undef

begin_define
define|#
directive|define
name|ECONNRESET
value|WSAECONNRESET
end_define

begin_undef
undef|#
directive|undef
name|ENOBUFS
end_undef

begin_define
define|#
directive|define
name|ENOBUFS
value|WSAENOBUFS
end_define

begin_undef
undef|#
directive|undef
name|EISCONN
end_undef

begin_define
define|#
directive|define
name|EISCONN
value|WSAEISCONN
end_define

begin_undef
undef|#
directive|undef
name|ENOTCONN
end_undef

begin_define
define|#
directive|define
name|ENOTCONN
value|WSAENOTCONN
end_define

begin_define
define|#
directive|define
name|ESHUTDOWN
value|WSAESHUTDOWN
end_define

begin_define
define|#
directive|define
name|ETOOMANYREFS
value|WSAETOOMANYREFS
end_define

begin_undef
undef|#
directive|undef
name|ETIMEDOUT
end_undef

begin_define
define|#
directive|define
name|ETIMEDOUT
value|WSAETIMEDOUT
end_define

begin_undef
undef|#
directive|undef
name|ECONNREFUSED
end_undef

begin_define
define|#
directive|define
name|ECONNREFUSED
value|WSAECONNREFUSED
end_define

begin_undef
undef|#
directive|undef
name|ELOOP
end_undef

begin_define
define|#
directive|define
name|ELOOP
value|WSAELOOP
end_define

begin_define
define|#
directive|define
name|EHOSTDOWN
value|WSAEHOSTDOWN
end_define

begin_undef
undef|#
directive|undef
name|EHOSTUNREACH
end_undef

begin_define
define|#
directive|define
name|EHOSTUNREACH
value|WSAEHOSTUNREACH
end_define

begin_define
define|#
directive|define
name|EPROCLIM
value|WSAEPROCLIM
end_define

begin_define
define|#
directive|define
name|EUSERS
value|WSAEUSERS
end_define

begin_define
define|#
directive|define
name|EDQUOT
value|WSAEDQUOT
end_define

begin_define
define|#
directive|define
name|ESTALE
value|WSAESTALE
end_define

begin_define
define|#
directive|define
name|EREMOTE
value|WSAEREMOTE
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
comment|/*  * Check if the system's kernel supports IPv4.  *  * Returns:  *  *	ISC_R_SUCCESS		IPv4 is supported.  *	ISC_R_NOTFOUND		IPv4 is not supported.  *	ISC_R_DISABLED		IPv4 is disabled.  *	ISC_R_UNEXPECTED  */
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
comment|/*  * Check if the system's kernel supports IPv6.  *  * Returns:  *  *	ISC_R_SUCCESS		IPv6 is supported.  *	ISC_R_NOTFOUND		IPv6 is not supported.  *	ISC_R_DISABLED		IPv6 is disabled.  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_net_probeunix
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check if UNIX domain sockets are supported.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_net_probe_ipv6only
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check if the system's kernel supports the IPV6_V6ONLY socket option.  *  * Returns:  *  *	ISC_R_SUCCESS		the option is supported for both TCP and UDP.  *	ISC_R_NOTFOUND		IPv6 itself or the option is not supported.  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_net_probe_ipv6pktinfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check if the system's kernel supports the IPV6_(RECV)PKTINFO socket option  * for UDP sockets.  *  * Returns:  *  *	ISC_R_SUCCESS		the option is supported.  *	ISC_R_NOTFOUND		IPv6 itself or the option is not supported.  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|isc_net_disableipv4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_net_disableipv6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_net_enableipv4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_net_enableipv6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_net_getudpportrange
parameter_list|(
name|int
name|af
parameter_list|,
name|in_port_t
modifier|*
name|low
parameter_list|,
name|in_port_t
modifier|*
name|high
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns system's default range of ephemeral UDP ports, if defined.  * If the range is not available or unknown, ISC_NET_PORTRANGELOW and  * ISC_NET_PORTRANGEHIGH will be returned.  *  * Requires:  *  *\li	'low' and 'high' must be non NULL.  *  * Returns:  *  *\li	*low and *high will be the ports specifying the low and high ends of  *	the range.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDNTOP
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDPTON
end_ifdef

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

begin_define
define|#
directive|define
name|inet_aton
value|isc_net_aton
end_define

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

