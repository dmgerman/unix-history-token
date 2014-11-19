begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ALEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_ALEREG_H
end_define

begin_comment
comment|/*  * Atheros Communucations, Inc. PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_ATHEROS
value|0x1969
end_define

begin_comment
comment|/*  * Atheros AR8121/AR8113/AR8114 device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR81XX
value|0x1026
end_define

begin_define
define|#
directive|define
name|ALE_SPI_CTRL
value|0x200
end_define

begin_define
define|#
directive|define
name|SPI_VPD_ENB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ALE_SPI_ADDR
value|0x204
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_DATA
value|0x208
end_define

begin_define
define|#
directive|define
name|ALE_SPI_CONFIG
value|0x20C
end_define

begin_define
define|#
directive|define
name|ALE_SPI_OP_PROGRAM
value|0x210
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_SC_ERASE
value|0x211
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_CHIP_ERASE
value|0x212
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_RDID
value|0x213
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_WREN
value|0x214
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_RDSR
value|0x215
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_WRSR
value|0x216
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_SPI_OP_READ
value|0x217
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|ALE_TWSI_CTRL
value|0x218
end_define

begin_define
define|#
directive|define
name|TWSI_CTRL_SW_LD_START
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TWSI_CTRL_HW_LD_START
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TWSI_CTRL_LD_EXIST
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ALE_DEV_MISC_CTRL
value|0x21C
end_define

begin_define
define|#
directive|define
name|ALE_PCIE_PHYMISC
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIE_PHYMISC_FORCE_RCV_DET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ALE_MASTER_CFG
value|0x1400
end_define

begin_define
define|#
directive|define
name|MASTER_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MASTER_MTIMER_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MASTER_IM_TX_TIMER_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MASTER_MANUAL_INT_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MASTER_IM_RX_TIMER_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MASTER_INT_RDCLR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MASTER_LED_MODE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_REV_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_ID_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_REV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_ID_SHIFT
value|24
end_define

begin_comment
comment|/* Number of ticks per usec for AR81xx. */
end_comment

begin_define
define|#
directive|define
name|ALE_TICK_USECS
value|2
end_define

begin_define
define|#
directive|define
name|ALE_USECS
parameter_list|(
name|x
parameter_list|)
value|((x) / ALE_TICK_USECS)
end_define

begin_define
define|#
directive|define
name|ALE_MANUAL_TIMER
value|0x1404
end_define

begin_define
define|#
directive|define
name|ALE_IM_TIMER
value|0x1408
end_define

begin_define
define|#
directive|define
name|IM_TIMER_TX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IM_TIMER_RX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IM_TIMER_TX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IM_TIMER_RX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALE_IM_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|ALE_IM_TIMER_MAX
value|130000
end_define

begin_comment
comment|/* 130ms */
end_comment

begin_define
define|#
directive|define
name|ALE_IM_RX_TIMER_DEFAULT
value|30
end_define

begin_define
define|#
directive|define
name|ALE_IM_TX_TIMER_DEFAULT
value|1000
end_define

begin_define
define|#
directive|define
name|ALE_GPHY_CTRL
value|0x140C
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|GPHY_CTRL_EXT_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_PIPE_MOD
value|0x0002
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_BERT_START
value|0x0010
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_GALE_25M_ENB
value|0x0020
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_LPW_EXIT
value|0x0040
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_PHY_IDDQ
value|0x0080
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_PHY_IDDQ_DIS
value|0x0100
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_PCLK_SEL_DIS
value|0x0200
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_HIB_EN
value|0x0400
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_HIB_PULSE
value|0x0800
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_SEL_ANA_RESET
value|0x1000
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_PHY_PLL_ON
value|0x2000
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_PWDOWN_HW
value|0x4000
end_define

begin_define
define|#
directive|define
name|ALE_INTR_CLR_TIMER
value|0x140E
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|ALE_IDLE_STATUS
value|0x1410
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_RXMAC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_TXMAC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_RXQ
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_TXQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_DMARD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_DMAWR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_SMB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_CMB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ALE_MDIO
value|0x1414
end_define

