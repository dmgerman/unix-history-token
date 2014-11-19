begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register names were taken almost as is from the documentation.  */
end_comment

begin_define
define|#
directive|define
name|MAC_CONFIGURATION
value|0x0
end_define

begin_define
define|#
directive|define
name|CONF_JD
value|(1<< 22)
end_define

begin_comment
comment|/* jabber timer disable */
end_comment

begin_define
define|#
directive|define
name|CONF_BE
value|(1<< 21)
end_define

begin_comment
comment|/* Frame Burst Enable */
end_comment

begin_define
define|#
directive|define
name|CONF_PS
value|(1<< 15)
end_define

begin_comment
comment|/* GMII/MII */
end_comment

begin_define
define|#
directive|define
name|CONF_FES
value|(1<< 14)
end_define

begin_comment
comment|/* MII speed select */
end_comment

begin_define
define|#
directive|define
name|CONF_DM
value|(1<< 11)
end_define

begin_comment
comment|/* Full Duplex Enable */
end_comment

begin_define
define|#
directive|define
name|CONF_ACS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CONF_TE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CONF_RE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MAC_FRAME_FILTER
value|0x4
end_define

begin_define
define|#
directive|define
name|FRAME_FILTER_RA
value|(1<< 31)
end_define

begin_comment
comment|/* Receive All */
end_comment

begin_define
define|#
directive|define
name|FRAME_FILTER_HPF
value|(1<< 10)
end_define

begin_comment
comment|/* Hash or Perfect Filter */
end_comment

begin_define
define|#
directive|define
name|FRAME_FILTER_PM
value|(1<< 4)
end_define

begin_comment
comment|/* Pass multicast */
end_comment

begin_define
define|#
directive|define
name|FRAME_FILTER_HMC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FRAME_FILTER_HUC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FRAME_FILTER_PR
value|(1<< 0)
end_define

begin_comment
comment|/* All Incoming Frames */
end_comment

begin_define
define|#
directive|define
name|GMII_ADDRESS
value|0x10
end_define

begin_define
define|#
directive|define
name|GMII_ADDRESS_PA_MASK
value|0x1f
end_define

begin_comment
comment|/* Phy device */
end_comment

begin_define
define|#
directive|define
name|GMII_ADDRESS_PA_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|GMII_ADDRESS_GR_MASK
value|0x1f
end_define

begin_comment
comment|/* Phy register */
end_comment

begin_define
define|#
directive|define
name|GMII_ADDRESS_GR_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|GMII_ADDRESS_CR_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|GMII_ADDRESS_CR_SHIFT
value|2
end_define

begin_comment
comment|/* Clock */
end_comment

begin_define
define|#
directive|define
name|GMII_ADDRESS_GW
value|(1<< 1)
end_define

begin_comment
comment|/* Write operation */
end_comment

begin_define
define|#
directive|define
name|GMII_ADDRESS_GB
value|(1<< 0)
end_define

begin_comment
comment|/* Busy */
end_comment

begin_define
define|#
directive|define
name|GMII_DATA
value|0x14
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL
value|0x18
end_define

begin_define
define|#
directive|define
name|GMAC_VLAN_TAG
value|0x1C
end_define

begin_define
define|#
directive|define
name|VERSION
value|0x20
end_define

begin_define
define|#
directive|define
name|DEBUG
value|0x24
end_define

begin_define
define|#
directive|define
name|LPI_CONTROL_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|LPI_TIMERS_CONTROL
value|0x34
end_define

begin_define
define|#
directive|define
name|INTERRUPT_STATUS
value|0x38
end_define

begin_define
define|#
directive|define
name|INTERRUPT_MASK
value|0x3C
end_define

begin_define
define|#
directive|define
name|MAC_ADDRESS_HIGH
parameter_list|(
name|n
parameter_list|)
value|((n> 15 ? 0x800 : 0x40) + 0x8 * n)
end_define

