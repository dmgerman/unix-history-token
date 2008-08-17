begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008 University of Zagreb  * Copyright (c) 2006-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VIMAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VIMAGE_H_
end_define

begin_define
define|#
directive|define
name|V_hostname
value|hostname
end_define

begin_define
define|#
directive|define
name|G_hostname
value|hostname
end_define

begin_define
define|#
directive|define
name|V_domainname
value|domainname
end_define

begin_define
define|#
directive|define
name|V_acq_seq
value|acq_seq
end_define

begin_define
define|#
directive|define
name|V_acqtree
value|acqtree
end_define

begin_define
define|#
directive|define
name|V_addrsel_policytab
value|addrsel_policytab
end_define

begin_define
define|#
directive|define
name|V_ah_cleartos
value|ah_cleartos
end_define

begin_define
define|#
directive|define
name|V_ah_enable
value|ah_enable
end_define

begin_define
define|#
directive|define
name|V_ahstat
value|ahstat
end_define

begin_define
define|#
directive|define
name|V_arp_maxtries
value|arp_maxtries
end_define

begin_define
define|#
directive|define
name|V_arp_proxyall
value|arp_proxyall
end_define

begin_define
define|#
directive|define
name|V_arpt_keep
value|arpt_keep
end_define

begin_define
define|#
directive|define
name|V_autoinc_step
value|autoinc_step
end_define

begin_define
define|#
directive|define
name|V_blackhole
value|blackhole
end_define

begin_define
define|#
directive|define
name|V_crypto_support
value|crypto_support
end_define

begin_define
define|#
directive|define
name|V_curr_dyn_buckets
value|curr_dyn_buckets
end_define

begin_define
define|#
directive|define
name|V_dad_ignore_ns
value|dad_ignore_ns
end_define

begin_define
define|#
directive|define
name|V_dad_init
value|dad_init
end_define

begin_define
define|#
directive|define
name|V_dad_maxtry
value|dad_maxtry
end_define

begin_define
define|#
directive|define
name|V_dadq
value|dadq
end_define

begin_define
define|#
directive|define
name|V_defaultaddrpolicy
value|defaultaddrpolicy
end_define

begin_define
define|#
directive|define
name|V_divcb
value|divcb
end_define

begin_define
define|#
directive|define
name|V_divcbinfo
value|divcbinfo
end_define

begin_define
define|#
directive|define
name|V_drop_synfin
value|drop_synfin
end_define

begin_define
define|#
directive|define
name|V_dyn_ack_lifetime
value|dyn_ack_lifetime
end_define

begin_define
define|#
directive|define
name|V_dyn_buckets
value|dyn_buckets
end_define

begin_define
define|#
directive|define
name|V_dyn_count
value|dyn_count
end_define

begin_define
define|#
directive|define
name|V_dyn_fin_lifetime
value|dyn_fin_lifetime
end_define

begin_define
define|#
directive|define
name|V_dyn_keepalive
value|dyn_keepalive
end_define

begin_define
define|#
directive|define
name|V_dyn_keepalive_interval
value|dyn_keepalive_interval
end_define

begin_define
define|#
directive|define
name|V_dyn_keepalive_period
value|dyn_keepalive_period
end_define

begin_define
define|#
directive|define
name|V_dyn_max
value|dyn_max
end_define

begin_define
define|#
directive|define
name|V_dyn_rst_lifetime
value|dyn_rst_lifetime
end_define

begin_define
define|#
directive|define
name|V_dyn_short_lifetime
value|dyn_short_lifetime
end_define

begin_define
define|#
directive|define
name|V_dyn_syn_lifetime
value|dyn_syn_lifetime
end_define

begin_define
define|#
directive|define
name|V_dyn_udp_lifetime
value|dyn_udp_lifetime
end_define

begin_define
define|#
directive|define
name|V_esp_enable
value|esp_enable
end_define

begin_define
define|#
directive|define
name|V_esp_max_ivlen
value|esp_max_ivlen
end_define

