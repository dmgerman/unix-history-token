begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Yandex LLC  * Copyright (c) 2015 Alexander V. Chernikov<melifaro@FreeBSD.org>  * Copyright (c) 2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IP_FW_NAT64_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IP_FW_NAT64_H_
end_define

begin_struct
struct|struct
name|ipfw_nat64stl_stats
block|{
name|uint64_t
name|opcnt64
decl_stmt|;
comment|/* 6to4 of packets translated */
name|uint64_t
name|opcnt46
decl_stmt|;
comment|/* 4to6 of packets translated */
name|uint64_t
name|ofrags
decl_stmt|;
comment|/* number of fragments generated */
name|uint64_t
name|ifrags
decl_stmt|;
comment|/* number of fragments received */
name|uint64_t
name|oerrors
decl_stmt|;
comment|/* number of output errors */
name|uint64_t
name|noroute4
decl_stmt|;
name|uint64_t
name|noroute6
decl_stmt|;
name|uint64_t
name|noproto
decl_stmt|;
comment|/* Protocol not supported */
name|uint64_t
name|nomem
decl_stmt|;
comment|/* mbuf allocation filed */
name|uint64_t
name|dropped
decl_stmt|;
comment|/* dropped due to some errors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipfw_nat64lsn_stats
block|{
name|uint64_t
name|opcnt64
decl_stmt|;
comment|/* 6to4 of packets translated */
name|uint64_t
name|opcnt46
decl_stmt|;
comment|/* 4to6 of packets translated */
name|uint64_t
name|ofrags
decl_stmt|;
comment|/* number of fragments generated */
name|uint64_t
name|ifrags
decl_stmt|;
comment|/* number of fragments received */
name|uint64_t
name|oerrors
decl_stmt|;
comment|/* number of output errors */
name|uint64_t
name|noroute4
decl_stmt|;
name|uint64_t
name|noroute6
decl_stmt|;
name|uint64_t
name|noproto
decl_stmt|;
comment|/* Protocol not supported */
name|uint64_t
name|nomem
decl_stmt|;
comment|/* mbuf allocation filed */
name|uint64_t
name|dropped
decl_stmt|;
comment|/* dropped due to some errors */
name|uint64_t
name|nomatch4
decl_stmt|;
comment|/* No addr/port match */
name|uint64_t
name|jcalls
decl_stmt|;
comment|/* Number of job handler calls */
name|uint64_t
name|jrequests
decl_stmt|;
comment|/* Number of job requests */
name|uint64_t
name|jhostsreq
decl_stmt|;
comment|/* Number of job host requests */
name|uint64_t
name|jportreq
decl_stmt|;
comment|/* Number of portgroup requests */
name|uint64_t
name|jhostfails
decl_stmt|;
comment|/* Number of failed host allocs */
name|uint64_t
name|jportfails
decl_stmt|;
comment|/* Number of failed portgroup allocs */
name|uint64_t
name|jreinjected
decl_stmt|;
comment|/* Number of packets reinjected to q */
name|uint64_t
name|jmaxlen
decl_stmt|;
comment|/* Max queue length reached */
name|uint64_t
name|jnomem
decl_stmt|;
comment|/* No memory to alloc queue item */
name|uint64_t
name|screated
decl_stmt|;
comment|/* Number of states created */
name|uint64_t
name|sdeleted
decl_stmt|;
comment|/* Number of states deleted */
name|uint64_t
name|spgcreated
decl_stmt|;
comment|/* Number of portgroups created */
name|uint64_t
name|spgdeleted
decl_stmt|;
comment|/* Number of portgroups deleted */
name|uint64_t
name|hostcount
decl_stmt|;
comment|/* Number of hosts  */
name|uint64_t
name|tcpchunks
decl_stmt|;
comment|/* Number of TCP chunks */
name|uint64_t
name|udpchunks
decl_stmt|;
comment|/* Number of UDP chunks */
name|uint64_t
name|icmpchunks
decl_stmt|;
comment|/* Number of ICMP chunks */
name|uint64_t
name|_reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAT64_LOG
value|0x0001
end_define

begin_comment
comment|/* Enable logging via BPF */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_nat64stl_cfg
block|{
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* NAT name			*/
name|ipfw_obj_ntlv
name|ntlv6
decl_stmt|;
comment|/* object name tlv		*/
name|ipfw_obj_ntlv
name|ntlv4
decl_stmt|;
comment|/* object name tlv		*/
name|struct
name|in6_addr
name|prefix6
decl_stmt|;
comment|/* NAT64 prefix */
name|uint8_t
name|plen6
decl_stmt|;
comment|/* Prefix length */
name|uint8_t
name|set
decl_stmt|;
comment|/* Named instance set [0..31] */
name|uint8_t
name|spare
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
name|ipfw_nat64stl_cfg
typedef|;
end_typedef

begin_comment
comment|/*  * NAT64LSN default configuration values  */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_MAX_PORTS
value|2048
end_define

begin_comment
comment|/* Max number of ports per host */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_JMAXLEN
value|2048
end_define

begin_comment
comment|/* Max outstanding requests. */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_TCP_SYN_AGE
value|10
end_define

begin_comment
comment|/* State's TTL after SYN received. */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_TCP_EST_AGE
value|(2 * 3600)
end_define

begin_comment
comment|/* TTL for established connection */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_TCP_FIN_AGE
value|180
end_define

begin_comment
comment|/* State's TTL after FIN/RST received */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_UDP_AGE
value|120
end_define

begin_comment
comment|/* TTL for UDP states */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_ICMP_AGE
value|60
end_define

begin_comment
comment|/* TTL for ICMP states */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_HOST_AGE
value|3600
end_define

begin_comment
comment|/* TTL for stale host entry */
end_comment

begin_define
define|#
directive|define
name|NAT64LSN_PG_AGE
value|900
end_define

begin_comment
comment|/* TTL for stale ports groups */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_nat64lsn_cfg
block|{
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* NAT name			*/
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|max_ports
decl_stmt|;
comment|/* Max ports per client */
name|uint32_t
name|agg_prefix_len
decl_stmt|;
comment|/* Prefix length to count */
name|uint32_t
name|agg_prefix_max
decl_stmt|;
comment|/* Max hosts per agg prefix */
name|struct
name|in_addr
name|prefix4
decl_stmt|;
name|uint16_t
name|plen4
decl_stmt|;
comment|/* Prefix length */
name|uint16_t
name|plen6
decl_stmt|;
comment|/* Prefix length */
name|struct
name|in6_addr
name|prefix6
decl_stmt|;
comment|/* NAT64 prefix */
name|uint32_t
name|jmaxlen
decl_stmt|;
comment|/* Max jobqueue length */
name|uint16_t
name|min_port
decl_stmt|;
comment|/* Min port group # to use */
name|uint16_t
name|max_port
decl_stmt|;
comment|/* Max port group # to use */
name|uint16_t
name|nh_delete_delay
decl_stmt|;
comment|/* Stale host delete delay */
name|uint16_t
name|pg_delete_delay
decl_stmt|;
comment|/* Stale portgroup delete delay */
name|uint16_t
name|st_syn_ttl
decl_stmt|;
comment|/* TCP syn expire */
name|uint16_t
name|st_close_ttl
decl_stmt|;
comment|/* TCP fin expire */
name|uint16_t
name|st_estab_ttl
decl_stmt|;
comment|/* TCP established expire */
name|uint16_t
name|st_udp_ttl
decl_stmt|;
comment|/* UDP expire */
name|uint16_t
name|st_icmp_ttl
decl_stmt|;
comment|/* ICMP expire */
name|uint8_t
name|set
decl_stmt|;
comment|/* Named instance set [0..31] */
name|uint8_t
name|spare
decl_stmt|;
block|}
name|ipfw_nat64lsn_cfg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_nat64lsn_state
block|{
name|struct
name|in_addr
name|daddr
decl_stmt|;
comment|/* Remote IPv4 address */
name|uint16_t
name|dport
decl_stmt|;
comment|/* Remote destination port */
name|uint16_t
name|aport
decl_stmt|;
comment|/* Local alias port */
name|uint16_t
name|sport
decl_stmt|;
comment|/* Source port */
name|uint8_t
name|flags
decl_stmt|;
comment|/* State flags */
name|uint8_t
name|spare
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|idle
decl_stmt|;
comment|/* Last used time */
block|}
name|ipfw_nat64lsn_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_nat64lsn_stg
block|{
name|uint64_t
name|next_idx
decl_stmt|;
comment|/* next state index */
name|struct
name|in_addr
name|alias4
decl_stmt|;
comment|/* IPv4 alias address */
name|uint8_t
name|proto
decl_stmt|;
comment|/* protocol */
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|spare
decl_stmt|;
name|struct
name|in6_addr
name|host6
decl_stmt|;
comment|/* Bound IPv6 host */
name|uint32_t
name|count
decl_stmt|;
comment|/* Number of states */
name|uint32_t
name|spare2
decl_stmt|;
block|}
name|ipfw_nat64lsn_stg
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET6_IP_FW_NAT64_H_ */
end_comment

end_unit

