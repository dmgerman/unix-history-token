begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_sm_mad_ctrl_t.  *	This object represents a controller that receives the IBA NodeInfo  *	attribute from a node.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_SM_MAD_CTRL_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_SM_MAD_CTRL_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_passivelock.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_stats.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_vl15intf.h>
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
comment|/****h* OpenSM/SM MAD Controller * NAME *	SM MAD Controller * * DESCRIPTION *	The SM MAD Controller object encapsulates *	the information	needed to receive MADs from the transport layer. * *	The SM MAD Controller object is thread safe. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: SM MAD Controller/osm_sm_mad_ctrl_t * NAME *	osm_sm_mad_ctrl_t * * DESCRIPTION *	SM MAD Controller structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_sm_mad_ctrl
block|{
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|osm_subn_t
modifier|*
name|p_subn
decl_stmt|;
name|osm_mad_pool_t
modifier|*
name|p_mad_pool
decl_stmt|;
name|osm_vl15_t
modifier|*
name|p_vl15
decl_stmt|;
name|osm_vendor_t
modifier|*
name|p_vendor
decl_stmt|;
name|osm_bind_handle_t
name|h_bind
decl_stmt|;
name|cl_plock_t
modifier|*
name|p_lock
decl_stmt|;
name|cl_dispatcher_t
modifier|*
name|p_disp
decl_stmt|;
name|cl_disp_reg_handle_t
name|h_disp
decl_stmt|;
name|osm_stats_t
modifier|*
name|p_stats
decl_stmt|;
block|}
name|osm_sm_mad_ctrl_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_log *		Pointer to the log object. * *	p_subn *		Pointer to the subnet object. * *	p_mad_pool *		Pointer to the MAD pool. * *	p_vendor *		Pointer to the vendor specific interfaces object. * *	h_bind *		Bind handle returned by the transport layer. * *	p_lock *		Pointer to the serializing lock. * *	p_disp *		Pointer to the Dispatcher. * *	h_disp *		Handle returned from dispatcher registration. * *	p_stats *		Pointer to the OpenSM statistics block. * * SEE ALSO *	SM MAD Controller object *	SM MADr object *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM MAD Controller/osm_sm_mad_ctrl_construct * NAME *	osm_sm_mad_ctrl_construct * * DESCRIPTION *	This function constructs a SM MAD Controller object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_mad_ctrl_construct
parameter_list|(
name|IN
name|osm_sm_mad_ctrl_t
modifier|*
name|p_ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_ctrl *		[in] Pointer to a SM MAD Controller *		object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_sm_mad_ctrl_init, and osm_sm_mad_ctrl_destroy. * *	Calling osm_sm_mad_ctrl_construct is a prerequisite to calling any other *	method except osm_sm_mad_ctrl_init. * * SEE ALSO *	SM MAD Controller object, osm_sm_mad_ctrl_init, *	osm_sm_mad_ctrl_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM MAD Controller/osm_sm_mad_ctrl_destroy * NAME *	osm_sm_mad_ctrl_destroy * * DESCRIPTION *	The osm_sm_mad_ctrl_destroy function destroys the object, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_mad_ctrl_destroy
parameter_list|(
name|IN
name|osm_sm_mad_ctrl_t
modifier|*
name|p_ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_ctrl *		[in] Pointer to the object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified *	SM MAD Controller object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to *	osm_sm_mad_ctrl_construct or osm_sm_mad_ctrl_init. * * SEE ALSO *	SM MAD Controller object, osm_sm_mad_ctrl_construct, *	osm_sm_mad_ctrl_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM MAD Controller/osm_sm_mad_ctrl_init * NAME *	osm_sm_mad_ctrl_init * * DESCRIPTION *	The osm_sm_mad_ctrl_init function initializes a *	SM MAD Controller object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sm_mad_ctrl_init
parameter_list|(
name|IN
name|osm_sm_mad_ctrl_t
modifier|*
name|p_ctrl
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_mad_pool_t
modifier|*
name|p_mad_pool
parameter_list|,
name|IN
name|osm_vl15_t
modifier|*
name|p_vl15
parameter_list|,
name|IN
name|osm_vendor_t
modifier|*
name|p_vendor
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_stats_t
modifier|*
name|p_stats
parameter_list|,
name|IN
name|cl_plock_t
modifier|*
name|p_lock
parameter_list|,
name|IN
name|cl_dispatcher_t
modifier|*
name|p_disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_ctrl *		[in] Pointer to an osm_sm_mad_ctrl_t object to initialize. * *	p_mad_pool *		[in] Pointer to the MAD pool. * *	p_vl15 *		[in] Pointer to the VL15 interface object. * *	p_vendor *		[in] Pointer to the vendor specific interfaces object. * *	p_log *		[in] Pointer to the log object. * *	p_stats *		[in] Pointer to the OpenSM stastics block. * *	p_lock *		[in] Pointer to the OpenSM serializing lock. * *	p_disp *		[in] Pointer to the OpenSM central Dispatcher. * * RETURN VALUES *	IB_SUCCESS if the SM MAD Controller object was initialized *	successfully. * * NOTES *	Allows calling other SM MAD Controller methods. * * SEE ALSO *	SM MAD Controller object, osm_sm_mad_ctrl_construct, *	osm_sm_mad_ctrl_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_mad_ctrl_bind * NAME *	osm_sm_mad_ctrl_bind * * DESCRIPTION *	Binds the SM MAD Controller object to a port guid. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sm_mad_ctrl_bind
parameter_list|(
name|IN
name|osm_sm_mad_ctrl_t
modifier|*
name|p_ctrl
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_ctrl *		[in] Pointer to an osm_sm_mad_ctrl_t object to initialize. * *	port_guid *		[in] Local port GUID with which to bind. * * * RETURN VALUES *	None * * NOTES *	A given SM MAD Controller object can only be bound to one *	port at a time. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_mad_ctrl_get_bind_handle * NAME *	osm_sm_mad_ctrl_get_bind_handle * * DESCRIPTION *	Returns the bind handle. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_bind_handle_t
name|osm_sm_mad_ctrl_get_bind_handle
parameter_list|(
name|IN
specifier|const
name|osm_sm_mad_ctrl_t
modifier|*
name|p_ctrl
parameter_list|)
block|{
return|return
name|p_ctrl
operator|->
name|h_bind
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ctrl *		[in] Pointer to an osm_sm_mad_ctrl_t object. * * RETURN VALUES *	Returns the bind handle, which may be OSM_BIND_INVALID_HANDLE *	if no port has been bound. * * NOTES *	A given SM MAD Controller object can only be bound to one *	port at a time. * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_SM_MAD_CTRL_H_ */
end_comment

end_unit

