begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005,2008 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_router_t.  *	This object represents an IBA router.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_ROUTER_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_ROUTER_H_
end_define

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
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_node.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mcast_tbl.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port_profile.h>
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
comment|/****h* OpenSM/Router * NAME *	Router * * DESCRIPTION *	The Router object encapsulates the information needed by the *	OpenSM to manage routers.  The OpenSM allocates one router object *	per router in the IBA subnet. * *	The Router object is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Hal Rosenstock, Voltaire * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Router/osm_router_t * NAME *	osm_router_t * * DESCRIPTION *	Router structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_router
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|osm_port_t
modifier|*
name|p_port
decl_stmt|;
block|}
name|osm_router_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	p_port *		Pointer to the Port object for this router. * * SEE ALSO *	Router object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Router/osm_router_delete * NAME *	osm_router_delete * * DESCRIPTION *	Destroys and deallocates the object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_router_delete
parameter_list|(
name|IN
name|OUT
name|osm_router_t
modifier|*
modifier|*
name|pp_rtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_rtr *		[in] Pointer to the object to destroy. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *	Router object, osm_router_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Router/osm_router_new * NAME *	osm_router_new * * DESCRIPTION *	The osm_router_new function initializes a Router object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_router_t
modifier|*
name|osm_router_new
parameter_list|(
name|IN
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to the node object of this router * * RETURN VALUES *	Pointer to the new initialized router object. * * NOTES * * SEE ALSO *	Router object, osm_router_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Router/osm_router_get_port_ptr * NAME *	osm_router_get_port_ptr * * DESCRIPTION *	Returns a pointer to the Port object for this router. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_port_t
modifier|*
name|osm_router_get_port_ptr
parameter_list|(
name|IN
specifier|const
name|osm_router_t
modifier|*
name|p_rtr
parameter_list|)
block|{
return|return
name|p_rtr
operator|->
name|p_port
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rtr *		[in] Pointer to an osm_router_t object. * * RETURN VALUES *	Returns a pointer to the Port object for this router. * * NOTES * * SEE ALSO *	Router object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Router/osm_router_get_node_ptr * NAME *	osm_router_get_node_ptr * * DESCRIPTION *	Returns a pointer to the Node object for this router. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_node_t
modifier|*
name|osm_router_get_node_ptr
parameter_list|(
name|IN
specifier|const
name|osm_router_t
modifier|*
name|p_rtr
parameter_list|)
block|{
return|return
name|p_rtr
operator|->
name|p_port
operator|->
name|p_node
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_rtr *		[in] Pointer to an osm_router_t object. * * RETURN VALUES *	Returns a pointer to the Node object for this router. * * NOTES * * SEE ALSO *	Router object *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_ROUTER_H_ */
end_comment

end_unit

