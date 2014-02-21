begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lock-tokens-table.h : internal interface to ops on `lock-tokens' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_LOCK_TOKENS_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_LOCK_TOKENS_TABLE_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"../trail.h"
end_include

begin_include
include|#
directive|include
file|"../fs.h"
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
comment|/* Open a `lock-tokens' table in ENV.  If CREATE is non-zero, create    one if it doesn't exist.  Set *LOCK_TOKENS_P to the new table.    Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_lock_tokens_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|locks_tokens_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Add a lock-token to the `lock-tokens' table in FS, as part of TRAIL.    Use PATH as the key and LOCK_TOKEN as the value.     Warning: if PATH already exists as a key, then its value will be    overwritten. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__lock_token_add
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
specifier|const
name|char
modifier|*
name|lock_token
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Remove the lock-token whose key is PATH from the `lock-tokens'    table of FS, as part of TRAIL.     If PATH doesn't exist as a key, return SVN_ERR_FS_NO_SUCH_LOCK. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__lock_token_delete
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
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Retrieve the lock-token *LOCK_TOKEN_P pointed to by PATH from the    `lock-tokens' table of FS, as part of TRAIL.  Perform all    allocations in POOL.     If PATH doesn't exist as a key, return SVN_ERR_FS_NO_SUCH_LOCK.     If PATH points to a token which points to an expired lock, return      SVN_ERR_FS_LOCK_EXPIRED.  (After this, both the token and lock are      gone from their respective tables.)     If PATH points to a token which points to a non-existent lock,      return SVN_ERR_FS_BAD_LOCK_TOKEN.  (After this, the token is also      removed from the `lock-tokens' table.)  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__lock_token_get
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|lock_token_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|trail_t
modifier|*
name|trail
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
comment|/* SVN_LIBSVN_FS_LOCK_TOKENS_TABLE_H */
end_comment

end_unit

