begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Private thread definitions for the uthread kernel.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_PRIVATE_H
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
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<spinlock.h>
end_include

begin_include
include|#
directive|include
file|<pthread_np.h>
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
name|_x
parameter_list|)
value|_thread_sys_write(1,_x,strlen(_x));
end_define

begin_define
define|#
directive|define
name|stderr_debug
parameter_list|(
name|_x
parameter_list|)
value|_thread_sys_write(2,_x,strlen(_x));
end_define

begin_comment
comment|/*  * Priority queue manipulation macros (using pqe link):  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_PRIOQ_INSERT_HEAD
parameter_list|(
name|thrd
parameter_list|)
value|_pq_insert_head(&_readyq,thrd)
end_define

begin_define
define|#
directive|define
name|PTHREAD_PRIOQ_INSERT_TAIL
parameter_list|(
name|thrd
parameter_list|)
value|_pq_insert_tail(&_readyq,thrd)
end_define

begin_define
define|#
directive|define
name|PTHREAD_PRIOQ_REMOVE
parameter_list|(
name|thrd
parameter_list|)
value|_pq_remove(&_readyq,thrd)
end_define

begin_define
define|#
directive|define
name|PTHREAD_PRIOQ_FIRST
parameter_list|()
value|_pq_first(&_readyq)
end_define

begin_comment
comment|/*  * Waiting queue manipulation macros (using pqe link):  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PTHREADS_INVARIANTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_REMOVE
parameter_list|(
name|thrd
parameter_list|)
value|_waitq_remove(thrd)
end_define

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_INSERT
parameter_list|(
name|thrd
parameter_list|)
value|_waitq_insert(thrd)
end_define

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_CLEARACTIVE
parameter_list|()
value|_waitq_clearactive()
end_define

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_SETACTIVE
parameter_list|()
value|_waitq_setactive()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_REMOVE
parameter_list|(
name|thrd
parameter_list|)
value|TAILQ_REMOVE(&_waitingq,thrd,pqe)
end_define

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_INSERT
parameter_list|(
name|thrd
parameter_list|)
value|do {					\ 	if ((thrd)->wakeup_time.tv_sec == -1)				\ 		TAILQ_INSERT_TAIL(&_waitingq,thrd,pqe);			\ 	else {								\ 		pthread_t tid = TAILQ_FIRST(&_waitingq);		\ 		while ((tid != NULL)&& (tid->wakeup_time.tv_sec != -1)&& \ 		    ((tid->wakeup_time.tv_sec< (thrd)->wakeup_time.tv_sec) ||	\ 		    ((tid->wakeup_time.tv_sec == (thrd)->wakeup_time.tv_sec)&&	\ 		    (tid->wakeup_time.tv_nsec<= (thrd)->wakeup_time.tv_nsec)))) \ 			tid = TAILQ_NEXT(tid, pqe);			\ 		if (tid == NULL)					\ 			TAILQ_INSERT_TAIL(&_waitingq,thrd,pqe);		\ 		else							\ 			TAILQ_INSERT_BEFORE(tid,thrd,pqe);		\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_CLEARACTIVE
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PTHREAD_WAITQ_SETACTIVE
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Work queue manipulation macros (using qe link):  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_WORKQ_INSERT
parameter_list|(
name|thrd
parameter_list|)
value|do {					\ 	TAILQ_INSERT_TAIL(&_workq,thrd,qe);				\ 	(thrd)->flags |= PTHREAD_FLAGS_IN_WORKQ;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PTHREAD_WORKQ_REMOVE
parameter_list|(
name|thrd
parameter_list|)
value|do {					\ 	TAILQ_REMOVE(&_workq,thrd,qe);					\ 	(thrd)->flags&= ~PTHREAD_FLAGS_IN_WORKQ;			\ } while (0)
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
comment|/*  * State change macro with scheduling queue change - This must be  * called with preemption deferred (see thread_kern_sched_[un]defer).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PTHREADS_INVARIANTS
argument_list|)
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
value|do {				\ 	if (_thread_kern_new_state != 0)				\ 		PANIC("Recursive PTHREAD_NEW_STATE");			\ 	_thread_kern_new_state = 1;					\ 	if ((thrd)->state != newstate) {				\ 		if ((thrd)->state == PS_RUNNING) {			\ 			PTHREAD_PRIOQ_REMOVE(thrd);			\ 			PTHREAD_WAITQ_INSERT(thrd);			\ 		} else if (newstate == PS_RUNNING) { 			\ 			PTHREAD_WAITQ_REMOVE(thrd);			\ 			PTHREAD_PRIOQ_INSERT_TAIL(thrd);		\ 		}							\ 	}								\ 	_thread_kern_new_state = 0;					\ 	PTHREAD_SET_STATE(thrd, newstate);				\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTHREAD_NEW_STATE
parameter_list|(
name|thrd
parameter_list|,
name|newstate
parameter_list|)
value|do {				\ 	if ((thrd)->state != newstate) {				\ 		if ((thrd)->state == PS_RUNNING) {			\ 			PTHREAD_PRIOQ_REMOVE(thrd);			\ 			PTHREAD_WAITQ_INSERT(thrd);			\ 		} else if (newstate == PS_RUNNING) { 			\ 			PTHREAD_WAITQ_REMOVE(thrd);			\ 			PTHREAD_PRIOQ_INSERT_TAIL(thrd);		\ 		}							\ 	}								\ 	PTHREAD_SET_STATE(thrd, newstate);				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define the signals to be used for scheduling.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PTHREADS_COMPAT_SCHED
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ITIMER_SCHED_TIMER
value|ITIMER_VIRTUAL
end_define

begin_define
define|#
directive|define
name|_SCHED_SIGNAL
value|SIGVTALRM
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_ITIMER_SCHED_TIMER
value|ITIMER_PROF
end_define

begin_define
define|#
directive|define
name|_SCHED_SIGNAL
value|SIGPROF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Priority queues.  *  * XXX It'd be nice if these were contained in uthread_priority_queue.[ch].  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pq_list
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread
argument_list|)
name|pl_head
expr_stmt|;
comment|/* list of threads at this priority */
name|TAILQ_ENTRY
argument_list|(
argument|pq_list
argument_list|)
name|pl_link
expr_stmt|;
comment|/* link for queue of priority lists */
name|int
name|pl_prio
decl_stmt|;
comment|/* the priority of this list */
name|int
name|pl_queued
decl_stmt|;
comment|/* is this in the priority queue */
block|}
name|pq_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pq_queue
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pq_list
argument_list|)
name|pq_queue
expr_stmt|;
comment|/* queue of priority lists */
name|pq_list_t
modifier|*
name|pq_lists
decl_stmt|;
comment|/* array of all priority lists */
name|int
name|pq_size
decl_stmt|;
comment|/* number of priority lists */
block|}
name|pq_queue_t
typedef|;
end_typedef

