begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_SP_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_SP_API_H__
end_define

begin_include
include|#
directive|include
file|"ecore_status.h"
end_include

begin_enum
enum|enum
name|spq_mode
block|{
name|ECORE_SPQ_MODE_BLOCK
block|,
comment|/* Client will poll a designated mem. address */
name|ECORE_SPQ_MODE_CB
block|,
comment|/* Client supplies a callback */
name|ECORE_SPQ_MODE_EBLOCK
block|,
comment|/* ECORE should block until completion */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ecore_hwfn
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|event_ring_data
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|eth_slow_path_rx_cqe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ecore_spq_comp_cb
block|{
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|union
name|event_ring_data
modifier|*
parameter_list|,
name|u8
name|fw_return_code
parameter_list|)
function_decl|;
name|void
modifier|*
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_eth_cqe_completion - handles the completion of a  *        ramrod on the cqe ring  *  * @param p_hwfn  * @param cqe  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_eth_cqe_completion
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|eth_slow_path_rx_cqe
modifier|*
name|cqe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_pf_update_tunn_cfg - PF Function Tunnel configuration  *					update  Ramrod  *  * This ramrod is sent to update a tunneling configuration  * for a physical function (PF).  *  * @param p_hwfn  * @param p_ptt  * @param p_tunn - pf update tunneling parameters  * @param comp_mode - completion mode  * @param p_comp_data - callback function  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_pf_update_tunn_cfg
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|struct
name|ecore_tunnel_info
modifier|*
name|p_tunn
parameter_list|,
name|enum
name|spq_mode
name|comp_mode
parameter_list|,
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

