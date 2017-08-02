begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_node_t.  *	This object represents an IBA node.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_NODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_NODE_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_path.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
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

begin_struct_decl
struct_decl|struct
name|osm_switch
struct_decl|;
end_struct_decl

begin_comment
comment|/****h* OpenSM/Node * NAME *	Node * * DESCRIPTION *	The Node object encapsulates the information needed by the *	OpenSM to manage nodes.  The OpenSM allocates one Node object *	per node in the IBA subnet. * *	The Node object is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Node/osm_node_t * NAME *	osm_node_t * * DESCRIPTION *	Node structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_node
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|struct
name|osm_switch
modifier|*
name|sw
decl_stmt|;
name|ib_node_info_t
name|node_info
decl_stmt|;
name|ib_node_desc_t
name|node_desc
decl_stmt|;
name|uint32_t
name|discovery_count
decl_stmt|;
name|uint32_t
name|physp_tbl_size
decl_stmt|;
name|char
modifier|*
name|print_desc
decl_stmt|;
name|uint8_t
modifier|*
name|physp_discovered
decl_stmt|;
name|osm_physp_t
name|physp_table
index|[
literal|1
index|]
decl_stmt|;
block|}
name|osm_node_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	sw *		For switch node contains pointer to appropriate osm_switch *		structure. NULL for non-switch nodes. Can be used for fast *		access to switch object and for simple node type detection * *	node_info *		The IBA defined NodeInfo data for this node. * *	node_desc *		The IBA defined NodeDescription data for this node. * *	discovery_count *		The number of times this node has been discovered *		during the current fabric sweep.  This number is reset *		to zero at the start of a sweep. * *	physp_tbl_size *		The size of the physp_table array.  This value is one greater *		than the number of ports in the node, since port numbers *		start with 1 for some bizarre reason. * *	print_desc *		A printable version of the node description. * *	physp_discovered *		Array of physp_discovered objects for all ports of this node. *		Each object indiactes whether the port has been discovered *		during the sweep or not. 1 means that the port had been discovered. * *	physp_table *		Array of physical port objects belonging to this node. *		Index is contiguous by local port number. *		For switches, port 0 is the always the management port (14.2.5.6). *		MUST BE LAST MEMBER! - Since it grows !!!! * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_delete * NAME *	osm_node_delete * * DESCRIPTION *	The osm_node_delete function destroys a node, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_node_delete
parameter_list|(
name|IN
name|OUT
name|osm_node_t
modifier|*
modifier|*
name|p_node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in][out] Pointer to a Pointer a Node object to destroy. *		On return, the pointer to set to NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified Node object. *	This function should only be called after a call to osm_node_new. * * SEE ALSO *	Node object, osm_node_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_new * NAME *	osm_node_new * * DESCRIPTION *	The osm_node_new function initializes a Node object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_node_t
modifier|*
name|osm_node_new
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to a osm_madw_t object containing a mad with *		the node's NodeInfo attribute.  The caller may discard the *		osm_madw_t structure after calling osm_node_new. * * RETURN VALUES *	On success, a pointer to the new initialized osm_node_t structure. *	NULL otherwise. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_physp_ptr * NAME *	osm_node_get_physp_ptr * * DESCRIPTION *	Returns a pointer to the physical port object at the *	specified local port number. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_physp_t
modifier|*
name|osm_node_get_physp_ptr
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint32_t
name|port_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|port_num
operator|<
name|p_node
operator|->
name|physp_tbl_size
argument_list|)
expr_stmt|;
return|return
name|osm_physp_is_valid
argument_list|(
operator|&
name|p_node
operator|->
name|physp_table
index|[
name|port_num
index|]
argument_list|)
condition|?
operator|&
name|p_node
operator|->
name|physp_table
index|[
name|port_num
index|]
else|:
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Local port number. * * RETURN VALUES *	Returns a pointer to the physical port object at the *	specified local port number. *	A return value of zero means the port number was out of range. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_type * NAME *	osm_node_get_type * * DESCRIPTION *	Returns the type of this node. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_node_get_type
parameter_list|(
name|IN
specifier|const
name|osm_node_t
modifier|*
name|p_node
parameter_list|)
block|{
return|return
name|p_node
operator|->
name|node_info
operator|.
name|node_type
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * * RETURN VALUES *	Returns the IBA defined type of this node. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_num_physp * NAME *	osm_node_get_num_physp * * DESCRIPTION *	Returns the number of osm_physp ports allocated for this node. *	For switches, it is the number of external physical ports plus *	port 0. For CAs and routers, it is the number of external physical *	ports plus 1. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_node_get_num_physp
parameter_list|(
name|IN
specifier|const
name|osm_node_t
modifier|*
name|p_node
parameter_list|)
block|{
return|return
operator|(
name|uint8_t
operator|)
name|p_node
operator|->
name|physp_tbl_size
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * * RETURN VALUES *	Returns the IBA defined type of this node. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_remote_node * NAME *	osm_node_get_remote_node * * DESCRIPTION *	Returns a pointer to the node on the other end of the *	specified port. *	Returns NULL if no remote node exists. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_node_t
modifier|*
name|osm_node_get_remote_node
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|OUT
name|uint8_t
modifier|*
name|p_remote_port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Port number in p_node through which to get the remote node. * *	p_remote_port_num *		[out] Port number in the remote's node through which this *		link exists.  The caller may specify NULL for this pointer *		if the port number isn't needed. * * RETURN VALUES *	Returns a pointer to the node on the other end of the *	specified port. *	Returns NULL if no remote node exists. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_base_lid * NAME *	osm_node_get_base_lid * * DESCRIPTION *	Returns the LID value of the specified port on this node. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|osm_node_get_base_lid
parameter_list|(
name|IN
specifier|const
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint32_t
name|port_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|port_num
operator|<
name|p_node
operator|->
name|physp_tbl_size
argument_list|)
expr_stmt|;
return|return
name|osm_physp_get_base_lid
argument_list|(
operator|&
name|p_node
operator|->
name|physp_table
index|[
name|port_num
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Local port number. * * RETURN VALUES *	Returns a pointer to the physical port object at the *	specified local port number. *	A return value of zero means the port number was out of range. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_remote_base_lid * NAME *	osm_node_get_remote_base_lid * * DESCRIPTION *	Returns the base LID value of the port on the other side *	of the wire from the specified port on this node. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_net16_t
name|osm_node_get_remote_base_lid
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint32_t
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Local port number. * * RETURN VALUES *	Returns a pointer to the physical port object at the *	specified local port number. *	A return value of zero means the port number was out of range. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_lmc * NAME *	osm_node_get_lmc * * DESCRIPTION *	Returns the LMC value of the specified port on this node. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_node_get_lmc
parameter_list|(
name|IN
specifier|const
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint32_t
name|port_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|port_num
operator|<
name|p_node
operator|->
name|physp_tbl_size
argument_list|)
expr_stmt|;
return|return
name|osm_physp_get_lmc
argument_list|(
operator|&
name|p_node
operator|->
name|physp_table
index|[
name|port_num
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Local port number. * * RETURN VALUES *	Returns the LMC value of the specified port on this node. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_init_physp * NAME *	osm_node_init_physp * * DESCRIPTION *	Initializes a physical port for the given node. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_node_init_physp
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|uint8_t
name|port_num
parameter_list|,
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	p_madw *		[in] Pointer to a osm_madw_t object containing a mad with *		the node's NodeInfo attribute as discovered through the *		Physical Port to add to the node.  The caller may discard the *		osm_madw_t structure after calling osm_node_new. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Node object, Physical Port object. *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_get_node_guid * NAME *	osm_node_get_node_guid * * DESCRIPTION *	Returns the node GUID of this node. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_node_get_node_guid
parameter_list|(
name|IN
specifier|const
name|osm_node_t
modifier|*
name|p_node
parameter_list|)
block|{
return|return
name|p_node
operator|->
name|node_info
operator|.
name|node_guid
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * * RETURN VALUES *	Returns the node GUID of this node. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_link * NAME *	osm_node_link * * DESCRIPTION *	Logically connects a node to another node through the specified port. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_node_link
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
name|osm_node_t
modifier|*
name|p_remote_node
parameter_list|,
name|IN
name|uint8_t
name|remote_port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Port number in p_node through which to create the link. * *	p_remote_node *		[in] Pointer to the remote port object. * *	remote_port_num *		[in] Port number in the remote's node through which to *		create this link. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_unlink * NAME *	osm_node_unlink * * DESCRIPTION *	Logically disconnects a node from another node through *	the specified port. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_node_unlink
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
name|osm_node_t
modifier|*
name|p_remote_node
parameter_list|,
name|IN
name|uint8_t
name|remote_port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Port number in p_node through which to unlink. * *	p_remote_node *		[in] Pointer to the remote port object. * *	remote_port_num *		[in] Port number in the remote's node through which to unlink. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_link_exists * NAME *	osm_node_link_exists * * DESCRIPTION *	Return TRUE if a link exists between the specified nodes on *	the specified ports. *	Returns FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_node_link_exists
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
name|osm_node_t
modifier|*
name|p_remote_node
parameter_list|,
name|IN
name|uint8_t
name|remote_port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Port number in p_node through which to check the link. * *	p_remote_node *		[in] Pointer to the remote port object. * *	remote_port_num *		[in] Port number in the remote's node through which to *		check this link. * * RETURN VALUES *	Return TRUE if a link exists between the specified nodes on *	the specified ports. *	Returns FALSE otherwise. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_has_any_link * NAME *	osm_node_has_any_link * * DESCRIPTION *	Return TRUE if a any link exists from the specified nodes on *	the specified port. *	Returns FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_node_has_any_link
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Port number in p_node through which to check the link. * * RETURN VALUES *	Return TRUE if a any link exists from the specified nodes on *	the specified port. *	Returns FALSE otherwise. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Node/osm_node_link_has_valid_ports * NAME *	osm_node_link_has_valid_ports * * DESCRIPTION *	Return TRUE if both ports in the link are valid (initialized). *	Returns FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_node_link_has_valid_ports
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
name|osm_node_t
modifier|*
name|p_remote_node
parameter_list|,
name|IN
name|uint8_t
name|remote_port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to an osm_node_t object. * *	port_num *		[in] Port number in p_node through which to check the link. * * RETURN VALUES *	Return TRUE if both ports in the link are valid (initialized). *	Returns FALSE otherwise. * * NOTES * * SEE ALSO *	Node object *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_NODE_H_ */
end_comment

end_unit

