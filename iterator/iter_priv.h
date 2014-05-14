begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_priv.h - iterative resolver private address and domain store  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to assist the iterator module.  * Keep track of the private addresses and lookup fast.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_PRIV_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_PRIV_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

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
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_parse
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Iterator priv structure  */
end_comment

begin_struct
struct|struct
name|iter_priv
block|{
comment|/** regional for allocation */
name|struct
name|regional
modifier|*
name|region
decl_stmt|;
comment|/**  	 * Tree of the address spans that are blocked. 	 * contents of type addr_tree_node. 	 * No further data need, only presence or absence. 	 */
name|rbtree_t
name|a
decl_stmt|;
comment|/**  	 * Tree of the domains spans that are allowed to contain 	 * the blocked address spans. 	 * contents of type name_tree_node. 	 * No further data need, only presence or absence. 	 */
name|rbtree_t
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create priv structure   * @return new structure or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|iter_priv
modifier|*
name|priv_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete priv structure.  * @param priv: to delete.  */
end_comment

begin_function_decl
name|void
name|priv_delete
parameter_list|(
name|struct
name|iter_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Process priv config.  * @param priv: where to store.  * @param cfg: config options.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|priv_apply_cfg
parameter_list|(
name|struct
name|iter_priv
modifier|*
name|priv
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if rrset is bad.  * Will remove individual RRs that are bad (if possible) to  * sanitize the RRset without removing it completely.  * @param priv: structure for private address storage.  * @param pkt: packet to decompress rrset name in.  * @param rrset: the rrset to examine, A or AAAA.  * @return true if the rrset is bad and should be removed.  */
end_comment

begin_function_decl
name|int
name|priv_rrset_bad
parameter_list|(
name|struct
name|iter_priv
modifier|*
name|priv
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|rrset_parse
modifier|*
name|rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory used by priv structure.  * @param priv: structure for address storage.  * @return bytes in use.  */
end_comment

begin_function_decl
name|size_t
name|priv_get_mem
parameter_list|(
name|struct
name|iter_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITERATOR_ITER_PRIV_H */
end_comment

end_unit

