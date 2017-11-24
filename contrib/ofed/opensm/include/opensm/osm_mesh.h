begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2008,2009 System Fabric Works, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *      Declarations for mesh analysis  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSM_MESH_H
end_ifndef

begin_define
define|#
directive|define
name|OSM_MESH_H
end_define

begin_struct_decl
struct_decl|struct
name|_lash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_switch
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * per switch to switch link info  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_link
block|{
name|int
name|switch_id
decl_stmt|;
name|int
name|link_id
decl_stmt|;
name|int
name|next_port
decl_stmt|;
name|int
name|num_ports
decl_stmt|;
name|int
name|ports
index|[
literal|0
index|]
decl_stmt|;
block|}
name|link_t
typedef|;
end_typedef

begin_comment
comment|/*  * per switch node mesh info  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_mesh_node
block|{
name|int
modifier|*
name|axes
decl_stmt|;
comment|/* used to hold and reorder assigned axes */
name|int
modifier|*
name|coord
decl_stmt|;
comment|/* mesh coordinates of switch */
name|int
modifier|*
modifier|*
name|matrix
decl_stmt|;
comment|/* distances between adjacant switches */
name|int
modifier|*
name|poly
decl_stmt|;
comment|/* characteristic polynomial of matrix */
comment|/* used as an invariant classification */
name|int
name|dimension
decl_stmt|;
comment|/* apparent dimension of mesh around node */
name|int
name|temp
decl_stmt|;
comment|/* temporary holder for distance info */
name|int
name|type
decl_stmt|;
comment|/* index of node type in mesh_info array */
name|unsigned
name|int
name|num_links
decl_stmt|;
comment|/* number of 'links' to adjacent switches */
name|link_t
modifier|*
name|links
index|[
literal|0
index|]
decl_stmt|;
comment|/* per link information */
block|}
name|mesh_node_t
typedef|;
end_typedef

begin_function_decl
name|void
name|osm_mesh_node_delete
parameter_list|(
name|struct
name|_lash
modifier|*
name|p_lash
parameter_list|,
name|struct
name|_switch
modifier|*
name|sw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osm_mesh_node_create
parameter_list|(
name|struct
name|_lash
modifier|*
name|p_lash
parameter_list|,
name|struct
name|_switch
modifier|*
name|sw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osm_do_mesh_analysis
parameter_list|(
name|struct
name|_lash
modifier|*
name|p_lash
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

