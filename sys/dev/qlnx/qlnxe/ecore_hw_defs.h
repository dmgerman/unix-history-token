begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ECORE_IGU_DEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_ECORE_IGU_DEF_H_
end_define

begin_comment
comment|/* Fields of IGU PF CONFIGRATION REGISTER */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_FUNC_EN
value|(0x1<<0)
end_define

begin_comment
comment|/* function enable        */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_MSI_MSIX_EN
value|(0x1<<1)
end_define

begin_comment
comment|/* MSI/MSIX enable        */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_INT_LINE_EN
value|(0x1<<2)
end_define

begin_comment
comment|/* INT enable             */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_ATTN_BIT_EN
value|(0x1<<3)
end_define

begin_comment
comment|/* attention enable       */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_SINGLE_ISR_EN
value|(0x1<<4)
end_define

begin_comment
comment|/* single ISR mode enable */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_SIMD_MODE
value|(0x1<<5)
end_define

begin_comment
comment|/* simd all ones mode     */
end_comment

begin_comment
comment|/* Fields of IGU VF CONFIGRATION REGISTER */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_FUNC_EN
value|(0x1<<0)
end_define

begin_comment
comment|/* function enable        */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_MSI_MSIX_EN
value|(0x1<<1)
end_define

begin_comment
comment|/* MSI/MSIX enable        */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_SINGLE_ISR_EN
value|(0x1<<4)
end_define

begin_comment
comment|/* single ISR mode enable */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_PARENT_MASK
value|(0xF)
end_define

begin_comment
comment|/* Parent PF              */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_PARENT_SHIFT
value|5
end_define

begin_comment
comment|/* Parent PF              */
end_comment

begin_comment
comment|/* Igu control commands  */
end_comment

begin_enum
enum|enum
name|igu_ctrl_cmd
block|{
name|IGU_CTRL_CMD_TYPE_RD
block|,
name|IGU_CTRL_CMD_TYPE_WR
block|,
name|MAX_IGU_CTRL_CMD
block|}
enum|;
end_enum

begin_comment
comment|/* Control register for the IGU command register  */
end_comment

begin_struct
struct|struct
name|igu_ctrl_reg
block|{
name|u32
name|ctrl_data
decl_stmt|;
define|#
directive|define
name|IGU_CTRL_REG_FID_MASK
value|0xFFFF
comment|/* Opaque_FID	 */
define|#
directive|define
name|IGU_CTRL_REG_FID_SHIFT
value|0
define|#
directive|define
name|IGU_CTRL_REG_PXP_ADDR_MASK
value|0xFFF
comment|/* Command address */
define|#
directive|define
name|IGU_CTRL_REG_PXP_ADDR_SHIFT
value|16
define|#
directive|define
name|IGU_CTRL_REG_RESERVED_MASK
value|0x1
define|#
directive|define
name|IGU_CTRL_REG_RESERVED_SHIFT
value|28
define|#
directive|define
name|IGU_CTRL_REG_TYPE_MASK
value|0x1
comment|/* use enum igu_ctrl_cmd */
define|#
directive|define
name|IGU_CTRL_REG_TYPE_SHIFT
value|31
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

