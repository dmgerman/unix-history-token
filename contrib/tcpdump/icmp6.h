begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/icmp6.h,v 1.4 2000/12/17 23:13:32 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*	$NetBSD: icmp6.h,v 1.13 2000/08/03 16:30:37 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$KAME: icmp6.h,v 1.22 2000/08/03 15:25:16 jinmei Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip_icmp.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_ICMP6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_ICMP6_H_
end_define

begin_struct
struct|struct
name|icmp6_hdr
block|{
name|u_int8_t
name|icmp6_type
decl_stmt|;
comment|/* type field */
name|u_int8_t
name|icmp6_code
decl_stmt|;
comment|/* code field */
name|u_int16_t
name|icmp6_cksum
decl_stmt|;
comment|/* checksum field */
union|union
block|{
name|u_int32_t
name|icmp6_un_data32
index|[
literal|1
index|]
decl_stmt|;
comment|/* type-specific field */
name|u_int16_t
name|icmp6_un_data16
index|[
literal|2
index|]
decl_stmt|;
comment|/* type-specific field */
name|u_int8_t
name|icmp6_un_data8
index|[
literal|4
index|]
decl_stmt|;
comment|/* type-specific field */
block|}
name|icmp6_dataun
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|icmp6_data32
value|icmp6_dataun.icmp6_un_data32
end_define

begin_define
define|#
directive|define
name|icmp6_data16
value|icmp6_dataun.icmp6_un_data16
end_define

begin_define
define|#
directive|define
name|icmp6_data8
value|icmp6_dataun.icmp6_un_data8
end_define

begin_define
define|#
directive|define
name|icmp6_pptr
value|icmp6_data32[0]
end_define

begin_comment
comment|/* parameter prob */
end_comment

begin_define
define|#
directive|define
name|icmp6_mtu
value|icmp6_data32[0]
end_define

begin_comment
comment|/* packet too big */
end_comment

begin_define
define|#
directive|define
name|icmp6_id
value|icmp6_data16[0]
end_define

begin_comment
comment|/* echo request/reply */
end_comment

begin_define
define|#
directive|define
name|icmp6_seq
value|icmp6_data16[1]
end_define

begin_comment
comment|/* echo request/reply */
end_comment

begin_define
define|#
directive|define
name|icmp6_maxdelay
value|icmp6_data16[0]
end_define

begin_comment
comment|/* mcast group membership */
end_comment

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH
value|1
end_define

begin_comment
comment|/* dest unreachable, codes: */
end_comment

begin_define
define|#
directive|define
name|ICMP6_PACKET_TOO_BIG
value|2
end_define

begin_comment
comment|/* packet too big */
end_comment

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEEDED
value|3
end_define

begin_comment
comment|/* time exceeded, code: */
end_comment

begin_define
define|#
directive|define
name|ICMP6_PARAM_PROB
value|4
end_define

begin_comment
comment|/* ip6 header bad */
end_comment

begin_define
define|#
directive|define
name|ICMP6_ECHO_REQUEST
value|128
end_define

begin_comment
comment|/* echo service */
end_comment

begin_define
define|#
directive|define
name|ICMP6_ECHO_REPLY
value|129
end_define

begin_comment
comment|/* echo reply */
end_comment

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_QUERY
value|130
end_define

begin_comment
comment|/* group membership query */
end_comment

begin_define
define|#
directive|define
name|MLD6_LISTENER_QUERY
value|130
end_define

begin_comment
comment|/* multicast listener query */
end_comment

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_REPORT
value|131
end_define

begin_comment
comment|/* group membership report */
end_comment

begin_define
define|#
directive|define
name|MLD6_LISTENER_REPORT
value|131
end_define

begin_comment
comment|/* multicast listener report */
end_comment

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_REDUCTION
value|132
end_define

begin_comment
comment|/* group membership termination */
end_comment

begin_define
define|#
directive|define
name|MLD6_LISTENER_DONE
value|132
end_define

begin_comment
comment|/* multicast listener done */
end_comment

begin_define
define|#
directive|define
name|ND_ROUTER_SOLICIT
value|133
end_define

begin_comment
comment|/* router solicitation */
end_comment

begin_define
define|#
directive|define
name|ND_ROUTER_ADVERT
value|134
end_define

begin_comment
comment|/* router advertisment */
end_comment

begin_define
define|#
directive|define
name|ND_NEIGHBOR_SOLICIT
value|135
end_define

begin_comment
comment|/* neighbor solicitation */
end_comment

begin_define
define|#
directive|define
name|ND_NEIGHBOR_ADVERT
value|136
end_define

begin_comment
comment|/* neighbor advertisment */
end_comment

begin_define
define|#
directive|define
name|ND_REDIRECT
value|137
end_define

begin_comment
comment|/* redirect */
end_comment

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING
value|138
end_define

begin_comment
comment|/* router renumbering */
end_comment

begin_define
define|#
directive|define
name|ICMP6_WRUREQUEST
value|139
end_define

begin_comment
comment|/* who are you request */
end_comment

begin_define
define|#
directive|define
name|ICMP6_WRUREPLY
value|140
end_define

begin_comment
comment|/* who are you reply */
end_comment

begin_define
define|#
directive|define
name|ICMP6_FQDN_QUERY
value|139
end_define

begin_comment
comment|/* FQDN query */
end_comment

begin_define
define|#
directive|define
name|ICMP6_FQDN_REPLY
value|140
end_define

begin_comment
comment|/* FQDN reply */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_QUERY
value|139
end_define

begin_comment
comment|/* node information request */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_REPLY
value|140
end_define

begin_comment
comment|/* node information reply */
end_comment

begin_comment
comment|/* The definitions below are experimental. TBA */
end_comment

begin_define
define|#
directive|define
name|MLD6_MTRACE_RESP
value|141
end_define

begin_comment
comment|/* mtrace response(to sender) */
end_comment

begin_define
define|#
directive|define
name|MLD6_MTRACE
value|142
end_define

begin_comment
comment|/* mtrace messages */
end_comment

begin_define
define|#
directive|define
name|ICMP6_MAXTYPE
value|142
end_define

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOROUTE
value|0
end_define

begin_comment
comment|/* no route to destination */
end_comment

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_ADMIN
value|1
end_define

begin_comment
comment|/* administratively prohibited */
end_comment

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOTNEIGHBOR
value|2
end_define

begin_comment
comment|/* not a neighbor(obsolete) */
end_comment

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_BEYONDSCOPE
value|2
end_define

begin_comment
comment|/* beyond scope of source address */
end_comment

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_ADDR
value|3
end_define

begin_comment
comment|/* address unreachable */
end_comment

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOPORT
value|4
end_define

begin_comment
comment|/* port unreachable */
end_comment

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEED_TRANSIT
value|0
end_define

begin_comment
comment|/* ttl==0 in transit */
end_comment

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEED_REASSEMBLY
value|1
end_define

begin_comment
comment|/* ttl==0 in reass */
end_comment

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_HEADER
value|0
end_define

begin_comment
comment|/* erroneous header field */
end_comment

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_NEXTHEADER
value|1
end_define

begin_comment
comment|/* unrecognized next header */
end_comment

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_OPTION
value|2
end_define

begin_comment
comment|/* unrecognized option */
end_comment

begin_define
define|#
directive|define
name|ICMP6_INFOMSG_MASK
value|0x80
end_define

begin_comment
comment|/* all informational messages */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_IPV6
value|0
end_define

begin_comment
comment|/* Query Subject is an IPv6 address */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_FQDN
value|1
end_define

begin_comment
comment|/* Query Subject is a Domain name */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_IPV4
value|2
end_define

begin_comment
comment|/* Query Subject is an IPv4 address */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_SUCCESS
value|0
end_define

begin_comment
comment|/* node information successful reply */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_REFUSED
value|1
end_define

begin_comment
comment|/* node information request is refused */
end_comment

begin_define
define|#
directive|define
name|ICMP6_NI_UNKNOWN
value|2
end_define

begin_comment
comment|/* unknown Qtype */
end_comment

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_COMMAND
value|0
end_define

begin_comment
comment|/* rr command */
end_comment

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_RESULT
value|1
end_define

begin_comment
comment|/* rr result */
end_comment

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET
value|255
end_define

begin_comment
comment|/* rr seq num reset */
end_comment

begin_comment
comment|/* Used in kernel only */
end_comment

begin_define
define|#
directive|define
name|ND_REDIRECT_ONLINK
value|0
end_define

begin_comment
comment|/* redirect to an on-link node */
end_comment

begin_define
define|#
directive|define
name|ND_REDIRECT_ROUTER
value|1
end_define

begin_comment
comment|/* redirect to a better router */
end_comment

begin_comment
comment|/*  * Multicast Listener Discovery  */
end_comment

begin_struct
struct|struct
name|mld6_hdr
block|{
name|struct
name|icmp6_hdr
name|mld6_hdr
decl_stmt|;
name|struct
name|in6_addr
name|mld6_addr
decl_stmt|;
comment|/* multicast address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mld6_type
value|mld6_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|mld6_code
value|mld6_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|mld6_cksum
value|mld6_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|mld6_maxdelay
value|mld6_hdr.icmp6_data16[0]
end_define

begin_define
define|#
directive|define
name|mld6_reserved
value|mld6_hdr.icmp6_data16[1]
end_define

begin_comment
comment|/*  * Neighbor Discovery  */
end_comment

begin_struct
struct|struct
name|nd_router_solicit
block|{
comment|/* router solicitation */
name|struct
name|icmp6_hdr
name|nd_rs_hdr
decl_stmt|;
comment|/* could be followed by options */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nd_rs_type
value|nd_rs_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|nd_rs_code
value|nd_rs_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|nd_rs_cksum
value|nd_rs_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|nd_rs_reserved
value|nd_rs_hdr.icmp6_data32[0]
end_define

begin_struct
struct|struct
name|nd_router_advert
block|{
comment|/* router advertisement */
name|struct
name|icmp6_hdr
name|nd_ra_hdr
decl_stmt|;
name|u_int32_t
name|nd_ra_reachable
decl_stmt|;
comment|/* reachable time */
name|u_int32_t
name|nd_ra_retransmit
decl_stmt|;
comment|/* retransmit timer */
comment|/* could be followed by options */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nd_ra_type
value|nd_ra_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|nd_ra_code
value|nd_ra_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|nd_ra_cksum
value|nd_ra_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|nd_ra_curhoplimit
value|nd_ra_hdr.icmp6_data8[0]
end_define

begin_define
define|#
directive|define
name|nd_ra_flags_reserved
value|nd_ra_hdr.icmp6_data8[1]
end_define

begin_define
define|#
directive|define
name|ND_RA_FLAG_MANAGED
value|0x80
end_define

begin_define
define|#
directive|define
name|ND_RA_FLAG_OTHER
value|0x40
end_define

begin_define
define|#
directive|define
name|nd_ra_router_lifetime
value|nd_ra_hdr.icmp6_data16[1]
end_define

begin_struct
struct|struct
name|nd_neighbor_solicit
block|{
comment|/* neighbor solicitation */
name|struct
name|icmp6_hdr
name|nd_ns_hdr
decl_stmt|;
name|struct
name|in6_addr
name|nd_ns_target
decl_stmt|;
comment|/*target address */
comment|/* could be followed by options */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nd_ns_type
value|nd_ns_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|nd_ns_code
value|nd_ns_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|nd_ns_cksum
value|nd_ns_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|nd_ns_reserved
value|nd_ns_hdr.icmp6_data32[0]
end_define

begin_struct
struct|struct
name|nd_neighbor_advert
block|{
comment|/* neighbor advertisement */
name|struct
name|icmp6_hdr
name|nd_na_hdr
decl_stmt|;
name|struct
name|in6_addr
name|nd_na_target
decl_stmt|;
comment|/* target address */
comment|/* could be followed by options */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nd_na_type
value|nd_na_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|nd_na_code
value|nd_na_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|nd_na_cksum
value|nd_na_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|nd_na_flags_reserved
value|nd_na_hdr.icmp6_data32[0]
end_define

begin_comment
comment|/* netowkr endian */
end_comment

begin_define
define|#
directive|define
name|ND_NA_FLAG_ROUTER
value|((u_int32_t)htonl(0x80000000))
end_define

begin_define
define|#
directive|define
name|ND_NA_FLAG_SOLICITED
value|((u_int32_t)htonl(0x40000000))
end_define

begin_define
define|#
directive|define
name|ND_NA_FLAG_OVERRIDE
value|((u_int32_t)htonl(0x20000000))
end_define

begin_struct
struct|struct
name|nd_redirect
block|{
comment|/* redirect */
name|struct
name|icmp6_hdr
name|nd_rd_hdr
decl_stmt|;
name|struct
name|in6_addr
name|nd_rd_target
decl_stmt|;
comment|/* target address */
name|struct
name|in6_addr
name|nd_rd_dst
decl_stmt|;
comment|/* destination address */
comment|/* could be followed by options */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nd_rd_type
value|nd_rd_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|nd_rd_code
value|nd_rd_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|nd_rd_cksum
value|nd_rd_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|nd_rd_reserved
value|nd_rd_hdr.icmp6_data32[0]
end_define

begin_struct
struct|struct
name|nd_opt_hdr
block|{
comment|/* Neighbor discovery option header */
name|u_int8_t
name|nd_opt_type
decl_stmt|;
name|u_int8_t
name|nd_opt_len
decl_stmt|;
comment|/* followed by option specific data*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ND_OPT_SOURCE_LINKADDR
value|1
end_define

begin_define
define|#
directive|define
name|ND_OPT_TARGET_LINKADDR
value|2
end_define

begin_define
define|#
directive|define
name|ND_OPT_PREFIX_INFORMATION
value|3
end_define

begin_define
define|#
directive|define
name|ND_OPT_REDIRECTED_HEADER
value|4
end_define

begin_define
define|#
directive|define
name|ND_OPT_MTU
value|5
end_define

begin_define
define|#
directive|define
name|ND_OPT_ADVINT
value|7
end_define

begin_struct
struct|struct
name|nd_opt_prefix_info
block|{
comment|/* prefix information */
name|u_int8_t
name|nd_opt_pi_type
decl_stmt|;
name|u_int8_t
name|nd_opt_pi_len
decl_stmt|;
name|u_int8_t
name|nd_opt_pi_prefix_len
decl_stmt|;
name|u_int8_t
name|nd_opt_pi_flags_reserved
decl_stmt|;
name|u_int32_t
name|nd_opt_pi_valid_time
decl_stmt|;
name|u_int32_t
name|nd_opt_pi_preferred_time
decl_stmt|;
name|u_int32_t
name|nd_opt_pi_reserved2
decl_stmt|;
name|struct
name|in6_addr
name|nd_opt_pi_prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ND_OPT_PI_FLAG_ONLINK
value|0x80
end_define

begin_define
define|#
directive|define
name|ND_OPT_PI_FLAG_AUTO
value|0x40
end_define

begin_define
define|#
directive|define
name|ND_OPT_PI_FLAG_ROUTER
value|0x20
end_define

begin_comment
comment|/*2292bis*/
end_comment

begin_struct
struct|struct
name|nd_opt_rd_hdr
block|{
comment|/* redirected header */
name|u_int8_t
name|nd_opt_rh_type
decl_stmt|;
name|u_int8_t
name|nd_opt_rh_len
decl_stmt|;
name|u_int16_t
name|nd_opt_rh_reserved1
decl_stmt|;
name|u_int32_t
name|nd_opt_rh_reserved2
decl_stmt|;
comment|/* followed by IP header and data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nd_opt_mtu
block|{
comment|/* MTU option */
name|u_int8_t
name|nd_opt_mtu_type
decl_stmt|;
name|u_int8_t
name|nd_opt_mtu_len
decl_stmt|;
name|u_int16_t
name|nd_opt_mtu_reserved
decl_stmt|;
name|u_int32_t
name|nd_opt_mtu_mtu
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nd_opt_advint
block|{
comment|/* Advertisement interval option */
name|u_int8_t
name|nd_opt_advint_type
decl_stmt|;
name|u_int8_t
name|nd_opt_advint_len
decl_stmt|;
name|u_int16_t
name|nd_opt_advint_reserved
decl_stmt|;
name|u_int32_t
name|nd_opt_advint_advint
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * icmp6 namelookup  */
end_comment

begin_struct
struct|struct
name|icmp6_namelookup
block|{
name|struct
name|icmp6_hdr
name|icmp6_nl_hdr
decl_stmt|;
name|u_int8_t
name|icmp6_nl_nonce
index|[
literal|8
index|]
decl_stmt|;
name|int32_t
name|icmp6_nl_ttl
decl_stmt|;
if|#
directive|if
literal|0
block|u_int8_t	icmp6_nl_len; 	u_int8_t	icmp6_nl_name[3];
endif|#
directive|endif
comment|/* could be followed by options */
block|}
struct|;
end_struct

begin_comment
comment|/*  * icmp6 node information  */
end_comment

begin_struct
struct|struct
name|icmp6_nodeinfo
block|{
name|struct
name|icmp6_hdr
name|icmp6_ni_hdr
decl_stmt|;
name|u_int8_t
name|icmp6_ni_nonce
index|[
literal|8
index|]
decl_stmt|;
comment|/* could be followed by reply data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ni_type
value|icmp6_ni_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|ni_code
value|icmp6_ni_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|ni_cksum
value|icmp6_ni_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|ni_qtype
value|icmp6_ni_hdr.icmp6_data16[0]
end_define

begin_define
define|#
directive|define
name|ni_flags
value|icmp6_ni_hdr.icmp6_data16[1]
end_define

begin_define
define|#
directive|define
name|NI_QTYPE_NOOP
value|0
end_define

begin_comment
comment|/* NOOP  */
end_comment

begin_define
define|#
directive|define
name|NI_QTYPE_SUPTYPES
value|1
end_define

begin_comment
comment|/* Supported Qtypes */
end_comment

begin_define
define|#
directive|define
name|NI_QTYPE_FQDN
value|2
end_define

begin_comment
comment|/* FQDN (draft 04) */
end_comment

begin_define
define|#
directive|define
name|NI_QTYPE_DNSNAME
value|2
end_define

begin_comment
comment|/* DNS Name */
end_comment

begin_define
define|#
directive|define
name|NI_QTYPE_NODEADDR
value|3
end_define

begin_comment
comment|/* Node Addresses */
end_comment

begin_define
define|#
directive|define
name|NI_QTYPE_IPV4ADDR
value|4
end_define

begin_comment
comment|/* IPv4 Addresses */
end_comment

begin_comment
comment|/* network endian */
end_comment

begin_define
define|#
directive|define
name|NI_SUPTYPE_FLAG_COMPRESS
value|((u_int16_t)htons(0x1))
end_define

begin_define
define|#
directive|define
name|NI_FQDN_FLAG_VALIDTTL
value|((u_int16_t)htons(0x1))
end_define

begin_comment
comment|/* network endian */
end_comment

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_TRUNCATE
value|((u_int16_t)htons(0x1))
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ALL
value|((u_int16_t)htons(0x2))
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_COMPAT
value|((u_int16_t)htons(0x4))
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_LINKLOCAL
value|((u_int16_t)htons(0x8))
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_SITELOCAL
value|((u_int16_t)htons(0x10))
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_GLOBAL
value|((u_int16_t)htons(0x20))
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ANYCAST
value|((u_int16_t)htons(0x40))
end_define

begin_comment
comment|/* just experimental. not in spec */
end_comment

begin_struct
struct|struct
name|ni_reply_fqdn
block|{
name|u_int32_t
name|ni_fqdn_ttl
decl_stmt|;
comment|/* TTL */
name|u_int8_t
name|ni_fqdn_namelen
decl_stmt|;
comment|/* length in octets of the FQDN */
name|u_int8_t
name|ni_fqdn_name
index|[
literal|3
index|]
decl_stmt|;
comment|/* XXX: alignment */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Router Renumbering. as router-renum-08.txt  */
end_comment

begin_struct
struct|struct
name|icmp6_router_renum
block|{
comment|/* router renumbering header */
name|struct
name|icmp6_hdr
name|rr_hdr
decl_stmt|;
name|u_int8_t
name|rr_segnum
decl_stmt|;
name|u_int8_t
name|rr_flags
decl_stmt|;
name|u_int16_t
name|rr_maxdelay
decl_stmt|;
name|u_int32_t
name|rr_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ICMP6_RR_FLAGS_TEST
value|0x80
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_FLAGS_REQRESULT
value|0x40
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_FLAGS_ALLIF
value|0x20
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_FLAGS_SPECSITE
value|0x10
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_FLAGS_PREVDONE
value|0x08
end_define

begin_define
define|#
directive|define
name|rr_type
value|rr_hdr.icmp6_type
end_define

begin_define
define|#
directive|define
name|rr_code
value|rr_hdr.icmp6_code
end_define

begin_define
define|#
directive|define
name|rr_cksum
value|rr_hdr.icmp6_cksum
end_define

begin_define
define|#
directive|define
name|rr_seqnum
value|rr_hdr.icmp6_data32[0]
end_define

begin_struct
struct|struct
name|rr_pco_match
block|{
comment|/* match prefix part */
name|u_int8_t
name|rpm_code
decl_stmt|;
name|u_int8_t
name|rpm_len
decl_stmt|;
name|u_int8_t
name|rpm_ordinal
decl_stmt|;
name|u_int8_t
name|rpm_matchlen
decl_stmt|;
name|u_int8_t
name|rpm_minlen
decl_stmt|;
name|u_int8_t
name|rpm_maxlen
decl_stmt|;
name|u_int16_t
name|rpm_reserved
decl_stmt|;
name|struct
name|in6_addr
name|rpm_prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RPM_PCO_ADD
value|1
end_define

begin_define
define|#
directive|define
name|RPM_PCO_CHANGE
value|2
end_define

begin_define
define|#
directive|define
name|RPM_PCO_SETGLOBAL
value|3
end_define

begin_define
define|#
directive|define
name|RPM_PCO_MAX
value|4
end_define

begin_struct
struct|struct
name|rr_pco_use
block|{
comment|/* use prefix part */
name|u_int8_t
name|rpu_uselen
decl_stmt|;
name|u_int8_t
name|rpu_keeplen
decl_stmt|;
name|u_int8_t
name|rpu_ramask
decl_stmt|;
name|u_int8_t
name|rpu_raflags
decl_stmt|;
name|u_int32_t
name|rpu_vltime
decl_stmt|;
name|u_int32_t
name|rpu_pltime
decl_stmt|;
name|u_int32_t
name|rpu_flags
decl_stmt|;
name|struct
name|in6_addr
name|rpu_prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_RAFLAGS_ONLINK
value|0x80
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_RAFLAGS_AUTO
value|0x40
end_define

begin_comment
comment|/* network endian */
end_comment

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME
value|((u_int32_t)htonl(0x80000000))
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME
value|((u_int32_t)htonl(0x40000000))
end_define

begin_struct
struct|struct
name|rr_result
block|{
comment|/* router renumbering result message */
name|u_int16_t
name|rrr_flags
decl_stmt|;
name|u_int8_t
name|rrr_ordinal
decl_stmt|;
name|u_int8_t
name|rrr_matchedlen
decl_stmt|;
name|u_int32_t
name|rrr_ifid
decl_stmt|;
name|struct
name|in6_addr
name|rrr_prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* network endian */
end_comment

begin_define
define|#
directive|define
name|ICMP6_RR_RESULT_FLAGS_OOB
value|((u_int16_t)htons(0x0002))
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_RESULT_FLAGS_FORBIDDEN
value|((u_int16_t)htons(0x0001))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _NETINET_ICMP6_H_ */
end_comment

end_unit

