begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* changes.h --- FSX changed paths lists container  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__CHANGES_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__CHANGES_H
end_define

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* Entries in a revision's change list tend to be widely redundant (similar  * changes to similar paths).  Even more so, change lists from a larger  * revision range also tend to overlap.  *  * In its serialized form, the svn_fs_x__changes_t container extracts most  * of that redundancy and the run-time representation is also much smaller  * than sum of the respective svn_fs_x__change_t* arrays.  *  * As with other containers, this one has two modes: 'construction', in  * which you may add data to it, and 'getter' in which there is only r/o  * access to the data.  */
end_comment

begin_comment
comment|/* An opaque collection of change lists (apr_array_header_t * of  * svn_fs_x__change_t *).  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|svn_fs_x__changes_t
name|svn_fs_x__changes_t
typedef|;
end_typedef

begin_comment
comment|/* Create and populate changes containers. */
end_comment

begin_comment
comment|/* Create and return a new changes container with an initial capacity of  * INITIAL_COUNT svn_fs_x__change_t objects.  * Allocate the result in RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_fs_x__changes_t
modifier|*
name|svn_fs_x__changes_create
parameter_list|(
name|apr_size_t
name|initial_count
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start a new change list CHANGES (implicitly terminating the previous one)  * and return its index in *LIST_INDEX.  Append all changes from LIST to  * that new change list.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__changes_append_list
parameter_list|(
name|apr_size_t
modifier|*
name|list_index
parameter_list|,
name|svn_fs_x__changes_t
modifier|*
name|changes
parameter_list|,
name|apr_array_header_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a rough estimate in bytes for the serialized representation  * of CHANGES.  */
end_comment

begin_function_decl
name|apr_size_t
name|svn_fs_x__changes_estimate_size
parameter_list|(
specifier|const
name|svn_fs_x__changes_t
modifier|*
name|changes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read changes containers. */
end_comment

begin_comment
comment|/* From CHANGES, extract the change list with the given IDX.  Allocate  * the result in POOL and return it in *LIST.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__changes_get_list
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|list
parameter_list|,
specifier|const
name|svn_fs_x__changes_t
modifier|*
name|changes
parameter_list|,
name|apr_size_t
name|idx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* I/O interface. */
end_comment

begin_comment
comment|/* Write a serialized representation of CHANGES to STREAM.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__write_changes_container
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|svn_fs_x__changes_t
modifier|*
name|changes
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a changes container from its serialized representation in STREAM.  * Allocate the result in RESULT_POOL and return it in *CHANGES_P.  Use  * SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__read_changes_container
parameter_list|(
name|svn_fs_x__changes_t
modifier|*
modifier|*
name|changes_p
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implements #svn_cache__serialize_func_t for svn_fs_x__changes_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_changes_container
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|data_len
parameter_list|,
name|void
modifier|*
name|in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implements #svn_cache__deserialize_func_t for svn_fs_x__changes_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_changes_container
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implements svn_cache__partial_getter_func_t for svn_fs_x__changes_t,  * setting *OUT to the change list (apr_array_header_t *) selected by  * the apr_uint32_t index passed in as *BATON.  This function is similar  * to svn_fs_x__changes_get_list but operates on the cache serialized  * representation of the container.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__changes_get_list_func
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

