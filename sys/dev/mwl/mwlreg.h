begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2007-2009 Marvell Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the Marvell Wireless LAN controller Hardware Access Layer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MWL_HALREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MWL_HALREG_H_
end_define

begin_define
define|#
directive|define
name|MWL_ANT_INFO_SUPPORT
end_define

begin_comment
comment|/* per-antenna data in rx descriptor */
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_TSF_LOW
value|0xa600
end_define

begin_comment
comment|/* TSF lo */
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_TSF_HIGH
value|0xa604
end_define

begin_comment
comment|/* TSF hi */
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_CHIP_REV
value|0xa814
end_define

begin_comment
comment|/* chip rev */
end_comment

begin_comment
comment|//          Map to 0x80000000 (Bus control) on BAR0
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_H2A_INTERRUPT_EVENTS
value|0x00000C18
end_define

begin_comment
comment|// (From host to ARM)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_H2A_INTERRUPT_CAUSE
value|0x00000C1C
end_define

begin_comment
comment|// (From host to ARM)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_H2A_INTERRUPT_MASK
value|0x00000C20
end_define

begin_comment
comment|// (From host to ARM)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_H2A_INTERRUPT_CLEAR_SEL
value|0x00000C24
end_define

begin_comment
comment|// (From host to ARM)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_H2A_INTERRUPT_STATUS_MASK
value|0x00000C28
end_define

begin_comment
comment|// (From host to ARM)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_A2H_INTERRUPT_EVENTS
value|0x00000C2C
end_define

begin_comment
comment|// (From ARM to host)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_A2H_INTERRUPT_CAUSE
value|0x00000C30
end_define

begin_comment
comment|// (From ARM to host)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_A2H_INTERRUPT_MASK
value|0x00000C34
end_define

begin_comment
comment|// (From ARM to host)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_A2H_INTERRUPT_CLEAR_SEL
value|0x00000C38
end_define

begin_comment
comment|// (From ARM to host)
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_A2H_INTERRUPT_STATUS_MASK
value|0x00000C3C
end_define

begin_comment
comment|// (From ARM to host)
end_comment

begin_comment
comment|//  Map to 0x80000000 on BAR1
end_comment

begin_define
define|#
directive|define
name|MACREG_REG_GEN_PTR
value|0x00000C10
end_define

begin_define
define|#
directive|define
name|MACREG_REG_INT_CODE
value|0x00000C14
end_define

begin_define
define|#
directive|define
name|MACREG_REG_SCRATCH
value|0x00000C40
end_define

begin_define
define|#
directive|define
name|MACREG_REG_FW_PRESENT
value|0x0000BFFC
end_define

begin_define
define|#
directive|define
name|MACREG_REG_PROMISCUOUS
value|0xA300
end_define

begin_comment
comment|//	Bit definitio for MACREG_REG_A2H_INTERRUPT_CAUSE (A2HRIC)
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_TX_DONE
value|0x00000001
end_define

begin_comment
comment|// bit 0
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_RX_RDY
value|0x00000002
end_define

begin_comment
comment|// bit 1
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_OPC_DONE
value|0x00000004
end_define

begin_comment
comment|// bit 2
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_MAC_EVENT
value|0x00000008
end_define

begin_comment
comment|// bit 3
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_RX_PROBLEM
value|0x00000010
end_define

begin_comment
comment|// bit 4
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_RADIO_OFF
value|0x00000020
end_define

begin_comment
comment|// bit 5
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_RADIO_ON
value|0x00000040
end_define

begin_comment
comment|// bit 6
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_RADAR_DETECT
value|0x00000080
end_define

begin_comment
comment|// bit 7
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_ICV_ERROR
value|0x00000100
end_define

begin_comment
comment|// bit 8
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_MIC_ERROR
value|0x00000200
end_define

begin_comment
comment|// bit 9
end_comment

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_QUEUE_EMPTY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_QUEUE_FULL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_CHAN_SWITCH
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_TX_WATCHDOG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_BA_WATCHDOG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MACREQ_A2HRIC_BIT_TX_ACK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ISR_SRC_BITS
value|((MACREG_A2HRIC_BIT_RX_RDY)   | \                              (MACREG_A2HRIC_BIT_TX_DONE)  | \                              (MACREG_A2HRIC_BIT_OPC_DONE) | \                              (MACREG_A2HRIC_BIT_MAC_EVENT)| \                              (MACREG_A2HRIC_BIT_MIC_ERROR)| \                              (MACREG_A2HRIC_BIT_ICV_ERROR)| \                              (MACREG_A2HRIC_BIT_RADAR_DETECT)| \                              (MACREG_A2HRIC_BIT_CHAN_SWITCH)| \                              (MACREG_A2HRIC_BIT_TX_WATCHDOG)| \                              (MACREG_A2HRIC_BIT_QUEUE_EMPTY)| \                              (MACREG_A2HRIC_BIT_BA_WATCHDOG)| \ 			     (MACREQ_A2HRIC_BIT_TX_ACK))
end_define

begin_define
define|#
directive|define
name|MACREG_A2HRIC_BIT_MASK
value|ISR_SRC_BITS
end_define

begin_comment
comment|//	Bit definitio for MACREG_REG_H2A_INTERRUPT_CAUSE (H2ARIC)
end_comment

begin_define
define|#
directive|define
name|MACREG_H2ARIC_BIT_PPA_READY
value|0x00000001
end_define

begin_comment
comment|// bit 0
end_comment

begin_define
define|#
directive|define
name|MACREG_H2ARIC_BIT_DOOR_BELL
value|0x00000002
end_define

begin_comment
comment|// bit 1
end_comment

begin_define
define|#
directive|define
name|ISR_RESET
value|(1<<15)
end_define

begin_comment
comment|//	INT code register event definition
end_comment

begin_define
define|#
directive|define
name|MACREG_INT_CODE_CMD_FINISHED
value|0x00000005
end_define

begin_comment
comment|/*  * Host/Firmware Interface definitions.  */
end_comment

begin_comment
comment|/**  * Define total number of TX queues in the shared memory.  * This count includes the EDCA queues, Block Ack queues, and HCCA queues  * In addition to this, there could be a management packet queue some   * time in the future  */
end_comment

begin_define
define|#
directive|define
name|NUM_EDCA_QUEUES
value|4
end_define

begin_define
define|#
directive|define
name|NUM_HCCA_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|NUM_BA_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|NUM_MGMT_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|NUM_ACK_EVENT_QUEUE
value|1
end_define

begin_define
define|#
directive|define
name|TOTAL_TX_QUEUES
define|\
value|(NUM_EDCA_QUEUES + NUM_HCCA_QUEUES + NUM_BA_QUEUES + NUM_MGMT_QUEUES + NUM_ACK_EVENT_QUEUE)
end_define

begin_define
define|#
directive|define
name|MAX_TXWCB_QUEUES
value|TOTAL_TX_QUEUES - NUM_ACK_EVENT_QUEUE
end_define

begin_define
define|#
directive|define
name|MAX_RXWCB_QUEUES
value|1
end_define

begin_comment
comment|//=============================================================================
end_comment

begin_comment
comment|//          PUBLIC DEFINITIONS
end_comment

begin_comment
comment|//=============================================================================
end_comment

begin_define
define|#
directive|define
name|RATE_INDEX_MAX_ARRAY
value|14
end_define

begin_define
define|#
directive|define
name|WOW_MAX_STATION
value|32
end_define

begin_comment
comment|/*  * Hardware tx/rx descriptors.  *  * NB: tx descriptor size must match f/w expected size  * because f/w prefetch's the next descriptor linearly  * and doesn't chase the next pointer.  */
end_comment