begin_comment
comment|/*  * TailQ initialization values.  */
end_comment

begin_define
define|#
directive|define
name|TAILQ_INITIALIZER
value|{ NULL, NULL }
end_define

begin_comment
comment|/*   * Mutex definitions.  */
end_comment

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
comment|/* 	 * Used for priority inheritence and protection. 	 * 	 *   m_prio       - For priority inheritence, the highest active 	 *                  priority (threads locking the mutex inherit 	 *                  this priority).  For priority protection, the 	 *                  ceiling priority of this mutex. 	 *   m_saved_prio - mutex owners inherited priority before 	 *                  taking the mutex, restored when the owner 	 *                  unlocks the mutex. 	 */
name|int
name|m_prio
decl_stmt|;
name|int
name|m_saved_prio
decl_stmt|;
comment|/* 	 * Link for list of all mutexes a thread currently owns. 	 */
name|TAILQ_ENTRY
argument_list|(
argument|pthread_mutex
argument_list|)
name|m_qe
expr_stmt|;
comment|/* 	 * Lock for accesses to this structure. 	 */
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
comment|/*  * Static mutex initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_STATIC_INITIALIZER
define|\
value|{ PTHREAD_MUTEX_DEFAULT, PTHREAD_PRIO_NONE, TAILQ_INITIALIZER, \ 	NULL, { NULL }, MUTEX_FLAGS_PRIVATE, 0, 0, 0, TAILQ_INITIALIZER, \ 	_SPINLOCK_INITIALIZER }
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
comment|/* 	 * Lock for accesses to this structure. 	 */
name|spinlock_t
name|lock
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
name|COND_FLAGS_PRIVATE
value|0x01
end_define

