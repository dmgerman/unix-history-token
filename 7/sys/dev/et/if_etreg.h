begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/dev/netif/et/if_etreg.h,v 1.3 2007/10/23 14:28:42 sephe Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Portions of this code is derived from NetBSD which is covered by  * the following license:  *  * Copyright (c) 2004, 2005 David Young.  All rights reserved.  *  * Programmed for NetBSD by David Young.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of David Young may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY David Young ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL David  * Young BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $DragonFly: src/sys/sys/bitops.h,v 1.1 2007/10/14 04:15:17 sephe Exp $  */
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

begin_comment
comment|/*  * __BIT(n): Return a bitmask with bit n set, where the least  *           significant bit is bit 0.  *  * __BITS(m, n): Return a bitmask with bits m through n, inclusive,  *               set.  It does not matter whether m>n or m<=n.  The  *               least significant bit is bit 0.  *  * A "bitfield" is a span of consecutive bits defined by a bitmask,  * where 1s select the bits in the bitfield.  __SHIFTIN, __SHIFTOUT,  * and __SHIFTOUT_MASK help read and write bitfields from device  * registers.  *  * __SHIFTIN(v, mask): Left-shift bits `v' into the bitfield  *                     defined by `mask', and return them.  No  *                     side-effects.  *  * __SHIFTOUT(v, mask): Extract and return the bitfield selected  *                      by `mask' from `v', right-shifting the  *                      bits so that the rightmost selected bit  *                      is at bit 0.  No side-effects.  *  * __SHIFTOUT_MASK(mask): Right-shift the bits in `mask' so that  *                        the rightmost non-zero bit is at bit  *                        0.  This is useful for finding the  *                        greatest unsigned value that a bitfield  *                        can hold.  No side-effects.  Note that  *                        __SHIFTOUT_MASK(m) = __SHIFTOUT(m, m).  */
end_comment

begin_comment
comment|/* __BIT(n): nth bit, where __BIT(0) == 0x1. */
end_comment

begin_define
define|#
directive|define
name|__BIT
parameter_list|(
name|__n
parameter_list|)
value|(((__n) == 32) ? 0 : ((uint32_t)1<< (__n)))
end_define

begin_comment
comment|/* __BITS(m, n): bits m through n, m< n. */
end_comment

begin_define
define|#
directive|define
name|__BITS
parameter_list|(
name|__m
parameter_list|,
name|__n
parameter_list|)
define|\
value|((__BIT(MAX((__m), (__n)) + 1) - 1) ^ (__BIT(MIN((__m), (__n))) - 1))
end_define

begin_comment
comment|/* Find least significant bit that is set */
end_comment

begin_define
define|#
directive|define
name|__LOWEST_SET_BIT
parameter_list|(
name|__mask
parameter_list|)
value|((((__mask) - 1)& (__mask)) ^ (__mask))
end_define

begin_define
define|#
directive|define
name|__SHIFTOUT
parameter_list|(
name|__x
parameter_list|,
name|__mask
parameter_list|)
value|(((__x)& (__mask)) / __LOWEST_SET_BIT(__mask))
end_define

begin_define
define|#
directive|define
name|__SHIFTIN
parameter_list|(
name|__x
parameter_list|,
name|__mask
parameter_list|)
value|((__x) * __LOWEST_SET_BIT(__mask))
end_define

begin_define
define|#
directive|define
name|__SHIFTOUT_MASK
parameter_list|(
name|__mask
parameter_list|)
value|__SHIFTOUT((__mask), (__mask))
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
name|ET_PCIR_BAR
value|PCIR_BAR(0)
end_define

begin_define
define|#
directive|define
name|ET_PCIR_DEVICE_CAPS
value|0x4c
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
value|0xa4
end_define

begin_define
define|#
directive|define
name|ET_PCIR_MAC_ADDR1
value|0xa8
end_define

begin_define
define|#
directive|define
name|ET_PCIR_EEPROM_STATUS
value|0xb2
end_define

begin_comment
comment|/* XXX undocumented */
end_comment

begin_define
define|#
directive|define
name|ET_PCIM_EEPROM_STATUS_ERROR
value|0x4c
end_define

begin_define
define|#
directive|define
name|ET_PCIR_ACK_LATENCY
value|0xc0
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
value|0xc2
end_define

