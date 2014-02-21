begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  *    mad.h -  *      Header file for common special QP resources creation code.  *  *  Creation date:  *  *  Version: osmt_mtl_regular_qp.h,v 1.2 2003/03/20 16:05:10 eitan  *  *  Authors:  *    Elazar Raab  *  *  Changes:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|H_MAD_H
end_ifndef

begin_define
define|#
directive|define
name|H_MAD_H
end_define

begin_include
include|#
directive|include
file|<vapi.h>
end_include

begin_include
include|#
directive|include
file|<evapi.h>
end_include

begin_include
include|#
directive|include
file|<vapi_common.h>
end_include

begin_include
include|#
directive|include
file|<ib_defs.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAD_IN
argument_list|)
operator|||
name|defined
argument_list|(
name|MAD_OUT
argument_list|)
end_if

begin_error
error|#
directive|error
error|MACROS MAD_IN and MAD_OUT are in use, do not override
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAD_IN
end_define

begin_define
define|#
directive|define
name|MAD_OUT
end_define

begin_comment
comment|/* HCA Constants */
end_comment

begin_define
define|#
directive|define
name|HCA_ID
value|"mt21108_pci0"
end_define

begin_define
define|#
directive|define
name|GRH_LEN
value|40
end_define

begin_define
define|#
directive|define
name|KNOWN_QP1_QKEY
value|0x80010000
end_define

begin_define
define|#
directive|define
name|MAX_OUTS_SQ
value|2
end_define

begin_comment
comment|/* Max. buffers posted for requests in SQ */
end_comment

begin_define
define|#
directive|define
name|MAX_OUTS_RQ
value|5
end_define

begin_comment
comment|/* Max. buffers posted for responses in RQ */
end_comment

begin_define
define|#
directive|define
name|MAX_POLL_CNT
value|300
end_define

begin_define
define|#
directive|define
name|POLL_SLEEP
value|1
end_define

begin_comment
comment|/* for usleep */
end_comment

begin_define
define|#
directive|define
name|MAD_SIZE
value|256
end_define

begin_comment
comment|/* MADs are always 256B */
end_comment

begin_define
define|#
directive|define
name|MAD_ATTR_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|MAD_TID_OFFSET
value|8
end_define

begin_comment
comment|/* Verbs SQP resources handles */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|VAPI_hca_id_t
name|hca_id
decl_stmt|;
comment|/*id of HCA */
name|u_int8_t
name|port_num
decl_stmt|;
comment|/* the port num to use */
name|VAPI_hca_hndl_t
name|hca_hndl
decl_stmt|;
comment|/*handle of HCA */
name|VAPI_qp_hndl_t
name|qp_hndl
decl_stmt|;
comment|/*handle of QP I use */
name|VAPI_mr_hndl_t
name|mr_hndl
decl_stmt|;
comment|/*handle of memory region */
name|VAPI_cq_hndl_t
name|rq_cq_hndl
decl_stmt|,
name|sq_cq_hndl
decl_stmt|;
comment|/*handle of send& receive completion Queues */
name|VAPI_pd_hndl_t
name|pd_hndl
decl_stmt|;
comment|/*handle of Partition Domain */
comment|/* VAPI_ud_av_hndl_t   av_hndl; */
name|IB_lid_t
name|slid
decl_stmt|;
comment|/*LID*/
name|void
modifier|*
name|buf_ptr
decl_stmt|;
comment|/*mem buffer for outstanding pkts */
name|MT_size_t
name|buf_size
decl_stmt|;
comment|/*size of mem buffer for outstanding pkts */
name|u_int32_t
name|max_outs_sq
decl_stmt|;
comment|/*max # of outstanding pkts in send queue */
name|u_int32_t
name|max_outs_rq
decl_stmt|;
comment|/*max # of outstanding pkts in receive queue */
name|IB_rkey_t
name|l_key
decl_stmt|;
comment|/*my l_key for memory regions */
name|VAPI_qkey_t
name|qkey
decl_stmt|;
comment|/*my qkey */
name|EVAPI_compl_handler_hndl_t
name|rq_cq_eventh
decl_stmt|,
name|sq_cq_eventh
decl_stmt|;
comment|/* event handlers for polling */
name|bool
name|is_sqp
decl_stmt|;
comment|/* relate to union below - my QP */
union|union
block|{
name|VAPI_special_qp_t
name|sqp_type
decl_stmt|;
name|VAPI_qp_num_t
name|qp_num
decl_stmt|;
block|}
name|qp_id
union|;
name|void
modifier|*
name|wait_q
decl_stmt|;
block|}
name|osmt_mtl_mad_res_t
typedef|;
end_typedef

