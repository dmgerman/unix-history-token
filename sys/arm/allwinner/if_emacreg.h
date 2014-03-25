begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_EMACREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_EMACREG_H__
end_define

begin_comment
comment|/*  * EMAC register definitions  */
end_comment

begin_define
define|#
directive|define
name|EMAC_CTL
value|0x00
end_define

begin_define
define|#
directive|define
name|EMAC_CTL_RST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_CTL_TX_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EMAC_CTL_RX_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE
value|0x04
end_define

begin_define
define|#
directive|define
name|EMAC_TX_FLOW
value|0x08
end_define

begin_define
define|#
directive|define
name|EMAC_TX_CTL0
value|0x0C
end_define

begin_define
define|#
directive|define
name|EMAC_TX_CTL1
value|0x10
end_define

begin_define
define|#
directive|define
name|EMAC_TX_INS
value|0x14
end_define

begin_define
define|#
directive|define
name|EMAC_TX_PL0
value|0x18
end_define

begin_define
define|#
directive|define
name|EMAC_TX_PL1
value|0x1C
end_define

begin_define
define|#
directive|define
name|EMAC_TX_STA
value|0x20
end_define

begin_define
define|#
directive|define
name|EMAC_TX_IO_DATA
value|0x24
end_define

begin_define
define|#
directive|define
name|EMAC_TX_IO_DATA1
value|0x28
end_define

begin_define
define|#
directive|define
name|EMAC_TX_TSVL0
value|0x2C
end_define

begin_define
define|#
directive|define
name|EMAC_TX_TSVH0
value|0x30
end_define

begin_define
define|#
directive|define
name|EMAC_TX_TSVL1
value|0x34
end_define

begin_define
define|#
directive|define
name|EMAC_TX_TSVH1
value|0x38
end_define

begin_define
define|#
directive|define
name|EMAC_RX_CTL
value|0x3C
end_define

begin_define
define|#
directive|define
name|EMAC_RX_HASH0
value|0x40
end_define

begin_define
define|#
directive|define
name|EMAC_RX_HASH1
value|0x44
end_define

begin_define
define|#
directive|define
name|EMAC_RX_STA
value|0x48
end_define

begin_define
define|#
directive|define
name|EMAC_RX_IO_DATA
value|0x4C
end_define

begin_define
define|#
directive|define
name|EMAC_RX_FBC
value|0x50
end_define

begin_define
define|#
directive|define
name|EMAC_INT_CTL
value|0x54
end_define

begin_define
define|#
directive|define
name|EMAC_INT_STA
value|0x58
end_define

begin_define
define|#
directive|define
name|EMAC_INT_STA_TX
value|(0x01 | 0x02)
end_define

begin_define
define|#
directive|define
name|EMAC_INT_STA_RX
value|0x100
end_define

begin_define
define|#
directive|define
name|EMAC_INT_EN
value|(0xf<< 0) | (1<< 8)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL0
value|0x5C
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1
value|0x60
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_IPGT
value|0x64
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_IPGR
value|0x68
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CLRT
value|0x6C
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MAXF
value|0x70
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_SUPP
value|0x74
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_TEST
value|0x78
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MCFG
value|0x7C
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MCMD
value|0x80
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MADR
value|0x84
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MWTD
value|0x88
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MRDD
value|0x8C
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MIND
value|0x90
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_SSRR
value|0x94
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_A0
value|0x98
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_A1
value|0x9C
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_A2
value|0xA0
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_L0
value|0xA4
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_H0
value|0xA8
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_L1
value|0xAC
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_H1
value|0xB0
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_L2
value|0xB4
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_H2
value|0xB8
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_L3
value|0xBC
end_define

begin_define
define|#
directive|define
name|EMAC_SAFX_H3
value|0xC0
end_define

begin_define
define|#
directive|define
name|EMAC_PHY_DUPLEX
value|(1<< 8)
end_define

begin_comment
comment|/*  * Each received packet has 8 bytes header:  * Byte 0: Packet valid flag: 0x01 valid, 0x00 not valid  * Byte 1: 0x43 -> Ascii code 'C'  * Byte 2: 0x41 -> Ascii code 'A'  * Byte 3: 0x4d -> Ascii code 'M'  * Byte 4: High byte of received packet's status  * Byte 5: Low byte of received packet's status  * Byte 6: High byte of packet size  * Byte 7: Low byte of packet size  */
end_comment

begin_define
define|#
directive|define
name|EMAC_PACKET_HEADER
value|(0x0143414d)
end_define

begin_comment
comment|/* Aborted frame enable */
end_comment

begin_define
define|#
directive|define
name|EMAC_TX_AB_M
value|(1<< 0)
end_define

begin_comment
comment|/* 0: Enable CPU mode for TX, 1: DMA */
end_comment

begin_define
define|#
directive|define
name|EMAC_TX_TM
value|~(1<< 1)
end_define

