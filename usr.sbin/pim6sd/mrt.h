begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND  *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MRT_H
end_ifndef

begin_define
define|#
directive|define
name|MRT_H
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
file|<netinet/ip_mroute.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_mroute.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* flags for the mrt entries */
end_comment

begin_define
define|#
directive|define
name|MRTF_SPT
value|0x0001
end_define

begin_comment
comment|/* iif toward source                */
end_comment

begin_define
define|#
directive|define
name|MRTF_WC
value|0x0002
end_define

begin_comment
comment|/* (*,G) entry                      */
end_comment

begin_define
define|#
directive|define
name|MRTF_RP
value|0x0004
end_define

begin_comment
comment|/* iif toward RP                    */
end_comment

begin_define
define|#
directive|define
name|MRTF_NEW
value|0x0008
end_define

begin_comment
comment|/* new created routing entry        */
end_comment

begin_define
define|#
directive|define
name|MRTF_IIF_REGISTER
value|0x0020
end_define

begin_comment
comment|/* ???                              */
end_comment

begin_define
define|#
directive|define
name|MRTF_REGISTER
value|0x0080
end_define

begin_comment
comment|/* ???                              */
end_comment

begin_define
define|#
directive|define
name|MRTF_KERNEL_CACHE
value|0x0200
end_define

begin_comment
comment|/* a mirror for the kernel cache    */
end_comment

begin_define
define|#
directive|define
name|MRTF_NULL_OIF
value|0x0400
end_define

begin_comment
comment|/* null oif cache..     ???         */
end_comment

begin_define
define|#
directive|define
name|MRTF_REG_SUPP
value|0x0800
end_define

begin_comment
comment|/* register suppress    ???         */
end_comment

begin_define
define|#
directive|define
name|MRTF_ASSERTED
value|0x1000
end_define

begin_comment
comment|/* upstream is not that of src ???  */
end_comment

begin_define
define|#
directive|define
name|MRTF_SG
value|0x2000
end_define

begin_comment
comment|/* (S,G) pure, not hanging off of (*,G)*/
end_comment

begin_define
define|#
directive|define
name|MRTF_PMBR
value|0x4000
end_define

begin_comment
comment|/* (*,*,RP) entry (for interop)     */
end_comment

begin_define
define|#
directive|define
name|MRTF_MFC_CLONE_SG
value|0x8000
end_define

begin_comment
comment|/* clone (S,G) MFC from (*,G) or (*,*,RP) */
end_comment

begin_define
define|#
directive|define
name|CREATE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DONT_CREATE
value|FALSE
end_define

begin_define
define|#
directive|define
name|MFC_MOVE_FORCE
value|0x1
end_define

begin_define
define|#
directive|define
name|MFC_UPDATE_FORCE
value|0x2
end_define

begin_comment
comment|/* Macro to duplicate oif info (oif bits, timers) */
end_comment

