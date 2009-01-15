begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008 University of Zagreb  * Copyright (c) 2006-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_VINET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_VINET_H_
end_define

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/igmp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_hostcache.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_syncache.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp_var.h>
end_include

begin_struct
struct|struct
name|vnet_inet
block|{
name|struct
name|in_ifaddrhashhead
modifier|*
name|_in_ifaddrhashtbl
decl_stmt|;
name|struct
name|in_ifaddrhead
name|_in_ifaddrhead
decl_stmt|;
name|u_long
name|_in_ifaddrhmask
decl_stmt|;
name|struct
name|in_multihead
name|_in_multihead
decl_stmt|;
name|int
name|_arpt_keep
decl_stmt|;
name|int
name|_arp_maxtries
decl_stmt|;
name|int
name|_useloopback
decl_stmt|;
name|int
name|_arp_proxyall
decl_stmt|;
name|int
name|_subnetsarelocal
decl_stmt|;
name|int
name|_sameprefixcarponly
decl_stmt|;
name|int
name|_ipforwarding
decl_stmt|;
name|int
name|_ipstealth
decl_stmt|;
name|int
name|_ipfastforward_active
decl_stmt|;
name|int
name|_ipsendredirects
decl_stmt|;
name|int
name|_ip_defttl
decl_stmt|;
name|int
name|_ip_keepfaith
decl_stmt|;
name|int
name|_ip_sendsourcequench
decl_stmt|;
name|int
name|_ip_do_randomid
decl_stmt|;
name|int
name|_ip_checkinterface
decl_stmt|;
name|u_short
name|_ip_id
decl_stmt|;
name|uma_zone_t
name|_ipq_zone
decl_stmt|;
name|int
name|_nipq
decl_stmt|;
comment|/* Total # of reass queues */
name|int
name|_maxnipq
decl_stmt|;
comment|/* Admin. limit on # reass queues. */
name|int
name|_maxfragsperpacket
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|ipqhead
argument_list|,
argument|ipq
argument_list|)
name|_ipq
index|[
name|IPREASS_NHASH
index|]
expr_stmt|;
name|struct
name|inpcbhead
name|_tcb
decl_stmt|;
comment|/* head of queue of active tcpcb's */
name|struct
name|inpcbinfo
name|_tcbinfo
decl_stmt|;
name|struct
name|tcpstat
name|_tcpstat
decl_stmt|;
comment|/* tcp statistics */
name|struct
name|tcp_hostcache
name|_tcp_hostcache
decl_stmt|;
name|struct
name|callout
name|_tcp_hc_callout
decl_stmt|;
name|struct
name|tcp_syncache
name|_tcp_syncache
decl_stmt|;
name|int
name|_tcp_syncookies
decl_stmt|;
name|int
name|_tcp_syncookiesonly
decl_stmt|;
name|int
name|_tcp_sc_rst_sock_fail
decl_stmt|;
name|struct
name|inpcbhead
name|_divcb
decl_stmt|;
name|struct
name|inpcbinfo
name|_divcbinfo
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|tcptw
argument_list|)
name|_twq_2msl
expr_stmt|;
name|int
name|_tcp_mssdflt
decl_stmt|;
name|int
name|_tcp_v6mssdflt
decl_stmt|;
name|int
name|_tcp_minmss
decl_stmt|;
name|int
name|_tcp_do_rfc1323
decl_stmt|;
name|int
name|_icmp_may_rst
decl_stmt|;
name|int
name|_tcp_isn_reseed_interval
decl_stmt|;
name|int
name|_tcp_inflight_enable
decl_stmt|;
name|int
name|_tcp_inflight_rttthresh
decl_stmt|;
name|int
name|_tcp_inflight_min
decl_stmt|;
name|int
name|_tcp_inflight_max
decl_stmt|;
name|int
name|_tcp_inflight_stab
decl_stmt|;
name|int
name|_nolocaltimewait
decl_stmt|;
name|int
name|_path_mtu_discovery
decl_stmt|;
name|int
name|_ss_fltsz
decl_stmt|;
name|int
name|_ss_fltsz_local
decl_stmt|;
name|int
name|_tcp_do_newreno
decl_stmt|;
name|int
name|_tcp_do_tso
decl_stmt|;
name|int
name|_tcp_do_autosndbuf
decl_stmt|;
name|int
name|_tcp_autosndbuf_inc
decl_stmt|;
name|int
name|_tcp_autosndbuf_max
decl_stmt|;
name|int
name|_tcp_do_sack
decl_stmt|;
name|int
name|_tcp_sack_maxholes
decl_stmt|;
name|int
name|_tcp_sack_globalmaxholes
decl_stmt|;
name|int
name|_tcp_sack_globalholes
decl_stmt|;
name|int
name|_blackhole
decl_stmt|;
name|int
name|_tcp_delack_enabled
decl_stmt|;
name|int
name|_drop_synfin
decl_stmt|;
name|int
name|_tcp_do_rfc3042
decl_stmt|;
name|int
name|_tcp_do_rfc3390
decl_stmt|;
name|int
name|_tcp_do_rfc3465
decl_stmt|;
name|int
name|_tcp_abc_l_var
decl_stmt|;
name|int
name|_tcp_do_ecn
decl_stmt|;
name|int
name|_tcp_ecn_maxretries
decl_stmt|;
name|int
name|_tcp_insecure_rst
decl_stmt|;
name|int
name|_tcp_do_autorcvbuf
decl_stmt|;
name|int
name|_tcp_autorcvbuf_inc
decl_stmt|;
name|int
name|_tcp_autorcvbuf_max
decl_stmt|;
name|int
name|_tcp_reass_maxseg
decl_stmt|;
name|int
name|_tcp_reass_qsize
decl_stmt|;
name|int
name|_tcp_reass_maxqlen
decl_stmt|;
name|int
name|_tcp_reass_overflows
decl_stmt|;
name|u_char
name|_isn_secret
index|[
literal|32
index|]
decl_stmt|;
name|int
name|_isn_last_reseed
decl_stmt|;
name|u_int32_t
name|_isn_offset
decl_stmt|;
name|u_int32_t
name|_isn_offset_old
decl_stmt|;
name|struct
name|inpcbhead
name|_udb
decl_stmt|;
name|struct
name|inpcbinfo
name|_udbinfo
decl_stmt|;
name|struct
name|udpstat
name|_udpstat
decl_stmt|;
name|int
name|_udp_blackhole
decl_stmt|;
name|struct
name|inpcbhead
name|_ripcb
decl_stmt|;
name|struct
name|inpcbinfo
name|_ripcbinfo
decl_stmt|;
name|struct
name|socket
modifier|*
name|_ip_mrouter
decl_stmt|;
name|struct
name|socket
modifier|*
name|_ip_rsvpd
decl_stmt|;
name|int
name|_ip_rsvp_on
decl_stmt|;
name|int
name|_rsvp_on
decl_stmt|;
name|struct
name|icmpstat
name|_icmpstat
decl_stmt|;
name|struct
name|ipstat
name|_ipstat
decl_stmt|;
name|struct
name|igmpstat
name|_igmpstat
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|router_info
argument_list|)
name|_router_info_head
expr_stmt|;
name|int
name|_rtq_timeout
decl_stmt|;
name|int
name|_rtq_reallyold
decl_stmt|;
name|int
name|_rtq_minreallyold
decl_stmt|;
name|int
name|_rtq_toomany
decl_stmt|;
name|struct
name|callout
name|_rtq_timer
decl_stmt|;
name|int
name|_ipport_lowfirstauto
decl_stmt|;
name|int
name|_ipport_lowlastauto
decl_stmt|;
name|int
name|_ipport_firstauto
decl_stmt|;
name|int
name|_ipport_lastauto
decl_stmt|;
name|int
name|_ipport_hifirstauto
decl_stmt|;
name|int
name|_ipport_hilastauto
decl_stmt|;
name|int
name|_ipport_reservedhigh
decl_stmt|;
name|int
name|_ipport_reservedlow
decl_stmt|;
name|int
name|_ipport_randomized
decl_stmt|;
name|int
name|_ipport_randomcps
decl_stmt|;
name|int
name|_ipport_randomtime
decl_stmt|;
name|int
name|_ipport_stoprandom
decl_stmt|;
name|int
name|_ipport_tcpallocs
decl_stmt|;
name|int
name|_ipport_tcplastcount
decl_stmt|;
name|int
name|_icmpmaskrepl
decl_stmt|;
name|u_int
name|_icmpmaskfake
decl_stmt|;
name|int
name|_drop_redirect
decl_stmt|;
name|int
name|_log_redirect
decl_stmt|;
name|int
name|_icmplim
decl_stmt|;
name|int
name|_icmplim_output
decl_stmt|;
name|char
name|_reply_src
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|int
name|_icmp_rfi
decl_stmt|;
name|int
name|_icmp_quotelen
decl_stmt|;
name|int
name|_icmpbmcastecho
decl_stmt|;
name|int
name|_fw_one_pass
decl_stmt|;
block|}
struct|;
end_struct

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
name|vnet_inet
name|vnet_inet_0
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

