begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2001 Eduardo Horvath.  * All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: gemreg.h,v 1.9 2006/11/24 13:01:07 martin Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_GEMREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_GEMREG_H
end_define

begin_comment
comment|/* register definitions for Apple GMAC, Sun ERI and Sun GEM */
end_comment

begin_comment
comment|/*  * First bank: this registers live at the start of the PCI  * mapping, and at the start of the second bank of the SBus  * version.  */
end_comment

begin_define
define|#
directive|define
name|GEM_SEB_STATE
value|0x0000
end_define

begin_comment
comment|/* SEB state reg, R/O */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG
value|0x0004
end_define

begin_comment
comment|/* config reg */
end_comment

begin_define
define|#
directive|define
name|GEM_STATUS
value|0x000c
end_define

begin_comment
comment|/* status reg */
end_comment

begin_comment
comment|/* Note: Reading the status reg clears bits 0-6. */
end_comment

begin_define
define|#
directive|define
name|GEM_INTMASK
value|0x0010
end_define

begin_define
define|#
directive|define
name|GEM_INTACK
value|0x0014
end_define

begin_comment
comment|/* Interrupt acknowledge, W/O */
end_comment

begin_define
define|#
directive|define
name|GEM_STATUS_ALIAS
value|0x001c
end_define

begin_comment
comment|/* Bits in GEM_SEB register */
end_comment

begin_define
define|#
directive|define
name|GEM_SEB_ARB
value|0x00000002
end_define

begin_comment
comment|/* Arbitration status */
end_comment

begin_define
define|#
directive|define
name|GEM_SEB_RXWON
value|0x00000004
end_define

begin_comment
comment|/* Bits in GEM_CONFIG register */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_BURST_64
value|0x00000000
end_define

begin_comment
comment|/* maximum burst size 64KB */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_BURST_INF
value|0x00000001
end_define

begin_comment
comment|/* infinite for entire packet */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_TXDMA_LIMIT
value|0x0000003e
end_define

begin_define
define|#
directive|define
name|GEM_CONFIG_RXDMA_LIMIT
value|0x000007c0
end_define

begin_comment
comment|/* GEM_CONFIG_RONPAULBIT and GEM_CONFIG_BUG2FIX are Apple only. */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_RONPAULBIT
value|0x00000800
end_define

begin_comment
comment|/* after infinite burst use */
end_comment

begin_comment
comment|/* memory read multiple for */
end_comment

begin_comment
comment|/* PCI commands */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_BUG2FIX
value|0x00001000
end_define

begin_comment
comment|/* fix RX hang after overflow */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_TXDMA_LIMIT_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|GEM_CONFIG_RXDMA_LIMIT_SHIFT
value|6
end_define

begin_comment
comment|/* Top part of GEM_STATUS has TX completion information */
end_comment

begin_define
define|#
directive|define
name|GEM_STATUS_TX_COMPLETION_MASK
value|0xfff80000
end_define

begin_comment
comment|/* TX completion reg. */
end_comment

begin_define
define|#
directive|define
name|GEM_STATUS_TX_COMPLETION_SHFT
value|19
end_define

begin_comment
comment|/*  * Interrupt bits, for both the GEM_STATUS and GEM_INTMASK regs  * Bits 0-6 auto-clear when read.  */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_INTME
value|0x00000001
end_define

begin_comment
comment|/* Frame w/INTME bit set sent */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_EMPTY
value|0x00000002
end_define

begin_comment
comment|/* TX ring empty */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_DONE
value|0x00000004
end_define

begin_comment
comment|/* TX complete */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_RX_DONE
value|0x00000010
end_define

begin_comment
comment|/* Got a packet */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_RX_NOBUF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GEM_INTR_RX_TAG_ERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GEM_INTR_PERR
value|0x00000080
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_PCS
value|0x00002000
end_define

begin_comment
comment|/* Physical Code Sub-layer */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_MAC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_RX_MAC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_MAC_CONTROL
value|0x00010000
end_define

begin_comment
comment|/* MAC control interrupt */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_MIF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_BERR
value|0x00040000
end_define

begin_comment
comment|/* Bus error interrupt */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_BITS
value|"\177\020"					\ 			"b\0INTME\0b\1TXEMPTY\0b\2TXDONE\0"		\ 			"b\4RXDONE\0b\5RXNOBUF\0b\6RX_TAG_ERR\0"	\ 			"b\xdPCS\0b\xeTXMAC\0b\xfRXMAC\0"		\ 			"b\x10MAC_CONTROL\0b\x11MIF\0b\x12IBERR\0\0"
end_define

begin_comment
comment|/*  * Second bank: this registers live at offset 0x1000 of the PCI  * mapping, and at the start of the first bank of the SBus  * version.  */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BANK2_OFFSET
value|0x1000
end_define

begin_define
define|#
directive|define
name|GEM_PCI_BANK2_SIZE
value|0x14
end_define

begin_comment
comment|/* This is the same as the GEM_STATUS reg but reading it does not clear bits. */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_ERROR_STATUS
value|0x0000
end_define

begin_comment
comment|/* PCI error status */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_ERROR_MASK
value|0x0004
end_define

begin_comment
comment|/* PCI error mask */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BIF_CONFIG
value|0x0008
end_define

begin_comment
comment|/* PCI BIF configuration */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BIF_DIAG
value|0x000c
end_define

