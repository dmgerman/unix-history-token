begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_MEMAC_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_MEMAC_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_include
include|#
directive|include
file|"fsl_enet.h"
end_include

begin_define
define|#
directive|define
name|MEMAC_NUM_OF_PADDRS
value|7
end_define

begin_comment
comment|/* Num of additional exact match MAC adr regs */
end_comment

begin_comment
comment|/* Control and Configuration Register (COMMAND_CONFIG) */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_MG
value|0x80000000
end_define

begin_comment
comment|/* 00 Magic Packet detection */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_REG_LOWP_RXETY
value|0x01000000
end_define

begin_comment
comment|/* 07 Rx low power indication */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_LOWP_ENA
value|0x00800000
end_define

begin_comment
comment|/* 08 Tx Low Power Idle Enable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_SFD_ANY
value|0x00200000
end_define

begin_comment
comment|/* 10 Disable SFD check */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PFC_MODE
value|0x00080000
end_define

begin_comment
comment|/* 12 Enable PFC */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_NO_LEN_CHK
value|0x00020000
end_define

begin_comment
comment|/* 14 Payload length check disable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_SEND_IDLE
value|0x00010000
end_define

begin_comment
comment|/* 15 Force idle generation */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_CNT_FRM_EN
value|0x00002000
end_define

begin_comment
comment|/* 18 Control frame rx enable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_SW_RESET
value|0x00001000
end_define

begin_comment
comment|/* 19 S/W Reset, self clearing bit */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_PAD_EN
value|0x00000800
end_define

begin_comment
comment|/* 20 Enable Tx padding of frames */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_LOOPBACK_EN
value|0x00000400
end_define

begin_comment
comment|/* 21 XGMII/GMII loopback enable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_ADDR_INS
value|0x00000200
end_define

begin_comment
comment|/* 22 Tx source MAC addr insertion */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PAUSE_IGNORE
value|0x00000100
end_define

begin_comment
comment|/* 23 Ignore Pause frame quanta */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PAUSE_FWD
value|0x00000080
end_define

begin_comment
comment|/* 24 Terminate/frwd Pause frames */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_CRC_FWD
value|0x00000040
end_define

begin_comment
comment|/* 25 Terminate/frwd CRC of frames */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PAD_EN
value|0x00000020
end_define

begin_comment
comment|/* 26 Frame padding removal */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PROMIS_EN
value|0x00000010
end_define

begin_comment
comment|/* 27 Promiscuous operation enable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_WAN_MODE
value|0x00000008
end_define

begin_comment
comment|/* 28 WAN mode enable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_RX_EN
value|0x00000002
end_define

begin_comment
comment|/* 30 MAC receive path enable */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_EN
value|0x00000001
end_define

begin_comment
comment|/* 31 MAC transmit path enable */
end_comment

begin_comment
comment|/* Transmit FIFO Sections Register (TX_FIFO_SECTIONS) */
end_comment

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_EMPTY_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_AVAIL_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_10G
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_1G
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_EMPTY_PFC_10G
value|0x00360000
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_EMPTY_PFC_1G
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_AVAIL_10G
value|0x00000019
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_AVAIL_1G
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TX_FIFO_SECTIONS_TX_AVAIL_SLOW_10G
value|0x00000060
end_define

begin_define
define|#
directive|define
name|GET_TX_EMPTY_DEFAULT_VALUE
parameter_list|(
name|_val
parameter_list|)
define|\
value|_val&= ~TX_FIFO_SECTIONS_TX_EMPTY_MASK;					\ ((_val == TX_FIFO_SECTIONS_TX_AVAIL_10G) ?					\ 		(_val |= TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_10G) :	\ 		(_val |= TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_1G));
end_define

begin_define
define|#
directive|define
name|GET_TX_EMPTY_PFC_VALUE
parameter_list|(
name|_val
parameter_list|)
define|\
value|_val&= ~TX_FIFO_SECTIONS_TX_EMPTY_MASK;					\ ((_val == TX_FIFO_SECTIONS_TX_AVAIL_10G) ?					\ 		(_val |= TX_FIFO_SECTIONS_TX_EMPTY_PFC_10G) :		\ 		(_val |= TX_FIFO_SECTIONS_TX_EMPTY_PFC_1G));
end_define

