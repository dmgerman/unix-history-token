begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ECORE_CID_
end_ifndef

begin_define
define|#
directive|define
name|_ECORE_CID_
end_define

begin_include
include|#
directive|include
file|"ecore_hsi_common.h"
end_include

begin_include
include|#
directive|include
file|"ecore_proto_if.h"
end_include

begin_include
include|#
directive|include
file|"ecore_cxt_api.h"
end_include

begin_comment
comment|/* Tasks segments definitions  */
end_comment

begin_define
define|#
directive|define
name|ECORE_CXT_ISCSI_TID_SEG
value|PROTOCOLID_ISCSI
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|ECORE_CXT_FCOE_TID_SEG
value|PROTOCOLID_FCOE
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|ECORE_CXT_ROCE_TID_SEG
value|PROTOCOLID_ROCE
end_define

begin_comment
comment|/* 2 */
end_comment

begin_enum
enum|enum
name|ecore_cxt_elem_type
block|{
name|ECORE_ELEM_CXT
block|,
name|ECORE_ELEM_SRQ
block|,
name|ECORE_ELEM_TASK
block|}
enum|;
end_enum

begin_function_decl
name|u32
name|ecore_cxt_get_proto_cid_count
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|protocol_type
name|type
parameter_list|,
name|u32
modifier|*
name|vf_cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ecore_cxt_get_proto_tid_count
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|protocol_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ecore_cxt_get_proto_cid_start
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|protocol_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ecore_cxt_get_srq_count
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_set_pf_params - Set the PF params for cxt init  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_set_pf_params
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|rdma_tasks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_cfg_ilt_compute - compute ILT init parameters  *  * @param p_hwfn  * @param last_line  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_cfg_ilt_compute
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
modifier|*
name|last_line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_cfg_ilt_compute_excess - how many lines can be decreased  *  * @param p_hwfn  * @param used_lines  */
end_comment

begin_function_decl
name|u32
name|ecore_cxt_cfg_ilt_compute_excess
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|used_lines
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_mngr_alloc - Allocate and init the context manager struct  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_mngr_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_mngr_free  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_cxt_mngr_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_tables_alloc - Allocate ILT shadow, Searcher T2, acquired map  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_tables_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_mngr_setup - Reset the acquired CIDs  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_cxt_mngr_setup
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_hw_init_common - Initailze ILT and DQ, common phase, per path.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_cxt_hw_init_common
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_hw_init_pf - Initailze ILT and DQ, PF phase, per path.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_cxt_hw_init_pf
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_qm_init_pf - Initailze the QM PF phase, per path  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_qm_init_pf
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Reconfigures QM pf on the fly  *  * @param p_hwfn  * @param p_ptt  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_qm_reconf
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
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ECORE_CXT_PF_CID
value|(0xff)
end_define

begin_comment
comment|/**  * @brief ecore_cxt_release - Release a cid  *  * @param p_hwfn  * @param cid  */
end_comment

begin_function_decl
name|void
name|ecore_cxt_release_cid
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_release - Release a cid belonging to a vf-queue  *  * @param p_hwfn  * @param cid  * @param vfid - engine relative index. ECORE_CXT_PF_CID if belongs to PF  */
end_comment

begin_function_decl
name|void
name|_ecore_cxt_release_cid
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|cid
parameter_list|,
name|u8
name|vfid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_acquire - Acquire a new cid of a specific protocol type  *  * @param p_hwfn  * @param type  * @param p_cid  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_acquire_cid
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|protocol_type
name|type
parameter_list|,
name|u32
modifier|*
name|p_cid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief _ecore_cxt_acquire - Acquire a new cid of a specific protocol type  *                             for a vf-queue  *  * @param p_hwfn  * @param type  * @param p_cid  * @param vfid - engine relative index. ECORE_CXT_PF_CID if belongs to PF  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|_ecore_cxt_acquire_cid
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|protocol_type
name|type
parameter_list|,
name|u32
modifier|*
name|p_cid
parameter_list|,
name|u8
name|vfid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_get_tid_mem_info - function checks if the  *        page containing the iid in the ilt is already  *        allocated, if it is not it allocates the page.  *  * @param p_hwfn  * @param elem_type  * @param iid  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_dynamic_ilt_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|ecore_cxt_elem_type
name|elem_type
parameter_list|,
name|u32
name|iid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_cxt_free_ilt_range - function frees ilt pages  *        associated with the protocol and element type passed.  *  * @param p_hwfn  * @param proto  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_free_ilt_range
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|ecore_cxt_elem_type
name|elem_type
parameter_list|,
name|u32
name|start_iid
parameter_list|,
name|u32
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ECORE_CTX_WORKING_MEM
value|0
end_define

begin_define
define|#
directive|define
name|ECORE_CTX_FL_MEM
value|1
end_define

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_get_task_ctx
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|tid
parameter_list|,
name|u8
name|ctx_type
parameter_list|,
name|void
modifier|*
modifier|*
name|task_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ECORE_CID_ */
end_comment

end_unit

