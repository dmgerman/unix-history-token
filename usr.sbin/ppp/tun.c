begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* For IFF_ defines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/* For IFF_ defines */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_tun.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"layer.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"id.h"
end_include

begin_include
include|#
directive|include
file|"timer.h"
end_include

begin_include
include|#
directive|include
file|"lqr.h"
end_include

begin_include
include|#
directive|include
file|"hdlc.h"
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"fsm.h"
end_include

begin_include
include|#
directive|include
file|"throughput.h"
end_include

begin_include
include|#
directive|include
file|"iplist.h"
end_include

begin_include
include|#
directive|include
file|"slcompress.h"
end_include

begin_include
include|#
directive|include
file|"ipcp.h"
end_include

begin_include
include|#
directive|include
file|"filter.h"
end_include

begin_include
include|#
directive|include
file|"descriptor.h"
end_include

begin_include
include|#
directive|include
file|"lcp.h"
end_include

begin_include
include|#
directive|include
file|"ccp.h"
end_include

begin_include
include|#
directive|include
file|"link.h"
end_include

begin_include
include|#
directive|include
file|"mp.h"
end_include

begin_include
include|#
directive|include
file|"iface.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NORADIUS
end_ifndef

begin_include
include|#
directive|include
file|"radius.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bundle.h"
end_include

begin_include
include|#
directive|include
file|"tun.h"
end_include

begin_function
name|void
name|tun_configure
parameter_list|(
name|struct
name|bundle
modifier|*
name|bundle
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__NetBSD__
name|struct
name|ifreq
name|ifr
decl_stmt|;
name|int
name|s
decl_stmt|;
name|s
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|<
literal|0
condition|)
block|{
name|log_Printf
argument_list|(
name|LogERROR
argument_list|,
literal|"tun_configure: socket(): %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|sprintf
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
literal|"tun%d"
argument_list|,
name|bundle
operator|->
name|unit
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_mtu
operator|=
name|bundle
operator|->
name|iface
operator|->
name|mtu
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCSIFMTU
argument_list|,
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
name|log_Printf
argument_list|(
name|LogERROR
argument_list|,
literal|"tun_configure: ioctl(SIOCSIFMTU): %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
name|struct
name|tuninfo
name|info
decl_stmt|;
name|memset
argument_list|(
operator|&
name|info
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
name|info
argument_list|)
expr_stmt|;
name|info
operator|.
name|type
operator|=
name|IFT_PPP
expr_stmt|;
name|info
operator|.
name|mtu
operator|=
name|bundle
operator|->
name|iface
operator|->
name|mtu
expr_stmt|;
name|info
operator|.
name|baudrate
operator|=
name|bundle
operator|->
name|bandwidth
expr_stmt|;
ifdef|#
directive|ifdef
name|__OpenBSD__
name|info
operator|.
name|flags
operator|=
name|IFF_UP
operator||
name|IFF_POINTOPOINT
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ID0ioctl
argument_list|(
name|bundle
operator|->
name|dev
operator|.
name|fd
argument_list|,
name|TUNSIFINFO
argument_list|,
operator|&
name|info
argument_list|)
operator|<
literal|0
condition|)
name|log_Printf
argument_list|(
name|LogERROR
argument_list|,
literal|"tun_configure: ioctl(TUNSIFINFO): %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