begin_define
define|#
directive|define
name|ET_REPLAY_TIMER_RX_L0S_ADJ
value|250
end_define

begin_comment
comment|/* XXX infered from default */
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
value|0xcf
end_define

begin_define
define|#
directive|define
name|ET_PCIM_L0S_LATENCY
value|__BITS(2, 0)
end_define

begin_define
define|#
directive|define
name|ET_PCIM_L1_LATENCY
value|__BITS(5, 3)
end_define

begin_define
define|#
directive|define
name|ET_PCIV_L0S_LATENCY
parameter_list|(
name|l
parameter_list|)
value|__SHIFTIN((l) - 1, ET_PCIM_L0S_LATENCY)
end_define

begin_define
define|#
directive|define
name|ET_PCIV_L1_LATENCY
parameter_list|(
name|l
parameter_list|)
value|__SHIFTIN((l) - 1, ET_PCIM_L1_LATENCY)
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
value|0x000c
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
name|ET_PM_SYSCLK_GATE
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ET_PM_TXCLK_GATE
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_PM_RXCLK_GATE
value|__BIT(5)
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
value|0x001c
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_RXDMA
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_TXMAC
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_RXMAC
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_MAC
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_MAC_STAT
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_MMC
value|__BIT(6)
end_define

begin_define
define|#
directive|define
name|ET_SWRST_SELFCLR_DISABLE
value|__BIT(31)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_TXDMA_CTRL_CACHE_THR
value|__BITS(7, 4)
end_define

begin_define
define|#
directive|define
name|ET_TXDMA_CTRL_SINGLE_EPKT
value|__BIT(8)
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
value|0x100c
end_define

begin_define
define|#
directive|define
name|ET_TX_STATUS_HI
value|0x101c
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
name|ET_TX_READY_POS_INDEX
value|__BITS(9, 0)
end_define

begin_define
define|#
directive|define
name|ET_TX_READY_POS_WRAP
value|__BIT(10)
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
name|ET_TX_DONE_POS_INDEX
value|__BITS(9, 0)
end_define

begin_define
define|#
directive|define
name|ET_TX_DONE_POS_WRAP
value|__BIT(10)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_SIZE
value|__BITS(9, 8)
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_128
value|0
end_define

begin_comment
comment|/* 127 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_256
value|1
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_512
value|2
end_define

begin_comment
comment|/* 511 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_1024
value|3
end_define

begin_comment
comment|/* 1023 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING0_ENABLE
value|__BIT(10)
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_SIZE
value|__BITS(12, 11)
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_2048
value|0
end_define

begin_comment
comment|/* 2047 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_4096
value|1
end_define

begin_comment
comment|/* 4095 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_8192
value|2
end_define

begin_comment
comment|/* 8191 */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_16384
value|3
end_define

begin_comment
comment|/* 16383 (9022?) */
end_comment

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_RING1_ENABLE
value|__BIT(13)
end_define

begin_define
define|#
directive|define
name|ET_RXDMA_CTRL_HALTED
value|__BIT(17)
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
value|0x200c
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
name|ET_RXSTAT_POS_INDEX
value|__BITS(11, 0)
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_POS_WRAP
value|__BIT(12)
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
value|0x203c
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
value|0x204c
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_POS_INDEX
value|__BITS(9, 0)
end_define

begin_define
define|#
directive|define
name|ET_RX_RING0_POS_WRAP
value|__BIT(10)
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
value|0x205c
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
value|__BITS(9, 0)
end_define

begin_define
define|#
directive|define
name|ET_RX_RING1_POS_WRAP
value|__BIT(10)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_TXMAC_CTRL_FC_DISABLE
value|__BIT(3)
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
name|ET_RXMAC_CTRL
value|0x4000
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL_ENABLE
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL_NO_PKTFILT
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_CTRL_WOL_DISABLE
value|__BIT(3)
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
value|0x406c
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_MCAST
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_UCAST
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_FRAG
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ET_PKTFILT_MINLEN
value|__BITS(22, 16)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_SEGSZ_FC
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MC_SEGSZ_MAX
value|__BITS(9, 2)
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
value|0x408c
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
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_PASS_ELEN
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_PASS_ETRUNC
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|ET_RXMAC_MGT_CHECK_PKT
value|__BIT(17)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SYNC_TXEN
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RXEN
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SYNC_RXEN
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_TXFLOW
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RXFLOW
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_LOOPBACK
value|__BIT(8)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_TXFUNC
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_RXFUNC
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_TXMC
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_RST_RXMC
value|__BIT(19)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SIM_RST
value|__BIT(30)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG1_SOFT_RST
value|__BIT(31)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_CRC
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_PADCRC
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_LENCHK
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_BIGFRM
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_MODE_MII
value|__BIT(8)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_MODE_GMII
value|__BIT(9)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CFG2_PREAMBLE_LEN
value|__BITS(15, 12)
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
name|ET_IPG_B2B
value|__BITS(6, 0)
end_define

