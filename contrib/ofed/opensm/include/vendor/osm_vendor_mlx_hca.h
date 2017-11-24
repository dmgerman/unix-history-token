begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_HCA_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_HCA_H_
end_define

begin_include
include|#
directive|include
file|<vendor/osm_vendor.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx_inout.h>
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
if|#
directive|if
name|defined
argument_list|(
name|OSM_VENDOR_INTF_TS_NO_VAPI
argument_list|)
operator|||
name|defined
argument_list|(
name|OSM_VENDOR_INTF_SIM
argument_list|)
define|#
directive|define
name|VAPI_hca_hndl_t
value|uint32_t
define|#
directive|define
name|VAPI_hca_id_t
value|char*
endif|#
directive|endif
name|ib_api_status_t
name|osm_vendor_get_guid_ca_and_port
parameter_list|(
name|IN
name|osm_vendor_t
specifier|const
modifier|*
name|p_vend
parameter_list|,
name|IN
name|ib_net64_t
specifier|const
name|guid
parameter_list|,
name|OUT
name|uint32_t
modifier|*
name|p_hca_hndl
parameter_list|,
name|OUT
name|char
modifier|*
name|p_hca_id
parameter_list|,
name|OUT
name|uint8_t
modifier|*
name|p_hca_idx
parameter_list|,
name|OUT
name|uint32_t
modifier|*
name|p_port_num
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
comment|/* _OSMV_HCA_H_ */
end_comment

end_unit