begin_struct
struct|struct
name|mwl_txdesc
block|{
name|uint32_t
name|Status
decl_stmt|;
define|#
directive|define
name|EAGLE_TXD_STATUS_IDLE
value|0x00000000
define|#
directive|define
name|EAGLE_TXD_STATUS_USED
value|0x00000001
define|#
directive|define
name|EAGLE_TXD_STATUS_OK
value|0x00000001
define|#
directive|define
name|EAGLE_TXD_STATUS_OK_RETRY
value|0x00000002
define|#
directive|define
name|EAGLE_TXD_STATUS_OK_MORE_RETRY
value|0x00000004
define|#
directive|define
name|EAGLE_TXD_STATUS_MULTICAST_TX
value|0x00000008
define|#
directive|define
name|EAGLE_TXD_STATUS_BROADCAST_TX
value|0x00000010
define|#
directive|define
name|EAGLE_TXD_STATUS_FAILED_LINK_ERROR
value|0x00000020
define|#
directive|define
name|EAGLE_TXD_STATUS_FAILED_EXCEED_LIMIT
value|0x00000040
define|#
directive|define
name|EAGLE_TXD_STATUS_FAILED_XRETRY
value|EAGLE_TXD_STATUS_FAILED_EXCEED_LIMIT
define|#
directive|define
name|EAGLE_TXD_STATUS_FAILED_AGING
value|0x00000080
define|#
directive|define
name|EAGLE_TXD_STATUS_FW_OWNED
value|0x80000000
name|uint8_t
name|DataRate
decl_stmt|;
name|uint8_t
name|TxPriority
decl_stmt|;
name|uint16_t
name|QosCtrl
decl_stmt|;
name|uint32_t
name|PktPtr
decl_stmt|;
name|uint16_t
name|PktLen
decl_stmt|;
name|uint8_t
name|DestAddr
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|pPhysNext
decl_stmt|;
name|uint32_t
name|SapPktInfo
decl_stmt|;
define|#
directive|define
name|EAGLE_TXD_MODE_BONLY
value|1
define|#
directive|define
name|EAGLE_TXD_MODE_GONLY
value|2
define|#
directive|define
name|EAGLE_TXD_MODE_BG
value|3
define|#
directive|define
name|EAGLE_TXD_MODE_NONLY
value|4
define|#
directive|define
name|EAGLE_TXD_MODE_BN
value|5
define|#
directive|define
name|EAGLE_TXD_MODE_GN
value|6
define|#
directive|define
name|EAGLE_TXD_MODE_BGN
value|7
define|#
directive|define
name|EAGLE_TXD_MODE_AONLY
value|8
define|#
directive|define
name|EAGLE_TXD_MODE_AG
value|10
define|#
directive|define
name|EAGLE_TXD_MODE_AN
value|12
name|uint16_t
name|Format
decl_stmt|;
define|#
directive|define
name|EAGLE_TXD_FORMAT
value|0x0001
comment|/* frame format/rate */
define|#
directive|define
name|EAGLE_TXD_FORMAT_LEGACY
value|0x0000
comment|/* legacy rate frame */
define|#
directive|define
name|EAGLE_TXD_FORMAT_HT
value|0x0001
comment|/* HT rate frame */
define|#
directive|define
name|EAGLE_TXD_GI
value|0x0002
comment|/* guard interval */
define|#
directive|define
name|EAGLE_TXD_GI_SHORT
value|0x0002
comment|/* short guard interval */
define|#
directive|define
name|EAGLE_TXD_GI_LONG
value|0x0000
comment|/* long guard interval */
define|#
directive|define
name|EAGLE_TXD_CHW
value|0x0004
comment|/* channel width */
define|#
directive|define
name|EAGLE_TXD_CHW_20
value|0x0000
comment|/* 20MHz channel width */
define|#
directive|define
name|EAGLE_TXD_CHW_40
value|0x0004
comment|/* 40MHz channel width */
define|#
directive|define
name|EAGLE_TXD_RATE
value|0x01f8
comment|/* tx rate (legacy)/ MCS */
define|#
directive|define
name|EAGLE_TXD_RATE_S
value|3
define|#
directive|define
name|EAGLE_TXD_ADV
value|0x0600
comment|/* advanced coding */
define|#
directive|define
name|EAGLE_TXD_ADV_S
value|9
define|#
directive|define
name|EAGLE_TXD_ADV_NONE
value|0x0000
define|#
directive|define
name|EAGLE_TXD_ADV_LDPC
value|0x0200
define|#
directive|define
name|EAGLE_TXD_ADV_RS
value|0x0400
comment|/* NB: 3 is reserved */
define|#
directive|define
name|EAGLE_TXD_ANTENNA
value|0x1800
comment|/* antenna select */
define|#
directive|define
name|EAGLE_TXD_ANTENNA_S
value|11
define|#
directive|define
name|EAGLE_TXD_EXTCHAN
value|0x6000
comment|/* extension channel */
define|#
directive|define
name|EAGLE_TXD_EXTCHAN_S
value|13
define|#
directive|define
name|EAGLE_TXD_EXTCHAN_HI
value|0x0000
comment|/* above */
define|#
directive|define
name|EAGLE_TXD_EXTCHAN_LO
value|0x2000
comment|/* below */
define|#
directive|define
name|EAGLE_TXD_PREAMBLE
value|0x8000
define|#
directive|define
name|EAGLE_TXD_PREAMBLE_SHORT
value|0x8000
comment|/* short preamble */
define|#
directive|define
name|EAGLE_TXD_PREAMBLE_LONG
value|0x0000
comment|/* long preamble */
name|uint16_t
name|pad
decl_stmt|;
comment|/* align to 4-byte boundary */
define|#
directive|define
name|EAGLE_TXD_FIXED_RATE
value|0x0100
comment|/* get tx rate from Format */
define|#
directive|define
name|EAGLE_TXD_DONT_AGGR
value|0x0200
comment|/* don't aggregate frame */
name|uint32_t
name|ack_wcb_addr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mwl_ant_info
block|{
name|uint8_t
name|rssi_a
decl_stmt|;
comment|/* RSSI for antenna A */
name|uint8_t
name|rssi_b
decl_stmt|;
comment|/* RSSI for antenna B */
name|uint8_t
name|rssi_c
decl_stmt|;
comment|/* RSSI for antenna C */
name|uint8_t
name|rsvd1
decl_stmt|;
comment|/* Reserved */
name|uint8_t
name|nf_a
decl_stmt|;
comment|/* Noise floor for antenna A */
name|uint8_t
name|nf_b
decl_stmt|;
comment|/* Noise floor for antenna B */
name|uint8_t
name|nf_c
decl_stmt|;
comment|/* Noise floor for antenna C */
name|uint8_t
name|rsvd2
decl_stmt|;
comment|/* Reserved */
name|uint8_t
name|nf
decl_stmt|;
comment|/* Noise floor */
name|uint8_t
name|rsvd3
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved - To make word aligned */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mwl_rxdesc
block|{
name|uint8_t
name|RxControl
decl_stmt|;
comment|/* control element */
define|#
directive|define
name|EAGLE_RXD_CTRL_DRIVER_OWN
value|0x00
define|#
directive|define
name|EAGLE_RXD_CTRL_OS_OWN
value|0x04
define|#
directive|define
name|EAGLE_RXD_CTRL_DMA_OWN
value|0x80
name|uint8_t
name|RSSI
decl_stmt|;
comment|/* received signal strengt indication */
name|uint8_t
name|Status
decl_stmt|;
comment|/* status field w/ USED bit */
define|#
directive|define
name|EAGLE_RXD_STATUS_IDLE
value|0x00
define|#
directive|define
name|EAGLE_RXD_STATUS_OK
value|0x01
define|#
directive|define
name|EAGLE_RXD_STATUS_MULTICAST_RX
value|0x02
define|#
directive|define
name|EAGLE_RXD_STATUS_BROADCAST_RX
value|0x04
define|#
directive|define
name|EAGLE_RXD_STATUS_FRAGMENT_RX
value|0x08
define|#
directive|define
name|EAGLE_RXD_STATUS_GENERAL_DECRYPT_ERR
value|0xff
define|#
directive|define
name|EAGLE_RXD_STATUS_DECRYPT_ERR_MASK
value|0x80
define|#
directive|define
name|EAGLE_RXD_STATUS_TKIP_MIC_DECRYPT_ERR
value|0x02
define|#
directive|define
name|EAGLE_RXD_STATUS_WEP_ICV_DECRYPT_ERR
value|0x04
define|#
directive|define
name|EAGLE_RXD_STATUS_TKIP_ICV_DECRYPT_ERR
value|0x08
name|uint8_t
name|Channel
decl_stmt|;
comment|/* channel # pkt received on */
name|uint16_t
name|PktLen
decl_stmt|;
comment|/* total length of received data */
name|uint8_t
name|SQ2
decl_stmt|;
comment|/* not used */
name|uint8_t
name|Rate
decl_stmt|;
comment|/* received data rate */
name|uint32_t
name|pPhysBuffData
decl_stmt|;
comment|/* physical address of payload data */
name|uint32_t
name|pPhysNext
decl_stmt|;
comment|/* physical address of next RX desc */
name|uint16_t
name|QosCtrl
decl_stmt|;
comment|/* received QosCtrl field variable */
name|uint16_t
name|HtSig2
decl_stmt|;
comment|/* like name states */
ifdef|#
directive|ifdef
name|MWL_ANT_INFO_SUPPORT
name|struct
name|mwl_ant_info
name|ai
decl_stmt|;
comment|/* antenna info */
endif|#
directive|endif
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* //          Define OpMode for SoftAP/Station mode // //  The following mode signature has to be written to PCI scratch register#0 //  right after successfully downloading the last block of firmware and //  before waiting for firmware ready signature  */
end_comment

begin_define
define|#
directive|define
name|HostCmd_STA_MODE
value|0x5A
end_define

begin_define
define|#
directive|define
name|HostCmd_SOFTAP_MODE
value|0xA5
end_define

begin_define
define|#
directive|define
name|HostCmd_STA_FWRDY_SIGNATURE
value|0xF0F1F2F4
end_define

begin_define
define|#
directive|define
name|HostCmd_SOFTAP_FWRDY_SIGNATURE
value|0xF1F2F4A5
end_define

begin_comment
comment|//***************************************************************************
end_comment

begin_comment
comment|//***************************************************************************
end_comment

begin_comment
comment|//***************************************************************************
end_comment

begin_define
define|#
directive|define
name|HostCmd_CMD_CODE_DNLD
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_GET_HW_SPEC
value|0x0003
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_HW_SPEC
value|0x0004
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_MAC_MULTICAST_ADR
value|0x0010
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11_GET_STAT
value|0x0014
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_MAC_REG_ACCESS
value|0x0019
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_BBP_REG_ACCESS
value|0x001a
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_RF_REG_ACCESS
value|0x001b
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11_RADIO_CONTROL
value|0x001c
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11_RF_TX_POWER
value|0x001e
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11_RF_ANTENNA
value|0x0020
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_BEACON
value|0x0100
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_AID
value|0x010d
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_RF_CHANNEL
value|0x010a
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_INFRA_MODE
value|0x010e
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_G_PROTECT_FLAG
value|0x010f
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11_RTS_THSD
value|0x0113
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11_SET_SLOT
value|0x0114
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_802_11H_DETECT_RADAR
value|0x0120
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_WMM_MODE
value|0x0123
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_HT_GUARD_INTERVAL
value|0x0124
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_FIXED_RATE
value|0x0126
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_LINKADAPT_CS_MODE
value|0x0129
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_MAC_ADDR
value|0x0202
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_RATE_ADAPT_MODE
value|0x0203
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_GET_WATCHDOG_BITMAP
value|0x0205
end_define

begin_comment
comment|//SoftAP command code
end_comment

begin_define
define|#
directive|define
name|HostCmd_CMD_BSS_START
value|0x1100
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_NEW_STN
value|0x1111
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_KEEP_ALIVE
value|0x1112
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_APMODE
value|0x1114
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_SWITCH_CHANNEL
value|0x1121
end_define

begin_comment
comment|/* 	@HWENCR@ 	Command to update firmware encryption keys. */
end_comment

begin_define
define|#
directive|define
name|HostCmd_CMD_UPDATE_ENCRYPTION
value|0x1122
end_define

begin_comment
comment|/* 	@11E-BA@ 	Command to create/destroy block ACK */
end_comment

begin_define
define|#
directive|define
name|HostCmd_CMD_BASTREAM
value|0x1125
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_RIFS
value|0x1126
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_N_PROTECT_FLAG
value|0x1131
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_N_PROTECT_OPMODE
value|0x1132
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_OPTIMIZATION_LEVEL
value|0x1133
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_GET_CALTABLE
value|0x1134
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_MIMOPSHT
value|0x1135
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_GET_BEACON
value|0x1138
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_REGION_CODE
value|0x1139
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_POWERSAVESTATION
value|0x1140
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_TIM
value|0x1141
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_GET_TIM
value|0x1142
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_GET_SEQNO
value|0x1143
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_DWDS_ENABLE
value|0x1144
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_AMPDU_RETRY_RATEDROP_MODE
value|0x1145
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_CFEND_ENABLE
value|0x1146
end_define

begin_comment
comment|/* //          Define general result code for each command  */
end_comment

begin_define
define|#
directive|define
name|HostCmd_RESULT_OK
value|0x0000
end_define

begin_comment
comment|// OK
end_comment

begin_define
define|#
directive|define
name|HostCmd_RESULT_ERROR
value|0x0001
end_define

begin_comment
comment|// Genenral error
end_comment

begin_define
define|#
directive|define
name|HostCmd_RESULT_NOT_SUPPORT
value|0x0002
end_define

begin_comment
comment|// Command is not valid
end_comment

begin_define
define|#
directive|define
name|HostCmd_RESULT_PENDING
value|0x0003
end_define

begin_comment
comment|// Command is pending (will be processed)
end_comment

begin_define
define|#
directive|define
name|HostCmd_RESULT_BUSY
value|0x0004
end_define

begin_comment
comment|// System is busy (command ignored)
end_comment

begin_define
define|#
directive|define
name|HostCmd_RESULT_PARTIAL_DATA
value|0x0005
end_define

begin_comment
comment|// Data buffer is not big enough
end_comment

begin_comment
comment|/* //          Definition of action or option for each command // //          Define general purpose action  */
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_WRITE
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_GET
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_SET
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_OFF
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_ON
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_DIFF_CHANNEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GEN_SET_LIST
value|0x0002
end_define

begin_comment
comment|//          Define action or option for HostCmd_FW_USE_FIXED_RATE
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_USE_FIXED_RATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_NOT_USE_FIXED_RATE
value|0x0002
end_define

begin_comment
comment|//          Define action or option for HostCmd_CMD_802_11_SET_WEP
end_comment

begin_comment
comment|//#define HostCmd_ACT_ENABLE                    0x0001 // Use MAC control for WEP on/off
end_comment

begin_comment
comment|//#define HostCmd_ACT_DISABLE                   0x0000
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_ADD
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_REMOVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_USE_DEFAULT
value|0x0008
end_define

begin_define
define|#
directive|define
name|HostCmd_TYPE_WEP_40_BIT
value|0x0001
end_define

begin_comment
comment|// 40 bit
end_comment

begin_define
define|#
directive|define
name|HostCmd_TYPE_WEP_104_BIT
value|0x0002
end_define

begin_comment
comment|// 104 bit
end_comment

begin_define
define|#
directive|define
name|HostCmd_TYPE_WEP_128_BIT
value|0x0003
end_define

begin_comment
comment|// 128 bit
end_comment

begin_define
define|#
directive|define
name|HostCmd_TYPE_WEP_TX_KEY
value|0x0004
end_define

begin_comment
comment|// TX WEP
end_comment

begin_define
define|#
directive|define
name|HostCmd_NUM_OF_WEP_KEYS
value|4
end_define

begin_define
define|#
directive|define
name|HostCmd_WEP_KEY_INDEX_MASK
value|0x3fffffff
end_define

begin_comment
comment|//          Define action or option for HostCmd_CMD_802_11_RESET
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_HALT
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_RESTART
value|0x0002
end_define

begin_comment
comment|//          Define action or option for HostCmd_CMD_802_11_RADIO_CONTROL
end_comment

begin_define
define|#
directive|define
name|HostCmd_TYPE_AUTO_PREAMBLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_TYPE_SHORT_PREAMBLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_TYPE_LONG_PREAMBLE
value|0x0003
end_define

begin_comment
comment|//          Define action or option for CMD_802_11_RF_CHANNEL
end_comment

begin_define
define|#
directive|define
name|HostCmd_TYPE_802_11A
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_TYPE_802_11B
value|0x0002
end_define

begin_comment
comment|//          Define action or option for HostCmd_CMD_802_11_RF_TX_POWER
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_TX_POWER_OPT_SET_HIGH
value|0x0003
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_TX_POWER_OPT_SET_MID
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_TX_POWER_OPT_SET_LOW
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_TX_POWER_OPT_SET_AUTO
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_TX_POWER_LEVEL_MIN
value|0x000e
end_define

begin_comment
comment|// in dbm
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_TX_POWER_LEVEL_GAP
value|0x0001
end_define

begin_comment
comment|// in dbm
end_comment

begin_comment
comment|//          Define action or option for HostCmd_CMD_802_11_DATA_RATE
end_comment

begin_define
define|#
directive|define
name|HostCmd_ACT_SET_TX_AUTO
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_SET_TX_FIX_RATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GET_TX_RATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_SET_RX
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_SET_TX
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_SET_BOTH
value|0x0003
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GET_RX
value|0x0004
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GET_TX
value|0x0008
end_define

begin_define
define|#
directive|define
name|HostCmd_ACT_GET_BOTH
value|0x000c
end_define

begin_define
define|#
directive|define
name|TYPE_ANTENNA_DIVERSITY
value|0xffff
end_define

begin_comment
comment|//          Define action or option for HostCmd_CMD_802_11_PS_MODE
end_comment

begin_define
define|#
directive|define
name|HostCmd_TYPE_CAM
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_TYPE_MAX_PSP
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_TYPE_FAST_PSP
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_CMD_SET_EDCA_PARAMS
value|0x0115
end_define

begin_comment
comment|//=============================================================================
end_comment

begin_comment
comment|//			HOST COMMAND DEFINITIONS
end_comment

begin_comment
comment|//=============================================================================
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          Definition of data structure for each command
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          Define general data structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|Cmd
decl_stmt|;
name|uint16_t
name|Length
decl_stmt|;
ifdef|#
directive|ifdef
name|MWL_MBSS_SUPPORT
name|uint8_t
name|SeqNum
decl_stmt|;
name|uint8_t
name|MacId
decl_stmt|;
else|#
directive|else
name|uint16_t
name|SeqNum
decl_stmt|;
endif|#
directive|endif
name|uint16_t
name|Result
decl_stmt|;
block|}
name|__packed
name|FWCmdHdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|Version
decl_stmt|;
comment|// HW revision
name|uint8_t
name|HostIf
decl_stmt|;
comment|// Host interface
name|uint16_t
name|NumOfMCastAdr
decl_stmt|;
comment|// Max. number of Multicast address FW can handle
name|uint8_t
name|PermanentAddr
index|[
literal|6
index|]
decl_stmt|;
comment|// MAC address
name|uint16_t
name|RegionCode
decl_stmt|;
comment|// Region Code
name|uint32_t
name|FWReleaseNumber
decl_stmt|;
comment|// 4 byte of FW release number
name|uint32_t
name|ulFwAwakeCookie
decl_stmt|;
comment|// Firmware awake cookie
name|uint32_t
name|DeviceCaps
decl_stmt|;
comment|// Device capabilities (see above)
name|uint32_t
name|RxPdWrPtr
decl_stmt|;
comment|// Rx shared memory queue
name|uint32_t
name|NumTxQueues
decl_stmt|;
comment|// # TX queues in WcbBase array
name|uint32_t
name|WcbBase
index|[
name|MAX_TXWCB_QUEUES
index|]
decl_stmt|;
comment|// TX WCB Rings
name|uint32_t
name|Flags
decl_stmt|;
define|#
directive|define
name|SET_HW_SPEC_DISABLEMBSS
value|0x08
define|#
directive|define
name|SET_HW_SPEC_HOSTFORM_BEACON
value|0x10
define|#
directive|define
name|SET_HW_SPEC_HOSTFORM_PROBERESP
value|0x20
define|#
directive|define
name|SET_HW_SPEC_HOST_POWERSAVE
value|0x40
define|#
directive|define
name|SET_HW_SPEC_HOSTENCRDECR_MGMT
value|0x80
name|uint32_t
name|TxWcbNumPerQueue
decl_stmt|;
name|uint32_t
name|TotalRxWcb
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_SET_HW_SPEC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|u_int8_t
name|Version
decl_stmt|;
comment|/* version of the HW                    */
name|u_int8_t
name|HostIf
decl_stmt|;
comment|/* host interface                       */
name|u_int16_t
name|NumOfWCB
decl_stmt|;
comment|/* Max. number of WCB FW can handle     */
name|u_int16_t
name|NumOfMCastAddr
decl_stmt|;
comment|/* MaxNbr of MC addresses FW can handle */
name|u_int8_t
name|PermanentAddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* MAC address programmed in HW         */
name|u_int16_t
name|RegionCode
decl_stmt|;
name|u_int16_t
name|NumberOfAntenna
decl_stmt|;
comment|/* Number of antenna used      */
name|u_int32_t
name|FWReleaseNumber
decl_stmt|;
comment|/* 4 byte of FW release number */
name|u_int32_t
name|WcbBase0
decl_stmt|;
name|u_int32_t
name|RxPdWrPtr
decl_stmt|;
name|u_int32_t
name|RxPdRdPtr
decl_stmt|;
name|u_int32_t
name|ulFwAwakeCookie
decl_stmt|;
name|u_int32_t
name|WcbBase1
index|[
name|TOTAL_TX_QUEUES
operator|-
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_GET_HW_SPEC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|u_int32_t
name|Enable
decl_stmt|;
comment|/* FALSE: Disable or TRUE: Enable */
block|}
name|__packed
name|HostCmd_DS_BSS_START
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElemId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int8_t
name|OuiType
index|[
literal|4
index|]
decl_stmt|;
comment|/* 00:50:f2:01 */
name|u_int8_t
name|Ver
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|GrpKeyCipher
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|PwsKeyCnt
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|PwsKeyCipherList
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|AuthKeyCnt
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|AuthKeyList
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
name|RsnIE_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElemId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int8_t
name|Ver
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|GrpKeyCipher
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|PwsKeyCnt
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|PwsKeyCipherList
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|AuthKeyCnt
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|AuthKeyList
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|RsnCap
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|Rsn48IE_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElementId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int8_t
name|CfpCnt
decl_stmt|;
name|u_int8_t
name|CfpPeriod
decl_stmt|;
name|u_int16_t
name|CfpMaxDuration
decl_stmt|;
name|u_int16_t
name|CfpDurationRemaining
decl_stmt|;
block|}
name|__packed
name|CfParams_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElementId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int16_t
name|AtimWindow
decl_stmt|;
block|}
name|__packed
name|IbssParams_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|CfParams_t
name|CfParamSet
decl_stmt|;
name|IbssParams_t
name|IbssParamSet
decl_stmt|;
block|}
name|__packed
name|SsParams_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElementId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int16_t
name|DwellTime
decl_stmt|;
name|u_int8_t
name|HopSet
decl_stmt|;
name|u_int8_t
name|HopPattern
decl_stmt|;
name|u_int8_t
name|HopIndex
decl_stmt|;
block|}
name|__packed
name|FhParams_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElementId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int8_t
name|CurrentChan
decl_stmt|;
block|}
name|__packed
name|DsParams_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|FhParams_t
name|FhParamSet
decl_stmt|;
name|DsParams_t
name|DsParamSet
decl_stmt|;
block|}
name|__packed
name|PhyParams_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|FirstChannelNum
decl_stmt|;
name|u_int8_t
name|NumOfChannels
decl_stmt|;
name|u_int8_t
name|MaxTxPwrLevel
decl_stmt|;
block|}
name|__packed
name|ChannelInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElementId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int8_t
name|CountryStr
index|[
literal|3
index|]
decl_stmt|;
name|ChannelInfo_t
name|ChannelInfo
index|[
literal|40
index|]
decl_stmt|;
block|}
name|__packed
name|Country_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|AIFSN
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|ACM
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ACI
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|rsvd
range|:
literal|1
decl_stmt|;
block|}
name|__packed
name|ACIAIFSN_field_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ECW_min
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|ECW_max
range|:
literal|4
decl_stmt|;
block|}
name|__packed
name|ECWmin_max_field_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACIAIFSN_field_t
name|ACI_AIFSN
decl_stmt|;
name|ECWmin_max_field_t
name|ECW_min_max
decl_stmt|;
name|u_int16_t
name|TXOP_lim
decl_stmt|;
block|}
name|__packed
name|ACparam_rcd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ElementId
decl_stmt|;
name|u_int8_t
name|Len
decl_stmt|;
name|u_int8_t
name|OUI
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|Type
decl_stmt|;
name|u_int8_t
name|Subtype
decl_stmt|;
name|u_int8_t
name|version
decl_stmt|;
name|u_int8_t
name|rsvd
decl_stmt|;
name|ACparam_rcd_t
name|AC_BE
decl_stmt|;
name|ACparam_rcd_t
name|AC_BK
decl_stmt|;
name|ACparam_rcd_t
name|AC_VI
decl_stmt|;
name|ACparam_rcd_t
name|AC_VO
decl_stmt|;
block|}
name|__packed
name|WMM_param_elem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
ifdef|#
directive|ifdef
name|MWL_MBSS_SUPPORT
name|u_int8_t
name|StaMacAddr
index|[
literal|6
index|]
decl_stmt|;
endif|#
directive|endif
name|u_int8_t
name|SsId
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|BssType
decl_stmt|;
name|u_int16_t
name|BcnPeriod
decl_stmt|;
name|u_int8_t
name|DtimPeriod
decl_stmt|;
name|SsParams_t
name|SsParamSet
decl_stmt|;
name|PhyParams_t
name|PhyParamSet
decl_stmt|;
name|u_int16_t
name|ProbeDelay
decl_stmt|;
name|u_int16_t
name|CapInfo
decl_stmt|;
comment|/* see below */
name|u_int8_t
name|BssBasicRateSet
index|[
literal|14
index|]
decl_stmt|;
name|u_int8_t
name|OpRateSet
index|[
literal|14
index|]
decl_stmt|;
name|RsnIE_t
name|RsnIE
decl_stmt|;
name|Rsn48IE_t
name|Rsn48IE
decl_stmt|;
name|WMM_param_elem_t
name|WMMParam
decl_stmt|;
name|Country_t
name|Country
decl_stmt|;
name|u_int32_t
name|ApRFType
decl_stmt|;
comment|/* 0->B, 1->G, 2->Mixed, 3->A, 4->11J */
block|}
name|__packed
name|StartCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_DEFAULT
value|0x0000
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_ESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_IBSS
value|0x0002
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_CF_POLLABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_CF_REQUEST
value|0x0008
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_PRIVACY
value|0x0010
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_SHORT_PREAMBLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_PBCC
value|0x0040
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_CHANNEL_AGILITY
value|0x0080
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_SHORT_SLOT
value|0x0400
end_define

