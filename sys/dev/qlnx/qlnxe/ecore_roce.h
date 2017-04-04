begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_RDMA_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_RDMA_H__
end_define

begin_include
include|#
directive|include
file|"ecore_status.h"
end_include

begin_include
include|#
directive|include
file|"ecore.h"
end_include

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
file|"ecore_roce_api.h"
end_include

begin_include
include|#
directive|include
file|"ecore_dev_api.h"
end_include

begin_comment
comment|/* Constants */
end_comment

begin_comment
comment|/* HW/FW RoCE Limitations (internal. For external see ecore_rdma_api.h) */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_FMR
value|(RDMA_MAX_TIDS)
end_define

begin_comment
comment|/* 2^17 - 1 */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_P_KEY
value|(1)
end_define

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_WQE
value|(0x7FFF)
end_define

begin_comment
comment|/* 2^15 -1 */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_SRQ_WQE_ELEM
value|(0x7FFF)
end_define

begin_comment
comment|/* 2^15 -1 */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_PAGE_SIZE_CAPS
value|(0xFFFFF000)
end_define

begin_comment
comment|/* TODO:> 4k?! */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_ACK_DELAY
value|(15)
end_define

begin_comment
comment|/* 131 milliseconds */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_MR_SIZE
value|(0x10000000000ULL)
end_define

begin_comment
comment|/* 2^40 */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_CQS
value|(RDMA_MAX_CQS)
end_define

begin_comment
comment|/* 64k */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_MRS
value|(RDMA_MAX_TIDS)
end_define

begin_comment
comment|/* 2^17 - 1 */
end_comment

begin_comment
comment|/* Add 1 for header element */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_SRQ_ELEM_PER_WQE
value|(RDMA_MAX_SGE_PER_RQ_WQE + 1)
end_define

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_SGE_PER_SRQ_WQE
value|(RDMA_MAX_SGE_PER_RQ_WQE)
end_define

begin_define
define|#
directive|define
name|ECORE_RDMA_SRQ_WQE_ELEM_SIZE
value|(16)
end_define

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_SRQS
value|(32 * 1024)
end_define

begin_comment
comment|/* 32k */
end_comment

begin_comment
comment|/* Configurable */
end_comment

begin_comment
comment|/* Max CQE is derived from u16/32 size, halved and decremented by 1 to handle  * wrap properly and then decremented by 1 again. The latter decrement comes  * from a requirement to create a chain that is bigger than what the user  * requested by one:  * The CQE size is 32 bytes but the FW writes in chunks of 64  * bytes, for performance purposes. Allocating an extra entry and telling the  * FW we have less prevents overwriting the first entry in case of a wrap i.e.  * when the FW writes the last entry and the application hasn't read the first  * one.  */
end_comment

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_CQE_32_BIT
value|(0x7FFFFFFF - 1)
end_define

begin_define
define|#
directive|define
name|ECORE_RDMA_MAX_CQE_16_BIT
value|(0x7FFF - 1)
end_define

