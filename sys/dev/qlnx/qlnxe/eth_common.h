begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ETH_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__ETH_COMMON__
end_define

begin_comment
comment|/********************/
end_comment

begin_comment
comment|/* ETH FW CONSTANTS */
end_comment

begin_comment
comment|/********************/
end_comment

begin_comment
comment|/* FP HSI version. FP HSI is compatible if (fwVer.major == drvVer.major&& fwVer.minor>= drvVer.minor) */
end_comment

begin_define
define|#
directive|define
name|ETH_HSI_VER_MAJOR
value|3
end_define

begin_comment
comment|/* ETH FP HSI Major version */
end_comment

begin_define
define|#
directive|define
name|ETH_HSI_VER_MINOR
value|10
end_define

begin_comment
comment|/* ETH FP HSI Minor version */
end_comment

begin_define
define|#
directive|define
name|ETH_HSI_VER_NO_PKT_LEN_TUNN
value|5
end_define

begin_comment
comment|/* Alias for 8.7.x.x/8.8.x.x ETH FP HSI MINOR version. In this version driver is not required to set pkt_len field in eth_tx_1st_bd struct, and tunneling offload is not supported. */
end_comment

begin_define
define|#
directive|define
name|ETH_CACHE_LINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|ETH_RX_CQE_GAP
value|32
end_define

begin_define
define|#
directive|define
name|ETH_MAX_RAMROD_PER_CON
value|8
end_define

begin_define
define|#
directive|define
name|ETH_TX_BD_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|ETH_RX_BD_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|ETH_RX_CQE_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|ETH_RX_NUM_NEXT_PAGE_BDS
value|2
end_define

begin_comment
comment|/* Limitation for Tunneled LSO Packets on the offset (in bytes) of the inner IP header (relevant to LSO for tunneled packet): */
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_TUNN_LSO_INNER_IPV4_OFFSET
value|253
end_define

begin_comment
comment|/* Offset is limited to 253 bytes (inclusive). */
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_TUNN_LSO_INNER_IPV6_OFFSET
value|251
end_define

begin_comment
comment|/* Offset is limited to 251 bytes (inclusive). */
end_comment

begin_define
define|#
directive|define
name|ETH_TX_MIN_BDS_PER_NON_LSO_PKT
value|1
end_define

begin_define
define|#
directive|define
name|ETH_TX_MAX_BDS_PER_NON_LSO_PACKET
value|18
end_define

begin_define
define|#
directive|define
name|ETH_TX_MAX_BDS_PER_LSO_PACKET
value|255
end_define

begin_define
define|#
directive|define
name|ETH_TX_MAX_LSO_HDR_NBD
value|4
end_define

begin_define
define|#
directive|define
name|ETH_TX_MIN_BDS_PER_LSO_PKT
value|3
end_define

begin_define
define|#
directive|define
name|ETH_TX_MIN_BDS_PER_TUNN_IPV6_WITH_EXT_PKT
value|3
end_define

begin_define
define|#
directive|define
name|ETH_TX_MIN_BDS_PER_IPV6_WITH_EXT_PKT
value|2
end_define

begin_define
define|#
directive|define
name|ETH_TX_MIN_BDS_PER_PKT_W_LOOPBACK_MODE
value|2
end_define

begin_define
define|#
directive|define
name|ETH_TX_MAX_NON_LSO_PKT_LEN
value|(9700 - (4 + 4 + 12 + 8))
end_define

begin_comment
comment|/* (QM_REG_TASKBYTECRDCOST_0, QM_VOQ_BYTE_CRD_TASK_COST) - (VLAN-TAG + CRC + IPG + PREAMBLE) */
end_comment

begin_define
define|#
directive|define
name|ETH_TX_MAX_LSO_HDR_BYTES
value|510
end_define

begin_define
define|#
directive|define
name|ETH_TX_LSO_WINDOW_BDS_NUM
value|(18 - 1)
end_define

begin_comment
comment|/* Number of BDs to consider for LSO sliding window restriction is (ETH_TX_LSO_WINDOW_BDS_NUM - hdr_nbd) */
end_comment

begin_define
define|#
directive|define
name|ETH_TX_LSO_WINDOW_MIN_LEN
value|9700
end_define

begin_comment
comment|/* Minimum data length (in bytes) in LSO sliding window */
end_comment

begin_define
define|#
directive|define
name|ETH_TX_MAX_LSO_PAYLOAD_LEN
value|0xFE000
end_define

begin_comment
comment|/* Maximum LSO packet TCP payload length (in bytes) */
end_comment

begin_define
define|#
directive|define
name|ETH_TX_NUM_SAME_AS_LAST_ENTRIES
value|320
end_define

begin_comment
comment|/* Number of same-as-last resources in tx switching */
end_comment

begin_define
define|#
directive|define
name|ETH_TX_INACTIVE_SAME_AS_LAST
value|0xFFFF
end_define

