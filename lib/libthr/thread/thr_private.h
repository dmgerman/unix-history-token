begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Private thread definitions for the uthread kernel.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THR_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_THR_PRIVATE_H
end_define

begin_comment
comment|/*  * Evaluate the storage class specifier.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
end_ifdef

begin_define
define|#
directive|define
name|SCLASS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCLASS
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Include files.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<pthread_np.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<spinlock.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<sys/thr.h>
end_include

begin_include
include|#
directive|include
file|<sys/umtx.h>
end_include

begin_comment
comment|/*  * Kernel fatal error handler macro.  */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|string
parameter_list|)
value|_thread_exit(__FILE__,__LINE__,string)
end_define

begin_comment
comment|/* Output debug messages like this: */
end_comment

begin_define
define|#
directive|define
name|stdout_debug
parameter_list|(
name|args
modifier|...
parameter_list|)
value|_thread_printf(STDOUT_FILENO, args)
end_define

begin_define
define|#
directive|define
name|stderr_debug
parameter_list|(
name|args
modifier|...
parameter_list|)
value|_thread_printf(STDOUT_FILENO, args)
end_define

begin_comment
comment|/*  * Currently executing thread.  */
end_comment

begin_define
define|#
directive|define
name|curthread
value|_get_curthread()
end_define

begin_comment
comment|/*  * State change macro without scheduling queue change:  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_SET_STATE
parameter_list|(
name|thrd
parameter_list|,
name|newstate
parameter_list|)
value|do {				\ 	(thrd)->state = newstate;					\ 	(thrd)->fname = __FILE__;					\ 	(thrd)->lineno = __LINE__;					\ } while (0)
end_define

begin_comment
comment|/*  * State change macro with scheduling queue change - This must be  * called with GIANT held.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PTHREADS_INVARIANTS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|PTHREAD_ASSERT
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
value|do {	\ 	if (!(cond))			\ 		PANIC(msg);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PTHREAD_ASSERT_NOT_IN_SYNCQ
parameter_list|(
name|thrd
parameter_list|)
define|\
value|PTHREAD_ASSERT((((thrd)->flags& PTHREAD_FLAGS_IN_SYNCQ) == 0),	\ 	    "Illegal call from signal handler");
end_define

begin_define
define|#
directive|define
name|PTHREAD_NEW_STATE
parameter_list|(
name|thrd
parameter_list|,
name|newstate
parameter_list|)
value|do {				\ 	if ((thrd)->state != newstate) {				\ 		if ((thrd)->state == PS_RUNNING) {			\ 			PTHREAD_SET_STATE(thrd, newstate);		\ 		} else if (newstate == PS_RUNNING) { 			\ 			if (thr_kill(thrd->thr_id, SIGTHR))		\ 				abort();				\ 			PTHREAD_SET_STATE(thrd, newstate);		\ 		}							\ 	}								\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTHREAD_ASSERT
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PTHREAD_ASSERT_NOT_IN_SYNCQ
parameter_list|(
name|thrd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PTHREAD_NEW_STATE
parameter_list|(
name|thrd
parameter_list|,
name|newstate
parameter_list|)
value|do {				\ 	if (thr_kill(thrd->thr_id, SIGTHR))				\ 		abort();						\ 	PTHREAD_SET_STATE(thrd, newstate);				\ } while (0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PTHREAD_NEW_STATE
parameter_list|(
name|thrd
parameter_list|,
name|newstate
parameter_list|)
value|do {				\ 	if ((thrd)->state != newstate) {				\ 		if ((thrd)->state == PS_RUNNING) {			\ 		} else if (newstate == PS_RUNNING) { 			\ 			if (thr_kill(thrd->thr_id, SIGTHR))		\ 				abort();				\ 		}							\ 	}								\ 	PTHREAD_SET_STATE(thrd, newstate);				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * TailQ initialization values.  */
end_comment

begin_define
define|#
directive|define
name|TAILQ_INITIALIZER
value|{ NULL, NULL }
end_define

begin_define
define|#
directive|define
name|UMTX_INITIALIZER
value|{ NULL }
end_define

