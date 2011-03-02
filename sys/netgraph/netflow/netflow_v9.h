begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Alexander V. Chernikov<melifaro@ipfw.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	 $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETFLOW_V9_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETFLOW_V9_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COUNTERS_64
end_ifdef

begin_define
define|#
directive|define
name|CNTR
value|uint64_t
end_define

begin_define
define|#
directive|define
name|CNTR_MAX
value|UINT64_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CNTR
value|uint32_t
end_define

begin_define
define|#
directive|define
name|CNTR_MAX
value|UINT_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|netflow_v9_template
block|{
name|int
name|field_id
decl_stmt|;
name|int
name|field_length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Template ID for tcp/udp v4 streams ID:257 (0x100 + NETFLOW_V9_FLOW_V4_L4) */
end_comment

begin_struct
struct|struct
name|netflow_v9_record_ipv4_tcp
block|{
name|uint32_t
name|src_addr
decl_stmt|;
comment|/* Source IPv4 address (IPV4_SRC_ADDR) */
name|uint32_t
name|dst_addr
decl_stmt|;
comment|/* Destination IPv4 address (IPV4_DST_ADDR) */
name|uint32_t
name|next_hop
decl_stmt|;
comment|/* Next hop IPv4 address (IPV4_NEXT_HOP) */
name|uint16_t
name|i_ifx
decl_stmt|;
comment|/* Source interface index (INPUT_SNMP) */
name|uint16_t
name|o_ifx
decl_stmt|;
comment|/* Destination interface index (OUTPUT_SNMP) */
name|CNTR
name|i_packets
decl_stmt|;
comment|/* Number of incoming packets in a flow (IN_PKTS) */
name|CNTR
name|i_octets
decl_stmt|;
comment|/* Number of incoming octets in a flow (IN_BYTES) */
name|CNTR
name|o_packets
decl_stmt|;
comment|/* Number of outgoing packets in a flow (OUT_PKTS) */
name|CNTR
name|o_octets
decl_stmt|;
comment|/* Number of outgoing octets in a flow (OUT_BYTES) */
name|uint32_t
name|first
decl_stmt|;
comment|/* System uptime at start of a flow (FIRST_SWITCHED) */
name|uint32_t
name|last
decl_stmt|;
comment|/* System uptime at end of a flow (LAST_SWITCHED) */
name|uint16_t
name|s_port
decl_stmt|;
comment|/* Source port (L4_SRC_PORT) */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* Destination port (L4_DST_PORT) */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Cumulative OR of tcp flags (TCP_FLAGS) */
name|uint8_t
name|prot
decl_stmt|;
comment|/* IP protocol */
name|uint8_t
name|tos
decl_stmt|;
comment|/* IP type of service IN (or OUT) (TOS) */
name|uint32_t
name|src_as
decl_stmt|;
comment|/* Src peer/origin Autonomous System (SRC_AS) */
name|uint32_t
name|dst_as
decl_stmt|;
comment|/* Dst peer/origin Autonomous System (DST_AS) */
name|uint8_t
name|src_mask
decl_stmt|;
comment|/* Source route's mask bits (SRC_MASK) */
name|uint8_t
name|dst_mask
decl_stmt|;
comment|/* Destination route's mask bits (DST_MASK) */
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
comment|/* Template ID for tcp/udp v6 streams ID: 260 (0x100 + NETFLOW_V9_FLOW_V6_L4) */
end_comment

begin_struct
struct|struct
name|netflow_v9_record_ipv6_tcp
block|{
name|struct
name|in6_addr
name|src_addr
decl_stmt|;
comment|/* Source IPv6 address (IPV6_SRC_ADDR) */
name|struct
name|in6_addr
name|dst_addr
decl_stmt|;
comment|/* Destination IPv6 address (IPV6_DST_ADDR) */
name|struct
name|in6_addr
name|next_hop
decl_stmt|;
comment|/* Next hop IPv6 address (IPV6_NEXT_HOP) */
name|uint16_t
name|i_ifx
decl_stmt|;
comment|/* Source interface index (INPUT_SNMP) */
name|uint16_t
name|o_ifx
decl_stmt|;
comment|/* Destination interface index (OUTPUT_SNMP) */
name|CNTR
name|i_packets
decl_stmt|;
comment|/* Number of incoming packets in a flow (IN_PKTS) */
name|CNTR
name|i_octets
decl_stmt|;
comment|/* Number of incoming octets in a flow (IN_BYTES) */
name|CNTR
name|o_packets
decl_stmt|;
comment|/* Number of outgoing packets in a flow (OUT_PKTS) */
name|CNTR
name|o_octets
decl_stmt|;
comment|/* Number of outgoing octets in a flow (OUT_BYTES) */
name|uint32_t
name|first
decl_stmt|;
comment|/* System uptime at start of a flow (FIRST_SWITCHED) */
name|uint32_t
name|last
decl_stmt|;
comment|/* System uptime at end of a flow (LAST_SWITCHED) */
name|uint16_t
name|s_port
decl_stmt|;
comment|/* Source port (L4_SRC_PORT) */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* Destination port (L4_DST_PORT) */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Cumulative OR of tcp flags (TCP_FLAGS) */
name|uint8_t
name|prot
decl_stmt|;
comment|/* IP protocol */
name|uint8_t
name|tos
decl_stmt|;
comment|/* IP type of service IN (or OUT) (TOS) */
name|uint32_t
name|src_as
decl_stmt|;
comment|/* Src peer/origin Autonomous System (SRC_AS) */
name|uint32_t
name|dst_as
decl_stmt|;
comment|/* Dst peer/origin Autonomous System (DST_AS) */
name|uint8_t
name|src_mask
decl_stmt|;
comment|/* Source route's mask bits (SRC_MASK) */
name|uint8_t
name|dst_mask
decl_stmt|;
comment|/* Destination route's mask bits (DST_MASK) */
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
comment|/* Used in export9_add to determine max record size */
end_comment

begin_struct
struct|struct
name|netflow_v9_record_general
block|{
union|union
block|{
name|struct
name|netflow_v9_record_ipv4_tcp
name|v4_tcp
decl_stmt|;
name|struct
name|netflow_v9_record_ipv6_tcp
name|v6_tcp
decl_stmt|;
block|}
name|rec
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BASE_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|MIN_MTU
value|sizeof(struct netflow_v5_header)
end_define

begin_define
define|#
directive|define
name|MAX_MTU
value|16384
end_define

begin_define
define|#
directive|define
name|NETFLOW_V9_MAX_SIZE
value|_NETFLOW_V9_MAX_SIZE(BASE_MTU)
end_define

begin_comment
comment|/* Decrease MSS by 16 since there can be some IPv[46] header options */
end_comment

begin_define
define|#
directive|define
name|_NETFLOW_V9_MAX_SIZE
parameter_list|(
name|x
parameter_list|)
value|(x) - sizeof(struct ip6_hdr) - sizeof(struct udphdr) - 16
end_define

begin_comment
comment|/* #define NETFLOW_V9_MAX_FLOWSETS	2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_MAX_RECORD_SIZE
value|sizeof(struct netflow_v9_record_ipv6_tcp)
end_define

begin_define
define|#
directive|define
name|NETFLOW_V9_MAX_PACKETS_TEMPL
value|500
end_define

begin_comment
comment|/* Send data templates every ... packets */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_MAX_TIME_TEMPL
value|600
end_define

begin_comment
comment|/* Send data templates every ... seconds */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_MAX_TEMPLATES
value|16
end_define

begin_comment
comment|/* Not a real value */
end_comment

begin_define
define|#
directive|define
name|_NETFLOW_V9_TEMPLATE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof(struct netflow_v9_template)) * 4
end_define

begin_comment
comment|//#define _NETFLOW_V9_TEMPLATE_SIZE(x)	((x) + 1) * 4
end_comment

begin_comment
comment|/* Flow Templates */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_V4_L4
value|1
end_define

begin_comment
comment|/* IPv4 TCP/UDP packet */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_V4_ICMP
value|2
end_define

begin_comment
comment|/* IPv4 ICMP packet, currently unused */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_V4_L3
value|3
end_define

begin_comment
comment|/* IPv4 IP packet */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_V6_L4
value|4
end_define

begin_comment
comment|/* IPv6 TCP/UDP packet */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_V6_ICMP
value|5
end_define

begin_comment
comment|/* IPv6 ICMP packet, currently unused */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_V6_L3
value|6
end_define

begin_comment
comment|/* IPv6 IP packet */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FLOW_FAKE
value|65535
end_define

begin_comment
comment|/* Not uset used in real flowsets! */
end_comment

begin_struct
struct|struct
name|netflow_v9_export_dgram
block|{
name|struct
name|netflow_v9_header
name|header
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
comment|/* MTU can change, record length is dynamic */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|netflow_v9_flowset_header
block|{
name|uint16_t
name|id
decl_stmt|;
comment|/* FlowSet id */
name|uint16_t
name|length
decl_stmt|;
comment|/* FlowSet length */
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
name|netflow_v9_packet_opt
block|{
name|uint16_t
name|length
decl_stmt|;
comment|/* current packet length */
name|uint16_t
name|count
decl_stmt|;
comment|/* current records count */
name|uint16_t
name|mtu
decl_stmt|;
comment|/* max MTU shapshot */
name|uint16_t
name|flow_type
decl_stmt|;
comment|/* current flowset */
name|uint16_t
name|flow_header
decl_stmt|;
comment|/* offset pointing to current flow header */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

