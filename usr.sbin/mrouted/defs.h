begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
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
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/igmp.h>
end_include

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
name|VENDOR_CODE
value|1
end_define

begin_comment
comment|/* Get a new vendor code if you make significant 			     * changes to mrouted. */
end_comment

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
value|8
end_define

begin_comment
comment|/* increment on local changes or bug fixes, */
end_comment

begin_comment
comment|/* reset to 0 whever PROTOCOL_VERSION increments */
end_comment

begin_define
define|#
directive|define
name|MROUTED_LEVEL
value|((MROUTED_VERSION<< 8) | PROTOCOL_VERSION | \ 			((NF_PRUNE | NF_GENID | NF_MTRACE)<< 16) | \ 			(VENDOR_CODE<< 24))
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

begin_define
define|#
directive|define
name|signal
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|sigset(s,f)
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
name|DEFAULT_DEBUG
value|2
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
name|u_char
name|pruning
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
name|IGMP_MEMBERSHIP_QUERY
end_ifndef

begin_define
define|#
directive|define
name|IGMP_MEMBERSHIP_QUERY
value|IGMP_HOST_MEMBERSHIP_QUERY
end_define

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

begin_comment
comment|/* main.c */
end_comment

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
name|fd
operator|,
name|ihfunc_t
name|func
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
name|recvlen
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|int
name|type
operator|,
name|int
name|code
operator|,
name|u_int32
name|group
operator|,
name|int
name|datalen
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
name|age_callout_queue
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
name|delay
operator|,
name|cfunc_t
name|action
operator|,
name|char
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timer_clearTimer
name|__P
argument_list|(
operator|(
name|int
name|timer_id
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
name|origin
operator|,
name|u_int32
name|mask
operator|,
name|u_int
name|metric
operator|,
name|u_int32
name|src
operator|,
name|vifi_t
name|vifi
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
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
name|which_routes
operator|,
name|vifi_t
name|vifi
operator|,
name|u_int32
name|dst
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
name|which_routes
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
name|add_vif_to_routes
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
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
name|vifi
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
name|addr
operator|,
name|vifi_t
name|vifi
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
name|vifi_t
name|find_vif
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
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
name|fp
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
name|vifi
operator|,
name|u_int32
name|addr
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_int32
name|group
operator|,
name|int
name|r_type
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
name|int
name|update_neighbor
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|,
name|u_int32
name|addr
operator|,
name|int
name|msgtype
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
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
name|src
operator|,
name|u_int32
name|dst
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
name|src
operator|,
name|u_int32
name|dst
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_int32
name|group
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_int32
name|group
operator|,
name|int
name|tmo
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
name|naddr
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
name|nsubnet
operator|,
name|u_int32
name|nmask
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
name|addr
operator|,
name|char
operator|*
name|s
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
name|addr
operator|,
name|u_int32
name|mask
operator|,
name|char
operator|*
name|s
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
name|s
operator|,
name|int
name|n
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
name|addr
operator|,
name|u_int
name|len
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
name|add_table_entry
name|__P
argument_list|(
operator|(
name|u_int32
name|origin
operator|,
name|u_int32
name|mcastgrp
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
name|r
operator|,
name|u_int32
name|mcastgrp
operator|,
name|u_int
name|del_flag
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
name|r
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
name|accept_prune
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
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
name|rt
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
name|vifi
operator|,
name|u_int32
name|addr
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
name|vifi
operator|,
name|u_int32
name|mcastgrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scoped_addr
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|,
name|u_int32
name|addr
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
name|fp2
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
name|vifi
operator|,
name|u_int32
name|mcastgrp
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
name|vifi
operator|,
name|u_int32
name|mcastgrp
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
name|vifi
operator|,
name|u_int32
name|mcastgrp
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
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
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_int32
name|group
operator|,
name|char
operator|*
name|data
operator|,
name|u_int
name|no
operator|,
name|int
name|datalen
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
name|bufsize
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
name|bool
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
name|t
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
name|l
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
name|ifa
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
name|grp
operator|,
name|u_int32
name|ifa
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
name|grp
operator|,
name|u_int32
name|ifa
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
name|vifi
operator|,
expr|struct
name|uvif
operator|*
name|v
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
name|vifi
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
name|origin
operator|,
expr|struct
name|gtable
operator|*
name|g
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
name|origin
operator|,
expr|struct
name|gtable
operator|*
name|g
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
name|rtentry
modifier|*
name|snmp_find_route
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gtable
modifier|*
name|find_grp
name|__P
argument_list|(
operator|(
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

begin_decl_stmt
specifier|extern
name|int
name|find_src_grp
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|mask
operator|,
name|u_int32
name|grp
operator|)
argument_list|)
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
name|rsrr_read
name|__P
argument_list|(
operator|(
name|int
name|f
operator|,
name|fd_set
operator|*
name|rfd
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
name|gt
operator|,
name|int
name|notify
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
name|gt
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