begin_define
define|#
directive|define
name|VOIF_COPY
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|do {									\ 			IF_COPY(&from->joined_oifs ,&to->joined_oifs);			\ 			IF_COPY(&from->oifs ,&to->oifs );				\ 			IF_COPY(&from->leaves ,&to->leaves);				\ 			IF_COPY(&from->pruned_oifs ,&to->leaves );			\ 			IF_COPY(&from->asserted_oifs ,&to->asserted_oifs);		\ 			bcopy(from->vif_timers , to->vif_timers ,			\ 			numvifs*sizeof(from->vif_timers[0]));				\ 			bcopy(from->vif_deletion_delay , to->vif_deletion_delay ,	\ 			numvifs*sizeof(from->vif_deletion_delay[0]));			\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|FREE_MRTENTRY
parameter_list|(
name|mrtentry_ptr
parameter_list|)
define|\
value|do {									\ 				kernel_cache_t *prev;					\ 				kernel_cache_t *next;					\ 											\ 				free( (char *)( (mrtentry_ptr)->vif_timers ) );			\ 				free( (char *)( (mrtentry_ptr)->vif_deletion_delay ) );		\ 				for( next=(mrtentry_ptr)->kernel_cache ; next!=(kernel_cache_t *)NULL ; )	\ 				{										\ 					prev=next;								\ 					next=next->next;						\ 					free(prev);							\ 				}									\ 				free( (char *)( (mrtentry_ptr)->kernel_cache ) );			\ 				free( (char *)(mrtentry_ptr) );						\ 			} while (0)
end_define

begin_comment
comment|/*  * The complicated structure used by the more complicated Join/Prune  * message building  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|build_jp_message
block|{
name|struct
name|build_jp_message
modifier|*
name|next
decl_stmt|;
comment|/* Used to chain the free entries       */
name|u_int8
modifier|*
name|jp_message
decl_stmt|;
comment|/* The Join/Prune message               */
name|u_int32
name|jp_message_size
decl_stmt|;
comment|/* Size of the Join/Prune message (in bytes)  */
name|u_int16
name|holdtime
decl_stmt|;
comment|/* Join/Prune message holdtime field          */
name|struct
name|sockaddr_in6
name|curr_group
decl_stmt|;
comment|/* Current group address                      */
name|u_int8
name|curr_group_msklen
decl_stmt|;
comment|/* Current group masklen                      */
name|u_int8
modifier|*
name|join_list
decl_stmt|;
comment|/* The working area for the join addresses    */
name|u_int32
name|join_list_size
decl_stmt|;
comment|/* The size of the join_list (in bytes)       */
name|u_int16
name|join_addr_number
decl_stmt|;
comment|/* Number of the join addresses in join_list  */
name|u_int8
modifier|*
name|prune_list
decl_stmt|;
comment|/* The working area for the prune addresses   */
name|u_int32
name|prune_list_size
decl_stmt|;
comment|/* The size of the prune_list (in bytes)      */
name|u_int16
name|prune_addr_number
decl_stmt|;
comment|/* Number of the prune addresses in prune_list*/
name|u_int8
modifier|*
name|rp_list_join
decl_stmt|;
comment|/* The working area for RP join addresses     */
name|u_int32
name|rp_list_join_size
decl_stmt|;
comment|/* The size of the rp_list_join (in bytes)    */
name|u_int16
name|rp_list_join_number
decl_stmt|;
comment|/* Number of RP addresses in rp_list_join     */
name|u_int8
modifier|*
name|rp_list_prune
decl_stmt|;
comment|/* The working area for RP prune addresses   */
name|u_int32
name|rp_list_prune_size
decl_stmt|;
comment|/* The size of the rp_list_prune (in bytes)  */
name|u_int16
name|rp_list_prune_number
decl_stmt|;
comment|/* Number of RP addresses in rp_list_prune */
name|u_int8
modifier|*
name|num_groups_ptr
decl_stmt|;
comment|/* Pointer to number_of_groups in jp_message  */
block|}
name|build_jp_message_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pim_nbr_entry
block|{
name|struct
name|pim_nbr_entry
modifier|*
name|next
decl_stmt|;
comment|/* link to next neighbor          */
name|struct
name|pim_nbr_entry
modifier|*
name|prev
decl_stmt|;
comment|/* link to prev neighbor          */
name|struct
name|sockaddr_in6
name|address
decl_stmt|;
comment|/* neighbor address               */
name|vifi_t
name|vifi
decl_stmt|;
comment|/* which interface                */
name|u_int16
name|timer
decl_stmt|;
comment|/* for timing out neighbor        */
name|build_jp_message_t
modifier|*
name|build_jp_message
decl_stmt|;
comment|/* A structure for fairly                                            		 * complicated Join/Prune                                            		 * message construction.                                            		 */
block|}
name|pim_nbr_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|srcentry
block|{
name|struct
name|srcentry
modifier|*
name|next
decl_stmt|;
comment|/* link to next entry               */
name|struct
name|srcentry
modifier|*
name|prev
decl_stmt|;
comment|/* link to prev entry               */
name|struct
name|sockaddr_in6
name|address
decl_stmt|;
comment|/* source or RP address             */
name|struct
name|mrtentry
modifier|*
name|mrtlink
decl_stmt|;
comment|/* link to routing entries          */
name|vifi_t
name|incoming
decl_stmt|;
comment|/* incoming vif                     */
name|struct
name|pim_nbr_entry
modifier|*
name|upstream
decl_stmt|;
comment|/* upstream router                  */
name|u_int32
name|metric
decl_stmt|;
comment|/* Unicast Routing Metric to the source */
name|u_int32
name|preference
decl_stmt|;
comment|/* The metric preference (for assers)*/
name|u_int16
name|timer
decl_stmt|;
comment|/* Entry timer??? Delete?           */
name|struct
name|cand_rp
modifier|*
name|cand_rp
decl_stmt|;
comment|/* Used if this is rpentry_t        */
block|}
name|srcentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|srcentry_t
name|rpentry_t
typedef|;
end_typedef

