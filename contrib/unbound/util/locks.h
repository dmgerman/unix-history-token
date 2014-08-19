begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * util/locks.h - unbound locking primitives  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_LOCKS_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_LOCKS_H
end_define

begin_comment
comment|/**  * \file  * Locking primitives.  * If pthreads is available, these are used.  * If no locking exists, they do nothing.  *  * The idea is to have different sorts of locks for different tasks.  * This allows the locking code to be ported more easily.  *  * Types of locks that are supported.  *   o lock_rw: lock that has many readers and one writer (to a data entry).  *   o lock_basic: simple mutex. Blocking, one person has access only.  *     This lock is meant for non performance sensitive uses.  *   o lock_quick: speed lock. For performance sensitive locking of critical  *     sections. Could be implemented by a mutex or a spinlock.  *   * Also thread creation and deletion functions are defined here.  */
end_comment

begin_include
include|#
directive|include
file|"util/log.h"
end_include

begin_comment
comment|/**  * The following macro is used to check the return value of the  * pthread calls. They return 0 on success and an errno on error.  * The errno is logged to the logfile with a descriptive comment.  */
end_comment

begin_define
define|#
directive|define
name|LOCKRET
parameter_list|(
name|func
parameter_list|)
value|do {\ 	int lockret_err;		\ 	if( (lockret_err=(func)) != 0)		\ 		log_err("%s at %d could not " #func ": %s", \ 		__FILE__, __LINE__, strerror(lockret_err));	\  	} while(0)
end_define

begin_comment
comment|/** DEBUG: use thread debug whenever possible */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PTHREAD
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_PTHREAD_SPINLOCK_T
argument_list|)
operator|&&
name|defined
argument_list|(
name|ENABLE_LOCK_CHECKS
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_THREAD_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREAD_DEBUG
end_ifdef

begin_comment
comment|/******************* THREAD DEBUG ************************/
end_comment

begin_comment
comment|/* (some) checking; to detect races and deadlocks. */
end_comment

begin_include
include|#
directive|include
file|"testcode/checklocks.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_THREAD_DEBUG */
end_comment

begin_define
define|#
directive|define
name|lock_protect
parameter_list|(
name|lock
parameter_list|,
name|area
parameter_list|,
name|size
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_unprotect
parameter_list|(
name|lock
parameter_list|,
name|area
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_get_mem
parameter_list|(
name|lock
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|checklock_start
parameter_list|()
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|checklock_stop
parameter_list|()
end_define

begin_comment
comment|/* nop */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTHREAD
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_comment
comment|/******************* PTHREAD ************************/
end_comment

begin_comment
comment|/** use pthread mutex for basic lock */
end_comment

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|lock_basic_t
typedef|;
end_typedef

begin_comment
comment|/** small front for pthread init func, NULL is default attrs. */
end_comment

begin_define
define|#
directive|define
name|lock_basic_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_init(lock, NULL))
end_define

begin_define
define|#
directive|define
name|lock_basic_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_basic_lock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_basic_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_unlock(lock))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PTHREAD_RWLOCK_T
end_ifndef

begin_comment
comment|/** in case rwlocks are not supported, use a mutex. */
end_comment

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|lock_rw_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_rw_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_init(lock, NULL))
end_define

begin_define
define|#
directive|define
name|lock_rw_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_rdlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_wrlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_unlock(lock))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_PTHREAD_RWLOCK_T */
end_comment

begin_comment
comment|/** we use the pthread rwlock */
end_comment

begin_typedef
typedef|typedef
name|pthread_rwlock_t
name|lock_rw_t
typedef|;
end_typedef

begin_comment
comment|/** small front for pthread init func, NULL is default attrs. */
end_comment

begin_define
define|#
directive|define
name|lock_rw_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_rwlock_init(lock, NULL))
end_define

begin_define
define|#
directive|define
name|lock_rw_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_rwlock_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_rdlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_rwlock_rdlock(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_wrlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_rwlock_wrlock(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_rwlock_unlock(lock))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PTHREAD_RWLOCK_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PTHREAD_SPINLOCK_T
end_ifndef

begin_comment
comment|/** in case spinlocks are not supported, use a mutex. */
end_comment

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|lock_quick_t
typedef|;
end_typedef

begin_comment
comment|/** small front for pthread init func, NULL is default attrs. */
end_comment

begin_define
define|#
directive|define
name|lock_quick_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_init(lock, NULL))
end_define

begin_define
define|#
directive|define
name|lock_quick_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_quick_lock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_quick_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_mutex_unlock(lock))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_PTHREAD_SPINLOCK_T */
end_comment

begin_comment
comment|/** use pthread spinlock for the quick lock */
end_comment

begin_typedef
typedef|typedef
name|pthread_spinlock_t
name|lock_quick_t
typedef|;
end_typedef

begin_comment
comment|/**   * allocate process private since this is available whether  * Thread Process-Shared Synchronization is supported or not.  * This means only threads inside this process may access the lock.  * (not threads from another process that shares memory).  * spinlocks are not supported on all pthread platforms.   */
end_comment

begin_define
define|#
directive|define
name|lock_quick_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_spin_init(lock, PTHREAD_PROCESS_PRIVATE))
end_define

