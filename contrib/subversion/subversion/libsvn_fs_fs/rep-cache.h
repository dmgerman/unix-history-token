begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rep-cache.h : interface to rep cache db functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_FS_REP_CACHE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_FS_REP_CACHE_H
end_define

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
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
define|#
directive|define
name|REP_CACHE_DB_NAME
value|"rep-cache.db"
comment|/* Open and create, if needed, the rep cache database associated with FS.    Use POOL for temporary allocations. */
name|svn_error_t
modifier|*
name|svn_fs_fs__open_rep_cache
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set *EXISTS to TRUE iff the rep-cache DB file exists. */
name|svn_error_t
modifier|*
name|svn_fs_fs__exists_rep_cache
parameter_list|(
name|svn_boolean_t
modifier|*
name|exists
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Iterate all representations currently in FS's cache. */
name|svn_error_t
modifier|*
name|svn_fs_fs__walk_rep_reference
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|start
parameter_list|,
name|svn_revnum_t
name|end
parameter_list|,
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|walker
function_decl|)
parameter_list|(
name|representation_t
modifier|*
name|rep
parameter_list|,
name|void
modifier|*
name|walker_baton
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
parameter_list|,
name|void
modifier|*
name|walker_baton
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
name|pool
parameter_list|)
function_decl|;
comment|/* Return the representation REP in FS which has fulltext CHECKSUM.    REP is allocated in POOL.  If the rep cache database has not been    opened, just set *REP to NULL. */
name|svn_error_t
modifier|*
name|svn_fs_fs__get_rep_reference
parameter_list|(
name|representation_t
modifier|*
modifier|*
name|rep
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set the representation REP in FS, using REP->CHECKSUM.    Use POOL for temporary allocations.     If the rep cache database has not been opened, this may be a no op.     If REJECT_DUP is TRUE, return an error if there is an existing    match for REP->CHECKSUM. */
name|svn_error_t
modifier|*
name|svn_fs_fs__set_rep_reference
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|representation_t
modifier|*
name|rep
parameter_list|,
name|svn_boolean_t
name|reject_dup
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Delete from the cache all reps corresponding to revisions younger    than YOUNGEST. */
name|svn_error_t
modifier|*
name|svn_fs_fs__del_rep_reference
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|youngest
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Start a transaction to take an SQLite reserved lock that prevents    other writes. */
name|svn_error_t
modifier|*
name|svn_fs_fs__lock_rep_cache
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
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
comment|/* SVN_LIBSVN_FS_FS_REP_CACHE_H */
end_comment

end_unit

