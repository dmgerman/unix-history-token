begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svn_fs_util.h: Declarations for the APIs of libsvn_fs_util to be  * consumed by only fs_* libs.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_FS_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_FS_UTIL_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
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
comment|/* Returns whether PATH is in canonical form as defined by    svn_fs__canonicalize_abspath().  */
name|svn_boolean_t
name|svn_fs__is_canonical_abspath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
comment|/* Return a canonicalized version of a filesystem PATH, allocated in POOL.     While the filesystem API is pretty flexible about the incoming paths    (they must be UTF-8 with '/' as separators, but they don't have to    begin with '/', and multiple contiguous '/'s are ignored) we want any    paths that are physically stored in the underlying database to look    consistent.  Specifically, absolute filesystem paths should begin with    '/', and all redundant and trailing '/' characters be removed.     This is similar to svn_fspath__canonicalize() but doesn't treat "."    segments as special. */
specifier|const
name|char
modifier|*
name|svn_fs__canonicalize_abspath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* If EXPECT_OPEN, verify that FS refers to an open database;    otherwise, verify that FS refers to an unopened database.  Return    an appropriate error if the expectation fails to match the    reality.  */
name|svn_error_t
modifier|*
name|svn_fs__check_fs
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_boolean_t
name|expect_open
parameter_list|)
function_decl|;
comment|/* An identifier for FS to be used in the text of error messages.    (Not used anywhere but in this header.)     Note: we log the UUID, rather than (fs)->path, since some of these    errors are marshalled to the client. */
define|#
directive|define
name|svn_fs__identifier
parameter_list|(
name|fs
parameter_list|)
value|((fs)->uuid)
comment|/* Constructing nice error messages for roots.  */
comment|/* Build an SVN_ERR_FS_NOT_FOUND error, with a detailed error text,    for PATH in ROOT. ROOT is of type svn_fs_root_t *. */
define|#
directive|define
name|SVN_FS__NOT_FOUND
parameter_list|(
name|root
parameter_list|,
name|path
parameter_list|)
value|(                        \   root->is_txn_root ?                                          \     svn_error_createf                                          \       (SVN_ERR_FS_NOT_FOUND, 0,                                \        _("File not found: transaction '%s', path '%s'"),       \        root->txn, path)                                        \   :                                                            \     svn_error_createf                                          \       (SVN_ERR_FS_NOT_FOUND, 0,                                \        _("File not found: revision %ld, path '%s'"),           \        root->rev, path)                                        \   )
comment|/* Build a detailed `file already exists' message for PATH in ROOT.    ROOT is of type svn_fs_root_t *. */
define|#
directive|define
name|SVN_FS__ALREADY_EXISTS
parameter_list|(
name|root
parameter_list|,
name|path_str
parameter_list|)
value|(                               \   root->is_txn_root ?                                                          \     svn_error_createf                                                          \       (SVN_ERR_FS_ALREADY_EXISTS, 0,                                           \        _("File already exists: filesystem '%s', transaction '%s', path '%s'"), \        svn_fs__identifier(root->fs), root->txn, path_str)      \   :                                                                            \     svn_error_createf                                                          \       (SVN_ERR_FS_ALREADY_EXISTS, 0,                                           \        _("File already exists: filesystem '%s', revision %ld, path '%s'"),     \        svn_fs__identifier(root->fs), root->rev, path_str)      \   )
comment|/* ROOT is of type svn_fs_root_t *. */
define|#
directive|define
name|SVN_FS__NOT_TXN
parameter_list|(
name|root
parameter_list|)
define|\
value|svn_error_create                                    \     (SVN_ERR_FS_NOT_TXN_ROOT, NULL,                   \      _("Root object must be a transaction root"))
comment|/* SVN_FS__ERR_NOT_MUTABLE: the caller attempted to change a node    outside of a transaction. FS is of type "svn_fs_t *". */
define|#
directive|define
name|SVN_FS__ERR_NOT_MUTABLE
parameter_list|(
name|fs
parameter_list|,
name|rev
parameter_list|,
name|path_in_repo
parameter_list|)
define|\
value|svn_error_createf(                                                     \      SVN_ERR_FS_NOT_MUTABLE, 0,                                          \      _("File is not mutable: filesystem '%s', revision %ld, path '%s'"), \      svn_fs__identifier(fs), rev, path_in_repo)
comment|/* FS is of type "svn_fs_t *".*/
define|#
directive|define
name|SVN_FS__ERR_NOT_DIRECTORY
parameter_list|(
name|fs
parameter_list|,
name|path_in_repo
parameter_list|)
define|\
value|svn_error_createf(                                              \      SVN_ERR_FS_NOT_DIRECTORY, 0,                                 \      _("'%s' is not a directory in filesystem '%s'"),             \      path_in_repo, svn_fs__identifier(fs))
comment|/* FS is of type "svn_fs_t *".   */
define|#
directive|define
name|SVN_FS__ERR_NOT_FILE
parameter_list|(
name|fs
parameter_list|,
name|path_in_repo
parameter_list|)
define|\
value|svn_error_createf(                                              \      SVN_ERR_FS_NOT_FILE, 0,                                      \      _("'%s' is not a file in filesystem '%s'"),                  \      path_in_repo, svn_fs__identifier(fs))
comment|/* FS is of type "svn_fs_t *", LOCK is of type "svn_lock_t *".   */
define|#
directive|define
name|SVN_FS__ERR_PATH_ALREADY_LOCKED
parameter_list|(
name|fs
parameter_list|,
name|lock
parameter_list|)
define|\
value|svn_error_createf(                                                        \      SVN_ERR_FS_PATH_ALREADY_LOCKED, 0,                                     \      _("Path '%s' is already locked by user '%s' in filesystem '%s'"),      \      (lock)->path, (lock)->owner, svn_fs__identifier(fs))
comment|/* FS is of type "svn_fs_t *". */
define|#
directive|define
name|SVN_FS__ERR_NO_SUCH_LOCK
parameter_list|(
name|fs
parameter_list|,
name|path_in_repo
parameter_list|)
define|\
value|svn_error_createf(                                              \      SVN_ERR_FS_NO_SUCH_LOCK, 0,                                  \      _("No lock on path '%s' in filesystem '%s'"),                \      path_in_repo, svn_fs__identifier(fs))
comment|/* FS is of type "svn_fs_t *". */
define|#
directive|define
name|SVN_FS__ERR_LOCK_EXPIRED
parameter_list|(
name|fs
parameter_list|,
name|token
parameter_list|)
define|\
value|svn_error_createf(                                             \      SVN_ERR_FS_LOCK_EXPIRED, 0,                                 \      _("Lock has expired: lock-token '%s' in filesystem '%s'"),  \      token, svn_fs__identifier(fs))
comment|/* FS is of type "svn_fs_t *". */
define|#
directive|define
name|SVN_FS__ERR_NO_USER
parameter_list|(
name|fs
parameter_list|)
define|\
value|svn_error_createf(                                                \      SVN_ERR_FS_NO_USER, 0,                                         \      _("No username is currently associated with filesystem '%s'"), \      svn_fs__identifier(fs))
comment|/* SVN_FS__ERR_LOCK_OWNER_MISMATCH: trying to use a lock whose    LOCK_OWNER doesn't match the USERNAME associated with FS.    FS is of type "svn_fs_t *". */
define|#
directive|define
name|SVN_FS__ERR_LOCK_OWNER_MISMATCH
parameter_list|(
name|fs
parameter_list|,
name|username
parameter_list|,
name|lock_owner
parameter_list|)
define|\
value|svn_error_createf(                                                    \      SVN_ERR_FS_LOCK_OWNER_MISMATCH, 0,                                 \      _("User '%s' is trying to use a lock owned by '%s' in "            \        "filesystem '%s'"),                                              \      username, lock_owner, svn_fs__identifier(fs))
comment|/* Return a NULL-terminated copy of the first component of PATH,    allocated in POOL.  If path is empty, or consists entirely of    slashes, return the empty string.     If the component is followed by one or more slashes, we set *NEXT_P    to point after the slashes.  If the component ends PATH, we set    *NEXT_P to zero.  This means:    - If *NEXT_P is zero, then the component ends the PATH, and there      are no trailing slashes in the path.    - If *NEXT_P points at PATH's terminating NULL character, then      the component returned was the last, and PATH ends with one or more      slash characters.    - Otherwise, *NEXT_P points to the beginning of the next component      of PATH.  You can pass this value to next_entry_name to extract      the next component. */
name|char
modifier|*
name|svn_fs__next_entry_name
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|next_p
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Allocate an svn_fs_path_change2_t structure in POOL, initialize and    return it.     Set the node_rev_id field of the created struct to NODE_REV_ID, and    change_kind to CHANGE_KIND.  Set all other fields to their _unknown,    NULL or invalid value, respectively. */
name|svn_fs_path_change2_t
modifier|*
name|svn_fs__path_change_create_internal
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|node_rev_id
parameter_list|,
name|svn_fs_path_change_kind_t
name|change_kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Append REL_PATH (which may contain slashes) to each path that exists in    the mergeinfo INPUT, and return a new mergeinfo in *OUTPUT.  Deep    copies the values.  Perform all allocations in POOL. */
name|svn_error_t
modifier|*
name|svn_fs__append_to_merged_froms
parameter_list|(
name|svn_mergeinfo_t
modifier|*
name|output
parameter_list|,
name|svn_mergeinfo_t
name|input
parameter_list|,
specifier|const
name|char
modifier|*
name|rel_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_FS_UTIL_H */
end_comment

end_unit

