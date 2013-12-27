begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pool.c:  pool wrappers for Subversion  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<apr_general.h>
end_include

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_thread_mutex.h>
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_if
if|#
directive|if
name|APR_POOL_DEBUG
end_if

begin_comment
comment|/* file_line for the non-debug case. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
name|SVN_FILE_LINE_UNDEFINED
index|[]
init|=
literal|"svn:<undefined>"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_POOL_DEBUG */
end_comment

begin_escape
end_escape

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Pool allocation handler which just aborts, since we aren't generally    prepared to deal with out-of-memory errors.  */
end_comment

begin_function
specifier|static
name|int
name|abort_on_pool_failure
parameter_list|(
name|int
name|retcode
parameter_list|)
block|{
comment|/* Don't translate this string! It requires memory allocation to do so!      And we don't have any of it... */
name|printf
argument_list|(
literal|"Out of memory - terminating application.\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
comment|/* not reached */
block|}
end_function

begin_if
if|#
directive|if
name|APR_POOL_DEBUG
end_if

begin_undef
undef|#
directive|undef
name|svn_pool_create_ex
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_POOL_DEBUG */
end_comment

begin_if
if|#
directive|if
operator|!
name|APR_POOL_DEBUG
end_if

begin_function
name|apr_pool_t
modifier|*
name|svn_pool_create_ex
parameter_list|(
name|apr_pool_t
modifier|*
name|parent_pool
parameter_list|,
name|apr_allocator_t
modifier|*
name|allocator
parameter_list|)
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_pool_create_ex
argument_list|(
operator|&
name|pool
argument_list|,
name|parent_pool
argument_list|,
name|abort_on_pool_failure
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
return|return
name|pool
return|;
block|}
end_function

begin_comment
comment|/* Wrapper that ensures binary compatibility */
end_comment

begin_function
name|apr_pool_t
modifier|*
name|svn_pool_create_ex_debug
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
name|apr_allocator_t
modifier|*
name|allocator
parameter_list|,
specifier|const
name|char
modifier|*
name|file_line
parameter_list|)
block|{
return|return
name|svn_pool_create_ex
argument_list|(
name|pool
argument_list|,
name|allocator
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* APR_POOL_DEBUG */
end_comment

begin_function
name|apr_pool_t
modifier|*
name|svn_pool_create_ex_debug
parameter_list|(
name|apr_pool_t
modifier|*
name|parent_pool
parameter_list|,
name|apr_allocator_t
modifier|*
name|allocator
parameter_list|,
specifier|const
name|char
modifier|*
name|file_line
parameter_list|)
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_pool_create_ex_debug
argument_list|(
operator|&
name|pool
argument_list|,
name|parent_pool
argument_list|,
name|abort_on_pool_failure
argument_list|,
name|allocator
argument_list|,
name|file_line
argument_list|)
expr_stmt|;
return|return
name|pool
return|;
block|}
end_function

begin_comment
comment|/* Wrapper that ensures binary compatibility */
end_comment

begin_function
name|apr_pool_t
modifier|*
name|svn_pool_create_ex
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
name|apr_allocator_t
modifier|*
name|allocator
parameter_list|)
block|{
return|return
name|svn_pool_create_ex_debug
argument_list|(
name|pool
argument_list|,
name|allocator
argument_list|,
name|SVN_FILE_LINE_UNDEFINED
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_POOL_DEBUG */
end_comment

begin_function
name|apr_allocator_t
modifier|*
name|svn_pool_create_allocator
parameter_list|(
name|svn_boolean_t
name|thread_safe
parameter_list|)
block|{
name|apr_allocator_t
modifier|*
name|allocator
decl_stmt|;
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/* create the allocator and limit it's internal free list to keep    * memory usage in check */
if|if
condition|(
name|apr_allocator_create
argument_list|(
operator|&
name|allocator
argument_list|)
condition|)
name|abort_on_pool_failure
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
name|apr_allocator_max_free_set
argument_list|(
name|allocator
argument_list|,
name|SVN_ALLOCATOR_RECOMMENDED_MAX_FREE
argument_list|)
expr_stmt|;
comment|/* create the root pool */
name|pool
operator|=
name|svn_pool_create_ex
argument_list|(
name|NULL
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
name|apr_allocator_owner_set
argument_list|(
name|allocator
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_POOL_DEBUG
name|apr_pool_tag
argument_list|(
name|pool
argument_list|,
literal|"svn root pool"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* By default, allocators are *not* thread-safe. We must provide a mutex    * if we want thread-safety for that mutex. */
if|#
directive|if
name|APR_HAS_THREADS
if|if
condition|(
name|thread_safe
condition|)
block|{
name|apr_thread_mutex_t
modifier|*
name|mutex
decl_stmt|;
name|apr_thread_mutex_create
argument_list|(
operator|&
name|mutex
argument_list|,
name|APR_THREAD_MUTEX_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|apr_allocator_mutex_set
argument_list|(
name|allocator
argument_list|,
name|mutex
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* better safe than sorry */
name|SVN_ERR_ASSERT_NO_RETURN
argument_list|(
name|allocator
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|allocator
return|;
block|}
end_function

end_unit