begin_comment
comment|/*  * Symbol translation macros  */
end_comment

begin_define
define|#
directive|define
name|INIT_VNET_INET
parameter_list|(
name|vnet
parameter_list|)
define|\
value|INIT_FROM_VNET(vnet, VNET_MOD_INET, struct vnet_inet, vnet_inet)
end_define

begin_define
define|#
directive|define
name|VNET_INET
parameter_list|(
name|sym
parameter_list|)
value|VSYM(vnet_inet, sym)
end_define

begin_define
define|#
directive|define
name|V_arp_maxtries
value|VNET_INET(arp_maxtries)
end_define

begin_define
define|#
directive|define
name|V_arp_proxyall
value|VNET_INET(arp_proxyall)
end_define

begin_define
define|#
directive|define
name|V_arpt_keep
value|VNET_INET(arpt_keep)
end_define

begin_define
define|#
directive|define
name|V_blackhole
value|VNET_INET(blackhole)
end_define

begin_define
define|#
directive|define
name|V_divcb
value|VNET_INET(divcb)
end_define

begin_define
define|#
directive|define
name|V_divcbinfo
value|VNET_INET(divcbinfo)
end_define

begin_define
define|#
directive|define
name|V_drop_redirect
value|VNET_INET(drop_redirect)
end_define

