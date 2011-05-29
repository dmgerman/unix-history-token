begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Intel Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MAD_RMPP_H__
end_ifndef

begin_define
define|#
directive|define
name|__MAD_RMPP_H__
end_define

begin_enum
enum|enum
block|{
name|IB_RMPP_RESULT_PROCESSED
block|,
name|IB_RMPP_RESULT_CONSUMED
block|,
name|IB_RMPP_RESULT_INTERNAL
block|,
name|IB_RMPP_RESULT_UNHANDLED
block|}
enum|;
end_enum

begin_function_decl
name|int
name|ib_send_rmpp_mad
parameter_list|(
name|struct
name|ib_mad_send_wr_private
modifier|*
name|mad_send_wr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ib_mad_recv_wc
modifier|*
name|ib_process_rmpp_recv_wc
parameter_list|(
name|struct
name|ib_mad_agent_private
modifier|*
name|agent
parameter_list|,
name|struct
name|ib_mad_recv_wc
modifier|*
name|mad_recv_wc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ib_process_rmpp_send_wc
parameter_list|(
name|struct
name|ib_mad_send_wr_private
modifier|*
name|mad_send_wr
parameter_list|,
name|struct
name|ib_mad_send_wc
modifier|*
name|mad_send_wc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ib_rmpp_send_handler
parameter_list|(
name|struct
name|ib_mad_send_wc
modifier|*
name|mad_send_wc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ib_cancel_rmpp_recvs
parameter_list|(
name|struct
name|ib_mad_agent_private
modifier|*
name|agent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ib_retry_rmpp
parameter_list|(
name|struct
name|ib_mad_send_wr_private
modifier|*
name|mad_send_wr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MAD_RMPP_H__ */
end_comment

end_unit