begin_define
define|#
directive|define
name|lock_quick_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_spin_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_quick_lock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_spin_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_quick_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(pthread_spin_unlock(lock))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE SPINLOCK */
end_comment

begin_comment
comment|/** Thread creation */
end_comment

begin_typedef
typedef|typedef
name|pthread_t
name|ub_thread_t
typedef|;
end_typedef

begin_comment
comment|/** Pass where to store tread_t in thr. Use default NULL attributes. */
end_comment

begin_define
define|#
directive|define
name|ub_thread_create
parameter_list|(
name|thr
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
value|LOCKRET(pthread_create(thr, NULL, func, arg))
end_define

begin_comment
comment|/** get self id. */
end_comment

begin_define
define|#
directive|define
name|ub_thread_self
parameter_list|()
value|pthread_self()
end_define

begin_comment
comment|/** wait for another thread to terminate */
end_comment

begin_define
define|#
directive|define
name|ub_thread_join
parameter_list|(
name|thread
parameter_list|)
value|LOCKRET(pthread_join(thread, NULL))
end_define

begin_typedef
typedef|typedef
name|pthread_key_t
name|ub_thread_key_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ub_thread_key_create
parameter_list|(
name|key
parameter_list|,
name|f
parameter_list|)
value|LOCKRET(pthread_key_create(key, f))
end_define

begin_define
define|#
directive|define
name|ub_thread_key_set
parameter_list|(
name|key
parameter_list|,
name|v
parameter_list|)
value|LOCKRET(pthread_setspecific(key, v))
end_define

begin_define
define|#
directive|define
name|ub_thread_key_get
parameter_list|(
name|key
parameter_list|)
value|pthread_getspecific(key)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* we do not HAVE_PTHREAD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SOLARIS_THREADS
end_ifdef

begin_comment
comment|/******************* SOLARIS THREADS ************************/
end_comment

begin_include
include|#
directive|include
file|<synch.h>
end_include

begin_include
include|#
directive|include
file|<thread.h>
end_include

begin_typedef
typedef|typedef
name|rwlock_t
name|lock_rw_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_rw_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(rwlock_init(lock, USYNC_THREAD, NULL))
end_define

begin_define
define|#
directive|define
name|lock_rw_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(rwlock_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_rdlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(rw_rdlock(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_wrlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(rw_wrlock(lock))
end_define

begin_define
define|#
directive|define
name|lock_rw_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(rw_unlock(lock))
end_define

begin_comment
comment|/** use basic mutex */
end_comment

begin_typedef
typedef|typedef
name|mutex_t
name|lock_basic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_basic_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_init(lock, USYNC_THREAD, NULL))
end_define

begin_define
define|#
directive|define
name|lock_basic_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_basic_lock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_basic_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_unlock(lock))
end_define

begin_comment
comment|/** No spinlocks in solaris threads API. Use a mutex. */
end_comment

begin_typedef
typedef|typedef
name|mutex_t
name|lock_quick_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_quick_init
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_init(lock, USYNC_THREAD, NULL))
end_define

begin_define
define|#
directive|define
name|lock_quick_destroy
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_destroy(lock))
end_define

begin_define
define|#
directive|define
name|lock_quick_lock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_lock(lock))
end_define

begin_define
define|#
directive|define
name|lock_quick_unlock
parameter_list|(
name|lock
parameter_list|)
value|LOCKRET(mutex_unlock(lock))
end_define

begin_comment
comment|/** Thread creation, create a default thread. */
end_comment

