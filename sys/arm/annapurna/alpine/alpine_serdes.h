begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015,2016 Annapurna Labs Ltd. and affiliates  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ALPINE_SERDES_H__
end_ifndef

begin_define
define|#
directive|define
name|__ALPINE_SERDES_H__
end_define

begin_comment
comment|/* SerDes ETH mode */
end_comment

begin_enum
enum|enum
name|alpine_serdes_eth_mode
block|{
name|ALPINE_SERDES_ETH_MODE_SGMII
block|,
name|ALPINE_SERDES_ETH_MODE_KR
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Get SerDes group regs base, to be used in relevant Alpine drivers.  * Valid group is 0..3.  * Returns virtual base address of the group regs base.  */
end_comment

begin_function_decl
name|void
modifier|*
name|alpine_serdes_resource_get
parameter_list|(
name|uint32_t
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set SerDes ETH mode for an entire group, unless already set  * Valid group is 0..3.  * Returns 0 upon success.  */
end_comment

begin_function_decl
name|int
name|alpine_serdes_eth_mode_set
parameter_list|(
name|uint32_t
name|group
parameter_list|,
name|enum
name|alpine_serdes_eth_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lock the all serdes group for using common registers */
end_comment

begin_function_decl
name|void
name|alpine_serdes_eth_group_lock
parameter_list|(
name|uint32_t
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unlock the all serdes group for using common registers */
end_comment

begin_function_decl
name|void
name|alpine_serdes_eth_group_unlock
parameter_list|(
name|uint32_t
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ALPINE_SERDES_H__ */
end_comment

end_unit

