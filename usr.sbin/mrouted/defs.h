begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $Id: defs.h,v 3.5 1995/05/09 01:00:39 fenner Exp $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
value|5
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
value|( (MROUTED_VERSION<< 8) | PROTOCOL_VERSION | \ 			((NF_PRUNE | NF_GENID | NF_MTRACE)<< 16))
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

begin_comment
comment|/*  * External declarations for global variables and functions.  */
end_comment

begin_define
define|#
directive|define
name|RECV_BUF_SIZE
value|MAX_IP_PACKET_LEN
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

begin_function_decl
specifier|extern
name|void
name|log
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_igmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_igmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|send_igmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_route_updates
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_route
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|age_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expire_all_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_all_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_report
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|report
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|report_to_all_neighbors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|report_next_chunk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_vif_to_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_vif_from_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_neighbor_from_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_vifs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_vif_state
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vifi_t
name|find_vif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|age_vifs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_vifs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stop_all_vifs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|listaddr
modifier|*
name|neighbor_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_group_report
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|query_groups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|probe_for_neighbors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|update_neighbor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_neighbor_request
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_neighbor_request2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_neighbors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_neighbors2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|config_vifs_from_kernel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|config_vifs_from_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inet_valid_host
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inet_valid_subnet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_fmt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_fmts
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32
name|inet_parse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inet_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtentry
modifier|*
name|determine_route
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_ktable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_table_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|del_table_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_table_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_lclgrp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_lclgrp
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|kroutes
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|accept_prune
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|no_entry_exists
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtr_cnt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_all_prunes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|age_table_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_cache
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SNMP
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|rtentry
modifier|*
name|snmp_find_route
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|gtable
modifier|*
name|find_grp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|stable
modifier|*
name|find_grp_src
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|chkgrp_graft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_graft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|send_graft_ack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_g_ack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_mtrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_leave_message
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|accept_membership_query
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

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

begin_function_decl
specifier|extern
name|int
name|find_src_grp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|grplst_mem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scoped_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_function_decl
specifier|extern
name|void
name|k_set_rcvbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_hdr_include
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_set_ttl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_set_loop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_set_if
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_join
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_leave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_init_dvmrp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_stop_dvmrp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_add_vif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_del_vif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|k_add_rg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|k_del_rg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|k_get_version
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fopen
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|htonl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|u_long
name|htonl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|ntohl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_function_decl
specifier|extern
name|void
name|rsrr_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rsrr_read
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

end_unit

