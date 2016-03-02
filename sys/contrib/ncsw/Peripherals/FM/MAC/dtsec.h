begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          dtsec.h   @Description   FM dTSEC ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTSEC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTSEC_H
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
file|"dtsec_mii_acc.h"
end_include

begin_include
include|#
directive|include
file|"fm_mac.h"
end_include

begin_define
define|#
directive|define
name|PEMASK_TSRE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IMASK_BREN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IMASK_RXCEN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IMASK_MSROEN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IMASK_GTSCEN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IMASK_BTEN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IMASK_TXCEN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IMASK_TXEEN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IMASK_LCEN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IMASK_CRLEN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IMASK_XFUNEN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IMASK_ABRTEN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IMASK_IFERREN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IMASK_MAGEN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IMASK_MMRDEN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IMASK_MMWREN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IMASK_GRSCEN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IMASK_TDPEEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IMASK_RDPEEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EVENTS_MASK
value|((uint32_t)(IMASK_BREN    | \                                                 IMASK_RXCEN   | \                                                 IMASK_MSROEN  | \                                                 IMASK_GTSCEN  | \                                                 IMASK_BTEN    | \                                                 IMASK_TXCEN   | \                                                 IMASK_TXEEN   | \                                                 IMASK_ABRTEN  | \                                                 IMASK_LCEN    | \                                                 IMASK_CRLEN   | \                                                 IMASK_XFUNEN  | \                                                 IMASK_IFERREN | \                                                 IMASK_MAGEN   | \                                                 IMASK_MMRDEN  | \                                                 IMASK_MMWREN  | \                                                 IMASK_GRSCEN  | \                                                 IMASK_TDPEEN  | \                                                 IMASK_RDPEEN))
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
value|switch(exception){ \     case e_FM_MAC_EX_1G_BAB_RX:                                   \         bitMask = IMASK_BREN; break;                              \     case e_FM_MAC_EX_1G_RX_CTL:                                   \         bitMask = IMASK_RXCEN; break;                             \     case e_FM_MAC_EX_1G_GRATEFUL_TX_STP_COMPLET:                  \         bitMask = IMASK_GTSCEN ; break;                           \     case e_FM_MAC_EX_1G_BAB_TX:                                   \         bitMask = IMASK_BTEN   ; break;                           \     case e_FM_MAC_EX_1G_TX_CTL:                                   \         bitMask = IMASK_TXCEN  ; break;                           \     case e_FM_MAC_EX_1G_TX_ERR:                                   \         bitMask = IMASK_TXEEN  ; break;                           \     case e_FM_MAC_EX_1G_LATE_COL:                                 \         bitMask = IMASK_LCEN   ; break;                           \     case e_FM_MAC_EX_1G_COL_RET_LMT:                              \         bitMask = IMASK_CRLEN  ; break;                           \     case e_FM_MAC_EX_1G_TX_FIFO_UNDRN:                            \         bitMask = IMASK_XFUNEN ; break;                           \     case e_FM_MAC_EX_1G_MAG_PCKT:                                 \         bitMask = IMASK_MAGEN ; break;                            \     case e_FM_MAC_EX_1G_MII_MNG_RD_COMPLET:                       \         bitMask = IMASK_MMRDEN; break;                            \     case e_FM_MAC_EX_1G_MII_MNG_WR_COMPLET:                       \         bitMask = IMASK_MMWREN  ; break;                          \     case e_FM_MAC_EX_1G_GRATEFUL_RX_STP_COMPLET:                  \         bitMask = IMASK_GRSCEN; break;                            \     case e_FM_MAC_EX_1G_TX_DATA_ERR:                              \         bitMask = IMASK_TDPEEN; break;                            \     case e_FM_MAC_EX_1G_RX_MIB_CNT_OVFL:                          \         bitMask = IMASK_MSROEN ; break;                           \     default: bitMask = 0;break;}
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

begin_comment
comment|/********************* From mac ext ******************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_ErrorDisable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ERROR_DISABLE_TRANSMIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_LATE_COLLISION
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_COLLISION_RETRY_LIMIT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_TxFIFO_UNDERRUN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_TxABORT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_INTERFACE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_TxDATA_PARITY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_RxDATA_PARITY
value|0x00000001
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DTSEC_NUM_OF_PADDRS
value|15
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
value|256
end_define

begin_comment
comment|/* Hash table size (= 32 bits * 8 regs) */
end_comment