begin_comment
comment|/* init an osmt_mtl_mad_res_t with all resources initialized (use functions below) */
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_init
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
comment|/*pointer to res (resources) struct */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_init_opened_hca
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
comment|/*pointer to res (resources) struct */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cleanup all resources of (which are valid) in res */
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_mad_cleanup
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
comment|/*pointer to res (resources) struct */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create CQs and QP as given in res->is_sqp (if TRUE, get special QP) */
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_get_qp_resources
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
comment|/*pointer to res (resources) struct */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* move QP to RTS state */
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_mad_qp_init
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
comment|/*max number of outstanding packets allowed in send queue */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create and register res->buf_ptr */
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_mad_create_mr
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
comment|/*pointer to res (resources) struct */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_create_av
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
parameter_list|,
comment|/* pointer to res (resources) struct */
name|int16_t
name|dlid
parameter_list|,
comment|/*destination lid */
name|VAPI_ud_av_hndl_t
modifier|*
name|avh_p
comment|/* address vectr handle to update */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Send MAD to given dest QP*/
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_mad_send
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
parameter_list|,
comment|/*pointer to res (resources) struct */
name|VAPI_wr_id_t
name|id
parameter_list|,
comment|/*wqe ID */
name|void
modifier|*
name|mad
parameter_list|,
comment|/*mad buffer to send */
name|VAPI_qp_num_t
name|dest_qp
parameter_list|,
comment|/*destination QP */
name|IB_sl_t
name|sl
parameter_list|,
comment|/*Service Level */
name|u_int32_t
name|dest_qkey
parameter_list|,
comment|/*Destination QP KEY */
name|VAPI_ud_av_hndl_t
name|avh
comment|/* address vectr handle to use */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* post buffers to RQ. returns num of buffers actually posted */
end_comment

begin_function_decl
name|int
name|osmt_mtl_mad_post_recv_bufs
parameter_list|(
name|osmt_mtl_mad_res_t
modifier|*
name|res
parameter_list|,
comment|/*pointer to res (resources) struct */
name|void
modifier|*
name|buf_array
parameter_list|,
comment|/*array of receive buffers */
name|u_int32_t
name|num_o_bufs
parameter_list|,
comment|/*number of receive buffers */
name|u_int32_t
name|size
parameter_list|,
comment|/* size of expected receive packet - MAD */
name|VAPI_wr_id_t
name|start_id
comment|/* start id for receive buffers */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Poll given CQ for completion max_poll times (POLL_SLEEP [usec] delays). result in wc_desc_p. */
end_comment

begin_function_decl
name|VAPI_ret_t
name|osmt_mtl_mad_poll4cqe
parameter_list|(
name|VAPI_hca_hndl_t
name|hca
parameter_list|,
comment|/*handle for HCA */
name|VAPI_cq_hndl_t
name|cq
parameter_list|,
comment|/*handle for Completion Queue - Rcv/Send  */
name|VAPI_wc_desc_t
modifier|*
name|wc_desc_p
parameter_list|,
comment|/*handle of cqe */
name|u_int32_t
name|max_poll
parameter_list|,
comment|/*number of polling iterations */
name|u_int32_t
name|poll_sleep
parameter_list|,
comment|/*timeout for each polling    */
name|VAPI_ud_av_hndl_t
modifier|*
name|avh_p
comment|/* address vectopr handle to cleanup */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