begin_define
define|#
directive|define
name|V_espstat
value|espstat
end_define

begin_define
define|#
directive|define
name|V_ether_ipfw
value|ether_ipfw
end_define

begin_define
define|#
directive|define
name|V_frag6_nfragpackets
value|frag6_nfragpackets
end_define

begin_define
define|#
directive|define
name|V_frag6_nfrags
value|frag6_nfrags
end_define

begin_define
define|#
directive|define
name|V_fw6_enable
value|fw6_enable
end_define

begin_define
define|#
directive|define
name|V_fw_debug
value|fw_debug
end_define

begin_define
define|#
directive|define
name|V_fw_deny_unknown_exthdrs
value|fw_deny_unknown_exthdrs
end_define

begin_define
define|#
directive|define
name|V_fw_enable
value|fw_enable
end_define

begin_define
define|#
directive|define
name|V_fw_one_pass
value|fw_one_pass
end_define

begin_define
define|#
directive|define
name|V_fw_verbose
value|fw_verbose
end_define

begin_define
define|#
directive|define
name|V_gif_softc_list
value|gif_softc_list
end_define

begin_define
define|#
directive|define
name|V_icmp6_nodeinfo
value|icmp6_nodeinfo
end_define

begin_define
define|#
directive|define
name|V_icmp6_rediraccept
value|icmp6_rediraccept
end_define

begin_define
define|#
directive|define
name|V_icmp6_redirtimeout
value|icmp6_redirtimeout
end_define

begin_define
define|#
directive|define
name|V_icmp6errpps_count
value|icmp6errpps_count
end_define

begin_define
define|#
directive|define
name|V_icmp6errppslim
value|icmp6errppslim
end_define

begin_define
define|#
directive|define
name|V_icmp6errppslim_last
value|icmp6errppslim_last
end_define

begin_define
define|#
directive|define
name|V_icmp6stat
value|icmp6stat
end_define

begin_define
define|#
directive|define
name|V_icmp_may_rst
value|icmp_may_rst
end_define

begin_define
define|#
directive|define
name|V_icmpstat
value|icmpstat
end_define

begin_define
define|#
directive|define
name|V_if_index
value|if_index
end_define

begin_define
define|#
directive|define
name|V_if_indexlim
value|if_indexlim
end_define

begin_define
define|#
directive|define
name|V_ifaddr_event_tag
value|ifaddr_event_tag
end_define

begin_define
define|#
directive|define
name|V_ifg_head
value|ifg_head
end_define

begin_define
define|#
directive|define
name|V_ifindex_table
value|ifindex_table
end_define

begin_define
define|#
directive|define
name|V_ifklist
value|ifklist
end_define

begin_define
define|#
directive|define
name|V_ifnet
value|ifnet
end_define

begin_define
define|#
directive|define
name|V_igmpstat
value|igmpstat
end_define

begin_define
define|#
directive|define
name|V_in6_ifaddr
value|in6_ifaddr
end_define

begin_define
define|#
directive|define
name|V_in6_maxmtu
value|in6_maxmtu
end_define

begin_define
define|#
directive|define
name|V_in6_tmpaddrtimer_ch
value|in6_tmpaddrtimer_ch
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhashtbl
value|in_ifaddrhashtbl
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhead
value|in_ifaddrhead
end_define

begin_define
define|#
directive|define
name|V_in_ifaddrhmask
value|in_ifaddrhmask
end_define

begin_define
define|#
directive|define
name|V_in_multihead
value|in_multihead
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_net_deflev
value|ip4_ah_net_deflev
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_offsetmask
value|ip4_ah_offsetmask
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_trans_deflev
value|ip4_ah_trans_deflev
end_define

begin_define
define|#
directive|define
name|V_ip4_def_policy
value|ip4_def_policy
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_net_deflev
value|ip4_esp_net_deflev
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_randpad
value|ip4_esp_randpad
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_trans_deflev
value|ip4_esp_trans_deflev
end_define

