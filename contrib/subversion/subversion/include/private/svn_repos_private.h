begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_repos_private.h  * @brief Subversion-internal repos APIs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_REPOS_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_REPOS_PRIVATE_H
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
file|"svn_repos.h"
end_include

begin_include
include|#
directive|include
file|"svn_editor.h"
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
comment|/** Validate that property @a name is valid for use in a Subversion  * repository; return @c SVN_ERR_REPOS_BAD_ARGS if it isn't.  For some  * "svn:" properties, also validate the @a value, and return  * @c SVN_ERR_BAD_PROPERTY_VALUE if it is not valid.  *  * Use @a pool for temporary allocations.  *  * @note This function is used to implement server-side validation.  * Consequently, if you make this function stricter in what it accepts, you  * (a) break svnsync'ing of existing repositories that contain now-invalid  * properties, (b) do not preclude such invalid values from entering the  * repository via tools that use the svn_fs_* API directly (possibly  * including svnadmin and svnlook).  This has happened before and there  * are known (documented, but unsupported) upgrade paths in some cases.  *  * @since New in 1.7.  */
name|svn_error_t
modifier|*
name|svn_repos__validate_prop
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|value
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Given the error @a err from svn_repos_fs_commit_txn(), return an  * string containing either or both of the svn_fs_commit_txn() error  * and the SVN_ERR_REPOS_POST_COMMIT_HOOK_FAILED wrapped error from  * the post-commit hook.  Any error tracing placeholders in the error  * chain are skipped over.  *  * This function does not modify @a err.  *  * ### This method should not be necessary, but there are a few  * ### places, e.g. mod_dav_svn, where only a single error message  * ### string is returned to the caller and it is useful to have both  * ### error messages included in the message.  *  * Use @a pool to do any allocations in.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_repos__post_commit_error_str
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* A repos version of svn_fs_type */
name|svn_error_t
modifier|*
name|svn_repos__fs_type
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|fs_type
parameter_list|,
specifier|const
name|char
modifier|*
name|repos_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create a commit editor for REPOS, based on REVISION.  */
name|svn_error_t
modifier|*
name|svn_repos__get_commit_ev2
parameter_list|(
name|svn_editor_t
modifier|*
modifier|*
name|editor
parameter_list|,
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|svn_authz_t
modifier|*
name|authz
parameter_list|,
specifier|const
name|char
modifier|*
name|authz_repos_name
parameter_list|,
specifier|const
name|char
modifier|*
name|authz_user
parameter_list|,
name|apr_hash_t
modifier|*
name|revprops
parameter_list|,
name|svn_commit_callback2_t
name|commit_cb
parameter_list|,
name|void
modifier|*
name|commit_baton
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
name|svn_error_t
modifier|*
name|svn_repos__replay_ev2
parameter_list|(
name|svn_fs_root_t
modifier|*
name|root
parameter_list|,
specifier|const
name|char
modifier|*
name|base_dir
parameter_list|,
name|svn_revnum_t
name|low_water_mark
parameter_list|,
name|svn_editor_t
modifier|*
name|editor
parameter_list|,
name|svn_repos_authz_func_t
name|authz_read_func
parameter_list|,
name|void
modifier|*
name|authz_read_baton
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
comment|/* SVN_REPOS_PRIVATE_H */
end_comment

end_unit