begin_struct
struct|struct
name|pthread_mutex_attr
block|{
name|enum
name|pthread_mutextype
name|m_type
decl_stmt|;
name|int
name|m_protocol
decl_stmt|;
name|int
name|m_ceiling
decl_stmt|;
name|long
name|m_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Static mutex initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_MUTEXATTR_STATIC_INITIALIZER
define|\
value|{ PTHREAD_MUTEX_DEFAULT, PTHREAD_PRIO_NONE, 0, MUTEX_FLAGS_PRIVATE }
end_define

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_STATIC_INITIALIZER
define|\
value|{ PTHREAD_MUTEXATTR_STATIC_INITIALIZER, UMTX_INITIALIZER, NULL,	\ 	0, 0, TAILQ_INITIALIZER }
end_define

begin_union
union|union
name|pthread_mutex_data
block|{
name|void
modifier|*
name|m_ptr
decl_stmt|;
name|int
name|m_count
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|pthread_mutex
block|{
name|enum
name|pthread_mutextype
name|m_type
decl_stmt|;
name|int
name|m_protocol
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|mutex_head
argument_list|,
argument|pthread
argument_list|)
name|m_queue
expr_stmt|;
name|struct
name|pthread
modifier|*
name|m_owner
decl_stmt|;
name|union
name|pthread_mutex_data
name|m_data
decl_stmt|;
name|long
name|m_flags
decl_stmt|;
name|int
name|m_refcount
decl_stmt|;
comment|/*          * Used for priority inheritence and protection.          *          *   m_prio       - For priority inheritence, the highest active          *                  priority (threads locking the mutex inherit          *                  this priority).  For priority protection, the          *                  ceiling priority of this mutex.          *   m_saved_prio - mutex owners inherited priority before          *                  taking the mutex, restored when the owner          *                  unlocks the mutex.          */
name|int
name|m_prio
decl_stmt|;
name|int
name|m_saved_prio
decl_stmt|;
comment|/*          * Link for list of all mutexes a thread currently owns.          */
name|TAILQ_ENTRY
argument_list|(
argument|pthread_mutex
argument_list|)
name|m_qe
expr_stmt|;
comment|/*          * Lock for accesses to this structure.          */
name|spinlock_t
name|lock
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for mutexes.   */
end_comment

begin_define
define|#
directive|define
name|MUTEX_FLAGS_PRIVATE
value|0x01
end_define

begin_define
define|#
directive|define
name|MUTEX_FLAGS_INITED
value|0x02
end_define

begin_define
define|#
directive|define
name|MUTEX_FLAGS_BUSY
value|0x04
end_define

begin_comment
comment|/*   * Condition variable definitions.  */
end_comment

begin_enum
enum|enum
name|pthread_cond_type
block|{
name|COND_TYPE_FAST
block|,
name|COND_TYPE_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pthread_cond
block|{
name|enum
name|pthread_cond_type
name|c_type
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|cond_head
argument_list|,
argument|pthread
argument_list|)
name|c_queue
expr_stmt|;
name|pthread_mutex_t
name|c_mutex
decl_stmt|;
name|void
modifier|*
name|c_data
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
name|int
name|c_seqno
decl_stmt|;
comment|/* 	 * Lock for accesses to this structure. 	 */
name|struct
name|umtx
name|c_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_cond_attr
block|{
name|enum
name|pthread_cond_type
name|c_type
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for condition variables.  */
end_comment

begin_define
define|#
directive|define
name|COND_FLAGS_INITED
value|0x01
end_define

begin_comment
comment|/*  * Static cond initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_COND_STATIC_INITIALIZER
define|\
value|{ COND_TYPE_FAST, TAILQ_INITIALIZER, NULL, NULL, \ 	0, 0, UMTX_INITIALIZER }
end_define

begin_comment
comment|/*  * Semaphore definitions.  */
end_comment

begin_struct
struct|struct
name|sem
block|{
define|#
directive|define
name|SEM_MAGIC
value|((u_int32_t) 0x09fa4012)
name|u_int32_t
name|magic
decl_stmt|;
name|pthread_mutex_t
name|lock
decl_stmt|;
name|pthread_cond_t
name|gtzero
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
name|u_int32_t
name|nwaiters
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cleanup definitions.  */
end_comment

begin_struct
struct|struct
name|pthread_cleanup
block|{
name|struct
name|pthread_cleanup
modifier|*
name|next
decl_stmt|;
name|void
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|()
function_decl|;
name|void
modifier|*
name|routine_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_attr
block|{
name|int
name|sched_policy
decl_stmt|;
name|int
name|sched_inherit
decl_stmt|;
name|int
name|sched_interval
decl_stmt|;
name|int
name|prio
decl_stmt|;
name|int
name|suspend
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|arg_attr
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cleanup_attr
function_decl|)
parameter_list|()
function_decl|;
name|void
modifier|*
name|stackaddr_attr
decl_stmt|;
name|size_t
name|stacksize_attr
decl_stmt|;
name|size_t
name|guardsize_attr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Thread creation state attributes.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_CREATE_RUNNING
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_CREATE_SUSPENDED
value|1
end_define

begin_comment
comment|/*  * Miscellaneous definitions.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_STACK_DEFAULT
value|65536
end_define

begin_comment
comment|/*  * Size of default red zone at the end of each stack.  In actuality, this "red  * zone" is merely an unmapped region, except in the case of the initial stack.  * Since mmap() makes it possible to specify the maximum growth of a MAP_STACK  * region, an unmapped gap between thread stacks achieves the same effect as  * explicitly mapped red zones.  * This is declared and initialized in uthread_init.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_pthread_guard_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_pthread_page_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Maximum size of initial thread's stack.  This perhaps deserves to be larger  * than the stacks of other threads, since many applications are likely to run  * almost entirely on this stack.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_STACK_INITIAL
value|0x100000
end_define

begin_comment
comment|/*  * Define the different priority ranges.  All applications have thread  * priorities constrained within 0-31.  The threads library raises the  * priority when delivering signals in order to ensure that signal  * delivery happens (from the POSIX spec) "as soon as possible".  * In the future, the threads library will also be able to map specific  * threads into real-time (cooperating) processes or kernel threads.  * The RT and SIGNAL priorities will be used internally and added to  * thread base priorities so that the scheduling queue can handle both  * normal and RT priority threads with and without signal handling.  *  * The approach taken is that, within each class, signal delivery  * always has priority over thread execution.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_DEFAULT_PRIORITY
value|15
end_define

begin_define
define|#
directive|define
name|PTHREAD_MIN_PRIORITY
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_MAX_PRIORITY
value|31
end_define

begin_comment
comment|/* 0x1F */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_SIGNAL_PRIORITY
value|32
end_define

begin_comment
comment|/* 0x20 */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_RT_PRIORITY
value|64
end_define

begin_comment
comment|/* 0x40 */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_FIRST_PRIORITY
value|PTHREAD_MIN_PRIORITY
end_define

begin_define
define|#
directive|define
name|PTHREAD_LAST_PRIORITY
define|\
value|(PTHREAD_MAX_PRIORITY + PTHREAD_SIGNAL_PRIORITY + PTHREAD_RT_PRIORITY)
end_define

begin_define
define|#
directive|define
name|PTHREAD_BASE_PRIORITY
parameter_list|(
name|prio
parameter_list|)
value|((prio)& PTHREAD_MAX_PRIORITY)
end_define

begin_comment
comment|/*  * Clock resolution in microseconds.  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_RES_USEC
value|10000
end_define

begin_define
define|#
directive|define
name|CLOCK_RES_USEC_MIN
value|1000
end_define

begin_comment
comment|/*  * Time slice period in microseconds.  */
end_comment

begin_define
define|#
directive|define
name|TIMESLICE_USEC
value|20000
end_define

begin_comment
comment|/*  * XXX Define a thread-safe macro to get the current time of day  * which is updated at regular intervals by the scheduling signal  * handler.  */
end_comment

begin_define
define|#
directive|define
name|GET_CURRENT_TOD
parameter_list|(
name|tv
parameter_list|)
value|gettimeofday(&(tv), NULL)
end_define

begin_struct
struct|struct
name|pthread_rwlockattr
block|{
name|int
name|pshared
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_rwlock
block|{
name|pthread_mutex_t
name|lock
decl_stmt|;
comment|/* monitor lock */
name|int
name|state
decl_stmt|;
comment|/* 0 = idle>0 = # of readers  -1 = writer */
name|pthread_cond_t
name|read_signal
decl_stmt|;
name|pthread_cond_t
name|write_signal
decl_stmt|;
name|int
name|blocked_writers
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Thread states.  */
end_comment

begin_enum
enum|enum
name|pthread_state
block|{
name|PS_RUNNING
block|,
name|PS_MUTEX_WAIT
block|,
name|PS_COND_WAIT
block|,
name|PS_SLEEP_WAIT
block|,
comment|/* XXX We need to wrap syscalls to set this state */
name|PS_WAIT_WAIT
block|,
name|PS_JOIN
block|,
name|PS_DEAD
block|,
name|PS_DEADLOCK
block|,
name|PS_STATE_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * File descriptor locking definitions.  */
end_comment

begin_define
define|#
directive|define
name|FD_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|FD_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|FD_RDWR
value|(FD_READ | FD_WRITE)
end_define

begin_union
union|union
name|pthread_wait_data
block|{
name|pthread_mutex_t
name|mutex
decl_stmt|;
name|pthread_cond_t
name|cond
decl_stmt|;
name|spinlock_t
modifier|*
name|spinlock
decl_stmt|;
name|struct
name|pthread
modifier|*
name|thread
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|join_status
block|{
name|struct
name|pthread
modifier|*
name|thread
decl_stmt|;
name|void
modifier|*
name|ret
decl_stmt|;
name|int
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_state_data
block|{
name|union
name|pthread_wait_data
name|psd_wait_data
decl_stmt|;
name|enum
name|pthread_state
name|psd_state
decl_stmt|;
name|int
name|psd_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_specific_elem
block|{
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|seqno
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Thread structure.  */
end_comment

begin_struct
struct|struct
name|pthread
block|{
comment|/* 	 * Magic value to help recognize a valid thread structure 	 * from an invalid one: 	 */
define|#
directive|define
name|PTHREAD_MAGIC
value|((u_int32_t) 0xd09ba115)
name|u_int32_t
name|magic
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|u_int64_t
name|uniqueid
decl_stmt|;
comment|/* for gdb */
name|thr_id_t
name|thr_id
decl_stmt|;
name|sigset_t
name|savedsig
decl_stmt|;
name|int
name|crit_ref
decl_stmt|;
comment|/* crit. section netsting level */
comment|/* 	 * Lock for accesses to this thread structure. 	 */
name|spinlock_t
name|lock
decl_stmt|;
comment|/* Queue entry for list of all threads: */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|tle
expr_stmt|;
comment|/* Queue entry for list of dead threads: */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|dle
expr_stmt|;
comment|/* 	 * Thread start routine, argument, stack pointer and thread 	 * attributes. 	 */
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
name|void
modifier|*
name|stack
decl_stmt|;
name|struct
name|pthread_attr
name|attr
decl_stmt|;
comment|/* 	 * Machine context, including signal state. 	 */
name|ucontext_t
name|ctx
decl_stmt|;
comment|/* 	 * Cancelability flags - the lower 2 bits are used by cancel 	 * definitions in pthread.h 	 */
define|#
directive|define
name|PTHREAD_AT_CANCEL_POINT
value|0x0004
define|#
directive|define
name|PTHREAD_CANCELLING
value|0x0008
comment|/* 	 * Protected by Giant. 	 */
name|int
name|cancelflags
decl_stmt|;
comment|/* Thread state: */
name|enum
name|pthread_state
name|state
decl_stmt|;
comment|/* 	 * Error variable used instead of errno. The function __error() 	 * returns a pointer to this.  	 */
name|int
name|error
decl_stmt|;
comment|/* 	 * The joiner is the thread that is joining to this thread.  The 	 * join status keeps track of a join operation to another thread. 	 */
name|struct
name|pthread
modifier|*
name|joiner
decl_stmt|;
name|struct
name|join_status
name|join_status
decl_stmt|;
comment|/* 	 * A thread can belong to: 	 * 	 *   o A queue of threads waiting for a mutex 	 *   o A queue of threads waiting for a condition variable 	 * 	 * A thread can also be joining a thread (the joiner field above). 	 * 	 * It must not be possible for a thread to belong to any of the 	 * above queues while it is handling a signal.  Signal handlers 	 * may longjmp back to previous stack frames circumventing normal 	 * control flow.  This could corrupt queue integrity if the thread 	 * retains membership in the queue.  Therefore, if a thread is a 	 * member of one of these queues when a signal handler is invoked, 	 * it must remove itself from the queue before calling the signal 	 * handler and reinsert itself after normal return of the handler. 	 * 	 * Use sqe for synchronization (mutex and condition variable) queue 	 * links. 	 */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|sqe
expr_stmt|;
comment|/* synchronization queue link */
comment|/* Wait data. */
name|union
name|pthread_wait_data
name|data
decl_stmt|;
comment|/* Miscellaneous flags; only set with signals deferred. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|PTHREAD_FLAGS_PRIVATE
value|0x0001
define|#
directive|define
name|PTHREAD_EXITING
value|0x0002
define|#
directive|define
name|PTHREAD_FLAGS_IN_CONDQ
value|0x0080
comment|/* in condition queue using sqe link*/
define|#
directive|define
name|PTHREAD_FLAGS_IN_MUTEXQ
value|0x0100
comment|/* in mutex queue using sqe link */
define|#
directive|define
name|PTHREAD_FLAGS_SUSPENDED
value|0x0200
comment|/* thread is suspended */
define|#
directive|define
name|PTHREAD_FLAGS_TRACE
value|0x0400
comment|/* for debugging purposes */
define|#
directive|define
name|PTHREAD_FLAGS_IN_SYNCQ
define|\
value|(PTHREAD_FLAGS_IN_CONDQ | PTHREAD_FLAGS_IN_MUTEXQ)
comment|/* 	 * Base priority is the user setable and retrievable priority 	 * of the thread.  It is only affected by explicit calls to 	 * set thread priority and upon thread creation via a thread 	 * attribute or default priority. 	 */
name|char
name|base_priority
decl_stmt|;
comment|/* 	 * Inherited priority is the priority a thread inherits by 	 * taking a priority inheritence or protection mutex.  It 	 * is not affected by base priority changes.  Inherited 	 * priority defaults to and remains 0 until a mutex is taken 	 * that is being waited on by any other thread whose priority 	 * is non-zero. 	 */
name|char
name|inherited_priority
decl_stmt|;
comment|/* 	 * Active priority is always the maximum of the threads base 	 * priority and inherited priority.  When there is a change 	 * in either the base or inherited priority, the active 	 * priority must be recalculated. 	 */
name|char
name|active_priority
decl_stmt|;
comment|/* Number of priority ceiling or protection mutexes owned. */
name|int
name|priority_mutex_count
decl_stmt|;
comment|/* 	 * Queue of currently owned mutexes. 	 */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread_mutex
argument_list|)
name|mutexq
expr_stmt|;
name|void
modifier|*
name|ret
decl_stmt|;
name|struct
name|pthread_specific_elem
modifier|*
name|specific
decl_stmt|;
name|int
name|specific_data_count
decl_stmt|;
comment|/* 	 * Architecture specific id field used for _{get, set}_curthread() 	 * interface. 	 */
name|void
modifier|*
name|arch_id
decl_stmt|;
comment|/* Cleanup handlers Link List */
name|struct
name|pthread_cleanup
modifier|*
name|cleanup
decl_stmt|;
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* Ptr to source file name  */
name|int
name|lineno
decl_stmt|;
comment|/* Source line number.      */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Global variables for the uthread kernel.  */
end_comment

begin_decl_stmt
name|SCLASS
name|void
modifier|*
name|_usrstack
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
operator|(
name|void
operator|*
operator|)
name|USRSTACK
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|SCLASS
name|spinlock_t
name|stack_lock
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|_SPINLOCK_INITIALIZER
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STACK_LOCK
value|_SPINLOCK(&stack_lock);
end_define

begin_define
define|#
directive|define
name|STACK_UNLOCK
value|_SPINUNLOCK(&stack_lock);
end_define

begin_comment
comment|/* List of all threads: */
end_comment

begin_decl_stmt
name|SCLASS
name|TAILQ_HEAD
argument_list|(,
name|pthread
argument_list|)
name|_thread_list
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_thread_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Dead threads: */
end_comment

begin_decl_stmt
name|SCLASS
name|TAILQ_HEAD
argument_list|(,
name|pthread
argument_list|)
name|_dead_list
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_dead_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These two locks protect the global active threads list and  * the global dead threads list, respectively. Combining these  * into one lock for both lists doesn't seem wise, since it  * would likely increase contention during busy thread creation  * and destruction for very little savings in space.  *  * The lock for the "dead threads list" must be a pthread mutex  * because it is used with condition variables to synchronize  * the gc thread with active threads in the process of exiting or  * dead threads who have just been joined.  */
end_comment

begin_decl_stmt
name|SCLASS
name|spinlock_t
name|thread_list_lock
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|_SPINLOCK_INITIALIZER
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|pthread_mutex_t
name|dead_list_lock
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|NULL
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|THREAD_LIST_LOCK
value|_SPINLOCK(&thread_list_lock)
end_define

begin_define
define|#
directive|define
name|THREAD_LIST_UNLOCK
value|_SPINUNLOCK(&thread_list_lock)
end_define

begin_define
define|#
directive|define
name|DEAD_LIST_LOCK
value|_pthread_mutex_lock(&dead_list_lock)
end_define

begin_define
define|#
directive|define
name|DEAD_LIST_UNLOCK
value|_pthread_mutex_unlock(&dead_list_lock)
end_define

begin_comment
comment|/* Initial thread: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread
modifier|*
name|_thread_initial
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default thread attributes: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread_attr
name|pthread_attr_default
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
block|{
name|SCHED_RR
block|,
literal|0
block|,
name|TIMESLICE_USEC
block|,
name|PTHREAD_DEFAULT_PRIORITY
block|,
name|PTHREAD_CREATE_RUNNING
block|,
name|PTHREAD_CREATE_JOINABLE
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|PTHREAD_STACK_DEFAULT
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default mutex attributes: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread_mutex_attr
name|pthread_mutexattr_default
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
block|{
name|PTHREAD_MUTEX_DEFAULT
block|,
name|PTHREAD_PRIO_NONE
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default condition variable attributes: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread_cond_attr
name|pthread_condattr_default
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
block|{
name|COND_TYPE_FAST
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|SCLASS
name|int
name|_clock_res_usec
comment|/* Clock resolution in usec.	*/
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|CLOCK_RES_USEC
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Giant lock. */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|umtx
name|_giant_mutex
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|UMTX_INITIALIZER
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_giant_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Garbage collector condition variable. */
end_comment

begin_decl_stmt
name|SCLASS
name|pthread_cond_t
name|_gc_cond
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|NULL
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Array of signal actions for this process.  */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|sigaction
name|_thread_sigact
index|[
name|NSIG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tracks the number of threads blocked while waiting for a spinlock. */
end_comment

begin_decl_stmt
name|SCLASS
specifier|volatile
name|int
name|_spinblock_count
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
literal|0
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * And, should we climb the beanstalk,  * We'll meet his brother, Giant.  */
end_comment

begin_function_decl
name|void
name|GIANT_LOCK
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GIANT_UNLOCK
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Undefine the storage class specifier: */
end_comment

begin_undef
undef|#
directive|undef
name|SCLASS
end_undef

begin_comment
comment|/*  * Function prototype definitions.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|char
modifier|*
name|__ttyname_basic
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|__ttyname_r_basic
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ttyname_r
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_cond_wait_backout
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_find_thread
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pthread_t
name|_get_curthread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_set_curthread
parameter_list|(
name|ucontext_t
modifier|*
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_retire_thread
parameter_list|(
name|void
modifier|*
name|arch_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_thread_stack_alloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_stack_free
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_create
parameter_list|(
name|pthread_t
modifier|*
parameter_list|,
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_mutex_cv_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_mutex_cv_unlock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mutex_lock_backout
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mutex_notify_priochange
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_mutex_reinit
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mutex_unlock_private
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_cond_reinit
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_pthread_getspecific
parameter_list|(
name|pthread_key_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_key_create
parameter_list|(
name|pthread_key_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_key_delete
parameter_list|(
name|pthread_key_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutex_destroy
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutex_init
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|,
specifier|const
name|pthread_mutexattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutex_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutex_trylock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutex_unlock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutexattr_init
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutexattr_destroy
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutexattr_settype
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_once
parameter_list|(
name|pthread_once_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pthread_t
name|_pthread_self
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_setspecific
parameter_list|(
name|pthread_key_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_spintrylock
parameter_list|(
name|spinlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_exit
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_exit_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_thread_cleanup
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_cleanupspecific
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_dump_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sig_wrapper
parameter_list|(
name|int
name|sig
parameter_list|,
name|siginfo_t
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_printf
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_seterrno
parameter_list|(
name|pthread_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pthread_addr_t
name|_thread_gc
parameter_list|(
name|pthread_addr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_enter_cancellation_point
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_leave_cancellation_point
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_cancellation_point
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_suspend
parameter_list|(
name|pthread_t
name|thread
parameter_list|,
name|struct
name|timespec
modifier|*
name|abstime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_critical_enter
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_critical_exit
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* #include<sys/aio.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_AIO_H_
end_ifdef

begin_decl_stmt
name|int
name|__sys_aio_suspend
argument_list|(
specifier|const
expr|struct
name|aiocb
operator|*
specifier|const
index|[]
argument_list|,
name|int
argument_list|,
specifier|const
expr|struct
name|timespec
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/event.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_EVENT_H_
end_ifdef

begin_function_decl
name|int
name|__sys_kevent
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|kevent
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|kevent
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/ioctl.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_IOCTL_H_
end_ifdef

begin_function_decl
name|int
name|__sys_ioctl
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/mman.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_MMAN_H_
end_ifdef

begin_function_decl
name|int
name|__sys_msync
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/mount.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_MOUNT_H_
end_ifdef

begin_function_decl
name|int
name|__sys_fstatfs
parameter_list|(
name|int
parameter_list|,
name|struct
name|statfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/socket.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_SOCKET_H_
end_ifdef

begin_function_decl
name|int
name|__sys_accept
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_bind
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_connect
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_getpeername
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_getsockname
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_getsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|socklen_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_listen
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_recvfrom
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_recvmsg
parameter_list|(
name|int
parameter_list|,
name|struct
name|msghdr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sendfile
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|sf_hdtr
modifier|*
parameter_list|,
name|off_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_sendmsg
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|msghdr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_sendto
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_setsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|socklen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_shutdown
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_socket
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_socketpair
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/stat.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_STAT_H_
end_ifdef

begin_function_decl
name|int
name|__sys_fchflags
parameter_list|(
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_fchmod
parameter_list|(
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_fstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/uio.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_UIO_H_
end_ifdef

begin_function_decl
name|ssize_t
name|__sys_readv
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_writev
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<sys/wait.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WNOHANG
end_ifdef

begin_function_decl
name|pid_t
name|__sys_wait4
parameter_list|(
name|pid_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|rusage
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<dirent.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DIRENT_H_
end_ifdef

begin_function_decl
name|int
name|__sys_getdirentries
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<fcntl.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_FCNTL_H_
end_ifdef

begin_function_decl
name|int
name|__sys_fcntl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_flock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<poll.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_POLL_H_
end_ifdef

begin_function_decl
name|int
name|__sys_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<signal.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SIGNAL_H_
end_ifdef

begin_function_decl
name|int
name|__sys_sigaction
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sigaction
modifier|*
parameter_list|,
name|struct
name|sigaction
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sigaltstack
parameter_list|(
specifier|const
name|struct
name|sigaltstack
modifier|*
parameter_list|,
name|struct
name|sigaltstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sigprocmask
parameter_list|(
name|int
parameter_list|,
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sigreturn
parameter_list|(
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<unistd.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UNISTD_H_
end_ifdef

begin_function_decl
name|int
name|__sys_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_dup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_dup2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_execve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__sys_exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_fchown
parameter_list|(
name|int
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|__sys_fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|__sys_fpathconf
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_fsync
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_pipe
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|__sys_write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PTHREAD_PRIVATE_H */
end_comment

end_unit

