begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$KAME: nd6.h,v 1.76 2001/12/18 02:10:31 itojun Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_ND6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_ND6_H_
end_define

begin_comment
comment|/* see net/route.h, or net/if_inarp.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTF_ANNOUNCE
end_ifndef

begin_define
define|#
directive|define
name|RTF_ANNOUNCE
value|RTF_PROTO2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_struct_decl
struct_decl|struct
name|llentry
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ND6_LLINFO_NOSTATE
value|-2
end_define

begin_comment
comment|/*  * We don't need the WAITDELETE state any more, but we keep the definition  * in a comment line instead of removing it. This is necessary to avoid  * unintentionally reusing the value for another purpose, which might  * affect backward compatibility with old applications.  * (20000711 jinmei@kame.net)  */
end_comment

begin_comment
comment|/* #define ND6_LLINFO_WAITDELETE	-1 */
end_comment

begin_define
define|#
directive|define
name|ND6_LLINFO_INCOMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|ND6_LLINFO_REACHABLE
value|1
end_define

begin_define
define|#
directive|define
name|ND6_LLINFO_STALE
value|2
end_define

begin_define
define|#
directive|define
name|ND6_LLINFO_DELAY
value|3
end_define

begin_define
define|#
directive|define
name|ND6_LLINFO_PROBE
value|4
end_define

begin_define
define|#
directive|define
name|ND6_IS_LLINFO_PROBREACH
parameter_list|(
name|n
parameter_list|)
value|((n)->ln_state> ND6_LLINFO_INCOMPLETE)
end_define

begin_define
define|#
directive|define
name|ND6_LLINFO_PERMANENT
parameter_list|(
name|n
parameter_list|)
value|(((n)->la_expire == 0)&& ((n)->ln_state> ND6_LLINFO_INCOMPLETE))
end_define

