begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|"enet_ext.h"
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

begin_define
define|#
directive|define
name|DEFAULT_exceptions
define|\
value|((uint32_t)(TGEC_IMASK_MDIO_SCAN_EVENT     |  \                 TGEC_IMASK_REM_FAULT           |  \                 TGEC_IMASK_LOC_FAULT           |  \                 TGEC_IMASK_TX_ECC_ER           |  \                 TGEC_IMASK_TX_FIFO_UNFL        |  \                 TGEC_IMASK_TX_FIFO_OVFL        |  \                 TGEC_IMASK_TX_ER               |  \                 TGEC_IMASK_RX_FIFO_OVFL        |  \                 TGEC_IMASK_RX_ECC_ER           |  \                 TGEC_IMASK_RX_JAB_FRM          |  \                 TGEC_IMASK_RX_OVRSZ_FRM        |  \                 TGEC_IMASK_RX_RUNT_FRM         |  \                 TGEC_IMASK_RX_FRAG_FRM         |  \                 TGEC_IMASK_RX_CRC_ER           |  \                 TGEC_IMASK_RX_ALIGN_ER))
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
value|switch (exception){ \     case e_FM_MAC_EX_10G_MDIO_SCAN_EVENTMDIO:                           \         bitMask = TGEC_IMASK_MDIO_SCAN_EVENT    ; break;                \     case e_FM_MAC_EX_10G_MDIO_CMD_CMPL:                                 \         bitMask = TGEC_IMASK_MDIO_CMD_CMPL      ; break;                \     case e_FM_MAC_EX_10G_REM_FAULT:                                     \         bitMask = TGEC_IMASK_REM_FAULT          ; break;                \     case e_FM_MAC_EX_10G_LOC_FAULT:                                     \         bitMask = TGEC_IMASK_LOC_FAULT          ; break;                \     case e_FM_MAC_EX_10G_1TX_ECC_ER:                                    \         bitMask = TGEC_IMASK_TX_ECC_ER         ; break;                 \     case e_FM_MAC_EX_10G_TX_FIFO_UNFL:                                  \         bitMask = TGEC_IMASK_TX_FIFO_UNFL       ; break;                \     case e_FM_MAC_EX_10G_TX_FIFO_OVFL:                                  \         bitMask = TGEC_IMASK_TX_FIFO_OVFL       ; break;                \     case e_FM_MAC_EX_10G_TX_ER:                                         \         bitMask = TGEC_IMASK_TX_ER              ; break;                \     case e_FM_MAC_EX_10G_RX_FIFO_OVFL:                                  \         bitMask = TGEC_IMASK_RX_FIFO_OVFL       ; break;                \     case e_FM_MAC_EX_10G_RX_ECC_ER:                                     \         bitMask = TGEC_IMASK_RX_ECC_ER          ; break;                \     case e_FM_MAC_EX_10G_RX_JAB_FRM:                                    \         bitMask = TGEC_IMASK_RX_JAB_FRM         ; break;                \     case e_FM_MAC_EX_10G_RX_OVRSZ_FRM:                                  \         bitMask = TGEC_IMASK_RX_OVRSZ_FRM       ; break;                \     case e_FM_MAC_EX_10G_RX_RUNT_FRM:                                   \         bitMask = TGEC_IMASK_RX_RUNT_FRM        ; break;                \     case e_FM_MAC_EX_10G_RX_FRAG_FRM:                                   \         bitMask = TGEC_IMASK_RX_FRAG_FRM        ; break;                \     case e_FM_MAC_EX_10G_RX_LEN_ER:                                     \         bitMask = TGEC_IMASK_RX_LEN_ER          ; break;                \     case e_FM_MAC_EX_10G_RX_CRC_ER:                                     \         bitMask = TGEC_IMASK_RX_CRC_ER          ; break;                \     case e_FM_MAC_EX_10G_RX_ALIGN_ER:                                   \         bitMask = TGEC_IMASK_RX_ALIGN_ER        ; break;                \     default: bitMask = 0;break;}
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
name|struct
name|tgec_regs
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
name|struct
name|tgec_cfg
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