begin_typedef
typedef|typedef
name|thread_t
name|ub_thread_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ub_thread_create
parameter_list|(
name|thr
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
value|LOCKRET(thr_create(NULL, NULL, func, arg, NULL, thr))
end_define

begin_define
define|#
directive|define
name|ub_thread_self
parameter_list|()
value|thr_self()
end_define

begin_define
define|#
directive|define
name|ub_thread_join
parameter_list|(
name|thread
parameter_list|)
value|LOCKRET(thr_join(thread, NULL, NULL))
end_define

begin_typedef
typedef|typedef
name|thread_key_t
name|ub_thread_key_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ub_thread_key_create
parameter_list|(
name|key
parameter_list|,
name|f
parameter_list|)
value|LOCKRET(thr_keycreate(key, f))
end_define

begin_define
define|#
directive|define
name|ub_thread_key_set
parameter_list|(
name|key
parameter_list|,
name|v
parameter_list|)
value|LOCKRET(thr_setspecific(key, v))
end_define

begin_function_decl
name|void
modifier|*
name|ub_thread_key_get
parameter_list|(
name|ub_thread_key_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* we do not HAVE_SOLARIS_THREADS and no PTHREADS */
end_comment

begin_comment
comment|/******************* WINDOWS THREADS ************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WINDOWS_THREADS
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/* Use a mutex */
end_comment

begin_typedef
typedef|typedef
name|LONG
name|lock_rw_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_rw_init
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_init(lock)
end_define

begin_define
define|#
directive|define
name|lock_rw_destroy
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_destroy(lock)
end_define

begin_define
define|#
directive|define
name|lock_rw_rdlock
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_lock(lock)
end_define

begin_define
define|#
directive|define
name|lock_rw_wrlock
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_lock(lock)
end_define

begin_define
define|#
directive|define
name|lock_rw_unlock
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_unlock(lock)
end_define

begin_comment
comment|/** the basic lock is a mutex, implemented opaquely, for error handling. */
end_comment

begin_typedef
typedef|typedef
name|LONG
name|lock_basic_t
typedef|;
end_typedef

begin_function_decl
name|void
name|lock_basic_init
parameter_list|(
name|lock_basic_t
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_basic_destroy
parameter_list|(
name|lock_basic_t
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_basic_lock
parameter_list|(
name|lock_basic_t
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_basic_unlock
parameter_list|(
name|lock_basic_t
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** on windows no spinlock, use mutex too. */
end_comment

begin_typedef
typedef|typedef
name|LONG
name|lock_quick_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_quick_init
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_init(lock)
end_define

begin_define
define|#
directive|define
name|lock_quick_destroy
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_destroy(lock)
end_define

begin_define
define|#
directive|define
name|lock_quick_lock
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_lock(lock)
end_define

begin_define
define|#
directive|define
name|lock_quick_unlock
parameter_list|(
name|lock
parameter_list|)
value|lock_basic_unlock(lock)
end_define

begin_comment
comment|/** Thread creation, create a default thread. */
end_comment

begin_typedef
typedef|typedef
name|HANDLE
name|ub_thread_t
typedef|;
end_typedef

begin_function_decl
name|void
name|ub_thread_create
parameter_list|(
name|ub_thread_t
modifier|*
name|thr
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ub_thread_t
name|ub_thread_self
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_thread_join
parameter_list|(
name|ub_thread_t
name|thr
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|DWORD
name|ub_thread_key_t
typedef|;
end_typedef

begin_function_decl
name|void
name|ub_thread_key_create
parameter_list|(
name|ub_thread_key_t
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_thread_key_set
parameter_list|(
name|ub_thread_key_t
name|key
parameter_list|,
name|void
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ub_thread_key_get
parameter_list|(
name|ub_thread_key_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* we do not HAVE_SOLARIS_THREADS, PTHREADS or WINDOWS_THREADS */
end_comment

begin_comment
comment|/******************* NO THREADS ************************/
end_comment

begin_define
define|#
directive|define
name|THREADS_DISABLED
value|1
end_define

begin_comment
comment|/** In case there is no thread support, define locks to do nothing */
end_comment

begin_typedef
typedef|typedef
name|int
name|lock_rw_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_rw_init
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_rw_destroy
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_rw_rdlock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_rw_wrlock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_rw_unlock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_comment
comment|/** define locks to do nothing */
end_comment

begin_typedef
typedef|typedef
name|int
name|lock_basic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_basic_init
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_basic_destroy
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_basic_lock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_basic_unlock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_comment
comment|/** define locks to do nothing */
end_comment

begin_typedef
typedef|typedef
name|int
name|lock_quick_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lock_quick_init
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_quick_destroy
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_quick_lock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|lock_quick_unlock
parameter_list|(
name|lock
parameter_list|)
end_define

begin_comment
comment|/* nop */
end_comment

begin_comment
comment|/** Thread creation, threads do not exist */
end_comment

begin_typedef
typedef|typedef
name|pid_t
name|ub_thread_t
typedef|;
end_typedef

begin_comment
comment|/** ub_thread_create is simulated with fork (extremely heavy threads,   * with no shared memory). */
end_comment

begin_define
define|#
directive|define
name|ub_thread_create
parameter_list|(
name|thr
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|ub_thr_fork_create(thr, func, arg)
end_define

begin_define
define|#
directive|define
name|ub_thread_self
parameter_list|()
value|getpid()
end_define

begin_define
define|#
directive|define
name|ub_thread_join
parameter_list|(
name|thread
parameter_list|)
value|ub_thr_fork_wait(thread)
end_define

begin_function_decl
name|void
name|ub_thr_fork_wait
parameter_list|(
name|ub_thread_t
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_thr_fork_create
parameter_list|(
name|ub_thread_t
modifier|*
name|thr
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
modifier|*
name|ub_thread_key_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ub_thread_key_create
parameter_list|(
name|key
parameter_list|,
name|f
parameter_list|)
value|(*(key)) = NULL
end_define

begin_define
define|#
directive|define
name|ub_thread_key_set
parameter_list|(
name|key
parameter_list|,
name|v
parameter_list|)
value|(key) = (v)
end_define

begin_define
define|#
directive|define
name|ub_thread_key_get
parameter_list|(
name|key
parameter_list|)
value|(key)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_WINDOWS_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SOLARIS_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PTHREAD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREAD_DEBUG */
end_comment

begin_comment
comment|/**  * Block all signals for this thread.  * fatal exit on error.  */
end_comment

begin_function_decl
name|void
name|ub_thread_blocksigs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * unblock one signal for this thread.  */
end_comment

begin_function_decl
name|void
name|ub_thread_sig_unblock
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_LOCKS_H */
end_comment

end_unit

