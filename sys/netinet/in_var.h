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
comment|/* ia_{,sub}net{,mask} in host order */
name|u_long
name|ia_net
decl_stmt|;
comment|/* network number of interface */
name|u_long
name|ia_netmask
decl_stmt|;
comment|/* mask of net part */
name|u_long
name|ia_subnet
decl_stmt|;
comment|/* subnet number, including net */
name|u_long
name|ia_subnetmask
decl_stmt|;
comment|/* mask of subnet part */
name|struct
name|in_addr
name|ia_netbroadcast
decl_stmt|;
comment|/* to recognize net broadcasts */
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

begin_comment
comment|/*  * Hash table for IP addresses.  */
end_comment

begin_extern
extern|extern	LIST_HEAD(in_ifaddrhashhead
operator|,
extern|in_ifaddr
end_extern

begin_expr_stmt
unit|)
operator|*
name|in_ifaddrhashtbl
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern	TAILQ_HEAD(in_ifaddrhead
operator|,
extern|in_ifaddr
end_extern

begin_expr_stmt
unit|)
name|in_ifaddrhead
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|in_ifaddrhmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for hash table */
end_comment

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
value|{ \ 	for ((ia) = TAILQ_FIRST(&V_in_ifaddrhead); \ 	    (ia) != NULL&& (ia)->ia_ifp != (ifp); \ 	    (ia) = TAILQ_NEXT((ia), ia_link)) \ 		continue; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This information should be part of the ifnet structure but we don't wish  * to change that - as it might break a number of things  */
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
ifdef|#
directive|ifdef
name|notyet
name|int
name|rti_timev1
decl_stmt|;
comment|/* IGMPv1 querier present */
name|int
name|rti_timev2
decl_stmt|;
comment|/* IGMPv2 querier present */
name|int
name|rti_timer
decl_stmt|;
comment|/* report to general query */
name|int
name|rti_qrv
decl_stmt|;
comment|/* querier robustness */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Internet multicast address structure.  There is one of these for each IP  * multicast group to which this host belongs on a given network interface.  * For every entry on the interface's if_multiaddrs list which represents  * an IP multicast group, there is one of these structures.  They are also  * kept on a system-wide list to make it easier to keep our legacy IGMP code  * compatible with the rest of the world (see IN_FIRST_MULTI et al, below).  */
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
comment|/* queue macro glue */
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
comment|/* IGMP membership report timer */
name|u_int
name|inm_state
decl_stmt|;
comment|/*  state of the membership */
name|struct
name|router_info
modifier|*
name|inm_rti
decl_stmt|;
comment|/* router info*/
name|u_int
name|inm_refcount
decl_stmt|;
comment|/* reference count */
ifdef|#
directive|ifdef
name|notyet
comment|/* IGMPv3 source-specific multicast fields */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|in_msfentry
argument_list|)
name|inm_msf
expr_stmt|;
comment|/* all active source filters */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|in_msfentry
argument_list|)
name|inm_msf_record
expr_stmt|;
comment|/* recorded sources */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|in_msfentry
argument_list|)
name|inm_msf_exclude
expr_stmt|;
comment|/* exclude sources */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|in_msfentry
argument_list|)
name|inm_msf_include
expr_stmt|;
comment|/* include sources */
comment|/* XXX: should this lot go to the router_info structure? */
comment|/* XXX: can/should these be callouts? */
comment|/* IGMP protocol timers */
name|int32_t
name|inm_ti_curstate
decl_stmt|;
comment|/* current state timer */
name|int32_t
name|inm_ti_statechg
decl_stmt|;
comment|/* state change timer */
comment|/* IGMP report timers */
name|uint16_t
name|inm_rpt_statechg
decl_stmt|;
comment|/* state change report timer */
name|uint16_t
name|inm_rpt_toxx
decl_stmt|;
comment|/* fmode change report timer */
comment|/* IGMP protocol state */
name|uint16_t
name|inm_fmode
decl_stmt|;
comment|/* filter mode */
name|uint32_t
name|inm_recsrc_count
decl_stmt|;
comment|/* # of recorded sources */
name|uint16_t
name|inm_exclude_sock_count
decl_stmt|;
comment|/* # of exclude-mode sockets */
name|uint16_t
name|inm_gass_count
decl_stmt|;
comment|/* # of g-a-s queries */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/*  * Internet multicast source filter list. This list is used to store  * IP multicast source addresses for each membership on an interface.  * TODO: Allocate these structures using UMA.  * TODO: Find an easier way of linking the struct into two lists at once.  */
end_comment

