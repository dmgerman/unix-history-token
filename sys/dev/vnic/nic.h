begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Cavium Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NIC_H
end_ifndef

begin_define
define|#
directive|define
name|NIC_H
end_define

begin_comment
comment|/* PCI vendor ID */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_CAVIUM
value|0x177D
end_define

begin_comment
comment|/* PCI device IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_THUNDER_NIC_PF
value|0xA01E
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_THUNDER_PASS1_NIC_VF
value|0x0011
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_THUNDER_NIC_VF
value|0xA034
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_THUNDER_BGX
value|0xA026
end_define

begin_comment
comment|/* PCI BAR nos */
end_comment

begin_define
define|#
directive|define
name|PCI_CFG_REG_BAR_NUM
value|0
end_define

begin_define
define|#
directive|define
name|PCI_MSIX_REG_BAR_NUM
value|4
end_define

begin_comment
comment|/* PCI revision IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_REVID_PASS2
value|8
end_define

begin_comment
comment|/* NIC SRIOV VF count */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_VFS_SUPPORTED
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_NUM_VF_ENABLED
value|8
end_define

begin_define
define|#
directive|define
name|NIC_TNS_BYPASS_MODE
value|0
end_define

begin_define
define|#
directive|define
name|NIC_TNS_MODE
value|1
end_define

begin_comment
comment|/* NIC priv flags */
end_comment

begin_define
define|#
directive|define
name|NIC_SRIOV_ENABLED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NIC_TNS_ENABLED
value|(1<< 1)
end_define

begin_comment
comment|/* ARM64TODO */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* VNIC HW optimiation features */
end_comment

begin_define
define|#
directive|define
name|VNIC_RSS_SUPPORT
end_define

begin_define
define|#
directive|define
name|VNIC_MULTI_QSET_SUPPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Min/Max packet size */
end_comment

begin_define
define|#
directive|define
name|NIC_HW_MIN_FRS
value|64
end_define

begin_define
define|#
directive|define
name|NIC_HW_MAX_FRS
value|9200
end_define

begin_comment
comment|/* 9216 max packet including FCS */
end_comment

begin_comment
comment|/* Max pkinds */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_PKIND
value|16
end_define

begin_comment
comment|/*  * Rx Channels */
end_comment

begin_comment
comment|/* Receive channel configuration in TNS bypass mode  * Below is configuration in TNS bypass mode  * BGX0-LMAC0-CHAN0 - VNIC CHAN0  * BGX0-LMAC1-CHAN0 - VNIC CHAN16  * ...  * BGX1-LMAC0-CHAN0 - VNIC CHAN128  * ...  * BGX1-LMAC3-CHAN0 - VNIC CHAN174  */
end_comment

begin_define
define|#
directive|define
name|NIC_INTF_COUNT
value|2
end_define

begin_comment
comment|/* Interfaces btw VNIC and TNS/BGX */
end_comment

begin_define
define|#
directive|define
name|NIC_CHANS_PER_INF
value|128
end_define

begin_define
define|#
directive|define
name|NIC_MAX_CHANS
value|(NIC_INTF_COUNT * NIC_CHANS_PER_INF)
end_define

begin_define
define|#
directive|define
name|NIC_CPI_COUNT
value|2048
end_define

begin_comment
comment|/* No of channel parse indices */
end_comment

begin_comment
comment|/* TNS bypass mode: 1-1 mapping between VNIC and BGX:LMAC */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_BGX
value|MAX_BGX_PER_CN88XX
end_define

begin_define
define|#
directive|define
name|NIC_CPI_PER_BGX
value|(NIC_CPI_COUNT / NIC_MAX_BGX)
end_define

begin_define
define|#
directive|define
name|NIC_MAX_CPI_PER_LMAC
value|64
end_define

begin_comment
comment|/* Max when CPI_ALG is IP diffserv */
end_comment

begin_define
define|#
directive|define
name|NIC_RSSI_PER_BGX
value|(NIC_RSSI_COUNT / NIC_MAX_BGX)
end_define

begin_comment
comment|/* Tx scheduling */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_TL4
value|1024
end_define

