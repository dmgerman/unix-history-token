begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1993-1996 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  */
end_comment

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

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcpip.h>
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
file|"ip_compat.h"
end_include

begin_include
include|#
directive|include
file|"ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"ip_proxy.h"
end_include

begin_include
include|#
directive|include
file|"ip_nat.h"
end_include

begin_include
include|#
directive|include
file|"ip_state.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ipmon.c	1.21 6/5/96 (C)1993-1996 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: ipmon.c,v 2.0.2.9 1997/04/30 13:54:10 darrenr Exp $"
decl_stmt|;
end_decl_stmt

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
name|void
name|printiplci
name|__P
argument_list|(
operator|(
expr|struct
name|ipl_ci
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|resynclog
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|ipl_ci
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
name|int
name|read_ipflog
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
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|read_natlog
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
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|read_statelog
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
operator|,
name|FILE
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
name|u_short
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

begin_expr_stmt
specifier|static
name|int
argument_list|(
argument|*readfunc[
literal|3
argument|]
argument_list|)
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
operator|,
name|FILE
operator|*
operator|)
argument_list|)
operator|=
block|{
name|read_ipflog
block|,
name|read_natlog
block|,
name|read_statelog
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*printfunc[
literal|3
argument|]
argument_list|)
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
operator|=
block|{
name|print_ipflog
block|,
name|print_natlog
block|,
name|print_statelog
block|}
expr_stmt|;
end_expr_stmt

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
name|OPT_ALL
value|0x040
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
specifier|static
name|void
name|printiplci
parameter_list|(
name|icp
parameter_list|)
name|struct
name|ipl_ci
modifier|*
name|icp
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"sec %ld usec %ld hlen %d plen %d\n"
argument_list|,
name|icp
operator|->
name|sec
argument_list|,
name|icp
operator|->
name|usec
argument_list|,
name|icp
operator|->
name|hlen
argument_list|,
name|icp
operator|->
name|plen
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|resynclog
parameter_list|(
name|fd
parameter_list|,
name|iplcp
parameter_list|,
name|log
parameter_list|)
name|int
name|fd
decl_stmt|;
name|struct
name|ipl_ci
modifier|*
name|iplcp
decl_stmt|;
name|FILE
modifier|*
name|log
decl_stmt|;
block|{
name|time_t
name|now
decl_stmt|;
name|char
modifier|*
name|s
init|=
name|NULL
decl_stmt|;
name|int
name|len
decl_stmt|,
name|nr
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
name|s
condition|)
block|{
name|s
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|iplcp
operator|->
name|sec
expr_stmt|;
if|if
condition|(
name|opts
operator|&
name|OPT_SYSLOG
condition|)
block|{
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"Sync bytes:"
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|" %02x %02x %02x %02x"
argument_list|,
operator|*
name|s
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|1
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|2
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|3
operator|)
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|" %02x %02x %02x %02x\n"
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|4
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|5
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|6
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|7
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|log
argument_list|,
literal|"Sync bytes:"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|log
argument_list|,
literal|" %02x %02x %02x %02x"
argument_list|,
operator|*
name|s
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|1
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|2
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|3
operator|)
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|log
argument_list|,
literal|" %02x %02x %02x %02x\n"
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|4
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|5
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|6
operator|)
argument_list|,
operator|*
operator|(
name|s
operator|+
literal|7
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
do|do
block|{
name|s
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|iplcp
operator|->
name|sec
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|iplcp
operator|->
name|sec
argument_list|)
expr_stmt|;
while|while
condition|(
name|len
condition|)
block|{
switch|switch
condition|(
operator|(
name|nr
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
operator|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
case|case
literal|0
case|:
return|return;
default|default :
name|s
operator|+=
name|nr
expr_stmt|;
name|len
operator|-=
name|nr
expr_stmt|;
name|now
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
do|while
condition|(
operator|(
name|now
operator|<
name|iplcp
operator|->
name|sec
operator|)
operator|||
operator|(
operator|(
name|iplcp
operator|->
name|sec
operator|-
name|now
operator|)
operator|>
operator|(
literal|86400
operator|*
literal|5
operator|)
operator|)
condition|)
do|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|iplcp
operator|->
name|usec
argument_list|)
expr_stmt|;
while|while
condition|(
name|len
condition|)
block|{
switch|switch
condition|(
operator|(
name|nr
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
operator|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
case|case
literal|0
case|:
return|return;
default|default :
name|s
operator|+=
name|nr
expr_stmt|;
name|len
operator|-=
name|nr
expr_stmt|;
break|break;
block|}
block|}
block|}
do|while
condition|(
name|iplcp
operator|->
name|usec
operator|>
literal|1000000
condition|)
do|;
name|len
operator|=
sizeof|sizeof
argument_list|(
operator|*
name|iplcp
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|iplcp
operator|->
name|sec
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|iplcp
operator|->
name|usec
argument_list|)
expr_stmt|;
while|while
condition|(
name|len
condition|)
block|{
switch|switch
condition|(
operator|(
name|nr
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
operator|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
case|case
literal|0
case|:
return|return;
default|default :
name|s
operator|+=
name|nr
expr_stmt|;
name|len
operator|-=
name|nr
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|read_natlog
parameter_list|(
name|fd
parameter_list|,
name|lenp
parameter_list|,
name|buf
parameter_list|,
name|bufsize
parameter_list|,
name|log
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

begin_decl_stmt
name|FILE
modifier|*
name|log
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|len
decl_stmt|,
name|avail
init|=
literal|0
decl_stmt|,
name|want
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|natlog
argument_list|)
decl_stmt|;
operator|*
name|lenp
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|avail
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"ioctl(FIONREAD"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|avail
operator|<
name|want
condition|)
return|return
literal|2
return|;
while|while
condition|(
name|want
condition|)
block|{
name|len
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|want
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
condition|)
name|want
operator|-=
name|len
expr_stmt|;
else|else
break|break;
block|}
if|if
condition|(
operator|!
name|want
condition|)
block|{
operator|*
name|lenp
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|natlog
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
operator|!
name|len
condition|?
literal|2
else|:
operator|-
literal|1
return|;
block|}
end_block

begin_function
specifier|static
name|int
name|read_statelog
parameter_list|(
name|fd
parameter_list|,
name|lenp
parameter_list|,
name|buf
parameter_list|,
name|bufsize
parameter_list|,
name|log
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

begin_decl_stmt
name|FILE
modifier|*
name|log
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|len
decl_stmt|,
name|avail
init|=
literal|0
decl_stmt|,
name|want
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|ipslog
argument_list|)
decl_stmt|;
operator|*
name|lenp
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|avail
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"ioctl(FIONREAD"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|avail
operator|<
name|want
condition|)
return|return
literal|2
return|;
while|while
condition|(
name|want
condition|)
block|{
name|len
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|want
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
condition|)
name|want
operator|-=
name|len
expr_stmt|;
else|else
break|break;
block|}
if|if
condition|(
operator|!
name|want
condition|)
block|{
operator|*
name|lenp
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|ipslog
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
operator|!
name|len
condition|?
literal|2
else|:
operator|-
literal|1
return|;
block|}
end_block

begin_function
specifier|static
name|int
name|read_ipflog
parameter_list|(
name|fd
parameter_list|,
name|lenp
parameter_list|,
name|buf
parameter_list|,
name|bufsize
parameter_list|,
name|log
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

begin_decl_stmt
name|FILE
modifier|*
name|log
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|ipl_ci
modifier|*
name|icp
init|=
operator|(
expr|struct
name|ipl_ci
operator|*
operator|)
name|buf
decl_stmt|;
name|time_t
name|now
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|len
decl_stmt|,
name|n
init|=
name|bufsize
decl_stmt|,
name|tr
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|ipl_ci
argument_list|)
decl_stmt|,
name|nr
decl_stmt|;
if|if
condition|(
name|bufsize
operator|<
name|tr
condition|)
return|return
literal|1
return|;
for|for
control|(
name|s
operator|=
name|buf
init|;
operator|(
name|n
operator|>
literal|0
operator|)
operator|&&
operator|(
name|tr
operator|>
literal|0
operator|)
condition|;
name|s
operator|+=
name|nr
operator|,
name|n
operator|-=
name|nr
control|)
block|{
name|nr
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
name|tr
argument_list|)
expr_stmt|;
if|if
condition|(
name|nr
operator|>
literal|0
condition|)
name|tr
operator|-=
name|nr
expr_stmt|;
else|else
return|return
operator|-
literal|1
return|;
block|}
name|now
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|icp
operator|->
name|hlen
operator|>
literal|92
operator|)
operator|||
operator|(
name|now
operator|<
name|icp
operator|->
name|sec
operator|)
operator|||
operator|(
operator|(
name|now
operator|-
name|icp
operator|->
name|sec
operator|)
operator|>
operator|(
literal|86400
operator|*
literal|5
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|opts
operator|&
name|OPT_SYSLOG
condition|)
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"Out of sync! (1,%lx)\n"
argument_list|,
name|now
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|log
argument_list|,
literal|"Out of sync! (1,%lx)\n"
argument_list|,
name|now
argument_list|)
expr_stmt|;
name|dumphex
argument_list|(
name|log
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ipl_ci
argument_list|)
argument_list|)
expr_stmt|;
name|resynclog
argument_list|(
name|fd
argument_list|,
name|icp
argument_list|,
name|log
argument_list|)
expr_stmt|;
block|}
name|len
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
name|u_int
operator|)
name|icp
operator|->
name|plen
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|128
operator|||
name|len
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|opts
operator|&
name|OPT_SYSLOG
condition|)
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"Out of sync! (2,%d)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|log
argument_list|,
literal|"Out of sync! (2,%d)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|dumphex
argument_list|(
name|log
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ipl_ci
argument_list|)
argument_list|)
expr_stmt|;
name|resynclog
argument_list|(
name|fd
argument_list|,
name|icp
argument_list|,
name|log
argument_list|)
expr_stmt|;
block|}
name|tr
operator|=
name|icp
operator|->
name|hlen
operator|+
name|icp
operator|->
name|plen
expr_stmt|;
if|if
condition|(
name|n
operator|<
name|tr
condition|)
return|return
literal|1
return|;
for|for
control|(
init|;
operator|(
name|n
operator|>
literal|0
operator|)
operator|&&
operator|(
name|tr
operator|>
literal|0
operator|)
condition|;
name|s
operator|+=
name|nr
operator|,
name|n
operator|-=
name|nr
control|)
block|{
name|nr
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
name|tr
argument_list|)
expr_stmt|;
if|if
condition|(
name|nr
operator|>
literal|0
condition|)
name|tr
operator|-=
name|nr
expr_stmt|;
else|else
return|return
operator|-
literal|1
return|;
block|}
operator|*
name|lenp
operator|=
name|s
operator|-
name|buf
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
name|u_short
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
name|struct
name|servent
modifier|*
name|serv
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|pname
argument_list|,
literal|"%hu"
argument_list|,
name|htons
argument_list|(
name|port
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|res
condition|)
return|return
name|pname
return|;
name|serv
operator|=
name|getservbyport
argument_list|(
operator|(
name|int
operator|)
name|port
argument_list|,
name|proto
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|serv
condition|)
return|return
name|pname
return|;
return|return
name|serv
operator|->
name|s_name
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
name|fputs
argument_list|(
name|line
argument_list|,
name|stdout
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
name|fputs
argument_list|(
name|line
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
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
init|=
operator|(
expr|struct
name|natlog
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
decl_stmt|;
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
name|nl
operator|->
name|nl_tv
operator|.
name|tv_sec
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%2d/%02d/%4d "
argument_list|,
name|tm
operator|->
name|tm_mday
argument_list|,
name|tm
operator|->
name|tm_mon
operator|+
literal|1
argument_list|,
name|tm
operator|->
name|tm_year
operator|+
literal|1900
argument_list|)
expr_stmt|;
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%02d:%02d:%02d.%-.6ld @%hd "
argument_list|,
name|tm
operator|->
name|tm_hour
argument_list|,
name|tm
operator|->
name|tm_min
argument_list|,
name|tm
operator|->
name|tm_sec
argument_list|,
name|nl
operator|->
name|nl_tv
operator|.
name|tv_usec
argument_list|,
name|nl
operator|->
name|nl_rule
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
name|ISL_EXPIRE
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
argument|, line); }   static	void	print_statelog(log, buf, blen) FILE	*log; char	*buf; int	blen; { 	struct	ipslog *sl = (struct ipslog *)buf; 	struct	protoent *pr; 	char	*t = line
argument_list|,
argument|*proto
argument_list|,
argument|pname[
literal|6
argument|]; 	struct	tm	*tm; 	int	res;  	res = (opts& OPT_RESOLVE) ?
literal|1
argument|:
literal|0
argument|; 	tm = localtime((time_t *)&sl->isl_tv.tv_sec); 	if (!(opts& OPT_SYSLOG)) { 		(void) sprintf(t,
literal|"%2d/%02d/%4d "
argument|, 			tm->tm_mday, tm->tm_mon +
literal|1
argument|, tm->tm_year +
literal|1900
argument|); 		t += strlen(t); 	} 	(void) sprintf(t,
literal|"%02d:%02d:%02d.%-.6ld "
argument|, 		tm->tm_hour, tm->tm_min, tm->tm_sec, sl->isl_tv.tv_usec); 	t += strlen(t);  	if (sl->isl_type == ISL_NEW) 		strcpy(t,
literal|"STATE:NEW "
argument|); 	else if (sl->isl_type == ISL_EXPIRE) 		strcpy(t,
literal|"STATE:EXPIRE "
argument|); 	else 		sprintf(t,
literal|"Type: %d "
argument|, sl->isl_type); 	t += strlen(t);  	pr = getprotobynumber((int)sl->isl_p); 	if (!pr) { 		proto = pname; 		sprintf(proto,
literal|"%d"
argument|, (u_int)sl->isl_p); 	} else 		proto = pr->p_name;  	if (sl->isl_p == IPPROTO_TCP || sl->isl_p == IPPROTO_UDP) { 		(void) sprintf(t,
literal|"%s,%s -> "
argument|, 			hostname(res, sl->isl_src), 			portname(res, proto, sl->isl_sport)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s,%s PR %s"
argument|, 			hostname(res, sl->isl_dst), 			portname(res, proto, sl->isl_dport), proto); 	} else if (sl->isl_p == IPPROTO_ICMP) { 		(void) sprintf(t,
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
argument|, line); }   static	void	print_ipflog(log, buf, blen) FILE	*log; char	*buf; int	blen; { 	struct	protoent *pr; 	struct	tcphdr	*tp; 	struct	icmp	*ic; 	struct	ip	*ipc; 	struct	tm	*tm; 	char	c[
literal|3
argument|], pname[
literal|8
argument|], *t, *proto; 	u_short	hl, p; 	int	i, lvl, res;
if|#
directive|if
operator|!
name|SOLARIS
operator|&&
operator|!
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
argument|int	len;
endif|#
directive|endif
argument|struct	ip	*ip; 	struct	ipl_ci	*lp;  	lp = (struct ipl_ci *)buf; 	ip = (struct ip *)(buf + sizeof(*lp)); 	res = (opts& OPT_RESOLVE) ?
literal|1
argument|:
literal|0
argument|; 	t = line; 	*t =
literal|'\0'
argument|; 	hl = (ip->ip_hl<<
literal|2
argument|); 	p = (u_short)ip->ip_p; 	tm = localtime((time_t *)&lp->sec); 	if (!(opts& OPT_SYSLOG)) { 		(void) sprintf(t,
literal|"%2d/%02d/%4d "
argument|, 			tm->tm_mday, tm->tm_mon +
literal|1
argument|, tm->tm_year +
literal|1900
argument|); 		t += strlen(t); 	}
if|#
directive|if
name|SOLARIS
operator|||
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
argument|(void) sprintf(t,
literal|"%02d:%02d:%02d.%-.6ld %.*s @%hd "
argument|, 		tm->tm_hour, tm->tm_min, tm->tm_sec, lp->usec, 		(int)sizeof(lp->ifname), lp->ifname, lp->rule);
else|#
directive|else
argument|for (len =
literal|0
argument|; len<
literal|3
argument|; len++) 		if (!lp->ifname[len]) 			break; 	if (lp->ifname[len]) 		len++; 	(void) sprintf(t,
literal|"%02d:%02d:%02d.%-.6ld %*.*s%ld @%hd "
argument|, 		tm->tm_hour, tm->tm_min, tm->tm_sec, lp->usec, 		len, len, lp->ifname, lp->unit, lp->rule);
endif|#
directive|endif
argument|pr = getprotobynumber((int)p); 	if (!pr) { 		proto = pname; 		sprintf(proto,
literal|"%d"
argument|, (u_int)p); 	} else 		proto = pr->p_name;   	if (lp->flags& (FI_SHORT<<
literal|20
argument|)) { 		c[
literal|0
argument|] =
literal|'S'
argument|; 		lvl = LOG_ERR; 	} else if (lp->flags& FR_PASS) { 		if (lp->flags& FR_LOGP) 			c[
literal|0
argument|] =
literal|'p'
argument|; 		else 			c[
literal|0
argument|] =
literal|'P'
argument|; 		lvl = LOG_NOTICE; 	} else if (lp->flags& FR_BLOCK) { 		if (lp->flags& FR_LOGB) 			c[
literal|0
argument|] =
literal|'b'
argument|; 		else 			c[
literal|0
argument|] =
literal|'B'
argument|; 		lvl = LOG_WARNING; 	} else if (lp->flags& FF_LOGNOMATCH) { 		c[
literal|0
argument|] =
literal|'n'
argument|; 		lvl = LOG_NOTICE; 	} else { 		c[
literal|0
argument|] =
literal|'L'
argument|; 		lvl = LOG_INFO; 	} 	c[
literal|1
argument|] =
literal|' '
argument|; 	c[
literal|2
argument|] =
literal|'\0'
argument|; 	(void) strcat(line, c); 	t = line + strlen(line);  	if ((p == IPPROTO_TCP || p == IPPROTO_UDP)&& !(ip->ip_off&
literal|0x1fff
argument|)) { 		tp = (struct tcphdr *)((char *)ip + hl); 		if (!(lp->flags& (FI_SHORT<<
literal|16
argument|))) { 			(void) sprintf(t,
literal|"%s,%s -> "
argument|, 				hostname(res, ip->ip_src), 				portname(res, proto, tp->th_sport)); 			t += strlen(t); 			(void) sprintf(t,
literal|"%s,%s PR %s len %hu %hu "
argument|, 				hostname(res, ip->ip_dst), 				portname(res, proto, tp->th_dport), 				proto, hl, ip->ip_len); 			t += strlen(t);  			if (p == IPPROTO_TCP) { 				*t++ =
literal|'-'
argument|; 				for (i =
literal|0
argument|; tcpfl[i].value; i++) 					if (tp->th_flags& tcpfl[i].value) 						*t++ = tcpfl[i].flag; 			} 			if (opts& OPT_VERBOSE) { 				(void) sprintf(t,
literal|" %lu %lu %hu"
argument|, 					(u_long)tp->th_seq, 					(u_long)tp->th_ack, tp->th_win); 				t += strlen(t); 			} 			*t =
literal|'\0'
argument|; 		} else { 			(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, ip->ip_src)); 			t += strlen(t); 			(void) sprintf(t,
literal|"%s PR %s len %hu %hu"
argument|, 				hostname(res, ip->ip_dst), proto, 				hl, ip->ip_len); 		} 	} else if (p == IPPROTO_ICMP) { 		ic = (struct icmp *)((char *)ip + hl); 		(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, ip->ip_src)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s PR icmp len %hu (%hu) icmp %d/%d"
argument|, 			hostname(res, ip->ip_dst), hl, 			ip->ip_len, ic->icmp_type, ic->icmp_code); 		if (ic->icmp_type == ICMP_UNREACH || 		    ic->icmp_type == ICMP_SOURCEQUENCH || 		    ic->icmp_type == ICMP_PARAMPROB || 		    ic->icmp_type == ICMP_REDIRECT || 		    ic->icmp_type == ICMP_TIMXCEED) { 			ipc =&ic->icmp_ip; 			tp = (struct tcphdr *)((char *)ipc + hl);  			p = (u_short)ipc->ip_p; 			pr = getprotobynumber((int)p); 			if (!pr) { 				proto = pname; 				(void) sprintf(proto,
literal|"%d"
argument|, (int)p); 			} else 				proto = pr->p_name;  			t += strlen(t); 			(void) sprintf(t,
literal|" for %s,%s -"
argument|, 				hostname(res, ipc->ip_src), 				portname(res, proto, tp->th_sport)); 			t += strlen(t); 			(void) sprintf(t,
literal|" %s,%s PR %s len %hu %hu"
argument|, 				hostname(res, ipc->ip_dst), 				portname(res, proto, tp->th_dport), 				proto, ipc->ip_hl<<
literal|2
argument|, ipc->ip_len); 		} 	} else { 		(void) sprintf(t,
literal|"%s -> "
argument|, hostname(res, ip->ip_src)); 		t += strlen(t); 		(void) sprintf(t,
literal|"%s PR %s len %hu (%hu)"
argument|, 			hostname(res, ip->ip_dst), proto, hl, ip->ip_len); 		t += strlen(t); 		if (ip->ip_off&
literal|0x1fff
argument|) 			(void) sprintf(t,
literal|" frag %s%s%hu@%hu"
argument|, 				ip->ip_off& IP_MF ?
literal|"+"
argument|:
literal|""
argument|, 				ip->ip_off& IP_DF ?
literal|"-"
argument|:
literal|""
argument|, 				ip->ip_len - hl, (ip->ip_off&
literal|0x1fff
argument|)<<
literal|3
argument|); 	} 	t += strlen(t);  	if (lp->flags& FR_KEEPSTATE) { 		(void) strcpy(t,
literal|" K-S"
argument|); 		t += strlen(t); 	}  	if (lp->flags& FR_KEEPFRAG) { 		(void) strcpy(t,
literal|" K-F"
argument|); 		t += strlen(t); 	}  	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	if (opts& OPT_SYSLOG) 		syslog(lvl,
literal|"%s"
argument|, line); 	else 		(void) fprintf(log,
literal|"%s"
argument|, line); 	if (opts& OPT_HEXHDR) 		dumphex(log, buf, sizeof(struct ipl_ci)); 	if (opts& OPT_HEXBODY) 		dumphex(log, (u_char *)ip, lp->plen + lp->hlen); }   void static usage(prog) char *prog; { 	fprintf(stderr,
literal|"%s: [-NFhstvxX] [-f<logfile>]\n"
argument|, prog); 	exit(
literal|1
argument|); }   void flushlogs(file, log) char *file; FILE *log; { 	int	fd, flushed =
literal|0
argument|;  	if ((fd = open(file, O_RDWR)) == -
literal|1
argument|) { 		(void) fprintf(stderr,
literal|"%s: "
argument|, file); 		perror(
literal|"open"
argument|); 		exit(-
literal|1
argument|); 	}  	if (ioctl(fd, SIOCIPFFB,&flushed) ==
literal|0
argument|) { 		printf(
literal|"%d bytes flushed from log buffer\n"
argument|, 			flushed); 		fflush(stdout); 	} else 		perror(
literal|"SIOCIPFFB"
argument|); 	(void) close(fd);  	if (flushed) { 		if (opts& OPT_SYSLOG) 			syslog(LOG_INFO,
literal|"%d bytes flushed from log\n"
argument|, 				flushed); 		else 			fprintf(log,
literal|"%d bytes flushed from log\n"
argument|, flushed); 	} }   int main(argc, argv) int argc; char *argv[]; { 	struct	stat	stat; 	FILE	*log = NULL; 	int	fd[
literal|3
argument|] = {-
literal|1
argument|, -
literal|1
argument|, -
literal|1
argument|}, flushed =
literal|0
argument|, doread, n, i, nfd =
literal|1
argument|; 	int	tr, nr, regular; 	int	fdt[
literal|3
argument|] = {IPL_LOGIPF, IPL_LOGNAT, IPL_LOGSTATE}; 	char	buf[
literal|512
argument|], c, *iplfile = IPL_NAME; 	extern	int	optind; 	extern	char	*optarg;  	while ((c = getopt(argc, argv,
literal|"?af:FhnNsStvxX"
argument|)) != -
literal|1
argument|) 		switch (c) 		{ 		case
literal|'a'
argument|: 			opts |= OPT_ALL; 			nfd =
literal|3
argument|; 			break; 		case
literal|'f'
argument|: 			iplfile = optarg; 			break; 		case
literal|'F'
argument|: 			if (!(opts& OPT_ALL)) 				flushlogs(iplfile, log); 			else { 				flushlogs(IPL_NAME, log); 				flushlogs(IPL_NAT, log); 				flushlogs(IPL_STATE, log); 			} 			break; 		case
literal|'n'
argument|: 			opts |= OPT_RESOLVE; 			break; 		case
literal|'N'
argument|: 			opts |= OPT_NAT; 			fdt[
literal|0
argument|] = IPL_LOGNAT; 			readfunc[
literal|0
argument|] = read_natlog; 			printfunc[
literal|0
argument|] = print_natlog; 			break; 		case
literal|'s'
argument|: 			openlog(argv[
literal|0
argument|], LOG_NDELAY|LOG_PID, LOGFAC); 			opts |= OPT_SYSLOG; 			break; 		case
literal|'S'
argument|: 			opts |= OPT_STATE; 			fdt[
literal|0
argument|] = IPL_LOGSTATE; 			readfunc[
literal|0
argument|] = read_statelog; 			printfunc[
literal|0
argument|] = print_statelog; 			break; 		case
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
argument|]); 		}  	if ((fd[
literal|0
argument|] == -
literal|1
argument|)&& (fd[
literal|0
argument|] = open(iplfile, O_RDONLY)) == -
literal|1
argument|) { 		(void) fprintf(stderr,
literal|"%s: "
argument|, iplfile); 		perror(
literal|"open"
argument|); 		exit(-
literal|1
argument|); 	}  	if ((opts& OPT_ALL)) { 		if ((fd[
literal|1
argument|] = open(IPL_NAT, O_RDONLY)) == -
literal|1
argument|) { 			(void) fprintf(stderr,
literal|"%s: "
argument|, IPL_NAT); 			perror(
literal|"open"
argument|); 			exit(-
literal|1
argument|); 		} 		if ((fd[
literal|2
argument|] = open(IPL_STATE, O_RDONLY)) == -
literal|1
argument|) { 			(void) fprintf(stderr,
literal|"%s: "
argument|, IPL_STATE); 			perror(
literal|"open"
argument|); 			exit(-
literal|1
argument|); 		} 	}  	if (!(opts& OPT_SYSLOG)) { 		log = argv[optind] ? fopen(argv[optind],
literal|"a"
argument|) : stdout; 		setvbuf(log, NULL, _IONBF,
literal|0
argument|); 	}  	if (fstat(fd[
literal|0
argument|],&stat) == -
literal|1
argument|) { 		fprintf(stderr,
literal|"%s :"
argument|, iplfile); 		perror(
literal|"fstat"
argument|); 		exit(-
literal|1
argument|); 	}  	regular = !S_ISCHR(stat.st_mode);  	for (doread =
literal|1
argument|; doread; ) { 		nr =
literal|0
argument|;  		for (i =
literal|0
argument|; i< nfd; i++) { 			tr =
literal|0
argument|; 			if (!regular) { 				if (ioctl(fd[i], FIONREAD,&tr) == -
literal|1
argument|) { 					perror(
literal|"ioctl(FIONREAD)"
argument|); 					exit(-
literal|1
argument|); 				} 			} else { 				tr = (lseek(fd[i],
literal|0
argument|, SEEK_CUR)< 				      stat.st_size); 				if (!tr&& !(opts& OPT_TAIL)) 					doread =
literal|0
argument|; 			} 			if (!tr) 				continue; 			nr += tr;  			tr = (*readfunc[i])(fd[i],&n, buf, sizeof(buf), log); 			switch (tr) 			{ 			case -
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
argument|) { 					(*printfunc[i])(log, buf, n); 					if (!(opts& OPT_SYSLOG)) 						fflush(log); 				} 				break; 			} 		} 		if (!nr&& regular&& (opts& OPT_TAIL)) 			sleep(
literal|1
argument|); 	} 	exit(
literal|0
argument|);
comment|/* NOTREACHED */
argument|}
end_function

end_unit

