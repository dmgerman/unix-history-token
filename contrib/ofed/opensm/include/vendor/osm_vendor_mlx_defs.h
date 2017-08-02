begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005,2009 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_DEFS_H_
end_define

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx_inout.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx_txn.h>
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
comment|/* The maximum number of outstanding MADs an RMPP sender can transmit */
end_comment

begin_define
define|#
directive|define
name|OSMV_RMPP_RECV_WIN
value|16
end_define

begin_comment
comment|/* Transaction Timeout = OSMV_TXN_TIMEOUT_FACTOR * Response Timeout */
end_comment

begin_define
define|#
directive|define
name|OSMV_TXN_TIMEOUT_FACTOR
value|128
end_define

begin_comment
comment|/************/
end_comment

begin_comment
comment|/****s* OSM Vendor: Types/osmv_bind_obj_t * NAME *	osmv_bind_obj_t * * DESCRIPTION *	The object managing a single bind context. *       The bind handle is a direct pointer to it. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_bind_obj
block|{
comment|/* Used to signal when the struct is being destroyed */
name|struct
name|_osmv_bind_obj
modifier|*
name|magic_ptr
decl_stmt|;
name|osm_vendor_t
comment|/*const */
modifier|*
name|p_vendor
decl_stmt|;
name|uint32_t
name|hca_hndl
decl_stmt|;
name|uint32_t
name|port_num
decl_stmt|;
comment|/* Atomic access protector */
name|cl_spinlock_t
name|lock
decl_stmt|;
comment|/* is_closing == TRUE --> the handle is being unbound */
name|boolean_t
name|is_closing
decl_stmt|;
comment|/* Event callbacks */
name|osm_vend_mad_recv_callback_t
name|recv_cb
decl_stmt|;
name|osm_vend_mad_send_err_callback_t
name|send_err_cb
decl_stmt|;
comment|/* ... and their context */
name|void
modifier|*
name|cb_context
decl_stmt|;
comment|/* A pool to manage MAD wrappers */
name|osm_mad_pool_t
modifier|*
name|p_osm_pool
decl_stmt|;
comment|/* each subvendor implements its own transport mgr */
name|void
modifier|*
name|p_transp_mgr
decl_stmt|;
comment|/* The transaction DB */
name|osmv_txn_mgr_t
name|txn_mgr
decl_stmt|;
block|}
name|osmv_bind_obj_t
typedef|;
end_typedef

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSMV_DEFS_H_ */
end_comment

end_unit

