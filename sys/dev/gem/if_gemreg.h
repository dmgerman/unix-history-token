begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 Eduardo Horvath.  * All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: gemreg.h,v 1.2 2001/10/18 03:33:33 thorpej Exp  *  * $FreeBSD$  */
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
comment|/* Register definitions for Sun GEM gigabit ethernet */
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
comment|/* Note: Reading the status reg clears bits 0-6 */
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
comment|/* This is the same as the GEM_STATUS reg but reading it does not clear bits. */
end_comment

begin_define
define|#
directive|define
name|GEM_ERROR_STATUS
value|0x1000
end_define

begin_comment
comment|/* PCI error status R/C */
end_comment

begin_define
define|#
directive|define
name|GEM_ERROR_MASK
value|0x1004
end_define

begin_define
define|#
directive|define
name|GEM_BIF_CONFIG
value|0x1008
end_define

begin_comment
comment|/* BIF config reg */
end_comment

begin_define
define|#
directive|define
name|GEM_BIF_DIAG
value|0x100c
end_define

begin_define
define|#
directive|define
name|GEM_RESET
value|0x1010
end_define

begin_comment
comment|/* Software reset register */
end_comment

begin_comment
comment|/* Bits in GEM_SEB register */
end_comment

begin_define
define|#
directive|define
name|GEM_SEB_ARB
value|0x000000002
end_define

begin_comment
comment|/* Arbitration status */
end_comment

begin_define
define|#
directive|define
name|GEM_SEB_RXWON
value|0x000000004
end_define

begin_comment
comment|/* Bits in GEM_CONFIG register */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_BURST_64
value|0x000000000
end_define

begin_comment
comment|/* 0->infininte, 1->64KB */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_BURST_INF
value|0x000000001
end_define

begin_comment
comment|/* 0->infininte, 1->64KB */
end_comment

begin_define
define|#
directive|define
name|GEM_CONFIG_TXDMA_LIMIT
value|0x00000003e
end_define

begin_define
define|#
directive|define
name|GEM_CONFIG_RXDMA_LIMIT
value|0x0000007c0
end_define

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
name|GEM_STATUS_TX_COMPL
value|0xfff800000
end_define

begin_comment
comment|/* TX completion reg. */
end_comment

begin_comment
comment|/* Interrupt bits, for both the GEM_STATUS and GEM_INTMASK regs. */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_INTME
value|0x000000001
end_define

begin_comment
comment|/* Frame w/INTME bit set sent */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_EMPTY
value|0x000000002
end_define

begin_comment
comment|/* TX ring empty */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_TX_DONE
value|0x000000004
end_define

begin_comment
comment|/* TX complete */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_RX_DONE
value|0x000000010
end_define

begin_comment
comment|/* Got a packet */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_RX_NOBUF
value|0x000000020
end_define

begin_define
define|#
directive|define
name|GEM_INTR_RX_TAG_ERR
value|0x000000040
end_define

begin_define
define|#
directive|define
name|GEM_INTR_PCS
value|0x000002000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_TX_MAC
value|0x000004000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_RX_MAC
value|0x000008000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_MAC_CONTROL
value|0x000010000
end_define

begin_comment
comment|/* MAC control interrupt */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_MIF
value|0x000020000
end_define

begin_define
define|#
directive|define
name|GEM_INTR_BERR
value|0x000040000
end_define

begin_comment
comment|/* Bus error interrupt */
end_comment

begin_define
define|#
directive|define
name|GEM_INTR_BITS
value|"\177\020"					\ 			"b\0INTME\0b\1TXEMPTY\0b\2TXDONE\0"		\ 			"b\4RXDONE\0b\5RXNOBUF\0b\6RX_TAG_ERR\0"	\ 			"b\15PCS\0b\16TXMAC\0b\17RXMAC\0"		\ 			"b\20MAC_CONTROL\0b\21MIF\0b\22BERR\0\0"
end_define

begin_comment
unit|\
comment|/* GEM_ERROR_STATUS and GEM_ERROR_MASK PCI error bits */
end_comment

begin_define
define|#
directive|define
name|GEM_ERROR_STAT_BADACK
value|0x000000001
end_define

begin_comment
comment|/* No ACK64# */
end_comment

begin_define
define|#
directive|define
name|GEM_ERROR_STAT_DTRTO
value|0x000000002
end_define

begin_comment
comment|/* Delayed xaction timeout */
end_comment

begin_define
define|#
directive|define
name|GEM_ERROR_STAT_OTHERS
value|0x000000004
end_define

