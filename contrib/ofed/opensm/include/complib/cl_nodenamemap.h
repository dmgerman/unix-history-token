begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2007 Lawrence Livermore National Lab  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_NODE_NAME_MAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_NODE_NAME_MAP_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_comment
comment|/* NOTE: this may modify the parameter "nodedesc". */
end_comment

begin_function_decl
name|char
modifier|*
name|clean_nodedesc
parameter_list|(
name|char
modifier|*
name|nodedesc
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|_name_map_item
block|{
name|cl_map_item_t
name|item
decl_stmt|;
name|uint64_t
name|guid
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|name_map_item_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cl_qmap_t
name|nn_map_t
typedef|;
end_typedef

begin_comment
comment|/**  * Node name map interface.  * It is OK to pass NULL for the node_name_map[_fp] parameters.  */
end_comment

begin_function_decl
name|nn_map_t
modifier|*
name|open_node_name_map
parameter_list|(
specifier|const
name|char
modifier|*
name|node_name_map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_node_name_map
parameter_list|(
name|nn_map_t
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|remap_node_name
parameter_list|(
name|nn_map_t
modifier|*
name|map
parameter_list|,
name|uint64_t
name|target_guid
parameter_list|,
name|char
modifier|*
name|nodedesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOTE: parameter "nodedesc" may be modified here. */
end_comment

begin_function_decl
name|int
name|parse_node_map
parameter_list|(
specifier|const
name|char
modifier|*
name|file_name
parameter_list|,
name|int
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cxt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_NODE_NAME_MAP_H_ */
end_comment

end_unit

