begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2009 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_ucast_mgr_t.  *	This object represents the Unicast Manager object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_UCAST_MGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_UCAST_MGR_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_passivelock.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_switch.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_ucast_cache.h>
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
comment|/****h* OpenSM/Unicast Manager * NAME *	Unicast Manager * * DESCRIPTION *	The Unicast Manager object encapsulates the information *	needed to control unicast LID forwarding on the subnet. * *	The Unicast Manager object is thread safe. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_struct_decl
struct_decl|struct
name|osm_sm
struct_decl|;
end_struct_decl

begin_comment
comment|/****s* OpenSM: Unicast Manager/osm_ucast_mgr_t * NAME *	osm_ucast_mgr_t * * DESCRIPTION *	Unicast Manager structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_ucast_mgr
block|{
name|struct
name|osm_sm
modifier|*
name|sm
decl_stmt|;
name|osm_subn_t
modifier|*
name|p_subn
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|cl_plock_t
modifier|*
name|p_lock
decl_stmt|;
name|uint16_t
name|max_lid
decl_stmt|;
name|cl_qlist_t
name|port_order_list
decl_stmt|;
name|boolean_t
name|is_dor
decl_stmt|;
name|boolean_t
name|some_hop_count_set
decl_stmt|;
name|cl_qmap_t
name|cache_sw_tbl
decl_stmt|;
name|boolean_t
name|cache_valid
decl_stmt|;
block|}
name|osm_ucast_mgr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	sm *		Pointer to the SM object. * *	p_subn *		Pointer to the Subnet object for this subnet. * *	p_log *		Pointer to the log object. * *	p_lock *		Pointer to the serializing lock. * *	is_dor *		Dimension Order Routing (DOR) will be done * *	port_order_list *		List of ports ordered for routing. * *	some_hop_count_set *		Initialized to FALSE at the beginning of each the min hop *		tables calculation iteration cycle, set to TRUE to indicate *		that some hop count changes were done. * *	cache_sw_tbl *		Cached switches table. * *	cache_valid *		TRUE if the unicast cache is valid. * * SEE ALSO *	Unicast Manager object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Manager/osm_ucast_mgr_construct * NAME *	osm_ucast_mgr_construct * * DESCRIPTION *	This function constructs a Unicast Manager object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_mgr_construct
parameter_list|(
name|IN
name|osm_ucast_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to a Unicast Manager object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows osm_ucast_mgr_destroy * *	Calling osm_ucast_mgr_construct is a prerequisite to calling any other *	method except osm_ucast_mgr_init. * * SEE ALSO *	Unicast Manager object, osm_ucast_mgr_init, *	osm_ucast_mgr_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Manager/osm_ucast_mgr_destroy * NAME *	osm_ucast_mgr_destroy * * DESCRIPTION *	The osm_ucast_mgr_destroy function destroys the object, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_mgr_destroy
parameter_list|(
name|IN
name|osm_ucast_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified *	Unicast Manager object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to *	osm_ucast_mgr_construct or osm_ucast_mgr_init. * * SEE ALSO *	Unicast Manager object, osm_ucast_mgr_construct, *	osm_ucast_mgr_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Manager/osm_ucast_mgr_init * NAME *	osm_ucast_mgr_init * * DESCRIPTION *	The osm_ucast_mgr_init function initializes a *	Unicast Manager object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_ucast_mgr_init
parameter_list|(
name|IN
name|osm_ucast_mgr_t
modifier|*
name|p_mgr
parameter_list|,
name|IN
name|struct
name|osm_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_ucast_mgr_t object to initialize. * *	sm *		[in] Pointer to the SM object. * * RETURN VALUES *	IB_SUCCESS if the Unicast Manager object was initialized *	successfully. * * NOTES *	Allows calling other Unicast Manager methods. * * SEE ALSO *	Unicast Manager object, osm_ucast_mgr_construct, *	osm_ucast_mgr_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Manager/osm_ucast_mgr_set_fwd_tables * NAME *	osm_ucast_mgr_set_fwd_tables * * DESCRIPTION *	Setup forwarding table for the switch (from prepared new_lft). * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_mgr_set_fwd_tables
parameter_list|(
name|IN
name|osm_ucast_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_ucast_mgr_t object. * * SEE ALSO *	Unicast Manager *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Manager/osm_ucast_mgr_build_lid_matrices * NAME *	osm_ucast_mgr_build_lid_matrices * * DESCRIPTION *	Build switches's lid matrices. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_ucast_mgr_build_lid_matrices
parameter_list|(
name|IN
name|osm_ucast_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_ucast_mgr_t object. * * NOTES *	This function processes the subnet, configuring switches' *	min hops tables (aka lid matrices). * * SEE ALSO *	Unicast Manager *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Manager/osm_ucast_mgr_process * NAME *	osm_ucast_mgr_process * * DESCRIPTION *	Process and configure the subnet's unicast forwarding tables. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_ucast_mgr_process
parameter_list|(
name|IN
name|osm_ucast_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_ucast_mgr_t object. * * RETURN VALUES *	Returns zero on success and negative value on failure. * * NOTES *	This function processes the subnet, configuring switch *	unicast forwarding tables. * * SEE ALSO *	Unicast Manager, Node Info Response Controller *********/
end_comment

begin_function_decl
name|int
name|ucast_dummy_build_lid_matrices
parameter_list|(
name|void
modifier|*
name|context
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
comment|/* _OSM_UCAST_MGR_H_ */
end_comment

end_unit

