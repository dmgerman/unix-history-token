begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008 University of Zagreb  * Copyright (c) 2006-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_VINET6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_VINET6_H_
end_define

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/nd6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/raw_ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/scope6_var.h>
end_include

begin_struct
struct|struct
name|vnet_inet6
block|{
name|struct
name|in6_ifaddr
modifier|*
name|_in6_ifaddr
decl_stmt|;
name|u_int
name|_frag6_nfragpackets
decl_stmt|;
name|u_int
name|_frag6_nfrags
decl_stmt|;
name|struct
name|ip6q
name|_ip6q
decl_stmt|;
name|struct
name|route_in6
name|_ip6_forward_rt
decl_stmt|;
comment|/* XXX remove */
name|struct
name|in6_addrpolicy
name|_defaultaddrpolicy
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|addrsel_policyent
argument_list|)
name|_addrsel_policytab
expr_stmt|;
name|u_int
name|_in6_maxmtu
decl_stmt|;
name|int
name|_ip6_auto_linklocal
decl_stmt|;
name|int
name|_rtq_minreallyold6
decl_stmt|;
name|int
name|_rtq_reallyold6
decl_stmt|;
name|int
name|_rtq_toomany6
decl_stmt|;
name|struct
name|ip6stat
name|_ip6stat
decl_stmt|;
name|struct
name|rip6stat
name|_rip6stat
decl_stmt|;
name|struct
name|icmp6stat
name|_icmp6stat
decl_stmt|;
name|int
name|_rtq_timeout6
decl_stmt|;
name|struct
name|callout
name|_rtq_timer6
decl_stmt|;
name|struct
name|callout
name|_rtq_mtutimer
decl_stmt|;
name|struct
name|callout
name|_nd6_slowtimo_ch
decl_stmt|;
name|struct
name|callout
name|_nd6_timer_ch
decl_stmt|;
name|struct
name|callout
name|_in6_tmpaddrtimer_ch
decl_stmt|;
name|int
name|_nd6_inuse
decl_stmt|;
name|int
name|_nd6_allocated
decl_stmt|;
name|int
name|_nd6_onlink_ns_rfc4861
decl_stmt|;
name|struct
name|nd_drhead
name|_nd_defrouter
decl_stmt|;
name|struct
name|nd_prhead
name|_nd_prefix
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|_nd6_defifp
decl_stmt|;
name|int
name|_nd6_defifindex
decl_stmt|;
name|struct
name|scope6_id
name|_sid_default
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dadq
argument_list|)
name|_dadq
expr_stmt|;
name|int
name|_dad_init
decl_stmt|;
name|int
name|_icmp6errpps_count
decl_stmt|;
name|struct
name|timeval
name|_icmp6errppslim_last
decl_stmt|;
name|int
name|_ip6_forwarding
decl_stmt|;
name|int
name|_ip6_sendredirects
decl_stmt|;
name|int
name|_ip6_defhlim
decl_stmt|;
name|int
name|_ip6_defmcasthlim
decl_stmt|;
name|int
name|_ip6_accept_rtadv
decl_stmt|;
name|int
name|_ip6_maxfragpackets
decl_stmt|;
name|int
name|_ip6_maxfrags
decl_stmt|;
name|int
name|_ip6_log_interval
decl_stmt|;
name|int
name|_ip6_hdrnestlimit
decl_stmt|;
name|int
name|_ip6_dad_count
decl_stmt|;
name|int
name|_ip6_auto_flowlabel
decl_stmt|;
name|int
name|_ip6_use_deprecated
decl_stmt|;
name|int
name|_ip6_rr_prune
decl_stmt|;
name|int
name|_ip6_mcast_pmtu
decl_stmt|;
name|int
name|_ip6_v6only
decl_stmt|;
name|int
name|_ip6_keepfaith
decl_stmt|;
name|int
name|_ip6stealth
decl_stmt|;
name|time_t
name|_ip6_log_time
decl_stmt|;
name|int
name|_pmtu_expire
decl_stmt|;
name|int
name|_pmtu_probe
decl_stmt|;
name|u_long
name|_rip6_sendspace
decl_stmt|;
name|u_long
name|_rip6_recvspace
decl_stmt|;
name|int
name|_icmp6_rediraccept
decl_stmt|;
name|int
name|_icmp6_redirtimeout
decl_stmt|;
name|int
name|_icmp6errppslim
decl_stmt|;
name|int
name|_icmp6_nodeinfo
decl_stmt|;
name|int
name|_udp6_sendspace
decl_stmt|;
name|int
name|_udp6_recvspace
decl_stmt|;
name|int
name|_ip6qmaxlen
decl_stmt|;
name|int
name|_ip6_prefer_tempaddr
decl_stmt|;
name|int
name|_ip6_forward_srcrt
decl_stmt|;
comment|/* XXX remove */
name|int
name|_ip6_sourcecheck
decl_stmt|;
comment|/* XXX remove */
name|int
name|_ip6_sourcecheck_interval
decl_stmt|;
comment|/* XXX remove */
name|int
name|_ip6_ours_check_algorithm
decl_stmt|;
comment|/* XXX remove */
name|int
name|_nd6_prune
decl_stmt|;
name|int
name|_nd6_delay
decl_stmt|;
name|int
name|_nd6_umaxtries
decl_stmt|;
name|int
name|_nd6_mmaxtries
decl_stmt|;
name|int
name|_nd6_useloopback
decl_stmt|;
name|int
name|_nd6_gctimer
decl_stmt|;
name|int
name|_nd6_maxndopt
decl_stmt|;
name|int
name|_nd6_maxnudhint
decl_stmt|;
name|int
name|_nd6_maxqueuelen
decl_stmt|;
name|int
name|_nd6_debug
decl_stmt|;
name|int
name|_nd6_recalc_reachtm_interval
decl_stmt|;
name|int
name|_dad_ignore_ns
decl_stmt|;
name|int
name|_dad_maxtry
decl_stmt|;
name|int
name|_ip6_use_tempaddr
decl_stmt|;
name|int
name|_ip6_desync_factor
decl_stmt|;
name|u_int32_t
name|_ip6_temp_preferred_lifetime
decl_stmt|;
name|u_int32_t
name|_ip6_temp_valid_lifetime
decl_stmt|;
name|int
name|_ip6_mrouter_ver
decl_stmt|;
name|int
name|_pim6
decl_stmt|;
name|u_int
name|_mrt6debug
decl_stmt|;
name|int
name|_ip6_temp_regen_advance
decl_stmt|;
name|int
name|_ip6_use_defzone
decl_stmt|;
name|struct
name|ip6_pktopts
name|_ip6_opts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Size guard. See sys/vimage.h. */
end_comment

