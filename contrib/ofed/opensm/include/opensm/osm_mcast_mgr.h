begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2009 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009-2011 ZIH, TU Dresden, Federal Republic of Germany. All rights reserved.  * Copyright (C) 2012-2013 Tokyo Institute of Technology. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mcast_work_obj_t.  * 	Provide access to a mcast function which searches the root swicth for  * 	a spanning tree.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MCAST_MGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MCAST_MGR_H_
end_define

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

begin_typedef
typedef|typedef
struct|struct
name|osm_mcast_work_obj
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|osm_port_t
modifier|*
name|p_port
decl_stmt|;
name|cl_map_item_t
name|map_item
decl_stmt|;
block|}
name|osm_mcast_work_obj_t
typedef|;
end_typedef

begin_function_decl
name|int
name|osm_mcast_make_port_list_and_map
parameter_list|(
name|cl_qlist_t
modifier|*
name|list
parameter_list|,
name|cl_qmap_t
modifier|*
name|map
parameter_list|,
name|osm_mgrp_box_t
modifier|*
name|mbox
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_mcast_drop_port_list
parameter_list|(
name|cl_qlist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_switch_t
modifier|*
name|osm_mcast_mgr_find_root_switch
parameter_list|(
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|cl_qlist_t
modifier|*
name|list
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
comment|/* _OSM_MCAST_MGR_H_ */
end_comment

end_unit

