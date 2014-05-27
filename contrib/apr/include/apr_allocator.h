begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ALLOCATOR_H
end_define

begin_comment
comment|/**  * @file apr_allocator.h  * @brief APR Internal Memory Allocation  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_define
define|#
directive|define
name|APR_WANT_MEMFUNC
end_define

begin_comment
comment|/**< For no good reason? */
end_comment

begin_include
include|#
directive|include
file|"apr_want.h"
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
comment|/**  * @defgroup apr_allocator Internal Memory Allocation  * @ingroup APR   * @{  */
comment|/** the allocator structure */
typedef|typedef
name|struct
name|apr_allocator_t
name|apr_allocator_t
typedef|;
comment|/** the structure which holds information about the allocation */
typedef|typedef
name|struct
name|apr_memnode_t
name|apr_memnode_t
typedef|;
comment|/** basic memory node structure  * @note The next, ref and first_avail fields are available for use by the  *       caller of apr_allocator_alloc(), the remaining fields are read-only.  *       The next field has to be used with caution and sensibly set when the  *       memnode is passed back to apr_allocator_free().  See apr_allocator_free()  *       for details.    *       The ref and first_avail fields will be properly restored by  *       apr_allocator_free().  */
struct|struct
name|apr_memnode_t
block|{
name|apr_memnode_t
modifier|*
name|next
decl_stmt|;
comment|/**< next memnode */
name|apr_memnode_t
modifier|*
modifier|*
name|ref
decl_stmt|;
comment|/**< reference to self */
name|apr_uint32_t
name|index
decl_stmt|;
comment|/**< size */
name|apr_uint32_t
name|free_index
decl_stmt|;
comment|/**< how much free */
name|char
modifier|*
name|first_avail
decl_stmt|;
comment|/**< pointer to first free memory */
name|char
modifier|*
name|endp
decl_stmt|;
comment|/**< pointer to end of free memory */
block|}
struct|;
comment|/** The base size of a memory node - aligned.  */
define|#
directive|define
name|APR_MEMNODE_T_SIZE
value|APR_ALIGN_DEFAULT(sizeof(apr_memnode_t))
comment|/** Symbolic constants */
define|#
directive|define
name|APR_ALLOCATOR_MAX_FREE_UNLIMITED
value|0
comment|/**  * Create a new allocator  * @param allocator The allocator we have just created.  *  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_allocator_create
argument_list|(
argument|apr_allocator_t **allocator
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Destroy an allocator  * @param allocator The allocator to be destroyed  * @remark Any memnodes not given back to the allocator prior to destroying  *         will _not_ be free()d.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_allocator_destroy
argument_list|(
argument|apr_allocator_t *allocator
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Allocate a block of mem from the allocator  * @param allocator The allocator to allocate from  * @param size The size of the mem to allocate (excluding the  *        memnode structure)  */
name|APR_DECLARE
argument_list|(
argument|apr_memnode_t *
argument_list|)
name|apr_allocator_alloc
argument_list|(
argument|apr_allocator_t *allocator
argument_list|,
argument|apr_size_t size
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Free a list of blocks of mem, giving them back to the allocator.  * The list is typically terminated by a memnode with its next field  * set to NULL.  * @param allocator The allocator to give the mem back to  * @param memnode The memory node to return  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_allocator_free
argument_list|(
argument|apr_allocator_t *allocator
argument_list|,
argument|apr_memnode_t *memnode
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
expr_stmt|;
include|#
directive|include
file|"apr_pools.h"
comment|/**  * Set the owner of the allocator  * @param allocator The allocator to set the owner for  * @param pool The pool that is to own the allocator  * @remark Typically pool is the highest level pool using the allocator  */
comment|/*  * XXX: see if we can come up with something a bit better.  Currently  * you can make a pool an owner, but if the pool doesn't use the allocator  * the allocator will never be destroyed.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_allocator_owner_set
argument_list|(
argument|apr_allocator_t *allocator
argument_list|,
argument|apr_pool_t *pool
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Get the current owner of the allocator  * @param allocator The allocator to get the owner from  */
name|APR_DECLARE
argument_list|(
argument|apr_pool_t *
argument_list|)
name|apr_allocator_owner_get
argument_list|(
argument|apr_allocator_t *allocator
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Set the current threshold at which the allocator should start  * giving blocks back to the system.  * @param allocator The allocator to set the threshold on  * @param size The threshold.  0 == unlimited.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_allocator_max_free_set
argument_list|(
argument|apr_allocator_t *allocator
argument_list|,
argument|apr_size_t size
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
include|#
directive|include
file|"apr_thread_mutex.h"
if|#
directive|if
name|APR_HAS_THREADS
comment|/**  * Set a mutex for the allocator to use  * @param allocator The allocator to set the mutex for  * @param mutex The mutex  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_allocator_mutex_set
argument_list|(
argument|apr_allocator_t *allocator
argument_list|,
argument|apr_thread_mutex_t *mutex
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Get the mutex currently set for the allocator  * @param allocator The allocator  */
name|APR_DECLARE
argument_list|(
argument|apr_thread_mutex_t *
argument_list|)
name|apr_allocator_mutex_get
argument_list|(
argument|apr_allocator_t *allocator
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_THREADS */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APR_ALLOCATOR_H */
end_comment

end_unit

