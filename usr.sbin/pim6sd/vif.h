begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND  *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.  * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.  * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VIF_H
end_ifndef

begin_define
define|#
directive|define
name|VIF_H
end_define

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
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_mroute.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_mroute.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|total_interfaces
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
name|struct
name|uvif
name|uvifs
index|[]
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
name|phys_vif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|reg_vif_num
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NO_VIF
value|((vifi_t)MAXVIFS)
end_define

begin_comment
comment|/* An invalid vif index */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_METRIC
value|1
end_define

begin_define
define|#
directive|define
name|VIFF_DOWN
value|0x000100
end_define

begin_define
define|#
directive|define
name|VIFF_DISABLED
value|0x000200
end_define

begin_define
define|#
directive|define
name|VIFF_QUERIER
value|0x000400
end_define

begin_define
define|#
directive|define
name|VIFF_REXMIT_PRUNES
value|0x004000
end_define

begin_define
define|#
directive|define
name|VIFF_DR
value|0x040000
end_define

begin_define
define|#
directive|define
name|VIFF_NONBRS
value|0x080000
end_define

begin_define
define|#
directive|define
name|VIFF_PIM_NBR
value|0x200000
end_define

begin_define
define|#
directive|define
name|VIFF_POINT_TO_POINT
value|0x400000
end_define

begin_define
define|#
directive|define
name|NBRTYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|NBRBITS
value|sizeof(NBRTYPE) *8
end_define

begin_decl_stmt
specifier|extern
name|if_set
name|if_nullset
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IF_ISEMPTY
parameter_list|(
name|p
parameter_list|)
value|(memcmp((p),&if_nullset, sizeof(if_nullset)) == 0)
end_define

begin_define
define|#
directive|define
name|IF_SAME
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|(memcmp((p1),(p2),sizeof(*(p1))) == 0)
end_define

begin_define
define|#
directive|define
name|IF_CLR_MASK
parameter_list|(
name|p
parameter_list|,
name|mask
parameter_list|)
define|\
value|{\     int idx;\     for (idx = 0; idx< sizeof(*(p))/sizeof(fd_mask); idx++) {\         (p)->ifs_bits[idx]&= ~((mask)->ifs_bits[idx]);\     }\   }
end_define

