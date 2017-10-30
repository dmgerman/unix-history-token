begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_DTSEC_MII_ACC_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_DTSEC_MII_ACC_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_comment
comment|/* MII Management Configuration Register */
end_comment

begin_define
define|#
directive|define
name|MIIMCFG_RESET_MGMT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIIMCFG_MGNTCLK_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|MIIMCFG_MGNTCLK_SHIFT
value|0
end_define

begin_comment
comment|/* MII  Management Command Register */
end_comment

begin_define
define|#
directive|define
name|MIIMCOM_SCAN_CYCLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MIIMCOM_READ_CYCLE
value|0x00000001
end_define

begin_comment
comment|/* MII  Management Address Register */
end_comment

begin_define
define|#
directive|define
name|MIIMADD_PHY_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MIIMADD_PHY_ADDR_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|MIIMADD_REG_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MIIMADD_REG_ADDR_MASK
value|0x0000001f
end_define

begin_comment
comment|/* MII Management Indicator Register */
end_comment

begin_define
define|#
directive|define
name|MIIMIND_BUSY
value|0x00000001
end_define

begin_comment
comment|/* PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_CR_PHY_RESET
value|0x8000
end_define

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
name|PHY_CR_RESET_AN
value|0x0200
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

begin_define
define|#
directive|define
name|PHY_TBICON_CLK_SEL
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_TBIANA_SGMII
value|0x4001
end_define

begin_define
define|#
directive|define
name|PHY_TBIANA_1000X
value|0x01a0
end_define

begin_comment
comment|/* register map */
end_comment

begin_comment
comment|/* MII Configuration Control Memory Map Registers */
end_comment

begin_struct
struct|struct
name|dtsec_mii_reg
block|{
name|uint32_t
name|reserved1
index|[
literal|72
index|]
decl_stmt|;
name|uint32_t
name|miimcfg
decl_stmt|;
comment|/* MII Mgmt:configuration */
name|uint32_t
name|miimcom
decl_stmt|;
comment|/* MII Mgmt:command       */
name|uint32_t
name|miimadd
decl_stmt|;
comment|/* MII Mgmt:address       */
name|uint32_t
name|miimcon
decl_stmt|;
comment|/* MII Mgmt:control 3     */
name|uint32_t
name|miimstat
decl_stmt|;
comment|/* MII Mgmt:status        */
name|uint32_t
name|miimind
decl_stmt|;
comment|/* MII Mgmt:indicators    */
block|}
struct|;
end_struct

begin_comment
comment|/* dTSEC MII API */
end_comment

begin_comment
comment|/* functions to access the mii registers for phy configuration.  * this functionality may not be available for all dtsecs in the system.  * consult the reference manual for details */
end_comment

begin_function_decl
name|void
name|fman_dtsec_mii_reset
parameter_list|(
name|struct
name|dtsec_mii_reg
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* frequency is in MHz.  * note that dtsec clock is 1/2 of fman clock */
end_comment

begin_function_decl
name|void
name|fman_dtsec_mii_init
parameter_list|(
name|struct
name|dtsec_mii_reg
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|dtsec_freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_dtsec_mii_write_reg
parameter_list|(
name|struct
name|dtsec_mii_reg
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|addr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
name|data
parameter_list|,
name|uint16_t
name|dtsec_freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_dtsec_mii_read_reg
parameter_list|(
name|struct
name|dtsec_mii_reg
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|addr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|,
name|uint16_t
name|dtsec_freq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_DTSEC_MII_ACC_H */
end_comment

end_unit