begin_define
define|#
directive|define
name|V_drop_synfin
value|VNET_INET(drop_synfin)
end_define

begin_define
define|#
directive|define
name|V_fw_one_pass
value|VNET_INET(fw_one_pass)
end_define

begin_define
define|#
directive|define
name|V_icmp_may_rst
value|VNET_INET(icmp_may_rst)
end_define

begin_define
define|#
directive|define
name|V_icmp_quotelen
value|VNET_INET(icmp_quotelen)
end_define

begin_define
define|#
directive|define
name|V_icmp_rfi
value|VNET_INET(icmp_rfi)
end_define

begin_define
define|#
directive|define
name|V_icmpbmcastecho
value|VNET_INET(icmpbmcastecho)
end_define

begin_define
define|#
directive|define
name|V_icmplim
value|VNET_INET(icmplim)
end_define

begin_define
define|#
directive|define
name|V_icmplim_output
value|VNET_INET(icmplim_output)
end_define

begin_define
define|#
directive|define
name|V_icmpmaskfake
value|VNET_INET(icmpmaskfake)
end_define

begin_define
define|#
directive|define
name|V_icmpmaskrepl
value|VNET_INET(icmpmaskrepl)
end_define

begin_define
define|#
directive|define
name|V_icmpstat
value|VNET_INET(icmpstat)
end_define