begin_define
define|#
directive|define
name|MAC_ADDRESS_LOW
parameter_list|(
name|n
parameter_list|)
value|((n> 15 ? 0x804 : 0x44) + 0x8 * n)
end_define

begin_define
define|#
directive|define
name|SGMII_RGMII_SMII_CTRL_STATUS
value|0xD8
end_define

begin_define
define|#
directive|define
name|MMC_CONTROL
value|0x100
end_define

begin_define
define|#
directive|define
name|MMC_CONTROL_CNTRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MMC_RECEIVE_INTERRUPT
value|0x104
end_define

begin_define
define|#
directive|define
name|MMC_TRANSMIT_INTERRUPT
value|0x108
end_define

begin_define
define|#
directive|define
name|MMC_RECEIVE_INTERRUPT_MASK
value|0x10C
end_define

begin_define
define|#
directive|define
name|MMC_TRANSMIT_INTERRUPT_MASK
value|0x110
end_define

begin_define
define|#
directive|define
name|TXOCTETCOUNT_GB
value|0x114
end_define

begin_define
define|#
directive|define
name|TXFRAMECOUNT_GB
value|0x118
end_define

begin_define
define|#
directive|define
name|TXBROADCASTFRAMES_G
value|0x11C
end_define

begin_define
define|#
directive|define
name|TXMULTICASTFRAMES_G
value|0x120
end_define

begin_define
define|#
directive|define
name|TX64OCTETS_GB
value|0x124
end_define

begin_define
define|#
directive|define
name|TX65TO127OCTETS_GB
value|0x128
end_define

begin_define
define|#
directive|define
name|TX128TO255OCTETS_GB
value|0x12C
end_define

begin_define
define|#
directive|define
name|TX256TO511OCTETS_GB
value|0x130
end_define

begin_define
define|#
directive|define
name|TX512TO1023OCTETS_GB
value|0x134
end_define

begin_define
define|#
directive|define
name|TX1024TOMAXOCTETS_GB
value|0x138
end_define

begin_define
define|#
directive|define
name|TXUNICASTFRAMES_GB
value|0x13C
end_define

begin_define
define|#
directive|define
name|TXMULTICASTFRAMES_GB
value|0x140
end_define

begin_define
define|#
directive|define
name|TXBROADCASTFRAMES_GB
value|0x144
end_define

begin_define
define|#
directive|define
name|TXUNDERFLOWERROR
value|0x148
end_define

begin_define
define|#
directive|define
name|TXSINGLECOL_G
value|0x14C
end_define

begin_define
define|#
directive|define
name|TXMULTICOL_G
value|0x150
end_define

begin_define
define|#
directive|define
name|TXDEFERRED
value|0x154
end_define

begin_define
define|#
directive|define
name|TXLATECOL
value|0x158
end_define

begin_define
define|#
directive|define
name|TXEXESSCOL
value|0x15C
end_define

begin_define
define|#
directive|define
name|TXCARRIERERR
value|0x160
end_define

begin_define
define|#
directive|define
name|TXOCTETCNT
value|0x164
end_define

begin_define
define|#
directive|define
name|TXFRAMECOUNT_G
value|0x168
end_define

begin_define
define|#
directive|define
name|TXEXCESSDEF
value|0x16C
end_define

begin_define
define|#
directive|define
name|TXPAUSEFRAMES
value|0x170
end_define

begin_define
define|#
directive|define
name|TXVLANFRAMES_G
value|0x174
end_define

begin_define
define|#
directive|define
name|TXOVERSIZE_G
value|0x178
end_define

begin_define
define|#
directive|define
name|RXFRAMECOUNT_GB
value|0x180
end_define

begin_define
define|#
directive|define
name|RXOCTETCOUNT_GB
value|0x184
end_define

begin_define
define|#
directive|define
name|RXOCTETCOUNT_G
value|0x188
end_define

