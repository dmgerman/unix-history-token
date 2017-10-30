begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          memac.h   @Description   FM Multirate Ethernet MAC (mEMAC) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MEMAC_H
end_ifndef

begin_define
define|#
directive|define
name|__MEMAC_H
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
file|"fsl_fman_memac_mii_acc.h"
end_include

begin_include
include|#
directive|include
file|"fm_mac.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman_memac.h"
end_include

begin_define
define|#
directive|define
name|MEMAC_default_exceptions
define|\
value|((uint32_t)(MEMAC_IMASK_TSECC_ER | MEMAC_IMASK_TECC_ER | MEMAC_IMASK_RECC_ER | MEMAC_IMASK_MGI))
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
value|switch (exception){    \     case e_FM_MAC_EX_10G_1TX_ECC_ER:                                        \         bitMask = MEMAC_IMASK_TECC_ER; break;                               \     case e_FM_MAC_EX_10G_RX_ECC_ER:                                         \         bitMask = MEMAC_IMASK_RECC_ER; break;                               \     case e_FM_MAC_EX_TS_FIFO_ECC_ERR:                                       \         bitMask = MEMAC_IMASK_TSECC_ER; break;                              \     case e_FM_MAC_EX_MAGIC_PACKET_INDICATION:                               \         bitMask = MEMAC_IMASK_MGI; break;                                   \     default: bitMask = 0;break;}
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
name|memac_regs
modifier|*
name|p_MemMap
decl_stmt|;
comment|/**< Pointer to MAC memory mapped registers */
name|struct
name|memac_mii_access_mem_map
modifier|*
name|p_MiiMemMap
decl_stmt|;
comment|/**< Pointer to MII memory mapped registers */
name|uint64_t
name|addr
decl_stmt|;
comment|/**< MAC address of device */
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
name|MEMAC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< Whether a particular individual address recognition register is being used */
name|uint64_t
name|paddr
index|[
name|MEMAC_NUM_OF_PADDRS
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
comment|/**< Pointer to driver's global address hash table  */
name|t_EthHash
modifier|*
name|p_UnicastAddrHash
decl_stmt|;
comment|/**< Pointer to driver's individual address hash table  */
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
name|memac_cfg
modifier|*
name|p_MemacDriverParam
decl_stmt|;
block|}
name|t_Memac
typedef|;
end_typedef

begin_comment
comment|/* Internal PHY access */
end_comment

begin_define
define|#
directive|define
name|PHY_MDIO_ADDR
value|0
end_define

begin_comment
comment|/* Internal PHY Registers - SGMII */
end_comment

begin_define
define|#
directive|define
name|PHY_SGMII_CR_PHY_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_CR_RESET_AN
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_CR_DEF_VAL
value|0x1140
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_DEV_ABILITY_SGMII
value|0x4001
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_DEV_ABILITY_1000X
value|0x01A0
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_IF_SPEED_GIGABIT
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_IF_MODE_AN
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_IF_MODE_SGMII
value|0x0001
end_define

begin_define
define|#
directive|define
name|PHY_SGMII_IF_MODE_1000X
value|0x0000
end_define

begin_define
define|#
directive|define
name|MEMAC_TO_MII_OFFSET
value|0x030
end_define

begin_comment
comment|/* Offset from the MEM map to the MDIO mem map */
end_comment

begin_function_decl
name|t_Error
name|MEMAC_MII_WritePhyReg
parameter_list|(
name|t_Handle
name|h_Memac
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
name|MEMAC_MII_ReadPhyReg
parameter_list|(
name|t_Handle
name|h_Memac
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
comment|/* __MEMAC_H */
end_comment

end_unit

