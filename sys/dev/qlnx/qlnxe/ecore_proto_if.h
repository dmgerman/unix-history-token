begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_PROTO_IF_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_PROTO_IF_H__
end_define

begin_comment
comment|/*  * PF parameters (according to personality/protocol)  */
end_comment

begin_define
define|#
directive|define
name|ECORE_ROCE_PROTOCOL_INDEX
value|(3)
end_define

begin_struct
struct|struct
name|ecore_eth_pf_params
block|{
comment|/* The following parameters are used during HW-init 	 * and these parameters need to be passed as arguments 	 * to update_pf_params routine invoked before slowpath start 	 */
name|u16
name|num_cons
decl_stmt|;
comment|/* per-VF number of CIDs */
name|u8
name|num_vf_cons
decl_stmt|;
define|#
directive|define
name|ETH_PF_PARAMS_VF_CONS_DEFAULT
value|(32)
comment|/* To enable arfs, previous to HW-init a positive number needs to be 	 * set [as filters require allocated searcher ILT memory]. 	 * This will set the maximal number of configured steering-filters. 	 */
name|u32
name|num_arfs_filters
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Most of the the parameters below are described in the FW FCoE HSI */
end_comment

begin_struct
struct|struct
name|ecore_fcoe_pf_params
block|{
comment|/* The following parameters are used during protocol-init */
name|u64
name|glbl_q_params_addr
decl_stmt|;
name|u64
name|bdq_pbl_base_addr
index|[
literal|2
index|]
decl_stmt|;
comment|/* The following parameters are used during HW-init 	 * and these parameters need to be passed as arguments 	 * to update_pf_params routine invoked before slowpath start 	 */
name|u16
name|num_cons
decl_stmt|;
name|u16
name|num_tasks
decl_stmt|;
comment|/* The following parameters are used during protocol-init */
name|u16
name|sq_num_pbl_pages
decl_stmt|;
name|u16
name|cq_num_entries
decl_stmt|;
name|u16
name|cmdq_num_entries
decl_stmt|;
name|u16
name|rq_buffer_log_size
decl_stmt|;
name|u16
name|mtu
decl_stmt|;
name|u16
name|dummy_icid
decl_stmt|;
name|u16
name|bdq_xoff_threshold
index|[
literal|2
index|]
decl_stmt|;
name|u16
name|bdq_xon_threshold
index|[
literal|2
index|]
decl_stmt|;
name|u16
name|rq_buffer_size
decl_stmt|;
name|u8
name|num_cqs
decl_stmt|;
comment|/* num of global CQs */
name|u8
name|log_page_size
decl_stmt|;
name|u8
name|gl_rq_pi
decl_stmt|;
name|u8
name|gl_cmd_pi
decl_stmt|;
name|u8
name|debug_mode
decl_stmt|;
name|u8
name|is_target
decl_stmt|;
name|u8
name|bdq_pbl_num_entries
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Most of the the parameters below are described in the FW iSCSI / TCP HSI */
end_comment

begin_struct
struct|struct
name|ecore_iscsi_pf_params
block|{
name|u64
name|glbl_q_params_addr
decl_stmt|;
name|u64
name|bdq_pbl_base_addr
index|[
literal|3
index|]
decl_stmt|;
name|u16
name|cq_num_entries
decl_stmt|;
name|u16
name|cmdq_num_entries
decl_stmt|;
name|u32
name|two_msl_timer
decl_stmt|;
name|u16
name|tx_sws_timer
decl_stmt|;
comment|/* The following parameters are used during HW-init 	 * and these parameters need to be passed as arguments 	 * to update_pf_params routine invoked before slowpath start 	 */
name|u16
name|num_cons
decl_stmt|;
name|u16
name|num_tasks
decl_stmt|;
comment|/* The following parameters are used during protocol-init */
name|u16
name|half_way_close_timeout
decl_stmt|;
name|u16
name|bdq_xoff_threshold
index|[
literal|3
index|]
decl_stmt|;
name|u16
name|bdq_xon_threshold
index|[
literal|3
index|]
decl_stmt|;
name|u16
name|cmdq_xoff_threshold
decl_stmt|;
name|u16
name|cmdq_xon_threshold
decl_stmt|;
name|u16
name|rq_buffer_size
decl_stmt|;
name|u8
name|num_sq_pages_in_ring
decl_stmt|;
name|u8
name|num_r2tq_pages_in_ring
decl_stmt|;
name|u8
name|num_uhq_pages_in_ring
decl_stmt|;
name|u8
name|num_queues
decl_stmt|;
name|u8
name|log_page_size
decl_stmt|;
name|u8
name|rqe_log_size
decl_stmt|;
name|u8
name|max_fin_rt
decl_stmt|;
name|u8
name|gl_rq_pi
decl_stmt|;
name|u8
name|gl_cmd_pi
decl_stmt|;
name|u8
name|debug_mode
decl_stmt|;
name|u8
name|ll2_ooo_queue_id
decl_stmt|;
name|u8
name|ooo_enable
decl_stmt|;
name|u8
name|is_target
decl_stmt|;
name|u8
name|is_tmwo_en
decl_stmt|;
name|u8
name|bdq_pbl_num_entries
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ecore_rdma_protocol
block|{
name|ECORE_RDMA_PROTOCOL_DEFAULT
block|,
name|ECORE_RDMA_PROTOCOL_NONE
block|,
name|ECORE_RDMA_PROTOCOL_ROCE
block|,
name|ECORE_RDMA_PROTOCOL_IWARP
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_rdma_pf_params
block|{
comment|/* Supplied to ECORE during resource allocation (may affect the ILT and 	 * the doorbell BAR). 	 */
name|u32
name|min_dpis
decl_stmt|;
comment|/* number of requested DPIs */
name|u32
name|num_qps
decl_stmt|;
comment|/* number of requested Queue Pairs */
name|u32
name|num_srqs
decl_stmt|;
comment|/* number of requested SRQ */
name|u8
name|roce_edpm_mode
decl_stmt|;
comment|/* see QED_ROCE_EDPM_MODE_ENABLE */
name|u8
name|gl_pi
decl_stmt|;
comment|/* protocol index */
comment|/* Will allocate rate limiters to be used with QPs */
name|u8
name|enable_dcqcn
decl_stmt|;
comment|/* Max number of CNQs - limits number of ECORE_RDMA_CNQ feature, 	 * Allowing an incrementation in ECORE_PF_L2_QUE. 	 * To disable CNQs, use dedicated value instead of `0'. 	 */
define|#
directive|define
name|ECORE_RDMA_PF_PARAMS_CNQS_NONE
value|(0xffff)
name|u16
name|max_cnqs
decl_stmt|;
comment|/* TCP port number used for the iwarp traffic */
name|u16
name|iwarp_port
decl_stmt|;
name|enum
name|ecore_rdma_protocol
name|rdma_protocol
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_pf_params
block|{
name|struct
name|ecore_eth_pf_params
name|eth_pf_params
decl_stmt|;
name|struct
name|ecore_fcoe_pf_params
name|fcoe_pf_params
decl_stmt|;
name|struct
name|ecore_iscsi_pf_params
name|iscsi_pf_params
decl_stmt|;
name|struct
name|ecore_rdma_pf_params
name|rdma_pf_params
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

