begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Private thread definitions for the uthread kernel.  *  * $FreeBSD$  */
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
file|<stdio.h>
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/kse.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<pthread_np.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LIBTHREAD_DB
end_ifndef

begin_include
include|#
directive|include
file|"lock.h"
end_include

begin_include
include|#
directive|include
file|"pthread_md.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unfortunately, libpthread had symbol versioning before libc.  * But now libc has symbol versioning, we need to occupy the  * same version namespace in order to override some libc functions.  * So in order to avoid breaking binaries requiring symbols from  * LIBTHREAD_1_0, we need to provide a compatible interface for  * those symbols.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYMBOL_VERSIONING
argument_list|)
operator|&&
name|defined
argument_list|(
name|PIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYM_LT10
parameter_list|(
name|sym
parameter_list|)
value|__CONCAT(sym, _lt10)
end_define

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
name|LT10_COMPAT
parameter_list|(
name|sym
parameter_list|)
define|\
value|WEAK_REF(sym, SYM_LT10(sym));			\ 	SYM_COMPAT(sym, SYM_LT10(sym), LIBTHREAD_1_0)
end_define

begin_define
define|#
directive|define
name|LT10_COMPAT_DEFAULT
parameter_list|(
name|sym
parameter_list|)
define|\
value|LT10_COMPAT(sym);				\ 	WEAK_REF(sym, SYM_FB10(sym));			\ 	SYM_DEFAULT(sym, SYM_FB10(sym), FBSD_1.0)
end_define

begin_define
define|#
directive|define
name|LT10_COMPAT_PRIVATE
parameter_list|(
name|sym
parameter_list|)
define|\
value|LT10_COMPAT(sym);				\ 	WEAK_REF(sym, SYM_FBP10(sym));			\ 	SYM_DEFAULT(sym, SYM_FBP10(sym), FBSDprivate)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LT10_COMPAT_DEFAULT
parameter_list|(
name|sym
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LT10_COMPAT_PRIVATE
parameter_list|(
name|sym
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|SCLASS_PRESET
parameter_list|(
name|x
modifier|...
parameter_list|)
value|= x
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

begin_define
define|#
directive|define
name|SCLASS_PRESET
parameter_list|(
name|x
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|_thr_exit(__FILE__, __LINE__, string)
end_define

begin_comment
comment|/* Output debug messages like this: */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDOUT_FILENO
end_ifdef

begin_define
define|#
directive|define
name|stdout_debug
parameter_list|(
modifier|...
parameter_list|)
value|_thread_printf(STDOUT_FILENO, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDERR_FILENO
end_ifdef

begin_define
define|#
directive|define
name|stderr_debug
parameter_list|(
modifier|...
parameter_list|)
value|_thread_printf(STDERR_FILENO, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBG_MUTEX
value|0x0001
end_define

begin_define
define|#
directive|define
name|DBG_SIG
value|0x0002
end_define

begin_define
define|#
directive|define
name|DBG_INFO_DUMP
value|0x0004
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
value|do {	\ 	if (!(cond))			\ 		PANIC(msg);		\ } while (0)
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

begin_comment
comment|/*  * State change macro without scheduling queue change:  */
end_comment

begin_define
define|#
directive|define
name|THR_SET_STATE
parameter_list|(
name|thrd
parameter_list|,
name|newstate
parameter_list|)
value|do {				\ 	(thrd)->state = newstate;					\ 	(thrd)->fname = __FILE__;					\ 	(thrd)->lineno = __LINE__;					\ } while (0)
end_define

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
define|#
directive|define
name|PQF_ACTIVE
value|0x0001
name|int
name|pq_flags
decl_stmt|;
name|int
name|pq_threads
decl_stmt|;
block|}
name|pq_queue_t
typedef|;
end_typedef

begin_comment
comment|/*  * Each KSEG has a scheduling queue.  For now, threads that exist in their  * own KSEG (system scope) will get a full priority queue.  In the future  * this can be optimized for the single thread per KSEG case.  */
end_comment

begin_struct
struct|struct
name|sched_queue
block|{
name|pq_queue_t
name|sq_runq
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread
argument_list|)
name|sq_waitq
expr_stmt|;
comment|/* waiting in userland */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kse_thr_mailbox
modifier|*
name|kse_critical_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|kse_group
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|MAX_KSE_LOCKLEVEL
value|5
end_define

begin_struct
struct|struct
name|kse
block|{
comment|/* -- location and order specific items for gdb -- */
name|struct
name|kcb
modifier|*
name|k_kcb
decl_stmt|;
name|struct
name|pthread
modifier|*
name|k_curthread
decl_stmt|;
comment|/* current thread */
name|struct
name|kse_group
modifier|*
name|k_kseg
decl_stmt|;
comment|/* parent KSEG */
name|struct
name|sched_queue
modifier|*
name|k_schedq
decl_stmt|;
comment|/* scheduling queue */
comment|/* -- end of location and order specific items -- */
name|TAILQ_ENTRY
argument_list|(
argument|kse
argument_list|)
name|k_qe
expr_stmt|;
comment|/* KSE list link entry */
name|TAILQ_ENTRY
argument_list|(
argument|kse
argument_list|)
name|k_kgqe
expr_stmt|;
comment|/* KSEG's KSE list entry */
comment|/* 	 * Items that are only modified by the kse, or that otherwise 	 * don't need to be locked when accessed 	 */
name|struct
name|lock
name|k_lock
decl_stmt|;
name|struct
name|lockuser
name|k_lockusers
index|[
name|MAX_KSE_LOCKLEVEL
index|]
decl_stmt|;
name|int
name|k_locklevel
decl_stmt|;
name|stack_t
name|k_stack
decl_stmt|;
name|int
name|k_flags
decl_stmt|;
define|#
directive|define
name|KF_STARTED
value|0x0001
comment|/* kernel kse created */
define|#
directive|define
name|KF_INITIALIZED
value|0x0002
comment|/* initialized on 1st upcall */
define|#
directive|define
name|KF_TERMINATED
value|0x0004
comment|/* kse is terminated */
define|#
directive|define
name|KF_IDLE
value|0x0008
comment|/* kse is idle */
define|#
directive|define
name|KF_SWITCH
value|0x0010
comment|/* thread switch in UTS */
name|int
name|k_error
decl_stmt|;
comment|/* syscall errno in critical */
name|int
name|k_cpu
decl_stmt|;
comment|/* CPU ID when bound */
name|int
name|k_sigseqno
decl_stmt|;
comment|/* signal buffered count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KSE_SET_IDLE
parameter_list|(
name|kse
parameter_list|)
value|((kse)->k_flags |= KF_IDLE)
end_define

begin_define
define|#
directive|define
name|KSE_CLEAR_IDLE
parameter_list|(
name|kse
parameter_list|)
value|((kse)->k_flags&= ~KF_IDLE)
end_define

begin_define
define|#
directive|define
name|KSE_IS_IDLE
parameter_list|(
name|kse
parameter_list|)
value|(((kse)->k_flags& KF_IDLE) != 0)
end_define

begin_define
define|#
directive|define
name|KSE_SET_SWITCH
parameter_list|(
name|kse
parameter_list|)
value|((kse)->k_flags |= KF_SWITCH)
end_define

begin_define
define|#
directive|define
name|KSE_CLEAR_SWITCH
parameter_list|(
name|kse
parameter_list|)
value|((kse)->k_flags&= ~KF_SWITCH)
end_define

begin_define
define|#
directive|define
name|KSE_IS_SWITCH
parameter_list|(
name|kse
parameter_list|)
value|(((kse)->k_flags& KF_SWITCH) != 0)
end_define

begin_comment
comment|/*  * Each KSE group contains one or more KSEs in which threads can run.  * At least for now, there is one scheduling queue per KSE group; KSEs  * within the same KSE group compete for threads from the same scheduling  * queue.  A scope system thread has one KSE in one KSE group; the group  * does not use its scheduling queue.  */
end_comment

begin_struct
struct|struct
name|kse_group
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|kse
argument_list|)
name|kg_kseq
expr_stmt|;
comment|/* list of KSEs in group */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pthread
argument_list|)
name|kg_threadq
expr_stmt|;
comment|/* list of threads in group */
name|TAILQ_ENTRY
argument_list|(
argument|kse_group
argument_list|)
name|kg_qe
expr_stmt|;
comment|/* link entry */
name|struct
name|sched_queue
name|kg_schedq
decl_stmt|;
comment|/* scheduling queue */
name|struct
name|lock
name|kg_lock
decl_stmt|;
name|int
name|kg_threadcount
decl_stmt|;
comment|/* # of assigned threads */
name|int
name|kg_ksecount
decl_stmt|;
comment|/* # of assigned KSEs */
name|int
name|kg_idle_kses
decl_stmt|;
name|int
name|kg_flags
decl_stmt|;
define|#
directive|define
name|KGF_SINGLE_THREAD
value|0x0001
comment|/* scope system kse group */
define|#
directive|define
name|KGF_SCHEDQ_INITED
value|0x0002
comment|/* has an initialized schedq */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Add/remove threads from a KSE's scheduling queue.  * For now the scheduling queue is hung off the KSEG.  */
end_comment

begin_define
define|#
directive|define
name|KSEG_THRQ_ADD
parameter_list|(
name|kseg
parameter_list|,
name|thr
parameter_list|)
define|\
value|do {							\ 	TAILQ_INSERT_TAIL(&(kseg)->kg_threadq, thr, kle);\ 	(kseg)->kg_threadcount++;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|KSEG_THRQ_REMOVE
parameter_list|(
name|kseg
parameter_list|,
name|thr
parameter_list|)
define|\
value|do {							\ 	TAILQ_REMOVE(&(kseg)->kg_threadq, thr, kle);	\ 	(kseg)->kg_threadcount--;			\ } while (0)
end_define

begin_comment
comment|/*  * Lock acquire and release for KSEs.  */
end_comment

begin_define
define|#
directive|define
name|KSE_LOCK_ACQUIRE
parameter_list|(
name|kse
parameter_list|,
name|lck
parameter_list|)
define|\
value|do {									\ 	if ((kse)->k_locklevel< MAX_KSE_LOCKLEVEL) {			\ 		(kse)->k_locklevel++;					\ 		_lock_acquire((lck),					\&(kse)->k_lockusers[(kse)->k_locklevel - 1], 0);	\ 	}								\ 	else 								\ 		PANIC("Exceeded maximum lock level");			\ } while (0)
end_define

begin_define
define|#
directive|define
name|KSE_LOCK_RELEASE
parameter_list|(
name|kse
parameter_list|,
name|lck
parameter_list|)
define|\
value|do {									\ 	if ((kse)->k_locklevel> 0) {					\ 		_lock_release((lck),					\&(kse)->k_lockusers[(kse)->k_locklevel - 1]);	\ 		(kse)->k_locklevel--;					\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Lock our own KSEG.  */
end_comment

begin_define
define|#
directive|define
name|KSE_LOCK
parameter_list|(
name|curkse
parameter_list|)
define|\
value|KSE_LOCK_ACQUIRE(curkse,&(curkse)->k_kseg->kg_lock)
end_define

begin_define
define|#
directive|define
name|KSE_UNLOCK
parameter_list|(
name|curkse
parameter_list|)
define|\
value|KSE_LOCK_RELEASE(curkse,&(curkse)->k_kseg->kg_lock)
end_define

begin_comment
comment|/*  * Lock a potentially different KSEG.  */
end_comment

begin_define
define|#
directive|define
name|KSE_SCHED_LOCK
parameter_list|(
name|curkse
parameter_list|,
name|kseg
parameter_list|)
define|\
value|KSE_LOCK_ACQUIRE(curkse,&(kseg)->kg_lock)
end_define

begin_define
define|#
directive|define
name|KSE_SCHED_UNLOCK
parameter_list|(
name|curkse
parameter_list|,
name|kseg
parameter_list|)
define|\
value|KSE_LOCK_RELEASE(curkse,&(kseg)->kg_lock)
end_define

begin_comment
comment|/*  * Waiting queue manipulation macros (using pqe link):  */
end_comment

begin_define
define|#
directive|define
name|KSE_WAITQ_REMOVE
parameter_list|(
name|kse
parameter_list|,
name|thrd
parameter_list|)
define|\
value|do { \ 	if (((thrd)->flags& THR_FLAGS_IN_WAITQ) != 0) { \ 		TAILQ_REMOVE(&(kse)->k_schedq->sq_waitq, thrd, pqe); \ 		(thrd)->flags&= ~THR_FLAGS_IN_WAITQ; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|KSE_WAITQ_INSERT
parameter_list|(
name|kse
parameter_list|,
name|thrd
parameter_list|)
value|kse_waitq_insert(thrd)
end_define

begin_define
define|#
directive|define
name|KSE_WAITQ_FIRST
parameter_list|(
name|kse
parameter_list|)
value|TAILQ_FIRST(&(kse)->k_schedq->sq_waitq)
end_define

begin_define
define|#
directive|define
name|KSE_WAKEUP
parameter_list|(
name|kse
parameter_list|)
value|kse_wakeup(&(kse)->k_kcb->kcb_kmbx)
end_define

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
comment|/*  * lock initialization values.  */
end_comment

begin_define
define|#
directive|define
name|LCK_INITIALIZER
value|{ NULL, NULL, LCK_DEFAULT }
end_define

begin_struct
struct|struct
name|pthread_mutex
block|{
comment|/* 	 * Lock for accesses to this structure. 	 */
name|struct
name|lock
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

begin_comment
comment|/*  * Static mutex initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_STATIC_INITIALIZER
define|\
value|{ LCK_INITIALIZER, PTHREAD_MUTEX_DEFAULT, PTHREAD_PRIO_NONE,	\ 	TAILQ_INITIALIZER, NULL, MUTEX_FLAGS_PRIVATE, 0, 0, 0, 0,	\ 	TAILQ_INITIALIZER }
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
comment|/* 	 * Lock for accesses to this structure. 	 */
name|struct
name|lock
name|c_lock
decl_stmt|;
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
name|struct
name|pthread_mutex
modifier|*
name|c_mutex
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
name|long
name|c_seqno
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

begin_struct
struct|struct
name|pthread_barrier
block|{
name|pthread_mutex_t
name|b_lock
decl_stmt|;
name|pthread_cond_t
name|b_cond
decl_stmt|;
name|int
name|b_count
decl_stmt|;
name|int
name|b_waiters
decl_stmt|;
name|int
name|b_generation
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
name|int
name|s_lock
decl_stmt|;
name|pthread_t
name|s_owner
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
value|{ LCK_INITIALIZER, COND_TYPE_FAST, TAILQ_INITIALIZER,	\ 	NULL, NULL, 0, 0 }
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
define|#
directive|define
name|THR_SIGNAL_THREAD
value|0x200
comment|/* This is a signal thread */
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
parameter_list|(
name|void
modifier|*
parameter_list|)
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
name|THR_STACK32_DEFAULT
value|(1 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|THR_STACK64_DEFAULT
value|(2 * 1024 * 1024)
end_define

begin_comment
comment|/*  * Maximum size of initial thread's stack.  This perhaps deserves to be larger  * than the stacks of other threads, since many applications are likely to run  * almost entirely on this stack.  */
end_comment

begin_define
define|#
directive|define
name|THR_STACK32_INITIAL
value|(2 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|THR_STACK64_INITIAL
value|(4 * 1024 * 1024)
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
comment|/*  * Clock resolution in microseconds.  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_RES_USEC
value|10000
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
comment|/*  * XXX - Define a thread-safe macro to get the current time of day  *       which is updated at regular intervals by something.  *  * For now, we just make the system call to get the time.  */
end_comment

begin_define
define|#
directive|define
name|KSE_GET_TOD
parameter_list|(
name|curkse
parameter_list|,
name|tsp
parameter_list|)
define|\
value|do {							\ 	*tsp = (curkse)->k_kcb->kcb_kmbx.km_timeofday;	\ 	if ((tsp)->tv_sec == 0)				\ 		clock_gettime(CLOCK_REALTIME, tsp);	\ } while (0)
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
name|PS_LOCKWAIT
block|,
name|PS_MUTEX_WAIT
block|,
name|PS_COND_WAIT
block|,
name|PS_SLEEP_WAIT
block|,
name|PS_SIGSUSPEND
block|,
name|PS_SIGWAIT
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

begin_struct
struct|struct
name|sigwait_data
block|{
name|sigset_t
modifier|*
name|waitset
decl_stmt|;
name|siginfo_t
modifier|*
name|siginfo
decl_stmt|;
comment|/* used to save siginfo for sigwaitinfo() */
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
name|struct
name|lock
modifier|*
name|lock
decl_stmt|;
name|struct
name|sigwait_data
modifier|*
name|sigwait
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Define a continuation routine that can be used to perform a  * transfer of control:  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|thread_continuation_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * This stores a thread's state prior to running a signal handler.  * It is used when a signal is delivered to a thread blocked in  * userland.  If the signal handler returns normally, the thread's  * state is restored from here.  */
end_comment

begin_struct
struct|struct
name|pthread_sigframe
block|{
name|int
name|psf_valid
decl_stmt|;
name|int
name|psf_flags
decl_stmt|;
name|int
name|psf_cancelflags
decl_stmt|;
name|int
name|psf_interrupted
decl_stmt|;
name|int
name|psf_timeout
decl_stmt|;
name|int
name|psf_signo
decl_stmt|;
name|enum
name|pthread_state
name|psf_state
decl_stmt|;
name|union
name|pthread_wait_data
name|psf_wait_data
decl_stmt|;
name|struct
name|timespec
name|psf_wakeup_time
decl_stmt|;
name|sigset_t
name|psf_sigset
decl_stmt|;
name|sigset_t
name|psf_sigmask
decl_stmt|;
name|int
name|psf_seqno
decl_stmt|;
name|thread_continuation_t
name|psf_continuation
decl_stmt|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|MAX_THR_LOCKLEVEL
value|5
end_define

begin_comment
comment|/*  * Thread structure.  */
end_comment

begin_struct
struct|struct
name|pthread
block|{
comment|/* Thread control block */
name|struct
name|tcb
modifier|*
name|tcb
decl_stmt|;
comment|/* 	 * Magic value to help recognize a valid thread structure 	 * from an invalid one: 	 */
define|#
directive|define
name|THR_MAGIC
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
comment|/* Queue entry for list of all threads: */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|tle
expr_stmt|;
comment|/* link for all threads in process */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|kle
expr_stmt|;
comment|/* link for all threads in KSE/KSEG */
comment|/* Queue entry for GC lists: */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|gcle
expr_stmt|;
comment|/* Hash queue entry */
name|LIST_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|hle
expr_stmt|;
comment|/* 	 * Lock for accesses to this thread structure. 	 */
name|struct
name|lock
name|lock
decl_stmt|;
name|struct
name|lockuser
name|lockusers
index|[
name|MAX_THR_LOCKLEVEL
index|]
decl_stmt|;
name|int
name|locklevel
decl_stmt|;
name|kse_critical_t
name|critical
index|[
name|MAX_KSE_LOCKLEVEL
index|]
decl_stmt|;
name|struct
name|kse
modifier|*
name|kse
decl_stmt|;
name|struct
name|kse_group
modifier|*
name|kseg
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
name|int
name|active
decl_stmt|;
comment|/* thread running */
name|int
name|blocked
decl_stmt|;
comment|/* thread blocked in kernel */
name|int
name|need_switchout
decl_stmt|;
comment|/* 	 * Used for tracking delivery of signal handlers. 	 */
name|siginfo_t
modifier|*
name|siginfo
decl_stmt|;
name|thread_continuation_t
name|sigbackout
decl_stmt|;
comment|/* 	 * Cancelability flags - the lower 2 bits are used by cancel 	 * definitions in pthread.h 	 */
define|#
directive|define
name|THR_AT_CANCEL_POINT
value|0x0004
define|#
directive|define
name|THR_CANCELLING
value|0x0008
define|#
directive|define
name|THR_CANCEL_NEEDED
value|0x0010
name|int
name|cancelflags
decl_stmt|;
name|thread_continuation_t
name|continuation
decl_stmt|;
comment|/* 	 * The thread's base and pending signal masks.  The active 	 * signal mask is stored in the thread's context (in mailbox). 	 */
name|sigset_t
name|sigmask
decl_stmt|;
name|sigset_t
name|sigpend
decl_stmt|;
name|sigset_t
modifier|*
name|oldsigmask
decl_stmt|;
specifier|volatile
name|int
name|check_pending
decl_stmt|;
name|int
name|refcount
decl_stmt|;
comment|/* Thread state: */
name|enum
name|pthread_state
name|state
decl_stmt|;
specifier|volatile
name|int
name|lock_switch
decl_stmt|;
comment|/* 	 * Number of microseconds accumulated by this thread when 	 * time slicing is active. 	 */
name|long
name|slice_usec
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
comment|/* 	 * The current thread can belong to only one scheduling queue at 	 * a time (ready or waiting queue).  It can also belong to: 	 * 	 *   o A queue of threads waiting for a mutex 	 *   o A queue of threads waiting for a condition variable 	 * 	 * It is possible for a thread to belong to more than one of the 	 * above queues if it is handling a signal.  A thread may only 	 * enter a mutex or condition variable queue when it is not 	 * being called from a signal handler.  If a thread is a member 	 * of one of these queues when a signal handler is invoked, it 	 * must be removed from the queue before invoking the handler 	 * and then added back to the queue after return from the handler. 	 * 	 * Use pqe for the scheduling queue link (both ready and waiting), 	 * sqe for synchronization (mutex, condition variable, and join) 	 * queue links, and qe for all other links. 	 */
name|TAILQ_ENTRY
argument_list|(
argument|pthread
argument_list|)
name|pqe
expr_stmt|;
comment|/* priority, wait queues link */
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
comment|/* 	 * Set to TRUE if a blocking operation was 	 * interrupted by a signal: 	 */
name|int
name|interrupted
decl_stmt|;
comment|/* 	 * Set to non-zero when this thread has entered a critical 	 * region.  We allow for recursive entries into critical regions. 	 */
name|int
name|critical_count
decl_stmt|;
comment|/* 	 * Set to TRUE if this thread should yield after leaving a 	 * critical region to check for signals, messages, etc. 	 */
name|int
name|critical_yield
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
name|THR_FLAGS_IN_WAITQ
value|0x0002
comment|/* in waiting queue using pqe link */
define|#
directive|define
name|THR_FLAGS_IN_RUNQ
value|0x0004
comment|/* in run queue using pqe link */
define|#
directive|define
name|THR_FLAGS_EXITING
value|0x0008
comment|/* thread is exiting */
define|#
directive|define
name|THR_FLAGS_SUSPENDED
value|0x0010
comment|/* thread is suspended */
comment|/* Thread list flags; only set with thread list lock held. */
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
name|int
name|tlflags
decl_stmt|;
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
comment|/* Number rwlocks rdlocks held. */
name|int
name|rdlock_count
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
comment|/* Alternative stack for sigaltstack() */
name|stack_t
name|sigstk
decl_stmt|;
comment|/* 	 * Current locks bitmap for rtld. 	 */
name|int
name|rtld_bits
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
comment|/*  * Critical regions can also be detected by looking at the threads  * current lock level.  Ensure these macros increment and decrement  * the lock levels such that locks can not be held with a lock level  * of 0.  */
end_comment

begin_define
define|#
directive|define
name|THR_IN_CRITICAL
parameter_list|(
name|thrd
parameter_list|)
define|\
value|(((thrd)->locklevel> 0) ||				\ 	((thrd)->critical_count> 0))
end_define

begin_define
define|#
directive|define
name|THR_YIELD_CHECK
parameter_list|(
name|thrd
parameter_list|)
define|\
value|do {								\ 	if (!THR_IN_CRITICAL(thrd)) {				\ 		if (__predict_false(_libkse_debug))		\ 			_thr_debug_check_yield(thrd);		\ 		if ((thrd)->critical_yield != 0)		\ 			_thr_sched_switch(thrd);		\ 		if ((thrd)->check_pending != 0) 		\ 			_thr_sig_check_pending(thrd);		\ 	}							\ } while (0)
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
value|do {								\ 	if ((thrd)->locklevel< MAX_THR_LOCKLEVEL) {		\ 		THR_DEACTIVATE_LAST_LOCK(thrd);			\ 		(thrd)->locklevel++;				\ 		_lock_acquire((lck),				\&(thrd)->lockusers[(thrd)->locklevel - 1],	\ 		    (thrd)->active_priority);			\ 	} else 							\ 		PANIC("Exceeded maximum lock level");		\ } while (0)
end_define

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
value|do {								\ 	if ((thrd)->locklevel> 0) {				\ 		_lock_release((lck),				\&(thrd)->lockusers[(thrd)->locklevel - 1]);	\ 		(thrd)->locklevel--;				\ 		THR_ACTIVATE_LAST_LOCK(thrd);			\ 		if ((thrd)->locklevel == 0)			\ 			THR_YIELD_CHECK(thrd);			\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_ACTIVATE_LAST_LOCK
parameter_list|(
name|thrd
parameter_list|)
define|\
value|do {									\ 	if ((thrd)->locklevel> 0)					\ 		_lockuser_setactive(					\&(thrd)->lockusers[(thrd)->locklevel - 1], 1);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_DEACTIVATE_LAST_LOCK
parameter_list|(
name|thrd
parameter_list|)
define|\
value|do {									\ 	if ((thrd)->locklevel> 0)					\ 		_lockuser_setactive(					\&(thrd)->lockusers[(thrd)->locklevel - 1], 0);	\ } while (0)
end_define

begin_comment
comment|/*  * For now, threads will have their own lock separate from their  * KSE scheduling lock.  */
end_comment

begin_define
define|#
directive|define
name|THR_LOCK
parameter_list|(
name|thr
parameter_list|)
value|THR_LOCK_ACQUIRE(thr,&(thr)->lock)
end_define

begin_define
define|#
directive|define
name|THR_UNLOCK
parameter_list|(
name|thr
parameter_list|)
value|THR_LOCK_RELEASE(thr,&(thr)->lock)
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

begin_comment
comment|/*  * Priority queue manipulation macros (using pqe link).  We use  * the thread's kseg link instead of the kse link because a thread  * does not (currently) have a statically assigned kse.  */
end_comment

begin_define
define|#
directive|define
name|THR_RUNQ_INSERT_HEAD
parameter_list|(
name|thrd
parameter_list|)
define|\
value|_pq_insert_head(&(thrd)->kseg->kg_schedq.sq_runq, thrd)
end_define

begin_define
define|#
directive|define
name|THR_RUNQ_INSERT_TAIL
parameter_list|(
name|thrd
parameter_list|)
define|\
value|_pq_insert_tail(&(thrd)->kseg->kg_schedq.sq_runq, thrd)
end_define

begin_define
define|#
directive|define
name|THR_RUNQ_REMOVE
parameter_list|(
name|thrd
parameter_list|)
define|\
value|_pq_remove(&(thrd)->kseg->kg_schedq.sq_runq, thrd)
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
value|(atomic_load_acq_int(&_gc_count)>= 5)
end_define

begin_comment
comment|/*  * Locking the scheduling queue for another thread uses that thread's  * KSEG lock.  */
end_comment

begin_define
define|#
directive|define
name|THR_SCHED_LOCK
parameter_list|(
name|curthr
parameter_list|,
name|thr
parameter_list|)
value|do {		\ 	(curthr)->critical[(curthr)->locklevel] = _kse_critical_enter(); \ 	(curthr)->locklevel++;				\ 	KSE_SCHED_LOCK((curthr)->kse, (thr)->kseg);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_SCHED_UNLOCK
parameter_list|(
name|curthr
parameter_list|,
name|thr
parameter_list|)
value|do {		\ 	KSE_SCHED_UNLOCK((curthr)->kse, (thr)->kseg);	\ 	(curthr)->locklevel--;				\ 	_kse_critical_leave((curthr)->critical[(curthr)->locklevel]); \ } while (0)
end_define

begin_comment
comment|/* Take the scheduling lock with the intent to call the scheduler. */
end_comment

begin_define
define|#
directive|define
name|THR_LOCK_SWITCH
parameter_list|(
name|curthr
parameter_list|)
value|do {			\ 	(void)_kse_critical_enter();			\ 	KSE_SCHED_LOCK((curthr)->kse, (curthr)->kseg);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_UNLOCK_SWITCH
parameter_list|(
name|curthr
parameter_list|)
value|do {			\ 	KSE_SCHED_UNLOCK((curthr)->kse, (curthr)->kseg);\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_CRITICAL_ENTER
parameter_list|(
name|thr
parameter_list|)
value|(thr)->critical_count++
end_define

begin_define
define|#
directive|define
name|THR_CRITICAL_LEAVE
parameter_list|(
name|thr
parameter_list|)
value|do {		\ 	(thr)->critical_count--;		\ 	if (((thr)->critical_yield != 0)&&	\ 	    ((thr)->critical_count == 0)) {	\ 		(thr)->critical_yield = 0;	\ 		_thr_sched_switch(thr);		\ 	}					\ } while (0)
end_define

begin_define
define|#
directive|define
name|THR_IS_ACTIVE
parameter_list|(
name|thrd
parameter_list|)
define|\
value|((thrd)->kse != NULL)&& ((thrd)->kse->k_curthread == (thrd))
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
name|THR_IS_SUSPENDED
parameter_list|(
name|thrd
parameter_list|)
define|\
value|(((thrd)->state == PS_SUSPENDED) || \ 	(((thrd)->flags& THR_FLAGS_SUSPENDED) != 0))
end_define

begin_define
define|#
directive|define
name|THR_IS_EXITING
parameter_list|(
name|thrd
parameter_list|)
value|(((thrd)->flags& THR_FLAGS_EXITING) != 0)
end_define

begin_define
define|#
directive|define
name|DBG_CAN_RUN
parameter_list|(
name|thrd
parameter_list|)
value|(((thrd)->tcb->tcb_tmbx.tm_dflags& \ 	TMDF_SUSPEND) == 0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|__isthreaded
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|_kse_isthreaded
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

begin_comment
comment|/*  * Global variables for the pthread kernel.  */
end_comment

begin_function_decl
name|SCLASS
name|void
modifier|*
name|_usrstack
name|SCLASS_PRESET
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SCLASS
name|struct
name|kse
modifier|*
name|_kse_initial
name|SCLASS_PRESET
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SCLASS
name|struct
name|pthread
modifier|*
name|_thr_initial
name|SCLASS_PRESET
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For debugger */
end_comment

begin_decl_stmt
name|SCLASS
name|int
name|_libkse_debug
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thread_activated
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thread_scope_system
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|SCLASS_PRESET
argument_list|(
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_thread_list
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of threads needing GC: */
end_comment

begin_decl_stmt
name|SCLASS
name|TAILQ_HEAD
argument_list|(,
name|pthread
argument_list|)
name|_thread_gc_list
name|SCLASS_PRESET
argument_list|(
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_thread_gc_list
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thread_active_threads
name|SCLASS_PRESET
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|TAILQ_HEAD
argument_list|(
name|atfork_head
argument_list|,
name|pthread_atfork
argument_list|)
name|_thr_atfork_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|pthread_mutex_t
name|_thr_atfork_mutex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default thread attributes: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread_attr
name|_pthread_attr_default
name|SCLASS_PRESET
argument_list|(
block|{
name|SCHED_RR
operator|,
literal|0
operator|,
name|TIMESLICE_USEC
operator|,
name|THR_DEFAULT_PRIORITY
operator|,
name|THR_CREATE_RUNNING
operator|,
name|PTHREAD_CREATE_JOINABLE
operator|,
name|NULL
operator|,
name|NULL
operator|,
name|NULL
operator|,
comment|/* stacksize */
literal|0
operator|,
comment|/* guardsize */
literal|0
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Default mutex attributes: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread_mutex_attr
name|_pthread_mutexattr_default
name|SCLASS_PRESET
argument_list|(
block|{
name|PTHREAD_MUTEX_DEFAULT
operator|,
name|PTHREAD_PRIO_NONE
operator|,
literal|0
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Default condition variable attributes: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|pthread_cond_attr
name|_pthread_condattr_default
name|SCLASS_PRESET
argument_list|(
block|{
name|COND_TYPE_FAST
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Clock resolution in usec.	*/
end_comment

begin_function_decl
name|SCLASS
name|int
name|_clock_res_usec
name|SCLASS_PRESET
parameter_list|(
name|CLOCK_RES_USEC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Array of signal actions for this process: */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|sigaction
name|_thread_sigact
index|[
name|_SIG_MAXSIG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Lock for above count of dummy handlers and for the process signal  * mask and pending signal sets.  */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|lock
name|_thread_signal_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pending signals and mask for this process: */
end_comment

begin_decl_stmt
name|SCLASS
name|sigset_t
name|_thr_proc_sigpending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|siginfo_t
name|_thr_proc_siginfo
index|[
name|_SIG_MAXSIG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|pid_t
name|_thr_pid
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Garbage collector lock. */
end_comment

begin_decl_stmt
name|SCLASS
name|struct
name|lock
name|_gc_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_gc_check
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_gc_count
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|struct
name|lock
name|_mutex_static_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|struct
name|lock
name|_rwlock_static_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|struct
name|lock
name|_keytable_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|struct
name|lock
name|_thread_list_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thr_guard_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thr_stack_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thr_stack_initial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thr_page_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|pthread_t
name|_thr_sig_daemon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCLASS
name|int
name|_thr_debug_flags
name|SCLASS_PRESET
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Undefine the storage class and preset specifiers: */
end_comment

begin_undef
undef|#
directive|undef
name|SCLASS
end_undef

begin_undef
undef|#
directive|undef
name|SCLASS_PRESET
end_undef

begin_comment
comment|/*  * Function prototype definitions.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|_cond_reinit
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kse
modifier|*
name|_kse_alloc
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|int
name|sys_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kse_critical_t
name|_kse_critical_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kse_critical_leave
parameter_list|(
name|kse_critical_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kse_in_critical
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kse_free
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|struct
name|kse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kse_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kse_group
modifier|*
name|_kseg_alloc
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kse_lock_wait
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kse_lock_wakeup
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kse_single_thread
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kse_setthreaded
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kseg_free
parameter_list|(
name|struct
name|kse_group
modifier|*
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
name|struct
name|pthread
modifier|*
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_mutex_reinit
parameter_list|(
name|struct
name|pthread_mutex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mutex_unlock_private
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_libpthread_init
parameter_list|(
name|struct
name|pthread
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
name|void
name|_pq_free
parameter_list|(
name|struct
name|pq_queue
modifier|*
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

begin_function_decl
name|struct
name|pthread
modifier|*
name|_pq_first_debug
parameter_list|(
name|struct
name|pq_queue
modifier|*
name|pq
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

begin_function_decl
name|struct
name|pthread
modifier|*
name|_thr_alloc
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_exit
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
name|_thr_exit_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_lock_wait
parameter_list|(
name|struct
name|lock
modifier|*
name|lock
parameter_list|,
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_lock_wakeup
parameter_list|(
name|struct
name|lock
modifier|*
name|lock
parameter_list|,
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_mutex_reinit
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_ref_add
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
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
name|_thr_ref_delete
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_rtld_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_rtld_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_schedule_add
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_schedule_remove
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_setrunnable
parameter_list|(
name|struct
name|pthread
modifier|*
name|curthread
parameter_list|,
name|struct
name|pthread
modifier|*
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kse_mailbox
modifier|*
name|_thr_setrunnable_unlocked
parameter_list|(
name|struct
name|pthread
modifier|*
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kse_mailbox
modifier|*
name|_thr_sig_add
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|int
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_sig_dispatch
parameter_list|(
name|struct
name|kse
modifier|*
parameter_list|,
name|int
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_stack_alloc
parameter_list|(
name|struct
name|pthread_attr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_stack_free
parameter_list|(
name|struct
name|pthread_attr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_exit_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_free
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_gc
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_panic_exit
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
name|_thread_printf
parameter_list|(
name|int
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
name|_thr_sched_switch
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_sched_switch_unlocked
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_set_timeout
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_seterrno
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
name|_thr_sig_handler
parameter_list|(
name|int
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|,
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_sig_check_pending
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_sig_rundown
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_sig_send
parameter_list|(
name|struct
name|pthread
modifier|*
name|pthread
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_sigframe_restore
parameter_list|(
name|struct
name|pthread
modifier|*
name|thread
parameter_list|,
name|struct
name|pthread_sigframe
modifier|*
name|psf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_spinlock_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_cancel_enter
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_cancel_leave
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
name|int
name|_thr_setconcurrency
parameter_list|(
name|int
name|new_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_setmaxconcurrency
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_critical_enter
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_critical_leave
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_start_sig_daemon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_getprocsig
parameter_list|(
name|int
name|sig
parameter_list|,
name|siginfo_t
modifier|*
name|siginfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_getprocsig_unlocked
parameter_list|(
name|int
name|sig
parameter_list|,
name|siginfo_t
modifier|*
name|siginfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_signal_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_signal_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_hash_add
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_hash_remove
parameter_list|(
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
name|_thr_hash_find
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_finish_cancellation
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_sigonstack
parameter_list|(
name|void
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thr_debug_check_yield
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Aliases for _pthread functions. Should be called instead of  * originals if PLT replocation is unwanted at runtme.  */
end_comment

begin_function_decl
name|int
name|_thr_cond_broadcast
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_cond_signal
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_cond_wait
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
name|_thr_mutex_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_mutex_unlock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_rwlock_rdlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_rwlock_wrlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_thr_rwlock_unlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
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
name|sigset_t
modifier|*
parameter_list|,
name|siginfo_t
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
name|__inline
name|int
name|_thr_dump_enabled
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|_thr_debug_flags
operator|&
name|DBG_INFO_DUMP
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_THR_PRIVATE_H */
end_comment

end_unit

