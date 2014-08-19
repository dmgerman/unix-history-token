begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rbtree.h -- generic red-black tree  *  * Copyright (c) 2001-2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/**  * \file  * Red black tree. Implementation taken from NSD 3.0.5, adjusted for use  * in unbound (memory allocation, logging and so on).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_RBTREE_H_
end_ifndef

begin_define
define|#
directive|define
name|UTIL_RBTREE_H_
end_define

begin_comment
comment|/**  * This structure must be the first member of the data structure in  * the rbtree.  This allows easy casting between an rbnode_t and the  * user data (poor man's inheritance).  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|rbnode_t
name|rbnode_t
typedef|;
end_typedef

begin_comment
comment|/**  * The rbnode_t struct definition.  */
end_comment

begin_struct
struct|struct
name|rbnode_t
block|{
comment|/** parent in rbtree, RBTREE_NULL for root */
name|rbnode_t
modifier|*
name|parent
decl_stmt|;
comment|/** left node (smaller items) */
name|rbnode_t
modifier|*
name|left
decl_stmt|;
comment|/** right node (larger items) */
name|rbnode_t
modifier|*
name|right
decl_stmt|;
comment|/** pointer to sorting key */
specifier|const
name|void
modifier|*
name|key
decl_stmt|;
comment|/** colour of this node */
name|uint8_t
name|color
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** The nullpointer, points to empty node */
end_comment

begin_define
define|#
directive|define
name|RBTREE_NULL
value|&rbtree_null_node
end_define

begin_comment
comment|/** the global empty node */
end_comment

begin_decl_stmt
specifier|extern
name|rbnode_t
name|rbtree_null_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** An entire red black tree */
end_comment

begin_typedef
typedef|typedef
name|struct
name|rbtree_t
name|rbtree_t
typedef|;
end_typedef

begin_comment
comment|/** definition for tree struct */
end_comment

begin_struct
struct|struct
name|rbtree_t
block|{
comment|/** The root of the red-black tree */
name|rbnode_t
modifier|*
name|root
decl_stmt|;
comment|/** The number of the nodes in the tree */
name|size_t
name|count
decl_stmt|;
comment|/**  	 * Key compare function.<0,0,>0 like strcmp.  	 * Return 0 on two NULL ptrs.  	 */
name|int
function_decl|(
modifier|*
name|cmp
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Create new tree (malloced) with given key compare function.   * @param cmpf: compare function (like strcmp) takes pointers to two keys.  * @return: new tree, empty.  */
end_comment

begin_function_decl
name|rbtree_t
modifier|*
name|rbtree_create
parameter_list|(
name|int
function_decl|(
modifier|*
name|cmpf
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Init a new tree (malloced by caller) with given key compare function.   * @param rbtree: uninitialised memory for new tree, returned empty.  * @param cmpf: compare function (like strcmp) takes pointers to two keys.  */
end_comment

begin_function_decl
name|void
name|rbtree_init
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|,
name|int
function_decl|(
modifier|*
name|cmpf
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Insert data into the tree.   * @param rbtree: tree to insert to.  * @param data: element to insert.   * @return: data ptr or NULL if key already present.   */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_insert
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|,
name|rbnode_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete element from tree.  * @param rbtree: tree to delete from.  * @param key: key of item to delete.  * @return: node that is now unlinked from the tree. User to delete it.   * returns 0 if node not present   */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_delete
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find key in tree. Returns NULL if not found.  * @param rbtree: tree to find in.  * @param key: key that must match.  * @return: node that fits or NULL.  */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_search
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find, but match does not have to be exact.  * @param rbtree: tree to find in.  * @param key: key to find position of.  * @param result: set to the exact node if present, otherwise to element that  *   precedes the position of key in the tree. NULL if no smaller element.  * @return: true if exact match in result. Else result points to<= element,  * or NULL if key is smaller than the smallest key.   */
end_comment

begin_function_decl
name|int
name|rbtree_find_less_equal
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|rbnode_t
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns first (smallest) node in the tree  * @param rbtree: tree  * @return: smallest element or NULL if tree empty.  */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_first
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns last (largest) node in the tree  * @param rbtree: tree  * @return: largest element or NULL if tree empty.  */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_last
parameter_list|(
name|rbtree_t
modifier|*
name|rbtree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns next larger node in the tree  * @param rbtree: tree  * @return: next larger element or NULL if no larger in tree.  */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_next
parameter_list|(
name|rbnode_t
modifier|*
name|rbtree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns previous smaller node in the tree  * @param rbtree: tree  * @return: previous smaller element or NULL if no previous in tree.  */
end_comment

begin_function_decl
name|rbnode_t
modifier|*
name|rbtree_previous
parameter_list|(
name|rbnode_t
modifier|*
name|rbtree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Call with node=variable of struct* with rbnode_t as first element.  * with type is the type of a pointer to that struct.   */
end_comment

begin_define
define|#
directive|define
name|RBTREE_FOR
parameter_list|(
name|node
parameter_list|,
name|type
parameter_list|,
name|rbtree
parameter_list|)
define|\
value|for(node=(type)rbtree_first(rbtree); \ 		(rbnode_t*)node != RBTREE_NULL; \ 		node = (type)rbtree_next((rbnode_t*)node))
end_define

begin_comment
comment|/**  * Call function for all elements in the redblack tree, such that  * leaf elements are called before parent elements. So that all  * elements can be safely free()d.  * Note that your function must not remove the nodes from the tree.  * Since that may trigger rebalances of the rbtree.  * @param tree: the tree  * @param func: function called with element and user arg.  * 	The function must not alter the rbtree.  * @param arg: user argument.  */
end_comment

begin_function_decl
name|void
name|traverse_postorder
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|rbnode_t
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
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_RBTREE_H_ */
end_comment

end_unit

