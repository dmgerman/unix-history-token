begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* osdep.h     Operating system dependencies... */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1996-2003 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   Internet Systems Consortium, Inc.  *   950 Charter Street  *   Redwood City, CA 94063  *<info@isc.org>  *   http://www.isc.org/  *  * This software has been written for Internet Systems Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about Internet Systems Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ISC_DHCP_OSDEP_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ISC_DHCP_OSDEP_H__
end_define

begin_include
include|#
directive|include
file|"site.h"
end_include

begin_comment
comment|/* Porting::     If you add a new network API, you must add a check for it below: */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_SOCKETS
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_SOCKET_SEND
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_SOCKET_RECEIVE
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_RAW_SOCKETS
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_RAW_SEND
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_SOCKET_RECEIVE
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_BPF
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_BPF_SEND
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_BPF_RECEIVE
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_LPF
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_LPF_SEND
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_LPF_RECEIVE
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_NIT
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_NIT_SEND
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_NIT_RECEIVE
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USR_DLPI_SEND
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_DLPI_RECEIVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_DEFAULT_NETWORK
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
name|TIME_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIME_MAX
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Porting::     If you add a new system configuration file, include it here: */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cf/sunos5-5.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cf/sunos4.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|aix
end_ifdef

begin_include
include|#
directive|include
file|"cf/aix.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|bsdi
end_ifdef

begin_include
include|#
directive|include
file|"cf/bsdos.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|"cf/netbsd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"cf/freebsd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OpenBSD
end_ifdef

begin_include
include|#
directive|include
file|"cf/openbsd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cf/alphaosf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_include
include|#
directive|include
file|"cf/ultrix.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_include
include|#
directive|include
file|"cf/linux.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCO
end_ifdef

begin_include
include|#
directive|include
file|"cf/sco.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cf/hpux.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_include
include|#
directive|include
file|"cf/qnx.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__CYGWIN32__
end_ifdef

begin_include
include|#
directive|include
file|"cf/cygwin32.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|"cf/rhapsody.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cf/nextstep.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* snprintf/vsnprintf hacks.  for systems with no libc versions only. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_SNPRINTF
end_ifdef

begin_function_decl
specifier|extern
name|int
name|isc_print_snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isc_print_vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|snprintf
value|isc_print_snprintf
end_define

begin_define
define|#
directive|define
name|vsnprintf
value|isc_print_vsnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Porting::     If you add a new network API, and have it set up so that it can be    used for sending or receiving, but doesn't have to be used for both,    then set up an ifdef like the ones below: */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SOCKETS
end_ifdef

begin_define
define|#
directive|define
name|USE_SOCKET_SEND
end_define

begin_define
define|#
directive|define
name|USE_SOCKET_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_RAW_SOCKETS
end_ifdef

begin_define
define|#
directive|define
name|USE_RAW_SEND
end_define

begin_define
define|#
directive|define
name|USE_SOCKET_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BPF
end_ifdef

begin_define
define|#
directive|define
name|USE_BPF_SEND
end_define

begin_define
define|#
directive|define
name|USE_BPF_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LPF
end_ifdef

begin_define
define|#
directive|define
name|USE_LPF_SEND
end_define

begin_define
define|#
directive|define
name|USE_LPF_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NIT
end_ifdef

begin_define
define|#
directive|define
name|USE_NIT_SEND
end_define

begin_define
define|#
directive|define
name|USE_NIT_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DLPI
end_ifdef

begin_define
define|#
directive|define
name|USE_DLPI_SEND
end_define

begin_define
define|#
directive|define
name|USE_DLPI_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_UPF
end_ifdef

begin_define
define|#
directive|define
name|USE_UPF_SEND
end_define

begin_define
define|#
directive|define
name|USE_UPF_RECEIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Porting::     If you add support for sending packets directly out an interface,    and your support does not do ARP or routing, you must use a fallback    mechanism to deal with packets that need to be sent to routers.    Currently, all low-level packet interfaces use BSD sockets as a    fallback. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_BPF_SEND
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_NIT_SEND
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|USE_DLPI_SEND
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_UPF_SEND
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|USE_LPF_SEND
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|USE_SOCKET_SEND
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SO_BINDTODEVICE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|USE_SOCKET_FALLBACK
end_define

begin_define
define|#
directive|define
name|USE_FALLBACK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Porting::     If you add support for sending packets directly out an interface    and need to be able to assemble packets, add the USE_XXX_SEND    definition for your interface to the list tested below. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_RAW_SEND
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_BPF_SEND
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|USE_NIT_SEND
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_UPF_SEND
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|USE_DLPI_SEND
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_LPF_SEND
argument_list|)
end_if

begin_define
define|#
directive|define
name|PACKET_ASSEMBLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Porting::     If you add support for receiving packets directly from an interface    and need to be able to decode raw packets, add the USE_XXX_RECEIVE    definition for your interface to the list tested below. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_RAW_RECEIVE
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_BPF_SEND
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|USE_NIT_RECEIVE
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_UPF_RECEIVE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|USE_DLPI_RECEIVE
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_LPF_RECEIVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PACKET_DECODING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we don't have a DLPI packet filter, we have to filter in userland.    Probably not worth doing, actually. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_DLPI_RECEIVE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_DLPI_PFMOD
argument_list|)
end_if

begin_define
define|#
directive|define
name|USERLAND_FILTER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* jmp_buf is assumed to be a struct unless otherwise defined in the    system header. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|jbp_decl
end_ifndef

begin_define
define|#
directive|define
name|jbp_decl
parameter_list|(
name|x
parameter_list|)
value|jmp_buf *x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|jref
end_ifndef

begin_define
define|#
directive|define
name|jref
parameter_list|(
name|x
parameter_list|)
value|(&(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|jdref
end_ifndef

begin_define
define|#
directive|define
name|jdref
parameter_list|(
name|x
parameter_list|)
value|(*(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|jrefproto
end_ifndef

begin_define
define|#
directive|define
name|jrefproto
value|jmp_buf *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BPF_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|BPF_FORMAT
value|"/dev/bpf%d"
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
name|F_SETFD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SETFD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SETFD
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
name|IFF_POINTOPOINT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_IFF_POINTOPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_IFF_POINTOPOINT
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
name|AF_LINK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_AF_LINK
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_AF_LINK
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
name|ARPHRD_TUNNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_TUNNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_TUNNEL
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
name|ARPHRD_LOOPBACK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_LOOPBACK
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_LOOPBACK
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
name|ARPHRD_ROSE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_ROSE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_ROSE
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
name|ARPHRD_IEEE802
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_IEEE802
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_IEEE802
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
name|ARPHRD_IEEE802_TR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_IEEE802_TR
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_IEEE802_TR
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
name|ARPHRD_FDDI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_FDDI
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_FDDI
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
name|ARPHRD_AX25
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_AX25
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_AX25
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
name|ARPHRD_NETROM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_NETROM
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_NETROM
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
name|ARPHRD_METRICOM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ARPHRD_METRICOM
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ARPHRD_METRICOM
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
name|SO_BINDTODEVICE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SO_BINDTODEVICE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SO_BINDTODEVICE
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
name|AF_LINK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_AF_LINK
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_AF_LINK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Linux needs to define SHUT_* in /usr/include/sys/socket.h someday... */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHUT_RD
argument_list|)
end_if

begin_define
define|#
directive|define
name|SHUT_RD
value|0
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
name|SOCKLEN_T
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOCKLEN_T
value|socklen_t
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
comment|/* __ISC_DHCP_OSDEP_H__ */
end_comment

end_unit