begin_define
define|#
directive|define
name|NIC_MAX_TL4_SHAPERS
value|256
end_define

begin_comment
comment|/* 1 shaper for 4 TL4s */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_TL3
value|256
end_define

begin_define
define|#
directive|define
name|NIC_MAX_TL3_SHAPERS
value|64
end_define

begin_comment
comment|/* 1 shaper for 4 TL3s */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_TL2
value|64
end_define

begin_define
define|#
directive|define
name|NIC_MAX_TL2_SHAPERS
value|2
end_define

begin_comment
comment|/* 1 shaper for 32 TL2s */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_TL1
value|2
end_define

begin_comment
comment|/* TNS bypass mode */
end_comment

begin_define
define|#
directive|define
name|NIC_TL2_PER_BGX
value|32
end_define

begin_define
define|#
directive|define
name|NIC_TL4_PER_BGX
value|(NIC_MAX_TL4 / NIC_MAX_BGX)
end_define

begin_define
define|#
directive|define
name|NIC_TL4_PER_LMAC
value|(NIC_MAX_TL4 / NIC_CHANS_PER_INF)
end_define

begin_comment
comment|/* NIC VF Interrupts */
end_comment

begin_define
define|#
directive|define
name|NICVF_INTR_CQ
value|0
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_SQ
value|1
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_RBDR
value|2
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_PKT_DROP
value|3
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_TCP_TIMER
value|4
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_MBOX
value|5
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_QS_ERR
value|6
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_CQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_SQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_RBDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_PKT_DROP_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_TCP_TIMER_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_MBOX_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_QS_ERR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_CQ_MASK
value|(0xFF<< NICVF_INTR_CQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_SQ_MASK
value|(0xFF<< NICVF_INTR_SQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_RBDR_MASK
value|(0x03<< NICVF_INTR_RBDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_PKT_DROP_MASK
value|(1<< NICVF_INTR_PKT_DROP_SHIFT)
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_TCP_TIMER_MASK
value|(1<< NICVF_INTR_TCP_TIMER_SHIFT)
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_MBOX_MASK
value|(1<< NICVF_INTR_MBOX_SHIFT)
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_QS_ERR_MASK
value|(1<< NICVF_INTR_QS_ERR_SHIFT)
end_define

begin_comment
comment|/* MSI-X interrupts */
end_comment

begin_define
define|#
directive|define
name|NIC_PF_MSIX_VECTORS
value|10
end_define

begin_define
define|#
directive|define
name|NIC_VF_MSIX_VECTORS
value|20
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC0_SBE
value|0
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC0_DBE
value|1
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC1_SBE
value|2
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC1_DBE
value|3
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC2_SBE
value|4
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC2_DBE
value|5
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC3_SBE
value|6
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_ECC3_DBE
value|7
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_MBOX0
value|8
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_ID_MBOX1
value|9
end_define

begin_struct
struct|struct
name|msix_entry
block|{
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Global timer for CQ timer thresh interrupts  * Calculated for SCLK of 700Mhz  * value written should be a 1/16th of what is expected  *  * 1 tick per 0.05usec = value of 2.2  * This 10% would be covered in CQ timer thresh value  */
end_comment

begin_define
define|#
directive|define
name|NICPF_CLK_PER_INT_TICK
value|2
end_define

begin_comment
comment|/*  * Time to wait before we decide that a SQ is stuck.  *  * Since both pkt rx and tx notifications are done with same CQ,  * when packets are being received at very high rate (eg: L2 forwarding)  * then freeing transmitted skbs will be delayed and watchdog  * will kick in, resetting interface. Hence keeping this value high.  */
end_comment

begin_define
define|#
directive|define
name|NICVF_TX_TIMEOUT
value|(50 * HZ)
end_define

begin_define
define|#
directive|define
name|NIC_RSSI_COUNT
value|4096
end_define

begin_comment
comment|/* Total no of RSS indices */
end_comment

begin_define
define|#
directive|define
name|NIC_MAX_RSS_HASH_BITS
value|8
end_define

begin_define
define|#
directive|define
name|NIC_MAX_RSS_IDR_TBL_SIZE
value|(1<< NIC_MAX_RSS_HASH_BITS)
end_define

begin_define
define|#
directive|define
name|RSS_HASH_KEY_SIZE
value|5
end_define

begin_comment
comment|/* 320 bit key */
end_comment

begin_enum
enum|enum
name|rx_stats_reg_offset
block|{
name|RX_OCTS
init|=
literal|0x0
block|,
name|RX_UCAST
init|=
literal|0x1
block|,
name|RX_BCAST
init|=
literal|0x2
block|,
name|RX_MCAST
init|=
literal|0x3
block|,
name|RX_RED
init|=
literal|0x4
block|,
name|RX_RED_OCTS
init|=
literal|0x5
block|,
name|RX_ORUN
init|=
literal|0x6
block|,
name|RX_ORUN_OCTS
init|=
literal|0x7
block|,
name|RX_FCS
init|=
literal|0x8
block|,
name|RX_L2ERR
init|=
literal|0x9
block|,
name|RX_DRP_BCAST
init|=
literal|0xa
block|,
name|RX_DRP_MCAST
init|=
literal|0xb
block|,
name|RX_DRP_L3BCAST
init|=
literal|0xc
block|,
name|RX_DRP_L3MCAST
init|=
literal|0xd
block|,
name|RX_STATS_ENUM_LAST
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|tx_stats_reg_offset
block|{
name|TX_OCTS
init|=
literal|0x0
block|,
name|TX_UCAST
init|=
literal|0x1
block|,
name|TX_BCAST
init|=
literal|0x2
block|,
name|TX_MCAST
init|=
literal|0x3
block|,
name|TX_DROP
init|=
literal|0x4
block|,
name|TX_STATS_ENUM_LAST
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|nicvf_hw_stats
block|{
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint64_t
name|rx_ucast_frames
decl_stmt|;
name|uint64_t
name|rx_bcast_frames
decl_stmt|;
name|uint64_t
name|rx_mcast_frames
decl_stmt|;
name|uint64_t
name|rx_fcs_errors
decl_stmt|;
name|uint64_t
name|rx_l2_errors
decl_stmt|;
name|uint64_t
name|rx_drop_red
decl_stmt|;
name|uint64_t
name|rx_drop_red_bytes
decl_stmt|;
name|uint64_t
name|rx_drop_overrun
decl_stmt|;
name|uint64_t
name|rx_drop_overrun_bytes
decl_stmt|;
name|uint64_t
name|rx_drop_bcast
decl_stmt|;
name|uint64_t
name|rx_drop_mcast
decl_stmt|;
name|uint64_t
name|rx_drop_l3_bcast
decl_stmt|;
name|uint64_t
name|rx_drop_l3_mcast
decl_stmt|;
name|uint64_t
name|rx_bgx_truncated_pkts
decl_stmt|;
name|uint64_t
name|rx_jabber_errs
decl_stmt|;
name|uint64_t
name|rx_fcs_errs
decl_stmt|;
name|uint64_t
name|rx_bgx_errs
decl_stmt|;
name|uint64_t
name|rx_prel2_errs
decl_stmt|;
name|uint64_t
name|rx_l2_hdr_malformed
decl_stmt|;
name|uint64_t
name|rx_oversize
decl_stmt|;
name|uint64_t
name|rx_undersize
decl_stmt|;
name|uint64_t
name|rx_l2_len_mismatch
decl_stmt|;
name|uint64_t
name|rx_l2_pclp
decl_stmt|;
name|uint64_t
name|rx_ip_ver_errs
decl_stmt|;
name|uint64_t
name|rx_ip_csum_errs
decl_stmt|;
name|uint64_t
name|rx_ip_hdr_malformed
decl_stmt|;
name|uint64_t
name|rx_ip_payload_malformed
decl_stmt|;
name|uint64_t
name|rx_ip_ttl_errs
decl_stmt|;
name|uint64_t
name|rx_l3_pclp
decl_stmt|;
name|uint64_t
name|rx_l4_malformed
decl_stmt|;
name|uint64_t
name|rx_l4_csum_errs
decl_stmt|;
name|uint64_t
name|rx_udp_len_errs
decl_stmt|;
name|uint64_t
name|rx_l4_port_errs
decl_stmt|;
name|uint64_t
name|rx_tcp_flag_errs
decl_stmt|;
name|uint64_t
name|rx_tcp_offset_errs
decl_stmt|;
name|uint64_t
name|rx_l4_pclp
decl_stmt|;
name|uint64_t
name|rx_truncated_pkts
decl_stmt|;
name|uint64_t
name|tx_bytes_ok
decl_stmt|;
name|uint64_t
name|tx_ucast_frames_ok
decl_stmt|;
name|uint64_t
name|tx_bcast_frames_ok
decl_stmt|;
name|uint64_t
name|tx_mcast_frames_ok
decl_stmt|;
name|uint64_t
name|tx_drops
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nicvf_drv_stats
block|{
comment|/* Rx */
name|uint64_t
name|rx_frames_ok
decl_stmt|;
name|uint64_t
name|rx_frames_64
decl_stmt|;
name|uint64_t
name|rx_frames_127
decl_stmt|;
name|uint64_t
name|rx_frames_255
decl_stmt|;
name|uint64_t
name|rx_frames_511
decl_stmt|;
name|uint64_t
name|rx_frames_1023
decl_stmt|;
name|uint64_t
name|rx_frames_1518
decl_stmt|;
name|uint64_t
name|rx_frames_jumbo
decl_stmt|;
name|uint64_t
name|rx_drops
decl_stmt|;
comment|/* Tx */
name|uint64_t
name|tx_frames_ok
decl_stmt|;
name|uint64_t
name|tx_drops
decl_stmt|;
name|uint64_t
name|tx_tso
decl_stmt|;
name|uint64_t
name|txq_stop
decl_stmt|;
name|uint64_t
name|txq_wake
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nicvf
block|{
name|struct
name|nicvf
modifier|*
name|pnicvf
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|sx
name|core_sx
decl_stmt|;
name|struct
name|ifmedia
name|if_media
decl_stmt|;
name|uint32_t
name|if_flags
decl_stmt|;
name|uint8_t
name|hwaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint8_t
name|node
decl_stmt|;
name|boolean_t
name|tns_mode
range|:
literal|1
decl_stmt|;
name|boolean_t
name|sqs_mode
range|:
literal|1
decl_stmt|;
name|bool
name|loopback_supported
range|:
literal|1
decl_stmt|;
name|uint16_t
name|mtu
decl_stmt|;
name|struct
name|queue_set
modifier|*
name|qs
decl_stmt|;
name|uint8_t
name|rx_queues
decl_stmt|;
name|uint8_t
name|tx_queues
decl_stmt|;
name|uint8_t
name|max_queues
decl_stmt|;
name|struct
name|resource
modifier|*
name|reg_base
decl_stmt|;
name|boolean_t
name|link_up
decl_stmt|;
name|uint8_t
name|duplex
decl_stmt|;
name|uint32_t
name|speed
decl_stmt|;
name|uint8_t
name|cpi_alg
decl_stmt|;
comment|/* Interrupt coalescing settings */
name|uint32_t
name|cq_coalesce_usecs
decl_stmt|;
name|uint32_t
name|msg_enable
decl_stmt|;
name|struct
name|nicvf_hw_stats
name|hw_stats
decl_stmt|;
name|struct
name|nicvf_drv_stats
name|drv_stats
decl_stmt|;
name|struct
name|bgx_stats
name|bgx_stats
decl_stmt|;
comment|/* Interface statistics */
name|struct
name|callout
name|stats_callout
decl_stmt|;
name|struct
name|mtx
name|stats_mtx
decl_stmt|;
comment|/* MSI-X  */
name|boolean_t
name|msix_enabled
decl_stmt|;
name|uint8_t
name|num_vec
decl_stmt|;
name|struct
name|msix_entry
name|msix_entries
index|[
name|NIC_VF_MSIX_VECTORS
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_table_res
decl_stmt|;
name|char
name|irq_name
index|[
name|NIC_VF_MSIX_VECTORS
index|]
index|[
literal|20
index|]
decl_stmt|;
name|boolean_t
name|irq_allocated
index|[
name|NIC_VF_MSIX_VECTORS
index|]
decl_stmt|;
comment|/* VF<-> PF mailbox communication */
name|boolean_t
name|pf_acked
decl_stmt|;
name|boolean_t
name|pf_nacked
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * PF<--> VF Mailbox communication  * Eight 64bit registers are shared between PF and VF.  * Separate set for each VF.  * Writing '1' into last register mbx7 means end of message.  */
end_comment

begin_comment
comment|/* PF<--> VF mailbox communication */
end_comment

begin_define
define|#
directive|define
name|NIC_PF_VF_MAILBOX_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_TIMEOUT
value|2000
end_define

begin_comment
comment|/* ms */
end_comment

begin_comment
comment|/* Mailbox message types */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_READY
value|0x01
end_define

begin_comment
comment|/* Is PF ready to rcv msgs */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_ACK
value|0x02
end_define

begin_comment
comment|/* ACK the message received */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_NACK
value|0x03
end_define

begin_comment
comment|/* NACK the message received */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_QS_CFG
value|0x04
end_define

begin_comment
comment|/* Configure Qset */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RQ_CFG
value|0x05
end_define

begin_comment
comment|/* Configure receive queue */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_SQ_CFG
value|0x06
end_define

begin_comment
comment|/* Configure Send queue */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RQ_DROP_CFG
value|0x07
end_define

begin_comment
comment|/* Configure receive queue */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_SET_MAC
value|0x08
end_define

begin_comment
comment|/* Add MAC ID to DMAC filter */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_SET_MAX_FRS
value|0x09
end_define

begin_comment
comment|/* Set max frame size */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_CPI_CFG
value|0x0A
end_define

begin_comment
comment|/* Config CPI, RSSI */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RSS_SIZE
value|0x0B
end_define

begin_comment
comment|/* Get RSS indir_tbl size */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RSS_CFG
value|0x0C
end_define

begin_comment
comment|/* Config RSS table */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RSS_CFG_CONT
value|0x0D
end_define

begin_comment
comment|/* RSS config continuation */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RQ_BP_CFG
value|0x0E
end_define

begin_comment
comment|/* RQ backpressure config */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_RQ_SW_SYNC
value|0x0F
end_define

begin_comment
comment|/* Flush inflight pkts to RQ */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_BGX_STATS
value|0x10
end_define

begin_comment
comment|/* Get stats from BGX */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_BGX_LINK_CHANGE
value|0x11
end_define

begin_comment
comment|/* BGX:LMAC link status */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_ALLOC_SQS
value|0x12
end_define

begin_comment
comment|/* Allocate secondary Qset */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_NICVF_PTR
value|0x13
end_define

begin_comment
comment|/* Send nicvf ptr to PF */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_PNICVF_PTR
value|0x14
end_define

begin_comment
comment|/* Get primary qset nicvf ptr */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_SNICVF_PTR
value|0x15
end_define

begin_comment
comment|/* Send sqet nicvf ptr to PVF */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_LOOPBACK
value|0x16
end_define

begin_comment
comment|/* Set interface in loopback */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_CFG_DONE
value|0xF0
end_define

begin_comment
comment|/* VF configuration done */
end_comment

begin_define
define|#
directive|define
name|NIC_MBOX_MSG_SHUTDOWN
value|0xF1
end_define

begin_comment
comment|/* VF is being shutdown */
end_comment

begin_struct
struct|struct
name|nic_cfg_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint8_t
name|node_id
decl_stmt|;
name|boolean_t
name|tns_mode
range|:
literal|1
decl_stmt|;
name|boolean_t
name|sqs_mode
range|:
literal|1
decl_stmt|;
name|boolean_t
name|loopback_supported
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Qset configuration */
end_comment

begin_struct
struct|struct
name|qs_cfg_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|num
decl_stmt|;
name|uint8_t
name|sqs_count
decl_stmt|;
name|uint64_t
name|cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Receive queue configuration */
end_comment

begin_struct
struct|struct
name|rq_cfg_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|qs_num
decl_stmt|;
name|uint8_t
name|rq_num
decl_stmt|;
name|uint64_t
name|cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Send queue configuration */
end_comment

begin_struct
struct|struct
name|sq_cfg_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|qs_num
decl_stmt|;
name|uint8_t
name|sq_num
decl_stmt|;
name|boolean_t
name|sqs_mode
decl_stmt|;
name|uint64_t
name|cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set VF's MAC address */
end_comment

begin_struct
struct|struct
name|set_mac_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set Maximum frame size */
end_comment

begin_struct
struct|struct
name|set_frs_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint16_t
name|max_frs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set CPI algorithm type */
end_comment

begin_struct
struct|struct
name|cpi_cfg_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint8_t
name|rq_cnt
decl_stmt|;
name|uint8_t
name|cpi_alg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Get RSS table size */
end_comment

begin_struct
struct|struct
name|rss_sz_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint16_t
name|ind_tbl_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set RSS configuration */
end_comment

begin_struct
struct|struct
name|rss_cfg_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint8_t
name|hash_bits
decl_stmt|;
name|uint8_t
name|tbl_len
decl_stmt|;
name|uint8_t
name|tbl_offset
decl_stmt|;
define|#
directive|define
name|RSS_IND_TBL_LEN_PER_MBX_MSG
value|8
name|uint8_t
name|ind_tbl
index|[
name|RSS_IND_TBL_LEN_PER_MBX_MSG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bgx_stats_msg
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|uint8_t
name|rx
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint64_t
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Physical interface link status */
end_comment

begin_struct
struct|struct
name|bgx_link_status
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|link_up
decl_stmt|;
name|uint8_t
name|duplex
decl_stmt|;
name|uint32_t
name|speed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set interface in loopback mode */
end_comment

begin_struct
struct|struct
name|set_loopback
block|{
name|uint8_t
name|msg
decl_stmt|;
name|uint8_t
name|vf_id
decl_stmt|;
name|boolean_t
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* 128 bit shared memory between PF and each VF */
end_comment

begin_union
union|union
name|nic_mbx
block|{
struct|struct
block|{
name|uint8_t
name|msg
decl_stmt|;
block|}
name|msg
struct|;
name|struct
name|nic_cfg_msg
name|nic_cfg
decl_stmt|;
name|struct
name|qs_cfg_msg
name|qs
decl_stmt|;
name|struct
name|rq_cfg_msg
name|rq
decl_stmt|;
name|struct
name|sq_cfg_msg
name|sq
decl_stmt|;
name|struct
name|set_mac_msg
name|mac
decl_stmt|;
name|struct
name|set_frs_msg
name|frs
decl_stmt|;
name|struct
name|cpi_cfg_msg
name|cpi_cfg
decl_stmt|;
name|struct
name|rss_sz_msg
name|rss_size
decl_stmt|;
name|struct
name|rss_cfg_msg
name|rss_cfg
decl_stmt|;
name|struct
name|bgx_stats_msg
name|bgx_stats
decl_stmt|;
name|struct
name|bgx_link_status
name|link_status
decl_stmt|;
name|struct
name|set_loopback
name|lbk
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|NIC_NODE_ID_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|NIC_NODE_ID_SHIFT
value|44
end_define

begin_function
specifier|static
name|__inline
name|int
name|nic_get_node_id
parameter_list|(
name|struct
name|resource
modifier|*
name|res
parameter_list|)
block|{
name|pci_addr_t
name|addr
decl_stmt|;
name|addr
operator|=
name|rman_get_start
argument_list|(
name|res
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|addr
operator|>>
name|NIC_NODE_ID_SHIFT
operator|)
operator|&
name|NIC_NODE_ID_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|boolean_t
name|pass1_silicon
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
comment|/* Check if the chip revision is< Pass2 */
return|return
operator|(
name|pci_get_revid
argument_list|(
name|dev
argument_list|)
operator|<
name|PCI_REVID_PASS2
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|nicvf_send_msg_to_pf
parameter_list|(
name|struct
name|nicvf
modifier|*
name|vf
parameter_list|,
name|union
name|nic_mbx
modifier|*
name|mbx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NIC_H */
end_comment

end_unit