begin_define
define|#
directive|define
name|V_ip4_ipsec_dfbit
value|ip4_ipsec_dfbit
end_define

begin_define
define|#
directive|define
name|V_ip4_ipsec_ecn
value|ip4_ipsec_ecn
end_define

begin_define
define|#
directive|define
name|V_ip6_accept_rtadv
value|ip6_accept_rtadv
end_define

begin_define
define|#
directive|define
name|V_ip6_ah_net_deflev
value|ip6_ah_net_deflev
end_define

begin_define
define|#
directive|define
name|V_ip6_ah_trans_deflev
value|ip6_ah_trans_deflev
end_define

begin_define
define|#
directive|define
name|V_ip6_auto_flowlabel
value|ip6_auto_flowlabel
end_define

begin_define
define|#
directive|define
name|V_ip6_auto_linklocal
value|ip6_auto_linklocal
end_define

begin_define
define|#
directive|define
name|V_ip6_dad_count
value|ip6_dad_count
end_define

begin_define
define|#
directive|define
name|V_ip6_defhlim
value|ip6_defhlim
end_define

begin_define
define|#
directive|define
name|V_ip6_defmcasthlim
value|ip6_defmcasthlim
end_define

begin_define
define|#
directive|define
name|V_ip6_desync_factor
value|ip6_desync_factor
end_define

begin_define
define|#
directive|define
name|V_ip6_esp_net_deflev
value|ip6_esp_net_deflev
end_define

begin_define
define|#
directive|define
name|V_ip6_esp_trans_deflev
value|ip6_esp_trans_deflev
end_define

begin_define
define|#
directive|define
name|V_ip6_forward_rt
value|ip6_forward_rt
end_define

begin_define
define|#
directive|define
name|V_ip6_forward_srcrt
value|ip6_forward_srcrt
end_define

begin_define
define|#
directive|define
name|V_ip6_forwarding
value|ip6_forwarding
end_define

begin_define
define|#
directive|define
name|V_ip6_gif_hlim
value|ip6_gif_hlim
end_define

begin_define
define|#
directive|define
name|V_ip6_hdrnestlimit
value|ip6_hdrnestlimit
end_define

begin_define
define|#
directive|define
name|V_ip6_ipsec_ecn
value|ip6_ipsec_ecn
end_define

begin_define
define|#
directive|define
name|V_ip6_keepfaith
value|ip6_keepfaith
end_define

begin_define
define|#
directive|define
name|V_ip6_log_interval
value|ip6_log_interval
end_define

begin_define
define|#
directive|define
name|V_ip6_log_time
value|ip6_log_time
end_define

begin_define
define|#
directive|define
name|V_ip6_maxfragpackets
value|ip6_maxfragpackets
end_define

begin_define
define|#
directive|define
name|V_ip6_maxfrags
value|ip6_maxfrags
end_define

begin_define
define|#
directive|define
name|V_ip6_mcast_pmtu
value|ip6_mcast_pmtu
end_define

begin_define
define|#
directive|define
name|V_ip6_mrouter_ver
value|ip6_mrouter_ver
end_define

begin_define
define|#
directive|define
name|V_ip6_opts
value|ip6_opts
end_define

begin_define
define|#
directive|define
name|V_ip6_ours_check_algorithm
value|ip6_ours_check_algorithm
end_define

begin_define
define|#
directive|define
name|V_ip6_prefer_tempaddr
value|ip6_prefer_tempaddr
end_define

begin_define
define|#
directive|define
name|V_ip6_rr_prune
value|ip6_rr_prune
end_define

begin_define
define|#
directive|define
name|V_ip6_sendredirects
value|ip6_sendredirects
end_define

begin_define
define|#
directive|define
name|V_ip6_sourcecheck
value|ip6_sourcecheck
end_define

