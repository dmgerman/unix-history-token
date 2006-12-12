begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: in6_var.h,v 1.56 2001/03/29 05:34:31 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1985, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_var.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IN6_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IN6_VAR_H_
end_define

begin_comment
comment|/*  * Interface address, Internet version.  One of these structures  * is allocated for each interface with an Internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_comment
comment|/*  * pltime/vltime are just for future reference (required to implements 2  * hour rule for hosts).  they should never be modified by nd6_timeout or  * anywhere else.  *	userland -> kernel: accept pltime/vltime  *	kernel -> userland: throw up everything  *	in kernel: modify preferred/expire only  */
end_comment

begin_struct
struct|struct
name|in6_addrlifetime
block|{
name|time_t
name|ia6t_expire
decl_stmt|;
comment|/* valid lifetime expiration time */
name|time_t
name|ia6t_preferred
decl_stmt|;
comment|/* preferred lifetime expiration time */
name|u_int32_t
name|ia6t_vltime
decl_stmt|;
comment|/* valid lifetime */
name|u_int32_t
name|ia6t_pltime
decl_stmt|;
comment|/* prefix lifetime */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|nd_ifinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scope6_id
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|in6_ifextra
block|{
name|struct
name|in6_ifstat
modifier|*
name|in6_ifstat
decl_stmt|;
name|struct
name|icmp6_ifstat
modifier|*
name|icmp6_ifstat
decl_stmt|;
name|struct
name|nd_ifinfo
modifier|*
name|nd_ifinfo
decl_stmt|;
name|struct
name|scope6_id
modifier|*
name|scope6_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_ifaddr
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
name|struct
name|sockaddr_in6
name|ia_addr
decl_stmt|;
comment|/* interface address */
name|struct
name|sockaddr_in6
name|ia_net
decl_stmt|;
comment|/* network number of interface */
name|struct
name|sockaddr_in6
name|ia_dstaddr
decl_stmt|;
comment|/* space for destination addr */
name|struct
name|sockaddr_in6
name|ia_prefixmask
decl_stmt|;
comment|/* prefix mask */
name|u_int32_t
name|ia_plen
decl_stmt|;
comment|/* prefix length */
name|struct
name|in6_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in6 list of IP6 addresses */
name|int
name|ia6_flags
decl_stmt|;
name|struct
name|in6_addrlifetime
name|ia6_lifetime
decl_stmt|;
name|time_t
name|ia6_createtime
decl_stmt|;
comment|/* the creation time of this address, which is 				 * currently used for temporary addresses only. 				 */
name|time_t
name|ia6_updatetime
decl_stmt|;
comment|/* back pointer to the ND prefix (for autoconfigured addresses only) */
name|struct
name|nd_prefix
modifier|*
name|ia6_ndpr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* control structure to manage address selection policy */
end_comment

begin_struct
struct|struct
name|in6_addrpolicy
block|{
name|struct
name|sockaddr_in6
name|addr
decl_stmt|;
comment|/* prefix address */
name|struct
name|sockaddr_in6
name|addrmask
decl_stmt|;
comment|/* prefix mask */
name|int
name|preced
decl_stmt|;
comment|/* precedence */
name|int
name|label
decl_stmt|;
comment|/* matching label */
name|u_quad_t
name|use
decl_stmt|;
comment|/* statistics */
block|}
struct|;
end_struct

begin_comment
comment|/*  * IPv6 interface statistics, as defined in RFC2465 Ipv6IfStatsEntry (p12).  */
end_comment

begin_struct
struct|struct
name|in6_ifstat
block|{
name|u_quad_t
name|ifs6_in_receive
decl_stmt|;
comment|/* # of total input datagram */
name|u_quad_t
name|ifs6_in_hdrerr
decl_stmt|;
comment|/* # of datagrams with invalid hdr */
name|u_quad_t
name|ifs6_in_toobig
decl_stmt|;
comment|/* # of datagrams exceeded MTU */
name|u_quad_t
name|ifs6_in_noroute
decl_stmt|;
comment|/* # of datagrams with no route */
name|u_quad_t
name|ifs6_in_addrerr
decl_stmt|;
comment|/* # of datagrams with invalid dst */
name|u_quad_t
name|ifs6_in_protounknown
decl_stmt|;
comment|/* # of datagrams with unknown proto */
comment|/* NOTE: increment on final dst if */
name|u_quad_t
name|ifs6_in_truncated
decl_stmt|;
comment|/* # of truncated datagrams */
name|u_quad_t
name|ifs6_in_discard
decl_stmt|;
comment|/* # of discarded datagrams */
comment|/* NOTE: fragment timeout is not here */
name|u_quad_t
name|ifs6_in_deliver
decl_stmt|;
comment|/* # of datagrams delivered to ULP */
comment|/* NOTE: increment on final dst if */
name|u_quad_t
name|ifs6_out_forward
decl_stmt|;
comment|/* # of datagrams forwarded */
comment|/* NOTE: increment on outgoing if */
name|u_quad_t
name|ifs6_out_request
decl_stmt|;
comment|/* # of outgoing datagrams from ULP */
comment|/* NOTE: does not include forwrads */
name|u_quad_t
name|ifs6_out_discard
decl_stmt|;
comment|/* # of discarded datagrams */
name|u_quad_t
name|ifs6_out_fragok
decl_stmt|;
comment|/* # of datagrams fragmented */
name|u_quad_t
name|ifs6_out_fragfail
decl_stmt|;
comment|/* # of datagrams failed on fragment */
name|u_quad_t
name|ifs6_out_fragcreat
decl_stmt|;
comment|/* # of fragment datagrams */
comment|/* NOTE: this is # after fragment */
name|u_quad_t
name|ifs6_reass_reqd
decl_stmt|;
comment|/* # of incoming fragmented packets */
comment|/* NOTE: increment on final dst if */
name|u_quad_t
name|ifs6_reass_ok
decl_stmt|;
comment|/* # of reassembled packets */
comment|/* NOTE: this is # after reass */
comment|/* NOTE: increment on final dst if */
name|u_quad_t
name|ifs6_reass_fail
decl_stmt|;
comment|/* # of reass failures */
comment|/* NOTE: may not be packet count */
comment|/* NOTE: increment on final dst if */
name|u_quad_t
name|ifs6_in_mcast
decl_stmt|;
comment|/* # of inbound multicast datagrams */
name|u_quad_t
name|ifs6_out_mcast
decl_stmt|;
comment|/* # of outbound multicast datagrams */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ICMPv6 interface statistics, as defined in RFC2466 Ipv6IfIcmpEntry.  * XXX: I'm not sure if this file is the right place for this structure...  */
end_comment

begin_struct
struct|struct
name|icmp6_ifstat
block|{
comment|/* 	 * Input statistics 	 */
comment|/* ipv6IfIcmpInMsgs, total # of input messages */
name|u_quad_t
name|ifs6_in_msg
decl_stmt|;
comment|/* ipv6IfIcmpInErrors, # of input error messages */
name|u_quad_t
name|ifs6_in_error
decl_stmt|;
comment|/* ipv6IfIcmpInDestUnreachs, # of input dest unreach errors */
name|u_quad_t
name|ifs6_in_dstunreach
decl_stmt|;
comment|/* ipv6IfIcmpInAdminProhibs, # of input administratively prohibited errs */
name|u_quad_t
name|ifs6_in_adminprohib
decl_stmt|;
comment|/* ipv6IfIcmpInTimeExcds, # of input time exceeded errors */
name|u_quad_t
name|ifs6_in_timeexceed
decl_stmt|;
comment|/* ipv6IfIcmpInParmProblems, # of input parameter problem errors */
name|u_quad_t
name|ifs6_in_paramprob
decl_stmt|;
comment|/* ipv6IfIcmpInPktTooBigs, # of input packet too big errors */
name|u_quad_t
name|ifs6_in_pkttoobig
decl_stmt|;
comment|/* ipv6IfIcmpInEchos, # of input echo requests */
name|u_quad_t
name|ifs6_in_echo
decl_stmt|;
comment|/* ipv6IfIcmpInEchoReplies, # of input echo replies */
name|u_quad_t
name|ifs6_in_echoreply
decl_stmt|;
comment|/* ipv6IfIcmpInRouterSolicits, # of input router solicitations */
name|u_quad_t
name|ifs6_in_routersolicit
decl_stmt|;
comment|/* ipv6IfIcmpInRouterAdvertisements, # of input router advertisements */
name|u_quad_t
name|ifs6_in_routeradvert
decl_stmt|;
comment|/* ipv6IfIcmpInNeighborSolicits, # of input neighbor solicitations */
name|u_quad_t
name|ifs6_in_neighborsolicit
decl_stmt|;
comment|/* ipv6IfIcmpInNeighborAdvertisements, # of input neighbor advertisements */
name|u_quad_t
name|ifs6_in_neighboradvert
decl_stmt|;
comment|/* ipv6IfIcmpInRedirects, # of input redirects */
name|u_quad_t
name|ifs6_in_redirect
decl_stmt|;
comment|/* ipv6IfIcmpInGroupMembQueries, # of input MLD queries */
name|u_quad_t
name|ifs6_in_mldquery
decl_stmt|;
comment|/* ipv6IfIcmpInGroupMembResponses, # of input MLD reports */
name|u_quad_t
name|ifs6_in_mldreport
decl_stmt|;
comment|/* ipv6IfIcmpInGroupMembReductions, # of input MLD done */
name|u_quad_t
name|ifs6_in_mlddone
decl_stmt|;
comment|/* 	 * Output statistics. We should solve unresolved routing problem... 	 */
comment|/* ipv6IfIcmpOutMsgs, total # of output messages */
name|u_quad_t
name|ifs6_out_msg
decl_stmt|;
comment|/* ipv6IfIcmpOutErrors, # of output error messages */
name|u_quad_t
name|ifs6_out_error
decl_stmt|;
comment|/* ipv6IfIcmpOutDestUnreachs, # of output dest unreach errors */
name|u_quad_t
name|ifs6_out_dstunreach
decl_stmt|;
comment|/* ipv6IfIcmpOutAdminProhibs, # of output administratively prohibited errs */
name|u_quad_t
name|ifs6_out_adminprohib
decl_stmt|;
comment|/* ipv6IfIcmpOutTimeExcds, # of output time exceeded errors */
name|u_quad_t
name|ifs6_out_timeexceed
decl_stmt|;
comment|/* ipv6IfIcmpOutParmProblems, # of output parameter problem errors */
name|u_quad_t
name|ifs6_out_paramprob
decl_stmt|;
comment|/* ipv6IfIcmpOutPktTooBigs, # of output packet too big errors */
name|u_quad_t
name|ifs6_out_pkttoobig
decl_stmt|;
comment|/* ipv6IfIcmpOutEchos, # of output echo requests */
name|u_quad_t
name|ifs6_out_echo
decl_stmt|;
comment|/* ipv6IfIcmpOutEchoReplies, # of output echo replies */
name|u_quad_t
name|ifs6_out_echoreply
decl_stmt|;
comment|/* ipv6IfIcmpOutRouterSolicits, # of output router solicitations */
name|u_quad_t
name|ifs6_out_routersolicit
decl_stmt|;
comment|/* ipv6IfIcmpOutRouterAdvertisements, # of output router advertisements */
name|u_quad_t
name|ifs6_out_routeradvert
decl_stmt|;
comment|/* ipv6IfIcmpOutNeighborSolicits, # of output neighbor solicitations */
name|u_quad_t
name|ifs6_out_neighborsolicit
decl_stmt|;
comment|/* ipv6IfIcmpOutNeighborAdvertisements, # of output neighbor advertisements */
name|u_quad_t
name|ifs6_out_neighboradvert
decl_stmt|;
comment|/* ipv6IfIcmpOutRedirects, # of output redirects */
name|u_quad_t
name|ifs6_out_redirect
decl_stmt|;
comment|/* ipv6IfIcmpOutGroupMembQueries, # of output MLD queries */
name|u_quad_t
name|ifs6_out_mldquery
decl_stmt|;
comment|/* ipv6IfIcmpOutGroupMembResponses, # of output MLD reports */
name|u_quad_t
name|ifs6_out_mldreport
decl_stmt|;
comment|/* ipv6IfIcmpOutGroupMembReductions, # of output MLD done */
name|u_quad_t
name|ifs6_out_mlddone
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_ifreq
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
union|union
block|{
name|struct
name|sockaddr_in6
name|ifru_addr
decl_stmt|;
name|struct
name|sockaddr_in6
name|ifru_dstaddr
decl_stmt|;
name|int
name|ifru_flags
decl_stmt|;
name|int
name|ifru_flags6
decl_stmt|;
name|int
name|ifru_metric
decl_stmt|;
name|caddr_t
name|ifru_data
decl_stmt|;
name|struct
name|in6_addrlifetime
name|ifru_lifetime
decl_stmt|;
name|struct
name|in6_ifstat
name|ifru_stat
decl_stmt|;
name|struct
name|icmp6_ifstat
name|ifru_icmp6stat
decl_stmt|;
name|u_int32_t
name|ifru_scope_id
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ifr_ifru
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|sockaddr_in6
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_in6
name|ifra_dstaddr
decl_stmt|;
name|struct
name|sockaddr_in6
name|ifra_prefixmask
decl_stmt|;
name|int
name|ifra_flags
decl_stmt|;
name|struct
name|in6_addrlifetime
name|ifra_lifetime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prefix type macro */
end_comment

begin_define
define|#
directive|define
name|IN6_PREFIX_ND
value|1
end_define

begin_define
define|#
directive|define
name|IN6_PREFIX_RR
value|2
end_define

begin_comment
comment|/*  * prefix related flags passed between kernel(NDP related part) and  * user land command(ifconfig) and daemon(rtadvd).  */
end_comment

begin_struct
struct|struct
name|in6_prflags
block|{
struct|struct
name|prf_ra
block|{
name|u_char
name|onlink
range|:
literal|1
decl_stmt|;
name|u_char
name|autonomous
range|:
literal|1
decl_stmt|;
name|u_char
name|reserved
range|:
literal|6
decl_stmt|;
block|}
name|prf_ra
struct|;
name|u_char
name|prf_reserved1
decl_stmt|;
name|u_short
name|prf_reserved2
decl_stmt|;
comment|/* want to put this on 4byte offset */
struct|struct
name|prf_rr
block|{
name|u_char
name|decrvalid
range|:
literal|1
decl_stmt|;
name|u_char
name|decrprefd
range|:
literal|1
decl_stmt|;
name|u_char
name|reserved
range|:
literal|6
decl_stmt|;
block|}
name|prf_rr
struct|;
name|u_char
name|prf_reserved3
decl_stmt|;
name|u_short
name|prf_reserved4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_prefixreq
block|{
name|char
name|ipr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_char
name|ipr_origin
decl_stmt|;
name|u_char
name|ipr_plen
decl_stmt|;
name|u_int32_t
name|ipr_vltime
decl_stmt|;
name|u_int32_t
name|ipr_pltime
decl_stmt|;
name|struct
name|in6_prflags
name|ipr_flags
decl_stmt|;
name|struct
name|sockaddr_in6
name|ipr_prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PR_ORIG_RA
value|0
end_define

begin_define
define|#
directive|define
name|PR_ORIG_RR
value|1
end_define

begin_define
define|#
directive|define
name|PR_ORIG_STATIC
value|2
end_define

begin_define
define|#
directive|define
name|PR_ORIG_KERNEL
value|3
end_define

begin_define
define|#
directive|define
name|ipr_raf_onlink
value|ipr_flags.prf_ra.onlink
end_define

begin_define
define|#
directive|define
name|ipr_raf_auto
value|ipr_flags.prf_ra.autonomous
end_define

begin_define
define|#
directive|define
name|ipr_statef_onlink
value|ipr_flags.prf_state.onlink
end_define

begin_define
define|#
directive|define
name|ipr_rrf_decrvalid
value|ipr_flags.prf_rr.decrvalid
end_define

begin_define
define|#
directive|define
name|ipr_rrf_decrprefd
value|ipr_flags.prf_rr.decrprefd
end_define

begin_struct
struct|struct
name|in6_rrenumreq
block|{
name|char
name|irr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_char
name|irr_origin
decl_stmt|;
name|u_char
name|irr_m_len
decl_stmt|;
comment|/* match len for matchprefix */
name|u_char
name|irr_m_minlen
decl_stmt|;
comment|/* minlen for matching prefix */
name|u_char
name|irr_m_maxlen
decl_stmt|;
comment|/* maxlen for matching prefix */
name|u_char
name|irr_u_uselen
decl_stmt|;
comment|/* uselen for adding prefix */
name|u_char
name|irr_u_keeplen
decl_stmt|;
comment|/* keeplen from matching prefix */
struct|struct
name|irr_raflagmask
block|{
name|u_char
name|onlink
range|:
literal|1
decl_stmt|;
name|u_char
name|autonomous
range|:
literal|1
decl_stmt|;
name|u_char
name|reserved
range|:
literal|6
decl_stmt|;
block|}
name|irr_raflagmask
struct|;
name|u_int32_t
name|irr_vltime
decl_stmt|;
name|u_int32_t
name|irr_pltime
decl_stmt|;
name|struct
name|in6_prflags
name|irr_flags
decl_stmt|;
name|struct
name|sockaddr_in6
name|irr_matchprefix
decl_stmt|;
name|struct
name|sockaddr_in6
name|irr_useprefix
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|irr_raf_mask_onlink
value|irr_raflagmask.onlink
end_define

begin_define
define|#
directive|define
name|irr_raf_mask_auto
value|irr_raflagmask.autonomous
end_define

begin_define
define|#
directive|define
name|irr_raf_mask_reserved
value|irr_raflagmask.reserved
end_define

begin_define
define|#
directive|define
name|irr_raf_onlink
value|irr_flags.prf_ra.onlink
end_define

begin_define
define|#
directive|define
name|irr_raf_auto
value|irr_flags.prf_ra.autonomous
end_define

begin_define
define|#
directive|define
name|irr_statef_onlink
value|irr_flags.prf_state.onlink
end_define

begin_define
define|#
directive|define
name|irr_rrf
value|irr_flags.prf_rr
end_define

begin_define
define|#
directive|define
name|irr_rrf_decrvalid
value|irr_flags.prf_rr.decrvalid
end_define

begin_define
define|#
directive|define
name|irr_rrf_decrprefd
value|irr_flags.prf_rr.decrprefd
end_define

begin_comment
comment|/*  * Given a pointer to an in6_ifaddr (ifaddr),  * return a pointer to the addr as a sockaddr_in6  */
end_comment

begin_define
define|#
directive|define
name|IA6_IN6
parameter_list|(
name|ia
parameter_list|)
value|(&((ia)->ia_addr.sin6_addr))
end_define

begin_define
define|#
directive|define
name|IA6_DSTIN6
parameter_list|(
name|ia
parameter_list|)
value|(&((ia)->ia_dstaddr.sin6_addr))
end_define

begin_define
define|#
directive|define
name|IA6_MASKIN6
parameter_list|(
name|ia
parameter_list|)
value|(&((ia)->ia_prefixmask.sin6_addr))
end_define

begin_define
define|#
directive|define
name|IA6_SIN6
parameter_list|(
name|ia
parameter_list|)
value|(&((ia)->ia_addr))
end_define

begin_define
define|#
directive|define
name|IA6_DSTSIN6
parameter_list|(
name|ia
parameter_list|)
value|(&((ia)->ia_dstaddr))
end_define

begin_define
define|#
directive|define
name|IFA_IN6
parameter_list|(
name|x
parameter_list|)
value|(&((struct sockaddr_in6 *)((x)->ifa_addr))->sin6_addr)
end_define

begin_define
define|#
directive|define
name|IFA_DSTIN6
parameter_list|(
name|x
parameter_list|)
value|(&((struct sockaddr_in6 *)((x)->ifa_dstaddr))->sin6_addr)
end_define

begin_define
define|#
directive|define
name|IFPR_IN6
parameter_list|(
name|x
parameter_list|)
value|(&((struct sockaddr_in6 *)((x)->ifpr_prefix))->sin6_addr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IN6_ARE_MASKED_ADDR_EQUAL
parameter_list|(
name|d
parameter_list|,
name|a
parameter_list|,
name|m
parameter_list|)
value|(	\ 	(((d)->s6_addr32[0] ^ (a)->s6_addr32[0])& (m)->s6_addr32[0]) == 0&& \ 	(((d)->s6_addr32[1] ^ (a)->s6_addr32[1])& (m)->s6_addr32[1]) == 0&& \ 	(((d)->s6_addr32[2] ^ (a)->s6_addr32[2])& (m)->s6_addr32[2]) == 0&& \ 	(((d)->s6_addr32[3] ^ (a)->s6_addr32[3])& (m)->s6_addr32[3]) == 0 )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCSIFADDR_IN6
value|_IOW('i', 12, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFADDR_IN6
value|_IOWR('i', 33, struct in6_ifreq)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * SIOCSxxx ioctls should be unused (see comments in in6.c), but  * we do not shift numbers for binary compatibility.  */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFDSTADDR_IN6
value|_IOW('i', 14, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCSIFNETMASK_IN6
value|_IOW('i', 22, struct in6_ifreq)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCGIFDSTADDR_IN6
value|_IOWR('i', 34, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFNETMASK_IN6
value|_IOWR('i', 37, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCDIFADDR_IN6
value|_IOW('i', 25, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCAIFADDR_IN6
value|_IOW('i', 26, struct in6_aliasreq)
end_define

begin_define
define|#
directive|define
name|SIOCSIFPHYADDR_IN6
value|_IOW('i', 70, struct in6_aliasreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFPSRCADDR_IN6
value|_IOWR('i', 71, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFPDSTADDR_IN6
value|_IOWR('i', 72, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFAFLAG_IN6
value|_IOWR('i', 73, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGDRLST_IN6
value|_IOWR('i', 74, struct in6_drlist)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* XXX: SIOCGPRLST_IN6 is exposed in KAME but in6_oprlist is not. */
end_comment

begin_define
define|#
directive|define
name|SIOCGPRLST_IN6
value|_IOWR('i', 75, struct in6_oprlist)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|OSIOCGIFINFO_IN6
value|_IOWR('i', 76, struct in6_ondireq)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCGIFINFO_IN6
value|_IOWR('i', 108, struct in6_ndireq)
end_define

begin_define
define|#
directive|define
name|SIOCSIFINFO_IN6
value|_IOWR('i', 109, struct in6_ndireq)
end_define

begin_define
define|#
directive|define
name|SIOCSNDFLUSH_IN6
value|_IOWR('i', 77, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGNBRINFO_IN6
value|_IOWR('i', 78, struct in6_nbrinfo)
end_define

begin_define
define|#
directive|define
name|SIOCSPFXFLUSH_IN6
value|_IOWR('i', 79, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCSRTRFLUSH_IN6
value|_IOWR('i', 80, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFALIFETIME_IN6
value|_IOWR('i', 81, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCSIFALIFETIME_IN6
value|_IOWR('i', 82, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFSTAT_IN6
value|_IOWR('i', 83, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGIFSTAT_ICMP6
value|_IOWR('i', 84, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCSDEFIFACE_IN6
value|_IOWR('i', 85, struct in6_ndifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGDEFIFACE_IN6
value|_IOWR('i', 86, struct in6_ndifreq)
end_define

begin_define
define|#
directive|define
name|SIOCSIFINFO_FLAGS
value|_IOWR('i', 87, struct in6_ndireq)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|SIOCSSCOPE6
value|_IOW('i', 88, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGSCOPE6
value|_IOWR('i', 89, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGSCOPE6DEF
value|_IOWR('i', 90, struct in6_ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCSIFPREFIX_IN6
value|_IOW('i', 100, struct in6_prefixreq)
end_define

begin_comment
comment|/* set */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFPREFIX_IN6
value|_IOWR('i', 101, struct in6_prefixreq)
end_define

begin_comment
comment|/* get */
end_comment

begin_define
define|#
directive|define
name|SIOCDIFPREFIX_IN6
value|_IOW('i', 102, struct in6_prefixreq)
end_define

begin_comment
comment|/* del */
end_comment

begin_define
define|#
directive|define
name|SIOCAIFPREFIX_IN6
value|_IOW('i', 103, struct in6_rrenumreq)
end_define

begin_comment
comment|/* add */
end_comment

begin_define
define|#
directive|define
name|SIOCCIFPREFIX_IN6
value|_IOW('i', 104, \ 				     struct in6_rrenumreq)
end_define

begin_comment
comment|/* change */
end_comment

begin_define
define|#
directive|define
name|SIOCSGIFPREFIX_IN6
value|_IOW('i', 105, \ 				     struct in6_rrenumreq)
end_define

begin_comment
comment|/* set global */
end_comment

begin_define
define|#
directive|define
name|SIOCGETSGCNT_IN6
value|_IOWR('u', 106, \ 				      struct sioc_sg_req6)
end_define

begin_comment
comment|/* get s,g pkt cnt */
end_comment

begin_define
define|#
directive|define
name|SIOCGETMIFCNT_IN6
value|_IOWR('u', 107, \ 				      struct sioc_mif_req6)
end_define

begin_comment
comment|/* get pkt cnt per if */
end_comment

begin_define
define|#
directive|define
name|SIOCAADDRCTL_POLICY
value|_IOW('u', 108, struct in6_addrpolicy)
end_define

begin_define
define|#
directive|define
name|SIOCDADDRCTL_POLICY
value|_IOW('u', 109, struct in6_addrpolicy)
end_define

begin_define
define|#
directive|define
name|IN6_IFF_ANYCAST
value|0x01
end_define

begin_comment
comment|/* anycast address */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_TENTATIVE
value|0x02
end_define

begin_comment
comment|/* tentative address */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_DUPLICATED
value|0x04
end_define

begin_comment
comment|/* DAD detected duplicate */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_DETACHED
value|0x08
end_define

begin_comment
comment|/* may be detached from the link */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_DEPRECATED
value|0x10
end_define

begin_comment
comment|/* deprecated address */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_NODAD
value|0x20
end_define

begin_comment
comment|/* don't perform DAD on this address 					 * (used only at first SIOC* call) 					 */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_AUTOCONF
value|0x40
end_define

begin_comment
comment|/* autoconfigurable address. */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_TEMPORARY
value|0x80
end_define

begin_comment
comment|/* temporary (anonymous) address. */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_NOPFX
value|0x8000
end_define

begin_comment
comment|/* skip kernel prefix management. 					 * XXX: this should be temporary. 					 */
end_comment

begin_comment
comment|/* do not input/output */
end_comment

begin_define
define|#
directive|define
name|IN6_IFF_NOTREADY
value|(IN6_IFF_TENTATIVE|IN6_IFF_DUPLICATED)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IN6_ARE_SCOPE_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)-(b))
end_define

begin_define
define|#
directive|define
name|IN6_ARE_SCOPE_EQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)==(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|in6_ifaddr
modifier|*
name|in6_ifaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|icmp6stat
name|icmp6stat
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|in6_ifstat_inc
parameter_list|(
name|ifp
parameter_list|,
name|tag
parameter_list|)
define|\
value|do {								\ 	if (ifp)						\ 		((struct in6_ifextra *)((ifp)->if_afdata[AF_INET6]))->in6_ifstat->tag++; \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|in6_addr
name|zeroin6_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|inet6ctlerrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|in6_maxmtu
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IP6MADDR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MALLOC_DECLARE */
end_comment

begin_comment
comment|/*  * Macro for finding the internet address structure (in6_ifaddr) corresponding  * to a given interface (ifnet structure).  */
end_comment

begin_define
define|#
directive|define
name|IFP_TO_IA6
parameter_list|(
name|ifp
parameter_list|,
name|ia
parameter_list|)
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in6_ifaddr *ia; */
define|\
value|do {									\ 	struct ifaddr *ifa;						\ 	TAILQ_FOREACH(ifa,&(ifp)->if_addrlist, ifa_list) {		\ 		if (ifa->ifa_addr->sa_family == AF_INET6)		\ 			break;						\ 	}								\ 	(ia) = (struct in6_ifaddr *)ifa;				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Multi-cast membership entry.  One for each group/ifp that a PCB  * belongs to.  */
end_comment

begin_struct
struct|struct
name|in6_multi_mship
block|{
name|struct
name|in6_multi
modifier|*
name|i6mm_maddr
decl_stmt|;
comment|/* Multicast address pointer */
name|LIST_ENTRY
argument_list|(
argument|in6_multi_mship
argument_list|)
name|i6mm_chain
expr_stmt|;
comment|/* multicast options chain */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in6_multi
block|{
name|LIST_ENTRY
argument_list|(
argument|in6_multi
argument_list|)
name|in6m_entry
expr_stmt|;
comment|/* list glue */
name|struct
name|in6_addr
name|in6m_addr
decl_stmt|;
comment|/* IP6 multicast address */
name|struct
name|ifnet
modifier|*
name|in6m_ifp
decl_stmt|;
comment|/* back pointer to ifnet */
name|struct
name|ifmultiaddr
modifier|*
name|in6m_ifma
decl_stmt|;
comment|/* back pointer to ifmultiaddr */
name|u_int
name|in6m_refcount
decl_stmt|;
comment|/* # membership claims by sockets */
name|u_int
name|in6m_state
decl_stmt|;
comment|/* state of the membership */
name|u_int
name|in6m_timer
decl_stmt|;
comment|/* MLD6 listener report timer */
name|struct
name|timeval
name|in6m_timer_expire
decl_stmt|;
comment|/* when the timer expires */
name|struct
name|callout
modifier|*
name|in6m_timer_ch
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IN6M_TIMER_UNDEF
value|-1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* flags to in6_update_ifa */
end_comment

begin_define
define|#
directive|define
name|IN6_IFAUPDATE_DADDELAY
value|0x1
end_define

begin_comment
comment|/* first time to configure an address */
end_comment

begin_extern
extern|extern LIST_HEAD(in6_multihead
operator|,
extern|in6_multi
end_extern

begin_expr_stmt
unit|)
name|in6_multihead
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Structure used by macros below to remember position when stepping through  * all of the in6_multi records.  */
end_comment

begin_struct
struct|struct
name|in6_multistep
block|{
name|struct
name|in6_ifaddr
modifier|*
name|i_ia
decl_stmt|;
name|struct
name|in6_multi
modifier|*
name|i_in6m
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros for looking up the in6_multi record for a given IP6 multicast  * address on a given interface. If no matching record is found, "in6m"  * returns NULL.  */
end_comment

begin_define
define|#
directive|define
name|IN6_LOOKUP_MULTI
parameter_list|(
name|addr
parameter_list|,
name|ifp
parameter_list|,
name|in6m
parameter_list|)
define|\
comment|/* struct in6_addr addr; */
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in6_multi *in6m; */
define|\
value|do { \ 	struct ifmultiaddr *ifma; \ 	IF_ADDR_LOCK(ifp); \ 	TAILQ_FOREACH(ifma,&(ifp)->if_multiaddrs, ifma_link) { \ 		if (ifma->ifma_addr->sa_family == AF_INET6 \&& IN6_ARE_ADDR_EQUAL(&((struct sockaddr_in6 *)ifma->ifma_addr)->sin6_addr, \&(addr))) \ 			break; \ 	} \ 	(in6m) = (struct in6_multi *)(ifma ? ifma->ifma_protospec : 0); \ 	IF_ADDR_UNLOCK(ifp); \ } while(0)
end_define

begin_comment
comment|/*  * Macro to step through all of the in6_multi records, one at a time.  * The current position is remembered in "step", which the caller must  * provide.  IN6_FIRST_MULTI(), below, must be called to initialize "step"  * and get the first record.  Both macros return a NULL "in6m" when there  * are no remaining records.  */
end_comment

begin_define
define|#
directive|define
name|IN6_NEXT_MULTI
parameter_list|(
name|step
parameter_list|,
name|in6m
parameter_list|)
define|\
comment|/* struct in6_multistep step; */
define|\
comment|/* struct in6_multi *in6m; */
define|\
value|do { \ 	if (((in6m) = (step).i_in6m) != NULL) \ 		(step).i_in6m = LIST_NEXT((step).i_in6m, in6m_entry); \ } while(0)
end_define

begin_define
define|#
directive|define
name|IN6_FIRST_MULTI
parameter_list|(
name|step
parameter_list|,
name|in6m
parameter_list|)
define|\
comment|/* struct in6_multistep step; */
define|\
comment|/* struct in6_multi *in6m */
define|\
value|do { \ 	(step).i_in6m = LIST_FIRST(&in6_multihead); \ 		IN6_NEXT_MULTI((step), (in6m)); \ } while(0)
end_define

begin_decl_stmt
name|struct
name|in6_multi
modifier|*
name|in6_addmulti
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
name|in6_delmulti
name|__P
argument_list|(
operator|(
expr|struct
name|in6_multi
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in6_multi_mship
modifier|*
name|in6_joingroup
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in6_leavegroup
parameter_list|(
name|struct
name|in6_multi_mship
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|in6_mask2len
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
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
name|in6_control
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_update_ifa
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|in6_aliasreq
operator|*
operator|,
expr|struct
name|in6_ifaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_purgeaddr
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
name|int
name|in6if_do_dad
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
name|in6_purgeif
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
name|in6_savemkludge
name|__P
argument_list|(
operator|(
expr|struct
name|in6_ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|in6_domifattach
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
name|in6_domifdetach
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_setmaxmtu
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
name|in6_if2idlen
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
name|in6_restoremkludge
name|__P
argument_list|(
operator|(
expr|struct
name|in6_ifaddr
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
name|in6_purgemkludge
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
name|in6_ifaddr
modifier|*
name|in6ifa_ifpforlinklocal
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|in6_ifaddr
modifier|*
name|in6ifa_ifpwithaddr
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ip6_sprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_addr2zoneid
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
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_matchlen
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_are_prefix_equal
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
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
name|void
name|in6_prefixlen2mask
name|__P
argument_list|(
operator|(
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
name|in6_prefix_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
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
name|int
name|in6_prefix_add_ifid
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in6_ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_prefix_remove_ifid
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in6_ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_purgeprefix
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

begin_function_decl
name|void
name|in6_ifremloop
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in6_ifaddloop
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|in6_is_addr_deprecated
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|in6_src_ioctl
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|caddr_t
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
comment|/* _NETINET6_IN6_VAR_H_ */
end_comment

end_unit