begin_enum
enum|enum
name|ecore_rdma_toggle_bit
block|{
name|ECORE_RDMA_TOGGLE_BIT_CLEAR
init|=
literal|0
block|,
name|ECORE_RDMA_TOGGLE_BIT_SET
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* @@@TBD Currently we support only affilited events    * enum ecore_rdma_unaffiliated_event_code {    * ECORE_RDMA_PORT_ACTIVE, // Link Up    * ECORE_RDMA_PORT_CHANGED, // SGID table has changed    * ECORE_RDMA_LOCAL_CATASTROPHIC_ERR, // Fatal device error    * ECORE_RDMA_PORT_ERR, // Link down    * };    */
end_comment

begin_define
define|#
directive|define
name|QEDR_MAX_BMAP_NAME
value|(10)
end_define

begin_struct
struct|struct
name|ecore_bmap
block|{
name|u32
name|max_count
decl_stmt|;
name|unsigned
name|long
modifier|*
name|bitmap
decl_stmt|;
name|char
name|name
index|[
name|QEDR_MAX_BMAP_NAME
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* functions for enabling/disabling edpm in rdma PFs according to existence of  * qps during DCBx update or bar size  */
end_comment

begin_function_decl
name|void
name|ecore_roce_dpm_dcbx
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

begin_function_decl
name|void
name|ecore_rdma_dpm_bar
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ECORE_IWARP
end_ifdef

begin_define
define|#
directive|define
name|ECORE_IWARP_LL2_SYN_TX_SIZE
value|(128)
end_define

begin_define
define|#
directive|define
name|ECORE_IWARP_LL2_SYN_RX_SIZE
value|(256)
end_define

begin_define
define|#
directive|define
name|ECORE_IWARP_LL2_OOO_DEF_TX_SIZE
value|(256)
end_define

begin_define
define|#
directive|define
name|ECORE_IWARP_LL2_OOO_DEF_RX_SIZE
value|(4096)
end_define

begin_define
define|#
directive|define
name|ECORE_IWARP_MAX_SYN_PKT_SIZE
value|(128)
end_define

begin_define
define|#
directive|define
name|ECORE_IWARP_HANDLE_INVAL
value|(0xff)
end_define

begin_struct
struct|struct
name|ecore_iwarp_ll2_buff
block|{
name|struct
name|ecore_iwarp_ll2_buff
modifier|*
name|piggy_buf
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|dma_addr_t
name|data_phys_addr
decl_stmt|;
name|u32
name|buff_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_iwarp_ll2_mpa_buf
block|{
name|osal_list_entry_t
name|list_entry
decl_stmt|;
name|struct
name|ecore_iwarp_ll2_buff
modifier|*
name|ll2_buf
decl_stmt|;
name|struct
name|unaligned_opaque_data
name|data
decl_stmt|;
name|u16
name|tcp_payload_len
decl_stmt|;
name|u8
name|placement_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In some cases a fpdu will arrive with only one byte of the header, in this  * case the fpdu_length will be partial ( contain only higher byte and  * incomplete bytes will contain the invalid value */
end_comment

begin_define
define|#
directive|define
name|ECORE_IWARP_INVALID_INCOMPLETE_BYTES
value|0xffff
end_define

begin_struct
struct|struct
name|ecore_iwarp_fpdu
block|{
name|struct
name|ecore_iwarp_ll2_buff
modifier|*
name|mpa_buf
decl_stmt|;
name|dma_addr_t
name|pkt_hdr
decl_stmt|;
name|u8
name|pkt_hdr_size
decl_stmt|;
name|dma_addr_t
name|mpa_frag
decl_stmt|;
name|void
modifier|*
name|mpa_frag_virt
decl_stmt|;
name|u16
name|mpa_frag_len
decl_stmt|;
name|u16
name|fpdu_length
decl_stmt|;
name|u16
name|incomplete_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_iwarp_info
block|{
name|osal_list_t
name|listen_list
decl_stmt|;
comment|/* ecore_iwarp_listener */
name|osal_list_t
name|ep_list
decl_stmt|;
comment|/* ecore_iwarp_ep */
name|osal_list_t
name|ep_free_list
decl_stmt|;
comment|/* pre-allocated ep's */
name|osal_list_t
name|mpa_buf_list
decl_stmt|;
comment|/* list of mpa_bufs */
name|osal_list_t
name|mpa_buf_pending_list
decl_stmt|;
name|osal_spinlock_t
name|iw_lock
decl_stmt|;
name|osal_spinlock_t
name|qp_lock
decl_stmt|;
comment|/* for teardown races */
name|struct
name|iwarp_rxmit_stats_drv
name|stats
decl_stmt|;
name|u32
name|rcv_wnd_scale
decl_stmt|;
name|u16
name|max_mtu
decl_stmt|;
name|u16
name|num_ooo_rx_bufs
decl_stmt|;
name|u8
name|mac_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|crc_needed
decl_stmt|;
name|u8
name|tcp_flags
decl_stmt|;
name|u8
name|ll2_syn_handle
decl_stmt|;
name|u8
name|ll2_ooo_handle
decl_stmt|;
name|u8
name|ll2_mpa_handle
decl_stmt|;
name|u8
name|peer2peer
decl_stmt|;
name|u8
name|_pad
decl_stmt|;
name|enum
name|mpa_negotiation_mode
name|mpa_rev
decl_stmt|;
name|enum
name|mpa_rtr_type
name|rtr_type
decl_stmt|;
name|struct
name|ecore_iwarp_fpdu
modifier|*
name|partial_fpdus
decl_stmt|;
name|struct
name|ecore_iwarp_ll2_mpa_buf
modifier|*
name|mpa_bufs
decl_stmt|;
name|u8
modifier|*
name|mpa_intermediate_buf
decl_stmt|;
name|u16
name|max_num_partial_fpdus
decl_stmt|;
comment|/* MPA statistics */
name|u64
name|unalign_rx_comp
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_ECORE_DCQCN
parameter_list|(
name|p_hwfn
parameter_list|)
define|\
value|(!!(p_hwfn->pf_params.rdma_pf_params.enable_dcqcn))
end_define

begin_struct
struct|struct
name|ecore_roce_info
block|{
name|struct
name|roce_events_stats
name|event_stats
decl_stmt|;
name|u8
name|dcqcn_enabled
decl_stmt|;
name|u8
name|dcqcn_reaction_point
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_rdma_info
block|{
name|osal_spinlock_t
name|lock
decl_stmt|;
name|struct
name|ecore_bmap
name|cq_map
decl_stmt|;
name|struct
name|ecore_bmap
name|pd_map
decl_stmt|;
name|struct
name|ecore_bmap
name|tid_map
decl_stmt|;
name|struct
name|ecore_bmap
name|srq_map
decl_stmt|;
name|struct
name|ecore_bmap
name|cid_map
decl_stmt|;
name|struct
name|ecore_bmap
name|tcp_cid_map
decl_stmt|;
name|struct
name|ecore_bmap
name|real_cid_map
decl_stmt|;
name|struct
name|ecore_bmap
name|dpi_map
decl_stmt|;
name|struct
name|ecore_bmap
name|toggle_bits
decl_stmt|;
name|struct
name|ecore_rdma_events
name|events
decl_stmt|;
name|struct
name|ecore_rdma_device
modifier|*
name|dev
decl_stmt|;
name|struct
name|ecore_rdma_port
modifier|*
name|port
decl_stmt|;
name|u32
name|last_tid
decl_stmt|;
name|u8
name|num_cnqs
decl_stmt|;
name|struct
name|rdma_sent_stats
name|rdma_sent_pstats
decl_stmt|;
name|struct
name|rdma_rcv_stats
name|rdma_rcv_tstats
decl_stmt|;
name|u32
name|num_qps
decl_stmt|;
name|u32
name|num_mrs
decl_stmt|;
name|u32
name|num_srqs
decl_stmt|;
name|u16
name|queue_zone_base
decl_stmt|;
name|u16
name|max_queue_zones
decl_stmt|;
name|enum
name|protocol_type
name|proto
decl_stmt|;
name|struct
name|ecore_roce_info
name|roce
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_ECORE_IWARP
name|struct
name|ecore_iwarp_info
name|iwarp
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ECORE_IWARP
end_ifdef

begin_enum
enum|enum
name|ecore_iwarp_qp_state
block|{
name|ECORE_IWARP_QP_STATE_IDLE
block|,
name|ECORE_IWARP_QP_STATE_RTS
block|,
name|ECORE_IWARP_QP_STATE_TERMINATE
block|,
name|ECORE_IWARP_QP_STATE_CLOSING
block|,
name|ECORE_IWARP_QP_STATE_ERROR
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ecore_rdma_qp
block|{
name|struct
name|regpair
name|qp_handle
decl_stmt|;
name|struct
name|regpair
name|qp_handle_async
decl_stmt|;
name|u32
name|qpid
decl_stmt|;
comment|/* iwarp: may differ from icid */
name|u16
name|icid
decl_stmt|;
name|enum
name|ecore_roce_qp_state
name|cur_state
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_ECORE_IWARP
name|enum
name|ecore_iwarp_qp_state
name|iwarp_state
decl_stmt|;
endif|#
directive|endif
name|bool
name|use_srq
decl_stmt|;
name|bool
name|signal_all
decl_stmt|;
name|bool
name|fmr_and_reserved_lkey
decl_stmt|;
name|bool
name|incoming_rdma_read_en
decl_stmt|;
name|bool
name|incoming_rdma_write_en
decl_stmt|;
name|bool
name|incoming_atomic_en
decl_stmt|;
name|bool
name|e2e_flow_control_en
decl_stmt|;
name|u16
name|pd
decl_stmt|;
comment|/* Protection domain */
name|u16
name|pkey
decl_stmt|;
comment|/* Primary P_key index */
name|u32
name|dest_qp
decl_stmt|;
name|u16
name|mtu
decl_stmt|;
name|u16
name|srq_id
decl_stmt|;
name|u8
name|traffic_class_tos
decl_stmt|;
comment|/* IPv6/GRH traffic class; IPv4 TOS */
name|u8
name|hop_limit_ttl
decl_stmt|;
comment|/* IPv6/GRH hop limit; IPv4 TTL */
name|u16
name|dpi
decl_stmt|;
name|u32
name|flow_label
decl_stmt|;
comment|/* ignored in IPv4 */
name|u16
name|vlan_id
decl_stmt|;
name|u32
name|ack_timeout
decl_stmt|;
name|u8
name|retry_cnt
decl_stmt|;
name|u8
name|rnr_retry_cnt
decl_stmt|;
name|u8
name|min_rnr_nak_timer
decl_stmt|;
name|bool
name|sqd_async
decl_stmt|;
name|union
name|ecore_gid
name|sgid
decl_stmt|;
comment|/* GRH SGID; IPv4/6 Source IP */
name|union
name|ecore_gid
name|dgid
decl_stmt|;
comment|/* GRH DGID; IPv4/6 Destination IP */
name|enum
name|roce_mode
name|roce_mode
decl_stmt|;
name|u16
name|udp_src_port
decl_stmt|;
comment|/* RoCEv2 only */
name|u8
name|stats_queue
decl_stmt|;
comment|/* requeseter */
name|u8
name|max_rd_atomic_req
decl_stmt|;
name|u32
name|sq_psn
decl_stmt|;
name|u16
name|sq_cq_id
decl_stmt|;
comment|/* The cq to be associated with the send queue*/
name|u16
name|sq_num_pages
decl_stmt|;
name|dma_addr_t
name|sq_pbl_ptr
decl_stmt|;
name|void
modifier|*
name|orq
decl_stmt|;
name|dma_addr_t
name|orq_phys_addr
decl_stmt|;
name|u8
name|orq_num_pages
decl_stmt|;
name|bool
name|req_offloaded
decl_stmt|;
comment|/* responder */
name|u8
name|max_rd_atomic_resp
decl_stmt|;
name|u32
name|rq_psn
decl_stmt|;
name|u16
name|rq_cq_id
decl_stmt|;
comment|/* The cq to be associated with the receive queue */
name|u16
name|rq_num_pages
decl_stmt|;
name|dma_addr_t
name|rq_pbl_ptr
decl_stmt|;
name|void
modifier|*
name|irq
decl_stmt|;
name|dma_addr_t
name|irq_phys_addr
decl_stmt|;
name|u8
name|irq_num_pages
decl_stmt|;
name|bool
name|resp_offloaded
decl_stmt|;
name|u32
name|cq_prod
decl_stmt|;
name|u8
name|remote_mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|local_mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|void
modifier|*
name|shared_queue
decl_stmt|;
name|dma_addr_t
name|shared_queue_phys_addr
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_ECORE_IWARP
name|struct
name|ecore_iwarp_ep
modifier|*
name|ep
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ECORE_IWARP
end_ifdef

begin_enum
enum|enum
name|ecore_iwarp_ep_state
block|{
name|ECORE_IWARP_EP_INIT
block|,
name|ECORE_IWARP_EP_MPA_REQ_RCVD
block|,
name|ECORE_IWARP_EP_ESTABLISHED
block|,
name|ECORE_IWARP_EP_CLOSED
block|}
enum|;
end_enum

begin_union
union|union
name|async_output
block|{
name|struct
name|iwarp_eqe_data_mpa_async_completion
name|mpa_response
decl_stmt|;
name|struct
name|iwarp_eqe_data_tcp_async_completion
name|mpa_request
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Endpoint structure represents a TCP connection. This connection can be  * associated with a QP or not (in which case QP==NULL)  */
end_comment

begin_struct
struct|struct
name|ecore_iwarp_ep
block|{
name|osal_list_entry_t
name|list_entry
decl_stmt|;
name|int
name|sig
decl_stmt|;
name|struct
name|ecore_rdma_qp
modifier|*
name|qp
decl_stmt|;
name|enum
name|ecore_iwarp_ep_state
name|state
decl_stmt|;
comment|/* This contains entire buffer required for ep memories. This is the 	 * only one actually allocated and freed. The rest are pointers into 	 * this buffer 	 */
name|void
modifier|*
name|ep_buffer_virt
decl_stmt|;
name|dma_addr_t
name|ep_buffer_phys
decl_stmt|;
comment|/* Asynce EQE events contain only the ep pointer on the completion. The 	 * rest of the data is written to an output buffer pre-allocated by 	 * the driver. This buffer points to a location in the ep_buffer. 	 */
name|union
name|async_output
modifier|*
name|async_output_virt
decl_stmt|;
name|dma_addr_t
name|async_output_phys
decl_stmt|;
name|struct
name|ecore_iwarp_cm_info
name|cm_info
decl_stmt|;
name|enum
name|tcp_connect_mode
name|connect_mode
decl_stmt|;
name|enum
name|mpa_rtr_type
name|rtr_type
decl_stmt|;
name|enum
name|mpa_negotiation_mode
name|mpa_rev
decl_stmt|;
name|u32
name|tcp_cid
decl_stmt|;
name|u32
name|cid
decl_stmt|;
name|u8
name|remote_mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|local_mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|mss
decl_stmt|;
name|bool
name|mpa_reply_processed
decl_stmt|;
comment|/* The event_cb function is called for asynchrounous events associated 	 * with the ep. It is initialized at different entry points depending 	 * on whether the ep is the tcp connection active side or passive side 	 * The cb_context is passed to the event_cb function. 	 */
name|iwarp_event_handler
name|event_cb
decl_stmt|;
name|void
modifier|*
name|cb_context
decl_stmt|;
comment|/* For Passive side - syn packet related data */
name|struct
name|ecore_iwarp_ll2_buff
modifier|*
name|syn
decl_stmt|;
name|u16
name|syn_ip_payload_length
decl_stmt|;
name|dma_addr_t
name|syn_phy_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_iwarp_listener
block|{
name|osal_list_entry_t
name|list_entry
decl_stmt|;
comment|/* The event_cb function is called for connection requests. 	 * The cb_context is passed to the event_cb function. 	 */
name|iwarp_event_handler
name|event_cb
decl_stmt|;
name|void
modifier|*
name|cb_context
decl_stmt|;
name|u32
name|max_backlog
decl_stmt|;
name|u8
name|ip_version
decl_stmt|;
name|u32
name|ip_addr
index|[
literal|4
index|]
decl_stmt|;
name|u16
name|port
decl_stmt|;
name|u16
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ecore_iwarp_async_event
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|fw_event_code
parameter_list|,
name|struct
name|regpair
modifier|*
name|fw_handle
parameter_list|,
name|u8
name|fw_return_code
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_ECORE_IWARP */
end_comment

begin_function_decl
name|void
name|ecore_roce_async_event
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|fw_event_code
parameter_list|,
name|union
name|rdma_eqe_data
modifier|*
name|rdma_data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__ECORE_RDMA_H__*/
end_comment

end_unit

