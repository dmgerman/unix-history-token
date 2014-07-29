begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_hints.h - iterative resolver module stub and root hints.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to assist the iterator module.  * Keep track of stub and root hints, and read those from config.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_HINTS_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_HINTS_H
end_define

begin_include
include|#
directive|include
file|"util/storage/dnstree.h"
end_include

begin_struct_decl
struct_decl|struct
name|iter_env
struct_decl|;
end_struct_decl

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
comment|/**  * Iterator hints structure  */
end_comment

begin_struct
struct|struct
name|iter_hints
block|{
comment|/**  	 * Hints are stored in this tree. Sort order is specially chosen. 	 * first sorted on qclass. Then on dname in nsec-like order, so that 	 * a lookup on class, name will return an exact match or the closest 	 * match which gives the ancestor needed. 	 * contents of type iter_hints_stub. The class IN root is in here. 	 * uses name_tree_node from dnstree.h. 	 */
name|rbtree_t
name|tree
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Iterator hints for a particular stub.  */
end_comment

begin_struct
struct|struct
name|iter_hints_stub
block|{
comment|/** tree sorted by name, class */
name|struct
name|name_tree_node
name|node
decl_stmt|;
comment|/** delegation point with hint information for this stub. malloced. */
name|struct
name|delegpt
modifier|*
name|dp
decl_stmt|;
comment|/** does the stub need to forego priming (like on other ports) */
name|uint8_t
name|noprime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create hints   * @return new hints or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|iter_hints
modifier|*
name|hints_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete hints.  * @param hints: to delete.  */
end_comment

begin_function_decl
name|void
name|hints_delete
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Process hints config. Sets default values for root hints if no config.  * @param hints: where to store.  * @param cfg: config options.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|hints_apply_cfg
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find root hints for the given class.  * @param hints: hint storage.  * @param qclass: class for which root hints are requested. host order.  * @return: NULL if no hints, or a ptr to stored hints.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|hints_lookup_root
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|,
name|uint16_t
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find next root hints (to cycle through all root hints).  * @param hints: hint storage  * @param qclass: class for which root hints are sought.  * 	0 means give the first available root hints class.  * 	x means, give class x or a higher class if any.  * 	returns the found class in this variable.  * @return true if a root hint class is found.  * 	false if not root hint class is found (qclass may have been changed).  */
end_comment

begin_function_decl
name|int
name|hints_next_root
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|,
name|uint16_t
modifier|*
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Given a qname/qclass combination, and the delegation point from the cache  * for this qname/qclass, determine if this combination indicates that a  * stub hint exists and must be primed.  *  * @param hints: hint storage.  * @param qname: The qname that generated the delegation point.  * @param qclass: The qclass that generated the delegation point.  * @param dp: The cache generated delegation point.  * @return: A priming delegation point if there is a stub hint that must  *         be primed, otherwise null.  */
end_comment

begin_function_decl
name|struct
name|iter_hints_stub
modifier|*
name|hints_lookup_stub
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory in use by hints  * @param hints: hint storage.  * @return bytes in use  */
end_comment

begin_function_decl
name|size_t
name|hints_get_mem
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add stub to hints structure. For external use since it recalcs   * the tree parents.  * @param hints: the hints data structure  * @param c: class of zone  * @param dp: delegation point with name and target nameservers for new  *	hints stub. malloced.  * @param noprime: set noprime option to true or false on new hint stub.  * @return false on failure (out of memory);  */
end_comment

begin_function_decl
name|int
name|hints_add_stub
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|int
name|noprime
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove stub from hints structure. For external use since it   * recalcs the tree parents.  * @param hints: the hints data structure  * @param c: class of stub zone  * @param nm: name of stub zone (in uncompressed wireformat).  */
end_comment

begin_function_decl
name|void
name|hints_delete_stub
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
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
comment|/* ITERATOR_ITER_HINTS_H */
end_comment

end_unit

