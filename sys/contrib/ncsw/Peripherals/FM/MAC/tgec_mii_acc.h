begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TGEC_MII_ACC_H
end_ifndef

begin_define
define|#
directive|define
name|__TGEC_MII_ACC_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/* MII  Management Command Register */
end_comment

begin_define
define|#
directive|define
name|MIIMCOM_READ_POST_INCREMENT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MIIMCOM_READ_CYCLE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MIIMCOM_SCAN_CYCLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MIIMCOM_PREAMBLE_DISABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MIIMCOM_MDIO_HOLD_1_REG_CLK
value|0
end_define

begin_define
define|#
directive|define
name|MIIMCOM_MDIO_HOLD_2_REG_CLK
value|1
end_define

begin_define
define|#
directive|define
name|MIIMCOM_MDIO_HOLD_3_REG_CLK
value|2
end_define

begin_define
define|#
directive|define
name|MIIMCOM_MDIO_HOLD_4_REG_CLK
value|3
end_define

begin_define
define|#
directive|define
name|MIIMCOM_DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|MIIMCOM_DIV_SHIFT
value|8
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

begin_define
define|#
directive|define
name|MIIMIND_READ_ERROR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MIIDATA_BUSY
value|0x80000000
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

begin_comment
comment|/*----------------------------------------------------*/
end_comment

begin_comment
comment|/* MII Configuration Control Memory Map Registers     */
end_comment

begin_comment
comment|/*----------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_TgecMiiAccessMemMap
block|{
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
block|}
name|_PackedType
name|t_TgecMiiAccessMemMap
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TGEC_MII_ACC_H */
end_comment

end_unit

