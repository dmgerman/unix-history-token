begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 Sepherosa Ziehau.  All rights reserved.  *  * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $DragonFly: src/sys/dev/netif/et/if_etreg.h,v 1.3 2007/10/23 14:28:42 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ETREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_ETREG_H
end_define

begin_define
define|#
directive|define
name|ET_MEM_TXSIZE_EX
value|182
end_define

begin_define
define|#
directive|define
name|ET_MEM_RXSIZE_MIN
value|608
end_define

begin_define
define|#
directive|define
name|ET_MEM_RXSIZE_DEFAULT
value|11216
end_define

begin_define
define|#
directive|define
name|ET_MEM_SIZE
value|16384
end_define

begin_define
define|#
directive|define
name|ET_MEM_UNIT
value|16
end_define

begin_comment
comment|/*  * PCI registers  *  * ET_PCIV_ACK_LATENCY_{128,256} are from  * PCI EXPRESS BASE SPECIFICATION, REV. 1.0a, Table 3-5  *  * ET_PCIV_REPLAY_TIMER_{128,256} are from  * PCI EXPRESS BASE SPECIFICATION, REV. 1.0a, Table 3-4  */
end_comment

begin_define
define|#
directive|define
name|ET_PCIR_DEVICE_CAPS
value|0x4C
end_define

begin_define
define|#
directive|define
name|ET_PCIM_DEVICE_CAPS_MAX_PLSZ
value|0x7
end_define

begin_comment
comment|/* Max playload size */
end_comment

begin_define
define|#
directive|define
name|ET_PCIV_DEVICE_CAPS_PLSZ_128
value|0x0
end_define

begin_define
define|#
directive|define
name|ET_PCIV_DEVICE_CAPS_PLSZ_256
value|0x1
end_define

begin_define
define|#
directive|define
name|ET_PCIR_DEVICE_CTRL
value|0x50
end_define

begin_define
define|#
directive|define
name|ET_PCIM_DEVICE_CTRL_MAX_RRSZ
value|0x7000
end_define

begin_comment
comment|/* Max read request size */
end_comment

begin_define
define|#
directive|define
name|ET_PCIV_DEVICE_CTRL_RRSZ_2K
value|0x4000
end_define

begin_define
define|#
directive|define
name|ET_PCIR_MAC_ADDR0
value|0xA4
end_define

begin_define
define|#
directive|define
name|ET_PCIR_MAC_ADDR1
value|0xA8
end_define

begin_define
define|#
directive|define
name|ET_PCIR_EEPROM_STATUS
value|0xB2
end_define

begin_comment
comment|/* XXX undocumented */
end_comment

begin_define
define|#
directive|define
name|ET_PCIM_EEPROM_STATUS_ERROR
value|0x4C
end_define

begin_define
define|#
directive|define
name|ET_PCIR_ACK_LATENCY
value|0xC0
end_define

begin_define
define|#
directive|define
name|ET_PCIV_ACK_LATENCY_128
value|237
end_define

begin_define
define|#
directive|define
name|ET_PCIV_ACK_LATENCY_256
value|416
end_define

begin_define
define|#
directive|define
name|ET_PCIR_REPLAY_TIMER
value|0xC2
end_define

begin_define
define|#
directive|define
name|ET_REPLAY_TIMER_RX_L0S_ADJ
value|250
end_define

begin_comment
comment|/* XXX inferred from default */
end_comment

begin_define
define|#
directive|define
name|ET_PCIV_REPLAY_TIMER_128
value|(711 + ET_REPLAY_TIMER_RX_L0S_ADJ)
end_define

begin_define
define|#
directive|define
name|ET_PCIV_REPLAY_TIMER_256
value|(1248 + ET_REPLAY_TIMER_RX_L0S_ADJ)
end_define

begin_define
define|#
directive|define
name|ET_PCIR_L0S_L1_LATENCY
value|0xCF
end_define

begin_comment
comment|/*  * CSR  */
end_comment

begin_define
define|#
directive|define
name|ET_TXQUEUE_START
value|0x0000
end_define

begin_define
define|#
directive|define
name|ET_TXQUEUE_END
value|0x0004
end_define

begin_define
define|#
directive|define
name|ET_RXQUEUE_START
value|0x0008
end_define

begin_define
define|#
directive|define
name|ET_RXQUEUE_END
value|0x000C
end_define

