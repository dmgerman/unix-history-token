begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_THREAD_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|APR_THREAD_MUTEX_H
end_define

begin_comment
comment|/**  * @file apr_thread_mutex.h  * @brief APR Thread Mutex Routines  */
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
if|#
directive|if
name|APR_HAS_THREADS
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * @defgroup apr_thread_mutex Thread Mutex Routines  * @ingroup APR   * @{  */
comment|/** Opaque thread-local mutex structure */
typedef|typedef
name|struct
name|apr_thread_mutex_t
name|apr_thread_mutex_t
typedef|;
define|#
directive|define
name|APR_THREAD_MUTEX_DEFAULT
value|0x0
comment|/**< platform-optimal lock behavior */
define|#
directive|define
name|APR_THREAD_MUTEX_NESTED
value|0x1
comment|/**< enable nested (recursive) locks */
define|#
directive|define
name|APR_THREAD_MUTEX_UNNESTED
value|0x2
comment|/**< disable nested locks */
comment|/* Delayed the include to avoid a circular reference */
include|#
directive|include
file|"apr_pools.h"
comment|/**  * Create and initialize a mutex that can be used to synchronize threads.  * @param mutex the memory address where the newly created mutex will be  *        stored.  * @param flags Or'ed value of:  *<PRE>  *           APR_THREAD_MUTEX_DEFAULT   platform-optimal lock behavior.  *           APR_THREAD_MUTEX_NESTED    enable nested (recursive) locks.  *           APR_THREAD_MUTEX_UNNESTED  disable nested locks (non-recursive).  *</PRE>  * @param pool the pool from which to allocate the mutex.  * @warning Be cautious in using APR_THREAD_MUTEX_DEFAULT.  While this is the  * most optimal mutex based on a given platform's performance characteristics,  * it will behave as either a nested or an unnested lock.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_mutex_create
argument_list|(
argument|apr_thread_mutex_t **mutex
argument_list|,
argument|unsigned int flags
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Acquire the lock for the given mutex. If the mutex is already locked,  * the current thread will be put to sleep until the lock becomes available.  * @param mutex the mutex on which to acquire the lock.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_mutex_lock
argument_list|(
name|apr_thread_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Attempt to acquire the lock for the given mutex. If the mutex has already  * been acquired, the call returns immediately with APR_EBUSY. Note: it  * is important that the APR_STATUS_IS_EBUSY(s) macro be used to determine  * if the return value was APR_EBUSY, for portability reasons.  * @param mutex the mutex on which to attempt the lock acquiring.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_mutex_trylock
argument_list|(
name|apr_thread_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Release the lock for the given mutex.  * @param mutex the mutex from which to release the lock.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_mutex_unlock
argument_list|(
name|apr_thread_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Destroy the mutex and free the memory associated with the lock.  * @param mutex the mutex to destroy.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_mutex_destroy
argument_list|(
name|apr_thread_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Get the pool used by this thread_mutex.  * @return apr_pool_t the pool  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|thread_mutex
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
comment|/* ! APR_THREAD_MUTEX_H */
end_comment

end_unit

