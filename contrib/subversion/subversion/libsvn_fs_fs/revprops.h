begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* revprops.h --- everything needed to handle revprops in FSFS  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_comment
comment|/* In the filesystem FS, pack all revprop shards up to min_unpacked_rev.  *  * NOTE: Keep the old non-packed shards around until after the format bump.  * Otherwise, re-running upgrade will drop the packed revprop shard but  * have no unpacked data anymore.  Call upgrade_cleanup_pack_revprops after  * the bump.  *  * NOTIFY_FUNC and NOTIFY_BATON as well as CANCEL_FUNC and CANCEL_BATON are  * used in the usual way.  Temporary allocations are done in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__upgrade_pack_revprops
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_upgrade_notify_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
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
end_function_decl

begin_comment
comment|/* In the filesystem FS, remove all non-packed revprop shards up to  * min_unpacked_rev.  Temporary allocations are done in SCRATCH_POOL.  *  * NOTIFY_FUNC and NOTIFY_BATON as well as CANCEL_FUNC and CANCEL_BATON are  * used in the usual way.  Cancellation is supported in the sense that we  * will cleanly abort the operation.  However, there will be remnant shards  * that must be removed manually.  *  * See upgrade_pack_revprops for more info.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__upgrade_cleanup_pack_revprops
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_upgrade_notify_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
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
end_function_decl

begin_comment
comment|/* Read the revprops for revision REV in FS and return them in *PROPERTIES_P.  *  * Allocations will be done in POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_revision_proplist
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|proplist_p
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

begin_comment
comment|/* Set the revision property list of revision REV in filesystem FS to    PROPLIST.  Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__set_revision_proplist
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_hash_t
modifier|*
name|proplist
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return TRUE, if for REVISION in FS, we can find the revprop pack file.  * Use POOL for temporary allocations.  * Set *MISSING, if the reason is a missing manifest or pack file.  */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_fs__packed_revprop_available
parameter_list|(
name|svn_boolean_t
modifier|*
name|missing
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/****** Packing FSFS shards *********/
end_comment

begin_comment
comment|/* Copy revprop files for revisions [START_REV, END_REV) from SHARD_PATH  * to the pack file at PACK_FILE_NAME in PACK_FILE_DIR.  *  * The file sizes have already been determined and written to SIZES.  * Please note that this function will be executed while the filesystem  * has been locked and that revprops files will therefore not be modified  * while the pack is in progress.  *  * COMPRESSION_LEVEL defines how well the resulting pack file shall be  * compressed or whether is shall be compressed at all.  TOTAL_SIZE is  * a hint on which initial buffer size we should use to hold the pack file  * content.  *  * CANCEL_FUNC and CANCEL_BATON are used as usual. Temporary allocations  * are done in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__copy_revprops
parameter_list|(
specifier|const
name|char
modifier|*
name|pack_file_dir
parameter_list|,
specifier|const
name|char
modifier|*
name|pack_filename
parameter_list|,
specifier|const
name|char
modifier|*
name|shard_path
parameter_list|,
name|svn_revnum_t
name|start_rev
parameter_list|,
name|svn_revnum_t
name|end_rev
parameter_list|,
name|apr_array_header_t
modifier|*
name|sizes
parameter_list|,
name|apr_size_t
name|total_size
parameter_list|,
name|int
name|compression_level
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
end_function_decl

begin_comment
comment|/* In the filesystem FS, pack all revprop shards up to min_unpacked_rev.  *  * NOTE: Keep the old non-packed shards around until after the format bump.  * Otherwise, re-running upgrade will drop the packed revprop shard but  * have no unpacked data anymore.  Call upgrade_cleanup_pack_revprops after  * the bump.  *  * NOTIFY_FUNC and NOTIFY_BATON as well as CANCEL_FUNC and CANCEL_BATON are  * used in the usual way.  Temporary allocations are done in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__pack_revprops_shard
parameter_list|(
specifier|const
name|char
modifier|*
name|pack_file_dir
parameter_list|,
specifier|const
name|char
modifier|*
name|shard_path
parameter_list|,
name|apr_int64_t
name|shard
parameter_list|,
name|int
name|max_files_per_dir
parameter_list|,
name|apr_off_t
name|max_pack_size
parameter_list|,
name|int
name|compression_level
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
end_function_decl

begin_comment
comment|/* In the filesystem FS, remove all non-packed revprop shards up to  * min_unpacked_rev.  Temporary allocations are done in SCRATCH_POOL.  *  * NOTIFY_FUNC and NOTIFY_BATON as well as CANCEL_FUNC and CANCEL_BATON are  * used in the usual way.  Cancellation is supported in the sense that we  * will cleanly abort the operation.  However, there will be remnant shards  * that must be removed manually.  *  * See upgrade_pack_revprops for more info.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__delete_revprops_shard
parameter_list|(
specifier|const
name|char
modifier|*
name|shard_path
parameter_list|,
name|apr_int64_t
name|shard
parameter_list|,
name|int
name|max_files_per_dir
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
end_function_decl

end_unit