begin_define
define|#
directive|define
name|V_igmpstat
value|VNET_INET(igmpstat)
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhashtbl
value|VNET_INET(in_ifaddrhashtbl)
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhead
value|VNET_INET(in_ifaddrhead)
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhmask
value|VNET_INET(in_ifaddrhmask)
end_define

begin_define
define|#
directive|define
name|V_in_multihead
value|VNET_INET(in_multihead)
end_define

begin_define
define|#
directive|define
name|V_ip_checkinterface
value|VNET_INET(ip_checkinterface)
end_define

begin_define
define|#
directive|define
name|V_ip_defttl
value|VNET_INET(ip_defttl)
end_define

begin_define
define|#
directive|define
name|V_ip_do_randomid
value|VNET_INET(ip_do_randomid)
end_define

begin_define
define|#
directive|define
name|V_ip_id
value|VNET_INET(ip_id)
end_define

begin_define
define|#
directive|define
name|V_ip_keepfaith
value|VNET_INET(ip_keepfaith)
end_define

begin_define
define|#
directive|define
name|V_ip_mrouter
value|VNET_INET(ip_mrouter)
end_define

begin_define
define|#
directive|define
name|V_ip_rsvp_on
value|VNET_INET(ip_rsvp_on)
end_define

begin_define
define|#
directive|define
name|V_ip_rsvpd
value|VNET_INET(ip_rsvpd)
end_define

begin_define
define|#
directive|define
name|V_ip_sendsourcequench
value|VNET_INET(ip_sendsourcequench)
end_define

begin_define
define|#
directive|define
name|V_ipfastforward_active
value|VNET_INET(ipfastforward_active)
end_define

begin_define
define|#
directive|define
name|V_ipforwarding
value|VNET_INET(ipforwarding)
end_define

