begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ra_local.h : shared internal declarations for ra_local module  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_RA_LOCAL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_RA_LOCAL_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"svn_repos.h"
end_include

begin_include
include|#
directive|include
file|"svn_ra.h"
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
comment|/** Structures **/
comment|/* A baton which represents a single ra_local session. */
typedef|typedef
struct|struct
name|svn_ra_local__session_baton_t
block|{
comment|/* The user accessing the repository. */
specifier|const
name|char
modifier|*
name|username
decl_stmt|;
comment|/* The URL of the session, split into two components. */
specifier|const
name|char
modifier|*
name|repos_url
decl_stmt|;
name|svn_stringbuf_t
modifier|*
name|fs_path
decl_stmt|;
comment|/* URI-decoded, always with a leading slash. */
comment|/* A repository object. */
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
comment|/* The filesystem object associated with REPOS above (for      convenience). */
name|svn_fs_t
modifier|*
name|fs
decl_stmt|;
comment|/* The UUID associated with REPOS above (cached) */
specifier|const
name|char
modifier|*
name|uuid
decl_stmt|;
comment|/* Callbacks/baton passed to svn_ra_open. */
specifier|const
name|svn_ra_callbacks2_t
modifier|*
name|callbacks
decl_stmt|;
name|void
modifier|*
name|callback_baton
decl_stmt|;
block|}
name|svn_ra_local__session_baton_t
typedef|;
comment|/** Private routines **/
comment|/* Given a `file://' URL, figure out which portion specifies a    repository on local disk, and return that in REPOS_URL (if not    NULL); URI-decode and return the remainder (the path *within* the    repository's filesystem) in FS_PATH.  Open REPOS to the repository    root (if not NULL).  Allocate the return values in POOL.    Currently, we are not expecting to handle `file://hostname/'-type    URLs; hostname, in this case, is expected to be the empty string or    "localhost". */
name|svn_error_t
modifier|*
name|svn_ra_local__split_URL
parameter_list|(
name|svn_repos_t
modifier|*
modifier|*
name|repos
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|repos_url
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|fs_path
parameter_list|,
specifier|const
name|char
modifier|*
name|URL
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
comment|/* SVN_LIBSVN_RA_LOCAL_H */
end_comment

end_unit

