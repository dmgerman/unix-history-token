begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_pcb.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_PCB_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_define
define|#
directive|define
name|in6pcb
value|inpcb
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|in6p_sp
value|inp_sp
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_struct_decl
struct_decl|struct
name|inpcbpolicy
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Common structure pcb for internet protocol implementation.  * Here are stored pointers to local and foreign host table  * entries, local and foreign socket numbers, and pointers  * up (to a socket structure) and down (to a protocol-specific)  * control block.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|inpcbhead
argument_list|,
name|inpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|inpcbporthead
argument_list|,
name|inpcbport
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|u_quad_t
name|inp_gen_t
typedef|;
end_typedef

begin_comment
comment|/*  * PCB with AF_INET6 null bind'ed laddr can receive AF_INET input packet.  * So, AF_INET6 null laddr is also used as AF_INET null laddr,  * by utilize following structure. (At last, same as INRIA)  */
end_comment

begin_struct
struct|struct
name|in_addr_4in6
block|{
name|u_int32_t
name|ia46_pad32
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|in_addr
name|ia46_addr4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE: ipv6 addrs should be 64-bit aligned, per RFC 2553.  * in_conninfo has some extra padding to accomplish this.  */
end_comment

begin_struct
struct|struct
name|in_endpoints
block|{
name|u_int16_t
name|ie_fport
decl_stmt|;
comment|/* foreign port */
name|u_int16_t
name|ie_lport
decl_stmt|;
comment|/* local port */
comment|/* protocol dependent part, local and foreign addr */
union|union
block|{
comment|/* foreign host table entry */
name|struct
name|in_addr_4in6
name|ie46_foreign
decl_stmt|;
name|struct
name|in6_addr
name|ie6_foreign
decl_stmt|;
block|}
name|ie_dependfaddr
union|;
union|union
block|{
comment|/* local host table entry */
name|struct
name|in_addr_4in6
name|ie46_local
decl_stmt|;
name|struct
name|in6_addr
name|ie6_local
decl_stmt|;
block|}
name|ie_dependladdr
union|;
define|#
directive|define
name|ie_faddr
value|ie_dependfaddr.ie46_foreign.ia46_addr4
define|#
directive|define
name|ie_laddr
value|ie_dependladdr.ie46_local.ia46_addr4
define|#
directive|define
name|ie6_faddr
value|ie_dependfaddr.ie6_foreign
define|#
directive|define
name|ie6_laddr
value|ie_dependladdr.ie6_local
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX  * At some point struct route should possibly change to:  *   struct rtentry *rt  *   struct in_endpoints *ie;   */
end_comment

begin_struct
struct|struct
name|in_conninfo
block|{
name|u_int8_t
name|inc_flags
decl_stmt|;
name|u_int8_t
name|inc_len
decl_stmt|;
name|u_int16_t
name|inc_pad
decl_stmt|;
comment|/* XXX alignment for in_endpoints */
comment|/* protocol dependent part; cached route */
name|struct
name|in_endpoints
name|inc_ie
decl_stmt|;
union|union
block|{
comment|/* placeholder for routing entry */
name|struct
name|route
name|inc4_route
decl_stmt|;
name|struct
name|route_in6
name|inc6_route
decl_stmt|;
block|}
name|inc_dependroute
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|inc_isipv6
value|inc_flags
end_define

begin_comment
comment|/* temp compatability */
end_comment

begin_define
define|#
directive|define
name|inc_fport
value|inc_ie.ie_fport
end_define

begin_define
define|#
directive|define
name|inc_lport
value|inc_ie.ie_lport
end_define

begin_define
define|#
directive|define
name|inc_faddr
value|inc_ie.ie_faddr
end_define

begin_define
define|#
directive|define
name|inc_laddr
value|inc_ie.ie_laddr
end_define

begin_define
define|#
directive|define
name|inc_route
value|inc_dependroute.inc4_route
end_define

begin_define
define|#
directive|define
name|inc6_faddr
value|inc_ie.ie6_faddr
end_define

begin_define
define|#
directive|define
name|inc6_laddr
value|inc_ie.ie6_laddr
end_define

begin_define
define|#
directive|define
name|inc6_route
value|inc_dependroute.inc6_route
end_define

begin_comment
comment|/*  * NB: the zone allocator is type-stable EXCEPT FOR THE FIRST TWO LONGS  * of the structure.  Therefore, it is important that the members in  * that position not contain any information which is required to be  * stable.  */
end_comment

begin_struct_decl
struct_decl|struct
name|icmp6_filter
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|inpcb
block|{
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_hash
expr_stmt|;
comment|/* hash list */
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_list
expr_stmt|;
comment|/* list for all PCBs of this proto */
name|u_int32_t
name|inp_flow
decl_stmt|;
comment|/* local and foreign ports, local and foreign addr */
name|struct
name|in_conninfo
name|inp_inc
decl_stmt|;
name|caddr_t
name|inp_ppcb
decl_stmt|;
comment|/* pointer to per-protocol pcb */
name|struct
name|inpcbinfo
modifier|*
name|inp_pcbinfo
decl_stmt|;
comment|/* PCB list info */
name|struct
name|socket
modifier|*
name|inp_socket
decl_stmt|;
comment|/* back pointer to socket */
comment|/* list for this PCB's local port */
name|int
name|inp_flags
decl_stmt|;
comment|/* generic IP/datagram flags */
name|struct
name|inpcbpolicy
modifier|*
name|inp_sp
decl_stmt|;
comment|/* for IPSEC */
name|u_char
name|inp_vflag
decl_stmt|;
define|#
directive|define
name|INP_IPV4
value|0x1
define|#
directive|define
name|INP_IPV6
value|0x2
name|u_char
name|inp_ip_ttl
decl_stmt|;
comment|/* time to live proto */
name|u_char
name|inp_ip_p
decl_stmt|;
comment|/* protocol proto */
comment|/* protocol dependent part; options */
struct|struct
block|{
name|u_char
name|inp4_ip_tos
decl_stmt|;
comment|/* type of service proto */
name|struct
name|mbuf
modifier|*
name|inp4_options
decl_stmt|;
comment|/* IP options */
name|struct
name|ip_moptions
modifier|*
name|inp4_moptions
decl_stmt|;
comment|/* IP multicast options */
block|}
name|inp_depend4
struct|;
define|#
directive|define
name|inp_fport
value|inp_inc.inc_fport
define|#
directive|define
name|inp_lport
value|inp_inc.inc_lport
define|#
directive|define
name|inp_faddr
value|inp_inc.inc_faddr
define|#
directive|define
name|inp_laddr
value|inp_inc.inc_laddr
define|#
directive|define
name|inp_route
value|inp_inc.inc_route
define|#
directive|define
name|inp_ip_tos
value|inp_depend4.inp4_ip_tos
define|#
directive|define
name|inp_options
value|inp_depend4.inp4_options
define|#
directive|define
name|inp_moptions
value|inp_depend4.inp4_moptions
struct|struct
block|{
comment|/* IP options */
name|struct
name|mbuf
modifier|*
name|inp6_options
decl_stmt|;
comment|/* IP6 options for outgoing packets */
name|struct
name|ip6_pktopts
modifier|*
name|inp6_outputopts
decl_stmt|;
comment|/* IP multicast options */
name|struct
name|ip6_moptions
modifier|*
name|inp6_moptions
decl_stmt|;
comment|/* ICMPv6 code type filter */
name|struct
name|icmp6_filter
modifier|*
name|inp6_icmp6filt
decl_stmt|;
comment|/* IPV6_CHECKSUM setsockopt */
name|int
name|inp6_cksum
decl_stmt|;
name|u_short
name|inp6_ifindex
decl_stmt|;
name|short
name|inp6_hops
decl_stmt|;
name|u_int8_t
name|inp6_hlim
decl_stmt|;
block|}
name|inp_depend6
struct|;
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_portlist
expr_stmt|;
name|struct
name|inpcbport
modifier|*
name|inp_phd
decl_stmt|;
comment|/* head of this list */
name|inp_gen_t
name|inp_gencnt
decl_stmt|;
comment|/* generation count of this instance */
define|#
directive|define
name|in6p_faddr
value|inp_inc.inc6_faddr
define|#
directive|define
name|in6p_laddr
value|inp_inc.inc6_laddr
define|#
directive|define
name|in6p_route
value|inp_inc.inc6_route
define|#
directive|define
name|in6p_ip6_hlim
value|inp_depend6.inp6_hlim
define|#
directive|define
name|in6p_hops
value|inp_depend6.inp6_hops
comment|/* default hop limit */
define|#
directive|define
name|in6p_ip6_nxt
value|inp_ip_p
define|#
directive|define
name|in6p_flowinfo
value|inp_flow
define|#
directive|define
name|in6p_vflag
value|inp_vflag
define|#
directive|define
name|in6p_options
value|inp_depend6.inp6_options
define|#
directive|define
name|in6p_outputopts
value|inp_depend6.inp6_outputopts
define|#
directive|define
name|in6p_moptions
value|inp_depend6.inp6_moptions
define|#
directive|define
name|in6p_icmp6filt
value|inp_depend6.inp6_icmp6filt
define|#
directive|define
name|in6p_cksum
value|inp_depend6.inp6_cksum
define|#
directive|define
name|inp6_ifindex
value|inp_depend6.inp6_ifindex
define|#
directive|define
name|in6p_flags
value|inp_flags
comment|/* for KAME src sync over BSD*'s */
define|#
directive|define
name|in6p_socket
value|inp_socket
comment|/* for KAME src sync over BSD*'s */
define|#
directive|define
name|in6p_lport
value|inp_lport
comment|/* for KAME src sync over BSD*'s */
define|#
directive|define
name|in6p_fport
value|inp_fport
comment|/* for KAME src sync over BSD*'s */
define|#
directive|define
name|in6p_ppcb
value|inp_ppcb
comment|/* for KAME src sync over BSD*'s */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The range of the generation count, as used in this implementation,  * is 9e19.  We would have to create 300 billion connections per  * second for this number to roll over in a year.  This seems sufficiently  * unlikely that we simply don't concern ourselves with that possibility.  */
end_comment

begin_comment
comment|/*  * Interface exported to userland by various protocols which use  * inpcbs.  Hack alert -- only define if struct xsocket is in scope.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_SOCKETVAR_H_
end_ifdef

begin_struct
struct|struct
name|xinpcb
block|{
name|size_t
name|xi_len
decl_stmt|;
comment|/* length of this structure */
name|struct
name|inpcb
name|xi_inp
decl_stmt|;
name|struct
name|xsocket
name|xi_socket
decl_stmt|;
name|u_quad_t
name|xi_alignment_hack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xinpgen
block|{
name|size_t
name|xig_len
decl_stmt|;
comment|/* length of this structure */
name|u_int
name|xig_count
decl_stmt|;
comment|/* number of PCBs at this time */
name|inp_gen_t
name|xig_gen
decl_stmt|;
comment|/* generation count at this time */
name|so_gen_t
name|xig_sogen
decl_stmt|;
comment|/* socket generation count at this time */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SOCKETVAR_H_ */
end_comment

begin_struct
struct|struct
name|inpcbport
block|{
name|LIST_ENTRY
argument_list|(
argument|inpcbport
argument_list|)
name|phd_hash
expr_stmt|;
name|struct
name|inpcbhead
name|phd_pcblist
decl_stmt|;
name|u_short
name|phd_port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|inpcbinfo
block|{
comment|/* XXX documentation, prefixes */
name|struct
name|inpcbhead
modifier|*
name|hashbase
decl_stmt|;
name|u_long
name|hashmask
decl_stmt|;
name|struct
name|inpcbporthead
modifier|*
name|porthashbase
decl_stmt|;
name|u_long
name|porthashmask
decl_stmt|;
name|struct
name|inpcbhead
modifier|*
name|listhead
decl_stmt|;
name|u_short
name|lastport
decl_stmt|;
name|u_short
name|lastlow
decl_stmt|;
name|u_short
name|lasthi
decl_stmt|;
name|struct
name|vm_zone
modifier|*
name|ipi_zone
decl_stmt|;
comment|/* zone to allocate pcbs from */
name|u_int
name|ipi_count
decl_stmt|;
comment|/* number of pcbs in this list */
name|u_quad_t
name|ipi_gencnt
decl_stmt|;
comment|/* current generation count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INP_PCBHASH
parameter_list|(
name|faddr
parameter_list|,
name|lport
parameter_list|,
name|fport
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((faddr) ^ ((faddr)>> 16) ^ ntohs((lport) ^ (fport)))& (mask))
end_define

begin_define
define|#
directive|define
name|INP_PCBPORTHASH
parameter_list|(
name|lport
parameter_list|,
name|mask
parameter_list|)
define|\
value|(ntohs((lport))& (mask))
end_define

begin_comment
comment|/* flags in inp_flags: */
end_comment

begin_define
define|#
directive|define
name|INP_RECVOPTS
value|0x01
end_define

begin_comment
comment|/* receive incoming IP options */
end_comment

begin_define
define|#
directive|define
name|INP_RECVRETOPTS
value|0x02
end_define

begin_comment
comment|/* receive IP options for reply */
end_comment

begin_define
define|#
directive|define
name|INP_RECVDSTADDR
value|0x04
end_define

begin_comment
comment|/* receive IP dst address */
end_comment

begin_define
define|#
directive|define
name|INP_HDRINCL
value|0x08
end_define

begin_comment
comment|/* user supplies entire IP header */
end_comment

begin_define
define|#
directive|define
name|INP_HIGHPORT
value|0x10
end_define

begin_comment
comment|/* user wants "high" port binding */
end_comment

begin_define
define|#
directive|define
name|INP_LOWPORT
value|0x20
end_define

begin_comment
comment|/* user wants "low" port binding */
end_comment

begin_define
define|#
directive|define
name|INP_ANONPORT
value|0x40
end_define

begin_comment
comment|/* port chosen for user */
end_comment

begin_define
define|#
directive|define
name|INP_RECVIF
value|0x80
end_define

begin_comment
comment|/* receive incoming interface */
end_comment

begin_define
define|#
directive|define
name|INP_MTUDISC
value|0x100
end_define

begin_comment
comment|/* user can do MTU discovery */
end_comment

begin_define
define|#
directive|define
name|INP_FAITH
value|0x200
end_define

begin_comment
comment|/* accept FAITH'ed connections */
end_comment

begin_define
define|#
directive|define
name|IN6P_IPV6_V6ONLY
value|0x008000
end_define

begin_comment
comment|/* restrict AF_INET6 socket for v6 */
end_comment

begin_define
define|#
directive|define
name|IN6P_PKTINFO
value|0x010000
end_define

begin_comment
comment|/* receive IP6 dst and I/F */
end_comment

begin_define
define|#
directive|define
name|IN6P_HOPLIMIT
value|0x020000
end_define

begin_comment
comment|/* receive hoplimit */
end_comment

begin_define
define|#
directive|define
name|IN6P_HOPOPTS
value|0x040000
end_define

begin_comment
comment|/* receive hop-by-hop options */
end_comment

begin_define
define|#
directive|define
name|IN6P_DSTOPTS
value|0x080000
end_define

begin_comment
comment|/* receive dst options after rthdr */
end_comment

begin_define
define|#
directive|define
name|IN6P_RTHDR
value|0x100000
end_define

begin_comment
comment|/* receive routing header */
end_comment

begin_define
define|#
directive|define
name|IN6P_RTHDRDSTOPTS
value|0x200000
end_define

begin_comment
comment|/* receive dstoptions before rthdr */
end_comment

begin_define
define|#
directive|define
name|IN6P_AUTOFLOWLABEL
value|0x800000
end_define

begin_comment
comment|/* attach flowlabel automatically */
end_comment

begin_define
define|#
directive|define
name|INP_CONTROLOPTS
value|(INP_RECVOPTS|INP_RECVRETOPTS|INP_RECVDSTADDR|\ 					INP_RECVIF|\ 				 IN6P_PKTINFO|IN6P_HOPLIMIT|IN6P_HOPOPTS|\ 				 IN6P_DSTOPTS|IN6P_RTHDR|IN6P_RTHDRDSTOPTS|\ 				 IN6P_AUTOFLOWLABEL)
end_define

begin_define
define|#
directive|define
name|INP_UNMAPPABLEOPTS
value|(IN6P_HOPOPTS|IN6P_DSTOPTS|IN6P_RTHDR|\ 				 IN6P_AUTOFLOWLABEL)
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|IN6P_HIGHPORT
value|INP_HIGHPORT
end_define

begin_define
define|#
directive|define
name|IN6P_LOWPORT
value|INP_LOWPORT
end_define

begin_define
define|#
directive|define
name|IN6P_ANONPORT
value|INP_ANONPORT
end_define

begin_define
define|#
directive|define
name|IN6P_RECVIF
value|INP_RECVIF
end_define

begin_define
define|#
directive|define
name|IN6P_MTUDISC
value|INP_MTUDISC
end_define

begin_define
define|#
directive|define
name|IN6P_FAITH
value|INP_FAITH
end_define

begin_define
define|#
directive|define
name|IN6P_CONTROLOPTS
value|INP_CONTROLOPTS
end_define

begin_comment
comment|/* 	 * socket AF version is {newer than,or include} 	 * actual datagram AF version 	 */
end_comment

begin_define
define|#
directive|define
name|INPLOOKUP_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|sotoinpcb
parameter_list|(
name|so
parameter_list|)
value|((struct inpcb *)(so)->so_pcb)
end_define

begin_define
define|#
directive|define
name|sotoin6pcb
parameter_list|(
name|so
parameter_list|)
value|sotoinpcb(so)
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|INP_SOCKAF
parameter_list|(
name|so
parameter_list|)
value|so->so_proto->pr_domain->dom_family
end_define

begin_define
define|#
directive|define
name|INP_CHECK_SOCKAF
parameter_list|(
name|so
parameter_list|,
name|af
parameter_list|)
value|(INP_SOCKAF(so) == af)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ipport_lowfirstauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipport_lowlastauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipport_firstauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipport_lastauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipport_hifirstauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipport_hilastauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbpurgeif0
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
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
name|in_losing
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
name|void
name|in_rtchange
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_pcballoc
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|inpcbinfo
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
name|in_pcbbind
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|sockaddr
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
name|in_pcbconnect
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|sockaddr
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
name|void
name|in_pcbdetach
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
name|void
name|in_pcbdisconnect
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
name|in_pcbinshash
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
name|in_pcbladdr
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inpcb
modifier|*
name|in_pcblookup_local
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbinfo
operator|*
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inpcb
modifier|*
name|in_pcblookup_hash
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbinfo
operator|*
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
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
name|in_pcbnotifyall
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbhead
operator|*
operator|,
expr|struct
name|in_addr
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|inpcb
operator|*
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbrehash
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
name|in_setpeeraddr
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_setsockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbremlists
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
name|inp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prison_xinpcb
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|inpcb
operator|*
name|inp
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
comment|/* !_NETINET_IN_PCB_H_ */
end_comment

end_unit