begin_define
define|#
directive|define
name|HostCmd_CAPINFO_DSSS_OFDM
value|0x2000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|StartCmd_t
name|StartCmd
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_AP_BEACON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|FrmBodyLen
decl_stmt|;
name|uint8_t
name|FrmBody
index|[
literal|1
index|]
decl_stmt|;
comment|/* NB: variable length */
block|}
name|__packed
name|HostCmd_DS_SET_BEACON
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_MAC_MULTICAST_ADR
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|NumOfAdrs
decl_stmt|;
define|#
directive|define
name|MWL_HAL_MCAST_MAX
value|32
name|uint8_t
name|MACList
index|[
literal|6
operator|*
literal|32
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_MAC_MULTICAST_ADR
typedef|;
end_typedef

begin_comment
comment|// Indicate to FW the current state of AP ERP info
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|GProtectFlag
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_G_PROTECT_FLAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_INFRA_MODE
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_802_11_RF_CHANNEL
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint8_t
name|CurrentChannel
decl_stmt|;
comment|/* channel # */
name|uint32_t
name|ChannelFlags
decl_stmt|;
comment|/* see below */
block|}
name|__packed
name|HostCmd_FW_SET_RF_CHANNEL
typedef|;
end_typedef

begin_comment
comment|/* bits 0-5 specify frequency band */
end_comment

