begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_fwd.h - iterative resolver module forward zones.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to assist the iterator module.  * Keep track of forward zones, and read those from config.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_FWD_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_FWD_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delegpt
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Iterator forward zones structure  */
end_comment

begin_struct
struct|struct
name|iter_forwards
block|{
comment|/**  	 * Zones are stored in this tree. Sort order is specially chosen. 	 * first sorted on qclass. Then on dname in nsec-like order, so that 	 * a lookup on class, name will return an exact match or the closest 	 * match which gives the ancestor needed. 	 * contents of type iter_forward_zone. 	 */
name|rbtree_t
modifier|*
name|tree
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Iterator forward servers for a particular zone.  */
end_comment

begin_struct
struct|struct
name|iter_forward_zone
block|{
comment|/** redblacktree node, key is this structure: class and name */
name|rbnode_t
name|node
decl_stmt|;
comment|/** name */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|namelen
decl_stmt|;
comment|/** number of labels in name */
name|int
name|namelabs
decl_stmt|;
comment|/** delegation point with forward server information for this zone.  	 * If NULL then this forward entry is used to indicate that a 	 * stub-zone with the same name exists, and should be used.  	 * This delegation point is malloced. 	 */
name|struct
name|delegpt
modifier|*
name|dp
decl_stmt|;
comment|/** pointer to parent in tree (or NULL if none) */
name|struct
name|iter_forward_zone
modifier|*
name|parent
decl_stmt|;
comment|/** class. host order. */
name|uint16_t
name|dclass
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create forwards   * @return new forwards or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|iter_forwards
modifier|*
name|forwards_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete forwards.  * @param fwd: to delete.  */
end_comment

begin_function_decl
name|void
name|forwards_delete
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Process forwards config.  * @param fwd: where to store.  * @param cfg: config options.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|forwards_apply_cfg
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find forward zone exactly by name  * @param fwd: forward storage.  * @param qname: The qname of the query.  * @param qclass: The qclass of the query.  * @return: A delegation point or null.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|forwards_find
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|uint16_t
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find forward zone information  * For this qname/qclass find forward zone information, returns delegation  * point with server names and addresses, or NULL if no forwarding is needed.  *  * @param fwd: forward storage.  * @param qname: The qname of the query.  * @param qclass: The qclass of the query.  * @return: A delegation point if the query has to be forwarded to that list,  *         otherwise null.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|forwards_lookup
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|uint16_t
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Same as forwards_lookup, but for the root only  * @param fwd: forward storage.  * @param qclass: The qclass of the query.  * @return: A delegation point if root forward exists, otherwise null.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|forwards_lookup_root
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find next root item in forwards lookup tree.  * @param fwd: the forward storage  * @param qclass: class to look at next, or higher.  * @return false if none found, or if true stored in qclass.  */
end_comment

begin_function_decl
name|int
name|forwards_next_root
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
modifier|*
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory in use by forward storage  * @param fwd: forward storage.  * @return bytes in use  */
end_comment

begin_function_decl
name|size_t
name|forwards_get_mem
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare two fwd entries */
end_comment

begin_function_decl
name|int
name|fwd_cmp
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
comment|/**  * Add zone to forward structure. For external use since it recalcs   * the tree parents.  * @param fwd: the forward data structure  * @param c: class of zone  * @param dp: delegation point with name and target nameservers for new  *	forward zone. malloced.  * @return false on failure (out of memory);  */
end_comment

begin_function_decl
name|int
name|forwards_add_zone
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove zone from forward structure. For external use since it   * recalcs the tree parents.  * @param fwd: the forward data structure  * @param c: class of zone  * @param nm: name of zone (in uncompressed wireformat).  */
end_comment

begin_function_decl
name|void
name|forwards_delete_zone
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add stub hole (empty entry in forward table, that makes resolution skip  * a forward-zone because the stub zone should override the forward zone).  * Does not add one if not necessary.  * @param fwd: the forward data structure  * @param c: class of zone  * @param nm: name of zone (in uncompressed wireformat).  * @return false on failure (out of memory);  */
end_comment

begin_function_decl
name|int
name|forwards_add_stub_hole
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove stub hole, if one exists.  * @param fwd: the forward data structure  * @param c: class of zone  * @param nm: name of zone (in uncompressed wireformat).  */
end_comment

begin_function_decl
name|void
name|forwards_delete_stub_hole
parameter_list|(
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITERATOR_ITER_FWD_H */
end_comment

end_unit

