begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Stanislav Sedov<stas@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Master configuration register  */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_REG
value|0x1400
end_define

begin_define
define|#
directive|define
name|AE_MASTER_SOFT_RESET
value|0x1
end_define

begin_comment
comment|/* Reset adapter. */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_MTIMER_EN
value|0x2
end_define

begin_comment
comment|/* Unknown. */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_IMT_EN
value|0x4
end_define

begin_comment
comment|/* Interrupt moderation timer enable. */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_MANUAL_INT
value|0x8
end_define

begin_comment
comment|/* Software manual interrupt. */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_REVNUM_SHIFT
value|16
end_define

begin_comment
comment|/* Chip revision number. */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_REVNUM_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AE_MASTER_DEVID_SHIFT
value|24
end_define

begin_comment
comment|/* PCI device id. */
end_comment

begin_define
define|#
directive|define
name|AE_MASTER_DEVID_MASK
value|0xff
end_define

begin_comment
comment|/*  * Interrupt status register  */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_REG
value|0x1600
end_define

begin_define
define|#
directive|define
name|AE_ISR_TIMER
value|0x00000001
end_define

begin_comment
comment|/* Counter expired. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_MANUAL
value|0x00000002
end_define

begin_comment
comment|/* Manual interrupt occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_RXF_OVERFLOW
value|0x00000004
end_define

begin_comment
comment|/* RxF overflow occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_TXF_UNDERRUN
value|0x00000008
end_define

begin_comment
comment|/* TxF underrun occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_TXS_OVERFLOW
value|0x00000010
end_define

begin_comment
comment|/* TxS overflow occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_RXS_OVERFLOW
value|0x00000020
end_define

begin_comment
comment|/* Internal RxS ring overflow. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_LINK_CHG
value|0x00000040
end_define

begin_comment
comment|/* Link state changed. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_TXD_UNDERRUN
value|0x00000080
end_define

begin_comment
comment|/* TxD underrun occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_RXD_OVERFLOW
value|0x00000100
end_define

begin_comment
comment|/* RxD overflow occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_DMAR_TIMEOUT
value|0x00000200
end_define

begin_comment
comment|/* DMA read timeout. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_DMAW_TIMEOUT
value|0x00000400
end_define

begin_comment
comment|/* DMA write timeout. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_PHY
value|0x00000800
end_define

begin_comment
comment|/* PHY interrupt. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_TXS_UPDATED
value|0x00010000
end_define

begin_comment
comment|/* Tx status updated. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_RXD_UPDATED
value|0x00020000
end_define

begin_comment
comment|/* Rx status updated. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_TX_EARLY
value|0x00040000
end_define

begin_comment
comment|/* TxMAC started transmit. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_FIFO_UNDERRUN
value|0x01000000
end_define

begin_comment
comment|/* FIFO underrun. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_FRAME_ERROR
value|0x02000000
end_define

begin_comment
comment|/* Frame receive error. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_FRAME_SUCCESS
value|0x04000000
end_define

begin_comment
comment|/* Frame receive success. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_CRC_ERROR
value|0x08000000
end_define

begin_comment
comment|/* CRC error occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_PHY_LINKDOWN
value|0x10000000
end_define

begin_comment
comment|/* PHY link down. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_DISABLE
value|0x80000000
end_define

begin_comment
comment|/* Disable interrupts. */
end_comment

begin_define
define|#
directive|define
name|AE_ISR_TX_EVENT
value|(AE_ISR_TXF_UNDERRUN | AE_ISR_TXS_OVERFLOW | \ 				 AE_ISR_TXD_UNDERRUN | AE_ISR_TXS_UPDATED | \ 				 AE_ISR_TX_EARLY)
end_define

begin_define
define|#
directive|define
name|AE_ISR_RX_EVENT
value|(AE_ISR_RXF_OVERFLOW | AE_ISR_RXS_OVERFLOW | \ 				 AE_ISR_RXD_OVERFLOW | AE_ISR_RXD_UPDATED)
end_define

begin_comment
comment|/* Interrupt mask register. */
end_comment

