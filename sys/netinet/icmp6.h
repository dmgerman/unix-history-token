begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: icmp6.h,v 1.46 2001/04/27 15:09:48 itojun Exp $	*/
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

begin_define
define|#
directive|define
name|ICMPV6_PLD_MAXLEN
value|1232
end_define

begin_comment
comment|/* IPV6_MMTU - sizeof(struct ip6_hdr) 					   - sizeof(struct icmp6_hdr) */
end_comment

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
value|200
end_define

begin_comment
comment|/* mtrace response(to sender) */
end_comment

begin_define
define|#
directive|define
name|MLD6_MTRACE
value|201
end_define

begin_comment
comment|/* mtrace messages */
end_comment

begin_define
define|#
directive|define
name|ICMP6_HADISCOV_REQUEST
value|202
end_define

begin_comment
comment|/* XXX To be defined */
end_comment

begin_define
define|#
directive|define
name|ICMP6_HADISCOV_REPLY
value|203
end_define

begin_comment
comment|/* XXX To be defined */
end_comment

begin_define
define|#
directive|define
name|ICMP6_MAXTYPE
value|203
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|ND_RA_FLAG_HA
value|0x20
end_define

begin_comment
comment|/*  * Router preference values based on draft-draves-ipngwg-router-selection-01.  * These are non-standard definitions.  */
end_comment

begin_define
define|#
directive|define
name|ND_RA_FLAG_RTPREF_MASK
value|0x18
end_define

begin_comment
comment|/* 00011000 */
end_comment

begin_define
define|#
directive|define
name|ND_RA_FLAG_RTPREF_HIGH
value|0x08
end_define

begin_comment
comment|/* 00001000 */
end_comment

begin_define
define|#
directive|define
name|ND_RA_FLAG_RTPREF_MEDIUM
value|0x00
end_define

begin_comment
comment|/* 00000000 */
end_comment

begin_define
define|#
directive|define
name|ND_RA_FLAG_RTPREF_LOW
value|0x18
end_define

begin_comment
comment|/* 00011000 */
end_comment

begin_define
define|#
directive|define
name|ND_RA_FLAG_RTPREF_RSV
value|0x10
end_define

begin_comment
comment|/* 00010000 */
end_comment

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|ND_NA_FLAG_ROUTER
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ND_NA_FLAG_SOLICITED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ND_NA_FLAG_OVERRIDE
value|0x20000000
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ND_NA_FLAG_ROUTER
value|0x80
end_define

begin_define
define|#
directive|define
name|ND_NA_FLAG_SOLICITED
value|0x40
end_define

begin_define
define|#
directive|define
name|ND_NA_FLAG_OVERRIDE
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|ND_OPT_ROUTE_INFO
value|200
end_define