begin_define
define|#
directive|define
name|DTSEC_TO_MII_OFFSET
value|0x1120
end_define

begin_comment
comment|/* number of pattern match registers (entries) */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_errorDisabled
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_promiscuousEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_pauseExtended
value|0x0
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
name|DEFAULT_halfDuplex
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_halfDulexFlowControlEn
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_txTimeStampEn
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_rxTimeStampEn
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_packetAlignment
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_controlFrameAccept
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_groupHashExtend
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_broadcReject
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_rxShortFrame
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_exactMatch
value|FALSE
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
name|DEFAULT_loopback
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_actOnRxPauseFrame
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_actOnTxPauseFrame
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PreAmLength
value|0x7
end_define

begin_define
define|#
directive|define
name|DEFAULT_PreAmRxEn
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PreAmTxEn
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_lengthCheckEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_padAndCrcEnable
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_crcEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_nonBackToBackIpg1
value|0x40
end_define

begin_define
define|#
directive|define
name|DEFAULT_nonBackToBackIpg2
value|0x60
end_define

begin_define
define|#
directive|define
name|DEFAULT_minIfgEnforcement
value|0x50
end_define

begin_define
define|#
directive|define
name|DEFAULT_backToBackIpg
value|0x60
end_define

begin_define
define|#
directive|define
name|DEFAULT_altBackoffVal
value|0x0A
end_define

begin_define
define|#
directive|define
name|DEFAULT_altBackoffEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_backPressureNoBackoff
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_noBackoff
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_excessDefer
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_maxRetransmission
value|0x0F
end_define

begin_define
define|#
directive|define
name|DEFAULT_collisionWindow
value|0x37
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
name|DEFAULT_collisionWindow
value|0x37
end_define

begin_define
define|#
directive|define
name|DEFAULT_fifoTxThr
value|0x10
end_define

begin_define
define|#
directive|define
name|DEFAULT_fifoTxWatermarkH
value|0x7e
end_define

begin_define
define|#
directive|define
name|DEFAULT_fifoRxWatermarkL
value|0x08
end_define

begin_define
define|#
directive|define
name|DEFAULT_tbiPhyAddr
value|5
end_define

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|((uint32_t)(IMASK_BREN    | \                                                     IMASK_RXCEN   | \                                                     IMASK_BTEN    | \                                                     IMASK_TXCEN   | \                                                     IMASK_TXEEN   | \                                                     IMASK_ABRTEN  | \                                                     IMASK_LCEN    | \                                                     IMASK_CRLEN   | \                                                     IMASK_XFUNEN  | \                                                     IMASK_IFERREN | \                                                     IMASK_MAGEN   | \                                                     IMASK_TDPEEN  | \                                                     IMASK_RDPEEN))
end_define

begin_define
define|#
directive|define
name|MAX_PHYS
value|32
end_define

begin_comment
comment|/* maximum number of phys */
end_comment

begin_define
define|#
directive|define
name|DTSEC_ID1_ID
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DTSEC_ID1_REV_MJ
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|DTSEC_ID1_REV_MN
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|ID2_INT_REDUCED_OFF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ID2_INT_NORMAL_OFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ECNTRL_CLRCNT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ECNTRL_AUTOZ
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ECNTRL_STEN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ECNTRL_CFG_RO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ECNTRL_GMIIM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ECNTRL_TBIM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ECNTRL_SGMIIM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ECNTRL_RPM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ECNTRL_R100M
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ECNTRL_RMM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ECNTRL_QSGMIIM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TCTRL_THDF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TCTRL_TTSE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TCTRL_GTS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TCTRL_TFC_PAUSE
value|0x00000010
end_define

begin_comment
comment|/* PTV offsets */
end_comment

begin_define
define|#
directive|define
name|PTV_PTE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|RCTRL_CFA
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RCTRL_GHTX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RCTRL_RTSE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RCTRL_GRS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RCTRL_BC_REJ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RCTRL_MPROM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RCTRL_RSF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RCTRL_EMEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RCTRL_UPROM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RCTRL_PROM
value|(RCTRL_UPROM | RCTRL_MPROM)
end_define

