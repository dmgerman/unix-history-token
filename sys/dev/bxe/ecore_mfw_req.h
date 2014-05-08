begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2014 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ECORE_MFW_REQ_H
end_ifndef

begin_define
define|#
directive|define
name|ECORE_MFW_REQ_H
end_define

begin_define
define|#
directive|define
name|PORT_0
value|0
end_define

begin_define
define|#
directive|define
name|PORT_1
value|1
end_define

begin_define
define|#
directive|define
name|PORT_MAX
value|2
end_define

begin_define
define|#
directive|define
name|NVM_PATH_MAX
value|2
end_define

begin_comment
comment|/* FCoE capabilities required from the driver */
end_comment

begin_struct
struct|struct
name|fcoe_capabilities
block|{
name|uint32_t
name|capability1
decl_stmt|;
comment|/* Maximum number of I/Os per connection */
define|#
directive|define
name|FCOE_IOS_PER_CONNECTION_MASK
value|0x0000ffff
define|#
directive|define
name|FCOE_IOS_PER_CONNECTION_SHIFT
value|0
comment|/* Maximum number of Logins per port */
define|#
directive|define
name|FCOE_LOGINS_PER_PORT_MASK
value|0xffff0000
define|#
directive|define
name|FCOE_LOGINS_PER_PORT_SHIFT
value|16
name|uint32_t
name|capability2
decl_stmt|;
comment|/* Maximum number of exchanges */
define|#
directive|define
name|FCOE_NUMBER_OF_EXCHANGES_MASK
value|0x0000ffff
define|#
directive|define
name|FCOE_NUMBER_OF_EXCHANGES_SHIFT
value|0
comment|/* Maximum NPIV WWN per port */
define|#
directive|define
name|FCOE_NPIV_WWN_PER_PORT_MASK
value|0xffff0000
define|#
directive|define
name|FCOE_NPIV_WWN_PER_PORT_SHIFT
value|16
name|uint32_t
name|capability3
decl_stmt|;
comment|/* Maximum number of targets supported */
define|#
directive|define
name|FCOE_TARGETS_SUPPORTED_MASK
value|0x0000ffff
define|#
directive|define
name|FCOE_TARGETS_SUPPORTED_SHIFT
value|0
comment|/* Maximum number of outstanding commands across all connections */
define|#
directive|define
name|FCOE_OUTSTANDING_COMMANDS_MASK
value|0xffff0000
define|#
directive|define
name|FCOE_OUTSTANDING_COMMANDS_SHIFT
value|16
name|uint32_t
name|capability4
decl_stmt|;
define|#
directive|define
name|FCOE_CAPABILITY4_STATEFUL
value|0x00000001
define|#
directive|define
name|FCOE_CAPABILITY4_STATELESS
value|0x00000002
define|#
directive|define
name|FCOE_CAPABILITY4_CAPABILITIES_REPORTED_VALID
value|0x00000004
block|}
struct|;
end_struct