begin_struct
struct|struct
name|nd_ifinfo
block|{
name|u_int32_t
name|linkmtu
decl_stmt|;
comment|/* LinkMTU */
name|u_int32_t
name|maxmtu
decl_stmt|;
comment|/* Upper bound of LinkMTU */
name|u_int32_t
name|basereachable
decl_stmt|;
comment|/* BaseReachableTime */
name|u_int32_t
name|reachable
decl_stmt|;
comment|/* Reachable Time */
name|u_int32_t
name|retrans
decl_stmt|;
comment|/* Retrans Timer */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* Flags */
name|int
name|recalctm
decl_stmt|;
comment|/* BaseReacable re-calculation timer */
name|u_int8_t
name|chlim
decl_stmt|;
comment|/* CurHopLimit */
name|u_int8_t
name|initialized
decl_stmt|;
comment|/* Flag to see the entry is initialized */
comment|/* the following 3 members are for privacy extension for addrconf */
name|u_int8_t
name|randomseed0
index|[
literal|8
index|]
decl_stmt|;
comment|/* upper 64 bits of MD5 digest */
name|u_int8_t
name|randomseed1
index|[
literal|8
index|]
decl_stmt|;
comment|/* lower 64 bits (usually the EUI64 IFID) */
name|u_int8_t
name|randomid
index|[
literal|8
index|]
decl_stmt|;
comment|/* current random ID */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ND6_IFF_PERFORMNUD
value|0x1
end_define

begin_define
define|#
directive|define
name|ND6_IFF_ACCEPT_RTADV
value|0x2
end_define

begin_define
define|#
directive|define
name|ND6_IFF_PREFER_SOURCE
value|0x4
end_define

begin_comment
comment|/* Not used in FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|ND6_IFF_IFDISABLED
value|0x8
end_define

begin_comment
comment|/* IPv6 operation is disabled due to 				     * DAD failure.  (XXX: not ND-specific) 				     */
end_comment

begin_define
define|#
directive|define
name|ND6_IFF_DONT_SET_IFROUTE
value|0x10
end_define

begin_define
define|#
directive|define
name|ND6_IFF_AUTO_LINKLOCAL
value|0x20
end_define

begin_define
define|#
directive|define
name|ND6_IFF_NO_RADR
value|0x40
end_define

begin_define
define|#
directive|define
name|ND6_IFF_NO_PREFER_IFACE
value|0x80
end_define

begin_comment
comment|/* XXX: not related to ND. */
end_comment

begin_define
define|#
directive|define
name|ND6_IFF_NO_DAD
value|0x100
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ND_IFINFO
parameter_list|(
name|ifp
parameter_list|)
define|\
value|(((struct in6_ifextra *)(ifp)->if_afdata[AF_INET6])->nd_ifinfo)
end_define

begin_define
define|#
directive|define
name|IN6_LINKMTU
parameter_list|(
name|ifp
parameter_list|)
define|\
value|((ND_IFINFO(ifp)->linkmtu&& ND_IFINFO(ifp)->linkmtu< (ifp)->if_mtu) \ 	    ? ND_IFINFO(ifp)->linkmtu \ 	    : ((ND_IFINFO(ifp)->maxmtu&& ND_IFINFO(ifp)->maxmtu< (ifp)->if_mtu) \ 		? ND_IFINFO(ifp)->maxmtu : (ifp)->if_mtu))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|in6_nbrinfo
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|in6_addr
name|addr
decl_stmt|;
comment|/* IPv6 address of the neighbor */
name|long
name|asked
decl_stmt|;
comment|/* number of queries already sent for this addr */
name|int
name|isrouter
decl_stmt|;
comment|/* if it acts as a router */
name|int
name|state
decl_stmt|;
comment|/* reachability state */
name|int
name|expire
decl_stmt|;
comment|/* lifetime for NDP state transition */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRLSTSIZ
value|10
end_define

begin_define
define|#
directive|define
name|PRLSTSIZ
value|10
end_define

begin_struct
struct|struct
name|in6_drlist
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
struct|struct
block|{
name|struct
name|in6_addr
name|rtaddr
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
name|u_short
name|rtlifetime
decl_stmt|;
name|u_long
name|expire
decl_stmt|;
name|u_short
name|if_index
decl_stmt|;
block|}
name|defrouter
index|[
name|DRLSTSIZ
index|]
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_defrouter
block|{
name|struct
name|sockaddr_in6
name|rtaddr
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
name|u_short
name|rtlifetime
decl_stmt|;
name|u_long
name|expire
decl_stmt|;
name|u_short
name|if_index
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|in6_oprlist
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
struct|struct
block|{
name|struct
name|in6_addr
name|prefix
decl_stmt|;
name|struct
name|prf_ra
name|raflags
decl_stmt|;
name|u_char
name|prefixlen
decl_stmt|;
name|u_char
name|origin
decl_stmt|;
name|u_long
name|vltime
decl_stmt|;
name|u_long
name|pltime
decl_stmt|;
name|u_long
name|expire
decl_stmt|;
name|u_short
name|if_index
decl_stmt|;
name|u_short
name|advrtrs
decl_stmt|;
comment|/* number of advertisement routers */
name|struct
name|in6_addr
name|advrtr
index|[
name|DRLSTSIZ
index|]
decl_stmt|;
comment|/* XXX: explicit limit */
block|}
name|prefix
index|[
name|PRLSTSIZ
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|in6_prlist
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
struct|struct
block|{
name|struct
name|in6_addr
name|prefix
decl_stmt|;
name|struct
name|prf_ra
name|raflags
decl_stmt|;
name|u_char
name|prefixlen
decl_stmt|;
name|u_char
name|origin
decl_stmt|;
name|u_int32_t
name|vltime
decl_stmt|;
name|u_int32_t
name|pltime
decl_stmt|;
name|time_t
name|expire
decl_stmt|;
name|u_short
name|if_index
decl_stmt|;
name|u_short
name|advrtrs
decl_stmt|;
comment|/* number of advertisement routers */
name|struct
name|in6_addr
name|advrtr
index|[
name|DRLSTSIZ
index|]
decl_stmt|;
comment|/* XXX: explicit limit */
block|}
name|prefix
index|[
name|PRLSTSIZ
index|]
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_prefix
block|{
name|struct
name|sockaddr_in6
name|prefix
decl_stmt|;
name|struct
name|prf_ra
name|raflags
decl_stmt|;
name|u_char
name|prefixlen
decl_stmt|;
name|u_char
name|origin
decl_stmt|;
name|u_int32_t
name|vltime
decl_stmt|;
name|u_int32_t
name|pltime
decl_stmt|;
name|time_t
name|expire
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
name|u_short
name|if_index
decl_stmt|;
name|u_short
name|advrtrs
decl_stmt|;
comment|/* number of advertisement routers */
comment|/* struct sockaddr_in6 advrtr[] */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|in6_ondireq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|linkmtu
decl_stmt|;
comment|/* LinkMTU */
name|u_int32_t
name|maxmtu
decl_stmt|;
comment|/* Upper bound of LinkMTU */
name|u_int32_t
name|basereachable
decl_stmt|;
comment|/* BaseReachableTime */
name|u_int32_t
name|reachable
decl_stmt|;
comment|/* Reachable Time */
name|u_int32_t
name|retrans
decl_stmt|;
comment|/* Retrans Timer */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* Flags */
name|int
name|recalctm
decl_stmt|;
comment|/* BaseReacable re-calculation timer */
name|u_int8_t
name|chlim
decl_stmt|;
comment|/* CurHopLimit */
name|u_int8_t
name|receivedra
decl_stmt|;
block|}
name|ndi
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|in6_ndireq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|nd_ifinfo
name|ndi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_ndifreq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_long
name|ifindex
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Prefix status */
end_comment

begin_define
define|#
directive|define
name|NDPRF_ONLINK
value|0x1
end_define

begin_define
define|#
directive|define
name|NDPRF_DETACHED
value|0x2
end_define

begin_comment
comment|/* protocol constants */
end_comment

begin_define
define|#
directive|define
name|MAX_RTR_SOLICITATION_DELAY
value|1
end_define

begin_comment
comment|/* 1sec */
end_comment

begin_define
define|#
directive|define
name|RTR_SOLICITATION_INTERVAL
value|4
end_define

begin_comment
comment|/* 4sec */
end_comment

begin_define
define|#
directive|define
name|MAX_RTR_SOLICITATIONS
value|3
end_define

begin_define
define|#
directive|define
name|ND6_INFINITE_LIFETIME
value|0xffffffff
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* node constants */
end_comment

begin_define
define|#
directive|define
name|MAX_REACHABLE_TIME
value|3600000
end_define

begin_comment
comment|/* msec */
end_comment

begin_define
define|#
directive|define
name|REACHABLE_TIME
value|30000
end_define

begin_comment
comment|/* msec */
end_comment

begin_define
define|#
directive|define
name|RETRANS_TIMER
value|1000
end_define

begin_comment
comment|/* msec */
end_comment

begin_define
define|#
directive|define
name|MIN_RANDOM_FACTOR
value|512
end_define

begin_comment
comment|/* 1024 * 0.5 */
end_comment

begin_define
define|#
directive|define
name|MAX_RANDOM_FACTOR
value|1536
end_define

begin_comment
comment|/* 1024 * 1.5 */
end_comment

begin_define
define|#
directive|define
name|DEF_TEMP_VALID_LIFETIME
value|604800
end_define

begin_comment
comment|/* 1 week */
end_comment

begin_define
define|#
directive|define
name|DEF_TEMP_PREFERRED_LIFETIME
value|86400
end_define

begin_comment
comment|/* 1 day */
end_comment

begin_define
define|#
directive|define
name|TEMPADDR_REGEN_ADVANCE
value|5
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|MAX_TEMP_DESYNC_FACTOR
value|600
end_define

begin_comment
comment|/* 10 min */
end_comment

begin_define
define|#
directive|define
name|ND_COMPUTE_RTIME
parameter_list|(
name|x
parameter_list|)
define|\
value|(((MIN_RANDOM_FACTOR * (x>> 10)) + (arc4random()& \ 		((MAX_RANDOM_FACTOR - MIN_RANDOM_FACTOR) * (x>> 10)))) /1000)
end_define

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nd_drhead
argument_list|,
name|nd_defrouter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|nd_defrouter
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nd_defrouter
argument_list|)
name|dr_entry
expr_stmt|;
name|struct
name|in6_addr
name|rtaddr
decl_stmt|;
name|u_char
name|raflags
decl_stmt|;
comment|/* flags on RA message */
name|u_short
name|rtlifetime
decl_stmt|;
name|u_long
name|expire
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|installed
decl_stmt|;
comment|/* is installed into kernel routing table */
name|u_int
name|refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nd_prefixctl
block|{
name|struct
name|ifnet
modifier|*
name|ndpr_ifp
decl_stmt|;
comment|/* prefix */
name|struct
name|sockaddr_in6
name|ndpr_prefix
decl_stmt|;
name|u_char
name|ndpr_plen
decl_stmt|;
name|u_int32_t
name|ndpr_vltime
decl_stmt|;
comment|/* advertised valid lifetime */
name|u_int32_t
name|ndpr_pltime
decl_stmt|;
comment|/* advertised preferred lifetime */
name|struct
name|prf_ra
name|ndpr_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nd_prhead
argument_list|,
name|nd_prefix
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|nd_prefix
block|{
name|struct
name|ifnet
modifier|*
name|ndpr_ifp
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|nd_prefix
argument_list|)
name|ndpr_entry
expr_stmt|;
name|struct
name|sockaddr_in6
name|ndpr_prefix
decl_stmt|;
comment|/* prefix */
name|struct
name|in6_addr
name|ndpr_mask
decl_stmt|;
comment|/* netmask derived from the prefix */
name|u_int32_t
name|ndpr_vltime
decl_stmt|;
comment|/* advertised valid lifetime */
name|u_int32_t
name|ndpr_pltime
decl_stmt|;
comment|/* advertised preferred lifetime */
name|time_t
name|ndpr_expire
decl_stmt|;
comment|/* expiration time of the prefix */
name|time_t
name|ndpr_preferred
decl_stmt|;
comment|/* preferred time of the prefix */
name|time_t
name|ndpr_lastupdate
decl_stmt|;
comment|/* reception time of last advertisement */
name|struct
name|prf_ra
name|ndpr_flags
decl_stmt|;
name|u_int32_t
name|ndpr_stateflags
decl_stmt|;
comment|/* actual state flags */
comment|/* list of routers that advertise the prefix: */
name|LIST_HEAD
argument_list|(
argument|pr_rtrhead
argument_list|,
argument|nd_pfxrouter
argument_list|)
name|ndpr_advrtrs
expr_stmt|;
name|u_char
name|ndpr_plen
decl_stmt|;
name|int
name|ndpr_addrcnt
decl_stmt|;
comment|/* count of derived addresses */
specifier|volatile
name|u_int
name|ndpr_refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ndpr_raf
value|ndpr_flags
end_define

begin_define
define|#
directive|define
name|ndpr_raf_onlink
value|ndpr_flags.onlink
end_define

begin_define
define|#
directive|define
name|ndpr_raf_auto
value|ndpr_flags.autonomous
end_define

begin_define
define|#
directive|define
name|ndpr_raf_router
value|ndpr_flags.router
end_define

begin_comment
comment|/*  * Message format for use in obtaining information about prefixes  * from inet6 sysctl function  */
end_comment

begin_struct
struct|struct
name|inet6_ndpr_msghdr
block|{
name|u_short
name|inpm_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|inpm_version
decl_stmt|;
comment|/* future binary compatibility */
name|u_char
name|inpm_type
decl_stmt|;
comment|/* message type */
name|struct
name|in6_addr
name|inpm_prefix
decl_stmt|;
name|u_long
name|prm_vltim
decl_stmt|;
name|u_long
name|prm_pltime
decl_stmt|;
name|u_long
name|prm_expire
decl_stmt|;
name|u_long
name|prm_preferred
decl_stmt|;
name|struct
name|in6_prflags
name|prm_flags
decl_stmt|;
name|u_short
name|prm_index
decl_stmt|;
comment|/* index for associated ifp */
name|u_char
name|prm_plen
decl_stmt|;
comment|/* length of prefix in bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|prm_raf_onlink
value|prm_flags.prf_ra.onlink
end_define

begin_define
define|#
directive|define
name|prm_raf_auto
value|prm_flags.prf_ra.autonomous
end_define

begin_define
define|#
directive|define
name|prm_statef_onlink
value|prm_flags.prf_state.onlink
end_define

begin_define
define|#
directive|define
name|prm_rrf_decrvalid
value|prm_flags.prf_rr.decrvalid
end_define

begin_define
define|#
directive|define
name|prm_rrf_decrprefd
value|prm_flags.prf_rr.decrprefd
end_define

begin_struct
struct|struct
name|nd_pfxrouter
block|{
name|LIST_ENTRY
argument_list|(
argument|nd_pfxrouter
argument_list|)
name|pfr_entry
expr_stmt|;
name|struct
name|nd_defrouter
modifier|*
name|router
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IP6NDP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nd6.c */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_prune
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_delay
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_umaxtries
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_mmaxtries
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_useloopback
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_maxnudhint
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_gctimer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|nd_drhead
argument_list|,
name|nd_defrouter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|nd_prhead
argument_list|,
name|nd_prefix
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_onlink_ns_rfc4861
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_nd6_prune
value|VNET(nd6_prune)
end_define

begin_define
define|#
directive|define
name|V_nd6_delay
value|VNET(nd6_delay)
end_define

begin_define
define|#
directive|define
name|V_nd6_umaxtries
value|VNET(nd6_umaxtries)
end_define

begin_define
define|#
directive|define
name|V_nd6_mmaxtries
value|VNET(nd6_mmaxtries)
end_define

begin_define
define|#
directive|define
name|V_nd6_useloopback
value|VNET(nd6_useloopback)
end_define

begin_define
define|#
directive|define
name|V_nd6_maxnudhint
value|VNET(nd6_maxnudhint)
end_define

begin_define
define|#
directive|define
name|V_nd6_gctimer
value|VNET(nd6_gctimer)
end_define

begin_define
define|#
directive|define
name|V_nd_defrouter
value|VNET(nd_defrouter)
end_define

begin_define
define|#
directive|define
name|V_nd_prefix
value|VNET(nd_prefix)
end_define

begin_define
define|#
directive|define
name|V_nd6_debug
value|VNET(nd6_debug)
end_define

begin_define
define|#
directive|define
name|V_nd6_onlink_ns_rfc4861
value|VNET(nd6_onlink_ns_rfc4861)
end_define

begin_comment
comment|/* Lock for the prefix and default router lists. */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|rwlock
argument_list|,
name|nd6_lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|uint64_t
argument_list|,
name|nd6_list_genid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_nd6_lock
value|VNET(nd6_lock)
end_define

begin_define
define|#
directive|define
name|V_nd6_list_genid
value|VNET(nd6_list_genid)
end_define

begin_define
define|#
directive|define
name|ND6_RLOCK
parameter_list|()
value|rw_rlock(&V_nd6_lock)
end_define

begin_define
define|#
directive|define
name|ND6_RUNLOCK
parameter_list|()
value|rw_runlock(&V_nd6_lock)
end_define

begin_define
define|#
directive|define
name|ND6_WLOCK
parameter_list|()
value|rw_wlock(&V_nd6_lock)
end_define

begin_define
define|#
directive|define
name|ND6_WUNLOCK
parameter_list|()
value|rw_wunlock(&V_nd6_lock)
end_define

begin_define
define|#
directive|define
name|ND6_TRY_UPGRADE
parameter_list|()
value|rw_try_upgrade(&V_nd6_lock)
end_define

begin_define
define|#
directive|define
name|ND6_WLOCK_ASSERT
parameter_list|()
value|rw_assert(&V_nd6_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|ND6_RLOCK_ASSERT
parameter_list|()
value|rw_assert(&V_nd6_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|ND6_LOCK_ASSERT
parameter_list|()
value|rw_assert(&V_nd6_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|ND6_UNLOCK_ASSERT
parameter_list|()
value|rw_assert(&V_nd6_lock, RA_UNLOCKED)
end_define

begin_comment
comment|/* Mutex for prefix onlink/offlink transitions. */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|mtx
argument_list|,
name|nd6_onlink_mtx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_nd6_onlink_mtx
value|VNET(nd6_onlink_mtx)
end_define

begin_define
define|#
directive|define
name|ND6_ONLINK_LOCK
parameter_list|()
value|mtx_lock(&V_nd6_onlink_mtx)
end_define

begin_define
define|#
directive|define
name|ND6_ONLINK_TRYLOCK
parameter_list|()
value|mtx_trylock(&V_nd6_onlink_mtx)
end_define

begin_define
define|#
directive|define
name|ND6_ONLINK_UNLOCK
parameter_list|()
value|mtx_unlock(&V_nd6_onlink_mtx)
end_define

begin_define
define|#
directive|define
name|ND6_ONLINK_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&V_nd6_onlink_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ND6_ONLINK_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&V_nd6_onlink_mtx, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|nd6log
parameter_list|(
name|x
parameter_list|)
value|do { if (V_nd6_debug) log x; } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_comment
comment|/* nd6_rtr.c */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|nd6_defifindex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip6_desync_factor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* seconds */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_int32_t
argument_list|,
name|ip6_temp_preferred_lifetime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* seconds */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_int32_t
argument_list|,
name|ip6_temp_valid_lifetime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* seconds */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip6_temp_regen_advance
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|V_nd6_defifindex
value|VNET(nd6_defifindex)
end_define

begin_define
define|#
directive|define
name|V_ip6_desync_factor
value|VNET(ip6_desync_factor)
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_preferred_lifetime
value|VNET(ip6_temp_preferred_lifetime)
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_valid_lifetime
value|VNET(ip6_temp_valid_lifetime)
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_regen_advance
value|VNET(ip6_temp_regen_advance)
end_define

begin_union
union|union
name|nd_opts
block|{
name|struct
name|nd_opt_hdr
modifier|*
name|nd_opt_array
index|[
literal|16
index|]
decl_stmt|;
comment|/* max = ND_OPT_NONCE */
struct|struct
block|{
name|struct
name|nd_opt_hdr
modifier|*
name|zero
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|src_lladdr
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|tgt_lladdr
decl_stmt|;
name|struct
name|nd_opt_prefix_info
modifier|*
name|pi_beg
decl_stmt|;
comment|/* multiple opts, start */
name|struct
name|nd_opt_rd_hdr
modifier|*
name|rh
decl_stmt|;
name|struct
name|nd_opt_mtu
modifier|*
name|mtu
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res6
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res7
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res8
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res9
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res10
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res11
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res12
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res13
decl_stmt|;
name|struct
name|nd_opt_nonce
modifier|*
name|nonce
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|__res15
decl_stmt|;
name|struct
name|nd_opt_hdr
modifier|*
name|search
decl_stmt|;
comment|/* multiple opts */
name|struct
name|nd_opt_hdr
modifier|*
name|last
decl_stmt|;
comment|/* multiple opts */
name|int
name|done
decl_stmt|;
name|struct
name|nd_opt_prefix_info
modifier|*
name|pi_end
decl_stmt|;
comment|/* multiple opts, end */
block|}
name|nd_opt_each
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|nd_opts_src_lladdr
value|nd_opt_each.src_lladdr
end_define

begin_define
define|#
directive|define
name|nd_opts_tgt_lladdr
value|nd_opt_each.tgt_lladdr
end_define

begin_define
define|#
directive|define
name|nd_opts_pi
value|nd_opt_each.pi_beg
end_define

begin_define
define|#
directive|define
name|nd_opts_pi_end
value|nd_opt_each.pi_end
end_define

begin_define
define|#
directive|define
name|nd_opts_rh
value|nd_opt_each.rh
end_define

begin_define
define|#
directive|define
name|nd_opts_mtu
value|nd_opt_each.mtu
end_define

begin_define
define|#
directive|define
name|nd_opts_nonce
value|nd_opt_each.nonce
end_define

begin_define
define|#
directive|define
name|nd_opts_search
value|nd_opt_each.search
end_define

begin_define
define|#
directive|define
name|nd_opts_last
value|nd_opt_each.last
end_define

begin_define
define|#
directive|define
name|nd_opts_done
value|nd_opt_each.done
end_define

begin_comment
comment|/* XXX: need nd6_var.h?? */
end_comment

begin_comment
comment|/* nd6.c */
end_comment

begin_function_decl
name|void
name|nd6_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|void
name|nd6_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|nd_ifinfo
modifier|*
name|nd6_ifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|nd_ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_is_addr_neighbor
parameter_list|(
specifier|const
name|struct
name|sockaddr_in6
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
name|nd6_option_init
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|union
name|nd_opts
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nd_opt_hdr
modifier|*
name|nd6_option
parameter_list|(
name|union
name|nd_opts
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_options
parameter_list|(
name|union
name|nd_opts
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|llentry
modifier|*
name|nd6_lookup
parameter_list|(
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|llentry
modifier|*
name|nd6_alloc
parameter_list|(
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_setmtu
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_llinfo_setstate
parameter_list|(
name|struct
name|llentry
modifier|*
name|lle
parameter_list|,
name|int
name|newstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_timer
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_purge
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_resolve_addr
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|dst
parameter_list|,
name|char
modifier|*
name|desten
parameter_list|,
name|uint32_t
modifier|*
name|pflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_resolve
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|struct
name|llentry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_ioctl
parameter_list|(
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_cache_lladdr
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|char
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
name|nd6_grab_holdchain
parameter_list|(
name|struct
name|llentry
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|sockaddr_in6
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_flush_holdchain
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr_in6
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_add_ifa_lle
parameter_list|(
name|struct
name|in6_ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_rem_ifa_lle
parameter_list|(
name|struct
name|in6_ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_output_ifp
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr_in6
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* nd6_nbr.c */
end_comment

begin_function_decl
name|void
name|nd6_na_input
parameter_list|(
name|struct
name|mbuf
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
name|nd6_na_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|u_long
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
name|void
name|nd6_ns_input
parameter_list|(
name|struct
name|mbuf
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
name|nd6_ns_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|nd6_ifptomac
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_dad_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_dad_start
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_dad_stop
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* nd6_rtr.c */
end_comment

begin_function_decl
name|void
name|nd6_rs_input
parameter_list|(
name|struct
name|mbuf
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
name|nd6_ra_input
parameter_list|(
name|struct
name|mbuf
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
name|defrouter_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defrouter_select_fib
parameter_list|(
name|int
name|fibnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defrouter_select
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defrouter_ref
parameter_list|(
name|struct
name|nd_defrouter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defrouter_rele
parameter_list|(
name|struct
name|nd_defrouter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|defrouter_remove
parameter_list|(
name|struct
name|in6_addr
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
name|defrouter_unlink
parameter_list|(
name|struct
name|nd_defrouter
modifier|*
parameter_list|,
name|struct
name|nd_drhead
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defrouter_del
parameter_list|(
name|struct
name|nd_defrouter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_prelist_add
parameter_list|(
name|struct
name|nd_prefixctl
modifier|*
parameter_list|,
name|struct
name|nd_defrouter
modifier|*
parameter_list|,
name|struct
name|nd_prefix
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_prefix_unlink
parameter_list|(
name|struct
name|nd_prefix
modifier|*
parameter_list|,
name|struct
name|nd_prhead
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_prefix_del
parameter_list|(
name|struct
name|nd_prefix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_prefix_ref
parameter_list|(
name|struct
name|nd_prefix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nd6_prefix_rele
parameter_list|(
name|struct
name|nd_prefix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_prefix_onlink
parameter_list|(
name|struct
name|nd_prefix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_prefix_offlink
parameter_list|(
name|struct
name|nd_prefix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfxlist_onlink_check
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nd_defrouter
modifier|*
name|defrouter_lookup
parameter_list|(
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nd_defrouter
modifier|*
name|defrouter_lookup_locked
parameter_list|(
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nd_prefix
modifier|*
name|nd6_prefix_lookup
parameter_list|(
name|struct
name|nd_prefixctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt6_flush
parameter_list|(
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nd6_setdefaultiface
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in6_tmpifadd
parameter_list|(
specifier|const
name|struct
name|in6_ifaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET6_ND6_H_ */
end_comment

end_unit