begin_define
define|#
directive|define
name|FREQ_BAND_2DOT4GHZ
value|0x0001
end_define

begin_define
define|#
directive|define
name|FREQ_BAND_4DOT9GHZ
value|0x0002
end_define

begin_comment
comment|/* XXX not implemented */
end_comment

begin_define
define|#
directive|define
name|FREQ_BAND_5GHZ
value|0x0004
end_define

begin_define
define|#
directive|define
name|FREQ_BAND_5DOT2GHZ
value|0x0008
end_define

begin_comment
comment|/* XXX not implemented */
end_comment

begin_comment
comment|/* bits 6-10 specify channel width */
end_comment

begin_define
define|#
directive|define
name|CH_AUTO_WIDTH
value|0x0000
end_define

begin_comment
comment|/* XXX not used? */
end_comment

begin_define
define|#
directive|define
name|CH_10_MHz_WIDTH
value|0x0040
end_define

begin_define
define|#
directive|define
name|CH_20_MHz_WIDTH
value|0x0080
end_define

begin_define
define|#
directive|define
name|CH_40_MHz_WIDTH
value|0x0100
end_define

begin_comment
comment|/* bits 11-12 specify extension channel */
end_comment

begin_define
define|#
directive|define
name|EXT_CH_NONE
value|0x0000
end_define

