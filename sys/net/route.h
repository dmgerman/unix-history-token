begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)route.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_ROUTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_ROUTE_H_
end_define

begin_include
include|#
directive|include
file|<sys/counter.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_comment
comment|/*  * Kernel resident routing tables.  *  * The routing tables are initialized when interface addresses  * are set by making entries for all directly connected interfaces.  */
end_comment

begin_comment
comment|/*  * A route consists of a destination address, a reference  * to a routing entry, and a reference to an llentry.    * These are often held by protocols in their control  * blocks, e.g. inpcb.  */
end_comment

begin_struct
struct|struct
name|route
block|{
name|struct
name|rtentry
modifier|*
name|ro_rt
decl_stmt|;
name|struct
name|llentry
modifier|*
name|ro_lle
decl_stmt|;
name|struct
name|in_ifaddr
modifier|*
name|ro_ia
decl_stmt|;
name|int
name|ro_flags
decl_stmt|;
name|struct
name|sockaddr
name|ro_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RT_CACHING_CONTEXT
value|0x1
end_define

begin_comment
comment|/* XXX: not used anywhere */
end_comment

begin_define
define|#
directive|define
name|RT_NORTREF
value|0x2
end_define

begin_comment
comment|/* doesn't hold reference on ro_rt */
end_comment

begin_struct
struct|struct
name|rt_metrics
block|{
name|u_long
name|rmx_locks
decl_stmt|;
comment|/* Kernel must leave these values alone */
name|u_long
name|rmx_mtu
decl_stmt|;
comment|/* MTU for this path */
name|u_long
name|rmx_hopcount
decl_stmt|;
comment|/* max hops expected */
name|u_long
name|rmx_expire
decl_stmt|;
comment|/* lifetime for route, e.g. redirect */
name|u_long
name|rmx_recvpipe
decl_stmt|;
comment|/* inbound delay-bandwidth product */
name|u_long
name|rmx_sendpipe
decl_stmt|;
comment|/* outbound delay-bandwidth product */
name|u_long
name|rmx_ssthresh
decl_stmt|;
comment|/* outbound gateway buffer limit */
name|u_long
name|rmx_rtt
decl_stmt|;
comment|/* estimated round trip time */
name|u_long
name|rmx_rttvar
decl_stmt|;
comment|/* estimated rtt variance */
name|u_long
name|rmx_pksent
decl_stmt|;
comment|/* packets sent using this route */
name|u_long
name|rmx_weight
decl_stmt|;
comment|/* route weight */
name|u_long
name|rmx_filler
index|[
literal|3
index|]
decl_stmt|;
comment|/* will be used for T/TCP later */
block|}
struct|;
end_struct

begin_comment
comment|/*  * rmx_rtt and rmx_rttvar are stored as microseconds;  * RTTTOPRHZ(rtt) converts to a value suitable for use  * by a protocol slowtimo counter.  */
end_comment

begin_define
define|#
directive|define
name|RTM_RTTUNIT
value|1000000
end_define

begin_comment
comment|/* units for rtt, rttvar, as units per sec */
end_comment

begin_define
define|#
directive|define
name|RTTTOPRHZ
parameter_list|(
name|r
parameter_list|)
value|((r) / (RTM_RTTUNIT / PR_SLOWHZ))
end_define

begin_define
define|#
directive|define
name|RT_DEFAULT_FIB
value|0
end_define

begin_comment
comment|/* Explicitly mark fib=0 restricted cases */
end_comment

begin_define
define|#
directive|define
name|RT_ALL_FIBS
value|-1
end_define

begin_comment
comment|/* Announce event for every fib */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|rt_numfibs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of usable routing tables */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_int
argument_list|,
name|rt_add_addr_allfibs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Announce interfaces to all fibs */
end_comment

begin_define
define|#
directive|define
name|V_rt_add_addr_allfibs
value|VNET(rt_add_addr_allfibs)
end_define

begin_comment
comment|/*  * We distinguish between routes to hosts and routes to networks,  * preferring the former if available.  For each route we infer  * the interface to use from the gateway address supplied when  * the route was entered.  Routes that forward packets through  * gateways are marked so that the output routines know to address the  * gateway rather than the ultimate destination.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RNF_NORMAL
end_ifndef

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RADIX_MPATH
end_ifdef

begin_include
include|#
directive|include
file|<net/radix_mpath.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|_WANT_RTENTRY
argument_list|)
end_if

begin_struct
struct|struct
name|rtentry
block|{
name|struct
name|radix_node
name|rt_nodes
index|[
literal|2
index|]
decl_stmt|;
comment|/* tree glue, and other values */
comment|/* 	 * XXX struct rtentry must begin with a struct radix_node (or two!) 	 * because the code does some casts of a 'struct radix_node *' 	 * to a 'struct rtentry *' 	 */
define|#
directive|define
name|rt_key
parameter_list|(
name|r
parameter_list|)
value|(*((struct sockaddr **)(&(r)->rt_nodes->rn_key)))
define|#
directive|define
name|rt_mask
parameter_list|(
name|r
parameter_list|)
value|(*((struct sockaddr **)(&(r)->rt_nodes->rn_mask)))
name|struct
name|sockaddr
modifier|*
name|rt_gateway
decl_stmt|;
comment|/* value */
name|struct
name|ifnet
modifier|*
name|rt_ifp
decl_stmt|;
comment|/* the answer: interface to use */
name|struct
name|ifaddr
modifier|*
name|rt_ifa
decl_stmt|;
comment|/* the answer: interface address to use */
name|int
name|rt_flags
decl_stmt|;
comment|/* up/down?, host/net */
name|int
name|rt_refcnt
decl_stmt|;
comment|/* # held references */
name|u_int
name|rt_fibnum
decl_stmt|;
comment|/* which FIB */
name|u_long
name|rt_mtu
decl_stmt|;
comment|/* MTU for this path */
name|u_long
name|rt_weight
decl_stmt|;
comment|/* absolute weight */
name|u_long
name|rt_expire
decl_stmt|;
comment|/* lifetime for route, e.g. redirect */
define|#
directive|define
name|rt_endzero
value|rt_pksent
name|counter_u64_t
name|rt_pksent
decl_stmt|;
comment|/* packets sent using this route */
name|struct
name|mtx
name|rt_mtx
decl_stmt|;
comment|/* mutex for routing entry */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL || _WANT_RTENTRY */
end_comment

begin_define
define|#
directive|define
name|RTF_UP
value|0x1
end_define

begin_comment
comment|/* route usable */
end_comment

begin_define
define|#
directive|define
name|RTF_GATEWAY
value|0x2
end_define

begin_comment
comment|/* destination is a gateway */
end_comment

begin_define
define|#
directive|define
name|RTF_HOST
value|0x4
end_define

begin_comment
comment|/* host entry (net otherwise) */
end_comment

begin_define
define|#
directive|define
name|RTF_REJECT
value|0x8
end_define

begin_comment
comment|/* host or net unreachable */
end_comment

begin_define
define|#
directive|define
name|RTF_DYNAMIC
value|0x10
end_define

begin_comment
comment|/* created dynamically (by redirect) */
end_comment

begin_define
define|#
directive|define
name|RTF_MODIFIED
value|0x20
end_define

begin_comment
comment|/* modified dynamically (by redirect) */
end_comment

begin_define
define|#
directive|define
name|RTF_DONE
value|0x40
end_define

begin_comment
comment|/* message confirmed */
end_comment

begin_comment
comment|/*			0x80		   unused, was RTF_DELCLONE */
end_comment

begin_comment
comment|/*			0x100		   unused, was RTF_CLONING */
end_comment

begin_define
define|#
directive|define
name|RTF_XRESOLVE
value|0x200
end_define

begin_comment
comment|/* external daemon resolves name */
end_comment

begin_define
define|#
directive|define
name|RTF_LLINFO
value|0x400
end_define

begin_comment
comment|/* DEPRECATED - exists ONLY for backward  					   compatibility */
end_comment

begin_define
define|#
directive|define
name|RTF_LLDATA
value|0x400
end_define

begin_comment
comment|/* used by apps to add/del L2 entries */
end_comment

begin_define
define|#
directive|define
name|RTF_STATIC
value|0x800
end_define

begin_comment
comment|/* manually added */
end_comment

begin_define
define|#
directive|define
name|RTF_BLACKHOLE
value|0x1000
end_define

begin_comment
comment|/* just discard pkts (during updates) */
end_comment

begin_define
define|#
directive|define
name|RTF_PROTO2
value|0x4000
end_define

begin_comment
comment|/* protocol specific routing flag */
end_comment

begin_define
define|#
directive|define
name|RTF_PROTO1
value|0x8000
end_define

begin_comment
comment|/* protocol specific routing flag */
end_comment

begin_comment
comment|/*			0x10000		   unused, was RTF_PRCLONING */
end_comment

begin_comment
comment|/*			0x20000		   unused, was RTF_WASCLONED */
end_comment

begin_define
define|#
directive|define
name|RTF_PROTO3
value|0x40000
end_define

begin_comment
comment|/* protocol specific routing flag */
end_comment

begin_comment
comment|/*			0x80000		   unused */
end_comment

begin_define
define|#
directive|define
name|RTF_PINNED
value|0x100000
end_define

begin_comment
comment|/* route is immutable */
end_comment

begin_define
define|#
directive|define
name|RTF_LOCAL
value|0x200000
end_define

begin_comment
comment|/* route represents a local address */
end_comment

begin_define
define|#
directive|define
name|RTF_BROADCAST
value|0x400000
end_define

begin_comment
comment|/* route represents a bcast address */
end_comment

begin_define
define|#
directive|define
name|RTF_MULTICAST
value|0x800000
end_define

begin_comment
comment|/* route represents a mcast address */
end_comment

begin_comment
comment|/* 0x8000000 and up unassigned */
end_comment

begin_define
define|#
directive|define
name|RTF_STICKY
value|0x10000000
end_define

begin_comment
comment|/* always route dst->src */
end_comment

begin_define
define|#
directive|define
name|RTF_RNH_LOCKED
value|0x40000000
end_define

begin_comment
comment|/* radix node head is locked */
end_comment

begin_define
define|#
directive|define
name|RTF_GWFLAG_COMPAT
value|0x80000000
end_define

begin_comment
comment|/* a compatibility bit for interacting 					   with existing routing apps */
end_comment

begin_comment
comment|/* Mask of RTF flags that are allowed to be modified by RTM_CHANGE. */
end_comment

begin_define
define|#
directive|define
name|RTF_FMASK
define|\
value|(RTF_PROTO1 | RTF_PROTO2 | RTF_PROTO3 | RTF_BLACKHOLE | \ 	 RTF_REJECT | RTF_STATIC | RTF_STICKY)
end_define

begin_comment
comment|/*  * Routing statistics.  */
end_comment

begin_struct
struct|struct
name|rtstat
block|{
name|short
name|rts_badredirect
decl_stmt|;
comment|/* bogus redirect calls */
name|short
name|rts_dynamic
decl_stmt|;
comment|/* routes created by redirects */
name|short
name|rts_newgateway
decl_stmt|;
comment|/* routes modified by redirects */
name|short
name|rts_unreach
decl_stmt|;
comment|/* lookups which failed */
name|short
name|rts_wildcard
decl_stmt|;
comment|/* lookups satisfied by a wildcard */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structures for routing messages.  */
end_comment

begin_struct
struct|struct
name|rt_msghdr
block|{
name|u_short
name|rtm_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|rtm_version
decl_stmt|;
comment|/* future binary compatibility */
name|u_char
name|rtm_type
decl_stmt|;
comment|/* message type */
name|u_short
name|rtm_index
decl_stmt|;
comment|/* index for associated ifp */
name|int
name|rtm_flags
decl_stmt|;
comment|/* flags, incl. kern& message, e.g. DONE */
name|int
name|rtm_addrs
decl_stmt|;
comment|/* bitmask identifying sockaddrs in msg */
name|pid_t
name|rtm_pid
decl_stmt|;
comment|/* identify sender */
name|int
name|rtm_seq
decl_stmt|;
comment|/* for sender to identify action */
name|int
name|rtm_errno
decl_stmt|;
comment|/* why failed */
name|int
name|rtm_fmask
decl_stmt|;
comment|/* bitmask used in RTM_CHANGE message */
name|u_long
name|rtm_inits
decl_stmt|;
comment|/* which metrics we are initializing */
name|struct
name|rt_metrics
name|rtm_rmx
decl_stmt|;
comment|/* metrics themselves */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTM_VERSION
value|5
end_define

begin_comment
comment|/* Up the ante and ignore older versions */
end_comment

begin_comment
comment|/*  * Message types.  */
end_comment

begin_define
define|#
directive|define
name|RTM_ADD
value|0x1
end_define

begin_comment
comment|/* Add Route */
end_comment

begin_define
define|#
directive|define
name|RTM_DELETE
value|0x2
end_define

begin_comment
comment|/* Delete Route */
end_comment

begin_define
define|#
directive|define
name|RTM_CHANGE
value|0x3
end_define

begin_comment
comment|/* Change Metrics or flags */
end_comment

begin_define
define|#
directive|define
name|RTM_GET
value|0x4
end_define

begin_comment
comment|/* Report Metrics */
end_comment

begin_define
define|#
directive|define
name|RTM_LOSING
value|0x5
end_define

begin_comment
comment|/* Kernel Suspects Partitioning */
end_comment

begin_define
define|#
directive|define
name|RTM_REDIRECT
value|0x6
end_define

begin_comment
comment|/* Told to use different route */
end_comment

begin_define
define|#
directive|define
name|RTM_MISS
value|0x7
end_define

begin_comment
comment|/* Lookup failed on this address */
end_comment

begin_define
define|#
directive|define
name|RTM_LOCK
value|0x8
end_define

begin_comment
comment|/* fix specified metrics */
end_comment

begin_comment
comment|/*	0x9  */
end_comment

begin_comment
comment|/*	0xa  */
end_comment

begin_define
define|#
directive|define
name|RTM_RESOLVE
value|0xb
end_define

begin_comment
comment|/* req to resolve dst to LL addr */
end_comment

begin_define
define|#
directive|define
name|RTM_NEWADDR
value|0xc
end_define

begin_comment
comment|/* address being added to iface */
end_comment

begin_define
define|#
directive|define
name|RTM_DELADDR
value|0xd
end_define

begin_comment
comment|/* address being removed from iface */
end_comment

begin_define
define|#
directive|define
name|RTM_IFINFO
value|0xe
end_define

begin_comment
comment|/* iface going up/down etc. */
end_comment

begin_define
define|#
directive|define
name|RTM_NEWMADDR
value|0xf
end_define

begin_comment
comment|/* mcast group membership being added to if */
end_comment

begin_define
define|#
directive|define
name|RTM_DELMADDR
value|0x10
end_define

begin_comment
comment|/* mcast group membership being deleted */
end_comment

begin_define
define|#
directive|define
name|RTM_IFANNOUNCE
value|0x11
end_define

begin_comment
comment|/* iface arrival/departure */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211
value|0x12
end_define

begin_comment
comment|/* IEEE80211 wireless event */
end_comment

begin_comment
comment|/*  * Bitmask values for rtm_inits and rmx_locks.  */
end_comment

begin_define
define|#
directive|define
name|RTV_MTU
value|0x1
end_define

begin_comment
comment|/* init or lock _mtu */
end_comment

begin_define
define|#
directive|define
name|RTV_HOPCOUNT
value|0x2
end_define

begin_comment
comment|/* init or lock _hopcount */
end_comment

begin_define
define|#
directive|define
name|RTV_EXPIRE
value|0x4
end_define

begin_comment
comment|/* init or lock _expire */
end_comment

begin_define
define|#
directive|define
name|RTV_RPIPE
value|0x8
end_define

begin_comment
comment|/* init or lock _recvpipe */
end_comment

begin_define
define|#
directive|define
name|RTV_SPIPE
value|0x10
end_define

begin_comment
comment|/* init or lock _sendpipe */
end_comment

begin_define
define|#
directive|define
name|RTV_SSTHRESH
value|0x20
end_define

begin_comment
comment|/* init or lock _ssthresh */
end_comment

begin_define
define|#
directive|define
name|RTV_RTT
value|0x40
end_define

begin_comment
comment|/* init or lock _rtt */
end_comment

begin_define
define|#
directive|define
name|RTV_RTTVAR
value|0x80
end_define

begin_comment
comment|/* init or lock _rttvar */
end_comment

begin_define
define|#
directive|define
name|RTV_WEIGHT
value|0x100
end_define

begin_comment
comment|/* init or lock _weight */
end_comment

begin_comment
comment|/*  * Bitmask values for rtm_addrs.  */
end_comment

begin_define
define|#
directive|define
name|RTA_DST
value|0x1
end_define

begin_comment
comment|/* destination sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_GATEWAY
value|0x2
end_define

begin_comment
comment|/* gateway sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_NETMASK
value|0x4
end_define

begin_comment
comment|/* netmask sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_GENMASK
value|0x8
end_define

begin_comment
comment|/* cloning mask sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_IFP
value|0x10
end_define

begin_comment
comment|/* interface name sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_IFA
value|0x20
end_define

begin_comment
comment|/* interface addr sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_AUTHOR
value|0x40
end_define

begin_comment
comment|/* sockaddr for author of redirect */
end_comment

begin_define
define|#
directive|define
name|RTA_BRD
value|0x80
end_define

begin_comment
comment|/* for NEWADDR, broadcast or p-p dest addr */
end_comment

begin_comment
comment|/*  * Index offsets for sockaddr array for alternate internal encoding.  */
end_comment

begin_define
define|#
directive|define
name|RTAX_DST
value|0
end_define

begin_comment
comment|/* destination sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTAX_GATEWAY
value|1
end_define

begin_comment
comment|/* gateway sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTAX_NETMASK
value|2
end_define

begin_comment
comment|/* netmask sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTAX_GENMASK
value|3
end_define

begin_comment
comment|/* cloning mask sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTAX_IFP
value|4
end_define

begin_comment
comment|/* interface name sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTAX_IFA
value|5
end_define

begin_comment
comment|/* interface addr sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTAX_AUTHOR
value|6
end_define

begin_comment
comment|/* sockaddr for author of redirect */
end_comment

begin_define
define|#
directive|define
name|RTAX_BRD
value|7
end_define

begin_comment
comment|/* for NEWADDR, broadcast or p-p dest addr */
end_comment

begin_define
define|#
directive|define
name|RTAX_MAX
value|8
end_define

begin_comment
comment|/* size of array to allocate */
end_comment

begin_struct
struct|struct
name|rt_addrinfo
block|{
name|int
name|rti_addrs
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|rti_info
index|[
name|RTAX_MAX
index|]
decl_stmt|;
name|int
name|rti_flags
decl_stmt|;
name|struct
name|ifaddr
modifier|*
name|rti_ifa
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|rti_ifp
decl_stmt|;
name|u_long
name|rti_mflags
decl_stmt|;
name|struct
name|rt_metrics
modifier|*
name|rti_rmx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This macro returns the size of a struct sockaddr when passed  * through a routing socket. Basically we round up sa_len to  * a multiple of sizeof(long), with a minimum of sizeof(long).  * The check for a NULL pointer is just a convenience, probably never used.  * The case sa_len == 0 should only apply to empty structures.  */
end_comment

begin_define
define|#
directive|define
name|SA_SIZE
parameter_list|(
name|sa
parameter_list|)
define|\
value|(  (!(sa) || ((struct sockaddr *)(sa))->sa_len == 0) ?	\ 	sizeof(long)		:				\ 	1 + ( (((struct sockaddr *)(sa))->sa_len - 1) | (sizeof(long) - 1) ) )
end_define

begin_define
define|#
directive|define
name|sa_equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(	\     (((struct sockaddr *)(a))->sa_len == ((struct sockaddr *)(b))->sa_len)&& \     (bcmp((a), (b), ((struct sockaddr *)(b))->sa_len) == 0))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|RT_LINK_IS_UP
parameter_list|(
name|ifp
parameter_list|)
value|(!((ifp)->if_capabilities& IFCAP_LINKSTATE) \ 				 || (ifp)->if_link_state == LINK_STATE_UP)
end_define

begin_define
define|#
directive|define
name|RT_LOCK_INIT
parameter_list|(
name|_rt
parameter_list|)
define|\
value|mtx_init(&(_rt)->rt_mtx, "rtentry", NULL, MTX_DEF | MTX_DUPOK)
end_define

begin_define
define|#
directive|define
name|RT_LOCK
parameter_list|(
name|_rt
parameter_list|)
value|mtx_lock(&(_rt)->rt_mtx)
end_define

begin_define
define|#
directive|define
name|RT_UNLOCK
parameter_list|(
name|_rt
parameter_list|)
value|mtx_unlock(&(_rt)->rt_mtx)
end_define

begin_define
define|#
directive|define
name|RT_LOCK_DESTROY
parameter_list|(
name|_rt
parameter_list|)
value|mtx_destroy(&(_rt)->rt_mtx)
end_define

begin_define
define|#
directive|define
name|RT_LOCK_ASSERT
parameter_list|(
name|_rt
parameter_list|)
value|mtx_assert(&(_rt)->rt_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|RT_UNLOCK_COND
parameter_list|(
name|_rt
parameter_list|)
value|do {				\ 	if (mtx_owned(&(_rt)->rt_mtx))				\ 		mtx_unlock(&(_rt)->rt_mtx);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RT_ADDREF
parameter_list|(
name|_rt
parameter_list|)
value|do {					\ 	RT_LOCK_ASSERT(_rt);					\ 	KASSERT((_rt)->rt_refcnt>= 0,				\ 		("negative refcnt %d", (_rt)->rt_refcnt));	\ 	(_rt)->rt_refcnt++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|RT_REMREF
parameter_list|(
name|_rt
parameter_list|)
value|do {					\ 	RT_LOCK_ASSERT(_rt);					\ 	KASSERT((_rt)->rt_refcnt> 0,				\ 		("bogus refcnt %d", (_rt)->rt_refcnt));	\ 	(_rt)->rt_refcnt--;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|RTFREE_LOCKED
parameter_list|(
name|_rt
parameter_list|)
value|do {					\ 	if ((_rt)->rt_refcnt<= 1)				\ 		rtfree(_rt);					\ 	else {							\ 		RT_REMREF(_rt);					\ 		RT_UNLOCK(_rt);					\ 	}							\
comment|/* guard against invalid refs */
value|\ 	_rt = 0;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|RTFREE
parameter_list|(
name|_rt
parameter_list|)
value|do {					\ 	RT_LOCK(_rt);						\ 	RTFREE_LOCKED(_rt);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|RO_RTFREE
parameter_list|(
name|_ro
parameter_list|)
value|do {					\ 	if ((_ro)->ro_rt) {					\ 		if ((_ro)->ro_flags& RT_NORTREF) {		\ 			(_ro)->ro_flags&= ~RT_NORTREF;		\ 			(_ro)->ro_rt = NULL;			\ 		} else {					\ 			RT_LOCK((_ro)->ro_rt);			\ 			RTFREE_LOCKED((_ro)->ro_rt);		\ 		}						\ 	}							\ } while (0)
end_define

begin_function_decl
name|struct
name|radix_node_head
modifier|*
name|rt_tables_get_rnh
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ifmultiaddr
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|rt_ieee80211msg
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_ifannouncemsg
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_ifmsg
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_missmsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|rt_addrinfo
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_missmsg_fib
parameter_list|(
name|int
parameter_list|,
name|struct
name|rt_addrinfo
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_newaddrmsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_newaddrmsg_fib
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt_addrmsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt_routemsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_newmaddrmsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifmultiaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt_setgate
parameter_list|(
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_maskedcopy
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtsock_addrmsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtsock_routemsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Note the following locking behavior:  *  *    rtalloc_ign() and rtalloc() return ro->ro_rt unlocked  *  *    rtalloc1() returns a locked rtentry  *  *    rtfree() and RTFREE_LOCKED() require a locked rtentry  *  *    RTFREE() uses an unlocked entry.  */
end_comment

begin_function_decl
name|int
name|rt_expunge
parameter_list|(
name|struct
name|radix_node_head
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtfree
parameter_list|(
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt_check
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX MRT COMPAT VERSIONS THAT SET UNIVERSE to 0 */
end_comment

begin_comment
comment|/* Thes are used by old code not yet converted to use multiple FIBS */
end_comment

begin_function_decl
name|int
name|rt_getifa
parameter_list|(
name|struct
name|rt_addrinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtalloc_ign
parameter_list|(
name|struct
name|route
modifier|*
name|ro
parameter_list|,
name|u_long
name|ignflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtalloc
parameter_list|(
name|struct
name|route
modifier|*
name|ro
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX deprecated, use rtalloc_ign(ro, 0) */
end_comment

begin_function_decl
name|struct
name|rtentry
modifier|*
name|rtalloc1
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtinit
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtioctl
parameter_list|(
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtredirect
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtrequest
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX MRT NEW VERSIONS THAT USE FIBs  * For now the protocol indepedent versions are the same as the AF_INET ones  * but this will change..   */
end_comment

begin_function_decl
name|int
name|rt_getifa_fib
parameter_list|(
name|struct
name|rt_addrinfo
modifier|*
parameter_list|,
name|u_int
name|fibnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtalloc_ign_fib
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
name|rtalloc_fib
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
name|rtalloc1_fib
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
name|int
name|rtioctl_fib
parameter_list|(
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtredirect_fib
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
name|rtrequest_fib
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
name|rtrequest1_fib
parameter_list|(
name|int
parameter_list|,
name|struct
name|rt_addrinfo
modifier|*
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

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|rtevent_redirect_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|route_redirect_event
argument_list|,
name|rtevent_redirect_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