begin_define
define|#
directive|define
name|TMR_CTL_ESFDP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TMR_CTL_ESFDE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TSEC_ID1_DEBUG
value|0x00e00c00
end_define

begin_define
define|#
directive|define
name|DEBUG_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DPERROR_Tx_ERROR_ON_SEC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DPERROR_Tx_ERROR_ON_WRITE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DPERROR_Rx_ERROR_ON_SEC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DPERROR_Rx_ERROR_ON_WRITE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DPERROR_STT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DPERROR_STR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MACCFG1_SOFT_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MACCFG1_LOOPBACK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MACCFG1_RX_FLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MACCFG1_TX_FLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MACCFG1_TX_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MACCFG1_RX_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_RxMC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_TxMC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_RxFUN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_TxFUN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MACCFG2_NIBBLE_MODE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MACCFG2_BYTE_MODE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MACCFG2_PRE_AM_Rx_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MACCFG2_PRE_AM_Tx_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MACCFG2_LENGTH_CHECK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MACCFG2_MAGIC_PACKET_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MACCFG2_PAD_CRC_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACCFG2_CRC_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MACCFG2_FULL_DUPLEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PREAMBLE_LENGTH_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IPGIFG_MIN_IFG_ENFORCEMENT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_1
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_2
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|IPGIFG_MIN_IFG_ENFORCEMENT
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|IPGIFG_BACK_TO_BACK_IPG
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|HAFDUP_ALT_BEB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HAFDUP_BP_NO_BACKOFF
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HAFDUP_NO_BACKOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HAFDUP_EXCESS_DEFER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HAFDUP_COLLISION_WINDOW
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|HAFDUP_ALTERNATE_BEB_TRUNCATION_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HAFDUP_RETRANSMISSION_MAX_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HAFDUP_RETRANSMISSION_MAX
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|NUM_OF_HASH_REGS
value|8
end_define

begin_comment
comment|/* Number of hash table registers */
end_comment

begin_define
define|#
directive|define
name|DEBUG_GET_FIFO_READ_INDEX
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|DEBUG_GET_FIFO_WRITE_INDEX
value|0x0000007f
end_define

begin_comment
comment|/* Pause Time Value Register  */
end_comment

begin_define
define|#
directive|define
name|PTV_PTE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MASK22BIT
value|0x003FFFFF
end_define

begin_define
define|#
directive|define
name|MASK16BIT
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MASK12BIT
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|MASK8BIT
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|VAL32BIT
value|0x100000000LL
end_define

begin_define
define|#
directive|define
name|VAL22BIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|VAL16BIT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|VAL12BIT
value|0x00001000
end_define

begin_comment
comment|/* PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_CR_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_CR_SPEED0
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_CR_ANE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_CR_FULLDUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_CR_SPEED1
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_TBICON_SRESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_TBICON_SPEED2
value|0x0020
end_define

begin_comment
comment|/* CAR1/2 bits */
end_comment

begin_define
define|#
directive|define
name|CAR1_TR64
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CAR1_TR127
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CAR1_TR255
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CAR1_TR511
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CAR1_TRK1
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CAR1_TRMAX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CAR1_TRMGV
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CAR1_RBYT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CAR1_RPKT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CAR1_RMCA
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CAR1_RBCA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CAR1_RXPF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CAR1_RALN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CAR1_RFLR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CAR1_RCDE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CAR1_RCSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CAR1_RUND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CAR1_ROVR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CAR1_RFRG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CAR1_RJBR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CAR1_RDRP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CAR2_TFCS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CAR2_TBYT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CAR2_TPKT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CAR2_TMCA
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CAR2_TBCA
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CAR2_TXPF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CAR2_TDRP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CAM1_ERRORS_ONLY
value|(CAR1_RXPF |   \                             CAR1_RALN | \                             CAR1_RFLR | \                             CAR1_RCDE | \                             CAR1_RCSE | \                             CAR1_RUND | \                             CAR1_ROVR | \                             CAR1_RFRG | \                             CAR1_RJBR | \                             CAR1_RDRP)
end_define

