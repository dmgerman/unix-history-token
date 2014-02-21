begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_THREAD_COND_H
end_ifndef

begin_define
define|#
directive|define
name|APR_THREAD_COND_H
end_define

begin_comment
comment|/**  * @file apr_thread_cond.h  * @brief APR Condition Variable Routines  */
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
file|"apr_time.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
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
comment|/**  * @defgroup apr_thread_cond Condition Variable Routines  * @ingroup APR   * @{  */
comment|/** Opaque structure for thread condition variables */
typedef|typedef
name|struct
name|apr_thread_cond_t
name|apr_thread_cond_t
typedef|;
comment|/**  * Note: destroying a condition variable (or likewise, destroying or  * clearing the pool from which a condition variable was allocated) if  * any threads are blocked waiting on it gives undefined results.  */
comment|/**  * Create and initialize a condition variable that can be used to signal  * and schedule threads in a single process.  * @param cond the memory address where the newly created condition variable  *        will be stored.  * @param pool the pool from which to allocate the condition.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_cond_create
argument_list|(
name|apr_thread_cond_t
operator|*
operator|*
name|cond
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Put the active calling thread to sleep until signaled to wake up. Each  * condition variable must be associated with a mutex, and that mutex must  * be locked before  calling this function, or the behavior will be  * undefined. As the calling thread is put to sleep, the given mutex  * will be simultaneously released; and as this thread wakes up the lock  * is again simultaneously acquired.  * @param cond the condition variable on which to block.  * @param mutex the mutex that must be locked upon entering this function,  *        is released while the thread is asleep, and is again acquired before  *        returning from this function.  * @remark Spurious wakeups may occur. Before and after every call to wait on  * a condition variable, the caller should test whether the condition is already  * met.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_cond_wait
argument_list|(
name|apr_thread_cond_t
operator|*
name|cond
argument_list|,
name|apr_thread_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Put the active calling thread to sleep until signaled to wake up or  * the timeout is reached. Each condition variable must be associated  * with a mutex, and that mutex must be locked before calling this  * function, or the behavior will be undefined. As the calling thread  * is put to sleep, the given mutex will be simultaneously released;  * and as this thread wakes up the lock is again simultaneously acquired.  * @param cond the condition variable on which to block.  * @param mutex the mutex that must be locked upon entering this function,  *        is released while the thread is asleep, and is again acquired before  *        returning from this function.  * @param timeout The amount of time in microseconds to wait. This is   *        a maximum, not a minimum. If the condition is signaled, we   *        will wake up before this time, otherwise the error APR_TIMEUP  *        is returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_cond_timedwait
argument_list|(
argument|apr_thread_cond_t *cond
argument_list|,
argument|apr_thread_mutex_t *mutex
argument_list|,
argument|apr_interval_time_t timeout
argument_list|)
empty_stmt|;
comment|/**  * Signals a single thread, if one exists, that is blocking on the given  * condition variable. That thread is then scheduled to wake up and acquire  * the associated mutex. Although it is not required, if predictable scheduling  * is desired, that mutex must be locked while calling this function.  * @param cond the condition variable on which to produce the signal.  * @remark If no threads are waiting on the condition variable, nothing happens.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_cond_signal
argument_list|(
name|apr_thread_cond_t
operator|*
name|cond
argument_list|)
expr_stmt|;
comment|/**  * Signals all threads blocking on the given condition variable.  * Each thread that was signaled is then scheduled to wake up and acquire  * the associated mutex. This will happen in a serialized manner.  * @param cond the condition variable on which to produce the broadcast.  * @remark If no threads are waiting on the condition variable, nothing happens.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_cond_broadcast
argument_list|(
name|apr_thread_cond_t
operator|*
name|cond
argument_list|)
expr_stmt|;
comment|/**  * Destroy the condition variable and free the associated memory.  * @param cond the condition variable to destroy.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_cond_destroy
argument_list|(
name|apr_thread_cond_t
operator|*
name|cond
argument_list|)
expr_stmt|;
comment|/**  * Get the pool used by this thread_cond.  * @return apr_pool_t the pool  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|thread_cond
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
comment|/* ! APR_THREAD_COND_H */
end_comment

end_unit