begin_define
define|#
directive|define
name|ET_QUEUE_ADDR
parameter_list|(
name|addr
parameter_list|)
value|(((addr) / ET_MEM_UNIT) - 1)
end_define

begin_define
define|#
directive|define
name|ET_QUEUE_ADDR_START
value|0
end_define

begin_define
define|#
directive|define
name|ET_QUEUE_ADDR_END
value|ET_QUEUE_ADDR(ET_MEM_SIZE)
end_define

begin_define
define|#
directive|define
name|ET_PM
value|0x0010
end_define

begin_define
define|#
directive|define
name|EM_PM_GIGEPHY_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_PM_SYSCLK_GATE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_PM_TXCLK_GATE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_PM_RXCLK_GATE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_PM_PHY_SW_COMA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ET_INTR_STATUS
value|0x0018
end_define

begin_define
define|#
directive|define
name|ET_INTR_MASK
value|0x001C
end_define

begin_define
define|#
directive|define
name|ET_SWRST
value|0x0028
end_define

begin_define
define|#
directive|define
name|ET_SWRST_TXDMA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_SWRST_RXDMA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_SWRST_TXMAC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_SWRST_RXMAC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_SWRST_MAC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_SWRST_MAC_STAT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_SWRST_MMC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ET_SWRST_SELFCLR_DISABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ET_MSI_CFG
value|0x0030
end_define

begin_define
define|#
directive|define
name|ET_LOOPBACK
value|0x0034
end_define

begin_define
define|#
directive|define
name|ET_TIMER
value|0x0038
end_define

begin_define
define|#
directive|define
name|ET_TXDMA_CTRL
value|0x1000
end_define

begin_define
define|#
directive|define
name|ET_TXDMA_CTRL_HALT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_TXDMA_CTRL_CACHE_THR_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|ET_TXDMA_CTRL_SINGLE_EPKT
value|0x00000100
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|ET_TX_RING_HI
value|0x1004
end_define

begin_define
define|#
directive|define
name|ET_TX_RING_LO
value|0x1008
end_define

begin_define
define|#
directive|define
name|ET_TX_RING_CNT
value|0x100C
end_define

begin_define
define|#
directive|define
name|ET_TX_STATUS_HI
value|0x101C
end_define

begin_define
define|#
directive|define
name|ET_TX_STATUS_LO
value|0x1020
end_define

begin_define
define|#
directive|define
name|ET_TX_READY_POS
value|0x1024
end_define

begin_define
define|#
directive|define
name|ET_TX_READY_POS_INDEX_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ET_TX_READY_POS_WRAP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ET_TX_DONE_POS
value|0x1060
end_define

begin_define
define|#
directive|define
name|ET_TX_DONE_POS_INDEX_MASK
value|0x0000003FF
end_define

begin_define
define|#
directive|define
name|ET_TX_DONE_POS_WRAP
value|0x000000400
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL
value|0x2000
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_HALT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_SIZE_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_128
value|0x00000000
end_define

begin_comment
comment|/* 127 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_256
value|0x00000100
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_512
value|0x00000200
end_define

begin_comment
comment|/* 511 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_1024
value|0x00000300
end_define

begin_comment
comment|/* 1023 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_ENABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_SIZE_MASK
value|0x00001800
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_2048
value|0x00000000
end_define

begin_comment
comment|/* 2047 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_4096
value|0x00000800
end_define

begin_comment
comment|/* 4095 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_8192
value|0x00001000
end_define

begin_comment
comment|/* 8191 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_16384
value|0x00001800
end_define

begin_comment
comment|/* 16383 (9022?) */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_ENABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_HALTED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ET_RX_STATUS_LO
value|0x2004
end_define

begin_define
define|#
directive|define
name|ET_RX_STATUS_HI
value|0x2008
end_define

begin_define
define|#
directive|define
name|ET_RX_INTR_NPKTS
value|0x200C
end_define

