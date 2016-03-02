begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          tgec.h   @Description   FM 10G MAC ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TGEC_H
end_ifndef

begin_define
define|#
directive|define
name|__TGEC_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"tgec_mii_acc.h"
end_include

begin_include
include|#
directive|include
file|"fm_mac.h"
end_include

begin_comment
comment|/* Interrupt Mask Register (IMASK) */
end_comment

begin_define
define|#
directive|define
name|IMASK_MDIO_SCAN_EVENTMDIO
value|0x00010000
end_define

begin_comment
comment|/* MDIO_SCAN_EVENTMDIO scan event interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_MDIO_CMD_CMPL
value|0x00008000
end_define

begin_comment
comment|/* 16 MDIO_CMD_CMPL MDIO command completion interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_REM_FAULT
value|0x00004000
end_define

begin_comment
comment|/* 17 REM_FAULT Remote fault interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_LOC_FAULT
value|0x00002000
end_define

begin_comment
comment|/* 18 LOC_FAULT Local fault interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_1TX_ECC_ER
value|0x00001000
end_define

begin_comment
comment|/* 19 TX_ECC_ER Transmit frame ECC error interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_TX_FIFO_UNFL
value|0x00000800
end_define

begin_comment
comment|/* 20 TX_FIFO_UNFL Transmit FIFO underflow interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_TX_FIFO_OVFL
value|0x00000400
end_define

begin_comment
comment|/* 21 TX_FIFO_OVFL Transmit FIFO overflow interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_TX_ER
value|0x00000200
end_define

begin_comment
comment|/* 22 TX_ER Transmit frame error interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_FIFO_OVFL
value|0x00000100
end_define

begin_comment
comment|/* 23 RX_FIFO_OVFL Receive FIFO overflow interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_ECC_ER
value|0x00000080
end_define

begin_comment
comment|/* 24 RX_ECC_ER Receive frame ECC error interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_JAB_FRM
value|0x00000040
end_define

begin_comment
comment|/* 25 RX_JAB_FRM Receive jabber frame interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_OVRSZ_FRM
value|0x00000020
end_define

begin_comment
comment|/* 26 RX_OVRSZ_FRM Receive oversized frame interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_RUNT_FRM
value|0x00000010
end_define

begin_comment
comment|/* 27 RX_RUNT_FRM Receive runt frame interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_FRAG_FRM
value|0x00000008
end_define

begin_comment
comment|/* 28 RX_FRAG_FRM Receive fragment frame interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_LEN_ER
value|0x00000004
end_define

begin_comment
comment|/* 29 RX_LEN_ER Receive payload length error interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_CRC_ER
value|0x00000002
end_define

begin_comment
comment|/* 30 RX_CRC_ER Receive CRC error interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|IMASK_RX_ALIGN_ER
value|0x00000001
end_define

begin_comment
comment|/* 31 RX_ALIGN_ER Receive alignment error interrupt mask.                                                  * 0 masked                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|EVENTS_MASK
value|((uint32_t)(IMASK_MDIO_SCAN_EVENTMDIO |  \                                                 IMASK_MDIO_CMD_CMPL       |  \                                                 IMASK_REM_FAULT           |  \                                                 IMASK_LOC_FAULT           |  \                                                 IMASK_1TX_ECC_ER          |  \                                                 IMASK_TX_FIFO_UNFL        |  \                                                 IMASK_TX_FIFO_OVFL        |  \                                                 IMASK_TX_ER               |  \                                                 IMASK_RX_FIFO_OVFL        |  \                                                 IMASK_RX_ECC_ER           |  \                                                 IMASK_RX_JAB_FRM          |  \                                                 IMASK_RX_OVRSZ_FRM        |  \                                                 IMASK_RX_RUNT_FRM         |  \                                                 IMASK_RX_FRAG_FRM         |  \                                                 IMASK_RX_LEN_ER           |  \                                                 IMASK_RX_CRC_ER           |  \                                                 IMASK_RX_ALIGN_ER))
end_define

begin_define
define|#
directive|define
name|GET_EXCEPTION_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|exception
parameter_list|)
value|switch(exception){ \     case e_FM_MAC_EX_10G_MDIO_SCAN_EVENTMDIO:                                    \         bitMask = IMASK_MDIO_SCAN_EVENTMDIO; break;                              \     case e_FM_MAC_EX_10G_MDIO_CMD_CMPL:                                          \         bitMask = IMASK_MDIO_CMD_CMPL      ; break;                              \     case e_FM_MAC_EX_10G_REM_FAULT:                                              \         bitMask = IMASK_REM_FAULT          ; break;                              \     case e_FM_MAC_EX_10G_LOC_FAULT:                                              \         bitMask = IMASK_LOC_FAULT          ; break;                              \     case e_FM_MAC_EX_10G_1TX_ECC_ER:                                             \         bitMask = IMASK_1TX_ECC_ER         ; break;                              \     case e_FM_MAC_EX_10G_TX_FIFO_UNFL:                                           \         bitMask = IMASK_TX_FIFO_UNFL       ; break;                              \     case e_FM_MAC_EX_10G_TX_FIFO_OVFL:                                           \         bitMask = IMASK_TX_FIFO_OVFL       ; break;                              \     case e_FM_MAC_EX_10G_TX_ER:                                                  \         bitMask = IMASK_TX_ER              ; break;                              \     case e_FM_MAC_EX_10G_RX_FIFO_OVFL:                                           \         bitMask = IMASK_RX_FIFO_OVFL       ; break;                              \     case e_FM_MAC_EX_10G_RX_ECC_ER:                                              \         bitMask = IMASK_RX_ECC_ER          ; break;                              \     case e_FM_MAC_EX_10G_RX_JAB_FRM:                                             \         bitMask = IMASK_RX_JAB_FRM         ; break;                              \     case e_FM_MAC_EX_10G_RX_OVRSZ_FRM:                                           \         bitMask = IMASK_RX_OVRSZ_FRM       ; break;                              \     case e_FM_MAC_EX_10G_RX_RUNT_FRM:                                            \         bitMask = IMASK_RX_RUNT_FRM        ; break;                              \     case e_FM_MAC_EX_10G_RX_FRAG_FRM:                                            \         bitMask = IMASK_RX_FRAG_FRM        ; break;                              \     case e_FM_MAC_EX_10G_RX_LEN_ER:                                              \         bitMask = IMASK_RX_LEN_ER          ; break;                              \     case e_FM_MAC_EX_10G_RX_CRC_ER:                                              \         bitMask = IMASK_RX_CRC_ER          ; break;                              \     case e_FM_MAC_EX_10G_RX_ALIGN_ER:                                            \         bitMask = IMASK_RX_ALIGN_ER        ; break;                              \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/* Default Config Params */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_wanModeEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_promiscuousModeEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_pauseForwardEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_pauseIgnore
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_txAddrInsEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_loopbackEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_cmdFrameEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_rxErrorDiscard
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_phyTxenaOn
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_sendIdleEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_noLengthCheckEnable
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_lgthCheckNostdr
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_timeStampEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_rxSfdAny
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_rxPblFwd
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_txPblFwd
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_txIpgLength
value|12
end_define