begin_define
define|#
directive|define
name|RXBROADCASTFRAMES_G
value|0x18C
end_define

begin_define
define|#
directive|define
name|RXMULTICASTFRAMES_G
value|0x190
end_define

begin_define
define|#
directive|define
name|RXCRCERROR
value|0x194
end_define

begin_define
define|#
directive|define
name|RXALIGNMENTERROR
value|0x198
end_define

begin_define
define|#
directive|define
name|RXRUNTERROR
value|0x19C
end_define

begin_define
define|#
directive|define
name|RXJABBERERROR
value|0x1A0
end_define

begin_define
define|#
directive|define
name|RXUNDERSIZE_G
value|0x1A4
end_define

begin_define
define|#
directive|define
name|RXOVERSIZE_G
value|0x1A8
end_define

begin_define
define|#
directive|define
name|RX64OCTETS_GB
value|0x1AC
end_define

begin_define
define|#
directive|define
name|RX65TO127OCTETS_GB
value|0x1B0
end_define

begin_define
define|#
directive|define
name|RX128TO255OCTETS_GB
value|0x1B4
end_define

begin_define
define|#
directive|define
name|RX256TO511OCTETS_GB
value|0x1B8
end_define

begin_define
define|#
directive|define
name|RX512TO1023OCTETS_GB
value|0x1BC
end_define

begin_define
define|#
directive|define
name|RX1024TOMAXOCTETS_GB
value|0x1C0
end_define

begin_define
define|#
directive|define
name|RXUNICASTFRAMES_G
value|0x1C4
end_define

begin_define
define|#
directive|define
name|RXLENGTHERROR
value|0x1C8
end_define

begin_define
define|#
directive|define
name|RXOUTOFRANGETYPE
value|0x1CC
end_define

begin_define
define|#
directive|define
name|RXPAUSEFRAMES
value|0x1D0
end_define

begin_define
define|#
directive|define
name|RXFIFOOVERFLOW
value|0x1D4
end_define

begin_define
define|#
directive|define
name|RXVLANFRAMES_GB
value|0x1D8
end_define

begin_define
define|#
directive|define
name|RXWATCHDOGERROR
value|0x1DC
end_define

begin_define
define|#
directive|define
name|RXRCVERROR
value|0x1E0
end_define

begin_define
define|#
directive|define
name|RXCTRLFRAMES_G
value|0x1E4
end_define

begin_define
define|#
directive|define
name|MMC_IPC_RECEIVE_INT_MASK
value|0x200
end_define

begin_define
define|#
directive|define
name|MMC_IPC_RECEIVE_INT
value|0x208
end_define

begin_define
define|#
directive|define
name|RXIPV4_GD_FRMS
value|0x210
end_define

begin_define
define|#
directive|define
name|RXIPV4_HDRERR_FRMS
value|0x214
end_define

begin_define
define|#
directive|define
name|RXIPV4_NOPAY_FRMS
value|0x218
end_define

begin_define
define|#
directive|define
name|RXIPV4_FRAG_FRMS
value|0x21C
end_define

begin_define
define|#
directive|define
name|RXIPV4_UDSBL_FRMS
value|0x220
end_define

begin_define
define|#
directive|define
name|RXIPV6_GD_FRMS
value|0x224
end_define

begin_define
define|#
directive|define
name|RXIPV6_HDRERR_FRMS
value|0x228
end_define

begin_define
define|#
directive|define
name|RXIPV6_NOPAY_FRMS
value|0x22C
end_define

begin_define
define|#
directive|define
name|RXUDP_GD_FRMS
value|0x230
end_define

begin_define
define|#
directive|define
name|RXUDP_ERR_FRMS
value|0x234
end_define

begin_define
define|#
directive|define
name|RXTCP_GD_FRMS
value|0x238
end_define

begin_define
define|#
directive|define
name|RXTCP_ERR_FRMS
value|0x23C
end_define