begin_comment
comment|/* draft-ietf-ipngwg-router-preference, not officially assigned yet */
end_comment

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|nd_opt_route_info
block|{
comment|/* route info */
name|u_int8_t
name|nd_opt_rti_type
decl_stmt|;
name|u_int8_t
name|nd_opt_rti_len
decl_stmt|;
name|u_int8_t
name|nd_opt_rti_prefixlen
decl_stmt|;
name|u_int8_t
name|nd_opt_rti_flags
decl_stmt|;
name|u_int32_t
name|nd_opt_rti_lifetime
decl_stmt|;
comment|/* followed by prefix */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|NI_SUPTYPE_FLAG_COMPRESS
value|0x1
end_define

begin_define
define|#
directive|define
name|NI_FQDN_FLAG_VALIDTTL
value|0x1
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|NI_SUPTYPE_FLAG_COMPRESS
value|0x0100
end_define

begin_define
define|#
directive|define
name|NI_FQDN_FLAG_VALIDTTL
value|0x0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NAME_LOOKUPS_04
end_ifdef

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_LINKLOCAL
value|0x1
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_SITELOCAL
value|0x2
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_GLOBAL
value|0x4
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ALL
value|0x8
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_TRUNCATE
value|0x10
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ANYCAST
value|0x20
end_define

begin_comment
comment|/* just experimental. not in spec */
end_comment

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_LINKLOCAL
value|0x0100
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_SITELOCAL
value|0x0200
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_GLOBAL
value|0x0400
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ALL
value|0x0800
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_TRUNCATE
value|0x1000
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ANYCAST
value|0x2000
end_define

begin_comment
comment|/* just experimental. not in spec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* draft-ietf-ipngwg-icmp-name-lookups-05 (and later?) */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_TRUNCATE
value|0x1
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ALL
value|0x2
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_COMPAT
value|0x4
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_LINKLOCAL
value|0x8
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_SITELOCAL
value|0x10
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_GLOBAL
value|0x20
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ANYCAST
value|0x40
end_define

begin_comment
comment|/* just experimental. not in spec */
end_comment

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_TRUNCATE
value|0x0100
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ALL
value|0x0200
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_COMPAT
value|0x0400
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_LINKLOCAL
value|0x0800
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_SITELOCAL
value|0x1000
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_GLOBAL
value|0x2000
end_define

begin_define
define|#
directive|define
name|NI_NODEADDR_FLAG_ANYCAST
value|0x4000
end_define

begin_comment
comment|/* just experimental. not in spec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|ICMP6_RR_FLAGS_FORCEAPPLY
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME
value|0x40000000
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME
value|0x80
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|ICMP6_RR_RESULT_FLAGS_OOB
value|0x0002
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_RESULT_FLAGS_FORBIDDEN
value|0x0001
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|ICMP6_RR_RESULT_FLAGS_OOB
value|0x0200
end_define

begin_define
define|#
directive|define
name|ICMP6_RR_RESULT_FLAGS_FORBIDDEN
value|0x0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * icmp6 filter structures.  */
end_comment

begin_struct
struct|struct
name|icmp6_filter
block|{
name|u_int32_t
name|icmp6_filt
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ICMP6_FILTER_SETPASSALL
parameter_list|(
name|filterp
parameter_list|)
define|\
value|do {								\ 	int i; u_char *p;					\ 	p = (u_char *)filterp;					\ 	for (i = 0; i< sizeof(struct icmp6_filter); i++)	\ 		p[i] = 0xff;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ICMP6_FILTER_SETBLOCKALL
parameter_list|(
name|filterp
parameter_list|)
define|\
value|bzero(filterp, sizeof(struct icmp6_filter))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|ICMP6_FILTER_SETPASSALL
parameter_list|(
name|filterp
parameter_list|)
define|\
value|memset(filterp, 0xff, sizeof(struct icmp6_filter))
end_define

begin_define
define|#
directive|define
name|ICMP6_FILTER_SETBLOCKALL
parameter_list|(
name|filterp
parameter_list|)
define|\
value|memset(filterp, 0x00, sizeof(struct icmp6_filter))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|ICMP6_FILTER_SETPASS
parameter_list|(
name|type
parameter_list|,
name|filterp
parameter_list|)
define|\
value|(((filterp)->icmp6_filt[(type)>> 5]) |= (1<< ((type)& 31)))
end_define

begin_define
define|#
directive|define
name|ICMP6_FILTER_SETBLOCK
parameter_list|(
name|type
parameter_list|,
name|filterp
parameter_list|)
define|\
value|(((filterp)->icmp6_filt[(type)>> 5])&= ~(1<< ((type)& 31)))
end_define

begin_define
define|#
directive|define
name|ICMP6_FILTER_WILLPASS
parameter_list|(
name|type
parameter_list|,
name|filterp
parameter_list|)
define|\
value|((((filterp)->icmp6_filt[(type)>> 5])& (1<< ((type)& 31))) != 0)
end_define

begin_define
define|#
directive|define
name|ICMP6_FILTER_WILLBLOCK
parameter_list|(
name|type
parameter_list|,
name|filterp
parameter_list|)
define|\
value|((((filterp)->icmp6_filt[(type)>> 5])& (1<< ((type)& 31))) == 0)
end_define

begin_comment
comment|/*  * Variables related to this implementation  * of the internet control message protocol version 6.  */
end_comment

begin_struct
struct|struct
name|icmp6errstat
block|{
name|u_quad_t
name|icp6errs_dst_unreach_noroute
decl_stmt|;
name|u_quad_t
name|icp6errs_dst_unreach_admin
decl_stmt|;
name|u_quad_t
name|icp6errs_dst_unreach_beyondscope
decl_stmt|;
name|u_quad_t
name|icp6errs_dst_unreach_addr
decl_stmt|;
name|u_quad_t
name|icp6errs_dst_unreach_noport
decl_stmt|;
name|u_quad_t
name|icp6errs_packet_too_big
decl_stmt|;
name|u_quad_t
name|icp6errs_time_exceed_transit
decl_stmt|;
name|u_quad_t
name|icp6errs_time_exceed_reassembly
decl_stmt|;
name|u_quad_t
name|icp6errs_paramprob_header
decl_stmt|;
name|u_quad_t
name|icp6errs_paramprob_nextheader
decl_stmt|;
name|u_quad_t
name|icp6errs_paramprob_option
decl_stmt|;
name|u_quad_t
name|icp6errs_redirect
decl_stmt|;
comment|/* we regard redirect as an error here */
name|u_quad_t
name|icp6errs_unknown
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|icmp6stat
block|{
comment|/* statistics related to icmp6 packets generated */
name|u_quad_t
name|icp6s_error
decl_stmt|;
comment|/* # of calls to icmp6_error */
name|u_quad_t
name|icp6s_canterror
decl_stmt|;
comment|/* no error 'cuz old was icmp */
name|u_quad_t
name|icp6s_toofreq
decl_stmt|;
comment|/* no error 'cuz rate limitation */
name|u_quad_t
name|icp6s_outhist
index|[
literal|256
index|]
decl_stmt|;
comment|/* statistics related to input message processed */
name|u_quad_t
name|icp6s_badcode
decl_stmt|;
comment|/* icmp6_code out of range */
name|u_quad_t
name|icp6s_tooshort
decl_stmt|;
comment|/* packet< sizeof(struct icmp6_hdr) */
name|u_quad_t
name|icp6s_checksum
decl_stmt|;
comment|/* bad checksum */
name|u_quad_t
name|icp6s_badlen
decl_stmt|;
comment|/* calculated bound mismatch */
name|u_quad_t
name|icp6s_reflect
decl_stmt|;
comment|/* number of responses */
name|u_quad_t
name|icp6s_inhist
index|[
literal|256
index|]
decl_stmt|;
name|u_quad_t
name|icp6s_nd_toomanyopt
decl_stmt|;
comment|/* too many ND options */
name|struct
name|icmp6errstat
name|icp6s_outerrhist
decl_stmt|;
define|#
directive|define
name|icp6s_odst_unreach_noroute
define|\
value|icp6s_outerrhist.icp6errs_dst_unreach_noroute
define|#
directive|define
name|icp6s_odst_unreach_admin
value|icp6s_outerrhist.icp6errs_dst_unreach_admin
define|#
directive|define
name|icp6s_odst_unreach_beyondscope
define|\
value|icp6s_outerrhist.icp6errs_dst_unreach_beyondscope
define|#
directive|define
name|icp6s_odst_unreach_addr
value|icp6s_outerrhist.icp6errs_dst_unreach_addr
define|#
directive|define
name|icp6s_odst_unreach_noport
value|icp6s_outerrhist.icp6errs_dst_unreach_noport
define|#
directive|define
name|icp6s_opacket_too_big
value|icp6s_outerrhist.icp6errs_packet_too_big
define|#
directive|define
name|icp6s_otime_exceed_transit
define|\
value|icp6s_outerrhist.icp6errs_time_exceed_transit
define|#
directive|define
name|icp6s_otime_exceed_reassembly
define|\
value|icp6s_outerrhist.icp6errs_time_exceed_reassembly
define|#
directive|define
name|icp6s_oparamprob_header
value|icp6s_outerrhist.icp6errs_paramprob_header
define|#
directive|define
name|icp6s_oparamprob_nextheader
define|\
value|icp6s_outerrhist.icp6errs_paramprob_nextheader
define|#
directive|define
name|icp6s_oparamprob_option
value|icp6s_outerrhist.icp6errs_paramprob_option
define|#
directive|define
name|icp6s_oredirect
value|icp6s_outerrhist.icp6errs_redirect
define|#
directive|define
name|icp6s_ounknown
value|icp6s_outerrhist.icp6errs_unknown
name|u_quad_t
name|icp6s_pmtuchg
decl_stmt|;
comment|/* path MTU changes */
name|u_quad_t
name|icp6s_nd_badopt
decl_stmt|;
comment|/* bad ND options */
name|u_quad_t
name|icp6s_badns
decl_stmt|;
comment|/* bad neighbor solicitation */
name|u_quad_t
name|icp6s_badna
decl_stmt|;
comment|/* bad neighbor advertisement */
name|u_quad_t
name|icp6s_badrs
decl_stmt|;
comment|/* bad router advertisement */
name|u_quad_t
name|icp6s_badra
decl_stmt|;
comment|/* bad router advertisement */
name|u_quad_t
name|icp6s_badredirect
decl_stmt|;
comment|/* bad redirect message */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Names for ICMP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|ICMPV6CTL_STATS
value|1
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_REDIRACCEPT
value|2
end_define

begin_comment
comment|/* accept/process redirects */
end_comment

begin_define
define|#
directive|define
name|ICMPV6CTL_REDIRTIMEOUT
value|3
end_define

begin_comment
comment|/* redirect cache time */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*obsoleted*/
end_comment

begin_define
define|#
directive|define
name|ICMPV6CTL_ERRRATELIMIT
value|5
end_define

begin_comment
comment|/* ICMPv6 error rate limitation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_PRUNE
value|6
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_DELAY
value|8
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_UMAXTRIES
value|9
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_MMAXTRIES
value|10
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_USELOOPBACK
value|11
end_define

begin_comment
comment|/*#define ICMPV6CTL_ND6_PROXYALL	12	obsoleted, do not reuse here */
end_comment

begin_define
define|#
directive|define
name|ICMPV6CTL_NODEINFO
value|13
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ERRPPSLIMIT
value|14
end_define

begin_comment
comment|/* ICMPv6 error pps limitation */
end_comment

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_MAXNUDHINT
value|15
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_MTUDISC_HIWAT
value|16
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_MTUDISC_LOWAT
value|17
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_DEBUG
value|18
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_DRLIST
value|19
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_ND6_PRLIST
value|20
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_MAXID
value|21
end_define

begin_define
define|#
directive|define
name|ICMPV6CTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "rediraccept", CTLTYPE_INT }, \ 	{ "redirtimeout", CTLTYPE_INT }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "nd6_prune", CTLTYPE_INT }, \ 	{ 0, 0 }, \ 	{ "nd6_delay", CTLTYPE_INT }, \ 	{ "nd6_umaxtries", CTLTYPE_INT }, \ 	{ "nd6_mmaxtries", CTLTYPE_INT }, \ 	{ "nd6_useloopback", CTLTYPE_INT }, \ 	{ 0, 0 }, \ 	{ "nodeinfo", CTLTYPE_INT }, \ 	{ "errppslimit", CTLTYPE_INT }, \ 	{ "nd6_maxnudhint", CTLTYPE_INT }, \ 	{ "mtudisc_hiwat", CTLTYPE_INT }, \ 	{ "mtudisc_lowat", CTLTYPE_INT }, \ 	{ "nd6_debug", CTLTYPE_INT }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ }
end_define

begin_define
define|#
directive|define
name|RTF_PROBEMTU
value|RTF_PROTO1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rttimer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|in6_multi
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|icmp6_init
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
name|icmp6_paramerror
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
name|icmp6_error
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
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|icmp6_input
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
name|icmp6_fasttimo
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
name|icmp6_reflect
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|icmp6_prepare
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
name|icmp6_redirect_input
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
name|icmp6_redirect_output
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ip6ctlparam
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|icmp6_mtudisc_update
name|__P
argument_list|(
operator|(
expr|struct
name|ip6ctlparam
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX: is this the right place for these macros? */
end_comment

begin_define
define|#
directive|define
name|icmp6_ifstat_inc
parameter_list|(
name|ifp
parameter_list|,
name|tag
parameter_list|)
define|\
value|do {								\ 	if ((ifp)&& (ifp)->if_index<= if_index			\&& (ifp)->if_index< icmp6_ifstatmax			\&& icmp6_ifstat&& icmp6_ifstat[(ifp)->if_index]) {	\ 		icmp6_ifstat[(ifp)->if_index]->tag++;		\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|icmp6_ifoutstat_inc
parameter_list|(
name|ifp
parameter_list|,
name|type
parameter_list|,
name|code
parameter_list|)
define|\
value|do { \ 		icmp6_ifstat_inc(ifp, ifs6_out_msg); \  		if (type< ICMP6_INFOMSG_MASK) \  			icmp6_ifstat_inc(ifp, ifs6_out_error); \ 		switch(type) { \ 		 case ICMP6_DST_UNREACH: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_dstunreach); \ 			 if (code == ICMP6_DST_UNREACH_ADMIN) \ 				 icmp6_ifstat_inc(ifp, ifs6_out_adminprohib); \ 			 break; \ 		 case ICMP6_PACKET_TOO_BIG: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_pkttoobig); \ 			 break; \ 		 case ICMP6_TIME_EXCEEDED: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_timeexceed); \ 			 break; \ 		 case ICMP6_PARAM_PROB: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_paramprob); \ 			 break; \ 		 case ICMP6_ECHO_REQUEST: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_echo); \ 			 break; \ 		 case ICMP6_ECHO_REPLY: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_echoreply); \ 			 break; \ 		 case MLD6_LISTENER_QUERY: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_mldquery); \ 			 break; \ 		 case MLD6_LISTENER_REPORT: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_mldreport); \ 			 break; \ 		 case MLD6_LISTENER_DONE: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_mlddone); \ 			 break; \ 		 case ND_ROUTER_SOLICIT: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_routersolicit); \ 			 break; \ 		 case ND_ROUTER_ADVERT: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_routeradvert); \ 			 break; \ 		 case ND_NEIGHBOR_SOLICIT: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_neighborsolicit); \ 			 break; \ 		 case ND_NEIGHBOR_ADVERT: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_neighboradvert); \ 			 break; \ 		 case ND_REDIRECT: \ 			 icmp6_ifstat_inc(ifp, ifs6_out_redirect); \ 			 break; \ 		} \ } while (0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|icmp6_rediraccept
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accept/process redirects */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|icmp6_redirtimeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache time for redirect routes */
end_comment

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
comment|/* not _NETINET_ICMP6_H_ */
end_comment

end_unit