begin_struct
struct|struct
name|glob_ncsi_oem_data
block|{
name|uint32_t
name|driver_version
decl_stmt|;
name|uint32_t
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|fcoe_capabilities
name|fcoe_features
index|[
name|NVM_PATH_MAX
index|]
index|[
name|PORT_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* current drv_info version */
end_comment

begin_define
define|#
directive|define
name|DRV_INFO_CUR_VER
value|2
end_define

begin_comment
comment|/* drv_info op codes supported */
end_comment

begin_enum
enum|enum
name|drv_info_opcode
block|{
name|ETH_STATS_OPCODE
block|,
name|FCOE_STATS_OPCODE
block|,
name|ISCSI_STATS_OPCODE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ETH_STAT_INFO_VERSION_LEN
value|12
end_define

begin_comment
comment|/*  Per PCI Function Ethernet Statistics required from the driver */
end_comment

begin_struct
struct|struct
name|eth_stats_info
block|{
comment|/* Function's Driver Version. padded to 12 */
name|uint8_t
name|version
index|[
name|ETH_STAT_INFO_VERSION_LEN
index|]
decl_stmt|;
comment|/* Locally Admin Addr. BigEndian EIU48. Actual size is 6 bytes */
name|uint8_t
name|mac_local
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|mac_add1
index|[
literal|8
index|]
decl_stmt|;
comment|/* Additional Programmed MAC Addr 1. */
name|uint8_t
name|mac_add2
index|[
literal|8
index|]
decl_stmt|;
comment|/* Additional Programmed MAC Addr 2. */
name|uint32_t
name|mtu_size
decl_stmt|;
comment|/* MTU Size. Note   : Negotiated MTU */
name|uint32_t
name|feature_flags
decl_stmt|;
comment|/* Feature_Flags. */
define|#
directive|define
name|FEATURE_ETH_CHKSUM_OFFLOAD_MASK
value|0x01
define|#
directive|define
name|FEATURE_ETH_LSO_MASK
value|0x02
define|#
directive|define
name|FEATURE_ETH_BOOTMODE_MASK
value|0x1C
define|#
directive|define
name|FEATURE_ETH_BOOTMODE_SHIFT
value|2
define|#
directive|define
name|FEATURE_ETH_BOOTMODE_NONE
value|(0x0<< 2)
define|#
directive|define
name|FEATURE_ETH_BOOTMODE_PXE
value|(0x1<< 2)
define|#
directive|define
name|FEATURE_ETH_BOOTMODE_ISCSI
value|(0x2<< 2)
define|#
directive|define
name|FEATURE_ETH_BOOTMODE_FCOE
value|(0x3<< 2)
define|#
directive|define
name|FEATURE_ETH_TOE_MASK
value|0x20
name|uint32_t
name|lso_max_size
decl_stmt|;
comment|/* LSO MaxOffloadSize. */
name|uint32_t
name|lso_min_seg_cnt
decl_stmt|;
comment|/* LSO MinSegmentCount. */
comment|/* Num Offloaded Connections TCP_IPv4. */
name|uint32_t
name|ipv4_ofld_cnt
decl_stmt|;
comment|/* Num Offloaded Connections TCP_IPv6. */
name|uint32_t
name|ipv6_ofld_cnt
decl_stmt|;
name|uint32_t
name|promiscuous_mode
decl_stmt|;
comment|/* Promiscuous Mode. non-zero true */
name|uint32_t
name|txq_size
decl_stmt|;
comment|/* TX Descriptors Queue Size */
name|uint32_t
name|rxq_size
decl_stmt|;
comment|/* RX Descriptors Queue Size */
comment|/* TX Descriptor Queue Avg Depth. % Avg Queue Depth since last poll */
name|uint32_t
name|txq_avg_depth
decl_stmt|;
comment|/* RX Descriptors Queue Avg Depth. % Avg Queue Depth since last poll */
name|uint32_t
name|rxq_avg_depth
decl_stmt|;
comment|/* IOV_Offload. 0=none; 1=MultiQueue, 2=VEB 3= VEPA*/
name|uint32_t
name|iov_offload
decl_stmt|;
comment|/* Number of NetQueue/VMQ Config'd. */
name|uint32_t
name|netq_cnt
decl_stmt|;
name|uint32_t
name|vf_cnt
decl_stmt|;
comment|/* Num VF assigned to this PF. */
block|}
struct|;
end_struct

begin_comment
comment|/*  Per PCI Function FCOE Statistics required from the driver */
end_comment

begin_struct
struct|struct
name|fcoe_stats_info
block|{
name|uint8_t
name|version
index|[
literal|12
index|]
decl_stmt|;
comment|/* Function's Driver Version. */
name|uint8_t
name|mac_local
index|[
literal|8
index|]
decl_stmt|;
comment|/* Locally Admin Addr. */
name|uint8_t
name|mac_add1
index|[
literal|8
index|]
decl_stmt|;
comment|/* Additional Programmed MAC Addr 1. */
name|uint8_t
name|mac_add2
index|[
literal|8
index|]
decl_stmt|;
comment|/* Additional Programmed MAC Addr 2. */
comment|/* QoS Priority (per 802.1p). 0-7255 */
name|uint32_t
name|qos_priority
decl_stmt|;
name|uint32_t
name|txq_size
decl_stmt|;
comment|/* FCoE TX Descriptors Queue Size. */
name|uint32_t
name|rxq_size
decl_stmt|;
comment|/* FCoE RX Descriptors Queue Size. */
comment|/* FCoE TX Descriptor Queue Avg Depth. */
name|uint32_t
name|txq_avg_depth
decl_stmt|;
comment|/* FCoE RX Descriptors Queue Avg Depth. */
name|uint32_t
name|rxq_avg_depth
decl_stmt|;
name|uint32_t
name|rx_frames_lo
decl_stmt|;
comment|/* FCoE RX Frames received. */
name|uint32_t
name|rx_frames_hi
decl_stmt|;
comment|/* FCoE RX Frames received. */
name|uint32_t
name|rx_bytes_lo
decl_stmt|;
comment|/* FCoE RX Bytes received. */
name|uint32_t
name|rx_bytes_hi
decl_stmt|;
comment|/* FCoE RX Bytes received. */
name|uint32_t
name|tx_frames_lo
decl_stmt|;
comment|/* FCoE TX Frames sent. */
name|uint32_t
name|tx_frames_hi
decl_stmt|;
comment|/* FCoE TX Frames sent. */
name|uint32_t
name|tx_bytes_lo
decl_stmt|;
comment|/* FCoE TX Bytes sent. */
name|uint32_t
name|tx_bytes_hi
decl_stmt|;
comment|/* FCoE TX Bytes sent. */
name|uint32_t
name|rx_fcs_errors
decl_stmt|;
comment|/* number of receive packets with FCS errors */
name|uint32_t
name|rx_fc_crc_errors
decl_stmt|;
comment|/* number of FC frames with CRC errors*/
name|uint32_t
name|fip_login_failures
decl_stmt|;
comment|/* number of FCoE/FIP Login failures */
block|}
struct|;
end_struct

begin_comment
comment|/* Per PCI  Function iSCSI Statistics required from the driver*/
end_comment

begin_struct
struct|struct
name|iscsi_stats_info
block|{
name|uint8_t
name|version
index|[
literal|12
index|]
decl_stmt|;
comment|/* Function's Driver Version. */
name|uint8_t
name|mac_local
index|[
literal|8
index|]
decl_stmt|;
comment|/* Locally Admin iSCSI MAC Addr. */
name|uint8_t
name|mac_add1
index|[
literal|8
index|]
decl_stmt|;
comment|/* Additional Programmed MAC Addr 1. */
comment|/* QoS Priority (per 802.1p). 0-7255 */
name|uint32_t
name|qos_priority
decl_stmt|;
name|uint8_t
name|initiator_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* iSCSI Boot Initiator Node name. */
name|uint8_t
name|ww_port_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* iSCSI World wide port name */
name|uint8_t
name|boot_target_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* iSCSI Boot Target Name. */
name|uint8_t
name|boot_target_ip
index|[
literal|16
index|]
decl_stmt|;
comment|/* iSCSI Boot Target IP. */
name|uint32_t
name|boot_target_portal
decl_stmt|;
comment|/* iSCSI Boot Target Portal. */
name|uint8_t
name|boot_init_ip
index|[
literal|16
index|]
decl_stmt|;
comment|/* iSCSI Boot Initiator IP Address. */
name|uint32_t
name|max_frame_size
decl_stmt|;
comment|/* Max Frame Size. bytes */
name|uint32_t
name|txq_size
decl_stmt|;
comment|/* PDU TX Descriptors Queue Size. */
name|uint32_t
name|rxq_size
decl_stmt|;
comment|/* PDU RX Descriptors Queue Size. */
name|uint32_t
name|txq_avg_depth
decl_stmt|;
comment|/*PDU TX Descriptor Queue Avg Depth. */
name|uint32_t
name|rxq_avg_depth
decl_stmt|;
comment|/*PDU RX Descriptors Queue Avg Depth. */
name|uint32_t
name|rx_pdus_lo
decl_stmt|;
comment|/* iSCSI PDUs received. */
name|uint32_t
name|rx_pdus_hi
decl_stmt|;
comment|/* iSCSI PDUs received. */
name|uint32_t
name|rx_bytes_lo
decl_stmt|;
comment|/* iSCSI RX Bytes received. */
name|uint32_t
name|rx_bytes_hi
decl_stmt|;
comment|/* iSCSI RX Bytes received. */
name|uint32_t
name|tx_pdus_lo
decl_stmt|;
comment|/* iSCSI PDUs sent. */
name|uint32_t
name|tx_pdus_hi
decl_stmt|;
comment|/* iSCSI PDUs sent. */
name|uint32_t
name|tx_bytes_lo
decl_stmt|;
comment|/* iSCSI PDU TX Bytes sent. */
name|uint32_t
name|tx_bytes_hi
decl_stmt|;
comment|/* iSCSI PDU TX Bytes sent. */
name|uint32_t
name|pcp_prior_map_tbl
decl_stmt|;
comment|/*C-PCP to S-PCP Priority MapTable. 				9 nibbles, the position of each nibble 				represents the C-PCP value, the value 				of the nibble = S-PCP value.*/
block|}
struct|;
end_struct

begin_union
union|union
name|drv_info_to_mcp
block|{
name|struct
name|eth_stats_info
name|ether_stat
decl_stmt|;
name|struct
name|fcoe_stats_info
name|fcoe_stat
decl_stmt|;
name|struct
name|iscsi_stats_info
name|iscsi_stat
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECORE_MFW_REQ_H */
end_comment

end_unit

