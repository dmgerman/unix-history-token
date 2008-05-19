begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_AGEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_AGEREG_H
end_define

begin_comment
comment|/*  * Attansic Technology Corp. PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_ATTANSIC
value|0x1969
end_define

begin_comment
comment|/*  * Attansic L1 device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATTANSIC_L1
value|0x1048
end_define

begin_define
define|#
directive|define
name|AGE_VPD_REG_CONF_START
value|0x0100
end_define

begin_define
define|#
directive|define
name|AGE_VPD_REG_CONF_END
value|0x01FF
end_define

begin_define
define|#
directive|define
name|AGE_VPD_REG_CONF_SIG
value|0x5A
end_define

begin_define
define|#
directive|define
name|AGE_SPI_CTRL
value|0x200
end_define

begin_define
define|#
directive|define
name|SPI_STAT_NOT_READY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SPI_STAT_WR_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SPI_STAT_WRP_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SPI_INST_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|SPI_START
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SPI_INST_START
value|0x00000800
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
name|SPI_LOADER_START
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SPI_CS_HI_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SPI_CS_HOLD_MASK
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|SPI_CLK_LO_MASK
value|0x00300000
end_define

begin_define
define|#
directive|define
name|SPI_CLK_HI_MASK
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|SPI_CS_SETUP_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SPI_EPROM_PG_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|SPI_INST_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SPI_CS_HI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SPI_CS_HOLD_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|SPI_CLK_LO_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SPI_CLK_HI_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|SPI_CS_SETUP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SPI_EPROM_PG_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|SPI_WAIT_READY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AGE_SPI_ADDR
value|0x204
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_DATA
value|0x208
end_define

begin_define
define|#
directive|define
name|AGE_SPI_CONFIG
value|0x20C
end_define

begin_define
define|#
directive|define
name|AGE_SPI_OP_PROGRAM
value|0x210
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_SC_ERASE
value|0x211
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_CHIP_ERASE
value|0x212
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_RDID
value|0x213
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_WREN
value|0x214
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_RDSR
value|0x215
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_WRSR
value|0x216
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_SPI_OP_READ
value|0x217
end_define

begin_comment
comment|/* 8bits */
end_comment

begin_define
define|#
directive|define
name|AGE_TWSI_CTRL
value|0x218
end_define

begin_define
define|#
directive|define
name|AGE_DEV_MISC_CTRL
value|0x21C
end_define

begin_define
define|#
directive|define
name|AGE_MASTER_CFG
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
name|MASTER_ITIMER_ENB
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
comment|/* Number of ticks per usec for L1. */
end_comment

begin_define
define|#
directive|define
name|AGE_TICK_USECS
value|2
end_define

begin_define
define|#
directive|define
name|AGE_USECS
parameter_list|(
name|x
parameter_list|)
value|((x) / AGE_TICK_USECS)
end_define

begin_define
define|#
directive|define
name|AGE_MANUAL_TIMER
value|0x1404
end_define

begin_define
define|#
directive|define
name|AGE_IM_TIMER
value|0x1408
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|AGE_IM_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|AGE_IM_TIMER_MAX
value|130000
end_define

begin_comment
comment|/* 130ms */
end_comment

begin_define
define|#
directive|define
name|AGE_IM_TIMER_DEFAULT
value|100
end_define

begin_define
define|#
directive|define
name|AGE_GPHY_CTRL
value|0x140C
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|GPHY_CTRL_RST
value|0x0000
end_define

begin_define
define|#
directive|define
name|GPHY_CTRL_CLR
value|0x0001
end_define

begin_define
define|#
directive|define
name|AGE_INTR_CLR_TIMER
value|0x140E
end_define

begin_comment
comment|/* 16bits */
end_comment

begin_define
define|#
directive|define
name|AGE_IDLE_STATUS
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
name|AGE_MDIO
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
name|AGE_PHY_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|AGE_PHY_STATUS
value|0x1418
end_define

begin_define
define|#
directive|define
name|AGE_BIST0
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

begin_define
define|#
directive|define
name|AGE_BIST1
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
name|AGE_MAC_CFG
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
name|AGE_IPG_IFG_CFG
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
comment|/* station address */
end_comment

