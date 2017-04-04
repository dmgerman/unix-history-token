begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_LL2_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_LL2_API_H__
end_define

begin_comment
comment|/* ECORE LL2 API: called by ECORE's upper level client  */
end_comment

begin_comment
comment|/* must be the asme as core_rx_conn_type */
end_comment

begin_enum
enum|enum
name|ecore_ll2_conn_type
block|{
name|ECORE_LL2_TYPE_FCOE
comment|/* FCoE L2 connection */
block|,
name|ECORE_LL2_TYPE_ISCSI
comment|/* Iscsi L2 connection */
block|,
name|ECORE_LL2_TYPE_TEST
comment|/* Eth TB test connection */
block|,
name|ECORE_LL2_TYPE_OOO
comment|/* Iscsi OOO L2 connection */
block|,
name|ECORE_LL2_TYPE_TOE
comment|/* toe L2 connection */
block|,
name|ECORE_LL2_TYPE_ROCE
comment|/* RoCE L2 connection */
block|,
name|ECORE_LL2_TYPE_IWARP
block|,
name|MAX_ECORE_LL2_RX_CONN_TYPE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ecore_ll2_roce_flavor_type
block|{
name|ECORE_LL2_ROCE
block|,
comment|/* use this as default or d/c */
name|ECORE_LL2_RROCE
block|,
name|MAX_ECORE_LL2_ROCE_FLAVOR_TYPE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ecore_ll2_tx_dest
block|{
name|ECORE_LL2_TX_DEST_NW
comment|/* Light L2 TX Destination to the Network */
block|,
name|ECORE_LL2_TX_DEST_LB
comment|/* Light L2 TX Destination to the Loopback */
block|,
name|ECORE_LL2_TX_DEST_DROP
comment|/* Light L2 Drop the TX packet */
block|,
name|ECORE_LL2_TX_DEST_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ecore_ll2_error_handle
block|{
name|ECORE_LL2_DROP_PACKET
comment|/* If error occurs drop packet */
block|,
name|ECORE_LL2_DO_NOTHING
comment|/* If error occurs do nothing */
block|,
name|ECORE_LL2_ASSERT
comment|/* If error occurs assert */
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_ll2_stats
block|{
name|u64
name|gsi_invalid_hdr
decl_stmt|;
name|u64
name|gsi_invalid_pkt_length
decl_stmt|;
name|u64
name|gsi_unsupported_pkt_typ
decl_stmt|;
name|u64
name|gsi_crcchksm_error
decl_stmt|;
name|u64
name|packet_too_big_discard
decl_stmt|;
name|u64
name|no_buff_discard
decl_stmt|;
name|u64
name|rcv_ucast_bytes
decl_stmt|;
name|u64
name|rcv_mcast_bytes
decl_stmt|;
name|u64
name|rcv_bcast_bytes
decl_stmt|;
name|u64
name|rcv_ucast_pkts
decl_stmt|;
name|u64
name|rcv_mcast_pkts
decl_stmt|;
name|u64
name|rcv_bcast_pkts
decl_stmt|;
name|u64
name|sent_ucast_bytes
decl_stmt|;
name|u64
name|sent_mcast_bytes
decl_stmt|;
name|u64
name|sent_bcast_bytes
decl_stmt|;
name|u64
name|sent_ucast_pkts
decl_stmt|;
name|u64
name|sent_mcast_pkts
decl_stmt|;
name|u64
name|sent_bcast_pkts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_ll2_comp_rx_data
block|{
name|u8
name|connection_handle
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
name|dma_addr_t
name|rx_buf_addr
decl_stmt|;
name|u16
name|parse_flags
decl_stmt|;
name|u16
name|err_flags
decl_stmt|;
name|u16
name|vlan
decl_stmt|;
name|bool
name|b_last_packet
decl_stmt|;
union|union
block|{
name|u8
name|placement_offset
decl_stmt|;
name|u8
name|data_length_error
decl_stmt|;
block|}
name|u
union|;
union|union
block|{
name|u16
name|packet_length
decl_stmt|;
name|u16
name|data_length
decl_stmt|;
block|}
name|length
union|;
name|u32
name|opaque_data_0
decl_stmt|;
comment|/* src_mac_addr_hi */
name|u32
name|opaque_data_1
decl_stmt|;
comment|/* src_mac_addr_lo */
comment|/* GSI only */
name|u32
name|gid_dst
index|[
literal|4
index|]
decl_stmt|;
name|u16
name|qp_id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ecore_ll2_complete_rx_packet_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|struct
name|ecore_ll2_comp_rx_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ecore_ll2_release_rx_packet_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|dma_addr_t
name|rx_buf_addr
parameter_list|,
name|bool
name|b_last_packet
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ecore_ll2_complete_tx_packet_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|dma_addr_t
name|first_frag_addr
parameter_list|,
name|bool
name|b_last_fragment
parameter_list|,
name|bool
name|b_last_packet
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ecore_ll2_release_tx_packet_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|dma_addr_t
name|first_frag_addr
parameter_list|,
name|bool
name|b_last_fragment
parameter_list|,
name|bool
name|b_last_packet
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ecore_ll2_cbs
block|{
name|ecore_ll2_complete_rx_packet_cb
name|rx_comp_cb
decl_stmt|;
name|ecore_ll2_release_rx_packet_cb
name|rx_release_cb
decl_stmt|;
name|ecore_ll2_complete_tx_packet_cb
name|tx_comp_cb
decl_stmt|;
name|ecore_ll2_release_tx_packet_cb
name|tx_release_cb
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_ll2_acquire_data
block|{
name|enum
name|ecore_ll2_conn_type
name|conn_type
decl_stmt|;
name|u16
name|mtu
decl_stmt|;
comment|/* Maximum bytes that can be placed on a BD*/
name|u16
name|rx_num_desc
decl_stmt|;
comment|/* Relevant only for OOO connection if 0 OOO rx buffers=2*rx_num_desc */
name|u16
name|rx_num_ooo_buffers
decl_stmt|;
name|u8
name|rx_drop_ttl0_flg
decl_stmt|;
comment|/* if set, 802.1q tags will be removed and copied to CQE */
name|u8
name|rx_vlan_removal_en
decl_stmt|;
name|u16
name|tx_num_desc
decl_stmt|;
name|u8
name|tx_max_bds_per_packet
decl_stmt|;
name|u8
name|tx_tc
decl_stmt|;
name|enum
name|ecore_ll2_tx_dest
name|tx_dest
decl_stmt|;
name|enum
name|ecore_ll2_error_handle
name|ai_err_packet_too_big
decl_stmt|;
name|enum
name|ecore_ll2_error_handle
name|ai_err_no_buf
decl_stmt|;
name|u8
name|secondary_queue
decl_stmt|;
name|u8
name|gsi_enable
decl_stmt|;
comment|/* Output container for LL2 connection's handle */
name|u8
modifier|*
name|p_connection_handle
decl_stmt|;
specifier|const
name|struct
name|ecore_ll2_cbs
modifier|*
name|cbs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_ll2_acquire_connection - allocate resources,  *        starts rx& tx (if relevant) queues pair. Provides  *        connecion handler as output parameter.  *  *  * @param p_hwfn  * @param data - describes connection parameters  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_acquire_connection
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|struct
name|ecore_ll2_acquire_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ll2_establish_connection - start previously  *        allocated LL2 queues pair  *  * @param p_hwfn  * @param p_ptt  * @param connection_handle    LL2 connection's handle  *                              obtained from  *                              ecore_ll2_require_connection  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_establish_connection
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ll2_post_rx_buffers - submit buffers to LL2 RxQ.  *  * @param p_hwfn  * @param connection_handle    LL2 connection's handle  *                              obtained from  *                              ecore_ll2_require_connection  * @param addr                  rx (physical address) buffers to  *                              submit  * @param cookie  * @param notify_fw             produce corresponding Rx BD  *                              immediately  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_post_rx_buffer
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|dma_addr_t
name|addr
parameter_list|,
name|u16
name|buf_len
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|u8
name|notify_fw
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ecore_ll2_tx_pkt_info
block|{
name|u8
name|num_of_bds
decl_stmt|;
name|u16
name|vlan
decl_stmt|;
name|u8
name|bd_flags
decl_stmt|;
name|u16
name|l4_hdr_offset_w
decl_stmt|;
comment|/* from start of packet */
name|enum
name|ecore_ll2_tx_dest
name|tx_dest
decl_stmt|;
name|enum
name|ecore_ll2_roce_flavor_type
name|ecore_roce_flavor
decl_stmt|;
name|dma_addr_t
name|first_frag
decl_stmt|;
name|u16
name|first_frag_len
decl_stmt|;
name|bool
name|enable_ip_cksum
decl_stmt|;
name|bool
name|enable_l4_cksum
decl_stmt|;
name|bool
name|calc_ip_len
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_ll2_prepare_tx_packet - request for start Tx BD  *        to prepare Tx packet submission to FW.  *  *  * @param p_hwfn  * @param pkt - info regarding the tx packet  * @param notify_fw - issue doorbell to fw for this packet  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_prepare_tx_packet
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|struct
name|ecore_ll2_tx_pkt_info
modifier|*
name|pkt
parameter_list|,
name|bool
name|notify_fw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ll2_release_connection - releases resources  *        allocated for LL2 connection  *  * @param p_hwfn  * @param connection_handle    LL2 connection's handle  *                              obtained from  *                              ecore_ll2_require_connection  */
end_comment

begin_function_decl
name|void
name|ecore_ll2_release_connection
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ll2_set_fragment_of_tx_packet - provides  *        fragments to fill Tx BD of BDs requested by  *        ecore_ll2_prepare_tx_packet..  *  *  * @param p_hwfn  * @param connection_handle    LL2 connection's handle  *                              obtained from  *                              ecore_ll2_require_connection  * @param addr  * @param nbytes  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_set_fragment_of_tx_packet
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|dma_addr_t
name|addr
parameter_list|,
name|u16
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ll2_terminate_connection - stops Tx/Rx queues  *  *  * @param p_hwfn  * @param connection_handle    LL2 connection's handle  *                              obtained from  *                              ecore_ll2_require_connection  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_terminate_connection
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ll2_get_stats - get LL2 queue's statistics  *  *  * @param p_hwfn  * @param connection_handle    LL2 connection's handle  *                              obtained from  *                              ecore_ll2_require_connection  * @param p_stats  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ll2_get_stats
parameter_list|(
name|void
modifier|*
name|cxt
parameter_list|,
name|u8
name|connection_handle
parameter_list|,
name|struct
name|ecore_ll2_stats
modifier|*
name|p_stats
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

