begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Alexander V. Chernikov<melifaro@ipfw.ru>  * Copyright (c) 2004 Gleb Smirnoff<glebius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	 $SourceForge: netflow.h,v 1.8 2004/09/16 17:05:11 glebius Exp $  *	 $FreeBSD$  */
end_comment

begin_comment
comment|/* netflow timeouts in seconds */
end_comment

begin_define
define|#
directive|define
name|ACTIVE_TIMEOUT
value|(30*60)
end_define

begin_comment
comment|/* maximum flow lifetime is 30 min */
end_comment

begin_define
define|#
directive|define
name|INACTIVE_TIMEOUT
value|15
end_define

begin_comment
comment|/*  * More info can be found in these Cisco documents:  *  * Cisco IOS NetFlow, White Papers.  * http://www.cisco.com/en/US/products/ps6601/prod_white_papers_list.html  *  * Cisco CNS NetFlow Collection Engine User Guide, 5.0.2, NetFlow Export  * Datagram Formats.  * http://www.cisco.com/en/US/products/sw/netmgtsw/ps1964/products_user_guide_chapter09186a00803f3147.html#wp26453  *  * Cisco Systems NetFlow Services Export Version 9  * http://www.ietf.org/rfc/rfc3954.txt  *  */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V1
value|1
end_define

begin_define
define|#
directive|define
name|NETFLOW_V5
value|5
end_define

begin_define
define|#
directive|define
name|NETFLOW_V9
value|9
end_define