begin_comment
comment|/* Interface Mode Register (IF_MODE) */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_MASK
value|0x00000003
end_define

begin_comment
comment|/* 30-31 Mask on i/f mode bits */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_XGMII
value|0x00000000
end_define

begin_comment
comment|/* 30-31 XGMII (10G) interface */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_GMII
value|0x00000002
end_define

begin_comment
comment|/* 30-31 GMII (1G) interface */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_RGMII
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IF_MODE_RGMII_AUTO
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IF_MODE_RGMII_1000
value|0x00004000
end_define

begin_comment
comment|/* 10 - 1000Mbps RGMII */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_RGMII_100
value|0x00000000
end_define

begin_comment
comment|/* 00 - 100Mbps RGMII */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_RGMII_10
value|0x00002000
end_define

begin_comment
comment|/* 01 - 10Mbps RGMII */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_RGMII_SP_MASK
value|0x00006000
end_define

begin_comment
comment|/* Setsp mask bits */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_RGMII_FD
value|0x00001000
end_define

begin_comment
comment|/* Full duplex RGMII */
end_comment

begin_define
define|#
directive|define
name|IF_MODE_HD
value|0x00000040
end_define

begin_comment
comment|/* Half duplex operation */
end_comment

begin_comment
comment|/* Hash table Control Register (HASHTABLE_CTRL) */
end_comment

begin_define
define|#
directive|define
name|HASH_CTRL_MCAST_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|HASH_CTRL_MCAST_EN
value|0x00000100
end_define

begin_comment
comment|/* 23 Mcast frame rx for hash */
end_comment

begin_define
define|#
directive|define
name|HASH_CTRL_ADDR_MASK
value|0x0000003F
end_define

begin_comment
comment|/* 26-31 Hash table address code */
end_comment

begin_define
define|#
directive|define
name|GROUP_ADDRESS
value|0x0000010000000000LL
end_define

begin_comment
comment|/* MAC mcast indication */
end_comment

begin_define
define|#
directive|define
name|HASH_TABLE_SIZE
value|64
end_define

begin_comment
comment|/* Hash tbl size */
end_comment

begin_comment
comment|/* Transmit Inter-Packet Gap Length Register (TX_IPG_LENGTH) */
end_comment

begin_define
define|#
directive|define
name|MEMAC_TX_IPG_LENGTH_MASK
value|0x0000003F
end_define

begin_comment
comment|/* Statistics Configuration Register (STATN_CONFIG) */
end_comment

begin_define
define|#
directive|define
name|STATS_CFG_CLR
value|0x00000004
end_define

begin_comment
comment|/* 29 Reset all counters */
end_comment

begin_define
define|#
directive|define
name|STATS_CFG_CLR_ON_RD
value|0x00000002
end_define

begin_comment
comment|/* 30 Clear on read */
end_comment

begin_define
define|#
directive|define
name|STATS_CFG_SATURATE
value|0x00000001
end_define

begin_comment
comment|/* 31 Saturate at the maximum val */
end_comment

begin_comment
comment|/* Interrupt Mask Register (IMASK) */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IMASK_MGI
value|0x40000000
end_define

begin_comment
comment|/* 1 Magic pkt detect indication */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IMASK_TSECC_ER
value|0x20000000
end_define

begin_comment
comment|/* 2 Timestamp FIFO ECC error evnt */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IMASK_TECC_ER
value|0x02000000
end_define

begin_comment
comment|/* 6 Transmit frame ECC error evnt */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IMASK_RECC_ER
value|0x01000000
end_define

begin_comment
comment|/* 7 Receive frame ECC error evnt */
end_comment

begin_define
define|#
directive|define
name|MEMAC_ALL_ERRS_IMASK
define|\
value|((uint32_t)(MEMAC_IMASK_TSECC_ER	| \ 			MEMAC_IMASK_TECC_ER	| \ 			MEMAC_IMASK_RECC_ER	| \ 			MEMAC_IMASK_MGI))
end_define

begin_define
define|#
directive|define
name|MEMAC_IEVNT_PCS
value|0x80000000
end_define

begin_comment
comment|/* PCS (XG). Link sync (G) */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_AN
value|0x40000000
end_define

begin_comment
comment|/* Auto-negotiation */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_LT
value|0x20000000
end_define

