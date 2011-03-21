begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_RMPP_CTX_H
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_RMPP_CTX_H
end_define

begin_include
include|#
directive|include
file|<complib/cl_event.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx_sar.h>
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

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|_osmv_rmpp_send_ctx
block|{
name|uint8_t
name|status
decl_stmt|;
name|uint32_t
name|window_first
decl_stmt|;
name|uint32_t
name|window_last
decl_stmt|;
name|uint32_t
name|mad_sz
decl_stmt|;
name|boolean_t
name|is_sa_mad
decl_stmt|;
name|cl_event_t
name|event
decl_stmt|;
comment|/* Segmentation engine */
name|osmv_rmpp_sar_t
name|sar
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
block|}
name|osmv_rmpp_send_ctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osmv_rmpp_recv_ctx
block|{
name|boolean_t
name|is_sa_mad
decl_stmt|;
name|uint32_t
name|expected_seg
decl_stmt|;
comment|/* Reassembly buffer */
name|cl_qlist_t
modifier|*
name|p_rbuf
decl_stmt|;
comment|/* Reassembly engine */
name|osmv_rmpp_sar_t
name|sar
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
block|}
name|osmv_rmpp_recv_ctx_t
typedef|;
end_typedef

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_init  *  * DESCRIPTION  *  c'tor for rmpp_send_ctx obj  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_send_ctx_init
parameter_list|(
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_ctx
parameter_list|,
name|void
modifier|*
name|arbt_mad
parameter_list|,
name|uint32_t
name|mad_sz
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_done  *  * DESCRIPTION  *  d'tor for rmpp_send_ctx obj  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|void
name|osmv_rmpp_send_ctx_done
parameter_list|(
name|IN
name|osmv_rmpp_send_ctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_get_wf  *  * DESCRIPTION  *  returns number of first segment in current window  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osmv_rmpp_send_ctx_get_wf
parameter_list|(
name|IN
specifier|const
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_ctx
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_ctx
argument_list|)
expr_stmt|;
return|return
name|p_ctx
operator|->
name|window_first
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_set_wf  *  * DESCRIPTION  *  sets number of first segment in current window  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osmv_rmpp_send_ctx_set_wf
parameter_list|(
name|IN
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_ctx
parameter_list|,
name|IN
name|uint32_t
name|val
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_ctx
argument_list|)
expr_stmt|;
name|p_ctx
operator|->
name|window_first
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_get_wl  *  * DESCRIPTION  *  returns number of last segment in current window  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osmv_rmpp_send_ctx_get_wl
parameter_list|(
name|IN
specifier|const
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_send_ctx
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_send_ctx
argument_list|)
expr_stmt|;
return|return
name|p_send_ctx
operator|->
name|window_last
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_set_wl  *  * DESCRIPTION  *  sets number of last segment in current window  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osmv_rmpp_send_ctx_set_wl
parameter_list|(
name|IN
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_ctx
parameter_list|,
name|IN
name|uint32_t
name|val
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_ctx
argument_list|)
expr_stmt|;
name|p_ctx
operator|->
name|window_last
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_get_num_segs  *  * DESCRIPTION  *   returns the total number of mad segments to send  * SEE ALSO  *  */
end_comment

begin_function_decl
name|uint32_t
name|osmv_rmpp_send_ctx_get_num_segs
parameter_list|(
name|IN
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_send_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_send_ctx_get_seg  *  * DESCRIPTION  *   Retrieves the mad segment by seg number (including setting the mad relevant bits& hdrs)  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_send_ctx_get_seg
parameter_list|(
name|IN
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_send_ctx
parameter_list|,
name|IN
name|uint32_t
name|seg_idx
parameter_list|,
name|IN
name|uint32_t
name|resp_timeout
parameter_list|,
name|OUT
name|void
modifier|*
name|p_mad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_recv_ctx_init  *  * DESCRIPTION  *   c'tor for rmpp_recv_ctx obj  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_recv_ctx_init
parameter_list|(
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_ctx
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_recv_ctx_done  *  * DESCRIPTION  *   d'tor for rmpp_recv_ctx obj  * SEE ALSO  *  */
end_comment

begin_function_decl
name|void
name|osmv_rmpp_recv_ctx_done
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_recv_ctx_get_es  *  * DESCRIPTION  *   retrunes index of expected segement in the curr window  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osmv_rmpp_recv_ctx_get_es
parameter_list|(
name|IN
specifier|const
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_recv_ctx
argument_list|)
expr_stmt|;
return|return
name|p_recv_ctx
operator|->
name|expected_seg
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_rmpp_recv_ctx_set_es  *  * DESCRIPTION  *   sets index of expected segement in the curr window  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osmv_rmpp_recv_ctx_set_es
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|,
name|IN
name|uint32_t
name|val
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_recv_ctx
argument_list|)
expr_stmt|;
name|p_recv_ctx
operator|->
name|expected_seg
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_rmpp_recv_ctx_store_madw_seg  *  * DESCRIPTION  *  stores rmpp mad in the list  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_recv_ctx_store_mad_seg
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|,
name|IN
name|void
modifier|*
name|p_mad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|osmv_rmpp_recv_ctx_get_cur_byte_num
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|osmv_rmpp_recv_ctx_get_byte_num_from_first
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|osmv_rmpp_recv_ctx_get_byte_num_from_last
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_recv_ctx_reassemble_arbt_mad  *  * DESCRIPTION  *  reassembles all rmpp buffs to one big arbitrary mad  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_recv_ctx_reassemble_arbt_mad
parameter_list|(
name|IN
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_recv_ctx
parameter_list|,
name|IN
name|uint32_t
name|size
parameter_list|,
name|IN
name|void
modifier|*
name|p_arbt_mad
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