begin_define
define|#
directive|define
name|COND_FLAGS_INITED
value|0x02
end_define

begin_define
define|#
directive|define
name|COND_FLAGS_BUSY
value|0x04
end_define

begin_comment
comment|/*  * Static cond initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_COND_STATIC_INITIALIZER
define|\
value|{ COND_TYPE_FAST, TAILQ_INITIALIZER, NULL, NULL, \ 	0, _SPINLOCK_INITIALIZER }
end_define

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
comment|/* Size of red zone at the end of each stack. */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_STACK_GUARD
value|4096
end_define

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
comment|/* Address immediately beyond the beginning of the initial thread stack. */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_DEFAULT_PRIORITY
value|64
end_define

begin_define
define|#
directive|define
name|PTHREAD_MAX_PRIORITY
value|126
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
name|_POSIX_THREAD_ATTR_STACKSIZE
end_define

begin_comment
comment|/*  * Clock resolution in nanoseconds.  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_RES_NSEC
value|10000000
end_define

begin_comment
comment|/*  * Time slice period in microseconds.  */
end_comment

begin_define
define|#
directive|define
name|TIMESLICE_USEC
value|100000
end_define

begin_struct
struct|struct
name|pthread_key
block|{
name|spinlock_t
name|lock
decl_stmt|;
specifier|volatile
name|int
name|allocated
decl_stmt|;
specifier|volatile
name|int
name|count
decl_stmt|;
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

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
name|PS_SIGTHREAD
block|,
name|PS_MUTEX_WAIT
block|,
name|PS_COND_WAIT
block|,
name|PS_FDLR_WAIT
block|,
name|PS_FDLW_WAIT
block|,
name|PS_FDR_WAIT
block|,
name|PS_FDW_WAIT
block|,
name|PS_FILE_WAIT
block|,
name|PS_POLL_WAIT
block|,
name|PS_SELECT_WAIT
block|,
name|PS_SLEEP_WAIT
block|,
name|PS_WAIT_WAIT
block|,
name|PS_SIGSUSPEND
block|,
name|PS_SIGWAIT
block|,
name|PS_SPINBLOCK
block|,
name|PS_JOIN
block|,
name|PS_SUSPENDED
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

begin_comment
comment|/*  * File descriptor table structure.  */
end_comment

begin_struct
struct|struct
name|fd_table_entry
block|{
comment|/* 	 * Lock for accesses to this file descriptor table 	 * entry. This is passed to _spinlock() to provide atomic 	 * access to this structure. It does *not* represent the 	 * state of the lock on the file descriptor. 	 */
name|spinlock_t
name|lock
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread
argument_list|)
name|r_queue
expr_stmt|;
comment|/* Read queue.                        */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread
argument_list|)
name|w_queue
expr_stmt|;
comment|/* Write queue.                       */
name|struct
name|pthread
modifier|*
name|r_owner
decl_stmt|;
comment|/* Ptr to thread owning read lock.    */
name|struct
name|pthread
modifier|*
name|w_owner
decl_stmt|;
comment|/* Ptr to thread owning write lock.   */
name|char
modifier|*
name|r_fname
decl_stmt|;
comment|/* Ptr to read lock source file name  */
name|int
name|r_lineno
decl_stmt|;
comment|/* Read lock source line number.      */
name|char
modifier|*
name|w_fname
decl_stmt|;
comment|/* Ptr to write lock source file name */
name|int
name|w_lineno
decl_stmt|;
comment|/* Write lock source line number.     */
name|int
name|r_lockcount
decl_stmt|;
comment|/* Count for FILE read locks.         */
name|int
name|w_lockcount
decl_stmt|;
comment|/* Count for FILE write locks.        */
name|int
name|flags
decl_stmt|;
comment|/* Flags used in open.                */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_poll_data
block|{
name|int
name|nfds
decl_stmt|;
name|struct
name|pollfd
modifier|*
name|fds
decl_stmt|;
block|}
struct|;
end_struct

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
specifier|const
name|sigset_t
modifier|*
name|sigwait
decl_stmt|;
comment|/* Waiting on a signal in sigwait */
struct|struct
block|{
name|short
name|fd
decl_stmt|;
comment|/* Used when thread waiting on fd */
name|short
name|branch
decl_stmt|;
comment|/* Line number, for debugging.    */
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* Source file name for debugging.*/
block|}
name|fd
struct|;
name|struct
name|pthread_poll_data
modifier|*
name|poll_data
decl_stmt|;
name|spinlock_t
modifier|*
name|spinlock
decl_stmt|;
block|}
union|;
end_union

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
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__i386__
argument_list|)
comment|/* 	 * Saved floating point registers on systems where they are not 	 * saved in the signal context. 	 */
name|char
name|saved_fp
index|[
literal|108
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* 	 * Saved signal context used in call to sigreturn by 	 * _thread_kern_sched if sig_saved is TRUE. 	 */
name|ucontext_t
name|saved_sigcontext
decl_stmt|;
comment|/*  	 * Saved jump buffer used in call to longjmp by _thread_kern_sched 	 * if sig_saved is FALSE. 	 */
name|jmp_buf
name|saved_jmp_buf
decl_stmt|;
comment|/* 	 * TRUE if the last state saved was a signal context. FALSE if the 	 * last state saved was a jump buffer. 	 */
name|int
name|sig_saved
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
define|#
directive|define
name|PTHREAD_CANCEL_NEEDED
value|0x0010
name|int
name|cancelflags
decl_stmt|;
comment|/* 	 * Current signal mask and pending signals. 	 */
name|sigset_t
name|sigmask
decl_stmt|;
name|sigset_t
name|sigpend
decl_stmt|;
comment|/* Thread state: */
name|enum
name|pthread_state
name|state
decl_stmt|;
comment|/* Time that this thread was last made active. */
name|struct
name|timeval
name|last_active
decl_stmt|;
comment|/* Time that this thread was last made inactive. */
name|struct
name|timeval
name|last_inactive
decl_stmt|;
comment|/* 	 * Number of microseconds accumulated by this thread when 	 * time slicing is active. 	 */
name|long
name|slice_usec
decl_stmt|;
comment|/* 	 * Incremental priority accumulated by thread while it is ready to 	 * run but is denied being run. 	 */
name|int
name|inc_prio
decl_stmt|;
comment|/* 	 * Time to wake up thread. This is used for sleeping threads and 	 * for any operation which may time out (such as select). 	 */
name|struct
name|timespec
name|wakeup_time
decl_stmt|;
comment|/* TRUE if operation has timed out. */
name|int
name|timeout
decl_stmt|;
comment|/* 	 * Error variable used instead of errno. The function __error() 	 * returns a pointer to this.  	 */
name|int
name|error
decl_stmt|;
comment|/* Join queue head and link for waiting threads: */
name|TAILQ_HEAD
argument_list|(
argument|join_head
argument_list|,
argument|pthread
argument_list|)
name|join_queue
expr_stmt|;
comment|/* 	 * The current thread can belong to only one scheduling queue at 	 * a time (ready or waiting queue).  It can also belong to (only) 	 * one of: 	 * 	 *   o A queue of threads waiting for a mutex 	 *   o A queue of threads waiting for a condition variable 	 *   o A queue of threads waiting for another thread to terminate 	 *     (the join queue above) 	 *   o A queue of threads waiting for a file descriptor lock 	 *   o A queue of threads needing work done by the kernel thread 	 *     (waiting for a spinlock or file I/O) 	 * 	 * Use pqe for the scheduling queue link (both ready and waiting), 	 * and qe for other links. 	 */
comment|/* Priority queue entry for this thread: */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|pqe
expr_stmt|;
comment|/* Queue entry for this thread: */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|qe
expr_stmt|;
comment|/* Wait data. */
name|union
name|pthread_wait_data
name|data
decl_stmt|;
comment|/* 	 * Allocated for converting select into poll. 	 */
name|struct
name|pthread_poll_data
name|poll_data
decl_stmt|;
comment|/* 	 * Set to TRUE if a blocking operation was 	 * interrupted by a signal: 	 */
name|int
name|interrupted
decl_stmt|;
comment|/* Signal number when in state PS_SIGWAIT: */
name|int
name|signo
decl_stmt|;
comment|/* 	 * Set to non-zero when this thread has deferred signals. 	 * We allow for recursive deferral. 	 */
name|int
name|sig_defer_count
decl_stmt|;
comment|/* 	 * Set to TRUE if this thread should yield after undeferring 	 * signals. 	 */
name|int
name|yield_on_sig_undefer
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
value|0x0004
comment|/* in condition queue using qe link*/
define|#
directive|define
name|PTHREAD_FLAGS_IN_WORKQ
value|0x0008
comment|/* in work queue using qe link */
define|#
directive|define
name|PTHREAD_FLAGS_IN_WAITQ
value|0x0010
comment|/* in waiting queue using pqe link */
define|#
directive|define
name|PTHREAD_FLAGS_IN_PRIOQ
value|0x0020
comment|/* in priority queue using pqe link */
define|#
directive|define
name|PTHREAD_FLAGS_IN_MUTEXQ
value|0x0040
comment|/* in mutex queue using qe link */
define|#
directive|define
name|PTHREAD_FLAGS_IN_FILEQ
value|0x0080
comment|/* in file lock queue using qe link */
define|#
directive|define
name|PTHREAD_FLAGS_IN_FDQ
value|0x0100
comment|/* in fd lock queue using qe link */
define|#
directive|define
name|PTHREAD_FLAGS_TRACE
value|0x0200
comment|/* for debugging purposes */
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
specifier|const
name|void
modifier|*
modifier|*
name|specific_data
decl_stmt|;
name|int
name|specific_data_count
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
comment|/* Spare thread stack. */
end_comment

begin_struct
struct|struct
name|stack
block|{
name|SLIST_ENTRY
argument_list|(
argument|stack
argument_list|)
name|qe
expr_stmt|;
comment|/* Queue entry for this stack. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Global variables for the uthread kernel.  */
end_comment

begin_comment
comment|/* Kernel thread structure used when there are no running threads: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread
name|_thread_kern_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ptr to the thread structure for the running thread: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread
modifier|*
specifier|volatile
name|_thread_run
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
operator|&
name|_thread_kern_thread
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
comment|/* Ptr to the thread structure for the last user thread to run: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread
modifier|*
specifier|volatile
name|_last_user_thread
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
operator|&
name|_thread_kern_thread
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
comment|/*  * Ptr to the thread running in single-threaded mode or NULL if  * running multi-threaded (default POSIX behaviour).  */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread
modifier|*
specifier|volatile
name|_thread_single
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
comment|/*  * Array of kernel pipe file descriptors that are used to ensure that  * no signals are missed in calls to _select.  */
end_comment

begin_decl_stmt
name|SCLASS
name|int
name|_thread_kern_pipe
index|[
literal|2
index|]
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
block|{
operator|-
literal|1
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

begin_decl_stmt
name|SCLASS
name|int
specifier|volatile
name|_queue_signals
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
literal|0
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
name|_thread_kern_in_sched
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
literal|0
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
comment|/* Last time that an incremental priority update was performed: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|timeval
name|kern_inc_prio_time
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
block|{
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

begin_comment
comment|/*  * Standard I/O file descriptors need special flag treatment since  * setting one to non-blocking does all on *BSD. Sigh. This array  * is used to store the initial flag settings.  */
end_comment

begin_decl_stmt
name|SCLASS
name|int
name|_pthread_stdio_flags
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File table information: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|fd_table_entry
modifier|*
modifier|*
name|_thread_fd_table
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
comment|/* Table for polling file descriptors: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pollfd
modifier|*
name|_thread_pfd_table
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

begin_decl_stmt
name|SCLASS
specifier|const
name|int
name|dtablecount
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
literal|4096
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|fd_table_entry
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

begin_decl_stmt
name|SCLASS
name|int
name|_thread_dtablesize
comment|/* Descriptor table size.           */
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
literal|0
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
name|_clock_res_nsec
comment|/* Clock resolution in nsec.	*/
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|CLOCK_RES_NSEC
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
comment|/* Garbage collector mutex and condition variable. */
end_comment

begin_decl_stmt
name|SCLASS
name|pthread_mutex_t
name|_gc_mutex
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
init|=
name|NULL
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

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
name|struct
name|sigaction
name|_thread_sigact
index|[
name|NSIG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Scheduling queues:  */
end_comment

begin_decl_stmt
name|SCLASS
name|pq_queue_t
name|_readyq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|TAILQ_HEAD
argument_list|(,
name|pthread
argument_list|)
name|_waitingq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Work queue:  */
end_comment

begin_decl_stmt
name|SCLASS
name|TAILQ_HEAD
argument_list|(,
name|pthread
argument_list|)
name|_workq
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
comment|/* Indicates that the signal queue needs to be checked. */
end_comment

begin_decl_stmt
name|SCLASS
specifier|volatile
name|int
name|_sigq_check_reqd
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
comment|/* Thread switch hook. */
end_comment

begin_decl_stmt
name|SCLASS
name|pthread_switch_routine_t
name|_sched_switch_hook
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
comment|/*  * Spare stack queue.  Stacks of default size are cached in order to reduce  * thread creation time.  Spare stacks are used in LIFO order to increase cache  * locality.  */
end_comment

begin_decl_stmt
name|SCLASS
name|SLIST_HEAD
argument_list|(,
name|stack
argument_list|)
name|_stackq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Base address of next unallocated default-size stack.  Stacks are allocated  * contiguously, starting below the beginning of the main stack.  When a new  * stack is created, a guard page is created just above it in order to (usually)  * detect attempts by the adjacent stack to trounce the next thread stack. */
end_comment

begin_decl_stmt
name|SCLASS
name|void
modifier|*
name|_next_stack
ifdef|#
directive|ifdef
name|GLOBAL_PTHREAD_PRIVATE
comment|/* main stack top   - main stack size       - stack size            - (red zone + main stack red zone) */
init|=
operator|(
name|void
operator|*
operator|)
name|USRSTACK
operator|-
name|PTHREAD_STACK_INITIAL
operator|-
name|PTHREAD_STACK_DEFAULT
operator|-
operator|(
literal|2
operator|*
name|PTHREAD_STACK_GUARD
operator|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used for _PTHREADS_INVARIANTS checking. */
end_comment

begin_decl_stmt
name|SCLASS
name|int
name|_thread_kern_new_state
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
comment|/* Undefine the storage class specifier: */
end_comment

begin_undef
undef|#
directive|undef
name|SCLASS
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_LOCK_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|_FD_LOCK
parameter_list|(
name|_fd
parameter_list|,
name|_type
parameter_list|,
name|_ts
parameter_list|)
value|_thread_fd_lock_debug(_fd, _type, \ 						_ts, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|_FD_UNLOCK
parameter_list|(
name|_fd
parameter_list|,
name|_type
parameter_list|)
value|_thread_fd_unlock_debug(_fd, _type, \ 						__FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_FD_LOCK
parameter_list|(
name|_fd
parameter_list|,
name|_type
parameter_list|,
name|_ts
parameter_list|)
value|_thread_fd_lock(_fd, _type, _ts)
end_define

begin_define
define|#
directive|define
name|_FD_UNLOCK
parameter_list|(
name|_fd
parameter_list|,
name|_type
parameter_list|)
value|_thread_fd_unlock(_fd, _type)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|_find_dead_thread
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
name|void
name|_funlock_owned
parameter_list|(
name|pthread_t
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
name|_thread_fd_lock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_fd_lock_debug
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dispatch_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_signal
parameter_list|(
name|pthread_t
parameter_list|,
name|int
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
name|int
name|_pq_alloc
parameter_list|(
name|struct
name|pq_queue
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pq_init
parameter_list|(
name|struct
name|pq_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pq_remove
parameter_list|(
name|struct
name|pq_queue
modifier|*
name|pq
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pq_insert_head
parameter_list|(
name|struct
name|pq_queue
modifier|*
name|pq
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pq_insert_tail
parameter_list|(
name|struct
name|pq_queue
modifier|*
name|pq
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pthread
modifier|*
name|_pq_first
parameter_list|(
name|struct
name|pq_queue
modifier|*
name|pq
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PTHREADS_INVARIANTS
argument_list|)
end_if

begin_function_decl
name|void
name|_waitq_insert
parameter_list|(
name|pthread_t
name|pthread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_waitq_remove
parameter_list|(
name|pthread_t
name|pthread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_waitq_setactive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_waitq_clearactive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|_thread_fd_unlock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_fd_unlock_debug
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_fd_unlock_owned
parameter_list|(
name|pthread_t
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
name|_thread_kern_sched
parameter_list|(
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_kern_sched_state
parameter_list|(
name|enum
name|pthread_state
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_kern_sched_state_unlock
parameter_list|(
name|enum
name|pthread_state
name|state
parameter_list|,
name|spinlock_t
modifier|*
name|lock
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_kern_set_timeout
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_kern_sig_defer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_kern_sig_undefer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sig_handler
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sig_handle
parameter_list|(
name|int
parameter_list|,
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sig_init
parameter_list|(
name|void
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
name|_thread_start_sig_handler
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
name|int
name|_thread_fd_table_init
parameter_list|(
name|int
name|fd
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

begin_comment
comment|/* #include<signal.h> */
end_comment

begin_function_decl
name|int
name|_thread_sys_sigaction
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
name|_thread_sys_sigpending
parameter_list|(
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_sigprocmask
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
name|_thread_sys_sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_siginterrupt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_sigpause
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_sigreturn
parameter_list|(
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_sigstack
parameter_list|(
specifier|const
name|struct
name|sigstack
modifier|*
parameter_list|,
name|struct
name|sigstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_sigvec
parameter_list|(
name|int
parameter_list|,
name|struct
name|sigvec
modifier|*
parameter_list|,
name|struct
name|sigvec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_psignal
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|void
argument_list|(
operator|*
name|_thread_sys_signal
argument_list|(
name|int
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|_thread_sys_fchmod
parameter_list|(
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fchflags
parameter_list|(
name|int
parameter_list|,
name|u_long
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
name|_thread_sys_fstatfs
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

begin_function_decl
name|int
name|_thread_sys_pipe
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|_thread_sys_accept
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_bind
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_connect
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getpeername
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getsockname
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getsockopt
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
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_listen
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_setsockopt
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_shutdown
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_socket
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
name|_thread_sys_socketpair
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

begin_function_decl
name|ssize_t
name|_thread_sys_recv
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|_thread_sys_recvfrom
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
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|_thread_sys_recvmsg
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
name|ssize_t
name|_thread_sys_send
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|_thread_sys_sendmsg
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
name|_thread_sys_sendto
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<stdio.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_STDIO_H_
end_ifdef

begin_function_decl
name|FILE
modifier|*
name|_thread_sys_fdopen
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|_thread_sys_fopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|_thread_sys_freopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|_thread_sys_popen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|_thread_sys_tmpfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_ctermid
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_cuserid
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_fgetln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_fgets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_gets
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_tempnam
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_thread_sys_tmpnam
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_feof
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_ferror
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fgetc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fgetpos
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|fpos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fileno
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fprintf
parameter_list|(
name|FILE
modifier|*
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
name|int
name|_thread_sys_fpurge
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fputc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fscanf
parameter_list|(
name|FILE
modifier|*
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
name|int
name|_thread_sys_fseek
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fsetpos
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|fpos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getw
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_putc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_puts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_putw
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_remove
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_rename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_scanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_setlinebuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_setvbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
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
name|int
name|_thread_sys_sprintf
parameter_list|(
name|char
modifier|*
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
name|int
name|_thread_sys_sscanf
parameter_list|(
specifier|const
name|char
modifier|*
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
name|int
name|_thread_sys_ungetc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_vscanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_vsprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_vsscanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|_thread_sys_ftell
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|_thread_sys_fread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|_thread_sys_fwrite
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_clearerr
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_perror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_rewind
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_setbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_setbuffer
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
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
comment|/* #include<unistd.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UNISTD_H_
end_ifdef

begin_function_decl
name|char
modifier|*
name|_thread_sys_ttyname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_dup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_dup2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_exect
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
name|int
name|_thread_sys_execve
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
name|int
name|_thread_sys_fchdir
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fchown
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
name|int
name|_thread_sys_fsync
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_ftruncate
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_pause
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_pipe
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|_thread_sys_lseek
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|_thread_sys_fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|_thread_sys_tcgetpgrp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|_thread_sys_read
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
name|_thread_sys_write
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

begin_function_decl
name|void
name|_thread_sys__exit
parameter_list|(
name|int
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
name|_thread_sys_creat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_fcntl
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
name|_thread_sys_flock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_open
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
comment|/* #include<sys/ioctl.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_IOCTL_H_
end_ifdef

begin_function_decl
name|int
name|_thread_sys_ioctl
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
comment|/* #include<dirent.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DIRENT_H_
end_ifdef

begin_function_decl
name|DIR
modifier|*
name|___thread_sys_opendir2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DIR
modifier|*
name|_thread_sys_opendir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_alphasort
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_scandir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|dirent
modifier|*
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|dirent
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_closedir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thread_sys_getdirentries
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

begin_function_decl
name|long
name|_thread_sys_telldir
parameter_list|(
specifier|const
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dirent
modifier|*
name|_thread_sys_readdir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_rewinddir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_sys_seekdir
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|long
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
name|_thread_sys_readv
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
name|_thread_sys_writev
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
name|_thread_sys_wait
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|_thread_sys_waitpid
parameter_list|(
name|pid_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|_thread_sys_wait3
parameter_list|(
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

begin_function_decl
name|pid_t
name|_thread_sys_wait4
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
comment|/* #include<poll.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_POLL_H_
end_ifdef

begin_function_decl
name|int
name|_thread_sys_poll
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
comment|/* #include<sys/mman.h> */
end_comment

begin_function_decl
name|int
name|_thread_sys_msync
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

