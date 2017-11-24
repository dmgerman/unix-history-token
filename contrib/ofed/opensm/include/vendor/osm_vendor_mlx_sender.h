begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_RMPP_SENDER_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_RMPP_SENDER_H_
end_define

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx_txn.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_function_decl
name|BEGIN_C_DECLS
comment|/****d* OSM Vendor/osmv_simple_send_madw  * NAME  *   osmv_simple_send_madw  *  * DESCRIPTION  *   Send a single MAD (256 bytes).  *  *   If this MAD requires a response, set the timeout event.  *   The function call returns when the MAD's send completion is received.  *  */
name|ib_api_status_t
name|osmv_simple_send_madw
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
specifier|const
name|p_madw
parameter_list|,
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|,
name|IN
name|boolean_t
name|is_retry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****d* OSM Vendor/osmv_rmpp_send_madw  * NAME  *   osmv_rmpp_send_madw  *  * DESCRIPTION  *	Send a single MAD wrapper (of arbitrary length).  *      Follow the RMPP semantics  *      (segmentation, send window, timeouts etc).  *  *      The function call returns either when the whole MAD  *      has been acknowledged, or upon error.  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_send_madw
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
specifier|const
name|p_madw
parameter_list|,
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|,
name|IN
name|boolean_t
name|is_rmpp_ds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  NAME            osmv_rmpp_send_ack  *  *  DESCRIPTION  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_send_ack
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
specifier|const
name|ib_mad_t
modifier|*
name|p_req_mad
parameter_list|,
name|IN
name|uint32_t
name|seg_num
parameter_list|,
name|IN
name|uint32_t
name|nwl
parameter_list|,
name|IN
specifier|const
name|osm_mad_addr_t
modifier|*
name|p_mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  NAME           osmv_rmpp_send_nak  *  *  DESCRIPTION    Send the RMPP ABORT or STOP packet  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_send_nak
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
specifier|const
name|ib_mad_t
modifier|*
name|p_req_mad
parameter_list|,
name|IN
specifier|const
name|osm_mad_addr_t
modifier|*
name|p_mad_addr
parameter_list|,
name|IN
name|uint8_t
name|nak_type
parameter_list|,
name|IN
name|uint8_t
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  NAME           osmv_rmpp_snd_error  *  *  DESCRIPTION    Mark an error status and signal the sender thread to handle it  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osmv_rmpp_snd_error
parameter_list|(
name|IN
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_send_ctx
parameter_list|,
name|IN
name|ib_api_status_t
name|status
parameter_list|)
block|{
name|p_send_ctx
operator|->
name|status
operator|=
name|status
expr_stmt|;
comment|/* Release the thread waiting on send() 	 * It will release the transaction's context 	 */
name|cl_event_signal
argument_list|(
operator|&
name|p_send_ctx
operator|->
name|event
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSMV_RMPP_SENDER_H_ */
end_comment

end_unit