begin_define
define|#
directive|define
name|AGE_PAR0
value|0x1488
end_define

begin_define
define|#
directive|define
name|AGE_PAR1
value|0x148C
end_define

begin_comment
comment|/* 64bit multicast hash register. */
end_comment

begin_define
define|#
directive|define
name|AGE_MAR0
value|0x1490
end_define

begin_define
define|#
directive|define
name|AGE_MAR1
value|0x1494
end_define

begin_comment
comment|/* half-duplex parameter configuration. */
end_comment

begin_define
define|#
directive|define
name|AGE_HDPX_CFG
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
name|AGE_FRAME_SIZE
value|0x149C
end_define

begin_define
define|#
directive|define
name|AGE_WOL_CFG
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
name|AGE_PATTERN_CFG0
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
name|AGE_PATTERN_CFG1
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

begin_define
define|#
directive|define
name|AGE_SRAM_RD_ADDR
value|0x1500
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_RD_LEN
value|0x1504
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_RRD_ADDR
value|0x1508
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_RRD_LEN
value|0x150C
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TPD_ADDR
value|0x1510
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TPD_LEN
value|0x1514
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TRD_ADDR
value|0x1518
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TRD_LEN
value|0x151C
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_RX_FIFO_ADDR
value|0x1520
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_RX_FIFO_LEN
value|0x1524
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TX_FIFO_ADDR
value|0x1528
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TX_FIFO_LEN
value|0x152C
end_define

begin_define
define|#
directive|define
name|AGE_SRAM_TCPH_ADDR
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
name|AGE_DMA_BLOCK
value|0x1534
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK_LOAD
value|0x00000001
end_define

begin_comment
comment|/*  * All descriptors and CMB/SMB share the same high address.  */
end_comment

begin_define
define|#
directive|define
name|AGE_DESC_ADDR_HI
value|0x1540
end_define

begin_define
define|#
directive|define
name|AGE_DESC_RD_ADDR_LO
value|0x1544
end_define

begin_define
define|#
directive|define
name|AGE_DESC_RRD_ADDR_LO
value|0x1548
end_define

begin_define
define|#
directive|define
name|AGE_DESC_TPD_ADDR_LO
value|0x154C
end_define

begin_define
define|#
directive|define
name|AGE_DESC_CMB_ADDR_LO
value|0x1550
end_define

begin_define
define|#
directive|define
name|AGE_DESC_SMB_ADDR_LO
value|0x1554
end_define

begin_define
define|#
directive|define
name|AGE_DESC_RRD_RD_CNT
value|0x1558
end_define

begin_define
define|#
directive|define
name|DESC_RD_CNT_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|DESC_RRD_CNT_MASK
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|DESC_RD_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DESC_RRD_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AGE_DESC_TPD_CNT
value|0x155C
end_define

begin_define
define|#
directive|define
name|DESC_TPD_CNT_MASK
value|0x00003FF
end_define

begin_define
define|#
directive|define
name|DESC_TPD_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AGE_TXQ_CFG
value|0x1580
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TPD_BURST_MASK
value|0x0000001F
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
name|TXQ_CFG_TPD_FETCH_THRESH_MASK
value|0x00003F00
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
name|TXQ_CFG_TPD_FETCH_THRESH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TPD_FETCH_DEFAULT
value|16
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
name|AGE_TX_JUMBO_TPD_TH_IPG
value|0x1584
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_TPD_TH_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_TPD_IPG_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_TPD_TH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_TPD_IPG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TX_JUMBO_TPD_IPG_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|AGE_RXQ_CFG
value|0x15A0
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_BURST_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RRD_BURST_THRESH_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_PREF_MIN_IPG_MASK
value|0x001F0000
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
name|RXQ_CFG_RD_BURST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_BURST_DEFAULT
value|8
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RRD_BURST_THRESH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RRD_BURST_THRESH_DEFAULT
value|8
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_PREF_MIN_IPG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_PREF_MIN_IPG_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|AGE_RXQ_JUMBO_CFG
value|0x15A4
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_SZ_THRESH_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_LKAH_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_RRD_TIMER_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_SZ_THRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_LKAH_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_LKAH_DEFAULT
value|0x01
end_define