begin_define
define|#
directive|define
name|V_ip6_sourcecheck_interval
value|ip6_sourcecheck_interval
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_preferred_lifetime
value|ip6_temp_preferred_lifetime
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_regen_advance
value|ip6_temp_regen_advance
end_define

begin_define
define|#
directive|define
name|V_ip6_temp_valid_lifetime
value|ip6_temp_valid_lifetime
end_define

begin_define
define|#
directive|define
name|V_ip6_use_defzone
value|ip6_use_defzone
end_define

begin_define
define|#
directive|define
name|V_ip6_use_deprecated
value|ip6_use_deprecated
end_define

begin_define
define|#
directive|define
name|V_ip6_use_tempaddr
value|ip6_use_tempaddr
end_define

begin_define
define|#
directive|define
name|V_ip6_v6only
value|ip6_v6only
end_define

begin_define
define|#
directive|define
name|V_ip6q
value|ip6q
end_define

begin_define
define|#
directive|define
name|V_ip6qmaxlen
value|ip6qmaxlen
end_define

begin_define
define|#
directive|define
name|V_ip6stat
value|ip6stat
end_define

begin_define
define|#
directive|define
name|V_ip6stealth
value|ip6stealth
end_define

begin_define
define|#
directive|define
name|V_ip_checkinterface
value|ip_checkinterface
end_define

begin_define
define|#
directive|define
name|V_ip_defttl
value|ip_defttl
end_define

begin_define
define|#
directive|define
name|V_ip_do_randomid
value|ip_do_randomid
end_define

begin_define
define|#
directive|define
name|V_ip_gif_ttl
value|ip_gif_ttl
end_define

begin_define
define|#
directive|define
name|V_ip_keepfaith
value|ip_keepfaith
end_define

begin_define
define|#
directive|define
name|V_ip_mrouter
value|ip_mrouter
end_define

begin_define
define|#
directive|define
name|V_ip_rsvp_on
value|ip_rsvp_on
end_define

begin_define
define|#
directive|define
name|V_ip_rsvpd
value|ip_rsvpd
end_define

begin_define
define|#
directive|define
name|V_ip_sendsourcequench
value|ip_sendsourcequench
end_define

begin_define
define|#
directive|define
name|V_ipcomp_enable
value|ipcomp_enable
end_define

begin_define
define|#
directive|define
name|V_ipcompstat
value|ipcompstat
end_define

begin_define
define|#
directive|define
name|V_ipfastforward_active
value|ipfastforward_active
end_define

begin_define
define|#
directive|define
name|V_ipforwarding
value|ipforwarding
end_define

begin_define
define|#
directive|define
name|V_ipfw_dyn_v
value|ipfw_dyn_v
end_define

begin_define
define|#
directive|define
name|V_ipfw_timeout
value|ipfw_timeout
end_define

begin_define
define|#
directive|define
name|V_ipip_allow
value|ipip_allow
end_define

begin_define
define|#
directive|define
name|V_ipipstat
value|ipipstat
end_define

begin_define
define|#
directive|define
name|V_ipport_firstauto
value|ipport_firstauto
end_define

begin_define
define|#
directive|define
name|V_ipport_hifirstauto
value|ipport_hifirstauto
end_define

begin_define
define|#
directive|define
name|V_ipport_hilastauto
value|ipport_hilastauto
end_define

begin_define
define|#
directive|define
name|V_ipport_lastauto
value|ipport_lastauto
end_define

begin_define
define|#
directive|define
name|V_ipport_lowfirstauto
value|ipport_lowfirstauto
end_define

begin_define
define|#
directive|define
name|V_ipport_lowlastauto
value|ipport_lowlastauto
end_define

begin_define
define|#
directive|define
name|V_ipport_randomcps
value|ipport_randomcps
end_define

begin_define
define|#
directive|define
name|V_ipport_randomized
value|ipport_randomized
end_define

begin_define
define|#
directive|define
name|V_ipport_randomtime
value|ipport_randomtime
end_define

