begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $Id: defs.h,v 1.4 1993/06/24 05:11:16 deering Exp $  */
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
value|2
end_define

begin_comment
comment|/* increment when packet format/content changes */
end_comment

begin_define
define|#
directive|define
name|MROUTED_VERSION
value|0
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
value|( (MROUTED_VERSION<< 8) | PROTOCOL_VERSION )
end_define

begin_comment
comment|/* for IGMP 'group' field of DVMRP messages */
end_comment

begin_comment
comment|/*  * External declarations for global variables and functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|recv_buf
index|[
name|MAX_IP_PACKET_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|send_buf
index|[
name|MAX_IP_PACKET_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|igmp_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|allhosts_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|dvmrp_group
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
name|u_long
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

begin_ifndef
ifndef|#
directive|ifndef
name|htonl
end_ifndef

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

end_unit