begin_comment
comment|/* 0: DRQ asserted, 1: DRQ automatically */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_DRQ_MODE
value|(1<< 1)
end_define

begin_comment
comment|/* 0: Enable CPU mode for RX, 1: DMA */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_TM
value|~(1<< 2)
end_define

begin_comment
comment|/* Pass all Frames */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_PA
value|(1<< 4)
end_define

begin_comment
comment|/* Pass Control Frames */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_PCF
value|(1<< 5)
end_define

begin_comment
comment|/* Pass Frames with CRC Error */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_PCRCE
value|(1<< 6)
end_define

begin_comment
comment|/* Pass Frames with Length Error */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_PLE
value|(1<< 7)
end_define

begin_comment
comment|/* Pass Frames length out of range */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_POR
value|(1<< 8)
end_define

begin_comment
comment|/* Accept unicast Packets */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_UCAD
value|(1<< 16)
end_define

begin_comment
comment|/* Enable DA Filtering */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_DAF
value|(1<< 17)
end_define

begin_comment
comment|/* Accept multicast Packets */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_MCO
value|(1<< 20)
end_define

begin_comment
comment|/* Enable Hash filter */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_MHF
value|(1<< 21)
end_define

begin_comment
comment|/* Accept Broadcast Packets */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_BCO
value|(1<< 22)
end_define

begin_comment
comment|/* Enable SA Filtering */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_SAF
value|(1<< 24)
end_define

begin_comment
comment|/* Inverse Filtering */
end_comment

begin_define
define|#
directive|define
name|EMAC_RX_SAIF
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_SETUP
value|(EMAC_RX_POR | EMAC_RX_UCAD | \     EMAC_RX_DAF | EMAC_RX_MCO | EMAC_RX_BCO)
end_define

begin_comment
comment|/* Enable Receive Flow Control */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL0_RFC
value|(1<< 2)
end_define

begin_comment
comment|/* Enable Transmit Flow Control */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL0_TFC
value|(1<< 3)
end_define

begin_comment
comment|/* Enable soft reset */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL0_SOFT_RST
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL0_SETUP
value|(EMAC_MAC_CTL0_RFC | EMAC_MAC_CTL0_TFC)
end_define

begin_comment
comment|/* Enable duplex */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_DUP
value|(1<< 0)
end_define

begin_comment
comment|/* Enable MAC Frame Length Checking */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_FLC
value|(1<< 1)
end_define

begin_comment
comment|/* Enable Huge Frame */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_HF
value|(1<< 2)
end_define

begin_comment
comment|/* Enable MAC Delayed CRC */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_DCRC
value|(1<< 3)
end_define

begin_comment
comment|/* Enable MAC CRC */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_CRC
value|(1<< 4)
end_define

begin_comment
comment|/* Enable MAC PAD Short frames */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_PC
value|(1<< 5)
end_define

begin_comment
comment|/* Enable MAC PAD Short frames and append CRC */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_VC
value|(1<< 6)
end_define

begin_comment
comment|/* Enable MAC auto detect Short frames */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_ADP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_PRE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_LPE
value|(1<< 9)
end_define

begin_comment
comment|/* Enable no back off */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_NB
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_BNB
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_ED
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CTL1_SETUP
value|(EMAC_MAC_CTL1_FLC | EMAC_MAC_CTL1_CRC | \     EMAC_MAC_CTL1_PC)
end_define

begin_comment
comment|/* half duplex */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_IPGT_HD
value|0x12
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAC_IPGT_FD
value|0x15
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_NBTB_IPG1
value|0xC
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_NBTB_IPG2
value|0x12
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_CW
value|0x37
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_RM
value|0xF
end_define

begin_define
define|#
directive|define
name|EMAC_MAC_MFL
value|0x0600
end_define

begin_comment
comment|/* Receive status */
end_comment

begin_define
define|#
directive|define
name|EMAC_CRCERR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|EMAC_LENERR
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_FLUSH_FIFO
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|EMAC_PHY_RESET
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|EMAC_PHY_PWRDOWN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|EMAC_PROC_MIN
value|16
end_define

begin_define
define|#
directive|define
name|EMAC_PROC_MAX
value|255
end_define

begin_define
define|#
directive|define
name|EMAC_PROC_DEFAULT
value|64
end_define

begin_define
define|#
directive|define
name|EMAC_LOCK
parameter_list|(
name|cs
parameter_list|)
value|mtx_lock(&(sc)->emac_mtx)
end_define

begin_define
define|#
directive|define
name|EMAC_UNLOCK
parameter_list|(
name|cs
parameter_list|)
value|mtx_unlock(&(sc)->emac_mtx)
end_define

begin_define
define|#
directive|define
name|EMAC_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->emac_mtx, MA_OWNED);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_EMACREG_H__ */
end_comment

end_unit