begin_define
define|#
directive|define
name|V_ipport_reservedhigh
value|ipport_reservedhigh
end_define

begin_define
define|#
directive|define
name|V_ipport_reservedlow
value|ipport_reservedlow
end_define

begin_define
define|#
directive|define
name|V_ipport_stoprandom
value|ipport_stoprandom
end_define

begin_define
define|#
directive|define
name|V_ipport_tcpallocs
value|ipport_tcpallocs
end_define

begin_define
define|#
directive|define
name|V_ipport_tcplastcount
value|ipport_tcplastcount
end_define

begin_define
define|#
directive|define
name|V_ipq
value|ipq
end_define

begin_define
define|#
directive|define
name|V_ipq_zone
value|ipq_zone
end_define

begin_define
define|#
directive|define
name|V_ipsec4stat
value|ipsec4stat
end_define

begin_define
define|#
directive|define
name|V_ipsec6stat
value|ipsec6stat
end_define

begin_define
define|#
directive|define
name|V_ipsec_ah_keymin
value|ipsec_ah_keymin
end_define

begin_define
define|#
directive|define
name|V_ipsec_debug
value|ipsec_debug
end_define

begin_define
define|#
directive|define
name|V_ipsec_esp_auth
value|ipsec_esp_auth
end_define

begin_define
define|#
directive|define
name|V_ipsec_esp_keymin
value|ipsec_esp_keymin
end_define

begin_define
define|#
directive|define
name|V_ipsec_integrity
value|ipsec_integrity
end_define

begin_define
define|#
directive|define
name|V_ipsec_replay
value|ipsec_replay
end_define

begin_define
define|#
directive|define
name|V_ipsendredirects
value|ipsendredirects
end_define

begin_define
define|#
directive|define
name|V_ipstat
value|ipstat
end_define

begin_define
define|#
directive|define
name|V_ipstealth
value|ipstealth
end_define

begin_define
define|#
directive|define
name|V_isn_ctx
value|isn_ctx
end_define

begin_define
define|#
directive|define
name|V_isn_last_reseed
value|isn_last_reseed
end_define

begin_define
define|#
directive|define
name|V_isn_offset
value|isn_offset
end_define

begin_define
define|#
directive|define
name|V_isn_offset_old
value|isn_offset_old
end_define

begin_define
define|#
directive|define
name|V_isn_secret
value|isn_secret
end_define

begin_define
define|#
directive|define
name|V_key_blockacq_count
value|key_blockacq_count
end_define

begin_define
define|#
directive|define
name|V_key_blockacq_lifetime
value|key_blockacq_lifetime
end_define

begin_define
define|#
directive|define
name|V_key_cb
value|key_cb
end_define

begin_define
define|#
directive|define
name|V_key_debug_level
value|key_debug_level
end_define

begin_define
define|#
directive|define
name|V_key_int_random
value|key_int_random
end_define

begin_define
define|#
directive|define
name|V_key_larval_lifetime
value|key_larval_lifetime
end_define

begin_define
define|#
directive|define
name|V_key_preferred_oldsa
value|key_preferred_oldsa
end_define

begin_define
define|#
directive|define
name|V_key_spi_maxval
value|key_spi_maxval
end_define

begin_define
define|#
directive|define
name|V_key_spi_minval
value|key_spi_minval
end_define

begin_define
define|#
directive|define
name|V_key_spi_trycnt
value|key_spi_trycnt
end_define

begin_define
define|#
directive|define
name|V_key_src
value|key_src
end_define

begin_define
define|#
directive|define
name|V_layer3_chain
value|layer3_chain
end_define

begin_define
define|#
directive|define
name|V_llinfo_arp
value|llinfo_arp
end_define

begin_define
define|#
directive|define
name|V_llinfo_nd6
value|llinfo_nd6
end_define

begin_define
define|#
directive|define
name|V_lo_list
value|lo_list
end_define

begin_define
define|#
directive|define
name|V_loif
value|loif
end_define