begin_comment
comment|/* no extension channel */
end_comment

begin_define
define|#
directive|define
name|EXT_CH_ABOVE_CTRL_CH
value|0x0800
end_define

begin_comment
comment|/* extension channel above */
end_comment

begin_define
define|#
directive|define
name|EXT_CH_AUTO
value|0x1000
end_define

begin_comment
comment|/* XXX not used? */
end_comment

begin_define
define|#
directive|define
name|EXT_CH_BELOW_CTRL_CH
value|0x1800
end_define

begin_comment
comment|/* extension channel below */
end_comment

begin_comment
comment|/* bits 13-31 are reserved */
end_comment

begin_define
define|#
directive|define
name|FIXED_RATE_WITH_AUTO_RATE_DROP
value|0
end_define

begin_define
define|#
directive|define
name|FIXED_RATE_WITHOUT_AUTORATE_DROP
value|1
end_define

begin_define
define|#
directive|define
name|LEGACY_RATE_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|HT_RATE_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|RETRY_COUNT_VALID
value|0
end_define

begin_define
define|#
directive|define
name|RETRY_COUNT_INVALID
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// lower rate after the retry count
name|uint32_t
name|FixRateType
decl_stmt|;
comment|//0: legacy, 1: HT
name|uint32_t
name|RetryCountValid
decl_stmt|;
comment|//0: retry count is not valid, 1: use retry count specified
block|}
name|__packed
name|FIX_RATE_FLAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FIX_RATE_FLAG
name|FixRateTypeFlags
decl_stmt|;
name|uint32_t
name|FixedRate
decl_stmt|;
comment|// legacy rate(not index) or an MCS code.
name|uint32_t
name|RetryCount
decl_stmt|;
block|}
name|__packed
name|FIXED_RATE_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Action
decl_stmt|;
comment|//HostCmd_ACT_GEN_GET		0x0000
comment|//HostCmd_ACT_GEN_SET 		0x0001
comment|//HostCmd_ACT_NOT_USE_FIXED_RATE 0x0002
name|uint32_t
name|AllowRateDrop
decl_stmt|;
comment|// use fixed rate specified but firmware can drop to
name|uint32_t
name|EntryCount
decl_stmt|;
name|FIXED_RATE_ENTRY
name|FixedRateTable
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|MulticastRate
decl_stmt|;
name|uint8_t
name|MultiRateTxType
decl_stmt|;
name|uint8_t
name|ManagementRate
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_USE_FIXED_RATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|AllowRateDrop
decl_stmt|;
name|uint32_t
name|EntryCount
decl_stmt|;
name|FIXED_RATE_ENTRY
name|FixedRateTable
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
name|USE_FIXED_RATE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Action
decl_stmt|;
name|uint32_t
name|GIType
decl_stmt|;
define|#
directive|define
name|GI_TYPE_LONG
value|0x0001
define|#
directive|define
name|GI_TYPE_SHORT
value|0x0002
block|}
name|__packed
name|HostCmd_FW_HT_GUARD_INTERVAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Action
decl_stmt|;
name|uint8_t
name|RxAntennaMap
decl_stmt|;
name|uint8_t
name|TxAntennaMap
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_HT_MIMO_CONFIG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint8_t
name|Slot
decl_stmt|;
comment|// Slot=0 if regular, Slot=1 if short.
block|}
name|__packed
name|HostCmd_FW_SET_SLOT
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_802_11_GET_STAT
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|TxRetrySuccesses
decl_stmt|;
name|uint32_t
name|TxMultipleRetrySuccesses
decl_stmt|;
name|uint32_t
name|TxFailures
decl_stmt|;
name|uint32_t
name|RTSSuccesses
decl_stmt|;
name|uint32_t
name|RTSFailures
decl_stmt|;
name|uint32_t
name|AckFailures
decl_stmt|;
name|uint32_t
name|RxDuplicateFrames
decl_stmt|;
name|uint32_t
name|FCSErrorCount
decl_stmt|;
name|uint32_t
name|TxWatchDogTimeouts
decl_stmt|;
name|uint32_t
name|RxOverflows
decl_stmt|;
comment|//used
name|uint32_t
name|RxFragErrors
decl_stmt|;
comment|//used
name|uint32_t
name|RxMemErrors
decl_stmt|;
comment|//used
name|uint32_t
name|PointerErrors
decl_stmt|;
comment|//used
name|uint32_t
name|TxUnderflows
decl_stmt|;
comment|//used
name|uint32_t
name|TxDone
decl_stmt|;
name|uint32_t
name|TxDoneBufTryPut
decl_stmt|;
name|uint32_t
name|TxDoneBufPut
decl_stmt|;
name|uint32_t
name|Wait4TxBuf
decl_stmt|;
comment|// Put size of requested buffer in here
name|uint32_t
name|TxAttempts
decl_stmt|;
name|uint32_t
name|TxSuccesses
decl_stmt|;
name|uint32_t
name|TxFragments
decl_stmt|;
name|uint32_t
name|TxMulticasts
decl_stmt|;
name|uint32_t
name|RxNonCtlPkts
decl_stmt|;
name|uint32_t
name|RxMulticasts
decl_stmt|;
name|uint32_t
name|RxUndecryptableFrames
decl_stmt|;
name|uint32_t
name|RxICVErrors
decl_stmt|;
name|uint32_t
name|RxExcludedFrames
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_802_11_GET_STAT
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_MAC_REG_ACCESS
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|Offset
decl_stmt|;
name|uint32_t
name|Value
decl_stmt|;
name|uint16_t
name|Reserved
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_MAC_REG_ACCESS
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_BBP_REG_ACCESS
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|Offset
decl_stmt|;
name|uint8_t
name|Value
decl_stmt|;
name|uint8_t
name|Reserverd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_BBP_REG_ACCESS
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_RF_REG_ACCESS
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|Offset
decl_stmt|;
name|uint8_t
name|Value
decl_stmt|;
name|uint8_t
name|Reserverd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_RF_REG_ACCESS
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_802_11_RADIO_CONTROL
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|Control
decl_stmt|;
comment|// @bit0: 1/0,on/off, @bit1: 1/0, long/short @bit2: 1/0,auto/fix
name|uint16_t
name|RadioOn
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_802_11_RADIO_CONTROL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TX_POWER_LEVEL_TOTAL
value|8
end_define

