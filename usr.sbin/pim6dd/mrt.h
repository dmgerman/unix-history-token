begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Oregon.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Oregon.  *  The name of the University of Oregon may not be used to endorse or   *  promote products derived from this software without specific prior   *  written permission.  *  *  THE UNIVERSITY OF OREGON DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND   *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL UO, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to   *  Kurt Windisch (kurtw@antc.uoregon.edu)  *  *  $Id: mrt.h,v 1.2 1999/08/24 10:04:56 jinmei Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from PIM sparse-mode pimd.  * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *    * The pimd program is COPYRIGHT 1998 by University of Southern California.  *  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *   * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
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

begin_comment
comment|/* Macro to duplicate oif info (oif bits, timers): XXX: unused */
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
value|do {                                                           \                 VIFM_COPY((from)->joined_oifs, (to)->joined_oifs);         \                 VIFM_COPY((from)->oifs, (to)->oifs);                       \                 VIFM_COPY((from)->leaves, (to)->leaves);                   \                 VIFM_COPY((from)->pruned_oifs, (to)->pruned_oifs);         \                 bcopy((from)->prune_timers, (to)->prune_timers,            \ 		      numvifs*sizeof((from)->prune_timers[0]));            \                 bcopy((from)->prune_delay_timerids,                        \ 		      (to)->prune_delay_timerids,                          \ 		      numvifs*sizeof((from)->prune_delay_timerids[0]));    \                 (to)->join_delay_timerid = (from)->join_delay_timerid;     \ 	    } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SAVE_MEMORY
end_ifdef

begin_define
define|#
directive|define
name|FREE_MRTENTRY
parameter_list|(
name|mrtentry_ptr
parameter_list|)
define|\
value|do {                                                          \                   u_int16 i;                                               \                   u_long *il_ptr;                                          \ 		  free((char *)((mrtentry_ptr)->prune_timers));            \ 		  for(i=0, il_ptr=(mrtentry_ptr)->prune_delay_timerids;    \                       i<numvifs; i++, il_ptr++)                            \ 		       timer_clearTimer(*il_ptr);                          \ 		  free((char *)((mrtentry_ptr)->prune_delay_timerids));    \                   timer_clearTimer((mrtentry_ptr)->join_delay_timerid);    \ 		  delete_pim6_graft_entry((mrtentry_ptr));                  \                   free((char *)(mrtentry_ptr));                            \ 	     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREE_MRTENTRY
parameter_list|(
name|mrtentry_ptr
parameter_list|)
define|\
value|do {                                                          \                   u_int16 i;                                               \                   u_long *il_ptr;                                          \ 		  free((char *)((mrtentry_ptr)->prune_timers));            \ 		  for(i=0, il_ptr=(mrtentry_ptr)->prune_delay_timerids;    \                       i<total_interfaces; i++, il_ptr++)                   \ 		       timer_clearTimer(*il_ptr);                          \ 		  free((char *)((mrtentry_ptr)->prune_delay_timerids));    \                   free((char *)((mrtentry_ptr)->last_assert));             \                   free((char *)((mrtentry_ptr)->last_prune));              \                   timer_clearTimer((mrtentry_ptr)->join_delay_timerid);    \ 		  delete_pim6_graft_entry((mrtentry_ptr));                  \                   free((char *)(mrtentry_ptr));                            \ 	     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SAVE_MEMORY */
end_comment

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
comment|/* link to next neighbor	    */
name|struct
name|pim_nbr_entry
modifier|*
name|prev
decl_stmt|;
comment|/* link to prev neighbor	    */
name|struct
name|sockaddr_in6
name|address
decl_stmt|;
comment|/* neighbor address		    */
name|vifi_t
name|vifi
decl_stmt|;
comment|/* which interface		    */
name|u_int16
name|timer
decl_stmt|;
comment|/* for timing out neighbor	    */
block|}
name|pim_nbr_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used to get forwarded data related counts (number of packet, number of  * bits, etc)  */
end_comment

begin_struct
struct|struct
name|sg_count
block|{
name|u_long
name|pktcnt
decl_stmt|;
comment|/*  Number of packets for (s,g) */
name|u_long
name|bytecnt
decl_stmt|;
comment|/*  Number of bytes for (s,g)   */
name|u_long
name|wrong_if
decl_stmt|;
comment|/*  Number of packets received on wrong iif for (s,g) */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mrtentry
name|mrtentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pim_graft_entry
block|{
name|struct
name|pim_graft_entry
modifier|*
name|next
decl_stmt|;
name|struct
name|pim_graft_entry
modifier|*
name|prev
decl_stmt|;
name|mrtentry_t
modifier|*
name|mrtlink
decl_stmt|;
block|}
name|pim_graft_entry_t
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
comment|/* link to next entry		    */
name|struct
name|srcentry
modifier|*
name|prev
decl_stmt|;
comment|/* link to prev entry		    */
name|struct
name|sockaddr_in6
name|address
decl_stmt|;
comment|/* source or RP address 	    */
name|struct
name|mrtentry
modifier|*
name|mrtlink
decl_stmt|;
comment|/* link to routing entries	    */
name|vifi_t
name|incoming
decl_stmt|;
comment|/* incoming vif			    */
name|struct
name|pim_nbr_entry
modifier|*
name|upstream
decl_stmt|;
comment|/* upstream router		    */
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
comment|/* Entry timer??? Delete?      	    */
block|}
name|srcentry_t
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
comment|/* link to next entry		    */
name|struct
name|grpentry
modifier|*
name|prev
decl_stmt|;
comment|/* link to prev entry		    */
name|struct
name|sockaddr_in6
name|group
decl_stmt|;
comment|/* subnet group of multicasts	    */
name|struct
name|mrtentry
modifier|*
name|mrtlink
decl_stmt|;
comment|/* link to (S,G) routing entries	    */
block|}
name|grpentry_t
typedef|;
end_typedef

