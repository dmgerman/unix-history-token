begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_ISCSI_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_ISCSI_H__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_chain.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_common.h"
end_include

begin_include
include|#
directive|include
file|"tcp_common.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_iscsi.h"
end_include

begin_include
include|#
directive|include
file|"ecore_sp_commands.h"
end_include

begin_include
include|#
directive|include
file|"ecore_iscsi_api.h"
end_include

begin_struct
struct|struct
name|ecore_iscsi_info
block|{
name|osal_spinlock_t
name|lock
decl_stmt|;
name|osal_list_t
name|free_list
decl_stmt|;
name|u16
name|max_num_outstanding_tasks
decl_stmt|;
name|void
modifier|*
name|event_context
decl_stmt|;
name|iscsi_event_cb_t
name|event_cb
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_iscsi_alloc
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
name|ecore_iscsi_setup
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
name|ecore_iscsi_free
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
name|ecore_iscsi_free_connection
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_iscsi_conn
modifier|*
name|p_conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_iscsi_conn_offload - iSCSI connection offload  *  * This ramrod offloads iSCSI connection to FW  *  * @param p_path  * @param p_conn  * @param comp_mode  * @param comp_addr  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_iscsi_conn_offload
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_iscsi_conn
modifier|*
name|p_conn
parameter_list|,
name|enum
name|spq_mode
name|comp_mode
parameter_list|,
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_iscsi_conn_update - iSCSI connection update  *  * This ramrod updatess iSCSI ofloadedconnection in FW  *  * @param p_path  * @param p_conn  * @param comp_mode  * @param comp_addr  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_iscsi_conn_update
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_iscsi_conn
modifier|*
name|p_conn
parameter_list|,
name|enum
name|spq_mode
name|comp_mode
parameter_list|,
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_iscsi_mac_update - iSCSI connection's MAC update  *  * This ramrod updates remote MAC for iSCSI offloaded connection in FW  *  * @param p_path  * @param p_conn  * @param comp_mode  * @param comp_addr  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_iscsi_mac_update
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_iscsi_conn
modifier|*
name|p_conn
parameter_list|,
name|enum
name|spq_mode
name|comp_mode
parameter_list|,
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_iscsi_conn_terminate - iSCSI connection  *        terminate  *  * This ramrod deletes iSCSI offloaded connection in FW  *  * @param p_path  * @param p_conn  * @param comp_mode  * @param comp_addr  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_iscsi_conn_terminate
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_iscsi_conn
modifier|*
name|p_conn
parameter_list|,
name|enum
name|spq_mode
name|comp_mode
parameter_list|,
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_iscsi_conn_clear_sq - iSCSI connection  *        clear SQ  *  * This ramrod clears connection's SQ in FW  *  * @param p_path  * @param p_conn  * @param comp_mode  * @param comp_addr  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_iscsi_conn_clear_sq
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_iscsi_conn
modifier|*
name|p_conn
parameter_list|,
name|enum
name|spq_mode
name|comp_mode
parameter_list|,
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__ECORE_ISCSI_H__*/
end_comment

end_unit

