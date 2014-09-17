begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_var.h	8.2 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/fnv_hash.h>
end_include

begin_include
include|#
directive|include
file|<sys/tree.h>
end_include

begin_struct_decl
struct_decl|struct
name|igmp_ifinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|in_multi
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lltable
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * IPv4 per-interface state.  */
end_comment

begin_struct
struct|struct
name|in_ifinfo
block|{
name|struct
name|lltable
modifier|*
name|ii_llt
decl_stmt|;
comment|/* ARP state */
name|struct
name|igmp_ifinfo
modifier|*
name|ii_igmp
decl_stmt|;
comment|/* IGMP state */
name|struct
name|in_multi
modifier|*
name|ii_allhosts
decl_stmt|;
comment|/* 224.0.0.1 membership */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_WANT_IFADDR
argument_list|)
end_if

begin_comment
comment|/*  * Interface address, Internet version.  One of these structures  * is allocated for each Internet address on an interface.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|in_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
define|#
directive|define
name|ia_flags
value|ia_ifa.ifa_flags
comment|/* ia_subnet{,mask} in host order */
name|u_long
name|ia_subnet
decl_stmt|;
comment|/* subnet address */
name|u_long
name|ia_subnetmask
decl_stmt|;
comment|/* mask of subnet */
name|LIST_ENTRY
argument_list|(
argument|in_ifaddr
argument_list|)
name|ia_hash
expr_stmt|;
comment|/* entry in bucket of inet addresses */
name|TAILQ_ENTRY
argument_list|(
argument|in_ifaddr
argument_list|)
name|ia_link
expr_stmt|;
comment|/* list of internet addresses */
name|struct
name|sockaddr_in
name|ia_addr
decl_stmt|;
comment|/* reserve space for interface name */
name|struct
name|sockaddr_in
name|ia_dstaddr
decl_stmt|;
comment|/* reserve space for broadcast addr */
define|#
directive|define
name|ia_broadaddr
value|ia_dstaddr
name|struct
name|sockaddr_in
name|ia_sockmask
decl_stmt|;
comment|/* reserve space for general netmask */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|in_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_in
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|ifra_broadaddr
decl_stmt|;
define|#
directive|define
name|ifra_dstaddr
value|ifra_broadaddr
name|struct
name|sockaddr_in
name|ifra_mask
decl_stmt|;
name|int
name|ifra_vhid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a pointer to an in_ifaddr (ifaddr),  * return a pointer to the addr as a sockaddr_in.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIN
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct in_ifaddr *)(ia))->ia_addr))
end_define

begin_define
define|#
directive|define
name|IA_DSTSIN
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct in_ifaddr *)(ia))->ia_dstaddr))
end_define

begin_define
define|#
directive|define
name|IA_MASKSIN
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct in_ifaddr *)(ia))->ia_sockmask))
end_define

