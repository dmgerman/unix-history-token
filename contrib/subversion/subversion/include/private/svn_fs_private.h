begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svn_fs_private.h: Private declarations for the filesystem layer to  * be consumed by libsvn_fs* and non-libsvn_fs* modules.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_FS_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_FS_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_editor.h"
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
comment|/* The maximum length of a transaction name.  The Berkeley DB backend    generates transaction names from a sequence expressed as a base 36    number with a maximum of MAX_KEY_SIZE (currently 200) bytes.  The    FSFS backend generates transaction names of the form<rev>-<base 36-number> where the base 36 number is a sequence value    with a maximum length of MAX_KEY_SIZE bytes.  The maximum length is    212, but use 220 just to have some extra space:      10   -> 32 bit revision number      1    -> '-'      200  -> 200 digit base 36 number      1    -> '\0'  */
define|#
directive|define
name|SVN_FS__TXN_MAX_LEN
value|220
comment|/** Retrieve the lock-tokens associated in the context @a access_ctx.  * The tokens are in a hash keyed with<tt>const char *</tt> tokens,  * and with<tt>const char *</tt> values for the paths associated.  *  * You should always use svn_fs_access_add_lock_token2() if you intend  * to use this function.  The result of the function is not guaranteed  * if you use it with the deprecated svn_fs_access_add_lock_token()  * API.  *  * @since New in 1.6. */
name|apr_hash_t
modifier|*
name|svn_fs__access_get_lock_tokens
parameter_list|(
name|svn_fs_access_t
modifier|*
name|access_ctx
parameter_list|)
function_decl|;
comment|/* Check whether PATH is valid for a filesystem, following (most of) the  * requirements in svn_fs.h:"Directory entry names and directory paths".  *  * Return SVN_ERR_FS_PATH_SYNTAX if PATH is not valid.  */
name|svn_error_t
modifier|*
name|svn_fs__path_valid
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
comment|/** Editors  *  * ### docco  *  * @defgroup svn_fs_editor Transaction editors  * @{  */
comment|/**  * Create a new filesystem transaction, based on based on the youngest  * revision of @a fs, and return its name @a *txn_name and an @a *editor  * that can be used to make changes into it.  *  * @a flags determines transaction enforcement behaviors, and is composed  * from the constants SVN_FS_TXN_* (#SVN_FS_TXN_CHECK_OOD etc.). It is a  * property of the underlying transaction, and will not change if multiple  * editors are used to refer to that transaction (see @a autocommit, below).  *  * @note If you're building a txn for committing, you probably don't want  * to call this directly.  Instead, call svn_repos__get_commit_ev2(), which  * honors the repository's hook configurations.  *  * When svn_editor_complete() is called for @a editor, internal resources  * will be cleaned and nothing more will happen. If you wish to commit the  * transaction, call svn_fs_editor_commit() instead. It is illegal to call  * both; the second call will return #SVN_ERR_FS_INCORRECT_EDITOR_COMPLETION.  *  * @see svn_fs_commit_txn()  *  * @since New in 1.8.  */
name|svn_error_t
modifier|*
name|svn_fs__editor_create
parameter_list|(
name|svn_editor_t
modifier|*
modifier|*
name|editor
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|txn_name
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_uint32_t
name|flags
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
comment|/**  * Like svn_fs__editor_create(), but open an existing transaction  * @a txn_name and continue editing it.  *  * @since New in 1.8.  */
name|svn_error_t
modifier|*
name|svn_fs__editor_create_for
parameter_list|(
name|svn_editor_t
modifier|*
modifier|*
name|editor
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_name
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
comment|/**  * Commit the transaction represented by @a editor.  *  * If the commit to the filesystem succeeds, then @a *revision will be set  * to the resulting revision number. Note that further errors may occur,  * as described below. If the commit process does not succeed, for whatever  * reason, then @a *revision will be set to #SVN_INVALID_REVNUM.  *  * If a conflict occurs during the commit, then @a *conflict_path will  * be set to a path that caused the conflict. #SVN_NO_ERROR will be returned.  * Callers may want to construct an #SVN_ERR_FS_CONFLICT error with a  * message that incorporates @a *conflict_path.  *  * If a non-conflict error occurs during the commit, then that error will  * be returned.  * As is standard with any Subversion API, @a revision, @a post_commit_err,  * and @a conflict_path (the OUT parameters) have an indeterminate value if  * an error is returned.  *  * If the commit completes (and a revision is returned in @a *revision), then  * it is still possible for an error to occur during the cleanup process.  * Any such error will be returned in @a *post_commit_err. The caller must  * properly use or clear that error.  *  * If svn_editor_complete() has already been called on @a editor, then  * #SVN_ERR_FS_INCORRECT_EDITOR_COMPLETION will be returned.  *  * @note After calling this function, @a editor will be marked as completed  * and no further operations may be performed on it. The underlying  * transaction will either be committed or aborted once this function is  * called. It cannot be recovered for additional work.  *  * @a result_pool will be used to allocate space for @a conflict_path.  * @a scratch_pool will be used for all temporary allocations.  *  * @note To summarize, there are three possible outcomes of this function:  * successful commit (with or without an associated @a *post_commit_err);  * failed commit due to a conflict (reported via @a *conflict_path); and  * failed commit for some other reason (reported via the returned error.)  *  * @since New in 1.8.  */
name|svn_error_t
modifier|*
name|svn_fs__editor_commit
parameter_list|(
name|svn_revnum_t
modifier|*
name|revision
parameter_list|,
name|svn_error_t
modifier|*
modifier|*
name|post_commit_err
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|conflict_path
parameter_list|,
name|svn_editor_t
modifier|*
name|editor
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
comment|/** @} */
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
comment|/* SVN_FS_PRIVATE_H */
end_comment

end_unit

