begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  * defs.h,v 3.8.4.15 1998/03/01 02:51:42 fenner Exp  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
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

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_define
define|#
directive|define
name|rtentry
value|kern_rtentry
end_define

begin_comment
comment|/* XXX !!! UGH */
end_comment

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_undef
undef|#
directive|undef
name|rtentry
end_undef

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
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/igmp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* sigh */
end_comment

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|220000
end_if

begin_define
define|#
directive|define
name|rtentry
value|kernel_rtentry
end_define

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_undef
undef|#
directive|undef
name|rtentry
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/ip_mroute.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_comment
comment|/*XXX*/
end_comment

begin_typedef
typedef|typedef
name|u_int
name|u_int32
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*cfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*ihfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
name|fd_set
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_include
include|#
directive|include
file|"dvmrp.h"
end_include

begin_include
include|#
directive|include
file|"igmpv2.h"
end_include

begin_include
include|#
directive|include
file|"vif.h"
end_include

begin_include
include|#
directive|include
file|"route.h"
end_include

begin_include
include|#
directive|include
file|"prune.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_include
include|#
directive|include
file|"rsrr.h"
end_include

begin_include
include|#
directive|include
file|"rsrr_var.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_comment
comment|/*  * Miscellaneous constants and macros.  */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|EQUAL
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp((s1), (s2)) == 0)
end_define

begin_define
define|#
directive|define
name|TIMER_INTERVAL
value|ROUTE_MAX_REPORT_DELAY
end_define

begin_define
define|#
directive|define
name|PROTOCOL_VERSION
value|3
end_define

begin_comment
comment|/* increment when packet format/content changes */
end_comment

begin_define
define|#
directive|define
name|MROUTED_VERSION
value|9
end_define

begin_comment
comment|/* not in DVMRP packets at all */
end_comment

begin_define
define|#
directive|define
name|DVMRP_CONSTANT
value|0x000eff00
end_define

begin_comment
comment|/* constant portion of 'group' field */
end_comment

begin_define
define|#
directive|define
name|MROUTED_LEVEL
value|(DVMRP_CONSTANT | PROTOCOL_VERSION)
end_define

begin_comment
comment|/* for IGMP 'group' field of DVMRP messages */
end_comment

begin_define
define|#
directive|define
name|LEAF_FLAGS
value|(( vifs_with_neighbors == 1 ) ? 0x010000 : 0)
end_define

begin_comment
comment|/* more for IGMP 'group' field of DVMRP messages */
end_comment

begin_define
define|#
directive|define
name|DEL_RTE_GROUP
value|0
end_define

begin_define
define|#
directive|define
name|DEL_ALL_ROUTES
value|1
end_define

begin_comment
comment|/* for Deleting kernel table entries */
end_comment

begin_comment
comment|/* obnoxious gcc gives an extraneous warning about this constant... */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800UL
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800L
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_define
define|#
directive|define
name|BIT_ZERO
parameter_list|(
name|X
parameter_list|)
value|((X) = 0)
end_define

begin_define
define|#
directive|define
name|BIT_SET
parameter_list|(
name|X
parameter_list|,
name|n
parameter_list|)
value|((X) |= 1<< (n))
end_define

begin_define
define|#
directive|define
name|BIT_CLR
parameter_list|(
name|X
parameter_list|,
name|n
parameter_list|)
value|((X)&= ~(1<< (n)))
end_define