begin_define
define|#
directive|define
name|ET_IPG_MINIFG
value|__BITS(15, 8)
end_define

begin_define
define|#
directive|define
name|ET_IPG_NONB2B_2
value|__BITS(22, 16)
end_define

begin_define
define|#
directive|define
name|ET_IPG_NONB2B_1
value|__BITS(30, 24)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX
value|0x500c
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_COLLWIN
value|__BITS(9, 0)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_REXMIT_MAX
value|__BITS(15, 12)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_EXC_DEFER
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_NOBACKOFF
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_BP_NOBACKOFF
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_ALT_BEB
value|__BIT(19)
end_define

begin_define
define|#
directive|define
name|ET_MAC_HDX_ALT_BEB_TRUNC
value|__BITS(23, 20)
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
value|__BITS(2, 0)
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_PREAMBLE_SUP
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_SCAN_AUTOINC
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_MII_CFG_RST
value|__BIT(31)
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
value|__BIT(0)
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
name|ET_MII_ADDR_REG
value|__BITS(4, 0)
end_define

begin_define
define|#
directive|define
name|ET_MII_ADDR_PHY
value|__BITS(12, 8)
end_define

begin_define
define|#
directive|define
name|ET_MII_CTRL
value|0x502c
end_define

begin_define
define|#
directive|define
name|ET_MII_CTRL_VALUE
value|__BITS(15, 0)
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
name|ET_MII_STAT_VALUE
value|__BITS(15, 0)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_MII_IND_INVALID
value|__BIT(2)
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
value|__BIT(24)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CTRL_LHDX
value|__BIT(25)
end_define

begin_define
define|#
directive|define
name|ET_MAC_CTRL_GHDX
value|__BIT(26)
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
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_ARB_DISABLE
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_RXMAC_DISABLE
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_TXMAC_DISABLE
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_TXDMA_DISABLE
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_RXDMA_DISABLE
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_MMC_CTRL_FORCE_CE
value|__BIT(6)
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|ET_INTR_TXEOF
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ET_INTR_TXDMA_ERROR
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXEOF
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXRING0_LOW
value|__BIT(6)
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXRING1_LOW
value|__BIT(7)
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXSTAT_LOW
value|__BIT(8)
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXDMA_ERROR
value|__BIT(9)
end_define

begin_define
define|#
directive|define
name|ET_INTR_TIMER
value|__BIT(14)
end_define

begin_define
define|#
directive|define
name|ET_INTR_WOL
value|__BIT(15)
end_define

begin_define
define|#
directive|define
name|ET_INTR_PHY
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|ET_INTR_TXMAC
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|ET_INTR_RXMAC
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|ET_INTR_MAC_STATS
value|__BIT(19)
end_define

begin_define
define|#
directive|define
name|ET_INTR_SLAVE_TO
value|__BIT(20)
end_define

begin_define
define|#
directive|define
name|ET_INTRS
value|(ET_INTR_TXEOF | \ 					 ET_INTR_RXEOF | \ 					 ET_INTR_TIMER)
end_define

begin_comment
comment|/*  * RX ring position uses same layout  */
end_comment

begin_define
define|#
directive|define
name|ET_RX_RING_POS_INDEX
value|__BITS(9, 0)
end_define

begin_define
define|#
directive|define
name|ET_RX_RING_POS_WRAP
value|__BIT(10)
end_define

begin_comment
comment|/*  * PCI IDs  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_LUCENT
value|0x11c1
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_LUCENT_ET1310
value|0xed00
end_define

begin_comment
comment|/* ET1310 10/100/1000M Ethernet */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_LUCENT_ET1310_FAST
value|0xed01
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