begin_comment
comment|/* Value for a connection for which same as last feature is disabled */
end_comment

begin_define
define|#
directive|define
name|ETH_NUM_STATISTIC_COUNTERS
value|MAX_NUM_VPORTS
end_define

begin_comment
comment|/* Maximum number of statistics counters */
end_comment

begin_define
define|#
directive|define
name|ETH_NUM_STATISTIC_COUNTERS_DOUBLE_VF_ZONE
value|(ETH_NUM_STATISTIC_COUNTERS - MAX_NUM_VFS/2)
end_define

begin_comment
comment|/* Maximum number of statistics counters when doubled VF zone used */
end_comment

begin_define
define|#
directive|define
name|ETH_NUM_STATISTIC_COUNTERS_QUAD_VF_ZONE
value|(ETH_NUM_STATISTIC_COUNTERS - 3*MAX_NUM_VFS/4)
end_define

begin_comment
comment|/* Maximum number of statistics counters when quad VF zone used */
end_comment

begin_define
define|#
directive|define
name|ETH_RX_MAX_BUFF_PER_PKT
value|5
end_define

begin_comment
comment|/* Maximum number of buffers, used for RX packet placement */
end_comment

begin_define
define|#
directive|define
name|ETH_RX_BD_THRESHOLD
value|12
end_define

begin_comment
comment|/* Minimum number of free BDs in RX ring, that guarantee receiving of at least one RX packet. */
end_comment

begin_comment
comment|/* num of MAC/VLAN filters */
end_comment

begin_define
define|#
directive|define
name|ETH_NUM_MAC_FILTERS
value|512
end_define

begin_define
define|#
directive|define
name|ETH_NUM_VLAN_FILTERS
value|512
end_define

begin_comment
comment|/* approx. multicast constants */
end_comment

begin_define
define|#
directive|define
name|ETH_MULTICAST_BIN_FROM_MAC_SEED
value|0
end_define

begin_comment
comment|/* CRC seed for multicast bin calculation */
end_comment

begin_define
define|#
directive|define
name|ETH_MULTICAST_MAC_BINS
value|256
end_define

begin_define
define|#
directive|define
name|ETH_MULTICAST_MAC_BINS_IN_REGS
value|(ETH_MULTICAST_MAC_BINS / 32)
end_define

begin_comment
comment|/*  ethernet vport update constants */
end_comment

begin_define
define|#
directive|define
name|ETH_FILTER_RULES_COUNT
value|10
end_define

begin_define
define|#
directive|define
name|ETH_RSS_IND_TABLE_ENTRIES_NUM
value|128
end_define

begin_comment
comment|/* number of RSS indirection table entries, per Vport) */
end_comment

begin_define
define|#
directive|define
name|ETH_RSS_KEY_SIZE_REGS
value|10
end_define

begin_comment
comment|/* Length of RSS key (in regs) */
end_comment

begin_define
define|#
directive|define
name|ETH_RSS_ENGINE_NUM_K2
value|207
end_define

begin_comment
comment|/* number of available RSS engines in K2 */
end_comment

begin_define
define|#
directive|define
name|ETH_RSS_ENGINE_NUM_BB
value|127
end_define

begin_comment
comment|/* number of available RSS engines in BB */
end_comment

begin_comment
comment|/* TPA constants */
end_comment

begin_define
define|#
directive|define
name|ETH_TPA_MAX_AGGS_NUM
value|64
end_define

begin_comment
comment|/* Maximum number of open TPA aggregations */
end_comment

begin_define
define|#
directive|define
name|ETH_TPA_CQE_START_LEN_LIST_SIZE
value|ETH_RX_MAX_BUFF_PER_PKT
end_define

begin_comment
comment|/* Maximum number of additional buffers, reported by TPA-start CQE */
end_comment

begin_define
define|#
directive|define
name|ETH_TPA_CQE_CONT_LEN_LIST_SIZE
value|6
end_define

begin_comment
comment|/* Maximum number of buffers, reported by TPA-continue CQE */
end_comment

begin_define
define|#
directive|define
name|ETH_TPA_CQE_END_LEN_LIST_SIZE
value|4
end_define

begin_comment
comment|/* Maximum number of buffers, reported by TPA-end CQE */
end_comment

begin_comment
comment|/* Control frame check constants */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_FRAME_ETH_TYPE_NUM
value|4
end_define

begin_comment
comment|/* Number of etherType values configured by the driver for control frame check */
end_comment

begin_comment
comment|/*  * Destination port mode  */
end_comment