begin_define
define|#
directive|define
name|V_max_gif_nesting
value|max_gif_nesting
end_define

begin_define
define|#
directive|define
name|V_maxfragsperpacket
value|maxfragsperpacket
end_define

begin_define
define|#
directive|define
name|V_maxnipq
value|maxnipq
end_define

begin_define
define|#
directive|define
name|V_mrt6debug
value|mrt6debug
end_define

begin_define
define|#
directive|define
name|V_nd6_allocated
value|nd6_allocated
end_define

begin_define
define|#
directive|define
name|V_nd6_debug
value|nd6_debug
end_define

begin_define
define|#
directive|define
name|V_nd6_defifindex
value|nd6_defifindex
end_define

begin_define
define|#
directive|define
name|V_nd6_defifp
value|nd6_defifp
end_define

begin_define
define|#
directive|define
name|V_nd6_delay
value|nd6_delay
end_define

begin_define
define|#
directive|define
name|V_nd6_gctimer
value|nd6_gctimer
end_define

begin_define
define|#
directive|define
name|V_nd6_inuse
value|nd6_inuse
end_define

begin_define
define|#
directive|define
name|V_nd6_maxndopt
value|nd6_maxndopt
end_define

begin_define
define|#
directive|define
name|V_nd6_maxnudhint
value|nd6_maxnudhint
end_define

begin_define
define|#
directive|define
name|V_nd6_maxqueuelen
value|nd6_maxqueuelen
end_define

begin_define
define|#
directive|define
name|V_nd6_mmaxtries
value|nd6_mmaxtries
end_define

begin_define
define|#
directive|define
name|V_nd6_prune
value|nd6_prune
end_define

begin_define
define|#
directive|define
name|V_nd6_recalc_reachtm_interval
value|nd6_recalc_reachtm_interval
end_define

begin_define
define|#
directive|define
name|V_nd6_slowtimo_ch
value|nd6_slowtimo_ch
end_define

begin_define
define|#
directive|define
name|V_nd6_timer_ch
value|nd6_timer_ch
end_define

begin_define
define|#
directive|define
name|V_nd6_umaxtries
value|nd6_umaxtries
end_define

begin_define
define|#
directive|define
name|V_nd6_useloopback
value|nd6_useloopback
end_define

begin_define
define|#
directive|define
name|V_nd_defrouter
value|nd_defrouter
end_define

begin_define
define|#
directive|define
name|V_nd_prefix
value|nd_prefix
end_define

begin_define
define|#
directive|define
name|V_nextID
value|nextID
end_define

begin_define
define|#
directive|define
name|V_ng_ID_hash
value|ng_ID_hash
end_define

begin_define
define|#
directive|define
name|V_ng_eiface_unit
value|ng_eiface_unit
end_define

begin_define
define|#
directive|define
name|V_ng_iface_unit
value|ng_iface_unit
end_define

begin_define
define|#
directive|define
name|V_ng_name_hash
value|ng_name_hash
end_define

begin_define
define|#
directive|define
name|V_nipq
value|nipq
end_define

begin_define
define|#
directive|define
name|V_nolocaltimewait
value|nolocaltimewait
end_define

begin_define
define|#
directive|define
name|V_norule_counter
value|norule_counter
end_define

begin_define
define|#
directive|define
name|V_parallel_tunnels
value|parallel_tunnels
end_define

begin_define
define|#
directive|define
name|V_path_mtu_discovery
value|path_mtu_discovery
end_define

begin_define
define|#
directive|define
name|V_pfkeystat
value|pfkeystat
end_define

begin_define
define|#
directive|define
name|V_pim6
value|pim6
end_define

begin_define
define|#
directive|define
name|V_pmtu_expire
value|pmtu_expire
end_define

begin_define
define|#
directive|define
name|V_pmtu_probe
value|pmtu_probe
end_define

begin_define
define|#
directive|define
name|V_policy_id
value|policy_id
end_define

