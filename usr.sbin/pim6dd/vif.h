begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND   *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to   *  Pavlin Ivanov Radoslavov (pavlin@catarina.usc.edu)  *  *  $Id: vif.h,v 1.2 1999/08/24 16:45:23 jinmei Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Bitmap handling functions.  * These should be fast but generic.  bytes can be slow to zero and compare,  * words are hard to make generic.  Thus two sets of macros (yuk).  */
end_comment

begin_comment
comment|/*  * The VIFM_ functions should migrate out of<netinet/ip_mroute.h>, since  * the kernel no longer uses vifbitmaps.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VIFM_SET
end_ifndef

begin_typedef
typedef|typedef
name|u_int32
name|vifbitmap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VIFM_SET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m) |=  (1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_CLR
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m)&= ~(1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_ISSET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m)&   (1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_CLRALL
parameter_list|(
name|m
parameter_list|)
value|((m) = 0x00000000)
end_define

begin_define
define|#
directive|define
name|VIFM_COPY
parameter_list|(
name|mfrom
parameter_list|,
name|mto
parameter_list|)
value|((mto) = (mfrom))
end_define

begin_define
define|#
directive|define
name|VIFM_SAME
parameter_list|(
name|m1
parameter_list|,
name|m2
parameter_list|)
value|((m1) == (m2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * And<netinet/ip_mroute.h> was missing some required functions anyway  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|VIFM_SETALL
parameter_list|(
name|m
parameter_list|)
value|((m) = ~0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIFM_ISSET_ONLY
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m) == (1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_ISEMPTY
parameter_list|(
name|m
parameter_list|)
value|((m) == 0)
end_define

begin_define
define|#
directive|define
name|VIFM_CLR_MASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
value|((m)&= ~(mask))
end_define

begin_define
define|#
directive|define
name|VIFM_SET_MASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
value|((m) |= (mask))
end_define

begin_define
define|#
directive|define
name|VIFM_MERGE
parameter_list|(
name|m1
parameter_list|,
name|m2
parameter_list|,
name|result
parameter_list|)
value|((result) = (m1) | (m2))
end_define

begin_comment
comment|/*  * And<netinet6/ip6_mroute.h> was missing some required functions anyway  */
end_comment

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
name|IF_CLR_MASK
parameter_list|(
name|p
parameter_list|,
name|mask
parameter_list|)
define|\
value|{\ 	int idx;\ 	for (idx = 0; idx< sizeof(*(p))/sizeof(fd_mask); idx++) {\ 		(p)->ifs_bits[idx]&= ~((mask)->ifs_bits[idx]);\ 	}\   }
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
value|{\ 	int idx;\ 	for (idx = 0; idx< sizeof(*(p1))/sizeof(fd_mask); idx++) {\ 		(result)->ifs_bits[idx] = (p1)->ifs_bits[idx]|(p2)->ifs_bits[idx]; \ 	}\   }
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

begin_comment
comment|/* Check whether I am the forwarder on some LAN */
end_comment

begin_define
define|#
directive|define
name|VIFM_FORWARDER
parameter_list|(
name|leaves
parameter_list|,
name|oifs
parameter_list|)
value|((leaves)& (oifs))
end_define

begin_comment
comment|/*  * Neighbor bitmaps are, for efficiency, implemented as a struct  * containing two variables of a native machine type.  If you  * have a native type that's bigger than a long, define it below.  */
end_comment

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
value|sizeof(NBRTYPE) * 8
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

begin_define
define|#
directive|define
name|MAXNBRS
value|2 * NBRBITS
end_define

begin_define
define|#
directive|define
name|NBRM_SET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(((n)< NBRBITS) ? ((m).lo |= (1<< (n))) :  \ 				      ((m).hi |= (1<< (n - NBRBITS))))
end_define

begin_define
define|#
directive|define
name|NBRM_CLR
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(((n)< NBRBITS) ? ((m).lo&= ~(1<< (n))) : \ 				      ((m).hi&= ~(1<< (n - NBRBITS))))
end_define

