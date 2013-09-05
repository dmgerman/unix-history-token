begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_pools.h  * @brief APR pool management for Subversion  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_POOLS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_POOLS_H
end_define

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* Wrappers around APR pools, so we get debugging. */
comment|/** The recommended maximum amount of memory (4MB) to keep in an APR  * allocator on the free list, conveniently defined here to share  * between all our applications.  */
define|#
directive|define
name|SVN_ALLOCATOR_RECOMMENDED_MAX_FREE
value|(4096 * 1024)
comment|/** Wrapper around apr_pool_create_ex(), with a simpler interface.  * The return pool will have an abort function set, which will call  * abort() on OOM.  */
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
function_decl|;
ifndef|#
directive|ifndef
name|DOXYGEN_SHOULD_SKIP_THIS
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
function_decl|;
if|#
directive|if
name|APR_POOL_DEBUG
define|#
directive|define
name|svn_pool_create_ex
parameter_list|(
name|pool
parameter_list|,
name|allocator
parameter_list|)
define|\
value|svn_pool_create_ex_debug(pool, allocator, APR_POOL__FILE_LINE__)
endif|#
directive|endif
comment|/* APR_POOL_DEBUG */
endif|#
directive|endif
comment|/* DOXYGEN_SHOULD_SKIP_THIS */
comment|/** Create a pool as a subpool of @a parent_pool */
define|#
directive|define
name|svn_pool_create
parameter_list|(
name|parent_pool
parameter_list|)
value|svn_pool_create_ex(parent_pool, NULL)
comment|/** Clear a @a pool destroying its children.  *  * This define for @c svn_pool_clear exists for completeness.  */
define|#
directive|define
name|svn_pool_clear
value|apr_pool_clear
comment|/** Destroy a @a pool and all of its children.  *  * This define for @c svn_pool_destroy exists for symmetry and  * completeness.  */
define|#
directive|define
name|svn_pool_destroy
value|apr_pool_destroy
comment|/** Return a new allocator.  This function limits the unused memory in the  * new allocator to #SVN_ALLOCATOR_RECOMMENDED_MAX_FREE and ensures  * proper synchronization if the allocator is used by multiple threads.  *  * If your application uses multiple threads, creating a separate  * allocator for each of these threads may not be feasible.  Set the  * @a thread_safe parameter to @c TRUE in that case; otherwise, set @a  * thread_safe to @c FALSE to maximize performance.  *  * @note Even if @a thread_safe is @c TRUE, pools themselves will  * still not be thread-safe and their access may require explicit  * serialization.  *  * To access the owner pool, which can also serve as the root pool for  * your sub-pools, call @c apr_allocator_get_owner().  *  * @since: New in 1.8  */
name|apr_allocator_t
modifier|*
name|svn_pool_create_allocator
parameter_list|(
name|svn_boolean_t
name|thread_safe
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
comment|/* SVN_POOLS_H */
end_comment

end_unit

