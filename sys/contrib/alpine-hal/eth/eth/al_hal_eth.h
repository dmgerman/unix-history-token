begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_eth_api API  * Ethernet Controller HAL driver API  * @ingroup group_eth  * @{  * @file   al_hal_eth.h  *  * @brief Header file for Unified GbE and 10GbE Ethernet Controllers This is a  * common header file that covers both Standard and Advanced Controller  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_ETH_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_ETH_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_common.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_udma.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_eth_alu.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AL_ETH_EX
end_ifdef

begin_include
include|#
directive|include
file|"al_hal_eth_ex.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_eth_ex_internal.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* *INDENT-ON* */
ifndef|#
directive|ifndef
name|AL_ETH_PKT_MAX_BUFS
ifndef|#
directive|ifndef
name|AL_ETH_EX
define|#
directive|define
name|AL_ETH_PKT_MAX_BUFS
value|19
else|#
directive|else
define|#
directive|define
name|AL_ETH_PKT_MAX_BUFS
value|30
endif|#
directive|endif
endif|#
directive|endif
define|#
directive|define
name|AL_ETH_UDMA_TX_QUEUES
value|4
define|#
directive|define
name|AL_ETH_UDMA_RX_QUEUES
value|4
comment|/* PCI Adapter Device/Revision ID */
define|#
directive|define
name|AL_ETH_DEV_ID_STANDARD
value|0x0001
define|#
directive|define
name|AL_ETH_DEV_ID_ADVANCED
value|0x0002
define|#
directive|define
name|AL_ETH_REV_ID_0
value|0
comment|/* Alpine V1 Rev 0 */
define|#
directive|define
name|AL_ETH_REV_ID_1
value|1
comment|/* Alpine V1 Rev 1 */
define|#
directive|define
name|AL_ETH_REV_ID_2
value|2
comment|/* Alpine V2 basic */
define|#
directive|define
name|AL_ETH_REV_ID_3
value|3
comment|/* Alpine V2 advanced */
comment|/* PCI BARs */
define|#
directive|define
name|AL_ETH_UDMA_BAR
value|0
define|#
directive|define
name|AL_ETH_EC_BAR
value|4
define|#
directive|define
name|AL_ETH_MAC_BAR
value|2
define|#
directive|define
name|AL_ETH_MAX_FRAME_LEN
value|10000
define|#
directive|define
name|AL_ETH_MIN_FRAME_LEN
value|60
define|#
directive|define
name|AL_ETH_TSO_MSS_MAX_IDX
value|8
define|#
directive|define
name|AL_ETH_TSO_MSS_MIN_VAL
value|1
comment|/*TODO: update with correct value*/
define|#
directive|define
name|AL_ETH_TSO_MSS_MAX_VAL
value|(AL_ETH_MAX_FRAME_LEN - 200)
enum|enum
name|AL_ETH_PROTO_ID
block|{
name|AL_ETH_PROTO_ID_UNKNOWN
init|=
literal|0
block|,
name|AL_ETH_PROTO_ID_IPv4
init|=
literal|8
block|,
name|AL_ETH_PROTO_ID_IPv6
init|=
literal|11
block|,
name|AL_ETH_PROTO_ID_TCP
init|=
literal|12
block|,
name|AL_ETH_PROTO_ID_UDP
init|=
literal|13
block|,
name|AL_ETH_PROTO_ID_FCOE
init|=
literal|21
block|,
name|AL_ETH_PROTO_ID_GRH
init|=
literal|22
block|,
comment|/** RoCE l3 header */
name|AL_ETH_PROTO_ID_BTH
init|=
literal|23
block|,
comment|/** RoCE l4 header */
name|AL_ETH_PROTO_ID_ANY
init|=
literal|32
block|,
comment|/**< for sw usage only */
block|}
enum|;
define|#
directive|define
name|AL_ETH_PROTOCOLS_NUM
value|(AL_ETH_PROTO_ID_ANY)
enum|enum
name|AL_ETH_TX_TUNNEL_MODE
block|{
name|AL_ETH_NO_TUNNELING
init|=
literal|0
block|,
name|AL_ETH_TUNNEL_NO_UDP
init|=
literal|1
block|,
comment|/* NVGRE / IP over IP */
name|AL_ETH_TUNNEL_WITH_UDP
init|=
literal|3
block|,
comment|/* VXLAN */
block|}
enum|;
define|#
directive|define
name|AL_ETH_RX_THASH_TABLE_SIZE
value|(1<< 8)
define|#
directive|define
name|AL_ETH_RX_FSM_TABLE_SIZE
value|(1<< 7)
define|#
directive|define
name|AL_ETH_RX_CTRL_TABLE_SIZE
value|(1<< 11)
define|#
directive|define
name|AL_ETH_RX_HASH_KEY_NUM
value|10
define|#
directive|define
name|AL_ETH_FWD_MAC_NUM
value|32
define|#
directive|define
name|AL_ETH_FWD_MAC_HASH_NUM
value|256
define|#
directive|define
name|AL_ETH_FWD_PBITS_TABLE_NUM
value|(1<< 3)
define|#
directive|define
name|AL_ETH_FWD_PRIO_TABLE_NUM
value|(1<< 3)
define|#
directive|define
name|AL_ETH_FWD_VID_TABLE_NUM
value|(1<< 12)
define|#
directive|define
name|AL_ETH_FWD_DSCP_TABLE_NUM
value|(1<< 8)
define|#
directive|define
name|AL_ETH_FWD_TC_TABLE_NUM
value|(1<< 8)
comment|/** MAC media mode */
enum|enum
name|al_eth_mac_mode
block|{
name|AL_ETH_MAC_MODE_RGMII
block|,
name|AL_ETH_MAC_MODE_SGMII
block|,
name|AL_ETH_MAC_MODE_SGMII_2_5G
block|,
name|AL_ETH_MAC_MODE_10GbE_Serial
block|,
comment|/**< Applies to XFI and KR modes */
name|AL_ETH_MAC_MODE_10G_SGMII
block|,
comment|/**< SGMII using the 10G MAC, don't use*/
name|AL_ETH_MAC_MODE_XLG_LL_40G
block|,
comment|/**< applies to 40G mode using the 40G low latency (LL) MAC */
name|AL_ETH_MAC_MODE_KR_LL_25G
block|,
comment|/**< applies to 25G mode using the 10/25G low latency (LL) MAC */
name|AL_ETH_MAC_MODE_XLG_LL_50G
block|,
comment|/**< applies to 50G mode using the 40/50G low latency (LL) MAC */
name|AL_ETH_MAC_MODE_XLG_LL_25G
comment|/**< applies to 25G mode using the 40/50G low latency (LL) MAC */
block|}
enum|;
struct|struct
name|al_eth_capabilities
block|{
name|al_bool
name|speed_10_HD
decl_stmt|;
name|al_bool
name|speed_10_FD
decl_stmt|;
name|al_bool
name|speed_100_HD
decl_stmt|;
name|al_bool
name|speed_100_FD
decl_stmt|;
name|al_bool
name|speed_1000_HD
decl_stmt|;
name|al_bool
name|speed_1000_FD
decl_stmt|;
name|al_bool
name|speed_10000_HD
decl_stmt|;
name|al_bool
name|speed_10000_FD
decl_stmt|;
name|al_bool
name|pfc
decl_stmt|;
comment|/**< priority flow control */
name|al_bool
name|eee
decl_stmt|;
comment|/**< Energy Efficient Ethernet */
block|}
struct|;
comment|/** interface type used for MDIO */
enum|enum
name|al_eth_mdio_if
block|{
name|AL_ETH_MDIO_IF_1G_MAC
init|=
literal|0
block|,
name|AL_ETH_MDIO_IF_10G_MAC
init|=
literal|1
block|}
enum|;
comment|/** MDIO protocol type */
enum|enum
name|al_eth_mdio_type
block|{
name|AL_ETH_MDIO_TYPE_CLAUSE_22
init|=
literal|0
block|,
name|AL_ETH_MDIO_TYPE_CLAUSE_45
init|=
literal|1
block|}
enum|;
comment|/** flow control mode */
enum|enum
name|al_eth_flow_control_type
block|{
name|AL_ETH_FLOW_CONTROL_TYPE_LINK_PAUSE
block|,
name|AL_ETH_FLOW_CONTROL_TYPE_PFC
block|}
enum|;
comment|/** Tx to Rx switching decision type */
enum|enum
name|al_eth_tx_switch_dec_type
block|{
name|AL_ETH_TX_SWITCH_TYPE_MAC
init|=
literal|0
block|,
name|AL_ETH_TX_SWITCH_TYPE_VLAN_TABLE
init|=
literal|1
block|,
name|AL_ETH_TX_SWITCH_TYPE_VLAN_TABLE_AND_MAC
init|=
literal|2
block|,
name|AL_ETH_TX_SWITCH_TYPE_BITMAP
init|=
literal|3
block|}
enum|;
comment|/** Tx to Rx VLAN ID selection type */
enum|enum
name|al_eth_tx_switch_vid_sel_type
block|{
name|AL_ETH_TX_SWITCH_VID_SEL_TYPE_VLAN1
init|=
literal|0
block|,
name|AL_ETH_TX_SWITCH_VID_SEL_TYPE_VLAN2
init|=
literal|1
block|,
name|AL_ETH_TX_SWITCH_VID_SEL_TYPE_NEW_VLAN1
init|=
literal|2
block|,
name|AL_ETH_TX_SWITCH_VID_SEL_TYPE_NEW_VLAN2
init|=
literal|3
block|,
name|AL_ETH_TX_SWITCH_VID_SEL_TYPE_DEFAULT_VLAN1
init|=
literal|4
block|,
name|AL_ETH_TX_SWITCH_VID_SEL_TYPE_FINAL_VLAN1
init|=
literal|5
block|}
enum|;
comment|/** Rx descriptor configurations */
comment|/* Note: when selecting rx descriptor field to inner packet, then that field * will be set according to inner packet when packet is tunneled, for non-tunneled * packets, the field will be set according to the packets header */
comment|/** selection of the LRO_context_value result in the Metadata */
enum|enum
name|al_eth_rx_desc_lro_context_val_res
block|{
name|AL_ETH_LRO_CONTEXT_VALUE
init|=
literal|0
block|,
comment|/**< LRO_context_value */
name|AL_ETH_L4_OFFSET
init|=
literal|1
block|,
comment|/**< L4_offset */
block|}
enum|;
comment|/** selection of the L4 offset in the Metadata */
enum|enum
name|al_eth_rx_desc_l4_offset_sel
block|{
name|AL_ETH_L4_OFFSET_OUTER
init|=
literal|0
block|,
comment|/**< set L4 offset of the outer packet */
name|AL_ETH_L4_OFFSET_INNER
init|=
literal|1
block|,
comment|/**< set L4 offset of the inner packet */
block|}
enum|;
comment|/** selection of the L4 checksum result in the Metadata */
enum|enum
name|al_eth_rx_desc_l4_chk_res_sel
block|{
name|AL_ETH_L4_INNER_CHK
init|=
literal|0
block|,
comment|/**< L4 checksum */
name|AL_ETH_L4_INNER_OUTER_CHK
init|=
literal|1
block|,
comment|/**< Logic AND between outer and inner 					    L4 checksum result */
block|}
enum|;
comment|/** selection of the L3 checksum result in the Metadata */
enum|enum
name|al_eth_rx_desc_l3_chk_res_sel
block|{
name|AL_ETH_L3_CHK_TYPE_0
init|=
literal|0
block|,
comment|/**< L3 checksum */
name|AL_ETH_L3_CHK_TYPE_1
init|=
literal|1
block|,
comment|/**< L3 checksum or RoCE/FCoE CRC, 				       based on outer header */
name|AL_ETH_L3_CHK_TYPE_2
init|=
literal|2
block|,
comment|/**< If tunnel exist = 0, 					  L3 checksum or RoCE/FCoE CRC, 					  based on outer header. 				       Else, 					  logic AND between outer L3 checksum 					  (Ipv4) and inner CRC (RoCE or FcoE) */
name|AL_ETH_L3_CHK_TYPE_3
init|=
literal|3
block|,
comment|/**< combination of the L3 checksum result and 				       CRC result,based on the checksum and 				       RoCE/FCoE CRC input selections. */
block|}
enum|;
comment|/** selection of the L3 protocol index in the Metadata */
enum|enum
name|al_eth_rx_desc_l3_proto_idx_sel
block|{
name|AL_ETH_L3_PROTO_IDX_OUTER
init|=
literal|0
block|,
comment|/**< set L3 proto index of the outer packet */
name|AL_ETH_L3_PROTO_IDX_INNER
init|=
literal|1
block|,
comment|/**< set L3 proto index of the inner packet */
block|}
enum|;
comment|/** selection of the L3 offset in the Metadata */
enum|enum
name|al_eth_rx_desc_l3_offset_sel
block|{
name|AL_ETH_L3_OFFSET_OUTER
init|=
literal|0
block|,
comment|/**< set L3 offset of the outer packet */
name|AL_ETH_L3_OFFSET_INNER
init|=
literal|1
block|,
comment|/**< set L3 offset of the inner packet */
block|}
enum|;
comment|/** selection of the L4 protocol index in the Metadata */
enum|enum
name|al_eth_rx_desc_l4_proto_idx_sel
block|{
name|AL_ETH_L4_PROTO_IDX_OUTER
init|=
literal|0
block|,
comment|/**< set L4 proto index of the outer packet */
name|AL_ETH_L4_PROTO_IDX_INNER
init|=
literal|1
block|,
comment|/**< set L4 proto index of the inner packet */
block|}
enum|;
comment|/** selection of the frag indication in the Metadata */
enum|enum
name|al_eth_rx_desc_frag_sel
block|{
name|AL_ETH_FRAG_OUTER
init|=
literal|0
block|,
comment|/**< set frag of the outer packet */
name|AL_ETH_FRAG_INNER
init|=
literal|1
block|,
comment|/**< set frag of the inner packet */
block|}
enum|;
comment|/** Ethernet Rx completion descriptor */
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ctrl_meta
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|word2
decl_stmt|;
name|uint32_t
name|word3
decl_stmt|;
block|}
name|al_eth_rx_cdesc
typedef|;
comment|/** Flow Contol parameters */
struct|struct
name|al_eth_flow_control_params
block|{
name|enum
name|al_eth_flow_control_type
name|type
decl_stmt|;
comment|/**< flow control type */
name|al_bool
name|obay_enable
decl_stmt|;
comment|/**< stop tx when pause received */
name|al_bool
name|gen_enable
decl_stmt|;
comment|/**< generate pause frames */
name|uint16_t
name|rx_fifo_th_high
decl_stmt|;
name|uint16_t
name|rx_fifo_th_low
decl_stmt|;
name|uint16_t
name|quanta
decl_stmt|;
name|uint16_t
name|quanta_th
decl_stmt|;
name|uint8_t
name|prio_q_map
index|[
literal|4
index|]
index|[
literal|8
index|]
decl_stmt|;
comment|/**< for each UDMA, defines the mapping between 					   * PFC priority and queues(in bit mask). 					   * same mapping used for obay and generation. 					   * for example: 					   * if prio_q_map[1][7] = 0xC, then TX queues 2 					   * and 3 of UDMA 1 will be stopped when pause 					   * received with priority 7, also, when RX queues 					   * 2 and 3 of UDMA 1 become almost full, then 					   * pause frame with priority 7 will be sent. 					   * 					   *note: 					   * 1) if specific a queue is not used, the caller must 					   * make set the prio_q_map to 0 otherwise that queue 					   * will make the controller keep sending PAUSE packets. 					   * 2) queues of unused UDMA must be treated as above. 					   * 3) when working in LINK PAUSE mode, only entries at 					   * priority 0 will be considered. 					   */
block|}
struct|;
comment|/* Packet Tx flags */
define|#
directive|define
name|AL_ETH_TX_FLAGS_TSO
value|AL_BIT(7)
comment|/**< Enable TCP/UDP segmentation offloading */
define|#
directive|define
name|AL_ETH_TX_FLAGS_IPV4_L3_CSUM
value|AL_BIT(13)
comment|/**< Enable IPv4 header checksum calculation */
define|#
directive|define
name|AL_ETH_TX_FLAGS_L4_CSUM
value|AL_BIT(14)
comment|/**< Enable TCP/UDP checksum calculation */
define|#
directive|define
name|AL_ETH_TX_FLAGS_L4_PARTIAL_CSUM
value|AL_BIT(17)
comment|/**< L4 partial checksum calculation */
define|#
directive|define
name|AL_ETH_TX_FLAGS_L2_MACSEC_PKT
value|AL_BIT(16)
comment|/**< L2 Packet type 802_3 or 802_3_MACSEC, V2 */
define|#
directive|define
name|AL_ETH_TX_FLAGS_ENCRYPT
value|AL_BIT(16)
comment|/**< Enable TX packet encryption, V3 */
define|#
directive|define
name|AL_ETH_TX_FLAGS_L2_DIS_FCS
value|AL_BIT(15)
comment|/**< Disable CRC calculation*/
define|#
directive|define
name|AL_ETH_TX_FLAGS_TS
value|AL_BIT(21)
comment|/**< Timestamp the packet */
define|#
directive|define
name|AL_ETH_TX_FLAGS_INT
value|AL_M2S_DESC_INT_EN
define|#
directive|define
name|AL_ETH_TX_FLAGS_NO_SNOOP
value|AL_M2S_DESC_NO_SNOOP_H
comment|/** this structure used for tx packet meta data */
struct|struct
name|al_eth_meta_data
block|{
name|uint8_t
name|store
range|:
literal|1
decl_stmt|;
comment|/**< store the meta into the queues cache */
name|uint8_t
name|words_valid
range|:
literal|4
decl_stmt|;
comment|/**< valid bit per word */
name|uint8_t
name|vlan1_cfi_sel
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan2_vid_sel
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan2_cfi_sel
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan2_pbits_sel
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan2_ether_sel
range|:
literal|2
decl_stmt|;
name|uint16_t
name|vlan1_new_vid
range|:
literal|12
decl_stmt|;
name|uint8_t
name|vlan1_new_cfi
range|:
literal|1
decl_stmt|;
name|uint8_t
name|vlan1_new_pbits
range|:
literal|3
decl_stmt|;
name|uint16_t
name|vlan2_new_vid
range|:
literal|12
decl_stmt|;
name|uint8_t
name|vlan2_new_cfi
range|:
literal|1
decl_stmt|;
name|uint8_t
name|vlan2_new_pbits
range|:
literal|3
decl_stmt|;
name|uint8_t
name|l3_header_len
decl_stmt|;
comment|/**< in bytes */
name|uint8_t
name|l3_header_offset
decl_stmt|;
name|uint8_t
name|l4_header_len
decl_stmt|;
comment|/**< in words(32-bits) */
comment|/* rev 0 specific */
name|uint8_t
name|mss_idx_sel
range|:
literal|3
decl_stmt|;
comment|/**< for TSO, select the register that holds the MSS */
comment|/* rev 1 specific */
name|uint8_t
name|ts_index
range|:
literal|4
decl_stmt|;
comment|/**< index of regiser where to store the tx timestamp */
name|uint16_t
name|mss_val
range|:
literal|14
decl_stmt|;
comment|/**< for TSO, set the mss value */
name|uint8_t
name|outer_l3_offset
decl_stmt|;
comment|/**< for tunneling mode. up to 64 bytes */
name|uint8_t
name|outer_l3_len
decl_stmt|;
comment|/**< for tunneling mode. up to 128 bytes */
block|}
struct|;
comment|/* Packet Rx flags when adding buffer to receive queue */
comment|/**<  * Target-ID to be assigned to the packet descriptors  * Requires Target-ID in descriptor to be enabled for the specific UDMA  * queue.  */
define|#
directive|define
name|AL_ETH_RX_FLAGS_TGTID_MASK
value|AL_FIELD_MASK(15, 0)
define|#
directive|define
name|AL_ETH_RX_FLAGS_NO_SNOOP
value|AL_M2S_DESC_NO_SNOOP_H
define|#
directive|define
name|AL_ETH_RX_FLAGS_INT
value|AL_M2S_DESC_INT_EN
define|#
directive|define
name|AL_ETH_RX_FLAGS_DUAL_BUF
value|AL_BIT(31)
comment|/* Packet Rx flags set by HW when receiving packet */
define|#
directive|define
name|AL_ETH_RX_ERROR
value|AL_BIT(16)
comment|/**< layer 2 errors (FCS, bad len, etc) */
define|#
directive|define
name|AL_ETH_RX_FLAGS_L4_CSUM_ERR
value|AL_BIT(14)
define|#
directive|define
name|AL_ETH_RX_FLAGS_L3_CSUM_ERR
value|AL_BIT(13)
comment|/* Packet Rx flags - word 3 in Rx completion descriptor */
define|#
directive|define
name|AL_ETH_RX_FLAGS_CRC
value|AL_BIT(31)
define|#
directive|define
name|AL_ETH_RX_FLAGS_L3_CSUM_2
value|AL_BIT(30)
define|#
directive|define
name|AL_ETH_RX_FLAGS_L4_CSUM_2
value|AL_BIT(29)
define|#
directive|define
name|AL_ETH_RX_FLAGS_SW_SRC_PORT_SHIFT
value|13
define|#
directive|define
name|AL_ETH_RX_FLAGS_SW_SRC_PORT_MASK
value|AL_FIELD_MASK(15, 13)
define|#
directive|define
name|AL_ETH_RX_FLAGS_LRO_CONTEXT_VAL_SHIFT
value|3
define|#
directive|define
name|AL_ETH_RX_FLAGS_LRO_CONTEXT_VAL_MASK
value|AL_FIELD_MASK(10, 3)
define|#
directive|define
name|AL_ETH_RX_FLAGS_L4_OFFSET_SHIFT
value|3
define|#
directive|define
name|AL_ETH_RX_FLAGS_L4_OFFSET_MASK
value|AL_FIELD_MASK(10, 3)
define|#
directive|define
name|AL_ETH_RX_FLAGS_PRIORITY_SHIFT
value|0
define|#
directive|define
name|AL_ETH_RX_FLAGS_PRIORITY_MASK
value|AL_FIELD_MASK(2, 0)
comment|/** packet structure. used for packet transmission and reception */
struct|struct
name|al_eth_pkt
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/**< see flags above, depends on context(tx or rx) */
name|enum
name|AL_ETH_PROTO_ID
name|l3_proto_idx
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|l4_proto_idx
decl_stmt|;
name|uint8_t
name|source_vlan_count
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan_mod_add_count
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan_mod_del_count
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan_mod_v1_ether_sel
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan_mod_v1_vid_sel
range|:
literal|2
decl_stmt|;
name|uint8_t
name|vlan_mod_v1_pbits_sel
range|:
literal|2
decl_stmt|;
comment|/* rev 1 specific */
name|enum
name|AL_ETH_TX_TUNNEL_MODE
name|tunnel_mode
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|outer_l3_proto_idx
decl_stmt|;
comment|/**< for tunneling mode */
comment|/**< 	 * Target-ID to be assigned to the packet descriptors 	 * Requires Target-ID in descriptor to be enabled for the specific UDMA 	 * queue. 	 */
name|uint16_t
name|tgtid
decl_stmt|;
name|uint32_t
name|rx_header_len
decl_stmt|;
comment|/**< header buffer length of rx packet, not used */
name|struct
name|al_eth_meta_data
modifier|*
name|meta
decl_stmt|;
comment|/**< if null, then no meta added */
ifdef|#
directive|ifdef
name|AL_ETH_RX_DESC_RAW_GET
name|uint32_t
name|rx_desc_raw
index|[
literal|4
index|]
decl_stmt|;
endif|#
directive|endif
name|uint16_t
name|rxhash
decl_stmt|;
name|uint16_t
name|l3_offset
decl_stmt|;
ifdef|#
directive|ifdef
name|AL_ETH_EX
name|struct
name|al_eth_ext_metadata
modifier|*
name|ext_meta_data
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|num_of_bufs
decl_stmt|;
name|struct
name|al_buf
name|bufs
index|[
name|AL_ETH_PKT_MAX_BUFS
index|]
decl_stmt|;
block|}
struct|;
struct_decl|struct
name|al_ec_regs
struct_decl|;
comment|/** Ethernet Adapter private data structure used by this driver */
struct|struct
name|al_hal_eth_adapter
block|{
name|uint8_t
name|rev_id
decl_stmt|;
comment|/**<PCI adapter revision ID */
name|uint8_t
name|udma_id
decl_stmt|;
comment|/**< the id of the UDMA used by this adapter */
name|struct
name|unit_regs
name|__iomem
modifier|*
name|unit_regs
decl_stmt|;
name|void
name|__iomem
modifier|*
name|udma_regs_base
decl_stmt|;
name|struct
name|al_ec_regs
name|__iomem
modifier|*
name|ec_regs_base
decl_stmt|;
name|void
name|__iomem
modifier|*
name|ec_ints_base
decl_stmt|;
name|struct
name|al_eth_mac_regs
name|__iomem
modifier|*
name|mac_regs_base
decl_stmt|;
name|struct
name|interrupt_controller_ctrl
name|__iomem
modifier|*
name|mac_ints_base
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< the upper layer must keep the string area */
name|struct
name|al_udma
name|tx_udma
decl_stmt|;
comment|/*	uint8_t tx_queues;*/
comment|/* number of tx queues */
name|struct
name|al_udma
name|rx_udma
decl_stmt|;
comment|/*	uint8_t rx_queues;*/
comment|/* number of tx queues */
name|uint8_t
name|enable_rx_parser
decl_stmt|;
comment|/**< config and enable rx parsing */
name|enum
name|al_eth_flow_control_type
name|fc_type
decl_stmt|;
comment|/**< flow control*/
name|enum
name|al_eth_mac_mode
name|mac_mode
decl_stmt|;
name|enum
name|al_eth_mdio_if
name|mdio_if
decl_stmt|;
comment|/**< which mac mdio interface to use */
name|enum
name|al_eth_mdio_type
name|mdio_type
decl_stmt|;
comment|/**< mdio protocol type */
name|al_bool
name|shared_mdio_if
decl_stmt|;
comment|/**< when AL_TRUE, the mdio interface is shared with other controllers.*/
name|uint8_t
name|curr_lt_unit
decl_stmt|;
name|uint8_t
name|serdes_lane
decl_stmt|;
ifdef|#
directive|ifdef
name|AL_ETH_EX
name|struct
name|al_eth_ex_state
name|ex_state
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
comment|/** parameters from upper layer */
struct|struct
name|al_eth_adapter_params
block|{
name|uint8_t
name|rev_id
decl_stmt|;
comment|/**<PCI adapter revision ID */
name|uint8_t
name|udma_id
decl_stmt|;
comment|/**< the id of the UDMA used by this adapter */
name|uint8_t
name|enable_rx_parser
decl_stmt|;
comment|/**< when true, the rx epe parser will be enabled */
name|void
name|__iomem
modifier|*
name|udma_regs_base
decl_stmt|;
comment|/**< UDMA register base address */
name|void
name|__iomem
modifier|*
name|ec_regs_base
decl_stmt|;
comment|/**< Ethernet controller registers base address 				     * can be null if the function is virtual 				     */
name|void
name|__iomem
modifier|*
name|mac_regs_base
decl_stmt|;
comment|/**< Ethernet MAC registers base address 				      * can be null if the function is virtual 				      */
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< the upper layer must keep the string area */
name|uint8_t
name|serdes_lane
decl_stmt|;
comment|/**< serdes lane (relevant to 25G macs only) */
block|}
struct|;
comment|/* adapter management */
comment|/**  * initialize the ethernet adapter's DMA  * - initialize the adapter data structure  * - initialize the Tx and Rx UDMA  * - enable the Tx and Rx UDMA, the rings will be still disabled at this point.  *  * @param adapter pointer to the private structure  * @param params the parameters passed from upper layer  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_adapter_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_adapter_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/**  * stop the DMA of the ethernet adapter  *  * @param adapter pointer to the private structure  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_adapter_stop
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
name|int
name|al_eth_adapter_reset
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * enable the ec and mac interrupts  *  * @param adapter pointer to the private structure  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ec_mac_ints_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * ec and mac interrupt service routine  * read and print asserted interrupts  *  * @param adapter pointer to the private structure  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ec_mac_isr
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/* Q management */
comment|/**  * Configure and enable a queue ring  *  * @param adapter pointer to the private structure  * @param type tx or rx  * @param qid queue index  * @param q_params queue parameters  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_queue_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|enum
name|al_udma_type
name|type
parameter_list|,
name|uint32_t
name|qid
parameter_list|,
name|struct
name|al_udma_q_params
modifier|*
name|q_params
parameter_list|)
function_decl|;
comment|/**  * enable a queue if it was previously disabled  *  * @param adapter pointer to the private structure  * @param type tx or rx  * @param qid queue index  *  * @return -EPERM (not implemented yet).  */
name|int
name|al_eth_queue_enable
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|enum
name|al_udma_type
name|type
parameter_list|,
name|uint32_t
name|qid
parameter_list|)
function_decl|;
comment|/**  * disable a queue  * @param adapter pointer to the private structure  * @param type tx or rx  * @param qid queue index  *  * @return -EPERM (not implemented yet).  */
name|int
name|al_eth_queue_disable
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|enum
name|al_udma_type
name|type
parameter_list|,
name|uint32_t
name|qid
parameter_list|)
function_decl|;
comment|/* MAC layer */
comment|/**  * configure the mac media type.  * this function only sets the mode, but not the speed as certain mac modes  * support multiple speeds as will be negotiated by the link layer.  * @param adapter pointer to the private structure.  * @param mode media mode  *  * @return 0 on success. negative errno on failure.  */
name|int
name|al_eth_mac_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|enum
name|al_eth_mac_mode
name|mode
parameter_list|)
function_decl|;
comment|/**  * stop the mac tx and rx paths.  * @param adapter pointer to the private structure.  *  * @return 0 on success. negative error on failure.  */
name|int
name|al_eth_mac_stop
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * start the mac tx and rx paths.  * @param adapter pointer to the private structure.  *  * @return 0 on success. negative error on failure.  */
name|int
name|al_eth_mac_start
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Perform gearbox reset for tx lanes And/Or Rx lanes.  * applicable only when the controller is connected to srds25G.  * This reset should be performed after each operation that changes the clocks  * (such as serdes reset, mac stop, etc.)  *  * @param adapter pointer to the private structure.  * @param tx_reset assert and de-assert reset for tx lanes  * @param rx_reset assert and de-assert reset for rx lanes  */
name|void
name|al_eth_gearbox_reset
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|tx_reset
parameter_list|,
name|al_bool
name|rx_reset
parameter_list|)
function_decl|;
comment|/**  * Enable / Disable forward error correction (FEC)  *  * @param adapter pointer to the private structure.  * @param enable true to enable FEC. false to disable FEC.  *  * @return 0 on success. negative error on failure.  */
name|int
name|al_eth_fec_enable
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|enable
parameter_list|)
function_decl|;
comment|/**  * Get forward error correction (FEC) statistics  *  * @param adapter pointer to the private structure.  * @param corrected number of bits been corrected by the FEC  * @param uncorrectable number of bits that FEC couldn't correct.  *  * @return 0 on success. negative error on failure.  */
name|int
name|al_eth_fec_stats_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
modifier|*
name|corrected
parameter_list|,
name|uint32_t
modifier|*
name|uncorrectable
parameter_list|)
function_decl|;
comment|/**  * get the adapter capabilities (speed, duplex,..)  * this function must not be called before configuring the mac mode using al_eth_mac_config()  * @param adapter pointer to the private structure.  * @param caps pointer to structure that will be updated by this function  *  * @return 0 on success. negative errno on failure.  */
name|int
name|al_eth_capabilities_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_capabilities
modifier|*
name|caps
parameter_list|)
function_decl|;
comment|/**  * update link auto negotiation speed and duplex mode  * this function assumes the mac mode already set using the al_eth_mac_config()  * function.  *  * @param adapter pointer to the private structure  * @param force_1000_base_x set to AL_TRUE to force the mac to work on 1000baseX  *	  (not relevant to RGMII)  * @param an_enable set to AL_TRUE to enable auto negotiation  *	  (not relevant to RGMII)  * @param speed in mega bits, e.g 1000 stands for 1Gbps (relevant only in case  *	  an_enable is AL_FALSE)  * @param full_duplex set to AL_TRUE to enable full duplex mode (relevant only  *	  in case an_enable is AL_FALSE)  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_mac_link_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|force_1000_base_x
parameter_list|,
name|al_bool
name|an_enable
parameter_list|,
name|uint32_t
name|speed
parameter_list|,
name|al_bool
name|full_duplex
parameter_list|)
function_decl|;
comment|/**  * Enable/Disable Loopback mode  *  * @param adapter pointer to the private structure  * @param enable set to AL_TRUE to enable full duplex mode  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_mac_loopback_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
comment|/**  * configure minimum and maximum rx packet length  *  * @param adapter pointer to the private structure  * @param min_rx_len minimum rx packet length  * @param max_rx_len maximum rx packet length  * both length limits in bytes and it includes the MAC Layer header and FCS.  * @return 0 on success, otherwise on failure.  */
name|int
name|al_eth_rx_pkt_limit_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|min_rx_len
parameter_list|,
name|uint32_t
name|max_rx_len
parameter_list|)
function_decl|;
comment|/* MDIO */
comment|/* Reference clock frequency (platform specific) */
enum|enum
name|al_eth_ref_clk_freq
block|{
name|AL_ETH_REF_FREQ_375_MHZ
init|=
literal|0
block|,
name|AL_ETH_REF_FREQ_187_5_MHZ
init|=
literal|1
block|,
name|AL_ETH_REF_FREQ_250_MHZ
init|=
literal|2
block|,
name|AL_ETH_REF_FREQ_500_MHZ
init|=
literal|3
block|,
name|AL_ETH_REF_FREQ_428_MHZ
init|=
literal|4
block|, }
enum|;
comment|/**  * configure the MDIO hardware interface  * @param adapter pointer to the private structure  * @param mdio_type clause type  * @param shared_mdio_if set to AL_TRUE if multiple controllers using the same  * @param ref_clk_freq reference clock frequency  * @param mdio_clk_freq_khz the required MDC/MDIO clock frequency [Khz]  * MDIO pins of the chip.  *  * @return 0 on success, otherwise on failure.  */
name|int
name|al_eth_mdio_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|enum
name|al_eth_mdio_type
name|mdio_type
parameter_list|,
name|al_bool
name|shared_mdio_if
parameter_list|,
name|enum
name|al_eth_ref_clk_freq
name|ref_clk_freq
parameter_list|,
name|unsigned
name|int
name|mdio_clk_freq_khz
parameter_list|)
function_decl|;
comment|/**  * read mdio register  * this function uses polling mode, and as the mdio is slow interface, it might  * block the cpu for long time (milliseconds).  * @param adapter pointer to the private structure  * @param phy_addr address of mdio phy  * @param device address of mdio device (used only in CLAUSE 45)  * @param reg index of the register  * @param val pointer for read value of the register  *  * @return 0 on success, negative errno on failure  */
name|int
name|al_eth_mdio_read
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|phy_addr
parameter_list|,
name|uint32_t
name|device
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|val
parameter_list|)
function_decl|;
comment|/**  * write mdio register  * this function uses polling mode, and as the mdio is slow interface, it might  * block the cpu for long time (milliseconds).  * @param adapter pointer to the private structure  * @param phy_addr address of mdio phy  * @param device address of mdio device (used only in CLAUSE 45)  * @param reg index of the register  * @param val value to write  *  * @return 0 on success, negative errno on failure  */
name|int
name|al_eth_mdio_write
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|phy_addr
parameter_list|,
name|uint32_t
name|device
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint16_t
name|val
parameter_list|)
function_decl|;
comment|/* TX */
comment|/**  * get number of free tx descriptors  *  * @param adapter adapter handle  * @param qid queue index  *  * @return num of free descriptors.  */
specifier|static
name|INLINE
name|uint32_t
name|al_eth_tx_available_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|qid
parameter_list|)
block|{
name|struct
name|al_udma_q
modifier|*
name|udma_q
decl_stmt|;
name|al_udma_q_handle_get
argument_list|(
operator|&
name|adapter
operator|->
name|tx_udma
argument_list|,
name|qid
argument_list|,
operator|&
name|udma_q
argument_list|)
expr_stmt|;
return|return
name|al_udma_available_get
argument_list|(
name|udma_q
argument_list|)
return|;
block|}
comment|/**  * prepare packet descriptors in tx queue.  *  * This functions prepares the descriptors for the given packet in the tx  * submission ring. the caller must call al_eth_tx_pkt_action() below  * in order to notify the hardware about the new descriptors.  *  * @param tx_dma_q pointer to UDMA tx queue  * @param pkt the packet to transmit  *  * @return number of descriptors used for this packet, 0 if no free  * room in the descriptors ring  */
name|int
name|al_eth_tx_pkt_prepare
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|tx_dma_q
parameter_list|,
name|struct
name|al_eth_pkt
modifier|*
name|pkt
parameter_list|)
function_decl|;
comment|/**  * Trigger the DMA about previously added tx descriptors.  *  * @param tx_dma_q pointer to UDMA tx queue  * @param tx_descs number of descriptors to notify the DMA about.  * the tx_descs can be sum of descriptor numbers of multiple prepared packets,  * this way the caller can use this function to notify the DMA about multiple  * packets.  */
name|void
name|al_eth_tx_dma_action
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|tx_dma_q
parameter_list|,
name|uint32_t
name|tx_descs
parameter_list|)
function_decl|;
comment|/**  * get number of completed tx descriptors, upper layer should derive from  * this information which packets were completed.  *  * @param tx_dma_q pointer to UDMA tx queue  *  * @return number of completed tx descriptors.  */
name|int
name|al_eth_comp_tx_get
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|tx_dma_q
parameter_list|)
function_decl|;
comment|/**  * configure a TSO MSS val  *  * the TSO MSS vals are preconfigured values for MSS stored in hardware and the  * packet could use them when not working in MSS explicit mode.  * @param adapter pointer to the private structure  * @param idx the mss index  * @param mss_val the MSS value  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_tso_mss_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|idx
parameter_list|,
name|uint32_t
name|mss_val
parameter_list|)
function_decl|;
comment|/* RX */
comment|/**  * Config the RX descriptor fields  *  * @param adapter pointer to the private structure  * @param lro_sel select LRO context or l4 offset  * @param l4_offset_sel select l4 offset source  * @param l4_sel  select the l4 checksum result  * @param l3_sel  select the l3 checksum result  * @param l3_proto_sel select the l3 protocol index source  * @param l4_proto_sel select the l4 protocol index source  * @param frag_sel select the frag indication source  */
name|void
name|al_eth_rx_desc_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|enum
name|al_eth_rx_desc_lro_context_val_res
name|lro_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_l4_offset_sel
name|l4_offset_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_l3_offset_sel
name|l3_offset_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_l4_chk_res_sel
name|l4_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_l3_chk_res_sel
name|l3_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_l3_proto_idx_sel
name|l3_proto_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_l4_proto_idx_sel
name|l4_proto_sel
parameter_list|,
name|enum
name|al_eth_rx_desc_frag_sel
name|frag_sel
parameter_list|)
function_decl|;
comment|/**  * Configure RX header split  *  * @param adapter pointer to the private structure  * @param enable header split when AL_TRUE  * @param header_split_len length in bytes of the header split, this value used when  * CTRL TABLE header split len select is set to  * AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_REG, in this case the controller will  * store the first header_split_len bytes into buf2, then the rest (if any) into buf1.  * when CTRL_TABLE header split len select set to other value, then the header_len  * determined according to the parser, and the header_split_len parameter is not  * used.  *  * return 0 on success. otherwise on failure.  */
name|int
name|al_eth_rx_header_split_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|enable
parameter_list|,
name|uint32_t
name|header_len
parameter_list|)
function_decl|;
comment|/**  * enable / disable header split in the udma queue.  * length will be taken from the udma configuration to enable different length per queue.  *  * @param adapter pointer to the private structure  * @param enable header split when AL_TRUE  * @param qid the queue id to enable/disable header split  * @param header_len in what len the udma will cut the header  *  * return 0 on success.  */
name|int
name|al_eth_rx_header_split_force_len_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|enable
parameter_list|,
name|uint32_t
name|qid
parameter_list|,
name|uint32_t
name|header_len
parameter_list|)
function_decl|;
comment|/**  * add buffer to receive queue  *  * @param rx_dma_q pointer to UDMA rx queue  * @param buf pointer to data buffer  * @param flags bitwise of AL_ETH_RX_FLAGS  * @param header_buf this is not used for far and header_buf should be set to  * NULL.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_rx_buffer_add
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|rx_dma_q
parameter_list|,
name|struct
name|al_buf
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|struct
name|al_buf
modifier|*
name|header_buf
parameter_list|)
function_decl|;
comment|/**  * notify the hw engine about rx descriptors that were added to the receive queue  *  * @param rx_dma_q pointer to UDMA rx queue  * @param descs_num number of rx descriptors  */
name|void
name|al_eth_rx_buffer_action
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|rx_dma_q
parameter_list|,
name|uint32_t
name|descs_num
parameter_list|)
function_decl|;
comment|/**  * get packet from RX completion ring  *  * @param rx_dma_q pointer to UDMA rx queue  * @param pkt pointer to a packet data structure, this function fills this  * structure with the information about the received packet. the buffers  * structures filled only with the length of the data written into the buffer,  * the address fields are not updated as the upper layer can retrieve this  * information by itself because the hardware uses the buffers in the same order  * were those buffers inserted into the ring of the receive queue.  * this structure should be allocated by the caller function.  *  * @return return number of descriptors or 0 if no completed packet found.  */
name|uint32_t
name|al_eth_pkt_rx
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|rx_dma_q
parameter_list|,
name|struct
name|al_eth_pkt
modifier|*
name|pkt
parameter_list|)
function_decl|;
comment|/* RX parser table */
struct|struct
name|al_eth_epe_p_reg_entry
block|{
name|uint32_t
name|data
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
name|uint32_t
name|ctrl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_epe_control_entry
block|{
name|uint32_t
name|data
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
comment|/**  * update rx parser entry  *  * @param adapter pointer to the private structure  * @param idx the protocol index to update  * @param reg_entry contents of parser register entry  * @param control entry contents of control table entry  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_rx_parser_entry_update
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_epe_p_reg_entry
modifier|*
name|reg_entry
parameter_list|,
name|struct
name|al_eth_epe_control_entry
modifier|*
name|control_entry
parameter_list|)
function_decl|;
comment|/* Flow Steering and filtering */
name|int
name|al_eth_thash_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|udma
parameter_list|,
name|uint32_t
name|queue
parameter_list|)
function_decl|;
comment|/* FSM table bits */
comment|/** FSM table has 7 bits input address:  *  bits[2:0] are the outer packet's type (IPv4, TCP...)  *  bits[5:3] are the inner packet's type  *  bit[6] is set when packet is tunneled.  *  * The output of each entry:  *  bits[1:0] - input selection: selects the input for the thash (2/4 tuple, inner/outer)  *  bit[2] - selects whether to use thash output, or default values for the queue and udma  *  bits[6:3] default UDMA mask: the UDMAs to select when bit 2 above was unset  *  bits[9:5] defualt queue: the queue index to select when bit 2 above was unset  */
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV4_TCP
value|0
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV4_UDP
value|1
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV6_TCP
value|2
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV6_UDP
value|3
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV6_NO_UDP_TCP
value|4
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV4_NO_UDP_TCP
value|5
define|#
directive|define
name|AL_ETH_FSM_ENTRY_IPV4_FRAGMENTED
value|6
define|#
directive|define
name|AL_ETH_FSM_ENTRY_NOT_IP
value|7
define|#
directive|define
name|AL_ETH_FSM_ENTRY_OUTER
parameter_list|(
name|idx
parameter_list|)
value|((idx)& 7)
define|#
directive|define
name|AL_ETH_FSM_ENTRY_INNER
parameter_list|(
name|idx
parameter_list|)
value|(((idx)>> 3)& 7)
define|#
directive|define
name|AL_ETH_FSM_ENTRY_TUNNELED
parameter_list|(
name|idx
parameter_list|)
value|(((idx)>> 6)& 1)
comment|/* FSM DATA format */
define|#
directive|define
name|AL_ETH_FSM_DATA_OUTER_2_TUPLE
value|0
define|#
directive|define
name|AL_ETH_FSM_DATA_OUTER_4_TUPLE
value|1
define|#
directive|define
name|AL_ETH_FSM_DATA_INNER_2_TUPLE
value|2
define|#
directive|define
name|AL_ETH_FSM_DATA_INNER_4_TUPLE
value|3
define|#
directive|define
name|AL_ETH_FSM_DATA_HASH_SEL
value|(1<< 2)
define|#
directive|define
name|AL_ETH_FSM_DATA_DEFAULT_Q_SHIFT
value|5
define|#
directive|define
name|AL_ETH_FSM_DATA_DEFAULT_UDMA_SHIFT
value|3
comment|/* set fsm table entry */
name|int
name|al_eth_fsm_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint32_t
name|entry
parameter_list|)
function_decl|;
enum|enum
name|AL_ETH_FWD_CTRL_IDX_VLAN_TABLE_OUT
block|{
name|AL_ETH_FWD_CTRL_IDX_VLAN_TABLE_OUT_0
init|=
literal|0
block|,
name|AL_ETH_FWD_CTRL_IDX_VLAN_TABLE_OUT_1
init|=
literal|1
block|,
name|AL_ETH_FWD_CTRL_IDX_VLAN_TABLE_OUT_ANY
init|=
literal|2
block|, }
enum|;
enum|enum
name|AL_ETH_FWD_CTRL_IDX_TUNNEL
block|{
name|AL_ETH_FWD_CTRL_IDX_TUNNEL_NOT_EXIST
init|=
literal|0
block|,
name|AL_ETH_FWD_CTRL_IDX_TUNNEL_EXIST
init|=
literal|1
block|,
name|AL_ETH_FWD_CTRL_IDX_TUNNEL_ANY
init|=
literal|2
block|, }
enum|;
enum|enum
name|AL_ETH_FWD_CTRL_IDX_VLAN
block|{
name|AL_ETH_FWD_CTRL_IDX_VLAN_NOT_EXIST
init|=
literal|0
block|,
name|AL_ETH_FWD_CTRL_IDX_VLAN_EXIST
init|=
literal|1
block|,
name|AL_ETH_FWD_CTRL_IDX_VLAN_ANY
init|=
literal|2
block|, }
enum|;
enum|enum
name|AL_ETH_FWD_CTRL_IDX_MAC_TABLE
block|{
name|AL_ETH_FWD_CTRL_IDX_MAC_TABLE_NO_MATCH
init|=
literal|0
block|,
name|AL_ETH_FWD_CTRL_IDX_MAC_TABLE_MATCH
init|=
literal|1
block|,
name|AL_ETH_FWD_CTRL_IDX_MAC_TABLE_ANY
init|=
literal|2
block|, }
enum|;
enum|enum
name|AL_ETH_FWD_CTRL_IDX_MAC_DA_TYPE
block|{
name|AL_ETH_FWD_CTRL_IDX_MAC_DA_TYPE_UC
init|=
literal|0
block|,
comment|/**< unicast */
name|AL_ETH_FWD_CTRL_IDX_MAC_DA_TYPE_MC
init|=
literal|1
block|,
comment|/**< multicast */
name|AL_ETH_FWD_CTRL_IDX_MAC_DA_TYPE_BC
init|=
literal|2
block|,
comment|/**< broadcast */
name|AL_ETH_FWD_CTRL_IDX_MAC_DA_TYPE_ANY
init|=
literal|4
block|,
comment|/**< for sw usage */
block|}
enum|;
comment|/**  * This structure defines the index or group of indeces within the control table.  * each field has special enum value (with _ANY postfix) that indicates all  * possible values of that field.  */
struct|struct
name|al_eth_fwd_ctrl_table_index
block|{
name|enum
name|AL_ETH_FWD_CTRL_IDX_VLAN_TABLE_OUT
name|vlan_table_out
decl_stmt|;
name|enum
name|AL_ETH_FWD_CTRL_IDX_TUNNEL
name|tunnel_exist
decl_stmt|;
name|enum
name|AL_ETH_FWD_CTRL_IDX_VLAN
name|vlan_exist
decl_stmt|;
name|enum
name|AL_ETH_FWD_CTRL_IDX_MAC_TABLE
name|mac_table_match
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|protocol_id
decl_stmt|;
name|enum
name|AL_ETH_FWD_CTRL_IDX_MAC_DA_TYPE
name|mac_type
decl_stmt|;
block|}
struct|;
enum|enum
name|AL_ETH_CTRL_TABLE_PRIO_SEL
block|{
name|AL_ETH_CTRL_TABLE_PRIO_SEL_PBITS_TABLE
init|=
literal|0
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_DSCP_TABLE
init|=
literal|1
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_TC_TABLE
init|=
literal|2
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG1
init|=
literal|3
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG2
init|=
literal|4
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG3
init|=
literal|5
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG4
init|=
literal|6
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG5
init|=
literal|7
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG6
init|=
literal|7
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG7
init|=
literal|9
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_REG8
init|=
literal|10
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_VAL_3
init|=
literal|11
block|,
name|AL_ETH_CTRL_TABLE_PRIO_SEL_VAL_0
init|=
literal|12
block|, }
enum|;
comment|/** where to select the initial queue from */
enum|enum
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1
block|{
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_PRIO_TABLE
init|=
literal|0
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_THASH_TABLE
init|=
literal|1
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_MAC_TABLE
init|=
literal|2
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_MHASH_TABLE
init|=
literal|3
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_REG1
init|=
literal|4
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_REG2
init|=
literal|5
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_REG3
init|=
literal|6
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_REG4
init|=
literal|7
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_VAL_3
init|=
literal|12
block|,
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1_VAL_0
init|=
literal|13
block|, }
enum|;
comment|/** target queue will be built up from the priority and initial queue */
enum|enum
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_2
block|{
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_2_PRIO_TABLE
init|=
literal|0
block|,
comment|/**< target queue is the output of priority table */
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_2_PRIO
init|=
literal|1
block|,
comment|/**< target queue is the priority */
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_2_PRIO_QUEUE
init|=
literal|2
block|,
comment|/**< target queue is initial queue[0], priority[1] */
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_2_NO_PRIO
init|=
literal|3
block|,
comment|/**< target queue is the initial */
block|}
enum|;
enum|enum
name|AL_ETH_CTRL_TABLE_UDMA_SEL
block|{
name|AL_ETH_CTRL_TABLE_UDMA_SEL_THASH_TABLE
init|=
literal|0
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_THASH_AND_VLAN
init|=
literal|1
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_VLAN_TABLE
init|=
literal|2
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_VLAN_AND_MAC
init|=
literal|3
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_MAC_TABLE
init|=
literal|4
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_MAC_AND_MHASH
init|=
literal|5
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_MHASH_TABLE
init|=
literal|6
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG1
init|=
literal|7
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG2
init|=
literal|8
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG3
init|=
literal|9
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG4
init|=
literal|10
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG5
init|=
literal|11
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG6
init|=
literal|12
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG7
init|=
literal|13
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_REG8
init|=
literal|14
block|,
name|AL_ETH_CTRL_TABLE_UDMA_SEL_VAL_0
init|=
literal|15
block|, }
enum|;
enum|enum
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL
block|{
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_0
init|=
literal|0
block|,
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_REG
init|=
literal|1
block|,
comment|/**< select header len from the hdr_split register (set by al_eth_rx_header_split_config())*/
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_OUTER_L3_OFFSET
init|=
literal|2
block|,
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_OUTER_L4_OFFSET
init|=
literal|3
block|,
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_TUNNEL_START_OFFSET
init|=
literal|4
block|,
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_INNER_L3_OFFSET
init|=
literal|5
block|,
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL_INNER_L4_OFFSET
init|=
literal|6
block|, }
enum|;
struct|struct
name|al_eth_fwd_ctrl_table_entry
block|{
name|enum
name|AL_ETH_CTRL_TABLE_PRIO_SEL
name|prio_sel
decl_stmt|;
name|enum
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_1
name|queue_sel_1
decl_stmt|;
comment|/**< queue id source */
name|enum
name|AL_ETH_CTRL_TABLE_QUEUE_SEL_2
name|queue_sel_2
decl_stmt|;
comment|/**< mix queue id with priority */
name|enum
name|AL_ETH_CTRL_TABLE_UDMA_SEL
name|udma_sel
decl_stmt|;
name|enum
name|AL_ETH_CTRL_TABLE_HDR_SPLIT_LEN_SEL
name|hdr_split_len_sel
decl_stmt|;
name|al_bool
name|filter
decl_stmt|;
comment|/**< set to AL_TRUE to enable filtering */
block|}
struct|;
comment|/**  * Configure default control table entry  *  * @param adapter pointer to the private structure  * @param use_table set to AL_TRUE if control table is used, when set to AL_FALSE  * then control table will be bypassed and the entry value will be used.  * @param entry defines the value to be used when bypassing control table.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ctrl_table_def_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|use_table
parameter_list|,
name|struct
name|al_eth_fwd_ctrl_table_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
comment|/**  * Configure control table entry  *  * @param adapter pointer to the private structure  * @param index the entry index within the control table.  * @param entry the value to write to the control table entry  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ctrl_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_fwd_ctrl_table_index
modifier|*
name|index
parameter_list|,
name|struct
name|al_eth_fwd_ctrl_table_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
name|int
name|al_eth_ctrl_table_raw_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint32_t
name|entry
parameter_list|)
function_decl|;
name|int
name|al_eth_ctrl_table_def_raw_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
comment|/**  * Configure hash key initial registers  * Those registers define the initial key values, those values used for  * the THASH and MHASH hash functions.  *  * @param adapter pointer to the private structure  * @param idx the register index  * @param val the register value  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_hash_key_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
struct|struct
name|al_eth_fwd_mac_table_entry
block|{
name|uint8_t
name|addr
index|[
literal|6
index|]
decl_stmt|;
comment|/**< byte 0 is the first byte seen on the wire */
name|uint8_t
name|mask
index|[
literal|6
index|]
decl_stmt|;
name|al_bool
name|tx_valid
decl_stmt|;
name|uint8_t
name|tx_target
decl_stmt|;
name|al_bool
name|rx_valid
decl_stmt|;
name|uint8_t
name|udma_mask
decl_stmt|;
comment|/**< target udma */
name|uint8_t
name|qid
decl_stmt|;
comment|/**< target queue */
name|al_bool
name|filter
decl_stmt|;
comment|/**< set to AL_TRUE to enable filtering */
block|}
struct|;
comment|/**  * Configure mac table entry  * The HW traverse this table and looks for match from lowest index,  * when the packets MAC DA& mask == addr, and the valid bit is set, then match occurs.  *  * @param adapter pointer to the private structure  * @param idx the entry index within the mac table.  * @param entry the contents of the MAC table entry  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_mac_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_fwd_mac_table_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
name|int
name|al_eth_fwd_mac_addr_raw_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint32_t
name|addr_lo
parameter_list|,
name|uint32_t
name|addr_hi
parameter_list|,
name|uint32_t
name|mask_lo
parameter_list|,
name|uint32_t
name|mask_hi
parameter_list|)
function_decl|;
name|int
name|al_eth_fwd_mac_ctrl_raw_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint32_t
name|ctrl
parameter_list|)
function_decl|;
name|int
name|al_eth_mac_addr_store
parameter_list|(
name|void
modifier|*
name|__iomem
name|ec_base
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
modifier|*
name|addr
parameter_list|)
function_decl|;
name|int
name|al_eth_mac_addr_read
parameter_list|(
name|void
modifier|*
name|__iomem
name|ec_base
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/**  * Configure pbits table entry  * The HW uses this table to translate between vlan pbits field to priority.  * The vlan pbits is used as the index of this table.  *  * @param adapter pointer to the private structure  * @param idx the entry index within the table.  * @param prio the priority to set for this entry  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_pbits_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|prio
parameter_list|)
function_decl|;
comment|/**  * Configure priority table entry  * The HW uses this table to translate between priority to queue index.  * The priority is used as the index of this table.  *  * @param adapter pointer to the private structure  * @param prio the entry index within the table.  * @param qid the queue index to set for this entry (priority).  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_priority_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|prio
parameter_list|,
name|uint8_t
name|qid
parameter_list|)
function_decl|;
comment|/**  * Configure DSCP table entry  * The HW uses this table to translate between IPv4 DSCP field to priority.  * The IPv4 byte 1 (DSCP+ECN) used as index to this table.  *  * @param adapter pointer to the private structure  * @param idx the entry index within the table.  * @param prio the queue index to set for this entry (priority).  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_dscp_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|prio
parameter_list|)
function_decl|;
comment|/**  * Configure TC table entry  * The HW uses this table to translate between IPv6 TC field to priority.  * The IPv6 TC used as index to this table.  *  * @param adapter pointer to the private structure  * @param idx the entry index within the table.  * @param prio the queue index to set for this entry (priority).  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_tc_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|prio
parameter_list|)
function_decl|;
comment|/**  * Configure MAC HASH table entry  * The HW uses 8 bits from the hash result on the MAC DA as index to this table.  *  * @param adapter pointer to the private structure  * @param idx the entry index within the table.  * @param udma_mask the target udma to set for this entry.  * @param qid the target queue index to set for this entry.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_mhash_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|udma_mask
parameter_list|,
name|uint8_t
name|qid
parameter_list|)
function_decl|;
struct|struct
name|al_eth_fwd_vid_table_entry
block|{
name|uint8_t
name|control
range|:
literal|1
decl_stmt|;
comment|/**< used as input for the control table */
name|uint8_t
name|filter
range|:
literal|1
decl_stmt|;
comment|/**< set to 1 to enable filtering */
name|uint8_t
name|udma_mask
range|:
literal|4
decl_stmt|;
comment|/**< target udmas */
block|}
struct|;
comment|/**  * Configure default vlan table entry  *  * @param adapter pointer to the private structure  * @param use_table set to AL_TRUE if vlan table is used, when set to AL_FALSE  * then vid table will be bypassed and the default_entry value will be used.  * @param default_entry defines the value to be used when bypassing vid table.  * @param default_vlan defines the value will be used when untagget packet  * received. this value will be used only for steering and filtering control,  * the packet's data will not be changed.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_vid_config_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|use_table
parameter_list|,
name|struct
name|al_eth_fwd_vid_table_entry
modifier|*
name|default_entry
parameter_list|,
name|uint32_t
name|default_vlan
parameter_list|)
function_decl|;
comment|/**  * Configure vlan table entry  *  * @param adapter pointer to the private structure  * @param idx the entry index within the vlan table. The HW uses the vlan id  * field of the packet when accessing this table.  * @param entry the value to write to the vlan table entry  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_vid_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_fwd_vid_table_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
comment|/**  * Configure default UDMA register  * When the control table entry udma selection set to AL_ETH_CTRL_TABLE_UDMA_SEL_REG<n>,  * then the target UDMA will be set according to the register n of the default  * UDMA registers.  *  * @param adapter pointer to the private structure  * @param idx the index of the default register.  * @param udma_mask the value of the register.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_default_udma_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|udma_mask
parameter_list|)
function_decl|;
comment|/**  * Configure default queue register  * When the control table entry queue selection 1 set to AL_ETH_CTRL_TABLE_QUEUE_SEL_1_REG<n>,  * then the target queue will be set according to the register n of the default  * queue registers.  *  * @param adapter pointer to the private structure  * @param idx the index of the default register.  * @param qid the value of the register.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_default_queue_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|qid
parameter_list|)
function_decl|;
comment|/**  * Configure default priority register  * When the control table entry queue selection 1 set to AL_ETH_CTRL_TABLE_PRIO_SEL_1_REG<n>,  * then the target priority will be set according to the register n of the default  * priority registers.  *  * @param adapter pointer to the private structure  * @param idx the index of the default register.  * @param prio the value of the register.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_fwd_default_priority_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|prio
parameter_list|)
function_decl|;
comment|/* filter undetected MAC DA */
define|#
directive|define
name|AL_ETH_RFW_FILTER_UNDET_MAC
value|(1<< 0)
comment|/* filter specific MAC DA based on MAC table output */
define|#
directive|define
name|AL_ETH_RFW_FILTER_DET_MAC
value|(1<< 1)
comment|/* filter all tagged */
define|#
directive|define
name|AL_ETH_RFW_FILTER_TAGGED
value|(1<< 2)
comment|/* filter all untagged */
define|#
directive|define
name|AL_ETH_RFW_FILTER_UNTAGGED
value|(1<< 3)
comment|/* filter all broadcast */
define|#
directive|define
name|AL_ETH_RFW_FILTER_BC
value|(1<< 4)
comment|/* filter all multicast */
define|#
directive|define
name|AL_ETH_RFW_FILTER_MC
value|(1<< 5)
comment|/* filter packet based on parser drop */
define|#
directive|define
name|AL_ETH_RFW_FILTER_PARSE
value|(1<< 6)
comment|/* filter packet based on VLAN table output */
define|#
directive|define
name|AL_ETH_RFW_FILTER_VLAN_VID
value|(1<< 7)
comment|/* filter packet based on control table output */
define|#
directive|define
name|AL_ETH_RFW_FILTER_CTRL_TABLE
value|(1<< 8)
comment|/* filter packet based on protocol index */
define|#
directive|define
name|AL_ETH_RFW_FILTER_PROT_INDEX
value|(1<< 9)
comment|/* filter packet based on WoL decision */
define|#
directive|define
name|AL_ETH_RFW_FILTER_WOL
value|(1<< 10)
struct|struct
name|al_eth_filter_params
block|{
name|al_bool
name|enable
decl_stmt|;
name|uint32_t
name|filters
decl_stmt|;
comment|/**< bitmask of AL_ETH_RFW_FILTER.. for filters to enable */
name|al_bool
name|filter_proto
index|[
name|AL_ETH_PROTOCOLS_NUM
index|]
decl_stmt|;
comment|/**< set AL_TRUE for protocols to filter */
block|}
struct|;
struct|struct
name|al_eth_filter_override_params
block|{
name|uint32_t
name|filters
decl_stmt|;
comment|/**< bitmask of AL_ETH_RFW_FILTER.. for filters to override */
name|uint8_t
name|udma
decl_stmt|;
comment|/**< target udma id */
name|uint8_t
name|qid
decl_stmt|;
comment|/**< target queue id */
block|}
struct|;
comment|/**  * Configure the receive filters  * this function enables/disables filtering packets and which filtering  * types to apply.  * filters that indicated in tables (MAC table, VLAN and Control tables)  * are not configured by this function. This functions only enables/disables  * respecting the filter indication from those tables.  *  * @param adapter pointer to the private structure  * @param params the parameters passed from upper layer  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_filter_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_filter_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/**  * Configure the receive override filters  * This function controls whither to force forwarding filtered packets  * to a specific UDMA/queue. The override filters apply only for  * filters that enabled by al_eth_filter_config().  *  * @param adapter pointer to the private structure  * @param params override config parameters  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_filter_override_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_filter_override_params
modifier|*
name|params
parameter_list|)
function_decl|;
name|int
name|al_eth_switching_config_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|udma_id
parameter_list|,
name|uint8_t
name|forward_all_to_mac
parameter_list|,
name|uint8_t
name|enable_int_switching
parameter_list|,
name|enum
name|al_eth_tx_switch_vid_sel_type
name|vid_sel_type
parameter_list|,
name|enum
name|al_eth_tx_switch_dec_type
name|uc_dec
parameter_list|,
name|enum
name|al_eth_tx_switch_dec_type
name|mc_dec
parameter_list|,
name|enum
name|al_eth_tx_switch_dec_type
name|bc_dec
parameter_list|)
function_decl|;
name|int
name|al_eth_switching_default_bitmap_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|udma_id
parameter_list|,
name|uint8_t
name|udma_uc_bitmask
parameter_list|,
name|uint8_t
name|udma_mc_bitmask
parameter_list|,
name|uint8_t
name|udma_bc_bitmask
parameter_list|)
function_decl|;
name|int
name|al_eth_flow_control_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_flow_control_params
modifier|*
name|params
parameter_list|)
function_decl|;
struct|struct
name|al_eth_eee_params
block|{
name|uint8_t
name|enable
decl_stmt|;
name|uint32_t
name|tx_eee_timer
decl_stmt|;
comment|/**< time in cycles the interface delays prior to entering eee state */
name|uint32_t
name|min_interval
decl_stmt|;
comment|/**< minimum interval in cycles between two eee states */
name|uint32_t
name|stop_cnt
decl_stmt|;
comment|/**< time in cycles to stop Tx mac i/f after getting out of eee state */
name|al_bool
name|fast_wake
decl_stmt|;
comment|/**< fast_wake is only applicable to 40/50G, otherwise the mode is deep_sleep */
block|}
struct|;
comment|/**  * configure EEE mode  * @param adapter pointer to the private structure.  * @param params pointer to the eee input parameters.  *  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_eee_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_eee_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/**  * get EEE configuration  * @param adapter pointer to the private structure.  * @param params pointer to the eee output parameters.  *  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_eee_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_eee_params
modifier|*
name|params
parameter_list|)
function_decl|;
name|int
name|al_eth_vlan_mod_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|udma_id
parameter_list|,
name|uint16_t
name|udma_etype
parameter_list|,
name|uint16_t
name|vlan1_data
parameter_list|,
name|uint16_t
name|vlan2_data
parameter_list|)
function_decl|;
comment|/* Timestamp  * This is a generic time-stamp mechanism that can be used as generic to  * time-stamp every received or transmit packet it can also support IEEE 1588v2  * PTP time synchronization protocol.  * In addition to time-stamp, an internal system time is maintained. For  * further accuracy, the chip support transmit/receive clock synchronization  * including recovery of master clock from one of the ports and distributing it  * to the rest of the ports - that is outside the scope of the Ethernet  * Controller - please refer to Annapurna Labs Alpine Hardware Wiki  */
comment|/* Timestamp management APIs */
comment|/**  * prepare the adapter for timestamping packets.  * Rx timestamps requires using 8 words (8x4 bytes) rx completion descriptor  * size as the timestamp value added into word 4.  *  * This function should be called after al_eth_mac_config() and before  * enabling the queues.  * @param adapter pointer to the private structure.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ts_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/* Timestamp data path APIs */
comment|/*  * This is the size of the on-chip array that keeps the time-stamp of the  * latest transmitted packets  */
define|#
directive|define
name|AL_ETH_PTH_TX_SAMPLES_NUM
value|16
comment|/**  * read Timestamp sample value of previously transmitted packet.  *  * The adapter includes AL_ETH_PTH_TX_SAMPLES_NUM timestamp samples for tx  * packets, those samples shared for all the UDMAs and queues. the al_eth_pkt  * data structure includes the index of which sample to use for the packet  * to transmit. It's the caller's responsibility to manage those samples,  * for example, when using an index, the caller must make sure the packet  * is completed and the tx time is sampled before using that index for  * another packet.  *  * This function should be called after the completion indication of the  * tx packet. however, there is a little chance that the timestamp sample  * won't be updated yet, thus this function must be called again when it  * returns -EAGAIN.  * @param adapter pointer to the private structure.  * @param ts_index the index (out of 16) of the timestamp register  * @param timestamp the timestamp value in 2^18 femtoseconds resolution.  * @return -EAGAIN if the sample was not updated yet. 0 when the sample  * was updated and no errors found.  */
name|int
name|al_eth_tx_ts_val_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|ts_index
parameter_list|,
name|uint32_t
modifier|*
name|timestamp
parameter_list|)
function_decl|;
comment|/* Timestamp PTH (PTP Timestamp Handler) control and times management */
comment|/** structure for describing PTH epoch time */
struct|struct
name|al_eth_pth_time
block|{
name|uint32_t
name|seconds
decl_stmt|;
comment|/**< seconds */
name|uint64_t
name|femto
decl_stmt|;
comment|/**< femto seconds */
block|}
struct|;
comment|/**  * Read the systime value  * This API should not be used to get the timestamp of packets.  * The HW maintains 50 bits for the sub-seconds portion in femto resolution,  * but this function reads only the 32 MSB bits since the LSB provides  * sub-nanoseconds accuracy, which is not needed.  * @param adapter pointer to the private structure.  * @param systime pointer to structure where the time will be stored.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_systime_read
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_pth_time
modifier|*
name|systime
parameter_list|)
function_decl|;
comment|/**  * Set the clock period to a given value.  * The systime will be incremented by this value on each posedge of the  * adapters internal clock which driven by the SouthBridge clock.  * @param adapter pointer to the private structure.  * @param clk_period the clock period in femto seconds.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_clk_period_write
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint64_t
name|clk_period
parameter_list|)
function_decl|;
comment|/**< enum for methods when updating systime using triggers */
enum|enum
name|al_eth_pth_update_method
block|{
name|AL_ETH_PTH_UPDATE_METHOD_SET
init|=
literal|0
block|,
comment|/**< Set the time in int/ext update time */
name|AL_ETH_PTH_UPDATE_METHOD_INC
init|=
literal|1
block|,
comment|/**< increment */
name|AL_ETH_PTH_UPDATE_METHOD_DEC
init|=
literal|2
block|,
comment|/**< decrement */
name|AL_ETH_PTH_UPDATE_METHOD_ADD_TO_LAST
init|=
literal|3
block|,
comment|/**< Set to last time + int/ext update time.*/
block|}
enum|;
comment|/**< systime internal update trigger types */
enum|enum
name|al_eth_pth_int_trig
block|{
name|AL_ETH_PTH_INT_TRIG_OUT_PULSE_0
init|=
literal|0
block|,
comment|/**< use output pulse as trigger */
name|AL_ETH_PTH_INT_TRIG_REG_WRITE
init|=
literal|1
block|,
comment|/**< use the int update register 					    * write as a trigger 					    */
block|}
enum|;
comment|/**< parameters for internal trigger update */
struct|struct
name|al_eth_pth_int_update_params
block|{
name|al_bool
name|enable
decl_stmt|;
comment|/**< enable internal trigger update */
name|enum
name|al_eth_pth_update_method
name|method
decl_stmt|;
comment|/**< internal trigger update 						 * method 						 */
name|enum
name|al_eth_pth_int_trig
name|trigger
decl_stmt|;
comment|/**< which internal trigger to 						  * use 						  */
block|}
struct|;
comment|/**  * Configure the systime internal update  *  * @param adapter pointer to the private structure.  * @param params the configuration of the internal update.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_int_update_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_pth_int_update_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/**  * set internal update time  *  * The update time used when updating the systime with  * internal update method.  *  * @param adapter pointer to the private structure.  * @param time the internal update time value  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_int_update_time_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_pth_time
modifier|*
name|time
parameter_list|)
function_decl|;
comment|/**< parameters for external trigger update */
struct|struct
name|al_eth_pth_ext_update_params
block|{
name|uint8_t
name|triggers
decl_stmt|;
comment|/**< bitmask of external triggers to enable */
name|enum
name|al_eth_pth_update_method
name|method
decl_stmt|;
comment|/**< external trigger update 						 * method 						 */
block|}
struct|;
comment|/**  * Configure the systime external update.  * external update triggered by external signals such as GPIO or pulses  * from other eth controllers on the SoC.  *  * @param adapter pointer to the private structure.  * @param params the configuration of the external update.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_ext_update_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_pth_ext_update_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/**  * set external update time  *  * The update time used when updating the systime with  * external update method.  * @param adapter pointer to the private structure.  * @param time the external update time value  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_ext_update_time_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_pth_time
modifier|*
name|time
parameter_list|)
function_decl|;
comment|/**  * set the read compensation delay  *  * When reading the systime, the HW adds this value to compensate  * read latency.  *  * @param adapter pointer to the private structure.  * @param subseconds the read latency delay in femto seconds.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_read_compensation_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint64_t
name|subseconds
parameter_list|)
function_decl|;
comment|/**  * set the internal write compensation delay  *  * When updating the systime due to an internal trigger's event, the HW adds  * this value to compensate latency.  *  * @param adapter pointer to the private structure.  * @param subseconds the write latency delay in femto seconds.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_int_write_compensation_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint64_t
name|subseconds
parameter_list|)
function_decl|;
comment|/**  * set the external write compensation delay  *  * When updating the systime due to an external trigger's event, the HW adds  * this value to compensate pulse propagation latency.  *  * @param adapter pointer to the private structure.  * @param subseconds the write latency delay in femto seconds.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_ext_write_compensation_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint64_t
name|subseconds
parameter_list|)
function_decl|;
comment|/**  * set the sync compensation delay  *  * When the adapter passes systime from PTH to MAC to do the packets  * timestamping, the sync compensation delay is added to systime value to  * compensate the latency between the PTH and the MAC.  *  * @param adapter pointer to the private structure.  * @param subseconds the sync latency delay in femto seconds.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_sync_compensation_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint64_t
name|subseconds
parameter_list|)
function_decl|;
define|#
directive|define
name|AL_ETH_PTH_PULSE_OUT_NUM
value|8
struct|struct
name|al_eth_pth_pulse_out_params
block|{
name|uint8_t
name|index
decl_stmt|;
comment|/**< id of the pulse (0..7) */
name|al_bool
name|enable
decl_stmt|;
name|al_bool
name|periodic
decl_stmt|;
comment|/**< when true, generate periodic pulse (PPS) */
name|uint8_t
name|period_sec
decl_stmt|;
comment|/**< for periodic pulse, this is seconds 				     * portion of the period time 				     */
name|uint32_t
name|period_us
decl_stmt|;
comment|/**< this is microseconds portion of the 				      * period 				      */
name|struct
name|al_eth_pth_time
name|start_time
decl_stmt|;
comment|/**< when to start pulse triggering */
name|uint64_t
name|pulse_width
decl_stmt|;
comment|/**< pulse width in femto seconds */
block|}
struct|;
comment|/**  * Configure an output pulse  * This function configures an output pulse coming from the internal System  * Time. This is typically a 1Hhz pulse that is used to synchronize the  * rest of the components of the system. This API configure the Ethernet  * Controller pulse. An additional set up is required to configure the chip  * General Purpose I/O (GPIO) to enable the chip output pin.  *  * @param adapter pointer to the private structure.  * @param params output pulse configuration.  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_pth_pulse_out_config
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_pth_pulse_out_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/* link */
struct|struct
name|al_eth_link_status
block|{
name|al_bool
name|link_up
decl_stmt|;
name|al_bool
name|local_fault
decl_stmt|;
name|al_bool
name|remote_fault
decl_stmt|;
block|}
struct|;
comment|/**  * get link status  *  * this function should be used when no external phy is used to get  * information about the link  *  * @param adapter pointer to the private structure.  * @param status pointer to struct where to set link information  *  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_link_status_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_link_status
modifier|*
name|status
parameter_list|)
function_decl|;
comment|/**  * clear link status  *  * this function clear latched status of the link.  *  * @param adapter pointer to the private structure.  *  * @return return 0 if supported.  */
name|int
name|al_eth_link_status_clear
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Set LEDs to represent link status.  *  * @param adapter pointer to the private structure.  * @param link_is_up boolean indicating current link status.  *	  In case link is down the leds will be turned off.  *	  In case link is up the leds will be turned on, that means  *	  leds will be blinking on traffic and will be constantly lighting  *	  on inactive link  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_led_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|al_bool
name|link_is_up
parameter_list|)
function_decl|;
comment|/* get statistics */
struct|struct
name|al_eth_mac_stats
block|{
comment|/* sum the data and padding octets (i.e. without header and FCS) received with a valid frame. */
name|uint64_t
name|aOctetsReceivedOK
decl_stmt|;
comment|/* sum of Payload and padding octets of frames transmitted without error*/
name|uint64_t
name|aOctetsTransmittedOK
decl_stmt|;
comment|/* total number of packets received. Good and bad packets */
name|uint32_t
name|etherStatsPkts
decl_stmt|;
comment|/* number of received unicast packets */
name|uint32_t
name|ifInUcastPkts
decl_stmt|;
comment|/* number of received multicast packets */
name|uint32_t
name|ifInMulticastPkts
decl_stmt|;
comment|/* number of received broadcast packets */
name|uint32_t
name|ifInBroadcastPkts
decl_stmt|;
comment|/* Number of frames received with FIFO Overflow, CRC, Payload Length, Jabber and Oversized, Alignment or PHY/PCS error indication */
name|uint32_t
name|ifInErrors
decl_stmt|;
comment|/* number of transmitted unicast packets */
name|uint32_t
name|ifOutUcastPkts
decl_stmt|;
comment|/* number of transmitted multicast packets */
name|uint32_t
name|ifOutMulticastPkts
decl_stmt|;
comment|/* number of transmitted broadcast packets */
name|uint32_t
name|ifOutBroadcastPkts
decl_stmt|;
comment|/* number of frames transmitted with FIFO Overflow, FIFO Underflow or Controller indicated error */
name|uint32_t
name|ifOutErrors
decl_stmt|;
comment|/* number of Frame received without error (Including Pause Frames). */
name|uint32_t
name|aFramesReceivedOK
decl_stmt|;
comment|/* number of Frames transmitter without error (Including Pause Frames) */
name|uint32_t
name|aFramesTransmittedOK
decl_stmt|;
comment|/* number of packets received with less than 64 octets */
name|uint32_t
name|etherStatsUndersizePkts
decl_stmt|;
comment|/* Too short frames with CRC error, available only for RGMII and 1G Serial modes */
name|uint32_t
name|etherStatsFragments
decl_stmt|;
comment|/* Too long frames with CRC error */
name|uint32_t
name|etherStatsJabbers
decl_stmt|;
comment|/* packet that exceeds the valid maximum programmed frame length */
name|uint32_t
name|etherStatsOversizePkts
decl_stmt|;
comment|/* number of frames received with a CRC error */
name|uint32_t
name|aFrameCheckSequenceErrors
decl_stmt|;
comment|/* number of frames received with alignment error */
name|uint32_t
name|aAlignmentErrors
decl_stmt|;
comment|/* number of dropped packets due to FIFO overflow */
name|uint32_t
name|etherStatsDropEvents
decl_stmt|;
comment|/* number of transmitted pause frames. */
name|uint32_t
name|aPAUSEMACCtrlFramesTransmitted
decl_stmt|;
comment|/* number of received pause frames. */
name|uint32_t
name|aPAUSEMACCtrlFramesReceived
decl_stmt|;
comment|/* frame received exceeded the maximum length programmed with register FRM_LGTH, available only for 10G modes */
name|uint32_t
name|aFrameTooLongErrors
decl_stmt|;
comment|/* received frame with bad length/type (between 46 and 0x600 or less 	 * than 46 for packets longer than 64), available only for 10G modes */
name|uint32_t
name|aInRangeLengthErrors
decl_stmt|;
comment|/* Valid VLAN tagged frames transmitted */
name|uint32_t
name|VLANTransmittedOK
decl_stmt|;
comment|/* Valid VLAN tagged frames received */
name|uint32_t
name|VLANReceivedOK
decl_stmt|;
comment|/* Total number of octets received. Good and bad packets */
name|uint32_t
name|etherStatsOctets
decl_stmt|;
comment|/* packets of 64 octets length is received (good and bad frames are counted) */
name|uint32_t
name|etherStatsPkts64Octets
decl_stmt|;
comment|/* Frames (good and bad) with 65 to 127 octets */
name|uint32_t
name|etherStatsPkts65to127Octets
decl_stmt|;
comment|/* Frames (good and bad) with 128 to 255 octets */
name|uint32_t
name|etherStatsPkts128to255Octets
decl_stmt|;
comment|/* Frames (good and bad) with 256 to 511 octets */
name|uint32_t
name|etherStatsPkts256to511Octets
decl_stmt|;
comment|/* Frames (good and bad) with 512 to 1023 octets */
name|uint32_t
name|etherStatsPkts512to1023Octets
decl_stmt|;
comment|/* Frames (good and bad) with 1024 to 1518 octets */
name|uint32_t
name|etherStatsPkts1024to1518Octets
decl_stmt|;
comment|/* frames with 1519 bytes to the maximum length programmed in the register FRAME_LENGTH. */
name|uint32_t
name|etherStatsPkts1519toX
decl_stmt|;
name|uint32_t
name|eee_in
decl_stmt|;
name|uint32_t
name|eee_out
decl_stmt|;
block|}
struct|;
comment|/**  * get mac statistics  * @param adapter pointer to the private structure.  * @param stats pointer to structure that will be filled with statistics.  *  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_mac_stats_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_mac_stats
modifier|*
name|stats
parameter_list|)
function_decl|;
struct|struct
name|al_eth_ec_stats
block|{
comment|/* Rx Frequency adjust FIFO input  packets */
name|uint32_t
name|faf_in_rx_pkt
decl_stmt|;
comment|/* Rx Frequency adjust FIFO input  short error packets */
name|uint32_t
name|faf_in_rx_short
decl_stmt|;
comment|/* Rx Frequency adjust FIFO input  long error packets */
name|uint32_t
name|faf_in_rx_long
decl_stmt|;
comment|/* Rx Frequency adjust FIFO output  packets */
name|uint32_t
name|faf_out_rx_pkt
decl_stmt|;
comment|/* Rx Frequency adjust FIFO output  short error packets */
name|uint32_t
name|faf_out_rx_short
decl_stmt|;
comment|/* Rx Frequency adjust FIFO output  long error packets */
name|uint32_t
name|faf_out_rx_long
decl_stmt|;
comment|/* Rx Frequency adjust FIFO output  drop packets */
name|uint32_t
name|faf_out_drop
decl_stmt|;
comment|/* Number of packets written into the Rx FIFO (without FIFO error indication) */
name|uint32_t
name|rxf_in_rx_pkt
decl_stmt|;
comment|/* Number of error packets written into the Rx FIFO (with FIFO error indication, */
comment|/* FIFO full indication during packet reception) */
name|uint32_t
name|rxf_in_fifo_err
decl_stmt|;
comment|/* Number of packets read from Rx FIFO 1 */
name|uint32_t
name|lbf_in_rx_pkt
decl_stmt|;
comment|/* Number of packets read from Rx FIFO 2 (loopback FIFO) */
name|uint32_t
name|lbf_in_fifo_err
decl_stmt|;
comment|/* Rx FIFO output drop packets from FIFO 1 */
name|uint32_t
name|rxf_out_rx_1_pkt
decl_stmt|;
comment|/* Rx FIFO output drop packets from FIFO 2 (loop back) */
name|uint32_t
name|rxf_out_rx_2_pkt
decl_stmt|;
comment|/* Rx FIFO output drop packets from FIFO 1 */
name|uint32_t
name|rxf_out_drop_1_pkt
decl_stmt|;
comment|/* Rx FIFO output drop packets from FIFO 2 (loop back) */
name|uint32_t
name|rxf_out_drop_2_pkt
decl_stmt|;
comment|/* Rx Parser 1, input packet counter */
name|uint32_t
name|rpe_1_in_rx_pkt
decl_stmt|;
comment|/* Rx Parser 1, output packet counter */
name|uint32_t
name|rpe_1_out_rx_pkt
decl_stmt|;
comment|/* Rx Parser 2, input packet counter */
name|uint32_t
name|rpe_2_in_rx_pkt
decl_stmt|;
comment|/* Rx Parser 2, output packet counter */
name|uint32_t
name|rpe_2_out_rx_pkt
decl_stmt|;
comment|/* Rx Parser 3 (MACsec), input packet counter */
name|uint32_t
name|rpe_3_in_rx_pkt
decl_stmt|;
comment|/* Rx Parser 3 (MACsec), output packet counter */
name|uint32_t
name|rpe_3_out_rx_pkt
decl_stmt|;
comment|/* Tx parser, input packet counter */
name|uint32_t
name|tpe_in_tx_pkt
decl_stmt|;
comment|/* Tx parser, output packet counter */
name|uint32_t
name|tpe_out_tx_pkt
decl_stmt|;
comment|/* Tx packet modification, input packet counter */
name|uint32_t
name|tpm_tx_pkt
decl_stmt|;
comment|/* Tx forwarding input packet counter */
name|uint32_t
name|tfw_in_tx_pkt
decl_stmt|;
comment|/* Tx forwarding input packet counter */
name|uint32_t
name|tfw_out_tx_pkt
decl_stmt|;
comment|/* Rx forwarding input packet counter */
name|uint32_t
name|rfw_in_rx_pkt
decl_stmt|;
comment|/* Rx Forwarding, packet with VLAN command drop indication */
name|uint32_t
name|rfw_in_vlan_drop
decl_stmt|;
comment|/* Rx Forwarding, packets with parse drop indication */
name|uint32_t
name|rfw_in_parse_drop
decl_stmt|;
comment|/* Rx Forwarding, multicast packets */
name|uint32_t
name|rfw_in_mc
decl_stmt|;
comment|/* Rx Forwarding, broadcast packets */
name|uint32_t
name|rfw_in_bc
decl_stmt|;
comment|/* Rx Forwarding, tagged packets */
name|uint32_t
name|rfw_in_vlan_exist
decl_stmt|;
comment|/* Rx Forwarding, untagged packets */
name|uint32_t
name|rfw_in_vlan_nexist
decl_stmt|;
comment|/* Rx Forwarding, packets with MAC address drop indication (from the MAC address table) */
name|uint32_t
name|rfw_in_mac_drop
decl_stmt|;
comment|/* Rx Forwarding, packets with undetected MAC address */
name|uint32_t
name|rfw_in_mac_ndet_drop
decl_stmt|;
comment|/* Rx Forwarding, packets with drop indication from the control table */
name|uint32_t
name|rfw_in_ctrl_drop
decl_stmt|;
comment|/* Rx Forwarding, packets with L3_protocol_index drop indication */
name|uint32_t
name|rfw_in_prot_i_drop
decl_stmt|;
comment|/* EEE, number of times the system went into EEE state */
name|uint32_t
name|eee_in
decl_stmt|;
block|}
struct|;
comment|/**  * get ec statistics  * @param adapter pointer to the private structure.  * @param stats pointer to structure that will be filled with statistics.  *  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ec_stats_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_ec_stats
modifier|*
name|stats
parameter_list|)
function_decl|;
struct|struct
name|al_eth_ec_stat_udma
block|{
comment|/* Rx forwarding output packet counter */
name|uint32_t
name|rfw_out_rx_pkt
decl_stmt|;
comment|/* Rx forwarding output drop packet counter */
name|uint32_t
name|rfw_out_drop
decl_stmt|;
comment|/* Multi-stream write, number of Rx packets */
name|uint32_t
name|msw_in_rx_pkt
decl_stmt|;
comment|/* Multi-stream write, number of dropped packets at SOP,  Q full indication */
name|uint32_t
name|msw_drop_q_full
decl_stmt|;
comment|/* Multi-stream write, number of dropped packets at SOP */
name|uint32_t
name|msw_drop_sop
decl_stmt|;
comment|/* Multi-stream write, number of dropped packets at EOP, */
comment|/*EOP was written with error indication (not all packet data was written) */
name|uint32_t
name|msw_drop_eop
decl_stmt|;
comment|/* Multi-stream write, number of packets written to the stream FIFO with EOP and without packet loss */
name|uint32_t
name|msw_wr_eop
decl_stmt|;
comment|/* Multi-stream write, number of packets read from the FIFO into the stream */
name|uint32_t
name|msw_out_rx_pkt
decl_stmt|;
comment|/* Number of transmitted packets without TSO enabled */
name|uint32_t
name|tso_no_tso_pkt
decl_stmt|;
comment|/* Number of transmitted packets with TSO enabled */
name|uint32_t
name|tso_tso_pkt
decl_stmt|;
comment|/* Number of TSO segments that were generated */
name|uint32_t
name|tso_seg_pkt
decl_stmt|;
comment|/* Number of TSO segments that required padding */
name|uint32_t
name|tso_pad_pkt
decl_stmt|;
comment|/* Tx Packet modification, MAC SA spoof error */
name|uint32_t
name|tpm_tx_spoof
decl_stmt|;
comment|/* Tx MAC interface, input packet counter */
name|uint32_t
name|tmi_in_tx_pkt
decl_stmt|;
comment|/* Tx MAC interface, number of packets forwarded to the MAC */
name|uint32_t
name|tmi_out_to_mac
decl_stmt|;
comment|/* Tx MAC interface, number of packets forwarded to the Rx data path */
name|uint32_t
name|tmi_out_to_rx
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q0_bytes
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q1_bytes
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q2_bytes
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q3_bytes
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q0_pkts
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q1_pkts
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q2_pkts
decl_stmt|;
comment|/* Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q3_pkts
decl_stmt|;
block|}
struct|;
comment|/**  * get per_udma statistics  * @param adapter pointer to the private structure.  * @param idx udma_id value  * @param stats pointer to structure that will be filled with statistics.  *  * @return return 0 on success. otherwise on failure.  */
name|int
name|al_eth_ec_stat_udma_get
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint8_t
name|idx
parameter_list|,
name|struct
name|al_eth_ec_stat_udma
modifier|*
name|stats
parameter_list|)
function_decl|;
comment|/* trafic control */
comment|/**  * perform Function Level Reset RMN  *  * Addressing RMN: 714  *  * @param pci_read_config_u32 pointer to function that reads register from pci header  * @param pci_write_config_u32 pointer to function that writes register from pci header  * @param handle pointer passes to the above functions as first parameter  * @param mac_base base address of the MAC registers  *  * @return 0.  */
name|int
name|al_eth_flr_rmn
parameter_list|(
name|int
function_decl|(
modifier|*
name|pci_read_config_u32
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|int
name|where
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|pci_write_config_u32
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|int
name|where
parameter_list|,
name|uint32_t
name|val
parameter_list|)
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|,
name|void
name|__iomem
modifier|*
name|mac_base
parameter_list|)
function_decl|;
comment|/**  * perform Function Level Reset RMN but restore registers that contain board specific data  *  * the data that save and restored is the board params and mac addresses  *  * @param pci_read_config_u32 pointer to function that reads register from pci header  * @param pci_write_config_u32 pointer to function that writes register from pci header  * @param handle pointer passes to the above functions as first parameter  * @param mac_base base address of the MAC registers  * @param ec_base base address of the Ethernet Controller registers  * @param mac_addresses_num number of mac addresses to restore  *  * @return 0.  */
name|int
name|al_eth_flr_rmn_restore_params
parameter_list|(
name|int
function_decl|(
modifier|*
name|pci_read_config_u32
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|int
name|where
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|pci_write_config_u32
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|int
name|where
parameter_list|,
name|uint32_t
name|val
parameter_list|)
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|,
name|void
name|__iomem
modifier|*
name|mac_base
parameter_list|,
name|void
name|__iomem
modifier|*
name|ec_base
parameter_list|,
name|int
name|mac_addresses_num
parameter_list|)
function_decl|;
comment|/* board specific information (media type, phy address, etc.. */
enum|enum
name|al_eth_board_media_type
block|{
name|AL_ETH_BOARD_MEDIA_TYPE_AUTO_DETECT
init|=
literal|0
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_RGMII
init|=
literal|1
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_10GBASE_SR
init|=
literal|2
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_SGMII
init|=
literal|3
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_1000BASE_X
init|=
literal|4
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_AUTO_DETECT_AUTO_SPEED
init|=
literal|5
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_SGMII_2_5G
init|=
literal|6
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_NBASE_T
init|=
literal|7
block|,
name|AL_ETH_BOARD_MEDIA_TYPE_25G
init|=
literal|8
block|, }
enum|;
enum|enum
name|al_eth_board_mdio_freq
block|{
name|AL_ETH_BOARD_MDIO_FREQ_2_5_MHZ
init|=
literal|0
block|,
name|AL_ETH_BOARD_MDIO_FREQ_1_MHZ
init|=
literal|1
block|, }
enum|;
enum|enum
name|al_eth_board_ext_phy_if
block|{
name|AL_ETH_BOARD_PHY_IF_MDIO
init|=
literal|0
block|,
name|AL_ETH_BOARD_PHY_IF_XMDIO
init|=
literal|1
block|,
name|AL_ETH_BOARD_PHY_IF_I2C
init|=
literal|2
block|,  }
enum|;
enum|enum
name|al_eth_board_auto_neg_mode
block|{
name|AL_ETH_BOARD_AUTONEG_OUT_OF_BAND
init|=
literal|0
block|,
name|AL_ETH_BOARD_AUTONEG_IN_BAND
init|=
literal|1
block|,  }
enum|;
comment|/* declare the 1G mac active speed when auto negotiation disabled */
enum|enum
name|al_eth_board_1g_speed
block|{
name|AL_ETH_BOARD_1G_SPEED_1000M
init|=
literal|0
block|,
name|AL_ETH_BOARD_1G_SPEED_100M
init|=
literal|1
block|,
name|AL_ETH_BOARD_1G_SPEED_10M
init|=
literal|2
block|, }
enum|;
enum|enum
name|al_eth_retimer_channel
block|{
name|AL_ETH_RETIMER_CHANNEL_A
init|=
literal|0
block|,
name|AL_ETH_RETIMER_CHANNEL_B
init|=
literal|1
block|,
name|AL_ETH_RETIMER_CHANNEL_C
init|=
literal|2
block|,
name|AL_ETH_RETIMER_CHANNEL_D
init|=
literal|3
block|,
name|AL_ETH_RETIMER_CHANNEL_E
init|=
literal|4
block|,
name|AL_ETH_RETIMER_CHANNEL_F
init|=
literal|5
block|,
name|AL_ETH_RETIMER_CHANNEL_G
init|=
literal|6
block|,
name|AL_ETH_RETIMER_CHANNEL_H
init|=
literal|7
block|,
name|AL_ETH_RETIMER_CHANNEL_MAX
init|=
literal|8
block|}
enum|;
comment|/* list of supported retimers */
enum|enum
name|al_eth_retimer_type
block|{
name|AL_ETH_RETIMER_BR_210
init|=
literal|0
block|,
name|AL_ETH_RETIMER_BR_410
init|=
literal|1
block|,
name|AL_ETH_RETIMER_DS_25
init|=
literal|2
block|,
name|AL_ETH_RETIMER_TYPE_MAX
init|=
literal|4
block|, }
enum|;
comment|/** structure represents the board information. this info set by boot loader  * and read by OS driver.  */
struct|struct
name|al_eth_board_params
block|{
name|enum
name|al_eth_board_media_type
name|media_type
decl_stmt|;
name|al_bool
name|phy_exist
decl_stmt|;
comment|/**< external phy exist */
name|uint8_t
name|phy_mdio_addr
decl_stmt|;
comment|/**< mdio address of external phy */
name|al_bool
name|sfp_plus_module_exist
decl_stmt|;
comment|/**< SFP+ module connected */
name|al_bool
name|autoneg_enable
decl_stmt|;
comment|/**< enable Auto-Negotiation */
name|al_bool
name|kr_lt_enable
decl_stmt|;
comment|/**< enable KR Link-Training */
name|al_bool
name|kr_fec_enable
decl_stmt|;
comment|/**< enable KR FEC */
name|enum
name|al_eth_board_mdio_freq
name|mdio_freq
decl_stmt|;
comment|/**< MDIO frequency */
name|uint8_t
name|i2c_adapter_id
decl_stmt|;
comment|/**< identifier for the i2c adapter to use to access SFP+ module */
name|enum
name|al_eth_board_ext_phy_if
name|phy_if
decl_stmt|;
comment|/**< phy interface */
name|enum
name|al_eth_board_auto_neg_mode
name|an_mode
decl_stmt|;
comment|/**< auto-negotiation mode (in-band / out-of-band) */
name|uint8_t
name|serdes_grp
decl_stmt|;
comment|/**< serdes's group id */
name|uint8_t
name|serdes_lane
decl_stmt|;
comment|/**< serdes's lane id */
name|enum
name|al_eth_ref_clk_freq
name|ref_clk_freq
decl_stmt|;
comment|/**< reference clock frequency */
name|al_bool
name|dont_override_serdes
decl_stmt|;
comment|/**< prevent override serdes parameters */
name|al_bool
name|force_1000_base_x
decl_stmt|;
comment|/**< set mac to 1000 base-x mode (instead sgmii) */
name|al_bool
name|an_disable
decl_stmt|;
comment|/**< disable auto negotiation */
name|enum
name|al_eth_board_1g_speed
name|speed
decl_stmt|;
comment|/**< port speed if AN disabled */
name|al_bool
name|half_duplex
decl_stmt|;
comment|/**< force half duplex if AN disabled */
name|al_bool
name|fc_disable
decl_stmt|;
comment|/**< disable flow control */
name|al_bool
name|retimer_exist
decl_stmt|;
comment|/**< retimer is exist on the board */
name|uint8_t
name|retimer_bus_id
decl_stmt|;
comment|/**< in what i2c bus the retimer is on */
name|uint8_t
name|retimer_i2c_addr
decl_stmt|;
comment|/**< i2c address of the retimer */
name|enum
name|al_eth_retimer_channel
name|retimer_channel
decl_stmt|;
comment|/**< what channel connected to this port (Rx) */
name|al_bool
name|dac
decl_stmt|;
comment|/**< assume direct attached cable is connected if auto detect is off or failed */
name|uint8_t
name|dac_len
decl_stmt|;
comment|/**< assume this cable length if auto detect is off or failed  */
name|enum
name|al_eth_retimer_type
name|retimer_type
decl_stmt|;
comment|/**< the type of the specific retimer */
name|enum
name|al_eth_retimer_channel
name|retimer_tx_channel
decl_stmt|;
comment|/**< what channel connected to this port (Tx) */
name|uint8_t
name|gpio_sfp_present
decl_stmt|;
comment|/**< gpio number of sfp present for this port. 0 if not exist */
block|}
struct|;
comment|/**  * set board parameter of the eth port  * this function used to set the board parameters into scratchpad  * registers. those paramters can be read later by OS driver.  *  * @param mac_base the virtual address of the mac registers (PCI BAR 2)  * @param params pointer to structure the includes the paramters  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_board_params_set
parameter_list|(
name|void
modifier|*
name|__iomem
name|mac_base
parameter_list|,
name|struct
name|al_eth_board_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/**  * get board parameter of the eth port  * this function used to get the board parameters from scratchpad  * registers.  *  * @param mac_base the virtual address of the mac registers (PCI BAR 2)  * @param params pointer to structure where the parameters will be stored.  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_board_params_get
parameter_list|(
name|void
modifier|*
name|__iomem
name|mac_base
parameter_list|,
name|struct
name|al_eth_board_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/*  * Wake-On-Lan (WoL)  *  * The following few functions configure the Wake-On-Lan packet detection  * inside the Integrated Ethernet MAC.  *  * There are other alternative ways to set WoL, such using the  * external 1000Base-T transceiver to set WoL mode.  *  * These APIs do not set the system-wide power-state, nor responsible on the  * transition from Sleep to Normal power state.  *  * For system level considerations, please refer to Annapurna Labs Alpine Wiki.  */
comment|/* Interrupt enable WoL MAC DA Unicast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_UNICAST
value|AL_BIT(0)
comment|/* Interrupt enable WoL L2 Multicast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_MULTICAST
value|AL_BIT(1)
comment|/* Interrupt enable WoL L2 Broadcast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_BROADCAST
value|AL_BIT(2)
comment|/* Interrupt enable WoL IPv4 detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_IPV4
value|AL_BIT(3)
comment|/* Interrupt enable WoL IPv6 detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_IPV6
value|AL_BIT(4)
comment|/* Interrupt enable WoL EtherType+MAC DA detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_ETHERTYPE_DA
value|AL_BIT(5)
comment|/* Interrupt enable WoL EtherType+L2 Broadcast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_ETHERTYPE_BC
value|AL_BIT(6)
comment|/* Interrupt enable WoL parser detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_PARSER
value|AL_BIT(7)
comment|/* Interrupt enable WoL magic detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_MAGIC
value|AL_BIT(8)
comment|/* Interrupt enable WoL magic+password detected  packet */
define|#
directive|define
name|AL_ETH_WOL_INT_MAGIC_PSWD
value|AL_BIT(9)
comment|/* Forward enable WoL MAC DA Unicast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_UNICAST
value|AL_BIT(0)
comment|/* Forward enable WoL L2 Multicast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_MULTICAST
value|AL_BIT(1)
comment|/* Forward enable WoL L2 Broadcast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_BROADCAST
value|AL_BIT(2)
comment|/* Forward enable WoL IPv4 detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_IPV4
value|AL_BIT(3)
comment|/* Forward enable WoL IPv6 detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_IPV6
value|AL_BIT(4)
comment|/* Forward enable WoL EtherType+MAC DA detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_ETHERTYPE_DA
value|AL_BIT(5)
comment|/* Forward enable WoL EtherType+L2 Broadcast detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_ETHERTYPE_BC
value|AL_BIT(6)
comment|/* Forward enable WoL parser detected  packet */
define|#
directive|define
name|AL_ETH_WOL_FWRD_PARSER
value|AL_BIT(7)
struct|struct
name|al_eth_wol_params
block|{
name|uint8_t
modifier|*
name|dest_addr
decl_stmt|;
comment|/**< 6 bytes array of destanation address for 				 magic packet detection */
name|uint8_t
modifier|*
name|pswd
decl_stmt|;
comment|/**< 6 bytes array of the password to use */
name|uint8_t
modifier|*
name|ipv4
decl_stmt|;
comment|/**< 4 bytes array of the ipv4 to use. 			    example: for ip = 192.168.1.2 			       ipv4[0]=2, ipv4[1]=1, ipv4[2]=168, ipv4[3]=192 */
name|uint8_t
modifier|*
name|ipv6
decl_stmt|;
comment|/** 16 bytes array of the ipv6 to use. 			   example: ip = 2607:f0d0:1002:0051:0000:0000:5231:1234 			       ipv6[0]=34, ipv6[1]=12, ipv6[2]=31 .. */
name|uint16_t
name|ethr_type1
decl_stmt|;
comment|/**< first ethertype to use */
name|uint16_t
name|ethr_type2
decl_stmt|;
comment|/**< secound ethertype to use */
name|uint16_t
name|forward_mask
decl_stmt|;
comment|/**< bitmask of AL_ETH_WOL_FWRD_* of the packet 				    types needed to be forward. */
name|uint16_t
name|int_mask
decl_stmt|;
comment|/**< bitmask of AL_ETH_WOL_INT_* of the packet types 				that will send interrupt to wake the system. */
block|}
struct|;
comment|/**  * enable the wol mechanism  * set what type of packets will wake up the system and what type of packets  * neet to forward after the system is up  *  * beside this function wol filter also need to be set by  * calling al_eth_filter_config with AL_ETH_RFW_FILTER_WOL  *  * @param adapter pointer to the private structure  * @param wol the parameters needed to configure the wol  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_wol_enable
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_eth_wol_params
modifier|*
name|wol
parameter_list|)
function_decl|;
comment|/**  * Disable the WoL mechnism.  *  * @param adapter pointer to the private structure  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_wol_disable
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Configure tx fwd vlan table entry  *  * @param adapter pointer to the private structure  * @param idx the entry index within the vlan table. The HW uses the vlan id  * field of the packet when accessing this table.  * @param udma_mask vlan table value that indicates that the packet should be forward back to  * the udmas, through the Rx path (udma_mask is one-hot representation)  * @param fwd_to_mac vlan table value that indicates that the packet should be forward to mac  *  * @return 0 on success. otherwise on failure.  */
name|int
name|al_eth_tx_fwd_vid_table_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|uint8_t
name|udma_mask
parameter_list|,
name|al_bool
name|fwd_to_mac
parameter_list|)
function_decl|;
comment|/** Tx Generic protocol detect Cam compare table entry  */
struct|struct
name|al_eth_tx_gpd_cam_entry
block|{
name|enum
name|AL_ETH_PROTO_ID
name|l3_proto_idx
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|l4_proto_idx
decl_stmt|;
name|enum
name|AL_ETH_TX_TUNNEL_MODE
name|tunnel_control
decl_stmt|;
name|uint8_t
name|source_vlan_count
range|:
literal|2
decl_stmt|;
name|uint8_t
name|tx_gpd_cam_ctrl
range|:
literal|1
decl_stmt|;
name|uint8_t
name|l3_proto_idx_mask
range|:
literal|5
decl_stmt|;
name|uint8_t
name|l4_proto_idx_mask
range|:
literal|5
decl_stmt|;
name|uint8_t
name|tunnel_control_mask
range|:
literal|3
decl_stmt|;
name|uint8_t
name|source_vlan_count_mask
range|:
literal|2
decl_stmt|;
block|}
struct|;
comment|/** Rx Generic protocol detect Cam compare table entry  */
struct|struct
name|al_eth_rx_gpd_cam_entry
block|{
name|enum
name|AL_ETH_PROTO_ID
name|outer_l3_proto_idx
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|outer_l4_proto_idx
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|inner_l3_proto_idx
decl_stmt|;
name|enum
name|AL_ETH_PROTO_ID
name|inner_l4_proto_idx
decl_stmt|;
name|uint8_t
name|parse_ctrl
decl_stmt|;
name|uint8_t
name|outer_l3_len
decl_stmt|;
name|uint8_t
name|l3_priority
decl_stmt|;
name|uint8_t
name|l4_dst_port_lsb
decl_stmt|;
name|uint8_t
name|rx_gpd_cam_ctrl
range|:
literal|1
decl_stmt|;
name|uint8_t
name|outer_l3_proto_idx_mask
range|:
literal|5
decl_stmt|;
name|uint8_t
name|outer_l4_proto_idx_mask
range|:
literal|5
decl_stmt|;
name|uint8_t
name|inner_l3_proto_idx_mask
range|:
literal|5
decl_stmt|;
name|uint8_t
name|inner_l4_proto_idx_mask
range|:
literal|5
decl_stmt|;
name|uint8_t
name|parse_ctrl_mask
decl_stmt|;
name|uint8_t
name|outer_l3_len_mask
decl_stmt|;
name|uint8_t
name|l3_priority_mask
decl_stmt|;
name|uint8_t
name|l4_dst_port_lsb_mask
decl_stmt|;
block|}
struct|;
enum|enum
name|AL_ETH_TX_GCP_ALU_OPSEL
block|{
name|AL_ETH_TX_GCP_ALU_L3_OFFSET
init|=
literal|0
block|,
name|AL_ETH_TX_GCP_ALU_OUTER_L3_OFFSET
init|=
literal|1
block|,
name|AL_ETH_TX_GCP_ALU_L3_LEN
init|=
literal|2
block|,
name|AL_ETH_TX_GCP_ALU_OUTER_L3_LEN
init|=
literal|3
block|,
name|AL_ETH_TX_GCP_ALU_L4_OFFSET
init|=
literal|4
block|,
name|AL_ETH_TX_GCP_ALU_L4_LEN
init|=
literal|5
block|,
name|AL_ETH_TX_GCP_ALU_TABLE_VAL
init|=
literal|10
block|}
enum|;
enum|enum
name|AL_ETH_RX_GCP_ALU_OPSEL
block|{
name|AL_ETH_RX_GCP_ALU_OUTER_L3_OFFSET
init|=
literal|0
block|,
name|AL_ETH_RX_GCP_ALU_INNER_L3_OFFSET
init|=
literal|1
block|,
name|AL_ETH_RX_GCP_ALU_OUTER_L4_OFFSET
init|=
literal|2
block|,
name|AL_ETH_RX_GCP_ALU_INNER_L4_OFFSET
init|=
literal|3
block|,
name|AL_ETH_RX_GCP_ALU_OUTER_L3_HDR_LEN_LAT
init|=
literal|4
block|,
name|AL_ETH_RX_GCP_ALU_INNER_L3_HDR_LEN_LAT
init|=
literal|5
block|,
name|AL_ETH_RX_GCP_ALU_OUTER_L3_HDR_LEN_SEL
init|=
literal|6
block|,
name|AL_ETH_RX_GCP_ALU_INNER_L3_HDR_LEN_SEL
init|=
literal|7
block|,
name|AL_ETH_RX_GCP_ALU_PARSE_RESULT_VECTOR_OFFSET_1
init|=
literal|8
block|,
name|AL_ETH_RX_GCP_ALU_PARSE_RESULT_VECTOR_OFFSET_2
init|=
literal|9
block|,
name|AL_ETH_RX_GCP_ALU_TABLE_VAL
init|=
literal|10
block|}
enum|;
comment|/** Tx Generic crc prameters table entry  */
struct|struct
name|al_eth_tx_gcp_table_entry
block|{
name|uint8_t
name|poly_sel
range|:
literal|1
decl_stmt|;
name|uint8_t
name|crc32_bit_comp
range|:
literal|1
decl_stmt|;
name|uint8_t
name|crc32_bit_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|crc32_byte_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|data_bit_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|data_byte_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|trail_size
range|:
literal|4
decl_stmt|;
name|uint8_t
name|head_size
range|:
literal|8
decl_stmt|;
name|uint8_t
name|head_calc
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mask_polarity
range|:
literal|1
decl_stmt|;
name|enum
name|AL_ETH_ALU_OPCODE
name|tx_alu_opcode_1
decl_stmt|;
name|enum
name|AL_ETH_ALU_OPCODE
name|tx_alu_opcode_2
decl_stmt|;
name|enum
name|AL_ETH_ALU_OPCODE
name|tx_alu_opcode_3
decl_stmt|;
name|enum
name|AL_ETH_TX_GCP_ALU_OPSEL
name|tx_alu_opsel_1
decl_stmt|;
name|enum
name|AL_ETH_TX_GCP_ALU_OPSEL
name|tx_alu_opsel_2
decl_stmt|;
name|enum
name|AL_ETH_TX_GCP_ALU_OPSEL
name|tx_alu_opsel_3
decl_stmt|;
name|enum
name|AL_ETH_TX_GCP_ALU_OPSEL
name|tx_alu_opsel_4
decl_stmt|;
name|uint32_t
name|gcp_mask
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|crc_init
decl_stmt|;
name|uint8_t
name|gcp_table_res
range|:
literal|7
decl_stmt|;
name|uint16_t
name|alu_val
range|:
literal|9
decl_stmt|;
block|}
struct|;
comment|/** Rx Generic crc prameters table entry  */
struct|struct
name|al_eth_rx_gcp_table_entry
block|{
name|uint8_t
name|poly_sel
range|:
literal|1
decl_stmt|;
name|uint8_t
name|crc32_bit_comp
range|:
literal|1
decl_stmt|;
name|uint8_t
name|crc32_bit_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|crc32_byte_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|data_bit_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|data_byte_swap
range|:
literal|1
decl_stmt|;
name|uint8_t
name|trail_size
range|:
literal|4
decl_stmt|;
name|uint8_t
name|head_size
range|:
literal|8
decl_stmt|;
name|uint8_t
name|head_calc
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mask_polarity
range|:
literal|1
decl_stmt|;
name|enum
name|AL_ETH_ALU_OPCODE
name|rx_alu_opcode_1
decl_stmt|;
name|enum
name|AL_ETH_ALU_OPCODE
name|rx_alu_opcode_2
decl_stmt|;
name|enum
name|AL_ETH_ALU_OPCODE
name|rx_alu_opcode_3
decl_stmt|;
name|enum
name|AL_ETH_RX_GCP_ALU_OPSEL
name|rx_alu_opsel_1
decl_stmt|;
name|enum
name|AL_ETH_RX_GCP_ALU_OPSEL
name|rx_alu_opsel_2
decl_stmt|;
name|enum
name|AL_ETH_RX_GCP_ALU_OPSEL
name|rx_alu_opsel_3
decl_stmt|;
name|enum
name|AL_ETH_RX_GCP_ALU_OPSEL
name|rx_alu_opsel_4
decl_stmt|;
name|uint32_t
name|gcp_mask
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|crc_init
decl_stmt|;
name|uint32_t
name|gcp_table_res
range|:
literal|27
decl_stmt|;
name|uint16_t
name|alu_val
range|:
literal|9
decl_stmt|;
block|}
struct|;
comment|/** Tx per_protocol_number crc& l3_checksum& l4_checksum command table entry  */
struct|struct
name|al_eth_tx_crc_chksum_replace_cmd_for_protocol_num_entry
block|{
name|al_bool
name|crc_en_00
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 0 ,enable_l3_checksum is 0 */
name|al_bool
name|crc_en_01
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 0 ,enable_l3_checksum is 1 */
name|al_bool
name|crc_en_10
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 1 ,enable_l3_checksum is 0 */
name|al_bool
name|crc_en_11
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 1 ,enable_l3_checksum is 1 */
name|al_bool
name|l4_csum_en_00
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 0 ,enable_l3_checksum is 0 */
name|al_bool
name|l4_csum_en_01
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 0 ,enable_l3_checksum is 1 */
name|al_bool
name|l4_csum_en_10
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 1 ,enable_l3_checksum is 0 */
name|al_bool
name|l4_csum_en_11
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 1 ,enable_l3_checksum is 1 */
name|al_bool
name|l3_csum_en_00
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 0 ,enable_l3_checksum is 0 */
name|al_bool
name|l3_csum_en_01
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 0 ,enable_l3_checksum is 1 */
name|al_bool
name|l3_csum_en_10
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 1 ,enable_l3_checksum is 0 */
name|al_bool
name|l3_csum_en_11
decl_stmt|;
comment|/*from Tx_buffer_descriptor: enable_l4_checksum is 1 ,enable_l3_checksum is 1 */
block|}
struct|;
comment|/**  * Configure tx_gpd_entry  *  * @param adapter pointer to the private structure  * @param idx the entry index  * @param tx_gpd_entry entry data for the Tx protocol detect Cam compare table  *  * @return 0 on success. otherwise on failure.  *  */
name|int
name|al_eth_tx_protocol_detect_table_entry_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_tx_gpd_cam_entry
modifier|*
name|tx_gpd_entry
parameter_list|)
function_decl|;
comment|/**  * Configure tx_gcp_entry  *  * @param adapter pointer to the private structure  * @param idx the entry index  * @param tx_gcp_entry entry data for the Tx Generic crc prameters table  *  * @return 0 on success. otherwise on failure.  *  */
name|int
name|al_eth_tx_generic_crc_table_entry_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_tx_gcp_table_entry
modifier|*
name|tx_gcp_entry
parameter_list|)
function_decl|;
comment|/**  * Configure tx_crc_chksum_replace_cmd_entry  *  * @param adapter pointer to the private structure  * @param idx the entry index  * @param tx_replace_entry entry data for the Tx crc_&_l3_checksum_&_l4_checksum replace command table  *  * @return 0 on success. otherwise on failure.  *  */
name|int
name|al_eth_tx_crc_chksum_replace_cmd_entry_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_tx_crc_chksum_replace_cmd_for_protocol_num_entry
modifier|*
name|tx_replace_entry
parameter_list|)
function_decl|;
comment|/**  * Configure rx_gpd_entry  *  * @param adapter pointer to the private structure  * @param idx the entry index  * @param rx_gpd_entry entry data for the Tx protocol detect Cam compare table  *  * @return 0 on success. otherwise on failure.  *  */
name|int
name|al_eth_rx_protocol_detect_table_entry_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_rx_gpd_cam_entry
modifier|*
name|rx_gpd_entry
parameter_list|)
function_decl|;
comment|/**  * Configure rx_gcp_entry  *  * @param adapter pointer to the private structure  * @param idx the entry index  * @param rx_gpd_entry entry data for the Tx protocol detect Cam compare table  * @param rx_gcp_entry entry data for the Tx Generic crc prameters table  *  * @return 0 on success. otherwise on failure.  *  */
name|int
name|al_eth_rx_generic_crc_table_entry_set
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|uint32_t
name|idx
parameter_list|,
name|struct
name|al_eth_rx_gcp_table_entry
modifier|*
name|rx_gcp_entry
parameter_list|)
function_decl|;
comment|/**  * Configure tx_gpd_table and regs  *  * @param adapter pointer to the private structure  *  */
name|int
name|al_eth_tx_protocol_detect_table_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Configure crc_chksum_replace_cmd_table  *  * @param adapter pointer to the private structure  *  */
name|int
name|al_eth_tx_crc_chksum_replace_cmd_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Configure tx_gcp_table and regs  *  * @param adapter pointer to the private structure  *  */
name|int
name|al_eth_tx_generic_crc_table_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Configure rx_gpd_table and regs  *  * @param adapter pointer to the private structure  *  */
name|int
name|al_eth_rx_protocol_detect_table_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
comment|/**  * Configure rx_gcp_table and regs  *  * @param adapter pointer to the private structure  *  */
name|int
name|al_eth_rx_generic_crc_table_init
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_ETH_H__ */
end_comment

begin_comment
comment|/** @} end of Ethernet group */
end_comment

end_unit