begin_enum
enum|enum
name|dest_port_mode
block|{
name|DEST_PORT_PHY
comment|/* Send to physical port. */
block|,
name|DEST_PORT_LOOPBACK
comment|/* Send to loopback port. */
block|,
name|DEST_PORT_PHY_LOOPBACK
comment|/* Send to physical and loopback port. */
block|,
name|DEST_PORT_DROP
comment|/* Drop the packet in PBF. */
block|,
name|MAX_DEST_PORT_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet address type  */
end_comment

begin_enum
enum|enum
name|eth_addr_type
block|{
name|BROADCAST_ADDRESS
block|,
name|MULTICAST_ADDRESS
block|,
name|UNICAST_ADDRESS
block|,
name|UNKNOWN_ADDRESS
block|,
name|MAX_ETH_ADDR_TYPE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|eth_tx_1st_bd_flags
block|{
name|u8
name|bitfields
decl_stmt|;
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_START_BD_MASK
value|0x1
comment|/* Set to 1 in the first BD. (for debug) */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_START_BD_SHIFT
value|0
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_FORCE_VLAN_MODE_MASK
value|0x1
comment|/* Do not allow additional VLAN manipulations on this packet. */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_FORCE_VLAN_MODE_SHIFT
value|1
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_IP_CSUM_MASK
value|0x1
comment|/* Recalculate IP checksum. For tunneled packet - relevant to inner header. */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_IP_CSUM_SHIFT
value|2
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_L4_CSUM_MASK
value|0x1
comment|/* Recalculate TCP/UDP checksum. For tunneled packet - relevant to inner header. */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_L4_CSUM_SHIFT
value|3
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_VLAN_INSERTION_MASK
value|0x1
comment|/* If set, insert VLAN tag from vlan field to the packet. For tunneled packet - relevant to outer header. */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_VLAN_INSERTION_SHIFT
value|4
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_LSO_MASK
value|0x1
comment|/* If set, this is an LSO packet. Note: For Tunneled LSO packets, the offset of the inner IPV4 (and IPV6) header is limited to 253 (and 251 respectively) bytes, inclusive. */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_LSO_SHIFT
value|5
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_TUNN_IP_CSUM_MASK
value|0x1
comment|/* Recalculate Tunnel IP Checksum (if Tunnel IP Header is IPv4) */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_TUNN_IP_CSUM_SHIFT
value|6
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_TUNN_L4_CSUM_MASK
value|0x1
comment|/* Recalculate Tunnel UDP/GRE Checksum (Depending on Tunnel Type) */
define|#
directive|define
name|ETH_TX_1ST_BD_FLAGS_TUNN_L4_CSUM_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * The parsing information data for the first tx bd of a given packet.  */
end_comment

begin_struct
struct|struct
name|eth_tx_data_1st_bd
block|{
name|__le16
name|vlan
comment|/* VLAN tag to insert to packet (if enabled by vlan_insertion flag). */
decl_stmt|;
name|u8
name|nbds
comment|/* Number of BDs in packet. Should be at least 1 in non-LSO packet and at least 3 in LSO (or Tunnel with IPv6+ext) packet. */
decl_stmt|;
name|struct
name|eth_tx_1st_bd_flags
name|bd_flags
decl_stmt|;
name|__le16
name|bitfields
decl_stmt|;
define|#
directive|define
name|ETH_TX_DATA_1ST_BD_TUNN_FLAG_MASK
value|0x1
comment|/* Indicates a tunneled packet. Must be set for encapsulated packet. */
define|#
directive|define
name|ETH_TX_DATA_1ST_BD_TUNN_FLAG_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DATA_1ST_BD_RESERVED0_MASK
value|0x1
define|#
directive|define
name|ETH_TX_DATA_1ST_BD_RESERVED0_SHIFT
value|1
define|#
directive|define
name|ETH_TX_DATA_1ST_BD_PKT_LEN_MASK
value|0x3FFF
comment|/* Total packet length - must be filled for non-LSO packets. */
define|#
directive|define
name|ETH_TX_DATA_1ST_BD_PKT_LEN_SHIFT
value|2
block|}
struct|;
end_struct

begin_comment
comment|/*  * The parsing information data for the second tx bd of a given packet.  */
end_comment

begin_struct
struct|struct
name|eth_tx_data_2nd_bd
block|{
name|__le16
name|tunn_ip_size
comment|/* For tunnel with IPv6+ext - Tunnel header IP datagram length (in BYTEs) */
decl_stmt|;
name|__le16
name|bitfields1
decl_stmt|;
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_INNER_L2_HDR_SIZE_W_MASK
value|0xF
comment|/* For Tunnel header with IPv6 ext. - Inner L2 Header Size (in 2-byte WORDs) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_INNER_L2_HDR_SIZE_W_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_INNER_ETH_TYPE_MASK
value|0x3
comment|/* For Tunnel header with IPv6 ext. - Inner L2 Header MAC DA Type (use enum eth_addr_type) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_INNER_ETH_TYPE_SHIFT
value|4
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_DEST_PORT_MODE_MASK
value|0x3
comment|/* Destination port mode. (use enum dest_port_mode) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_DEST_PORT_MODE_SHIFT
value|6
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_START_BD_MASK
value|0x1
comment|/* Should be 0 in all the BDs, except the first one. (for debug) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_START_BD_SHIFT
value|8
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_TYPE_MASK
value|0x3
comment|/* For Tunnel header with IPv6 ext. - Tunnel Type (use enum eth_tx_tunn_type) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_TYPE_SHIFT
value|9
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_INNER_IPV6_MASK
value|0x1
comment|/* For LSO / Tunnel header with IPv6+ext - Set if inner header is IPv6 */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_INNER_IPV6_SHIFT
value|11
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_IPV6_EXT_MASK
value|0x1
comment|/* In tunneling mode - Set to 1 when the Inner header is IPv6 with extension. Otherwise set to 1 if the header is IPv6 with extension. */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_IPV6_EXT_SHIFT
value|12
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_IPV6_EXT_MASK
value|0x1
comment|/* Set to 1 if Tunnel (outer = encapsulating) header has IPv6 ext. (Note: 3rd BD is required, hence EDPM does not support Tunnel [outer] header with Ipv6Ext) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_TUNN_IPV6_EXT_SHIFT
value|13
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_L4_UDP_MASK
value|0x1
comment|/* Set if (inner) L4 protocol is UDP. (Required when IPv6+ext (or tunnel with inner or outer Ipv6+ext) and l4_csum is set) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_L4_UDP_SHIFT
value|14
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_L4_PSEUDO_CSUM_MODE_MASK
value|0x1
comment|/* The pseudo header checksum type in the L4 checksum field. Required when IPv6+ext and l4_csum is set. (use enum eth_l4_pseudo_checksum_mode) */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_L4_PSEUDO_CSUM_MODE_SHIFT
value|15
name|__le16
name|bitfields2
decl_stmt|;
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_L4_HDR_START_OFFSET_W_MASK
value|0x1FFF
comment|/* For inner/outer header IPv6+ext - (inner) L4 header offset (in 2-byte WORDs). For regular packet - offset from the beginning of the packet. For tunneled packet - offset from the beginning of the inner header */
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_L4_HDR_START_OFFSET_W_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_RESERVED0_MASK
value|0x7
define|#
directive|define
name|ETH_TX_DATA_2ND_BD_RESERVED0_SHIFT
value|13
block|}
struct|;
end_struct

begin_comment
comment|/*  * Firmware data for L2-EDPM packet.  */
end_comment

begin_struct
struct|struct
name|eth_edpm_fw_data
block|{
name|struct
name|eth_tx_data_1st_bd
name|data_1st_bd
comment|/* Parsing information data from the 1st BD. */
decl_stmt|;
name|struct
name|eth_tx_data_2nd_bd
name|data_2nd_bd
comment|/* Parsing information data from the 2nd BD. */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FW debug.  */
end_comment

begin_struct
struct|struct
name|eth_fast_path_cqe_fw_debug
block|{
name|__le16
name|reserved2
comment|/* FW reserved. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tunneling parsing flags  */
end_comment

begin_struct
struct|struct
name|eth_tunnel_parsing_flags
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_TYPE_MASK
value|0x3
comment|/* 0 - no tunneling, 1 - GENEVE, 2 - GRE, 3 - VXLAN (use enum eth_rx_tunn_type) */
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_TENNANT_ID_EXIST_MASK
value|0x1
comment|/*  If it s not an encapsulated packet then put 0x0. If it s an encapsulated packet but the tenant-id doesn t exist then put 0x0. Else put 0x1 */
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_TENNANT_ID_EXIST_SHIFT
value|2
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_NEXT_PROTOCOL_MASK
value|0x3
comment|/* Type of the next header above the tunneling: 0 - unknown, 1 - L2, 2 - Ipv4, 3 - IPv6 (use enum tunnel_next_protocol) */
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_NEXT_PROTOCOL_SHIFT
value|3
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_FIRSTHDRIPMATCH_MASK
value|0x1
comment|/* The result of comparing the DA-ip of the tunnel header. */
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_FIRSTHDRIPMATCH_SHIFT
value|5
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_IPV4_FRAGMENT_MASK
value|0x1
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_IPV4_FRAGMENT_SHIFT
value|6
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_IPV4_OPTIONS_MASK
value|0x1
define|#
directive|define
name|ETH_TUNNEL_PARSING_FLAGS_IPV4_OPTIONS_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * PMD flow control bits  */
end_comment

begin_struct
struct|struct
name|eth_pmd_flow_flags
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ETH_PMD_FLOW_FLAGS_VALID_MASK
value|0x1
comment|/* CQE valid bit */
define|#
directive|define
name|ETH_PMD_FLOW_FLAGS_VALID_SHIFT
value|0
define|#
directive|define
name|ETH_PMD_FLOW_FLAGS_TOGGLE_MASK
value|0x1
comment|/* CQE ring toggle bit */
define|#
directive|define
name|ETH_PMD_FLOW_FLAGS_TOGGLE_SHIFT
value|1
define|#
directive|define
name|ETH_PMD_FLOW_FLAGS_RESERVED_MASK
value|0x3F
define|#
directive|define
name|ETH_PMD_FLOW_FLAGS_RESERVED_SHIFT
value|2
block|}
struct|;
end_struct

begin_comment
comment|/*  * Regular ETH Rx FP CQE.   */
end_comment

begin_struct
struct|struct
name|eth_fast_path_rx_reg_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|bitfields
decl_stmt|;
define|#
directive|define
name|ETH_FAST_PATH_RX_REG_CQE_RSS_HASH_TYPE_MASK
value|0x7
comment|/* Type of calculated RSS hash (use enum rss_hash_type) */
define|#
directive|define
name|ETH_FAST_PATH_RX_REG_CQE_RSS_HASH_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_FAST_PATH_RX_REG_CQE_TC_MASK
value|0xF
comment|/* Traffic Class */
define|#
directive|define
name|ETH_FAST_PATH_RX_REG_CQE_TC_SHIFT
value|3
define|#
directive|define
name|ETH_FAST_PATH_RX_REG_CQE_RESERVED0_MASK
value|0x1
define|#
directive|define
name|ETH_FAST_PATH_RX_REG_CQE_RESERVED0_SHIFT
value|7
name|__le16
name|pkt_len
comment|/* Total packet length (from the parser) */
decl_stmt|;
name|struct
name|parsing_and_err_flags
name|pars_flags
comment|/* Parsing and error flags from the parser */
decl_stmt|;
name|__le16
name|vlan_tag
comment|/* 802.1q VLAN tag */
decl_stmt|;
name|__le32
name|rss_hash
comment|/* RSS hash result */
decl_stmt|;
name|__le16
name|len_on_first_bd
comment|/* Number of bytes placed on first BD */
decl_stmt|;
name|u8
name|placement_offset
comment|/* Offset of placement from BD start */
decl_stmt|;
name|struct
name|eth_tunnel_parsing_flags
name|tunnel_pars_flags
comment|/* Tunnel Parsing Flags */
decl_stmt|;
name|u8
name|bd_num
comment|/* Number of BDs, used for packet */
decl_stmt|;
name|u8
name|reserved
index|[
literal|9
index|]
decl_stmt|;
name|struct
name|eth_fast_path_cqe_fw_debug
name|fw_debug
comment|/* FW reserved. */
decl_stmt|;
name|u8
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|eth_pmd_flow_flags
name|pmd_flags
comment|/* CQE valid and toggle bits */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TPA-continue ETH Rx FP CQE.  */
end_comment

begin_struct
struct|struct
name|eth_fast_path_rx_tpa_cont_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|tpa_agg_index
comment|/* TPA aggregation index */
decl_stmt|;
name|__le16
name|len_list
index|[
name|ETH_TPA_CQE_CONT_LEN_LIST_SIZE
index|]
comment|/* List of the segment sizes */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
name|u8
name|reserved1
comment|/* FW reserved. */
decl_stmt|;
name|__le16
name|reserved2
index|[
name|ETH_TPA_CQE_CONT_LEN_LIST_SIZE
index|]
comment|/* FW reserved. */
decl_stmt|;
name|u8
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|eth_pmd_flow_flags
name|pmd_flags
comment|/* CQE valid and toggle bits */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TPA-end ETH Rx FP CQE .   */
end_comment

begin_struct
struct|struct
name|eth_fast_path_rx_tpa_end_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|tpa_agg_index
comment|/* TPA aggregation index */
decl_stmt|;
name|__le16
name|total_packet_len
comment|/* Total aggregated packet length */
decl_stmt|;
name|u8
name|num_of_bds
comment|/* Total number of BDs comprising the packet */
decl_stmt|;
name|u8
name|end_reason
comment|/* Aggregation end reason. Use enum eth_tpa_end_reason */
decl_stmt|;
name|__le16
name|num_of_coalesced_segs
comment|/* Number of coalesced TCP segments */
decl_stmt|;
name|__le32
name|ts_delta
comment|/* TCP timestamp delta */
decl_stmt|;
name|__le16
name|len_list
index|[
name|ETH_TPA_CQE_END_LEN_LIST_SIZE
index|]
comment|/* List of the segment sizes */
decl_stmt|;
name|__le16
name|reserved3
index|[
name|ETH_TPA_CQE_END_LEN_LIST_SIZE
index|]
comment|/* FW reserved. */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|u8
name|reserved2
comment|/* FW reserved. */
decl_stmt|;
name|struct
name|eth_pmd_flow_flags
name|pmd_flags
comment|/* CQE valid and toggle bits */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TPA-start ETH Rx FP CQE.  */
end_comment

begin_struct
struct|struct
name|eth_fast_path_rx_tpa_start_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|bitfields
decl_stmt|;
define|#
directive|define
name|ETH_FAST_PATH_RX_TPA_START_CQE_RSS_HASH_TYPE_MASK
value|0x7
comment|/* Type of calculated RSS hash (use enum rss_hash_type) */
define|#
directive|define
name|ETH_FAST_PATH_RX_TPA_START_CQE_RSS_HASH_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_FAST_PATH_RX_TPA_START_CQE_TC_MASK
value|0xF
comment|/* Traffic Class */
define|#
directive|define
name|ETH_FAST_PATH_RX_TPA_START_CQE_TC_SHIFT
value|3
define|#
directive|define
name|ETH_FAST_PATH_RX_TPA_START_CQE_RESERVED0_MASK
value|0x1
define|#
directive|define
name|ETH_FAST_PATH_RX_TPA_START_CQE_RESERVED0_SHIFT
value|7
name|__le16
name|seg_len
comment|/* Segment length (packetLen from the parser) */
decl_stmt|;
name|struct
name|parsing_and_err_flags
name|pars_flags
comment|/* Parsing and error flags from the parser */
decl_stmt|;
name|__le16
name|vlan_tag
comment|/* 802.1q VLAN tag */
decl_stmt|;
name|__le32
name|rss_hash
comment|/* RSS hash result */
decl_stmt|;
name|__le16
name|len_on_first_bd
comment|/* Number of bytes placed on first BD */
decl_stmt|;
name|u8
name|placement_offset
comment|/* Offset of placement from BD start */
decl_stmt|;
name|struct
name|eth_tunnel_parsing_flags
name|tunnel_pars_flags
comment|/* Tunnel Parsing Flags */
decl_stmt|;
name|u8
name|tpa_agg_index
comment|/* TPA aggregation index */
decl_stmt|;
name|u8
name|header_len
comment|/* Packet L2+L3+L4 header length */
decl_stmt|;
name|__le16
name|ext_bd_len_list
index|[
name|ETH_TPA_CQE_START_LEN_LIST_SIZE
index|]
comment|/* Additional BDs length list. */
decl_stmt|;
name|struct
name|eth_fast_path_cqe_fw_debug
name|fw_debug
comment|/* FW reserved. */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
name|struct
name|eth_pmd_flow_flags
name|pmd_flags
comment|/* CQE valid and toggle bits */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The L4 pseudo checksum mode for Ethernet  */
end_comment

begin_enum
enum|enum
name|eth_l4_pseudo_checksum_mode
block|{
name|ETH_L4_PSEUDO_CSUM_CORRECT_LENGTH
comment|/* Pseudo Header checksum on packet is calculated with the correct packet length field. */
block|,
name|ETH_L4_PSEUDO_CSUM_ZERO_LENGTH
comment|/* Pseudo Header checksum on packet is calculated with zero length field. */
block|,
name|MAX_ETH_L4_PSEUDO_CHECKSUM_MODE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|eth_rx_bd
block|{
name|struct
name|regpair
name|addr
comment|/* single continues buffer */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * regular ETH Rx SP CQE  */
end_comment

begin_struct
struct|struct
name|eth_slow_path_rx_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|ramrod_cmd_id
decl_stmt|;
name|u8
name|error_flag
decl_stmt|;
name|u8
name|reserved
index|[
literal|25
index|]
decl_stmt|;
name|__le16
name|echo
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|struct
name|eth_pmd_flow_flags
name|pmd_flags
comment|/* CQE valid and toggle bits */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for all ETH Rx CQE types  */
end_comment

begin_union
union|union
name|eth_rx_cqe
block|{
name|struct
name|eth_fast_path_rx_reg_cqe
name|fast_path_regular
comment|/* Regular FP CQE */
decl_stmt|;
name|struct
name|eth_fast_path_rx_tpa_start_cqe
name|fast_path_tpa_start
comment|/* TPA-start CQE */
decl_stmt|;
name|struct
name|eth_fast_path_rx_tpa_cont_cqe
name|fast_path_tpa_cont
comment|/* TPA-continue CQE */
decl_stmt|;
name|struct
name|eth_fast_path_rx_tpa_end_cqe
name|fast_path_tpa_end
comment|/* TPA-end CQE */
decl_stmt|;
name|struct
name|eth_slow_path_rx_cqe
name|slow_path
comment|/* SP CQE */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * ETH Rx CQE type  */
end_comment

begin_enum
enum|enum
name|eth_rx_cqe_type
block|{
name|ETH_RX_CQE_TYPE_UNUSED
block|,
name|ETH_RX_CQE_TYPE_REGULAR
comment|/* Regular FP ETH Rx CQE */
block|,
name|ETH_RX_CQE_TYPE_SLOW_PATH
comment|/* Slow path ETH Rx CQE */
block|,
name|ETH_RX_CQE_TYPE_TPA_START
comment|/* TPA start ETH Rx CQE */
block|,
name|ETH_RX_CQE_TYPE_TPA_CONT
comment|/* TPA Continue ETH Rx CQE */
block|,
name|ETH_RX_CQE_TYPE_TPA_END
comment|/* TPA end ETH Rx CQE */
block|,
name|MAX_ETH_RX_CQE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Wrapper for PD RX CQE - used in order to cover full cache line when writing CQE  */
end_comment

begin_struct
struct|struct
name|eth_rx_pmd_cqe
block|{
name|union
name|eth_rx_cqe
name|cqe
comment|/* CQE data itself */
decl_stmt|;
name|u8
name|reserved
index|[
name|ETH_RX_CQE_GAP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Eth RX Tunnel Type  */
end_comment

begin_enum
enum|enum
name|eth_rx_tunn_type
block|{
name|ETH_RX_NO_TUNN
comment|/* No Tunnel. */
block|,
name|ETH_RX_TUNN_GENEVE
comment|/* GENEVE Tunnel. */
block|,
name|ETH_RX_TUNN_GRE
comment|/* GRE Tunnel. */
block|,
name|ETH_RX_TUNN_VXLAN
comment|/* VXLAN Tunnel. */
block|,
name|MAX_ETH_RX_TUNN_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Aggregation end reason.  */
end_comment

begin_enum
enum|enum
name|eth_tpa_end_reason
block|{
name|ETH_AGG_END_UNUSED
block|,
name|ETH_AGG_END_SP_UPDATE
comment|/* SP configuration update */
block|,
name|ETH_AGG_END_MAX_LEN
comment|/* Maximum aggregation length or maximum buffer number used. */
block|,
name|ETH_AGG_END_LAST_SEG
comment|/* TCP PSH flag or TCP payload length below continue threshold. */
block|,
name|ETH_AGG_END_TIMEOUT
comment|/* Timeout expiration. */
block|,
name|ETH_AGG_END_NOT_CONSISTENT
comment|/* Packet header not consistency: different IPv4 TOS, TTL or flags, IPv6 TC, Hop limit or Flow label, TCP header length or TS options. In GRO different TS value, SMAC, DMAC, ackNum, windowSize or VLAN */
block|,
name|ETH_AGG_END_OUT_OF_ORDER
comment|/* Out of order or retransmission packet: sequence, ack or timestamp not consistent with previous segment. */
block|,
name|ETH_AGG_END_NON_TPA_SEG
comment|/* Next segment cant be aggregated due to LLC/SNAP, IP error, IP fragment, IPv4 options, IPv6 extension, IP ECN = CE, TCP errors, TCP options, zero TCP payload length , TCP flags or not supported tunnel header options.  */
block|,
name|MAX_ETH_TPA_END_REASON
block|}
enum|;
end_enum

begin_comment
comment|/*  * The first tx bd of a given packet  */
end_comment

begin_struct
struct|struct
name|eth_tx_1st_bd
block|{
name|struct
name|regpair
name|addr
comment|/* Single continuous buffer */
decl_stmt|;
name|__le16
name|nbytes
comment|/* Number of bytes in this BD. */
decl_stmt|;
name|struct
name|eth_tx_data_1st_bd
name|data
comment|/* Parsing information data. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The second tx bd of a given packet  */
end_comment

begin_struct
struct|struct
name|eth_tx_2nd_bd
block|{
name|struct
name|regpair
name|addr
comment|/* Single continuous buffer */
decl_stmt|;
name|__le16
name|nbytes
comment|/* Number of bytes in this BD. */
decl_stmt|;
name|struct
name|eth_tx_data_2nd_bd
name|data
comment|/* Parsing information data. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The parsing information data for the third tx bd of a given packet.  */
end_comment

begin_struct
struct|struct
name|eth_tx_data_3rd_bd
block|{
name|__le16
name|lso_mss
comment|/* For LSO packet - the MSS in bytes. */
decl_stmt|;
name|__le16
name|bitfields
decl_stmt|;
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_TCP_HDR_LEN_DW_MASK
value|0xF
comment|/* For LSO with inner/outer IPv6+ext - TCP header length (in 4-byte WORDs) */
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_TCP_HDR_LEN_DW_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_HDR_NBD_MASK
value|0xF
comment|/* LSO - number of BDs which contain headers. value should be in range (1..ETH_TX_MAX_LSO_HDR_NBD). */
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_HDR_NBD_SHIFT
value|4
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_START_BD_MASK
value|0x1
comment|/* Should be 0 in all the BDs, except the first one. (for debug) */
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_START_BD_SHIFT
value|8
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_RESERVED0_MASK
value|0x7F
define|#
directive|define
name|ETH_TX_DATA_3RD_BD_RESERVED0_SHIFT
value|9
name|u8
name|tunn_l4_hdr_start_offset_w
comment|/* For tunnel with IPv6+ext - Pointer to the tunnel L4 Header (in 2-byte WORDs) */
decl_stmt|;
name|u8
name|tunn_hdr_size_w
comment|/* For tunnel with IPv6+ext - Total size of the Tunnel Header (in 2-byte WORDs) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The third tx bd of a given packet  */
end_comment

begin_struct
struct|struct
name|eth_tx_3rd_bd
block|{
name|struct
name|regpair
name|addr
comment|/* Single continuous buffer */
decl_stmt|;
name|__le16
name|nbytes
comment|/* Number of bytes in this BD. */
decl_stmt|;
name|struct
name|eth_tx_data_3rd_bd
name|data
comment|/* Parsing information data. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Complementary information for the regular tx bd of a given packet.  */
end_comment

begin_struct
struct|struct
name|eth_tx_data_bd
block|{
name|__le16
name|reserved0
decl_stmt|;
name|__le16
name|bitfields
decl_stmt|;
define|#
directive|define
name|ETH_TX_DATA_BD_RESERVED1_MASK
value|0xFF
define|#
directive|define
name|ETH_TX_DATA_BD_RESERVED1_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DATA_BD_START_BD_MASK
value|0x1
comment|/* Should be 0 in all the BDs, except the first one. (for debug) */
define|#
directive|define
name|ETH_TX_DATA_BD_START_BD_SHIFT
value|8
define|#
directive|define
name|ETH_TX_DATA_BD_RESERVED2_MASK
value|0x7F
define|#
directive|define
name|ETH_TX_DATA_BD_RESERVED2_SHIFT
value|9
name|__le16
name|reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The common regular TX BD ring element  */
end_comment

begin_struct
struct|struct
name|eth_tx_bd
block|{
name|struct
name|regpair
name|addr
comment|/* Single continuous buffer */
decl_stmt|;
name|__le16
name|nbytes
comment|/* Number of bytes in this BD. */
decl_stmt|;
name|struct
name|eth_tx_data_bd
name|data
comment|/* Complementary information. */
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|eth_tx_bd_types
block|{
name|struct
name|eth_tx_1st_bd
name|first_bd
comment|/* The first tx bd of a given packet */
decl_stmt|;
name|struct
name|eth_tx_2nd_bd
name|second_bd
comment|/* The second tx bd of a given packet */
decl_stmt|;
name|struct
name|eth_tx_3rd_bd
name|third_bd
comment|/* The third tx bd of a given packet */
decl_stmt|;
name|struct
name|eth_tx_bd
name|reg_bd
comment|/* The common non-special bd */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Eth Tx Tunnel Type  */
end_comment

begin_enum
enum|enum
name|eth_tx_tunn_type
block|{
name|ETH_TX_TUNN_GENEVE
comment|/* GENEVE Tunnel. */
block|,
name|ETH_TX_TUNN_TTAG
comment|/* T-Tag Tunnel. */
block|,
name|ETH_TX_TUNN_GRE
comment|/* GRE Tunnel. */
block|,
name|ETH_TX_TUNN_VXLAN
comment|/* VXLAN Tunnel. */
block|,
name|MAX_ETH_TX_TUNN_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ystorm Queue Zone  */
end_comment

begin_struct
struct|struct
name|xstorm_eth_queue_zone
block|{
name|struct
name|coalescing_timeset
name|int_coalescing_timeset
comment|/* Tx interrupt coalescing TimeSet */
decl_stmt|;
name|u8
name|reserved
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ETH doorbell data  */
end_comment

begin_struct
struct|struct
name|eth_db_data
block|{
name|u8
name|params
decl_stmt|;
define|#
directive|define
name|ETH_DB_DATA_DEST_MASK
value|0x3
comment|/* destination of doorbell (use enum db_dest) */
define|#
directive|define
name|ETH_DB_DATA_DEST_SHIFT
value|0
define|#
directive|define
name|ETH_DB_DATA_AGG_CMD_MASK
value|0x3
comment|/* aggregative command to CM (use enum db_agg_cmd_sel) */
define|#
directive|define
name|ETH_DB_DATA_AGG_CMD_SHIFT
value|2
define|#
directive|define
name|ETH_DB_DATA_BYPASS_EN_MASK
value|0x1
comment|/* enable QM bypass */
define|#
directive|define
name|ETH_DB_DATA_BYPASS_EN_SHIFT
value|4
define|#
directive|define
name|ETH_DB_DATA_RESERVED_MASK
value|0x1
define|#
directive|define
name|ETH_DB_DATA_RESERVED_SHIFT
value|5
define|#
directive|define
name|ETH_DB_DATA_AGG_VAL_SEL_MASK
value|0x3
comment|/* aggregative value selection */
define|#
directive|define
name|ETH_DB_DATA_AGG_VAL_SEL_SHIFT
value|6
name|u8
name|agg_flags
comment|/* bit for every DQ counter flags in CM context that DQ can increment */
decl_stmt|;
name|__le16
name|bd_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ETH_COMMON__ */
end_comment

end_unit

