begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2010, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
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

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_82575_SERDES
value|((ID_LED_DEF1_DEF2<< 12) | \                                      (ID_LED_DEF1_DEF2<<  8) | \                                      (ID_LED_DEF1_DEF2<<  4) | \                                      (ID_LED_OFF1_ON2))
end_define

begin_comment
comment|/*  * Receive Address Register Count  * Number of high/low register pairs in the RAR.  The RAR (Receive Address  * Registers) holds the directed and multicast addresses that we monitor.  * These entries are also used for MAC-based filtering.  */
end_comment

begin_comment
comment|/*  * For 82576, there are an additional set of RARs that begin at an offset  * separate from the first set of RARs.  */
end_comment

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES_82575
value|16
end_define

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES_82576
value|24
end_define

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES_82580
value|24
end_define

begin_define
define|#
directive|define
name|E1000_SW_SYNCH_MB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|E1000_STAT_DEV_RST_SET
value|0x00100000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_DEV_RST
value|0x20000000
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
name|__le64
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

begin_comment
comment|/* Extended Device Control */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_NSICR
value|0x00000001
end_define

begin_comment
comment|/* Disable Intr Clear all on read */
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
name|E1000_SRRCTL_DESCTYPE_MASK
value|0x0E000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_TIMESTAMP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DROP_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEPKT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEHDR_MASK
value|0x00003F00
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
name|E1000_MRQC_ENABLE_VMDQ
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_VMDQ_RSS_2Q
value|0x00000005
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
name|E1000_MRQC_ENABLE_RSS_8Q
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_VMRCTL_MIRROR_PORT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_VMRCTL_MIRROR_DSTPORT_MASK
value|(7<< E1000_VMRCTL_MIRROR_PORT_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VMRCTL_POOL_MIRROR_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|E1000_VMRCTL_UPLINK_MIRROR_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|E1000_VMRCTL_DOWNLINK_MIRROR_ENABLE
value|(1<< 2)
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
comment|/* Immediate Interrupt Rx (A.K.A. Low Latency Interrupt) */
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
name|E1000_IMIREXT_SIZE_BP
value|0x00001000
end_define

begin_comment
comment|/* Packet size bypass */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_URG
value|0x00002000
end_define

begin_comment
comment|/* Check URG bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_ACK
value|0x00004000
end_define

begin_comment
comment|/* Check ACK bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_PSH
value|0x00008000
end_define

begin_comment
comment|/* Check PSH bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_RST
value|0x00010000
end_define

begin_comment
comment|/* Check RST bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_SYN
value|0x00020000
end_define

begin_comment
comment|/* Check SYN bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_FIN
value|0x00040000
end_define

begin_comment
comment|/* Check FIN bit in header */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CTRL_BP
value|0x00080000
end_define

begin_comment
comment|/* Bypass check of ctrl bits */
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
name|__le64
name|pkt_addr
decl_stmt|;
comment|/* Packet buffer address */
name|__le64
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
union|union
block|{
name|__le32
name|data
decl_stmt|;
struct|struct
block|{
name|__le16
name|pkt_info
decl_stmt|;
comment|/*RSS type, Pkt type*/
name|__le16
name|hdr_info
decl_stmt|;
comment|/* Split Header, 				        	          * header buffer len*/
block|}
name|hs_rss
struct|;
block|}
name|lo_dword
union|;
union|union
block|{
name|__le32
name|rss
decl_stmt|;
comment|/* RSS Hash */
struct|struct
block|{
name|__le16
name|ip_id
decl_stmt|;
comment|/* IP id */
name|__le16
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
name|__le32
name|status_error
decl_stmt|;
comment|/* ext status/error */
name|__le16
name|length
decl_stmt|;
comment|/* Packet length */
name|__le16
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
value|0x0000000F
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
name|E1000_RXDADV_STAT_TS
value|0x10000
end_define

begin_comment
comment|/* Pkt was time stamped */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_STAT_TSIP
value|0x08000
end_define

begin_comment
comment|/* timestamp in packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_ERR_HBO
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
name|E1000_RXDADV_RSSTYPE_IPV4_TCP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV4
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_TCP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6_EX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_RSSTYPE_IPV6
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
comment|/* RSS Packet Types as indicated in the receive descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_IPV4
value|0x00000010
end_define

begin_comment
comment|/* IPV4 hdr present */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_IPV4_EX
value|0x00000020
end_define

begin_comment
comment|/* IPV4 hdr + extensions */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_IPV6
value|0x00000040
end_define

begin_comment
comment|/* IPV6 hdr present */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_IPV6_EX
value|0x00000080
end_define

begin_comment
comment|/* IPV6 hdr + extensions */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_TCP
value|0x00000100
end_define

begin_comment
comment|/* TCP hdr present */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_UDP
value|0x00000200
end_define

begin_comment
comment|/* UDP hdr present */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_SCTP
value|0x00000400
end_define

begin_comment
comment|/* SCTP hdr present */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_NFS
value|0x00000800
end_define

begin_comment
comment|/* NFS hdr present */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_IPSEC_ESP
value|0x00001000
end_define

begin_comment
comment|/* IPSec ESP */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_IPSEC_AH
value|0x00002000
end_define

begin_comment
comment|/* IPSec AH */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_LINKSEC
value|0x00004000
end_define

begin_comment
comment|/* LinkSec Encap */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_ETQF
value|0x00008000
end_define

begin_comment
comment|/* PKTTYPE is ETQF index */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_ETQF_MASK
value|0x00000070
end_define

begin_comment
comment|/* ETQF has 8 indices */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_PKTTYPE_ETQF_SHIFT
value|4
end_define

begin_comment
comment|/* Right-shift 4 bits */
end_comment

begin_comment
comment|/* LinkSec results */
end_comment

begin_comment
comment|/* Security Processing bit Indication */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDADV_LNKSEC_STATUS_SECP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_LNKSEC_ERROR_BIT_MASK
value|0x18000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_LNKSEC_ERROR_NO_SA_MATCH
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_LNKSEC_ERROR_REPLAY_ERROR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_LNKSEC_ERROR_BAD_SIG
value|0x18000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_IPSEC_STATUS_SECP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_IPSEC_ERROR_BIT_MASK
value|0x18000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_IPSEC_ERROR_INVALID_PROTOCOL
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_IPSEC_ERROR_INVALID_LENGTH
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_IPSEC_ERROR_AUTHENTICATION_FAILED
value|0x18000000
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
name|__le64
name|buffer_addr
decl_stmt|;
comment|/* Address of descriptor's data buf */
name|__le32
name|cmd_type_len
decl_stmt|;
name|__le32
name|olinfo_status
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
name|__le64
name|rsvd
decl_stmt|;
comment|/* Reserved */
name|__le32
name|nxtseq_seed
decl_stmt|;
name|__le32
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
name|E1000_ADVTXD_MAC_LINKSEC
value|0x00040000
end_define

begin_comment
comment|/* Apply LinkSec on packet */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_MAC_TSTAMP
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
name|E1000_ADVTXD_POPTS_IPSEC
value|0x00000400
end_define

begin_comment
comment|/* IPSec offload request */
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
name|__le32
name|vlan_macip_lens
decl_stmt|;
name|__le32
name|seqnum_seed
decl_stmt|;
name|__le32
name|type_tucmd_mlhl
decl_stmt|;
name|__le32
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
name|E1000_ADVTXD_TUCMD_L4T_SCTP
value|0x00001000
end_define

begin_comment
comment|/* L4 Packet TYPE of SCTP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_IPSEC_TYPE_ESP
value|0x00002000
end_define

begin_comment
comment|/* IPSec Type ESP */
end_comment

begin_comment
comment|/* IPSec Encrypt Enable for ESP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_IPSEC_ENCRYPT_EN
value|0x00004000
end_define

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
comment|/* Adv ctxt IPSec SA IDX mask */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_IPSEC_SA_INDEX_MASK
value|0x000000FF
end_define

begin_comment
comment|/* Adv ctxt IPSec ESP len mask */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_IPSEC_ESP_LEN_MASK
value|0x000000FF
end_define

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

begin_comment
comment|/* Tx Queue Arbitration Priority 0=low, 1=high */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_PRIORITY
value|0x08000000
end_define

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
name|E1000_DCA_CTRL_DCA_ENABLE
value|0x00000000
end_define

begin_comment
comment|/* DCA Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_CTRL_DCA_DISABLE
value|0x00000001
end_define

begin_comment
comment|/* DCA Disable */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_CTRL_DCA_MODE_CB1
value|0x00
end_define

begin_comment
comment|/* DCA Mode CB1 */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_CTRL_DCA_MODE_CB2
value|0x02
end_define

begin_comment
comment|/* DCA Mode CB2 */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_CPUID_MASK
value|0x0000001F
end_define

begin_comment
comment|/* Rx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_DESC_DCA_EN
value|(1<< 5)
end_define

begin_comment
comment|/* DCA Rx Desc enable */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_HEAD_DCA_EN
value|(1<< 6)
end_define

begin_comment
comment|/* DCA Rx Desc header enable */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_DATA_DCA_EN
value|(1<< 7)
end_define

begin_comment
comment|/* DCA Rx Desc payload enable */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL_CPUID_MASK
value|0x0000001F
end_define

begin_comment
comment|/* Tx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL_DESC_DCA_EN
value|(1<< 5)
end_define

begin_comment
comment|/* DCA Tx Desc enable */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL_TX_WB_RO_EN
value|(1<< 11)
end_define

begin_comment
comment|/* Tx Desc writeback RO bit */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL_CPUID_MASK_82576
value|0xFF000000
end_define

begin_comment
comment|/* Tx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_CPUID_MASK_82576
value|0xFF000000
end_define

begin_comment
comment|/* Rx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL_CPUID_SHIFT_82576
value|24
end_define

begin_comment
comment|/* Tx CPUID */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL_CPUID_SHIFT_82576
value|24
end_define

begin_comment
comment|/* Rx CPUID */
end_comment

begin_comment
comment|/* Additional interrupt register bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_LSECPNS
value|0x00000020
end_define

begin_comment
comment|/* PN threshold - server */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_LSECPNS
value|E1000_ICR_LSECPNS
end_define

begin_comment
comment|/* PN threshold - server */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_LSECPNS
value|E1000_ICR_LSECPNS
end_define

begin_comment
comment|/* PN threshold - server */
end_comment

begin_comment
comment|/* ETQF register bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_ETQF_FILTER_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|E1000_ETQF_IMM_INT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|E1000_ETQF_1588
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|E1000_ETQF_QUEUE_ENABLE
value|(1<< 31)
end_define

begin_comment
comment|/*  * ETQF filter list: one static filter per filter consumer. This is  *                   to avoid filter collisions later. Add new filters  *                   here!!  *  * Current filters:  *    EAPOL 802.1x (0x888e): Filter 0  */
end_comment

begin_define
define|#
directive|define
name|E1000_ETQF_FILTER_EAPOL
value|0
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_VF_BP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_1588_TIME_STAMP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_MASK_PROTO_BP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_MASK_SOURCE_ADDR_BP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_MASK_DEST_ADDR_BP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_FTQF_MASK_SOURCE_PORT_BP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_NVM_APME_82575
value|0x0400
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VFS
value|8
end_define

begin_define
define|#
directive|define
name|E1000_DTXSWC_MAC_SPOOF_MASK
value|0x000000FF
end_define

begin_comment
comment|/* Per VF MAC spoof control */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXSWC_VLAN_SPOOF_MASK
value|0x0000FF00
end_define

begin_comment
comment|/* Per VF VLAN spoof control */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXSWC_LLE_MASK
value|0x00FF0000
end_define

begin_comment
comment|/* Per VF Local LB enables */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXSWC_VLAN_SPOOF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_DTXSWC_LLE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_DTXSWC_VMDQ_LOOPBACK_EN
value|(1<< 31)
end_define

begin_comment
comment|/* global VF LB enable */
end_comment

begin_comment
comment|/* Easy defines for setting default pool, would normally be left a zero */
end_comment

begin_define
define|#
directive|define
name|E1000_VT_CTL_DEFAULT_POOL_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|E1000_VT_CTL_DEFAULT_POOL_MASK
value|(0x7<< E1000_VT_CTL_DEFAULT_POOL_SHIFT)
end_define

begin_comment
comment|/* Other useful VMD_CTL register defines */
end_comment

begin_define
define|#
directive|define
name|E1000_VT_CTL_IGNORE_MAC
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|E1000_VT_CTL_DISABLE_DEF_POOL
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|E1000_VT_CTL_VM_REPL_EN
value|(1<< 30)
end_define

begin_comment
comment|/* Per VM Offload register setup */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_RLPML_MASK
value|0x00003FFF
end_define

begin_comment
comment|/* Long Packet Maximum Length mask */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_LPE
value|0x00010000
end_define

begin_comment
comment|/* Accept Long packet */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_RSSE
value|0x00020000
end_define

begin_comment
comment|/* Enable RSS */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_AUPE
value|0x01000000
end_define

begin_comment
comment|/* Accept untagged packets */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_ROMPE
value|0x02000000
end_define

begin_comment
comment|/* Accept overflow multicast */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_ROPE
value|0x04000000
end_define

begin_comment
comment|/* Accept overflow unicast */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_BAM
value|0x08000000
end_define

begin_comment
comment|/* Accept Broadcast packets */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_MPME
value|0x10000000
end_define

begin_comment
comment|/* Multicast promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_STRVLAN
value|0x40000000
end_define

begin_comment
comment|/* Vlan stripping enable */
end_comment

begin_define
define|#
directive|define
name|E1000_VMOLR_STRCRC
value|0x80000000
end_define

begin_comment
comment|/* CRC stripping enable */
end_comment

begin_define
define|#
directive|define
name|E1000_VLVF_ARRAY_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|E1000_VLVF_VLANID_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|E1000_VLVF_POOLSEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|E1000_VLVF_POOLSEL_MASK
value|(0xFF<< E1000_VLVF_POOLSEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VLVF_LVLAN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|E1000_VLVF_VLANID_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_VMVIR_VLANA_DEFAULT
value|0x40000000
end_define

begin_comment
comment|/* Always use default VLAN */
end_comment

begin_define
define|#
directive|define
name|E1000_VMVIR_VLANA_NEVER
value|0x80000000
end_define

begin_comment
comment|/* Never insert VLAN tag */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_INIT_TIMEOUT
value|200
end_define

begin_comment
comment|/* Number of retries to clear RSTI */
end_comment

begin_define
define|#
directive|define
name|E1000_IOVCTL
value|0x05BBC
end_define

begin_define
define|#
directive|define
name|E1000_IOVCTL_REUSE_VFQ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_RPLOLR_STRVLAN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_RPLOLR_STRCRC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_TCTL_EXT_COLD
value|0x000FFC00
end_define

begin_define
define|#
directive|define
name|E1000_TCTL_EXT_COLD_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|E1000_DTXCTL_8023LL
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_DTXCTL_VLAN_ADDED
value|0x0008
end_define

begin_define
define|#
directive|define
name|E1000_DTXCTL_OOS_ENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_DTXCTL_MDP_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_DTXCTL_SPOOF_INT
value|0x0040
end_define

begin_define
define|#
directive|define
name|ALL_QUEUES
value|0xFFFF
end_define

begin_comment
comment|/* RX packet buffer size defines */
end_comment

begin_define
define|#
directive|define
name|E1000_RXPBS_SIZE_MASK_82576
value|0x0000007F
end_define

begin_function_decl
name|void
name|e1000_vmdq_set_loopback_pf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_vmdq_set_replication_pf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|e1000_rxpbs_adjust_82580
parameter_list|(
name|u32
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _E1000_82575_H_ */
end_comment

end_unit