begin_define
define|#
directive|define
name|NBRM_ISSET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(((n)< NBRBITS) ? ((m).lo& (1<< (n))) :   \ 				      ((m).hi& (1<< ((n) - NBRBITS))))
end_define

begin_define
define|#
directive|define
name|NBRM_CLRALL
parameter_list|(
name|m
parameter_list|)
value|((m).lo = (m).hi = 0)
end_define

begin_define
define|#
directive|define
name|NBRM_COPY
parameter_list|(
name|mfrom
parameter_list|,
name|mto
parameter_list|)
value|((mto).lo = (mfrom).lo, (mto).hi = (mfrom).hi)
end_define

begin_define
define|#
directive|define
name|NBRM_SAME
parameter_list|(
name|m1
parameter_list|,
name|m2
parameter_list|)
value|(((m1).lo == (m2).lo)&& ((m1).hi == (m2).hi))
end_define

begin_define
define|#
directive|define
name|NBRM_ISEMPTY
parameter_list|(
name|m
parameter_list|)
value|(((m).lo == 0)&& ((m).hi == 0))
end_define

begin_define
define|#
directive|define
name|NBRM_SETMASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
value|(((m).lo |= (mask).lo),((m).hi |= (mask).hi))
end_define

begin_define
define|#
directive|define
name|NBRM_CLRMASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
value|(((m).lo&= ~(mask).lo),((m).hi&= ~(mask).hi))
end_define

begin_define
define|#
directive|define
name|NBRM_MASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
value|(((m).lo&= (mask).lo),((m).hi&= (mask).hi))
end_define

begin_define
define|#
directive|define
name|NBRM_ISSETMASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
value|(((m).lo& (mask).lo) || ((m).hi& (mask).hi))
end_define

begin_define
define|#
directive|define
name|NBRM_ISSETALLMASK
parameter_list|(
name|m
parameter_list|,
name|mask
parameter_list|)
define|\
value|((((m).lo& (mask).lo) == (mask).lo)&& \ 				 (((m).hi& (mask).hi) == (mask).hi))
end_define

begin_comment
comment|/*  * This macro is TRUE if all the subordinates have been pruned, or if  * there are no subordinates on this vif.  * The arguments is the map of subordinates, the map of neighbors on the  * vif, and the map of received prunes.  */
end_comment

begin_define
define|#
directive|define
name|SUBS_ARE_PRUNED
parameter_list|(
name|sub
parameter_list|,
name|vifmask
parameter_list|,
name|prunes
parameter_list|)
define|\
value|(((sub).lo& (vifmask).lo) == ((prunes).lo& (vifmask).lo& (sub).lo)&& \      ((sub).hi& (vifmask).hi) == ((prunes).hi& (vifmask).hi& (sub).hi))
end_define

begin_comment
comment|/*  * User level Virtual Interface structure  *  * A "virtual interface" is either a physical, multicast-capable interface  * (called a "phyint"), a virtual point-to-point link (called a "tunnel")  * or a "register vif" used by PIM. The register vif is used by the  * Designated Router (DR) to send encapsulated data packets to the  * Rendevous Point (RP) for a particular group. The data packets are   * encapsulated in PIM messages (IPPROTO_PIM = 103) and then unicast to   * the RP.  * (Note: all addresses, subnet numbers and masks are kept in NETWORK order.)  */
end_comment