begin_define
define|#
directive|define
name|CAM2_ERRORS_ONLY
value|(CAR2_TFCS | CAR2_TXPF | CAR2_TDRP)
end_define

begin_typedef
typedef|typedef
struct|struct
name|t_InternalStatistics
block|{
name|uint64_t
name|tr64
decl_stmt|;
name|uint64_t
name|tr127
decl_stmt|;
name|uint64_t
name|tr255
decl_stmt|;
name|uint64_t
name|tr511
decl_stmt|;
name|uint64_t
name|tr1k
decl_stmt|;
name|uint64_t
name|trmax
decl_stmt|;
name|uint64_t
name|trmgv
decl_stmt|;
name|uint64_t
name|rfrg
decl_stmt|;
name|uint64_t
name|rjbr
decl_stmt|;
name|uint64_t
name|rdrp
decl_stmt|;
name|uint64_t
name|raln
decl_stmt|;
name|uint64_t
name|rund
decl_stmt|;
name|uint64_t
name|rovr
decl_stmt|;
name|uint64_t
name|rxpf
decl_stmt|;
name|uint64_t
name|txpf
decl_stmt|;
name|uint64_t
name|rbyt
decl_stmt|;
name|uint64_t
name|rpkt
decl_stmt|;
name|uint64_t
name|rmca
decl_stmt|;
name|uint64_t
name|rbca
decl_stmt|;
name|uint64_t
name|rflr
decl_stmt|;
name|uint64_t
name|rcde
decl_stmt|;
name|uint64_t
name|rcse
decl_stmt|;
name|uint64_t
name|tbyt
decl_stmt|;
name|uint64_t
name|tpkt
decl_stmt|;
name|uint64_t
name|tmca
decl_stmt|;
name|uint64_t
name|tbca
decl_stmt|;
name|uint64_t
name|tdrp
decl_stmt|;
name|uint64_t
name|tfcs
decl_stmt|;
block|}
name|t_InternalStatistics
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|exact_match1
decl_stmt|;
comment|/* octets 1-4 */
name|uint32_t
name|exact_match2
decl_stmt|;
comment|/* octets 5-6 */
block|}
name|_PackedType
name|macRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|tsec_id1
decl_stmt|;
comment|/* 0x000 ETSEC_ID register */
specifier|volatile
name|uint32_t
name|tsec_id2
decl_stmt|;
comment|/* 0x004 ETSEC_ID2 register */
specifier|volatile
name|uint32_t
name|ievent
decl_stmt|;
comment|/* 0x008 Interrupt event register */
specifier|volatile
name|uint32_t
name|imask
decl_stmt|;
comment|/* 0x00C Interrupt mask register */
specifier|volatile
name|uint32_t
name|edis
decl_stmt|;
comment|/* 0x010 Error disabled register */
specifier|volatile
name|uint32_t
name|ecntrl
decl_stmt|;
comment|/* 0x014 E control register */
specifier|volatile
name|uint32_t
name|ptv
decl_stmt|;
comment|/* 0x018 Pause time value register */
specifier|volatile
name|uint32_t
name|tbipa
decl_stmt|;
comment|/* 0x01C TBI PHY address register */
specifier|volatile
name|uint32_t
name|tmr_ctrl
decl_stmt|;
comment|/* 0x020 Time-stamp Control register */
specifier|volatile
name|uint32_t
name|tmr_pevent
decl_stmt|;
comment|/* 0x024 Time-stamp event register */
specifier|volatile
name|uint32_t
name|tmr_pemask
decl_stmt|;
comment|/* 0x028 Timer event mask register */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED2
decl_stmt|;
comment|/* 0x02C */
specifier|volatile
name|uint32_t
name|iobistctl
decl_stmt|;
comment|/* 0x030 IO BIST Control register */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED3
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x034 */
specifier|volatile
name|uint32_t
name|tctrl
decl_stmt|;
comment|/* 0x040 Transmit control register */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED4
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x044-0x04C */
specifier|volatile
name|uint32_t
name|rctrl
decl_stmt|;
comment|/* 0x050 Receive control register */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED5
index|[
literal|11
index|]
decl_stmt|;
comment|/* 0x054- 0x07C */
specifier|volatile
name|uint32_t
name|igaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x080-0x09C Individual/group address registers 0-7 */
specifier|volatile
name|uint32_t
name|gaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x0A0-0x0BC Group address registers 0-7 */
specifier|volatile
name|uint32_t
name|ETSEC_RESERVED6
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x0C0-0x0FC */
specifier|volatile
name|uint32_t
name|maccfg1
decl_stmt|;
comment|/* 0x100 MAC configuration #1 */
specifier|volatile
name|uint32_t
name|maccfg2
decl_stmt|;
comment|/* 0x104 MAC configuration #2 */
specifier|volatile
name|uint32_t
name|ipgifg
decl_stmt|;
comment|/* 0x108 IPG/IFG */
specifier|volatile
name|uint32_t
name|hafdup
decl_stmt|;
comment|/* 0x10C Half-duplex */
specifier|volatile
name|uint32_t
name|maxfrm
decl_stmt|;
comment|/* 0x110 Maximum frame */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED7
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x114-0x11C register */
name|t_MiiAccessMemMap
name|miiMemMap
decl_stmt|;
specifier|volatile
name|uint32_t
name|ifctrl
decl_stmt|;
comment|/* 0x138 MII Mgmt:interface control */
specifier|volatile
name|uint32_t
name|ifstat
decl_stmt|;
comment|/* 0x13C Interface status */
specifier|volatile
name|uint32_t
name|macstnaddr1
decl_stmt|;
comment|/* 0x140 Station Address,part 1 */
specifier|volatile
name|uint32_t
name|macstnaddr2
decl_stmt|;
comment|/* 0x144 Station Address,part 2  */
specifier|volatile
name|macRegs
name|macaddr
index|[
name|DTSEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/* 0x148-0x1BC mac exact match addresses 1-15, parts 1-2 */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED8
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x1C0-0x1FC register */
comment|/*  RMON MIB REGISTERS  */
comment|/*  TRANSMIT and RECEIVE COUNTERS   */
specifier|volatile
name|uint32_t
name|tr64
decl_stmt|;
comment|/* 0x200 transmit and receive 64 byte frame counter */
specifier|volatile
name|uint32_t
name|tr127
decl_stmt|;
comment|/* 0x204 transmit and receive 65 to 127 byte frame counter */
specifier|volatile
name|uint32_t
name|tr255
decl_stmt|;
comment|/* 0x208 transmit and receive 128 to 255 byte frame counter */
specifier|volatile
name|uint32_t
name|tr511
decl_stmt|;
comment|/* 0x20C transmit and receive 256 to 511 byte frame counter */
specifier|volatile
name|uint32_t
name|tr1k
decl_stmt|;
comment|/* 0x210 transmit and receive 512 to 1023 byte frame counter */
specifier|volatile
name|uint32_t
name|trmax
decl_stmt|;
comment|/* 0x214 transmit and receive 1024 to 1518 byte frame counter */
specifier|volatile
name|uint32_t
name|trmgv
decl_stmt|;
comment|/* 0x218 transmit and receive 1519 to 1522 byte good VLAN frame count */
comment|/* RECEIVE COUNTERS */
specifier|volatile
name|uint32_t
name|rbyt
decl_stmt|;
comment|/* 0x21C receive byte counter */
specifier|volatile
name|uint32_t
name|rpkt
decl_stmt|;
comment|/* 0x220 receive packet counter */
specifier|volatile
name|uint32_t
name|rfcs
decl_stmt|;
comment|/* 0x224 receive FCS error counter */
specifier|volatile
name|uint32_t
name|rmca
decl_stmt|;
comment|/* 0x228 RMCA receive multicast packet counter */
specifier|volatile
name|uint32_t
name|rbca
decl_stmt|;
comment|/* 0x22C receive broadcast packet counter */
specifier|volatile
name|uint32_t
name|rxcf
decl_stmt|;
comment|/* 0x230 receive control frame packet counter */
specifier|volatile
name|uint32_t
name|rxpf
decl_stmt|;
comment|/* 0x234 receive PAUSE frame packet counter */
specifier|volatile
name|uint32_t
name|rxuo
decl_stmt|;
comment|/* 0x238 receive unknown OP code counter */
specifier|volatile
name|uint32_t
name|raln
decl_stmt|;
comment|/* 0x23C receive alignment error counter */
specifier|volatile
name|uint32_t
name|rflr
decl_stmt|;
comment|/* 0x240 receive frame length error counter */
specifier|volatile
name|uint32_t
name|rcde
decl_stmt|;
comment|/* 0x244 receive code error counter */
specifier|volatile
name|uint32_t
name|rcse
decl_stmt|;
comment|/* 0x248 receive carrier sense error counter */
specifier|volatile
name|uint32_t
name|rund
decl_stmt|;
comment|/* 0x24C receive undersize packet counter */
specifier|volatile
name|uint32_t
name|rovr
decl_stmt|;
comment|/* 0x250 receive oversize packet counter */
specifier|volatile
name|uint32_t
name|rfrg
decl_stmt|;
comment|/* 0x254 receive fragments counter */
specifier|volatile
name|uint32_t
name|rjbr
decl_stmt|;
comment|/* 0x258 receive jabber counter */
specifier|volatile
name|uint32_t
name|rdrp
decl_stmt|;
comment|/* 0x25C receive drop */
comment|/* TRANSMIT COUNTERS */
specifier|volatile
name|uint32_t
name|tbyt
decl_stmt|;
comment|/* 0x260 transmit byte counter */
specifier|volatile
name|uint32_t
name|tpkt
decl_stmt|;
comment|/* 0x264 transmit packet counter */
specifier|volatile
name|uint32_t
name|tmca
decl_stmt|;
comment|/* 0x268 transmit multicast packet counter */
specifier|volatile
name|uint32_t
name|tbca
decl_stmt|;
comment|/* 0x26C transmit broadcast packet counter */
specifier|volatile
name|uint32_t
name|txpf
decl_stmt|;
comment|/* 0x270 transmit PAUSE control frame counter */
specifier|volatile
name|uint32_t
name|tdfr
decl_stmt|;
comment|/* 0x274 transmit deferral packet counter */
specifier|volatile
name|uint32_t
name|tedf
decl_stmt|;
comment|/* 0x278 transmit excessive deferral packet counter */
specifier|volatile
name|uint32_t
name|tscl
decl_stmt|;
comment|/* 0x27C transmit single collision packet counter */
specifier|volatile
name|uint32_t
name|tmcl
decl_stmt|;
comment|/* 0x280 transmit multiple collision packet counter */
specifier|volatile
name|uint32_t
name|tlcl
decl_stmt|;
comment|/* 0x284 transmit late collision packet counter */
specifier|volatile
name|uint32_t
name|txcl
decl_stmt|;
comment|/* 0x288 transmit excessive collision packet counter */
specifier|volatile
name|uint32_t
name|tncl
decl_stmt|;
comment|/* 0x28C transmit total collision counter */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED9
decl_stmt|;
comment|/* 0x290 */
specifier|volatile
name|uint32_t
name|tdrp
decl_stmt|;
comment|/* 0x294 transmit drop frame counter */
specifier|volatile
name|uint32_t
name|tjbr
decl_stmt|;
comment|/* 0x298 transmit jabber frame counter */
specifier|volatile
name|uint32_t
name|tfcs
decl_stmt|;
comment|/* 0x29C transmit FCS error counter */
specifier|volatile
name|uint32_t
name|txcf
decl_stmt|;
comment|/* 0x2A0 transmit control frame counter */
specifier|volatile
name|uint32_t
name|tovr
decl_stmt|;
comment|/* 0x2A4 transmit oversize frame counter */
specifier|volatile
name|uint32_t
name|tund
decl_stmt|;
comment|/* 0x2A8 transmit undersize frame counter */
specifier|volatile
name|uint32_t
name|tfrg
decl_stmt|;
comment|/* 0x2AC transmit fragments frame counter */
comment|/* GENERAL REGISTERS */
specifier|volatile
name|uint32_t
name|car1
decl_stmt|;
comment|/* 0x2B0 carry register one register* */
specifier|volatile
name|uint32_t
name|car2
decl_stmt|;
comment|/* 0x2B4 carry register two register* */
specifier|volatile
name|uint32_t
name|cam1
decl_stmt|;
comment|/* 0x2B8 carry register one mask register */
specifier|volatile
name|uint32_t
name|cam2
decl_stmt|;
comment|/* 0x2BC carry register two mask register */
specifier|volatile
name|uint32_t
name|DTSEC_RESERVED10
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x2C0-0x2FC */
comment|/* Debug and Factory Test Registers */
specifier|volatile
name|uint32_t
name|debug
decl_stmt|;
comment|/* 0x300 DEBUG - Debug Register */
specifier|volatile
name|uint32_t
name|dperror
decl_stmt|;
comment|/* 0x304 DPERROR - Parity Error Register */
specifier|volatile
name|uint32_t
name|hwassert
decl_stmt|;
comment|/* 0x308 HWASSERT */
specifier|volatile
name|uint32_t
name|RESERVED11
decl_stmt|;
comment|/* 0x30C Reserved */
specifier|volatile
name|uint32_t
name|rx_fifo_ptr
decl_stmt|;
comment|/* 0x310 RXFIFOPTR - Rx FIFO R/W Pointer Register */
specifier|volatile
name|uint32_t
name|rx_fifo_dath
decl_stmt|;
comment|/* 0x314 RXFIFODATH - Rx FIFO Data Register */
specifier|volatile
name|uint32_t
name|rx_fifo_datl
decl_stmt|;
comment|/* 0x318 RXFIFODATL - Rx FIFO Data Register */
specifier|volatile
name|uint32_t
name|rx_fifo_stat
decl_stmt|;
comment|/* 0x31C RXFIFOSTAT - Rx FIFO Status Register */
specifier|volatile
name|uint32_t
name|tx_fifo_ptr
decl_stmt|;
comment|/* 0x320 TXFIFOPTR - Tx FIFO R/W Pointer Register */
specifier|volatile
name|uint32_t
name|tx_fifo_dath
decl_stmt|;
comment|/* 0x324 TXFIFODATH - Rx FIFO Data Register */
specifier|volatile
name|uint32_t
name|tx_fifo_datl
decl_stmt|;
comment|/* 0x328 TXFIFODATL - Rx FIFO Data Register */
specifier|volatile
name|uint32_t
name|tx_fifo_stat
decl_stmt|;
comment|/* 0x32C TXFIFOSTAT - Tx FIFO Status Register */
specifier|volatile
name|uint32_t
name|pkt_rcv_cnt
decl_stmt|;
comment|/* 0x330 PKTRCVCNT - Number of packets accepted and written to Rx FIFO */
specifier|volatile
name|uint32_t
name|RESERVED12
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x334-0x33C Reserved */
specifier|volatile
name|uint32_t
name|tx_threshold
decl_stmt|;
comment|/* 0x340 Transmit threshold; Number of entries (4 bytes units) before starting to transmit to the MAC */
specifier|volatile
name|uint32_t
name|tx_watermark_high
decl_stmt|;
comment|/* 0x344 Transmit watermark high; Number of entries (4 byte units) before de-asserting Ready to packet Interface */
specifier|volatile
name|uint32_t
name|rx_watermark_low
decl_stmt|;
comment|/* 0x348 Receive watermark low; Number of entries (4 byte units) before unloading to packet Interface */
block|}
name|_PackedType
name|t_DtsecMemMap
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
name|uint32_t
name|errorDisabled
decl_stmt|;
name|bool
name|halfDuplex
decl_stmt|;
name|uint16_t
name|pauseTime
decl_stmt|;
name|uint16_t
name|pauseExtended
decl_stmt|;
name|uint8_t
name|tbiPhyAddr
decl_stmt|;
comment|/**< TBI Physical address  (1-31)     [DEFAULT_tbiPhyAddr] */
name|bool
name|autoZeroCounters
decl_stmt|;
name|bool
name|promiscuousEnable
decl_stmt|;
name|bool
name|halfDulexFlowControlEn
decl_stmt|;
name|bool
name|txTimeStampEn
decl_stmt|;
name|bool
name|rxTimeStampEn
decl_stmt|;
name|uint8_t
name|packetAlignmentPadding
decl_stmt|;
name|bool
name|controlFrameAccept
decl_stmt|;
name|bool
name|groupHashExtend
decl_stmt|;
name|bool
name|broadcReject
decl_stmt|;
name|bool
name|rxShortFrame
decl_stmt|;
name|bool
name|exactMatch
decl_stmt|;
name|bool
name|debugMode
decl_stmt|;
name|bool
name|loopback
decl_stmt|;
name|bool
name|actOnRxPauseFrame
decl_stmt|;
name|bool
name|actOnTxPauseFrame
decl_stmt|;
name|uint8_t
name|nonBackToBackIpg1
decl_stmt|;
name|uint8_t
name|nonBackToBackIpg2
decl_stmt|;
name|uint8_t
name|minIfgEnforcement
decl_stmt|;
name|uint8_t
name|backToBackIpg
decl_stmt|;
name|uint8_t
name|preambleLength
decl_stmt|;
name|bool
name|preambleRxEn
decl_stmt|;
name|bool
name|preambleTxEn
decl_stmt|;
name|bool
name|lengthCheckEnable
decl_stmt|;
name|bool
name|magicPacketEnable
decl_stmt|;
name|bool
name|padAndCrcEnable
decl_stmt|;
name|bool
name|crcEnable
decl_stmt|;
name|bool
name|alternateBackoffEnable
decl_stmt|;
name|uint8_t
name|alternateBackoffVal
decl_stmt|;
name|bool
name|backPressureNoBackoff
decl_stmt|;
name|bool
name|noBackoff
decl_stmt|;
name|bool
name|excessDefer
decl_stmt|;
name|uint8_t
name|maxRetransmission
decl_stmt|;
name|uint16_t
name|collisionWindow
decl_stmt|;
name|uint16_t
name|maxFrameLength
decl_stmt|;
name|uint8_t
name|fifoTxThr
decl_stmt|;
name|uint8_t
name|fifoTxWatermarkH
decl_stmt|;
name|uint8_t
name|fifoRxWatermarkL
decl_stmt|;
block|}
name|t_DtsecDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmMacControllerDriver
name|fmMacControllerDriver
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< Handle to the upper layer application              */
name|t_DtsecMemMap
modifier|*
name|p_MemMap
decl_stmt|;
comment|/**< pointer to dTSEC memory mapped registers.          */
name|t_MiiAccessMemMap
modifier|*
name|p_MiiMemMap
decl_stmt|;
comment|/**< pointer to dTSEC MII memory mapped registers.          */
name|uint64_t
name|addr
decl_stmt|;
comment|/**< MAC address of device;                             */
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
name|DTSEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< Whether a particular individual address recognition register is being used */
name|uint64_t
name|paddr
index|[
name|DTSEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< MAC address for particular individual address recognition register */
name|uint8_t
name|numOfIndAddrInRegs
decl_stmt|;
comment|/**< Number of individual addresses in registers for this station. */
name|bool
name|debugMode
decl_stmt|;
name|bool
name|halfDuplex
decl_stmt|;
name|t_InternalStatistics
name|internalStatistics
decl_stmt|;
name|t_EthHash
modifier|*
name|p_MulticastAddrHash
decl_stmt|;
comment|/* pointer to driver's global address hash table  */
name|t_EthHash
modifier|*
name|p_UnicastAddrHash
decl_stmt|;
comment|/* pointer to driver's individual address hash table  */
name|uint8_t
name|macId
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|bool
name|ptpTsuEnabled
decl_stmt|;
name|bool
name|enTsuErrExeption
decl_stmt|;
name|e_FmMacStatisticsLevel
name|statisticsLevel
decl_stmt|;
name|t_DtsecDriverParam
modifier|*
name|p_DtsecDriverParam
decl_stmt|;
block|}
name|t_Dtsec
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|DTSEC_MII_WritePhyReg
parameter_list|(
name|t_Handle
name|h_Dtsec
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
name|DTSEC_MII_ReadPhyReg
parameter_list|(
name|t_Handle
name|h_Dtsec
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
comment|/* __DTSEC_H */
end_comment

end_unit