begin_define
define|#
directive|define
name|AE_IMR_REG
value|0x1604
end_define

begin_define
define|#
directive|define
name|AE_IMR_DEFAULT
value|(AE_ISR_DMAR_TIMEOUT | AE_ISR_DMAW_TIMEOUT | \ 				 AE_ISR_PHY_LINKDOWN | \ 				 AE_ISR_TXS_UPDATED | AE_ISR_RXD_UPDATED )
end_define

begin_comment
comment|/*  * Ethernet address register.  */
end_comment

begin_define
define|#
directive|define
name|AE_EADDR0_REG
value|0x1488
end_define

begin_comment
comment|/* 5 - 2 bytes */
end_comment

begin_define
define|#
directive|define
name|AE_EADDR1_REG
value|0x148c
end_define

begin_comment
comment|/* 1 - 0 bytes */
end_comment

begin_comment
comment|/*  * Desriptor rings registers.  * L2 supports 64-bit addressing but all rings base addresses  * should have the same high 32 bits of address.  */
end_comment

begin_define
define|#
directive|define
name|AE_DESC_ADDR_HI_REG
value|0x1540
end_define

begin_comment
comment|/* High 32 bits of ring base address. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_ADDR_LO_REG
value|0x1554
end_define

begin_comment
comment|/* Low 32 bits of RxD ring address. */
end_comment

begin_define
define|#
directive|define
name|AE_TXD_ADDR_LO_REG
value|0x1544
end_define

begin_comment
comment|/* Low 32 bits of TxD ring address. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_ADDR_LO_REG
value|0x154c
end_define

begin_comment
comment|/* Low 32 bits of TxS ring address. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_COUNT_REG
value|0x1558
end_define

begin_comment
comment|/* Number of RxD descriptors in ring. 					   Should be 120-byte aligned (i.e. 					   the 'data' field of RxD should 					   have 128-byte alignment). */
end_comment

begin_define
define|#
directive|define
name|AE_TXD_BUFSIZE_REG
value|0x1548
end_define

begin_comment
comment|/* Size of TxD ring in 4-byte units. 					   Should be 4-byte aligned. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_COUNT_REG
value|0x1550
end_define

begin_comment
comment|/* Number of TxS descriptors in ring. 					   4 byte alignment. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_COUNT_MIN
value|16
end_define

begin_define
define|#
directive|define
name|AE_RXD_COUNT_MAX
value|512
end_define

begin_define
define|#
directive|define
name|AE_RXD_COUNT_DEFAULT
value|64
end_define

begin_comment
comment|/* Padding to align frames on a 128-byte boundary. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_PADDING
value|120
end_define

begin_define
define|#
directive|define
name|AE_TXD_BUFSIZE_MIN
value|4096
end_define

begin_define
define|#
directive|define
name|AE_TXD_BUFSIZE_MAX
value|65536
end_define

begin_define
define|#
directive|define
name|AE_TXD_BUFSIZE_DEFAULT
value|8192
end_define

begin_define
define|#
directive|define
name|AE_TXS_COUNT_MIN
value|8
end_define

begin_comment
comment|/* Not sure. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_COUNT_MAX
value|160
end_define

begin_define
define|#
directive|define
name|AE_TXS_COUNT_DEFAULT
value|64
end_define

begin_comment
comment|/* AE_TXD_BUFSIZE_DEFAULT / 128 */
end_comment

begin_comment
comment|/*  * Inter-frame gap configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_IFG_REG
value|0x1484
end_define

begin_define
define|#
directive|define
name|AE_IFG_TXIPG_DEFAULT
value|0x60
end_define

begin_comment
comment|/* 96-bit IFG time. */
end_comment

begin_define
define|#
directive|define
name|AE_IFG_TXIPG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AE_IFG_TXIPG_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|AE_IFG_RXIPG_DEFAULT
value|0x50
end_define

begin_comment
comment|/* 80-bit IFG time. */
end_comment

begin_define
define|#
directive|define
name|AE_IFG_RXIPG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AE_IFG_RXIPG_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|AE_IFG_IPGR1_DEFAULT
value|0x40
end_define

