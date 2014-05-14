begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * testcode/checklocks.h - wrapper on locks that checks access.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TESTCODE_CHECK_LOCKS_H
end_ifndef

begin_define
define|#
directive|define
name|TESTCODE_CHECK_LOCKS_H
end_define

begin_comment
comment|/**  * \file  * Locks that are checked.  *  * Holds information per lock and per thread.  * That information is protected by a mutex (unchecked).  *  * Checks:  *      o which func, file, line created the lock.  *      o contention count, measures amount of contention on the lock.  *      o the memory region(s) that the lock protects are  *        memcmp'ed to ascertain no race conditions.  *      o checks that locks are unlocked properly (before deletion).  *        keeps which func, file, line that locked it.  *	o checks deadlocks with timeout so it can print errors for them.  *  * Limitations:  *	o Detects unprotected memory access when the lock is locked or freed,  *	  which detects races only if they happen, and only if in protected  *	  memory areas.  *	o Detects deadlocks by timeout, so approximately, as they happen.  *	o Does not check order of locking.  *	o Uses a lot of memory.  *	o The checks use locks themselves, changing scheduling,  *	  thus changing what races you see.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREAD_DEBUG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PTHREAD
end_ifndef

begin_comment
comment|/* we need the *timed*lock() routines to use for deadlock detection. */
end_comment

begin_error
error|#
directive|error
literal|"Need pthreads for checked locks"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************* THREAD DEBUG ************************/
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_comment
comment|/** How many threads to allocate for */
end_comment

begin_define
define|#
directive|define
name|THRDEBUG_MAX_THREADS
value|32
end_define

begin_comment
comment|/* threads */
end_comment

begin_comment
comment|/** do we check locking order */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|check_locking_order
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * Protection memory area.  * It is copied to a holding buffer to compare against later.  * Note that it may encompass the lock structure.  */
end_comment