begin_comment
comment|/* GEM_BIF_CONFIG register bits */
end_comment

begin_define
define|#
directive|define
name|GEM_BIF_CONFIG_SLOWCLK
value|0x000000001
end_define

begin_comment
comment|/* Parity error timing */
end_comment

begin_define
define|#
directive|define
name|GEM_BIF_CONFIG_HOST_64
value|0x000000002
end_define

begin_comment
comment|/* 64-bit host */
end_comment

begin_define
define|#
directive|define
name|GEM_BIF_CONFIG_B64D_DIS
value|0x000000004
end_define

begin_comment
comment|/* no 64-bit data cycle */
end_comment

begin_define
define|#
directive|define
name|GEM_BIF_CONFIG_M66EN
value|0x000000008
end_define

begin_comment
comment|/* GEM_RESET register bits -- TX and RX self clear when complete. */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET_TX
value|0x000000001
end_define

begin_comment
comment|/* Reset TX half */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET_RX
value|0x000000002
end_define

begin_comment
comment|/* Reset RX half */
end_comment

begin_define
define|#
directive|define
name|GEM_RESET_RSTOUT
value|0x000000004
end_define

begin_comment
comment|/* Force PCI RSTOUT# */
end_comment

begin_comment
comment|/* GEM TX DMA registers */
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
comment|/* GEM_TX_CONFIG register bits. */
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
comment|/* GEM RX DMA registers */
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
comment|/* GEM_RX_CONFIG register bits. */
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
comment|/* checksum start offset */
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
value|0x07fc0000
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
value|0x03fc0000
end_define

begin_comment
comment|/* Delay intr for x ticks */
end_comment

begin_comment
comment|/* One tick is 1048 PCI clocs, or 16us at 66MHz */
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
comment|/* MAC sstate machine reg */
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
name|GEM_MAC_PAUSE_TIME
value|0xffff0000
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
name|GEM_MAC_XIF_MII_MODE
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
comment|/* ignore collitions */
end_comment

begin_define
define|#
directive|define
name|GEM_MAC_TX_ENA_IPG0
value|0x00000008
end_define

begin_comment
comment|/* extend Rx-to-TX IPG */
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
comment|/* Carrier Extension is required for half duplex Gbps operation */
end_comment

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

begin_comment
comment|/* GEM MIF registers */
end_comment

begin_comment
comment|/* Bit bang registers use low bit only */
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
name|GEM_MIF_INTERRUPT_MASK
value|0x6214
end_define

begin_define
define|#
directive|define
name|GEM_MIF_BASIC_STATUS
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
comment|/* TA bit, 1 for completion */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_FRAME_TA1
value|0x00020000
end_define

begin_comment
comment|/* TA bits */
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
comment|/* phy address, should be 0 */
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
comment|/* PHY select */
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
comment|/* MDIO_0 Data/MDIO_0 atached */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_CONFIG_MDI1
value|0x00000200
end_define

begin_comment
comment|/* MDIO_1 Data/MDIO_1 atached */
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
comment|/* MDI0 is onboard tranciever MID1 is external, PHYAD for both is 0 */
end_comment

begin_comment
comment|/* GEM_MIF_BASIC_STATUS and GEM_MIF_INTERRUPT_MASK bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MIF_STATUS
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GEM_MIF_BASIC
value|0xffff0000
end_define

begin_comment
comment|/*  * The Basic part is the last value read in the POLL field of the config  * register.  *  * The status part indicates the bits that have changed.  */
end_comment

begin_comment
comment|/* The GEM PCS/Serial link register. */
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
comment|/* LP ability reg */
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
comment|/* serial link status */
end_comment

begin_comment
comment|/* GEM_MII_CONTROL bits */
end_comment

begin_comment
comment|/*  * DO NOT TOUCH THIS REGISTER ON ERI -- IT HARD HANGS.  */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_RESET
value|0x00008000
end_define

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
name|GEM_MII_CONTROL_1000M
value|0x00002000
end_define

begin_comment
comment|/* speed select, always 0 */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_AUTONEG
value|0x00001000
end_define

begin_comment
comment|/* auto negotiation enabled */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_POWERDN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_ISOLATE
value|0x00000400
end_define

begin_comment
comment|/* isolate phy from mii */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_RAN
value|0x00000200
end_define

begin_comment
comment|/* restart auto negotioation */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONTROL_FDUPLEX
value|0x00000100
end_define

begin_comment
comment|/* full duplex, always 0 */
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

begin_comment
comment|/* GEM_MII_STATUS reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_GB_FDX
value|0x00000400
end_define

begin_comment
comment|/* can perform GBit FDX */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_GB_HDX
value|0x00000200
end_define