begin_define
define|#
directive|define
name|IF_MERGE
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|,
name|result
parameter_list|)
define|\
value|{\     int idx;\     for (idx = 0; idx< sizeof(*(p1))/sizeof(fd_mask); idx++) {\         (result)->ifs_bits[idx] = (p1)->ifs_bits[idx]|(p2)->ifs_bits[idx]; \     }\   }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|NBRTYPE
name|hi
decl_stmt|;
name|NBRTYPE
name|lo
decl_stmt|;
block|}
name|nbrbitmap_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vf_element
block|{
name|struct
name|vf_element
modifier|*
name|vfe_next
decl_stmt|;
name|struct
name|sockaddr_in6
modifier|*
name|vfe_addr
decl_stmt|;
name|struct
name|in6_addr
name|vfe_mask
decl_stmt|;
name|int
name|vfe_flags
decl_stmt|;
define|#
directive|define
name|VFRF_EXACT
value|0x0001
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFT_ACCEPT
value|1
end_define

begin_define
define|#
directive|define
name|VFT_DENY
value|2
end_define

begin_define
define|#
directive|define
name|VFF_BIDIR
value|1
end_define

begin_struct
struct|struct
name|vif_filter
block|{
name|int
name|vf_type
decl_stmt|;
name|int
name|vf_flags
decl_stmt|;
name|struct
name|vf_element
modifier|*
name|vf_filter
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|listaddr
block|{
name|struct
name|listaddr
modifier|*
name|al_next
decl_stmt|;
comment|/* link to next addr, MUST BE FIRST */
name|struct
name|sockaddr_in6
name|al_addr
decl_stmt|;
comment|/* local group or neighbor address  */
name|u_long
name|al_timer
decl_stmt|;
comment|/* for timing out group or neighbor */
name|time_t
name|al_ctime
decl_stmt|;
comment|/* entry creation time              */
union|union
block|{
name|u_int32
name|alu_genid
decl_stmt|;
comment|/* generation id for neighbor       */
name|struct
name|sockaddr_in6
name|alu_reporter
decl_stmt|;
comment|/* a host which reported membership */
block|}
name|al_alu
union|;
name|u_char
name|al_pv
decl_stmt|;
comment|/* router protocol version          */
name|u_char
name|al_mv
decl_stmt|;
comment|/* router mrouted version           */
name|u_char
name|al_old
decl_stmt|;
comment|/* time since heard old report      */
name|u_char
name|al_index
decl_stmt|;
comment|/* neighbor index                   */
name|u_long
name|al_timerid
decl_stmt|;
comment|/* timer for group membership       */
name|u_long
name|al_query
decl_stmt|;
comment|/* timer for repeated leave query   */
name|u_int16
name|al_flags
decl_stmt|;
comment|/* flags related to this neighbor   */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|al_genid
value|al_alu.alu_genid
end_define

begin_define
define|#
directive|define
name|al_reporter
value|al_alu.alu_reporter
end_define

begin_comment
comment|/*  * User level Virtual Interface structure  *  * A "virtual interface" is either a physical, multicast-capable interface  * (called a "phyint"), a virtual point-to-point link (called a "tunnel")  * or a "register vif" used by PIM. The register vif is used by the  * Designated Router (DR) to send encapsulated data packets to the  * Rendevous Point (RP) for a particular group. The data packets are  * encapsulated in PIM messages (IPPROTO_PIM = 103) and then unicast to  * the RP.  * (Note: all addresses, subnet numbers and masks are kept in NETWORK order.)  */
end_comment

begin_struct
struct|struct
name|uvif
block|{
name|u_int
name|uv_flags
decl_stmt|;
name|u_char
name|uv_metric
decl_stmt|;
comment|/* VIFF_ flags defined below            */
name|u_char
name|uv_admetric
decl_stmt|;
comment|/* advertised cost of this vif          */
name|u_int
name|uv_rate_limit
decl_stmt|;
comment|/* rate limit on this vif               */
name|struct
name|phaddr
modifier|*
name|uv_linklocal
decl_stmt|;
comment|/* link-local address of this vif      */
name|struct
name|sockaddr_in6
name|uv_rmt_addr
decl_stmt|;
comment|/* remote end-point addr (tunnels only) */
name|struct
name|sockaddr_in6
name|uv_dst_addr
decl_stmt|;
comment|/* destination for PIM messages         */
name|struct
name|sockaddr_in6
name|uv_prefix
decl_stmt|;
comment|/* prefix (phyints only) */
name|struct
name|in6_addr
name|uv_subnetmask
decl_stmt|;
comment|/* subnet mask (phyints only) */
name|char
name|uv_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name */
name|u_int
name|uv_ifindex
decl_stmt|;
comment|/* index of the interface */
name|u_int
name|uv_siteid
decl_stmt|;
comment|/* index of the site on the interface */
name|struct
name|listaddr
modifier|*
name|uv_groups
decl_stmt|;
comment|/* list of local groups  (phyints only) */
name|struct
name|lisaddr
modifier|*
name|uv_dvmrp_neighbors
decl_stmt|;
name|nbrbitmap_t
name|uv_nbrmap
decl_stmt|;
comment|/* bitmap of active neighboring routers */
name|struct
name|listaddr
modifier|*
name|uv_querier
decl_stmt|;
comment|/* MLD querier on vif */
name|int
name|uv_prune_lifetime
decl_stmt|;
comment|/* Prune lifetime or 0 for default  */
name|struct
name|vif_acl
modifier|*
name|uv_acl
decl_stmt|;
comment|/* access control list of groups        */
name|int
name|uv_leaftimer
decl_stmt|;
comment|/* time until this vif is considrd leaf */
name|struct
name|phaddr
modifier|*
name|uv_addrs
decl_stmt|;
comment|/* Additional addresses on this vif     */
name|struct
name|vif_filter
modifier|*
name|uvfilter
decl_stmt|;
comment|/* Route filters on this vif            */
name|u_int16
name|uv_pim_hello_timer
decl_stmt|;
comment|/* timer for sending PIM hello msgs  */
name|u_int16
name|uv_gq_timer
decl_stmt|;
comment|/* Group Query timer                    */
name|u_int16
name|uv_jp_timer
decl_stmt|;
comment|/* Join/Prune timer 			*/
name|int
name|uv_local_pref
decl_stmt|;
comment|/* default local preference for assert  */
name|int
name|uv_local_metric
decl_stmt|;
comment|/* default local metric for assert     */
name|struct
name|pim_nbr_entry
modifier|*
name|uv_pim_neighbors
decl_stmt|;
comment|/* list of PIM nbr routers */
name|void
modifier|*
name|config_attr
decl_stmt|;
comment|/* temporary buffer while parsing config */
comment|/* the followings are to collect statistics */
comment|/* incoming PIM6 packets on this interface */
name|u_quad_t
name|uv_in_pim6_hello
decl_stmt|;
name|u_quad_t
name|uv_in_pim6_join_prune
decl_stmt|;
name|u_quad_t
name|uv_in_pim6_bootsrap
decl_stmt|;
name|u_quad_t
name|uv_in_pim6_assert
decl_stmt|;
comment|/* outgoing PIM6 packets on this interface */
name|u_quad_t
name|uv_out_pim6_hello
decl_stmt|;
name|u_quad_t
name|uv_out_pim6_join_prune
decl_stmt|;
name|u_quad_t
name|uv_out_pim6_bootsrap
decl_stmt|;
name|u_quad_t
name|uv_out_pim6_assert
decl_stmt|;
comment|/* incoming MLD packets on this interface */
name|u_quad_t
name|uv_in_mld_query
decl_stmt|;
name|u_quad_t
name|uv_in_mld_report
decl_stmt|;
name|u_quad_t
name|uv_in_mld_done
decl_stmt|;
comment|/* outgoing MLD packets on this interface */
name|u_quad_t
name|uv_out_mld_query
decl_stmt|;
name|u_quad_t
name|uv_out_mld_report
decl_stmt|;
name|u_quad_t
name|uv_out_mld_done
decl_stmt|;
comment|/* statistics about the forwarding cache in kernel */
name|u_quad_t
name|uv_cache_miss
decl_stmt|;
name|u_quad_t
name|uv_cache_notcreated
decl_stmt|;
comment|/* occurrences of timeouts */
name|u_quad_t
name|uv_pim6_nbr_timo
decl_stmt|;
name|u_quad_t
name|uv_listener_timo
decl_stmt|;
name|u_quad_t
name|uv_outif_timo
decl_stmt|;
comment|/* outgoing interfaces timers */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|phaddr
block|{
name|struct
name|phaddr
modifier|*
name|pa_next
decl_stmt|;
name|struct
name|sockaddr_in6
name|pa_addr
decl_stmt|;
name|struct
name|sockaddr_in6
name|pa_prefix
decl_stmt|;
name|struct
name|in6_addr
name|pa_subnetmask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The Access Control List (list with scoped addresses) member */
end_comment

begin_define
define|#
directive|define
name|VIFF_NOLISTENER
value|0x800000
end_define

begin_comment
comment|/* no listener on the link   */
end_comment

begin_struct
struct|struct
name|vif_acl
block|{
name|struct
name|vif_acl
modifier|*
name|acl_next
decl_stmt|;
name|struct
name|sockaddr_in6
name|acl_addr
decl_stmt|;
name|struct
name|in6_addr
name|acl_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used to get the RPF neighbor and IIF info  * for a given source from the unicast routing table.  */
end_comment

begin_struct
struct|struct
name|rpfctl
block|{
name|struct
name|sockaddr_in6
name|source
decl_stmt|;
comment|/* the source for which we want iif and rpfnbr */
name|struct
name|sockaddr_in6
name|rpfneighbor
decl_stmt|;
comment|/* next hop towards the source */
name|vifi_t
name|iif
decl_stmt|;
comment|/* the incoming interface to reach the next hop */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|init_vifs
name|__P
argument_list|(
operator|(
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|sockaddr_in6
modifier|*
name|max_global_address
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|sockaddr_in6
modifier|*
name|uv_global
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|local_address
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|sockaddr_in6
modifier|*
name|local_iface
parameter_list|(
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|vifi_t
name|find_vif_direct
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|find_vif_direct_local
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vif_forwarder
name|__P
argument_list|(
operator|(
name|if_set
operator|*
name|p1
operator|,
name|if_set
operator|*
name|p2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|if_set
modifier|*
name|vif_and
name|__P
argument_list|(
operator|(
name|if_set
operator|*
name|p1
operator|,
name|if_set
operator|*
name|p2
operator|,
name|if_set
operator|*
name|result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|if_set
modifier|*
name|vif_xor
name|__P
argument_list|(
operator|(
name|if_set
operator|*
name|p1
operator|,
name|if_set
operator|*
name|p2
operator|,
name|if_set
operator|*
name|result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uvif
modifier|*
name|find_vif
name|__P
argument_list|(
operator|(
name|char
operator|*
name|ifname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

