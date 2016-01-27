begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:  *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.  *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_eth_alu_api API  * Ethernet Controller generic ALU API  * @ingroup group_eth  * @{  * @file   al_hal_eth_alu.h  *  * @brief Header file for control parameters for the generic ALU unit in the Ethernet Datapath for Advanced Ethernet port.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_ETH_ALU_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_ETH_ALU_H__
end_define

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* *INDENT-ON* */
enum|enum
name|AL_ETH_ALU_OPCODE
block|{
name|AL_ALU_FWD_A
init|=
literal|0
block|,
name|AL_ALU_ARITHMETIC_ADD
init|=
literal|1
block|,
name|AL_ALU_ARITHMETIC_SUBTRACT
init|=
literal|2
block|,
name|AL_ALU_BITWISE_AND
init|=
literal|3
block|,
name|AL_ALU_BITWISE_OR
init|=
literal|4
block|,
name|AL_ALU_SHIFT_RIGHT_A_BY_B
init|=
literal|5
block|,
name|AL_ALU_SHIFT_LEFT_A_BY_B
init|=
literal|6
block|,
name|AL_ALU_BITWISE_XOR
init|=
literal|7
block|,
name|AL_ALU_FWD_INV_A
init|=
literal|16
block|,
name|AL_ALU_ARITHMETIC_ADD_INV_A_AND_B
init|=
literal|17
block|,
name|AL_ALU_ARITHMETIC_SUBTRACT_INV_A_AND_B
init|=
literal|18
block|,
name|AL_ALU_BITWISE_AND_INV_A_AND_B
init|=
literal|19
block|,
name|AL_ALU_BITWISE_OR_INV_A_AND_B
init|=
literal|20
block|,
name|AL_ALU_SHIFT_RIGHT_INV_A_BY_B
init|=
literal|21
block|,
name|AL_ALU_SHIFT_LEFT_INV_A_BY_B
init|=
literal|22
block|,
name|AL_ALU_BITWISE_XOR_INV_A_AND_B
init|=
literal|23
block|,
name|AL_ALU_ARITHMETIC_ADD_A_AND_INV_B
init|=
literal|33
block|,
name|AL_ALU_ARITHMETIC_SUBTRACT_A_AND_INV_B
init|=
literal|34
block|,
name|AL_ALU_BITWISE_AND_A_AND_INV_B
init|=
literal|35
block|,
name|AL_ALU_BITWISE_OR_A_AND_INV_B
init|=
literal|36
block|,
name|AL_ALU_SHIFT_RIGHT_A_BY_INV_B
init|=
literal|37
block|,
name|AL_ALU_SHIFT_LEFT_A_BY_INV_B
init|=
literal|38
block|,
name|AL_ALU_BITWISE_XOR_A_AND_INV_B
init|=
literal|39
block|,
name|AL_ALU_ARITHMETIC_ADD_INV_A_AND_INV_B
init|=
literal|49
block|,
name|AL_ALU_ARITHMETIC_SUBTRACT_INV_A_AND
init|=
literal|50
block|,
name|AL_ALU_BITWISE_AND_INV_A_AND_INV_B
init|=
literal|51
block|,
name|AL_ALU_BITWISE_OR_INV_A_AND_INV_B
init|=
literal|52
block|,
name|AL_ALU_SHIFT_RIGHT_INV_A_BY_INV_B
init|=
literal|53
block|,
name|AL_ALU_SHIFT_LEFT_INV_A_BY_INV_B
init|=
literal|54
block|,
name|AL_ALU_BITWISE_XOR_INV_A_AND_INV_B
init|=
literal|55
block|}
enum|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_ETH_ALU_H__ */
end_comment

begin_comment
comment|/** @} end of Ethernet group */
end_comment

end_unit