begin_comment
comment|/* PCI BIF diagnostic */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_BIF_RESET
value|0x0000
end_define

begin_comment
comment|/* SBus BIF only software reset */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_CONFIG
value|0x0004
end_define

begin_comment
comment|/* SBus IO configuration */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_STATUS
value|0x0008
end_define

begin_comment
comment|/* SBus IO status */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_REVISION
value|0x000c
end_define

begin_comment
comment|/* SBus revision ID */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET
value|0x0010
end_define

begin_comment
comment|/* software reset */
end_comment

begin_comment
comment|/* GEM_PCI_ERROR_STATUS and GEM_PCI_ERROR_MASK error bits */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_ERR_STAT_BADACK
value|0x00000001
end_define

begin_comment
comment|/* No ACK64# */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_ERR_STAT_DTRTO
value|0x00000002
end_define

begin_comment
comment|/* Delayed xaction timeout */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_ERR_STAT_OTHERS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GEM_PCI_ERR_BITS
value|"\177\020b\0ACKBAD\0b\1DTRTO\0b\2OTHER\0\0"
end_define

begin_comment
comment|/* GEM_PCI_BIF_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BIF_CNF_SLOWCLK
value|0x00000001
end_define

begin_comment
comment|/* Parity error timing */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BIF_CNF_HOST_64
value|0x00000002
end_define

begin_comment
comment|/* 64-bit host */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BIF_CNF_B64D_DS
value|0x00000004
end_define

begin_comment
comment|/* no 64-bit data cycle */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_BIF_CNF_M66EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GEM_PCI_BIF_CNF_BITS
value|"\177\020b\0SLOWCLK\0b\1HOST64\0"	\ 				"b\2B64DIS\0b\3M66EN\0\0"
end_define

begin_comment
comment|/* GEM_PCI_BIF_DIAG register bits */
end_comment

begin_define
define|#
directive|define
name|GEN_PCI_BIF_DIAG_BC_SM
value|0x007f0000
end_define

begin_comment
comment|/* burst ctrl. state machine */
end_comment

begin_define
define|#
directive|define
name|GEN_PCI_BIF_DIAG_SM
value|0xff000000
end_define

begin_comment
comment|/* BIF state machine */
end_comment

begin_comment
comment|/* Bits in GEM_SBUS_CONFIG register */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_CFG_BURST_32
value|0x00000001
end_define

begin_comment
comment|/* 32 byte bursts */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_CFG_BURST_64
value|0x00000002
end_define

begin_comment
comment|/* 64 byte bursts */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_CFG_BURST_128
value|0x00000004
end_define

begin_comment
comment|/* 128 byte bursts */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_CFG_64BIT
value|0x00000008
end_define

begin_comment
comment|/* extended transfer mode */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_CFG_PARITY
value|0x00000200
end_define

begin_comment
comment|/* enable parity checking */
end_comment

begin_comment
comment|/* GEM_SBUS_STATUS register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_STATUS_LERR
value|0x00000001
end_define

begin_comment
comment|/* LERR from SBus slave */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_STATUS_SACK
value|0x00000002
end_define

begin_comment
comment|/* size ack. error */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_STATUS_EACK
value|0x00000004
end_define

begin_comment
comment|/* SBus ctrl. or slave error */
end_comment

begin_define
define|#
directive|define
name|GEM_SBUS_STATUS_MPARITY
value|0x00000008
end_define

begin_comment
comment|/* SBus master parity error */
end_comment

begin_comment
comment|/* GEM_RESET register bits -- TX and RX self clear when complete. */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET_TX
value|0x00000001
end_define

begin_comment
comment|/* Reset TX half. */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET_RX
value|0x00000002
end_define

begin_comment
comment|/* Reset RX half. */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET_PCI_RSTOUT
value|0x00000004
end_define

begin_comment
comment|/* Force PCI RSTOUT#. */
end_comment

begin_comment
comment|/* The rest of the registers live in the first bank again. */
end_comment

begin_comment
comment|/* TX DMA registers */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_KICK
value|0x2000
end_define

begin_comment
comment|/* Write last valid desc + 1 */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_CONFIG
value|0x2004
end_define

begin_define
define|#
directive|define
name|GEM_TX_RING_PTR_LO
value|0x2008
end_define

begin_define
define|#
directive|define
name|GEM_TX_RING_PTR_HI
value|0x200c
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_WR_PTR
value|0x2014
end_define

begin_comment
comment|/* FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_FIFO_SDWR_PTR
value|0x2018
end_define

begin_comment
comment|/* FIFO shadow write pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_FIFO_RD_PTR
value|0x201c
end_define

begin_comment
comment|/* FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_FIFO_SDRD_PTR
value|0x2020
end_define

begin_comment
comment|/* FIFO shadow read pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_FIFO_PKT_CNT
value|0x2024
end_define

begin_comment
comment|/* FIFO packet counter */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_STATE_MACHINE
value|0x2028
end_define

begin_comment
comment|/* ETX state machine reg */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_DATA_PTR_LO
value|0x2030
end_define

begin_define
define|#
directive|define
name|GEM_TX_DATA_PTR_HI
value|0x2034
end_define

begin_define
define|#
directive|define
name|GEM_TX_COMPLETION
value|0x2100
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_ADDRESS
value|0x2104
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_TAG
value|0x2108
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_DATA_LO
value|0x210c
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_DATA_HI_T1
value|0x2110
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_DATA_HI_T0
value|0x2114
end_define

