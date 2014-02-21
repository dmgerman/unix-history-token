begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"ipmon.h"
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
literal|"@(#)ipmon.c	1.21 6/5/96 (C)1993-2000 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$Id$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipmon_saver_t
name|executesaver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipmon_saver_t
name|filesaver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipmon_saver_t
name|nothingsaver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipmon_saver_t
name|snmpv1saver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipmon_saver_t
name|snmpv2saver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipmon_saver_t
name|syslogsaver
decl_stmt|;
end_decl_stmt

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

begin_typedef
typedef|typedef
struct|struct
name|logsource
block|{
name|int
name|fd
decl_stmt|;
name|int
name|logtype
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|regular
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|logsource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|config
block|{
name|int
name|opts
decl_stmt|;
name|int
name|maxfd
decl_stmt|;
name|logsource_t
name|logsrc
index|[
literal|3
index|]
decl_stmt|;
name|fd_set
name|fdmr
decl_stmt|;
name|FILE
modifier|*
name|blog
decl_stmt|;
name|char
modifier|*
name|bfile
decl_stmt|;
name|FILE
modifier|*
name|log
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|cfile
decl_stmt|;
block|}
name|config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|icmp_subtype
block|{
name|int
name|ist_val
decl_stmt|;
name|char
modifier|*
name|ist_name
decl_stmt|;
block|}
name|icmp_subtype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|icmp_type
block|{
name|int
name|it_val
decl_stmt|;
name|struct
name|icmp_subtype
modifier|*
name|it_subtable
decl_stmt|;
name|size_t
name|it_stsize
decl_stmt|;
name|char
modifier|*
name|it_name
decl_stmt|;
block|}
name|icmp_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IST_SZ
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x)/sizeof(icmp_subtype_t))
end_define

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
name|TH_ECN
block|,
literal|'E'
block|}
block|,
block|{
name|TH_CWR
block|,
literal|'C'
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
name|char
modifier|*
name|reasons
index|[]
init|=
block|{
literal|"filter-rule"
block|,
literal|"log-or-block_1"
block|,
literal|"pps-rate"
block|,
literal|"jumbogram"
block|,
literal|"makefrip-fail"
block|,
literal|"state_add-fail"
block|,
literal|"updateipid-fail"
block|,
literal|"log-or-block_2"
block|,
literal|"decap-fail"
block|,
literal|"auth_new-fail"
block|,
literal|"auth_captured"
block|,
literal|"coalesce-fail"
block|,
literal|"pullup-fail"
block|,
literal|"auth-feedback"
block|,
literal|"bad-frag"
block|,
literal|"natv4_out-fail"
block|,
literal|"natv4_in-fail"
block|,
literal|"natv6_out-fail"
block|,
literal|"natv6_in-fail"
block|, }
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MENTAT
end_ifdef

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
name|config_t
operator|*
operator|,
name|logsource_t
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
name|config_t
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
name|config_t
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
name|config_t
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
specifier|static
name|char
modifier|*
name|icmpname
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|icmpname6
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_type_t
modifier|*
name|find_icmptype
name|__P
argument_list|(
operator|(
name|int
operator|,
name|icmp_type_t
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
modifier|*
name|find_icmpsubtype
name|__P
argument_list|(
operator|(
name|int
operator|,
name|icmp_subtype_t
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|tm
modifier|*
name|get_tm
name|__P
argument_list|(
operator|(
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|struct
name|tm
modifier|*
name|get_tm
name|__P
argument_list|(
operator|(
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|portlocalname
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
name|getlocalproto
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
name|void
name|openlogs
name|__P
argument_list|(
operator|(
name|config_t
operator|*
name|conf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|read_loginfo
name|__P
argument_list|(
operator|(
name|config_t
operator|*
name|conf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|initconfig
name|__P
argument_list|(
operator|(
name|config_t
operator|*
name|conf
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
name|HOSTNAMEV4
parameter_list|(
name|b
parameter_list|)
value|hostname(AF_INET, (u_32_t *)&(b))
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

begin_decl_stmt
name|int
name|logfac
init|=
name|LOGFAC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipmonopts
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opts
init|=
name|OPT_NORESOLVE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|use_inet6
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmpunreachnames
index|[]
init|=
block|{
block|{
name|ICMP_UNREACH_NET
block|,
literal|"net"
block|}
block|,
block|{
name|ICMP_UNREACH_HOST
block|,
literal|"host"
block|}
block|,
block|{
name|ICMP_UNREACH_PROTOCOL
block|,
literal|"protocol"
block|}
block|,
block|{
name|ICMP_UNREACH_PORT
block|,
literal|"port"
block|}
block|,
block|{
name|ICMP_UNREACH_NEEDFRAG
block|,
literal|"needfrag"
block|}
block|,
block|{
name|ICMP_UNREACH_SRCFAIL
block|,
literal|"srcfail"
block|}
block|,
block|{
name|ICMP_UNREACH_NET_UNKNOWN
block|,
literal|"net_unknown"
block|}
block|,
block|{
name|ICMP_UNREACH_HOST_UNKNOWN
block|,
literal|"host_unknown"
block|}
block|,
block|{
name|ICMP_UNREACH_NET
block|,
literal|"isolated"
block|}
block|,
block|{
name|ICMP_UNREACH_NET_PROHIB
block|,
literal|"net_prohib"
block|}
block|,
block|{
name|ICMP_UNREACH_NET_PROHIB
block|,
literal|"host_prohib"
block|}
block|,
block|{
name|ICMP_UNREACH_TOSNET
block|,
literal|"tosnet"
block|}
block|,
block|{
name|ICMP_UNREACH_TOSHOST
block|,
literal|"toshost"
block|}
block|,
block|{
name|ICMP_UNREACH_ADMIN_PROHIBIT
block|,
literal|"admin_prohibit"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|redirectnames
index|[]
init|=
block|{
block|{
name|ICMP_REDIRECT_NET
block|,
literal|"net"
block|}
block|,
block|{
name|ICMP_REDIRECT_HOST
block|,
literal|"host"
block|}
block|,
block|{
name|ICMP_REDIRECT_TOSNET
block|,
literal|"tosnet"
block|}
block|,
block|{
name|ICMP_REDIRECT_TOSHOST
block|,
literal|"toshost"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|timxceednames
index|[]
init|=
block|{
block|{
name|ICMP_TIMXCEED_INTRANS
block|,
literal|"transit"
block|}
block|,
block|{
name|ICMP_TIMXCEED_REASS
block|,
literal|"reassem"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|paramnames
index|[]
init|=
block|{
block|{
name|ICMP_PARAMPROB_ERRATPTR
block|,
literal|"errata_pointer"
block|}
block|,
block|{
name|ICMP_PARAMPROB_OPTABSENT
block|,
literal|"optmissing"
block|}
block|,
block|{
name|ICMP_PARAMPROB_LENGTH
block|,
literal|"length"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_type_t
name|icmptypes4
index|[]
init|=
block|{
block|{
name|ICMP_ECHOREPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"echoreply"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|,
block|{
name|ICMP_UNREACH
block|,
name|icmpunreachnames
block|,
name|IST_SZ
argument_list|(
name|icmpunreachnames
argument_list|)
block|,
literal|"unreach"
block|}
block|,
block|{
name|ICMP_SOURCEQUENCH
block|,
name|NULL
block|,
literal|0
block|,
literal|"sourcequench"
block|}
block|,
block|{
name|ICMP_REDIRECT
block|,
name|redirectnames
block|,
name|IST_SZ
argument_list|(
name|redirectnames
argument_list|)
block|,
literal|"redirect"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|,
block|{
name|ICMP_ECHO
block|,
name|NULL
block|,
literal|0
block|,
literal|"echo"
block|}
block|,
block|{
name|ICMP_ROUTERADVERT
block|,
name|NULL
block|,
literal|0
block|,
literal|"routeradvert"
block|}
block|,
block|{
name|ICMP_ROUTERSOLICIT
block|,
name|NULL
block|,
literal|0
block|,
literal|"routersolicit"
block|}
block|,
block|{
name|ICMP_TIMXCEED
block|,
name|timxceednames
block|,
name|IST_SZ
argument_list|(
name|timxceednames
argument_list|)
block|,
literal|"timxceed"
block|}
block|,
block|{
name|ICMP_PARAMPROB
block|,
name|paramnames
block|,
name|IST_SZ
argument_list|(
name|paramnames
argument_list|)
block|,
literal|"paramprob"
block|}
block|,
block|{
name|ICMP_TSTAMP
block|,
name|NULL
block|,
literal|0
block|,
literal|"timestamp"
block|}
block|,
block|{
name|ICMP_TSTAMPREPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"timestampreply"
block|}
block|,
block|{
name|ICMP_IREQ
block|,
name|NULL
block|,
literal|0
block|,
literal|"inforeq"
block|}
block|,
block|{
name|ICMP_IREQREPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"inforeply"
block|}
block|,
block|{
name|ICMP_MASKREQ
block|,
name|NULL
block|,
literal|0
block|,
literal|"maskreq"
block|}
block|,
block|{
name|ICMP_MASKREPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"maskreply"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmpredirect6
index|[]
init|=
block|{
block|{
name|ICMP6_DST_UNREACH_NOROUTE
block|,
literal|"noroute"
block|}
block|,
block|{
name|ICMP6_DST_UNREACH_ADMIN
block|,
literal|"admin"
block|}
block|,
block|{
name|ICMP6_DST_UNREACH_NOTNEIGHBOR
block|,
literal|"neighbour"
block|}
block|,
block|{
name|ICMP6_DST_UNREACH_ADDR
block|,
literal|"address"
block|}
block|,
block|{
name|ICMP6_DST_UNREACH_NOPORT
block|,
literal|"noport"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmptimexceed6
index|[]
init|=
block|{
block|{
name|ICMP6_TIME_EXCEED_TRANSIT
block|,
literal|"intransit"
block|}
block|,
block|{
name|ICMP6_TIME_EXCEED_REASSEMBLY
block|,
literal|"reassem"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmpparamprob6
index|[]
init|=
block|{
block|{
name|ICMP6_PARAMPROB_HEADER
block|,
literal|"header"
block|}
block|,
block|{
name|ICMP6_PARAMPROB_NEXTHEADER
block|,
literal|"nextheader"
block|}
block|,
block|{
name|ICMP6_PARAMPROB_OPTION
block|,
literal|"option"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmpquerysubject6
index|[]
init|=
block|{
block|{
name|ICMP6_NI_SUBJ_IPV6
block|,
literal|"ipv6"
block|}
block|,
block|{
name|ICMP6_NI_SUBJ_FQDN
block|,
literal|"fqdn"
block|}
block|,
block|{
name|ICMP6_NI_SUBJ_IPV4
block|,
literal|"ipv4"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmpnodeinfo6
index|[]
init|=
block|{
block|{
name|ICMP6_NI_SUCCESS
block|,
literal|"success"
block|}
block|,
block|{
name|ICMP6_NI_REFUSED
block|,
literal|"refused"
block|}
block|,
block|{
name|ICMP6_NI_UNKNOWN
block|,
literal|"unknown"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_subtype_t
name|icmprenumber6
index|[]
init|=
block|{
block|{
name|ICMP6_ROUTER_RENUMBERING_COMMAND
block|,
literal|"command"
block|}
block|,
block|{
name|ICMP6_ROUTER_RENUMBERING_RESULT
block|,
literal|"result"
block|}
block|,
block|{
name|ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET
block|,
literal|"seqnum_reset"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|icmp_type_t
name|icmptypes6
index|[]
init|=
block|{
block|{
literal|0
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|,
block|{
name|ICMP6_DST_UNREACH
block|,
name|icmpredirect6
block|,
name|IST_SZ
argument_list|(
name|icmpredirect6
argument_list|)
block|,
literal|"unreach"
block|}
block|,
block|{
name|ICMP6_PACKET_TOO_BIG
block|,
name|NULL
block|,
literal|0
block|,
literal|"toobig"
block|}
block|,
block|{
name|ICMP6_TIME_EXCEEDED
block|,
name|icmptimexceed6
block|,
name|IST_SZ
argument_list|(
name|icmptimexceed6
argument_list|)
block|,
literal|"timxceed"
block|}
block|,
block|{
name|ICMP6_PARAM_PROB
block|,
name|icmpparamprob6
block|,
name|IST_SZ
argument_list|(
name|icmpparamprob6
argument_list|)
block|,
literal|"paramprob"
block|}
block|,
block|{
name|ICMP6_ECHO_REQUEST
block|,
name|NULL
block|,
literal|0
block|,
literal|"echo"
block|}
block|,
block|{
name|ICMP6_ECHO_REPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"echoreply"
block|}
block|,
block|{
name|ICMP6_MEMBERSHIP_QUERY
block|,
name|icmpquerysubject6
block|,
name|IST_SZ
argument_list|(
name|icmpquerysubject6
argument_list|)
block|,
literal|"groupmemberquery"
block|}
block|,
block|{
name|ICMP6_MEMBERSHIP_REPORT
block|,
name|NULL
block|,
literal|0
block|,
literal|"groupmemberreport"
block|}
block|,
block|{
name|ICMP6_MEMBERSHIP_REDUCTION
block|,
name|NULL
block|,
literal|0
block|,
literal|"groupmemberterm"
block|}
block|,
block|{
name|ND_ROUTER_SOLICIT
block|,
name|NULL
block|,
literal|0
block|,
literal|"routersolicit"
block|}
block|,
block|{
name|ND_ROUTER_ADVERT
block|,
name|NULL
block|,
literal|0
block|,
literal|"routeradvert"
block|}
block|,
block|{
name|ND_NEIGHBOR_SOLICIT
block|,
name|NULL
block|,
literal|0
block|,
literal|"neighborsolicit"
block|}
block|,
block|{
name|ND_NEIGHBOR_ADVERT
block|,
name|NULL
block|,
literal|0
block|,
literal|"neighboradvert"
block|}
block|,
block|{
name|ND_REDIRECT
block|,
name|NULL
block|,
literal|0
block|,
literal|"redirect"
block|}
block|,
block|{
name|ICMP6_ROUTER_RENUMBERING
block|,
name|icmprenumber6
block|,
name|IST_SZ
argument_list|(
name|icmprenumber6
argument_list|)
block|,
literal|"routerrenumber"
block|}
block|,
block|{
name|ICMP6_WRUREQUEST
block|,
name|NULL
block|,
literal|0
block|,
literal|"whoareyourequest"
block|}
block|,
block|{
name|ICMP6_WRUREPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"whoareyoureply"
block|}
block|,
block|{
name|ICMP6_FQDN_QUERY
block|,
name|NULL
block|,
literal|0
block|,
literal|"fqdnquery"
block|}
block|,
block|{
name|ICMP6_FQDN_REPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"fqdnreply"
block|}
block|,
block|{
name|ICMP6_NI_QUERY
block|,
name|icmpnodeinfo6
block|,
name|IST_SZ
argument_list|(
name|icmpnodeinfo6
argument_list|)
block|,
literal|"nodeinforequest"
block|}
block|,
block|{
name|ICMP6_NI_REPLY
block|,
name|NULL
block|,
literal|0
block|,
literal|"nodeinforeply"
block|}
block|,
block|{
name|MLD6_MTRACE_RESP
block|,
name|NULL
block|,
literal|0
block|,
literal|"mtraceresponse"
block|}
block|,
block|{
name|MLD6_MTRACE
block|,
name|NULL
block|,
literal|0
block|,
literal|"mtracerequest"
block|}
block|,
block|{
operator|-
literal|2
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|icmp_subtype_t
modifier|*
name|find_icmpsubtype
parameter_list|(
name|type
parameter_list|,
name|table
parameter_list|,
name|tablesz
parameter_list|)
name|int
name|type
decl_stmt|;
name|icmp_subtype_t
modifier|*
name|table
decl_stmt|;
name|size_t
name|tablesz
decl_stmt|;
block|{
name|icmp_subtype_t
modifier|*
name|ist
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|tablesz
operator|<
literal|2
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|(
name|type
operator|<
literal|0
operator|)
operator|||
operator|(
name|type
operator|>
name|table
index|[
name|tablesz
operator|-
literal|2
index|]
operator|.
name|ist_val
operator|)
condition|)
return|return
name|NULL
return|;
name|i
operator|=
name|type
expr_stmt|;
if|if
condition|(
name|table
index|[
name|type
index|]
operator|.
name|ist_val
operator|==
name|type
condition|)
return|return
name|table
operator|+
name|type
return|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|ist
operator|=
name|table
init|;
name|ist
operator|->
name|ist_val
operator|!=
operator|-
literal|2
condition|;
name|i
operator|++
operator|,
name|ist
operator|++
control|)
if|if
condition|(
name|ist
operator|->
name|ist_val
operator|==
name|type
condition|)
return|return
name|ist
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|icmp_type_t
modifier|*
name|find_icmptype
parameter_list|(
name|type
parameter_list|,
name|table
parameter_list|,
name|tablesz
parameter_list|)
name|int
name|type
decl_stmt|;
name|icmp_type_t
modifier|*
name|table
decl_stmt|;
name|size_t
name|tablesz
decl_stmt|;
block|{
name|icmp_type_t
modifier|*
name|it
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|tablesz
operator|<
literal|2
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|(
name|type
operator|<
literal|0
operator|)
operator|||
operator|(
name|type
operator|>
name|table
index|[
name|tablesz
operator|-
literal|2
index|]
operator|.
name|it_val
operator|)
condition|)
return|return
name|NULL
return|;
name|i
operator|=
name|type
expr_stmt|;
if|if
condition|(
name|table
index|[
name|type
index|]
operator|.
name|it_val
operator|==
name|type
condition|)
return|return
name|table
operator|+
name|type
return|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|it
operator|=
name|table
init|;
name|it
operator|->
name|it_val
operator|!=
operator|-
literal|2
condition|;
name|i
operator|++
operator|,
name|it
operator|++
control|)
if|if
condition|(
name|it
operator|->
name|it_val
operator|==
name|type
condition|)
return|return
name|it
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|handlehup
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|handlehup
argument_list|)
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
name|int
name|port
decl_stmt|,
name|i
decl_stmt|;
if|if
condition|(
name|protocols
operator|!=
name|NULL
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|protocols
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|protocols
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|protocols
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
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
operator|&&
name|protocols
index|[
name|p
operator|->
name|p_proto
index|]
operator|==
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
if|if
condition|(
name|protocols
index|[
literal|0
index|]
condition|)
name|free
argument_list|(
name|protocols
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|protocols
index|[
literal|0
index|]
operator|=
name|strdup
argument_list|(
literal|"ip"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_AIX51
argument_list|)
if|if
condition|(
name|protocols
index|[
literal|252
index|]
condition|)
name|free
argument_list|(
name|protocols
index|[
literal|252
index|]
argument_list|)
expr_stmt|;
name|protocols
index|[
literal|252
index|]
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|udp_ports
operator|!=
name|NULL
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|65536
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|udp_ports
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|udp_ports
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|udp_ports
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
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
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|65536
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|tcp_ports
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|tcp_ports
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|tcp_ports
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
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
name|ntohs
argument_list|(
name|s
operator|->
name|s_port
argument_list|)
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
name|ntohs
argument_list|(
name|s
operator|->
name|s_port
argument_list|)
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
if|if
condition|(
name|tab
operator|!=
name|NULL
condition|)
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
name|getlocalproto
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
if|if
condition|(
name|bufsize
operator|>
name|IPFILTER_LOGSIZE
condition|)
name|bufsize
operator|=
name|IPFILTER_LOGSIZE
expr_stmt|;
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
name|portlocalname
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
name|ipmonopts
operator|&
name|IPMON_PORTNUM
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
name|char
modifier|*
name|icmpname
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
name|u_int
name|type
decl_stmt|;
name|u_int
name|code
decl_stmt|;
block|{
specifier|static
name|char
name|name
index|[
literal|80
index|]
decl_stmt|;
name|icmp_subtype_t
modifier|*
name|ist
decl_stmt|;
name|icmp_type_t
modifier|*
name|it
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|NULL
expr_stmt|;
name|it
operator|=
name|find_icmptype
argument_list|(
name|type
argument_list|,
name|icmptypes4
argument_list|,
sizeof|sizeof
argument_list|(
name|icmptypes4
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|it
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|it
operator|!=
name|NULL
condition|)
name|s
operator|=
name|it
operator|->
name|it_name
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"icmptype(%d)/"
argument_list|,
name|type
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"%s/"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|ist
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|it
operator|!=
name|NULL
operator|&&
name|it
operator|->
name|it_subtable
operator|!=
name|NULL
condition|)
name|ist
operator|=
name|find_icmpsubtype
argument_list|(
name|code
argument_list|,
name|it
operator|->
name|it_subtable
argument_list|,
name|it
operator|->
name|it_stsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|ist
operator|!=
name|NULL
operator|&&
name|ist
operator|->
name|ist_name
operator|!=
name|NULL
condition|)
name|strcat
argument_list|(
name|name
argument_list|,
name|ist
operator|->
name|ist_name
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|name
operator|+
name|strlen
argument_list|(
name|name
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
name|code
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|icmpname6
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
name|u_int
name|type
decl_stmt|;
name|u_int
name|code
decl_stmt|;
block|{
specifier|static
name|char
name|name
index|[
literal|80
index|]
decl_stmt|;
name|icmp_subtype_t
modifier|*
name|ist
decl_stmt|;
name|icmp_type_t
modifier|*
name|it
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|NULL
expr_stmt|;
name|it
operator|=
name|find_icmptype
argument_list|(
name|type
argument_list|,
name|icmptypes6
argument_list|,
sizeof|sizeof
argument_list|(
name|icmptypes6
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|it
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|it
operator|!=
name|NULL
condition|)
name|s
operator|=
name|it
operator|->
name|it_name
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"icmpv6type(%d)/"
argument_list|,
name|type
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"%s/"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|ist
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|it
operator|!=
name|NULL
operator|&&
name|it
operator|->
name|it_subtable
operator|!=
name|NULL
condition|)
name|ist
operator|=
name|find_icmpsubtype
argument_list|(
name|code
argument_list|,
name|it
operator|->
name|it_subtable
argument_list|,
name|it
operator|->
name|it_stsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|ist
operator|!=
name|NULL
operator|&&
name|ist
operator|->
name|ist_name
operator|!=
name|NULL
condition|)
name|strcat
argument_list|(
name|name
argument_list|,
name|ist
operator|->
name|ist_name
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|name
operator|+
name|strlen
argument_list|(
name|name
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
name|code
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
end_function

begin_function
name|void
name|dumphex
parameter_list|(
name|log
parameter_list|,
name|dopts
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
name|FILE
modifier|*
name|log
decl_stmt|;
name|int
name|dopts
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|char
name|hline
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
operator|(
name|u_char
operator|*
operator|)
name|buf
decl_stmt|,
modifier|*
name|t
init|=
operator|(
name|u_char
operator|*
operator|)
name|hline
decl_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
operator|||
name|len
operator|==
literal|0
condition|)
return|return;
operator|*
name|hline
operator|=
literal|'\0'
expr_stmt|;
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
operator|(
name|dopts
operator|&
name|IPMON_SYSLOG
operator|)
condition|)
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s"
argument_list|,
name|hline
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|log
operator|!=
name|NULL
condition|)
name|fputs
argument_list|(
name|hline
argument_list|,
name|log
argument_list|)
expr_stmt|;
name|t
operator|=
operator|(
name|u_char
operator|*
operator|)
name|hline
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
operator|(
name|dopts
operator|&
name|IPMON_SYSLOG
operator|)
operator|!=
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s"
argument_list|,
name|hline
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|log
operator|!=
name|NULL
condition|)
block|{
name|fputs
argument_list|(
name|hline
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
block|}
end_function

begin_function
specifier|static
name|struct
name|tm
modifier|*
name|get_tm
parameter_list|(
name|sec
parameter_list|)
ifdef|#
directive|ifdef
name|__hpux
name|u_32_t
name|sec
decl_stmt|;
else|#
directive|else
name|time_t
name|sec
decl_stmt|;
endif|#
directive|endif
block|{
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|time_t
name|t
decl_stmt|;
name|t
operator|=
name|sec
expr_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
name|tm
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_natlog
parameter_list|(
name|conf
parameter_list|,
name|buf
parameter_list|,
name|blen
parameter_list|)
name|config_t
modifier|*
name|conf
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|blen
decl_stmt|;
block|{
specifier|static
name|u_32_t
name|seqnum
init|=
literal|0
decl_stmt|;
name|int
name|res
decl_stmt|,
name|i
decl_stmt|,
name|len
decl_stmt|,
name|family
decl_stmt|;
name|struct
name|natlog
modifier|*
name|nl
decl_stmt|;
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|iplog_t
modifier|*
name|ipl
decl_stmt|;
name|char
modifier|*
name|proto
decl_stmt|;
name|int
name|simple
decl_stmt|;
name|char
modifier|*
name|t
decl_stmt|;
name|t
operator|=
name|line
expr_stmt|;
name|simple
operator|=
literal|0
expr_stmt|;
name|ipl
operator|=
operator|(
name|iplog_t
operator|*
operator|)
name|buf
expr_stmt|;
if|if
condition|(
name|ipl
operator|->
name|ipl_seqnum
operator|!=
name|seqnum
condition|)
block|{
if|if
condition|(
operator|(
name|ipmonopts
operator|&
name|IPMON_SYSLOG
operator|)
operator|!=
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"missed %u NAT log entries: %u %u"
argument_list|,
name|ipl
operator|->
name|ipl_seqnum
operator|-
name|seqnum
argument_list|,
name|seqnum
argument_list|,
name|ipl
operator|->
name|ipl_seqnum
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|conf
operator|->
name|log
argument_list|,
literal|"missed %u NAT log entries: %u %u\n"
argument_list|,
name|ipl
operator|->
name|ipl_seqnum
operator|-
name|seqnum
argument_list|,
name|seqnum
argument_list|,
name|ipl
operator|->
name|ipl_seqnum
argument_list|)
expr_stmt|;
block|}
block|}
name|seqnum
operator|=
name|ipl
operator|->
name|ipl_seqnum
operator|+
name|ipl
operator|->
name|ipl_count
expr_stmt|;
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
name|ipmonopts
operator|&
name|IPMON_RESOLVE
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|tm
operator|=
name|get_tm
argument_list|(
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
name|ipmonopts
operator|&
name|IPMON_SYSLOG
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|".%-.6ld @%hd "
argument_list|,
operator|(
name|long
operator|)
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
switch|switch
condition|(
name|nl
operator|->
name|nl_action
condition|)
block|{
case|case
name|NL_NEW
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:NEW"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NL_FLUSH
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:FLUSH"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NL_CLONE
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:CLONE"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NL_EXPIRE
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:EXPIRE"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NL_DESTROY
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:DESTROY"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NL_PURGE
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"NAT:PURGE"
argument_list|)
expr_stmt|;
break|break;
default|default :
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"NAT:Action(%d)"
argument_list|,
name|nl
operator|->
name|nl_action
argument_list|)
expr_stmt|;
break|break;
block|}
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|nl
operator|->
name|nl_type
condition|)
block|{
case|case
name|NAT_MAP
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-MAP "
argument_list|)
expr_stmt|;
name|simple
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|NAT_REDIRECT
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-RDR "
argument_list|)
expr_stmt|;
name|simple
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|NAT_BIMAP
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-BIMAP "
argument_list|)
expr_stmt|;
name|simple
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|NAT_MAPBLK
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-MAPBLOCK "
argument_list|)
expr_stmt|;
name|simple
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|NAT_REWRITE
operator||
name|NAT_MAP
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-RWR_MAP "
argument_list|)
expr_stmt|;
break|break;
case|case
name|NAT_REWRITE
operator||
name|NAT_REDIRECT
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-RWR_RDR "
argument_list|)
expr_stmt|;
break|break;
case|case
name|NAT_ENCAP
operator||
name|NAT_MAP
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-ENC_MAP "
argument_list|)
expr_stmt|;
break|break;
case|case
name|NAT_ENCAP
operator||
name|NAT_REDIRECT
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-ENC_RDR "
argument_list|)
expr_stmt|;
break|break;
case|case
name|NAT_DIVERTUDP
operator||
name|NAT_MAP
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-DIV_MAP "
argument_list|)
expr_stmt|;
break|break;
case|case
name|NAT_DIVERTUDP
operator||
name|NAT_REDIRECT
case|:
name|strcpy
argument_list|(
name|t
argument_list|,
literal|"-DIV_RDR "
argument_list|)
expr_stmt|;
break|break;
default|default :
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"-Type(%d) "
argument_list|,
name|nl
operator|->
name|nl_type
argument_list|)
expr_stmt|;
break|break;
block|}
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|proto
operator|=
name|getlocalproto
argument_list|(
name|nl
operator|->
name|nl_p
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|family
operator|=
name|vtof
argument_list|(
name|nl
operator|->
name|nl_v
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|simple
operator|==
literal|1
condition|)
block|{
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s<- -> "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_osrcip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_osrcport
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_nsrcip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_nsrcport
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"[%s,%s] "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_odstip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_odstport
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_osrcip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_osrcport
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s<- -> "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_odstip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_odstport
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_nsrcip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_nsrcport
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
name|sprintf
argument_list|(
name|t
argument_list|,
literal|"%s,%s "
argument_list|,
name|hostname
argument_list|(
name|family
argument_list|,
name|nl
operator|->
name|nl_ndstip
operator|.
name|i6
argument_list|)
argument_list|,
name|portlocalname
argument_list|(
name|res
argument_list|,
name|proto
argument_list|,
operator|(
name|u_int
operator|)
name|nl
operator|->
name|nl_ndstport
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|t
operator|+=
name|strlen
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|t
argument_list|,
name|getlocalproto
argument_list|(
name|nl
operator|->
name|nl_p
index|[
literal|0
index|]
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
name|nl_action
operator|==
name|NL_EXPIRE
operator|||
name|nl
operator|->
name|nl_action
operator|==
name|NL_FLUSH
condition|)
block|{
ifdef|#
directive|ifdef
name|USE_QUAD_T
ifdef|#
directive|ifdef
name|PRId64
name|sprintf
argument_list|(
argument|t
argument_list|,
literal|" Pkts %"
argument|PRId64
literal|"/%"
argument|PRId64
literal|" Bytes %"
argument|PRId64
literal|"/%"
argument|PRId64
argument_list|,
else|#
directive|else
argument|sprintf(t,
literal|" Pkts %qd/%qd Bytes %qd/%qd"
argument|,
endif|#
directive|endif
else|#
directive|else
argument|sprintf(t,
literal|" Pkts %ld/%ld Bytes %ld/%ld"
argument|,
endif|#
directive|endif
argument|nl->nl_pkts[
literal|0
argument|], nl->nl_pkts[
literal|1
argument|], 				nl->nl_bytes[
literal|0
argument|], nl->nl_bytes[
literal|1
argument|]); 		t += strlen(t); 	}  	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	if (ipmonopts& IPMON_SYSLOG) 		syslog(LOG_INFO,
literal|"%s"
argument|, line); 	else if (conf->log != NULL) 		(void) fprintf(conf->log,
literal|"%s"
argument|, line); }   static void print_statelog(conf, buf, blen) 	config_t *conf; 	char *buf; 	int blen; { 	static u_32_t seqnum =
literal|0
argument|; 	int res, i, len, family; 	struct ipslog *sl; 	char *t, *proto; 	struct tm *tm; 	iplog_t *ipl;  	t = line; 	ipl = (iplog_t *)buf; 	if (ipl->ipl_seqnum != seqnum) { 		if ((ipmonopts& IPMON_SYSLOG) !=
literal|0
argument|) { 			syslog(LOG_WARNING,
literal|"missed %u state log entries: %u %u"
argument|, 			       ipl->ipl_seqnum - seqnum, seqnum, 			       ipl->ipl_seqnum); 		} else { 			(void) fprintf(conf->log,
literal|"missed %u state log entries: %u %u\n"
argument|, 			       ipl->ipl_seqnum - seqnum, seqnum, 			       ipl->ipl_seqnum); 		} 	} 	seqnum = ipl->ipl_seqnum + ipl->ipl_count;  	sl = (struct ipslog *)((char *)ipl + sizeof(*ipl)); 	res = (ipmonopts& IPMON_RESOLVE) ?
literal|1
argument|:
literal|0
argument|; 	tm = get_tm(ipl->ipl_sec); 	len = sizeof(line); 	if (!(ipmonopts& IPMON_SYSLOG)) { 		(void) strftime(t, len,
literal|"%d/%m/%Y "
argument|, tm); 		i = strlen(t); 		len -= i; 		t += i; 	} 	(void) strftime(t, len,
literal|"%T"
argument|, tm); 	t += strlen(t); 	sprintf(t,
literal|".%-.6ld "
argument|, (long)ipl->ipl_usec); 	t += strlen(t);  	family = vtof(sl->isl_v);  	switch (sl->isl_type) 	{ 	case ISL_NEW : 		strcpy(t,
literal|"STATE:NEW "
argument|); 		break;  	case ISL_CLONE : 		strcpy(t,
literal|"STATE:CLONED "
argument|); 		break;  	case ISL_EXPIRE : 		if ((sl->isl_p == IPPROTO_TCP)&& 		    (sl->isl_state[
literal|0
argument|]> IPF_TCPS_ESTABLISHED || 		     sl->isl_state[
literal|1
argument|]> IPF_TCPS_ESTABLISHED)) 			strcpy(t,
literal|"STATE:CLOSE "
argument|); 		else 			strcpy(t,
literal|"STATE:EXPIRE "
argument|); 		break;  	case ISL_FLUSH : 		strcpy(t,
literal|"STATE:FLUSH "
argument|); 		break;  	case ISL_INTERMEDIATE : 		strcpy(t,
literal|"STATE:INTERMEDIATE "
argument|); 		break;  	case ISL_REMOVE : 		strcpy(t,
literal|"STATE:REMOVE "
argument|); 		break;  	case ISL_KILLED : 		strcpy(t,
literal|"STATE:KILLED "
argument|); 		break;  	case ISL_UNLOAD : 		strcpy(t,
literal|"STATE:UNLOAD "
argument|); 		break;  	default : 		sprintf(t,
literal|"Type: %d "
argument|, sl->isl_type); 		break; 	} 	t += strlen(t);  	proto = getlocalproto(sl->isl_p);  	if (sl->isl_p == IPPROTO_TCP || sl->isl_p == IPPROTO_UDP) { 		sprintf(t,
literal|"%s,%s -> "
argument|, 			hostname(family, (u_32_t *)&sl->isl_src), 			portlocalname(res, proto, (u_int)sl->isl_sport)); 		t += strlen(t); 		sprintf(t,
literal|"%s,%s PR %s"
argument|, 			hostname(family, (u_32_t *)&sl->isl_dst), 			portlocalname(res, proto, (u_int)sl->isl_dport), proto); 	} else if (sl->isl_p == IPPROTO_ICMP) { 		sprintf(t,
literal|"%s -> "
argument|, hostname(family, (u_32_t *)&sl->isl_src)); 		t += strlen(t); 		sprintf(t,
literal|"%s PR icmp %d"
argument|, 			hostname(family, (u_32_t *)&sl->isl_dst), 			sl->isl_itype); 	} else if (sl->isl_p == IPPROTO_ICMPV6) { 		sprintf(t,
literal|"%s -> "
argument|, hostname(family, (u_32_t *)&sl->isl_src)); 		t += strlen(t); 		sprintf(t,
literal|"%s PR icmpv6 %d"
argument|, 			hostname(family, (u_32_t *)&sl->isl_dst), 			sl->isl_itype); 	} else { 		sprintf(t,
literal|"%s -> "
argument|, hostname(family, (u_32_t *)&sl->isl_src)); 		t += strlen(t); 		sprintf(t,
literal|"%s PR %s"
argument|, 			hostname(family, (u_32_t *)&sl->isl_dst), proto); 	} 	t += strlen(t); 	if (sl->isl_tag != FR_NOLOGTAG) { 		sprintf(t,
literal|" tag %u"
argument|, sl->isl_tag); 		t += strlen(t); 	} 	if (sl->isl_type != ISL_NEW) { 		sprintf(t,
ifdef|#
directive|ifdef
name|USE_QUAD_T
ifdef|#
directive|ifdef
name|PRId64
literal|" Forward: Pkts in %"
argument|PRId64
literal|" Bytes in %"
argument|PRId64
literal|" Pkts out %"
argument|PRId64
literal|" Bytes out %"
argument|PRId64
literal|" Backward: Pkts in %"
argument|PRId64
literal|" Bytes in %"
argument|PRId64
literal|" Pkts out %"
argument|PRId64
literal|" Bytes out %"
argument|PRId64,
else|#
directive|else
literal|" Forward: Pkts in %qd Bytes in %qd Pkts out %qd Bytes out %qd Backward: Pkts in %qd Bytes in %qd Pkts out %qd Bytes out %qd"
argument|,
endif|#
directive|endif
comment|/* PRId64 */
else|#
directive|else
literal|" Forward: Pkts in %ld Bytes in %ld Pkts out %ld Bytes out %ld Backward: Pkts in %ld Bytes in %ld Pkts out %ld Bytes out %ld"
argument|,
endif|#
directive|endif
argument|sl->isl_pkts[
literal|0
argument|], sl->isl_bytes[
literal|0
argument|], 			sl->isl_pkts[
literal|1
argument|], sl->isl_bytes[
literal|1
argument|], 			sl->isl_pkts[
literal|2
argument|], sl->isl_bytes[
literal|2
argument|], 			sl->isl_pkts[
literal|3
argument|], sl->isl_bytes[
literal|3
argument|]);  		t += strlen(t); 	}  	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	if (ipmonopts& IPMON_SYSLOG) 		syslog(LOG_INFO,
literal|"%s"
argument|, line); 	else if (conf->log != NULL) 		(void) fprintf(conf->log,
literal|"%s"
argument|, line); }   static void print_log(conf, log, buf, blen) 	config_t *conf; 	logsource_t *log; 	char *buf; 	int blen; { 	char *bp, *bpo; 	iplog_t	*ipl; 	int psize;  	bp = NULL; 	bpo = NULL;  	while (blen>
literal|0
argument|) { 		ipl = (iplog_t *)buf; 		if ((u_long)ipl& (sizeof(long)-
literal|1
argument|)) { 			if (bp) 				bpo = bp; 			bp = (char *)malloc(blen); 			bcopy((char *)ipl, bp, blen); 			if (bpo) { 				free(bpo); 				bpo = NULL; 			} 			buf = bp; 			continue; 		}  		psize = ipl->ipl_dsize; 		if (psize> blen) 			break;  		if (conf->blog != NULL) { 			fwrite(buf, psize,
literal|1
argument|, conf->blog); 			fflush(conf->blog); 		}  		if (log->logtype == IPL_LOGIPF) { 			if (ipl->ipl_magic == IPL_MAGIC) 				print_ipflog(conf, buf, psize);  		} else if (log->logtype == IPL_LOGNAT) { 			if (ipl->ipl_magic == IPL_MAGIC_NAT) 				print_natlog(conf, buf, psize);  		} else if (log->logtype == IPL_LOGSTATE) { 			if (ipl->ipl_magic == IPL_MAGIC_STATE) 				print_statelog(conf, buf, psize); 		}  		blen -= psize; 		buf += psize; 	} 	if (bp) 		free(bp); 	return; }   static void print_ipflog(conf, buf, blen) 	config_t *conf; 	char *buf; 	int blen; { 	static u_32_t seqnum =
literal|0
argument|; 	int i, f, lvl, res, len, off, plen, ipoff, defaction; 	struct icmp *icmp; 	struct icmp *ic; 	char *t, *proto; 	ip_t *ipc, *ip; 	struct tm *tm; 	u_32_t *s, *d; 	u_short hl, p; 	ipflog_t *ipf; 	iplog_t *ipl; 	tcphdr_t *tp;
ifdef|#
directive|ifdef
name|USE_INET6
argument|struct ip6_ext *ehp; 	u_short ehl; 	ip6_t *ip6; 	int go;
endif|#
directive|endif
argument|ipl = (iplog_t *)buf; 	if (ipl->ipl_seqnum != seqnum) { 		if ((ipmonopts& IPMON_SYSLOG) !=
literal|0
argument|) { 			syslog(LOG_WARNING,
literal|"missed %u ipf log entries: %u %u"
argument|, 			       ipl->ipl_seqnum - seqnum, seqnum, 			       ipl->ipl_seqnum); 		} else { 			(void) fprintf(conf->log,
literal|"missed %u ipf log entries: %u %u\n"
argument|, 			       ipl->ipl_seqnum - seqnum, seqnum, 			       ipl->ipl_seqnum); 		} 	} 	seqnum = ipl->ipl_seqnum + ipl->ipl_count;  	ipf = (ipflog_t *)((char *)buf + sizeof(*ipl)); 	ip = (ip_t *)((char *)ipf + sizeof(*ipf)); 	f = ipf->fl_family; 	res = (ipmonopts& IPMON_RESOLVE) ?
literal|1
argument|:
literal|0
argument|; 	t = line; 	*t =
literal|'\0'
argument|; 	tm = get_tm(ipl->ipl_sec);  	len = sizeof(line); 	if (!(ipmonopts& IPMON_SYSLOG)) { 		(void) strftime(t, len,
literal|"%d/%m/%Y "
argument|, tm); 		i = strlen(t); 		len -= i; 		t += i; 	} 	(void) strftime(t, len,
literal|"%T"
argument|, tm); 	t += strlen(t); 	sprintf(t,
literal|".%-.6ld "
argument|, (long)ipl->ipl_usec); 	t += strlen(t); 	if (ipl->ipl_count>
literal|1
argument|) { 		sprintf(t,
literal|"%dx "
argument|, ipl->ipl_count); 		t += strlen(t); 	}
if|#
directive|if
operator|(
name|defined
argument_list|(
name|MENTAT
argument_list|)
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
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|501113
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
argument|{ 	char	ifname[sizeof(ipf->fl_ifname) +
literal|1
argument|];  	strncpy(ifname, ipf->fl_ifname, sizeof(ipf->fl_ifname)); 	ifname[sizeof(ipf->fl_ifname)] =
literal|'\0'
argument|; 	sprintf(t,
literal|"%s"
argument|, ifname); 	t += strlen(t);
if|#
directive|if
name|defined
argument_list|(
name|MENTAT
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
comment|/* 	 * On Linux, the loopback interface is just "lo", not "lo0". 	 */
argument|if (strcmp(ifname,
literal|"lo"
argument|) !=
literal|0
argument|)
endif|#
directive|endif
argument|if (ISALPHA(*(t -
literal|1
argument|))) { 			sprintf(t,
literal|"%d"
argument|, ipf->fl_unit); 			t += strlen(t); 		}
endif|#
directive|endif
argument|}
else|#
directive|else
argument|for (len =
literal|0
argument|; len<
literal|3
argument|; len++) 		if (ipf->fl_ifname[len] ==
literal|'\0'
argument|) 			break; 	if (ipf->fl_ifname[len]) 		len++; 	sprintf(t,
literal|"%*.*s%u"
argument|, len, len, ipf->fl_ifname, ipf->fl_unit); 	t += strlen(t);
endif|#
directive|endif
argument|if ((ipf->fl_group[
literal|0
argument|] == (char)~
literal|0
argument|)&& (ipf->fl_group[
literal|1
argument|] ==
literal|'\0'
argument|)) 		strcat(t,
literal|" @-1:"
argument|); 	else if (ipf->fl_group[
literal|0
argument|] ==
literal|'\0'
argument|) 		(void) strcpy(t,
literal|" @0:"
argument|); 	else 		sprintf(t,
literal|" @%s:"
argument|, ipf->fl_group); 	t += strlen(t); 	if (ipf->fl_rule ==
literal|0xffffffff
argument|) 		strcat(t,
literal|"-1 "
argument|); 	else 		sprintf(t,
literal|"%u "
argument|, ipf->fl_rule +
literal|1
argument|); 	t += strlen(t);  	lvl = LOG_NOTICE;   	if (ipf->fl_lflags& FI_SHORT) { 		*t++ =
literal|'S'
argument|; 		lvl = LOG_ERR; 	}  	if (FR_ISPASS(ipf->fl_flags)) { 		if (ipf->fl_flags& FR_LOGP) 			*t++ =
literal|'p'
argument|; 		else 			*t++ =
literal|'P'
argument|; 	} else if (FR_ISBLOCK(ipf->fl_flags)) { 		if (ipf->fl_flags& FR_LOGB) 			*t++ =
literal|'b'
argument|; 		else 			*t++ =
literal|'B'
argument|; 		lvl = LOG_WARNING; 	} else if ((ipf->fl_flags& FR_LOGMASK) == FR_LOG) { 		*t++ =
literal|'L'
argument|; 		lvl = LOG_INFO; 	} else if (ipf->fl_flags& FF_LOGNOMATCH) { 		*t++ =
literal|'n'
argument|; 	} else { 		*t++ =
literal|'?'
argument|; 		lvl = LOG_EMERG; 	} 	if (ipf->fl_loglevel !=
literal|0xffff
argument|) 		lvl = ipf->fl_loglevel; 	*t++ =
literal|' '
argument|; 	*t =
literal|'\0'
argument|;  	if (f == AF_INET) { 		hl = IP_HL(ip)<<
literal|2
argument|; 		ipoff = ntohs(ip->ip_off); 		off = ipoff& IP_OFFMASK; 		p = (u_short)ip->ip_p; 		s = (u_32_t *)&ip->ip_src; 		d = (u_32_t *)&ip->ip_dst; 		plen = ntohs(ip->ip_len); 	} else
ifdef|#
directive|ifdef
name|USE_INET6
argument|if (f == AF_INET6) { 		off =
literal|0
argument|; 		ipoff =
literal|0
argument|; 		hl = sizeof(ip6_t); 		ip6 = (ip6_t *)ip; 		p = (u_short)ip6->ip6_nxt; 		s = (u_32_t *)&ip6->ip6_src; 		d = (u_32_t *)&ip6->ip6_dst; 		plen = hl + ntohs(ip6->ip6_plen); 		go =
literal|1
argument|; 		ehp = (struct ip6_ext *)((char *)ip6 + hl); 		while (go ==
literal|1
argument|) { 			switch (p) 			{ 			case IPPROTO_HOPOPTS : 			case IPPROTO_MOBILITY : 			case IPPROTO_DSTOPTS : 			case IPPROTO_ROUTING : 			case IPPROTO_AH : 				p = ehp->ip6e_nxt; 				ehl =
literal|8
argument|+ (ehp->ip6e_len<<
literal|3
argument|); 				hl += ehl; 				ehp = (struct ip6_ext *)((char *)ehp + ehl); 				break; 			case IPPROTO_FRAGMENT : 				hl += sizeof(struct ip6_frag);
comment|/* FALLTHROUGH */
argument|default : 				go =
literal|0
argument|; 				break; 			} 		} 	} else
endif|#
directive|endif
argument|{ 		goto printipflog; 	} 	proto = getlocalproto(p);  	if ((p == IPPROTO_TCP || p == IPPROTO_UDP)&& !off) { 		tp = (tcphdr_t *)((char *)ip + hl); 		if (!(ipf->fl_lflags& FI_SHORT)) { 			sprintf(t,
literal|"%s,%s -> "
argument|, hostname(f, s), 				portlocalname(res, proto, (u_int)tp->th_sport)); 			t += strlen(t); 			sprintf(t,
literal|"%s,%s PR %s len %hu %hu"
argument|, 				hostname(f, d), 				portlocalname(res, proto, (u_int)tp->th_dport), 				proto, hl, plen); 			t += strlen(t);  			if (p == IPPROTO_TCP) { 				*t++ =
literal|' '
argument|; 				*t++ =
literal|'-'
argument|; 				for (i =
literal|0
argument|; tcpfl[i].value; i++) 					if (tp->th_flags& tcpfl[i].value) 						*t++ = tcpfl[i].flag; 				if (ipmonopts& IPMON_VERBOSE) { 					sprintf(t,
literal|" %lu %lu %hu"
argument|, 						(u_long)(ntohl(tp->th_seq)), 						(u_long)(ntohl(tp->th_ack)), 						ntohs(tp->th_win)); 					t += strlen(t); 				} 			} 			*t =
literal|'\0'
argument|; 		} else { 			sprintf(t,
literal|"%s -> "
argument|, hostname(f, s)); 			t += strlen(t); 			sprintf(t,
literal|"%s PR %s len %hu %hu"
argument|, 				hostname(f, d), proto, hl, plen); 		}
if|#
directive|if
name|defined
argument_list|(
name|AF_INET6
argument_list|)
operator|&&
name|defined
argument_list|(
name|IPPROTO_ICMPV6
argument_list|)
argument|} else if ((p == IPPROTO_ICMPV6)&& !off&& (f == AF_INET6)) { 		ic = (struct icmp *)((char *)ip + hl); 		sprintf(t,
literal|"%s -> "
argument|, hostname(f, s)); 		t += strlen(t); 		sprintf(t,
literal|"%s PR icmpv6 len %hu %hu icmpv6 %s"
argument|, 			hostname(f, d), hl, plen, 			icmpname6(ic->icmp_type, ic->icmp_code));
endif|#
directive|endif
argument|} else if ((p == IPPROTO_ICMP)&& !off&& (f == AF_INET)) { 		ic = (struct icmp *)((char *)ip + hl); 		sprintf(t,
literal|"%s -> "
argument|, hostname(f, s)); 		t += strlen(t); 		sprintf(t,
literal|"%s PR icmp len %hu %hu icmp %s"
argument|, 			hostname(f, d), hl, plen, 			icmpname(ic->icmp_type, ic->icmp_code)); 		if (ic->icmp_type == ICMP_UNREACH || 		    ic->icmp_type == ICMP_SOURCEQUENCH || 		    ic->icmp_type == ICMP_PARAMPROB || 		    ic->icmp_type == ICMP_REDIRECT || 		    ic->icmp_type == ICMP_TIMXCEED) { 			ipc =&ic->icmp_ip; 			i = ntohs(ipc->ip_len);
comment|/* 			 * XXX - try to guess endian of ip_len in ICMP 			 * returned data. 			 */
argument|if (i>
literal|1500
argument|) 				i = ipc->ip_len; 			ipoff = ntohs(ipc->ip_off); 			proto = getlocalproto(ipc->ip_p);  			if (!(ipoff& IP_OFFMASK)&& 			    ((ipc->ip_p == IPPROTO_TCP) || 			     (ipc->ip_p == IPPROTO_UDP))) { 				tp = (tcphdr_t *)((char *)ipc + hl); 				t += strlen(t); 				sprintf(t,
literal|" for %s,%s -"
argument|, 					HOSTNAMEV4(ipc->ip_src), 					portlocalname(res, proto, 						 (u_int)tp->th_sport)); 				t += strlen(t); 				sprintf(t,
literal|" %s,%s PR %s len %hu %hu"
argument|, 					HOSTNAMEV4(ipc->ip_dst), 					portlocalname(res, proto, 						 (u_int)tp->th_dport), 					proto, IP_HL(ipc)<<
literal|2
argument|, i); 			} else if (!(ipoff& IP_OFFMASK)&& 				   (ipc->ip_p == IPPROTO_ICMP)) { 				icmp = (icmphdr_t *)((char *)ipc + hl);  				t += strlen(t); 				sprintf(t,
literal|" for %s -"
argument|, 					HOSTNAMEV4(ipc->ip_src)); 				t += strlen(t); 				sprintf(t,
literal|" %s PR icmp len %hu %hu icmp %d/%d"
argument|, 					HOSTNAMEV4(ipc->ip_dst), 					IP_HL(ipc)<<
literal|2
argument|, i, 					icmp->icmp_type, icmp->icmp_code); 			} else { 				t += strlen(t); 				sprintf(t,
literal|" for %s -"
argument|, 					HOSTNAMEV4(ipc->ip_src)); 				t += strlen(t); 				sprintf(t,
literal|" %s PR %s len %hu (%hu)"
argument|, 					HOSTNAMEV4(ipc->ip_dst), proto, 					IP_HL(ipc)<<
literal|2
argument|, i); 				t += strlen(t); 				if (ipoff& IP_OFFMASK) { 					sprintf(t,
literal|"(frag %d:%hu@%hu%s%s)"
argument|, 						ntohs(ipc->ip_id), 						i - (IP_HL(ipc)<<
literal|2
argument|), 						(ipoff& IP_OFFMASK)<<
literal|3
argument|, 						ipoff& IP_MF ?
literal|"+"
argument|:
literal|""
argument|, 						ipoff& IP_DF ?
literal|"-"
argument|:
literal|""
argument|); 				} 			}  		} 	} else { 		sprintf(t,
literal|"%s -> "
argument|, hostname(f, s)); 		t += strlen(t); 		sprintf(t,
literal|"%s PR %s len %hu (%hu)"
argument|, 			hostname(f, d), proto, hl, plen); 		t += strlen(t); 		if (off& IP_OFFMASK) 			sprintf(t,
literal|" (frag %d:%hu@%hu%s%s)"
argument|, 				ntohs(ip->ip_id), 				plen - hl, (off& IP_OFFMASK)<<
literal|3
argument|, 				ipoff& IP_MF ?
literal|"+"
argument|:
literal|""
argument|, 				ipoff& IP_DF ?
literal|"-"
argument|:
literal|""
argument|); 	} 	t += strlen(t);  printipflog: 	if (ipf->fl_flags& FR_KEEPSTATE) { 		(void) strcpy(t,
literal|" K-S"
argument|); 		t += strlen(t); 	}  	if (ipf->fl_flags& FR_KEEPFRAG) { 		(void) strcpy(t,
literal|" K-F"
argument|); 		t += strlen(t); 	}  	if (ipf->fl_dir ==
literal|0
argument|) 		strcpy(t,
literal|" IN"
argument|); 	else if (ipf->fl_dir ==
literal|1
argument|) 		strcpy(t,
literal|" OUT"
argument|); 	t += strlen(t); 	if (ipf->fl_logtag !=
literal|0
argument|) { 		sprintf(t,
literal|" log-tag %d"
argument|, ipf->fl_logtag); 		t += strlen(t); 	} 	if (ipf->fl_nattag.ipt_num[
literal|0
argument|] !=
literal|0
argument|) { 		strcpy(t,
literal|" nat-tag "
argument|); 		t += strlen(t); 		strncpy(t, ipf->fl_nattag.ipt_tag, sizeof(ipf->fl_nattag)); 		t += strlen(t); 	} 	if ((ipf->fl_lflags& FI_LOWTTL) !=
literal|0
argument|) { 			strcpy(t,
literal|" low-ttl"
argument|); 			t +=
literal|8
argument|; 	} 	if ((ipf->fl_lflags& FI_OOW) !=
literal|0
argument|) { 			strcpy(t,
literal|" OOW"
argument|); 			t +=
literal|4
argument|; 	} 	if ((ipf->fl_lflags& FI_BAD) !=
literal|0
argument|) { 			strcpy(t,
literal|" bad"
argument|); 			t +=
literal|4
argument|; 	} 	if ((ipf->fl_lflags& FI_NATED) !=
literal|0
argument|) { 			strcpy(t,
literal|" NAT"
argument|); 			t +=
literal|4
argument|; 	} 	if ((ipf->fl_lflags& FI_BADNAT) !=
literal|0
argument|) { 			strcpy(t,
literal|" bad-NAT"
argument|); 			t +=
literal|8
argument|; 	} 	if ((ipf->fl_lflags& FI_BADSRC) !=
literal|0
argument|) { 			strcpy(t,
literal|" bad-src"
argument|); 			t +=
literal|8
argument|; 	} 	if ((ipf->fl_lflags& FI_MULTICAST) !=
literal|0
argument|) { 			strcpy(t,
literal|" multicast"
argument|); 			t +=
literal|10
argument|; 	} 	if ((ipf->fl_lflags& FI_BROADCAST) !=
literal|0
argument|) { 			strcpy(t,
literal|" broadcast"
argument|); 			t +=
literal|10
argument|; 	} 	if ((ipf->fl_lflags& (FI_MULTICAST|FI_BROADCAST|FI_MBCAST)) == 	    FI_MBCAST) { 			strcpy(t,
literal|" mbcast"
argument|); 			t +=
literal|7
argument|; 	} 	if (ipf->fl_breason !=
literal|0
argument|) { 		strcpy(t,
literal|" reason:"
argument|); 		t +=
literal|8
argument|; 		strcpy(t, reasons[ipf->fl_breason]); 		t += strlen(reasons[ipf->fl_breason]); 	} 	*t++ =
literal|'\n'
argument|; 	*t++ =
literal|'\0'
argument|; 	defaction =
literal|0
argument|; 	if (conf->cfile != NULL) 		defaction = check_action(buf, line, ipmonopts, lvl);  	if (defaction ==
literal|0
argument|) { 		if (ipmonopts& IPMON_SYSLOG) { 			syslog(lvl,
literal|"%s"
argument|, line); 		} else if (conf->log != NULL) { 			(void) fprintf(conf->log,
literal|"%s"
argument|, line); 		}  		if (ipmonopts& IPMON_HEXHDR) { 			dumphex(conf->log, ipmonopts, buf, 				sizeof(iplog_t) + sizeof(*ipf)); 		} 		if (ipmonopts& IPMON_HEXBODY) { 			dumphex(conf->log, ipmonopts, (char *)ip, 				ipf->fl_plen + ipf->fl_hlen); 		} else if ((ipmonopts& IPMON_LOGBODY)&& 			   (ipf->fl_flags& FR_LOGBODY)) { 			dumphex(conf->log, ipmonopts, (char *)ip + ipf->fl_hlen, 				ipf->fl_plen); 		} 	} }   static void usage(prog) 	char *prog; { 	fprintf(stderr,
literal|"%s: [-NFhstvxX] [-f<logfile>]\n"
argument|, prog); 	exit(
literal|1
argument|); }   static void write_pid(file) 	char *file; { 	FILE *fp = NULL; 	int fd;  	if ((fd = open(file, O_CREAT|O_TRUNC|O_WRONLY,
literal|0644
argument|))>=
literal|0
argument|) { 		fp = fdopen(fd,
literal|"w"
argument|); 		if (fp == NULL) { 			close(fd); 			fprintf(stderr,
literal|"unable to open/create pid file: %s\n"
argument|, file); 			return; 		} 		fprintf(fp,
literal|"%d"
argument|, getpid()); 		fclose(fp); 	} }   static void flushlogs(file, log) 	char *file; 	FILE *log; { 	int	fd, flushed =
literal|0
argument|;  	if ((fd = open(file, O_RDWR)) == -
literal|1
argument|) { 		(void) fprintf(stderr,
literal|"%s: open: %s\n"
argument|, 			       file, STRERROR(errno)); 		exit(
literal|1
argument|); 	}  	if (ioctl(fd, SIOCIPFFB,&flushed) ==
literal|0
argument|) { 		printf(
literal|"%d bytes flushed from log buffer\n"
argument|, 			flushed); 		fflush(stdout); 	} else 		ipferror(fd,
literal|"SIOCIPFFB"
argument|); 	(void) close(fd);  	if (flushed) { 		if (ipmonopts& IPMON_SYSLOG) { 			syslog(LOG_INFO,
literal|"%d bytes flushed from log\n"
argument|, 				flushed); 		} else if ((log != stdout)&& (log != NULL)) { 			fprintf(log,
literal|"%d bytes flushed from log\n"
argument|, flushed); 		} 	} }   static void logopts(turnon, options) 	int turnon; 	char *options; { 	int flags =
literal|0
argument|; 	char *s;  	for (s = options; *s; s++) 	{ 		switch (*s) 		{ 		case
literal|'N'
argument|: 			flags |= IPMON_NAT; 			break; 		case
literal|'S'
argument|: 			flags |= IPMON_STATE; 			break; 		case
literal|'I'
argument|: 			flags |= IPMON_FILTER; 			break; 		default : 			fprintf(stderr,
literal|"Unknown log option %c\n"
argument|, *s); 			exit(
literal|1
argument|); 		} 	}  	if (turnon) 		ipmonopts |= flags; 	else 		ipmonopts&= ~(flags); }  static void initconfig(config_t *conf) { 	int i;  	memset(conf,
literal|0
argument|, sizeof(*conf));  	conf->log = stdout; 	conf->maxfd = -
literal|1
argument|;  	for (i =
literal|0
argument|; i<
literal|3
argument|; i++) { 		conf->logsrc[i].fd = -
literal|1
argument|; 		conf->logsrc[i].logtype = -
literal|1
argument|; 		conf->logsrc[i].regular = -
literal|1
argument|; 	}  	conf->logsrc[
literal|0
argument|].file = IPL_NAME; 	conf->logsrc[
literal|1
argument|].file = IPNAT_NAME; 	conf->logsrc[
literal|2
argument|].file = IPSTATE_NAME;  	add_doing(&executesaver); 	add_doing(&snmpv1saver); 	add_doing(&snmpv2saver); 	add_doing(&syslogsaver); 	add_doing(&filesaver); 	add_doing(&nothingsaver); }   int main(argc, argv) 	int argc; 	char *argv[]; { 	int	doread, c, make_daemon =
literal|0
argument|; 	char	*prog; 	config_t	config;  	prog = strrchr(argv[
literal|0
argument|],
literal|'/'
argument|); 	if (prog == NULL) 		prog = argv[
literal|0
argument|]; 	else 		prog++;  	initconfig(&config);  	while ((c = getopt(argc, argv,
literal|"?abB:C:Df:FhL:nN:o:O:pP:sS:tvxX"
argument|)) != -
literal|1
argument|) 		switch (c) 		{ 		case
literal|'a'
argument|: 			ipmonopts |= IPMON_LOGALL; 			config.logsrc[
literal|0
argument|].logtype = IPL_LOGIPF; 			config.logsrc[
literal|1
argument|].logtype = IPL_LOGNAT; 			config.logsrc[
literal|2
argument|].logtype = IPL_LOGSTATE; 			break; 		case
literal|'b'
argument|: 			ipmonopts |= IPMON_LOGBODY; 			break; 		case
literal|'B'
argument|: 			config.bfile = optarg; 			config.blog = fopen(optarg,
literal|"a"
argument|); 			break; 		case
literal|'C'
argument|: 			config.cfile = optarg; 			break; 		case
literal|'D'
argument|: 			make_daemon =
literal|1
argument|; 			break; 		case
literal|'f'
argument|: case
literal|'I'
argument|: 			ipmonopts |= IPMON_FILTER; 			config.logsrc[
literal|0
argument|].logtype = IPL_LOGIPF; 			config.logsrc[
literal|0
argument|].file = optarg; 			break; 		case
literal|'F'
argument|: 			flushlogs(config.logsrc[
literal|0
argument|].file, config.log); 			flushlogs(config.logsrc[
literal|1
argument|].file, config.log); 			flushlogs(config.logsrc[
literal|2
argument|].file, config.log); 			break; 		case
literal|'L'
argument|: 			logfac = fac_findname(optarg); 			if (logfac == -
literal|1
argument|) { 				fprintf(stderr,
literal|"Unknown syslog facility '%s'\n"
argument|, 					 optarg); 				exit(
literal|1
argument|); 			} 			break; 		case
literal|'n'
argument|: 			ipmonopts |= IPMON_RESOLVE; 			opts&= ~OPT_NORESOLVE; 			break; 		case
literal|'N'
argument|: 			ipmonopts |= IPMON_NAT; 			config.logsrc[
literal|1
argument|].logtype = IPL_LOGNAT; 			config.logsrc[
literal|1
argument|].file = optarg; 			break; 		case
literal|'o'
argument|: case
literal|'O'
argument|: 			logopts(c ==
literal|'o'
argument|, optarg); 			if (ipmonopts& IPMON_FILTER) 				config.logsrc[
literal|0
argument|].logtype = IPL_LOGIPF; 			if (ipmonopts& IPMON_NAT) 				config.logsrc[
literal|1
argument|].logtype = IPL_LOGNAT; 			if (ipmonopts& IPMON_STATE) 				config.logsrc[
literal|2
argument|].logtype = IPL_LOGSTATE; 			break; 		case
literal|'p'
argument|: 			ipmonopts |= IPMON_PORTNUM; 			break; 		case
literal|'P'
argument|: 			pidfile = optarg; 			break; 		case
literal|'s'
argument|: 			ipmonopts |= IPMON_SYSLOG; 			config.log = NULL; 			break; 		case
literal|'S'
argument|: 			ipmonopts |= IPMON_STATE; 			config.logsrc[
literal|2
argument|].logtype = IPL_LOGSTATE; 			config.logsrc[
literal|2
argument|].file = optarg; 			break; 		case
literal|'t'
argument|: 			ipmonopts |= IPMON_TAIL; 			break; 		case
literal|'v'
argument|: 			ipmonopts |= IPMON_VERBOSE; 			break; 		case
literal|'x'
argument|: 			ipmonopts |= IPMON_HEXBODY; 			break; 		case
literal|'X'
argument|: 			ipmonopts |= IPMON_HEXHDR; 			break; 		default : 		case
literal|'h'
argument|: 		case
literal|'?'
argument|: 			usage(argv[
literal|0
argument|]); 		}  	if (ipmonopts& IPMON_SYSLOG) 		openlog(prog, LOG_NDELAY|LOG_PID, logfac);  	init_tabs(); 	if (config.cfile) 		if (load_config(config.cfile) == -
literal|1
argument|) { 			unload_config(); 			exit(
literal|1
argument|); 		}
comment|/* 	 * Default action is to only open the filter log file. 	 */
argument|if ((config.logsrc[
literal|0
argument|].logtype == -
literal|1
argument|)&& 	    (config.logsrc[
literal|0
argument|].logtype == -
literal|1
argument|)&& 	    (config.logsrc[
literal|0
argument|].logtype == -
literal|1
argument|)) 		config.logsrc[
literal|0
argument|].logtype = IPL_LOGIPF;  	openlogs(&config);  	if (!(ipmonopts& IPMON_SYSLOG)) { 		config.file = argv[optind]; 		config.log = config.file ? fopen(config.file,
literal|"a"
argument|) : stdout; 		if (config.log == NULL) { 			(void) fprintf(stderr,
literal|"%s: fopen: %s\n"
argument|, 				       argv[optind], STRERROR(errno)); 			exit(
literal|1
argument|);
comment|/* NOTREACHED */
argument|} 		setvbuf(config.log, NULL, _IONBF,
literal|0
argument|); 	} else { 		config.log = NULL; 	}  	if (make_daemon&& 	    ((config.log != stdout) || (ipmonopts& IPMON_SYSLOG))) {
if|#
directive|if
name|BSD
operator|>=
literal|199306
argument|daemon(
literal|0
argument|, !(ipmonopts& IPMON_SYSLOG));
else|#
directive|else
argument|int pid;  		switch (fork()) 		{ 		case -
literal|1
argument|: 			(void) fprintf(stderr,
literal|"%s: fork() failed: %s\n"
argument|, 				       argv[
literal|0
argument|], STRERROR(errno)); 			exit(
literal|1
argument|);
comment|/* NOTREACHED */
argument|case
literal|0
argument|: 			break; 		default : 			exit(
literal|0
argument|); 		}  		setsid(); 		if ((ipmonopts& IPMON_SYSLOG)) 			close(
literal|2
argument|);
endif|#
directive|endif
comment|/* !BSD */
argument|close(
literal|0
argument|); 		close(
literal|1
argument|); 		write_pid(pidfile); 	}  	signal(SIGHUP, handlehup);  	for (doread =
literal|1
argument|; doread; ) 		doread = read_loginfo(&config);  	unload_config();  	return(
literal|0
argument|);
comment|/* NOTREACHED */
argument|}   static void openlogs(config_t *conf) { 	logsource_t *l; 	struct stat sb; 	int i;  	for (i =
literal|0
argument|; i<
literal|3
argument|; i++) { 		l =&conf->logsrc[i]; 		if (l->logtype == -
literal|1
argument|) 			continue; 		if (!strcmp(l->file,
literal|"-"
argument|)) 			l->fd =
literal|0
argument|; 		else { 			if ((l->fd= open(l->file, O_RDONLY)) == -
literal|1
argument|) { 				(void) fprintf(stderr,
literal|"%s: open: %s\n"
argument|, l->file, 					       STRERROR(errno)); 				exit(
literal|1
argument|);
comment|/* NOTREACHED */
argument|}  			if (fstat(l->fd,&sb) == -
literal|1
argument|) { 				(void) fprintf(stderr,
literal|"%d: fstat: %s\n"
argument|, 					       l->fd, STRERROR(errno)); 				exit(
literal|1
argument|);
comment|/* NOTREACHED */
argument|}  			l->regular = !S_ISCHR(sb.st_mode); 			if (l->regular) 				l->size = sb.st_size;  			FD_SET(l->fd,&conf->fdmr); 			if (l->fd> conf->maxfd) 				conf->maxfd = l->fd; 		} 	} }   static int read_loginfo(config_t *conf) { 	iplog_t buf[DEFAULT_IPFLOGSIZE/sizeof(iplog_t)+
literal|1
argument|]; 	int n, tr, nr, i; 	logsource_t *l; 	fd_set fdr;  	fdr = conf->fdmr;  	n = select(conf->maxfd +
literal|1
argument|,&fdr, NULL, NULL, NULL); 	if (n ==
literal|0
argument|) 		return
literal|1
argument|; 	if (n == -
literal|1
argument|) { 		if (errno == EINTR) 			return
literal|1
argument|; 		return -
literal|1
argument|; 	}  	for (i =
literal|0
argument|, nr =
literal|0
argument|; i<
literal|3
argument|; i++) { 		l =&conf->logsrc[i];  		if ((l->logtype == -
literal|1
argument|) || !FD_ISSET(l->fd,&fdr)) 			continue;  		tr =
literal|0
argument|; 		if (l->regular) { 			tr = (lseek(l->fd,
literal|0
argument|, SEEK_CUR)< l->size); 			if (!tr&& !(ipmonopts& IPMON_TAIL)) 				return
literal|0
argument|; 		}  		n =
literal|0
argument|; 		tr = read_log(l->fd,&n, (char *)buf, sizeof(buf)); 		if (donehup) { 			if (conf->file != NULL) { 				if (conf->log != NULL) { 					fclose(conf->log); 					conf->log = NULL; 				} 				conf->log = fopen(conf->file,
literal|"a"
argument|); 			}  			if (conf->bfile != NULL) { 				if (conf->blog != NULL) { 					fclose(conf->blog); 					conf->blog = NULL; 				} 				conf->blog = fopen(conf->bfile,
literal|"a"
argument|); 			}  			init_tabs(); 			if (conf->cfile != NULL) 				load_config(conf->cfile); 			donehup =
literal|0
argument|; 		}  		switch (tr) 		{ 		case -
literal|1
argument|: 			if (ipmonopts& IPMON_SYSLOG) 				syslog(LOG_CRIT,
literal|"read: %m\n"
argument|); 			else { 				ipferror(l->fd,
literal|"read"
argument|); 			} 			return
literal|0
argument|; 		case
literal|1
argument|: 			if (ipmonopts& IPMON_SYSLOG) 				syslog(LOG_CRIT,
literal|"aborting logging\n"
argument|); 			else if (conf->log != NULL) 				fprintf(conf->log,
literal|"aborting logging\n"
argument|); 			return
literal|0
argument|; 		case
literal|2
argument|: 			break; 		case
literal|0
argument|: 			nr += tr; 			if (n>
literal|0
argument|) { 				print_log(conf, l, (char *)buf, n); 				if (!(ipmonopts& IPMON_SYSLOG)) 					fflush(conf->log); 			} 			break; 		} 	}  	if (!nr&& (ipmonopts& IPMON_TAIL)) 		sleep(
literal|1
argument|);  	return
literal|1
argument|; }
end_function

end_unit

