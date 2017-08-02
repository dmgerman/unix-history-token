begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_ATTRIB_REQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_ATTRIB_REQ_H_
end_define

begin_include
include|#
directive|include
file|<opensm/osm_path.h>
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
comment|/*  * Abstract:  * 	Declaration of the attribute request object.  This object  *  encapsulates information needed by the generic request controller  *  to request an attribute from a node.  *	These objects are part of the OpenSM family of objects.  */
end_comment

begin_comment
comment|/****h* OpenSM/Attribute Request * NAME *	Attribute Request * * DESCRIPTION *	The Attribute Request structure encapsulates *   encapsulates information needed by the generic request controller *   to request an attribute from a node. * *	This structure allows direct access to member variables. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Attribute Request/osm_attrib_req_t * NAME *	osm_attrib_req_t * * DESCRIPTION *	Attribute request structure. * *	This structure allows direct access to member variables. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_attrib_req
block|{
name|uint16_t
name|attrib_id
decl_stmt|;
name|uint32_t
name|attrib_mod
decl_stmt|;
name|osm_madw_context_t
name|context
decl_stmt|;
name|osm_dr_path_t
name|path
decl_stmt|;
name|cl_disp_msgid_t
name|err_msg
decl_stmt|;
block|}
name|osm_attrib_req_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	attrib_id *		Attribute ID for this request. * *	attrib_mod *		Attribute modifier for this request. * *	context *		Context to insert in outbound mad wrapper context. * *	path *		The directed route path to the node. * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_ATTRIB_REQ_H_ */
end_comment

end_unit

