begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * daemon/acl_list.h - client access control storage for the server.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file keeps track of the list of clients that are allowed to   * access the server.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_ACL_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_ACL_LIST_H
end_define

begin_include
include|#
directive|include
file|"util/storage/dnstree.h"
end_include

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

begin_comment
comment|/**  * Enumeration of access control options for an address range.  * Allow or deny access.  */
end_comment

begin_enum
enum|enum
name|acl_access
block|{
comment|/** disallow any access whatsoever, drop it */
name|acl_deny
init|=
literal|0
block|,
comment|/** disallow access, send a polite 'REFUSED' reply */
name|acl_refuse
block|,
comment|/** disallow any access to zones that aren't local, drop it */
name|acl_deny_non_local
block|,
comment|/** disallow access to zones that aren't local, 'REFUSED' reply */
name|acl_refuse_non_local
block|,
comment|/** allow full access for recursion (+RD) queries */
name|acl_allow
block|,
comment|/** allow full access for all queries, recursion and cache snooping */
name|acl_allow_snoop
block|}
enum|;
end_enum

begin_comment
comment|/**  * Access control storage structure  */
end_comment

begin_struct
struct|struct
name|acl_list
block|{
comment|/** regional for allocation */
name|struct
name|regional
modifier|*
name|region
decl_stmt|;
comment|/**  	 * Tree of the addresses that are allowed/blocked. 	 * contents of type acl_addr. 	 */
name|rbtree_t
name|tree
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  *  * An address span with access control information  */
end_comment

begin_struct
struct|struct
name|acl_addr
block|{
comment|/** node in address tree */
name|struct
name|addr_tree_node
name|node
decl_stmt|;
comment|/** access control on this netblock */
name|enum
name|acl_access
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create acl structure   * @return new structure or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|acl_list
modifier|*
name|acl_list_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete acl structure.  * @param acl: to delete.  */
end_comment

begin_function_decl
name|void
name|acl_list_delete
parameter_list|(
name|struct
name|acl_list
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Process access control config.  * @param acl: where to store.  * @param cfg: config options.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|acl_list_apply_cfg
parameter_list|(
name|struct
name|acl_list
modifier|*
name|acl
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup address to see its access control status.  * @param acl: structure for address storage.  * @param addr: address to check  * @param addrlen: length of addr.  * @return: what to do with message from this address.  */
end_comment

begin_function_decl
name|enum
name|acl_access
name|acl_list_lookup
parameter_list|(
name|struct
name|acl_list
modifier|*
name|acl
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
comment|/**  * Get memory used by acl structure.  * @param acl: structure for address storage.  * @return bytes in use.  */
end_comment

begin_function_decl
name|size_t
name|acl_list_get_mem
parameter_list|(
name|struct
name|acl_list
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DAEMON_ACL_LIST_H */
end_comment

end_unit

