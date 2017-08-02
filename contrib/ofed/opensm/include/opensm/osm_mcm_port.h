begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mcm_port_t.  *	This object represents the membership of a port in a multicast group.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MCM_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MCM_PORT_H_
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
file|<opensm/osm_port.h>
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
name|osm_mgrp
struct_decl|;
end_struct_decl

begin_comment
comment|/****s* OpenSM: MCM Port Object/osm_mcm_port_t * NAME * 	osm_mcm_port_t * * DESCRIPTION * 	This object represents a particular port as a member of a *	multicast group. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mcm_port
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|cl_list_item_t
name|list_item
decl_stmt|;
name|osm_port_t
modifier|*
name|port
decl_stmt|;
name|struct
name|osm_mgrp
modifier|*
name|mgrp
decl_stmt|;
block|}
name|osm_mcm_port_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Map Item for qmap linkage.  Must be first element!! * *	list_item *		Linkage structure for cl_qlist. * *	port *		Reference to the parent port * *	mgrp *		The pointer to multicast group where this port is member of * * SEE ALSO *	MCM Port Object *********/
end_comment

begin_comment
comment|/****f* OpenSM: MCM Port Object/osm_mcm_port_new * NAME *	osm_mcm_port_new * * DESCRIPTION *	The osm_mcm_port_new function allocates and initializes a *	MCM Port Object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mcm_port_t
modifier|*
name|osm_mcm_port_new
parameter_list|(
name|IN
name|osm_port_t
modifier|*
name|port
parameter_list|,
name|IN
name|struct
name|osm_mgrp
modifier|*
name|mgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	port *		[in] Pointer to the port object * *	mgrp *		[in] Pointer to multicast group where this port is joined * * RETURN VALUES *	Pointer to the allocated and initialized MCM Port object. * * NOTES * * SEE ALSO *	MCM Port Object, osm_mcm_port_delete, *********/
end_comment

begin_comment
comment|/****f* OpenSM: MCM Port Object/osm_mcm_port_delete * NAME *	osm_mcm_port_delete * * DESCRIPTION *	The osm_mcm_port_delete function destroys and dellallocates an *	MCM Port Object, releasing all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcm_port_delete
parameter_list|(
name|IN
name|osm_mcm_port_t
modifier|*
name|p_mcm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mcm *		[in] Pointer to a MCM Port Object to delete. * * RETURN VALUE *	This function does not return a value. * * NOTES * * SEE ALSO *	MCM Port Object, osm_mcm_port_new *********/
end_comment

begin_comment
comment|/****s* OpenSM: MCM Port Object/osm_mcm_alias_guid_t * NAME *	osm_mcm_alias_guid_t * * DESCRIPTION *	This object represents an alias guid for a mcm port. * *	The osm_mcm_alias_guid_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mcm_alias_guid
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|ib_net64_t
name|alias_guid
decl_stmt|;
name|osm_mcm_port_t
modifier|*
name|p_base_mcm_port
decl_stmt|;
name|ib_gid_t
name|port_gid
decl_stmt|;
name|uint8_t
name|scope_state
decl_stmt|;
name|boolean_t
name|proxy_join
decl_stmt|;
block|}
name|osm_mcm_alias_guid_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	alias_guid *		Alias GUID for port obtained from SM GUIDInfo attribute * *	p_base_mcm_port *		Pointer to osm_mcm_port_t for base port GUID * *	port_gid *		GID of the member port * *	scope_state * *	proxy_join *		If FALSE - Join was performed by the endport identified *		by PortGID. If TRUE - Join was performed on behalf of *		the endport identified by PortGID by another port within *		the same partition. * * SEE ALSO *	MCM Port, Physical Port, Physical Port Table */
end_comment

begin_comment
comment|/****f* OpenSM: MCM Port Object/osm_mcm_alias_guid_new * NAME *	osm_mcm_alias_guid_new * * DESCRIPTION *	This function allocates and initializes an mcm alias guid object. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mcm_alias_guid_t
modifier|*
name|osm_mcm_alias_guid_new
parameter_list|(
name|IN
name|osm_mcm_port_t
modifier|*
name|p_base_mcm_port
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
comment|/* * PARAMETERS *	p_base_mcm_port *		[in] Pointer to the mcm port for this base GUID * *	mcmr *		[in] Pointer to MCMember record of the join request * *	proxy *		[in] proxy_join state analyzed from the request * * RETURN VALUE *	Pointer to the initialized mcm alias guid object. * * NOTES *	Allows calling other mcm alias guid methods. * * SEE ALSO *       MCM Port Object *********/
end_comment

begin_comment
comment|/****f* OpenSM: MCM Port Object/osm_mcm_alias_guid_delete * NAME *	osm_mcm_alias_guid_delete * * DESCRIPTION *	This function destroys and deallocates an mcm alias guid object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcm_alias_guid_delete
parameter_list|(
name|IN
name|OUT
name|osm_mcm_alias_guid_t
modifier|*
modifier|*
name|pp_mcm_alias_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	pp_mcm_alias_guid *		[in][out] Pointer to a pointer to an mcm alias guid object to *		delete. On return, this pointer is NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified mcm alias guid object. * * SEE ALSO *	MCM Port Object *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MCM_PORT_H_ */
end_comment

end_unit