begin_define
define|#
directive|define
name|V_rawcb_list
value|rawcb_list
end_define

begin_define
define|#
directive|define
name|V_regtree
value|regtree
end_define

begin_define
define|#
directive|define
name|V_rip6_recvspace
value|rip6_recvspace
end_define

begin_define
define|#
directive|define
name|V_rip6_sendspace
value|rip6_sendspace
end_define

begin_define
define|#
directive|define
name|V_rip6stat
value|rip6stat
end_define

begin_define
define|#
directive|define
name|V_ripcb
value|ripcb
end_define

begin_define
define|#
directive|define
name|V_ripcbinfo
value|ripcbinfo
end_define

begin_define
define|#
directive|define
name|V_router_info_head
value|router_info_head
end_define

begin_define
define|#
directive|define
name|V_rsvp_on
value|rsvp_on
end_define

begin_define
define|#
directive|define
name|V_rt_tables
value|rt_tables
end_define

begin_define
define|#
directive|define
name|V_rtq_minreallyold
value|rtq_minreallyold
end_define

begin_define
define|#
directive|define
name|V_rtq_mtutimer
value|rtq_mtutimer
end_define

begin_define
define|#
directive|define
name|V_rtq_reallyold
value|rtq_reallyold
end_define

begin_define
define|#
directive|define
name|V_rtq_timeout
value|rtq_timeout
end_define

begin_define
define|#
directive|define
name|V_rtq_timeout6
value|rtq_timeout6
end_define

begin_define
define|#
directive|define
name|V_rtq_timer
value|rtq_timer
end_define

begin_define
define|#
directive|define
name|V_rtq_timer6
value|rtq_timer6
end_define

begin_define
define|#
directive|define
name|V_rtq_toomany
value|rtq_toomany
end_define

begin_define
define|#
directive|define
name|V_rtstat
value|rtstat
end_define

begin_define
define|#
directive|define
name|V_rttrash
value|rttrash
end_define

begin_define
define|#
directive|define
name|V_sahtree
value|sahtree
end_define

begin_define
define|#
directive|define
name|V_sameprefixcarponly
value|sameprefixcarponly
end_define

begin_define
define|#
directive|define
name|V_saorder_state_alive
value|saorder_state_alive
end_define

begin_define
define|#
directive|define
name|V_saorder_state_any
value|saorder_state_any
end_define

begin_define
define|#
directive|define
name|V_set_disable
value|set_disable
end_define

begin_define
define|#
directive|define
name|V_sid_default
value|sid_default
end_define

begin_define
define|#
directive|define
name|V_spacqtree
value|spacqtree
end_define

begin_define
define|#
directive|define
name|V_sptree
value|sptree
end_define

begin_define
define|#
directive|define
name|V_ss_fltsz
value|ss_fltsz
end_define

begin_define
define|#
directive|define
name|V_ss_fltsz_local
value|ss_fltsz_local
end_define

begin_define
define|#
directive|define
name|V_static_count
value|static_count
end_define

begin_define
define|#
directive|define
name|V_subnetsarelocal
value|subnetsarelocal
end_define

begin_define
define|#
directive|define
name|V_tcb
value|tcb
end_define

begin_define
define|#
directive|define
name|V_tcbinfo
value|tcbinfo
end_define

begin_define
define|#
directive|define
name|V_tcp_autorcvbuf_inc
value|tcp_autorcvbuf_inc
end_define

begin_define
define|#
directive|define
name|V_tcp_autorcvbuf_max
value|tcp_autorcvbuf_max
end_define

begin_define
define|#
directive|define
name|V_tcp_autosndbuf_inc
value|tcp_autosndbuf_inc
end_define

begin_define
define|#
directive|define
name|V_tcp_autosndbuf_max
value|tcp_autosndbuf_max
end_define

begin_define
define|#
directive|define
name|V_tcp_delack_enabled
value|tcp_delack_enabled
end_define