begin_define
define|#
directive|define
name|RXICMP_GD_FRMS
value|0x240
end_define

begin_define
define|#
directive|define
name|RXICMP_ERR_FRMS
value|0x244
end_define

begin_define
define|#
directive|define
name|RXIPV4_GD_OCTETS
value|0x250
end_define

begin_define
define|#
directive|define
name|RXIPV4_HDRERR_OCTETS
value|0x254
end_define

begin_define
define|#
directive|define
name|RXIPV4_NOPAY_OCTETS
value|0x258
end_define

begin_define
define|#
directive|define
name|RXIPV4_FRAG_OCTETS
value|0x25C
end_define

begin_define
define|#
directive|define
name|RXIPV4_UDSBL_OCTETS
value|0x260
end_define

begin_define
define|#
directive|define
name|RXIPV6_GD_OCTETS
value|0x264
end_define

begin_define
define|#
directive|define
name|RXIPV6_HDRERR_OCTETS
value|0x268
end_define

begin_define
define|#
directive|define
name|RXIPV6_NOPAY_OCTETS
value|0x26C
end_define

begin_define
define|#
directive|define
name|RXUDP_GD_OCTETS
value|0x270
end_define

begin_define
define|#
directive|define
name|RXUDP_ERR_OCTETS
value|0x274
end_define

begin_define
define|#
directive|define
name|RXTCP_GD_OCTETS
value|0x278
end_define

begin_define
define|#
directive|define
name|RXTCPERROCTETS
value|0x27C
end_define

begin_define
define|#
directive|define
name|RXICMP_GD_OCTETS
value|0x280
end_define

begin_define
define|#
directive|define
name|RXICMP_ERR_OCTETS
value|0x284
end_define

begin_define
define|#
directive|define
name|L3_L4_CONTROL0
value|0x400
end_define

begin_define
define|#
directive|define
name|LAYER4_ADDRESS0
value|0x404
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR0_REG0
value|0x410
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR1_REG0
value|0x414
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR2_REG0
value|0x418
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR3_REG0
value|0x41C
end_define

begin_define
define|#
directive|define
name|L3_L4_CONTROL1
value|0x430
end_define

begin_define
define|#
directive|define
name|LAYER4_ADDRESS1
value|0x434
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR0_REG1
value|0x440
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR1_REG1
value|0x444
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR2_REG1
value|0x448
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR3_REG1
value|0x44C
end_define

begin_define
define|#
directive|define
name|L3_L4_CONTROL2
value|0x460
end_define

begin_define
define|#
directive|define
name|LAYER4_ADDRESS2
value|0x464
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR0_REG2
value|0x470
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR1_REG2
value|0x474
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR2_REG2
value|0x478
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR3_REG2
value|0x47C
end_define

begin_define
define|#
directive|define
name|L3_L4_CONTROL3
value|0x490
end_define

begin_define
define|#
directive|define
name|LAYER4_ADDRESS3
value|0x494
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR0_REG3
value|0x4A0
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR1_REG3
value|0x4A4
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR2_REG3
value|0x4A8
end_define

begin_define
define|#
directive|define
name|LAYER3_ADDR3_REG3
value|0x4AC
end_define

begin_define
define|#
directive|define
name|HASH_TABLE_REG
parameter_list|(
name|n
parameter_list|)
value|0x500 + (0x4 * n)
end_define

begin_define
define|#
directive|define
name|VLAN_INCL_REG
value|0x584
end_define

begin_define
define|#
directive|define
name|VLAN_HASH_TABLE_REG
value|0x588
end_define

begin_define
define|#
directive|define
name|TIMESTAMP_CONTROL
value|0x700
end_define

begin_define
define|#
directive|define
name|SUB_SECOND_INCREMENT
value|0x704
end_define

begin_define
define|#
directive|define
name|SYSTEM_TIME_SECONDS
value|0x708
end_define

