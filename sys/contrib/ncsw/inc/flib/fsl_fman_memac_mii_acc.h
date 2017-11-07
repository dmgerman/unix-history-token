begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_MEMAC_MII_ACC_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_MEMAC_MII_ACC_H
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

begin_comment
comment|/* MII Management Registers */
end_comment

begin_define
define|#
directive|define
name|MDIO_CFG_CLK_DIV_MASK
value|0x0080ff80
end_define

begin_define
define|#
directive|define
name|MDIO_CFG_CLK_DIV_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MDIO_CFG_HOLD_MASK
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|MDIO_CFG_ENC45
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MDIO_CFG_READ_ERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MDIO_CFG_BSY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_PHY_ADDR_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_READ
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MDIO_DATA_BSY
value|0x80000000
end_define

begin_comment
comment|/*MEMAC Internal PHY Registers - SGMII */
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

begin_comment
comment|/*----------------------------------------------------*/
end_comment

begin_comment
comment|/* MII Configuration Control Memory Map Registers     */
end_comment

begin_comment
comment|/*----------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|memac_mii_access_mem_map
block|{
name|uint32_t
name|mdio_cfg
decl_stmt|;
comment|/* 0x030  */
name|uint32_t
name|mdio_ctrl
decl_stmt|;
comment|/* 0x034  */
name|uint32_t
name|mdio_data
decl_stmt|;
comment|/* 0x038  */
name|uint32_t
name|mdio_addr
decl_stmt|;
comment|/* 0x03c  */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|fman_memac_mii_read_phy_reg
parameter_list|(
name|struct
name|memac_mii_access_mem_map
modifier|*
name|mii_regs
parameter_list|,
name|uint8_t
name|phy_addr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|,
name|enum
name|enet_speed
name|enet_speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_memac_mii_write_phy_reg
parameter_list|(
name|struct
name|memac_mii_access_mem_map
modifier|*
name|mii_regs
parameter_list|,
name|uint8_t
name|phy_addr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
name|data
parameter_list|,
name|enum
name|enet_speed
name|enet_speed
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MAC_API_MEMAC_MII_ACC_H */
end_comment

end_unit