begin_define
define|#
directive|define
name|MDIO_DATA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MDIO_REG_ADDR_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_READ
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MDIO_SUP_PREAMBLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_EXECUTE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_4
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_6
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_8
value|0x03000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_10
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_14
value|0x05000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_20
value|0x06000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_28
value|0x07000000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_BUSY
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MDIO_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MDIO_REG_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MDIO_REG_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< MDIO_REG_ADDR_SHIFT)& MDIO_REG_ADDR_MASK)
end_define

begin_comment
comment|/* Default PHY address. */
end_comment

begin_define
define|#
directive|define
name|ALE_PHY_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|ALE_PHY_STATUS
value|0x1418
end_define

begin_define
define|#
directive|define
name|PHY_STATUS_100M
value|0x00020000
end_define

begin_comment
comment|/* Packet memory BIST. */
end_comment

begin_define
define|#
directive|define
name|ALE_BIST0
value|0x141C
end_define

begin_define
define|#
directive|define
name|BIST0_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIST0_SRAM_FAIL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIST0_FUSE_FLAG
value|0x00000004
end_define

begin_comment
comment|/* PCIe retry buffer BIST. */
end_comment

begin_define
define|#
directive|define
name|ALE_BIST1
value|0x1420
end_define

begin_define
define|#
directive|define
name|BIST1_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIST1_SRAM_FAIL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIST1_FUSE_FLAG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ALE_SERDES_LOCK
value|0x1424
end_define

begin_define
define|#
directive|define
name|SERDES_LOCK_DET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SERDES_LOCK_DET_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ALE_MAC_CFG
value|0x1480
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RX_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_FC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RX_FC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MAC_CFG_LOOP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MAC_CFG_FULL_DUPLEX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_CRC_ENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_AUTO_PAD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_LENCHK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RX_JUMBO_ENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PREAMBLE_MASK
value|0x00003C00
end_define

begin_define
define|#
directive|define
name|MAC_CFG_VLAN_TAG_STRIP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PROMISC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_PAUSE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SCNT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SYNC_RST_TX
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_MASK
value|0x00300000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_10_100
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_1000
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_DBG_TX_BACKOFF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_JUMBO_ENB
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RXCSUM_ENB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_ALLMULTI
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_BCAST
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_DBG
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PREAMBLE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PREAMBLE_DEFAULT
value|7
end_define

begin_define
define|#
directive|define
name|ALE_IPG_IFG_CFG
value|0x1484
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPGT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|IPG_IFG_MIFG_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG1_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG2_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPGT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPGT_DEFAULT
value|0x60
end_define

begin_define
define|#
directive|define
name|IPG_IFG_MIFG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IPG_IFG_MIFG_DEFAULT
value|0x50
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG1_DEFAULT
value|0x40
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG2_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG2_DEFAULT
value|0x60
end_define

begin_comment
comment|/* Station address. */
end_comment

begin_define
define|#
directive|define
name|ALE_PAR0
value|0x1488
end_define

begin_define
define|#
directive|define
name|ALE_PAR1
value|0x148C
end_define

begin_comment
comment|/* 64bit multicast hash register. */
end_comment

begin_define
define|#
directive|define
name|ALE_MAR0
value|0x1490
end_define

begin_define
define|#
directive|define
name|ALE_MAR1
value|0x1494
end_define

begin_comment
comment|/* half-duplex parameter configuration. */
end_comment

begin_define
define|#
directive|define
name|ALE_HDPX_CFG
value|0x1498
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_LCOL_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_RETRY_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_EXC_DEF_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_NO_BACK_C
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_NO_BACK_P
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBT_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_JAMIPG_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_LCOL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_LCOL_DEFAULT
value|0x37
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_RETRY_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_RETRY_DEFAULT
value|0x0F
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBT_DEFAULT
value|0x0A
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_JAMIPG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_JAMIPG_DEFAULT
value|0x07
end_define

begin_define
define|#
directive|define
name|ALE_FRAME_SIZE
value|0x149C
end_define

