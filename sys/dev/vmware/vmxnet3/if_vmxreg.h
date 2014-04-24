begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Tsubai Masanari  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: src/sys/dev/pci/if_vmxreg.h,v 1.2 2013/06/12 01:07:33 uebayasi Exp $  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_VMXREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_VMXREG_H
end_define

begin_struct
struct|struct
name|UPT1_TxStats
block|{
name|uint64_t
name|TSO_packets
decl_stmt|;
name|uint64_t
name|TSO_bytes
decl_stmt|;
name|uint64_t
name|ucast_packets
decl_stmt|;
name|uint64_t
name|ucast_bytes
decl_stmt|;
name|uint64_t
name|mcast_packets
decl_stmt|;
name|uint64_t
name|mcast_bytes
decl_stmt|;
name|uint64_t
name|bcast_packets
decl_stmt|;
name|uint64_t
name|bcast_bytes
decl_stmt|;
name|uint64_t
name|error
decl_stmt|;
name|uint64_t
name|discard
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|UPT1_RxStats
block|{
name|uint64_t
name|LRO_packets
decl_stmt|;
name|uint64_t
name|LRO_bytes
decl_stmt|;
name|uint64_t
name|ucast_packets
decl_stmt|;
name|uint64_t
name|ucast_bytes
decl_stmt|;
name|uint64_t
name|mcast_packets
decl_stmt|;
name|uint64_t
name|mcast_bytes
decl_stmt|;
name|uint64_t
name|bcast_packets
decl_stmt|;
name|uint64_t
name|bcast_bytes
decl_stmt|;
name|uint64_t
name|nobuffer
decl_stmt|;
name|uint64_t
name|error
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Interrupt moderation levels */
end_comment

begin_define
define|#
directive|define
name|UPT1_IMOD_NONE
value|0
end_define

begin_comment
comment|/* No moderation */
end_comment

begin_define
define|#
directive|define
name|UPT1_IMOD_HIGHEST
value|7
end_define

begin_comment
comment|/* Least interrupts */
end_comment

begin_define
define|#
directive|define
name|UPT1_IMOD_ADAPTIVE
value|8
end_define

begin_comment
comment|/* Adaptive interrupt moderation */
end_comment

begin_comment
comment|/* Hardware features */
end_comment

begin_define
define|#
directive|define
name|UPT1_F_CSUM
value|0x0001
end_define

begin_comment
comment|/* Rx checksum verification */
end_comment

begin_define
define|#
directive|define
name|UPT1_F_RSS
value|0x0002
end_define

begin_comment
comment|/* Receive side scaling */
end_comment

begin_define
define|#
directive|define
name|UPT1_F_VLAN
value|0x0004
end_define

begin_comment
comment|/* VLAN tag stripping */
end_comment

begin_define
define|#
directive|define
name|UPT1_F_LRO
value|0x0008
end_define

begin_comment
comment|/* Large receive offloading */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR0_IMASK
parameter_list|(
name|irq
parameter_list|)
value|(0x000 + (irq) * 8)
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR0_TXH
parameter_list|(
name|q
parameter_list|)
value|(0x600 + (q) * 8)
end_define

begin_comment
comment|/* Tx head */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR0_RXH1
parameter_list|(
name|q
parameter_list|)
value|(0x800 + (q) * 8)
end_define

begin_comment
comment|/* Ring1 Rx head */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR0_RXH2
parameter_list|(
name|q
parameter_list|)
value|(0xA00 + (q) * 8)
end_define

begin_comment
comment|/* Ring2 Rx head */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_VRRS
value|0x000
end_define

begin_comment
comment|/* VMXNET3 revision report selection */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_UVRS
value|0x008
end_define

begin_comment
comment|/* UPT version report selection */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_DSL
value|0x010
end_define

begin_comment
comment|/* Driver shared address low */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_DSH
value|0x018
end_define

begin_comment
comment|/* Driver shared address high */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_CMD
value|0x020
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_MACL
value|0x028
end_define

begin_comment
comment|/* MAC address low */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_MACH
value|0x030
end_define

begin_comment
comment|/* MAC address high */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_INTR
value|0x038
end_define

begin_comment
comment|/* Interrupt status */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BAR1_EVENT
value|0x040
end_define

begin_comment
comment|/* Event status */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_ENABLE
value|0xCAFE0000
end_define

begin_comment
comment|/* Enable VMXNET3 */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_DISABLE
value|0xCAFE0001
end_define

begin_comment
comment|/* Disable VMXNET3 */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_RESET
value|0xCAFE0002
end_define

begin_comment
comment|/* Reset device */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_SET_RXMODE
value|0xCAFE0003
end_define

begin_comment
comment|/* Set interface flags */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_SET_FILTER
value|0xCAFE0004
end_define

begin_comment
comment|/* Set address filter */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_VLAN_FILTER
value|0xCAFE0005
end_define

begin_comment
comment|/* Set VLAN filter */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_GET_STATUS
value|0xF00D0000
end_define

begin_comment
comment|/* Get queue errors */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_GET_STATS
value|0xF00D0001
end_define

begin_comment
comment|/* Get queue statistics */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_GET_LINK
value|0xF00D0002
end_define

begin_comment
comment|/* Get link status */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_GET_MACL
value|0xF00D0003
end_define

begin_comment
comment|/* Get MAC address low */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_GET_MACH
value|0xF00D0004
end_define

begin_comment
comment|/* Get MAC address high */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CMD_GET_INTRCFG
value|0xF00D0008
end_define

begin_comment
comment|/* Get interrupt config */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_DMADESC_ALIGN
value|128
end_define

begin_define
define|#
directive|define
name|VMXNET3_INIT_GEN
value|1
end_define

begin_struct
struct|struct
name|vmxnet3_txdesc
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
range|:
literal|14
decl_stmt|;
name|uint32_t
name|gen
range|:
literal|1
decl_stmt|;
comment|/* Generation */
name|uint32_t
name|pad1
range|:
literal|1
decl_stmt|;
name|uint32_t
name|dtype
range|:
literal|1
decl_stmt|;
comment|/* Descriptor type */
name|uint32_t
name|pad2
range|:
literal|1
decl_stmt|;
name|uint32_t
name|offload_pos
range|:
literal|14
decl_stmt|;
comment|/* Offloading position */
name|uint32_t
name|hlen
range|:
literal|10
decl_stmt|;
comment|/* Header len */
name|uint32_t
name|offload_mode
range|:
literal|2
decl_stmt|;
comment|/* Offloading mode */
name|uint32_t
name|eop
range|:
literal|1
decl_stmt|;
comment|/* End of packet */
name|uint32_t
name|compreq
range|:
literal|1
decl_stmt|;
comment|/* Completion request */
name|uint32_t
name|pad3
range|:
literal|1
decl_stmt|;
name|uint32_t
name|vtag_mode
range|:
literal|1
decl_stmt|;
comment|/* VLAN tag insertion mode */
name|uint32_t
name|vtag
range|:
literal|16
decl_stmt|;
comment|/* VLAN tag */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Offloading modes */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_OM_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VMXNET3_OM_CSUM
value|2
end_define

begin_define
define|#
directive|define
name|VMXNET3_OM_TSO
value|3
end_define

begin_struct
struct|struct
name|vmxnet3_txcompdesc
block|{
name|uint32_t
name|eop_idx
range|:
literal|12
decl_stmt|;
comment|/* EOP index in Tx ring */
name|uint32_t
name|pad1
range|:
literal|20
decl_stmt|;
name|uint32_t
name|pad2
range|:
literal|32
decl_stmt|;
name|uint32_t
name|pad3
range|:
literal|32
decl_stmt|;
name|uint32_t
name|rsvd
range|:
literal|24
decl_stmt|;
name|uint32_t
name|type
range|:
literal|7
decl_stmt|;
name|uint32_t
name|gen
range|:
literal|1
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_rxdesc
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
range|:
literal|14
decl_stmt|;
name|uint32_t
name|btype
range|:
literal|1
decl_stmt|;
comment|/* Buffer type */
name|uint32_t
name|dtype
range|:
literal|1
decl_stmt|;
comment|/* Descriptor type */
name|uint32_t
name|rsvd
range|:
literal|15
decl_stmt|;
name|uint32_t
name|gen
range|:
literal|1
decl_stmt|;
name|uint32_t
name|pad1
range|:
literal|32
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Buffer types */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BTYPE_HEAD
value|0
end_define

begin_comment
comment|/* Head only */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_BTYPE_BODY
value|1
end_define

begin_comment
comment|/* Body only */
end_comment

begin_struct
struct|struct
name|vmxnet3_rxcompdesc
block|{
name|uint32_t
name|rxd_idx
range|:
literal|12
decl_stmt|;
comment|/* Rx descriptor index */
name|uint32_t
name|pad1
range|:
literal|2
decl_stmt|;
name|uint32_t
name|eop
range|:
literal|1
decl_stmt|;
comment|/* End of packet */
name|uint32_t
name|sop
range|:
literal|1
decl_stmt|;
comment|/* Start of packet */
name|uint32_t
name|qid
range|:
literal|10
decl_stmt|;
name|uint32_t
name|rss_type
range|:
literal|4
decl_stmt|;
name|uint32_t
name|no_csum
range|:
literal|1
decl_stmt|;
comment|/* No checksum calculated */
name|uint32_t
name|pad2
range|:
literal|1
decl_stmt|;
name|uint32_t
name|rss_hash
range|:
literal|32
decl_stmt|;
comment|/* RSS hash value */
name|uint32_t
name|len
range|:
literal|14
decl_stmt|;
name|uint32_t
name|error
range|:
literal|1
decl_stmt|;
name|uint32_t
name|vlan
range|:
literal|1
decl_stmt|;
comment|/* 802.1Q VLAN frame */
name|uint32_t
name|vtag
range|:
literal|16
decl_stmt|;
comment|/* VLAN tag */
name|uint32_t
name|csum
range|:
literal|16
decl_stmt|;
name|uint32_t
name|csum_ok
range|:
literal|1
decl_stmt|;
comment|/* TCP/UDP checksum ok */
name|uint32_t
name|udp
range|:
literal|1
decl_stmt|;
name|uint32_t
name|tcp
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ipcsum_ok
range|:
literal|1
decl_stmt|;
comment|/* IP checksum OK */
name|uint32_t
name|ipv6
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ipv4
range|:
literal|1
decl_stmt|;
name|uint32_t
name|fragment
range|:
literal|1
decl_stmt|;
comment|/* IP fragment */
name|uint32_t
name|fcs
range|:
literal|1
decl_stmt|;
comment|/* Frame CRC correct */
name|uint32_t
name|type
range|:
literal|7
decl_stmt|;
name|uint32_t
name|gen
range|:
literal|1
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMXNET3_RCD_RSS_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VMXNET3_RCD_RSS_TYPE_IPV4
value|1
end_define

begin_define
define|#
directive|define
name|VMXNET3_RCD_RSS_TYPE_TCPIPV4
value|2
end_define

begin_define
define|#
directive|define
name|VMXNET3_RCD_RSS_TYPE_IPV6
value|3
end_define

begin_define
define|#
directive|define
name|VMXNET3_RCD_RSS_TYPE_TCPIPV6
value|4
end_define

begin_define
define|#
directive|define
name|VMXNET3_REV1_MAGIC
value|0XBABEFEE1
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_LINUX
value|0x04
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_WINDOWS
value|0x08
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_SOLARIS
value|0x0C
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_FREEBSD
value|0x10
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_PXE
value|0x14
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_32BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|VMXNET3_GOS_64BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_TX_QUEUES
value|8
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_RX_QUEUES
value|16
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_INTRS
define|\
value|(VMXNET3_MAX_TX_QUEUES + VMXNET3_MAX_RX_QUEUES + 1)
end_define

begin_define
define|#
directive|define
name|VMXNET3_ICTRL_DISABLE_ALL
value|0x01
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXMODE_UCAST
value|0x01
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXMODE_MCAST
value|0x02
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXMODE_BCAST
value|0x04
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXMODE_ALLMULTI
value|0x08
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXMODE_PROMISC
value|0x10
end_define

begin_define
define|#
directive|define
name|VMXNET3_EVENT_RQERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|VMXNET3_EVENT_TQERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|VMXNET3_EVENT_LINK
value|0x04
end_define

begin_define
define|#
directive|define
name|VMXNET3_EVENT_DIC
value|0x08
end_define

begin_define
define|#
directive|define
name|VMXNET3_EVENT_DEBUG
value|0x10
end_define

begin_define
define|#
directive|define
name|VMXNET3_MIN_MTU
value|60
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_MTU
value|9000
end_define

begin_comment
comment|/* Interrupt mask mode. */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_IMM_AUTO
value|0x00
end_define

begin_define
define|#
directive|define
name|VMXNET3_IMM_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|VMXNET3_IMM_LAZY
value|0x02
end_define

begin_comment
comment|/* Interrupt type. */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_IT_AUTO
value|0x00
end_define

begin_define
define|#
directive|define
name|VMXNET3_IT_LEGACY
value|0x01
end_define

begin_define
define|#
directive|define
name|VMXNET3_IT_MSI
value|0x02
end_define

begin_define
define|#
directive|define
name|VMXNET3_IT_MSIX
value|0x03
end_define

begin_struct
struct|struct
name|vmxnet3_driver_shared
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|pad1
decl_stmt|;
comment|/* Misc. control */
name|uint32_t
name|version
decl_stmt|;
comment|/* Driver version */
name|uint32_t
name|guest
decl_stmt|;
comment|/* Guest OS */
name|uint32_t
name|vmxnet3_revision
decl_stmt|;
comment|/* Supported VMXNET3 revision */
name|uint32_t
name|upt_version
decl_stmt|;
comment|/* Supported UPT version */
name|uint64_t
name|upt_features
decl_stmt|;
name|uint64_t
name|driver_data
decl_stmt|;
name|uint64_t
name|queue_shared
decl_stmt|;
name|uint32_t
name|driver_data_len
decl_stmt|;
name|uint32_t
name|queue_shared_len
decl_stmt|;
name|uint32_t
name|mtu
decl_stmt|;
name|uint16_t
name|nrxsg_max
decl_stmt|;
name|uint8_t
name|ntxqueue
decl_stmt|;
name|uint8_t
name|nrxqueue
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
comment|/* Interrupt control */
name|uint8_t
name|automask
decl_stmt|;
name|uint8_t
name|nintr
decl_stmt|;
name|uint8_t
name|evintr
decl_stmt|;
name|uint8_t
name|modlevel
index|[
name|VMXNET3_MAX_INTRS
index|]
decl_stmt|;
name|uint32_t
name|ictrl
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* Receive filter parameters */
name|uint32_t
name|rxmode
decl_stmt|;
name|uint16_t
name|mcast_tablelen
decl_stmt|;
name|uint16_t
name|pad2
decl_stmt|;
name|uint64_t
name|mcast_table
decl_stmt|;
name|uint32_t
name|vlan_filter
index|[
literal|4096
operator|/
literal|32
index|]
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint64_t
name|paddr
decl_stmt|;
block|}
name|rss
struct|,
name|pm
struct|,
name|plugin
struct|;
name|uint32_t
name|event
decl_stmt|;
name|uint32_t
name|reserved3
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_txq_shared
block|{
comment|/* Control */
name|uint32_t
name|npending
decl_stmt|;
name|uint32_t
name|intr_threshold
decl_stmt|;
name|uint64_t
name|reserved1
decl_stmt|;
comment|/* Config */
name|uint64_t
name|cmd_ring
decl_stmt|;
name|uint64_t
name|data_ring
decl_stmt|;
name|uint64_t
name|comp_ring
decl_stmt|;
name|uint64_t
name|driver_data
decl_stmt|;
name|uint64_t
name|reserved2
decl_stmt|;
name|uint32_t
name|cmd_ring_len
decl_stmt|;
name|uint32_t
name|data_ring_len
decl_stmt|;
name|uint32_t
name|comp_ring_len
decl_stmt|;
name|uint32_t
name|driver_data_len
decl_stmt|;
name|uint8_t
name|intr_idx
decl_stmt|;
name|uint8_t
name|pad1
index|[
literal|7
index|]
decl_stmt|;
comment|/* Queue status */
name|uint8_t
name|stopped
decl_stmt|;
name|uint8_t
name|pad2
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|error
decl_stmt|;
name|struct
name|UPT1_TxStats
name|stats
decl_stmt|;
name|uint8_t
name|pad3
index|[
literal|88
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_rxq_shared
block|{
name|uint8_t
name|update_rxhead
decl_stmt|;
name|uint8_t
name|pad1
index|[
literal|7
index|]
decl_stmt|;
name|uint64_t
name|reserved1
decl_stmt|;
name|uint64_t
name|cmd_ring
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|comp_ring
decl_stmt|;
name|uint64_t
name|driver_data
decl_stmt|;
name|uint64_t
name|reserved2
decl_stmt|;
name|uint32_t
name|cmd_ring_len
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|comp_ring_len
decl_stmt|;
name|uint32_t
name|driver_data_len
decl_stmt|;
name|uint8_t
name|intr_idx
decl_stmt|;
name|uint8_t
name|pad2
index|[
literal|7
index|]
decl_stmt|;
name|uint8_t
name|stopped
decl_stmt|;
name|uint8_t
name|pad3
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|error
decl_stmt|;
name|struct
name|UPT1_RxStats
name|stats
decl_stmt|;
name|uint8_t
name|pad4
index|[
literal|88
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_TYPE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_TYPE_IPV4
value|0x01
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_TYPE_TCP_IPV4
value|0x02
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_TYPE_IPV6
value|0x04
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_TYPE_TCP_IPV6
value|0x08
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_FUNC_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_HASH_FUNC_TOEPLITZ
value|0x01
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_MAX_KEY_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|UPT1_RSS_MAX_IND_TABLE_SIZE
value|128
end_define

begin_struct
struct|struct
name|vmxnet3_rss_shared
block|{
name|uint16_t
name|hash_type
decl_stmt|;
name|uint16_t
name|hash_func
decl_stmt|;
name|uint16_t
name|hash_key_size
decl_stmt|;
name|uint16_t
name|ind_table_size
decl_stmt|;
name|uint8_t
name|hash_key
index|[
name|UPT1_RSS_MAX_KEY_SIZE
index|]
decl_stmt|;
name|uint8_t
name|ind_table
index|[
name|UPT1_RSS_MAX_IND_TABLE_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_VMXREG_H */
end_comment

end_unit

