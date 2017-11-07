begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MII_ACC_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__MII_ACC_EXT_H
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MII_ReadPhyReg   @Description   This routine is called to read a specified PHY                 register value.   @Param[in]     h_MiiAccess - Handle to MII configuration access registers  @Param[in]     phyAddr     - PHY address (0-31).  @Param[in]     reg         - PHY register to read  @Param[out]    p_Data      - Gets the register value.   @Return        Always zero (success). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|MII_ReadPhyReg
parameter_list|(
name|t_Handle
name|h_MiiAccess
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MII_WritePhyReg   @Description   This routine is called to write data to a specified PHY                    register.   @Param[in]     h_MiiAccess - Handle to MII configuration access registers  @Param[in]     phyAddr     - PHY address (0-31).  @Param[in]     reg         - PHY register to write  @Param[in]     data        - Data to write in register.   @Return        Always zero (success). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|MII_WritePhyReg
parameter_list|(
name|t_Handle
name|h_MiiAccess
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MII_ACC_EXT_H */
end_comment

end_unit