begin_comment
comment|/* Link Training/New page */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_MGI
value|0x00004000
end_define

begin_comment
comment|/* Magic pkt detection */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_TS_ECC_ER
value|0x00002000
end_define

begin_comment
comment|/* Timestamp FIFO ECC error */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_RX_FIFO_OVFL
value|0x00001000
end_define

begin_comment
comment|/* Rx FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_TX_FIFO_UNFL
value|0x00000800
end_define

begin_comment
comment|/* Tx FIFO underflow */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_TX_FIFO_OVFL
value|0x00000400
end_define

begin_comment
comment|/* Tx FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_TX_ECC_ER
value|0x00000200
end_define

begin_comment
comment|/* Tx frame ECC error */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_RX_ECC_ER
value|0x00000100
end_define

begin_comment
comment|/* Rx frame ECC error */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_LI_FAULT
value|0x00000080
end_define

begin_comment
comment|/* Link Interruption flt */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_RX_EMPTY
value|0x00000040
end_define

begin_comment
comment|/* Rx FIFO empty */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_TX_EMPTY
value|0x00000020
end_define

begin_comment
comment|/* Tx FIFO empty */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_RX_LOWP
value|0x00000010
end_define

begin_comment
comment|/* Low Power Idle */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_PHY_LOS
value|0x00000004
end_define

begin_comment
comment|/* Phy loss of signal */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_REM_FAULT
value|0x00000002
end_define

begin_comment
comment|/* Remote fault (XGMII) */
end_comment

begin_define
define|#
directive|define
name|MEMAC_IEVNT_LOC_FAULT
value|0x00000001
end_define

begin_comment
comment|/* Local fault (XGMII) */
end_comment