begin_comment
comment|/* can perform GBit HDX */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_ANEG_CPT
value|0x00000020
end_define

begin_comment
comment|/* auto negotiate compete */
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
name|GEM_MII_STATUS_ACFG
value|0x00000008
end_define

begin_comment
comment|/* can auto negotiate */
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
name|GEM_MII_STATUS_JABBER
value|0x00000002
end_define

begin_comment
comment|/* jabber condition detected */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_STATUS_EXTCAP
value|0x00000001
end_define

begin_comment
comment|/* extended register capability */
end_comment

begin_comment
comment|/* GEM_MII_ANAR and GEM_MII_ANLAR reg bits */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_NP
value|0x00008000
end_define

begin_comment
comment|/* next page bit */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_ACK
value|0x00004000
end_define

begin_comment
comment|/* ack reception of */
end_comment

begin_comment
comment|/* Link Partner Capability */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_RF
value|0x00003000
end_define

begin_comment
comment|/* advertise remote fault cap */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_ASYM_PAUSE
value|0x00000100
end_define

begin_comment
comment|/* asymmetric pause */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_SYM_PAUSE
value|0x00000080
end_define

begin_comment
comment|/* symmetric pause */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_ANEG_HLF_DUPLX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GEM_MII_ANEG_FUL_DUPLX
value|0x00000020
end_define

begin_comment
comment|/* GEM_MII_CONFIG reg */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_TIMER
value|0x0000001c
end_define

begin_comment
comment|/* link monitor timer values */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_CONFIG_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable PCS */
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
comment|/* Serial link */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_SERDES
value|0x00000002
end_define

begin_comment
comment|/* Use PCS via 10bit interfac */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_MII
value|0x00000004
end_define

begin_comment
comment|/* Use MII, not PCS */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_DATAPATH_MIIOUT
value|0x00000008
end_define

begin_comment
comment|/* enable serial output on GMII */
end_comment

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
comment|/* enable loopback at sl */
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
comment|/* lock reference clock */
end_comment

begin_define
define|#
directive|define
name|GEM_MII_SLINK_EMPHASIS
value|0x00000008
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

begin_define
define|#
directive|define
name|GEM_MII_SLINK_POWER_OFF
value|0x00000200
end_define

begin_comment
comment|/* Power down serial link */
end_comment

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
comment|/* waiting 500us lockrefn */
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
comment|/* Wired GEM PHY addresses */
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
comment|/*  * GEM descriptor table structures.  */
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
value|0x0000000000007fffLL
end_define

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_START
value|0x00000000001f8000LL
end_define

begin_comment
comment|/* Cxsum start offset */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_STUFF
value|0x000000001fe00000LL
end_define

begin_comment
comment|/* Cxsum stuff offset */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_CXSUM_ENABLE
value|0x0000000020000000LL
end_define

begin_comment
comment|/* Cxsum generation enable */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_END_OF_PACKET
value|0x0000000040000000LL
end_define

begin_define
define|#
directive|define
name|GEM_TD_START_OF_PACKET
value|0x0000000080000000LL
end_define

begin_define
define|#
directive|define
name|GEM_TD_INTERRUPT_ME
value|0x0000000100000000LL
end_define

begin_comment
comment|/* Interrupt me now */
end_comment

begin_define
define|#
directive|define
name|GEM_TD_NO_CRC
value|0x0000000200000000LL
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
value|0x000000000000ffffLL
end_define

begin_define
define|#
directive|define
name|GEM_RD_BUFSIZE
value|0x000000007fff0000LL
end_define

begin_define
define|#
directive|define
name|GEM_RD_OWN
value|0x0000000080000000LL
end_define

begin_comment
comment|/* 1 - owned by h/w */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_HASHVAL
value|0x0ffff00000000000LL
end_define

begin_define
define|#
directive|define
name|GEM_RD_HASH_PASS
value|0x1000000000000000LL
end_define

begin_comment
comment|/* passed hash filter */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_ALTERNATE_MAC
value|0x2000000000000000LL
end_define

begin_comment
comment|/* Alternate MAC adrs */
end_comment

begin_define
define|#
directive|define
name|GEM_RD_BAD_CRC
value|0x4000000000000000LL
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
value|(((x)&GEM_RD_BUFSIZE)>>GEM_RD_BUFSHIFT)
end_define

begin_comment
comment|/* PCI support */
end_comment

begin_define
define|#
directive|define
name|PCI_GEM_BASEADDR
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