begin_define
define|#
directive|define
name|RXQ_JUMBO_CFG_RRD_TIMER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AGE_RXQ_FIFO_PAUSE_THRESH
value|0x15A8
end_define

begin_define
define|#
directive|define
name|RXQ_FIFO_PAUSE_THRESH_LO_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|RXQ_FIFO_PAUSE_THRESH_HI_MASK
value|0x0FFF000
end_define

begin_define
define|#
directive|define
name|RXQ_FIFO_PAUSE_THRESH_LO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RXQ_FIFO_PAUSE_THRESH_HI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AGE_RXQ_RRD_PAUSE_THRESH
value|0x15AC
end_define

begin_define
define|#
directive|define
name|RXQ_RRD_PAUSE_THRESH_HI_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|RXQ_RRD_PAUSE_THRESH_LO_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|RXQ_RRD_PAUSE_THRESH_HI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RXQ_RRD_PAUSE_THRESH_LO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AGE_DMA_CFG
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
name|DMA_CFG_RD_ENB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_ENB
value|0x00000800
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
name|AGE_CSMB_CTRL
value|0x15D0
end_define

begin_define
define|#
directive|define
name|CSMB_CTRL_CMB_KICK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CSMB_CTRL_SMB_KICK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CSMB_CTRL_CMB_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CSMB_CTRL_SMB_ENB
value|0x00000008
end_define

begin_comment
comment|/* CMB DMA Write Threshold Register */
end_comment

begin_define
define|#
directive|define
name|AGE_CMB_WR_THRESH
value|0x15D4
end_define

begin_define
define|#
directive|define
name|CMB_WR_THRESH_RRD_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|CMB_WR_THRESH_TPD_MASK
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|CMB_WR_THRESH_RRD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CMB_WR_THRESH_RRD_DEFAULT
value|4
end_define

begin_define
define|#
directive|define
name|CMB_WR_THRESH_TPD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CMB_WR_THRESH_TPD_DEFAULT
value|4
end_define

begin_comment
comment|/* RX/TX count-down timer to trigger CMB-write. */
end_comment

begin_define
define|#
directive|define
name|AGE_CMB_WR_TIMER
value|0x15D8
end_define

begin_define
define|#
directive|define
name|CMB_WR_TIMER_RX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|CMB_WR_TIMER_TX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|CMB_WR_TIMER_RX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CMB_WR_TIMER_TX_SHIFT
value|16
end_define

begin_comment
comment|/* Number of packet received since last CMB write */
end_comment

begin_define
define|#
directive|define
name|AGE_CMB_RX_PKT_CNT
value|0x15DC
end_define

begin_comment
comment|/* Number of packet transmitted since last CMB write */
end_comment

begin_define
define|#
directive|define
name|AGE_CMB_TX_PKT_CNT
value|0x15E0
end_define

begin_comment
comment|/* SMB auto DMA timer register */
end_comment

begin_define
define|#
directive|define
name|AGE_SMB_TIMER
value|0x15E4
end_define

begin_define
define|#
directive|define
name|AGE_MBOX
value|0x15F0
end_define

begin_define
define|#
directive|define
name|MBOX_RD_PROD_IDX_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|MBOX_RRD_CONS_IDX_MASK
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|MBOX_TD_PROD_IDX_MASK
value|0xFFC00000
end_define

begin_define
define|#
directive|define
name|MBOX_RD_PROD_IDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MBOX_RRD_CONS_IDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|MBOX_TD_PROD_IDX_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|AGE_INTR_STATUS
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
name|INTR_MOD_TIMER
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
name|INTR_RD_UNDERRUN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INTR_RRD_OFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_TX_FIFO_UNDERRUN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_LINK_CHG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_HOST_RD_UNDERRUN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|INTR_HOST_RRD_OFLOW
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
name|INTR_RX_DMA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_CMB_RX
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INTR_CMB_TX
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
name|INTR_DIS_SMB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|INTR_DIS_DMA
value|0x40000000
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
name|AGE_INTR_MASK
value|0x1604
end_define