begin_define
define|#
directive|define
name|V_ipport_firstauto
value|VNET_INET(ipport_firstauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_hifirstauto
value|VNET_INET(ipport_hifirstauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_hilastauto
value|VNET_INET(ipport_hilastauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_lastauto
value|VNET_INET(ipport_lastauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_lowfirstauto
value|VNET_INET(ipport_lowfirstauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_lowlastauto
value|VNET_INET(ipport_lowlastauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_randomcps
value|VNET_INET(ipport_randomcps)
end_define

begin_define
define|#
directive|define
name|V_ipport_randomized
value|VNET_INET(ipport_randomized)
end_define

begin_define
define|#
directive|define
name|V_ipport_randomtime
value|VNET_INET(ipport_randomtime)
end_define

begin_define
define|#
directive|define
name|V_ipport_reservedhigh
value|VNET_INET(ipport_reservedhigh)
end_define

begin_define
define|#
directive|define
name|V_ipport_reservedlow
value|VNET_INET(ipport_reservedlow)
end_define

begin_define
define|#
directive|define
name|V_ipport_stoprandom
value|VNET_INET(ipport_stoprandom)
end_define

begin_define
define|#
directive|define
name|V_ipport_tcpallocs
value|VNET_INET(ipport_tcpallocs)
end_define

begin_define
define|#
directive|define
name|V_ipport_tcplastcount
value|VNET_INET(ipport_tcplastcount)
end_define

begin_define
define|#
directive|define
name|V_ipq
value|VNET_INET(ipq)
end_define

begin_define
define|#
directive|define
name|V_ipq_zone
value|VNET_INET(ipq_zone)
end_define

begin_define
define|#
directive|define
name|V_ipsendredirects
value|VNET_INET(ipsendredirects)
end_define

begin_define
define|#
directive|define
name|V_ipstat
value|VNET_INET(ipstat)
end_define

begin_define
define|#
directive|define
name|V_ipstealth
value|VNET_INET(ipstealth)
end_define

begin_define
define|#
directive|define
name|V_isn_last_reseed
value|VNET_INET(isn_last_reseed)
end_define

begin_define
define|#
directive|define
name|V_isn_offset
value|VNET_INET(isn_offset)
end_define

begin_define
define|#
directive|define
name|V_isn_offset_old
value|VNET_INET(isn_offset_old)
end_define

begin_define
define|#
directive|define
name|V_isn_secret
value|VNET_INET(isn_secret)
end_define

begin_define
define|#
directive|define
name|V_llinfo_arp
value|VNET_INET(llinfo_arp)
end_define

begin_define
define|#
directive|define
name|V_log_redirect
value|VNET_INET(log_redirect)
end_define

begin_define
define|#
directive|define
name|V_maxfragsperpacket
value|VNET_INET(maxfragsperpacket)
end_define

begin_define
define|#
directive|define
name|V_maxnipq
value|VNET_INET(maxnipq)
end_define

begin_define
define|#
directive|define
name|V_nipq
value|VNET_INET(nipq)
end_define

begin_define
define|#
directive|define
name|V_nolocaltimewait
value|VNET_INET(nolocaltimewait)
end_define

begin_define
define|#
directive|define
name|V_path_mtu_discovery
value|VNET_INET(path_mtu_discovery)
end_define

begin_define
define|#
directive|define
name|V_reply_src
value|VNET_INET(reply_src)
end_define

begin_define
define|#
directive|define
name|V_ripcb
value|VNET_INET(ripcb)
end_define

begin_define
define|#
directive|define
name|V_ripcbinfo
value|VNET_INET(ripcbinfo)
end_define

begin_define
define|#
directive|define
name|V_router_info_head
value|VNET_INET(router_info_head)
end_define

begin_define
define|#
directive|define
name|V_rsvp_on
value|VNET_INET(rsvp_on)
end_define

begin_define
define|#
directive|define
name|V_rtq_minreallyold
value|VNET_INET(rtq_minreallyold)
end_define

begin_define
define|#
directive|define
name|V_rtq_reallyold
value|VNET_INET(rtq_reallyold)
end_define

begin_define
define|#
directive|define
name|V_rtq_timeout
value|VNET_INET(rtq_timeout)
end_define

begin_define
define|#
directive|define
name|V_rtq_timer
value|VNET_INET(rtq_timer)
end_define

begin_define
define|#
directive|define
name|V_rtq_toomany
value|VNET_INET(rtq_toomany)
end_define

begin_define
define|#
directive|define
name|V_sameprefixcarponly
value|VNET_INET(sameprefixcarponly)
end_define

begin_define
define|#
directive|define
name|V_ss_fltsz
value|VNET_INET(ss_fltsz)
end_define

begin_define
define|#
directive|define
name|V_ss_fltsz_local
value|VNET_INET(ss_fltsz_local)
end_define

begin_define
define|#
directive|define
name|V_subnetsarelocal
value|VNET_INET(subnetsarelocal)
end_define

begin_define
define|#
directive|define
name|V_tcb
value|VNET_INET(tcb)
end_define

begin_define
define|#
directive|define
name|V_tcbinfo
value|VNET_INET(tcbinfo)
end_define

begin_define
define|#
directive|define
name|V_tcp_abc_l_var
value|VNET_INET(tcp_abc_l_var)
end_define

begin_define
define|#
directive|define
name|V_tcp_autorcvbuf_inc
value|VNET_INET(tcp_autorcvbuf_inc)
end_define

begin_define
define|#
directive|define
name|V_tcp_autorcvbuf_max
value|VNET_INET(tcp_autorcvbuf_max)
end_define

begin_define
define|#
directive|define
name|V_tcp_autosndbuf_inc
value|VNET_INET(tcp_autosndbuf_inc)
end_define

begin_define
define|#
directive|define
name|V_tcp_autosndbuf_max
value|VNET_INET(tcp_autosndbuf_max)
end_define

begin_define
define|#
directive|define
name|V_tcp_delack_enabled
value|VNET_INET(tcp_delack_enabled)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_autorcvbuf
value|VNET_INET(tcp_do_autorcvbuf)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_autosndbuf
value|VNET_INET(tcp_do_autosndbuf)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_ecn
value|VNET_INET(tcp_do_ecn)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_newreno
value|VNET_INET(tcp_do_newreno)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc1323
value|VNET_INET(tcp_do_rfc1323)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3042
value|VNET_INET(tcp_do_rfc3042)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3390
value|VNET_INET(tcp_do_rfc3390)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3465
value|VNET_INET(tcp_do_rfc3465)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_sack
value|VNET_INET(tcp_do_sack)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_tso
value|VNET_INET(tcp_do_tso)
end_define

begin_define
define|#
directive|define
name|V_tcp_ecn_maxretries
value|VNET_INET(tcp_ecn_maxretries)
end_define

begin_define
define|#
directive|define
name|V_tcp_hc_callout
value|VNET_INET(tcp_hc_callout)
end_define

begin_define
define|#
directive|define
name|V_tcp_hostcache
value|VNET_INET(tcp_hostcache)
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_enable
value|VNET_INET(tcp_inflight_enable)
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_max
value|VNET_INET(tcp_inflight_max)
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_min
value|VNET_INET(tcp_inflight_min)
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_rttthresh
value|VNET_INET(tcp_inflight_rttthresh)
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_stab
value|VNET_INET(tcp_inflight_stab)
end_define

begin_define
define|#
directive|define
name|V_tcp_insecure_rst
value|VNET_INET(tcp_insecure_rst)
end_define

begin_define
define|#
directive|define
name|V_tcp_isn_reseed_interval
value|VNET_INET(tcp_isn_reseed_interval)
end_define

begin_define
define|#
directive|define
name|V_tcp_minmss
value|VNET_INET(tcp_minmss)
end_define

begin_define
define|#
directive|define
name|V_tcp_mssdflt
value|VNET_INET(tcp_mssdflt)
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_maxqlen
value|VNET_INET(tcp_reass_maxqlen)
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_maxseg
value|VNET_INET(tcp_reass_maxseg)
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_overflows
value|VNET_INET(tcp_reass_overflows)
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_qsize
value|VNET_INET(tcp_reass_qsize)
end_define

begin_define
define|#
directive|define
name|V_tcp_sack_globalholes
value|VNET_INET(tcp_sack_globalholes)
end_define

begin_define
define|#
directive|define
name|V_tcp_sack_globalmaxholes
value|VNET_INET(tcp_sack_globalmaxholes)
end_define

begin_define
define|#
directive|define
name|V_tcp_sack_maxholes
value|VNET_INET(tcp_sack_maxholes)
end_define

begin_define
define|#
directive|define
name|V_tcp_sc_rst_sock_fail
value|VNET_INET(tcp_sc_rst_sock_fail)
end_define

begin_define
define|#
directive|define
name|V_tcp_syncache
value|VNET_INET(tcp_syncache)
end_define

begin_define
define|#
directive|define
name|V_tcp_syncookies
value|VNET_INET(tcp_syncookies)
end_define

begin_define
define|#
directive|define
name|V_tcp_syncookiesonly
value|VNET_INET(tcp_syncookiesonly)
end_define

begin_define
define|#
directive|define
name|V_tcp_v6mssdflt
value|VNET_INET(tcp_v6mssdflt)
end_define

begin_define
define|#
directive|define
name|V_tcpstat
value|VNET_INET(tcpstat)
end_define

begin_define
define|#
directive|define
name|V_twq_2msl
value|VNET_INET(twq_2msl)
end_define

begin_define
define|#
directive|define
name|V_udb
value|VNET_INET(udb)
end_define

begin_define
define|#
directive|define
name|V_udbinfo
value|VNET_INET(udbinfo)
end_define

begin_define
define|#
directive|define
name|V_udp_blackhole
value|VNET_INET(udp_blackhole)
end_define

begin_define
define|#
directive|define
name|V_udpstat
value|VNET_INET(udpstat)
end_define

begin_define
define|#
directive|define
name|V_useloopback
value|VNET_INET(useloopback)
end_define

begin_define
define|#
directive|define
name|ip_newid
parameter_list|()
value|((V_ip_do_randomid != 0) ? ip_randomid() : htons(V_ip_id++))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_VINET_H_ */
end_comment

end_unit