begin_comment
comment|/* (RP<->group) matching table related structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cand_rp
block|{
name|struct
name|cand_rp
modifier|*
name|next
decl_stmt|;
comment|/* Next candidate RP                 */
name|struct
name|cand_rp
modifier|*
name|prev
decl_stmt|;
comment|/* Previous candidate RP             */
name|struct
name|rp_grp_entry
modifier|*
name|rp_grp_next
decl_stmt|;
comment|/* The rp_grp_entry chain for that RP*/
name|rpentry_t
modifier|*
name|rpentry
decl_stmt|;
comment|/* Pointer to the RP entry           */
block|}
name|cand_rp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|grp_mask
block|{
name|struct
name|grp_mask
modifier|*
name|next
decl_stmt|;
name|struct
name|grp_mask
modifier|*
name|prev
decl_stmt|;
name|struct
name|rp_grp_entry
modifier|*
name|grp_rp_next
decl_stmt|;
name|struct
name|sockaddr_in6
name|group_addr
decl_stmt|;
name|struct
name|in6_addr
name|group_mask
decl_stmt|;
name|struct
name|in6_addr
name|hash_mask
decl_stmt|;
name|u_int16
name|fragment_tag
decl_stmt|;
comment|/* Used for garbage collection    */
name|u_int8
name|group_rp_number
decl_stmt|;
comment|/* Used when assembling segments  */
block|}
name|grp_mask_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rp_grp_entry
block|{
name|struct
name|rp_grp_entry
modifier|*
name|rp_grp_next
decl_stmt|;
comment|/* Next entry for same RP */
name|struct
name|rp_grp_entry
modifier|*
name|rp_grp_prev
decl_stmt|;
comment|/* Prev entry for same RP */
name|struct
name|rp_grp_entry
modifier|*
name|grp_rp_next
decl_stmt|;
comment|/* Next entry for same grp prefix */
name|struct
name|rp_grp_entry
modifier|*
name|grp_rp_prev
decl_stmt|;
comment|/* Prev entry for same grp prefix */
name|struct
name|grpentry
modifier|*
name|grplink
decl_stmt|;
comment|/* Link to all grps via this entry*/
name|u_int16
name|advholdtime
decl_stmt|;
comment|/* The advertised holdtime */
name|u_int16
name|holdtime
decl_stmt|;
comment|/* The RP holdtime (will be aged) */
name|u_int16
name|fragment_tag
decl_stmt|;
comment|/* The fragment tag from the                                			 * received BSR message 						 */
name|u_int8
name|priority
decl_stmt|;
comment|/* The RP priority */
name|grp_mask_t
modifier|*
name|group
decl_stmt|;
comment|/* Pointer to (group,mask) entry  */
name|cand_rp_t
modifier|*
name|rp
decl_stmt|;
comment|/* Pointer to the RP */
block|}
name|rp_grp_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|grpentry
block|{
name|struct
name|grpentry
modifier|*
name|next
decl_stmt|;
comment|/* link to next entry                */
name|struct
name|grpentry
modifier|*
name|prev
decl_stmt|;
comment|/* link to prev entry                */
name|struct
name|grpentry
modifier|*
name|rpnext
decl_stmt|;
comment|/* next grp for the same RP          */
name|struct
name|grpentry
modifier|*
name|rpprev
decl_stmt|;
comment|/* prev grp for the same RP          */
name|struct
name|sockaddr_in6
name|group
decl_stmt|;
comment|/* subnet group of multicasts        */
name|struct
name|sockaddr_in6
name|rpaddr
decl_stmt|;
comment|/* The IPv6 address of the RP        */
name|struct
name|mrtentry
modifier|*
name|mrtlink
decl_stmt|;
comment|/* link to (S,G) routing entries     */
name|rp_grp_entry_t
modifier|*
name|active_rp_grp
decl_stmt|;
comment|/* Pointer to the active rp_grp entry*/
name|struct
name|mrtentry
modifier|*
name|grp_route
decl_stmt|;
comment|/* Pointer to the (*,G) routing entry*/
block|}
name|grpentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mrtentry
block|{
name|struct
name|mrtentry
modifier|*
name|grpnext
decl_stmt|;
comment|/* next entry of same group         */
name|struct
name|mrtentry
modifier|*
name|grpprev
decl_stmt|;
comment|/* prev entry of same group         */
name|struct
name|mrtentry
modifier|*
name|srcnext
decl_stmt|;
comment|/* next entry of same source        */
name|struct
name|mrtentry
modifier|*
name|srcprev
decl_stmt|;
comment|/* prev entry of same source        */
name|struct
name|grpentry
modifier|*
name|group
decl_stmt|;
comment|/* pointer to group entry           */
name|struct
name|srcentry
modifier|*
name|source
decl_stmt|;
comment|/* pointer to source entry (or RP)  */
name|vifi_t
name|incoming
decl_stmt|;
comment|/* the iif (either toward S or RP)  */
name|if_set
name|oifs
decl_stmt|;
comment|/* The current result oifs          */
name|if_set
name|joined_oifs
decl_stmt|;
comment|/* The joined oifs (Join received)  */
name|if_set
name|pruned_oifs
decl_stmt|;
comment|/* The pruned oifs (Prune received) */
name|if_set
name|asserted_oifs
decl_stmt|;
comment|/* The asserted oifs (lost Assert)  */
name|if_set
name|leaves
decl_stmt|;
comment|/* Has directly connected members   */
name|struct
name|pim_nbr_entry
modifier|*
name|upstream
decl_stmt|;
comment|/* upstream router, needed because 				                                         * of the asserts it may be different                 				                         * than the source (or RP) upstream                               				             	 * router.                                        				     	 */
name|u_int32
name|metric
decl_stmt|;
comment|/* Routing Metric for this entry    */
name|u_int32
name|preference
decl_stmt|;
comment|/* The metric preference value      */
name|struct
name|sockaddr_in6
name|pmbr_addr
decl_stmt|;
comment|/* The PMBR address (for interop)   */
name|u_int16
modifier|*
name|vif_timers
decl_stmt|;
comment|/* vifs timer list                  */
name|u_int16
modifier|*
name|vif_deletion_delay
decl_stmt|;
comment|/* vifs deletion delay list    */
name|u_int16
name|flags
decl_stmt|;
comment|/* The MRTF_* flags                 */
name|u_int16
name|timer
decl_stmt|;
comment|/* entry timer                      */
name|u_int16
name|jp_timer
decl_stmt|;
comment|/* The Join/Prune timer             */
name|u_int16
name|rs_timer
decl_stmt|;
comment|/* Register-Suppression Timer       */
name|u_int
name|assert_timer
decl_stmt|;
name|u_int
name|assert_rate_timer
decl_stmt|;
name|struct
name|kernel_cache
modifier|*
name|kernel_cache
decl_stmt|;
comment|/* List of the kernel cache entries */
ifdef|#
directive|ifdef
name|RSRR
name|struct
name|rsrr_cache
modifier|*
name|rsrr_cache
decl_stmt|;
comment|/* Used to save RSRR requests for                                          * routes change notification.                                          */
endif|#
directive|endif
comment|/* RSRR */
block|}
name|mrtentry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used to get forwarded data related counts (number of packet, number of  * bits, etc)  */
end_comment

