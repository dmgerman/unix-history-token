begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|SOLARIS2
operator|>=
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|_SYS_VARARGS_H
end_define

begin_define
define|#
directive|define
name|_VARARGS_H
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
name|__STDC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/byteorder.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_include
include|#
directive|include
file|"ip_compat.h"
end_include

begin_include
include|#
directive|include
file|<netinet/tcpip.h>
end_include

begin_include
include|#
directive|include
file|"ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"ipt.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)misc.c	1.3 2/4/96 (C) 1995 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$Id: misc.c,v 2.2.2.1 2001/06/26 10:43:19 darrenr Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|opts
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|printpacket
parameter_list|(
name|ip
parameter_list|)
name|ip_t
modifier|*
name|ip
decl_stmt|;
block|{
name|tcphdr_t
modifier|*
name|tcp
decl_stmt|;
name|tcp
operator|=
operator|(
expr|struct
name|tcphdr
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|ip
operator|+
operator|(
name|ip
operator|->
name|ip_hl
operator|<<
literal|2
operator|)
operator|)
expr_stmt|;
name|printf
argument_list|(
literal|"ip %d(%d) %d"
argument_list|,
name|ip
operator|->
name|ip_len
argument_list|,
name|ip
operator|->
name|ip_hl
operator|<<
literal|2
argument_list|,
name|ip
operator|->
name|ip_p
argument_list|)
expr_stmt|;
if|if
condition|(
name|ip
operator|->
name|ip_off
operator|&
name|IP_OFFMASK
condition|)
name|printf
argument_list|(
literal|" @%d"
argument_list|,
name|ip
operator|->
name|ip_off
operator|<<
literal|3
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|inet_ntoa
argument_list|(
name|ip
operator|->
name|ip_src
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ip
operator|->
name|ip_off
operator|&
name|IP_OFFMASK
operator|)
condition|)
if|if
condition|(
name|ip
operator|->
name|ip_p
operator|==
name|IPPROTO_TCP
operator|||
name|ip
operator|->
name|ip_p
operator|==
name|IPPROTO_UDP
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|",%d"
argument_list|,
name|ntohs
argument_list|(
name|tcp
operator|->
name|th_sport
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"> "
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|inet_ntoa
argument_list|(
name|ip
operator|->
name|ip_dst
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ip
operator|->
name|ip_off
operator|&
name|IP_OFFMASK
operator|)
condition|)
if|if
condition|(
name|ip
operator|->
name|ip_p
operator|==
name|IPPROTO_TCP
operator|||
name|ip
operator|->
name|ip_p
operator|==
name|IPPROTO_UDP
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|",%d"
argument_list|,
name|ntohs
argument_list|(
name|tcp
operator|->
name|th_dport
argument_list|)
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function
name|void
name|verbose
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|void	verbose
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|pvar
decl_stmt|;
name|va_start
argument_list|(
name|pvar
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|opts
operator|&
name|OPT_VERBOSE
condition|)
name|vprintf
argument_list|(
name|fmt
argument_list|,
name|pvar
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|pvar
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|void
name|debug
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|void	debug
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|pvar
decl_stmt|;
name|va_start
argument_list|(
name|pvar
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|opts
operator|&
name|OPT_DEBUG
condition|)
name|vprintf
argument_list|(
name|fmt
argument_list|,
name|pvar
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|pvar
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