begin_struct
struct|struct
name|uvif
block|{
name|u_int
name|uv_flags
decl_stmt|;
comment|/* VIFF_ flags defined below            */
name|u_char
name|uv_metric
decl_stmt|;
comment|/* cost of this vif                     */
name|u_char
name|uv_admetric
decl_stmt|;
comment|/* advertised cost of this vif          */
if|#
directive|if
literal|0
comment|/* unused for IPv6? */
block|u_char	     uv_threshold;
comment|/* min ttl required to forward on vif   */
endif|#
directive|endif
name|u_int
name|uv_rate_limit
decl_stmt|;
comment|/* rate limit on this vif               */
name|struct
name|sockaddr_in6
name|uv_lcl_addr
decl_stmt|;
comment|/* local address of this vif            */
name|struct
name|phaddr
modifier|*
name|uv_linklocal
decl_stmt|;
comment|/* link-local address of this vif      */
if|#
directive|if
literal|0
block|u_int32	     uv_rmt_addr;
comment|/* remote end-point addr (tunnels only) */
endif|#
directive|endif
name|struct
name|sockaddr_in6
name|uv_dst_addr
decl_stmt|;
comment|/* destination for PIM messages         */
name|struct
name|sockaddr_in6
name|uv_prefix
decl_stmt|;
comment|/* prefix                (phyints only) */
name|struct
name|in6_addr
name|uv_subnetmask
decl_stmt|;
comment|/* subnet mask           (phyints only) */
name|char
name|uv_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name                   */
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
name|listaddr
modifier|*
name|uv_dvmrp_neighbors
decl_stmt|;
comment|/* list of neighboring routers     */
name|nbrbitmap_t
name|uv_nbrmap
decl_stmt|;
comment|/* bitmap of active neighboring routers */
name|struct
name|listaddr
modifier|*
name|uv_querier
decl_stmt|;
comment|/* MLD querier on vif                   */
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
name|uv_leaf_timer
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
name|uv_filter
decl_stmt|;
comment|/* Route filters on this vif	    */
name|u_int16
name|uv_pim_hello_timer
decl_stmt|;
comment|/* timer for sending PIM hello msgs  */
name|u_int16
name|uv_gq_timer
decl_stmt|;
comment|/* Group Query timer        	    */
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
comment|/* list of PIM neighbor routers */
block|}
struct|;
end_struct

begin_comment
comment|/* TODO: define VIFF_KERNEL_FLAGS */
end_comment

begin_define
define|#
directive|define
name|VIFF_KERNEL_FLAGS
value|(VIFF_TUNNEL | VIFF_SRCRT)
end_define

begin_define
define|#
directive|define
name|VIFF_DOWN
value|0x000100
end_define

begin_comment
comment|/* kernel state of interface */
end_comment

begin_define
define|#
directive|define
name|VIFF_DISABLED
value|0x000200
end_define

begin_comment
comment|/* administratively disabled */
end_comment

begin_define
define|#
directive|define
name|VIFF_QUERIER
value|0x000400
end_define

begin_comment
comment|/* I am the subnet's querier */
end_comment

begin_define
define|#
directive|define
name|VIFF_ONEWAY
value|0x000800
end_define

begin_comment
comment|/* Maybe one way interface   */
end_comment

begin_define
define|#
directive|define
name|VIFF_LEAF
value|0x001000
end_define

begin_comment
comment|/* all neighbors are leaves  */
end_comment

begin_define
define|#
directive|define
name|VIFF_IGMPV1
value|0x002000
end_define

begin_comment
comment|/* Act as an IGMPv1 Router   */
end_comment

begin_define
define|#
directive|define
name|VIFF_REXMIT_PRUNES
value|0x004000
end_define

begin_comment
comment|/* retransmit prunes         */
end_comment

begin_define
define|#
directive|define
name|VIFF_PASSIVE
value|0x008000
end_define

begin_comment
comment|/* passive tunnel	    */
end_comment

begin_define
define|#
directive|define
name|VIFF_ALLOW_NONPRUNERS
value|0x010000
end_define

begin_comment
comment|/* ok to peer with nonprunrs */
end_comment

begin_define
define|#
directive|define
name|VIFF_NOFLOOD
value|0x020000
end_define

begin_comment
comment|/* don't flood on this vif   */
end_comment

begin_define
define|#
directive|define
name|VIFF_DR
value|0x040000
end_define

begin_comment
comment|/* designated router	    */
end_comment

begin_comment
comment|/* TODO: VIFF_NONBRS == VIFF_ONEWAY? */
end_comment

