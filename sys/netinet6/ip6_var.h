begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip_var.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IP6_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IP6_VAR_H_
end_define

begin_comment
comment|/*  * IP6 reassembly queue structure.  Each fragment  * being reassembled is attached to one of these structures.  */
end_comment

begin_struct
struct|struct
name|ip6q
block|{
name|u_long
name|ip6q_head
decl_stmt|;
name|u_short
name|ip6q_len
decl_stmt|;
name|u_char
name|ip6q_nxt
decl_stmt|;
name|u_char
name|ip6q_hlim
decl_stmt|;
name|struct
name|ip6asfrag
modifier|*
name|ip6q_down
decl_stmt|;
name|struct
name|ip6asfrag
modifier|*
name|ip6q_up
decl_stmt|;
name|u_long
name|ip6q_ident
decl_stmt|;
name|u_char
name|ip6q_arrive
decl_stmt|;
name|u_char
name|ip6q_ttl
decl_stmt|;
name|struct
name|in6_addr
name|ip6q_src
decl_stmt|,
name|ip6q_dst
decl_stmt|;
name|struct
name|ip6q
modifier|*
name|ip6q_next
decl_stmt|;
name|struct
name|ip6q
modifier|*
name|ip6q_prev
decl_stmt|;
name|int
name|ip6q_unfrglen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ip6asfrag
block|{
name|u_long
name|ip6af_head
decl_stmt|;
name|u_short
name|ip6af_len
decl_stmt|;
name|u_char
name|ip6af_nxt
decl_stmt|;
name|u_char
name|ip6af_hlim
decl_stmt|;
comment|/* must not override the above members during reassembling */
name|struct
name|ip6asfrag
modifier|*
name|ip6af_down
decl_stmt|;
name|struct
name|ip6asfrag
modifier|*
name|ip6af_up
decl_stmt|;
name|u_short
name|ip6af_mff
decl_stmt|;
name|u_short
name|ip6af_off
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ip6af_m
decl_stmt|;
name|u_long
name|ip6af_offset
decl_stmt|;
comment|/* offset where next header starts */
name|u_short
name|ip6af_frglen
decl_stmt|;
comment|/* fragmentable part length */
name|u_char
name|ip6af_x1
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IP6_REASS_MBUF
parameter_list|(
name|ip6af
parameter_list|)
value|(*(struct mbuf **)&((ip6af)->ip6af_m))
end_define

begin_struct
struct|struct
name|ip6_moptions
block|{
name|struct
name|ifnet
modifier|*
name|im6o_multicast_ifp
decl_stmt|;
comment|/* ifp for outgoing multicasts */
name|u_char
name|im6o_multicast_hlim
decl_stmt|;
comment|/* hoplimit for outgoing multicasts */
name|u_char
name|im6o_multicast_loop
decl_stmt|;
comment|/* 1>= hear sends if a member */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|in6_multi_mship
argument_list|)
name|im6o_memberships
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control options for outgoing packets  */
end_comment

begin_comment
comment|/* Routing header related info */
end_comment

begin_struct
struct|struct
name|ip6po_rhinfo
block|{
name|struct
name|ip6_rthdr
modifier|*
name|ip6po_rhi_rthdr
decl_stmt|;
comment|/* Routing header */
name|struct
name|route_in6
name|ip6po_rhi_route
decl_stmt|;
comment|/* Route to the 1st hop */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ip6po_rthdr
value|ip6po_rhinfo.ip6po_rhi_rthdr
end_define

begin_define
define|#
directive|define
name|ip6po_route
value|ip6po_rhinfo.ip6po_rhi_route
end_define

begin_struct
struct|struct
name|ip6_pktopts
block|{
name|struct
name|mbuf
modifier|*
name|ip6po_m
decl_stmt|;
comment|/* Pointer to mbuf storing the data */
name|int
name|ip6po_hlim
decl_stmt|;
comment|/* Hoplimit for outgoing packets */
name|struct
name|in6_pktinfo
modifier|*
name|ip6po_pktinfo
decl_stmt|;
comment|/* Outgoing IF/address information */
name|struct
name|sockaddr
modifier|*
name|ip6po_nexthop
decl_stmt|;
comment|/* Next-hop address */
name|struct
name|ip6_hbh
modifier|*
name|ip6po_hbh
decl_stmt|;
comment|/* Hop-by-Hop options header */
name|struct
name|ip6_dest
modifier|*
name|ip6po_dest1
decl_stmt|;
comment|/* Destination options header(1st part) */
name|struct
name|ip6po_rhinfo
name|ip6po_rhinfo
decl_stmt|;
comment|/* Routing header related info. */
name|struct
name|ip6_dest
modifier|*
name|ip6po_dest2
decl_stmt|;
comment|/* Destination options header(2nd part) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ip6stat
block|{
name|u_long
name|ip6s_total
decl_stmt|;
comment|/* total packets received */
name|u_long
name|ip6s_tooshort
decl_stmt|;
comment|/* packet too short */
name|u_long
name|ip6s_toosmall
decl_stmt|;
comment|/* not enough data */
name|u_long
name|ip6s_fragments
decl_stmt|;
comment|/* fragments received */
name|u_long
name|ip6s_fragdropped
decl_stmt|;
comment|/* frags dropped(dups, out of space) */
name|u_long
name|ip6s_fragtimeout
decl_stmt|;
comment|/* fragments timed out */
name|u_long
name|ip6s_fragoverflow
decl_stmt|;
comment|/* fragments that exceeded limit */
name|u_long
name|ip6s_forward
decl_stmt|;
comment|/* packets forwarded */
name|u_long
name|ip6s_cantforward
decl_stmt|;
comment|/* packets rcvd for unreachable dest */
name|u_long
name|ip6s_redirectsent
decl_stmt|;
comment|/* packets forwarded on same net */
name|u_long
name|ip6s_delivered
decl_stmt|;
comment|/* datagrams delivered to upper level*/
name|u_long
name|ip6s_localout
decl_stmt|;
comment|/* total ip packets generated here */
name|u_long
name|ip6s_odropped
decl_stmt|;
comment|/* lost packets due to nobufs, etc. */
name|u_long
name|ip6s_reassembled
decl_stmt|;
comment|/* total packets reassembled ok */
name|u_long
name|ip6s_fragmented
decl_stmt|;
comment|/* datagrams sucessfully fragmented */
name|u_long
name|ip6s_ofragments
decl_stmt|;
comment|/* output fragments created */
name|u_long
name|ip6s_cantfrag
decl_stmt|;
comment|/* don't fragment flag was set, etc. */
name|u_long
name|ip6s_badoptions
decl_stmt|;
comment|/* error in option processing */
name|u_long
name|ip6s_noroute
decl_stmt|;
comment|/* packets discarded due to no route */
name|u_long
name|ip6s_badvers
decl_stmt|;
comment|/* ip6 version != 6 */
name|u_long
name|ip6s_rawout
decl_stmt|;
comment|/* total raw ip packets generated */
name|u_long
name|ip6s_badscope
decl_stmt|;
comment|/* scope error */
name|u_long
name|ip6s_notmember
decl_stmt|;
comment|/* don't join this multicast group */
name|u_long
name|ip6s_nxthist
index|[
literal|256
index|]
decl_stmt|;
comment|/* next header history */
name|u_long
name|ip6s_m1
decl_stmt|;
comment|/* one mbuf */
name|u_long
name|ip6s_m2m
index|[
literal|32
index|]
decl_stmt|;
comment|/* two or more mbuf */
name|u_long
name|ip6s_mext1
decl_stmt|;
comment|/* one ext mbuf */
name|u_long
name|ip6s_mext2m
decl_stmt|;
comment|/* two or more ext mbuf */
name|u_long
name|ip6s_exthdrtoolong
decl_stmt|;
comment|/* ext hdr are not continuous */
name|u_long
name|ip6s_nogif
decl_stmt|;
comment|/* no match gif found */
name|u_long
name|ip6s_toomanyhdr
decl_stmt|;
comment|/* discarded due to too many headers */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* flags passed to ip6_output as last parameter */
end_comment

begin_define
define|#
directive|define
name|IPV6_DADOUTPUT
value|0x01
end_define

begin_comment
comment|/* DAD */
end_comment

begin_define
define|#
directive|define
name|IPV6_FORWARDING
value|0x02
end_define

begin_comment
comment|/* most of IPv6 header exists */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ip6stat
name|ip6stat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ip6_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fragment identifier */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_defhlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default hop limit */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_defmcasthlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default multicast hop limit */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_forwarding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* act as router? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_forward_srcrt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* forward src-routed? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_gif_hlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hop limit for gif encap packet */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_use_deprecated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow deprecated addr as source */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_rr_prune
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* router renumbering prefix 					 * walk list every 5 sec.    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_mapped_addr_on
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|socket
modifier|*
name|ip6_mrouter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* multicast routing daemon */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_sendredirects
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send IP redirects when forwarding? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_maxfragpackets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum packets in reassembly queue */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_sourcecheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Verify source interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_sourcecheck_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interval between log messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_accept_rtadv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Acts as a host not a router */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_keepfaith
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Firewall Aided Internet Translator */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_log_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|ip6_log_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_hdrnestlimit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* upper limit of # of extension headers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ip6_dad_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DupAddrDetectionTransmits */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ip6_flow_seq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_auto_flowlabel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|rip6_usrreqs
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|icmp6_ctloutput
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|sockopt
operator|*
name|sopt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ip6_init
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
name|ip6intr
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
name|ip6_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ip6_freemoptions
name|__P
argument_list|(
operator|(
expr|struct
name|ip6_moptions
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_unknown_opt
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ip6_get_prevhdr
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_mforward
name|__P
argument_list|(
operator|(
expr|struct
name|ip6_hdr
operator|*
operator|,
expr|struct
name|ifnet
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
name|ip6_process_hopopts
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|int
operator|,
name|u_int32_t
operator|*
operator|,
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ip6_savecontrol
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
expr|struct
name|ip6_hdr
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
name|ip6_sysctl
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ip6_forward
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ip6_mloopback
name|__P
argument_list|(
operator|(
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_output
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|ip6_pktopts
operator|*
operator|,
expr|struct
name|route_in6
operator|*
operator|,
name|int
operator|,
expr|struct
name|ip6_moptions
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_ctloutput
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|sockopt
operator|*
name|sopt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_setpktoptions
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|ip6_pktopts
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_optlen
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|route6_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag6_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|frag6_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag6_slowtimo
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
name|frag6_drain
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
name|rip6_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rip6_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
name|mp
operator|,
name|int
operator|*
name|offp
operator|,
name|int
name|proto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rip6_ctloutput
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockopt
operator|*
name|sopt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rip6_output
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rip6_usrreq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dest6_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|none_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|int
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
comment|/* !_NETINET6_IP6_VAR_H_ */
end_comment

end_unit

