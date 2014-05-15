begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * radix.h -- generic radix tree  *  * Copyright (c) 2012, NLnet Labs. All rights reserved.  *  * This software is open source.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *  * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/**  * \file  * Radix tree. Implementation taken from NSD 4, adjusted for use in ldns.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_RADIX_H_
end_ifndef

begin_define
define|#
directive|define
name|LDNS_RADIX_H_
end_define

begin_include
include|#
directive|include
file|<ldns/error.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
name|uint16_t
name|radix_strlen_t
typedef|;
typedef|typedef
name|struct
name|ldns_radix_array_t
name|ldns_radix_array_t
typedef|;
typedef|typedef
name|struct
name|ldns_radix_node_t
name|ldns_radix_node_t
typedef|;
typedef|typedef
name|struct
name|ldns_radix_t
name|ldns_radix_t
typedef|;
comment|/** Radix node select edge array */
struct|struct
name|ldns_radix_array_t
block|{
comment|/** Additional string after the selection byte for this edge. */
name|uint8_t
modifier|*
name|str
decl_stmt|;
comment|/** Length of additional string for this edge. */
name|radix_strlen_t
name|len
decl_stmt|;
comment|/** Node that deals with byte+str. */
name|ldns_radix_node_t
modifier|*
name|edge
decl_stmt|;
block|}
struct|;
comment|/** A node in a radix tree */
struct|struct
name|ldns_radix_node_t
block|{
comment|/** Key corresponding to this node. */
name|uint8_t
modifier|*
name|key
decl_stmt|;
comment|/** Key length corresponding to this node. */
name|radix_strlen_t
name|klen
decl_stmt|;
comment|/** Data corresponding to this node. */
name|void
modifier|*
name|data
decl_stmt|;
comment|/** Parent node. */
name|ldns_radix_node_t
modifier|*
name|parent
decl_stmt|;
comment|/** Index in the the parent node select edge array. */
name|uint8_t
name|parent_index
decl_stmt|;
comment|/** Length of the array. */
name|uint16_t
name|len
decl_stmt|;
comment|/** Offset of the array. */
name|uint16_t
name|offset
decl_stmt|;
comment|/** Capacity of the array. */
name|uint16_t
name|capacity
decl_stmt|;
comment|/** Select edge array. */
name|ldns_radix_array_t
modifier|*
name|array
decl_stmt|;
block|}
struct|;
comment|/** An entire radix tree */
struct|struct
name|ldns_radix_t
block|{
comment|/** Root. */
name|ldns_radix_node_t
modifier|*
name|root
decl_stmt|;
comment|/** Number of nodes in tree. */
name|size_t
name|count
decl_stmt|;
block|}
struct|;
comment|/**  * Create a new radix tree.  * @return: new radix tree.  *  */
name|ldns_radix_t
modifier|*
name|ldns_radix_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Initialize radix tree.  * @param tree: uninitialized radix tree.  *  */
name|void
name|ldns_radix_init
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|)
function_decl|;
comment|/**  * Free the radix tree.  * @param tree: radix tree.  *  */
name|void
name|ldns_radix_free
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|)
function_decl|;
comment|/**  * Insert data into the tree.  * @param tree: tree to insert to.  * @param key:  key.  * @param len:  length of key.  * @param data: data.  * @return: status.  *  */
name|ldns_status
name|ldns_radix_insert
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|radix_strlen_t
name|len
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Delete data from the tree.  * @param tree: tree to insert to.  * @param key:  key.  * @param len:  length of key.  * @return: unlinked data or NULL if not present.  *  */
name|void
modifier|*
name|ldns_radix_delete
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|radix_strlen_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Search data in the tree.  * @param tree: tree to insert to.  * @param key:  key.  * @param len:  length of key.  * @return: the radix node or NULL if not found.  *  */
name|ldns_radix_node_t
modifier|*
name|ldns_radix_search
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|radix_strlen_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Search data in the tree, and if not found, find the closest smaller  * element in the tree.  * @param tree: tree to insert to.  * @param key:  key.  * @param len:  length of key.  * @param result: the radix node with the exact or closest match. NULL if  *                the key is smaller than the smallest key in the tree.  * @return 1 if exact match, 0 otherwise.  *  */
name|int
name|ldns_radix_find_less_equal
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|radix_strlen_t
name|len
parameter_list|,
name|ldns_radix_node_t
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
comment|/**  * Get the first element in the tree.  * @param tree: tree.  * @return: the radix node with the first element.  *  */
name|ldns_radix_node_t
modifier|*
name|ldns_radix_first
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|)
function_decl|;
comment|/**  * Get the last element in the tree.  * @param tree: tree.  * @return: the radix node with the last element.  *  */
name|ldns_radix_node_t
modifier|*
name|ldns_radix_last
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree
parameter_list|)
function_decl|;
comment|/**  * Next element.  * @param node: node.  * @return: node with next element.  *  */
name|ldns_radix_node_t
modifier|*
name|ldns_radix_next
parameter_list|(
name|ldns_radix_node_t
modifier|*
name|node
parameter_list|)
function_decl|;
comment|/**  * Previous element.  * @param node: node.  * @return: node with previous element.  *  */
name|ldns_radix_node_t
modifier|*
name|ldns_radix_prev
parameter_list|(
name|ldns_radix_node_t
modifier|*
name|node
parameter_list|)
function_decl|;
comment|/**  * Split radix tree intwo.  * @param tree1: one tree.  * @param num: number of elements to split off.  * @param tree2: another tree.  * @return: status.  *  */
name|ldns_status
name|ldns_radix_split
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree1
parameter_list|,
name|size_t
name|num
parameter_list|,
name|ldns_radix_t
modifier|*
modifier|*
name|tree2
parameter_list|)
function_decl|;
comment|/**  * Join two radix trees.  * @param tree1: one tree.  * @param tree2: another tree.  * @return: status.  *  */
name|ldns_status
name|ldns_radix_join
parameter_list|(
name|ldns_radix_t
modifier|*
name|tree1
parameter_list|,
name|ldns_radix_t
modifier|*
name|tree2
parameter_list|)
function_decl|;
comment|/**  * Call function for all nodes in the tree, such that leaf nodes are  * called before parent nodes.  * @param node: start node.  * @param func: function.  * @param arg: user argument.  *  */
name|void
name|ldns_radix_traverse_postorder
parameter_list|(
name|ldns_radix_node_t
modifier|*
name|node
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ldns_radix_node_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/**  * Print radix tree (for debugging purposes).  * @param fd: file descriptor.  * @param tree: tree.  *  */
name|void
name|ldns_radix_printf
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|ldns_radix_t
modifier|*
name|tree
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_RADIX_H_ */
end_comment

end_unit

