begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mtree_t.  *	This object represents multicast spanning tree.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MTREE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MTREE_H_
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
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_switch.h>
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

begin_define
define|#
directive|define
name|OSM_MTREE_LEAF
value|((void*)-1)
end_define

begin_comment
comment|/****h* OpenSM/Multicast Tree * NAME *	Multicast Tree * * DESCRIPTION *	The Multicast Tree object encapsulates the information needed by the *	OpenSM to manage multicast fabric routes.  It is a tree structure *	in which each node in the tree represents a switch, and may have a *	varying number of children. * *	Multicast trees do not contain loops. * *	The Multicast Tree is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Multicast Tree/osm_mtree_node_t * NAME *	osm_mtree_node_t * * DESCRIPTION *	The MTree Node object encapsulates the information needed by the *	OpenSM for a particular switch in the multicast tree. * *	The MTree Node object is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mtree_node
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
decl_stmt|;
name|uint8_t
name|max_children
decl_stmt|;
name|struct
name|osm_mtree_node
modifier|*
name|p_up
decl_stmt|;
name|struct
name|osm_mtree_node
modifier|*
name|child_array
index|[
literal|1
index|]
decl_stmt|;
block|}
name|osm_mtree_node_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage for quick map.  MUST BE FIRST ELEMENT!!! * *	p_sw *		Pointer to the switch represented by this tree node. * *	max_children *		Maximum number of child nodes of this node.  Equal to the *		the number of ports on the switch if the switch supports *		multicast.  Equal to 1 (default route) if the switch does *		not support multicast. * *	p_up *		Pointer to the parent of this node.  If this pointer is *		NULL, the node is at the root of the tree. * *	child_array *		Array (indexed by port number) of pointers to the *		child osm_mtree_node_t objects of this tree node, if any. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Tree/osm_mtree_node_new * NAME *	osm_mtree_node_new * * DESCRIPTION *	Returns an initialized a Multicast Tree object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mtree_node_t
modifier|*
name|osm_mtree_node_new
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch represented by this node. * * RETURN VALUES *	Pointer to an initialized tree node. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Tree/osm_mtree_destroy * NAME *	osm_mtree_destroy * * DESCRIPTION *	Destroys a Multicast Tree object given by the p_mtn * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mtree_destroy
parameter_list|(
name|IN
name|osm_mtree_node_t
modifier|*
name|p_mtn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mtn *		[in] Pointer to an osm_mtree_node_t object to destroy. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Tree/osm_mtree_node_get_max_children * NAME *	osm_mtree_node_get_max_children * * DESCRIPTION *	Returns the number maximum number of children of this node. *	The return value is 1 greater than the highest valid port *	number on the switch. * * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_mtree_node_get_max_children
parameter_list|(
name|IN
specifier|const
name|osm_mtree_node_t
modifier|*
name|p_mtn
parameter_list|)
block|{
return|return
operator|(
name|p_mtn
operator|->
name|max_children
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mtn *		[in] Pointer to the multicast tree node. * * RETURN VALUES *	See description. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Tree/osm_mtree_node_get_child * NAME *	osm_mtree_node_get_child * * DESCRIPTION *	Returns the specified child node of this node. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_mtree_node_t
modifier|*
name|osm_mtree_node_get_child
parameter_list|(
name|IN
specifier|const
name|osm_mtree_node_t
modifier|*
name|p_mtn
parameter_list|,
name|IN
name|uint8_t
name|child
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|child
operator|<
name|p_mtn
operator|->
name|max_children
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_mtn
operator|->
name|child_array
index|[
name|child
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mtn *		[in] Pointer to the multicast tree node. * *	child *		[in] Index of the child to retrieve. * * RETURN VALUES *	Returns the specified child node of this node. * * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Tree/osm_mtree_node_get_switch_ptr * NAME *	osm_mtree_node_get_switch_ptr * * DESCRIPTION *	Returns a pointer to the switch object represented by this tree node. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|osm_switch_t
modifier|*
name|osm_mtree_node_get_switch_ptr
parameter_list|(
name|IN
specifier|const
name|osm_mtree_node_t
modifier|*
name|p_mtn
parameter_list|)
block|{
return|return
name|p_mtn
operator|->
name|p_sw
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_mtn *		[in] Pointer to the multicast tree node. * *	child *		[in] Index of the child to retrieve. * * RETURN VALUES *	Returns a pointer to the switch object represented by this tree node. * * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MTREE_H_ */
end_comment

end_unit

