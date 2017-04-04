begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_SPQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_SPQ_H__
end_define

begin_include
include|#
directive|include
file|"ecore_hsi_common.h"
end_include

begin_include
include|#
directive|include
file|"ecore_status.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_eth.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_fcoe.h"
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
file|"ecore_hsi_roce.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_iwarp.h"
end_include

begin_include
include|#
directive|include
file|"ecore_chain.h"
end_include

begin_include
include|#
directive|include
file|"ecore_sp_api.h"
end_include

begin_union
union|union
name|ramrod_data
block|{
name|struct
name|pf_start_ramrod_data
name|pf_start
decl_stmt|;
name|struct
name|pf_update_ramrod_data
name|pf_update
decl_stmt|;
name|struct
name|rl_update_ramrod_data
name|rl_update
decl_stmt|;
name|struct
name|rx_queue_start_ramrod_data
name|rx_queue_start
decl_stmt|;
name|struct
name|rx_queue_update_ramrod_data
name|rx_queue_update
decl_stmt|;
name|struct
name|rx_queue_stop_ramrod_data
name|rx_queue_stop
decl_stmt|;
name|struct
name|tx_queue_start_ramrod_data
name|tx_queue_start
decl_stmt|;
name|struct
name|tx_queue_stop_ramrod_data
name|tx_queue_stop
decl_stmt|;
name|struct
name|vport_start_ramrod_data
name|vport_start
decl_stmt|;
name|struct
name|vport_stop_ramrod_data
name|vport_stop
decl_stmt|;
name|struct
name|rx_update_gft_filter_data
name|rx_update_gft
decl_stmt|;
name|struct
name|vport_update_ramrod_data
name|vport_update
decl_stmt|;
name|struct
name|core_rx_start_ramrod_data
name|core_rx_queue_start
decl_stmt|;
name|struct
name|core_rx_stop_ramrod_data
name|core_rx_queue_stop
decl_stmt|;
name|struct
name|core_tx_start_ramrod_data
name|core_tx_queue_start
decl_stmt|;
name|struct
name|core_tx_stop_ramrod_data
name|core_tx_queue_stop
decl_stmt|;
name|struct
name|vport_filter_update_ramrod_data
name|vport_filter_update
decl_stmt|;
name|struct
name|rdma_init_func_ramrod_data
name|rdma_init_func
decl_stmt|;
name|struct
name|rdma_close_func_ramrod_data
name|rdma_close_func
decl_stmt|;
name|struct
name|rdma_register_tid_ramrod_data
name|rdma_register_tid
decl_stmt|;
name|struct
name|rdma_deregister_tid_ramrod_data
name|rdma_deregister_tid
decl_stmt|;
name|struct
name|roce_create_qp_resp_ramrod_data
name|roce_create_qp_resp
decl_stmt|;
name|struct
name|roce_create_qp_req_ramrod_data
name|roce_create_qp_req
decl_stmt|;
name|struct
name|roce_modify_qp_resp_ramrod_data
name|roce_modify_qp_resp
decl_stmt|;
name|struct
name|roce_modify_qp_req_ramrod_data
name|roce_modify_qp_req
decl_stmt|;
name|struct
name|roce_query_qp_resp_ramrod_data
name|roce_query_qp_resp
decl_stmt|;
name|struct
name|roce_query_qp_req_ramrod_data
name|roce_query_qp_req
decl_stmt|;
name|struct
name|roce_destroy_qp_resp_ramrod_data
name|roce_destroy_qp_resp
decl_stmt|;
name|struct
name|roce_destroy_qp_req_ramrod_data
name|roce_destroy_qp_req
decl_stmt|;
name|struct
name|roce_init_func_ramrod_data
name|roce_init_func
decl_stmt|;
name|struct
name|rdma_create_cq_ramrod_data
name|rdma_create_cq
decl_stmt|;
name|struct
name|rdma_resize_cq_ramrod_data
name|rdma_resize_cq
decl_stmt|;
name|struct
name|rdma_destroy_cq_ramrod_data
name|rdma_destroy_cq
decl_stmt|;
name|struct
name|rdma_srq_create_ramrod_data
name|rdma_create_srq
decl_stmt|;
name|struct
name|rdma_srq_destroy_ramrod_data
name|rdma_destroy_srq
decl_stmt|;
name|struct
name|rdma_srq_modify_ramrod_data
name|rdma_modify_srq
decl_stmt|;
name|struct
name|iwarp_create_qp_ramrod_data
name|iwarp_create_qp
decl_stmt|;
name|struct
name|iwarp_tcp_offload_ramrod_data
name|iwarp_tcp_offload
decl_stmt|;
name|struct
name|iwarp_mpa_offload_ramrod_data
name|iwarp_mpa_offload
decl_stmt|;
name|struct
name|iwarp_modify_qp_ramrod_data
name|iwarp_modify_qp
decl_stmt|;
name|struct
name|iwarp_query_qp_ramrod_data
name|iwarp_query_qp
decl_stmt|;
name|struct
name|iwarp_init_func_ramrod_data
name|iwarp_init_func
decl_stmt|;
name|struct
name|fcoe_init_ramrod_params
name|fcoe_init
decl_stmt|;
name|struct
name|fcoe_conn_offload_ramrod_params
name|fcoe_conn_ofld
decl_stmt|;
name|struct
name|fcoe_conn_terminate_ramrod_params
name|fcoe_conn_terminate
decl_stmt|;
name|struct
name|fcoe_stat_ramrod_params
name|fcoe_stat
decl_stmt|;
name|struct
name|iscsi_slow_path_hdr
name|iscsi_empty
decl_stmt|;
name|struct
name|iscsi_init_ramrod_params
name|iscsi_init
decl_stmt|;
name|struct
name|iscsi_spe_func_dstry
name|iscsi_destroy
decl_stmt|;
name|struct
name|iscsi_spe_conn_offload
name|iscsi_conn_offload
decl_stmt|;
name|struct
name|iscsi_conn_update_ramrod_params
name|iscsi_conn_update
decl_stmt|;
name|struct
name|iscsi_spe_conn_mac_update
name|iscsi_conn_mac_update
decl_stmt|;
name|struct
name|iscsi_spe_conn_termination
name|iscsi_conn_terminate
decl_stmt|;
name|struct
name|vf_start_ramrod_data
name|vf_start
decl_stmt|;
name|struct
name|vf_stop_ramrod_data
name|vf_stop
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|EQ_MAX_CREDIT
value|0xffffffff
end_define

begin_enum
enum|enum
name|spq_priority
block|{
name|ECORE_SPQ_PRIORITY_NORMAL
block|,
name|ECORE_SPQ_PRIORITY_HIGH
block|, }
enum|;
end_enum

begin_union
union|union
name|ecore_spq_req_comp
block|{
name|struct
name|ecore_spq_comp_cb
name|cb
decl_stmt|;
name|u64
modifier|*
name|done_addr
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* SPQ_MODE_EBLOCK */
end_comment

begin_struct
struct|struct
name|ecore_spq_comp_done
block|{
name|u64
name|done
decl_stmt|;
name|u8
name|fw_return_code
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_spq_entry
block|{
name|osal_list_entry_t
name|list
decl_stmt|;
name|u8
name|flags
decl_stmt|;
comment|/* HSI slow path element */
name|struct
name|slow_path_element
name|elem
decl_stmt|;
name|union
name|ramrod_data
name|ramrod
decl_stmt|;
name|enum
name|spq_priority
name|priority
decl_stmt|;
comment|/* pending queue for this entry */
name|osal_list_t
modifier|*
name|queue
decl_stmt|;
name|enum
name|spq_mode
name|comp_mode
decl_stmt|;
name|struct
name|ecore_spq_comp_cb
name|comp_cb
decl_stmt|;
name|struct
name|ecore_spq_comp_done
name|comp_done
decl_stmt|;
comment|/* SPQ_MODE_EBLOCK */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_eq
block|{
name|struct
name|ecore_chain
name|chain
decl_stmt|;
name|u8
name|eq_sb_index
decl_stmt|;
comment|/* index within the SB */
name|__le16
modifier|*
name|p_fw_cons
decl_stmt|;
comment|/* ptr to index value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_consq
block|{
name|struct
name|ecore_chain
name|chain
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_spq
block|{
name|osal_spinlock_t
name|lock
decl_stmt|;
name|osal_list_t
name|unlimited_pending
decl_stmt|;
name|osal_list_t
name|pending
decl_stmt|;
name|osal_list_t
name|completion_pending
decl_stmt|;
name|osal_list_t
name|free_pool
decl_stmt|;
name|struct
name|ecore_chain
name|chain
decl_stmt|;
comment|/* allocated dma-able memory for spq entries (+ramrod data) */
name|dma_addr_t
name|p_phys
decl_stmt|;
name|struct
name|ecore_spq_entry
modifier|*
name|p_virt
decl_stmt|;
comment|/* Bitmap for handling out-of-order completions */
define|#
directive|define
name|SPQ_RING_SIZE
define|\
value|(CORE_SPQE_PAGE_SIZE_BYTES / sizeof(struct slow_path_element))
define|#
directive|define
name|SPQ_COMP_BMAP_SIZE
value|(SPQ_RING_SIZE / (sizeof(unsigned long) * 8
comment|/* BITS_PER_LONG */
value|))
name|unsigned
name|long
name|p_comp_bitmap
index|[
name|SPQ_COMP_BMAP_SIZE
index|]
decl_stmt|;
name|u8
name|comp_bitmap_idx
decl_stmt|;
define|#
directive|define
name|SPQ_COMP_BMAP_SET_BIT
parameter_list|(
name|p_spq
parameter_list|,
name|idx
parameter_list|)
define|\
value|do {									\ 		OSAL_SET_BIT(((idx) % SPQ_RING_SIZE), (p_spq)->p_comp_bitmap);	\ 	} while (0)
define|#
directive|define
name|SPQ_COMP_BMAP_CLEAR_BIT
parameter_list|(
name|p_spq
parameter_list|,
name|idx
parameter_list|)
define|\
value|do {										\ 		OSAL_CLEAR_BIT(((idx) % SPQ_RING_SIZE), (p_spq)->p_comp_bitmap);	\ 	} while (0)
define|#
directive|define
name|SPQ_COMP_BMAP_TEST_BIT
parameter_list|(
name|p_spq
parameter_list|,
name|idx
parameter_list|)
define|\
value|(OSAL_TEST_BIT(((idx) % SPQ_RING_SIZE), (p_spq)->p_comp_bitmap))
comment|/* Statistics */
name|u32
name|unlimited_pending_count
decl_stmt|;
name|u32
name|normal_count
decl_stmt|;
name|u32
name|high_count
decl_stmt|;
name|u32
name|comp_sent_count
decl_stmt|;
name|u32
name|comp_count
decl_stmt|;
name|u32
name|cid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ecore_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_hwfn
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * @brief ecore_spq_post - Posts a Slow hwfn request to FW, or lacking that  *        Pends it to the future list.  *  * @param p_hwfn  * @param p_req  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_spq_post
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_spq_entry
modifier|*
name|p_ent
parameter_list|,
name|u8
modifier|*
name|fw_return_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_allocate - Alloocates& initializes the SPQ and EQ.  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_spq_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_setup - Reset the SPQ to its start state.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_spq_setup
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_deallocate - Deallocates the given SPQ struct.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_spq_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_get_entry - Obtain an entrry from the spq  *        free pool list.  *  *  *  * @param p_hwfn  * @param pp_ent  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_spq_get_entry
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_spq_entry
modifier|*
modifier|*
name|pp_ent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_return_entry - Return an entry to spq free  *                                 pool list  *  * @param p_hwfn  * @param p_ent  */
end_comment

begin_function_decl
name|void
name|ecore_spq_return_entry
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_spq_entry
modifier|*
name|p_ent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_eq_allocate - Allocates& initializes an EQ struct  *  * @param p_hwfn  * @param num_elem number of elements in the eq  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_eq_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|num_elem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_eq_setup - Reset the EQ to its start state.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_eq_setup
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_eq_free - deallocates the given EQ struct.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_eq_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_eq_prod_update - update the FW with default EQ producer  *  * @param p_hwfn  * @param prod  */
end_comment

begin_function_decl
name|void
name|ecore_eq_prod_update
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|prod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_eq_completion - Completes currently pending EQ elements  *  * @param p_hwfn  * @param cookie  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_eq_completion
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_completion - Completes a single event  *  * @param p_hwfn  * @param echo - echo value from cookie (used for determining completion)  * @param p_data - data from cookie (used in callback function if applicable)  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_spq_completion
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|__le16
name|echo
parameter_list|,
name|u8
name|fw_return_code
parameter_list|,
name|union
name|event_ring_data
modifier|*
name|p_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_spq_get_cid - Given p_hwfn, return cid for the hwfn's SPQ  *  * @param p_hwfn  *  * @return u32 - SPQ CID  */
end_comment

begin_function_decl
name|u32
name|ecore_spq_get_cid
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_consq_alloc - Allocates& initializes an ConsQ struct  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_consq_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_consq_setup - Reset the ConsQ to its start state.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_consq_setup
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_consq_free - deallocates the given ConsQ struct.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_consq_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_SPQ_H__ */
end_comment

end_unit