begin_struct
struct|struct
name|sg_count
block|{
name|u_quad_t
name|pktcnt
decl_stmt|;
comment|/*  Number of packets for (s,g) */
name|u_quad_t
name|bytecnt
decl_stmt|;
comment|/*  Number of bytes for (s,g)   */
name|u_quad_t
name|wrong_if
decl_stmt|;
comment|/*  Number of packets received on wrong iif for (s,g) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure to keep track of existing (S,G) MFC entries in the kernel  * for particular (*,G) or (*,*,RP) entry. We must keep track for  * each active source which doesn't have (S,G) entry in the daemon's  * routing table. We need to keep track of such sources for two reasons:  *  *    (1) If the kernel does not support (*,G) MFC entries (currently, the  * "official" mcast code doesn't), we must know all installed (s,G) entries  * in the kernel and modify them if the iif or oif for the (*,G) changes.  *  *    (2) By checking periodically the traffic coming from the shared tree,  * we can either delete the idle sources or switch to the shortest path.  *  * Note that even if we have (*,G) implemented in the kernel, we still  * need to have this structure because of (2)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|kernel_cache
block|{
name|struct
name|kernel_cache
modifier|*
name|next
decl_stmt|;
name|struct
name|kernel_cache
modifier|*
name|prev
decl_stmt|;
name|struct
name|sockaddr_in6
name|source
decl_stmt|;
name|struct
name|sockaddr_in6
name|group
decl_stmt|;
name|struct
name|sg_count
name|sg_count
decl_stmt|;
comment|/* The (s,g) data retated counters (see above) */
block|}
name|kernel_cache_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vif_count
block|{
name|u_long
name|icount
decl_stmt|;
comment|/* Input packet count on vif            */
name|u_long
name|ocount
decl_stmt|;
comment|/* Output packet count on vif           */
name|u_long
name|ibytes
decl_stmt|;
comment|/* Input byte count on vif              */
name|u_long
name|obytes
decl_stmt|;
comment|/* Output byte count on vif             */
block|}
struct|;
end_struct

begin_comment
comment|/* globals and functions exportations */
end_comment

begin_decl_stmt
specifier|extern
name|srcentry_t
modifier|*
name|srclist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|grpentry_t
modifier|*
name|grplist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_pim6_mrt
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
name|mrtentry_t
modifier|*
name|find_route
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|,
name|u_int16
name|flags
operator|,
name|char
name|create
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|grpentry_t
modifier|*
name|find_group
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|srcentry_t
modifier|*
name|find_source
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_mrtentry
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_srcentry
name|__P
argument_list|(
operator|(
name|srcentry_t
operator|*
name|srcentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_grpentry
name|__P
argument_list|(
operator|(
name|grpentry_t
operator|*
name|grpentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_mrtentry_all_kernel_cache
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_single_kernel_cache
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
name|kernel_cache_t
operator|*
name|kernel_cache_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_single_kernel_cache_addr
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_kernel_cache
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|,
name|u_int16
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

