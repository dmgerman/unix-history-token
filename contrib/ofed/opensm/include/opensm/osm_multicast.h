begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2013 Oracle and/or its affiliates. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
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
file|<complib/cl_fleximap.h>
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

begin_include
include|#
directive|include
file|<opensm/osm_sm.h>
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
comment|/****s* OpenSM: Multicast Group/osm_mgrp_t * NAME *	osm_mgrp_t * * DESCRIPTION *	Multicast Group structure. * *	The osm_mgrp_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mgrp
block|{
name|cl_fmap_item_t
name|map_item
decl_stmt|;
name|cl_list_item_t
name|list_item
decl_stmt|;
name|ib_net16_t
name|mlid
decl_stmt|;
name|cl_qmap_t
name|mcm_port_tbl
decl_stmt|;
name|cl_qmap_t
name|mcm_alias_port_tbl
decl_stmt|;
name|ib_member_rec_t
name|mcmember_rec
decl_stmt|;
name|boolean_t
name|well_known
decl_stmt|;
name|unsigned
name|full_members
decl_stmt|;
block|}
name|osm_mgrp_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Map Item for fmap linkage.  Must be first element!! * *	list_item *		List item for linkage in osm_mgrp_box's mgrp_list qlist. * *	mlid *		The network ordered LID of this Multicast Group (must be *>= 0xC000). * *	mcm_port_tbl *		Table (sorted by port GUID) of osm_mcm_port_t objects *		representing the member ports of this multicast group. * *	mcm_alias_port_tbl *		Table (sorted by port alias GUID) of osm_mcm_port_t *		objects representing the member ports of this multicast *		group. * *	mcmember_rec *		Holds the parameters of the Multicast Group. * *	well_known *		Indicates that this is the wellknown multicast group which *		is created during the initialization of SM/SA and will be *		present even if there are no ports for this group * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: Multicast Group/osm_mgrp_box_t * NAME *	osm_mgrp_box_t * * DESCRIPTION *	Multicast structure which holds all multicast groups with same MLID. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mgrp_box
block|{
name|uint16_t
name|mlid
decl_stmt|;
name|cl_qlist_t
name|mgrp_list
decl_stmt|;
name|osm_mtree_node_t
modifier|*
name|root
decl_stmt|;
block|}
name|osm_mgrp_box_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	mlid *		The host ordered LID of this Multicast Group (must be *>= 0xC000). * *	p_root *		Pointer to the root "tree node" in the single spanning tree *		for this multicast group.  The nodes of the tree represent *		switches.  Member ports are not represented in the tree. * *	mgrp_list *		List of multicast groups (mpgr object) having same MLID value. * * SEE ALSO *********/
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
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|IN
name|ib_net16_t
name|mlid
parameter_list|,
name|IN
name|ib_member_rec_t
modifier|*
name|mcmr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	subn *		[in] Pointer to osm_subn_t object. * *	mlid *		[in] Multicast LID for this multicast group. * *	mcmr *		[in] MCMember Record for this multicast group. * * RETURN VALUES *	IB_SUCCESS if initialization was successful. * * NOTES *	Allows calling other Multicast Group methods. * * SEE ALSO *	Multicast Group, osm_mgrp_delete *********/
end_comment

begin_comment
comment|/*  * Need a forward declaration to work around include loop:  * osm_sm.h<- osm_multicast.h  */
end_comment

begin_struct_decl
struct_decl|struct
name|osm_sm
struct_decl|;
end_struct_decl

begin_comment
comment|/****f* OpenSM: Multicast Tree/osm_purge_mtree * NAME *	osm_purge_mtree * * DESCRIPTION *	Frees all the nodes in a multicast spanning tree * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_purge_mtree
parameter_list|(
name|IN
name|struct
name|osm_sm
modifier|*
name|sm
parameter_list|,
name|IN
name|osm_mgrp_box_t
modifier|*
name|mgb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to osm_sm_t object. *	mgb *		[in] Pointer to an osm_mgrp_box_t object. * * RETURN VALUES *	None. * * * NOTES * * SEE ALSO *********/
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
name|p_mgrp
parameter_list|,
name|IN
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
name|p_mgrp
parameter_list|)
block|{
return|return
name|p_mgrp
operator|->
name|mlid
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
name|mgrp
parameter_list|,
name|IN
name|osm_port_t
modifier|*
name|port
parameter_list|,
name|IN
name|ib_member_rec_t
modifier|*
name|mcmr
parameter_list|,
name|IN
name|boolean_t
name|proxy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	mgrp *		[in] Pointer to an osm_mgrp_t object to initialize. * *	port *		[in] Pointer to an osm_port_t object * *	mcmr *		[in] Pointer to MCMember record received for the join * *	proxy *		[in] The proxy join state for this port in the group. * * RETURN VALUES *	IB_SUCCESS *	IB_INSUFFICIENT_MEMORY * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_get_mcm_port * NAME *	osm_mgrp_get_mcm_port * * DESCRIPTION *	Finds a port in the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mcm_port_t
modifier|*
name|osm_mgrp_get_mcm_port
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
name|p_mgrp
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * *	port_guid *		[in] Port guid. * * RETURN VALUES *	Pointer to the mcm port object when present or NULL otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_get_mcm_alias_guid * NAME *	osm_mgrp_get_mcm_alias_guid * * DESCRIPTION *	Finds an mcm alias GUID in the multicast group based on an alias GUID. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mcm_alias_guid_t
modifier|*
name|osm_mgrp_get_mcm_alias_guid
parameter_list|(
name|IN
specifier|const
name|osm_mgrp_t
modifier|*
name|p_mgrp
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgrp *		[in] Pointer to an osm_mgrp_t object. * *	port_guid *		[in] Alias port guid. * * RETURN VALUES *	Pointer to the mcm alias GUID object when present or NULL otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Group/osm_mgrp_delete_port * NAME *	osm_mgrp_delete_port * * DESCRIPTION *	Removes a port from the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mgrp_delete_port
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|log
parameter_list|,
name|IN
name|osm_mgrp_t
modifier|*
name|mgrp
parameter_list|,
name|IN
name|osm_port_t
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	subn *		[in] Pointer to the subnet object * *	log *		[in] The log object pointer * *	mgrp *		[in] Pointer to an osm_mgrp_t object. * *	port *		[in] Pointer to an osm_port_t object for the the departing port. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_function_decl
name|boolean_t
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
name|osm_mcm_alias_guid_t
modifier|*
name|mcm_alias_guid
parameter_list|,
name|ib_member_rec_t
modifier|*
name|mcmr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_mgrp_cleanup
parameter_list|(
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|osm_mgrp_t
modifier|*
name|mpgr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_mgrp_box_delete
parameter_list|(
name|osm_mgrp_box_t
modifier|*
name|mbox
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
comment|/* _OSM_MULTICAST_H_ */
end_comment

end_unit

