begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* osdep.h     Operating system dependencies... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996, 1997, 1998, 1999 The Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE INTERNET SOFTWARE CONSORTIUM OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software was written for the Internet Software Consortium by Ted Lemon  * under a contract with Vixie Laboratories.  */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IRIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cf/irix.h"
end_include

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
name|defined
argument_list|(
name|USE_LPF_SEND
argument_list|)
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
name|SO_BINDTODEVICE
argument_list|)
operator|)
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
name|SIOCGIFHWADDR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SIOCGIFHWADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SIOCGIFHWADDR
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

end_unit