begin_expr_stmt
name|VIMAGE_CTASSERT
argument_list|(
name|SIZEOF_vnet_inet6
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|vnet_inet6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE_GLOBALS
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|vnet_inet6
name|vnet_inet6_0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INIT_VNET_INET6
parameter_list|(
name|vnet
parameter_list|)
define|\
value|INIT_FROM_VNET(vnet, VNET_MOD_INET6, struct vnet_inet6, vnet_inet6)
end_define

begin_define
define|#
directive|define
name|VNET_INET6
parameter_list|(
name|sym
parameter_list|)
value|VSYM(vnet_inet6, sym)
end_define

begin_comment
comment|/*  * Symbol translation macros  */
end_comment

begin_define
define|#
directive|define
name|V_addrsel_policytab
value|VNET_INET6(addrsel_policytab)
end_define

begin_define
define|#
directive|define
name|V_dad_ignore_ns
value|VNET_INET6(dad_ignore_ns)
end_define

begin_define
define|#
directive|define
name|V_dad_init
value|VNET_INET6(dad_init)
end_define

begin_define
define|#
directive|define
name|V_dad_maxtry
value|VNET_INET6(dad_maxtry)
end_define

begin_define
define|#
directive|define
name|V_dadq
value|VNET_INET6(dadq)
end_define

begin_define
define|#
directive|define
name|V_defaultaddrpolicy
value|VNET_INET6(defaultaddrpolicy)
end_define

begin_define
define|#
directive|define
name|V_frag6_nfragpackets
value|VNET_INET6(frag6_nfragpackets)
end_define

begin_define
define|#
directive|define
name|V_frag6_nfrags
value|VNET_INET6(frag6_nfrags)
end_define

begin_define
define|#
directive|define
name|V_icmp6_nodeinfo
value|VNET_INET6(icmp6_nodeinfo)
end_define

begin_define
define|#
directive|define
name|V_icmp6_rediraccept
value|VNET_INET6(icmp6_rediraccept)
end_define

begin_define
define|#
directive|define
name|V_icmp6_redirtimeout
value|VNET_INET6(icmp6_redirtimeout)
end_define

begin_define
define|#
directive|define
name|V_icmp6errpps_count
value|VNET_INET6(icmp6errpps_count)
end_define

begin_define
define|#
directive|define
name|V_icmp6errppslim
value|VNET_INET6(icmp6errppslim)
end_define

begin_define
define|#
directive|define
name|V_icmp6errppslim_last
value|VNET_INET6(icmp6errppslim_last)
end_define

begin_define
define|#
directive|define
name|V_icmp6stat
value|VNET_INET6(icmp6stat)
end_define

begin_define
define|#
directive|define
name|V_in6_ifaddr
value|VNET_INET6(in6_ifaddr)
end_define

begin_define
define|#
directive|define
name|V_in6_maxmtu
value|VNET_INET6(in6_maxmtu)
end_define

begin_define
define|#
directive|define
name|V_in6_tmpaddrtimer_ch
value|VNET_INET6(in6_tmpaddrtimer_ch)
end_define

begin_define
define|#
directive|define
name|V_ip6_accept_rtadv
value|VNET_INET6(ip6_accept_rtadv)
end_define

begin_define
define|#
directive|define
name|V_ip6_auto_flowlabel
value|VNET_INET6(ip6_auto_flowlabel)
end_define

begin_define
define|#
directive|define
name|V_ip6_auto_linklocal
value|VNET_INET6(ip6_auto_linklocal)
end_define

begin_define
define|#
directive|define
name|V_ip6_dad_count
value|VNET_INET6(ip6_dad_count)
end_define

begin_define
define|#
directive|define
name|V_ip6_defhlim
value|VNET_INET6(ip6_defhlim)
end_define

begin_define
define|#
directive|define
name|V_ip6_defmcasthlim
value|VNET_INET6(ip6_defmcasthlim)
end_define

begin_define
define|#
directive|define
name|V_ip6_desync_factor
value|VNET_INET6(ip6_desync_factor)
end_define

begin_define
define|#
directive|define
name|V_ip6_forwarding
value|VNET_INET6(ip6_forwarding)
end_define

begin_define
define|#
directive|define
name|V_ip6_hdrnestlimit
value|VNET_INET6(ip6_hdrnestlimit)
end_define

begin_define
define|#
directive|define
name|V_ip6_keepfaith
value|VNET_INET6(ip6_keepfaith)
end_define

begin_define
define|#
directive|define
name|V_ip6_log_interval
value|VNET_INET6(ip6_log_interval)
end_define

begin_define
define|#
directive|define
name|V_ip6_log_time
value|VNET_INET6(ip6_log_time)
end_define

begin_define
define|#
directive|define
name|V_ip6_maxfragpackets
value|VNET_INET6(ip6_maxfragpackets)
end_define

begin_define
define|#
directive|define
name|V_ip6_maxfrags
value|VNET_INET6(ip6_maxfrags)
end_define

begin_define
define|#
directive|define
name|V_ip6_mcast_pmtu
value|VNET_INET6(ip6_mcast_pmtu)
end_define

begin_define
define|#
directive|define
name|V_ip6_mrouter_ver
value|VNET_INET6(ip6_mrouter_ver)
end_define

begin_define
define|#
directive|define
name|V_ip6_opts
value|VNET_INET6(ip6_opts)
end_define

begin_define
define|#
directive|define
name|V_ip6_prefer_tempaddr
value|VNET_INET6(ip6_prefer_tempaddr)
end_define

begin_define
define|#
directive|define
name|V_ip6_rr_prune
value|VNET_INET6(ip6_rr_prune)
end_define

begin_define
define|#
directive|define
name|V_ip6_sendredirects
value|VNET_INET6(ip6_sendredirects)
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_preferred_lifetime
value|VNET_INET6(ip6_temp_preferred_lifetime)
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_regen_advance
value|VNET_INET6(ip6_temp_regen_advance)
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_valid_lifetime
value|VNET_INET6(ip6_temp_valid_lifetime)
end_define

begin_define
define|#
directive|define
name|V_ip6_use_defzone
value|VNET_INET6(ip6_use_defzone)
end_define

begin_define
define|#
directive|define
name|V_ip6_use_deprecated
value|VNET_INET6(ip6_use_deprecated)
end_define

begin_define
define|#
directive|define
name|V_ip6_use_tempaddr
value|VNET_INET6(ip6_use_tempaddr)
end_define

begin_define
define|#
directive|define
name|V_ip6_v6only
value|VNET_INET6(ip6_v6only)
end_define

begin_define
define|#
directive|define
name|V_ip6q
value|VNET_INET6(ip6q)
end_define

begin_define
define|#
directive|define
name|V_ip6qmaxlen
value|VNET_INET6(ip6qmaxlen)
end_define

begin_define
define|#
directive|define
name|V_ip6stat
value|VNET_INET6(ip6stat)
end_define

begin_define
define|#
directive|define
name|V_ip6stealth
value|VNET_INET6(ip6stealth)
end_define

begin_define
define|#
directive|define
name|V_llinfo_nd6
value|VNET_INET6(llinfo_nd6)
end_define

begin_define
define|#
directive|define
name|V_mrt6debug
value|VNET_INET6(mrt6debug)
end_define

begin_define
define|#
directive|define
name|V_nd6_allocated
value|VNET_INET6(nd6_allocated)
end_define

begin_define
define|#
directive|define
name|V_nd6_debug
value|VNET_INET6(nd6_debug)
end_define

begin_define
define|#
directive|define
name|V_nd6_defifindex
value|VNET_INET6(nd6_defifindex)
end_define

begin_define
define|#
directive|define
name|V_nd6_defifp
value|VNET_INET6(nd6_defifp)
end_define

begin_define
define|#
directive|define
name|V_nd6_delay
value|VNET_INET6(nd6_delay)
end_define

begin_define
define|#
directive|define
name|V_nd6_gctimer
value|VNET_INET6(nd6_gctimer)
end_define

begin_define
define|#
directive|define
name|V_nd6_inuse
value|VNET_INET6(nd6_inuse)
end_define

begin_define
define|#
directive|define
name|V_nd6_maxndopt
value|VNET_INET6(nd6_maxndopt)
end_define

begin_define
define|#
directive|define
name|V_nd6_maxnudhint
value|VNET_INET6(nd6_maxnudhint)
end_define

begin_define
define|#
directive|define
name|V_nd6_maxqueuelen
value|VNET_INET6(nd6_maxqueuelen)
end_define

begin_define
define|#
directive|define
name|V_nd6_mmaxtries
value|VNET_INET6(nd6_mmaxtries)
end_define

begin_define
define|#
directive|define
name|V_nd6_onlink_ns_rfc4861
value|VNET_INET6(nd6_onlink_ns_rfc4861)
end_define

begin_define
define|#
directive|define
name|V_nd6_prune
value|VNET_INET6(nd6_prune)
end_define

begin_define
define|#
directive|define
name|V_nd6_recalc_reachtm_interval
value|VNET_INET6(nd6_recalc_reachtm_interval)
end_define

begin_define
define|#
directive|define
name|V_nd6_slowtimo_ch
value|VNET_INET6(nd6_slowtimo_ch)
end_define

begin_define
define|#
directive|define
name|V_nd6_timer_ch
value|VNET_INET6(nd6_timer_ch)
end_define

begin_define
define|#
directive|define
name|V_nd6_umaxtries
value|VNET_INET6(nd6_umaxtries)
end_define

begin_define
define|#
directive|define
name|V_nd6_useloopback
value|VNET_INET6(nd6_useloopback)
end_define

begin_define
define|#
directive|define
name|V_nd_defrouter
value|VNET_INET6(nd_defrouter)
end_define

begin_define
define|#
directive|define
name|V_nd_prefix
value|VNET_INET6(nd_prefix)
end_define

begin_define
define|#
directive|define
name|V_pim6
value|VNET_INET6(pim6)
end_define

begin_define
define|#
directive|define
name|V_pmtu_expire
value|VNET_INET6(pmtu_expire)
end_define

begin_define
define|#
directive|define
name|V_pmtu_probe
value|VNET_INET6(pmtu_probe)
end_define

begin_define
define|#
directive|define
name|V_rip6_recvspace
value|VNET_INET6(rip6_recvspace)
end_define

begin_define
define|#
directive|define
name|V_rip6_sendspace
value|VNET_INET6(rip6_sendspace)
end_define

begin_define
define|#
directive|define
name|V_rip6stat
value|VNET_INET6(rip6stat)
end_define

begin_define
define|#
directive|define
name|V_rtq_minreallyold6
value|VNET_INET6(rtq_minreallyold6)
end_define

begin_define
define|#
directive|define
name|V_rtq_mtutimer
value|VNET_INET6(rtq_mtutimer)
end_define

begin_define
define|#
directive|define
name|V_rtq_reallyold6
value|VNET_INET6(rtq_reallyold6)
end_define

begin_define
define|#
directive|define
name|V_rtq_timeout6
value|VNET_INET6(rtq_timeout6)
end_define

begin_define
define|#
directive|define
name|V_rtq_timer6
value|VNET_INET6(rtq_timer6)
end_define

begin_define
define|#
directive|define
name|V_rtq_toomany6
value|VNET_INET6(rtq_toomany6)
end_define

begin_define
define|#
directive|define
name|V_sid_default
value|VNET_INET6(sid_default)
end_define

begin_define
define|#
directive|define
name|V_udp6_recvspace
value|VNET_INET6(udp6_recvspace)
end_define

begin_define
define|#
directive|define
name|V_udp6_sendspace
value|VNET_INET6(udp6_sendspace)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET6_VINET6_H_ */
end_comment

end_unit