begin_define
define|#
directive|define
name|AGE_INTRS
define|\
value|(INTR_SMB | INTR_DMA_RD_TO_RST | INTR_DMA_WR_TO_RST |	\ 	INTR_CMB_TX | INTR_CMB_RX)
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
name|rx_desc_oflows
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
name|uint32_t
name|updated
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Coalescing message block */
end_comment

begin_struct
struct|struct
name|cmb
block|{
name|uint32_t
name|intr_status
decl_stmt|;
name|uint32_t
name|rprod_cons
decl_stmt|;
define|#
directive|define
name|RRD_PROD_MASK
value|0x0000FFFF
define|#
directive|define
name|RD_CONS_MASK
value|0xFFFF0000
define|#
directive|define
name|RRD_PROD_SHIFT
value|0
define|#
directive|define
name|RD_CONS_SHIFT
value|16
name|uint32_t
name|tpd_cons
decl_stmt|;
define|#
directive|define
name|CMB_UPDATED
value|0x00000001
define|#
directive|define
name|TPD_CONS_MASK
value|0xFFFF0000
define|#
directive|define
name|TPD_CONS_SHIFT
value|16
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Rx return descriptor */
end_comment

begin_struct
struct|struct
name|rx_rdesc
block|{
name|uint32_t
name|index
decl_stmt|;
define|#
directive|define
name|AGE_RRD_NSEGS_MASK
value|0x000000FF
define|#
directive|define
name|AGE_RRD_CONS_MASK
value|0xFFFF0000
define|#
directive|define
name|AGE_RRD_NSEGS_SHIFT
value|0
define|#
directive|define
name|AGE_RRD_CONS_SHIFT
value|16
name|uint32_t
name|len
decl_stmt|;
define|#
directive|define
name|AGE_RRD_CSUM_MASK
value|0x0000FFFF
define|#
directive|define
name|AGE_RRD_LEN_MASK
value|0xFFFF0000
define|#
directive|define
name|AGE_RRD_CSUM_SHIFT
value|0
define|#
directive|define
name|AGE_RRD_LEN_SHIFT
value|16
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|AGE_RRD_ETHERNET
value|0x00000080
define|#
directive|define
name|AGE_RRD_VLAN
value|0x00000100
define|#
directive|define
name|AGE_RRD_ERROR
value|0x00000200
define|#
directive|define
name|AGE_RRD_IPV4
value|0x00000400
define|#
directive|define
name|AGE_RRD_UDP
value|0x00000800
define|#
directive|define
name|AGE_RRD_TCP
value|0x00001000
define|#
directive|define
name|AGE_RRD_BCAST
value|0x00002000
define|#
directive|define
name|AGE_RRD_MCAST
value|0x00004000
define|#
directive|define
name|AGE_RRD_PAUSE
value|0x00008000
define|#
directive|define
name|AGE_RRD_CRC
value|0x00010000
define|#
directive|define
name|AGE_RRD_CODE
value|0x00020000
define|#
directive|define
name|AGE_RRD_DRIBBLE
value|0x00040000
define|#
directive|define
name|AGE_RRD_RUNT
value|0x00080000
define|#
directive|define
name|AGE_RRD_OFLOW
value|0x00100000
define|#
directive|define
name|AGE_RRD_TRUNC
value|0x00200000
define|#
directive|define
name|AGE_RRD_IPCSUM_NOK
value|0x00400000
define|#
directive|define
name|AGE_RRD_TCP_UDPCSUM_NOK
value|0x00800000
define|#
directive|define
name|AGE_RRD_LENGTH_NOK
value|0x01000000
define|#
directive|define
name|AGE_RRD_DES_ADDR_FILTERED
value|0x02000000
name|uint32_t
name|vtags
decl_stmt|;
define|#
directive|define
name|AGE_RRD_VLAN_MASK
value|0xFFFF0000
define|#
directive|define
name|AGE_RRD_VLAN_SHIFT
value|16
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AGE_RX_NSEGS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& AGE_RRD_NSEGS_MASK)>> AGE_RRD_NSEGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|AGE_RX_CONS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& AGE_RRD_CONS_MASK)>> AGE_RRD_CONS_SHIFT)
end_define