begin_struct
struct|struct
name|in_msfentry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|in_msfentry
argument_list|)
name|isf_link
expr_stmt|;
comment|/* next filter in all-list */
name|TAILQ_ENTRY
argument_list|(
argument|in_msfentry
argument_list|)
name|isf_next
expr_stmt|;
comment|/* next filter in queue */
name|struct
name|in_addr
name|isf_addr
decl_stmt|;
comment|/* the address of this source */
name|uint16_t
name|isf_refcount
decl_stmt|;
comment|/* reference count */
name|uint16_t
name|isf_reporttag
decl_stmt|;
comment|/* what to report to the IGMP router */
name|uint16_t
name|isf_rexmit
decl_stmt|;
comment|/* retransmission state/count */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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

begin_extern
extern|extern LIST_HEAD(in_multihead
operator|,
extern|in_multi
end_extern

begin_expr_stmt
unit|)
name|in_multihead
expr_stmt|;
end_expr_stmt

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

begin_comment
comment|/*  * Structure used by macros below to remember position when stepping through  * all of the in_multi records.  */
end_comment

begin_struct
struct|struct
name|in_multistep
block|{
name|struct
name|in_multi
modifier|*
name|i_inm
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro for looking up the in_multi record for a given IP multicast address  * on a given interface.  If no matching record is found, "inm" is set null.  */
end_comment

begin_define
define|#
directive|define
name|IN_LOOKUP_MULTI
parameter_list|(
name|addr
parameter_list|,
name|ifp
parameter_list|,
name|inm
parameter_list|)
define|\
comment|/* struct in_addr addr; */
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|do { \ 	struct ifmultiaddr *ifma; \ \ 	IN_MULTI_LOCK_ASSERT(); \ 	IF_ADDR_LOCK(ifp); \ 	TAILQ_FOREACH(ifma,&((ifp)->if_multiaddrs), ifma_link) { \ 		if (ifma->ifma_addr->sa_family == AF_INET \&& ((struct sockaddr_in *)ifma->ifma_addr)->sin_addr.s_addr == \ 		    (addr).s_addr) \ 			break; \ 	} \ 	(inm) = ifma ? ifma->ifma_protospec : 0; \ 	IF_ADDR_UNLOCK(ifp); \ } while(0)
end_define

begin_comment
comment|/*  * Macro to step through all of the in_multi records, one at a time.  * The current position is remembered in "step", which the caller must  * provide.  IN_FIRST_MULTI(), below, must be called to initialize "step"  * and get the first record.  Both macros return a NULL "inm" when there  * are no remaining records.  */
end_comment

begin_define
define|#
directive|define
name|IN_NEXT_MULTI
parameter_list|(
name|step
parameter_list|,
name|inm
parameter_list|)
define|\
comment|/* struct in_multistep  step; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|do { \ 	IN_MULTI_LOCK_ASSERT(); \ 	if (((inm) = (step).i_inm) != NULL) \ 		(step).i_inm = LIST_NEXT((step).i_inm, inm_link); \ } while(0)
end_define

begin_define
define|#
directive|define
name|IN_FIRST_MULTI
parameter_list|(
name|step
parameter_list|,
name|inm
parameter_list|)
define|\
comment|/* struct in_multistep step; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|do { \ 	IN_MULTI_LOCK_ASSERT(); \ 	(step).i_inm = LIST_FIRST(&V_in_multihead); \ 	IN_NEXT_MULTI((step), (inm)); \ } while(0)
end_define

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

begin_function_decl
name|size_t
name|imo_match_group
parameter_list|(
name|struct
name|ip_moptions
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_msource
modifier|*
name|imo_match_source
parameter_list|(
name|struct
name|ip_moptions
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|sockaddr
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
name|void
name|in_delmulti_locked
parameter_list|(
name|struct
name|in_multi
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
name|int
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
name|void
name|in_ifscrub
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|in_ifaddr
modifier|*
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
name|int
name|in_rt_check
parameter_list|(
name|struct
name|rtentry
modifier|*
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|u_int
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