begin_define
define|#
directive|define
name|V_tcp_do_autorcvbuf
value|tcp_do_autorcvbuf
end_define

begin_define
define|#
directive|define
name|V_tcp_do_autosndbuf
value|tcp_do_autosndbuf
end_define

begin_define
define|#
directive|define
name|V_tcp_do_ecn
value|tcp_do_ecn
end_define

begin_define
define|#
directive|define
name|V_tcp_do_newreno
value|tcp_do_newreno
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc1323
value|tcp_do_rfc1323
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3042
value|tcp_do_rfc3042
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3390
value|tcp_do_rfc3390
end_define

begin_define
define|#
directive|define
name|V_tcp_do_sack
value|tcp_do_sack
end_define

begin_define
define|#
directive|define
name|V_tcp_do_tso
value|tcp_do_tso
end_define

begin_define
define|#
directive|define
name|V_tcp_hc_callout
value|tcp_hc_callout
end_define

begin_define
define|#
directive|define
name|V_tcp_ecn_maxretries
value|tcp_ecn_maxretries
end_define

begin_define
define|#
directive|define
name|V_tcp_hostcache
value|tcp_hostcache
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_enable
value|tcp_inflight_enable
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_max
value|tcp_inflight_max
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_min
value|tcp_inflight_min
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_rttthresh
value|tcp_inflight_rttthresh
end_define

begin_define
define|#
directive|define
name|V_tcp_inflight_stab
value|tcp_inflight_stab
end_define

begin_define
define|#
directive|define
name|V_tcp_insecure_rst
value|tcp_insecure_rst
end_define

begin_define
define|#
directive|define
name|V_tcp_isn_reseed_interval
value|tcp_isn_reseed_interval
end_define

begin_define
define|#
directive|define
name|V_tcp_minmss
value|tcp_minmss
end_define

begin_define
define|#
directive|define
name|V_tcp_mssdflt
value|tcp_mssdflt
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_maxqlen
value|tcp_reass_maxqlen
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_maxseg
value|tcp_reass_maxseg
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_overflows
value|tcp_reass_overflows
end_define

begin_define
define|#
directive|define
name|V_tcp_reass_qsize
value|tcp_reass_qsize
end_define

begin_define
define|#
directive|define
name|V_tcp_sack_globalholes
value|tcp_sack_globalholes
end_define

begin_define
define|#
directive|define
name|V_tcp_sack_globalmaxholes
value|tcp_sack_globalmaxholes
end_define

begin_define
define|#
directive|define
name|V_tcp_sack_maxholes
value|tcp_sack_maxholes
end_define

begin_define
define|#
directive|define
name|V_tcp_sc_rst_sock_fail
value|tcp_sc_rst_sock_fail
end_define

begin_define
define|#
directive|define
name|V_tcp_syncache
value|tcp_syncache
end_define

begin_define
define|#
directive|define
name|V_tcp_v6mssdflt
value|tcp_v6mssdflt
end_define

begin_define
define|#
directive|define
name|V_tcpstat
value|tcpstat
end_define

begin_define
define|#
directive|define
name|V_twq_2msl
value|twq_2msl
end_define

begin_define
define|#
directive|define
name|V_udb
value|udb
end_define

begin_define
define|#
directive|define
name|V_udbinfo
value|udbinfo
end_define

begin_define
define|#
directive|define
name|V_udp_blackhole
value|udp_blackhole
end_define

begin_define
define|#
directive|define
name|V_udp6_recvspace
value|udp6_recvspace
end_define

begin_define
define|#
directive|define
name|V_udp6_sendspace
value|udp6_sendspace
end_define

begin_define
define|#
directive|define
name|V_udpstat
value|udpstat
end_define

begin_define
define|#
directive|define
name|V_useloopback
value|useloopback
end_define

begin_define
define|#
directive|define
name|V_verbose_limit
value|verbose_limit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_VIMAGE_H_ */
end_comment

end_unit

