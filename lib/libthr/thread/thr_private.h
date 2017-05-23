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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpuset.h>
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
file|<stdbool.h>
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

begin_macro
name|__NULLABILITY_PRAGMA_PUSH
end_macro

begin_define
define|#
directive|define
name|SYM_FB10
parameter_list|(
name|sym
parameter_list|)
value|__CONCAT(sym, _fb10)
end_define

begin_define
define|#
directive|define
name|SYM_FBP10
parameter_list|(
name|sym
parameter_list|)
value|__CONCAT(sym, _fbp10)
end_define

begin_define
define|#
directive|define
name|WEAK_REF
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
value|__weak_reference(sym, alias)
end_define

begin_define
define|#
directive|define
name|SYM_COMPAT
parameter_list|(
name|sym
parameter_list|,
name|impl
parameter_list|,
name|ver
parameter_list|)
value|__sym_compat(sym, impl, ver)
end_define

begin_define
define|#
directive|define
name|SYM_DEFAULT
parameter_list|(
name|sym
parameter_list|,
name|impl
parameter_list|,
name|ver
parameter_list|)
value|__sym_default(sym, impl, ver)
end_define

begin_define
define|#
directive|define
name|FB10_COMPAT
parameter_list|(
name|func
parameter_list|,
name|sym
parameter_list|)
define|\
value|WEAK_REF(func, SYM_FB10(sym));			\ 	SYM_COMPAT(sym, SYM_FB10(sym), FBSD_1.0)
end_define

begin_define
define|#
directive|define
name|FB10_COMPAT_PRIVATE
parameter_list|(
name|func
parameter_list|,
name|sym
parameter_list|)
define|\
value|WEAK_REF(func, SYM_FBP10(sym));			\ 	SYM_DEFAULT(sym, SYM_FBP10(sym), FBSDprivate_1.0)
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|_PTHREAD_FORCED_UNWIND
end_ifdef

begin_define
define|#
directive|define
name|_BSD_SOURCE
end_define

begin_include
include|#
directive|include
file|<unwind.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|mutex_queue
argument_list|,
name|pthread_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Signal to do cancellation */
end_comment

begin_define
define|#
directive|define
name|SIGCANCEL
value|SIGTHR
end_define

