begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|<apr_thread_mutex.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|"svn_hash.h"
end_include

begin_include
include|#
directive|include
file|"svn_dso.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_mutex.h"
end_include

begin_comment
comment|/* A mutex to protect our global pool and cache. */
end_comment

begin_decl_stmt
specifier|static
name|svn_mutex__t
modifier|*
name|dso_mutex
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global pool to allocate DSOs in. */
end_comment

begin_decl_stmt
specifier|static
name|apr_pool_t
modifier|*
name|dso_pool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global cache for storing DSO objects. */
end_comment

begin_decl_stmt
specifier|static
name|apr_hash_t
modifier|*
name|dso_cache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Just an arbitrary location in memory... */
end_comment

begin_decl_stmt
specifier|static
name|int
name|not_there_sentinel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A specific value we store in the dso_cache to indicate that the    library wasn't found.  This keeps us from allocating extra memory    from dso_pool when trying to find libraries we already know aren't    there.  */
end_comment

begin_define
define|#
directive|define
name|NOT_THERE
value|((void *)&not_there_sentinel)
end_define

begin_function
name|svn_error_t
modifier|*
name|svn_dso_initialize2
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|dso_pool
condition|)
return|return
name|SVN_NO_ERROR
return|;
name|dso_pool
operator|=
name|svn_pool_create
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_mutex__init
argument_list|(
operator|&
name|dso_mutex
argument_list|,
name|TRUE
argument_list|,
name|dso_pool
argument_list|)
argument_list|)
expr_stmt|;
name|dso_cache
operator|=
name|apr_hash_make
argument_list|(
name|dso_pool
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_if
if|#
directive|if
name|APR_HAS_DSO
end_if

begin_function
specifier|static
name|svn_error_t
modifier|*
name|svn_dso_load_internal
parameter_list|(
name|apr_dso_handle_t
modifier|*
modifier|*
name|dso
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
operator|*
name|dso
operator|=
name|svn_hash_gets
argument_list|(
name|dso_cache
argument_list|,
name|fname
argument_list|)
expr_stmt|;
comment|/* First check to see if we've been through this before...  We do this      to avoid calling apr_dso_load multiple times for a given library,      which would result in wasting small amounts of memory each time. */
if|if
condition|(
operator|*
name|dso
operator|==
name|NOT_THERE
condition|)
block|{
operator|*
name|dso
operator|=
name|NULL
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
comment|/* If we got nothing back from the cache, try and load the library. */
if|if
condition|(
operator|!
operator|*
name|dso
condition|)
block|{
name|apr_status_t
name|status
init|=
name|apr_dso_load
argument_list|(
name|dso
argument_list|,
name|fname
argument_list|,
name|dso_pool
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
condition|)
block|{
ifdef|#
directive|ifdef
name|SVN_DEBUG_DSO
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Dynamic loading of '%s' failed with the following error:\n%s\n"
argument_list|,
name|fname
argument_list|,
name|apr_dso_error
argument_list|(
operator|*
name|dso
argument_list|,
name|buf
argument_list|,
literal|1024
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|*
name|dso
operator|=
name|NULL
expr_stmt|;
comment|/* It wasn't found, so set the special "we didn't find it" value. */
name|svn_hash_sets
argument_list|(
name|dso_cache
argument_list|,
name|apr_pstrdup
argument_list|(
name|dso_pool
argument_list|,
name|fname
argument_list|)
argument_list|,
name|NOT_THERE
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
comment|/* Stash the dso so we can use it next time. */
name|svn_hash_sets
argument_list|(
name|dso_cache
argument_list|,
name|apr_pstrdup
argument_list|(
name|dso_pool
argument_list|,
name|fname
argument_list|)
argument_list|,
operator|*
name|dso
argument_list|)
expr_stmt|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_dso_load
parameter_list|(
name|apr_dso_handle_t
modifier|*
modifier|*
name|dso
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
if|if
condition|(
operator|!
name|dso_pool
condition|)
name|SVN_ERR
argument_list|(
name|svn_dso_initialize2
argument_list|()
argument_list|)
expr_stmt|;
name|SVN_MUTEX__WITH_LOCK
argument_list|(
name|dso_mutex
argument_list|,
name|svn_dso_load_internal
argument_list|(
name|dso
argument_list|,
name|fname
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_DSO */
end_comment

end_unit

