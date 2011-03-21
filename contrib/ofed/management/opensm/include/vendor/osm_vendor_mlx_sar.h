begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_SAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_SAR_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
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
name|_osmv_rmpp_sar
block|{
name|void
modifier|*
name|p_arbt_mad
decl_stmt|;
name|uint32_t
name|data_len
decl_stmt|;
comment|/* total data len in all the mads */
comment|/* these data members contain only constants */
name|uint32_t
name|hdr_sz
decl_stmt|;
name|uint32_t
name|data_sz
decl_stmt|;
comment|/*typical data sz for this kind of mad (sa or regular */
block|}
name|osmv_rmpp_sar_t
typedef|;
end_typedef

begin_comment
comment|/*  * NAME  *   osmv_rmpp_sar_alloc  *  * DESCRIPTION  *   c'tor for rmpp_sar object  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_sar_init
parameter_list|(
name|osmv_rmpp_sar_t
modifier|*
name|p_sar
parameter_list|,
name|void
modifier|*
name|p_arbt_mad
parameter_list|,
name|uint32_t
name|mad_size
parameter_list|,
name|boolean_t
name|is_sa_mad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_sar_dealloc  *  * DESCRIPTION  *   d'tor for rmpp_sar object  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|void
name|osmv_rmpp_sar_done
parameter_list|(
name|osmv_rmpp_sar_t
modifier|*
name|p_sar
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_sar_get_mad_seg  *  * DESCRIPTION  *  segments the original mad buffer . returnes a mad with the data of the i-th segment  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_sar_get_mad_seg
parameter_list|(
name|osmv_rmpp_sar_t
modifier|*
name|p_sar
parameter_list|,
name|uint32_t
name|seg_idx
parameter_list|,
name|void
modifier|*
name|p_buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_sar_reassemble_arbt_mad  *  * DESCRIPTION  *  gets a qlist of mads and reassmbles to one big mad buffer  *  ALSO - deallocates the mad list  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_rmpp_sar_reassemble_arbt_mad
parameter_list|(
name|osmv_rmpp_sar_t
modifier|*
name|p_sar
parameter_list|,
name|cl_qlist_t
modifier|*
name|p_bufs
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

begin_comment
comment|/* _OSMV_SAR_H_ */
end_comment

end_unit