begin_define
define|#
directive|define
name|VIFF_NONBRS
value|0x080000
end_define

begin_comment
comment|/* no neighbor on vif	    */
end_comment

begin_define
define|#
directive|define
name|VIFF_POINT_TO_POINT
value|0x100000
end_define

begin_comment
comment|/* point-to-point link       */
end_comment

begin_define
define|#
directive|define
name|VIFF_PIM_NBR
value|0x200000
end_define

begin_comment
comment|/* PIM neighbor              */
end_comment

begin_define
define|#
directive|define
name|VIFF_DVMRP_NBR
value|0x400000
end_define

begin_comment
comment|/* DVMRP neighbor            */
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
comment|/* extra address */
name|struct
name|sockaddr_in6
name|pa_prefix
decl_stmt|;
comment|/* prefix of the extra address */
name|struct
name|in6_addr
name|pa_subnetmask
decl_stmt|;
comment|/* netmask */
block|}
struct|;
end_struct

begin_comment
comment|/* The Access Control List (list with scoped addresses) member */
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
comment|/* next acl member         */
name|u_int32
name|acl_addr
decl_stmt|;
comment|/* Group address           */
name|u_int32
name|acl_mask
decl_stmt|;
comment|/* Group addr. mask        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vif_filter
block|{
name|int
name|vf_type
decl_stmt|;
define|#
directive|define
name|VFT_ACCEPT
value|1
define|#
directive|define
name|VFT_DENY
value|2
name|int
name|vf_flags
decl_stmt|;
define|#
directive|define
name|VFF_BIDIR
value|1
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
name|VFEF_EXACT
value|0x0001
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
comment|/* entry creation time		    */
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
comment|/* router protocol version	    */
name|u_char
name|al_mv
decl_stmt|;
comment|/* router mrouted version	    */
name|u_char
name|al_old
decl_stmt|;
comment|/* time since heard old report: unnecessary for mld */
name|u_char
name|al_index
decl_stmt|;
comment|/* neighbor index		    */
name|u_long
name|al_timerid
decl_stmt|;
comment|/* timer for group membership	    */
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

begin_define
define|#
directive|define
name|NBRF_LEAF
value|0x0001
end_define

begin_comment
comment|/* This neighbor is a leaf 	    */
end_comment

begin_define
define|#
directive|define
name|NBRF_GENID
value|0x0100
end_define

begin_comment
comment|/* I know this neighbor's genid	    */
end_comment

begin_define
define|#
directive|define
name|NBRF_WAITING
value|0x0200
end_define

begin_comment
comment|/* Waiting for peering to come up   */
end_comment

begin_define
define|#
directive|define
name|NBRF_ONEWAY
value|0x0400
end_define

begin_comment
comment|/* One-way peering 		    */
end_comment

begin_define
define|#
directive|define
name|NBRF_TOOOLD
value|0x0800
end_define

begin_comment
comment|/* Too old (policy decision) 	    */
end_comment

begin_define
define|#
directive|define
name|NBRF_TOOMANYROUTES
value|0x1000
end_define

begin_comment
comment|/* Neighbor is spouting routes 	    */
end_comment

begin_define
define|#
directive|define
name|NBRF_NOTPRUNING
value|0x2000
end_define

begin_comment
comment|/* Neighbor doesn't appear to prune */
end_comment

begin_comment
comment|/*  * Don't peer with neighbors with any of these flags set  */
end_comment

begin_define
define|#
directive|define
name|NBRF_DONTPEER
value|(NBRF_WAITING|NBRF_ONEWAY|NBRF_TOOOLD| \ 				 NBRF_TOOMANYROUTES|NBRF_NOTPRUNING)
end_define

begin_define
define|#
directive|define
name|NO_VIF
value|((vifi_t)MAXMIFS)
end_define

begin_comment
comment|/* An invalid vif index */
end_comment

begin_comment
comment|/*  * Used to get the RPF neighbor and IIF info  * for a given source from the unicast routing table.   */
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

end_unit

