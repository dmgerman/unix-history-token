begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip_var.h	8.2 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Overlay for ip header used by other protocols (tcp, udp).  */
end_comment

begin_struct
struct|struct
name|ipovly
block|{
name|u_char
name|ih_x1
index|[
literal|9
index|]
decl_stmt|;
comment|/* (unused) */
name|u_char
name|ih_pr
decl_stmt|;
comment|/* protocol */
name|u_short
name|ih_len
decl_stmt|;
comment|/* protocol length */
name|struct
name|in_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ih_dst
decl_stmt|;
comment|/* destination internet address */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Ip reassembly queue structure.  Each fragment  * being reassembled is attached to one of these structures.  * They are timed out after ipq_ttl drops to 0, and may also  * be reclaimed if memory becomes tight.  */
end_comment

begin_struct
struct|struct
name|ipq
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ipq
argument_list|)
name|ipq_list
expr_stmt|;
comment|/* to other reass headers */
name|u_char
name|ipq_ttl
decl_stmt|;
comment|/* time for reass q to live */
name|u_char
name|ipq_p
decl_stmt|;
comment|/* protocol of this fragment */
name|u_short
name|ipq_id
decl_stmt|;
comment|/* sequence id for reassembly */
name|struct
name|mbuf
modifier|*
name|ipq_frags
decl_stmt|;
comment|/* to ip headers of fragments */
name|struct
name|in_addr
name|ipq_src
decl_stmt|,
name|ipq_dst
decl_stmt|;
name|u_char
name|ipq_nfrags
decl_stmt|;
comment|/* # frags in this packet */
name|struct
name|label
modifier|*
name|ipq_label
decl_stmt|;
comment|/* MAC label */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Structure stored in mbuf in inpcb.ip_options  * and passed to ip_output when ip options are in use.  * The actual length of the options (including ipopt_dst)  * is in m_len.  */
end_comment

begin_define
define|#
directive|define
name|MAX_IPOPTLEN
value|40
end_define

