begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_ROCE__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_ROCE__
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to ecore hsi rdma target for both roce and iwarp ecore driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"ecore_hsi_rdma.h"
end_include

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common roce target for both eCore and protocol roce driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"roce_common.h"
end_include

begin_comment
comment|/*  * The roce storm context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_roce_conn_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|pstorm_roce_conn_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce storm context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_roce_conn_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_roce_conn_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|30
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_roce_conn_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce storm context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ustorm_roce_conn_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce connection context  */
end_comment

begin_struct
struct|struct
name|e4_roce_conn_context
block|{
name|struct
name|ystorm_roce_conn_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ystorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|pstorm_roce_conn_st_ctx
name|pstorm_st_context
comment|/* pstorm storm context */
decl_stmt|;
name|struct
name|xstorm_roce_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|xstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e4_xstorm_rdma_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|e4_tstorm_rdma_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|e4_ustorm_rdma_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_roce_conn_st_ctx
name|tstorm_st_context
comment|/* tstorm storm context */
decl_stmt|;
name|struct
name|mstorm_roce_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|ustorm_roce_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ustorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce connection context  */
end_comment

begin_struct
struct|struct
name|e5_roce_conn_context
block|{
name|struct
name|ystorm_roce_conn_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ystorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|pstorm_roce_conn_st_ctx
name|pstorm_st_context
comment|/* pstorm storm context */
decl_stmt|;
name|struct
name|xstorm_roce_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|xstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e5_xstorm_rdma_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|e5_tstorm_rdma_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|e5_ustorm_rdma_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_roce_conn_st_ctx
name|tstorm_st_context
comment|/* tstorm storm context */
decl_stmt|;
name|struct
name|mstorm_roce_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|ustorm_roce_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ustorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce create qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_create_qp_req_ramrod_data
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_ROCE_FLAVOR_MASK
value|0x3
comment|/* Use roce_flavor enum */
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_ROCE_FLAVOR_SHIFT
value|0
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_FMR_AND_RESERVED_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_FMR_AND_RESERVED_EN_SHIFT
value|2
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_SIGNALED_COMP_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_SIGNALED_COMP_SHIFT
value|3
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_PRI_MASK
value|0x7
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_PRI_SHIFT
value|4
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_RESERVED_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_RESERVED_SHIFT
value|7
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_ERR_RETRY_CNT_MASK
value|0xF
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_ERR_RETRY_CNT_SHIFT
value|8
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_RNR_NAK_CNT_MASK
value|0xF
define|#
directive|define
name|ROCE_CREATE_QP_REQ_RAMROD_DATA_RNR_NAK_CNT_SHIFT
value|12
name|u8
name|max_ord
decl_stmt|;
name|u8
name|traffic_class
comment|/* In case of RRoCE on IPv4 will be used as TOS */
decl_stmt|;
name|u8
name|hop_limit
comment|/* In case of RRoCE on IPv4 will be used as TTL */
decl_stmt|;
name|u8
name|orq_num_pages
decl_stmt|;
name|__le16
name|p_key
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|__le32
name|dst_qp_id
decl_stmt|;
name|__le32
name|ack_timeout_val
decl_stmt|;
name|__le32
name|initial_psn
decl_stmt|;
name|__le16
name|mtu
decl_stmt|;
name|__le16
name|pd
decl_stmt|;
name|__le16
name|sq_num_pages
decl_stmt|;
name|__le16
name|low_latency_phy_queue
decl_stmt|;
name|struct
name|regpair
name|sq_pbl_addr
decl_stmt|;
name|struct
name|regpair
name|orq_pbl_addr
decl_stmt|;
name|__le16
name|local_mac_addr
index|[
literal|3
index|]
comment|/* BE order */
decl_stmt|;
name|__le16
name|remote_mac_addr
index|[
literal|3
index|]
comment|/* BE order */
decl_stmt|;
name|__le16
name|vlan_id
decl_stmt|;
name|__le16
name|udp_src_port
comment|/* Only relevant in RRoCE */
decl_stmt|;
name|__le32
name|src_gid
index|[
literal|4
index|]
comment|/* BE order. In case of RRoCE on IPv4 the high register will hold the address. Low registers must be zero! */
decl_stmt|;
name|__le32
name|dst_gid
index|[
literal|4
index|]
comment|/* BE order. In case of RRoCE on IPv4 the high register will hold the address. Low registers must be zero! */
decl_stmt|;
name|struct
name|regpair
name|qp_handle_for_cqe
decl_stmt|;
name|struct
name|regpair
name|qp_handle_for_async
decl_stmt|;
name|u8
name|stats_counter_id
comment|/* Statistics counter ID to use */
decl_stmt|;
name|u8
name|reserved3
index|[
literal|7
index|]
decl_stmt|;
name|__le32
name|cq_cid
decl_stmt|;
name|__le16
name|regular_latency_phy_queue
decl_stmt|;
name|__le16
name|dpi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce create qp responder ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_create_qp_resp_ramrod_data
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_ROCE_FLAVOR_MASK
value|0x3
comment|/* Use roce_flavor enum */
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_ROCE_FLAVOR_SHIFT
value|0
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_RDMA_RD_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_RDMA_RD_EN_SHIFT
value|2
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_RDMA_WR_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_RDMA_WR_EN_SHIFT
value|3
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_ATOMIC_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_ATOMIC_EN_SHIFT
value|4
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_SRQ_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_SRQ_FLG_SHIFT
value|5
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_E2E_FLOW_CONTROL_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_E2E_FLOW_CONTROL_EN_SHIFT
value|6
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_RESERVED_KEY_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_RESERVED_KEY_EN_SHIFT
value|7
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_PRI_MASK
value|0x7
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_PRI_SHIFT
value|8
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_MIN_RNR_NAK_TIMER_MASK
value|0x1F
define|#
directive|define
name|ROCE_CREATE_QP_RESP_RAMROD_DATA_MIN_RNR_NAK_TIMER_SHIFT
value|11
name|u8
name|max_ird
decl_stmt|;
name|u8
name|traffic_class
comment|/* In case of RRoCE on IPv4 will be used as TOS */
decl_stmt|;
name|u8
name|hop_limit
comment|/* In case of RRoCE on IPv4 will be used as TTL */
decl_stmt|;
name|u8
name|irq_num_pages
decl_stmt|;
name|__le16
name|p_key
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|__le32
name|dst_qp_id
decl_stmt|;
name|u8
name|stats_counter_id
comment|/* Statistics counter ID to use */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|__le16
name|mtu
decl_stmt|;
name|__le32
name|initial_psn
decl_stmt|;
name|__le16
name|pd
decl_stmt|;
name|__le16
name|rq_num_pages
decl_stmt|;
name|struct
name|rdma_srq_id
name|srq_id
decl_stmt|;
name|struct
name|regpair
name|rq_pbl_addr
decl_stmt|;
name|struct
name|regpair
name|irq_pbl_addr
decl_stmt|;
name|__le16
name|local_mac_addr
index|[
literal|3
index|]
comment|/* BE order */
decl_stmt|;
name|__le16
name|remote_mac_addr
index|[
literal|3
index|]
comment|/* BE order */
decl_stmt|;
name|__le16
name|vlan_id
decl_stmt|;
name|__le16
name|udp_src_port
comment|/* Only relevant in RRoCE */
decl_stmt|;
name|__le32
name|src_gid
index|[
literal|4
index|]
comment|/* BE order. In case of RRoCE on IPv4 the lower register will hold the address. High registers must be zero! */
decl_stmt|;
name|__le32
name|dst_gid
index|[
literal|4
index|]
comment|/* BE order. In case of RRoCE on IPv4 the lower register will hold the address. High registers must be zero! */
decl_stmt|;
name|struct
name|regpair
name|qp_handle_for_cqe
decl_stmt|;
name|struct
name|regpair
name|qp_handle_for_async
decl_stmt|;
name|__le16
name|low_latency_phy_queue
decl_stmt|;
name|u8
name|reserved2
index|[
literal|6
index|]
decl_stmt|;
name|__le32
name|cq_cid
decl_stmt|;
name|__le16
name|regular_latency_phy_queue
decl_stmt|;
name|__le16
name|dpi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE destroy qp requester output params  */
end_comment

begin_struct
struct|struct
name|roce_destroy_qp_req_output_params
block|{
name|__le32
name|num_bound_mw
decl_stmt|;
name|__le32
name|cq_prod
comment|/* Completion producer value at destroy QP */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE destroy qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_destroy_qp_req_ramrod_data
block|{
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE destroy qp responder output params  */
end_comment

begin_struct
struct|struct
name|roce_destroy_qp_resp_output_params
block|{
name|__le32
name|num_invalidated_mw
decl_stmt|;
name|__le32
name|cq_prod
comment|/* Completion producer value at destroy QP */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE destroy qp responder ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_destroy_qp_resp_ramrod_data
block|{
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce func init ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_events_stats
block|{
name|__le16
name|silent_drops
decl_stmt|;
name|__le16
name|rnr_naks_sent
decl_stmt|;
name|__le32
name|retransmit_count
decl_stmt|;
name|__le32
name|icrc_error_count
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ROCE slow path EQ cmd IDs  */
end_comment

begin_enum
enum|enum
name|roce_event_opcode
block|{
name|ROCE_EVENT_CREATE_QP
init|=
literal|11
block|,
name|ROCE_EVENT_MODIFY_QP
block|,
name|ROCE_EVENT_QUERY_QP
block|,
name|ROCE_EVENT_DESTROY_QP
block|,
name|ROCE_EVENT_CREATE_UD_QP
block|,
name|ROCE_EVENT_DESTROY_UD_QP
block|,
name|MAX_ROCE_EVENT_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * roce func init ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_init_func_params
block|{
name|u8
name|ll2_queue_id
comment|/* This ll2 queue ID is used for Unreliable Datagram QP */
decl_stmt|;
name|u8
name|cnp_vlan_priority
comment|/* VLAN priority of DCQCN CNP packet */
decl_stmt|;
name|u8
name|cnp_dscp
comment|/* The value of DSCP field in IP header for CNP packets */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
name|__le32
name|cnp_send_timeout
comment|/* The minimal difference of send time between CNP packets for specific QP. Units are in microseconds */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce func init ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_init_func_ramrod_data
block|{
name|struct
name|rdma_init_func_ramrod_data
name|rdma
decl_stmt|;
name|struct
name|roce_init_func_params
name|roce
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce modify qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_modify_qp_req_ramrod_data
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_MOVE_TO_ERR_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_MOVE_TO_ERR_FLG_SHIFT
value|0
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_MOVE_TO_SQD_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_MOVE_TO_SQD_FLG_SHIFT
value|1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_EN_SQD_ASYNC_NOTIFY_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_EN_SQD_ASYNC_NOTIFY_SHIFT
value|2
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_P_KEY_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_P_KEY_FLG_SHIFT
value|3
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ADDRESS_VECTOR_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ADDRESS_VECTOR_FLG_SHIFT
value|4
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_MAX_ORD_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_MAX_ORD_FLG_SHIFT
value|5
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_RNR_NAK_CNT_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_RNR_NAK_CNT_FLG_SHIFT
value|6
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ERR_RETRY_CNT_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ERR_RETRY_CNT_FLG_SHIFT
value|7
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ACK_TIMEOUT_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ACK_TIMEOUT_FLG_SHIFT
value|8
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_PRI_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_PRI_FLG_SHIFT
value|9
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_PRI_MASK
value|0x7
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_PRI_SHIFT
value|10
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_RESERVED1_MASK
value|0x7
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_RESERVED1_SHIFT
value|13
name|u8
name|fields
decl_stmt|;
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ERR_RETRY_CNT_MASK
value|0xF
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_ERR_RETRY_CNT_SHIFT
value|0
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_RNR_NAK_CNT_MASK
value|0xF
define|#
directive|define
name|ROCE_MODIFY_QP_REQ_RAMROD_DATA_RNR_NAK_CNT_SHIFT
value|4
name|u8
name|max_ord
decl_stmt|;
name|u8
name|traffic_class
decl_stmt|;
name|u8
name|hop_limit
decl_stmt|;
name|__le16
name|p_key
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|__le32
name|ack_timeout_val
decl_stmt|;
name|__le16
name|mtu
decl_stmt|;
name|__le16
name|reserved2
decl_stmt|;
name|__le32
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
name|__le32
name|src_gid
index|[
literal|4
index|]
comment|/* BE order. In case of IPv4 the higher register will hold the address. Low registers must be zero! */
decl_stmt|;
name|__le32
name|dst_gid
index|[
literal|4
index|]
comment|/* BE order. In case of IPv4 the higher register will hold the address. Low registers must be zero! */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * roce modify qp responder ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_modify_qp_resp_ramrod_data
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MOVE_TO_ERR_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MOVE_TO_ERR_FLG_SHIFT
value|0
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RDMA_RD_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RDMA_RD_EN_SHIFT
value|1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RDMA_WR_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RDMA_WR_EN_SHIFT
value|2
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_ATOMIC_EN_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_ATOMIC_EN_SHIFT
value|3
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_P_KEY_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_P_KEY_FLG_SHIFT
value|4
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_ADDRESS_VECTOR_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_ADDRESS_VECTOR_FLG_SHIFT
value|5
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MAX_IRD_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MAX_IRD_FLG_SHIFT
value|6
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_PRI_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_PRI_FLG_SHIFT
value|7
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MIN_RNR_NAK_TIMER_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MIN_RNR_NAK_TIMER_FLG_SHIFT
value|8
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RDMA_OPS_EN_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RDMA_OPS_EN_FLG_SHIFT
value|9
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RESERVED1_MASK
value|0x3F
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_RESERVED1_SHIFT
value|10
name|u8
name|fields
decl_stmt|;
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_PRI_MASK
value|0x7
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_PRI_SHIFT
value|0
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MIN_RNR_NAK_TIMER_MASK
value|0x1F
define|#
directive|define
name|ROCE_MODIFY_QP_RESP_RAMROD_DATA_MIN_RNR_NAK_TIMER_SHIFT
value|3
name|u8
name|max_ird
decl_stmt|;
name|u8
name|traffic_class
decl_stmt|;
name|u8
name|hop_limit
decl_stmt|;
name|__le16
name|p_key
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|__le16
name|mtu
decl_stmt|;
name|__le16
name|reserved2
decl_stmt|;
name|__le32
name|src_gid
index|[
literal|4
index|]
comment|/* BE order. In case of IPv4 the higher register will hold the address. Low registers must be zero! */
decl_stmt|;
name|__le32
name|dst_gid
index|[
literal|4
index|]
comment|/* BE order. In case of IPv4 the higher register will hold the address. Low registers must be zero! */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE query qp requester output params  */
end_comment

begin_struct
struct|struct
name|roce_query_qp_req_output_params
block|{
name|__le32
name|psn
comment|/* send next psn */
decl_stmt|;
name|__le32
name|flags
decl_stmt|;
define|#
directive|define
name|ROCE_QUERY_QP_REQ_OUTPUT_PARAMS_ERR_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_QUERY_QP_REQ_OUTPUT_PARAMS_ERR_FLG_SHIFT
value|0
define|#
directive|define
name|ROCE_QUERY_QP_REQ_OUTPUT_PARAMS_SQ_DRAINING_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_QUERY_QP_REQ_OUTPUT_PARAMS_SQ_DRAINING_FLG_SHIFT
value|1
define|#
directive|define
name|ROCE_QUERY_QP_REQ_OUTPUT_PARAMS_RESERVED0_MASK
value|0x3FFFFFFF
define|#
directive|define
name|ROCE_QUERY_QP_REQ_OUTPUT_PARAMS_RESERVED0_SHIFT
value|2
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE query qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_query_qp_req_ramrod_data
block|{
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE query qp responder output params  */
end_comment

begin_struct
struct|struct
name|roce_query_qp_resp_output_params
block|{
name|__le32
name|psn
comment|/* send next psn */
decl_stmt|;
name|__le32
name|err_flag
decl_stmt|;
define|#
directive|define
name|ROCE_QUERY_QP_RESP_OUTPUT_PARAMS_ERROR_FLG_MASK
value|0x1
define|#
directive|define
name|ROCE_QUERY_QP_RESP_OUTPUT_PARAMS_ERROR_FLG_SHIFT
value|0
define|#
directive|define
name|ROCE_QUERY_QP_RESP_OUTPUT_PARAMS_RESERVED0_MASK
value|0x7FFFFFFF
define|#
directive|define
name|ROCE_QUERY_QP_RESP_OUTPUT_PARAMS_RESERVED0_SHIFT
value|1
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE query qp responder ramrod data  */
end_comment

begin_struct
struct|struct
name|roce_query_qp_resp_ramrod_data
block|{
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ROCE ramrod command IDs  */
end_comment

begin_enum
enum|enum
name|roce_ramrod_cmd_id
block|{
name|ROCE_RAMROD_CREATE_QP
init|=
literal|11
block|,
name|ROCE_RAMROD_MODIFY_QP
block|,
name|ROCE_RAMROD_QUERY_QP
block|,
name|ROCE_RAMROD_DESTROY_QP
block|,
name|ROCE_RAMROD_CREATE_UD_QP
block|,
name|ROCE_RAMROD_DESTROY_UD_QP
block|,
name|MAX_ROCE_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_struct
struct|struct
name|e4_mstorm_roce_req_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_roce_req_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_OCCURED_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_OCCURED_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_CQE_ERROR_OCCURED_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_CQE_ERROR_OCCURED_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_CACHED_ORQ_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_CACHED_ORQ_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SND_SQ_CONS_EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_SND_SQ_CONS_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|snd_nxt_psn
comment|/* reg1 */
decl_stmt|;
name|__le32
name|snd_max_psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|orq_prod
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* reg5 */
decl_stmt|;
name|__le32
name|reg6
comment|/* reg6 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
name|u8
name|tx_cqe_error_type
comment|/* byte2 */
decl_stmt|;
name|u8
name|orq_cache_idx
comment|/* byte3 */
decl_stmt|;
name|__le16
name|snd_sq_cons_th
comment|/* word0 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|__le16
name|snd_sq_cons
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_NOTIFY_REQUESTER_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_NOTIFY_REQUESTER_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RQ_RULE_EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RQ_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|__le32
name|psn_and_rxmit_id_echo
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* reg5 */
decl_stmt|;
name|__le32
name|reg6
comment|/* reg6 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
name|u8
name|tx_async_error_type
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|rq_cons
comment|/* word0 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|__le16
name|rq_prod
comment|/* word1 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|irq_cons
comment|/* word3 */
decl_stmt|;
name|__le32
name|num_invlidated_mw
comment|/* reg9 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_roce_req_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_roce_req_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_STATE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_STATE_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FMR_ENDED_CF_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FMR_ENDED_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FME_ENDED_CF_EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_FME_ENDED_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_E2E_CREDIT_RULE_EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_E2E_CREDIT_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_PROD_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_PROD_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_INV_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_INV_FENCE_RULE_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_ORQ_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_ORQ_FENCE_RULE_EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_MAX_ORD_RULE_EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_MAX_ORD_RULE_EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_MIGRATION_FLAG_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_MIGRATION_FLAG_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|sq_cmp_cons
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|sq_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|word5
comment|/* word5 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|lsn
comment|/* reg0 */
decl_stmt|;
name|__le32
name|ssn
comment|/* reg1 */
decl_stmt|;
name|__le32
name|snd_una_psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|snd_nxt_psn
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|orq_cons_th
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|orq_cons
comment|/* cf_array1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_ERROR_STATE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_ERROR_STATE_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_IRQ_PROD_RULE_EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_IRQ_PROD_RULE_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT21_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT21_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|irq_prod
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le16
name|e5_reserved1
comment|/* word5 */
decl_stmt|;
name|__le16
name|irq_cons
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|rxmit_opcode
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|rxmit_psn_and_id
comment|/* reg0 */
decl_stmt|;
name|__le32
name|rxmit_bytes_length
comment|/* reg1 */
decl_stmt|;
name|__le32
name|psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|msn_and_syndrome
comment|/* cf_array1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_roce_req_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|E5XstormRoceConnAgCtxDqExtLdPart
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT10_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT11_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT12_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT13_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_ERROR_STATE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_ERROR_STATE_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF0_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF1_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF2_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SQ_FLUSH_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SQ_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RX_ERROR_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SND_RXMIT_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SND_RXMIT_CF_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF8_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF9_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF10_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF12_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF13_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FMR_ENDED_CF_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FMR_ENDED_CF_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF16_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF17_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF18_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF20_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF21_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SQ_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SQ_FLUSH_CF_EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RX_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SND_RXMIT_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SND_RXMIT_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FME_ENDED_CF_EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_FME_ENDED_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF16EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF19EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF20EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF21EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E2E_CREDIT_RULE_EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E2E_CREDIT_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SQ_PROD_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_SQ_PROD_EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_INV_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_INV_FENCE_RULE_EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_ORQ_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_ORQ_FENCE_RULE_EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_MAX_ORD_RULE_EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_MAX_ORD_RULE_EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_MIGRATION_FLAG_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_MIGRATION_FLAG_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_BIT17_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED_SHIFT
value|4
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|sq_cmp_cons
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|sq_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|word5
comment|/* word5 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|lsn
comment|/* reg0 */
decl_stmt|;
name|__le32
name|ssn
comment|/* reg1 */
decl_stmt|;
name|__le32
name|snd_una_psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|snd_nxt_psn
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|orq_cons_th
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|orq_cons
comment|/* cf_array1 */
decl_stmt|;
name|u8
name|flags15
decl_stmt|;
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED1_MASK
value|0x1
comment|/* bit22 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED2_MASK
value|0x1
comment|/* bit23 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED3_MASK
value|0x1
comment|/* bit24 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED4_MASK
value|0x3
comment|/* cf24 */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED5_MASK
value|0x1
comment|/* cf24en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED6_MASK
value|0x1
comment|/* rule26en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED7_MASK
value|0x1
comment|/* rule27en */
define|#
directive|define
name|E5XSTORMROCECONNAGCTXDQEXTLDPART_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|__le16
name|word7
comment|/* word7 */
decl_stmt|;
name|__le16
name|word8
comment|/* word8 */
decl_stmt|;
name|__le16
name|word9
comment|/* word9 */
decl_stmt|;
name|__le16
name|word10
comment|/* word10 */
decl_stmt|;
name|__le16
name|tx_rdma_edpm_usg_cnt
comment|/* word11 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|u8
name|byte8
comment|/* byte8 */
decl_stmt|;
name|u8
name|byte9
comment|/* byte9 */
decl_stmt|;
name|u8
name|byte10
comment|/* byte10 */
decl_stmt|;
name|u8
name|byte11
comment|/* byte11 */
decl_stmt|;
name|u8
name|byte12
comment|/* byte12 */
decl_stmt|;
name|u8
name|byte13
comment|/* byte13 */
decl_stmt|;
name|u8
name|byte14
comment|/* byte14 */
decl_stmt|;
name|u8
name|byte15
comment|/* byte15 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
name|__le32
name|reg11
comment|/* reg11 */
decl_stmt|;
name|__le32
name|reg12
comment|/* reg12 */
decl_stmt|;
name|__le32
name|reg13
comment|/* reg13 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_roce_req_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_tstorm_roce_req_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_OCCURED_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_OCCURED_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_CQE_ERROR_OCCURED_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_CQE_ERROR_OCCURED_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_CACHED_ORQ_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_CACHED_ORQ_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_SQ_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SET_TIMER_CF_EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_TX_ASYNC_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RXMIT_DONE_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_SCAN_COMPLETED_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SQ_DRAIN_COMPLETED_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SND_SQ_CONS_EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_SND_SQ_CONS_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|tx_cqe_error_type
comment|/* byte2 */
decl_stmt|;
name|__le16
name|snd_sq_cons_th
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|snd_nxt_psn
comment|/* reg1 */
decl_stmt|;
name|__le32
name|snd_max_psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|orq_prod
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* reg5 */
decl_stmt|;
name|__le32
name|reg6
comment|/* reg6 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
name|u8
name|orq_cache_idx
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|e4_reserved8
comment|/* byte6 */
decl_stmt|;
name|__le16
name|snd_sq_cons
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* conn_dpi */
decl_stmt|;
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|e4_reserved9
comment|/* word4 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_tstorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_TX_ERROR_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RQ_RULE_EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RQ_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|tx_async_error_type
comment|/* byte2 */
decl_stmt|;
name|__le16
name|rq_cons
comment|/* word0 */
decl_stmt|;
name|__le32
name|psn_and_rxmit_id_echo
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* reg5 */
decl_stmt|;
name|__le32
name|reg6
comment|/* reg6 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|e4_reserved8
comment|/* byte6 */
decl_stmt|;
name|__le16
name|rq_prod
comment|/* word1 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|__le32
name|num_invlidated_mw
comment|/* reg9 */
decl_stmt|;
name|__le16
name|irq_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|e4_reserved9
comment|/* word4 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_roce_req_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_ROCE_REQ_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word0
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_ROCE_RESP_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word0
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_xstorm_roce_req_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_STATE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_ERROR_STATE_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FMR_ENDED_CF_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FMR_ENDED_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_FLUSH_CF_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RX_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SND_RXMIT_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FME_ENDED_CF_EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_FME_ENDED_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF20EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF21EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_E2E_CREDIT_RULE_EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_E2E_CREDIT_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_PROD_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_SQ_PROD_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_INV_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_INV_FENCE_RULE_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_ORQ_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_ORQ_FENCE_RULE_EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_MAX_ORD_RULE_EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_MAX_ORD_RULE_EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_MIGRATION_FLAG_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_MIGRATION_FLAG_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_RESERVED_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_ROCE_REQ_CONN_AG_CTX_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|sq_cmp_cons
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|sq_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|word5
comment|/* word5 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|lsn
comment|/* reg0 */
decl_stmt|;
name|__le32
name|ssn
comment|/* reg1 */
decl_stmt|;
name|__le32
name|snd_una_psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|snd_nxt_psn
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|orq_cons_th
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|orq_cons
comment|/* cf_array1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_xstorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_ERROR_STATE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_ERROR_STATE_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RXMIT_CF_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RX_ERROR_CF_EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FORCE_ACK_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF20EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF21EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_IRQ_PROD_RULE_EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_IRQ_PROD_RULE_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT21_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_BIT21_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_ROCE_RESP_CONN_AG_CTX_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|irq_prod
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le16
name|ack_cons
comment|/* word5 */
decl_stmt|;
name|__le16
name|irq_cons
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|rxmit_opcode
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|rxmit_psn_and_id
comment|/* reg0 */
decl_stmt|;
name|__le32
name|rxmit_bytes_length
comment|/* reg1 */
decl_stmt|;
name|__le32
name|psn
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|msn_and_syndrome
comment|/* cf_array1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_roce_req_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_ROCE_REQ_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_roce_resp_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_ROCE_RESP_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Roce doorbell data  */
end_comment

begin_enum
enum|enum
name|roce_flavor
block|{
name|PLAIN_ROCE
comment|/* RoCE v1 */
block|,
name|RROCE_IPV4
comment|/* RoCE v2 (Routable RoCE) over ipv4 */
block|,
name|RROCE_IPV6
comment|/* RoCE v2 (Routable RoCE) over ipv6 */
block|,
name|MAX_ROCE_FLAVOR
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_ROCE__ */
end_comment

end_unit