begin_struct
struct|struct
name|protected_area
block|{
comment|/** where the memory region starts */
name|void
modifier|*
name|region
decl_stmt|;
comment|/** size of the region */
name|size_t
name|size
decl_stmt|;
comment|/** backbuffer that holds a copy, of same size. */
name|void
modifier|*
name|hold
decl_stmt|;
comment|/** next protected area in list */
name|struct
name|protected_area
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Per thread information for locking debug wrappers.   */
end_comment

begin_struct
struct|struct
name|thr_check
block|{
comment|/** thread id */
name|pthread_t
name|id
decl_stmt|;
comment|/** real thread func */
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
function_decl|;
comment|/** func user arg */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/** number of thread in list structure */
name|int
name|num
decl_stmt|;
comment|/** instance number - how many locks have been created by thread */
name|int
name|locks_created
decl_stmt|;
comment|/** file to write locking order information to */
name|FILE
modifier|*
name|order_info
decl_stmt|;
comment|/**  	 * List of locks that this thread is holding, double 	 * linked list. The first element is the most recent lock acquired. 	 * So it represents the stack of locks acquired. (of all types). 	 */
name|struct
name|checked_lock
modifier|*
name|holding_first
decl_stmt|,
modifier|*
name|holding_last
decl_stmt|;
comment|/** if the thread is currently waiting for a lock, which one */
name|struct
name|checked_lock
modifier|*
name|waiting
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * One structure for all types of locks.  */
end_comment

begin_struct
struct|struct
name|checked_lock
block|{
comment|/** mutex for exclusive access to this structure */
name|pthread_mutex_t
name|lock
decl_stmt|;
comment|/** list of memory regions protected by this checked lock */
name|struct
name|protected_area
modifier|*
name|prot
decl_stmt|;
comment|/** where was this lock created */
specifier|const
name|char
modifier|*
name|create_func
decl_stmt|,
modifier|*
name|create_file
decl_stmt|;
comment|/** where was this lock created */
name|int
name|create_line
decl_stmt|;
comment|/** unique instance identifier */
name|int
name|create_thread
decl_stmt|,
name|create_instance
decl_stmt|;
comment|/** contention count */
name|size_t
name|contention_count
decl_stmt|;
comment|/** number of times locked, ever */
name|size_t
name|history_count
decl_stmt|;
comment|/** hold count (how many threads are holding this lock) */
name|int
name|hold_count
decl_stmt|;
comment|/** how many threads are waiting for this lock */
name|int
name|wait_count
decl_stmt|;
comment|/** who touched it last */
specifier|const
name|char
modifier|*
name|holder_func
decl_stmt|,
modifier|*
name|holder_file
decl_stmt|;
comment|/** who touched it last */
name|int
name|holder_line
decl_stmt|;
comment|/** who owns the lock now */
name|struct
name|thr_check
modifier|*
name|holder
decl_stmt|;
comment|/** for rwlocks, the writelock holder */
name|struct
name|thr_check
modifier|*
name|writeholder
decl_stmt|;
comment|/** next lock a thread is holding (less recent) */
name|struct
name|checked_lock
modifier|*
name|next_held_lock
index|[
name|THRDEBUG_MAX_THREADS
index|]
decl_stmt|;
comment|/** prev lock a thread is holding (more recent) */
name|struct
name|checked_lock
modifier|*
name|prev_held_lock
index|[
name|THRDEBUG_MAX_THREADS
index|]
decl_stmt|;
comment|/** type of lock */
enum|enum
name|check_lock_type
block|{
comment|/** basic mutex */
name|check_lock_mutex
block|,
comment|/** fast spinlock */
name|check_lock_spinlock
block|,
comment|/** rwlock */
name|check_lock_rwlock
block|}
name|type
enum|;
comment|/** the lock itself, see type to disambiguate the union */
union|union
block|{
comment|/** mutex */
name|pthread_mutex_t
name|mutex
decl_stmt|;
comment|/** spinlock */
name|pthread_spinlock_t
name|spinlock
decl_stmt|;
comment|/** rwlock */
name|pthread_rwlock_t
name|rwlock
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Additional call for the user to specify what areas are protected  * @param lock: the lock that protects the area. It can be inside the area.  *	The lock must be inited. Call with user lock. (any type).  *	It demangles the lock itself (struct checked_lock**).  * @param area: ptr to mem.  * @param size: length of area.  * You can call it multiple times with the same lock to give several areas.  * Call it when you are done initialising the area, since it will be copied  * at this time and protected right away against unauthorised changes until   * the next lock() call is done.  */
end_comment

begin_function_decl
name|void
name|lock_protect
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|,
name|void
modifier|*
name|area
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove protected area from lock.  * No need to call this when deleting the lock.  * @param lock: the lock, any type, (struct checked_lock**).  * @param area: pointer to memory.  */
end_comment

begin_function_decl
name|void
name|lock_unprotect
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|,
name|void
modifier|*
name|area
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory associated with a checked lock  * @param lock: the checked lock, any type. (struct checked_lock**).  * @return: in bytes, including protected areas.  */
end_comment

begin_function_decl
name|size_t
name|lock_get_mem
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialise checklock. Sets up internal debug structures.  */
end_comment

begin_function_decl
name|void
name|checklock_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Cleanup internal debug state.  */
end_comment

begin_function_decl
name|void
name|checklock_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Init locks.  * @param type: what type of lock this is.  * @param lock: ptr to user alloced ptr structure. This is inited.  *     So an alloc is done and the ptr is stored as result.  * @param func: caller function name.  * @param file: caller file name.  * @param line: caller line number.  */
end_comment

begin_function_decl
name|void
name|checklock_init
parameter_list|(
name|enum
name|check_lock_type
name|type
parameter_list|,
name|struct
name|checked_lock
modifier|*
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Destroy locks. Free the structure.  * @param type: what type of lock this is.  * @param lock: ptr to user alloced structure. This is destroyed.  * @param func: caller function name.  * @param file: caller file name.  * @param line: caller line number.  */
end_comment

begin_function_decl
name|void
name|checklock_destroy
parameter_list|(
name|enum
name|check_lock_type
name|type
parameter_list|,
name|struct
name|checked_lock
modifier|*
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Acquire readlock.  * @param type: what type of lock this is. Had better be a rwlock.  * @param lock: ptr to lock.  * @param func: caller function name.  * @param file: caller file name.  * @param line: caller line number.  */
end_comment

begin_function_decl
name|void
name|checklock_rdlock
parameter_list|(
name|enum
name|check_lock_type
name|type
parameter_list|,
name|struct
name|checked_lock
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Acquire writelock.  * @param type: what type of lock this is. Had better be a rwlock.  * @param lock: ptr to lock.  * @param func: caller function name.  * @param file: caller file name.  * @param line: caller line number.  */
end_comment

begin_function_decl
name|void
name|checklock_wrlock
parameter_list|(
name|enum
name|check_lock_type
name|type
parameter_list|,
name|struct
name|checked_lock
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Locks.  * @param type: what type of lock this is. Had better be mutex or spinlock.  * @param lock: the lock.  * @param func: caller function name.  * @param file: caller file name.  * @param line: caller line number.  */
end_comment

begin_function_decl
name|void
name|checklock_lock
parameter_list|(
name|enum
name|check_lock_type
name|type
parameter_list|,
name|struct
name|checked_lock
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unlocks.  * @param type: what type of lock this is.  * @param lock: the lock.  * @param func: caller function name.  * @param file: caller file name.  * @param line: caller line number.  */
end_comment

begin_function_decl
name|void
name|checklock_unlock
parameter_list|(
name|enum
name|check_lock_type
name|type
parameter_list|,
name|struct
name|checked_lock
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create thread.  * @param thr: Thread id, where to store result.  * @param func: thread start function.  * @param arg: user argument.  */
end_comment

begin_function_decl
name|void
name|checklock_thrcreate
parameter_list|(
name|pthread_t
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

begin_comment
comment|/**  * Wait for thread to exit. Returns thread return value.  * @param thread: thread to wait for.  */
end_comment

begin_function_decl
name|void
name|checklock_thrjoin
parameter_list|(
name|pthread_t
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** structures to enable compiler type checking on the locks.   * Also the pointer makes it so that the lock can be part of the protected  * region without any possible problem (since the ptr will stay the same.)  * i.e. there can be contention and readlocks stored in checked_lock, while  * the protected area stays the same, even though it contains (ptr to) lock.  */
end_comment

begin_struct
struct|struct
name|checked_lock_rw
block|{
name|struct
name|checked_lock
modifier|*
name|c_rw
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** structures to enable compiler type checking on the locks. */
end_comment

begin_struct
struct|struct
name|checked_lock_mutex
block|{
name|struct
name|checked_lock
modifier|*
name|c_m
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** structures to enable compiler type checking on the locks. */
end_comment

begin_struct
struct|struct
name|checked_lock_spl
block|{
name|struct
name|checked_lock
modifier|*
name|c_spl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** debugging rwlock */
end_comment

begin_typedef
typedef|typedef
name|struct
name|checked_lock_rw
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
value|checklock_init(check_lock_rwlock,&((lock)->c_rw), __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_rw_destroy
parameter_list|(
name|lock
parameter_list|)
value|checklock_destroy(check_lock_rwlock,&((lock)->c_rw), __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_rw_rdlock
parameter_list|(
name|lock
parameter_list|)
value|checklock_rdlock(check_lock_rwlock, (lock)->c_rw, __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_rw_wrlock
parameter_list|(
name|lock
parameter_list|)
value|checklock_wrlock(check_lock_rwlock, (lock)->c_rw, __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_rw_unlock
parameter_list|(
name|lock
parameter_list|)
value|checklock_unlock(check_lock_rwlock, (lock)->c_rw, __func__, __FILE__, __LINE__)
end_define

begin_comment
comment|/** debugging mutex */
end_comment

begin_typedef
typedef|typedef
name|struct
name|checked_lock_mutex
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
value|checklock_init(check_lock_mutex,&((lock)->c_m), __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_basic_destroy
parameter_list|(
name|lock
parameter_list|)
value|checklock_destroy(check_lock_mutex,&((lock)->c_m), __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_basic_lock
parameter_list|(
name|lock
parameter_list|)
value|checklock_lock(check_lock_mutex, (lock)->c_m, __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_basic_unlock
parameter_list|(
name|lock
parameter_list|)
value|checklock_unlock(check_lock_mutex, (lock)->c_m, __func__, __FILE__, __LINE__)
end_define

begin_comment
comment|/** debugging spinlock */
end_comment

begin_typedef
typedef|typedef
name|struct
name|checked_lock_spl
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
value|checklock_init(check_lock_spinlock,&((lock)->c_spl), __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_quick_destroy
parameter_list|(
name|lock
parameter_list|)
value|checklock_destroy(check_lock_spinlock,&((lock)->c_spl), __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_quick_lock
parameter_list|(
name|lock
parameter_list|)
value|checklock_lock(check_lock_spinlock, (lock)->c_spl, __func__, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lock_quick_unlock
parameter_list|(
name|lock
parameter_list|)
value|checklock_unlock(check_lock_spinlock, (lock)->c_spl, __func__, __FILE__, __LINE__)
end_define

begin_comment
comment|/** we use the pthread id, our thr_check structure is kept behind the scenes */
end_comment

begin_typedef
typedef|typedef
name|pthread_t
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
value|checklock_thrcreate(thr, func, arg)
end_define

begin_define
define|#
directive|define
name|ub_thread_self
parameter_list|()
value|pthread_self()
end_define

begin_define
define|#
directive|define
name|ub_thread_join
parameter_list|(
name|thread
parameter_list|)
value|checklock_thrjoin(thread)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREAD_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TESTCODE_CHECK_LOCKS_H */
end_comment

end_unit

