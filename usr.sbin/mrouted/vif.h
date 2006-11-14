begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  * vif.h,v 3.8.4.26 1998/01/14 21:21:19 fenner Exp  */
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
name|u_long
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

begin_ifndef
ifndef|#
directive|ifndef
name|VIFM_SETALL
end_ifndef

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
name|NO_NBR
value|MAXNBRS
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
value|(((n)< NBRBITS) ? ((m).lo |= (1<< (n))) : \ 				      ((m).hi |= (1<< (n - NBRBITS))))
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
value|(((n)< NBRBITS) ? ((m).lo& (1<< (n))) : \ 				      ((m).hi& (1<< ((n) - NBRBITS))))
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

begin_struct
struct|struct
name|blastinfo
block|{
name|char
modifier|*
name|bi_buf
decl_stmt|;
comment|/* Pointer to malloced storage	    */
name|char
modifier|*
name|bi_cur
decl_stmt|;
comment|/* The update to process next	    */
name|char
modifier|*
name|bi_end
decl_stmt|;
comment|/* The place to put the next update	    */
name|int
name|bi_len
decl_stmt|;
comment|/* Size of malloced storage		    */
name|int
name|bi_timer
decl_stmt|;
comment|/* Timer to run process_blaster_report  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * User level Virtual Interface structure  *  * A "virtual interface" is either a physical, multicast-capable interface  * (called a "phyint") or a virtual point-to-point link (called a "tunnel").  * (Note: all addresses, subnet numbers and masks are kept in NETWORK order.)  */
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
name|u_char
name|uv_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif   */
name|u_int
name|uv_rate_limit
decl_stmt|;
comment|/* rate limit on this vif               */
name|u_int32
name|uv_lcl_addr
decl_stmt|;
comment|/* local address of this vif            */
name|u_int32
name|uv_rmt_addr
decl_stmt|;
comment|/* remote end-point addr (tunnels only) */
name|u_int32
name|uv_dst_addr
decl_stmt|;
comment|/* destination for DVMRP messages       */
name|u_int32
name|uv_subnet
decl_stmt|;
comment|/* subnet number         (phyints only) */
name|u_int32
name|uv_subnetmask
decl_stmt|;
comment|/* subnet mask           (phyints only) */
name|u_int32
name|uv_subnetbcast
decl_stmt|;
comment|/* subnet broadcast addr (phyints only) */
name|char
name|uv_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name                   */
name|struct
name|listaddr
modifier|*
name|uv_groups
decl_stmt|;
comment|/* list of local groups  (phyints only) */
name|struct
name|listaddr
modifier|*
name|uv_neighbors
decl_stmt|;
comment|/* list of neighboring routers          */
name|nbrbitmap_t
name|uv_nbrmap
decl_stmt|;
comment|/* bitmap of active neighboring routers */
name|struct
name|listaddr
modifier|*
name|uv_querier
decl_stmt|;
comment|/* IGMP querier on vif                  */
name|int
name|uv_igmpv1_warn
decl_stmt|;
comment|/* To rate-limit IGMPv1 warnings	    */
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
comment|/* Additional subnets on this vif       */
name|struct
name|vif_filter
modifier|*
name|uv_filter
decl_stmt|;
comment|/* Route filters on this vif	    */
name|struct
name|blastinfo
name|uv_blaster
decl_stmt|;
comment|/* Info about route blasters	    */
name|int
name|uv_nbrup
decl_stmt|;
comment|/* Counter for neighbor up events       */
name|int
name|uv_icmp_warn
decl_stmt|;
comment|/* To rate-limit ICMP warnings	    */
name|u_int
name|uv_nroutes
decl_stmt|;
comment|/* # of routes with this vif as parent  */
name|struct
name|ip
modifier|*
name|uv_encap_hdr
decl_stmt|;
comment|/* Pre-formed header to encapsulate msgs*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|uv_blasterbuf
value|uv_blaster.bi_buf
end_define

begin_define
define|#
directive|define
name|uv_blastercur
value|uv_blaster.bi_cur
end_define

begin_define
define|#
directive|define
name|uv_blasterend
value|uv_blaster.bi_end
end_define

begin_define
define|#
directive|define
name|uv_blasterlen
value|uv_blaster.bi_len
end_define

begin_define
define|#
directive|define
name|uv_blastertimer
value|uv_blaster.bi_timer
end_define

begin_define
define|#
directive|define
name|VIFF_KERNEL_FLAGS
value|(VIFF_TUNNEL|VIFF_SRCRT)
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
comment|/* passive tunnel	     */
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
name|VIFF_NOTRANSIT
value|0x040000
end_define

begin_comment
comment|/* don't transit these vifs  */
end_comment

begin_define
define|#
directive|define
name|VIFF_BLASTER
value|0x080000
end_define

begin_comment
comment|/* nbr on vif blasts routes  */
end_comment

begin_define
define|#
directive|define
name|VIFF_FORCE_LEAF
value|0x100000
end_define

begin_comment
comment|/* ignore nbrs on this vif   */
end_comment

begin_define
define|#
directive|define
name|VIFF_OTUNNEL
value|0x200000
end_define

begin_comment
comment|/* DVMRP msgs "beside" tunnel*/
end_comment

begin_define
define|#
directive|define
name|AVOID_TRANSIT
parameter_list|(
name|v
parameter_list|,
name|r
parameter_list|)
define|\
value|(((r)->rt_parent != NO_VIF)&& \ 		 ((r)->rt_gateway != 0)&& \ 		 (uvifs[(v)].uv_flags& VIFF_NOTRANSIT)&& \ 		 (uvifs[(r)->rt_parent].uv_flags& VIFF_NOTRANSIT))
end_define

begin_struct
struct|struct
name|phaddr
block|{
name|struct
name|phaddr
modifier|*
name|pa_next
decl_stmt|;
name|u_int32
name|pa_subnet
decl_stmt|;
comment|/* extra subnet			*/
name|u_int32
name|pa_subnetmask
decl_stmt|;
comment|/* netmask of extra subnet	*/
name|u_int32
name|pa_subnetbcast
decl_stmt|;
comment|/* broadcast of extra subnet	*/
block|}
struct|;
end_struct

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
name|u_int32
name|vfe_addr
decl_stmt|;
name|u_int32
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
name|u_int32
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
struct|struct
block|{
name|u_int32
name|alur_genid
decl_stmt|;
comment|/* generation id for neighbor       */
name|u_int
name|alur_nroutes
decl_stmt|;
comment|/* # of routes w/ nbr as parent	    */
name|u_char
name|alur_pv
decl_stmt|;
comment|/* router protocol version	    */
name|u_char
name|alur_mv
decl_stmt|;
comment|/* router mrouted version	    */
name|u_char
name|alur_index
decl_stmt|;
comment|/* neighbor index		    */
block|}
name|alu_router
struct|;
struct|struct
block|{
name|u_int32
name|alug_reporter
decl_stmt|;
comment|/* a host which reported membership */
name|u_long
name|alug_timerid
decl_stmt|;
comment|/* timer for group membership	    */
name|u_long
name|alug_query
decl_stmt|;
comment|/* timer for repeated leave query   */
name|u_char
name|alug_old
decl_stmt|;
comment|/* time since heard old report      */
block|}
name|alu_group
struct|;
block|}
name|al_alu
union|;
name|u_short
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
value|al_alu.alu_router.alur_genid
end_define

begin_define
define|#
directive|define
name|al_nroutes
value|al_alu.alu_router.alur_nroutes
end_define

begin_define
define|#
directive|define
name|al_pv
value|al_alu.alu_router.alur_pv
end_define

begin_define
define|#
directive|define
name|al_mv
value|al_alu.alu_router.alur_mv
end_define

begin_define
define|#
directive|define
name|al_index
value|al_alu.alu_router.alur_index
end_define

begin_define
define|#
directive|define
name|al_reporter
value|al_alu.alu_group.alug_reporter
end_define

begin_define
define|#
directive|define
name|al_old
value|al_alu.alu_group.alug_old
end_define

begin_define
define|#
directive|define
name|al_timerid
value|al_alu.alu_group.alug_timerid
end_define

begin_define
define|#
directive|define
name|al_query
value|al_alu.alu_group.alug_query
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
value|((vifi_t)MAXVIFS)
end_define

begin_comment
comment|/* An invalid vif index */
end_comment

end_unit