begin_define
define|#
directive|define
name|GEM_TX_FIFO_SIZE
value|0x2118
end_define

begin_define
define|#
directive|define
name|GEM_TX_DEBUG
value|0x3028
end_define

begin_comment
comment|/* GEM_TX_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_CONFIG_TXDMA_EN
value|0x00000001
end_define

begin_comment
comment|/* TX DMA enable */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_CONFIG_TXRING_SZ
value|0x0000001e
end_define

begin_comment
comment|/* TX ring size */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_CONFIG_TXFIFO_TH
value|0x001ffc00
end_define

begin_comment
comment|/* TX fifo threshold */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_CONFIG_PACED
value|0x00200000
end_define

begin_comment
comment|/* TX_all_int modifier */
end_comment

begin_define
define|#
directive|define
name|GEM_RING_SZ_32
value|(0<<1)
end_define

begin_comment
comment|/* 32 descriptors */
end_comment

begin_define
define|#
directive|define
name|GEM_RING_SZ_64
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_128
value|(2<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_256
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_512
value|(4<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_1024
value|(5<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_2048
value|(6<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_4096
value|(7<<1)
end_define

begin_define
define|#
directive|define
name|GEM_RING_SZ_8192
value|(8<<1)
end_define

begin_comment
comment|/* GEM_TX_COMPLETION register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_TX_COMPLETION_MASK
value|0x00001fff
end_define

begin_comment
comment|/* # of last descriptor */
end_comment

begin_comment
comment|/* RX DMA registers */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG
value|0x4000
end_define

begin_define
define|#
directive|define
name|GEM_RX_RING_PTR_LO
value|0x4004
end_define

begin_comment
comment|/* 64-bits unaligned GAK! */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_RING_PTR_HI
value|0x4008
end_define

begin_comment
comment|/* 64-bits unaligned GAK! */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_FIFO_WR_PTR
value|0x400c
end_define

begin_comment
comment|/* FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_FIFO_SDWR_PTR
value|0x4010
end_define

begin_comment
comment|/* FIFO shadow write pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_FIFO_RD_PTR
value|0x4014
end_define

begin_comment
comment|/* FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_FIFO_PKT_CNT
value|0x4018
end_define

begin_comment
comment|/* FIFO packet counter */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_STATE_MACHINE
value|0x401c
end_define

begin_comment
comment|/* ERX state machine reg */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_PAUSE_THRESH
value|0x4020
end_define

begin_define
define|#
directive|define
name|GEM_RX_DATA_PTR_LO
value|0x4024
end_define

begin_comment
comment|/* ERX state machine reg */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_DATA_PTR_HI
value|0x4028
end_define

begin_comment
comment|/* Damn thing is unaligned */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_KICK
value|0x4100
end_define

begin_comment
comment|/* Write last valid desc + 1 */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_COMPLETION
value|0x4104
end_define

begin_comment
comment|/* First pending desc */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_BLANKING
value|0x4108
end_define

begin_comment
comment|/* Interrupt blanking reg */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_FIFO_ADDRESS
value|0x410c
end_define

begin_define
define|#
directive|define
name|GEM_RX_FIFO_TAG
value|0x4110
end_define

begin_define
define|#
directive|define
name|GEM_RX_FIFO_DATA_LO
value|0x4114
end_define

begin_define
define|#
directive|define
name|GEM_RX_FIFO_DATA_HI_T1
value|0x4118
end_define

begin_define
define|#
directive|define
name|GEM_RX_FIFO_DATA_HI_T0
value|0x411c
end_define

begin_define
define|#
directive|define
name|GEM_RX_FIFO_SIZE
value|0x4120
end_define

begin_comment
comment|/* GEM_RX_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_RXDMA_EN
value|0x00000001
end_define

begin_comment
comment|/* RX DMA enable */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_RXRING_SZ
value|0x0000001e
end_define

begin_comment
comment|/* RX ring size */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_BATCH_DIS
value|0x00000020
end_define

begin_comment
comment|/* desc batching disable */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_FBOFF
value|0x00001c00
end_define

begin_comment
comment|/* first byte offset */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_CXM_START
value|0x000fe000
end_define

begin_comment
comment|/* cksum start offset bytes */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_FIFO_THRS
value|0x07000000
end_define

begin_comment
comment|/* fifo threshold size */
end_comment

begin_define
define|#
directive|define
name|GEM_THRSH_64
value|0
end_define

begin_define
define|#
directive|define
name|GEM_THRSH_128
value|1
end_define

begin_define
define|#
directive|define
name|GEM_THRSH_256
value|2
end_define

begin_define
define|#
directive|define
name|GEM_THRSH_512
value|3
end_define

begin_define
define|#
directive|define
name|GEM_THRSH_1024
value|4
end_define

begin_define
define|#
directive|define
name|GEM_THRSH_2048
value|5
end_define

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_FIFO_THRS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_FBOFF_SHFT
value|10
end_define

begin_define
define|#
directive|define
name|GEM_RX_CONFIG_CXM_START_SHFT
value|13
end_define

begin_comment
comment|/* GEM_RX_PAUSE_THRESH register bits -- sizes in multiples of 64 bytes */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_PTH_XOFF_THRESH
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|GEM_RX_PTH_XON_THRESH
value|0x001ff000
end_define

begin_comment
comment|/* GEM_RX_BLANKING register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_BLANKING_PACKETS
value|0x000001ff
end_define

begin_comment
comment|/* Delay intr for x packets */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_BLANKING_TIME
value|0x000ff000
end_define

begin_comment
comment|/* Delay intr for x ticks */
end_comment

begin_define
define|#
directive|define
name|GEM_RX_BLANKING_TIME_SHIFT
value|12
end_define

begin_comment
comment|/* One tick is 2048 PCI clocks, or 16us at 66MHz */
end_comment

begin_comment
comment|/* GEM_MAC registers */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TXRESET
value|0x6000
end_define

begin_comment
comment|/* Store 1, cleared when done */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RXRESET
value|0x6004
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_SEND_PAUSE_CMD
value|0x6008
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_STATUS
value|0x6010
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_STATUS
value|0x6014
end_define

begin_define
define|#
directive|define
name|GEM_MAC_CONTROL_STATUS
value|0x6018
end_define

begin_comment
comment|/* MAC control status reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_MASK
value|0x6020
end_define

begin_comment
comment|/* TX MAC mask register */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_MASK
value|0x6024
end_define

begin_define
define|#
directive|define
name|GEM_MAC_CONTROL_MASK
value|0x6028
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_CONFIG
value|0x6030
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_CONFIG
value|0x6034
end_define

begin_define
define|#
directive|define
name|GEM_MAC_CONTROL_CONFIG
value|0x6038
end_define

begin_define
define|#
directive|define
name|GEM_MAC_XIF_CONFIG
value|0x603c
end_define

begin_define
define|#
directive|define
name|GEM_MAC_IPG0
value|0x6040
end_define

begin_comment
comment|/* inter packet gap 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_IPG1
value|0x6044
end_define

begin_comment
comment|/* inter packet gap 1 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_IPG2
value|0x6048
end_define

begin_comment
comment|/* inter packet gap 2 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_SLOT_TIME
value|0x604c
end_define

begin_comment
comment|/* slot time, bits 0-7 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_MAC_MIN_FRAME
value|0x6050
end_define

begin_define
define|#
directive|define
name|GEM_MAC_MAC_MAX_FRAME
value|0x6054
end_define

begin_define
define|#
directive|define
name|GEM_MAC_PREAMBLE_LEN
value|0x6058
end_define

begin_define
define|#
directive|define
name|GEM_MAC_JAM_SIZE
value|0x605c
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ATTEMPT_LIMIT
value|0x6060
end_define

begin_define
define|#
directive|define
name|GEM_MAC_CONTROL_TYPE
value|0x6064
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR0
value|0x6080
end_define

begin_comment
comment|/* Normal MAC address 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_ADDR1
value|0x6084
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR2
value|0x6088
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR3
value|0x608c
end_define

begin_comment
comment|/* Alternate MAC address 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_ADDR4
value|0x6090
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR5
value|0x6094
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR6
value|0x6098
end_define

begin_comment
comment|/* Control MAC address 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_ADDR7
value|0x609c
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR8
value|0x60a0
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR_FILTER0
value|0x60a4
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR_FILTER1
value|0x60a8
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADDR_FILTER2
value|0x60ac
end_define

begin_define
define|#
directive|define
name|GEM_MAC_ADR_FLT_MASK1_2
value|0x60b0
end_define

begin_comment
comment|/* Address filter mask 1,2 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_ADR_FLT_MASK0
value|0x60b4
end_define

begin_comment
comment|/* Address filter mask 0 reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_HASH0
value|0x60c0
end_define

begin_comment
comment|/* Hash table 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_HASH1
value|0x60c4
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH2
value|0x60c8
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH3
value|0x60cc
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH4
value|0x60d0
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH5
value|0x60d4
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH6
value|0x60d8
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH7
value|0x60dc
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH8
value|0x60e0
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH9
value|0x60e4
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH10
value|0x60e8
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH11
value|0x60ec
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH12
value|0x60f0
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH13
value|0x60f4
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH14
value|0x60f8
end_define

begin_define
define|#
directive|define
name|GEM_MAC_HASH15
value|0x60fc
end_define

begin_define
define|#
directive|define
name|GEM_MAC_NORM_COLL_CNT
value|0x6100
end_define

begin_comment
comment|/* Normal collision counter */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_FIRST_COLL_CNT
value|0x6104
end_define

begin_comment
comment|/* 1st successful collision cntr */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_EXCESS_COLL_CNT
value|0x6108
end_define

begin_comment
comment|/* Excess collision counter */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_LATE_COLL_CNT
value|0x610c
end_define

begin_comment
comment|/* Late collision counter */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_DEFER_TMR_CNT
value|0x6110
end_define

begin_comment
comment|/* defer timer counter */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_PEAK_ATTEMPTS
value|0x6114
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_FRAME_COUNT
value|0x6118
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_LEN_ERR_CNT
value|0x611c
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_ALIGN_ERR
value|0x6120
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_CRC_ERR_CNT
value|0x6124
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_CODE_VIOL
value|0x6128
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RANDOM_SEED
value|0x6130
end_define

begin_define
define|#
directive|define
name|GEM_MAC_MAC_STATE
value|0x6134
end_define

begin_comment
comment|/* MAC state machine reg */
end_comment

begin_comment
comment|/* GEM_MAC_SEND_PAUSE_CMD register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_PAUSE_CMD_TIME
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GEM_MAC_PAUSE_CMD_SEND
value|0x00010000
end_define

begin_comment
comment|/* GEM_MAC_TX_STATUS and _MASK register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_XMIT_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_PKT_TOO_LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_NCC_EXP
value|0x00000008
end_define

begin_comment
comment|/* Normal collision cnt exp */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_ECC_EXP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_LCC_EXP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_FCC_EXP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_DEFER_EXP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_PEAK_EXP
value|0x00000100
end_define

begin_comment
comment|/* GEM_MAC_RX_STATUS and _MASK register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_OVERFLOW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_FRAME_CNT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_ALIGN_EXP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_CRC_EXP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_LEN_EXP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_CVI_EXP
value|0x00000040
end_define

begin_comment
comment|/* Code violation */
end_comment

begin_comment
comment|/* GEM_MAC_CONTROL_STATUS and GEM_MAC_CONTROL_MASK register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_PAUSED
value|0x00000001
end_define

begin_comment
comment|/* Pause received */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_PAUSE
value|0x00000002
end_define

begin_comment
comment|/* enter pause state */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RESUME
value|0x00000004
end_define

begin_comment
comment|/* exit pause state */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_PAUSE_TIME_SLTS
value|0xffff0000
end_define

begin_comment
comment|/* pause time in slots */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_STATUS_BITS
value|"\177\020b\0PAUSED\0b\1PAUSE\0b\2RESUME\0\0"
end_define

begin_define
define|#
directive|define
name|GEM_MAC_PAUSE_TIME_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|GEM_MAC_PAUSE_TIME
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GEM_MAC_PAUSE_TIME_SLTS)>> GEM_MAC_PAUSE_TIME_SHFT)
end_define

begin_comment
comment|/* GEM_MAC_XIF_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_TX_MII_ENA
value|0x00000001
end_define

begin_comment
comment|/* Enable XIF output drivers */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_MII_LOOPBK
value|0x00000002
end_define

begin_comment
comment|/* Enable MII loopback mode */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_ECHO_DISABL
value|0x00000004
end_define

begin_comment
comment|/* Disable echo */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_GMII_MODE
value|0x00000008
end_define

begin_comment
comment|/* Select GMII/MII mode */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_MII_BUF_ENA
value|0x00000010
end_define

begin_comment
comment|/* Enable MII recv buffers */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_LINK_LED
value|0x00000020
end_define

begin_comment
comment|/* force link LED active */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_FDPLX_LED
value|0x00000040
end_define

begin_comment
comment|/* force FDPLX LED active */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_XIF_BITS
value|"\177\020b\0TXMIIENA\0b\1MIILOOP\0b\2NOECHO" \ 				"\0b\3GMII\0b\4MIIBUFENA\0b\5LINKLED\0" \ 				"b\6FDLED\0\0"
end_define

begin_comment
comment|/*  * GEM_MAC_SLOT_TIME register  * The slot time is used as PAUSE time unit, value depends on whether carrier  * extension is enabled.  */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_SLOT_TIME_CARR_EXTEND
value|0x200
end_define

begin_define
define|#
directive|define
name|GEM_MAC_SLOT_TIME_NORMAL
value|0x40
end_define

begin_comment
comment|/* GEM_MAC_TX_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* TX enable */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_IGN_CARRIER
value|0x00000002
end_define

begin_comment
comment|/* Ignore carrier sense */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_IGN_COLLIS
value|0x00000004
end_define

begin_comment
comment|/* ignore collisions */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_ENA_IPG0
value|0x00000008
end_define

begin_comment
comment|/* extend RX-to-TX IPG */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_NGU
value|0x00000010
end_define

begin_comment
comment|/* Never give up */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_NGU_LIMIT
value|0x00000020
end_define

begin_comment
comment|/* Never give up limit */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_NO_BACKOFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_SLOWDOWN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GEM_MAC_TX_NO_FCS
value|0x00000100
end_define

begin_comment
comment|/* no FCS will be generated */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_CARR_EXTEND
value|0x00000200
end_define

begin_comment
comment|/* Ena TX Carrier Extension */
end_comment

begin_comment
comment|/* Carrier Extension is required for half duplex Gbps operation. */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_CONFIG_BITS
value|"\177\020" \ 				"b\0TXENA\0b\1IGNCAR\0b\2IGNCOLLIS\0" \ 				"b\3IPG0ENA\0b\4TXNGU\0b\5TXNGULIM\0" \ 				"b\6NOBKOFF\0b\7SLOWDN\0b\x8NOFCS\0" \ 				"b\x9TXCARREXT\0\0"
end_define

begin_comment
comment|/* GEM_MAC_RX_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_STRIP_PAD
value|0x00000002
end_define

begin_comment
comment|/* strip pad bytes */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_STRIP_CRC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GEM_MAC_RX_PROMISCUOUS
value|0x00000008
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_PROMISC_GRP
value|0x00000010
end_define

begin_comment
comment|/* promiscuous group mode */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_HASH_FILTER
value|0x00000020
end_define

begin_comment
comment|/* enable hash filter */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_ADDR_FILTER
value|0x00000040
end_define

begin_comment
comment|/* enable address filter */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_ERRCHK_DIS
value|0x00000080
end_define

begin_comment
comment|/* disable error checking */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_CARR_EXTEND
value|0x00000100
end_define

begin_comment
comment|/* Ena RX Carrier Extension */
end_comment

begin_comment
comment|/*  * Carrier Extension enables reception of packet bursts generated by  * senders with carrier extension enabled.  */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_RX_CONFIG_BITS
value|"\177\020" \ 				"b\0RXENA\0b\1STRPAD\0b\2STRCRC\0" \ 				"b\3PROMIS\0b\4PROMISCGRP\0b\5HASHFLTR\0" \ 				"b\6ADDRFLTR\0b\7ERRCHKDIS\0b\x9TXCARREXT\0\0"
end_define

begin_comment
comment|/* GEM_MAC_CONTROL_CONFIG bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_CC_TX_PAUSE
value|0x00000001
end_define

begin_comment
comment|/* send pause enabled */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_CC_RX_PAUSE
value|0x00000002
end_define

begin_comment
comment|/* receive pause enabled */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_CC_PASS_PAUSE
value|0x00000004
end_define

begin_comment
comment|/* pass pause up */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_CC_BITS
value|"\177\020b\0TXPAUSE\0b\1RXPAUSE\0b\2NOPAUSE\0\0"
end_define

begin_comment
comment|/*  * MIF registers  * Bit bang registers use low bit only.  */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_BB_CLOCK
value|0x6200
end_define

begin_comment
comment|/* bit bang clock */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_BB_DATA
value|0x6204
end_define

begin_comment
comment|/* bit bang data */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_BB_OUTPUT_ENAB
value|0x6208
end_define

begin_define
define|#
directive|define
name|GEM_MIF_FRAME
value|0x620c
end_define

begin_comment
comment|/* MIF frame - ctl and data */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG
value|0x6210
end_define

begin_define
define|#
directive|define
name|GEM_MIF_MASK
value|0x6214
end_define

begin_define
define|#
directive|define
name|GEM_MIF_STATUS
value|0x6218
end_define

begin_define
define|#
directive|define
name|GEM_MIF_STATE_MACHINE
value|0x621c
end_define

begin_comment
comment|/* GEM_MIF_FRAME bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_DATA
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_TA0
value|0x00010000
end_define

begin_comment
comment|/* TA LSB, 1 for completion */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_TA1
value|0x00020000
end_define

begin_comment
comment|/* TA MSB, 1 for instruction */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_REG_ADDR
value|0x007c0000
end_define

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_PHY_ADDR
value|0x0f800000
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_OP
value|0x30000000
end_define

begin_comment
comment|/* operation - write/read */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_START
value|0xc0000000
end_define

begin_comment
comment|/* START bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_READ
value|0x60020000
end_define

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_WRITE
value|0x50020000
end_define

begin_define
define|#
directive|define
name|GEM_MIF_REG_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|GEM_MIF_PHY_SHIFT
value|23
end_define

begin_comment
comment|/* GEM_MIF_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_PHY_SEL
value|0x00000001
end_define

begin_comment
comment|/* PHY select, 0: MDIO_0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_POLL_ENA
value|0x00000002
end_define

begin_comment
comment|/* poll enable */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_BB_ENA
value|0x00000004
end_define

begin_comment
comment|/* bit bang enable */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_REG_ADR
value|0x000000f8
end_define

begin_comment
comment|/* poll register address */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_MDI0
value|0x00000100
end_define

begin_comment
comment|/* MDIO_0 attached/data */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_MDI1
value|0x00000200
end_define

begin_comment
comment|/* MDIO_1 attached/data */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_PHY_ADR
value|0x00007c00
end_define

begin_comment
comment|/* poll PHY address */
end_comment

begin_comment
comment|/* MDI0 is the onboard transceiver, MDI1 is external, PHYAD for both is 0. */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_BITS
value|"\177\020b\0PHYSEL\0b\1POLL\0b\2BBENA\0" \ 				"b\x8MDIO0\0b\x9MDIO1\0\0"
end_define

begin_comment
comment|/* GEM_MIF_STATUS and GEM_MIF_MASK bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_POLL_STATUS_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* polling status */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_POLL_STATUS_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|GEM_MIF_POLL_DATA_MASK
value|0xffff0000
end_define

begin_comment
comment|/* polling data */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_POLL_DATA_SHFT
value|8
end_define

begin_comment
comment|/*  * The Basic part is the last value read in the POLL field of the config  * register.  * The status part indicates the bits that have changed.  */
end_comment

begin_comment
comment|/* GEM PCS/Serial link registers */
end_comment

begin_comment
comment|/* DO NOT TOUCH THESE REGISTERS ON ERI -- IT HARD HANGS. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL
value|0x9000
end_define

begin_define
define|#
directive|define
name|GEM_MII_STATUS
value|0x9004
end_define

begin_define
define|#
directive|define
name|GEM_MII_ANAR
value|0x9008
end_define

begin_comment
comment|/* MII advertisement reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANLPAR
value|0x900c
end_define

begin_comment
comment|/* Link Partner Ability Reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG
value|0x9010
end_define

begin_define
define|#
directive|define
name|GEM_MII_STATE_MACHINE
value|0x9014
end_define

begin_define
define|#
directive|define
name|GEM_MII_INTERRUP_STATUS
value|0x9018
end_define

begin_comment
comment|/* PCS interrupt state */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_MODE
value|0x9050
end_define

begin_define
define|#
directive|define
name|GEM_MII_SLINK_CONTROL
value|0x9054
end_define

begin_comment
comment|/* Serial link control */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_OUTPUT_SELECT
value|0x9058
end_define

begin_define
define|#
directive|define
name|GEM_MII_SLINK_STATUS
value|0x905c
end_define

begin_comment
comment|/* Serialink status */
end_comment

begin_comment
comment|/* GEM_MII_CONTROL bits - PCS "BMCR" (Basic Mode Control Reg) */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_1000M
value|0x00000040
end_define

begin_comment
comment|/* 1000Mbps speed select */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_COL_TST
value|0x00000080
end_define

begin_comment
comment|/* collision test */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_FDUPLEX
value|0x00000100
end_define

begin_comment
comment|/* full-duplex, always 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_RAN
value|0x00000200
end_define

begin_comment
comment|/* restart auto-negotiation */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_ISOLATE
value|0x00000400
end_define

begin_comment
comment|/* isolate PHY from MII */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_POWERDN
value|0x00000800
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_AUTONEG
value|0x00001000
end_define

begin_comment
comment|/* auto-negotiation enable */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_10_100M
value|0x00002000
end_define

begin_comment
comment|/* 10/100Mbps speed select */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_LOOPBK
value|0x00004000
end_define

begin_comment
comment|/* 10-bit i/f loopback */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_RESET
value|0x00008000
end_define

begin_comment
comment|/* Reset PCS. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_BITS
value|"\177\020b\7COLTST\0b\x8_FD\0b\x9RAN\0" \ 				"b\xaISOLATE\0b\xbPWRDWN\0b\xc_ANEG\0" \ 				"b\xdGIGE\0b\xeLOOP\0b\xfRESET\0\0"
end_define

begin_comment
comment|/* GEM_MII_STATUS reg - PCS "BMSR" (Basic Mode Status Reg) */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_EXTCAP
value|0x00000001
end_define

begin_comment
comment|/* extended capability */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_JABBER
value|0x00000002
end_define

begin_comment
comment|/* jabber condition detected */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_LINK_STS
value|0x00000004
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_ACFG
value|0x00000008
end_define

begin_comment
comment|/* can auto-negotiate */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_REM_FLT
value|0x00000010
end_define

begin_comment
comment|/* remote fault detected */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_ANEG_CPT
value|0x00000020
end_define

begin_comment
comment|/* auto-negotiate complete */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_EXTENDED
value|0x00000100
end_define

begin_comment
comment|/* extended status */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_BITS
value|"\177\020b\0EXTCAP\0b\1JABBER\0b\2LINKSTS\0" \ 				"b\3ACFG\0b\4REMFLT\0b\5ANEGCPT\0\0"
end_define

begin_comment
comment|/* GEM_MII_ANAR and GEM_MII_ANLPAR reg bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_FDUPLX
value|0x00000020
end_define

begin_comment
comment|/* full-duplex */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_HDUPLX
value|0x00000040
end_define

begin_comment
comment|/* half-duplex */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_PAUSE
value|0x00000080
end_define

begin_comment
comment|/* symmetric PAUSE */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_ASM_DIR
value|0x00000100
end_define

begin_comment
comment|/* asymmetric PAUSE */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_RFLT_FAIL
value|0x00001000
end_define

begin_comment
comment|/* remote fault - fail */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_RFLT_OFF
value|0x00002000
end_define

begin_comment
comment|/* remote fault - off-line */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_RFLT_MASK
define|\
value|(CAS_PCS_ANEG_RFLT_FAIL | CAS_PCS_ANEG_RFLT_OFF)
end_define

begin_define
define|#
directive|define
name|GEM_MII_ANEG_ACK
value|0x00004000
end_define

begin_comment
comment|/* acknowledge */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_NP
value|0x00008000
end_define

begin_comment
comment|/* next page */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_BITS
value|"\177\020b\5FDX\0b\6HDX\0b\7SYMPAUSE\0" \ 				"\b\x8_ASYMPAUSE\0\b\xdREMFLT\0\b\xeLPACK\0" \ 				"\b\xfNPBIT\0\0"
end_define

begin_comment
comment|/* GEM_MII_CONFIG reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable PCS. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_SDO
value|0x00000002
end_define

begin_comment
comment|/* signal detect override */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_SDL
value|0x00000004
end_define

begin_comment
comment|/* signal detect active-low */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_JS_NORM
value|0x00000000
end_define

begin_comment
comment|/* jitter study - normal op. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_JS_HF
value|0x00000008
end_define

begin_comment
comment|/* jitter study - HF test */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_JS_LF
value|0x00000010
end_define

begin_comment
comment|/* jitter study - LF test */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_JS_MASK
define|\
value|(GEM_MII_CONFIG_JS_HF | GEM_MII_CONFIG_JS_LF)
end_define

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_ANTO
value|0x00000020
end_define

begin_comment
comment|/* auto-neg. timer override */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_BITS
value|"\177\020b\0PCSENA\0\0"
end_define

begin_comment
comment|/*  * GEM_MII_INTERRUP_STATUS reg  * No mask register; mask with the global interrupt mask register.  */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_INTERRUP_LINK
value|0x00000004
end_define

begin_comment
comment|/* PCS link status change */
end_comment

begin_comment
comment|/* GEM_MII_DATAPATH_MODE reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_SERIAL
value|0x00000001
end_define

begin_comment
comment|/* Serialink */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_SERDES
value|0x00000002
end_define

begin_comment
comment|/* SERDES via 10-bit */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_MII
value|0x00000004
end_define

begin_comment
comment|/* GMII/MII */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_GMIIOE
value|0x00000008
end_define

begin_comment
comment|/* serial output on GMII en. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_BITS
value|"\177\020"	\ 				"b\0SERIAL\0b\1SERDES\0b\2MII\0b\3GMIIOE\0\0"
end_define

begin_comment
comment|/* GEM_MII_SLINK_CONTROL reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_LOOPBACK
value|0x00000001
end_define

begin_comment
comment|/* enable loopback at SL, logic 						 * reversed for SERDES */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_EN_SYNC_D
value|0x00000002
end_define

begin_comment
comment|/* enable sync detection */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_LOCK_REF
value|0x00000004
end_define

begin_comment
comment|/* lock to reference clock */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_EMPHASIS
value|0x00000018
end_define

begin_comment
comment|/* enable emphasis */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_SELFTEST
value|0x000001c0
end_define

begin_comment
comment|/* self-test */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_POWER_OFF
value|0x00000200
end_define

begin_comment
comment|/* Power down Serialink. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_RX_ZERO
value|0x00000c00
end_define

begin_comment
comment|/* PLL input to Serialink. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_RX_POLE
value|0x00003000
end_define

begin_comment
comment|/* PLL input to Serialink. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_TX_ZERO
value|0x0000c000
end_define

begin_comment
comment|/* PLL input to Serialink. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_TX_POLE
value|0x00030000
end_define

begin_comment
comment|/* PLL input to Serialink. */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_CONTROL_BITS
define|\
value|"\177\020b\0LOOP\0b\1ENASYNC\0b\2LOCKREF" \ 				"\0b\3EMPHASIS\0b\x9PWRDWN\0\0"
end_define

begin_comment
comment|/* GEM_MII_SLINK_STATUS reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_TEST
value|0x00000000
end_define

begin_comment
comment|/* undergoing test */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_LOCKED
value|0x00000001
end_define

begin_comment
comment|/* waiting 500us w/ lockrefn */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_COMMA
value|0x00000002
end_define

begin_comment
comment|/* waiting for comma detect */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_SYNC
value|0x00000003
end_define

begin_comment
comment|/* recv data synchronized */
end_comment

begin_comment
comment|/*  * PCI Expansion ROM runtime access  * Sun GEMs map a 1MB space for the PCI Expansion ROM as the second half  * of the first register bank, although they only support up to 64KB ROMs.  */
end_comment

begin_define
define|#
directive|define
name|GEM_PCI_ROM_OFFSET
value|0x100000
end_define

begin_define
define|#
directive|define
name|GEM_PCI_ROM_SIZE
value|0x10000
end_define

begin_comment
comment|/* Wired PHY addresses */
end_comment

begin_define
define|#
directive|define
name|GEM_PHYAD_INTERNAL
value|1
end_define

begin_define
define|#
directive|define
name|GEM_PHYAD_EXTERNAL
value|0
end_define

begin_comment
comment|/*  * descriptor table structures  */
end_comment

begin_struct
struct|struct
name|gem_desc
block|{
name|uint64_t
name|gd_flags
decl_stmt|;
name|uint64_t
name|gd_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Transmit flags */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_BUFSIZE
value|0x0000000000007fffULL
end_define

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_START
value|0x00000000001f8000ULL
end_define

begin_comment
comment|/* Cxsum start offset */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_STARTSHFT
value|15
end_define

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_STUFF
value|0x000000001fe00000ULL
end_define

begin_comment
comment|/* Cxsum stuff offset */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_STUFFSHFT
value|21
end_define

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_ENABLE
value|0x0000000020000000ULL
end_define

begin_comment
comment|/* Cxsum generation enable */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_END_OF_PACKET
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|GEM_TD_START_OF_PACKET
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|GEM_TD_INTERRUPT_ME
value|0x0000000100000000ULL
end_define

begin_comment
comment|/* Interrupt me now */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_NO_CRC
value|0x0000000200000000ULL
end_define

begin_comment
comment|/* do not insert crc */
end_comment

begin_comment
comment|/*  * Only need to set GEM_TD_CXSUM_ENABLE, GEM_TD_CXSUM_STUFF,  * GEM_TD_CXSUM_START, and GEM_TD_INTERRUPT_ME in 1st descriptor of a group.  */
end_comment

begin_comment
comment|/* Receive flags */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_CHECKSUM
value|0x000000000000ffffULL
end_define

begin_comment
comment|/* is the complement */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_BUFSIZE
value|0x000000007fff0000ULL
end_define

begin_define
define|#
directive|define
name|GEM_RD_OWN
value|0x0000000080000000ULL
end_define

begin_comment
comment|/* 1 - owned by h/w */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_HASHVAL
value|0x0ffff00000000000ULL
end_define

begin_define
define|#
directive|define
name|GEM_RD_HASH_PASS
value|0x1000000000000000ULL
end_define

begin_comment
comment|/* passed hash filter */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_ALTERNATE_MAC
value|0x2000000000000000ULL
end_define

begin_comment
comment|/* Alternate MAC adrs */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_BAD_CRC
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|GEM_RD_BUFSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GEM_RD_BUFLEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& GEM_RD_BUFSIZE)>> GEM_RD_BUFSHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

