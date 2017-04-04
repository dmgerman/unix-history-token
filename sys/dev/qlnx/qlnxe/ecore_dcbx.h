begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_DCBX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_DCBX_H__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_mcp.h"
end_include

begin_include
include|#
directive|include
file|"mcp_public.h"
end_include

begin_include
include|#
directive|include
file|"reg_addr.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hw.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_common.h"
end_include

begin_include
include|#
directive|include
file|"ecore_dcbx_api.h"
end_include

begin_struct
struct|struct
name|ecore_dcbx_info
block|{
name|struct
name|lldp_status_params_s
name|lldp_remote
index|[
name|LLDP_MAX_LLDP_AGENTS
index|]
decl_stmt|;
name|struct
name|lldp_config_params_s
name|lldp_local
index|[
name|LLDP_MAX_LLDP_AGENTS
index|]
decl_stmt|;
name|struct
name|dcbx_local_params
name|local_admin
decl_stmt|;
name|struct
name|ecore_dcbx_results
name|results
decl_stmt|;
name|struct
name|dcb_dscp_map
name|dscp_map
decl_stmt|;
name|bool
name|dscp_nig_update
decl_stmt|;
name|struct
name|dcbx_mib
name|operational
decl_stmt|;
name|struct
name|dcbx_mib
name|remote
decl_stmt|;
name|struct
name|ecore_dcbx_set
name|set
decl_stmt|;
name|struct
name|ecore_dcbx_get
name|get
decl_stmt|;
name|u8
name|dcbx_cap
decl_stmt|;
name|u16
name|iwarp_port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_dcbx_mib_meta_data
block|{
name|struct
name|lldp_config_params_s
modifier|*
name|lldp_local
decl_stmt|;
name|struct
name|lldp_status_params_s
modifier|*
name|lldp_remote
decl_stmt|;
name|struct
name|dcbx_local_params
modifier|*
name|local_admin
decl_stmt|;
name|struct
name|dcb_dscp_map
modifier|*
name|dscp_map
decl_stmt|;
name|struct
name|dcbx_mib
modifier|*
name|mib
decl_stmt|;
name|osal_size_t
name|size
decl_stmt|;
name|u32
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ECORE local interface routines */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dcbx_mib_update_event
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
parameter_list|,
name|enum
name|ecore_mib_read_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dcbx_read_lldp_params
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dcbx_info_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_dcbx_info_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_dcbx_set_pf_update_params
parameter_list|(
name|struct
name|ecore_dcbx_results
modifier|*
name|p_src
parameter_list|,
name|struct
name|pf_update_ramrod_data
modifier|*
name|p_dest
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_DCBX_H__ */
end_comment

end_unit