begin_define
define|#
directive|define
name|ET_RX_INTR_DELAY
value|0x2010
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_LO
value|0x2020
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_HI
value|0x2024
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_CNT
value|0x2028
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_POS
value|0x2030
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_POS_INDEX_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_POS_WRAP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_MINCNT
value|0x2038
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_LO
value|0x203C
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_HI
value|0x2040
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_CNT
value|0x2044
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_POS
value|0x204C
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_POS_INDEX_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_POS_WRAP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_MINCNT
value|0x2054
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_LO
value|0x2058
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_HI
value|0x205C
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_CNT
value|0x2060
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_POS
value|0x2068
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_POS_INDEX
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_POS_WRAP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_MINCNT
value|0x2070
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_CTRL
value|0x3000
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_CTRL_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_CTRL_FC_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_FLOWCTRL
value|0x3010
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_FLOWCTRL_CFPT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_FLOWCTRL_CFEP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_FLOWCTRL_CFPT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_BP_CTRL
value|0x3020
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_BP_CTRL_XONXOFF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_BP_CTRL_REQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL
value|0x4000
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL_NO_PKTFILT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL_WOL_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_WOL_CRC
value|0x4004
end_define

begin_define
define|#
directive|define
name|ET_WOL_SA_LO
value|0x4010
end_define

begin_define
define|#
directive|define
name|ET_WOL_SA_HI
value|0x4014
end_define

begin_define
define|#
directive|define
name|ET_WOL_MASK
value|0x4018
end_define

begin_define
define|#
directive|define
name|ET_UCAST_FILTADDR1
value|0x4068
end_define

begin_define
define|#
directive|define
name|ET_UCAST_FILTADDR2
value|0x406C
end_define

begin_define
define|#
directive|define
name|ET_UCAST_FILTADDR3
value|0x4070
end_define

begin_define
define|#
directive|define
name|ET_MULTI_HASH
value|0x4074
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT
value|0x4084
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_BCAST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_MCAST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_UCAST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_FRAG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_MINLEN_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_MINLEN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_SEGSZ
value|0x4088
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_SEGSZ_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_SEGSZ_FC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_SEGSZ_MAX_MASK
value|0x000003FC
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_SEGSZ
parameter_list|(
name|segsz
parameter_list|)
value|((segsz) / ET_MEM_UNIT)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CUT_THRU_FRMLEN
value|8074
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_WATERMARK
value|0x408C
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_SPACE_AVL
value|0x4094
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT
value|0x4098
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_PASS_ECRC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_PASS_ELEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_PASS_ETRUNC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_CHECK_PKT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1
value|0x5000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_TXEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SYNC_TXEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RXEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SYNC_RXEN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_TXFLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RXFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_LOOPBACK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_TXFUNC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_RXFUNC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_TXMC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_RXMC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SIM_RST
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SOFT_RST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2
value|0x5004
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_FDX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_CRC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_PADCRC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_LENCHK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_BIGFRM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_MODE_MII
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_MODE_GMII
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_PREAMBLE_LEN_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_PREAMBLE_LEN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ET_IPG
value|0x5008
end_define

begin_define
define|#
directive|define
name|ET_IPG_B2B_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|ET_IPG_MINIFG_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|ET_IPG_NONB2B_2_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|ET_IPG_NONB2B_1_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|ET_IPG_B2B_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ET_IPG_MINIFG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ET_IPG_NONB2B_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ET_IPG_NONB2B_1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX
value|0x500C
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_COLLWIN_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_REXMIT_MAX_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_EXC_DEFER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_NOBACKOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_BP_NOBACKOFF
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_ALT_BEB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_ALT_BEB_TRUNC_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_COLLWIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_REXMIT_MAX_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_ALT_BEB_TRUNC_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ET_MAX_FRMLEN
value|0x5010
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG
value|0x5020
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_CLKRST
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_PREAMBLE_SUP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_SCAN_AUTOINC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_RST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ET_MII_CMD
value|0x5024
end_define

begin_define
define|#
directive|define
name|ET_MII_CMD_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_MII_ADDR
value|0x5028
end_define

begin_define
define|#
directive|define
name|ET_MII_ADDR_REG_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|ET_MII_ADDR_PHY_MASK
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|ET_MII_ADDR_REG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ET_MII_ADDR_PHY_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ET_MII_CTRL
value|0x502C
end_define

begin_define
define|#
directive|define
name|ET_MII_CTRL_VALUE_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ET_MII_CTRL_VALUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ET_MII_STAT
value|0x5030
end_define

begin_define
define|#
directive|define
name|ET_MII_STAT_VALUE_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ET_MII_IND
value|0x5034
end_define

begin_define
define|#
directive|define
name|ET_MII_IND_BUSY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_MII_IND_INVALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_MAC_CTRL
value|0x5038
end_define

