begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_PHY_H_
end_define

begin_include
include|#
directive|include
file|"ixgbe_type.h"
end_include

begin_function_decl
name|s32
name|ixgbe_init_shared_code_phy
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_assign_func_pointers_phy
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_phy_link
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_check_phy_link
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
modifier|*
name|speed
parameter_list|,
name|bool
modifier|*
name|link_up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_phy_link_speed
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
name|speed
parameter_list|,
name|bool
name|autoneg
parameter_list|,
name|bool
name|autoneg_wait_to_complete
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixgbe_validate_phy_addr
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|phy_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|ixgbe_phy_type
name|ixgbe_get_phy_type_from_id
parameter_list|(
name|u32
name|phy_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_phy_id
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_identify_phy_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_reset_phy_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_read_phy_reg_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg_addr
parameter_list|,
name|u32
name|device_type
parameter_list|,
name|u16
modifier|*
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_write_phy_reg_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg_addr
parameter_list|,
name|u32
name|device_type
parameter_list|,
name|u16
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PHY specific */
end_comment

begin_function_decl
name|s32
name|ixgbe_setup_tnx_phy_link
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_check_tnx_phy_link
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
modifier|*
name|speed
parameter_list|,
name|bool
modifier|*
name|link_up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_tnx_phy_link_speed
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
name|speed
parameter_list|,
name|bool
name|autoneg
parameter_list|,
name|bool
name|autoneg_wait_to_complete
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_PHY_H_ */
end_comment

end_unit