begin_struct
struct|struct
name|netflow_v1_header
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* NetFlow version */
name|uint16_t
name|count
decl_stmt|;
comment|/* Number of records in flow */
name|uint32_t
name|sys_uptime
decl_stmt|;
comment|/* System uptime */
name|uint32_t
name|unix_secs
decl_stmt|;
comment|/* Current seconds since 0000 UTC 1970 */
name|uint32_t
name|unix_nsecs
decl_stmt|;
comment|/* Remaining nanoseconds since 0000 UTC 1970 */
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
name|netflow_v5_header
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* NetFlow version */
name|uint16_t
name|count
decl_stmt|;
comment|/* Number of records in flow */
name|uint32_t
name|sys_uptime
decl_stmt|;
comment|/* System uptime */
name|uint32_t
name|unix_secs
decl_stmt|;
comment|/* Current seconds since 0000 UTC 1970 */
name|uint32_t
name|unix_nsecs
decl_stmt|;
comment|/* Remaining nanoseconds since 0000 UTC 1970 */
name|uint32_t
name|flow_seq
decl_stmt|;
comment|/* Sequence number of the first record */
name|uint8_t
name|engine_type
decl_stmt|;
comment|/* Type of flow switching engine (RP,VIP,etc.) */
name|uint8_t
name|engine_id
decl_stmt|;
comment|/* Slot number of the flow switching engine */
name|uint16_t
name|pad
decl_stmt|;
comment|/* Pad to word boundary */
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
name|netflow_v9_header
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* NetFlow version */
name|uint16_t
name|count
decl_stmt|;
comment|/* Total number of records in packet */
name|uint32_t
name|sys_uptime
decl_stmt|;
comment|/* System uptime */
name|uint32_t
name|unix_secs
decl_stmt|;
comment|/* Current seconds since 0000 UTC 1970 */
name|uint32_t
name|seq_num
decl_stmt|;
comment|/* Sequence number */
name|uint32_t
name|source_id
decl_stmt|;
comment|/* Observation Domain id */
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
name|netflow_v1_record
block|{
name|uint32_t
name|src_addr
decl_stmt|;
comment|/* Source IP address */
name|uint32_t
name|dst_addr
decl_stmt|;
comment|/* Destination IP address */
name|uint32_t
name|next_hop
decl_stmt|;
comment|/* Next hop IP address */
name|uint16_t
name|in_ifx
decl_stmt|;
comment|/* Source interface index */
name|uint16_t
name|out_ifx
decl_stmt|;
comment|/* Destination interface index */
name|uint32_t
name|packets
decl_stmt|;
comment|/* Number of packets in a flow */
name|uint32_t
name|octets
decl_stmt|;
comment|/* Number of octets in a flow */
name|uint32_t
name|first
decl_stmt|;
comment|/* System uptime at start of a flow */
name|uint32_t
name|last
decl_stmt|;
comment|/* System uptime at end of a flow */
name|uint16_t
name|s_port
decl_stmt|;
comment|/* Source port */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* Destination port */
name|uint16_t
name|pad1
decl_stmt|;
comment|/* Pad to word boundary */
name|uint8_t
name|prot
decl_stmt|;
comment|/* IP protocol */
name|uint8_t
name|tos
decl_stmt|;
comment|/* IP type of service */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Cumulative OR of tcp flags */
name|uint8_t
name|pad2
decl_stmt|;
comment|/* Pad to word boundary */
name|uint16_t
name|pad3
decl_stmt|;
comment|/* Pad to word boundary */
name|uint8_t
name|reserved
index|[
literal|5
index|]
decl_stmt|;
comment|/* Reserved for future use */
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
name|netflow_v5_record
block|{
name|uint32_t
name|src_addr
decl_stmt|;
comment|/* Source IP address */
name|uint32_t
name|dst_addr
decl_stmt|;
comment|/* Destination IP address */
name|uint32_t
name|next_hop
decl_stmt|;
comment|/* Next hop IP address */
name|uint16_t
name|i_ifx
decl_stmt|;
comment|/* Source interface index */
name|uint16_t
name|o_ifx
decl_stmt|;
comment|/* Destination interface index */
name|uint32_t
name|packets
decl_stmt|;
comment|/* Number of packets in a flow */
name|uint32_t
name|octets
decl_stmt|;
comment|/* Number of octets in a flow */
name|uint32_t
name|first
decl_stmt|;
comment|/* System uptime at start of a flow */
name|uint32_t
name|last
decl_stmt|;
comment|/* System uptime at end of a flow */
name|uint16_t
name|s_port
decl_stmt|;
comment|/* Source port */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* Destination port */
name|uint8_t
name|pad1
decl_stmt|;
comment|/* Pad to word boundary */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Cumulative OR of tcp flags */
name|uint8_t
name|prot
decl_stmt|;
comment|/* IP protocol */
name|uint8_t
name|tos
decl_stmt|;
comment|/* IP type of service */
name|uint16_t
name|src_as
decl_stmt|;
comment|/* Src peer/origin Autonomous System */
name|uint16_t
name|dst_as
decl_stmt|;
comment|/* Dst peer/origin Autonomous System */
name|uint8_t
name|src_mask
decl_stmt|;
comment|/* Source route's mask bits */
name|uint8_t
name|dst_mask
decl_stmt|;
comment|/* Destination route's mask bits */
name|uint16_t
name|pad2
decl_stmt|;
comment|/* Pad to word boundary */
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
name|NETFLOW_V1_MAX_RECORDS
value|24
end_define

begin_define
define|#
directive|define
name|NETFLOW_V5_MAX_RECORDS
value|30
end_define

begin_define
define|#
directive|define
name|NETFLOW_V1_MAX_SIZE
value|(sizeof(netflow_v1_header)+ \ 			     sizeof(netflow_v1_record)*NETFLOW_V1_MAX_RECORDS)
end_define

begin_define
define|#
directive|define
name|NETFLOW_V5_MAX_SIZE
value|(sizeof(netflow_v5_header)+ \ 			     sizeof(netflow_v5_record)*NETFLOW_V5_MAX_RECORDS)
end_define

begin_struct
struct|struct
name|netflow_v5_export_dgram
block|{
name|struct
name|netflow_v5_header
name|header
decl_stmt|;
name|struct
name|netflow_v5_record
name|r
index|[
name|NETFLOW_V5_MAX_RECORDS
index|]
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

begin_comment
comment|/* RFC3954 field definitions */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IN_BYTES
value|1
end_define

begin_comment
comment|/* Input bytes count for a flow. Default 4, can be 8 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IN_PKTS
value|2
end_define

begin_comment
comment|/* Incoming counter with number of packets associated with an IP Flow. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FLOWS
value|3
end_define

begin_comment
comment|/* Number of Flows that were aggregated. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_PROTOCOL
value|4
end_define

begin_comment
comment|/* IP protocol byte. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_TOS
value|5
end_define

begin_comment
comment|/* Type of service byte setting when entering the incoming interface. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_TCP_FLAGS
value|6
end_define

begin_comment
comment|/* TCP flags; cumulative of all the TCP flags seen in this Flow. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_L4_SRC_PORT
value|7
end_define

begin_comment
comment|/* TCP/UDP source port number. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV4_SRC_ADDR
value|8
end_define

begin_comment
comment|/* IPv4 source address. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_SRC_MASK
value|9
end_define

begin_comment
comment|/* The number of contiguous bits in the source subnet mask (i.e., the mask in slash notation). 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_INPUT_SNMP
value|10
end_define

begin_comment
comment|/* Input interface index. Default 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_L4_DST_PORT
value|11
end_define

begin_comment
comment|/* TCP/UDP destination port number. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV4_DST_ADDR
value|12
end_define

begin_comment
comment|/* IPv4 destination address. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_DST_MASK
value|13
end_define

begin_comment
comment|/* The number of contiguous bits in the destination subnet mask (i.e., the mask in slash notation). 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_OUTPUT_SNMP
value|14
end_define

begin_comment
comment|/* Output interface index. Default 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV4_NEXT_HOP
value|15
end_define

begin_comment
comment|/* IPv4 address of the next-hop router. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_SRC_AS
value|16
end_define

begin_comment
comment|/* Source BGP autonomous system number. Default 2, can be 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_DST_AS
value|17
end_define

begin_comment
comment|/* Destination BGP autonomous system number. Default 2, can be 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_BGP_IPV4_NEXT_HOP
value|18
end_define

begin_comment
comment|/* Next-hop router's IP address in the BGP domain. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MUL_DST_PKTS
value|19
end_define

begin_comment
comment|/* IP multicast outgoing packet counter for packets associated with IP flow. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MUL_DST_BYTES
value|20
end_define

begin_comment
comment|/* IP multicast outgoing Octet (byte) counter for the number of bytes associated with IP flow. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_LAST_SWITCHED
value|21
end_define

begin_comment
comment|/* sysUptime in msec at which the last packet of this Flow was switched. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FIRST_SWITCHED
value|22
end_define

begin_comment
comment|/* sysUptime in msec at which the first packet of this Flow was switched. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_OUT_BYTES
value|23
end_define

begin_comment
comment|/* Outgoing counter for the number of bytes associated with an IP Flow. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_OUT_PKTS
value|24
end_define

begin_comment
comment|/* Outgoing counter for the number of packets associated with an IP Flow. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_SRC_ADDR
value|27
end_define

begin_comment
comment|/* IPv6 source address. 16 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_DST_ADDR
value|28
end_define

begin_comment
comment|/* IPv6 destination address. 16 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_SRC_MASK
value|29
end_define

begin_comment
comment|/* Length of the IPv6 source mask in contiguous bits. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_DST_MASK
value|30
end_define

begin_comment
comment|/* Length of the IPv6 destination mask in contiguous bits. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_FLOW_LABEL
value|31
end_define

begin_comment
comment|/* IPv6 flow label as per RFC 2460 definition. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_ICMP_TYPE
value|32
end_define

begin_comment
comment|/* Internet Control Message Protocol (ICMP) packet type; reported as ICMP Type * 256 + ICMP code. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MUL_IGMP_TYPE
value|33
end_define

begin_comment
comment|/* Internet Group Management Protocol (IGMP) packet type. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_SAMPLING_INTERVAL
value|34
end_define

begin_comment
comment|/* When using sampled NetFlow, the rate at which packets are sampled; for example, a value of 100 indicates that one of every hundred packets is sampled. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_SAMPLING_ALGORITHM
value|35
end_define

begin_comment
comment|/* For sampled NetFlow platform-wide: 0x01 deterministic sampling 0x02 random sampling. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FLOW_ACTIVE_TIMEOUT
value|36
end_define

begin_comment
comment|/* Timeout value (in seconds) for active flow entries in the NetFlow cache. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FLOW_INACTIVE_TIMEOUT
value|37
end_define

begin_comment
comment|/* Timeout value (in seconds) for inactive Flow entries in the NetFlow cache. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_ENGINE_TYPE
value|38
end_define

begin_comment
comment|/* Type of Flow switching engine (route processor, linecard, etc...). 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_ENGINE_ID
value|39
end_define

begin_comment
comment|/* ID number of the Flow switching engine. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_TOTAL_BYTES_EXP
value|40
end_define

begin_comment
comment|/* Counter with for the number of bytes exported by the Observation Domain. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_TOTAL_PKTS_EXP
value|41
end_define

begin_comment
comment|/* Counter with for the number of packets exported by the Observation Domain. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_TOTAL_FLOWS_EXP
value|42
end_define

begin_comment
comment|/* Counter with for the number of flows exported by the Observation Domain. Default 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_TOP_LABEL_TYPE
value|46
end_define

begin_comment
comment|/* MPLS Top Label Type. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_TOP_LABEL_IP_ADDR
value|47
end_define

begin_comment
comment|/* Forwarding Equivalent Class corresponding to the MPLS Top Label. 4 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FLOW_SAMPLER_ID
value|48
end_define

begin_comment
comment|/* Identifier shown in "show flow-sampler". 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FLOW_SAMPLER_MODE
value|49
end_define

begin_comment
comment|/* The type of algorithm used for sampling data. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_FLOW_SAMPLER_RANDOM_INTERVAL
value|50
end_define

begin_comment
comment|/* Packet interval at which to sample. 4. */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_DST_TOS
value|55
end_define

begin_comment
comment|/* Type of Service byte setting when exiting outgoing interface. 1. */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_SRC_MAC
value|56
end_define

begin_comment
comment|/* Source MAC Address. 6 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_DST_MAC
value|57
end_define

begin_comment
comment|/* Destination MAC Address. 6 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_SRC_VLAN
value|58
end_define

begin_comment
comment|/* Virtual LAN identifier associated with ingress interface. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_DST_VLAN
value|59
end_define

begin_comment
comment|/* Virtual LAN identifier associated with egress interface. 2 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IP_PROTOCOL_VERSION
value|60
end_define

begin_comment
comment|/* Internet Protocol Version. Set to 4 for IPv4, set to 6 for IPv6. If not present in the template, then version 4 is assumed. 1. */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_DIRECTION
value|61
end_define

begin_comment
comment|/* Flow direction: 0 - ingress flow 1 - egress flow. 1 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_NEXT_HOP
value|62
end_define

begin_comment
comment|/* IPv6 address of the next-hop router. 16 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_BGP_IPV6_NEXT_HOP
value|63
end_define

begin_comment
comment|/* Next-hop router in the BGP domain. 16 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_IPV6_OPTION_HEADERS
value|64
end_define

begin_comment
comment|/* Bit-encoded field identifying IPv6 option headers found in the flow */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_1
value|70
end_define

begin_comment
comment|/* MPLS label at position 1 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_2
value|71
end_define

begin_comment
comment|/* MPLS label at position 2 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_3
value|72
end_define

begin_comment
comment|/* MPLS label at position 3 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_4
value|73
end_define

begin_comment
comment|/* MPLS label at position 4 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_5
value|74
end_define

begin_comment
comment|/* MPLS label at position 5 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_6
value|75
end_define

begin_comment
comment|/* MPLS label at position 6 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_7
value|76
end_define

begin_comment
comment|/* MPLS label at position 7 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_8
value|77
end_define

begin_comment
comment|/* MPLS label at position 8 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_9
value|78
end_define

begin_comment
comment|/* MPLS label at position 9 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_FIELD_MPLS_LABEL_10
value|79
end_define

begin_comment
comment|/* MPLS label at position 10 in the stack. 3 */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V9_MAX_RESERVED_FLOWSET
value|0xFF
end_define

begin_comment
comment|/* Clause 5.2 */
end_comment

end_unit

