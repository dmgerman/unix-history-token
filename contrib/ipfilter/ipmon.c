begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1998 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  */
end_comment

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
literal|"@(#)ipmon.c	1.21 6/5/96 (C)1993-1998 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$Id: ipmon.c,v 2.3.2.1 1999/08/14 04:46:07 darrenr Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SOLARIS
end_ifndef

begin_define
define|#
directive|define
name|SOLARIS
value|(defined(__SVR4) || defined(__svr4__))&& defined(sun)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

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
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_fsm.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
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
file|<sys/uio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"netinet/ip_compat.h"
end_include

begin_include
include|#
directive|include
file|<netinet/tcpip.h>
end_include

begin_include
include|#
directive|include
file|"netinet/ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_proxy.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_nat.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_state.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SOLARIS2
argument_list|)
end_if

begin_define
define|#
directive|define
name|STRERROR
parameter_list|(
name|x
parameter_list|)
value|sys_errlist[x]
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRERROR
parameter_list|(
name|x
parameter_list|)
value|strerror(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|flags
block|{
name|int
name|value
decl_stmt|;
name|char
name|flag
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|flags
name|tcpfl
index|[]
init|=
block|{
block|{
name|TH_ACK
block|,
literal|'A'
block|}
block|,
block|{
name|TH_RST
block|,
literal|'R'
block|}
block|,
block|{
name|TH_SYN
block|,
literal|'S'
block|}
block|,
block|{
name|TH_FIN
block|,
literal|'F'
block|}
block|,
block|{
name|TH_URG
block|,
literal|'U'
block|}
block|,
block|{
name|TH_PUSH
block|,
literal|'P'
block|}
block|,
block|{
literal|0
block|,
literal|'\0'
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|pidfile
init|=
literal|"/etc/opt/ipf/ipmon.pid"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199306
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|pidfile
init|=
literal|"/var/run/ipmon.pid"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
modifier|*
name|pidfile
init|=
literal|"/etc/ipmon.pid"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
name|line
index|[
literal|2048
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|opts
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|newlog
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|logfile
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|donehup
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|usage
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|handlehup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|flushlogs
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|print_log
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|print_ipflog
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|print_natlog
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|print_statelog
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|dumphex
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|read_log
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|write_pid
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hostname
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|portname
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
decl|main
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|logopts
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_tabs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|getproto
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|protocols
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|udp_ports
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|tcp_ports
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OPT_SYSLOG
value|0x001
end_define

begin_define
define|#
directive|define
name|OPT_RESOLVE
value|0x002
end_define

begin_define
define|#
directive|define
name|OPT_HEXBODY
value|0x004
end_define

begin_define
define|#
directive|define
name|OPT_VERBOSE
value|0x008
end_define

begin_define
define|#
directive|define
name|OPT_HEXHDR
value|0x010
end_define

begin_define
define|#
directive|define
name|OPT_TAIL
value|0x020
end_define

begin_define
define|#
directive|define
name|OPT_NAT
value|0x080
end_define

begin_define
define|#
directive|define
name|OPT_STATE
value|0x100
end_define

begin_define
define|#
directive|define
name|OPT_FILTER
value|0x200
end_define

begin_define
define|#
directive|define
name|OPT_PORTNUM
value|0x400
end_define

begin_define
define|#
directive|define
name|OPT_LOGALL
value|(OPT_NAT|OPT_STATE|OPT_FILTER)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOGFAC
end_ifndef

begin_define
define|#
directive|define
name|LOGFAC
value|LOG_LOCAL0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|handlehup
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|handlehup
argument_list|)
expr_stmt|;
if|if
condition|(
name|logfile
operator|&&
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|logfile
argument_list|,
literal|"a"
argument_list|)
operator|)
condition|)
name|newlog
operator|=
name|fp
expr_stmt|;
name|init_tabs
argument_list|()
expr_stmt|;
name|donehup
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|init_tabs
parameter_list|()
block|{
name|struct
name|protoent
modifier|*
name|p
decl_stmt|;
name|struct
name|servent
modifier|*
name|s
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
modifier|*
name|tab
decl_stmt|;
name|u_int
name|port
decl_stmt|;
if|if
condition|(
name|protocols
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|protocols
argument_list|)
expr_stmt|;
name|protocols
operator|=
name|NULL
expr_stmt|;
block|}
name|protocols
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
literal|256
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|protocols
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|protocols
operator|!=
name|NULL
condition|)
block|{
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|protocols
argument_list|,
literal|256
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|protocols
argument_list|)
argument_list|)
expr_stmt|;
name|setprotoent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|p
operator|=
name|getprotoent
argument_list|()
operator|)
operator|!=
name|NULL
condition|)
if|if
condition|(
name|p
operator|->
name|p_proto
operator|>=
literal|0
operator|&&
name|p
operator|->
name|p_proto
operator|<=
literal|255
operator|&&
name|p
operator|->
name|p_name
operator|!=
name|NULL
condition|)
name|protocols
index|[
name|p
operator|->
name|p_proto
index|]
operator|=
name|strdup
argument_list|(
name|p
operator|->
name|p_name
argument_list|)
expr_stmt|;
name|endprotoent
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|udp_ports
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|udp_ports
argument_list|)
expr_stmt|;
name|udp_ports
operator|=
name|NULL
expr_stmt|;
block|}
name|udp_ports
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
literal|65536
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|udp_ports
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|udp_ports
operator|!=
name|NULL
condition|)
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|udp_ports
argument_list|,
literal|65536
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|udp_ports
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcp_ports
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|tcp_ports
argument_list|)
expr_stmt|;
name|tcp_ports
operator|=
name|NULL
expr_stmt|;
block|}
name|tcp_ports
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
literal|65536
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|tcp_ports
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcp_ports
operator|!=
name|NULL
condition|)
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|tcp_ports
argument_list|,
literal|65536
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|tcp_ports
argument_list|)
argument_list|)
expr_stmt|;
name|setservent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|s
operator|=
name|getservent
argument_list|()
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|s
operator|->
name|s_proto
operator|==
name|NULL
condition|)
continue|continue;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|s
operator|->
name|s_proto
argument_list|,
literal|"tcp"
argument_list|)
condition|)
block|{
name|port
operator|=
operator|(
name|u_int
operator|)
name|s
operator|->
name|s_port
expr_stmt|;
name|name
operator|=
name|s
operator|->
name|s_name
expr_stmt|;
name|tab
operator|=
name|tcp_ports
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|s
operator|->
name|s_proto
argument_list|,
literal|"udp"
argument_list|)
condition|)
block|{
name|port
operator|=
operator|(
name|u_int
operator|)
name|s
operator|->
name|s_port
expr_stmt|;
name|name
operator|=
name|s
operator|->
name|s_name
expr_stmt|;
name|tab
operator|=
name|udp_ports
expr_stmt|;
block|}
else|else
continue|continue;
if|if
condition|(
operator|(
name|port
operator|<
literal|0
operator|||
name|port
operator|>
literal|65535
operator|)
operator|||
operator|(
name|name
operator|==
name|NULL
operator|)
condition|)
continue|continue;
name|tab
index|[
name|port
index|]
operator|=
name|strdup
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
name|endservent
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|getproto
parameter_list|(
name|p
parameter_list|)
name|u_int
name|p
decl_stmt|;
block|{
specifier|static
name|char
name|pnum
index|[
literal|4
index|]
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|p
operator|&=
literal|0xff
expr_stmt|;
name|s
operator|=
name|protocols
condition|?
name|protocols
index|[
name|p
index|]
else|:
name|NULL
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
name|sprintf
argument_list|(
name|pnum
argument_list|,
literal|"%u"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|s
operator|=
name|pnum
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|read_log
parameter_list|(
name|fd
parameter_list|,
name|lenp
parameter_list|,
name|buf
parameter_list|,
name|bufsize
parameter_list|)
name|int
name|fd
decl_stmt|,
name|bufsize
decl_stmt|,
decl|*
name|lenp
decl_stmt|;
end_function

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|nr
decl_stmt|;
name|nr
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|bufsize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|nr
condition|)
return|return
literal|2
return|;
if|if
condition|(
operator|(
name|nr
operator|<
literal|0
operator|)
operator|&&
operator|(
name|errno
operator|!=
name|EINTR
operator|)
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|lenp
operator|=
name|nr
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_function
name|char
modifier|*
name|hostname
parameter_list|(
name|res
parameter_list|,
name|ip
parameter_list|)
name|int
name|res
decl_stmt|;
name|struct
name|in_addr
name|ip
decl_stmt|;
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
if|if
condition|(
operator|!
name|res
condition|)
return|return
name|inet_ntoa
argument_list|(
name|ip
argument_list|)
return|;
name|hp
operator|=
name|gethostbyaddr
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|ip
argument_list|,
sizeof|sizeof
argument_list|(
name|ip
argument_list|)
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hp
condition|)
return|return
name|inet_ntoa
argument_list|(
name|ip
argument_list|)
return|;
return|return
name|hp
operator|->
name|h_name
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|portname
parameter_list|(
name|res
parameter_list|,
name|proto
parameter_list|,
name|port
parameter_list|)
name|int
name|res
decl_stmt|;
name|char
modifier|*
name|proto
decl_stmt|;
name|u_int
name|port
decl_stmt|;
block|{
specifier|static
name|char
name|pname
index|[
literal|8
index|]
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|port
operator|=
name|ntohs
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|port
operator|&=
literal|0xffff
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|pname
argument_list|,
literal|"%u"
argument_list|,
name|port
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|res
operator|||
operator|(
name|opts
operator|&
name|OPT_PORTNUM
operator|)
condition|)
return|return
name|pname
return|;
name|s
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|proto
argument_list|,
literal|"tcp"
argument_list|)
condition|)
name|s
operator|=
name|tcp_ports
index|[
name|port
index|]
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|proto
argument_list|,
literal|"udp"
argument_list|)
condition|)
name|s
operator|=
name|udp_ports
index|[
name|port
index|]
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|s
operator|=
name|pname
expr_stmt|;
return|return
name|s
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|dumphex
parameter_list|(
name|log
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
name|FILE
modifier|*
name|log
decl_stmt|;
name|u_char
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|char
name|line
index|[
literal|80
index|]
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
name|u_char
modifier|*
name|s
init|=
name|buf
decl_stmt|,
modifier|*
name|t
init|=
operator|(
name|u_char
operator|*
operator|)
name|line
decl_stmt|;
for|for
control|(
name|i
operator|=
name|len
operator|,
name|j
operator|=
literal|0
init|;
name|i
condition|;
name|i
operator|--
operator|,
name|j
operator|++
operator|,
name|s
operator|++
control|)
block|{
if|if
condition|(
name|j
operator|&&
operator|!
operator|(
name|j
operator|&
literal|0xf
operator|)
condition|)
block|{
operator|*
name|t
operator|++
operator|=
literal|'\n'
expr_stmt|;
operator|*
name|t
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|opts
operator|&
name|OPT_SYSLOG
operator|)
condition|)
name|fputs
argument_list|(
name|line
argument_list|,
name|log
argument_list|)
expr_stmt|;
else|else
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|t
operator|=
operator|(
name|u_char
operator|*
operator|)
name|line
expr_stmt|;
operator|*
name|t
operator|=
literal|'\0'
expr_stmt|;
block|}
name|sprintf
argument_list|(
operator|(
name|char
operator|*
operator|)
name|t
argument_list|,
literal|"%02x"
argument_list|,
operator|*
name|s
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|t
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
operator|!
operator|(
operator|(
name|j
operator|+
literal|1
operator|)
operator|&
literal|0xf
operator|)
condition|)
block|{
name|s
operator|-=
literal|15
expr_stmt|;
name|sprintf
argument_list|(
operator|(
name|char
operator|*
operator|)
name|t
argument_list|,
literal|"        "
argument_list|)
expr_stmt|;
name|t
operator|+=
literal|8
expr_stmt|;
for|for
control|(
name|k
operator|=
literal|16
init|;
name|k
condition|;
name|k
operator|--
operator|,
name|s
operator|++
control|)
operator|*
name|t
operator|++
operator|=
operator|(
name|isprint
argument_list|(
operator|*
name|s
argument_list|)
condition|?
operator|*
name|s
else|:
literal|'.'
operator|)
expr_stmt|;
name|s
operator|--
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|j
operator|+
literal|1
operator|)
operator|&
literal|0xf
condition|)
operator|*
name|t
operator|++
operator|=
literal|' '
expr_stmt|;
empty_stmt|;
block|}
if|if
condition|(
name|j
operator|&
literal|0xf
condition|)
block|{
for|for
control|(
name|k
operator|=
literal|16
operator|-
operator|(
name|j
operator|&
literal|0xf
operator|)
init|;
name|k
condition|;
name|k
operator|--
control|)
block|{
operator|*
name|t
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|t
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|t
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
name|sprintf
argument_list|(
operator|(
name|char
operator|*
operator|)
name|t
argument_list|,
literal|"       "
argument_list|)
expr_stmt|;
name|t
operator|+=
literal|7
expr_stmt|;
name|s
operator|-=
name|j
operator|&
literal|0xf
expr_stmt|;
for|for
control|(
name|k
operator|=
name|j
operator|&
literal|0xf
init|;
name|k
condition|;
name|k
operator|--
operator|,
name|s
operator|++
control|)
operator|*
name|t
operator|++
operator|=
operator|(
name|isprint
argument_list|(
operator|*
name|s
argument_list|)
condition|?
operator|*
name|s
else|:
literal|'.'
operator|)
expr_stmt|;
operator|*
name|t
operator|++
operator|=
literal|'\n'
expr_stmt|;
operator|*
name|t
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
operator|!
operator|(
name|opts
operator|&
name|OPT_SYSLOG
operator|)
condition|)
block|{
name|fputs
argument_list|(
name|line
argument_list|,
name|log
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|log
argument_list|)
expr_stmt|;
block|}
else|else
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s"
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_natlog
parameter_list|(
name|log
parameter_list|,
name|buf
parameter_list|,
name|blen
parameter_list|)
name|FILE
modifier|*
name|log
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|blen
decl_stmt|;
block|{
name|struct
name|natlog
modifier|*
name|nl
decl_stmt|;
name|iplog_t
modifier|*
name|ipl
init|=
operator|(
name|iplog_t
operator|*
operator|)
name|buf
decl_stmt|;
name|char
modifier|*
name|t
init|=
name|line
decl_stmt|;
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|int
name|res
decl_stmt|,
name|i
decl_stmt|,
name|len
decl_stmt|;
name|nl
operator|=
operator|(
expr|struct
name|natlog
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|ipl
operator|+
sizeof|sizeof
argument_list|(
operator|*
name|ipl
argument_list|)
operator|)
expr_stmt|;
name|res
operator|=
operator|(
name|opts
operator|&
name|OPT_RESOLVE
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
operator|(
name|time_t
operator|*
operator|)
operator|&
name|ipl
operator|->
name|ipl_sec
argument_list|)
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|opts
operator|&
name|OPT_SYSLOG
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|strftime
argument_list|(
name|t
argument_list|,
name|len
argument_list|,
literal|"%d/%m/%Y "
argument_list|,
name|tm
argument_list|)
expr_stmt|;
name|i
operator|=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|len
operator|-=
name|i
expr_stmt|;
name|t
operator|+=
name|i
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|strftime
argument_list|(
name|t
argument_list|,
name|len
argument_list|,
literal|"%T"
argument_list|,
name|tm
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|t
argument_list|,
literal|".%-.6ld @%hd "
argument_list|,
name|ipl
operator|->
name|ipl_usec
argument_list|,
name|nl
operator|->
name|nl_rule
operator|+
literal|1
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
operator|->
name|nl_type
operator|==
name|NL_NEWMAP
condition|)
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:MAP "
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|nl
operator|->
name|nl_type
operator|==
name|NL_NEWRDR
condition|)
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:RDR "
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|nl
operator|->
name|nl_type
operator|==
name|NL_EXPIRE
condition|)
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:EXPIRE "
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"Type: %d "
argument_list|,
name|nl
operator|->
name|nl_type
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s<- -> "
argument_list|,
name|hostname
argument_list|(
name|res
argument_list|,
name|nl
operator|->
name|nl_inip
argument_list|)
argument_list|,
name|portname
argument_list|(
name|res
argument_list|,
name|NULL
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_inport
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s "
argument_list|,
name|hostname
argument_list|(
name|res
argument_list|,
name|nl
operator|->
name|nl_outip
argument_list|)
argument_list|,
name|portname
argument_list|(
name|res
argument_list|,
name|NULL
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_outport
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"[%s,%s]"
argument_list|,
name|hostname
argument_list|(
name|res
argument_list|,
name|nl
operator|->
name|nl_origip
argument_list|)
argument_list|,
name|portname
argument_list|(
name|res
argument_list|,
name|NULL
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_origport
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
operator|->
name|nl_type
operator|==
name|NL_EXPIRE
condition|)
block|{
ifdef|#
directive|ifdef
name|USE_QUAD_T
operator|(
name|void
operator|)
name|sprintf
argument_list|(
argument|t
argument_list|,
literal|" Pkts %qd Bytes %qd"
argument_list|,
else|#
directive|else
argument|(void) sprintf(t,
literal|" Pkts %ld Bytes %ld"
argument|,
endif|#
directive|endif
argument|nl->nl_pkts, nl->nl_bytes); 		t += strlen(t); 	}  	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	if (opts& OPT_SYSLOG) 		syslog(LOG_INFO,
literal|"%s"
argument|, line); 	else 		(void) fprintf(log,
literal|"%s"
argument|, line); }   static	void	print_statelog(log, buf, blen) FILE	*log; char	*buf; int	blen; { 	struct	ipslog *sl; 	iplog_t	*ipl = (iplog_t *)buf; 	char	*t = line
argument_list|,
argument|*proto; 	struct	tm	*tm; 	int	res
argument_list|,
argument|i
argument_list|,
argument|len;  	sl = (struct ipslog *)((char *)ipl + sizeof(*ipl)); 	res = (opts& OPT_RESOLVE) ?
literal|1
argument|:
literal|0
argument|; 	tm = localtime((time_t *)&ipl->ipl_sec); 	len = sizeof(line); 	if (!(opts& OPT_SYSLOG)) { 		(void) strftime(t, len,
literal|"%d/%m/%Y "
argument|, tm); 		i = strlen(t); 		len -= i; 		t += i; 	} 	(void) strftime(t, len,
literal|"%T"
argument|, tm); 	t += strlen(t); 	(void) sprintf(t,
literal|".%-.6ld "
argument|, ipl->ipl_usec); 	t += strlen(t);  	if (sl->isl_type == ISL_NEW) 		strcpy(t,
literal|"STATE:NEW "
argument|); 	else if (sl->isl_type == ISL_EXPIRE) { 		if ((sl->isl_p == IPPROTO_TCP)&& 		    (sl->isl_state[
literal|0
argument|]> TCPS_ESTABLISHED || 		     sl->isl_state[
literal|1
argument|]> TCPS_ESTABLISHED)) 			strcpy(t,
literal|"STATE:CLOSE "
argument|); 		else 			strcpy(t,
literal|"STATE:EXPIRE "
argument|); 	} else if (sl->isl_type == ISL_FLUSH) 		strcpy(t,
literal|"STATE:FLUSH "
argument|); 	else 		sprintf(t,
literal|"Type: %d "
argument|, sl->isl_type); 	t += strlen(t);  	proto = getproto(sl->isl_p);  	if (sl->isl_p == IPPROTO_TCP || sl->isl_p == IPPROTO_UDP) { 		(void) sprintf(t,
literal|"%s,%s -> "
argument|, 			hostname(res, sl->isl_src), 			portname(res, proto, (u_int)sl->isl_sport)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s,%s PR %s"
argument|, 			hostname(res, sl->isl_dst), 			portname(res, proto, (u_int)sl->isl_dport), proto); 	} else if (sl->isl_p == IPPROTO_ICMP) { 		(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, sl->isl_src)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s PR icmp %d"
argument|, 			hostname(res, sl->isl_dst), sl->isl_itype); 	} 	t += strlen(t); 	if (sl->isl_type != ISL_NEW) {
ifdef|#
directive|ifdef
name|USE_QUAD_T
argument|(void) sprintf(t,
literal|" Pkts %qd Bytes %qd"
argument|,
else|#
directive|else
argument|(void) sprintf(t,
literal|" Pkts %ld Bytes %ld"
argument|,
endif|#
directive|endif
argument|sl->isl_pkts, sl->isl_bytes); 		t += strlen(t); 	}  	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	if (opts& OPT_SYSLOG) 		syslog(LOG_INFO,
literal|"%s"
argument|, line); 	else 		(void) fprintf(log,
literal|"%s"
argument|, line); }   static	void	print_log(logtype, log, buf, blen) FILE	*log; char	*buf; int	logtype, blen; { 	iplog_t	*ipl; 	char *bp = NULL, *bpo = NULL; 	int psize;  	while (blen>
literal|0
argument|) { 		ipl = (iplog_t *)buf; 		if ((u_long)ipl& (sizeof(long)-
literal|1
argument|)) { 			if (bp) 				bpo = bp; 			bp = (char *)malloc(blen); 			bcopy((char *)ipl, bp, blen); 			if (bpo) { 				free(bpo); 				bpo = NULL; 			} 			buf = bp; 			continue; 		} 		if (ipl->ipl_magic != IPL_MAGIC) {
comment|/* invalid data or out of sync */
argument|break; 		} 		psize = ipl->ipl_dsize; 		switch (logtype) 		{ 		case IPL_LOGIPF : 			print_ipflog(log, buf, psize); 			break; 		case IPL_LOGNAT : 			print_natlog(log, buf, psize); 			break; 		case IPL_LOGSTATE : 			print_statelog(log, buf, psize); 			break; 		}  		blen -= psize; 		buf += psize; 	} 	if (bp) 		free(bp); 	return; }   static	void	print_ipflog(log, buf, blen) FILE	*log; char	*buf; int	blen; { 	tcphdr_t	*tp; 	struct	icmp	*ic; 	struct	tm	*tm; 	char	*t, *proto; 	u_short	hl, p; 	int	i, lvl, res, len; 	ip_t	*ipc, *ip; 	iplog_t	*ipl; 	ipflog_t *ipf;  	ipl = (iplog_t *)buf; 	ipf = (ipflog_t *)((char *)buf + sizeof(*ipl)); 	ip = (ip_t *)((char *)ipf + sizeof(*ipf)); 	res = (opts& OPT_RESOLVE) ?
literal|1
argument|:
literal|0
argument|; 	t = line; 	*t =
literal|'\0'
argument|; 	hl = (ip->ip_hl<<
literal|2
argument|); 	p = (u_short)ip->ip_p; 	tm = localtime((time_t *)&ipl->ipl_sec);
ifdef|#
directive|ifdef
name|linux
argument|ip->ip_len = ntohs(ip->ip_len);
endif|#
directive|endif
argument|len = sizeof(line); 	if (!(opts& OPT_SYSLOG)) { 		(void) strftime(t, len,
literal|"%d/%m/%Y "
argument|, tm); 		i = strlen(t); 		len -= i; 		t += i; 	} 	(void) strftime(t, len,
literal|"%T"
argument|, tm); 	t += strlen(t); 	(void) sprintf(t,
literal|".%-.6ld "
argument|, ipl->ipl_usec); 	t += strlen(t); 	if (ipl->ipl_count>
literal|1
argument|) { 		(void) sprintf(t,
literal|"%dx "
argument|, ipl->ipl_count); 		t += strlen(t); 	}
if|#
directive|if
operator|(
name|SOLARIS
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|<=
literal|1991011
operator|)
operator|&&
operator|(
name|NetBSD
operator|>=
literal|199603
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|OpenBSD
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|>=
literal|199603
operator|)
operator|)
operator|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
argument|len = (int)sizeof(ipf->fl_ifname); 	(void) sprintf(t,
literal|"%*.*s"
argument|, len, len, ipf->fl_ifname); 	t += strlen(t);
if|#
directive|if
name|SOLARIS
argument|if (isalpha(*(t -
literal|1
argument|))) 		*t++ =
literal|'0'
argument|+ ipf->fl_unit;
endif|#
directive|endif
else|#
directive|else
argument|for (len =
literal|0
argument|; len<
literal|3
argument|; len++) 		if (ipf->fl_ifname[len] ==
literal|'\0'
argument|) 			break; 	if (ipf->fl_ifname[len]) 		len++; 	(void) sprintf(t,
literal|"%*.*s%u"
argument|, len, len, ipf->fl_ifname, ipf->fl_unit); 	t += strlen(t);
endif|#
directive|endif
argument|(void) sprintf(t,
literal|" @%hu:%hu "
argument|, ipf->fl_group, ipf->fl_rule +
literal|1
argument|); 	t += strlen(t); 	proto = getproto(p);   	if (ipf->fl_flags& FF_SHORT) { 		*t++ =
literal|'S'
argument|; 		lvl = LOG_ERR; 	} else if (ipf->fl_flags& FR_PASS) { 		if (ipf->fl_flags& FR_LOGP) 			*t++ =
literal|'p'
argument|; 		else 			*t++ =
literal|'P'
argument|; 		lvl = LOG_NOTICE; 	} else if (ipf->fl_flags& FR_BLOCK) { 		if (ipf->fl_flags& FR_LOGB) 			*t++ =
literal|'b'
argument|; 		else 			*t++ =
literal|'B'
argument|; 		lvl = LOG_WARNING; 	} else if (ipf->fl_flags& FF_LOGNOMATCH) { 		*t++ =
literal|'n'
argument|; 		lvl = LOG_NOTICE; 	} else { 		*t++ =
literal|'L'
argument|; 		lvl = LOG_INFO; 	} 	if (ipf->fl_loglevel !=
literal|0xffff
argument|) 		lvl = ipf->fl_loglevel; 	*t++ =
literal|' '
argument|; 	*t =
literal|'\0'
argument|;  	if ((p == IPPROTO_TCP || p == IPPROTO_UDP)&& 	    !(ip->ip_off& IP_OFFMASK)) { 		tp = (tcphdr_t *)((char *)ip + hl); 		if (!(ipf->fl_flags& (FI_SHORT<<
literal|16
argument|))) { 			(void) sprintf(t,
literal|"%s,%s -> "
argument|, 				hostname(res, ip->ip_src), 				portname(res, proto, (u_int)tp->th_sport)); 			t += strlen(t); 			(void) sprintf(t,
literal|"%s,%s PR %s len %hu %hu "
argument|, 				hostname(res, ip->ip_dst), 				portname(res, proto, (u_int)tp->th_dport), 				proto, hl, ip->ip_len); 			t += strlen(t);  			if (p == IPPROTO_TCP) { 				*t++ =
literal|'-'
argument|; 				for (i =
literal|0
argument|; tcpfl[i].value; i++) 					if (tp->th_flags& tcpfl[i].value) 						*t++ = tcpfl[i].flag; 				if (opts& OPT_VERBOSE) { 					(void) sprintf(t,
literal|" %lu %lu %hu"
argument|, 						(u_long)(ntohl(tp->th_seq)), 						(u_long)(ntohl(tp->th_ack)), 						ntohs(tp->th_win)); 					t += strlen(t); 				} 			} 			*t =
literal|'\0'
argument|; 		} else { 			(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, ip->ip_src)); 			t += strlen(t); 			(void) sprintf(t,
literal|"%s PR %s len %hu %hu"
argument|, 				hostname(res, ip->ip_dst), proto, 				hl, ip->ip_len); 		} 	} else if (p == IPPROTO_ICMP) { 		ic = (struct icmp *)((char *)ip + hl); 		(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, ip->ip_src)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s PR icmp len %hu %hu icmp %d/%d"
argument|, 			hostname(res, ip->ip_dst), hl, ip->ip_len, 			ic->icmp_type, ic->icmp_code); 		if (ic->icmp_type == ICMP_UNREACH || 		    ic->icmp_type == ICMP_SOURCEQUENCH || 		    ic->icmp_type == ICMP_PARAMPROB || 		    ic->icmp_type == ICMP_REDIRECT || 		    ic->icmp_type == ICMP_TIMXCEED) { 			ipc =&ic->icmp_ip; 			tp = (tcphdr_t *)((char *)ipc + hl);  			proto = getproto(ipc->ip_p);  			t += strlen(t); 			(void) sprintf(t,
literal|" for %s,%s -"
argument|, 				hostname(res, ipc->ip_src), 				portname(res, proto, (u_int)tp->th_sport)); 			t += strlen(t); 			(void) sprintf(t,
literal|" %s,%s PR %s len %hu %hu"
argument|, 				hostname(res, ipc->ip_dst), 				portname(res, proto, (u_int)tp->th_dport), 				proto, ipc->ip_hl<<
literal|2
argument|, ipc->ip_len); 		} 	} else { 		(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, ip->ip_src)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s PR %s len %hu (%hu)"
argument|, 			hostname(res, ip->ip_dst), proto, hl, ip->ip_len); 		t += strlen(t); 		if (ip->ip_off& IP_OFFMASK) 			(void) sprintf(t,
literal|" frag %s%s%hu@%hu"
argument|, 				ip->ip_off& IP_MF ?
literal|"+"
argument|:
literal|""
argument|, 				ip->ip_off& IP_DF ?
literal|"-"
argument|:
literal|""
argument|, 				ip->ip_len - hl, 				(ip->ip_off& IP_OFFMASK)<<
literal|3
argument|); 	} 	t += strlen(t);  	if (ipf->fl_flags& FR_KEEPSTATE) { 		(void) strcpy(t,
literal|" K-S"
argument|); 		t += strlen(t); 	}  	if (ipf->fl_flags& FR_KEEPFRAG) { 		(void) strcpy(t,
literal|" K-F"
argument|); 		t += strlen(t); 	}  	if (ipf->fl_flags& FR_INQUE) 		strcpy(t,
literal|" IN"
argument|); 	else if (ipf->fl_flags& FR_OUTQUE) 		strcpy(t,
literal|" OUT"
argument|); 	t += strlen(t); 	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	if (opts& OPT_SYSLOG) 		syslog(lvl,
literal|"%s"
argument|, line); 	else 		(void) fprintf(log,
literal|"%s"
argument|, line); 	if (opts& OPT_HEXHDR) 		dumphex(log, (u_char *)buf, sizeof(iplog_t) + sizeof(*ipf)); 	if (opts& OPT_HEXBODY) 		dumphex(log, (u_char *)ip, ipf->fl_plen + ipf->fl_hlen); }   static void usage(prog) char *prog; { 	fprintf(stderr,
literal|"%s: [-NFhstvxX] [-f<logfile>]\n"
argument|, prog); 	exit(
literal|1
argument|); }   static void write_pid(file) char *file; { 	FILE *fp = NULL; 	int fd;  	if ((fd = open(file, O_CREAT|O_TRUNC|O_WRONLY,
literal|0644
argument|))>=
literal|0
argument|) 		fp = fdopen(fd,
literal|"w"
argument|); 	if (!fp) { 		close(fd); 		fprintf(stderr,
literal|"unable to open/create pid file: %s\n"
argument|, file); 		return; 	} 	fprintf(fp,
literal|"%d"
argument|, getpid()); 	fclose(fp); 	close(fd); }   static void flushlogs(file, log) char *file; FILE *log; { 	int	fd, flushed =
literal|0
argument|;  	if ((fd = open(file, O_RDWR)) == -
literal|1
argument|) { 		(void) fprintf(stderr,
literal|"%s: open: %s\n"
argument|, file,STRERROR(errno)); 		exit(-
literal|1
argument|); 	}  	if (ioctl(fd, SIOCIPFFB,&flushed) ==
literal|0
argument|) { 		printf(
literal|"%d bytes flushed from log buffer\n"
argument|, 			flushed); 		fflush(stdout); 	} else 		perror(
literal|"SIOCIPFFB"
argument|); 	(void) close(fd);  	if (flushed) { 		if (opts& OPT_SYSLOG) 			syslog(LOG_INFO,
literal|"%d bytes flushed from log\n"
argument|, 				flushed); 		else if (log != stdout) 			fprintf(log,
literal|"%d bytes flushed from log\n"
argument|, flushed); 	} }   static void logopts(turnon, options) int turnon; char *options; { 	int flags =
literal|0
argument|; 	char *s;  	for (s = options; *s; s++) 	{ 		switch (*s) 		{ 		case
literal|'N'
argument|: 			flags |= OPT_NAT; 			break; 		case
literal|'S'
argument|: 			flags |= OPT_STATE; 			break; 		case
literal|'I'
argument|: 			flags |= OPT_FILTER; 			break; 		default : 			fprintf(stderr,
literal|"Unknown log option %c\n"
argument|, *s); 			exit(
literal|1
argument|); 		} 	}  	if (turnon) 		opts |= flags; 	else 		opts&= ~(flags); }   int main(argc, argv) int argc; char *argv[]; { 	struct	stat	sb; 	FILE	*log = stdout; 	int	fd[
literal|3
argument|], doread, n, i; 	int	tr, nr, regular[
literal|3
argument|], c; 	int	fdt[
literal|3
argument|], devices =
literal|0
argument|, make_daemon =
literal|0
argument|; 	char	buf[
literal|512
argument|], *iplfile[
literal|3
argument|], *s; 	extern	int	optind; 	extern	char	*optarg;  	fd[
literal|0
argument|] = fd[
literal|1
argument|] = fd[
literal|2
argument|] = -
literal|1
argument|; 	fdt[
literal|0
argument|] = fdt[
literal|1
argument|] = fdt[
literal|2
argument|] = -
literal|1
argument|; 	iplfile[
literal|0
argument|] = IPL_NAME; 	iplfile[
literal|1
argument|] = IPNAT_NAME; 	iplfile[
literal|2
argument|] = IPSTATE_NAME;  	while ((c = getopt(argc, argv,
literal|"?aDf:FhnN:o:O:pP:sS:tvxX"
argument|)) != -
literal|1
argument|) 		switch (c) 		{ 		case
literal|'a'
argument|: 			opts |= OPT_LOGALL; 			fdt[
literal|0
argument|] = IPL_LOGIPF; 			fdt[
literal|1
argument|] = IPL_LOGNAT; 			fdt[
literal|2
argument|] = IPL_LOGSTATE; 			break; 		case
literal|'D'
argument|: 			make_daemon =
literal|1
argument|; 			break; 		case
literal|'f'
argument|: case
literal|'I'
argument|: 			opts |= OPT_FILTER; 			fdt[
literal|0
argument|] = IPL_LOGIPF; 			iplfile[
literal|0
argument|] = optarg; 			break; 		case
literal|'F'
argument|: 			flushlogs(iplfile[
literal|0
argument|], log); 			flushlogs(iplfile[
literal|1
argument|], log); 			flushlogs(iplfile[
literal|2
argument|], log); 			break; 		case
literal|'n'
argument|: 			opts |= OPT_RESOLVE; 			break; 		case
literal|'N'
argument|: 			opts |= OPT_NAT; 			fdt[
literal|1
argument|] = IPL_LOGNAT; 			iplfile[
literal|1
argument|] = optarg; 			break; 		case
literal|'o'
argument|: case
literal|'O'
argument|: 			logopts(c ==
literal|'o'
argument|, optarg); 			fdt[
literal|0
argument|] = fdt[
literal|1
argument|] = fdt[
literal|2
argument|] = -
literal|1
argument|; 			if (opts& OPT_FILTER) 				fdt[
literal|0
argument|] = IPL_LOGIPF; 			if (opts& OPT_NAT) 				fdt[
literal|1
argument|] = IPL_LOGNAT; 			if (opts& OPT_STATE) 				fdt[
literal|2
argument|] = IPL_LOGSTATE; 			break; 		case
literal|'p'
argument|: 			opts |= OPT_PORTNUM; 			break; 		case
literal|'P'
argument|: 			pidfile = optarg; 			break; 		case
literal|'s'
argument|: 			s = strrchr(argv[
literal|0
argument|],
literal|'/'
argument|); 			if (s == NULL) 				s = argv[
literal|0
argument|]; 			else 				s++; 			openlog(s, LOG_NDELAY|LOG_PID, LOGFAC); 			s = NULL; 			opts |= OPT_SYSLOG; 			break; 		case
literal|'S'
argument|: 			opts |= OPT_STATE; 			fdt[
literal|2
argument|] = IPL_LOGSTATE; 			iplfile[
literal|2
argument|] = optarg; 			break; 		case
literal|'t'
argument|: 			opts |= OPT_TAIL; 			break; 		case
literal|'v'
argument|: 			opts |= OPT_VERBOSE; 			break; 		case
literal|'x'
argument|: 			opts |= OPT_HEXBODY; 			break; 		case
literal|'X'
argument|: 			opts |= OPT_HEXHDR; 			break; 		default : 		case
literal|'h'
argument|: 		case
literal|'?'
argument|: 			usage(argv[
literal|0
argument|]); 		}  	init_tabs();
comment|/* 	 * Default action is to only open the filter log file. 	 */
argument|if ((fdt[
literal|0
argument|] == -
literal|1
argument|)&& (fdt[
literal|1
argument|] == -
literal|1
argument|)&& (fdt[
literal|2
argument|] == -
literal|1
argument|)) 		fdt[
literal|0
argument|] = IPL_LOGIPF;  	for (i =
literal|0
argument|; i<
literal|3
argument|; i++) { 		if (fdt[i] == -
literal|1
argument|) 			continue; 		if (!strcmp(iplfile[i],
literal|"-"
argument|)) 			fd[i] =
literal|0
argument|; 		else { 			if ((fd[i] = open(iplfile[i], O_RDONLY)) == -
literal|1
argument|) { 				(void) fprintf(stderr,
literal|"%s: open: %s\n"
argument|, iplfile[i], 					       STRERROR(errno)); 				exit(-
literal|1
argument|); 			}  			if (fstat(fd[i],&sb) == -
literal|1
argument|) { 				(void) fprintf(stderr,
literal|"%d: fstat: %s\n"
argument|,fd[i], 					       STRERROR(errno)); 				exit(-
literal|1
argument|); 			} 			if (!(regular[i] = !S_ISCHR(sb.st_mode))) 				devices++; 		} 	}  	if (!(opts& OPT_SYSLOG)) { 		logfile = argv[optind]; 		log = logfile ? fopen(logfile,
literal|"a"
argument|) : stdout; 		if (log == NULL) { 			 			(void) fprintf(stderr,
literal|"%s: fopen: %s\n"
argument|, argv[optind], 				STRERROR(errno)); 			exit(-
literal|1
argument|); 		} 		setvbuf(log, NULL, _IONBF,
literal|0
argument|); 	} else 		log = NULL;  	if (make_daemon&& (log != stdout)) { 		if (fork()>
literal|0
argument|) 			exit(
literal|0
argument|); 		write_pid(pidfile); 		close(
literal|0
argument|); 		close(
literal|1
argument|); 		close(
literal|2
argument|); 		setsid(); 	} else 		write_pid(pidfile);  	signal(SIGHUP, handlehup);  	for (doread =
literal|1
argument|; doread; ) { 		nr =
literal|0
argument|;  		for (i =
literal|0
argument|; i<
literal|3
argument|; i++) { 			tr =
literal|0
argument|; 			if (fdt[i] == -
literal|1
argument|) 				continue; 			if (!regular[i]) { 				if (ioctl(fd[i], FIONREAD,&tr) == -
literal|1
argument|) { 					perror(
literal|"ioctl(FIONREAD)"
argument|); 					exit(-
literal|1
argument|); 				} 			} else { 				tr = (lseek(fd[i],
literal|0
argument|, SEEK_CUR)< sb.st_size); 				if (!tr&& !(opts& OPT_TAIL)) 					doread =
literal|0
argument|; 			} 			if (!tr) 				continue; 			nr += tr;  			tr = read_log(fd[i],&n, buf, sizeof(buf)); 			if (donehup) { 				donehup =
literal|0
argument|; 				if (newlog) { 					fclose(log); 					log = newlog; 					newlog = NULL; 				} 			}  			switch (tr) 			{ 			case -
literal|1
argument|: 				if (opts& OPT_SYSLOG) 					syslog(LOG_ERR,
literal|"read: %m\n"
argument|); 				else 					perror(
literal|"read"
argument|); 				doread =
literal|0
argument|; 				break; 			case
literal|1
argument|: 				if (opts& OPT_SYSLOG) 					syslog(LOG_ERR,
literal|"aborting logging\n"
argument|); 				else 					fprintf(log,
literal|"aborting logging\n"
argument|); 				doread =
literal|0
argument|; 				break; 			case
literal|2
argument|: 				break; 			case
literal|0
argument|: 				if (n>
literal|0
argument|) { 					print_log(fdt[i], log, buf, n); 					if (!(opts& OPT_SYSLOG)) 						fflush(log); 				} 				break; 			} 		} 		if (!nr&& ((opts& OPT_TAIL) || devices)) 			sleep(
literal|1
argument|); 	} 	exit(
literal|0
argument|);
comment|/* NOTREACHED */
argument|}
end_function

end_unit