begin_define
define|#
directive|define
name|ALE_WOL_CFG
value|0x14A0
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WOL_CFG_MAGIC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WOL_CFG_MAGIC_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WOL_CFG_LINK_CHG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WOL_CFG_LINK_CHG_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN_DET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WOL_CFG_MAGIC_DET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WOL_CFG_LINK_CHG_DET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WOL_CFG_CLK_SWITCH_ENB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN4
value|0x00100000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN6
value|0x00400000
end_define

begin_comment
comment|/* WOL pattern length. */
end_comment

begin_define
define|#
directive|define
name|ALE_PATTERN_CFG0
value|0x14A4
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_0_LEN_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_1_LEN_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_2_LEN_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_3_LEN_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|ALE_PATTERN_CFG1
value|0x14A8
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_4_LEN_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_5_LEN_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_6_LEN_MASK
value|0x007F0000
end_define

begin_comment
comment|/* RSS */
end_comment

begin_define
define|#
directive|define
name|ALE_RSS_KEY0
value|0x14B0
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY1
value|0x14B4
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY2
value|0x14B8
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY3
value|0x14BC
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY4
value|0x14C0
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY5
value|0x14C4
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY6
value|0x14C8
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY7
value|0x14CC
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY8
value|0x14D0
end_define

begin_define
define|#
directive|define
name|ALE_RSS_KEY9
value|0x14D4
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE4
value|0x14E0
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE5
value|0x14E4
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE6
value|0x14E8
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE7
value|0x14EC
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_RD_ADDR
value|0x1500
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_RD_LEN
value|0x1504
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_RRD_ADDR
value|0x1508
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_RRD_LEN
value|0x150C
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TPD_ADDR
value|0x1510
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TPD_LEN
value|0x1514
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TRD_ADDR
value|0x1518
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TRD_LEN
value|0x151C
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_RX_FIFO_ADDR
value|0x1520
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_RX_FIFO_LEN
value|0x1524
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TX_FIFO_ADDR
value|0x1528
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TX_FIFO_LEN
value|0x152C
end_define

begin_define
define|#
directive|define
name|ALE_SRAM_TCPH_ADDR
value|0x1530
end_define

begin_define
define|#
directive|define
name|SRAM_TCPH_ADDR_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|SRAM_PATH_ADDR_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|SRAM_TCPH_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SRAM_PATH_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALE_DMA_BLOCK
value|0x1534
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK_LOAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_ADDR_HI
value|0x153C
end_define

begin_define
define|#
directive|define
name|ALE_TPD_ADDR_HI
value|0x1540
end_define

begin_define
define|#
directive|define
name|ALE_RXF0_PAGE0_ADDR_LO
value|0x1544
end_define

begin_define
define|#
directive|define
name|ALE_RXF0_PAGE1_ADDR_LO
value|0x1548
end_define

begin_define
define|#
directive|define
name|ALE_TPD_ADDR_LO
value|0x154C
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_ADDR_HI
value|0x1550
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_ADDR_HI
value|0x1554
end_define

begin_define
define|#
directive|define
name|ALE_RXF_PAGE_SIZE
value|0x1558
end_define

begin_define
define|#
directive|define
name|ALE_TPD_CNT
value|0x155C
end_define

begin_define
define|#
directive|define
name|TPD_CNT_MASK
value|0x00003FF
end_define

begin_define
define|#
directive|define
name|TPD_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE0
value|0x1560
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE1
value|0x1564
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE2
value|0x1568
end_define

begin_define
define|#
directive|define
name|ALE_RSS_IDT_TABLE3
value|0x156C
end_define

begin_define
define|#
directive|define
name|ALE_RSS_HASH_VALUE
value|0x1570
end_define

begin_define
define|#
directive|define
name|ALE_RSS_HASH_FLAG
value|0x1574
end_define

begin_define
define|#
directive|define
name|ALE_RSS_CPU
value|0x157C
end_define