begin_comment
comment|/* Carrier-sense window. */
end_comment

begin_define
define|#
directive|define
name|AE_IFG_IPGR1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AE_IFG_IPGR1_MASK
value|0x7f0000
end_define

begin_define
define|#
directive|define
name|AE_IFG_IPGR2_DEFAULT
value|0x60
end_define

begin_comment
comment|/* IFG window. */
end_comment

begin_define
define|#
directive|define
name|AE_IFG_IPGR2_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AE_IFG_IPGR2_MASK
value|0x7f000000
end_define

begin_comment
comment|/*  * Half-duplex mode configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_REG
value|0x1498
end_define

begin_comment
comment|/* Collision window. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_LCOL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AE_HDPX_LCOL_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|AE_HDPX_LCOL_DEFAULT
value|0x37
end_define

begin_comment
comment|/* Max retransmission time, after that the packet will be discarded. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_RETRY_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AE_HDPX_RETRY_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|AE_HDPX_RETRY_DEFAULT
value|0x0f
end_define

begin_comment
comment|/* Alternative binary exponential back-off time. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_ABEBT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|AE_HDPX_ABEBT_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|AE_HDPX_ABEBT_DEFAULT
value|0x0a
end_define

begin_comment
comment|/* IFG to start JAM for collision based flow control (8-bit time units).*/
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_JAMIPG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AE_HDPX_JAMIPG_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|AE_HDPX_JAMIPG_DEFAULT
value|0x07
end_define

begin_comment
comment|/* Allow the transmission of a packet which has been excessively deferred. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_EXC_EN
value|0x00010000
end_define

begin_comment
comment|/* No back-off on collision, immediately start the retransmission. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_NO_BACK_C
value|0x00020000
end_define

begin_comment
comment|/* No back-off on backpressure, immediately start the transmission. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_NO_BACK_P
value|0x00040000
end_define

begin_comment
comment|/* Alternative binary exponential back-off enable. */
end_comment

begin_define
define|#
directive|define
name|AE_HDPX_ABEBE
value|0x00080000
end_define

begin_comment
comment|/*  * Interrupt moderation timer configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_IMT_REG
value|0x1408
end_define

begin_comment
comment|/* Timer value in 2 us units. */
end_comment

begin_define
define|#
directive|define
name|AE_IMT_MAX
value|65000
end_define

begin_define
define|#
directive|define
name|AE_IMT_MIN
value|50
end_define

begin_define
define|#
directive|define
name|AE_IMT_DEFAULT
value|100
end_define

begin_comment
comment|/* 200 microseconds. */
end_comment

begin_comment
comment|/*  * Interrupt clearing timer configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_ICT_REG
value|0x140e
end_define

begin_comment
comment|/* Maximum time allowed to clear 					   interrupt. In 2 us units.  */
end_comment

begin_define
define|#
directive|define
name|AE_ICT_DEFAULT
value|50000
end_define

begin_comment
comment|/* 100ms */
end_comment

begin_comment
comment|/*  * MTU configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_MTU_REG
value|0x149c
end_define

begin_comment
comment|/* MTU size in bytes. */
end_comment

begin_comment
comment|/*  * Cut-through configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_CUT_THRESH_REG
value|0x1590
end_define

begin_comment
comment|/* Cut-through threshold in unknown units. */
end_comment

begin_define
define|#
directive|define
name|AE_CUT_THRESH_DEFAULT
value|0x177
end_define

begin_comment
comment|/*  * Flow-control configuration registers.  */
end_comment

begin_define
define|#
directive|define
name|AE_FLOW_THRESH_HI_REG
value|0x15a8
end_define

begin_comment
comment|/* High watermark of RxD 					   overflow threshold. */
end_comment

begin_define
define|#
directive|define
name|AE_FLOW_THRESH_LO_REG
value|0x15aa
end_define

begin_comment
comment|/* Lower watermark of RxD 					   overflow threshold */
end_comment

begin_comment
comment|/*  * Mailbox configuration registers. */
end_comment