begin_comment
comment|//          Define data structure for HostCmd_CMD_802_11_RF_TX_POWER
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|SupportTxPowerLevel
decl_stmt|;
name|uint16_t
name|CurrentTxPowerLevel
decl_stmt|;
name|uint16_t
name|Reserved
decl_stmt|;
name|uint16_t
name|PowerLevelList
index|[
name|TX_POWER_LEVEL_TOTAL
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_802_11_RF_TX_POWER
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_802_11_RF_ANTENNA
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_HostCmd_DS_802_11_RF_ANTENNA
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|AntennaMode
decl_stmt|;
comment|// Number of antennas or 0xffff(diversity)
block|}
name|__packed
name|HostCmd_DS_802_11_RF_ANTENNA
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_802_11_PS_MODE
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|PowerMode
decl_stmt|;
comment|// CAM, Max.PSP or Fast PSP
block|}
name|__packed
name|HostCmd_DS_802_11_PS_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|Threshold
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_802_11_RTS_THSD
typedef|;
end_typedef

begin_comment
comment|// used for stand alone bssid sets/clears
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
ifdef|#
directive|ifdef
name|MWL_MBSS_SUPPORT
name|uint16_t
name|MacType
decl_stmt|;
define|#
directive|define
name|WL_MAC_TYPE_PRIMARY_CLIENT
value|0
define|#
directive|define
name|WL_MAC_TYPE_SECONDARY_CLIENT
value|1
define|#
directive|define
name|WL_MAC_TYPE_PRIMARY_AP
value|2
define|#
directive|define
name|WL_MAC_TYPE_SECONDARY_AP
value|3
endif|#
directive|endif
name|uint8_t
name|MacAddr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_SET_MAC
operator|,
name|HostCmd_FW_SET_BSSID
operator|,
name|HostCmd_FW_SET_MAC
typedef|;
end_typedef

begin_comment
comment|// Indicate to FW to send out PS Poll
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|PSPoll
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_TX_POLL
typedef|;
end_typedef

begin_comment
comment|// used for AID sets/clears
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|AssocID
decl_stmt|;
name|uint8_t
name|MacAddr
index|[
literal|6
index|]
decl_stmt|;
comment|//AP's Mac Address(BSSID)
name|uint32_t
name|GProtection
decl_stmt|;
name|uint8_t
name|ApRates
index|[
name|RATE_INDEX_MAX_ARRAY
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_AID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|LegacyRateBitMap
decl_stmt|;
name|uint32_t
name|HTRateBitMap
decl_stmt|;
name|uint16_t
name|CapInfo
decl_stmt|;
name|uint16_t
name|HTCapabilitiesInfo
decl_stmt|;
name|uint8_t
name|MacHTParamInfo
decl_stmt|;
name|uint8_t
name|Rev
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|ControlChan
decl_stmt|;
name|uint8_t
name|AddChan
decl_stmt|;
name|uint16_t
name|OpMode
decl_stmt|;
name|uint16_t
name|stbc
decl_stmt|;
block|}
name|__packed
name|AddHtInfo
struct|;
block|}
name|__packed
name|PeerInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|AID
decl_stmt|;
name|uint8_t
name|MacAddr
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|StnId
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|Reserved
decl_stmt|;
name|PeerInfo_t
name|PeerInfo
decl_stmt|;
name|uint8_t
name|Qosinfo
decl_stmt|;
name|uint8_t
name|isQosSta
decl_stmt|;
name|uint32_t
name|FwStaPtr
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_NEW_STN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|tick
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_KEEP_ALIVE_TICK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|QNum
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_RIFS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|ApMode
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_APMODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
comment|// see following
name|uint16_t
name|RadarTypeCode
decl_stmt|;
block|}
name|__packed
name|HostCmd_802_11h_Detect_Radar
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DR_DFS_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DR_CHK_CHANNEL_AVAILABLE_START
value|1
end_define

begin_define
define|#
directive|define
name|DR_CHK_CHANNEL_AVAILABLE_STOP
value|2
end_define

begin_define
define|#
directive|define
name|DR_IN_SERVICE_MONITOR_START
value|3
end_define

begin_comment
comment|//New Structure for Update Tim 30/9/2003
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Aid
decl_stmt|;
name|uint32_t
name|Set
decl_stmt|;
block|}
name|__packed
name|HostCmd_UpdateTIM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|SsidBroadcastEnable
decl_stmt|;
block|}
name|__packed
name|HostCmd_SSID_BROADCAST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|WdsEnable
decl_stmt|;
block|}
name|__packed
name|HostCmd_WDS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Next11hChannel
decl_stmt|;
name|uint32_t
name|Mode
decl_stmt|;
name|uint32_t
name|InitialCount
decl_stmt|;
name|uint32_t
name|ChannelFlags
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_SWITCH_CHANNEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|SpectrumMgmt
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_SPECTRUM_MGMT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|int32_t
name|PowerConstraint
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_POWER_CONSTRAINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|FirstChannelNo
decl_stmt|;
name|uint8_t
name|NoofChannel
decl_stmt|;
name|uint8_t
name|MaxTransmitPw
decl_stmt|;
block|}
name|__packed
name|DomainChannelEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|CountryString
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|GChannelLen
decl_stmt|;
name|DomainChannelEntry
name|DomainEntryG
index|[
literal|1
index|]
decl_stmt|;
comment|/** Assume only 1 G zone **/
name|uint8_t
name|AChannelLen
decl_stmt|;
name|DomainChannelEntry
name|DomainEntryA
index|[
literal|20
index|]
decl_stmt|;
comment|/** Assume max of 5 A zone **/
block|}
name|__packed
name|DomainCountryInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Action
decl_stmt|;
comment|// 0 -> unset, 1 ->set
name|DomainCountryInfo
name|DomainInfo
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_COUNTRY_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|regionCode
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_REGIONCODE_INFO
typedef|;
end_typedef