begin_define
define|#
directive|define
name|ALE_TXQ_CFG
value|0x1580
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TPD_BURST_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_ENHANCED_MODE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TX_FIFO_BURST_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TPD_BURST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TPD_BURST_DEFAULT
value|4
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TX_FIFO_BURST_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TX_FIFO_BURST_DEFAULT
value|256
end_define

begin_define
define|#
directive|define
name|ALE_TX_JUMBO_THRESH
value|0x1584
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_THRESH_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_THRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_THRESH_UNIT
value|8
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_THRESH_UNIT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ALE_RXQ_CFG
value|0x15A0
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ALIGN_32
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ALIGN_64
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ALIGN_128
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ALIGN_256
value|0x00000003
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE1_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE2_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE3_ENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_IPV6_CSUM_VERIFY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_TBL_LEN_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV4
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV4_TCP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV6
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV6_TCP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_DIS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_SQSINT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_MQUESINT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_MQUEMINT
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_NIP_QUEUE_SEL_TBL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_ENB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_CUT_THROUGH_ENB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ENB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_TBL_LEN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ALE_RX_JUMBO_THRESH
value|0x15A4
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|RX_JUMBO_THRESH_MASK
value|0x07FF
end_define

begin_define
define|#
directive|define
name|RX_JUMBO_LKAH_MASK
value|0x7800
end_define

begin_define
define|#
directive|define
name|RX_JUMBO_THRESH_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RX_JUMBO_THRESH_UNIT
value|8
end_define

begin_define
define|#
directive|define
name|RX_JUMBO_THRESH_UNIT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|RX_JUMBO_LKAH_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RX_JUMBO_LKAH_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|ALE_RX_FIFO_PAUSE_THRESH
value|0x15A8
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_LO_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_HI_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_LO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_HI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALE_CMB_RXF1
value|0x15B4
end_define

begin_define
define|#
directive|define
name|ALE_CMB_RXF2
value|0x15B8
end_define

begin_define
define|#
directive|define
name|ALE_CMB_RXF3
value|0x15BC
end_define

begin_define
define|#
directive|define
name|ALE_DMA_CFG
value|0x15C0
end_define

begin_define
define|#
directive|define
name|DMA_CFG_IN_ORDER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DMA_CFG_ENH_ORDER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DMA_CFG_OUT_ORDER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RCB_64
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RCB_128
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_128
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_256
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_512
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_1024
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_2048
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_4096
value|0x00000050
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_128
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_256
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_512
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_1024
value|0x00000180
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_2048
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_4096
value|0x00000280
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_REQ_PRI
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_DELAY_CNT_MASK
value|0x0000F800
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_DELAY_CNT_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_TXCMB_ENB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RXCMB_ENB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_DELAY_CNT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_DELAY_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_DELAY_CNT_DEFAULT
value|15
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_DELAY_CNT_DEFAULT
value|4
end_define

begin_define
define|#
directive|define
name|ALE_SMB_STAT_TIMER
value|0x15C4
end_define

begin_define
define|#
directive|define
name|ALE_INT_TRIG_THRESH
value|0x15C8
end_define

begin_define
define|#
directive|define
name|INT_TRIG_TX_THRESH_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|INT_TRIG_RX_THRESH_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|INT_TRIG_TX_THRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|INT_TRIG_RX_THRESH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALE_INT_TRIG_TIMER
value|0x15CC
end_define

begin_define
define|#
directive|define
name|INT_TRIG_TX_TIMER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|INT_TRIG_RX_TIMER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|INT_TRIG_TX_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|INT_TRIG_RX_TIMER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_PAGE0_ADDR_LO
value|0x15D0
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_PAGE1_ADDR_LO
value|0x15D4
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_PAGE0_ADDR_LO
value|0x15D8
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_PAGE1_ADDR_LO
value|0x15DC
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_PAGE0_ADDR_LO
value|0x15E0
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_PAGE1_ADDR_LO
value|0x15E4
end_define

begin_define
define|#
directive|define
name|ALE_MBOX_TPD_PROD_IDX
value|0x15F0
end_define