begin_define
define|#
directive|define
name|DEFAULT_maxFrameLength
value|0x600
end_define

begin_define
define|#
directive|define
name|DEFAULT_debugMode
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_pauseTime
value|0xf000
end_define

begin_define
define|#
directive|define
name|DEFAULT_imask
value|0xf000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FM_TX_ECC_FRMS_ERRATA_10GMAC_A004
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_skipFman11Workaround
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_TX_ECC_FRMS_ERRATA_10GMAC_A004 */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|((uint32_t)(IMASK_MDIO_SCAN_EVENTMDIO |  \                                                 IMASK_REM_FAULT           |  \                                                 IMASK_LOC_FAULT           |  \                                                 IMASK_1TX_ECC_ER          |  \                                                 IMASK_TX_FIFO_UNFL        |  \                                                 IMASK_TX_FIFO_OVFL        |  \                                                 IMASK_TX_ER               |  \                                                 IMASK_RX_FIFO_OVFL        |  \                                                 IMASK_RX_ECC_ER           |  \                                                 IMASK_RX_JAB_FRM          |  \                                                 IMASK_RX_OVRSZ_FRM        |  \                                                 IMASK_RX_RUNT_FRM         |  \                                                 IMASK_RX_FRAG_FRM         |  \                                                 IMASK_RX_CRC_ER           |  \                                                 IMASK_RX_ALIGN_ER))
end_define

