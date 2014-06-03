begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/storage/dnstree.h - support for rbtree types suitable for DNS code.  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains structures combining types and functions to  * manipulate those structures that help building DNS lookup trees.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_STORAGE_DNSTREE_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_STORAGE_DNSTREE_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_comment
comment|/**  * Tree of domain names.  Sorted first by class then by name.  * This is not sorted canonically, but fast.  * This can be looked up to obtain a closest encloser parent name.  *  * The tree itself is a rbtree_t.  * This is the element node put as first entry in the client structure.  */
end_comment

begin_struct
struct|struct
name|name_tree_node
block|{
comment|/** rbtree node, key is this struct : dclass and name */
name|rbnode_t
name|node
decl_stmt|;
comment|/** parent in tree */
name|struct
name|name_tree_node
modifier|*
name|parent
decl_stmt|;
comment|/** name in uncompressed wireformat */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|len
decl_stmt|;
comment|/** labels in name */
name|int
name|labs
decl_stmt|;
comment|/** the class of the name (host order) */
name|uint16_t
name|dclass
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Tree of IP addresses.  Sorted first by protocol, then by bits.  * This can be looked up to obtain the enclosing subnet.  *  * The tree itself is a rbtree_t.  * This is the element node put as first entry in the client structure.  */
end_comment

begin_struct
struct|struct
name|addr_tree_node
block|{
comment|/** rbtree node, key is this struct : proto and subnet */
name|rbnode_t
name|node
decl_stmt|;
comment|/** parent in tree */
name|struct
name|addr_tree_node
modifier|*
name|parent
decl_stmt|;
comment|/** address */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** netblock size */
name|int
name|net
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Init a name tree to be empty  * @param tree: to init.  */
end_comment

begin_function_decl
name|void
name|name_tree_init
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * insert element into name tree.  * @param tree: name tree  * @param node: node element (at start of a structure that caller  *	has allocated).  * @param name: name to insert (wireformat)  *	this node has been allocated by the caller and it itself inserted.  * @param len: length of name  * @param labs: labels in name  * @param dclass: class of name  * @return false on error (duplicate element).  */
end_comment

begin_function_decl
name|int
name|name_tree_insert
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|struct
name|name_tree_node
modifier|*
name|node
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize parent pointers in name tree.  * Should be performed after insertions are done, before lookups  * @param tree: name tree  */
end_comment

begin_function_decl
name|void
name|name_tree_init_parents
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup exact match in name tree  * @param tree: name tree  * @param name: wireformat name  * @param len: length of name  * @param labs: labels in name  * @param dclass: class of name  * @return node or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|name_tree_node
modifier|*
name|name_tree_find
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup closest encloser in name tree.  * @param tree: name tree  * @param name: wireformat name  * @param len: length of name  * @param labs: labels in name  * @param dclass: class of name  * @return closest enclosing node (could be equal) or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|name_tree_node
modifier|*
name|name_tree_lookup
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find next root item in name tree.  * @param tree: the nametree.  * @param dclass: the class to look for next (or higher).  * @return false if no classes found, true means class put into c.  */
end_comment

begin_function_decl
name|int
name|name_tree_next_root
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|uint16_t
modifier|*
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Init addr tree to be empty.  * @param tree: to init.  */
end_comment

begin_function_decl
name|void
name|addr_tree_init
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * insert element into addr tree.  * @param tree: addr tree  * @param node: node element (at start of a structure that caller  *	has allocated).  * @param addr: to insert (copied).  * @param addrlen: length of addr  * @param net: size of subnet.   * @return false on error (duplicate element).  */
end_comment

begin_function_decl
name|int
name|addr_tree_insert
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|struct
name|addr_tree_node
modifier|*
name|node
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|int
name|net
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize parent pointers in addr tree.  * Should be performed after insertions are done, before lookups  * @param tree: addr tree  */
end_comment

begin_function_decl
name|void
name|addr_tree_init_parents
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup closest encloser in addr tree.  * @param tree: addr tree  * @param addr: to lookup.  * @param addrlen: length of addr  * @return closest enclosing node (could be equal) or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|addr_tree_node
modifier|*
name|addr_tree_lookup
parameter_list|(
name|rbtree_t
modifier|*
name|tree
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare name tree nodes */
end_comment

begin_function_decl
name|int
name|name_tree_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare addr tree nodes */
end_comment

begin_function_decl
name|int
name|addr_tree_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_STORAGE_DNSTREE_H */
end_comment

end_unit