begin_define
define|#
directive|define
name|ALE_RXF0_PAGE0
value|0x15F4
end_define

begin_define
define|#
directive|define
name|ALE_RXF0_PAGE1
value|0x15F5
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_PAGE0
value|0x15F6
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_PAGE1
value|0x15F7
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_PAGE0
value|0x15F8
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_PAGE1
value|0x15F9
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_PAGE0
value|0x15FA
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_PAGE1
value|0x15FB
end_define

begin_define
define|#
directive|define
name|RXF_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|ALE_INTR_STATUS
value|0x1600
end_define

begin_define
define|#
directive|define
name|INTR_SMB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INTR_TIMER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INTR_MANUAL_TIMER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|INTR_RX_FIFO_OFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INTR_RXF0_OFLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INTR_RXF1_OFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_RXF2_OFLOW
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_RXF3_OFLOW
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_TX_FIFO_UNDERRUN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|INTR_RX0_PAGE_FULL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|INTR_DMA_RD_TO_RST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|INTR_DMA_WR_TO_RST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|INTR_GPHY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|INTR_TX_CREDIT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|INTR_GPHY_LOW_PW
value|0x00004000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTR_TX_PKT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTR_TX_DMA
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT1
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT2
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT3
value|0x00200000
end_define

begin_define
define|#
directive|define
name|INTR_MAC_RX
value|0x00400000
end_define

begin_define
define|#
directive|define
name|INTR_MAC_TX
value|0x00800000
end_define

begin_define
define|#
directive|define
name|INTR_UNDERRUN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|INTR_FRAME_ERROR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|INTR_FRAME_OK
value|0x04000000
end_define

begin_define
define|#
directive|define
name|INTR_CSUM_ERROR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|INTR_PHY_LINK_DOWN
value|0x10000000
end_define

begin_define
define|#
directive|define
name|INTR_DIS_INT
value|0x80000000
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|ALE_INTR_MASK
value|0x1604
end_define

begin_define
define|#
directive|define
name|ALE_INTRS
define|\
value|(INTR_DMA_RD_TO_RST | INTR_DMA_WR_TO_RST |		\ 	INTR_RX_PKT | INTR_TX_PKT | INTR_RX_FIFO_OFLOW |	\ 	INTR_TX_FIFO_UNDERRUN)
end_define

begin_comment
comment|/*  * AR81xx requires register access to get MAC statistics  * and the format of statistics seems to be the same of L1 .  */
end_comment

begin_define
define|#
directive|define
name|ALE_RX_MIB_BASE
value|0x1700
end_define

begin_define
define|#
directive|define
name|ALE_TX_MIB_BASE
value|0x1760
end_define

begin_comment
comment|/* Statistics counters collected by the MAC. */
end_comment