begin_define
define|#
directive|define
name|MAX_PACKET_ALIGNMENT
value|31
end_define

begin_define
define|#
directive|define
name|MAX_INTER_PACKET_GAP
value|0x7f
end_define

begin_define
define|#
directive|define
name|MAX_INTER_PALTERNATE_BEB
value|0x0f
end_define

begin_define
define|#
directive|define
name|MAX_RETRANSMISSION
value|0x0f
end_define

begin_define
define|#
directive|define
name|MAX_COLLISION_WINDOW
value|0x03ff
end_define

begin_define
define|#
directive|define
name|TGEC_NUM_OF_PADDRS
value|1
end_define

begin_comment
comment|/* number of pattern match registers (entries) */
end_comment

begin_define
define|#
directive|define
name|GROUP_ADDRESS
value|0x0000010000000000LL
end_define

begin_comment
comment|/* Group address bit indication */
end_comment

begin_define
define|#
directive|define
name|HASH_TABLE_SIZE
value|512
end_define

begin_comment
comment|/* Hash table size (= 32 bits * 8 regs) */
end_comment

begin_define
define|#
directive|define
name|TGEC_TO_MII_OFFSET
value|0x1030
end_define

begin_comment
comment|/* Offset from the MEM map to the MDIO mem map */
end_comment

begin_comment
comment|/* 10-gigabit Ethernet MAC Controller ID (10GEC_ID) */
end_comment

begin_define
define|#
directive|define
name|TGEC_ID_ID
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|TGEC_ID_MAC_VERSION
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|TGEC_ID_MAC_REV
value|0x000000ff
end_define

begin_comment
comment|/* Command and Configuration Register (COMMAND_CONFIG) */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_PBL_FWD
value|0x00800000
end_define

begin_comment
comment|/* 08 Transmit Preamble Forwarding (custom preamble).                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_RX_PBL_FWD
value|0x00400000
end_define

begin_comment
comment|/* 09 Receive Preamble Forwarding (custom preamble).                                                  */
end_comment

begin_define
define|#
directive|define
name|RX_SFD_ANY
value|0x00200000
end_define

