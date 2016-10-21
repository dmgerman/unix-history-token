begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cachedb/cachedb.h - cache from a database external to the program module  *  * Copyright (c) 2016, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a module that uses an external database to cache  * dns responses.  */
end_comment

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_struct_decl
struct_decl|struct
name|cachedb_backend
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The global variable environment contents for the cachedb  * Shared between threads, this represents long term information.  * Like database connections.  */
end_comment

begin_struct
struct|struct
name|cachedb_env
block|{
comment|/** true is cachedb is enabled, the backend is turned on */
name|int
name|enabled
decl_stmt|;
comment|/** the backend routines */
name|struct
name|cachedb_backend
modifier|*
name|backend
decl_stmt|;
comment|/** backend specific data here */
name|void
modifier|*
name|backend_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Per query state for the cachedb module.  */
end_comment

begin_struct
struct|struct
name|cachedb_qstate
block|{
name|int
name|todo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Backend call routines  */
end_comment

begin_struct
struct|struct
name|cachedb_backend
block|{
comment|/** backend name */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** Init(env, cachedb_env): false on setup failure */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
parameter_list|,
name|struct
name|cachedb_env
modifier|*
parameter_list|)
function_decl|;
comment|/** Deinit - close db for program exit */
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
parameter_list|,
name|struct
name|cachedb_env
modifier|*
parameter_list|)
function_decl|;
comment|/** Lookup (env, cachedb_env, key, result_buffer): true if found */
name|int
function_decl|(
modifier|*
name|lookup
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
parameter_list|,
name|struct
name|cachedb_env
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
parameter_list|)
function_decl|;
comment|/** Store (env, cachedb_env, key, data, data_len) */
name|void
function_decl|(
modifier|*
name|store
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
parameter_list|,
name|struct
name|cachedb_env
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/** Init the cachedb module */
end_comment

begin_function_decl
name|int
name|cachedb_init
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Deinit the cachedb module */
end_comment

begin_function_decl
name|void
name|cachedb_deinit
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Operate on an event on a query (in qstate). */
end_comment

begin_function_decl
name|void
name|cachedb_operate
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|enum
name|module_ev
name|event
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|outbound
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Subordinate query done, inform this super request of its conclusion */
end_comment

begin_function_decl
name|void
name|cachedb_inform_super
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|super
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** clear the cachedb query-specific contents out of qstate */
end_comment

begin_function_decl
name|void
name|cachedb_clear
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** return memory estimate for cachedb module */
end_comment

begin_function_decl
name|size_t
name|cachedb_get_mem
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the function block with pointers to the cachedb functions  * @return the function block for "cachedb".  */
end_comment

begin_function_decl
name|struct
name|module_func_block
modifier|*
name|cachedb_get_funcblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

