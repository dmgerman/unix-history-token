begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_THREAD_RWLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|APR_THREAD_RWLOCK_H
end_define

begin_comment
comment|/**  * @file apr_thread_rwlock.h  * @brief APR Reader/Writer Lock Routines  */
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
comment|/**  * @defgroup apr_thread_rwlock Reader/Writer Lock Routines  * @ingroup APR   * @{  */
comment|/** Opaque read-write thread-safe lock. */
typedef|typedef
name|struct
name|apr_thread_rwlock_t
name|apr_thread_rwlock_t
typedef|;
comment|/**  * Note: The following operations have undefined results: unlocking a  * read-write lock which is not locked in the calling thread; write  * locking a read-write lock which is already locked by the calling  * thread; destroying a read-write lock more than once; clearing or  * destroying the pool from which a<b>locked</b> read-write lock is  * allocated.  */
comment|/**  * Create and initialize a read-write lock that can be used to synchronize  * threads.  * @param rwlock the memory address where the newly created readwrite lock  *        will be stored.  * @param pool the pool from which to allocate the mutex.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_create
argument_list|(
name|apr_thread_rwlock_t
operator|*
operator|*
name|rwlock
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Acquire a shared-read lock on the given read-write lock. This will allow  * multiple threads to enter the same critical section while they have acquired  * the read lock.  * @param rwlock the read-write lock on which to acquire the shared read.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_rdlock
argument_list|(
name|apr_thread_rwlock_t
operator|*
name|rwlock
argument_list|)
expr_stmt|;
comment|/**  * Attempt to acquire the shared-read lock on the given read-write lock. This  * is the same as apr_thread_rwlock_rdlock(), only that the function fails  * if there is another thread holding the write lock, or if there are any  * write threads blocking on the lock. If the function fails for this case,  * APR_EBUSY will be returned. Note: it is important that the  * APR_STATUS_IS_EBUSY(s) macro be used to determine if the return value was  * APR_EBUSY, for portability reasons.  * @param rwlock the rwlock on which to attempt the shared read.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_tryrdlock
argument_list|(
name|apr_thread_rwlock_t
operator|*
name|rwlock
argument_list|)
expr_stmt|;
comment|/**  * Acquire an exclusive-write lock on the given read-write lock. This will  * allow only one single thread to enter the critical sections. If there  * are any threads currently holding the read-lock, this thread is put to  * sleep until it can have exclusive access to the lock.  * @param rwlock the read-write lock on which to acquire the exclusive write.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_wrlock
argument_list|(
name|apr_thread_rwlock_t
operator|*
name|rwlock
argument_list|)
expr_stmt|;
comment|/**  * Attempt to acquire the exclusive-write lock on the given read-write lock.   * This is the same as apr_thread_rwlock_wrlock(), only that the function fails  * if there is any other thread holding the lock (for reading or writing),  * in which case the function will return APR_EBUSY. Note: it is important  * that the APR_STATUS_IS_EBUSY(s) macro be used to determine if the return  * value was APR_EBUSY, for portability reasons.  * @param rwlock the rwlock on which to attempt the exclusive write.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_trywrlock
argument_list|(
name|apr_thread_rwlock_t
operator|*
name|rwlock
argument_list|)
expr_stmt|;
comment|/**  * Release either the read or write lock currently held by the calling thread  * associated with the given read-write lock.  * @param rwlock the read-write lock to be released (unlocked).  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_unlock
argument_list|(
name|apr_thread_rwlock_t
operator|*
name|rwlock
argument_list|)
expr_stmt|;
comment|/**  * Destroy the read-write lock and free the associated memory.  * @param rwlock the rwlock to destroy.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_rwlock_destroy
argument_list|(
name|apr_thread_rwlock_t
operator|*
name|rwlock
argument_list|)
expr_stmt|;
comment|/**  * Get the pool used by this thread_rwlock.  * @return apr_pool_t the pool  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|thread_rwlock
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
comment|/* ! APR_THREAD_RWLOCK_H */
end_comment

end_unit

