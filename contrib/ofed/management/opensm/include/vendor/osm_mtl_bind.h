begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_BIND_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_BIND_H_
end_define

begin_include
include|#
directive|include
file|<opensm/osm_helper.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mtl.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_opensm.h>
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

begin_comment
comment|/****s* OpenSM: Vendor/osm_vendor_mgt_bind * NAME *   osm_vendor_mgt_bind_t * * DESCRIPTION * 	Tracks the handles returned by IB_MGT to the SMI and GSI *  Nulled on init of the vendor obj. Populated on first bind. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vendor_mgt_bind
block|{
name|boolean_t
name|smi_init
decl_stmt|,
name|gsi_init
decl_stmt|;
name|IB_MGT_mad_hndl_t
name|smi_mads_hdl
decl_stmt|;
name|IB_MGT_mad_hndl_t
name|gsi_mads_hdl
decl_stmt|;
name|struct
name|_osm_mtl_bind_info
modifier|*
name|smi_p_bind
decl_stmt|;
block|}
name|osm_vendor_mgt_bind_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	smi_mads_hdl *		Handle returned by IB_MGT_get_handle to the IB_MGT_SMI * *	gsi_mads_hdl *		Handle returned by IB_MGT_get_handle to the IB_MGT_GSI * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: Vendor osm_mtl_bind_info_t * NAME *   osm_mtl_bind_info_t * * DESCRIPTION * 	Handle to the result of binding a class callbacks to IB_MGT. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_mtl_bind_info
block|{
name|IB_MGT_mad_hndl_t
name|mad_hndl
decl_stmt|;
name|osm_vendor_t
modifier|*
name|p_vend
decl_stmt|;
name|void
modifier|*
name|client_context
decl_stmt|;
name|VAPI_hca_hndl_t
name|hca_hndl
decl_stmt|;
name|VAPI_hca_id_t
name|hca_id
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|osm_vend_mad_recv_callback_t
name|rcv_callback
decl_stmt|;
name|osm_vend_mad_send_err_callback_t
name|send_err_callback
decl_stmt|;
name|osm_mad_pool_t
modifier|*
name|p_osm_pool
decl_stmt|;
block|}
name|osm_mtl_bind_info_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	mad_hndl *		the handle returned from the registration in IB_MGT * *	p_vend *		Pointer to the vendor object. * *	client_context *		User's context passed during osm_bind * *  hca_id *     HCA Id we bind to. * *	port_num *		Port number (within the HCA) of the bound port. * *	rcv_callback *		OSM Callback function to be called on receive of MAD. * *  send_err_callback *     OSM Callback to be called on send error. * *  p_osm_pool *     Points to the MAD pool used by OSM * * * SEE ALSO *********/
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_mtl_send_mad
parameter_list|(
name|IN
name|osm_mtl_bind_info_t
modifier|*
name|p_bind
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
specifier|const
name|p_madw
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
comment|// _OSM_BIND_H_
end_comment

end_unit

