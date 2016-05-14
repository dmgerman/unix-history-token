begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_fs_fs_private.h  * @brief Private API for tools that access FSFS internals and can't use  *        the svn_fs_t API for that.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_FS_FS_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_FS_FS_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"svn_iter.h"
end_include

begin_include
include|#
directive|include
file|"svn_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
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
comment|/* __cplusplus */
comment|/* Description of one large representation.  It's content will be reused /  * overwritten when it gets replaced by an even larger representation.  */
typedef|typedef
struct|struct
name|svn_fs_fs__large_change_info_t
block|{
comment|/* size of the (deltified) representation */
name|apr_uint64_t
name|size
decl_stmt|;
comment|/* Revision of the representation. SVN_INVALID_REVNUM for unused entries. */
name|svn_revnum_t
name|revision
decl_stmt|;
comment|/* node path. "" for unused instances */
name|svn_stringbuf_t
modifier|*
name|path
decl_stmt|;
block|}
name|svn_fs_fs__large_change_info_t
typedef|;
comment|/* Container for the largest representations found so far.  The capacity  * is fixed and entries will be inserted by reusing the last one and  * reshuffling the entry pointers.  */
typedef|typedef
struct|struct
name|svn_fs_fs__largest_changes_t
block|{
comment|/* number of entries allocated in CHANGES */
name|apr_size_t
name|count
decl_stmt|;
comment|/* size of the smallest change */
name|apr_uint64_t
name|min_size
decl_stmt|;
comment|/* changes kept in this struct */
name|svn_fs_fs__large_change_info_t
modifier|*
modifier|*
name|changes
decl_stmt|;
block|}
name|svn_fs_fs__largest_changes_t
typedef|;
comment|/* Information we gather per size bracket.  */
typedef|typedef
struct|struct
name|svn_fs_fs__histogram_line_t
block|{
comment|/* number of item that fall into this bracket */
name|apr_uint64_t
name|count
decl_stmt|;
comment|/* sum of values in this bracket */
name|apr_uint64_t
name|sum
decl_stmt|;
block|}
name|svn_fs_fs__histogram_line_t
typedef|;
comment|/* A histogram of 64 bit integer values.  */
typedef|typedef
struct|struct
name|svn_fs_fs__histogram_t
block|{
comment|/* total sum over all brackets */
name|svn_fs_fs__histogram_line_t
name|total
decl_stmt|;
comment|/* one bracket per binary step.    * line[i] is the 2^(i-1)<= x< 2^i bracket */
name|svn_fs_fs__histogram_line_t
name|lines
index|[
literal|64
index|]
decl_stmt|;
block|}
name|svn_fs_fs__histogram_t
typedef|;
comment|/* Information we collect per file ending.  */
typedef|typedef
struct|struct
name|svn_fs_fs__extension_info_t
block|{
comment|/* file extension, including leading "."    * "(none)" in the container for files w/o extension. */
specifier|const
name|char
modifier|*
name|extension
decl_stmt|;
comment|/* histogram of representation sizes */
name|svn_fs_fs__histogram_t
name|rep_histogram
decl_stmt|;
comment|/* histogram of sizes of changed files */
name|svn_fs_fs__histogram_t
name|node_histogram
decl_stmt|;
block|}
name|svn_fs_fs__extension_info_t
typedef|;
comment|/* Compression statistics we collect over a given set of representations.  */
typedef|typedef
struct|struct
name|svn_fs_fs__rep_pack_stats_t
block|{
comment|/* number of representations */
name|apr_uint64_t
name|count
decl_stmt|;
comment|/* total size after deltification (i.e. on disk size) */
name|apr_uint64_t
name|packed_size
decl_stmt|;
comment|/* total size after de-deltification (i.e. plain text size) */
name|apr_uint64_t
name|expanded_size
decl_stmt|;
comment|/* total on-disk header size */
name|apr_uint64_t
name|overhead_size
decl_stmt|;
block|}
name|svn_fs_fs__rep_pack_stats_t
typedef|;
comment|/* Statistics we collect over a given set of representations.  * We group them into shared and non-shared ("unique") reps.  */
typedef|typedef
struct|struct
name|svn_fs_fs__representation_stats_t
block|{
comment|/* stats over all representations */
name|svn_fs_fs__rep_pack_stats_t
name|total
decl_stmt|;
comment|/* stats over those representations with ref_count == 1 */
name|svn_fs_fs__rep_pack_stats_t
name|uniques
decl_stmt|;
comment|/* stats over those representations with ref_count> 1 */
name|svn_fs_fs__rep_pack_stats_t
name|shared
decl_stmt|;
comment|/* sum of all ref_counts */
name|apr_uint64_t
name|references
decl_stmt|;
comment|/* sum of ref_count * expanded_size,    * i.e. total plaintext content if there was no rep sharing */
name|apr_uint64_t
name|expanded_size
decl_stmt|;
block|}
name|svn_fs_fs__representation_stats_t
typedef|;
comment|/* Basic statistics we collect over a given set of noderevs.  */
typedef|typedef
struct|struct
name|svn_fs_fs__node_stats_t
block|{
comment|/* number of noderev structs */
name|apr_uint64_t
name|count
decl_stmt|;
comment|/* their total size on disk (structs only) */
name|apr_uint64_t
name|size
decl_stmt|;
block|}
name|svn_fs_fs__node_stats_t
typedef|;
comment|/* Comprises all the information needed to create the output of the  * 'svnfsfs stats' command.  */
typedef|typedef
struct|struct
name|svn_fs_fs__stats_t
block|{
comment|/* sum total of all rev / pack file sizes in bytes */
name|apr_uint64_t
name|total_size
decl_stmt|;
comment|/* number of revisions in the repository */
name|apr_uint64_t
name|revision_count
decl_stmt|;
comment|/* total number of changed paths */
name|apr_uint64_t
name|change_count
decl_stmt|;
comment|/* sum of all changed path list sizes on disk in bytes */
name|apr_uint64_t
name|change_len
decl_stmt|;
comment|/* stats on all representations */
name|svn_fs_fs__representation_stats_t
name|total_rep_stats
decl_stmt|;
comment|/* stats on all file text representations */
name|svn_fs_fs__representation_stats_t
name|file_rep_stats
decl_stmt|;
comment|/* stats on all directory text representations */
name|svn_fs_fs__representation_stats_t
name|dir_rep_stats
decl_stmt|;
comment|/* stats on all file prop representations */
name|svn_fs_fs__representation_stats_t
name|file_prop_rep_stats
decl_stmt|;
comment|/* stats on all directory prop representations */
name|svn_fs_fs__representation_stats_t
name|dir_prop_rep_stats
decl_stmt|;
comment|/* size and count summary over all noderevs */
name|svn_fs_fs__node_stats_t
name|total_node_stats
decl_stmt|;
comment|/* size and count summary over all file noderevs */
name|svn_fs_fs__node_stats_t
name|file_node_stats
decl_stmt|;
comment|/* size and count summary over all directory noderevs */
name|svn_fs_fs__node_stats_t
name|dir_node_stats
decl_stmt|;
comment|/* the biggest single contributors to repo size */
name|svn_fs_fs__largest_changes_t
modifier|*
name|largest_changes
decl_stmt|;
comment|/* histogram of representation sizes */
name|svn_fs_fs__histogram_t
name|rep_size_histogram
decl_stmt|;
comment|/* histogram of sizes of changed nodes */
name|svn_fs_fs__histogram_t
name|node_size_histogram
decl_stmt|;
comment|/* histogram of representation sizes */
name|svn_fs_fs__histogram_t
name|added_rep_size_histogram
decl_stmt|;
comment|/* histogram of sizes of changed nodes */
name|svn_fs_fs__histogram_t
name|added_node_size_histogram
decl_stmt|;
comment|/* histogram of unused representations */
name|svn_fs_fs__histogram_t
name|unused_rep_histogram
decl_stmt|;
comment|/* histogram of sizes of changed files */
name|svn_fs_fs__histogram_t
name|file_histogram
decl_stmt|;
comment|/* histogram of sizes of file representations */
name|svn_fs_fs__histogram_t
name|file_rep_histogram
decl_stmt|;
comment|/* histogram of sizes of changed file property sets */
name|svn_fs_fs__histogram_t
name|file_prop_histogram
decl_stmt|;
comment|/* histogram of sizes of file property representations */
name|svn_fs_fs__histogram_t
name|file_prop_rep_histogram
decl_stmt|;
comment|/* histogram of sizes of changed directories (in bytes) */
name|svn_fs_fs__histogram_t
name|dir_histogram
decl_stmt|;
comment|/* histogram of sizes of directories representations */
name|svn_fs_fs__histogram_t
name|dir_rep_histogram
decl_stmt|;
comment|/* histogram of sizes of changed directories property sets */
name|svn_fs_fs__histogram_t
name|dir_prop_histogram
decl_stmt|;
comment|/* histogram of sizes of directories property representations */
name|svn_fs_fs__histogram_t
name|dir_prop_rep_histogram
decl_stmt|;
comment|/* extension -> svn_fs_fs__extension_info_t* map */
name|apr_hash_t
modifier|*
name|by_extension
decl_stmt|;
block|}
name|svn_fs_fs__stats_t
typedef|;
comment|/* Scan all contents of the repository FS and return statistics in *STATS,  * allocated in RESULT_POOL.  Report progress through PROGRESS_FUNC with  * PROGRESS_BATON, if PROGRESS_FUNC is not NULL.  * Use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_fs_fs__get_stats
parameter_list|(
name|svn_fs_fs__stats_t
modifier|*
modifier|*
name|stats
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_progress_notify_func_t
name|progress_func
parameter_list|,
name|void
modifier|*
name|progress_baton
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
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
comment|/* Node-revision IDs in FSFS consist of 3 of sub-IDs ("parts") that consist  * of a creation REVISION number and some revision- / transaction-local  * counter value (NUMBER).  Old-style ID parts use global counter values.  *  * The parts are: node_id, copy_id and txn_id for in-txn IDs as well as  * node_id, copy_id and rev_offset for in-revision IDs.  This struct the  * data structure used for each of those parts.  */
typedef|typedef
struct|struct
name|svn_fs_fs__id_part_t
block|{
comment|/* SVN_INVALID_REVNUM for txns -> not a txn, COUNTER must be 0.      SVN_INVALID_REVNUM for others -> not assigned to a revision, yet.      0                  for others -> old-style ID or the root in rev 0. */
name|svn_revnum_t
name|revision
decl_stmt|;
comment|/* sub-id value relative to REVISION.  Its interpretation depends on      the part itself.  In rev_item, it is the index_index value, in others      it represents a unique counter value. */
name|apr_uint64_t
name|number
decl_stmt|;
block|}
name|svn_fs_fs__id_part_t
typedef|;
comment|/* (user visible) entry in the phys-to-log index.  It describes a section  * of some packed / non-packed rev file as containing a specific item.  * There must be no overlapping / conflicting entries.  */
typedef|typedef
struct|struct
name|svn_fs_fs__p2l_entry_t
block|{
comment|/* offset of the first byte that belongs to the item */
name|apr_off_t
name|offset
decl_stmt|;
comment|/* length of the item in bytes */
name|apr_off_t
name|size
decl_stmt|;
comment|/* type of the item (see SVN_FS_FS__ITEM_TYPE_*) defines */
name|apr_uint32_t
name|type
decl_stmt|;
comment|/* modified FNV-1a checksum.  0 if unknown checksum */
name|apr_uint32_t
name|fnv1_checksum
decl_stmt|;
comment|/* item in that block */
name|svn_fs_fs__id_part_t
name|item
decl_stmt|;
block|}
name|svn_fs_fs__p2l_entry_t
typedef|;
comment|/* Callback function type receiving a single P2L index ENTRY, a user  * provided BATON and a SCRATCH_POOL for temporary allocations.  * ENTRY's lifetime may end when the callback returns.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_fs_fs__dump_index_func_t
function_decl|)
parameter_list|(
specifier|const
name|svn_fs_fs__p2l_entry_t
modifier|*
name|entry
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
comment|/* Read the P2L index for the rev / pack file containing REVISION in FS.  * For each index entry, invoke CALLBACK_FUNC with CALLBACK_BATON.  * If not NULL, call CANCEL_FUNC with CANCEL_BATON from time to time.  * Use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_fs_fs__dump_index
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|svn_fs_fs__dump_index_func_t
name|callback_func
parameter_list|,
name|void
modifier|*
name|callback_baton
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Rewrite the respective index information of the rev / pack file in FS  * containing REVISION and use the svn_fs_fs__p2l_entry_t * array ENTRIES  * as the new index contents.  Allocate temporaries from SCRATCH_POOL.  *  * Note that this becomes a no-op if ENTRIES is empty.  You may use a zero-  * sized empty entry instead.  */
name|svn_error_t
modifier|*
name|svn_fs_fs__load_index
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_array_header_t
modifier|*
name|entries
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
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

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_FS_FS_PRIVATE_H */
end_comment

end_unit