begin_struct
struct|struct
name|ipoption
block|{
name|struct
name|in_addr
name|ipopt_dst
decl_stmt|;
comment|/* first-hop dst if source routed */
name|char
name|ipopt_list
index|[
name|MAX_IPOPTLEN
index|]
decl_stmt|;
comment|/* options proper */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure attached to inpcb.ip_moptions and  * passed to ip_output when IP multicast options are in use.  * This structure is lazy-allocated.  */
end_comment

begin_struct
struct|struct
name|ip_moptions
block|{
name|struct
name|ifnet
modifier|*
name|imo_multicast_ifp
decl_stmt|;
comment|/* ifp for outgoing multicasts */
name|struct
name|in_addr
name|imo_multicast_addr
decl_stmt|;
comment|/* ifindex/addr on MULTICAST_IF */
name|u_long
name|imo_multicast_vif
decl_stmt|;
comment|/* vif num outgoing multicasts */
name|u_char
name|imo_multicast_ttl
decl_stmt|;
comment|/* TTL for outgoing multicasts */
name|u_char
name|imo_multicast_loop
decl_stmt|;
comment|/* 1 => hear sends if a member */
name|u_short
name|imo_num_memberships
decl_stmt|;
comment|/* no. memberships this socket */
name|u_short
name|imo_max_memberships
decl_stmt|;
comment|/* max memberships this socket */
name|struct
name|in_multi
modifier|*
modifier|*
name|imo_membership
decl_stmt|;
comment|/* group memberships */
name|struct
name|in_mfilter
modifier|*
name|imo_mfilters
decl_stmt|;
comment|/* source filters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipstat
block|{
name|u_long
name|ips_total
decl_stmt|;
comment|/* total packets received */
name|u_long
name|ips_badsum
decl_stmt|;
comment|/* checksum bad */
name|u_long
name|ips_tooshort
decl_stmt|;
comment|/* packet too short */
name|u_long
name|ips_toosmall
decl_stmt|;
comment|/* not enough data */
name|u_long
name|ips_badhlen
decl_stmt|;
comment|/* ip header length< data size */
name|u_long
name|ips_badlen
decl_stmt|;
comment|/* ip length< ip header length */
name|u_long
name|ips_fragments
decl_stmt|;
comment|/* fragments received */
name|u_long
name|ips_fragdropped
decl_stmt|;
comment|/* frags dropped (dups, out of space) */
name|u_long
name|ips_fragtimeout
decl_stmt|;
comment|/* fragments timed out */
name|u_long
name|ips_forward
decl_stmt|;
comment|/* packets forwarded */
name|u_long
name|ips_fastforward
decl_stmt|;
comment|/* packets fast forwarded */
name|u_long
name|ips_cantforward
decl_stmt|;
comment|/* packets rcvd for unreachable dest */
name|u_long
name|ips_redirectsent
decl_stmt|;
comment|/* packets forwarded on same net */
name|u_long
name|ips_noproto
decl_stmt|;
comment|/* unknown or unsupported protocol */
name|u_long
name|ips_delivered
decl_stmt|;
comment|/* datagrams delivered to upper level*/
name|u_long
name|ips_localout
decl_stmt|;
comment|/* total ip packets generated here */
name|u_long
name|ips_odropped
decl_stmt|;
comment|/* lost packets due to nobufs, etc. */
name|u_long
name|ips_reassembled
decl_stmt|;
comment|/* total packets reassembled ok */
name|u_long
name|ips_fragmented
decl_stmt|;
comment|/* datagrams successfully fragmented */
name|u_long
name|ips_ofragments
decl_stmt|;
comment|/* output fragments created */
name|u_long
name|ips_cantfrag
decl_stmt|;
comment|/* don't fragment flag was set, etc. */
name|u_long
name|ips_badoptions
decl_stmt|;
comment|/* error in option processing */
name|u_long
name|ips_noroute
decl_stmt|;
comment|/* packets discarded due to no route */
name|u_long
name|ips_badvers
decl_stmt|;
comment|/* ip version != 4 */
name|u_long
name|ips_rawout
decl_stmt|;
comment|/* total raw ip packets generated */
name|u_long
name|ips_toolong
decl_stmt|;
comment|/* ip length> max ip packet size */
name|u_long
name|ips_notmember
decl_stmt|;
comment|/* multicasts for unregistered grps */
name|u_long
name|ips_nogif
decl_stmt|;
comment|/* no match gif found */
name|u_long
name|ips_badaddr
decl_stmt|;
comment|/* invalid address on header */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_comment
comment|/*  * In-kernel consumers can use these accessor macros directly to update  * stats.  */
end_comment

begin_define
define|#
directive|define
name|IPSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|V_ipstat.name += (val)
end_define

begin_define
define|#
directive|define
name|IPSTAT_SUB
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|V_ipstat.name -= (val)
end_define

begin_define
define|#
directive|define
name|IPSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|IPSTAT_ADD(name, 1)
end_define

begin_define
define|#
directive|define
name|IPSTAT_DEC
parameter_list|(
name|name
parameter_list|)
value|IPSTAT_SUB(name, 1)
end_define

begin_comment
comment|/*  * Kernel module consumers must use this accessor macro.  */
end_comment

begin_function_decl
name|void
name|kmod_ipstat_inc
parameter_list|(
name|int
name|statnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KMOD_IPSTAT_INC
parameter_list|(
name|name
parameter_list|)
define|\
value|kmod_ipstat_inc(offsetof(struct ipstat, name) / sizeof(u_long))
end_define

begin_function_decl
name|void
name|kmod_ipstat_dec
parameter_list|(
name|int
name|statnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KMOD_IPSTAT_DEC
parameter_list|(
name|name
parameter_list|)
define|\
value|kmod_ipstat_dec(offsetof(struct ipstat, name) / sizeof(u_long))
end_define

begin_comment
comment|/* flags passed to ip_output as last parameter */
end_comment

begin_define
define|#
directive|define
name|IP_FORWARDING
value|0x1
end_define

begin_comment
comment|/* most of ip header exists */
end_comment

begin_define
define|#
directive|define
name|IP_RAWOUTPUT
value|0x2
end_define

begin_comment
comment|/* raw ip header exists */
end_comment

begin_define
define|#
directive|define
name|IP_SENDONES
value|0x4
end_define

begin_comment
comment|/* send all-ones broadcast */
end_comment

begin_define
define|#
directive|define
name|IP_SENDTOIF
value|0x8
end_define

begin_comment
comment|/* send on specific ifnet */
end_comment

begin_define
define|#
directive|define
name|IP_ROUTETOIF
value|SO_DONTROUTE
end_define

begin_comment
comment|/* 0x10 bypass routing tables */
end_comment

begin_define
define|#
directive|define
name|IP_ALLOWBROADCAST
value|SO_BROADCAST
end_define

begin_comment
comment|/* 0x20 can send broadcast packets */
end_comment

begin_comment
comment|/*  * mbuf flag used by ip_fastfwd  */
end_comment

begin_define
define|#
directive|define
name|M_FASTFWD_OURS
value|M_PROTO1
end_define

begin_comment
comment|/* changed dst to local */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NO_STRICT_ALIGNMENT
end_ifdef

begin_define
define|#
directive|define
name|IP_HDR_ALIGNED_P
parameter_list|(
name|ip
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IP_HDR_ALIGNED_P
parameter_list|(
name|ip
parameter_list|)
value|((((intptr_t) (ip))& 3) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|ipstat
argument_list|,
name|ipstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_short
argument_list|,
name|ip_id
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ip packet ctr, for ids */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip_defttl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* default IP ttl */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipforwarding
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ip forwarding */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPSTEALTH
end_ifdef

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipstealth
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* stealth forwarding */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|rsvp_on
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|socket
operator|*
argument_list|,
name|ip_rsvpd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reservation protocol daemon*/
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|socket
operator|*
argument_list|,
name|ip_mrouter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* multicast routing daemon */
end_comment

begin_define
define|#
directive|define
name|V_ipstat
value|VNET(ipstat)
end_define

begin_define
define|#
directive|define
name|V_ip_id
value|VNET(ip_id)
end_define

begin_define
define|#
directive|define
name|V_ip_defttl
value|VNET(ip_defttl)
end_define

begin_define
define|#
directive|define
name|V_ipforwarding
value|VNET(ipforwarding)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IPSTEALTH
end_ifdef

begin_define
define|#
directive|define
name|V_ipstealth
value|VNET(ipstealth)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|V_rsvp_on
value|VNET(rsvp_on)
end_define

begin_define
define|#
directive|define
name|V_ip_rsvpd
value|VNET(ip_rsvpd)
end_define

begin_define
define|#
directive|define
name|V_ip_mrouter
value|VNET(ip_mrouter)
end_define

begin_decl_stmt
specifier|extern
name|u_char
name|ip_protox
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|legal_vif_num
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
function_decl|(
modifier|*
name|ip_mcast_src
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|rip_usrreqs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|inp_freemoptions
parameter_list|(
name|struct
name|ip_moptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inp_getmoptions
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inp_setmoptions
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_fini
parameter_list|(
name|void
modifier|*
name|xtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_fragment
parameter_list|(
name|struct
name|ip
modifier|*
name|ip
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m_frag
parameter_list|,
name|int
name|mtu
parameter_list|,
name|u_long
name|if_hwassist_flags
parameter_list|,
name|int
name|sw_csum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_forward
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|srcrt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_mforward
function_decl|)
parameter_list|(
name|struct
name|ip
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
name|ip_moptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ip_moptions
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipproto_register
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipproto_unregister
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ip_reass
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_ifaddr
modifier|*
name|ip_rtaddr
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_int
name|fibnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_savecontrol
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|ip_randomid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rip_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rip_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rip_init
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
name|rip_destroy
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
name|void
name|rip_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rip_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipip_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsvp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_rsvp_init
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_rsvp_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_rsvp_vif
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ip_rsvp_force_done
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|rsvp_input_p
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|pfil_head
argument_list|,
name|inet_pfil_hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* packet filter hooks */
end_comment

begin_define
define|#
directive|define
name|V_inet_pfil_hook
value|VNET(inet_pfil_hook)
end_define

begin_function_decl
name|void
name|in_delayed_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hooks for ipfw, dummynet, divert etc. Most are declared in raw_ip.c */
end_comment

begin_comment
comment|/*  * Reference to an ipfw or packet filter rule that can be carried  * outside critical sections.  * A rule is identified by rulenum:rule_id which is ordered.  * In version chain_id the rule can be found in slot 'slot', so  * we don't need a lookup if chain_id == chain->id.  *  * On exit from the firewall this structure refers to the rule after  * the matching one (slot points to the new rule; rulenum:rule_id-1  * is the matching rule), and additional info (e.g. info often contains  * the insn argument or tablearg in the low 16 bits, in host format).  * On entry, the structure is valid if slot>0, and refers to the starting  * rules. 'info' contains the reason for reinject, e.g. divert port,  * divert direction, and so on.  */
end_comment

begin_struct
struct|struct
name|ipfw_rule_ref
block|{
name|uint32_t
name|slot
decl_stmt|;
comment|/* slot for matching rule	*/
name|uint32_t
name|rulenum
decl_stmt|;
comment|/* matching rule number		*/
name|uint32_t
name|rule_id
decl_stmt|;
comment|/* matching rule id		*/
name|uint32_t
name|chain_id
decl_stmt|;
comment|/* ruleset id			*/
name|uint32_t
name|info
decl_stmt|;
comment|/* see below			*/
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|IPFW_INFO_MASK
init|=
literal|0x0000ffff
block|,
name|IPFW_INFO_OUT
init|=
literal|0x00000000
block|,
comment|/* outgoing, just for convenience */
name|IPFW_INFO_IN
init|=
literal|0x80000000
block|,
comment|/* incoming, overloads dir */
name|IPFW_ONEPASS
init|=
literal|0x40000000
block|,
comment|/* One-pass, do not reinject */
name|IPFW_IS_MASK
init|=
literal|0x30000000
block|,
comment|/* which source ? */
name|IPFW_IS_DIVERT
init|=
literal|0x20000000
block|,
name|IPFW_IS_DUMMYNET
init|=
literal|0x10000000
block|,
name|IPFW_IS_PIPE
init|=
literal|0x08000000
block|,
comment|/* pip1=1, queue = 0 */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MTAG_IPFW
value|1148380143
end_define

begin_comment
comment|/* IPFW-tagged cookie */
end_comment

begin_define
define|#
directive|define
name|MTAG_IPFW_RULE
value|1262273568
end_define

begin_comment
comment|/* rule reference */
end_comment

begin_struct_decl
struct_decl|struct
name|ip_fw_args
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ip_fw_chk_ptr_t
function_decl|)
parameter_list|(
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ip_fw_ctl_ptr_t
function_decl|)
parameter_list|(
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|ip_fw_chk_ptr_t
argument_list|,
name|ip_fw_chk_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|ip_fw_ctl_ptr_t
argument_list|,
name|ip_fw_ctl_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ip_fw_chk_ptr
value|VNET(ip_fw_chk_ptr)
end_define

begin_define
define|#
directive|define
name|V_ip_fw_ctl_ptr
value|VNET(ip_fw_ctl_ptr)
end_define

begin_comment
comment|/* Divert hooks. */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ip_divert_ptr
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|incoming
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ng_ipfw hooks -- XXX make it the same as divert and dummynet */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ng_ipfw_input_p
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_dn_ctl_ptr
function_decl|)
parameter_list|(
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_dn_io_ptr
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip_do_randomid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ip_do_randomid
value|VNET(ip_do_randomid)
end_define

begin_define
define|#
directive|define
name|ip_newid
parameter_list|()
value|((V_ip_do_randomid != 0) ? ip_randomid() : \ 			    htons(V_ip_id++))
end_define

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
comment|/* !_NETINET_IP_VAR_H_ */
end_comment

end_unit