begin_define
define|#
directive|define
name|AE_MB_TXD_IDX_REG
value|0x15f0
end_define

begin_comment
comment|/* TxD read index. */
end_comment

begin_define
define|#
directive|define
name|AE_MB_RXD_IDX_REG
value|0x15f4
end_define

begin_comment
comment|/* RxD write index. */
end_comment

begin_comment
comment|/*  * DMA configuration registers.  */
end_comment

begin_define
define|#
directive|define
name|AE_DMAREAD_REG
value|0x1580
end_define

begin_comment
comment|/* Read DMA configuration register. */
end_comment

begin_define
define|#
directive|define
name|AE_DMAREAD_EN
value|1
end_define

begin_define
define|#
directive|define
name|AE_DMAWRITE_REG
value|0x15a0
end_define

begin_comment
comment|/* Write DMA configuration register. */
end_comment

begin_define
define|#
directive|define
name|AE_DMAWRITE_EN
value|1
end_define

begin_comment
comment|/*  * MAC configuration register.  */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_REG
value|0x1480
end_define

begin_define
define|#
directive|define
name|AE_MAC_TX_EN
value|0x00000001
end_define

begin_comment
comment|/* Enable transmit. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_RX_EN
value|0x00000002
end_define

begin_comment
comment|/* Enable receive. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_TX_FLOW_EN
value|0x00000004
end_define

begin_comment
comment|/* Enable Tx flow control. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_RX_FLOW_EN
value|0x00000008
end_define

begin_comment
comment|/* Enable Rx flow control. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_LOOPBACK
value|0x00000010
end_define

begin_comment
comment|/* Loopback at MII. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_FULL_DUPLEX
value|0x00000020
end_define

begin_comment
comment|/* Enable full-duplex. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_TX_CRC_EN
value|0x00000040
end_define

begin_comment
comment|/* Enable CRC generation. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_TX_AUTOPAD
value|0x00000080
end_define

begin_comment
comment|/* Pad short frames. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_PREAMBLE_MASK
value|0x00003c00
end_define

begin_comment
comment|/* Preamble length. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_PREAMBLE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AE_MAC_PREAMBLE_DEFAULT
value|0x07
end_define

begin_comment
comment|/* By standard. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_RMVLAN_EN
value|0x00004000
end_define

begin_comment
comment|/* Remove VLAN tags in 						   incoming packets. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_PROMISC_EN
value|0x00008000
end_define

begin_comment
comment|/* Enable promiscue mode. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_TX_MAXBACKOFF
value|0x00100000
end_define

begin_comment
comment|/* Unknown. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_MCAST_EN
value|0x02000000
end_define

begin_comment
comment|/* Pass all multicast frames. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_BCAST_EN
value|0x04000000
end_define

begin_comment
comment|/* Pass all broadcast frames. */
end_comment

begin_define
define|#
directive|define
name|AE_MAC_CLK_PHY
value|0x08000000
end_define

begin_comment
comment|/* If 1 uses loopback clock 						   PHY, if 0 - system clock. */
end_comment

begin_define
define|#
directive|define
name|AE_HALFBUF_MASK
value|0xf0000000
end_define

begin_comment
comment|/* Half-duplex retry buffer. */
end_comment

begin_define
define|#
directive|define
name|AE_HALFBUF_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|AE_HALFBUF_DEFAULT
value|2
end_define

begin_comment
comment|/* XXX: From Linux. */
end_comment

begin_comment
comment|/*  * MDIO control register.  */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_REG
value|0x1414
end_define

begin_define
define|#
directive|define
name|AE_MDIO_DATA_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|AE_MDIO_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AE_MDIO_REGADDR_MASK
value|0x1f0000
end_define

begin_define
define|#
directive|define
name|AE_MDIO_REGADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AE_MDIO_READ
value|0x00200000
end_define

begin_comment
comment|/* Read operation. */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_SUP_PREAMBLE
value|0x00400000
end_define

begin_comment
comment|/* Suppress preamble. */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_START
value|0x00800000
end_define

begin_comment
comment|/* Initiate MDIO transfer. */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_CLK_SHIFT
value|24
end_define