begin_comment
comment|// for HostCmd_CMD_SET_WMM_MODE
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
comment|// 0->unset, 1->set
block|}
name|__packed
name|HostCmd_FW_SetWMMMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
comment|// 0->unset, 1->set
name|uint16_t
name|IeListLen
decl_stmt|;
name|uint8_t
name|IeList
index|[
literal|200
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SetIEs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EDCA_PARAM_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|BA_PARAM_SIZE
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
comment|//0 = get all, 0x1 =set CWMin/Max,  0x2 = set TXOP , 0x4 =set AIFSN
name|uint16_t
name|TxOP
decl_stmt|;
comment|// in unit of 32 us
name|uint32_t
name|CWMax
decl_stmt|;
comment|// 0~15
name|uint32_t
name|CWMin
decl_stmt|;
comment|// 0~15
name|uint8_t
name|AIFSN
decl_stmt|;
name|uint8_t
name|TxQNum
decl_stmt|;
comment|// Tx Queue number.
block|}
name|__packed
name|HostCmd_FW_SET_EDCA_PARAMS
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************** 	@HWENCR@ 	Hardware Encryption related data structures and constant definitions. 	Note that all related changes are marked with the @HWENCR@ tag. *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MAX_ENCR_KEY_LENGTH
value|16
end_define

begin_comment
comment|/* max 128 bits - depends on type */
end_comment

begin_define
define|#
directive|define
name|MIC_KEY_LENGTH
value|8
end_define

begin_comment
comment|/* size of Tx/Rx MIC key - 8 bytes*/
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_TYPE_ID_WEP
value|0x00
end_define

begin_comment
comment|/* Key type is WEP		*/
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_TYPE_ID_TKIP
value|0x01
end_define

begin_comment
comment|/* Key type is TKIP		*/
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_TYPE_ID_AES
value|0x02
end_define

begin_comment
comment|/* Key type is AES-CCMP	*/
end_comment

begin_comment
comment|/* flags used in structure - same as driver EKF_XXX flags */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_INUSE
value|0x00000001
end_define

begin_comment
comment|/* indicate key is in use */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_RXGROUPKEY
value|0x00000002
end_define

begin_comment
comment|/* Group key for RX only */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_TXGROUPKEY
value|0x00000004
end_define

begin_comment
comment|/* Group key for TX */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_PAIRWISE
value|0x00000008
end_define

begin_comment
comment|/* pairwise */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_RXONLY
value|0x00000010
end_define

begin_comment
comment|/* only used for RX */
end_comment

begin_comment
comment|// These flags are new additions - for hardware encryption commands only.
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_AUTHENTICATOR
value|0x00000020
end_define

begin_comment
comment|/* Key is for Authenticator */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_TSC_VALID
value|0x00000040
end_define

begin_comment
comment|/* Sequence counters valid */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_WEP_TXKEY
value|0x01000000
end_define

begin_comment
comment|/* Tx key for WEP */
end_comment

begin_define
define|#
directive|define
name|ENCR_KEY_FLAG_MICKEY_VALID
value|0x02000000
end_define

begin_comment
comment|/* Tx/Rx MIC keys are valid */
end_comment

begin_comment
comment|/* 	UPDATE_ENCRYPTION command action type. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|// request to enable/disable HW encryption
name|EncrActionEnableHWEncryption
block|,
comment|// request to set encryption key
name|EncrActionTypeSetKey
block|,
comment|// request to remove one or more keys
name|EncrActionTypeRemoveKey
block|,
name|EncrActionTypeSetGroupKey
block|}
name|ENCR_ACTION_TYPE
typedef|;
end_typedef

begin_comment
comment|/* 	Key material definitions (for WEP, TKIP,& AES-CCMP) */
end_comment

begin_comment
comment|/*  	WEP Key material definition 	---------------------------- 	WEPKey	--> An array of 'MAX_ENCR_KEY_LENGTH' bytes. 				Note that we do not support 152bit WEP keys */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// WEP key material (max 128bit)
name|uint8_t
name|KeyMaterial
index|[
name|MAX_ENCR_KEY_LENGTH
index|]
decl_stmt|;
block|}
name|__packed
name|WEP_TYPE_KEY
typedef|;
end_typedef

begin_comment
comment|/* 	TKIP Key material definition 	---------------------------- 	This structure defines TKIP key material. Note that 	the TxMicKey and RxMicKey may or may not be valid. */
end_comment

begin_comment
comment|/* TKIP Sequence counter - 24 bits */
end_comment

begin_comment
comment|/* Incremented on each fragment MPDU */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|low
decl_stmt|;
name|uint32_t
name|high
decl_stmt|;
block|}
name|__packed
name|ENCR_TKIPSEQCNT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// TKIP Key material. Key type (group or pairwise key) is
comment|// determined by flags in KEY_PARAM_SET structure.
name|uint8_t
name|KeyMaterial
index|[
name|MAX_ENCR_KEY_LENGTH
index|]
decl_stmt|;
name|uint8_t
name|TkipTxMicKey
index|[
name|MIC_KEY_LENGTH
index|]
decl_stmt|;
name|uint8_t
name|TkipRxMicKey
index|[
name|MIC_KEY_LENGTH
index|]
decl_stmt|;
name|ENCR_TKIPSEQCNT
name|TkipRsc
decl_stmt|;
name|ENCR_TKIPSEQCNT
name|TkipTsc
decl_stmt|;
block|}
name|__packed
name|TKIP_TYPE_KEY
typedef|;
end_typedef

begin_comment
comment|/* 	AES-CCMP Key material definition 	-------------------------------- 	This structure defines AES-CCMP key material. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// AES Key material
name|uint8_t
name|KeyMaterial
index|[
name|MAX_ENCR_KEY_LENGTH
index|]
decl_stmt|;
block|}
name|__packed
name|AES_TYPE_KEY
typedef|;
end_typedef

begin_comment
comment|/* 	Encryption key definition. 	-------------------------- 	This structure provides all required/essential 	information about the key being set/removed. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|Length
decl_stmt|;
comment|// Total length of this structure
name|uint16_t
name|KeyTypeId
decl_stmt|;
comment|// Key type - WEP, TKIP or AES-CCMP.
name|uint32_t
name|KeyInfo
decl_stmt|;
comment|// key flags (ENCR_KEY_FLAG_XXX_
name|uint32_t
name|KeyIndex
decl_stmt|;
comment|// For WEP only - actual key index
name|uint16_t
name|KeyLen
decl_stmt|;
comment|// Size of the key
union|union
block|{
comment|// Key material (variable size array)
name|WEP_TYPE_KEY
name|WepKey
decl_stmt|;
name|TKIP_TYPE_KEY
name|TkipKey
decl_stmt|;
name|AES_TYPE_KEY
name|AesKey
decl_stmt|;
block|}
name|__packed
name|Key
union|;
ifdef|#
directive|ifdef
name|MWL_MBSS_SUPPORT
name|uint8_t
name|Macaddr
index|[
literal|6
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|__packed
name|KEY_PARAM_SET
typedef|;
end_typedef

begin_comment
comment|/* 	HostCmd_FW_UPDATE_ENCRYPTION 	---------------------------- 	Define data structure for updating firmware encryption keys.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|ActionType
decl_stmt|;
comment|// ENCR_ACTION_TYPE
name|uint32_t
name|DataLength
decl_stmt|;
comment|// size of the data buffer attached.
ifdef|#
directive|ifdef
name|MWL_MBSS_SUPPORT
name|uint8_t
name|macaddr
index|[
literal|6
index|]
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|ActionData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_UPDATE_ENCRYPTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|ActionType
decl_stmt|;
comment|// ENCR_ACTION_TYPE
name|uint32_t
name|DataLength
decl_stmt|;
comment|// size of the data buffer attached.
name|KEY_PARAM_SET
name|KeyParam
decl_stmt|;
ifndef|#
directive|ifndef
name|MWL_MBSS_SUPPORT
name|uint8_t
name|Macaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* XXX? */
endif|#
directive|endif
block|}
name|__packed
name|HostCmd_FW_UPDATE_ENCRYPTION_SET_KEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// Rate flags - see above.
name|uint32_t
name|Flags
decl_stmt|;
comment|// Rate in 500Kbps units.
name|uint8_t
name|RateKbps
decl_stmt|;
comment|// 802.11 rate to conversion table index value.
comment|// This is the value required by the firmware/hardware.
name|uint16_t
name|RateCodeToIndex
decl_stmt|;
block|}
name|__packed
name|RATE_INFO
typedef|;
end_typedef