begin_define
define|#
directive|define
name|IN_LNAOF
parameter_list|(
name|in
parameter_list|,
name|ifa
parameter_list|)
define|\
value|((ntohl((in).s_addr)& ~((struct in_ifaddr *)(ifa)->ia_subnetmask))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_char
name|inetctlerrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LLTABLE
parameter_list|(
name|ifp
parameter_list|)
define|\
value|((struct in_ifinfo *)(ifp)->if_afdata[AF_INET])->ii_llt
end_define

begin_comment
comment|/*  * Hash table for IP addresses.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|in_ifaddrhead
argument_list|,
name|in_ifaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|in_ifaddrhashhead
argument_list|,
name|in_ifaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|in_ifaddrhashhead
operator|*
argument_list|,
name|in_ifaddrhashtbl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|in_ifaddrhead
argument_list|,
name|in_ifaddrhead
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_long
argument_list|,
name|in_ifaddrhmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mask for hash table */
end_comment

begin_define
define|#
directive|define
name|V_in_ifaddrhashtbl
value|VNET(in_ifaddrhashtbl)
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhead
value|VNET(in_ifaddrhead)
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhmask
value|VNET(in_ifaddrhmask)
end_define

begin_define
define|#
directive|define
name|INADDR_NHASH_LOG2
value|9
end_define

begin_define
define|#
directive|define
name|INADDR_NHASH
value|(1<< INADDR_NHASH_LOG2)
end_define

begin_define
define|#
directive|define
name|INADDR_HASHVAL
parameter_list|(
name|x
parameter_list|)
value|fnv_32_buf((&(x)), sizeof(x), FNV1_32_INIT)
end_define

begin_define
define|#
directive|define
name|INADDR_HASH
parameter_list|(
name|x
parameter_list|)
define|\
value|(&V_in_ifaddrhashtbl[INADDR_HASHVAL(x)& V_in_ifaddrhmask])
end_define

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|in_ifaddr_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IN_IFADDR_LOCK_ASSERT
parameter_list|()
value|rw_assert(&in_ifaddr_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|IN_IFADDR_RLOCK
parameter_list|()
value|rw_rlock(&in_ifaddr_lock)
end_define

begin_define
define|#
directive|define
name|IN_IFADDR_RLOCK_ASSERT
parameter_list|()
value|rw_assert(&in_ifaddr_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|IN_IFADDR_RUNLOCK
parameter_list|()
value|rw_runlock(&in_ifaddr_lock)
end_define

begin_define
define|#
directive|define
name|IN_IFADDR_WLOCK
parameter_list|()
value|rw_wlock(&in_ifaddr_lock)
end_define

begin_define
define|#
directive|define
name|IN_IFADDR_WLOCK_ASSERT
parameter_list|()
value|rw_assert(&in_ifaddr_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|IN_IFADDR_WUNLOCK
parameter_list|()
value|rw_wunlock(&in_ifaddr_lock)
end_define

begin_comment
comment|/*  * Macro for finding the internet address structure (in_ifaddr)  * corresponding to one of our IP addresses (in_addr).  */
end_comment

begin_define
define|#
directive|define
name|INADDR_TO_IFADDR
parameter_list|(
name|addr
parameter_list|,
name|ia
parameter_list|)
define|\
comment|/* struct in_addr addr; */
define|\
comment|/* struct in_ifaddr *ia; */
define|\
value|do { \ \ 	LIST_FOREACH(ia, INADDR_HASH((addr).s_addr), ia_hash) \ 		if (IA_SIN(ia)->sin_addr.s_addr == (addr).s_addr) \ 			break; \ } while (0)
end_define

begin_comment
comment|/*  * Macro for finding the interface (ifnet structure) corresponding to one  * of our IP addresses.  */
end_comment

begin_define
define|#
directive|define
name|INADDR_TO_IFP
parameter_list|(
name|addr
parameter_list|,
name|ifp
parameter_list|)
define|\
comment|/* struct in_addr addr; */
define|\
comment|/* struct ifnet *ifp; */
define|\
value|{ \ 	struct in_ifaddr *ia; \ \ 	INADDR_TO_IFADDR(addr, ia); \ 	(ifp) = (ia == NULL) ? NULL : ia->ia_ifp; \ }
end_define

begin_comment
comment|/*  * Macro for finding the internet address structure (in_ifaddr) corresponding  * to a given interface (ifnet structure).  */
end_comment

begin_define
define|#
directive|define
name|IFP_TO_IA
parameter_list|(
name|ifp
parameter_list|,
name|ia
parameter_list|)
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in_ifaddr *ia; */
define|\
value|do {									\ 	IN_IFADDR_RLOCK();						\ 	for ((ia) = TAILQ_FIRST(&V_in_ifaddrhead);			\ 	    (ia) != NULL&& (ia)->ia_ifp != (ifp);			\ 	    (ia) = TAILQ_NEXT((ia), ia_link))				\ 		continue;						\ 	if ((ia) != NULL)						\ 		ifa_ref(&(ia)->ia_ifa);					\ 	IN_IFADDR_RUNLOCK();						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * IP datagram reassembly.  */
end_comment

begin_define
define|#
directive|define
name|IPREASS_NHASH_LOG2
value|6
end_define

begin_define
define|#
directive|define
name|IPREASS_NHASH
value|(1<< IPREASS_NHASH_LOG2)
end_define

begin_define
define|#
directive|define
name|IPREASS_HMASK
value|(IPREASS_NHASH - 1)
end_define

begin_define
define|#
directive|define
name|IPREASS_HASH
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((((x)& 0xF) | ((((x)>> 8)& 0xF)<< 4)) ^ (y))& IPREASS_HMASK)
end_define

begin_comment
comment|/*  * Legacy IPv4 IGMP per-link structure.  */
end_comment

begin_struct
struct|struct
name|router_info
block|{
name|struct
name|ifnet
modifier|*
name|rti_ifp
decl_stmt|;
name|int
name|rti_type
decl_stmt|;
comment|/* type of router which is querier on this interface */
name|int
name|rti_time
decl_stmt|;
comment|/* # of slow timeouts since last old query */
name|SLIST_ENTRY
argument_list|(
argument|router_info
argument_list|)
name|rti_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-interface IGMP router version information.  */
end_comment

begin_struct
struct|struct
name|igmp_ifinfo
block|{
name|LIST_ENTRY
argument_list|(
argument|igmp_ifinfo
argument_list|)
name|igi_link
expr_stmt|;
name|struct
name|ifnet
modifier|*
name|igi_ifp
decl_stmt|;
comment|/* interface this instance belongs to */
name|uint32_t
name|igi_version
decl_stmt|;
comment|/* IGMPv3 Host Compatibility Mode */
name|uint32_t
name|igi_v1_timer
decl_stmt|;
comment|/* IGMPv1 Querier Present timer (s) */
name|uint32_t
name|igi_v2_timer
decl_stmt|;
comment|/* IGMPv2 Querier Present timer (s) */
name|uint32_t
name|igi_v3_timer
decl_stmt|;
comment|/* IGMPv3 General Query (interface) timer (s)*/
name|uint32_t
name|igi_flags
decl_stmt|;
comment|/* IGMP per-interface flags */
name|uint32_t
name|igi_rv
decl_stmt|;
comment|/* IGMPv3 Robustness Variable */
name|uint32_t
name|igi_qi
decl_stmt|;
comment|/* IGMPv3 Query Interval (s) */
name|uint32_t
name|igi_qri
decl_stmt|;
comment|/* IGMPv3 Query Response Interval (s) */
name|uint32_t
name|igi_uri
decl_stmt|;
comment|/* IGMPv3 Unsolicited Report Interval (s) */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|in_multi
argument_list|)
name|igi_relinmhead
expr_stmt|;
comment|/* released groups */
name|struct
name|ifqueue
name|igi_gq
decl_stmt|;
comment|/* queue of general query responses */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGIF_SILENT
value|0x00000001
end_define

begin_comment
comment|/* Do not use IGMP on this ifp */
end_comment

begin_define
define|#
directive|define
name|IGIF_LOOPBACK
value|0x00000002
end_define

begin_comment
comment|/* Send IGMP reports to loopback */
end_comment

begin_comment
comment|/*  * IPv4 multicast IGMP-layer source entry.  */
end_comment

begin_struct
struct|struct
name|ip_msource
block|{
name|RB_ENTRY
argument_list|(
argument|ip_msource
argument_list|)
name|ims_link
expr_stmt|;
comment|/* RB tree links */
name|in_addr_t
name|ims_haddr
decl_stmt|;
comment|/* host byte order */
struct|struct
name|ims_st
block|{
name|uint16_t
name|ex
decl_stmt|;
comment|/* # of exclusive members */
name|uint16_t
name|in
decl_stmt|;
comment|/* # of inclusive members */
block|}
name|ims_st
index|[
literal|2
index|]
struct|;
comment|/* state at t0, t1 */
name|uint8_t
name|ims_stp
decl_stmt|;
comment|/* pending query */
block|}
struct|;
end_struct

begin_comment
comment|/*  * IPv4 multicast PCB-layer source entry.  */
end_comment

begin_struct
struct|struct
name|in_msource
block|{
name|RB_ENTRY
argument_list|(
argument|ip_msource
argument_list|)
name|ims_link
expr_stmt|;
comment|/* RB tree links */
name|in_addr_t
name|ims_haddr
decl_stmt|;
comment|/* host byte order */
name|uint8_t
name|imsl_st
index|[
literal|2
index|]
decl_stmt|;
comment|/* state before/at commit */
block|}
struct|;
end_struct

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|ip_msource_tree
argument_list|,
name|ip_msource
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* define struct ip_msource_tree */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ip_msource_cmp
parameter_list|(
specifier|const
name|struct
name|ip_msource
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|ip_msource
modifier|*
name|b
parameter_list|)
block|{
if|if
condition|(
name|a
operator|->
name|ims_haddr
operator|<
name|b
operator|->
name|ims_haddr
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ims_haddr
operator|==
name|b
operator|->
name|ims_haddr
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|ip_msource_tree
argument_list|,
name|ip_msource
argument_list|,
name|ims_link
argument_list|,
name|ip_msource_cmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * IPv4 multicast PCB-layer group filter descriptor.  */
end_comment

begin_struct
struct|struct
name|in_mfilter
block|{
name|struct
name|ip_msource_tree
name|imf_sources
decl_stmt|;
comment|/* source list for (S,G) */
name|u_long
name|imf_nsrc
decl_stmt|;
comment|/* # of source entries */
name|uint8_t
name|imf_st
index|[
literal|2
index|]
decl_stmt|;
comment|/* state before/at commit */
block|}
struct|;
end_struct

begin_comment
comment|/*  * IPv4 group descriptor.  *  * For every entry on an ifnet's if_multiaddrs list which represents  * an IP multicast group, there is one of these structures.  *  * If any source filters are present, then a node will exist in the RB-tree  * to permit fast lookup by source whenever an operation takes place.  * This permits pre-order traversal when we issue reports.  * Source filter trees are kept separately from the socket layer to  * greatly simplify locking.  *  * When IGMPv3 is active, inm_timer is the response to group query timer.  * The state-change timer inm_sctimer is separate; whenever state changes  * for the group the state change record is generated and transmitted,  * and kept if retransmissions are necessary.  *  * FUTURE: inm_link is now only used when groups are being purged  * on a detaching ifnet. It could be demoted to a SLIST_ENTRY, but  * because it is at the very start of the struct, we can't do this  * w/o breaking the ABI for ifmcstat.  */
end_comment

begin_struct
struct|struct
name|in_multi
block|{
name|LIST_ENTRY
argument_list|(
argument|in_multi
argument_list|)
name|inm_link
expr_stmt|;
comment|/* to-be-released by in_ifdetach */
name|struct
name|in_addr
name|inm_addr
decl_stmt|;
comment|/* IP multicast address, convenience */
name|struct
name|ifnet
modifier|*
name|inm_ifp
decl_stmt|;
comment|/* back pointer to ifnet */
name|struct
name|ifmultiaddr
modifier|*
name|inm_ifma
decl_stmt|;
comment|/* back pointer to ifmultiaddr */
name|u_int
name|inm_timer
decl_stmt|;
comment|/* IGMPv1/v2 group / v3 query timer */
name|u_int
name|inm_state
decl_stmt|;
comment|/* state of the membership */
name|void
modifier|*
name|inm_rti
decl_stmt|;
comment|/* unused, legacy field */
name|u_int
name|inm_refcount
decl_stmt|;
comment|/* reference count */
comment|/* New fields for IGMPv3 follow. */
name|struct
name|igmp_ifinfo
modifier|*
name|inm_igi
decl_stmt|;
comment|/* IGMP info */
name|SLIST_ENTRY
argument_list|(
argument|in_multi
argument_list|)
name|inm_nrele
expr_stmt|;
comment|/* to-be-released by IGMP */
name|struct
name|ip_msource_tree
name|inm_srcs
decl_stmt|;
comment|/* tree of sources */
name|u_long
name|inm_nsrc
decl_stmt|;
comment|/* # of tree entries */
name|struct
name|ifqueue
name|inm_scq
decl_stmt|;
comment|/* queue of pending 						 * state-change packets */
name|struct
name|timeval
name|inm_lastgsrtv
decl_stmt|;
comment|/* Time of last G-S-R query */
name|uint16_t
name|inm_sctimer
decl_stmt|;
comment|/* state-change timer */
name|uint16_t
name|inm_scrv
decl_stmt|;
comment|/* state-change rexmit count */
comment|/* 	 * SSM state counters which track state at T0 (the time the last 	 * state-change report's RV timer went to zero) and T1 	 * (time of pending report, i.e. now). 	 * Used for computing IGMPv3 state-change reports. Several refcounts 	 * are maintained here to optimize for common use-cases. 	 */
struct|struct
name|inm_st
block|{
name|uint16_t
name|iss_fmode
decl_stmt|;
comment|/* IGMP filter mode */
name|uint16_t
name|iss_asm
decl_stmt|;
comment|/* # of ASM listeners */
name|uint16_t
name|iss_ex
decl_stmt|;
comment|/* # of exclusive members */
name|uint16_t
name|iss_in
decl_stmt|;
comment|/* # of inclusive members */
name|uint16_t
name|iss_rec
decl_stmt|;
comment|/* # of recorded sources */
block|}
name|inm_st
index|[
literal|2
index|]
struct|;
comment|/* state at t0, t1 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Helper function to derive the filter mode on a source entry  * from its internal counters. Predicates are:  *  A source is only excluded if all listeners exclude it.  *  A source is only included if no listeners exclude it,  *  and at least one listener includes it.  * May be used by ifmcstat(8).  */
end_comment

begin_function
specifier|static
name|__inline
name|uint8_t
name|ims_get_mode
parameter_list|(
specifier|const
name|struct
name|in_multi
modifier|*
name|inm
parameter_list|,
specifier|const
name|struct
name|ip_msource
modifier|*
name|ims
parameter_list|,
name|uint8_t
name|t
parameter_list|)
block|{
name|t
operator|=
operator|!
operator|!
name|t
expr_stmt|;
if|if
condition|(
name|inm
operator|->
name|inm_st
index|[
name|t
index|]
operator|.
name|iss_ex
operator|>
literal|0
operator|&&
name|inm
operator|->
name|inm_st
index|[
name|t
index|]
operator|.
name|iss_ex
operator|==
name|ims
operator|->
name|ims_st
index|[
name|t
index|]
operator|.
name|ex
condition|)
return|return
operator|(
name|MCAST_EXCLUDE
operator|)
return|;
elseif|else
if|if
condition|(
name|ims
operator|->
name|ims_st
index|[
name|t
index|]
operator|.
name|in
operator|>
literal|0
operator|&&
name|ims
operator|->
name|ims_st
index|[
name|t
index|]
operator|.
name|ex
operator|==
literal|0
condition|)
return|return
operator|(
name|MCAST_INCLUDE
operator|)
return|;
return|return
operator|(
name|MCAST_UNDEFINED
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_ip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_raw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Lock macros for IPv4 layer multicast address lists.  IPv4 lock goes  * before link layer multicast locks in the lock order.  In most cases,  * consumers of IN_*_MULTI() macros should acquire the locks before  * calling them; users of the in_{add,del}multi() functions should not.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|in_multi_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IN_MULTI_LOCK
parameter_list|()
value|mtx_lock(&in_multi_mtx)
end_define

begin_define
define|#
directive|define
name|IN_MULTI_UNLOCK
parameter_list|()
value|mtx_unlock(&in_multi_mtx)
end_define

begin_define
define|#
directive|define
name|IN_MULTI_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&in_multi_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IN_MULTI_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&in_multi_mtx, MA_NOTOWNED)
end_define

begin_comment
comment|/* Acquire an in_multi record. */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|inm_acquire_locked
parameter_list|(
name|struct
name|in_multi
modifier|*
name|inm
parameter_list|)
block|{
name|IN_MULTI_LOCK_ASSERT
argument_list|()
expr_stmt|;
operator|++
name|inm
operator|->
name|inm_refcount
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Return values for imo_multi_filter().  */
end_comment

begin_define
define|#
directive|define
name|MCAST_PASS
value|0
end_define

begin_comment
comment|/* Pass */
end_comment

begin_define
define|#
directive|define
name|MCAST_NOTGMEMBER
value|1
end_define

begin_comment
comment|/* This host not a member of group */
end_comment

begin_define
define|#
directive|define
name|MCAST_NOTSMEMBER
value|2
end_define

begin_comment
comment|/* This host excluded source */
end_comment

begin_define
define|#
directive|define
name|MCAST_MUTED
value|3
end_define

begin_comment
comment|/* [deprecated] */
end_comment

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ip_moptions
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|radix_node_head
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|in_multi
modifier|*
name|inm_lookup_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_multi
modifier|*
name|inm_lookup
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|imo_multi_filter
parameter_list|(
specifier|const
name|struct
name|ip_moptions
modifier|*
parameter_list|,
specifier|const
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inm_commit
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inm_clear_recorded
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inm_print
parameter_list|(
specifier|const
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inm_record_source
parameter_list|(
name|struct
name|in_multi
modifier|*
name|inm
parameter_list|,
specifier|const
name|in_addr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inm_release
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inm_release_locked
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_multi
modifier|*
name|in_addmulti
parameter_list|(
name|struct
name|in_addr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_delmulti
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_joingroup
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
parameter_list|,
comment|/*const*/
name|struct
name|in_mfilter
modifier|*
parameter_list|,
name|struct
name|in_multi
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_joingroup_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
parameter_list|,
comment|/*const*/
name|struct
name|in_mfilter
modifier|*
parameter_list|,
name|struct
name|in_multi
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_leavegroup
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|,
comment|/*const*/
name|struct
name|in_mfilter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_leavegroup_locked
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|,
comment|/*const*/
name|struct
name|in_mfilter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_control
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_rtqdrain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_addprefix
parameter_list|(
name|struct
name|in_ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_scrubprefix
parameter_list|(
name|struct
name|in_ifaddr
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_direct_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_ifadown
parameter_list|(
name|struct
name|ifaddr
modifier|*
name|ifa
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ip_fastforward
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|in_domifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_domifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|void
name|in_rtalloc_ign
parameter_list|(
name|struct
name|route
modifier|*
name|ro
parameter_list|,
name|u_long
name|ignflags
parameter_list|,
name|u_int
name|fibnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_rtalloc
parameter_list|(
name|struct
name|route
modifier|*
name|ro
parameter_list|,
name|u_int
name|fibnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rtentry
modifier|*
name|in_rtalloc1
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_rtredirect
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_rtrequest
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_setmatchfunc
parameter_list|(
name|struct
name|radix_node_head
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int	 in_rt_getifa(struct rt_addrinfo *, u_int fibnum); int	 in_rtioctl(u_long, caddr_t, u_int); int	 in_rtrequest1(int, struct rt_addrinfo *, struct rtentry **, u_int);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* INET6 stuff */
end_comment

begin_include
include|#
directive|include
file|<netinet6/in6_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IN_VAR_H_ */
end_comment

end_unit