begin_comment
comment|/* Clock selection. */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_CLK_MASK
value|0x07000000
end_define

begin_comment
comment|/* Clock selection. */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_4
value|0
end_define

begin_comment
comment|/* Dividers? */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_6
value|2
end_define

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_8
value|3
end_define

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_10
value|4
end_define

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_14
value|5
end_define

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_20
value|6
end_define

begin_define
define|#
directive|define
name|AE_MDIO_CLK_25_28
value|7
end_define

begin_define
define|#
directive|define
name|AE_MDIO_BUSY
value|0x08000000
end_define

begin_comment
comment|/* MDIO is busy. */
end_comment

begin_comment
comment|/*  * Idle status register.  */
end_comment

begin_define
define|#
directive|define
name|AE_IDLE_REG
value|0x1410
end_define

begin_comment
comment|/*  * Idle status bits.  * If bit is set then the corresponding module is in non-idle state.  */
end_comment

begin_define
define|#
directive|define
name|AE_IDLE_RXMAC
value|1
end_define

begin_define
define|#
directive|define
name|AE_IDLE_TXMAC
value|2
end_define

begin_define
define|#
directive|define
name|AE_IDLE_DMAREAD
value|8
end_define

begin_define
define|#
directive|define
name|AE_IDLE_DMAWRITE
value|4
end_define

begin_comment
comment|/*  * Multicast hash tables registers.  */
end_comment

begin_define
define|#
directive|define
name|AE_REG_MHT0
value|0x1490
end_define

begin_define
define|#
directive|define
name|AE_REG_MHT1
value|0x1494
end_define

begin_comment
comment|/*  * Wake on lan (WOL).  */
end_comment

begin_define
define|#
directive|define
name|AE_WOL_REG
value|0x14a0
end_define

begin_define
define|#
directive|define
name|AE_WOL_MAGIC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AE_WOL_MAGIC_PME
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AE_WOL_LNKCHG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AE_WOL_LNKCHG_PME
value|0x00000020
end_define

begin_comment
comment|/*  * PCIE configuration registers. Descriptions unknown.  */
end_comment

begin_define
define|#
directive|define
name|AE_PCIE_LTSSM_TESTMODE_REG
value|0x12fc
end_define

begin_define
define|#
directive|define
name|AE_PCIE_LTSSM_TESTMODE_DEFAULT
value|0x6500
end_define

begin_define
define|#
directive|define
name|AE_PCIE_DLL_TX_CTRL_REG
value|0x1104
end_define

begin_define
define|#
directive|define
name|AE_PCIE_DLL_TX_CTRL_SEL_NOR_CLK
value|0x0400
end_define

begin_define
define|#
directive|define
name|AE_PCIE_DLL_TX_CTRL_DEFAULT
value|0x0568
end_define

begin_define
define|#
directive|define
name|AE_PCIE_PHYMISC_REG
value|0x1000
end_define

begin_define
define|#
directive|define
name|AE_PCIE_PHYMISC_FORCE_RCV_DET
value|0x4
end_define

begin_comment
comment|/*  * PHY enable register.  */
end_comment

begin_define
define|#
directive|define
name|AE_PHY_ENABLE_REG
value|0x140c
end_define

begin_define
define|#
directive|define
name|AE_PHY_ENABLE
value|1
end_define

begin_comment
comment|/*  * VPD registers.  */
end_comment

begin_define
define|#
directive|define
name|AE_VPD_CAP_REG
value|0x6c
end_define

begin_comment
comment|/* Command register. */
end_comment

begin_define
define|#
directive|define
name|AE_VPD_CAP_ID_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AE_VPD_CAP_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AE_VPD_CAP_NEXT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|AE_VPD_CAP_NEXT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AE_VPD_CAP_ADDR_MASK
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|AE_VPD_CAP_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AE_VPD_CAP_DONE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AE_VPD_DATA_REG
value|0x70
end_define

begin_comment
comment|/* Data register. */
end_comment

begin_define
define|#
directive|define
name|AE_VPD_NREGS
value|64
end_define

begin_comment
comment|/* Maximum number of VPD regs. */
end_comment

