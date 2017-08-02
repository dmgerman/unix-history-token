begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mad_wrapper_t.  *	This object represents the context wrapper for OpenSM MAD processing.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_UMADT_h_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_UMADT_h_
end_define

begin_include
include|#
directive|include
file|"iba/ib_types.h"
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|"umadt.h"
end_include

begin_include
include|#
directive|include
file|"ibt.h"
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
name|_umadt_obj_t
block|{
name|void
modifier|*
name|umadt_handle
decl_stmt|;
name|UMADT_INTERFACE
name|uMadtInterface
decl_stmt|;
name|IBT_INTERFACE
name|IbtInterface
decl_stmt|;
name|boolean
name|init_done
decl_stmt|;
name|cl_spinlock_t
name|register_lock
decl_stmt|;
name|cl_qlist_t
name|register_list
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
block|}
name|umadt_obj_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: Umadt MAD Wrapper/osm_bind_info * NAME *	osm_bind_info * * DESCRIPTION *	Context needed for processing individual MADs * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_mad_bind_info_t
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|umadt_obj_t
modifier|*
name|p_umadt_obj
decl_stmt|;
name|osm_mad_pool_t
modifier|*
name|p_mad_pool
decl_stmt|;
name|osm_vend_mad_recv_callback_t
name|mad_recv_callback
decl_stmt|;
name|void
modifier|*
name|client_context
decl_stmt|;
name|cl_thread_t
name|recv_processor_thread
decl_stmt|;
name|cl_spinlock_t
name|trans_ctxt_lock
decl_stmt|;
name|cl_qlist_t
name|trans_ctxt_list
decl_stmt|;
name|cl_timer_t
name|timeout_timer
decl_stmt|;
name|cl_spinlock_t
name|timeout_list_lock
decl_stmt|;
name|cl_qlist_t
name|timeout_list
decl_stmt|;
name|RegisterClassStruct
name|umadt_reg_class
decl_stmt|;
name|MADT_HANDLE
name|umadt_handle
decl_stmt|;
comment|/* Umadt type */
block|}
name|mad_bind_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_trans_context_t
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|uint64_t
name|trans_id
decl_stmt|;
name|uint64_t
name|sent_time
decl_stmt|;
comment|/* micro secs */
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|trans_context_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	list_item *		List linkage for pools and lists.  MUST BE FIRST MEMBER! * *	p_mad_pool *		Pointer to the MAD pool to be used by mads with this bind handle. * *	mad_recv_callback *		Callback function called by the mad receive processor. * *	client_context *		context to be passed to the receive callback. * *	recv_processor_thread *		Thread structure for the receive processor thread. * *	umadt_reg_class *		Umadt register class struct used to register with Umadt. * *	umadt_handle *		Umadt returns this handle from a registration call. The transport layer *		uses this handle to talk to Umadt. * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_OSM_UMADT_h_ */
end_comment

end_unit

