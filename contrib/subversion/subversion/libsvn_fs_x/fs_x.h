begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fs_x.h : interface to the native filesystem layer  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__FS_X_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__FS_X_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* Read the 'format' file of fsx filesystem FS and store its info in FS.  * Use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__read_format_file
parameter_list|(
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
comment|/* Open the fsx filesystem pointed to by PATH and associate it with    filesystem object FS.  Use SCRATCH_POOL for temporary allocations.     ### Some parts of *FS must have been initialized beforehand; some parts        (including FS->path) are initialized by this function. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__open
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Upgrade the fsx filesystem FS.  Indicate progress via the optional  * NOTIFY_FUNC callback using NOTIFY_BATON.  The optional CANCEL_FUNC  * will periodically be called with CANCEL_BATON to allow for preemption.  * Use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__upgrade
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
comment|/* Set *YOUNGEST to the youngest revision in filesystem FS.  Do any    temporary allocation in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__youngest_rev
parameter_list|(
name|svn_revnum_t
modifier|*
name|youngest
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
comment|/* Return SVN_ERR_FS_NO_SUCH_REVISION if the given revision REV is newer    than the current youngest revision in FS or is simply not a valid    revision number, else return success.  Use SCRATCH_POOL for temporary    allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__ensure_revision_exists
parameter_list|(
name|svn_revnum_t
name|rev
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
comment|/* Set *LENGTH to the be fulltext length of the node revision    specified by NODEREV. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__file_length
parameter_list|(
name|svn_filesize_t
modifier|*
name|length
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return TRUE if the representations in A and B have equal contents, else    return FALSE. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_x__file_text_rep_equal
parameter_list|(
name|svn_fs_x__representation_t
modifier|*
name|a
parameter_list|,
name|svn_fs_x__representation_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *EQUAL to TRUE if the property representations in A and B within FS    have equal contents, else set it to FALSE.  If STRICT is not set, allow    for false negatives.    Use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__prop_rep_equal
parameter_list|(
name|svn_boolean_t
modifier|*
name|equal
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|a
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|b
parameter_list|,
name|svn_boolean_t
name|strict
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a copy of the representation REP allocated from RESULT_POOL. */
end_comment

begin_function_decl
name|svn_fs_x__representation_t
modifier|*
name|svn_fs_x__rep_copy
parameter_list|(
name|svn_fs_x__representation_t
modifier|*
name|rep
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the recorded checksum of type KIND for the text representation    of NODREV into CHECKSUM, allocating from RESULT_POOL.  If no stored    checksum is available, put all NULL into CHECKSUM. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__file_checksum
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
parameter_list|,
name|svn_checksum_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Under the repository db PATH, create a FSFS repository with FORMAT,  * the given SHARD_SIZE.  If not supported by the respective format,  * the latter two parameters will be ignored.  FS will be updated.  *  * The only file not being written is the 'format' file.  This allows  * callers such as hotcopy to modify the contents before turning the  * tree into an accessible repository.  *  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__create_file_tree
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|format
parameter_list|,
name|int
name|shard_size
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a fs_x fileysystem referenced by FS at path PATH.  Get any    temporary allocations from SCRATCH_POOL.     ### Some parts of *FS must have been initialized beforehand; some parts        (including FS->path) are initialized by this function. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__create
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the uuid of repository FS to UUID and the instance ID to INSTANCE_ID.    If any of them is NULL, use a newly generated UUID / ID instead.    Perform temporary allocations in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__set_uuid
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|uuid
parameter_list|,
specifier|const
name|char
modifier|*
name|instance_id
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read the format number and maximum number of files per directory    from PATH and return them in *PFORMAT and *MAX_FILES_PER_DIR    respectively.     *MAX_FILES_PER_DIR is obtained from the 'layout' format option, and    will be set to zero if a linear scheme should be used.     Use SCRATCH_POOL for temporary allocation. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__write_format
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_boolean_t
name|overwrite
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the value of the property named PROPNAME in transaction REV.    Return the contents in *VALUE_P, allocated from RESULT_POOL.    Use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__revision_prop
parameter_list|(
name|svn_string_t
modifier|*
modifier|*
name|value_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
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
comment|/* Change, add, or delete a property on a revision REV in filesystem    FS.  NAME gives the name of the property, and value, if non-NULL,    gives the new contents of the property.  If value is NULL, then the    property will be deleted.  If OLD_VALUE_P is not NULL, do nothing unless    the preexisting value is *OLD_VALUE_P.    Do any temporary allocation in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__change_rev_prop
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
specifier|const
modifier|*
name|old_value_p
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|value
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If directory PATH does not exist, create it and give it the same    permissions as FS_PATH.  Do any temporary allocation in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__ensure_dir_exists
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|fs_path
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize all session-local caches in FS according to the global    cache settings. Use SCRATCH_POOL for temporary allocations.     Please note that it is permissible for this function to set some    or all of these caches to NULL, regardless of any setting. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__initialize_caches
parameter_list|(
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