begin_enum
enum|enum
name|memac_counters
block|{
name|E_MEMAC_COUNTER_R64
block|,
name|E_MEMAC_COUNTER_R127
block|,
name|E_MEMAC_COUNTER_R255
block|,
name|E_MEMAC_COUNTER_R511
block|,
name|E_MEMAC_COUNTER_R1023
block|,
name|E_MEMAC_COUNTER_R1518
block|,
name|E_MEMAC_COUNTER_R1519X
block|,
name|E_MEMAC_COUNTER_RFRG
block|,
name|E_MEMAC_COUNTER_RJBR
block|,
name|E_MEMAC_COUNTER_RDRP
block|,
name|E_MEMAC_COUNTER_RALN
block|,
name|E_MEMAC_COUNTER_TUND
block|,
name|E_MEMAC_COUNTER_ROVR
block|,
name|E_MEMAC_COUNTER_RXPF
block|,
name|E_MEMAC_COUNTER_TXPF
block|,
name|E_MEMAC_COUNTER_ROCT
block|,
name|E_MEMAC_COUNTER_RMCA
block|,
name|E_MEMAC_COUNTER_RBCA
block|,
name|E_MEMAC_COUNTER_RPKT
block|,
name|E_MEMAC_COUNTER_RUCA
block|,
name|E_MEMAC_COUNTER_RERR
block|,
name|E_MEMAC_COUNTER_TOCT
block|,
name|E_MEMAC_COUNTER_TMCA
block|,
name|E_MEMAC_COUNTER_TBCA
block|,
name|E_MEMAC_COUNTER_TUCA
block|,
name|E_MEMAC_COUNTER_TERR
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DEFAULT_PAUSE_QUANTA
value|0xf000
end_define

begin_define
define|#
directive|define
name|DEFAULT_FRAME_LENGTH
value|0x600
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_IPG_LENGTH
value|12
end_define

begin_comment
comment|/*  * memory map  */
end_comment

begin_struct
struct|struct
name|mac_addr
block|{
name|uint32_t
name|mac_addr_l
decl_stmt|;
comment|/* Lower 32 bits of 48-bit MAC address */
name|uint32_t
name|mac_addr_u
decl_stmt|;
comment|/* Upper 16 bits of 48-bit MAC address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|memac_regs
block|{
comment|/* General Control and Status */
name|uint32_t
name|res0000
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|command_config
decl_stmt|;
comment|/* 0x008 Ctrl and cfg */
name|struct
name|mac_addr
name|mac_addr0
decl_stmt|;
comment|/* 0x00C-0x010 MAC_ADDR_0...1 */
name|uint32_t
name|maxfrm
decl_stmt|;
comment|/* 0x014 Max frame length */
name|uint32_t
name|res0018
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|rx_fifo_sections
decl_stmt|;
comment|/* Receive FIFO configuration reg */
name|uint32_t
name|tx_fifo_sections
decl_stmt|;
comment|/* Transmit FIFO configuration reg */
name|uint32_t
name|res0024
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|hashtable_ctrl
decl_stmt|;
comment|/* 0x02C Hash table control */
name|uint32_t
name|res0030
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|ievent
decl_stmt|;
comment|/* 0x040 Interrupt event */
name|uint32_t
name|tx_ipg_length
decl_stmt|;
comment|/* 0x044 Transmitter inter-packet-gap */
name|uint32_t
name|res0048
decl_stmt|;
name|uint32_t
name|imask
decl_stmt|;
comment|/* 0x04C Interrupt mask */
name|uint32_t
name|res0050
decl_stmt|;
name|uint32_t
name|pause_quanta
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x054 Pause quanta */
name|uint32_t
name|pause_thresh
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x064 Pause quanta threshold */
name|uint32_t
name|rx_pause_status
decl_stmt|;
comment|/* 0x074 Receive pause status */
name|uint32_t
name|res0078
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|mac_addr
name|mac_addr
index|[
name|MEMAC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/* 0x80-0x0B4 mac padr */
name|uint32_t
name|lpwake_timer
decl_stmt|;
comment|/* 0x0B8 Low Power Wakeup Timer */
name|uint32_t
name|sleep_timer
decl_stmt|;
comment|/* 0x0BC Transmit EEE Low Power Timer */
name|uint32_t
name|res00c0
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|statn_config
decl_stmt|;
comment|/* 0x0E0 Statistics configuration */
name|uint32_t
name|res00e4
index|[
literal|7
index|]
decl_stmt|;
comment|/* Rx Statistics Counter */
name|uint32_t
name|reoct_l
decl_stmt|;
name|uint32_t
name|reoct_u
decl_stmt|;
name|uint32_t
name|roct_l
decl_stmt|;
name|uint32_t
name|roct_u
decl_stmt|;
name|uint32_t
name|raln_l
decl_stmt|;
name|uint32_t
name|raln_u
decl_stmt|;
name|uint32_t
name|rxpf_l
decl_stmt|;
name|uint32_t
name|rxpf_u
decl_stmt|;
name|uint32_t
name|rfrm_l
decl_stmt|;
name|uint32_t
name|rfrm_u
decl_stmt|;
name|uint32_t
name|rfcs_l
decl_stmt|;
name|uint32_t
name|rfcs_u
decl_stmt|;
name|uint32_t
name|rvlan_l
decl_stmt|;
name|uint32_t
name|rvlan_u
decl_stmt|;
name|uint32_t
name|rerr_l
decl_stmt|;
name|uint32_t
name|rerr_u
decl_stmt|;
name|uint32_t
name|ruca_l
decl_stmt|;
name|uint32_t
name|ruca_u
decl_stmt|;
name|uint32_t
name|rmca_l
decl_stmt|;
name|uint32_t
name|rmca_u
decl_stmt|;
name|uint32_t
name|rbca_l
decl_stmt|;
name|uint32_t
name|rbca_u
decl_stmt|;
name|uint32_t
name|rdrp_l
decl_stmt|;
name|uint32_t
name|rdrp_u
decl_stmt|;
name|uint32_t
name|rpkt_l
decl_stmt|;
name|uint32_t
name|rpkt_u
decl_stmt|;
name|uint32_t
name|rund_l
decl_stmt|;
name|uint32_t
name|rund_u
decl_stmt|;
name|uint32_t
name|r64_l
decl_stmt|;
name|uint32_t
name|r64_u
decl_stmt|;
name|uint32_t
name|r127_l
decl_stmt|;
name|uint32_t
name|r127_u
decl_stmt|;
name|uint32_t
name|r255_l
decl_stmt|;
name|uint32_t
name|r255_u
decl_stmt|;
name|uint32_t
name|r511_l
decl_stmt|;
name|uint32_t
name|r511_u
decl_stmt|;
name|uint32_t
name|r1023_l
decl_stmt|;
name|uint32_t
name|r1023_u
decl_stmt|;
name|uint32_t
name|r1518_l
decl_stmt|;
name|uint32_t
name|r1518_u
decl_stmt|;
name|uint32_t
name|r1519x_l
decl_stmt|;
name|uint32_t
name|r1519x_u
decl_stmt|;
name|uint32_t
name|rovr_l
decl_stmt|;
name|uint32_t
name|rovr_u
decl_stmt|;
name|uint32_t
name|rjbr_l
decl_stmt|;
name|uint32_t
name|rjbr_u
decl_stmt|;
name|uint32_t
name|rfrg_l
decl_stmt|;
name|uint32_t
name|rfrg_u
decl_stmt|;
name|uint32_t
name|rcnp_l
decl_stmt|;
name|uint32_t
name|rcnp_u
decl_stmt|;
name|uint32_t
name|rdrntp_l
decl_stmt|;
name|uint32_t
name|rdrntp_u
decl_stmt|;
name|uint32_t
name|res01d0
index|[
literal|12
index|]
decl_stmt|;
comment|/* Tx Statistics Counter */
name|uint32_t
name|teoct_l
decl_stmt|;
name|uint32_t
name|teoct_u
decl_stmt|;
name|uint32_t
name|toct_l
decl_stmt|;
name|uint32_t
name|toct_u
decl_stmt|;
name|uint32_t
name|res0210
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|txpf_l
decl_stmt|;
name|uint32_t
name|txpf_u
decl_stmt|;
name|uint32_t
name|tfrm_l
decl_stmt|;
name|uint32_t
name|tfrm_u
decl_stmt|;
name|uint32_t
name|tfcs_l
decl_stmt|;
name|uint32_t
name|tfcs_u
decl_stmt|;
name|uint32_t
name|tvlan_l
decl_stmt|;
name|uint32_t
name|tvlan_u
decl_stmt|;
name|uint32_t
name|terr_l
decl_stmt|;
name|uint32_t
name|terr_u
decl_stmt|;
name|uint32_t
name|tuca_l
decl_stmt|;
name|uint32_t
name|tuca_u
decl_stmt|;
name|uint32_t
name|tmca_l
decl_stmt|;
name|uint32_t
name|tmca_u
decl_stmt|;
name|uint32_t
name|tbca_l
decl_stmt|;
name|uint32_t
name|tbca_u
decl_stmt|;
name|uint32_t
name|res0258
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|tpkt_l
decl_stmt|;
name|uint32_t
name|tpkt_u
decl_stmt|;
name|uint32_t
name|tund_l
decl_stmt|;
name|uint32_t
name|tund_u
decl_stmt|;
name|uint32_t
name|t64_l
decl_stmt|;
name|uint32_t
name|t64_u
decl_stmt|;
name|uint32_t
name|t127_l
decl_stmt|;
name|uint32_t
name|t127_u
decl_stmt|;
name|uint32_t
name|t255_l
decl_stmt|;
name|uint32_t
name|t255_u
decl_stmt|;
name|uint32_t
name|t511_l
decl_stmt|;
name|uint32_t
name|t511_u
decl_stmt|;
name|uint32_t
name|t1023_l
decl_stmt|;
name|uint32_t
name|t1023_u
decl_stmt|;
name|uint32_t
name|t1518_l
decl_stmt|;
name|uint32_t
name|t1518_u
decl_stmt|;
name|uint32_t
name|t1519x_l
decl_stmt|;
name|uint32_t
name|t1519x_u
decl_stmt|;
name|uint32_t
name|res02a8
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|tcnp_l
decl_stmt|;
name|uint32_t
name|tcnp_u
decl_stmt|;
name|uint32_t
name|res02c8
index|[
literal|14
index|]
decl_stmt|;
comment|/* Line Interface Control */
name|uint32_t
name|if_mode
decl_stmt|;
comment|/* 0x300 Interface Mode Control */
name|uint32_t
name|if_status
decl_stmt|;
comment|/* 0x304 Interface Status */
name|uint32_t
name|res0308
index|[
literal|14
index|]
decl_stmt|;
comment|/* HiGig/2 */
name|uint32_t
name|hg_config
decl_stmt|;
comment|/* 0x340 Control and cfg */
name|uint32_t
name|res0344
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|hg_pause_quanta
decl_stmt|;
comment|/* 0x350 Pause quanta */
name|uint32_t
name|res0354
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|hg_pause_thresh
decl_stmt|;
comment|/* 0x360 Pause quanta threshold */
name|uint32_t
name|res0364
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|hgrx_pause_status
decl_stmt|;
comment|/* 0x370 Receive pause status */
name|uint32_t
name|hg_fifos_status
decl_stmt|;
comment|/* 0x374 fifos status */
name|uint32_t
name|rhm
decl_stmt|;
comment|/* 0x378 rx messages counter */
name|uint32_t
name|thm
decl_stmt|;
comment|/* 0x37C tx messages counter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|memac_cfg
block|{
name|bool
name|reset_on_init
decl_stmt|;
name|bool
name|rx_error_discard
decl_stmt|;
name|bool
name|pause_ignore
decl_stmt|;
name|bool
name|pause_forward_enable
decl_stmt|;
name|bool
name|no_length_check_enable
decl_stmt|;
name|bool
name|cmd_frame_enable
decl_stmt|;
name|bool
name|send_idle_enable
decl_stmt|;
name|bool
name|wan_mode_enable
decl_stmt|;
name|bool
name|promiscuous_mode_enable
decl_stmt|;
name|bool
name|tx_addr_ins_enable
decl_stmt|;
name|bool
name|loopback_enable
decl_stmt|;
name|bool
name|lgth_check_nostdr
decl_stmt|;
name|bool
name|time_stamp_enable
decl_stmt|;
name|bool
name|pad_enable
decl_stmt|;
name|bool
name|phy_tx_ena_on
decl_stmt|;
name|bool
name|rx_sfd_any
decl_stmt|;
name|bool
name|rx_pbl_fwd
decl_stmt|;
name|bool
name|tx_pbl_fwd
decl_stmt|;
name|bool
name|debug_mode
decl_stmt|;
name|bool
name|wake_on_lan
decl_stmt|;
name|uint16_t
name|max_frame_length
decl_stmt|;
name|uint16_t
name|pause_quanta
decl_stmt|;
name|uint32_t
name|tx_ipg_length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * fman_memac_defconfig() - Get default MEMAC configuration  * @cfg:    pointer to configuration structure.  *  * Call this function to obtain a default set of configuration values for  * initializing MEMAC. The user can overwrite any of the values before calling  * fman_memac_init(), if specific configuration needs to be applied.  */
end_comment

begin_function_decl
name|void
name|fman_memac_defconfig
parameter_list|(
name|struct
name|memac_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_memac_init
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|struct
name|memac_cfg
modifier|*
name|cfg
parameter_list|,
name|enum
name|enet_interface
name|enet_interface
parameter_list|,
name|enum
name|enet_speed
name|enet_speed
parameter_list|,
name|bool
name|slow_10g_if
parameter_list|,
name|uint32_t
name|exceptions
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_enable
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|apply_rx
parameter_list|,
name|bool
name|apply_tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_disable
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|apply_rx
parameter_list|,
name|bool
name|apply_tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_promiscuous
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_add_addr_in_paddr
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
modifier|*
name|adr
parameter_list|,
name|uint8_t
name|paddr_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_clear_addr_in_paddr
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|paddr_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|fman_memac_get_counter
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|enum
name|memac_counters
name|reg_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_tx_pause_frames
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|priority
parameter_list|,
name|uint16_t
name|pauseTime
parameter_list|,
name|uint16_t
name|threshTime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|fman_memac_get_max_frame_len
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_exception
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_reset_stat
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_reset
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_reset_filter_table
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_hash_table_entry
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|crc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_hash_table
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_rx_ignore_pause_frames
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_set_wol
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_memac_get_event
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_ack_event
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_memac_get_interrupt_mask
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_memac_adjust_link
parameter_list|(
name|struct
name|memac_regs
modifier|*
name|regs
parameter_list|,
name|enum
name|enet_interface
name|iface_mode
parameter_list|,
name|enum
name|enet_speed
name|speed
parameter_list|,
name|bool
name|full_dx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__FSL_FMAN_MEMAC_H*/
end_comment

end_unit

