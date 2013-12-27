begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_RMM_H
end_ifndef

begin_define
define|#
directive|define
name|APR_RMM_H
end_define

begin_comment
comment|/**   * @file apr_rmm.h  * @brief APR-UTIL Relocatable Memory Management Routines  */
end_comment

begin_comment
comment|/**  * @defgroup APR_Util_RMM Relocatable Memory Management Routines  * @ingroup APR_Util  * @{  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_anylock.h"
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
comment|/** Structure to access Relocatable, Managed Memory */
typedef|typedef
name|struct
name|apr_rmm_t
name|apr_rmm_t
typedef|;
comment|/** Fundamental allocation unit, within a specific apr_rmm_t */
typedef|typedef
name|apr_size_t
name|apr_rmm_off_t
typedef|;
comment|/**  * Initialize a relocatable memory block to be managed by the apr_rmm API.  * @param rmm The relocatable memory block  * @param lock An apr_anylock_t of the appropriate type of lock, or NULL  *             if no locking is required.  * @param membuf The block of relocatable memory to be managed  * @param memsize The size of relocatable memory block to be managed  * @param cont The pool to use for local storage and management  * @remark Both @param membuf and @param memsize must be aligned  * (for instance using APR_ALIGN_DEFAULT).  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_rmm_init
argument_list|(
argument|apr_rmm_t **rmm
argument_list|,
argument|apr_anylock_t *lock
argument_list|,
argument|void *membuf
argument_list|,
argument|apr_size_t memsize
argument_list|,
argument|apr_pool_t *cont
argument_list|)
empty_stmt|;
comment|/**  * Destroy a managed memory block.  * @param rmm The relocatable memory block to destroy  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_rmm_destroy
argument_list|(
name|apr_rmm_t
operator|*
name|rmm
argument_list|)
expr_stmt|;
comment|/**  * Attach to a relocatable memory block already managed by the apr_rmm API.  * @param rmm The relocatable memory block  * @param lock An apr_anylock_t of the appropriate type of lock  * @param membuf The block of relocatable memory already under management  * @param cont The pool to use for local storage and management  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_rmm_attach
argument_list|(
name|apr_rmm_t
operator|*
operator|*
name|rmm
argument_list|,
name|apr_anylock_t
operator|*
name|lock
argument_list|,
name|void
operator|*
name|membuf
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Detach from the managed block of memory.  * @param rmm The relocatable memory block to detach from  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_rmm_detach
argument_list|(
name|apr_rmm_t
operator|*
name|rmm
argument_list|)
expr_stmt|;
comment|/**  * Allocate memory from the block of relocatable memory.  * @param rmm The relocatable memory block  * @param reqsize How much memory to allocate  */
name|APU_DECLARE
argument_list|(
argument|apr_rmm_off_t
argument_list|)
name|apr_rmm_malloc
argument_list|(
argument|apr_rmm_t *rmm
argument_list|,
argument|apr_size_t reqsize
argument_list|)
empty_stmt|;
comment|/**  * Realloc memory from the block of relocatable memory.  * @param rmm The relocatable memory block  * @param entity The memory allocation to realloc  * @param reqsize The new size  */
name|APU_DECLARE
argument_list|(
argument|apr_rmm_off_t
argument_list|)
name|apr_rmm_realloc
argument_list|(
argument|apr_rmm_t *rmm
argument_list|,
argument|void *entity
argument_list|,
argument|apr_size_t reqsize
argument_list|)
empty_stmt|;
comment|/**  * Allocate memory from the block of relocatable memory and initialize it to zero.  * @param rmm The relocatable memory block  * @param reqsize How much memory to allocate  */
name|APU_DECLARE
argument_list|(
argument|apr_rmm_off_t
argument_list|)
name|apr_rmm_calloc
argument_list|(
argument|apr_rmm_t *rmm
argument_list|,
argument|apr_size_t reqsize
argument_list|)
empty_stmt|;
comment|/**  * Free allocation returned by apr_rmm_malloc or apr_rmm_calloc.  * @param rmm The relocatable memory block  * @param entity The memory allocation to free  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_rmm_free
argument_list|(
argument|apr_rmm_t *rmm
argument_list|,
argument|apr_rmm_off_t entity
argument_list|)
empty_stmt|;
comment|/**  * Retrieve the physical address of a relocatable allocation of memory  * @param rmm The relocatable memory block  * @param entity The memory allocation to free  * @return address The address, aligned with APR_ALIGN_DEFAULT.  */
name|APU_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_rmm_addr_get
argument_list|(
argument|apr_rmm_t *rmm
argument_list|,
argument|apr_rmm_off_t entity
argument_list|)
empty_stmt|;
comment|/**  * Compute the offset of a relocatable allocation of memory  * @param rmm The relocatable memory block  * @param entity The physical address to convert to an offset  */
name|APU_DECLARE
argument_list|(
argument|apr_rmm_off_t
argument_list|)
name|apr_rmm_offset_get
argument_list|(
name|apr_rmm_t
operator|*
name|rmm
argument_list|,
name|void
operator|*
name|entity
argument_list|)
expr_stmt|;
comment|/**  * Compute the required overallocation of memory needed to fit n allocs  * @param n The number of alloc/calloc regions desired  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_rmm_overhead_get
argument_list|(
argument|int n
argument_list|)
empty_stmt|;
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
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_RMM_H */
end_comment

end_unit

