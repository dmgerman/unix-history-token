begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_L2_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_L2_H__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hw.h"
end_include

begin_include
include|#
directive|include
file|"ecore_spq.h"
end_include

begin_include
include|#
directive|include
file|"ecore_l2_api.h"
end_include

begin_define
define|#
directive|define
name|MAX_QUEUES_PER_QZONE
value|(sizeof(unsigned long) * 8)
end_define

begin_define
define|#
directive|define
name|ECORE_QUEUE_CID_PF
value|(0xff)
end_define

begin_comment
comment|/* Almost identical to the ecore_queue_start_common_params,  * but here we maintain the SB index in IGU CAM.  */
end_comment

begin_struct
struct|struct
name|ecore_queue_cid_params
block|{
name|u8
name|vport_id
decl_stmt|;
name|u16
name|queue_id
decl_stmt|;
name|u8
name|stats_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional parameters required for initialization of the queue_cid  * and are relevant only for a PF initializing one for its VFs.  */
end_comment

begin_struct
struct|struct
name|ecore_queue_cid_vf_params
block|{
comment|/* Should match the VF's relative index */
name|u8
name|vfid
decl_stmt|;
comment|/* 0-based queue index. Should reflect the relative qzone the 	 * VF thinks is associated with it [in its range]. 	 */
name|u8
name|vf_qid
decl_stmt|;
comment|/* Indicates a VF is legacy, making it differ in several things: 	 *  - Producers would be placed in a different place. 	 *  - Makes assumptions regarding the CIDs. 	 */
name|u8
name|vf_legacy
decl_stmt|;
comment|/* For VFs, this index arrives via TLV to diffrentiate between 	 * different queues opened on the same qzone, and is passed 	 * [where the PF would have allocated it internally for its own]. 	 */
name|u8
name|qid_usage_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_cid
block|{
comment|/* For stats-id, the `rel' is actually absolute as well */
name|struct
name|ecore_queue_cid_params
name|rel
decl_stmt|;
name|struct
name|ecore_queue_cid_params
name|abs
decl_stmt|;
comment|/* These have no 'relative' meaning */
name|u16
name|sb_igu_id
decl_stmt|;
name|u8
name|sb_idx
decl_stmt|;
name|u32
name|cid
decl_stmt|;
name|u16
name|opaque_fid
decl_stmt|;
comment|/* VFs queues are mapped differently, so we need to know the 	 * relative queue associated with them [0-based]. 	 * Notice this is relevant on the *PF* queue-cid of its VF's queues, 	 * and not on the VF itself. 	 */
name|u8
name|vfid
decl_stmt|;
name|u8
name|vf_qid
decl_stmt|;
comment|/* We need an additional index to diffrentiate between queues opened 	 * for same queue-zone, as VFs would have to communicate the info 	 * to the PF [otherwise PF has no way to diffrentiate]. 	 */
name|u8
name|qid_usage_idx
decl_stmt|;
comment|/* Legacy VFs might have Rx producer located elsewhere */
name|u8
name|vf_legacy
decl_stmt|;
define|#
directive|define
name|ECORE_QCID_LEGACY_VF_RX_PROD
value|(1<< 0)
define|#
directive|define
name|ECORE_QCID_LEGACY_VF_CID
value|(1<< 1)
name|struct
name|ecore_hwfn
modifier|*
name|p_owner
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_l2_alloc
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
name|ecore_l2_setup
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
name|ecore_l2_free
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
name|ecore_eth_queue_cid_release
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_queue_cid
modifier|*
name|p_cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ecore_queue_cid
modifier|*
name|ecore_eth_queue_to_cid
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|opaque_fid
parameter_list|,
name|struct
name|ecore_queue_start_common_params
modifier|*
name|p_params
parameter_list|,
name|struct
name|ecore_queue_cid_vf_params
modifier|*
name|p_vf_params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_eth_vport_start
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_sp_vport_start_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Starts an Rx queue, when queue_cid is already prepared  *  * @param p_hwfn  * @param p_cid  * @param bd_max_bytes  * @param bd_chain_phys_addr  * @param cqe_pbl_addr  * @param cqe_pbl_size  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_eth_rxq_start_ramrod
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_queue_cid
modifier|*
name|p_cid
parameter_list|,
name|u16
name|bd_max_bytes
parameter_list|,
name|dma_addr_t
name|bd_chain_phys_addr
parameter_list|,
name|dma_addr_t
name|cqe_pbl_addr
parameter_list|,
name|u16
name|cqe_pbl_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Starts a Tx queue, where queue_cid is already prepared  *  * @param p_hwfn  * @param p_cid  * @param pbl_addr   * @param pbl_size  * @param p_pq_params - parameters for choosing the PQ for this Tx queue  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_eth_txq_start_ramrod
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_queue_cid
modifier|*
name|p_cid
parameter_list|,
name|dma_addr_t
name|pbl_addr
parameter_list|,
name|u16
name|pbl_size
parameter_list|,
name|u16
name|pq_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|ecore_mcast_bin_from_mac
parameter_list|(
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - ecore_configure_rfs_ntuple_filter  *  * This ramrod should be used to add or remove arfs hw filter  *  * @params p_hwfn  * @params p_ptt  * @params p_cb		Used for ECORE_SPQ_MODE_CB,where client would initialize 			it with cookie and callback function address, if not 			using this mode then client must pass NULL.  * @params p_addr	p_addr is an actual packet header that needs to be  *			filter. It has to mapped with IO to read prior to  *			calling this, [contains 4 tuples- src ip, dest ip,  *			src port, dest port].  * @params length	length of p_addr header up to past the transport header.  * @params qid		receive packet will be directed to this queue.  * @params vport_id  * @params b_is_add	flag to add or remove filter.  *  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_configure_rfs_ntuple_filter
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
name|ecore_spq_comp_cb
modifier|*
name|p_cb
parameter_list|,
name|dma_addr_t
name|p_addr
parameter_list|,
name|u16
name|length
parameter_list|,
name|u16
name|qid
parameter_list|,
name|u8
name|vport_id
parameter_list|,
name|bool
name|b_is_add
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

