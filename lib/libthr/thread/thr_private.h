begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005 Daniel M. Eischen<deischen@freebsd.org>  * Copyright (c) 2005 David Xu<davidxu@freebsd.org>  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|<sys/thr.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__hidden
end_ifndef

begin_define
define|#
directive|define
name|__hidden
value|__attribute__((visibility("hidden")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pthread_md.h"
end_include

begin_include
include|#
directive|include
file|"thr_umtx.h"
end_include

begin_include
include|#
directive|include
file|"thread_db.h"
end_include

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|pthreadlist
argument_list|,
argument|pthread
argument_list|)
name|pthreadlist
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|atfork_head
argument_list|,
argument|pthread_atfork
argument_list|)
name|atfork_head
expr_stmt|;
end_typedef

begin_comment
comment|/* Signal to do cancellation */
end_comment

begin_define
define|#
directive|define
name|SIGCANCEL
value|32
end_define

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
value|_thread_printf(STDOUT_FILENO, ##args)
end_define

begin_define
define|#
directive|define
name|stderr_debug
parameter_list|(
name|args
modifier|...
parameter_list|)
value|_thread_printf(STDOUT_FILENO, ##args)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_PTHREADS_INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|THR_ASSERT
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
value|do {	\ 	if (__predict_false(!(cond)))	\ 		PANIC(msg);		\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|THR_ASSERT
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_define
define|#
directive|define
name|STATIC_LIB_REQUIRE
parameter_list|(
name|name
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STATIC_LIB_REQUIRE
parameter_list|(
name|name
parameter_list|)
value|__asm (".globl " #name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMESPEC_ADD
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|val
parameter_list|)
define|\
value|do { 							\ 		(dst)->tv_sec = (src)->tv_sec + (val)->tv_sec;	\ 		(dst)->tv_nsec = (src)->tv_nsec + (val)->tv_nsec; \ 		if ((dst)->tv_nsec>= 1000000000) {		\ 			(dst)->tv_sec++;			\ 			(dst)->tv_nsec -= 1000000000;		\ 		}						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TIMESPEC_SUB
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|val
parameter_list|)
define|\
value|do { 							\ 		(dst)->tv_sec = (src)->tv_sec - (val)->tv_sec;	\ 		(dst)->tv_nsec = (src)->tv_nsec - (val)->tv_nsec; \ 		if ((dst)->tv_nsec< 0) {			\ 			(dst)->tv_sec--;			\ 			(dst)->tv_nsec += 1000000000;		\ 		}						\ 	} while (0)
end_define

begin_struct
struct|struct
name|pthread_mutex
block|{
comment|/* 	 * Lock for accesses to this structure. 	 */
specifier|volatile
name|umtx_t
name|m_lock
decl_stmt|;
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
name|long
name|m_flags
decl_stmt|;
name|int
name|m_count
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

begin_define
define|#
directive|define
name|PTHREAD_MUTEXATTR_STATIC_INITIALIZER
define|\
value|{ PTHREAD_MUTEX_DEFAULT, PTHREAD_PRIO_NONE, 0, MUTEX_FLAGS_PRIVATE }
end_define

begin_struct
struct|struct
name|pthread_cond
block|{
comment|/* 	 * Lock for accesses to this structure. 	 */
specifier|volatile
name|umtx_t
name|c_lock
decl_stmt|;
specifier|volatile
name|umtx_t
name|c_seqno
decl_stmt|;
specifier|volatile
name|int
name|c_waiters
decl_stmt|;
specifier|volatile
name|int
name|c_wakeups
decl_stmt|;
name|int
name|c_pshared
decl_stmt|;
name|int
name|c_clockid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_cond_attr
block|{
name|int
name|c_pshared
decl_stmt|;
name|int
name|c_clockid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_barrier
block|{
specifier|volatile
name|umtx_t
name|b_lock
decl_stmt|;
specifier|volatile
name|umtx_t
name|b_cycle
decl_stmt|;
specifier|volatile
name|int
name|b_count
decl_stmt|;
specifier|volatile
name|int
name|b_waiters
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_barrierattr
block|{
name|int
name|pshared
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_spinlock
block|{
specifier|volatile
name|umtx_t
name|s_lock
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
name|int
name|onstack
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|THR_CLEANUP_PUSH
parameter_list|(
name|td
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
value|{		\ 	struct pthread_cleanup __cup;			\ 							\ 	__cup.routine = func;				\ 	__cup.routine_arg = arg;			\ 	__cup.onstack = 1;				\ 	__cup.next = (td)->cleanup;			\ 	(td)->cleanup =&__cup;
end_define

begin_define
define|#
directive|define
name|THR_CLEANUP_POP
parameter_list|(
name|td
parameter_list|,
name|exec
parameter_list|)
define|\
value|(td)->cleanup = __cup.next;			\ 	if ((exec) != 0)				\ 		__cup.routine(__cup.routine_arg);	\ }
end_define

begin_struct
struct|struct
name|pthread_atfork
block|{
name|TAILQ_ENTRY
argument_list|(
argument|pthread_atfork
argument_list|)
name|qe
expr_stmt|;
name|void
function_decl|(
modifier|*
name|prepare
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|parent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|child
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
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
define|#
directive|define
name|THR_STACK_USER
value|0x100
comment|/* 0xFF reserved for<pthread.h> */
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
name|THR_CREATE_RUNNING
value|0
end_define

begin_define
define|#
directive|define
name|THR_CREATE_SUSPENDED
value|1
end_define

begin_comment
comment|/*  * Miscellaneous definitions.  */
end_comment

begin_define
define|#
directive|define
name|THR_STACK_DEFAULT
value|(sizeof(void *) / 4 * 1024 * 1024)
end_define

begin_comment
comment|/*  * Maximum size of initial thread's stack.  This perhaps deserves to be larger  * than the stacks of other threads, since many applications are likely to run  * almost entirely on this stack.  */
end_comment

begin_define
define|#
directive|define
name|THR_STACK_INITIAL
value|(THR_STACK_DEFAULT * 2)
end_define

begin_comment
comment|/*  * Define the different priority ranges.  All applications have thread  * priorities constrained within 0-31.  The threads library raises the  * priority when delivering signals in order to ensure that signal  * delivery happens (from the POSIX spec) "as soon as possible".  * In the future, the threads library will also be able to map specific  * threads into real-time (cooperating) processes or kernel threads.  * The RT and SIGNAL priorities will be used internally and added to  * thread base priorities so that the scheduling queue can handle both  * normal and RT priority threads with and without signal handling.  *  * The approach taken is that, within each class, signal delivery  * always has priority over thread execution.  */
end_comment

begin_define
define|#
directive|define
name|THR_DEFAULT_PRIORITY
value|15
end_define

begin_define
define|#
directive|define
name|THR_MIN_PRIORITY
value|0
end_define

begin_define
define|#
directive|define
name|THR_MAX_PRIORITY
value|31
end_define

begin_comment
comment|/* 0x1F */
end_comment

begin_define
define|#
directive|define
name|THR_SIGNAL_PRIORITY
value|32
end_define

begin_comment
comment|/* 0x20 */
end_comment

begin_define
define|#
directive|define
name|THR_RT_PRIORITY
value|64
end_define

begin_comment
comment|/* 0x40 */
end_comment

begin_define
define|#
directive|define
name|THR_FIRST_PRIORITY
value|THR_MIN_PRIORITY
end_define

begin_define
define|#
directive|define
name|THR_LAST_PRIORITY
define|\
value|(THR_MAX_PRIORITY + THR_SIGNAL_PRIORITY + THR_RT_PRIORITY)
end_define

begin_define
define|#
directive|define
name|THR_BASE_PRIORITY
parameter_list|(
name|prio
parameter_list|)
value|((prio)& THR_MAX_PRIORITY)
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
name|pthread_cond_t
name|read_signal
decl_stmt|;
name|pthread_cond_t
name|write_signal
decl_stmt|;
name|int
name|state
decl_stmt|;
comment|/* 0 = idle>0 = # of readers  -1 = writer */
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
name|PS_DEAD
block|}
enum|;
end_enum

begin_union
union|union
name|pthread_wait_data
block|{
name|pthread_mutex_t
name|mutex
decl_stmt|;
block|}
union|;
end_union

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

begin_struct
struct|struct
name|pthread_key
block|{
specifier|volatile
name|int
name|allocated
decl_stmt|;
specifier|volatile
name|int
name|count
decl_stmt|;
name|int
name|seqno
decl_stmt|;
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
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
name|THR_MAGIC
value|((u_int32_t) 0xd09ba115)
name|u_int32_t
name|magic
decl_stmt|;
comment|/* 	 * Lock for accesses to this thread structure. 	 */
name|umtx_t
name|lock
decl_stmt|;
comment|/* Kernel thread id. */
name|long
name|tid
decl_stmt|;
define|#
directive|define
name|TID_TERMINATED
value|1
comment|/* Internal condition variable cycle number. */
name|umtx_t
name|cycle
decl_stmt|;
comment|/* How many low level locks the thread held. */
name|int
name|locklevel
decl_stmt|;
comment|/* 	 * Set to non-zero when this thread has entered a critical 	 * region.  We allow for recursive entries into critical regions. 	 */
name|int
name|critical_count
decl_stmt|;
comment|/* Signal blocked counter. */
name|int
name|sigblock
decl_stmt|;
comment|/* Queue entry for list of all threads. */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|tle
expr_stmt|;
comment|/* link for all threads in process */
comment|/* Queue entry for GC lists. */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|gcle
expr_stmt|;
comment|/* Hash queue entry. */
name|LIST_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|hle
expr_stmt|;
comment|/* Threads reference count. */
name|int
name|refcount
decl_stmt|;
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
name|struct
name|pthread_attr
name|attr
decl_stmt|;
comment|/* 	 * Cancelability flags  	 */
define|#
directive|define
name|THR_CANCEL_DISABLE
value|0x0001
define|#
directive|define
name|THR_CANCEL_EXITING
value|0x0002
define|#
directive|define
name|THR_CANCEL_AT_POINT
value|0x0004
define|#
directive|define
name|THR_CANCEL_NEEDED
value|0x0008
define|#
directive|define
name|SHOULD_CANCEL
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)& (THR_CANCEL_DISABLE | THR_CANCEL_EXITING |	\ 		 THR_CANCEL_NEEDED)) == THR_CANCEL_NEEDED)
define|#
directive|define
name|SHOULD_ASYNC_CANCEL
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)& (THR_CANCEL_DISABLE | THR_CANCEL_EXITING |	\ 		 THR_CANCEL_NEEDED | THR_CANCEL_AT_POINT)) ==	\ 		 (THR_CANCEL_NEEDED | THR_CANCEL_AT_POINT))
name|int
name|cancelflags
decl_stmt|;
comment|/* Thread temporary signal mask. */
name|sigset_t
name|sigmask
decl_stmt|;
comment|/* Thread state: */
name|umtx_t
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
comment|/* 	 * The current thread can belong to a priority mutex queue. 	 * This is the synchronization queue link. 	 */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|sqe
expr_stmt|;
comment|/* Wait data. */
name|union
name|pthread_wait_data
name|data
decl_stmt|;
name|int
name|sflags
decl_stmt|;
define|#
directive|define
name|THR_FLAGS_IN_SYNCQ
value|0x0001
comment|/* Miscellaneous flags; only set with scheduling lock held. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|THR_FLAGS_PRIVATE
value|0x0001
define|#
directive|define
name|THR_FLAGS_NEED_SUSPEND
value|0x0002
comment|/* thread should be suspended */
define|#
directive|define
name|THR_FLAGS_SUSPENDED
value|0x0004
comment|/* thread is suspended */
comment|/* Thread list flags; only set with thread list lock held. */
name|int
name|tlflags
decl_stmt|;
define|#
directive|define
name|TLFLAGS_GC_SAFE
value|0x0001
comment|/* thread safe for cleaning */
define|#
directive|define
name|TLFLAGS_IN_TDLIST
value|0x0002
comment|/* thread in all thread list */
define|#
directive|define
name|TLFLAGS_IN_GCLIST
value|0x0004
comment|/* thread in gc list */
define|#
directive|define
name|TLFLAGS_DETACHED
value|0x0008
comment|/* thread is detached */
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
comment|/* Queue of currently owned simple type mutexes. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread_mutex
argument_list|)
name|mutexq
expr_stmt|;
comment|/* Queue of currently owned priority type mutexs. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread_mutex
argument_list|)
name|pri_mutexq
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
comment|/* Number rwlocks rdlocks held. */
name|int
name|rdlock_count
decl_stmt|;
comment|/* 	 * Current locks bitmap for rtld. */
name|int
name|rtld_bits
decl_stmt|;
comment|/* Thread control block */
name|struct
name|tcb
modifier|*
name|tcb
decl_stmt|;
comment|/* Cleanup handlers Link List */
name|struct
name|pthread_cleanup
modifier|*
name|cleanup
decl_stmt|;
comment|/* Enable event reporting */
name|int
name|report_events
decl_stmt|;
comment|/* Event mask */
name|int
name|event_mask
decl_stmt|;
comment|/* Event */
name|td_event_msg_t
name|event_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|THR_IN_CRITICAL
parameter_list|(
name|thrd
parameter_list|)
define|\
value|(((thrd)->locklevel> 0) ||			\ 	((thrd)->critical_count> 0))
end_define

begin_define
define|#
directive|define
name|THR_UMTX_TRYLOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|_thr_umtx_trylock((lck), (thrd)->tid)
end_define

begin_define
define|#
directive|define
name|THR_UMTX_LOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|_thr_umtx_lock((lck), (thrd)->tid)
end_define

begin_define
define|#
directive|define
name|THR_UMTX_TIMEDLOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|,
name|timo
parameter_list|)
define|\
value|_thr_umtx_timedlock((lck), (thrd)->tid, (timo))
end_define

begin_define
define|#
directive|define
name|THR_UMTX_UNLOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|_thr_umtx_unlock((lck), (thrd)->tid)
end_define

begin_define
define|#
directive|define
name|THR_LOCK_ACQUIRE
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|do {							\ 	(thrd)->locklevel++;				\ 	_thr_umtx_lock(lck, (thrd)->tid);		\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_PTHREADS_INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|THR_ASSERT_LOCKLEVEL
parameter_list|(
name|thrd
parameter_list|)
define|\
value|do {							\ 	if (__predict_false((thrd)->locklevel<= 0))	\ 		_thr_assert_lock_level();		\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|THR_ASSERT_LOCKLEVEL
parameter_list|(
name|thrd
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|THR_LOCK_RELEASE
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|do {							\ 	THR_ASSERT_LOCKLEVEL(thrd);			\ 	_thr_umtx_unlock((lck), (thrd)->tid);		\ 	(thrd)->locklevel--;				\ 	_thr_ast(thrd);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_LOCK
parameter_list|(
name|curthrd
parameter_list|)
value|THR_LOCK_ACQUIRE(curthrd,&(curthrd)->lock)
end_define

begin_define
define|#
directive|define
name|THR_UNLOCK
parameter_list|(
name|curthrd
parameter_list|)
value|THR_LOCK_RELEASE(curthrd,&(curthrd)->lock)
end_define

begin_define
define|#
directive|define
name|THR_THREAD_LOCK
parameter_list|(
name|curthrd
parameter_list|,
name|thr
parameter_list|)
value|THR_LOCK_ACQUIRE(curthrd,&(thr)->lock)
end_define

begin_define
define|#
directive|define
name|THR_THREAD_UNLOCK
parameter_list|(
name|curthrd
parameter_list|,
name|thr
parameter_list|)
value|THR_LOCK_RELEASE(curthrd,&(thr)->lock)
end_define

begin_define
define|#
directive|define
name|THREAD_LIST_LOCK
parameter_list|(
name|curthrd
parameter_list|)
define|\
value|do {								\ 	THR_LOCK_ACQUIRE((curthrd),&_thr_list_lock);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|THREAD_LIST_UNLOCK
parameter_list|(
name|curthrd
parameter_list|)
define|\
value|do {								\ 	THR_LOCK_RELEASE((curthrd),&_thr_list_lock);		\ } while (0)
end_define

begin_comment
comment|/*  * Macros to insert/remove threads to the all thread list and  * the gc list.  */
end_comment

begin_define
define|#
directive|define
name|THR_LIST_ADD
parameter_list|(
name|thrd
parameter_list|)
value|do {					\ 	if (((thrd)->tlflags& TLFLAGS_IN_TDLIST) == 0) {	\ 		TAILQ_INSERT_HEAD(&_thread_list, thrd, tle);	\ 		_thr_hash_add(thrd);				\ 		(thrd)->tlflags |= TLFLAGS_IN_TDLIST;		\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_LIST_REMOVE
parameter_list|(
name|thrd
parameter_list|)
value|do {				\ 	if (((thrd)->tlflags& TLFLAGS_IN_TDLIST) != 0) {	\ 		TAILQ_REMOVE(&_thread_list, thrd, tle);		\ 		_thr_hash_remove(thrd);				\ 		(thrd)->tlflags&= ~TLFLAGS_IN_TDLIST;		\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_GCLIST_ADD
parameter_list|(
name|thrd
parameter_list|)
value|do {				\ 	if (((thrd)->tlflags& TLFLAGS_IN_GCLIST) == 0) {	\ 		TAILQ_INSERT_HEAD(&_thread_gc_list, thrd, gcle);\ 		(thrd)->tlflags |= TLFLAGS_IN_GCLIST;		\ 		_gc_count++;					\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_GCLIST_REMOVE
parameter_list|(
name|thrd
parameter_list|)
value|do {				\ 	if (((thrd)->tlflags& TLFLAGS_IN_GCLIST) != 0) {	\ 		TAILQ_REMOVE(&_thread_gc_list, thrd, gcle);	\ 		(thrd)->tlflags&= ~TLFLAGS_IN_GCLIST;		\ 		_gc_count--;					\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|GC_NEEDED
parameter_list|()
value|(_gc_count>= 5)
end_define

begin_define
define|#
directive|define
name|THR_IN_SYNCQ
parameter_list|(
name|thrd
parameter_list|)
value|(((thrd)->sflags& THR_FLAGS_IN_SYNCQ) != 0)
end_define

begin_define
define|#
directive|define
name|SHOULD_REPORT_EVENT
parameter_list|(
name|curthr
parameter_list|,
name|e
parameter_list|)
define|\
value|(curthr->report_events&& 			\ 	 (((curthr)->event_mask | _thread_event_mask )& e) != 0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|__isthreaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Global variables for the pthread kernel.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|_usrstack
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|_thr_initial
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_scope_system
name|__hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For debugger */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_libthr_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thread_event_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|_thread_last_event
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of all threads: */
end_comment

begin_decl_stmt
specifier|extern
name|pthreadlist
name|_thread_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of threads needing GC: */
end_comment

begin_decl_stmt
specifier|extern
name|pthreadlist
name|_thread_gc_list
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thread_active_threads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|atfork_head
name|_thr_atfork_list
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_thr_atfork_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default thread attributes: */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pthread_attr
name|_pthread_attr_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default mutex attributes: */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pthread_mutex_attr
name|_pthread_mutexattr_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default condition variable attributes: */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pthread_cond_attr
name|_pthread_condattr_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pid_t
name|_thr_pid
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_guard_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_stack_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_stack_initial
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_page_size
name|__hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Garbage thread count. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_gc_count
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_mutex_static_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_cond_static_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_rwlock_static_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_keytable_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_thr_list_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|umtx_t
name|_thr_event_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|_thr_once_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_cond_t
name|_thr_once_cv
name|__hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function prototype definitions.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|_thr_setthreaded
argument_list|(
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_cv_lock
argument_list|(
name|pthread_mutex_t
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_cv_unlock
argument_list|(
name|pthread_mutex_t
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_mutex_notify_priochange
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|,
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_reinit
argument_list|(
name|pthread_mutex_t
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_mutex_fork
argument_list|(
expr|struct
name|pthread
operator|*
name|curthread
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_mutex_unlock_private
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_libpthread_init
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

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
name|_pthread_cond_init
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|,
specifier|const
name|pthread_condattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_cond_destroy
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_cond_wait
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|,
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_cond_timedwait
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|,
name|pthread_mutex_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_cond_signal
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_cond_broadcast
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_create
parameter_list|(
name|pthread_t
modifier|*
name|thread
parameter_list|,
specifier|const
name|pthread_attr_t
modifier|*
name|attr
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
name|arg
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
name|int
name|_pthread_rwlock_init
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|,
specifier|const
name|pthread_rwlockattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_rwlock_destroy
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pthread
modifier|*
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
name|void
name|_pthread_testcancel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pthread_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pthread_cleanup_push
parameter_list|(
name|void
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|routine_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pthread_cleanup_pop
parameter_list|(
name|int
name|execute
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|_thr_alloc
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thread_exit
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|char
operator|*
argument_list|)
name|__hidden
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_exit_cleanup
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_ref_add
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|,
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_ref_delete
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_ref_delete_unlocked
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_find_thread
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|,
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_rtld_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_rtld_fini
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_stack_alloc
argument_list|(
expr|struct
name|pthread_attr
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_stack_free
argument_list|(
expr|struct
name|pthread_attr
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_free
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_gc
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thread_cleanupspecific
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thread_dump_info
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thread_printf
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_spinlock_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_cancel_enter
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_cancel_leave
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_block
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_unblock
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_deinit
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_send_sig
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
name|int
name|sig
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_list_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_hash_add
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_hash_remove
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|_thr_hash_find
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_link
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_unlink
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_suspend_check
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_assert_lock_level
argument_list|(
name|void
argument_list|)
name|__hidden
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_ast
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_timer_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_report_creation
argument_list|(
expr|struct
name|pthread
operator|*
name|curthread
argument_list|,
expr|struct
name|pthread
operator|*
name|newthread
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_report_death
argument_list|(
expr|struct
name|pthread
operator|*
name|curthread
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_thread_bp_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_bp_death
parameter_list|(
name|void
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
comment|/* #inclde<sched.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SCHED_H_
end_ifdef

begin_function_decl
name|int
name|__sys_sched_yield
parameter_list|(
name|void
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
name|__sys_kill
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|__sys_sigpending
parameter_list|(
name|sigset_t
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
name|__sys_sigsuspend
parameter_list|(
specifier|const
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
name|ssize_t
name|__sys_recv
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
comment|/* #include<time.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_TIME_H_
end_ifdef

begin_function_decl
name|int
name|__sys_nanosleep
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
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
name|int
name|__sys_fork
parameter_list|(
name|void
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
name|pid_t
name|__sys_getpid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_select
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
name|__sys_sigwait
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sigtimedwait
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sigwaitinfo
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|,
name|siginfo_t
modifier|*
name|info
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

begin_function
specifier|static
specifier|inline
name|int
name|_thr_isthreaded
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__isthreaded
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|_thr_is_inited
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_thr_initial
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|_thr_check_init
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|_thr_initial
operator|==
name|NULL
condition|)
name|_libpthread_init
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_THR_PRIVATE_H */
end_comment

end_unit