begin_struct
struct|struct
name|mrtentry
block|{
name|struct
name|mrtentry
modifier|*
name|grpnext
decl_stmt|;
comment|/* next entry of same group	    */
name|struct
name|mrtentry
modifier|*
name|grpprev
decl_stmt|;
comment|/* prev entry of same group	    */
name|struct
name|mrtentry
modifier|*
name|srcnext
decl_stmt|;
comment|/* next entry of same source	    */
name|struct
name|mrtentry
modifier|*
name|srcprev
decl_stmt|;
comment|/* prev entry of same source	    */
name|struct
name|grpentry
modifier|*
name|group
decl_stmt|;
comment|/* pointer to group entry	    */
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
name|pruned_oifs
decl_stmt|;
comment|/* The pruned oifs (Prune received) */
name|if_set
name|asserted_oifs
decl_stmt|;
comment|/* The asserted oifs (Lost Assert)  */
name|if_set
name|filter_oifs
decl_stmt|;
comment|/* The filtered oifs */
name|if_set
name|leaves
decl_stmt|;
comment|/* Has directly connected members   */
name|struct
name|pim_nbr_entry
modifier|*
name|upstream
decl_stmt|;
comment|/* upstream router, needed because 					 * of the asserts it may be different 					 * than the source (or RP) upstream 					 * router. 					 */
name|u_int32
name|metric
decl_stmt|;
comment|/* Metric for the upstream          */
name|u_int32
name|preference
decl_stmt|;
comment|/* preference for the upstream      */
name|u_int16
modifier|*
name|prune_timers
decl_stmt|;
comment|/* prune timer list		    */
name|u_long
modifier|*
name|prune_delay_timerids
decl_stmt|;
comment|/* timers for LAN prunes     */
name|u_long
name|join_delay_timerid
decl_stmt|;
comment|/* timer for delay joins        */
name|u_int16
name|flags
decl_stmt|;
comment|/* The MRTF_* flags                 */
name|u_int16
name|timer
decl_stmt|;
comment|/* entry timer			    */
name|u_int
name|assert_timer
decl_stmt|;
name|struct
name|sg_count
name|sg_count
decl_stmt|;
name|u_long
modifier|*
name|last_assert
decl_stmt|;
comment|/* time for last data-driven assert */
name|u_long
modifier|*
name|last_prune
decl_stmt|;
comment|/* time for last data-driven prune  */
name|pim_graft_entry_t
modifier|*
name|graft
decl_stmt|;
comment|/* Pointer into graft entry list    */
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
struct|;
end_struct

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

begin_define
define|#
directive|define
name|FILTER_RANGE
value|0
end_define

begin_define
define|#
directive|define
name|FILTER_PREFIX
value|1
end_define

begin_struct
struct|struct
name|mrtfilter
block|{
name|struct
name|mrtfilter
modifier|*
name|next
decl_stmt|;
comment|/* link to the next entry */
name|int
name|type
decl_stmt|;
comment|/* filter type: RANGE or PREFIX */
union|union
block|{
comment|/* type specific data structure */
struct|struct
block|{
name|struct
name|sockaddr_in6
name|from
decl_stmt|;
name|struct
name|sockaddr_in6
name|to
decl_stmt|;
block|}
name|mrtfu_range
struct|;
struct|struct
block|{
name|struct
name|sockaddr_in6
name|prefix
decl_stmt|;
name|struct
name|in6_addr
name|mask
decl_stmt|;
block|}
name|mrtfu_prefix
struct|;
block|}
name|mrtu
union|;
name|if_set
name|ifset
decl_stmt|;
comment|/* interface list */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mrtf_from
value|mrtu.mrtfu_range.from
end_define

begin_define
define|#
directive|define
name|mrtf_to
value|mrtu.mrtfu_range.to
end_define

begin_define
define|#
directive|define
name|mrtf_prefix
value|mrtu.mrtfu_prefix.prefix
end_define

begin_define
define|#
directive|define
name|mrtf_mask
value|mrtu.mrtfu_prefix.mask
end_define

end_unit

