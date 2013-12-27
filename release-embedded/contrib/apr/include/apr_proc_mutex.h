begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_PROC_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|APR_PROC_MUTEX_H
end_define

begin_comment
comment|/**  * @file apr_proc_mutex.h  * @brief APR Process Locking Routines  */
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
comment|/**  * @defgroup apr_proc_mutex Process Locking Routines  * @ingroup APR   * @{  */
comment|/**   * Enumerated potential types for APR process locking methods  * @warning Check APR_HAS_foo_SERIALIZE defines to see if the platform supports  *          APR_LOCK_foo.  Only APR_LOCK_DEFAULT is portable.  */
typedef|typedef
enum|enum
block|{
name|APR_LOCK_FCNTL
block|,
comment|/**< fcntl() */
name|APR_LOCK_FLOCK
block|,
comment|/**< flock() */
name|APR_LOCK_SYSVSEM
block|,
comment|/**< System V Semaphores */
name|APR_LOCK_PROC_PTHREAD
block|,
comment|/**< POSIX pthread process-based locking */
name|APR_LOCK_POSIXSEM
block|,
comment|/**< POSIX semaphore process-based locking */
name|APR_LOCK_DEFAULT
comment|/**< Use the default process lock */
block|}
name|apr_lockmech_e
typedef|;
comment|/** Opaque structure representing a process mutex. */
typedef|typedef
name|struct
name|apr_proc_mutex_t
name|apr_proc_mutex_t
typedef|;
comment|/*   Function definitions */
comment|/**  * Create and initialize a mutex that can be used to synchronize processes.  * @param mutex the memory address where the newly created mutex will be  *        stored.  * @param fname A file name to use if the lock mechanism requires one.  This  *        argument should always be provided.  The lock code itself will  *        determine if it should be used.  * @param mech The mechanism to use for the interprocess lock, if any; one of  *<PRE>  *            APR_LOCK_FCNTL  *            APR_LOCK_FLOCK  *            APR_LOCK_SYSVSEM  *            APR_LOCK_POSIXSEM  *            APR_LOCK_PROC_PTHREAD  *            APR_LOCK_DEFAULT     pick the default mechanism for the platform  *</PRE>  * @param pool the pool from which to allocate the mutex.  * @see apr_lockmech_e  * @warning Check APR_HAS_foo_SERIALIZE defines to see if the platform supports  *          APR_LOCK_foo.  Only APR_LOCK_DEFAULT is portable.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_create
argument_list|(
argument|apr_proc_mutex_t **mutex
argument_list|,
argument|const char *fname
argument_list|,
argument|apr_lockmech_e mech
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Re-open a mutex in a child process.  * @param mutex The newly re-opened mutex structure.  * @param fname A file name to use if the mutex mechanism requires one.  This  *              argument should always be provided.  The mutex code itself will  *              determine if it should be used.  This filename should be the   *              same one that was passed to apr_proc_mutex_create().  * @param pool The pool to operate on.  * @remark This function must be called to maintain portability, even  *         if the underlying lock mechanism does not require it.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_child_init
argument_list|(
name|apr_proc_mutex_t
operator|*
operator|*
name|mutex
argument_list|,
specifier|const
name|char
operator|*
name|fname
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Acquire the lock for the given mutex. If the mutex is already locked,  * the current thread will be put to sleep until the lock becomes available.  * @param mutex the mutex on which to acquire the lock.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_lock
argument_list|(
name|apr_proc_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Attempt to acquire the lock for the given mutex. If the mutex has already  * been acquired, the call returns immediately with APR_EBUSY. Note: it  * is important that the APR_STATUS_IS_EBUSY(s) macro be used to determine  * if the return value was APR_EBUSY, for portability reasons.  * @param mutex the mutex on which to attempt the lock acquiring.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_trylock
argument_list|(
name|apr_proc_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Release the lock for the given mutex.  * @param mutex the mutex from which to release the lock.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_unlock
argument_list|(
name|apr_proc_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Destroy the mutex and free the memory associated with the lock.  * @param mutex the mutex to destroy.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_destroy
argument_list|(
name|apr_proc_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Destroy the mutex and free the memory associated with the lock.  * @param mutex the mutex to destroy.  * @note This function is generally used to kill a cleanup on an already  *       created mutex  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_mutex_cleanup
argument_list|(
name|void
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Return the name of the lockfile for the mutex, or NULL  * if the mutex doesn't use a lock file  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_proc_mutex_lockfile
argument_list|(
name|apr_proc_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Display the name of the mutex, as it relates to the actual method used.  * This matches the valid options for Apache's AcceptMutex directive  * @param mutex the name of the mutex  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_proc_mutex_name
argument_list|(
name|apr_proc_mutex_t
operator|*
name|mutex
argument_list|)
expr_stmt|;
comment|/**  * Display the name of the default mutex: APR_LOCK_DEFAULT  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_proc_mutex_defname
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Get the pool used by this proc_mutex.  * @return apr_pool_t the pool  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|proc_mutex
argument_list|)
expr_stmt|;
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
comment|/* ! APR_PROC_MUTEX_H */
end_comment

end_unit