begin_comment
comment|/* 10 Enables, when set, that any character is allowed at the SFD position of the preamble and the frame will be accepted.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_EN_TIMESTAMP
value|0x00100000
end_define

begin_comment
comment|/* 11 EN_TIMESTAMP IEEE 1588 timeStamp functionality control.                                                  * 0 disabled                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_ADDR_INS_SEL
value|0x00080000
end_define

begin_comment
comment|/* 12 TX_ADDR_INS_SEL Transmit MAC address select                                                  * 0 insert using first MAC address                                                  * 1 insert using second MAC address                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_LEN_CHK_NOSTDR
value|0x00040000
end_define

begin_comment
comment|/* 13 LEN_CHK_NOSTDR                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_NO_LEN_CHK
value|0x00020000
end_define

begin_comment
comment|/* 14 NO_LEN_CHK Payload length check disable                                                  * 0 MAC compares the frame payload length with the frame length/type field.                                                  * 1 Payload length check is disabled.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_SEND_IDLE
value|0x00010000
end_define

begin_comment
comment|/* 15 SEND_IDLE Force idle generation                                                  * 0 Normal operation.                                                 * 1 MAC permanently sends XGMII idle sequences even when faults are received.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PHY_TX_EN
value|0x00008000
end_define

begin_comment
comment|/* 16 PHY_TX_EN PHY transmit enable                                                  * 0 PHY transmit is disabled.                                                  * 1 PHY transmit is enabled.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_RX_ER_DISC
value|0x00004000
end_define

begin_comment
comment|/* 17 RX_ER_DISC Receive error frame discard enable                                                  * 0 Received error frames are processed.                                                  * 1 Any frame received with an error is discarded.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_CMD_FRM_EN
value|0x00002000
end_define

begin_comment
comment|/* 18 CMD_FRM_EN Command frame reception enable                                                  * 0 Only Pause frames are accepted (all other command frames are rejected).                                                  * 1 All command frames are accepted.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_STAT_CLR
value|0x00001000
end_define

begin_comment
comment|/* 19 STAT_CLR Clear statistics                                                  * 0 Normal operations.                                                  * 1 All statistics counters are cleared.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_LOOPBACK_EN
value|0x00000400
end_define

begin_comment
comment|/* 21 LOOPBAC_EN PHY interface loopback enable                                                  * 0 Configure PHY for normal operation.                                                  * 1 Configure PHY for loopback mode.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_ADDR_INS
value|0x00000200
end_define

begin_comment
comment|/* 22 TX_ADDR_INS Transmit source MAC address insertion                                                  * 0 MAC transmits the source MAC address unmodified.                                                  * 1 MAC overwrites the source MAC address with address specified by COMMAND_CONFIG[TX_ADDR_INS_SEL].                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PAUSE_IGNORE
value|0x00000100
end_define

begin_comment
comment|/* 23 PAUSE_IGNORE Ignore Pause frame quanta                                                  * 0 MAC stops transmit process for the duration specified in the Pause frame quanta of a received Pause frame.                                                  * 1 MAC ignores received Pause frames.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PAUSE_FWD
value|0x00000080
end_define

begin_comment
comment|/* 24 PAUSE_FWD Terminate/forward received Pause frames                                                  * 0 MAC terminates and discards received Pause frames.                                                  * 1 MAC forwards Pause frames to the user application.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_PROMIS_EN
value|0x00000010
end_define

begin_comment
comment|/* 27 PROMIS_EN Promiscuous operation enable                                                  * 0 Unicast frames with a destination address not matching the core MAC address (defined by registers, MAC_ADDR_0 and MAC_ADDR_1) are rejected.                                                  * 1 All frames are received without any MAC address filtering.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_WAN_MODE
value|0x00000008
end_define

begin_comment
comment|/* 28 WAN_MODE WAN mode enable                                                  * 0 Configure MAC for LAN mode.                                                  * 1 Configure MAC for WAN mode.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_RX_EN
value|0x00000002
end_define

begin_comment
comment|/* 30 RX_EN MAC receive path enable                                                  * 0 MAC receive path is disabled                                                  * 1 MAC receive path is enabled.                                                  */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_TX_EN
value|0x00000001
end_define

begin_comment
comment|/* 31 TX_EN MAC transmit path enable                                                  * 0 MAC transmit path is disabled                                                  * 1 MAC transmit path is enabled.                                                  */
end_comment

begin_comment
comment|/* Hashtable Control Register (HASHTABLE_CTRL) */
end_comment

begin_define
define|#
directive|define
name|HASH_CTRL_MCAST_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|HASH_CTRL_MCAST_RD
value|0x00000400
end_define

begin_comment
comment|/* 22 MCAST_READ Entry Multicast frame reception for the hash entry.                                                  * 0 disabled                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|HASH_CTRL_MCAST_EN
value|0x00000200
end_define

begin_comment
comment|/* 22 MCAST_EN Multicast frame reception for the hash entry.                                                  * 0 disabled                                                  * 1 enabled                                                  */
end_comment

begin_define
define|#
directive|define
name|HASH_ADDR_MASK
value|0x000001ff
end_define

begin_comment
comment|/* 23-31 HASH_ADDR Hash table address code.                                                  */
end_comment

begin_comment
comment|/* Transmit Inter-Packet Gap Length Register (TX_IPG_LENGTH) */
end_comment

begin_define
define|#
directive|define
name|TX_IPG_LENGTH_MASK
value|0x000003ff
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_define
define|#
directive|define
name|MEM_MAP_START
end_define