begin_comment
comment|/*  * Kernel fatal error handler macro.  */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|args
modifier|...
parameter_list|)
value|_thread_exitf(__FILE__, __LINE__, ##args)
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
value|_thread_printf(STDERR_FILENO, ##args)
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

begin_comment
comment|/* Magic cookie set for shared pthread locks and cv's pointers */
end_comment

begin_define
define|#
directive|define
name|THR_PSHARED_PTR
define|\
value|((void *)(uintptr_t)((1ULL<< (NBBY * sizeof(long) - 1)) | 1))
end_define

begin_comment
comment|/* XXX These values should be same as those defined in pthread.h */
end_comment

begin_define
define|#
directive|define
name|THR_MUTEX_INITIALIZER
value|((struct pthread_mutex *)NULL)
end_define

begin_define
define|#
directive|define
name|THR_ADAPTIVE_MUTEX_INITIALIZER
value|((struct pthread_mutex *)1)
end_define

begin_define
define|#
directive|define
name|THR_MUTEX_DESTROYED
value|((struct pthread_mutex *)2)
end_define

begin_define
define|#
directive|define
name|THR_COND_INITIALIZER
value|((struct pthread_cond *)NULL)
end_define

begin_define
define|#
directive|define
name|THR_COND_DESTROYED
value|((struct pthread_cond *)1)
end_define

begin_define
define|#
directive|define
name|THR_RWLOCK_INITIALIZER
value|((struct pthread_rwlock *)NULL)
end_define

begin_define
define|#
directive|define
name|THR_RWLOCK_DESTROYED
value|((struct pthread_rwlock *)1)
end_define

begin_define
define|#
directive|define
name|PMUTEX_FLAG_TYPE_MASK
value|0x0ff
end_define

begin_define
define|#
directive|define
name|PMUTEX_FLAG_PRIVATE
value|0x100
end_define

begin_define
define|#
directive|define
name|PMUTEX_FLAG_DEFERRED
value|0x200
end_define

begin_define
define|#
directive|define
name|PMUTEX_TYPE
parameter_list|(
name|mtxflags
parameter_list|)
value|((mtxflags)& PMUTEX_FLAG_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|PMUTEX_OWNER_ID
parameter_list|(
name|m
parameter_list|)
value|((m)->m_lock.m_owner& ~UMUTEX_CONTESTED)
end_define

begin_define
define|#
directive|define
name|MAX_DEFER_WAITERS
value|50
end_define

begin_comment
comment|/*  * Values for pthread_mutex m_ps indicator.  */
end_comment

begin_define
define|#
directive|define
name|PMUTEX_INITSTAGE_ALLOC
value|0
end_define

begin_define
define|#
directive|define
name|PMUTEX_INITSTAGE_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|PMUTEX_INITSTAGE_DONE
value|2
end_define

begin_struct
struct|struct
name|pthread_mutex
block|{
comment|/* 	 * Lock for accesses to this structure. 	 */
name|struct
name|umutex
name|m_lock
decl_stmt|;
name|int
name|m_flags
decl_stmt|;
name|int
name|m_count
decl_stmt|;
name|int
name|m_spinloops
decl_stmt|;
name|int
name|m_yieldloops
decl_stmt|;
name|int
name|m_ps
decl_stmt|;
comment|/* pshared init stage */
comment|/* 	 * Link for all mutexes a thread currently owns, of the same 	 * prio type. 	 */
name|TAILQ_ENTRY
argument_list|(
argument|pthread_mutex
argument_list|)
name|m_qe
expr_stmt|;
comment|/* Link for all private mutexes a thread currently owns. */
name|TAILQ_ENTRY
argument_list|(
argument|pthread_mutex
argument_list|)
name|m_pqe
expr_stmt|;
name|struct
name|pthread_mutex
modifier|*
name|m_rb_prev
decl_stmt|;
block|}
struct|;
end_struct

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
name|int
name|m_pshared
decl_stmt|;
name|int
name|m_robust
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PTHREAD_MUTEXATTR_STATIC_INITIALIZER
define|\
value|{ PTHREAD_MUTEX_DEFAULT, PTHREAD_PRIO_NONE, 0, MUTEX_FLAGS_PRIVATE, \ 	    PTHREAD_MUTEX_STALLED }
end_define

begin_struct
struct|struct
name|pthread_cond
block|{
name|__uint32_t
name|__has_user_waiters
decl_stmt|;
name|struct
name|ucond
name|kcond
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
name|struct
name|umutex
name|b_lock
decl_stmt|;
name|struct
name|ucond
name|b_cv
decl_stmt|;
name|int64_t
name|b_cycle
decl_stmt|;
name|int
name|b_count
decl_stmt|;
name|int
name|b_waiters
decl_stmt|;
name|int
name|b_refcount
decl_stmt|;
name|int
name|b_destroying
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
name|struct
name|umutex
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
name|prev
decl_stmt|;
name|void
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|routine_arg
decl_stmt|;
name|int
name|onheap
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
value|{		\ 	struct pthread_cleanup __cup;			\ 							\ 	__cup.routine = func;				\ 	__cup.routine_arg = arg;			\ 	__cup.onheap = 0;				\ 	__cup.prev = (td)->cleanup;			\ 	(td)->cleanup =&__cup;
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
value|(td)->cleanup = __cup.prev;			\ 	if ((exec) != 0)				\ 		__cup.routine(__cup.routine_arg);	\ }
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
define|#
directive|define
name|pthread_attr_start_copy
value|sched_policy
name|int
name|sched_policy
decl_stmt|;
name|int
name|sched_inherit
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
name|stackaddr_attr
decl_stmt|;
name|size_t
name|stacksize_attr
decl_stmt|;
name|size_t
name|guardsize_attr
decl_stmt|;
define|#
directive|define
name|pthread_attr_end_copy
value|cpuset
name|cpuset_t
modifier|*
name|cpuset
decl_stmt|;
name|size_t
name|cpusetsize
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wake_addr
block|{
name|struct
name|wake_addr
modifier|*
name|link
decl_stmt|;
name|unsigned
name|int
name|value
decl_stmt|;
name|char
name|pad
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sleepqueue
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread
argument_list|)
name|sq_blocked
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|sleepqueue
argument_list|)
name|sq_freeq
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|sleepqueue
argument_list|)
name|sq_hash
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|sleepqueue
argument_list|)
name|sq_flink
expr_stmt|;
name|void
modifier|*
name|sq_wchan
decl_stmt|;
name|int
name|sq_type
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
comment|/*  * Define priorities returned by kernel.  */
end_comment

begin_define
define|#
directive|define
name|THR_MIN_PRIORITY
value|(_thr_priorities[SCHED_OTHER-1].pri_min)
end_define

begin_define
define|#
directive|define
name|THR_MAX_PRIORITY
value|(_thr_priorities[SCHED_OTHER-1].pri_max)
end_define

begin_define
define|#
directive|define
name|THR_DEF_PRIORITY
value|(_thr_priorities[SCHED_OTHER-1].pri_default)
end_define

begin_define
define|#
directive|define
name|THR_MIN_RR_PRIORITY
value|(_thr_priorities[SCHED_RR-1].pri_min)
end_define

begin_define
define|#
directive|define
name|THR_MAX_RR_PRIORITY
value|(_thr_priorities[SCHED_RR-1].pri_max)
end_define

begin_define
define|#
directive|define
name|THR_DEF_RR_PRIORITY
value|(_thr_priorities[SCHED_RR-1].pri_default)
end_define

begin_comment
comment|/* XXX The SCHED_FIFO should have same priority range as SCHED_RR */
end_comment

begin_define
define|#
directive|define
name|THR_MIN_FIFO_PRIORITY
value|(_thr_priorities[SCHED_FIFO_1].pri_min)
end_define

begin_define
define|#
directive|define
name|THR_MAX_FIFO_PRIORITY
value|(_thr_priorities[SCHED_FIFO-1].pri_max)
end_define

begin_define
define|#
directive|define
name|THR_DEF_FIFO_PRIORITY
value|(_thr_priorities[SCHED_FIFO-1].pri_default)
end_define

begin_struct
struct|struct
name|pthread_prio
block|{
name|int
name|pri_min
decl_stmt|;
name|int
name|pri_max
decl_stmt|;
name|int
name|pri_default
decl_stmt|;
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
name|struct
name|urwlock
name|lock
decl_stmt|;
name|uint32_t
name|owner
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
comment|/*  * lwpid_t is 32bit but kernel thr API exports tid as long type  * to preserve the ABI for M:N model in very early date (r131431).  */
end_comment

begin_define
define|#
directive|define
name|TID
parameter_list|(
name|thread
parameter_list|)
value|((uint32_t) ((thread)->tid))
end_define

begin_comment
comment|/*  * Thread structure.  */
end_comment

begin_struct
struct|struct
name|pthread
block|{
define|#
directive|define
name|_pthread_startzero
value|tid
comment|/* Kernel thread id. */
name|long
name|tid
decl_stmt|;
define|#
directive|define
name|TID_TERMINATED
value|1
comment|/* 	 * Lock for accesses to this thread structure. 	 */
name|struct
name|umutex
name|lock
decl_stmt|;
comment|/* Internal condition variable cycle number. */
name|uint32_t
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
comment|/* Sleep queue entry */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|wle
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
define|#
directive|define
name|SHOULD_CANCEL
parameter_list|(
name|thr
parameter_list|)
define|\
value|((thr)->cancel_pending&& (thr)->cancel_enable&&	\ 	 (thr)->no_cancel == 0)
comment|/* Cancellation is enabled */
name|int
name|cancel_enable
decl_stmt|;
comment|/* Cancellation request is pending */
name|int
name|cancel_pending
decl_stmt|;
comment|/* Thread is at cancellation point */
name|int
name|cancel_point
decl_stmt|;
comment|/* Cancellation is temporarily disabled */
name|int
name|no_cancel
decl_stmt|;
comment|/* Asynchronouse cancellation is enabled */
name|int
name|cancel_async
decl_stmt|;
comment|/* Cancellation is in progress */
name|int
name|cancelling
decl_stmt|;
comment|/* Thread temporary signal mask. */
name|sigset_t
name|sigmask
decl_stmt|;
comment|/* Thread should unblock SIGCANCEL. */
name|int
name|unblock_sigcancel
decl_stmt|;
comment|/* In sigsuspend state */
name|int
name|in_sigsuspend
decl_stmt|;
comment|/* deferred signal info	*/
name|siginfo_t
name|deferred_siginfo
decl_stmt|;
comment|/* signal mask to restore. */
name|sigset_t
name|deferred_sigmask
decl_stmt|;
comment|/* the sigaction should be used for deferred signal. */
name|struct
name|sigaction
name|deferred_sigact
decl_stmt|;
comment|/* deferred signal delivery is performed, do not reenter. */
name|int
name|deferred_run
decl_stmt|;
comment|/* Force new thread to exit. */
name|int
name|force_exit
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
define|#
directive|define
name|THR_FLAGS_DETACHED
value|0x0008
comment|/* thread is detached */
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
comment|/* 	 * Queues of the owned mutexes.  Private queue must have index 	 * + 1 of the corresponding full queue. 	 */
define|#
directive|define
name|TMQ_NORM
value|0
comment|/* NORMAL or PRIO_INHERIT normal */
define|#
directive|define
name|TMQ_NORM_PRIV
value|1
comment|/* NORMAL or PRIO_INHERIT normal priv */
define|#
directive|define
name|TMQ_NORM_PP
value|2
comment|/* PRIO_PROTECT normal mutexes */
define|#
directive|define
name|TMQ_NORM_PP_PRIV
value|3
comment|/* PRIO_PROTECT normal priv */
define|#
directive|define
name|TMQ_ROBUST_PP
value|4
comment|/* PRIO_PROTECT robust mutexes */
define|#
directive|define
name|TMQ_ROBUST_PP_PRIV
value|5
comment|/* PRIO_PROTECT robust priv */
define|#
directive|define
name|TMQ_NITEMS
value|6
name|struct
name|mutex_queue
name|mq
index|[
name|TMQ_NITEMS
index|]
decl_stmt|;
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
ifdef|#
directive|ifdef
name|_PTHREAD_FORCED_UNWIND
name|struct
name|_Unwind_Exception
name|ex
decl_stmt|;
name|void
modifier|*
name|unwind_stackend
decl_stmt|;
name|int
name|unwind_disabled
decl_stmt|;
endif|#
directive|endif
comment|/* 	 * Magic value to help recognize a valid thread structure 	 * from an invalid one: 	 */
define|#
directive|define
name|THR_MAGIC
value|((u_int32_t) 0xd09ba115)
name|u_int32_t
name|magic
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
comment|/* Wait channel */
name|void
modifier|*
name|wchan
decl_stmt|;
comment|/* Referenced mutex. */
name|struct
name|pthread_mutex
modifier|*
name|mutex_obj
decl_stmt|;
comment|/* Thread will sleep. */
name|int
name|will_sleep
decl_stmt|;
comment|/* Number of threads deferred. */
name|int
name|nwaiter_defer
decl_stmt|;
name|int
name|robust_inited
decl_stmt|;
name|uintptr_t
name|robust_list
decl_stmt|;
name|uintptr_t
name|priv_robust_list
decl_stmt|;
name|uintptr_t
name|inact_mtx
decl_stmt|;
comment|/* Deferred threads from pthread_cond_signal. */
name|unsigned
name|int
modifier|*
name|defer_waiters
index|[
name|MAX_DEFER_WAITERS
index|]
decl_stmt|;
define|#
directive|define
name|_pthread_endzero
value|wake_addr
name|struct
name|wake_addr
modifier|*
name|wake_addr
decl_stmt|;
define|#
directive|define
name|WAKE_ADDR
parameter_list|(
name|td
parameter_list|)
value|((td)->wake_addr)
comment|/* Sleep queue */
name|struct
name|sleepqueue
modifier|*
name|sleepqueue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|THR_SHOULD_GC
parameter_list|(
name|thrd
parameter_list|)
define|\
value|((thrd)->refcount == 0&& (thrd)->state == PS_DEAD&&		\ 	 ((thrd)->flags& THR_FLAGS_DETACHED) != 0)
end_define

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
name|THR_CRITICAL_ENTER
parameter_list|(
name|thrd
parameter_list|)
define|\
value|(thrd)->critical_count++
end_define

begin_define
define|#
directive|define
name|THR_CRITICAL_LEAVE
parameter_list|(
name|thrd
parameter_list|)
define|\
value|do {						\ 		(thrd)->critical_count--;		\ 		_thr_ast(thrd);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|THR_UMUTEX_TRYLOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|_thr_umutex_trylock((lck), TID(thrd))
end_define

begin_define
define|#
directive|define
name|THR_UMUTEX_LOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|_thr_umutex_lock((lck), TID(thrd))
end_define

begin_define
define|#
directive|define
name|THR_UMUTEX_TIMEDLOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|,
name|timo
parameter_list|)
define|\
value|_thr_umutex_timedlock((lck), TID(thrd), (timo))
end_define

begin_define
define|#
directive|define
name|THR_UMUTEX_UNLOCK
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|_thr_umutex_unlock((lck), TID(thrd))
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
value|do {							\ 	(thrd)->locklevel++;				\ 	_thr_umutex_lock(lck, TID(thrd));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_LOCK_ACQUIRE_SPIN
parameter_list|(
name|thrd
parameter_list|,
name|lck
parameter_list|)
define|\
value|do {							\ 	(thrd)->locklevel++;				\ 	_thr_umutex_lock_spin(lck, TID(thrd));		\ } while (0)
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
value|do {							\ 	THR_ASSERT_LOCKLEVEL(thrd);			\ 	_thr_umutex_unlock((lck), TID(thrd));		\ 	(thrd)->locklevel--;				\ 	_thr_ast(thrd);					\ } while (0)
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
name|THREAD_LIST_RDLOCK
parameter_list|(
name|curthrd
parameter_list|)
define|\
value|do {								\ 	(curthrd)->locklevel++;					\ 	_thr_rwl_rdlock(&_thr_list_lock);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|THREAD_LIST_WRLOCK
parameter_list|(
name|curthrd
parameter_list|)
define|\
value|do {								\ 	(curthrd)->locklevel++;					\ 	_thr_rwl_wrlock(&_thr_list_lock);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|THREAD_LIST_UNLOCK
parameter_list|(
name|curthrd
parameter_list|)
define|\
value|do {								\ 	_thr_rwl_unlock(&_thr_list_lock);			\ 	(curthrd)->locklevel--;					\ 	_thr_ast(curthrd);					\ } while (0)
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
name|THR_REF_ADD
parameter_list|(
name|curthread
parameter_list|,
name|pthread
parameter_list|)
value|{			\ 	THR_CRITICAL_ENTER(curthread);				\ 	pthread->refcount++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_REF_DEL
parameter_list|(
name|curthread
parameter_list|,
name|pthread
parameter_list|)
value|{			\ 	pthread->refcount--;					\ 	THR_CRITICAL_LEAVE(curthread);				\ } while (0)
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
name|SHOULD_REPORT_EVENT
parameter_list|(
name|curthr
parameter_list|,
name|e
parameter_list|)
define|\
value|(curthr->report_events&& 			\ 	 (((curthr)->event_mask | _thread_event_mask )& e) != 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBC_ISTHREADED_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|__LIBC_ISTHREADED_DECLARED
end_define

begin_decl_stmt
specifier|extern
name|int
name|__isthreaded
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Global variables for the pthread kernel.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
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
name|struct
name|urwlock
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

begin_decl_stmt
specifier|extern
name|struct
name|pthread_mutex_attr
name|_pthread_mutexattr_adaptive_default
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
name|struct
name|pthread_prio
name|_thr_priorities
index|[]
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_is_smp
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|_thr_guard_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|_thr_stack_default
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
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

begin_decl_stmt
specifier|extern
name|int
name|_thr_spinloops
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_yieldloops
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_thr_queuefifo
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
name|struct
name|umutex
name|_mutex_static_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|umutex
name|_cond_static_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|umutex
name|_rwlock_static_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|umutex
name|_keytable_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|urwlock
name|_thr_list_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|umutex
name|_thr_event_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|umutex
name|_suspend_all_lock
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_suspend_all_waiters
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_suspend_all_cycle
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|_single_thread
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
expr|struct
name|pthread_mutex
operator|*
argument_list|,
name|int
argument_list|,
name|bool
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_cv_unlock
argument_list|(
expr|struct
name|pthread_mutex
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_cv_attach
argument_list|(
expr|struct
name|pthread_mutex
operator|*
argument_list|,
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_cv_detach
argument_list|(
expr|struct
name|pthread_mutex
operator|*
argument_list|,
name|int
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_mutex_owned
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
specifier|const
expr|struct
name|pthread_mutex
operator|*
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
name|int
name|_mutex_enter_robust
argument_list|(
expr|struct
name|pthread
operator|*
name|curthread
argument_list|,
expr|struct
name|pthread_mutex
operator|*
name|m
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_mutex_leave_robust
argument_list|(
expr|struct
name|pthread
operator|*
name|curthread
argument_list|,
expr|struct
name|pthread_mutex
operator|*
name|m
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
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__hidden
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thread_exitf
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__hidden
name|__dead2
name|__printflike
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
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
name|_thr_rtld_postfork_child
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
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thread_vprintf
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|va_list
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
name|void
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
name|_thr_cancel_enter2
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
name|_thr_testcancel
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
name|int
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

begin_decl_stmt
name|int
name|_thr_getscheduler
argument_list|(
name|lwpid_t
argument_list|,
name|int
operator|*
argument_list|,
expr|struct
name|sched_param
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_setscheduler
argument_list|(
name|lwpid_t
argument_list|,
name|int
argument_list|,
specifier|const
expr|struct
name|sched_param
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_prefork
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_postfork
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_signal_postfork_child
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_suspend_all_lock
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
name|_thr_suspend_all_unlock
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
name|_thr_try_gc
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
name|_rtp_to_schedparam
argument_list|(
specifier|const
expr|struct
name|rtprio
operator|*
name|rtp
argument_list|,
name|int
operator|*
name|policy
argument_list|,
expr|struct
name|sched_param
operator|*
name|param
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_schedparam_to_rtp
argument_list|(
name|int
name|policy
argument_list|,
specifier|const
expr|struct
name|sched_param
operator|*
name|param
argument_list|,
expr|struct
name|rtprio
operator|*
name|rtp
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

begin_function_decl
name|int
name|_sched_yield
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
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pthread_cleanup_pop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|_pthread_exit_mask
argument_list|(
name|void
operator|*
name|status
argument_list|,
name|sigset_t
operator|*
name|mask
argument_list|)
name|__dead2
name|__hidden
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

begin_function_decl
name|void
name|_pthread_cancel_enter
parameter_list|(
name|int
name|maycancel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pthread_cancel_leave
parameter_list|(
name|int
name|maycancel
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|_pthread_mutex_consistent
parameter_list|(
name|pthread_mutex_t
modifier|*
name|_Nonnull
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutexattr_getrobust
parameter_list|(
name|pthread_mutexattr_t
modifier|*
name|_Nonnull
name|__restrict
parameter_list|,
name|int
modifier|*
name|_Nonnull
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pthread_mutexattr_setrobust
parameter_list|(
name|pthread_mutexattr_t
modifier|*
name|_Nonnull
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* #include<fcntl.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_FCNTL_H_
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

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
name|__sys_openat
parameter_list|(
name|int
parameter_list|,
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
comment|/* _LIBC_PRIVATE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FCNTL_H_ */
end_comment

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
name|__sys_sigpending
parameter_list|(
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_sigreturn
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

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
comment|/* _LIBC_PRIVATE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FCNTL_H_ */
end_comment

begin_comment
comment|/* #include<time.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_TIME_H_
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

begin_function_decl
name|int
name|__sys_clock_nanosleep
parameter_list|(
name|clockid_t
parameter_list|,
name|int
parameter_list|,
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
comment|/* _LIBC_PRIVATE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FCNTL_H_ */
end_comment

begin_comment
comment|/* #include<sys/ucontext.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_UCONTEXT_H_
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

begin_function_decl
name|int
name|__sys_setcontext
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
name|ucp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sys_swapcontext
parameter_list|(
name|ucontext_t
modifier|*
name|oucp
parameter_list|,
specifier|const
name|ucontext_t
modifier|*
name|ucp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBC_PRIVATE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FCNTL_H_ */
end_comment

begin_comment
comment|/* #include<unistd.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UNISTD_H_
end_ifdef

begin_function_decl
name|void
name|__sys_exit
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

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

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
name|__sys_fork
parameter_list|(
name|void
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBC_PRIVATE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FCNTL_H_ */
end_comment

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

begin_function_decl
name|struct
name|wake_addr
modifier|*
name|_thr_alloc_wake_addr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_release_wake_addr
parameter_list|(
name|struct
name|wake_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_sleep
parameter_list|(
name|struct
name|pthread
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

begin_decl_stmt
name|void
name|_thr_wake_addr_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
name|_thr_clear_wake
parameter_list|(
name|struct
name|pthread
modifier|*
name|td
parameter_list|)
block|{
name|td
operator|->
name|wake_addr
operator|->
name|value
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|_thr_is_woken
parameter_list|(
name|struct
name|pthread
modifier|*
name|td
parameter_list|)
block|{
return|return
name|td
operator|->
name|wake_addr
operator|->
name|value
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|_thr_set_wake
parameter_list|(
name|unsigned
name|int
modifier|*
name|waddr
parameter_list|)
block|{
operator|*
name|waddr
operator|=
literal|1
expr_stmt|;
name|_thr_umtx_wake
argument_list|(
name|waddr
argument_list|,
name|INT_MAX
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|_thr_wake_all
argument_list|(
name|unsigned
name|int
operator|*
name|waddrs
index|[]
argument_list|,
name|int
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|struct
name|pthread
modifier|*
name|_sleepq_first
parameter_list|(
name|struct
name|sleepqueue
modifier|*
name|sq
parameter_list|)
block|{
return|return
name|TAILQ_FIRST
argument_list|(
operator|&
name|sq
operator|->
name|sq_blocked
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|void
name|_sleepq_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sleepqueue
modifier|*
name|_sleepq_alloc
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_sleepq_free
argument_list|(
expr|struct
name|sleepqueue
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_sleepq_lock
argument_list|(
name|void
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_sleepq_unlock
argument_list|(
name|void
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sleepqueue
modifier|*
name|_sleepq_lookup
argument_list|(
name|void
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_sleepq_add
argument_list|(
name|void
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
name|_sleepq_remove
argument_list|(
expr|struct
name|sleepqueue
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
name|_sleepq_drop
argument_list|(
expr|struct
name|sleepqueue
operator|*
argument_list|,
name|void
argument_list|(
operator|*
name|cb
argument_list|)
argument_list|(
expr|struct
name|pthread
operator|*
argument_list|,
name|void
operator|*
name|arg
argument_list|)
argument_list|,
name|void
operator|*
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|_pthread_mutex_init_calloc_cb
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|,
name|void
modifier|*
function_decl|(
name|calloc_cb
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|dl_phdr_info
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|__pthread_cxa_finalize
parameter_list|(
name|struct
name|dl_phdr_info
modifier|*
name|phdr_info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|_thr_tsd_unload
argument_list|(
expr|struct
name|dl_phdr_info
operator|*
name|phdr_info
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_thr_sigact_unload
argument_list|(
expr|struct
name|dl_phdr_info
operator|*
name|phdr_info
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_thr_stack_fix_protection
parameter_list|(
name|struct
name|pthread
modifier|*
name|thrd
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
modifier|*
name|__error_threaded
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__thr_interpose_libc
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function_decl
name|pid_t
name|__thr_fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__thr_setcontext
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
name|ucp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|__thr_sigaction
argument_list|(
name|int
name|sig
argument_list|,
specifier|const
expr|struct
name|sigaction
operator|*
name|act
argument_list|,
expr|struct
name|sigaction
operator|*
name|oact
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|__thr_sigprocmask
parameter_list|(
name|int
name|how
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|,
name|sigset_t
modifier|*
name|oset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__thr_sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__thr_sigtimedwait
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|,
name|siginfo_t
modifier|*
name|info
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__thr_sigwait
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|,
name|int
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__thr_sigwaitinfo
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

begin_function_decl
name|int
name|__thr_swapcontext
parameter_list|(
name|ucontext_t
modifier|*
name|oucp
parameter_list|,
specifier|const
name|ucontext_t
modifier|*
name|ucp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__thr_map_stacks_exec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|_spinlock
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|__thr_spinunlock
parameter_list|(
name|struct
name|_spinlock
modifier|*
name|lck
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__thr_spinlock
parameter_list|(
name|struct
name|_spinlock
modifier|*
name|lck
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcb
modifier|*
name|_tcb_ctor
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcb_dtor
parameter_list|(
name|struct
name|tcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__thr_pshared_init
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|__thr_pshared_offpage
argument_list|(
name|void
operator|*
name|key
argument_list|,
name|int
name|doalloc
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__thr_pshared_destroy
argument_list|(
name|void
operator|*
name|key
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__thr_pshared_atfork_pre
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__thr_pshared_atfork_post
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__END_DECLS
name|__NULLABILITY_PRAGMA_POP
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_THR_PRIVATE_H */
end_comment

end_unit