begin_define
define|#
directive|define
name|BIT_TST
parameter_list|(
name|X
parameter_list|,
name|n
parameter_list|)
value|((X)& 1<< (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy(b, a, c)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset((s), 0, (n))
end_define

begin_define
define|#
directive|define
name|setlinebuf
parameter_list|(
name|s
parameter_list|)
value|setvbuf(s, NULL, _IOLBF, 0)
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
name|_AIX
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * External declarations for global variables and functions.  */
end_comment

begin_define
define|#
directive|define
name|RECV_BUF_SIZE
value|8192
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|recv_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|send_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|igmp_socket
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|rsrr_socket
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32
name|allhosts_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|allrtrs_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|dvmrp_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|dvmrp_genid
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IF_DEBUG
parameter_list|(
name|l
parameter_list|)
value|if (debug&& debug& (l))
end_define

begin_define
define|#
directive|define
name|DEBUG_PKT
value|0x0001
end_define

begin_define
define|#
directive|define
name|DEBUG_PRUNE
value|0x0002
end_define

begin_define
define|#
directive|define
name|DEBUG_ROUTE
value|0x0004
end_define

begin_define
define|#
directive|define
name|DEBUG_PEER
value|0x0008
end_define

begin_define
define|#
directive|define
name|DEBUG_CACHE
value|0x0010
end_define

begin_define
define|#
directive|define
name|DEBUG_TIMEOUT
value|0x0020
end_define

begin_define
define|#
directive|define
name|DEBUG_IF
value|0x0040
end_define

begin_define
define|#
directive|define
name|DEBUG_MEMBER
value|0x0080
end_define

begin_define
define|#
directive|define
name|DEBUG_TRACE
value|0x0100
end_define

begin_define
define|#
directive|define
name|DEBUG_IGMP
value|0x0200
end_define

begin_define
define|#
directive|define
name|DEBUG_RTDETAIL
value|0x0400
end_define

begin_define
define|#
directive|define
name|DEBUG_KERN
value|0x0800
end_define

begin_define
define|#
directive|define
name|DEBUG_RSRR
value|0x1000
end_define

begin_define
define|#
directive|define
name|DEBUG_ICMP
value|0x2000
end_define

begin_define
define|#
directive|define
name|DEFAULT_DEBUG
value|0x02de
end_define

begin_comment
comment|/* default if "-d" given without value */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|did_final_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|routes_changed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delay_change_reports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|nroutes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uvif
name|uvifs
index|[
name|MAXVIFS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|numvifs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vifs_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|udp_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vifs_with_neighbors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s4
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MRT_INIT
value|DVMRP_INIT
end_define

begin_define
define|#
directive|define
name|MRT_DONE
value|DVMRP_DONE
end_define

begin_define
define|#
directive|define
name|MRT_ADD_VIF
value|DVMRP_ADD_VIF
end_define

begin_define
define|#
directive|define
name|MRT_DEL_VIF
value|DVMRP_DEL_VIF
end_define

begin_define
define|#
directive|define
name|MRT_ADD_MFC
value|DVMRP_ADD_MFC
end_define

begin_define
define|#
directive|define
name|MRT_DEL_MFC
value|DVMRP_DEL_MFC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IGMP_PIM
end_ifndef

begin_define
define|#
directive|define
name|IGMP_PIM
value|0x14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IPIP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IPIP
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The original multicast releases defined  * IGMP_HOST_{MEMBERSHIP_QUERY,MEMBERSHIP_REPORT,NEW_MEMBERSHIP_REPORT  *   ,LEAVE_MESSAGE}.  Later releases removed the HOST and inserted  * the IGMP version number.  NetBSD inserted the version number in  * a different way.  mrouted uses the new names, so we #define them  * to the old ones if needed.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IGMP_MEMBERSHIP_QUERY
argument_list|)
operator|&&
name|defined
argument_list|(
name|IGMP_HOST_MEMBERSHIP_QUERY
argument_list|)
end_if

begin_define
define|#
directive|define
name|IGMP_MEMBERSHIP_QUERY
value|IGMP_HOST_MEMBERSHIP_QUERY
end_define

begin_define
define|#
directive|define
name|IGMP_V2_LEAVE_GROUP
value|IGMP_HOST_LEAVE_MESSAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IGMP_V1_MEMBERSHIP_REPORT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IGMP_HOST_MEMBERSHIP_REPORT
end_ifdef

begin_define
define|#
directive|define
name|IGMP_V1_MEMBERSHIP_REPORT
value|IGMP_HOST_MEMBERSHIP_REPORT
end_define

begin_define
define|#
directive|define
name|IGMP_V2_MEMBERSHIP_REPORT
value|IGMP_HOST_NEW_MEMBERSHIP_REPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IGMP_v1_HOST_MEMBERSHIP_REPORT
end_ifdef

begin_define
define|#
directive|define
name|IGMP_V1_MEMBERSHIP_REPORT
value|IGMP_v1_HOST_MEMBERSHIP_REPORT
end_define

begin_define
define|#
directive|define
name|IGMP_V2_MEMBERSHIP_REPORT
value|IGMP_v2_HOST_MEMBERSHIP_REPORT
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
comment|/*  * NetBSD also renamed the mtrace types.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IGMP_MTRACE_RESP
argument_list|)
operator|&&
name|defined
argument_list|(
name|IGMP_MTRACE_REPLY
argument_list|)
end_if

begin_define
define|#
directive|define
name|IGMP_MTRACE_RESP
value|IGMP_MTRACE_REPLY
end_define

begin_define
define|#
directive|define
name|IGMP_MTRACE
value|IGMP_MTRACE_QUERY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|scaletime
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|log
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|register_input_handler
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ihfunc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* igmp.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_igmp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_igmp
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|build_igmp
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|int
operator|,
name|int
operator|,
name|u_int32
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_igmp
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|int
operator|,
name|int
operator|,
name|u_int32
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|igmp_packet_kind
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
specifier|extern
name|int
name|igmp_debug_kind
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

begin_comment
comment|/* icmp.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_icmp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ipip.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_ipip
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_ipip_on_vif
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_ipip
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|int
operator|,
name|int
operator|,
name|u_int32
operator|,
name|int
operator|,
expr|struct
name|uvif
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* callout.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|callout_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_all_callouts
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_callout_queue
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_nextTimer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_setTimer
name|__P
argument_list|(
operator|(
name|int
operator|,
name|cfunc_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_clearTimer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_leftTimer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* route.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_routes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|start_route_updates
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_route
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int
operator|,
name|u_int32
operator|,
name|vifi_t
operator|,
expr|struct
name|listaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_routes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expire_all_routes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_all_routes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_probe
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_report
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rtentry
modifier|*
name|determine_route
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|report
name|__P
argument_list|(
operator|(
name|int
operator|,
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|report_to_all_neighbors
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|report_next_chunk
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|blaster_alloc
name|__P
argument_list|(
operator|(
name|vifi_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_vif_to_routes
name|__P
argument_list|(
operator|(
name|vifi_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_vif_from_routes
name|__P
argument_list|(
operator|(
name|vifi_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_neighbor_to_routes
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_neighbor_from_routes
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|vifi_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_routes
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vif.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zero_vif
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_installvifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_vif_state
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_on_vif
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
operator|,
name|u_int32
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|find_vif
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_vifs
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stop_all_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|listaddr
modifier|*
name|neighbor_info
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_group_report
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|query_groups
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|probe_for_neighbors
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|listaddr
modifier|*
name|update_neighbor
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_neighbor_request
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_neighbor_request2
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_info_request
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
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
specifier|extern
name|void
name|accept_info_reply
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
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
specifier|extern
name|void
name|accept_neighbors
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_neighbors2
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_leave_message
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_membership_query
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* config.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|config_vifs_from_kernel
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cfparse.y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|config_vifs_from_file
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inet.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inet_valid_host
name|__P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet_valid_mask
name|__P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet_valid_subnet
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inet_fmt
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inet_fmts
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|inet_parse
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet_cksum
name|__P
argument_list|(
operator|(
name|u_short
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prune.c */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|kroutes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|determine_forwvifs
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_prune_or_graft
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_table_entry
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|del_table_entry
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|,
name|u_int32
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_table_entry
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_src_grp
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_ktable
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|steal_sources
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reset_neighbor_state
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|grplst_mem
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_all_prunes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_table_entry
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_cache
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_lclgrp
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_lclgrp
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|chkgrp_graft
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_prune
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
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
specifier|extern
name|void
name|accept_graft
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
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
specifier|extern
name|void
name|accept_g_ack
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* u_int is promoted u_char */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|accept_mtrace
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kern.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|k_set_rcvbuf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_hdr_include
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_set_ttl
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_set_loop
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_set_if
name|__P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_join
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_leave
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_init_dvmrp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_stop_dvmrp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_add_vif
name|__P
argument_list|(
operator|(
name|vifi_t
operator|,
expr|struct
name|uvif
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_del_vif
name|__P
argument_list|(
operator|(
name|vifi_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_add_rg
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
expr|struct
name|gtable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|k_del_rg
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
expr|struct
name|gtable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|k_get_version
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SNMP
end_ifdef

begin_comment
comment|/* prune.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gtable
modifier|*
name|find_grp
name|__P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stable
modifier|*
name|find_grp_src
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|next_grp_src_mask
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|*
operator|,
expr|struct
name|stable
operator|*
operator|*
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refresh_sg
name|__P
argument_list|(
operator|(
expr|struct
name|sioc_sg_req
operator|*
operator|,
expr|struct
name|gtable
operator|*
operator|,
expr|struct
name|stable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|next_child
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|*
operator|,
expr|struct
name|stable
operator|*
operator|*
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|vifi_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* route.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtentry
modifier|*
name|snmp_find_route
name|__P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|next_route
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|*
operator|,
name|u_int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|next_route_child
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|*
operator|,
name|u_int32
operator|,
name|u_int32
operator|,
name|vifi_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_comment
comment|/* prune.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gtable
modifier|*
name|kernel_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gtable
modifier|*
name|gtp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rsrr.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|rsrr_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_clean
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_cache_send
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_cache_clean
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

end_unit

