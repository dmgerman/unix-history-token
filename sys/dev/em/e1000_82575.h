begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_82575_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_82575_H_
end_define

begin_include
include|#
directive|include
file|"e1000_api.h"
end_include

begin_comment
comment|/* Receive Address Register Count  * Number of high/low register pairs in the RAR.  The RAR (Receive Address  * Registers) holds the directed and multicast addresses that we monitor.  * These entries are also used for MAC-based filtering.  */
end_comment

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES_82575
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|E1000_BIT_FIELDS
end_ifdef

begin_struct
struct|struct
name|e1000_adv_data_desc
block|{
name|u64
name|buffer_addr
decl_stmt|;
comment|/* Address of the descriptor's data buffer */
union|union
block|{
name|u32
name|data
decl_stmt|;
struct|struct
block|{
name|u32
name|datalen
range|:
literal|16
decl_stmt|;
comment|/* Data buffer length */
name|u32
name|rsvd
range|:
literal|4
decl_stmt|;
name|u32
name|dtyp
range|:
literal|4
decl_stmt|;
comment|/* Descriptor type */
name|u32
name|dcmd
range|:
literal|8
decl_stmt|;
comment|/* Descriptor command */
block|}
name|config
struct|;
block|}
name|lower
union|;
union|union
block|{
name|u32
name|data
decl_stmt|;
struct|struct
block|{
name|u32
name|status
range|:
literal|4
decl_stmt|;
comment|/* Descriptor status */
name|u32
name|idx
range|:
literal|4
decl_stmt|;
name|u32
name|popts
range|:
literal|6
decl_stmt|;
comment|/* Packet Options */
name|u32
name|paylen
range|:
literal|18
decl_stmt|;
comment|/* Payload length */
block|}
name|options
struct|;
block|}
name|upper
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|E1000_TXD_DTYP_ADV_C
value|0x2
end_define

begin_comment
comment|/* Advanced Context Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_DTYP_ADV_D
value|0x3
end_define

begin_comment
comment|/* Advanced Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TXD_CMD_DEXT
value|0x20
end_define

begin_comment
comment|/* Descriptor extension (0 = legacy) */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TUCMD_SNAP
value|0x1
end_define

begin_comment
comment|/* SNAP indication */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TUCMD_IPV4
value|0x2
end_define

begin_comment
comment|/* IP Packet Type: 1=IPv4 */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TUCMD_IPV6
value|0x0
end_define

begin_comment
comment|/* IP Packet Type: 0=IPv6 */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TUCMD_L4T_UDP
value|0x0
end_define

begin_comment
comment|/* L4 Packet TYPE of UDP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TUCMD_L4T_TCP
value|0x4
end_define

begin_comment
comment|/* L4 Packet TYPE of TCP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_TUCMD_MKRREQ
value|0x10
end_define

begin_comment
comment|/* Indicates markers are required */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_DCMD_EOP
value|0x1
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_DCMD_IFCS
value|0x2
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_DCMD_RS
value|0x8
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_DCMD_VLE
value|0x40
end_define

begin_comment
comment|/* Add VLAN tag */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_DCMD_TSE
value|0x80
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_struct
struct|struct
name|e1000_adv_context_desc
block|{
union|union
block|{
name|u32
name|ip_config
decl_stmt|;
struct|struct
block|{
name|u32
name|iplen
range|:
literal|9
decl_stmt|;
name|u32
name|maclen
range|:
literal|7
decl_stmt|;
name|u32
name|vlan_tag
range|:
literal|16
decl_stmt|;
block|}
name|fields
struct|;
block|}
name|ip_setup
union|;
name|u32
name|seq_num
decl_stmt|;
union|union
block|{
name|u64
name|l4_config
decl_stmt|;
struct|struct
block|{
name|u32
name|mkrloc
range|:
literal|9
decl_stmt|;
name|u32
name|tucmd
range|:
literal|11
decl_stmt|;
name|u32
name|dtyp
range|:
literal|4
decl_stmt|;
name|u32
name|adv
range|:
literal|8
decl_stmt|;
name|u32
name|rsvd
range|:
literal|4
decl_stmt|;
name|u32
name|idx
range|:
literal|4
decl_stmt|;
name|u32
name|l4len
range|:
literal|8
decl_stmt|;
name|u32
name|mss
range|:
literal|16
decl_stmt|;
block|}
name|fields
struct|;
block|}
name|l4_setup
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SRRCTL bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEPKT_SHIFT
value|10
end_define

begin_comment
comment|/* Shift _right_ */
end_comment

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEHDRSIZE_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEHDRSIZE_SHIFT
value|2
end_define

begin_comment
comment|/* Shift _left_ */
end_comment

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_LEGACY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_ADV_ONEBUF
value|0x02000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_SPLIT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_SPLIT_ALWAYS
value|0x0A000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_REPLICATION
value|0x06000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_REPLICATION_LARGE_PKT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_TX_HEAD_WB_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_TX_SEQNUM_WB_ENABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_RSS_4Q
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV4_UDP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_UDP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_UDP_EX
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_EICR_TX_QUEUE
value|( \     E1000_EICR_TX_QUEUE0 |    \     E1000_EICR_TX_QUEUE1 |    \     E1000_EICR_TX_QUEUE2 |    \     E1000_EICR_TX_QUEUE3)
end_define

begin_define
define|#
directive|define
name|E1000_EICR_RX_QUEUE
value|( \     E1000_EICR_RX_QUEUE0 |    \     E1000_EICR_RX_QUEUE1 |    \     E1000_EICR_RX_QUEUE2 |    \     E1000_EICR_RX_QUEUE3)
end_define

begin_define
define|#
directive|define
name|E1000_EIMS_RX_QUEUE
value|E1000_EICR_RX_QUEUE
end_define

begin_define
define|#
directive|define
name|E1000_EIMS_TX_QUEUE
value|E1000_EICR_TX_QUEUE
end_define

begin_define
define|#
directive|define
name|EIMS_ENABLE_MASK
value|( \     E1000_EIMS_RX_QUEUE  | \     E1000_EIMS_TX_QUEUE  | \     E1000_EIMS_TCP_TIMER | \     E1000_EIMS_OTHER)
end_define

begin_comment
comment|/* Immediate Interrupt RX (A.K.A. Low Latency Interrupt) */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIR_PORT_IM_EN
value|0x00010000
end_define

begin_comment
comment|/* TCP port enable */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIR_PORT_BP
value|0x00020000
end_define

begin_comment
comment|/* TCP port check bypass */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_SIZE_BP
value|0x00001000
end_define

begin_comment
comment|/* Packet size bypass */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_URG
value|0x00002000
end_define

begin_comment
comment|/* Check URG bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_ACK
value|0x00004000
end_define

begin_comment
comment|/* Check ACK bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_PSH
value|0x00008000
end_define

begin_comment
comment|/* Check PSH bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_RST
value|0x00010000
end_define

begin_comment
comment|/* Check RST bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_SYN
value|0x00020000
end_define

begin_comment
comment|/* Check SYN bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_FIN
value|0x00040000
end_define

begin_comment
comment|/* Check FIN bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREX_CTRL_BP
value|0x00080000
end_define

begin_comment
comment|/* Bypass check of control bits */
end_comment

begin_comment
comment|/* Receive Descriptor - Advanced */
end_comment

begin_union
union|union
name|e1000_adv_rx_desc
block|{
struct|struct
block|{
name|u64
name|pkt_addr
decl_stmt|;
comment|/* Packet buffer address */
name|u64
name|hdr_addr
decl_stmt|;
comment|/* Header buffer address */
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
struct|struct
block|{
name|u16
name|pkt_info
decl_stmt|;
comment|/* RSS type, Packet type */
name|u16
name|hdr_info
decl_stmt|;
comment|/* Split Header, 				                      * header buffer length */
block|}
name|lo_dword
struct|;
union|union
block|{
name|u32
name|rss
decl_stmt|;
comment|/* RSS Hash */
struct|struct
block|{
name|u16
name|ip_id
decl_stmt|;
comment|/* IP id */
name|u16
name|csum
decl_stmt|;
comment|/* Packet Checksum */
block|}
name|csum_ip
struct|;
block|}
name|hi_dword
union|;
block|}
name|lower
struct|;
struct|struct
block|{
name|u32
name|status_error
decl_stmt|;
comment|/* ext status/error */
name|u16
name|length
decl_stmt|;
comment|/* Packet length */
name|u16
name|vlan
decl_stmt|;
comment|/* VLAN tag */
block|}
name|upper
struct|;
block|}
name|wb
struct|;
comment|/* writeback */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_HDRBUFLEN_MASK
value|0x7FE0
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_HDRBUFLEN_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_SPLITHEADER_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_SPH
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_HBO
value|0x00800000
end_define

begin_comment
comment|/* RSS Hash results */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV4
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV4_TCP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_TCP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_EX
value|0x00000005
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_TCP_EX
value|0x00000006
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV4_UDP
value|0x00000007
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_UDP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_UDP_EX
value|0x00000009
end_define

begin_comment
comment|/* Transmit Descriptor - Advanced */
end_comment

begin_union
union|union
name|e1000_adv_tx_desc
block|{
struct|struct
block|{
name|u64
name|buffer_addr
decl_stmt|;
comment|/* Address of descriptor's data buf */
name|u32
name|cmd_type_len
decl_stmt|;
name|u32
name|olinfo_status
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
name|u64
name|rsvd
decl_stmt|;
comment|/* Reserved */
name|u32
name|nxtseq_seed
decl_stmt|;
name|u32
name|status
decl_stmt|;
block|}
name|wb
struct|;
block|}
union|;
end_union

begin_comment
comment|/* Adv Transmit Descriptor Config Masks */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DTYP_CTXT
value|0x00200000
end_define

begin_comment
comment|/* Advanced Context Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DTYP_DATA
value|0x00300000
end_define

begin_comment
comment|/* Advanced Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_EOP
value|0x01000000
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_IFCS
value|0x02000000
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_RDMA
value|0x04000000
end_define

begin_comment
comment|/* RDMA */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_RS
value|0x08000000
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_DDTYP_ISCSI
value|0x10000000
end_define

begin_comment
comment|/* DDP hdr type or iSCSI */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_DEXT
value|0x20000000
end_define

begin_comment
comment|/* Descriptor extension (1=Adv) */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_VLE
value|0x40000000
end_define

begin_comment
comment|/* VLAN pkt enable */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_TSE
value|0x80000000
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_MAC_LINKSEC
value|0x00040000
end_define

begin_comment
comment|/* Apply LinkSec on packet */
end_comment

begin_define
define|#
directive|define
name|E1000_ADV_MAC_TSTAMP
value|0x00080000
end_define

begin_comment
comment|/* IEEE1588 Timestamp packet */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_STAT_SN_CRC
value|0x00000002
end_define

begin_comment
comment|/* NXTSEQ/SEED present in WB */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_IDX_SHIFT
value|4
end_define

begin_comment
comment|/* Adv desc Index shift */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_POPTS_EOM
value|0x00000400
end_define

begin_comment
comment|/* Enable L bit in RDMA DDP hdr */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_POPTS_ISCO_1ST
value|0x00000000
end_define

begin_comment
comment|/* 1st TSO of iSCSI PDU */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_POPTS_ISCO_MDL
value|0x00000800
end_define

begin_comment
comment|/* Middle TSO of iSCSI PDU */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_POPTS_ISCO_LAST
value|0x00001000
end_define

begin_comment
comment|/* Last TSO of iSCSI PDU */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_POPTS_ISCO_FULL
value|0x00001800
end_define

begin_comment
comment|/* 1st&Last TSO-full iSCSI PDU*/
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_PAYLEN_SHIFT
value|14
end_define

begin_comment
comment|/* Adv desc PAYLEN shift */
end_comment

begin_comment
comment|/* Context descriptors */
end_comment

begin_struct
struct|struct
name|e1000_adv_tx_context_desc
block|{
name|u32
name|vlan_macip_lens
decl_stmt|;
name|u32
name|seqnum_seed
decl_stmt|;
name|u32
name|type_tucmd_mlhl
decl_stmt|;
name|u32
name|mss_l4len_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|E1000_ADVTXD_MACLEN_SHIFT
value|9
end_define

begin_comment
comment|/* Adv ctxt desc mac len shift */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_VLAN_SHIFT
value|16
end_define

begin_comment
comment|/* Adv ctxt vlan tag shift */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_SNAP
value|0x00000200
end_define

begin_comment
comment|/* SNAP indication */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_IPV4
value|0x00000400
end_define

begin_comment
comment|/* IP Packet Type: 1=IPv4 */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_IPV6
value|0x00000000
end_define

begin_comment
comment|/* IP Packet Type: 0=IPv6 */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_L4T_UDP
value|0x00000000
end_define

begin_comment
comment|/* L4 Packet TYPE of UDP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_L4T_TCP
value|0x00000800
end_define

begin_comment
comment|/* L4 Packet TYPE of TCP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_MKRREQ
value|0x00002000
end_define

begin_comment
comment|/* Req requires Markers and CRC */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_L4LEN_SHIFT
value|8
end_define

begin_comment
comment|/* Adv ctxt L4LEN shift */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_MSS_SHIFT
value|16
end_define

begin_comment
comment|/* Adv ctxt MSS shift */
end_comment

begin_comment
comment|/* Additional Transmit Descriptor Control definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_QUEUE_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* Enable specific Tx Queue */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_SWFLSH
value|0x04000000
end_define

begin_comment
comment|/* Tx Desc. write-back flushing */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_PRIORITY
value|0x08000000
end_define

begin_comment
comment|/* Tx Queue Arbitration Priority                                                  0=low, 1=high */
end_comment

begin_comment
comment|/* Additional Receive Descriptor Control definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_QUEUE_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* Enable specific Rx Queue */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_SWFLSH
value|0x04000000
end_define

begin_comment
comment|/* Rx Desc. write-back flushing */
end_comment

begin_comment
comment|/* Direct Cache Access (DCA) definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_DESC_DCA_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_HEAD_DCA_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_DATA_DCA_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL_DESC_DCA_EN
value|(1<< 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

