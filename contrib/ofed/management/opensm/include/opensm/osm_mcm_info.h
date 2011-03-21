begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2007 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mcm_info_t.  *	This object represents a Multicast Forwarding Information object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MCM_INFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MCM_INFO_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
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
comment|/****s* OpenSM: Multicast Member Info/osm_mcm_info_t * NAME *	osm_mcm_info_t * * DESCRIPTION *	Multicast Membership Info object. *	This object contains information about a node's membership *	in a particular multicast group. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mcm_info
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|ib_net16_t
name|mlid
decl_stmt|;
block|}
name|osm_mcm_info_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	list_item *		Linkage structure for cl_qlist.  MUST BE FIRST MEMBER! * *	mlid *		MLID of this multicast group. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Member Info/osm_mcm_info_new * NAME *	osm_mcm_info_new * * DESCRIPTION *	Returns an initialized a Multicast Member Info object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mcm_info_t
modifier|*
name|osm_mcm_info_new
parameter_list|(
name|IN
specifier|const
name|ib_net16_t
name|mlid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	mlid *		[in] MLID value for this multicast group. * * RETURN VALUES *	Pointer to an initialized tree node. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Multicast Member Info/osm_mcm_info_delete * NAME *	osm_mcm_info_delete * * DESCRIPTION *	Destroys and deallocates the specified object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcm_info_delete
parameter_list|(
name|IN
name|osm_mcm_info_t
modifier|*
specifier|const
name|p_mcm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mcm *		Pointer to the object to destroy. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MCM_INFO_H_ */
end_comment

end_unit