begin_comment
comment|/*  * 10G memory map  */
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
comment|/* 10Ge General Control and Status */
specifier|volatile
name|uint32_t
name|tgec_id
decl_stmt|;
comment|/* 0x000 10GEC_ID - Controller ID register */
specifier|volatile
name|uint32_t
name|scratch
decl_stmt|;
comment|/* 0x004  */
specifier|volatile
name|uint32_t
name|cmd_conf_ctrl
decl_stmt|;
comment|/* 0x008 COMMAND_CONFIG - Control and configuration register */
specifier|volatile
name|uint32_t
name|mac_addr_0
decl_stmt|;
comment|/* 0x00C MAC_ADDR_0 - Lower 32 bits of the first 48-bit MAC address */
specifier|volatile
name|uint32_t
name|mac_addr_1
decl_stmt|;
comment|/* 0x010 MAC_ADDR_1 - Upper 16 bits of the first 48-bit MAC address */
specifier|volatile
name|uint32_t
name|maxfrm
decl_stmt|;
comment|/* 0x014 MAXFRM - Maximum frame length register */
specifier|volatile
name|uint32_t
name|pause_quant
decl_stmt|;
comment|/* 0x018 PAUSE_QUANT - Pause quanta register */
specifier|volatile
name|uint32_t
name|rx_fifo_sections
decl_stmt|;
comment|/* 0x01c  */
specifier|volatile
name|uint32_t
name|tx_fifo_sections
decl_stmt|;
comment|/* 0x020  */
specifier|volatile
name|uint32_t
name|rx_fifo_almost_f_e
decl_stmt|;
comment|/* 0x024  */
specifier|volatile
name|uint32_t
name|tx_fifo_almost_f_e
decl_stmt|;
comment|/* 0x028  */
specifier|volatile
name|uint32_t
name|hashtable_ctrl
decl_stmt|;
comment|/* 0x02C HASHTABLE_CTRL - Hash table control register */
specifier|volatile
name|uint32_t
name|mdio_cfg_status
decl_stmt|;
comment|/* 0x030  */
specifier|volatile
name|uint32_t
name|mdio_command
decl_stmt|;
comment|/* 0x034  */
specifier|volatile
name|uint32_t
name|mdio_data
decl_stmt|;
comment|/* 0x038  */
specifier|volatile
name|uint32_t
name|mdio_regaddr
decl_stmt|;
comment|/* 0x03c  */
specifier|volatile
name|uint32_t
name|status
decl_stmt|;
comment|/* 0x040  */
specifier|volatile
name|uint32_t
name|tx_ipg_len
decl_stmt|;
comment|/* 0x044 TX_IPG_LENGTH - Transmitter inter-packet-gap register */
specifier|volatile
name|uint32_t
name|mac_addr_2
decl_stmt|;
comment|/* 0x048 MAC_ADDR_2 - Lower 32 bits of the second 48-bit MAC address */
specifier|volatile
name|uint32_t
name|mac_addr_3
decl_stmt|;
comment|/* 0x04C MAC_ADDR_3 - Upper 16 bits of the second 48-bit MAC address */
specifier|volatile
name|uint32_t
name|rx_fifo_ptr_rd
decl_stmt|;
comment|/* 0x050  */
specifier|volatile
name|uint32_t
name|rx_fifo_ptr_wr
decl_stmt|;
comment|/* 0x054  */
specifier|volatile
name|uint32_t
name|tx_fifo_ptr_rd
decl_stmt|;
comment|/* 0x058  */
specifier|volatile
name|uint32_t
name|tx_fifo_ptr_wr
decl_stmt|;
comment|/* 0x05c  */
specifier|volatile
name|uint32_t
name|imask
decl_stmt|;
comment|/* 0x060 IMASK - Interrupt mask register */
specifier|volatile
name|uint32_t
name|ievent
decl_stmt|;
comment|/* 0x064 IEVENT - Interrupt event register */
specifier|volatile
name|uint32_t
name|udp_port
decl_stmt|;
comment|/* 0x068 Defines a UDP Port number. When an UDP/IP frame is received with a matching UDP destination port, the receive status indication pin ff_rx_ts_frm will be asserted.*/
specifier|volatile
name|uint32_t
name|type_1588v2
decl_stmt|;
comment|/* 0x06c Type field for 1588v2 layer 2 frames. IEEE1588 defines the type 0x88f7 for 1588 frames. */
specifier|volatile
name|uint32_t
name|TENGEC_RESERVED4
index|[
literal|4
index|]
decl_stmt|;
comment|/*10Ge Statistics Counter */
specifier|volatile
name|uint64_t
name|TFRM
decl_stmt|;
comment|/* 80 aFramesTransmittedOK */
specifier|volatile
name|uint64_t
name|RFRM
decl_stmt|;
comment|/* 88 aFramesReceivedOK */
specifier|volatile
name|uint64_t
name|RFCS
decl_stmt|;
comment|/* 90 aFrameCheckSequenceErrors */
specifier|volatile
name|uint64_t
name|RALN
decl_stmt|;
comment|/* 98 aAlignmentErrors */
specifier|volatile
name|uint64_t
name|TXPF
decl_stmt|;
comment|/* A0 aPAUSEMACCtrlFramesTransmitted */
specifier|volatile
name|uint64_t
name|RXPF
decl_stmt|;
comment|/* A8 aPAUSEMACCtrlFramesReceived */
specifier|volatile
name|uint64_t
name|RLONG
decl_stmt|;
comment|/* B0 aFrameTooLongErrors */
specifier|volatile
name|uint64_t
name|RFLR
decl_stmt|;
comment|/* B8 aInRangeLengthErrors */
specifier|volatile
name|uint64_t
name|TVLAN
decl_stmt|;
comment|/* C0 VLANTransmittedOK */
specifier|volatile
name|uint64_t
name|RVLAN
decl_stmt|;
comment|/* C8 VLANReceivedOK */
specifier|volatile
name|uint64_t
name|TOCT
decl_stmt|;
comment|/* D0 ifOutOctets */
specifier|volatile
name|uint64_t
name|ROCT
decl_stmt|;
comment|/* D8 ifInOctets */
specifier|volatile
name|uint64_t
name|RUCA
decl_stmt|;
comment|/* E0 ifInUcastPkts */
specifier|volatile
name|uint64_t
name|RMCA
decl_stmt|;
comment|/* E8 ifInMulticastPkts */
specifier|volatile
name|uint64_t
name|RBCA
decl_stmt|;
comment|/* F0 ifInBroadcastPkts */
specifier|volatile
name|uint64_t
name|TERR
decl_stmt|;
comment|/* F8 ifOutErrors */
specifier|volatile
name|uint32_t
name|TENGEC_RESERVED6
index|[
literal|2
index|]
decl_stmt|;
specifier|volatile
name|uint64_t
name|TUCA
decl_stmt|;
comment|/* 108 ifOutUcastPkts */
specifier|volatile
name|uint64_t
name|TMCA
decl_stmt|;
comment|/* 110 ifOutMulticastPkts */
specifier|volatile
name|uint64_t
name|TBCA
decl_stmt|;
comment|/* 118 ifOutBroadcastPkts */
specifier|volatile
name|uint64_t
name|RDRP
decl_stmt|;
comment|/* 120 etherStatsDropEvents */
specifier|volatile
name|uint64_t
name|REOCT
decl_stmt|;
comment|/* 128 etherStatsOctets */
specifier|volatile
name|uint64_t
name|RPKT
decl_stmt|;
comment|/* 130 etherStatsPkts */
specifier|volatile
name|uint64_t
name|TRUND
decl_stmt|;
comment|/* 138 etherStatsUndersizePkts */
specifier|volatile
name|uint64_t
name|R64
decl_stmt|;
comment|/* 140 etherStatsPkts64Octets */
specifier|volatile
name|uint64_t
name|R127
decl_stmt|;
comment|/* 148 etherStatsPkts65to127Octets */
specifier|volatile
name|uint64_t
name|R255
decl_stmt|;
comment|/* 150 etherStatsPkts128to255Octets */
specifier|volatile
name|uint64_t
name|R511
decl_stmt|;
comment|/* 158 etherStatsPkts256to511Octets */
specifier|volatile
name|uint64_t
name|R1023
decl_stmt|;
comment|/* 160 etherStatsPkts512to1023Octets */
specifier|volatile
name|uint64_t
name|R1518
decl_stmt|;
comment|/* 168 etherStatsPkts1024to1518Octets */
specifier|volatile
name|uint64_t
name|R1519X
decl_stmt|;
comment|/* 170 etherStatsPkts1519toX */
specifier|volatile
name|uint64_t
name|TROVR
decl_stmt|;
comment|/* 178 etherStatsOversizePkts */
specifier|volatile
name|uint64_t
name|TRJBR
decl_stmt|;
comment|/* 180 etherStatsJabbers */
specifier|volatile
name|uint64_t
name|TRFRG
decl_stmt|;
comment|/* 188 etherStatsFragments */
specifier|volatile
name|uint64_t
name|RERR
decl_stmt|;
comment|/* 190 ifInErrors */
block|}
name|_PackedType
name|t_TgecMemMap
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEM_MAP_END
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|wanModeEnable
decl_stmt|;
comment|/* WAN Mode Enable. Sets WAN mode (1) or LAN mode (0, default) of operation. */
name|bool
name|promiscuousModeEnable
decl_stmt|;
comment|/* Enables MAC promiscuous operation. When set to '1', all frames are received without any MAC address filtering, when set to '0' (Reset value) Unicast Frames with a destination address not matching the Core MAC Address (MAC Address programmed in Registers MAC_ADDR_0 and MAC_ADDR_1 or the MAC address programmed in Registers MAC_ADDR_2 and MAC_ADDR_3 ) are rejected. */
name|bool
name|pauseForwardEnable
decl_stmt|;
comment|/* Terminate / Forward Pause Frames. If set to '1' pause frames are forwarded to the user application. When set to '0' (Reset value) pause frames are terminated and discarded within the MAC. */
name|bool
name|pauseIgnore
decl_stmt|;
comment|/* Ignore Pause Frame Quanta. If set to '1' received pause frames are ignored by the MAC. When set to '0' (Reset value) the transmit process is stopped for the amount of time specified in the pause quanta received within a pause frame. */
name|bool
name|txAddrInsEnable
decl_stmt|;
comment|/* Set Source MAC Address on Transmit.                                         If set to '1' the MAC overwrites the source MAC address received from the Client Interface with one of the MAC addresses (Refer to section 10.4)                                         If set to '0' (Reset value), the source MAC address from the Client Interface is transmitted unmodified to the line. */
name|bool
name|loopbackEnable
decl_stmt|;
comment|/* PHY Interface Loopback. When set to '1', the signal loop_ena is set to '1', when set to '0' (Reset value) the signal loop_ena is set to '0'. */
name|bool
name|cmdFrameEnable
decl_stmt|;
comment|/* Enables reception of all command frames. When set to '1' all Command Frames are accepted, when set to '0' (Reset Value) only Pause Frames are accepted and all other Command Frames are rejected. */
name|bool
name|rxErrorDiscard
decl_stmt|;
comment|/* Receive Errored Frame Discard Enable. When set to 1, any frame received with an error is discarded in the Core and not forwarded to the Client interface. When set to 0 (Reset value), errored Frames are forwarded to the Client interface with ff_rx_err asserted. */
name|bool
name|phyTxenaOn
decl_stmt|;
comment|/* PHY Transmit Enable. When set to '1', the signal phy_txena is set to '1', when set to '0' (Reset value) the signal phy_txena is set to '0' */
name|bool
name|sendIdleEnable
decl_stmt|;
comment|/* Force Idle Generation. When set to '1', the MAC permanently sends XGMII Idle sequences even when faults are received. */
name|bool
name|noLengthCheckEnable
decl_stmt|;
comment|/* Payload Length Check Disable. When set to 0 (Reset value), the Core checks the frame's payload length with the Frame Length/Type field, when set to 1, the payload length check is disabled. */
name|bool
name|lgthCheckNostdr
decl_stmt|;
comment|/* The Core interprets the Length/Type field differently depending on the value of this Bit */
name|bool
name|timeStampEnable
decl_stmt|;
comment|/* This bit selects between enabling and disabling the IEEE 1588 functionality.                                         1: IEEE 1588 is enabled.                                         0: IEEE 1588 is disabled. */
name|bool
name|rxSfdAny
decl_stmt|;
comment|/* Enables, when set, that any character is allowed at the SFD position of the preamble and the frame will be accepted.                                         If cleared (default) the frame is accepted only if the 8th byte of the preamble contains the SFD value 0xd5. If another value is received, the frame is discarded and the alignment error counter increments. */
name|bool
name|rxPblFwd
decl_stmt|;
comment|/* Receive Preamble Forwarding (custom preamble).                                         If set, the first word (ff_rx_sop) of every received frame contains the preamble of the frame. The frame data starts with the 2nd word from the FIFO.                                         If the bit is cleared (default) the preamble is removed from the frame before it is written into the receive FIFO. */
name|bool
name|txPblFwd
decl_stmt|;
comment|/* Transmit Preamble Forwarding (custom preamble).                                         If set, the first word written into the TX FIFO is considered as frame preamble. The MAC will not add a preamble in front of the frame. Note that bits 7:0 of the preamble word will still be overwritten with the XGMII start character upon transmission.                                         If cleared (default) the MAC */
name|uint32_t
name|txIpgLength
decl_stmt|;
comment|/*Transmit Inter-Packet-Gap (IPG) value.                                       A 6-bit value: Depending on LAN or WAN mode of operation (see COMMAND_CONFIG, 19.2.1 page 91) the value has the following meaning:                                         - LAN Mode: Number of octets in steps of 4. Valid values are 8, 12, 16, ... 100. DIC is fully supported (see 10.6.1 page 49) for any setting. A default of 12 (reset value) must be set to conform to IEEE802.3ae. Warning: When set to 8, PCS layers may not be able to perform clock rate compensation.                                         - WAN Mode: Stretch factor. Valid values are 4..15. The stretch factor is calculated as (value+1)*8. A default of 12 (reset value) must be set to conform to IEEE 802.3ae (i.e. 13*8=104). A larger value shrinks the IPG (increasing bandwidth). */
comment|/*.. */
name|uint16_t
name|maxFrameLength
decl_stmt|;
name|bool
name|debugMode
decl_stmt|;
name|uint16_t
name|pauseTime
decl_stmt|;
ifdef|#
directive|ifdef
name|FM_TX_ECC_FRMS_ERRATA_10GMAC_A004
name|bool
name|skipFman11Workaround
decl_stmt|;
endif|#
directive|endif
comment|/* FM_TX_ECC_FRMS_ERRATA_10GMAC_A004 */
block|}
name|t_TgecDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmMacControllerDriver
name|fmMacControllerDriver
decl_stmt|;
comment|/**< Upper Mac control block */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< Handle to the upper layer application  */
name|t_TgecMemMap
modifier|*
name|p_MemMap
decl_stmt|;
comment|/**< pointer to 10G memory mapped registers. */
name|t_TgecMiiAccessMemMap
modifier|*
name|p_MiiMemMap
decl_stmt|;
comment|/**< pointer to MII memory mapped registers.          */
name|uint64_t
name|addr
decl_stmt|;
comment|/**< MAC address of device; */
name|e_EnetMode
name|enetMode
decl_stmt|;
comment|/**< Ethernet physical interface  */
name|t_FmMacExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
name|int
name|mdioIrq
decl_stmt|;
name|t_FmMacExceptionCallback
modifier|*
name|f_Event
decl_stmt|;
name|bool
name|indAddrRegUsed
index|[
name|TGEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< Whether a particular individual address recognition register is being used */
name|uint64_t
name|paddr
index|[
name|TGEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< MAC address for particular individual address recognition register */
name|uint8_t
name|numOfIndAddrInRegs
decl_stmt|;
comment|/**< Number of individual addresses in registers for this station. */
name|t_EthHash
modifier|*
name|p_MulticastAddrHash
decl_stmt|;
comment|/**< pointer to driver's global address hash table  */
name|t_EthHash
modifier|*
name|p_UnicastAddrHash
decl_stmt|;
comment|/**< pointer to driver's individual address hash table  */
name|bool
name|debugMode
decl_stmt|;
name|uint8_t
name|macId
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|t_TgecDriverParam
modifier|*
name|p_TgecDriverParam
decl_stmt|;
block|}
name|t_Tgec
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|TGEC_MII_WritePhyReg
parameter_list|(
name|t_Handle
name|h_Tgec
parameter_list|,
name|uint8_t
name|phyAddr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|TGEC_MII_ReadPhyReg
parameter_list|(
name|t_Handle
name|h_Tgec
parameter_list|,
name|uint8_t
name|phyAddr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TGEC_H */
end_comment

end_unit