begin_comment
comment|/* 	UPDATE_STADB command action type. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|// request to add entry to stainfo db
name|StaInfoDbActionAddEntry
block|,
comment|// request to modify peer entry
name|StaInfoDbActionModifyEntry
block|,
comment|// request to remove peer from stainfo db
name|StaInfoDbActionRemoveEntry
block|}
name|__packed
name|STADB_ACTION_TYPE
typedef|;
end_typedef

begin_comment
comment|/* 	@11E-BA@ 	802.11e/WMM Related command(s)/data structures */
end_comment

begin_comment
comment|// Flag to indicate if the stream is an immediate block ack stream.
end_comment

begin_comment
comment|// if this bit is not set, the stream is delayed block ack stream.
end_comment

begin_define
define|#
directive|define
name|BASTREAM_FLAG_DELAYED_TYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|BASTREAM_FLAG_IMMEDIATE_TYPE
value|0x01
end_define

begin_comment
comment|// Flag to indicate the direction of the stream (upstream/downstream).
end_comment

begin_comment
comment|// If this bit is not set, the direction is downstream.
end_comment

begin_define
define|#
directive|define
name|BASTREAM_FLAG_DIRECTION_UPSTREAM
value|0x00
end_define

begin_define
define|#
directive|define
name|BASTREAM_FLAG_DIRECTION_DOWNSTREAM
value|0x02
end_define

begin_define
define|#
directive|define
name|BASTREAM_FLAG_DIRECTION_DLP
value|0x04
end_define

begin_define
define|#
directive|define
name|BASTREAM_FLAG_DIRECTION_BOTH
value|0x06
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|BaCreateStream
block|,
name|BaUpdateStream
block|,
name|BaDestroyStream
block|,
name|BaFlushStream
block|,
name|BaCheckCreateStream
block|}
name|BASTREAM_ACTION_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|Context
decl_stmt|;
block|}
name|__packed
name|BASTREAM_CONTEXT
typedef|;
end_typedef

begin_comment
comment|// parameters for block ack creation
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// BA Creation flags - see above
name|uint32_t
name|Flags
decl_stmt|;
comment|// idle threshold
name|uint32_t
name|IdleThrs
decl_stmt|;
comment|// block ack transmit threshold (after how many pkts should we send BAR?)
name|uint32_t
name|BarThrs
decl_stmt|;
comment|// receiver window size
name|uint32_t
name|WindowSize
decl_stmt|;
comment|// MAC Address of the BA partner
name|uint8_t
name|PeerMacAddr
index|[
literal|6
index|]
decl_stmt|;
comment|// Dialog Token
name|uint8_t
name|DialogToken
decl_stmt|;
comment|//TID for the traffic stream in this BA
name|uint8_t
name|Tid
decl_stmt|;
comment|// shared memory queue ID (not sure if this is required)
name|uint8_t
name|QueueId
decl_stmt|;
name|uint8_t
name|ParamInfo
decl_stmt|;
comment|// returned by firmware - firmware context pointer.
comment|// this context pointer will be passed to firmware for all future commands.
name|BASTREAM_CONTEXT
name|FwBaContext
decl_stmt|;
name|uint8_t
name|ResetSeqNo
decl_stmt|;
comment|/** 0 or 1**/
name|uint16_t
name|StartSeqNo
decl_stmt|;
comment|// proxy sta MAC Address
name|uint8_t
name|StaSrcMacAddr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
name|BASTREAM_CREATE_STREAM
typedef|;
end_typedef

begin_comment
comment|// new transmit sequence number information
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// BA flags - see above
name|uint32_t
name|Flags
decl_stmt|;
comment|// returned by firmware in the create ba stream response
name|BASTREAM_CONTEXT
name|FwBaContext
decl_stmt|;
comment|// new sequence number for this block ack stream
name|uint16_t
name|BaSeqNum
decl_stmt|;
block|}
name|__packed
name|BASTREAM_UPDATE_STREAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// BA Stream flags
name|uint32_t
name|Flags
decl_stmt|;
comment|// returned by firmware in the create ba stream response
name|BASTREAM_CONTEXT
name|FwBaContext
decl_stmt|;
block|}
name|__packed
name|BASTREAM_STREAM_INFO
typedef|;
end_typedef

begin_comment
comment|//Command to create/destroy block ACK
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|ActionType
decl_stmt|;
union|union
block|{
comment|// information required to create BA Stream...
name|BASTREAM_CREATE_STREAM
name|CreateParams
decl_stmt|;
comment|// update starting/new sequence number etc.
name|BASTREAM_UPDATE_STREAM
name|UpdtSeqNum
decl_stmt|;
comment|// destroy an existing stream...
name|BASTREAM_STREAM_INFO
name|DestroyParams
decl_stmt|;
comment|// destroy an existing stream...
name|BASTREAM_STREAM_INFO
name|FlushParams
decl_stmt|;
block|}
name|__packed
name|BaInfo
union|;
block|}
name|__packed
name|HostCmd_FW_BASTREAM
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_GET_WATCHDOG_BITMAP
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|Watchdogbitmap
decl_stmt|;
comment|// for SW/BA
block|}
name|__packed
name|HostCmd_FW_GET_WATCHDOG_BITMAP
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_SET_REGION_POWER
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|MaxPowerLevel
decl_stmt|;
name|uint16_t
name|Reserved
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_SET_REGION_POWER
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_SET_RATE_ADAPT_MODE
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|RateAdaptMode
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_SET_RATE_ADAPT_MODE
typedef|;
end_typedef

begin_comment
comment|//          Define data structure for HostCmd_CMD_SET_LINKADAPT_CS_MODE
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
name|uint16_t
name|CSMode
decl_stmt|;
block|}
name|__packed
name|HostCmd_DS_SET_LINKADAPT_CS_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|NProtectFlag
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_N_PROTECT_FLAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|NProtectOpMode
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_N_PROTECT_OPMODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|OptLevel
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_OPTIMIZATION_LEVEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|annex
decl_stmt|;
name|uint8_t
name|index
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|Reserverd
decl_stmt|;
define|#
directive|define
name|CAL_TBL_SIZE
value|160
name|uint8_t
name|calTbl
index|[
name|CAL_TBL_SIZE
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_GET_CALTABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|Addr
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|Enable
decl_stmt|;
name|uint8_t
name|Mode
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_SET_MIMOPSHT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_BEACON_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Bcnlen
decl_stmt|;
name|uint8_t
name|Reserverd
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|Bcn
index|[
name|MAX_BEACON_SIZE
index|]
decl_stmt|;
block|}
name|__packed
name|HostCmd_FW_GET_BEACON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|NumberOfPowersave
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_POWERSAVESTATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Aid
decl_stmt|;
name|uint32_t
name|Set
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|HostCmd_SET_TIM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|TrafficMap
index|[
literal|251
index|]
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|HostCmd_GET_TIM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint8_t
name|MacAddr
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|TID
decl_stmt|;
name|uint16_t
name|SeqNo
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|HostCmd_GET_SEQNO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Enable
decl_stmt|;
comment|//0 -- Disbale. or 1 -- Enable.
block|}
name|__packed
name|HostCmd_DWDS_ENABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint16_t
name|Action
decl_stmt|;
comment|/* 0: Get. 1:Set */
name|uint32_t
name|Option
decl_stmt|;
comment|/* 0: default. 1:Aggressive */
name|uint32_t
name|Threshold
decl_stmt|;
comment|/* Range 0-200, default 8 */
block|}
name|__packed
name|HostCmd_FW_AMPDU_RETRY_RATEDROP_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FWCmdHdr
name|CmdHdr
decl_stmt|;
name|uint32_t
name|Enable
decl_stmt|;
comment|/* 0 -- Disable. or 1 -- Enable */
block|}
name|__packed
name|HostCmd_CFEND_ENABLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MWL_HALREG_H_ */
end_comment

end_unit