begin_struct
struct|struct
name|smb
block|{
comment|/* Rx stats. */
name|uint32_t
name|rx_frames
decl_stmt|;
name|uint32_t
name|rx_bcast_frames
decl_stmt|;
name|uint32_t
name|rx_mcast_frames
decl_stmt|;
name|uint32_t
name|rx_pause_frames
decl_stmt|;
name|uint32_t
name|rx_control_frames
decl_stmt|;
name|uint32_t
name|rx_crcerrs
decl_stmt|;
name|uint32_t
name|rx_lenerrs
decl_stmt|;
name|uint32_t
name|rx_bytes
decl_stmt|;
name|uint32_t
name|rx_runts
decl_stmt|;
name|uint32_t
name|rx_fragments
decl_stmt|;
name|uint32_t
name|rx_pkts_64
decl_stmt|;
name|uint32_t
name|rx_pkts_65_127
decl_stmt|;
name|uint32_t
name|rx_pkts_128_255
decl_stmt|;
name|uint32_t
name|rx_pkts_256_511
decl_stmt|;
name|uint32_t
name|rx_pkts_512_1023
decl_stmt|;
name|uint32_t
name|rx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|rx_pkts_1519_max
decl_stmt|;
name|uint32_t
name|rx_pkts_truncated
decl_stmt|;
name|uint32_t
name|rx_fifo_oflows
decl_stmt|;
name|uint32_t
name|rx_rrs_errs
decl_stmt|;
name|uint32_t
name|rx_alignerrs
decl_stmt|;
name|uint32_t
name|rx_bcast_bytes
decl_stmt|;
name|uint32_t
name|rx_mcast_bytes
decl_stmt|;
name|uint32_t
name|rx_pkts_filtered
decl_stmt|;
comment|/* Tx stats. */
name|uint32_t
name|tx_frames
decl_stmt|;
name|uint32_t
name|tx_bcast_frames
decl_stmt|;
name|uint32_t
name|tx_mcast_frames
decl_stmt|;
name|uint32_t
name|tx_pause_frames
decl_stmt|;
name|uint32_t
name|tx_excess_defer
decl_stmt|;
name|uint32_t
name|tx_control_frames
decl_stmt|;
name|uint32_t
name|tx_deferred
decl_stmt|;
name|uint32_t
name|tx_bytes
decl_stmt|;
name|uint32_t
name|tx_pkts_64
decl_stmt|;
name|uint32_t
name|tx_pkts_65_127
decl_stmt|;
name|uint32_t
name|tx_pkts_128_255
decl_stmt|;
name|uint32_t
name|tx_pkts_256_511
decl_stmt|;
name|uint32_t
name|tx_pkts_512_1023
decl_stmt|;
name|uint32_t
name|tx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|tx_pkts_1519_max
decl_stmt|;
name|uint32_t
name|tx_single_colls
decl_stmt|;
name|uint32_t
name|tx_multi_colls
decl_stmt|;
name|uint32_t
name|tx_late_colls
decl_stmt|;
name|uint32_t
name|tx_excess_colls
decl_stmt|;
name|uint32_t
name|tx_underrun
decl_stmt|;
name|uint32_t
name|tx_desc_underrun
decl_stmt|;
name|uint32_t
name|tx_lenerrs
decl_stmt|;
name|uint32_t
name|tx_pkts_truncated
decl_stmt|;
name|uint32_t
name|tx_bcast_bytes
decl_stmt|;
name|uint32_t
name|tx_mcast_bytes
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ALE_HOST_RXF0_PAGEOFF
value|0x1800
end_define

begin_define
define|#
directive|define
name|ALE_TPD_CONS_IDX
value|0x1804
end_define

begin_define
define|#
directive|define
name|ALE_HOST_RXF1_PAGEOFF
value|0x1808
end_define

begin_define
define|#
directive|define
name|ALE_HOST_RXF2_PAGEOFF
value|0x180C
end_define

begin_define
define|#
directive|define
name|ALE_HOST_RXF3_PAGEOFF
value|0x1810
end_define

begin_define
define|#
directive|define
name|ALE_RXF0_CMB0_ADDR_LO
value|0x1820
end_define

begin_define
define|#
directive|define
name|ALE_RXF0_CMB1_ADDR_LO
value|0x1824
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_CMB0_ADDR_LO
value|0x1828
end_define

begin_define
define|#
directive|define
name|ALE_RXF1_CMB1_ADDR_LO
value|0x182C
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_CMB0_ADDR_LO
value|0x1830
end_define

begin_define
define|#
directive|define
name|ALE_RXF2_CMB1_ADDR_LO
value|0x1834
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_CMB0_ADDR_LO
value|0x1838
end_define

begin_define
define|#
directive|define
name|ALE_RXF3_CMB1_ADDR_LO
value|0x183C
end_define

begin_define
define|#
directive|define
name|ALE_TX_CMB_ADDR_LO
value|0x1840
end_define

begin_define
define|#
directive|define
name|ALE_SMB_ADDR_LO
value|0x1844
end_define

begin_comment
comment|/*  * RRS(receive return status) structure.  *  * Note:  * Atheros AR81xx does not support descriptor based DMA on Rx  * instead it just prepends a Rx status structure prior to a  * received frame which also resides on the same Rx buffer.  * This means driver should copy an entire frame from the  * buffer to new mbuf chain which in turn greatly increases CPU  * cycles and effectively nullify the advantage of DMA  * operation of controller. So you should have fast CPU to cope  * with the copy operation. Implementing flow-controls may help  * a lot to minimize Rx FIFO overflows but it's not available  * yet on FreeBSD and hardware doesn't seem to support  * fine-grained Tx/Rx flow controls.  */
end_comment

begin_struct
struct|struct
name|rx_rs
block|{
name|uint32_t
name|seqno
decl_stmt|;
define|#
directive|define
name|ALE_RD_SEQNO_MASK
value|0x0000FFFF
define|#
directive|define
name|ALE_RD_HASH_MASK
value|0xFFFF0000
define|#
directive|define
name|ALE_RD_SEQNO_SHIFT
value|0
define|#
directive|define
name|ALE_RD_HASH_SHIFT
value|16
define|#
directive|define
name|ALE_RX_SEQNO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& ALE_RD_SEQNO_MASK)>> ALE_RD_SEQNO_SHIFT)
name|uint32_t
name|length
decl_stmt|;
define|#
directive|define
name|ALE_RD_CSUM_MASK
value|0x0000FFFF
define|#
directive|define
name|ALE_RD_LEN_MASK
value|0x3FFF0000
define|#
directive|define
name|ALE_RD_CPU_MASK
value|0xC0000000
define|#
directive|define
name|ALE_RD_CSUM_SHIFT
value|0
define|#
directive|define
name|ALE_RD_LEN_SHIFT
value|16
define|#
directive|define
name|ALE_RD_CPU_SHIFT
value|30
define|#
directive|define
name|ALE_RX_CSUM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& ALE_RD_CSUM_MASK)>> ALE_RD_CSUM_SHIFT)
define|#
directive|define
name|ALE_RX_BYTES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& ALE_RD_LEN_MASK)>> ALE_RD_LEN_SHIFT)
define|#
directive|define
name|ALE_RX_CPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& ALE_RD_CPU_MASK)>> ALE_RD_CPU_SHIFT)
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|ALE_RD_RSS_IPV4
value|0x00000001
define|#
directive|define
name|ALE_RD_RSS_IPV4_TCP
value|0x00000002
define|#
directive|define
name|ALE_RD_RSS_IPV6
value|0x00000004
define|#
directive|define
name|ALE_RD_RSS_IPV6_TCP
value|0x00000008
define|#
directive|define
name|ALE_RD_IPV6
value|0x00000010
define|#
directive|define
name|ALE_RD_IPV4_FRAG
value|0x00000020
define|#
directive|define
name|ALE_RD_IPV4_DF
value|0x00000040
define|#
directive|define
name|ALE_RD_802_3
value|0x00000080
define|#
directive|define
name|ALE_RD_VLAN
value|0x00000100
define|#
directive|define
name|ALE_RD_ERROR
value|0x00000200
define|#
directive|define
name|ALE_RD_IPV4
value|0x00000400
define|#
directive|define
name|ALE_RD_UDP
value|0x00000800
define|#
directive|define
name|ALE_RD_TCP
value|0x00001000
define|#
directive|define
name|ALE_RD_BCAST
value|0x00002000
define|#
directive|define
name|ALE_RD_MCAST
value|0x00004000
define|#
directive|define
name|ALE_RD_PAUSE
value|0x00008000
define|#
directive|define
name|ALE_RD_CRC
value|0x00010000
define|#
directive|define
name|ALE_RD_CODE
value|0x00020000
define|#
directive|define
name|ALE_RD_DRIBBLE
value|0x00040000
define|#
directive|define
name|ALE_RD_RUNT
value|0x00080000
define|#
directive|define
name|ALE_RD_OFLOW
value|0x00100000
define|#
directive|define
name|ALE_RD_TRUNC
value|0x00200000
define|#
directive|define
name|ALE_RD_IPCSUM_NOK
value|0x00400000
define|#
directive|define
name|ALE_RD_TCP_UDPCSUM_NOK
value|0x00800000
define|#
directive|define
name|ALE_RD_LENGTH_NOK
value|0x01000000
define|#
directive|define
name|ALE_RD_DES_ADDR_FILTERED
value|0x02000000
name|uint32_t
name|vtags
decl_stmt|;
define|#
directive|define
name|ALE_RD_HASH_HI_MASK
value|0x0000FFFF
define|#
directive|define
name|ALE_RD_HASH_HI_SHIFT
value|0
define|#
directive|define
name|ALE_RD_VLAN_MASK
value|0xFFFF0000
define|#
directive|define
name|ALE_RD_VLAN_SHIFT
value|16
define|#
directive|define
name|ALE_RX_VLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& ALE_RD_VLAN_MASK)>> ALE_RD_VLAN_SHIFT)
define|#
directive|define
name|ALE_RX_VLAN_TAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> 4) | (((x)& 7)<< 13) | (((x)& 8)<< 9))
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Tx descriptor. */
end_comment

