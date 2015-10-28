begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cached_data.h --- cached (read) access to FSX data  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__CACHED_DATA_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__CACHED_DATA_H
end_define

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_include
include|#
directive|include
file|"index.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Set *NODEREV_P to the node-revision for the node ID in FS.  Do any    allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_node_revision
parameter_list|(
name|svn_fs_x__noderev_t
modifier|*
modifier|*
name|noderev_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_x__id_t
modifier|*
name|id
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
comment|/* Set *COUNT to the value of the mergeinfo_count member of the node-    revision for the node ID in FS.  Do temporary allocations in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_mergeinfo_count
parameter_list|(
name|apr_int64_t
modifier|*
name|count
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_x__id_t
modifier|*
name|id
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Verify that representation REP in FS can be accessed.    Do any allocations in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__check_rep
parameter_list|(
name|svn_fs_x__representation_t
modifier|*
name|rep
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Follow the representation delta chain in FS starting with REP.  The    number of reps (including REP) in the chain will be returned in    *CHAIN_LENGTH.  *SHARD_COUNT will be set to the number of shards    accessed.  Do any allocations in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__rep_chain_length
parameter_list|(
name|int
modifier|*
name|chain_length
parameter_list|,
name|int
modifier|*
name|shard_count
parameter_list|,
name|svn_fs_x__representation_t
modifier|*
name|rep
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *CONTENTS to be a readable svn_stream_t that receives the text    representation REP as seen in filesystem FS.  If CACHE_FULLTEXT is    not set, bypass fulltext cache lookup for this rep and don't put the    reconstructed fulltext into cache.    Allocate *CONTENT_P in RESULT_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_contents
parameter_list|(
name|svn_stream_t
modifier|*
modifier|*
name|contents_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__representation_t
modifier|*
name|rep
parameter_list|,
name|svn_boolean_t
name|cache_fulltext
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine on-disk and expanded sizes of the representation identified  * by ENTRY in FS and return the result in PACKED_LEN and EXPANDED_LEN,  * respectively.  FILE must point to the start of the representation and  * STREAM must be a stream defined on top of FILE.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_representation_length
parameter_list|(
name|svn_filesize_t
modifier|*
name|packed_len
parameter_list|,
name|svn_filesize_t
modifier|*
name|expanded_len
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
name|svn_fs_x__p2l_entry_t
modifier|*
name|entry
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Attempt to fetch the text representation of node-revision NODEREV as    seen in filesystem FS and pass it along with the BATON to the PROCESSOR.    Set *SUCCESS only of the data could be provided and the processing    had been called.    Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__try_process_file_contents
parameter_list|(
name|svn_boolean_t
modifier|*
name|success
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
parameter_list|,
name|svn_fs_process_contents_func_t
name|processor
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *STREAM_P to a delta stream turning the contents of the file SOURCE    into the contents of the file TARGET, allocated in RESULT_POOL.    If SOURCE is NULL, an empty string will be used in its stead.    Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_file_delta_stream
parameter_list|(
name|svn_txdelta_stream_t
modifier|*
modifier|*
name|stream_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|source
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|target
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
comment|/* Set *ENTRIES to an apr_array_header_t of dirent structs that contain    the directory entries of node-revision NODEREV in filesystem FS.  The    returned table is allocated in RESULT_POOL and entries are sorted    lexicographically.  SCRATCH_POOL is used for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__rep_contents_dir
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|entries_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
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
comment|/* Return the directory entry from ENTRIES that matches NAME.  If no such    entry exists, return NULL.  If HINT is not NULL, set *HINT to the array    index of the entry returned.  Successive calls in a linear scan scenario    will be faster called with the same HINT variable. */
end_comment

begin_function_decl
name|svn_fs_x__dirent_t
modifier|*
name|svn_fs_x__find_dir_entry
parameter_list|(
name|apr_array_header_t
modifier|*
name|entries
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|hint
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *DIRENT to the entry identified by NAME in the directory given    by NODEREV in filesystem FS.  If no such entry exits, *DIRENT will    be NULL.  The value referenced by HINT can be used to speed up    consecutive calls when travering the directory in name order.    Any value is allowed, however APR_SIZE_MAX gives best performance    when there has been no previous lookup for the same directory.     The returned object is allocated in RESULT_POOL; SCRATCH_POOL    used for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__rep_contents_dir_entry
parameter_list|(
name|svn_fs_x__dirent_t
modifier|*
modifier|*
name|dirent
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|apr_size_t
modifier|*
name|hint
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
comment|/* Set *PROPLIST to be an apr_hash_t containing the property list of    node-revision NODEREV as seen in filesystem FS.  Allocate the result    in RESULT_POOL and use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_proplist
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|proplist
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
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
comment|/* Fetch the list of change in revision REV in FS and return it in *CHANGES.  * Allocate the result in POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_changes
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|changes
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
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

