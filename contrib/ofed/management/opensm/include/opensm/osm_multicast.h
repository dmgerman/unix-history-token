begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mgrp_t.  *	This object represents an IBA Multicast Group.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MULTICAST_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MULTICAST_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mtree.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mcm_port.h>
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
comment|/****h* OpenSM/Multicast Group * NAME *	Multicast Group * * DESCRIPTION *	The Multicast Group encapsulates the information needed by the *	OpenSM to manage Multicast Groups.  The OpenSM allocates one *	Multicast Group object per Multicast Group in the IBA subnet. * *	The Multicast Group is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Multicast Group/osm_mcast_mgr_ctxt_t * NAME *	osm_mcast_mgr_ctxt_t * * DESCRIPTION *	Struct for passing context arguments to the multicast manager. * *	The osm_mcast_mgr_ctxt_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mcast_mgr_ctxt
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|ib_net16_t
name|mlid
decl_stmt|;
name|osm_mcast_req_type_t
name|req_type
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
block|}
name|osm_mcast_mgr_ctxt_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	mlid *		The network ordered LID of this Multicast Group *		(must be>= 0xC000). * *	req_type *		The type of the request that caused this call *		(multicast create/join/leave). * *	port_guid *		The port guid of the port that is being added/removed from *		the multicast group due to this call. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: Multicast Group/osm_mgrp_t * NAME *	osm_mgrp_t * * DESCRIPTION *	Multicast Group structure. * *	The osm_mgrp_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mgrp
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|ib_net16_t
name|mlid
decl_stmt|;
name|osm_mtree_node_t
modifier|*
name|p_root
decl_stmt|;
name|cl_qmap_t
name|mcm_port_tbl
decl_stmt|;
name|ib_member_rec_t
name|mcmember_rec
decl_stmt|;
name|boolean_t
name|well_known
decl_stmt|;
name|boolean_t
name|to_be_deleted
decl_stmt|;
name|uint32_t
name|last_change_id
decl_stmt|;
name|uint32_t
name|last_tree_id
decl_stmt|;
name|unsigned
name|full_members
decl_stmt|;
block|}
name|osm_mgrp_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Map Item for qmap linkage.  Must be first element!! * *	mlid *		The network ordered LID of this Multicast Group (must be *>= 0xC000). * *	p_root *		Pointer to the root "tree node" in the single spanning tree *		for this multicast group.  The nodes of the tree represent *		switches.  Member ports are not represented in the tree. * *	mcm_port_tbl *		Table (sorted by port GUID) of osm_mcm_port_t objects *		representing the member ports of this multicast group. * *	mcmember_rec *		Holds the parameters of the Multicast Group. * *	well_known *		Indicates that this is the wellknown multicast group which *		is created during the initialization of SM/SA and will be *		present even if there are no ports for this group * *	to_be_deleted *		Since groups are deleted only after re-route we need to *		track the fact the group is about to be deleted so we can *		track the fact a new join is actually a create request. * *	last_change_id *		a counter for the number of changes applied to the group. *		This counter shuold be incremented on any modification *		to the group: joining or leaving of ports. * *	last_tree_id *		the last change id used for building the current tree. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Vendor API/osm_mgrp_func_t * NAME *	osm_mgrp_func_t * * DESCRIPTION *	Callback for the osm_mgrp_apply_func function. *	The callback function must not modify the tree linkage. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|osm_mgrp_func_t
function_decl|)
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|,
name|IN
specifier|const
name|osm_mtree_node_t
modifier|*
specifier|const
name|p_mtn
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to the multicast group object. * *	p_mtn *		[in] Pointer to the multicast tree node. * *	context *		[in] User context. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_new * NAME *	osm_mgrp_new * * DESCRIPTION *	Allocates and initializes a Multicast Group for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mgrp_t
modifier|*
name|osm_mgrp_new
parameter_list|(
name|IN
specifier|const
name|ib_net16_t
name|mlid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	mlid *		[in] Multicast LID for this multicast group. * * RETURN VALUES *	IB_SUCCESS if initialization was successful. * * NOTES *	Allows calling other Multicast Group methods. * * SEE ALSO *	Multicast Group, osm_mgrp_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_delete * NAME *	osm_mgrp_delete * * DESCRIPTION *	Destroys and deallocates a Multicast Group. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mgrp_delete
parameter_list|(
name|IN
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Multicast Group, osm_mgrp_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_is_guid * NAME *	osm_mgrp_is_guid * * DESCRIPTION *	Indicates if the specified port GUID is a member of the Multicast Group. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_mgrp_is_guid
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|port_guid
parameter_list|)
block|{
return|return
operator|(
name|cl_qmap_get
argument_list|(
operator|&
name|p_mgrp
operator|->
name|mcm_port_tbl
argument_list|,
name|port_guid
argument_list|)
operator|!=
name|cl_qmap_end
argument_list|(
operator|&
name|p_mgrp
operator|->
name|mcm_port_tbl
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * *	port_guid *		[in] Port GUID. * * RETURN VALUES *	TRUE if the port GUID is a member of the group, *	FALSE otherwise. * * NOTES * * SEE ALSO *	Multicast Group *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_is_empty * NAME *	osm_mgrp_is_empty * * DESCRIPTION *	Indicates if the multicast group has any member ports. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_mgrp_is_empty
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|)
block|{
return|return
operator|(
name|cl_qmap_count
argument_list|(
operator|&
name|p_mgrp
operator|->
name|mcm_port_tbl
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * * RETURN VALUES *	TRUE if there are no ports in the multicast group. *	FALSE otherwise. * * NOTES * * SEE ALSO *	Multicast Group *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_get_mlid * NAME *	osm_mgrp_get_mlid * * DESCRIPTION *	The osm_mgrp_get_mlid function returns the multicast LID of this group. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|osm_mgrp_get_mlid
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|)
block|{
return|return
operator|(
name|p_mgrp
operator|->
name|mlid
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * * RETURN VALUES *	MLID of the Multicast Group. * * NOTES * * SEE ALSO *	Multicast Group *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_add_port * NAME *	osm_mgrp_add_port * * DESCRIPTION *	Adds a port to the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mcm_port_t
modifier|*
name|osm_mgrp_add_port
parameter_list|(
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|osm_log_t
modifier|*
name|log
parameter_list|,
name|IN
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|,
name|IN
specifier|const
name|ib_gid_t
modifier|*
specifier|const
name|p_port_gid
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|join_state
parameter_list|,
name|IN
name|boolean_t
name|proxy_join
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object to initialize. * *	p_port_gid *		[in] Pointer to the GID of the port to add to the multicast group. * *	join_state *		[in] The join state for this port in the group. * * RETURN VALUES *	IB_SUCCESS *	IB_INSUFFICIENT_MEMORY * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_is_port_present * NAME *	osm_mgrp_is_port_present * * DESCRIPTION *	checks a port from the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_mgrp_is_port_present
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|port_guid
parameter_list|,
name|OUT
name|osm_mcm_port_t
modifier|*
modifier|*
specifier|const
name|pp_mcm_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * *	port_guid *		[in] Port guid of the departing port. * *  pp_mcm_port *     [out] Pointer to a pointer to osm_mcm_port_t *           Updated to the member on success or NULLed * * RETURN VALUES *	TRUE if port present *	FALSE if port is not present. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_remove_port * NAME *	osm_mgrp_remove_port * * DESCRIPTION *	Removes a port from the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mgrp_delete_port
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
specifier|const
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *  p_subn *     [in] Pointer to the subnet object * *  p_log *     [in] The log object pointer * *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * *	port_guid *		[in] Port guid of the departing port. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_function_decl
name|int
name|osm_mgrp_remove_port
parameter_list|(
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|osm_log_t
modifier|*
name|log
parameter_list|,
name|osm_mgrp_t
modifier|*
name|mgrp
parameter_list|,
name|osm_mcm_port_t
modifier|*
name|mcm
parameter_list|,
name|uint8_t
name|join_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_apply_func * NAME *	osm_mgrp_apply_func * * DESCRIPTION *	Calls the specified function for each element in the tree. *	Elements are passed to the callback function in no particular order. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mgrp_apply_func
parameter_list|(
specifier|const
name|osm_mgrp_t
modifier|*
specifier|const
name|p_mgrp
parameter_list|,
name|osm_mgrp_func_t
name|p_func
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * *	p_func *		[in] Pointer to the users callback function. * *	context *		[in] User context passed to the callback function. * * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Multicast Group *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MULTICAST_H_ */
end_comment

end_unit