begin_struct
struct|struct
name|tx_desc
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
define|#
directive|define
name|ALE_TD_VLAN_MASK
value|0xFFFF0000
define|#
directive|define
name|ALE_TD_PKT_INT
value|0x00008000
define|#
directive|define
name|ALE_TD_DMA_INT
value|0x00004000
define|#
directive|define
name|ALE_TD_BUFLEN_MASK
value|0x00003FFF
define|#
directive|define
name|ALE_TD_VLAN_SHIFT
value|16
define|#
directive|define
name|ALE_TX_VLAN_TAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< 4) | ((x)>> 13) | (((x)>> 9)& 8))
define|#
directive|define
name|ALE_TD_BUFLEN_SHIFT
value|0
define|#
directive|define
name|ALE_TX_BYTES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< ALE_TD_BUFLEN_SHIFT)& ALE_TD_BUFLEN_MASK)
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|ALE_TD_MSS
value|0xFFF80000
define|#
directive|define
name|ALE_TD_TSO_HDR
value|0x00040000
define|#
directive|define
name|ALE_TD_TCPHDR_LEN
value|0x0003C000
define|#
directive|define
name|ALE_TD_IPHDR_LEN
value|0x00003C00
define|#
directive|define
name|ALE_TD_IPV6HDR_LEN2
value|0x00003C00
define|#
directive|define
name|ALE_TD_LLC_SNAP
value|0x00000200
define|#
directive|define
name|ALE_TD_VLAN_TAGGED
value|0x00000100
define|#
directive|define
name|ALE_TD_UDPCSUM
value|0x00000080
define|#
directive|define
name|ALE_TD_TCPCSUM
value|0x00000040
define|#
directive|define
name|ALE_TD_IPCSUM
value|0x00000020
define|#
directive|define
name|ALE_TD_IPV6HDR_LEN1
value|0x000000E0
define|#
directive|define
name|ALE_TD_TSO
value|0x00000010
define|#
directive|define
name|ALE_TD_CXSUM
value|0x00000008
define|#
directive|define
name|ALE_TD_INSERT_VLAN_TAG
value|0x00000004
define|#
directive|define
name|ALE_TD_IPV6
value|0x00000002
define|#
directive|define
name|ALE_TD_EOP
value|0x00000001
define|#
directive|define
name|ALE_TD_CSUM_PLOADOFFSET
value|0x00FF0000
define|#
directive|define
name|ALE_TD_CSUM_XSUMOFFSET
value|0xFF000000
define|#
directive|define
name|ALE_TD_CSUM_XSUMOFFSET_SHIFT
value|24
define|#
directive|define
name|ALE_TD_CSUM_PLOADOFFSET_SHIFT
value|16
define|#
directive|define
name|ALE_TD_MSS_SHIFT
value|19
define|#
directive|define
name|ALE_TD_TCPHDR_LEN_SHIFT
value|14
define|#
directive|define
name|ALE_TD_IPHDR_LEN_SHIFT
value|10
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_ALEREG_H */
end_comment

end_unit