begin_define
define|#
directive|define
name|AE_VPD_SIG_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AE_VPD_SIG
value|0x5a
end_define

begin_comment
comment|/* VPD block signature. */
end_comment

begin_define
define|#
directive|define
name|AE_VPD_REG_SHIFT
value|16
end_define

begin_comment
comment|/* Register id offset. */
end_comment

begin_comment
comment|/*  * SPI registers.  */
end_comment

begin_define
define|#
directive|define
name|AE_SPICTL_REG
value|0x200
end_define

begin_define
define|#
directive|define
name|AE_SPICTL_VPD_EN
value|0x2000
end_define

begin_comment
comment|/* Enable VPD. */
end_comment

begin_comment
comment|/*  * PHY-specific registers constants.  */
end_comment

begin_define
define|#
directive|define
name|AE_PHY_DBG_ADDR
value|0x1d
end_define

begin_define
define|#
directive|define
name|AE_PHY_DBG_DATA
value|0x1e
end_define

begin_define
define|#
directive|define
name|AE_PHY_DBG_POWERSAVE
value|0x1000
end_define

begin_comment
comment|/*  * TxD flags.  */
end_comment

begin_define
define|#
directive|define
name|AE_TXD_INSERT_VTAG
value|0x8000
end_define

begin_comment
comment|/* Insert VLAN tag on transfer. */
end_comment

begin_comment
comment|/*  * TxS flags.  */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_SUCCESS
value|0x0001
end_define

begin_comment
comment|/* Packed transmitted successfully. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_BCAST
value|0x0002
end_define

begin_comment
comment|/* Transmitted broadcast frame. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_MCAST
value|0x0004
end_define

begin_comment
comment|/* Transmitted multicast frame. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_PAUSE
value|0x0008
end_define

begin_comment
comment|/* Transmitted pause frame. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_CTRL
value|0x0010
end_define

begin_comment
comment|/* Transmitted control frame. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_DEFER
value|0x0020
end_define

begin_comment
comment|/* Frame transmitted with defer. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_EXCDEFER
value|0x0040
end_define

begin_comment
comment|/* Excessive collision. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_SINGLECOL
value|0x0080
end_define

begin_comment
comment|/* Single collision occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_MULTICOL
value|0x0100
end_define

begin_comment
comment|/* Multiple collisions occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_LATECOL
value|0x0200
end_define

begin_comment
comment|/* Late collision occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_ABORTCOL
value|0x0400
end_define

begin_comment
comment|/* Frame abort due to collisions. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_UNDERRUN
value|0x0800
end_define

begin_comment
comment|/* Tx SRAM underrun occuried. */
end_comment

begin_define
define|#
directive|define
name|AE_TXS_UPDATE
value|0x8000
end_define

begin_comment
comment|/*  * RxD flags.  */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_SUCCESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|AE_RXD_BCAST
value|0x0002
end_define

begin_comment
comment|/* Broadcast frame received. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_MCAST
value|0x0004
end_define

begin_comment
comment|/* Multicast frame received. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_PAUSE
value|0x0008
end_define

begin_comment
comment|/* Pause frame received. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_CTRL
value|0x0010
end_define

begin_comment
comment|/* Control frame received. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_CRCERR
value|0x0020
end_define

begin_comment
comment|/* Invalid frame CRC. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_CODEERR
value|0x0040
end_define

begin_comment
comment|/* Invalid frame opcode. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_RUNT
value|0x0080
end_define

begin_comment
comment|/* Runt frame received. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_FRAG
value|0x0100
end_define

begin_comment
comment|/* Collision fragment received. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_TRUNC
value|0x0200
end_define

begin_comment
comment|/* The frame was truncated due 					   to Rx SRAM underrun. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_ALIGN
value|0x0400
end_define

begin_comment
comment|/* Frame alignment error. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_HAS_VLAN
value|0x0800
end_define

begin_comment
comment|/* VLAN tag present. */
end_comment

begin_define
define|#
directive|define
name|AE_RXD_UPDATE
value|0x8000
end_define

end_unit