begin_define
define|#
directive|define
name|SYSTEM_TIME_NANOSECONDS
value|0x70C
end_define

begin_define
define|#
directive|define
name|SYSTEM_TIME_SECONDS_UPDATE
value|0x710
end_define

begin_define
define|#
directive|define
name|SYSTEM_TIME_NANOSECONDS_UPDATE
value|0x714
end_define

begin_define
define|#
directive|define
name|TIMESTAMP_ADDEND
value|0x718
end_define

begin_define
define|#
directive|define
name|TARGET_TIME_SECONDS
value|0x71C
end_define

begin_define
define|#
directive|define
name|TARGET_TIME_NANOSECONDS
value|0x720
end_define

begin_define
define|#
directive|define
name|SYSTEM_TIME_HIGHER_WORD_SECONDS
value|0x724
end_define

begin_define
define|#
directive|define
name|TIMESTAMP_STATUS
value|0x728
end_define

begin_define
define|#
directive|define
name|PPS_CONTROL
value|0x72C
end_define

begin_define
define|#
directive|define
name|AUXILIARY_TIMESTAMP_NANOSECONDS
value|0x730
end_define

begin_define
define|#
directive|define
name|AUXILIARY_TIMESTAMP_SECONDS
value|0x734
end_define

begin_define
define|#
directive|define
name|PPS0_INTERVAL
value|0x760
end_define

begin_define
define|#
directive|define
name|PPS0_WIDTH
value|0x764
end_define

begin_comment
comment|/* DMA */
end_comment

begin_define
define|#
directive|define
name|BUS_MODE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BUS_MODE_EIGHTXPBL
value|(1<< 24)
end_define

begin_comment
comment|/* Multiplies PBL by 8 */
end_comment

begin_define
define|#
directive|define
name|BUS_MODE_PBL_SHIFT
value|8
end_define

begin_comment
comment|/* Single block transfer size */
end_comment

begin_define
define|#
directive|define
name|BUS_MODE_PBL_BEATS_8
value|8
end_define

begin_define
define|#
directive|define
name|BUS_MODE_SWR
value|(1<< 0)
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|TRANSMIT_POLL_DEMAND
value|0x1004
end_define

begin_define
define|#
directive|define
name|RECEIVE_POLL_DEMAND
value|0x1008
end_define

begin_define
define|#
directive|define
name|RX_DESCR_LIST_ADDR
value|0x100C
end_define

begin_define
define|#
directive|define
name|TX_DESCR_LIST_ADDR
value|0x1010
end_define

begin_define
define|#
directive|define
name|DMA_STATUS
value|0x1014
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_NIS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_AIS
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FBI
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_RI
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_TI
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_INTR_MASK
value|0x1ffff
end_define

begin_define
define|#
directive|define
name|OPERATION_MODE
value|0x1018
end_define

begin_define
define|#
directive|define
name|MODE_RSF
value|(1<< 25)
end_define

begin_comment
comment|/* RX Full Frame */
end_comment

begin_define
define|#
directive|define
name|MODE_TSF
value|(1<< 21)
end_define

begin_comment
comment|/* TX Full Frame */
end_comment

begin_define
define|#
directive|define
name|MODE_FTF
value|(1<< 20)
end_define

begin_comment
comment|/* Flush TX FIFO */
end_comment

begin_define
define|#
directive|define
name|MODE_ST
value|(1<< 13)
end_define

begin_comment
comment|/* Start DMA TX */
end_comment

begin_define
define|#
directive|define
name|MODE_FUF
value|(1<< 6)
end_define

begin_comment
comment|/* TX frames< 64bytes */
end_comment

begin_define
define|#
directive|define
name|MODE_RTC_LEV32
value|0x1
end_define

begin_define
define|#
directive|define
name|MODE_RTC_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MODE_OSF
value|(1<< 2)
end_define

begin_comment
comment|/* Process Second frame */
end_comment

begin_define
define|#
directive|define
name|MODE_SR
value|(1<< 1)
end_define