begin_define
define|#
directive|define
name|ET_MAC_CTRL_MODE_MII
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CTRL_LHDX
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ET_MAC_CTRL_GHDX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ET_MAC_ADDR1
value|0x5040
end_define

begin_define
define|#
directive|define
name|ET_MAC_ADDR2
value|0x5044
end_define

begin_comment
comment|/* MAC statistics counters. */
end_comment

begin_define
define|#
directive|define
name|ET_STAT_PKTS_64
value|0x6080
end_define

begin_define
define|#
directive|define
name|ET_STAT_PKTS_65_127
value|0x6084
end_define

begin_define
define|#
directive|define
name|ET_STAT_PKTS_128_255
value|0x6088
end_define

begin_define
define|#
directive|define
name|ET_STAT_PKTS_256_511
value|0x608C
end_define

begin_define
define|#
directive|define
name|ET_STAT_PKTS_512_1023
value|0x6090
end_define

begin_define
define|#
directive|define
name|ET_STAT_PKTS_1024_1518
value|0x6094
end_define

begin_define
define|#
directive|define
name|ET_STAT_PKTS_1519_1522
value|0x6098
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_BYTES
value|0x609C
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_FRAMES
value|0x60A0
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_CRC_ERR
value|0x60A4
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_MCAST
value|0x60A8
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_BCAST
value|0x60AC
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_CTL
value|0x60B0
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_PAUSE
value|0x60B4
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_UNKNOWN_CTL
value|0x60B8
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_ALIGN_ERR
value|0x60BC
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_LEN_ERR
value|0x60C0
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_CODE_ERR
value|0x60C4
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_CS_ERR
value|0x60C8
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_RUNT
value|0x60CC
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_OVERSIZE
value|0x60D0
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_FRAG
value|0x60D4
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_JABBER
value|0x60D8
end_define

begin_define
define|#
directive|define
name|ET_STAT_RX_DROP
value|0x60DC
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_BYTES
value|0x60E0
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_FRAMES
value|0x60E4
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_MCAST
value|0x60E8
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_BCAST
value|0x60EC
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_PAUSE
value|0x60F0
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_DEFER
value|0x60F4
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_EXCESS_DEFER
value|0x60F8
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_SINGLE_COL
value|0x60FC
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_MULTI_COL
value|0x6100
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_LATE_COL
value|0x6104
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_EXCESS_COL
value|0x6108
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_TOTAL_COL
value|0x610C
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_PAUSE_HONOR
value|0x6110
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_DROP
value|0x6114
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_JABBER
value|0x6118
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_CRC_ERR
value|0x611C
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_CTL
value|0x6120
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_OVERSIZE
value|0x6124
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_UNDERSIZE
value|0x6128
end_define

begin_define
define|#
directive|define
name|ET_STAT_TX_FRAG
value|0x612C
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL
value|0x7000
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_ARB_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_RXMAC_DISABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_TXMAC_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_TXDMA_DISABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_RXDMA_DISABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_FORCE_CE
value|0x00000040
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|ET_INTR_TXDMA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_INTR_TXDMA_ERROR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXDMA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXRING0_LOW
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXRING1_LOW
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXSTAT_LOW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXDMA_ERROR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ET_INTR_TIMER
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ET_INTR_WOL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ET_INTR_PHY
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ET_INTR_TXMAC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXMAC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ET_INTR_MAC_STATS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ET_INTR_SLAVE_TO
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ET_INTRS
define|\
value|(ET_INTR_TXDMA | ET_INTR_RXDMA | ET_INTR_TIMER |	\ 	 ET_INTR_TXDMA_ERROR | ET_INTR_RXDMA_ERROR)
end_define

begin_comment
comment|/*  * RX ring position uses same layout  */
end_comment

begin_define
define|#
directive|define
name|ET_RX_RING_POS_INDEX_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ET_RX_RING_POS_WRAP
value|0x00000400
end_define

begin_comment
comment|/*  * PCI IDs  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_LUCENT
value|0x11C1
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_LUCENT_ET1310
value|0xED00
end_define

begin_comment
comment|/* ET1310 10/100/1000M Ethernet */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_LUCENT_ET1310_FAST
value|0xED01
end_define

begin_comment
comment|/* ET1310 10/100M Ethernet */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_ETREG_H */
end_comment

end_unit

