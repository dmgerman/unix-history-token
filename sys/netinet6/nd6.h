begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: nd6.h,v 1.55 2001/04/27 15:09:49 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_struct
struct|struct
name|llinfo_nd6
block|{
name|struct
name|llinfo_nd6
modifier|*
name|ln_next
decl_stmt|;
name|struct
name|llinfo_nd6
modifier|*
name|ln_prev
decl_stmt|;
name|struct
name|rtentry
modifier|*
name|ln_rt
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ln_hold
decl_stmt|;
comment|/* last packet until resolved/timeout */
name|long
name|ln_asked
decl_stmt|;
comment|/* number of queries already sent for this addr */
name|u_long
name|ln_expire
decl_stmt|;
comment|/* lifetime for NDP state transition */
name|short
name|ln_state
decl_stmt|;
comment|/* reachability state */
name|short
name|ln_router
decl_stmt|;
comment|/* 2^0: ND6 router bit */
name|int
name|ln_byhint
decl_stmt|;
comment|/* # of times we made it reachable by UL hint */
block|}
struct|;
end_struct

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
name|receivedra
decl_stmt|;
comment|/* the followings are for privacy extension for addrconf */
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
name|u_long
name|vltime
decl_stmt|;
name|u_long
name|pltime
decl_stmt|;
name|u_long
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
comment|/*1sec*/
end_comment

begin_define
define|#
directive|define
name|RTR_SOLICITATION_INTERVAL
value|4
end_define

begin_comment
comment|/*4sec*/
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
value|(((MIN_RANDOM_FACTOR * (x>> 10)) + (random()& \ 		((MAX_RANDOM_FACTOR - MIN_RANDOM_FACTOR) * (x>> 10)))) /1000)
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
name|flags
decl_stmt|;
name|u_short
name|rtlifetime
decl_stmt|;
name|u_long
name|expire
decl_stmt|;
name|u_long
name|advint
decl_stmt|;
comment|/* Mobile IPv6 addition (milliseconds) */
name|u_long
name|advint_expire
decl_stmt|;
comment|/* Mobile IPv6 addition */
name|int
name|advints_lost
decl_stmt|;
comment|/* Mobile IPv6 addition */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
block|}
struct|;
end_struct

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
name|struct
name|in6_addr
name|ndpr_addr
decl_stmt|;
comment|/* address that is derived from the prefix */
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
name|ndpr_refcnt
decl_stmt|;
comment|/* reference couter from addresses */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ndpr_next
value|ndpr_entry.le_next
end_define

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

begin_comment
comment|/*  * We keep expired prefix for certain amount of time, for validation purposes.  * 1800s = MaxRtrAdvInterval  */
end_comment

begin_define
define|#
directive|define
name|NDPR_KEEP_EXPIRED
value|(1800 * 2)
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
comment|/* future binary compatability */
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

begin_define
define|#
directive|define
name|ifpr2ndpr
parameter_list|(
name|ifpr
parameter_list|)
value|((struct nd_prefix *)(ifpr))
end_define

begin_define
define|#
directive|define
name|ndpr2ifpr
parameter_list|(
name|ndpr
parameter_list|)
value|((struct ifprefix *)(ndpr))
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
define|#
directive|define
name|pfr_next
value|pfr_entry.le_next
name|struct
name|nd_defrouter
modifier|*
name|router
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

begin_comment
comment|/* nd6.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nd6_prune
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_delay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_umaxtries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_mmaxtries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_useloopback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_maxnudhint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_gctimer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|llinfo_nd6
name|llinfo_nd6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nd_ifinfo
modifier|*
name|nd_ifinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nd_drhead
name|nd_defrouter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nd_prhead
name|nd_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nd6_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nd6log
parameter_list|(
name|x
parameter_list|)
value|do { if (nd6_debug) log x; } while (0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|callout
name|nd6_timer_ch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nd6_rtr.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nd6_defifindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_desync_factor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ip6_temp_preferred_lifetime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ip6_temp_valid_lifetime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_temp_regen_advance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds */
end_comment

begin_union
union|union
name|nd_opts
block|{
name|struct
name|nd_opt_hdr
modifier|*
name|nd_opt_array
index|[
literal|9
index|]
decl_stmt|;
comment|/*max = home agent info*/
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
name|six
decl_stmt|;
name|struct
name|nd_opt_advint
modifier|*
name|adv
decl_stmt|;
name|struct
name|nd_opt_hai
modifier|*
name|hai
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
name|nd_opts_adv
value|nd_opt_each.adv
end_define

begin_define
define|#
directive|define
name|nd_opts_hai
value|nd_opt_each.hai
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

begin_decl_stmt
name|void
name|nd6_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_ifattach
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_is_addr_neighbor
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_option_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
expr|union
name|nd_opts
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nd_opt_hdr
modifier|*
name|nd6_option
name|__P
argument_list|(
operator|(
expr|union
name|nd_opts
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_options
name|__P
argument_list|(
operator|(
expr|union
name|nd_opts
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rtentry
modifier|*
name|nd6_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|,
name|int
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_setmtu
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_timer
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_purge
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|llinfo_nd6
modifier|*
name|nd6_free
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_nud_hint
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_resolve
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_rtrequest
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|rt_addrinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_ioctl
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|caddr_t
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rtentry
modifier|*
name|nd6_cache_lladdr
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_output
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr_in6
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_storelladdr
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_need_cache
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nd6_nbr.c */
end_comment

begin_decl_stmt
name|void
name|nd6_na_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_na_output
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|,
name|u_long
operator|,
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_ns_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_ns_output
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|llinfo_nd6
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|nd6_ifptomac
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_dad_start
name|__P
argument_list|(
operator|(
expr|struct
name|ifaddr
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_dad_stop
name|__P
argument_list|(
operator|(
expr|struct
name|ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_dad_duplicated
name|__P
argument_list|(
operator|(
expr|struct
name|ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nd6_rtr.c */
end_comment

begin_decl_stmt
name|void
name|nd6_rs_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nd6_ra_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prelist_del
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|defrouter_addreq
name|__P
argument_list|(
operator|(
expr|struct
name|nd_defrouter
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|defrouter_delreq
name|__P
argument_list|(
operator|(
expr|struct
name|nd_defrouter
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|defrouter_select
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|defrtrlist_del
name|__P
argument_list|(
operator|(
expr|struct
name|nd_defrouter
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prelist_remove
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prelist_update
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|,
expr|struct
name|nd_defrouter
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_prelist_add
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|,
expr|struct
name|nd_defrouter
operator|*
operator|,
expr|struct
name|nd_prefix
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_prefix_onlink
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_prefix_offlink
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pfxlist_onlink_check
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nd_defrouter
modifier|*
name|defrouter_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nd_prefix
modifier|*
name|nd6_prefix_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_init_prefix_ltimes
name|__P
argument_list|(
operator|(
expr|struct
name|nd_prefix
operator|*
name|ndpr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rt6_flush
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nd6_setdefaultiface
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_tmpifadd
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|in6_ifaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