begin_define
define|#
directive|define
name|AGE_RX_CSUM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& AGE_RRD_CSUM_MASK)>> AGE_RRD_CSUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|AGE_RX_BYTES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& AGE_RRD_LEN_MASK)>> AGE_RRD_LEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|AGE_RX_VLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& AGE_RRD_VLAN_MASK)>> AGE_RRD_VLAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|AGE_RX_VLAN_TAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> 4) | (((x)& 7)<< 13) | (((x)& 8)<< 9))
end_define

begin_comment
comment|/* Rx descriptor. */
end_comment

begin_struct
struct|struct
name|rx_desc
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
define|#
directive|define
name|AGE_RD_LEN_MASK
value|0x0000FFFF
define|#
directive|define
name|AGE_CONS_UPD_REQ_MASK
value|0xFFFF0000
define|#
directive|define
name|AGE_RD_LEN_SHIFT
value|0
define|#
directive|define
name|AGE_CONS_UPD_REQ_SHIFT
value|16
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
name|AGE_TD_VLAN_MASK
value|0xFFFF0000
define|#
directive|define
name|AGE_TD_PKT_INT
value|0x00008000
define|#
directive|define
name|AGE_TD_DMA_INT
value|0x00004000
define|#
directive|define
name|AGE_TD_BUFLEN_MASK
value|0x00003FFF
define|#
directive|define
name|AGE_TD_VLAN_SHIFT
value|16
define|#
directive|define
name|AGE_TX_VLAN_TAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< 4) | ((x)>> 13) | (((x)>> 9)& 8))
define|#
directive|define
name|AGE_TD_BUFLEN_SHIFT
value|0
define|#
directive|define
name|AGE_TX_BYTES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< AGE_TD_BUFLEN_SHIFT)& AGE_TD_BUFLEN_MASK)
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|AGE_TD_TSO_MSS
value|0xFFF80000
define|#
directive|define
name|AGE_TD_TSO_HDR
value|0x00040000
define|#
directive|define
name|AGE_TD_TSO_TCPHDR_LEN
value|0x0003C000
define|#
directive|define
name|AGE_TD_IPHDR_LEN
value|0x00003C00
define|#
directive|define
name|AGE_TD_LLC_SNAP
value|0x00000200
define|#
directive|define
name|AGE_TD_VLAN_TAGGED
value|0x00000100
define|#
directive|define
name|AGE_TD_UDPCSUM
value|0x00000080
define|#
directive|define
name|AGE_TD_TCPCSUM
value|0x00000040
define|#
directive|define
name|AGE_TD_IPCSUM
value|0x00000020
define|#
directive|define
name|AGE_TD_TSO_IPV4
value|0x00000010
define|#
directive|define
name|AGE_TD_TSO_IPV6
value|0x00000012
define|#
directive|define
name|AGE_TD_CSUM
value|0x00000008
define|#
directive|define
name|AGE_TD_INSERT_VLAN_TAG
value|0x00000004
define|#
directive|define
name|AGE_TD_COALESCE
value|0x00000002
define|#
directive|define
name|AGE_TD_EOP
value|0x00000001
define|#
directive|define
name|AGE_TD_CSUM_PLOADOFFSET
value|0x00FF0000
define|#
directive|define
name|AGE_TD_CSUM_XSUMOFFSET
value|0xFF000000
define|#
directive|define
name|AGE_TD_CSUM_XSUMOFFSET_SHIFT
value|24
define|#
directive|define
name|AGE_TD_CSUM_PLOADOFFSET_SHIFT
value|16
define|#
directive|define
name|AGE_TD_TSO_MSS_SHIFT
value|19
define|#
directive|define
name|AGE_TD_TSO_TCPHDR_LEN_SHIFT
value|14
define|#
directive|define
name|AGE_TD_IPHDR_LEN_SHIFT
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
comment|/* _IF_AGEREG_H */
end_comment

end_unit