begin_comment
comment|/* Start DMA RX */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_ENABLE
value|0x101C
end_define

begin_define
define|#
directive|define
name|INT_EN_NIE
value|(1<< 16)
end_define

begin_comment
comment|/* Normal/Summary */
end_comment

begin_define
define|#
directive|define
name|INT_EN_AIE
value|(1<< 15)
end_define

begin_comment
comment|/* Abnormal/Summary */
end_comment

begin_define
define|#
directive|define
name|INT_EN_ERE
value|(1<< 14)
end_define

begin_comment
comment|/* Early receive */
end_comment

begin_define
define|#
directive|define
name|INT_EN_FBE
value|(1<< 13)
end_define

begin_comment
comment|/* Fatal bus error */
end_comment

begin_define
define|#
directive|define
name|INT_EN_ETE
value|(1<< 10)
end_define

begin_comment
comment|/* Early transmit */
end_comment

begin_define
define|#
directive|define
name|INT_EN_RWE
value|(1<< 9)
end_define

begin_comment
comment|/* Receive watchdog */
end_comment

begin_define
define|#
directive|define
name|INT_EN_RSE
value|(1<< 8)
end_define

begin_comment
comment|/* Receive stopped */
end_comment

begin_define
define|#
directive|define
name|INT_EN_RUE
value|(1<< 7)
end_define

begin_comment
comment|/* Recv buf unavailable */
end_comment

begin_define
define|#
directive|define
name|INT_EN_RIE
value|(1<< 6)
end_define

begin_comment
comment|/* Receive interrupt */
end_comment

begin_define
define|#
directive|define
name|INT_EN_UNE
value|(1<< 5)
end_define

begin_comment
comment|/* Tx underflow */
end_comment

begin_define
define|#
directive|define
name|INT_EN_OVE
value|(1<< 4)
end_define

begin_comment
comment|/* Receive overflow */
end_comment

begin_define
define|#
directive|define
name|INT_EN_TJE
value|(1<< 3)
end_define

begin_comment
comment|/* Transmit jabber */
end_comment

begin_define
define|#
directive|define
name|INT_EN_TUE
value|(1<< 2)
end_define

begin_comment
comment|/* Tx. buf unavailable */
end_comment

begin_define
define|#
directive|define
name|INT_EN_TSE
value|(1<< 1)
end_define

begin_comment
comment|/* Transmit stopped */
end_comment

begin_define
define|#
directive|define
name|INT_EN_TIE
value|(1<< 0)
end_define

begin_comment
comment|/* Transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|INT_EN_DEFAULT
value|(INT_EN_TIE|INT_EN_RIE|	\ 	    INT_EN_NIE|INT_EN_AIE|			\ 	    INT_EN_FBE|INT_EN_UNE)
end_define

begin_define
define|#
directive|define
name|MISSED_FRAMEBUF_OVERFLOW_CNTR
value|0x1020
end_define

begin_define
define|#
directive|define
name|RECEIVE_INT_WATCHDOG_TMR
value|0x1024
end_define

begin_define
define|#
directive|define
name|AXI_BUS_MODE
value|0x1028
end_define

begin_define
define|#
directive|define
name|AHB_OR_AXI_STATUS
value|0x102C
end_define

begin_define
define|#
directive|define
name|CURRENT_HOST_TRANSMIT_DESCR
value|0x1048
end_define

begin_define
define|#
directive|define
name|CURRENT_HOST_RECEIVE_DESCR
value|0x104C
end_define

begin_define
define|#
directive|define
name|CURRENT_HOST_TRANSMIT_BUF_ADDR
value|0x1050
end_define

begin_define
define|#
directive|define
name|CURRENT_HOST_RECEIVE_BUF_ADDR
value|0x1054
end_define

begin_define
define|#
directive|define
name|HW_FEATURE
value|0x1058
end_define

end_unit

