begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)proc.h	8.15 (Berkeley) 5/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROC_H_
end_define

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/* For struct callout. */
end_comment

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_comment
comment|/* For struct klist. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/priority.h>
end_include

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_comment
comment|/* XXX. */
end_comment

begin_include
include|#
directive|include
file|<sys/runq.h>
end_include

begin_include
include|#
directive|include
file|<sys/sigio.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* For structs itimerval, timeval. */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<machine/proc.h>
end_include

begin_comment
comment|/* Machine-dependent proc substruct. */
end_comment

begin_comment
comment|/*  * One structure allocated per session.  *  * List of locks  * (m)		locked by s_mtx mtx  * (e)		locked by proctree_lock sx  * (c)		const until freeing  */
end_comment

begin_struct
struct|struct
name|session
block|{
name|int
name|s_count
decl_stmt|;
comment|/* (m) Ref cnt; pgrps in session. */
name|struct
name|proc
modifier|*
name|s_leader
decl_stmt|;
comment|/* (m + e) Session leader. */
name|struct
name|vnode
modifier|*
name|s_ttyvp
decl_stmt|;
comment|/* (m) Vnode of controlling tty. */
name|struct
name|tty
modifier|*
name|s_ttyp
decl_stmt|;
comment|/* (m) Controlling tty. */
name|pid_t
name|s_sid
decl_stmt|;
comment|/* (c) Session ID. */
comment|/* (m) Setlogin() name: */
name|char
name|s_login
index|[
name|roundup
argument_list|(
name|MAXLOGNAME
argument_list|,
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|)
index|]
decl_stmt|;
name|struct
name|mtx
name|s_mtx
decl_stmt|;
comment|/* Mutex to protect members. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * One structure allocated per process group.  *  * List of locks  * (m)		locked by pg_mtx mtx  * (e)		locked by proctree_lock sx  * (c)		const until freeing  */
end_comment

begin_struct
struct|struct
name|pgrp
block|{
name|LIST_ENTRY
argument_list|(
argument|pgrp
argument_list|)
name|pg_hash
expr_stmt|;
comment|/* (e) Hash chain. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|proc
argument_list|)
name|pg_members
expr_stmt|;
comment|/* (m + e) Pointer to pgrp members. */
name|struct
name|session
modifier|*
name|pg_session
decl_stmt|;
comment|/* (c) Pointer to session. */
name|struct
name|sigiolst
name|pg_sigiolst
decl_stmt|;
comment|/* (m) List of sigio sources. */
name|pid_t
name|pg_id
decl_stmt|;
comment|/* (c) Process group id. */
name|int
name|pg_jobc
decl_stmt|;
comment|/* (m) Job control process count. */
name|struct
name|mtx
name|pg_mtx
decl_stmt|;
comment|/* Mutex to protect members */
block|}
struct|;
end_struct

begin_comment
comment|/*  * pargs, used to hold a copy of the command line, if it had a sane length.  */
end_comment

begin_struct
struct|struct
name|pargs
block|{
name|u_int
name|ar_ref
decl_stmt|;
comment|/* Reference count. */
name|u_int
name|ar_length
decl_stmt|;
comment|/* Length. */
name|u_char
name|ar_args
index|[
literal|1
index|]
decl_stmt|;
comment|/* Arguments. */
block|}
struct|;
end_struct

begin_comment
comment|/*-  * Description of a process.  *  * This structure contains the information needed to manage a thread of  * control, known in UN*X as a process; it has references to substructures  * containing descriptions of things that the process uses, but may share  * with related processes.  The process structure and the substructures  * are always addressable except for those marked "(CPU)" below,  * which might be addressable only on a processor on which the process  * is running.  *  * Below is a key of locks used to protect each member of struct proc.  The  * lock is indicated by a reference to a specific character in parens in the  * associated comment.  *      * - not yet protected  *      a - only touched by curproc or parent during fork/wait  *      b - created at fork, never changes  *		(exception aiods switch vmspaces, but they are also  *		marked 'P_SYSTEM' so hopefully it will be left alone)  *      c - locked by proc mtx  *      d - locked by allproc_lock lock  *      e - locked by proctree_lock lock  *      f - session mtx  *      g - process group mtx  *      h - callout_lock mtx  *      i - by curproc or the master session mtx  *      j - locked by sched_lock mtx  *      k - only accessed by curthread  *	k*- only accessed by curthread and from an interrupt  *      l - the attaching proc or attaching proc parent  *      m - Giant  *      n - not locked, lazy  *      o - ktrace lock  *      p - select lock (sellock)  *      q - td_contested lock  *      r - p_peers lock  *      x - created at fork, only changes during single threading in exec  *      z - zombie threads lock  *  * If the locking key specifies two identifiers (for example, p_pptr) then  * either lock is sufficient for read access, but both locks must be held  * for write access.  */
end_comment

begin_struct_decl
struct_decl|struct
name|auditinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kaudit_record
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|td_sched
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nlminfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kaioinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|p_sched
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sleepqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|turnstile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mqueue_notifier
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Here we define the two structures used for process information.  *  * The first is the thread. It might be thought of as a "Kernel  * Schedulable Entity Context".  * This structure contains all the information as to where a thread of  * execution is now, or was when it was suspended, why it was suspended,  * and anything else that will be needed to restart it when it is  * rescheduled. It includes a scheduler specific substructure that is different  * for each scheduler.  *  * M:N notes.  * It is important to remember that when using M:N threading,   * a particular thread structure may only exist as long as  * the system call or kernel entrance (e.g. by pagefault)  * which it is currently executing. It should therefore NEVER be referenced  * by pointers in long lived structures that live longer than a single  * request. If several threads complete their work at the same time,  * they will all rewind their stacks to the user boundary, report their  * completion state, and all but one will be freed. That last one will  * be kept to provide a kernel stack and pcb for the NEXT syscall or kernel  * entrance (basically to save freeing and then re-allocating it).  The existing  * thread keeps a cached spare thread available to allow it to quickly  * get one when it needs a new one. There is also a system  * cache of free threads. Threads have priority and partake in priority  * inheritance schemes.  *  * The second is the proc (process) which owns all the resources of a process  * other than CPU cycles, which are parceled out to the threads.  */
end_comment

begin_comment
comment|/***************  * Threads are the unit of execution  With a single run queue used by all processors:   RUNQ: --->THREAD---THREAD--...               SLEEPQ:[]---THREAD---THREAD---THREAD                                                      []---THREAD                                        	             []                                                      []---THREAD---THREAD  With PER-CPU run queues:  it gets more complicated.  *  *****************/
end_comment

begin_comment
comment|/*  * Kernel runnable context (thread).  * This is what is put to sleep and reactivated.  * Thread context.  Processes may have multiple threads.  */
end_comment

begin_struct
struct|struct
name|thread
block|{
name|struct
name|proc
modifier|*
name|td_proc
decl_stmt|;
comment|/* (*) Associated process. */
name|TAILQ_ENTRY
argument_list|(
argument|thread
argument_list|)
name|td_plist
expr_stmt|;
comment|/* (*) All threads in this proc. */
comment|/* The two queues below should someday be merged. */
name|TAILQ_ENTRY
argument_list|(
argument|thread
argument_list|)
name|td_slpq
expr_stmt|;
comment|/* (j) Sleep queue. */
name|TAILQ_ENTRY
argument_list|(
argument|thread
argument_list|)
name|td_lockq
expr_stmt|;
comment|/* (j) Lock queue. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|selinfo
argument_list|)
name|td_selq
expr_stmt|;
comment|/* (p) List of selinfos. */
name|struct
name|sleepqueue
modifier|*
name|td_sleepqueue
decl_stmt|;
comment|/* (k) Associated sleep queue. */
name|struct
name|turnstile
modifier|*
name|td_turnstile
decl_stmt|;
comment|/* (k) Associated turnstile. */
name|struct
name|umtx_q
modifier|*
name|td_umtxq
decl_stmt|;
comment|/* (c?) Link for when we're blocked. */
name|lwpid_t
name|td_tid
decl_stmt|;
comment|/* (b) Thread ID. */
name|sigqueue_t
name|td_sigqueue
decl_stmt|;
comment|/* (c) Sigs arrived, not delivered. */
define|#
directive|define
name|td_siglist
value|td_sigqueue.sq_signals
comment|/* Cleared during fork1() or thread_schedule_upcall(). */
define|#
directive|define
name|td_startzero
value|td_flags
name|int
name|td_flags
decl_stmt|;
comment|/* (j) TDF_* flags. */
name|int
name|td_inhibitors
decl_stmt|;
comment|/* (j) Why can not run. */
name|int
name|td_pflags
decl_stmt|;
comment|/* (k) Private thread (TDP_*) flags. */
name|int
name|td_dupfd
decl_stmt|;
comment|/* (k) Ret value from fdopen. XXX */
name|int
name|td_sqqueue
decl_stmt|;
comment|/* (j) Sleepqueue queue blocked on. */
name|void
modifier|*
name|td_wchan
decl_stmt|;
comment|/* (j) Sleep address. */
specifier|const
name|char
modifier|*
name|td_wmesg
decl_stmt|;
comment|/* (j) Reason for sleep. */
name|u_char
name|td_lastcpu
decl_stmt|;
comment|/* (j) Last cpu we were on. */
name|u_char
name|td_oncpu
decl_stmt|;
comment|/* (j) Which cpu we are on. */
specifier|volatile
name|u_char
name|td_owepreempt
decl_stmt|;
comment|/* (k*) Preempt on last critical_exit */
name|short
name|td_locks
decl_stmt|;
comment|/* (k) Count of non-spin locks. */
name|u_char
name|td_tsqueue
decl_stmt|;
comment|/* (j) Turnstile queue blocked on. */
name|struct
name|turnstile
modifier|*
name|td_blocked
decl_stmt|;
comment|/* (j) Lock thread is blocked on. */
specifier|const
name|char
modifier|*
name|td_lockname
decl_stmt|;
comment|/* (j) Name of lock blocked on. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|turnstile
argument_list|)
name|td_contested
expr_stmt|;
comment|/* (q) Contested locks. */
name|struct
name|lock_list_entry
modifier|*
name|td_sleeplocks
decl_stmt|;
comment|/* (k) Held sleep locks. */
name|int
name|td_intr_nesting_level
decl_stmt|;
comment|/* (k) Interrupt recursion. */
name|int
name|td_pinned
decl_stmt|;
comment|/* (k) Temporary cpu pin count. */
name|struct
name|kse_thr_mailbox
modifier|*
name|td_mailbox
decl_stmt|;
comment|/* (*) Userland mailbox address. */
name|struct
name|ucred
modifier|*
name|td_ucred
decl_stmt|;
comment|/* (k) Reference to credentials. */
name|struct
name|thread
modifier|*
name|td_standin
decl_stmt|;
comment|/* (k + a) Use this for an upcall. */
name|struct
name|kse_upcall
modifier|*
name|td_upcall
decl_stmt|;
comment|/* (k + j) Upcall structure. */
name|u_int
name|td_estcpu
decl_stmt|;
comment|/* (j) Sum of the same field in KSEs. */
name|u_int
name|td_slptime
decl_stmt|;
comment|/* (j) How long completely blocked. */
name|u_int
name|td_pticks
decl_stmt|;
comment|/* (k) Statclock hits for profiling */
name|u_int
name|td_sticks
decl_stmt|;
comment|/* (k) Statclock hits in system mode. */
name|u_int
name|td_iticks
decl_stmt|;
comment|/* (k) Statclock hits in intr mode. */
name|u_int
name|td_uticks
decl_stmt|;
comment|/* (k) Statclock hits in user mode. */
name|u_int
name|td_uuticks
decl_stmt|;
comment|/* (k) Statclock hits (usr), for UTS. */
name|u_int
name|td_usticks
decl_stmt|;
comment|/* (k) Statclock hits (sys), for UTS. */
name|int
name|td_intrval
decl_stmt|;
comment|/* (j) Return value of TDF_INTERRUPT. */
name|sigset_t
name|td_oldsigmask
decl_stmt|;
comment|/* (k) Saved mask from pre sigpause. */
name|sigset_t
name|td_sigmask
decl_stmt|;
comment|/* (c) Current signal mask. */
specifier|volatile
name|u_int
name|td_generation
decl_stmt|;
comment|/* (k) For detection of preemption */
name|stack_t
name|td_sigstk
decl_stmt|;
comment|/* (k) Stack ptr and on-stack flag. */
name|int
name|td_kflags
decl_stmt|;
comment|/* (c) Flags for KSE threading. */
name|int
name|td_xsig
decl_stmt|;
comment|/* (c) Signal for ptrace */
name|u_long
name|td_profil_addr
decl_stmt|;
comment|/* (k) Temporary addr until AST. */
name|u_int
name|td_profil_ticks
decl_stmt|;
comment|/* (k) Temporary ticks until AST. */
name|char
name|td_name
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* (*) Thread name. */
define|#
directive|define
name|td_endzero
value|td_base_pri
comment|/* Copied during fork1() or thread_sched_upcall(). */
define|#
directive|define
name|td_startcopy
value|td_endzero
name|u_char
name|td_base_pri
decl_stmt|;
comment|/* (j) Thread base kernel priority. */
name|u_char
name|td_priority
decl_stmt|;
comment|/* (j) Thread active priority. */
name|u_char
name|td_pri_class
decl_stmt|;
comment|/* (j) Scheduling class. */
name|u_char
name|td_user_pri
decl_stmt|;
comment|/* (j) User pri from estcpu and nice. */
name|u_char
name|td_base_user_pri
decl_stmt|;
comment|/* (j) Base user pri */
define|#
directive|define
name|td_endcopy
value|td_pcb
comment|/*  * Fields that must be manually set in fork1() or thread_sched_upcall()  * or already have been set in the allocator, constructor, etc.  */
name|struct
name|pcb
modifier|*
name|td_pcb
decl_stmt|;
comment|/* (k) Kernel VA of pcb and kstack. */
enum|enum
block|{
name|TDS_INACTIVE
init|=
literal|0x0
block|,
name|TDS_INHIBITED
block|,
name|TDS_CAN_RUN
block|,
name|TDS_RUNQ
block|,
name|TDS_RUNNING
block|}
name|td_state
enum|;
name|register_t
name|td_retval
index|[
literal|2
index|]
decl_stmt|;
comment|/* (k) Syscall aux returns. */
name|struct
name|callout
name|td_slpcallout
decl_stmt|;
comment|/* (h) Callout for sleep. */
name|struct
name|trapframe
modifier|*
name|td_frame
decl_stmt|;
comment|/* (k) */
name|struct
name|vm_object
modifier|*
name|td_kstack_obj
decl_stmt|;
comment|/* (a) Kstack object. */
name|vm_offset_t
name|td_kstack
decl_stmt|;
comment|/* (a) Kernel VA of kstack. */
name|int
name|td_kstack_pages
decl_stmt|;
comment|/* (a) Size of the kstack. */
name|struct
name|vm_object
modifier|*
name|td_altkstack_obj
decl_stmt|;
comment|/* (a) Alternate kstack object. */
name|vm_offset_t
name|td_altkstack
decl_stmt|;
comment|/* (a) Kernel VA of alternate kstack. */
name|int
name|td_altkstack_pages
decl_stmt|;
comment|/* (a) Size of alternate kstack. */
specifier|volatile
name|u_int
name|td_critnest
decl_stmt|;
comment|/* (k*) Critical section nest level. */
name|struct
name|mdthread
name|td_md
decl_stmt|;
comment|/* (k) Any machine-dependent fields. */
name|struct
name|td_sched
modifier|*
name|td_sched
decl_stmt|;
comment|/* (*) Scheduler-specific data. */
name|struct
name|kaudit_record
modifier|*
name|td_ar
decl_stmt|;
comment|/* (k) Active audit record, if any. */
name|int
name|td_syscalls
decl_stmt|;
comment|/* per-thread syscall count (used by NFS :)) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags kept in td_flags:  * To change these you MUST have the scheduler lock.  */
end_comment

begin_define
define|#
directive|define
name|TDF_BORROWING
value|0x00000001
end_define

begin_comment
comment|/* Thread is borrowing pri from another. */
end_comment

begin_define
define|#
directive|define
name|TDF_INPANIC
value|0x00000002
end_define

begin_comment
comment|/* Caused a panic, let it drive crashdump. */
end_comment

begin_define
define|#
directive|define
name|TDF_SINTR
value|0x00000008
end_define

begin_comment
comment|/* Sleep is interruptible. */
end_comment

begin_define
define|#
directive|define
name|TDF_TIMEOUT
value|0x00000010
end_define

begin_comment
comment|/* Timing out during sleep. */
end_comment

begin_define
define|#
directive|define
name|TDF_IDLETD
value|0x00000020
end_define

begin_comment
comment|/* This is a per-CPU idle thread. */
end_comment

begin_define
define|#
directive|define
name|TDF_SELECT
value|0x00000040
end_define

begin_comment
comment|/* Selecting; wakeup/waiting danger. */
end_comment

begin_define
define|#
directive|define
name|TDF_SLEEPABORT
value|0x00000080
end_define

begin_comment
comment|/* sleepq_abort was called. */
end_comment

begin_define
define|#
directive|define
name|TDF_TSNOBLOCK
value|0x00000100
end_define

begin_comment
comment|/* Don't block on a turnstile due to race. */
end_comment

begin_define
define|#
directive|define
name|TDF_UBORROWING
value|0x00000200
end_define

begin_comment
comment|/* Thread is borrowing user pri. */
end_comment

begin_define
define|#
directive|define
name|TDF_BOUNDARY
value|0x00000400
end_define

begin_comment
comment|/* Thread suspended at user boundary */
end_comment

begin_define
define|#
directive|define
name|TDF_ASTPENDING
value|0x00000800
end_define

begin_comment
comment|/* Thread has some asynchronous events. */
end_comment

begin_define
define|#
directive|define
name|TDF_TIMOFAIL
value|0x00001000
end_define

begin_comment
comment|/* Timeout from sleep after we were awake. */
end_comment

begin_define
define|#
directive|define
name|TDF_INTERRUPT
value|0x00002000
end_define

begin_comment
comment|/* Thread is marked as interrupted. */
end_comment

begin_define
define|#
directive|define
name|TDF_UPIBLOCKED
value|0x00004000
end_define

begin_comment
comment|/* Thread blocked on user PI mutex. */
end_comment

begin_define
define|#
directive|define
name|TDF_UNUSED15
value|0x00008000
end_define

begin_comment
comment|/* --available -- */
end_comment

begin_define
define|#
directive|define
name|TDF_NEEDRESCHED
value|0x00010000
end_define

begin_comment
comment|/* Thread needs to yield. */
end_comment

begin_define
define|#
directive|define
name|TDF_NEEDSIGCHK
value|0x00020000
end_define

begin_comment
comment|/* Thread may need signal delivery. */
end_comment

begin_define
define|#
directive|define
name|TDF_XSIG
value|0x00040000
end_define

begin_comment
comment|/* Thread is exchanging signal under trace */
end_comment

begin_define
define|#
directive|define
name|TDF_UNUSED19
value|0x00080000
end_define

begin_comment
comment|/* Thread is sleeping on a umtx. */
end_comment

begin_define
define|#
directive|define
name|TDF_THRWAKEUP
value|0x00100000
end_define

begin_comment
comment|/* Libthr thread must not suspend itself. */
end_comment

begin_define
define|#
directive|define
name|TDF_DBSUSPEND
value|0x00200000
end_define

begin_comment
comment|/* Thread is suspended by debugger */
end_comment

begin_define
define|#
directive|define
name|TDF_UNUSED22
value|0x00400000
end_define

begin_comment
comment|/* --available -- */
end_comment

begin_define
define|#
directive|define
name|TDF_UNUSED23
value|0x00800000
end_define

begin_comment
comment|/* --available -- */
end_comment

begin_define
define|#
directive|define
name|TDF_SCHED0
value|0x01000000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDF_SCHED1
value|0x02000000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDF_SCHED2
value|0x04000000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDF_SCHED3
value|0x08000000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_comment
comment|/*  * "Private" flags kept in td_pflags:  * These are only accessed by curthread and thus need no locking.  */
end_comment

begin_define
define|#
directive|define
name|TDP_OLDMASK
value|0x00000001
end_define

begin_comment
comment|/* Need to restore mask after suspend. */
end_comment

begin_define
define|#
directive|define
name|TDP_INKTR
value|0x00000002
end_define

begin_comment
comment|/* Thread is currently in KTR code. */
end_comment

begin_define
define|#
directive|define
name|TDP_INKTRACE
value|0x00000004
end_define

begin_comment
comment|/* Thread is currently in KTRACE code. */
end_comment

begin_define
define|#
directive|define
name|TDP_UPCALLING
value|0x00000008
end_define

begin_comment
comment|/* This thread is doing an upcall. */
end_comment

begin_define
define|#
directive|define
name|TDP_COWINPROGRESS
value|0x00000010
end_define

begin_comment
comment|/* Snapshot copy-on-write in progress. */
end_comment

begin_define
define|#
directive|define
name|TDP_ALTSTACK
value|0x00000020
end_define

begin_comment
comment|/* Have alternate signal stack. */
end_comment

begin_define
define|#
directive|define
name|TDP_DEADLKTREAT
value|0x00000040
end_define

begin_comment
comment|/* Lock aquisition - deadlock treatment. */
end_comment

begin_define
define|#
directive|define
name|TDP_SA
value|0x00000080
end_define

begin_comment
comment|/* A scheduler activation based thread. */
end_comment

begin_define
define|#
directive|define
name|TDP_NOSLEEPING
value|0x00000100
end_define

begin_comment
comment|/* Thread is not allowed to sleep on a sq. */
end_comment

begin_define
define|#
directive|define
name|TDP_OWEUPC
value|0x00000200
end_define

begin_comment
comment|/* Call addupc() at next AST. */
end_comment

begin_define
define|#
directive|define
name|TDP_ITHREAD
value|0x00000400
end_define

begin_comment
comment|/* Thread is an interrupt thread. */
end_comment

begin_define
define|#
directive|define
name|TDP_CAN_UNBIND
value|0x00000800
end_define

begin_comment
comment|/* Only temporarily bound. */
end_comment

begin_define
define|#
directive|define
name|TDP_SCHED1
value|0x00001000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDP_SCHED2
value|0x00002000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDP_SCHED3
value|0x00004000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDP_SCHED4
value|0x00008000
end_define

begin_comment
comment|/* Reserved for scheduler private use */
end_comment

begin_define
define|#
directive|define
name|TDP_GEOM
value|0x00010000
end_define

begin_comment
comment|/* Settle GEOM before finishing syscall */
end_comment

begin_define
define|#
directive|define
name|TDP_SOFTDEP
value|0x00020000
end_define

begin_comment
comment|/* Stuck processing softdep worklist */
end_comment

begin_define
define|#
directive|define
name|TDP_NORUNNINGBUF
value|0x00040000
end_define

begin_comment
comment|/* Ignore runningbufspace check */
end_comment

begin_define
define|#
directive|define
name|TDP_WAKEUP
value|0x00080000
end_define

begin_comment
comment|/* Don't sleep in umtx cond_wait */
end_comment

begin_comment
comment|/*  * Reasons that the current thread can not be run yet.  * More than one may apply.  */
end_comment

begin_define
define|#
directive|define
name|TDI_SUSPENDED
value|0x0001
end_define

begin_comment
comment|/* On suspension queue. */
end_comment

begin_define
define|#
directive|define
name|TDI_SLEEPING
value|0x0002
end_define

begin_comment
comment|/* Actually asleep! (tricky). */
end_comment

begin_define
define|#
directive|define
name|TDI_SWAPPED
value|0x0004
end_define

begin_comment
comment|/* Stack not in mem.  Bad juju if run. */
end_comment

begin_define
define|#
directive|define
name|TDI_LOCK
value|0x0008
end_define

begin_comment
comment|/* Stopped on a lock. */
end_comment

begin_define
define|#
directive|define
name|TDI_IWAIT
value|0x0010
end_define

begin_comment
comment|/* Awaiting interrupt. */
end_comment

begin_comment
comment|/*  * flags (in kflags) related to M:N threading.  */
end_comment

begin_define
define|#
directive|define
name|TDK_KSEREL
value|0x0001
end_define

begin_comment
comment|/* Blocked in msleep on p->p_completed. */
end_comment

begin_define
define|#
directive|define
name|TDK_KSERELSIG
value|0x0002
end_define

begin_comment
comment|/* Blocked in msleep on p->p_siglist. */
end_comment

begin_define
define|#
directive|define
name|TDK_WAKEUP
value|0x0004
end_define

begin_comment
comment|/* Thread has been woken by kse_wakeup. */
end_comment

begin_define
define|#
directive|define
name|TD_CAN_UNBIND
parameter_list|(
name|td
parameter_list|)
define|\
value|(((td)->td_pflags& TDP_CAN_UNBIND)&&	\      ((td)->td_upcall != NULL))
end_define

begin_define
define|#
directive|define
name|TD_IS_SLEEPING
parameter_list|(
name|td
parameter_list|)
value|((td)->td_inhibitors& TDI_SLEEPING)
end_define

begin_define
define|#
directive|define
name|TD_ON_SLEEPQ
parameter_list|(
name|td
parameter_list|)
value|((td)->td_wchan != NULL)
end_define

begin_define
define|#
directive|define
name|TD_IS_SUSPENDED
parameter_list|(
name|td
parameter_list|)
value|((td)->td_inhibitors& TDI_SUSPENDED)
end_define

begin_define
define|#
directive|define
name|TD_IS_SWAPPED
parameter_list|(
name|td
parameter_list|)
value|((td)->td_inhibitors& TDI_SWAPPED)
end_define

begin_define
define|#
directive|define
name|TD_ON_LOCK
parameter_list|(
name|td
parameter_list|)
value|((td)->td_inhibitors& TDI_LOCK)
end_define

begin_define
define|#
directive|define
name|TD_AWAITING_INTR
parameter_list|(
name|td
parameter_list|)
value|((td)->td_inhibitors& TDI_IWAIT)
end_define

begin_define
define|#
directive|define
name|TD_IS_RUNNING
parameter_list|(
name|td
parameter_list|)
value|((td)->td_state == TDS_RUNNING)
end_define

begin_define
define|#
directive|define
name|TD_ON_RUNQ
parameter_list|(
name|td
parameter_list|)
value|((td)->td_state == TDS_RUNQ)
end_define

begin_define
define|#
directive|define
name|TD_CAN_RUN
parameter_list|(
name|td
parameter_list|)
value|((td)->td_state == TDS_CAN_RUN)
end_define

begin_define
define|#
directive|define
name|TD_IS_INHIBITED
parameter_list|(
name|td
parameter_list|)
value|((td)->td_state == TDS_INHIBITED)
end_define

begin_define
define|#
directive|define
name|TD_ON_UPILOCK
parameter_list|(
name|td
parameter_list|)
value|((td)->td_flags& TDF_UPIBLOCKED)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|TD_IS_IDLETHREAD
parameter_list|(
name|td
parameter_list|)
value|((td) == pcpu(idlethread))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TD_IS_IDLETHREAD
parameter_list|(
name|td
parameter_list|)
value|((td)->td_flags& TDF_IDLETD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TD_SET_INHIB
parameter_list|(
name|td
parameter_list|,
name|inhib
parameter_list|)
value|do {			\ 	(td)->td_state = TDS_INHIBITED;			\ 	(td)->td_inhibitors |= (inhib);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|TD_CLR_INHIB
parameter_list|(
name|td
parameter_list|,
name|inhib
parameter_list|)
value|do {			\ 	if (((td)->td_inhibitors& (inhib))&&		\ 	    (((td)->td_inhibitors&= ~(inhib)) == 0))	\ 		(td)->td_state = TDS_CAN_RUN;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|TD_SET_SLEEPING
parameter_list|(
name|td
parameter_list|)
value|TD_SET_INHIB((td), TDI_SLEEPING)
end_define

begin_define
define|#
directive|define
name|TD_SET_SWAPPED
parameter_list|(
name|td
parameter_list|)
value|TD_SET_INHIB((td), TDI_SWAPPED)
end_define

begin_define
define|#
directive|define
name|TD_SET_LOCK
parameter_list|(
name|td
parameter_list|)
value|TD_SET_INHIB((td), TDI_LOCK)
end_define

begin_define
define|#
directive|define
name|TD_SET_SUSPENDED
parameter_list|(
name|td
parameter_list|)
value|TD_SET_INHIB((td), TDI_SUSPENDED)
end_define

begin_define
define|#
directive|define
name|TD_SET_IWAIT
parameter_list|(
name|td
parameter_list|)
value|TD_SET_INHIB((td), TDI_IWAIT)
end_define

begin_define
define|#
directive|define
name|TD_SET_EXITING
parameter_list|(
name|td
parameter_list|)
value|TD_SET_INHIB((td), TDI_EXITING)
end_define

begin_define
define|#
directive|define
name|TD_CLR_SLEEPING
parameter_list|(
name|td
parameter_list|)
value|TD_CLR_INHIB((td), TDI_SLEEPING)
end_define

begin_define
define|#
directive|define
name|TD_CLR_SWAPPED
parameter_list|(
name|td
parameter_list|)
value|TD_CLR_INHIB((td), TDI_SWAPPED)
end_define

begin_define
define|#
directive|define
name|TD_CLR_LOCK
parameter_list|(
name|td
parameter_list|)
value|TD_CLR_INHIB((td), TDI_LOCK)
end_define

begin_define
define|#
directive|define
name|TD_CLR_SUSPENDED
parameter_list|(
name|td
parameter_list|)
value|TD_CLR_INHIB((td), TDI_SUSPENDED)
end_define

begin_define
define|#
directive|define
name|TD_CLR_IWAIT
parameter_list|(
name|td
parameter_list|)
value|TD_CLR_INHIB((td), TDI_IWAIT)
end_define

begin_define
define|#
directive|define
name|TD_SET_RUNNING
parameter_list|(
name|td
parameter_list|)
value|(td)->td_state = TDS_RUNNING
end_define

begin_define
define|#
directive|define
name|TD_SET_RUNQ
parameter_list|(
name|td
parameter_list|)
value|(td)->td_state = TDS_RUNQ
end_define

begin_define
define|#
directive|define
name|TD_SET_CAN_RUN
parameter_list|(
name|td
parameter_list|)
value|(td)->td_state = TDS_CAN_RUN
end_define

begin_comment
comment|/*  * An upcall is used when returning to userland.  If a thread does not have  * an upcall on return to userland the thread exports its context and exits.  */
end_comment

begin_struct
struct|struct
name|kse_upcall
block|{
name|TAILQ_ENTRY
argument_list|(
argument|kse_upcall
argument_list|)
name|ku_link
expr_stmt|;
comment|/* List of upcalls in proc. */
name|struct
name|proc
modifier|*
name|ku_proc
decl_stmt|;
comment|/* Associated proc. */
name|struct
name|thread
modifier|*
name|ku_owner
decl_stmt|;
comment|/* Owning thread. */
name|int
name|ku_flags
decl_stmt|;
comment|/* KUF_* flags. */
name|struct
name|kse_mailbox
modifier|*
name|ku_mailbox
decl_stmt|;
comment|/* Userland mailbox address. */
name|stack_t
name|ku_stack
decl_stmt|;
comment|/* Userland upcall stack. */
name|void
modifier|*
name|ku_func
decl_stmt|;
comment|/* Userland upcall function. */
name|unsigned
name|int
name|ku_mflags
decl_stmt|;
comment|/* Cached upcall mbox flags. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KUF_DOUPCALL
value|0x00001
end_define

begin_comment
comment|/* Do upcall now; don't wait. */
end_comment

begin_define
define|#
directive|define
name|KUF_EXITING
value|0x00002
end_define

begin_comment
comment|/* Upcall structure is exiting. */
end_comment

begin_comment
comment|/*  * XXX: Does this belong in resource.h or resourcevar.h instead?  * Resource usage extension.  The times in rusage structs in the kernel are  * never up to date.  The actual times are kept as runtimes and tick counts  * (with control info in the "previous" times), and are converted when  * userland asks for rusage info.  Backwards compatibility prevents putting  * this directly in the user-visible rusage struct.  *  * Locking: (cj) means (j) for p_rux and (c) for p_crux.  */
end_comment

begin_struct
struct|struct
name|rusage_ext
block|{
name|u_int64_t
name|rux_runtime
decl_stmt|;
comment|/* (cj) Real time. */
name|u_int64_t
name|rux_uticks
decl_stmt|;
comment|/* (cj) Statclock hits in user mode. */
name|u_int64_t
name|rux_sticks
decl_stmt|;
comment|/* (cj) Statclock hits in sys mode. */
name|u_int64_t
name|rux_iticks
decl_stmt|;
comment|/* (cj) Statclock hits in intr mode. */
name|u_int64_t
name|rux_uu
decl_stmt|;
comment|/* (c) Previous user time in usec. */
name|u_int64_t
name|rux_su
decl_stmt|;
comment|/* (c) Previous sys time in usec. */
name|u_int64_t
name|rux_tu
decl_stmt|;
comment|/* (c) Previous total time in usec. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The old fashionned process. May have multiple threads.  *  Starts off with a single embedded THREAD.  */
end_comment

begin_struct
struct|struct
name|proc
block|{
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_list
expr_stmt|;
comment|/* (d) List of all processes. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|thread
argument_list|)
name|p_threads
expr_stmt|;
comment|/* (j)(td_plist) Threads. (shortcut) */
name|struct
name|ucred
modifier|*
name|p_ucred
decl_stmt|;
comment|/* (c) Process owner's identity. */
name|struct
name|filedesc
modifier|*
name|p_fd
decl_stmt|;
comment|/* (b) Open files. */
name|struct
name|filedesc_to_leader
modifier|*
name|p_fdtol
decl_stmt|;
comment|/* (b) Tracking node */
comment|/* Accumulated stats for all threads? */
name|struct
name|pstats
modifier|*
name|p_stats
decl_stmt|;
comment|/* (b) Accounting/statistics (CPU). */
name|struct
name|plimit
modifier|*
name|p_limit
decl_stmt|;
comment|/* (c) Process limits. */
name|struct
name|sigacts
modifier|*
name|p_sigacts
decl_stmt|;
comment|/* (x) Signal actions, state (CPU). */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|kse_upcall
argument_list|)
name|p_upcalls
expr_stmt|;
comment|/* All upcalls in the proc. */
comment|/* 	 * The following don't make too much sense. 	 * See the td_ or ke_ versions of the same flags. 	 */
name|int
name|p_flag
decl_stmt|;
comment|/* (c) P_* flags. */
name|int
name|p_sflag
decl_stmt|;
comment|/* (j) PS_* flags. */
enum|enum
block|{
name|PRS_NEW
init|=
literal|0
block|,
comment|/* In creation */
name|PRS_NORMAL
block|,
comment|/* threads can be run. */
name|PRS_ZOMBIE
block|}
name|p_state
enum|;
comment|/* (j/c) S* process status. */
name|pid_t
name|p_pid
decl_stmt|;
comment|/* (b) Process identifier. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_hash
expr_stmt|;
comment|/* (d) Hash chain. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_pglist
expr_stmt|;
comment|/* (g + e) List of processes in pgrp. */
name|struct
name|proc
modifier|*
name|p_pptr
decl_stmt|;
comment|/* (c + e) Pointer to parent process. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_sibling
expr_stmt|;
comment|/* (e) List of sibling processes. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|proc
argument_list|)
name|p_children
expr_stmt|;
comment|/* (e) Pointer to list of children. */
name|struct
name|mtx
name|p_mtx
decl_stmt|;
comment|/* (n) Lock for this struct. */
name|struct
name|ksiginfo
modifier|*
name|p_ksi
decl_stmt|;
comment|/* Locked by parent proc lock */
name|sigqueue_t
name|p_sigqueue
decl_stmt|;
comment|/* (c) Sigs not delivered to a td. */
define|#
directive|define
name|p_siglist
value|p_sigqueue.sq_signals
comment|/* The following fields are all zeroed upon creation in fork. */
define|#
directive|define
name|p_startzero
value|p_oppid
name|pid_t
name|p_oppid
decl_stmt|;
comment|/* (c + e) Save ppid in ptrace. XXX */
name|struct
name|vmspace
modifier|*
name|p_vmspace
decl_stmt|;
comment|/* (b) Address space. */
name|u_int
name|p_swtime
decl_stmt|;
comment|/* (j) Time swapped in or out. */
name|struct
name|itimerval
name|p_realtimer
decl_stmt|;
comment|/* (c) Alarm timer. */
name|struct
name|rusage_ext
name|p_rux
decl_stmt|;
comment|/* (cj) Internal resource usage. */
name|struct
name|rusage_ext
name|p_crux
decl_stmt|;
comment|/* (c) Internal child resource usage. */
name|int
name|p_profthreads
decl_stmt|;
comment|/* (c) Num threads in addupc_task. */
name|int
name|p_maxthrwaits
decl_stmt|;
comment|/* (c) Max threads num waiters */
name|int
name|p_traceflag
decl_stmt|;
comment|/* (o) Kernel trace points. */
name|struct
name|vnode
modifier|*
name|p_tracevp
decl_stmt|;
comment|/* (c + o) Trace to vnode. */
name|struct
name|ucred
modifier|*
name|p_tracecred
decl_stmt|;
comment|/* (o) Credentials to trace with. */
name|struct
name|vnode
modifier|*
name|p_textvp
decl_stmt|;
comment|/* (b) Vnode of executable. */
name|char
name|p_lock
decl_stmt|;
comment|/* (c) Proclock (prevent swap) count. */
name|struct
name|sigiolst
name|p_sigiolst
decl_stmt|;
comment|/* (c) List of sigio sources. */
name|int
name|p_sigparent
decl_stmt|;
comment|/* (c) Signal to parent on exit. */
name|int
name|p_sig
decl_stmt|;
comment|/* (n) For core dump/debugger XXX. */
name|u_long
name|p_code
decl_stmt|;
comment|/* (n) For core dump/debugger XXX. */
name|u_int
name|p_stops
decl_stmt|;
comment|/* (c) Stop event bitmask. */
name|u_int
name|p_stype
decl_stmt|;
comment|/* (c) Stop event type. */
name|char
name|p_step
decl_stmt|;
comment|/* (c) Process is stopped. */
name|u_char
name|p_pfsflags
decl_stmt|;
comment|/* (c) Procfs flags. */
name|struct
name|nlminfo
modifier|*
name|p_nlminfo
decl_stmt|;
comment|/* (?) Only used by/for lockd. */
name|struct
name|kaioinfo
modifier|*
name|p_aioinfo
decl_stmt|;
comment|/* (c) ASYNC I/O info. */
name|struct
name|thread
modifier|*
name|p_singlethread
decl_stmt|;
comment|/* (c + j) If single threading this is it */
name|int
name|p_suspcount
decl_stmt|;
comment|/* (c) Num threads in suspended mode. */
name|struct
name|thread
modifier|*
name|p_xthread
decl_stmt|;
comment|/* (c) Trap thread */
name|int
name|p_boundary_count
decl_stmt|;
comment|/* (c) Num threads at user boundary */
name|int
name|p_pendingcnt
decl_stmt|;
comment|/* how many signals are pending */
name|struct
name|itimers
modifier|*
name|p_itimers
decl_stmt|;
comment|/* (c) POSIX interval timers. */
comment|/* from ksegrp */
name|u_int
name|p_estcpu
decl_stmt|;
comment|/* (j) Sum of the field in threads. */
name|u_int
name|p_slptime
decl_stmt|;
comment|/* (j) How long completely blocked. */
name|int
name|p_numupcalls
decl_stmt|;
comment|/* (j) Num upcalls. */
name|int
name|p_upsleeps
decl_stmt|;
comment|/* (c) Num threads in kse_release(). */
name|struct
name|kse_thr_mailbox
modifier|*
name|p_completed
decl_stmt|;
comment|/* (c) Completed thread mboxes. */
name|int
name|p_nextupcall
decl_stmt|;
comment|/* (n) Next upcall time. */
name|int
name|p_upquantum
decl_stmt|;
comment|/* (n) Quantum to schedule an upcall. */
comment|/* End area that is zeroed on creation. */
define|#
directive|define
name|p_endzero
value|p_magic
comment|/* The following fields are all copied upon creation in fork. */
define|#
directive|define
name|p_startcopy
value|p_endzero
name|u_int
name|p_magic
decl_stmt|;
comment|/* (b) Magic number. */
name|char
name|p_comm
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* (b) Process name. */
name|struct
name|pgrp
modifier|*
name|p_pgrp
decl_stmt|;
comment|/* (c + e) Pointer to process group. */
name|struct
name|sysentvec
modifier|*
name|p_sysent
decl_stmt|;
comment|/* (b) Syscall dispatch info. */
name|struct
name|pargs
modifier|*
name|p_args
decl_stmt|;
comment|/* (c) Process arguments. */
name|rlim_t
name|p_cpulimit
decl_stmt|;
comment|/* (j) Current CPU limit in seconds. */
name|signed
name|char
name|p_nice
decl_stmt|;
comment|/* (c + j) Process "nice" value. */
comment|/* End area that is copied on creation. */
define|#
directive|define
name|p_endcopy
value|p_xstat
name|u_short
name|p_xstat
decl_stmt|;
comment|/* (c) Exit status; also stop sig. */
name|struct
name|knlist
name|p_klist
decl_stmt|;
comment|/* (c) Knotes attached to this proc. */
name|int
name|p_numthreads
decl_stmt|;
comment|/* (j) Number of threads. */
name|struct
name|mdproc
name|p_md
decl_stmt|;
comment|/* Any machine-dependent fields. */
name|struct
name|callout
name|p_itcallout
decl_stmt|;
comment|/* (h + c) Interval timer callout. */
name|u_short
name|p_acflag
decl_stmt|;
comment|/* (c) Accounting flags. */
name|struct
name|rusage
modifier|*
name|p_ru
decl_stmt|;
comment|/* (a) Exit information. XXX */
name|struct
name|proc
modifier|*
name|p_peers
decl_stmt|;
comment|/* (r) */
name|struct
name|proc
modifier|*
name|p_leader
decl_stmt|;
comment|/* (b) */
name|void
modifier|*
name|p_emuldata
decl_stmt|;
comment|/* (c) Emulator state data. */
name|struct
name|label
modifier|*
name|p_label
decl_stmt|;
comment|/* (*) Proc (not subject) MAC label. */
name|struct
name|p_sched
modifier|*
name|p_sched
decl_stmt|;
comment|/* (*) Scheduler-specific data. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ktr_request
argument_list|)
name|p_ktr
expr_stmt|;
comment|/* (o) KTR event queue. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|mqueue_notifier
argument_list|)
name|p_mqnotifier
expr_stmt|;
comment|/* (c) mqueue notifiers.*/
name|struct
name|auditinfo_addr
modifier|*
name|p_au
decl_stmt|;
comment|/* (c) Process audit properties. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|p_session
value|p_pgrp->pg_session
end_define

begin_define
define|#
directive|define
name|p_pgid
value|p_pgrp->pg_id
end_define

begin_define
define|#
directive|define
name|NOCPU
value|0xff
end_define

begin_comment
comment|/* For when we aren't on a CPU. */
end_comment

begin_comment
comment|/* These flags are kept in p_flag. */
end_comment

begin_define
define|#
directive|define
name|P_ADVLOCK
value|0x00001
end_define

begin_comment
comment|/* Process may hold a POSIX advisory lock. */
end_comment

begin_define
define|#
directive|define
name|P_CONTROLT
value|0x00002
end_define

begin_comment
comment|/* Has a controlling terminal. */
end_comment

begin_define
define|#
directive|define
name|P_KTHREAD
value|0x00004
end_define

begin_comment
comment|/* Kernel thread (*). */
end_comment

begin_define
define|#
directive|define
name|P_NOLOAD
value|0x00008
end_define

begin_comment
comment|/* Ignore during load avg calculations. */
end_comment

begin_define
define|#
directive|define
name|P_PPWAIT
value|0x00010
end_define

begin_comment
comment|/* Parent is waiting for child to exec/exit. */
end_comment

begin_define
define|#
directive|define
name|P_PROFIL
value|0x00020
end_define

begin_comment
comment|/* Has started profiling. */
end_comment

begin_define
define|#
directive|define
name|P_STOPPROF
value|0x00040
end_define

begin_comment
comment|/* Has thread requesting to stop profiling. */
end_comment

begin_define
define|#
directive|define
name|P_HADTHREADS
value|0x00080
end_define

begin_comment
comment|/* Has had threads (no cleanup shortcuts) */
end_comment

begin_define
define|#
directive|define
name|P_SUGID
value|0x00100
end_define

begin_comment
comment|/* Had set id privileges since last exec. */
end_comment

begin_define
define|#
directive|define
name|P_SYSTEM
value|0x00200
end_define

begin_comment
comment|/* System proc: no sigs, stats or swapping. */
end_comment

begin_define
define|#
directive|define
name|P_SINGLE_EXIT
value|0x00400
end_define

begin_comment
comment|/* Threads suspending should exit, not wait. */
end_comment

begin_define
define|#
directive|define
name|P_TRACED
value|0x00800
end_define

begin_comment
comment|/* Debugged process being traced. */
end_comment

begin_define
define|#
directive|define
name|P_WAITED
value|0x01000
end_define

begin_comment
comment|/* Someone is waiting for us. */
end_comment

begin_define
define|#
directive|define
name|P_WEXIT
value|0x02000
end_define

begin_comment
comment|/* Working on exiting. */
end_comment

begin_define
define|#
directive|define
name|P_EXEC
value|0x04000
end_define

begin_comment
comment|/* Process called exec. */
end_comment

begin_define
define|#
directive|define
name|P_SA
value|0x08000
end_define

begin_comment
comment|/* Using scheduler activations. */
end_comment

begin_define
define|#
directive|define
name|P_CONTINUED
value|0x10000
end_define

begin_comment
comment|/* Proc has continued from a stopped state. */
end_comment

begin_define
define|#
directive|define
name|P_STOPPED_SIG
value|0x20000
end_define

begin_comment
comment|/* Stopped due to SIGSTOP/SIGTSTP. */
end_comment

begin_define
define|#
directive|define
name|P_STOPPED_TRACE
value|0x40000
end_define

begin_comment
comment|/* Stopped because of tracing. */
end_comment

begin_define
define|#
directive|define
name|P_STOPPED_SINGLE
value|0x80000
end_define

begin_comment
comment|/* Only 1 thread can continue (not to user). */
end_comment

begin_define
define|#
directive|define
name|P_PROTECTED
value|0x100000
end_define

begin_comment
comment|/* Do not kill on memory overcommit. */
end_comment

begin_define
define|#
directive|define
name|P_SIGEVENT
value|0x200000
end_define

begin_comment
comment|/* Process pending signals changed. */
end_comment

begin_define
define|#
directive|define
name|P_SINGLE_BOUNDARY
value|0x400000
end_define

begin_comment
comment|/* Threads should suspend at user boundary. */
end_comment

begin_define
define|#
directive|define
name|P_HWPMC
value|0x800000
end_define

begin_comment
comment|/* Process is using HWPMCs */
end_comment

begin_define
define|#
directive|define
name|P_JAILED
value|0x1000000
end_define

begin_comment
comment|/* Process is in jail. */
end_comment

begin_define
define|#
directive|define
name|P_INEXEC
value|0x4000000
end_define

begin_comment
comment|/* Process is in execve(). */
end_comment

begin_define
define|#
directive|define
name|P_STATCHILD
value|0x8000000
end_define

begin_comment
comment|/* Child process stopped or exited. */
end_comment

begin_define
define|#
directive|define
name|P_STOPPED
value|(P_STOPPED_SIG|P_STOPPED_SINGLE|P_STOPPED_TRACE)
end_define

begin_define
define|#
directive|define
name|P_SHOULDSTOP
parameter_list|(
name|p
parameter_list|)
value|((p)->p_flag& P_STOPPED)
end_define

begin_comment
comment|/* These flags are kept in p_sflag and are protected with sched_lock. */
end_comment

begin_define
define|#
directive|define
name|PS_INMEM
value|0x00001
end_define

begin_comment
comment|/* Loaded into memory. */
end_comment

begin_define
define|#
directive|define
name|PS_XCPU
value|0x00002
end_define

begin_comment
comment|/* Exceeded CPU limit. */
end_comment

begin_define
define|#
directive|define
name|PS_ALRMPEND
value|0x00020
end_define

begin_comment
comment|/* Pending SIGVTALRM needs to be posted. */
end_comment

begin_define
define|#
directive|define
name|PS_PROFPEND
value|0x00040
end_define

begin_comment
comment|/* Pending SIGPROF needs to be posted. */
end_comment

begin_define
define|#
directive|define
name|PS_SWAPINREQ
value|0x00100
end_define

begin_comment
comment|/* Swapin request due to wakeup. */
end_comment

begin_define
define|#
directive|define
name|PS_SWAPPINGOUT
value|0x00200
end_define

begin_comment
comment|/* Process is being swapped out. */
end_comment

begin_define
define|#
directive|define
name|PS_SWAPPINGIN
value|0x04000
end_define

begin_comment
comment|/* Process is being swapped in. */
end_comment

begin_define
define|#
directive|define
name|PS_MACPEND
value|0x08000
end_define

begin_comment
comment|/* AST-based MAC event pending. */
end_comment

begin_comment
comment|/*  * These were process status values (p_stat), now they are only used in  * legacy conversion code.  */
end_comment

begin_define
define|#
directive|define
name|SIDL
value|1
end_define

begin_comment
comment|/* Process being created by fork. */
end_comment

begin_define
define|#
directive|define
name|SRUN
value|2
end_define

begin_comment
comment|/* Currently runnable. */
end_comment

begin_define
define|#
directive|define
name|SSLEEP
value|3
end_define

begin_comment
comment|/* Sleeping on an address. */
end_comment

begin_define
define|#
directive|define
name|SSTOP
value|4
end_define

begin_comment
comment|/* Process debugging or suspension. */
end_comment

begin_define
define|#
directive|define
name|SZOMB
value|5
end_define

begin_comment
comment|/* Awaiting collection by parent. */
end_comment

begin_define
define|#
directive|define
name|SWAIT
value|6
end_define

begin_comment
comment|/* Waiting for interrupt. */
end_comment

begin_define
define|#
directive|define
name|SLOCK
value|7
end_define

begin_comment
comment|/* Blocked on a lock. */
end_comment

begin_define
define|#
directive|define
name|P_MAGIC
value|0xbeefface
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Flags for mi_switch(). */
end_comment

begin_define
define|#
directive|define
name|SW_VOL
value|0x0001
end_define

begin_comment
comment|/* Voluntary switch. */
end_comment

begin_define
define|#
directive|define
name|SW_INVOL
value|0x0002
end_define

begin_comment
comment|/* Involuntary switch. */
end_comment

begin_define
define|#
directive|define
name|SW_PREEMPT
value|0x0004
end_define

begin_comment
comment|/* The invol switch is a preemption */
end_comment

begin_comment
comment|/* How values for thread_single(). */
end_comment

begin_define
define|#
directive|define
name|SINGLE_NO_EXIT
value|0
end_define

begin_define
define|#
directive|define
name|SINGLE_EXIT
value|1
end_define

begin_define
define|#
directive|define
name|SINGLE_BOUNDARY
value|2
end_define

begin_comment
comment|/* XXXKSE: Missing values for thread_suspend_check(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PARGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PGRP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SESSION
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SUBPROC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ZOMBIE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FOREACH_PROC_IN_SYSTEM
parameter_list|(
name|p
parameter_list|)
define|\
value|LIST_FOREACH((p),&allproc, p_list)
end_define

begin_define
define|#
directive|define
name|FOREACH_THREAD_IN_PROC
parameter_list|(
name|p
parameter_list|,
name|td
parameter_list|)
define|\
value|TAILQ_FOREACH((td),&(p)->p_threads, td_plist)
end_define

begin_define
define|#
directive|define
name|FOREACH_UPCALL_IN_PROC
parameter_list|(
name|p
parameter_list|,
name|ku
parameter_list|)
define|\
value|TAILQ_FOREACH((ku),&(p)->p_upcalls, ku_link)
end_define

begin_comment
comment|/* XXXKSE the following lines should probably only be used in 1:1 code: */
end_comment

begin_define
define|#
directive|define
name|FIRST_THREAD_IN_PROC
parameter_list|(
name|p
parameter_list|)
value|TAILQ_FIRST(&(p)->p_threads)
end_define

begin_comment
comment|/*  * We use process IDs<= PID_MAX; PID_MAX + 1 must also fit in a pid_t,  * as it is used to represent "no process group".  */
end_comment

begin_define
define|#
directive|define
name|PID_MAX
value|99999
end_define

begin_define
define|#
directive|define
name|NO_PID
value|100000
end_define

begin_define
define|#
directive|define
name|SESS_LEADER
parameter_list|(
name|p
parameter_list|)
value|((p)->p_session->s_leader == (p))
end_define

begin_define
define|#
directive|define
name|SESSHOLD
parameter_list|(
name|s
parameter_list|)
value|((s)->s_count++)
end_define

begin_define
define|#
directive|define
name|SESSRELE
parameter_list|(
name|s
parameter_list|)
value|sessrele(s)
end_define

begin_define
define|#
directive|define
name|STOPEVENT
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|v
parameter_list|)
value|do {						\ 	if ((p)->p_stops& (e))	{					\ 		PROC_LOCK(p);						\ 		stopevent((p), (e), (v));				\ 		PROC_UNLOCK(p);						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|_STOPEVENT
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|v
parameter_list|)
value|do {					\ 	PROC_LOCK_ASSERT(p, MA_OWNED);					\ 	WITNESS_WARN(WARN_GIANTOK | WARN_SLEEPOK,&p->p_mtx.lock_object, \  	    "checking stopevent %d", (e));				\ 	if ((p)->p_stops& (e))						\ 		stopevent((p), (e), (v));				\ } while (0)
end_define

begin_comment
comment|/* Lock and unlock a process. */
end_comment

begin_define
define|#
directive|define
name|PROC_LOCK
parameter_list|(
name|p
parameter_list|)
value|mtx_lock(&(p)->p_mtx)
end_define

begin_define
define|#
directive|define
name|PROC_TRYLOCK
parameter_list|(
name|p
parameter_list|)
value|mtx_trylock(&(p)->p_mtx)
end_define

begin_define
define|#
directive|define
name|PROC_UNLOCK
parameter_list|(
name|p
parameter_list|)
value|mtx_unlock(&(p)->p_mtx)
end_define

begin_define
define|#
directive|define
name|PROC_LOCKED
parameter_list|(
name|p
parameter_list|)
value|mtx_owned(&(p)->p_mtx)
end_define

begin_define
define|#
directive|define
name|PROC_LOCK_ASSERT
parameter_list|(
name|p
parameter_list|,
name|type
parameter_list|)
value|mtx_assert(&(p)->p_mtx, (type))
end_define

begin_comment
comment|/* Lock and unlock a process group. */
end_comment

begin_define
define|#
directive|define
name|PGRP_LOCK
parameter_list|(
name|pg
parameter_list|)
value|mtx_lock(&(pg)->pg_mtx)
end_define

begin_define
define|#
directive|define
name|PGRP_UNLOCK
parameter_list|(
name|pg
parameter_list|)
value|mtx_unlock(&(pg)->pg_mtx)
end_define

begin_define
define|#
directive|define
name|PGRP_LOCKED
parameter_list|(
name|pg
parameter_list|)
value|mtx_owned(&(pg)->pg_mtx)
end_define

begin_define
define|#
directive|define
name|PGRP_LOCK_ASSERT
parameter_list|(
name|pg
parameter_list|,
name|type
parameter_list|)
value|mtx_assert(&(pg)->pg_mtx, (type))
end_define

begin_define
define|#
directive|define
name|PGRP_LOCK_PGSIGNAL
parameter_list|(
name|pg
parameter_list|)
value|do {					\ 	if ((pg) != NULL)						\ 		PGRP_LOCK(pg);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|PGRP_UNLOCK_PGSIGNAL
parameter_list|(
name|pg
parameter_list|)
value|do {					\ 	if ((pg) != NULL)						\ 		PGRP_UNLOCK(pg);					\ } while (0)
end_define

begin_comment
comment|/* Lock and unlock a session. */
end_comment

begin_define
define|#
directive|define
name|SESS_LOCK
parameter_list|(
name|s
parameter_list|)
value|mtx_lock(&(s)->s_mtx)
end_define

begin_define
define|#
directive|define
name|SESS_UNLOCK
parameter_list|(
name|s
parameter_list|)
value|mtx_unlock(&(s)->s_mtx)
end_define

begin_define
define|#
directive|define
name|SESS_LOCKED
parameter_list|(
name|s
parameter_list|)
value|mtx_owned(&(s)->s_mtx)
end_define

begin_define
define|#
directive|define
name|SESS_LOCK_ASSERT
parameter_list|(
name|s
parameter_list|,
name|type
parameter_list|)
value|mtx_assert(&(s)->s_mtx, (type))
end_define

begin_comment
comment|/* Hold process U-area in memory, normally for ptrace/procfs work. */
end_comment

begin_define
define|#
directive|define
name|PHOLD
parameter_list|(
name|p
parameter_list|)
value|do {							\ 	PROC_LOCK(p);							\ 	_PHOLD(p);							\ 	PROC_UNLOCK(p);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PHOLD
parameter_list|(
name|p
parameter_list|)
value|do {							\ 	PROC_LOCK_ASSERT((p), MA_OWNED);				\ 	KASSERT(!((p)->p_flag& P_WEXIT) || (p) == curproc,		\ 	    ("PHOLD of exiting process"));				\ 	(p)->p_lock++;							\ 	if (((p)->p_sflag& PS_INMEM) == 0)				\ 		faultin((p));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|PROC_ASSERT_HELD
parameter_list|(
name|p
parameter_list|)
value|do {					\ 	KASSERT((p)->p_lock> 0, ("process not held"));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PRELE
parameter_list|(
name|p
parameter_list|)
value|do {							\ 	PROC_LOCK((p));							\ 	_PRELE((p));							\ 	PROC_UNLOCK((p));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PRELE
parameter_list|(
name|p
parameter_list|)
value|do {							\ 	PROC_LOCK_ASSERT((p), MA_OWNED);				\ 	(--(p)->p_lock);						\ 	if (((p)->p_flag& P_WEXIT)&& (p)->p_lock == 0)		\ 		wakeup(&(p)->p_lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PROC_ASSERT_NOT_HELD
parameter_list|(
name|p
parameter_list|)
value|do {					\ 	KASSERT((p)->p_lock == 0, ("process held"));			\ } while (0)
end_define

begin_comment
comment|/* Check whether a thread is safe to be swapped out. */
end_comment

begin_define
define|#
directive|define
name|thread_safetoswapout
parameter_list|(
name|td
parameter_list|)
value|(TD_IS_SLEEPING(td) || TD_IS_SUSPENDED(td))
end_define

begin_comment
comment|/* Control whether or not it is safe for curthread to sleep. */
end_comment

begin_define
define|#
directive|define
name|THREAD_NO_SLEEPING
parameter_list|()
value|do {					\ 	KASSERT(!(curthread->td_pflags& TDP_NOSLEEPING),		\ 	    ("nested no sleeping"));					\ 	curthread->td_pflags |= TDP_NOSLEEPING;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|THREAD_SLEEPING_OK
parameter_list|()
value|do {					\ 	KASSERT((curthread->td_pflags& TDP_NOSLEEPING),		\ 	    ("nested sleeping ok"));					\ 	curthread->td_pflags&= ~TDP_NOSLEEPING;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PIDHASH
parameter_list|(
name|pid
parameter_list|)
value|(&pidhashtbl[(pid)& pidhash])
end_define

begin_extern
extern|extern LIST_HEAD(pidhashhead
operator|,
extern|proc
end_extern

begin_expr_stmt
unit|)
operator|*
name|pidhashtbl
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|pidhash
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PGRPHASH
parameter_list|(
name|pgid
parameter_list|)
value|(&pgrphashtbl[(pgid)& pgrphash])
end_define

begin_extern
extern|extern LIST_HEAD(pgrphashhead
operator|,
extern|pgrp
end_extern

begin_expr_stmt
unit|)
operator|*
name|pgrphashtbl
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|pgrphash
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|allproc_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|proctree_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|ppeers_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|proc
name|proc0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process slot for swapper. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thread
name|thread0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Primary thread in proc0. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vmspace
name|vmspace0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VM space for proc0. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hogticks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Limit on kernel cpu hogs. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lastpid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nprocs
decl_stmt|,
name|maxproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current and max number of procs. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxprocperuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max procs per uid. */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|ps_arg_cache_limit
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|proclist
argument_list|,
name|proc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|procqueue
argument_list|,
name|proc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|threadqueue
argument_list|,
name|thread
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|proclist
name|allproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of all processes. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|proclist
name|zombproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of zombie processes. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|initproc
decl_stmt|,
modifier|*
name|pageproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process slots for init, pager. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|uma_zone
modifier|*
name|proc_zone
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|proc
modifier|*
name|pfind
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find process by id. */
end_comment

begin_function_decl
name|struct
name|pgrp
modifier|*
name|pgfind
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find process group by id. */
end_comment

begin_function_decl
name|struct
name|proc
modifier|*
name|zpfind
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find zombie process by id. */
end_comment

begin_function_decl
name|void
name|ast
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|choosethread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cr_cansignal
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|proc
modifier|*
name|proc
parameter_list|,
name|int
name|signum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|enterpgrp
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|pid_t
name|pgid
parameter_list|,
name|struct
name|pgrp
modifier|*
name|pgrp
parameter_list|,
name|struct
name|session
modifier|*
name|sess
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|enterthispgrp
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|pgrp
modifier|*
name|pgrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|faultin
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fixjobc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|pgrp
modifier|*
name|pgrp
parameter_list|,
name|int
name|entering
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fork1
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|proc
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fork_exit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fork_return
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inferior
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kick_proc0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|leavepgrp
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|maybe_preempt
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mi_switch
parameter_list|(
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|newtd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_candebug
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_cansee
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_cansched
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_cansignal
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|signum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_canwait
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pargs
modifier|*
name|pargs_alloc
parameter_list|(
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pargs_drop
parameter_list|(
name|struct
name|pargs
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pargs_free
parameter_list|(
name|struct
name|pargs
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pargs_hold
parameter_list|(
name|struct
name|pargs
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|procinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_linkup
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_reparent
parameter_list|(
name|struct
name|proc
modifier|*
name|child
parameter_list|,
name|struct
name|proc
modifier|*
name|newparent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pstats
modifier|*
name|pstats_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pstats_fork
parameter_list|(
name|struct
name|pstats
modifier|*
name|src
parameter_list|,
name|struct
name|pstats
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pstats_free
parameter_list|(
name|struct
name|pstats
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|securelevel_ge
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|securelevel_gt
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sessrele
parameter_list|(
name|struct
name|session
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setrunnable
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsugid
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigonstack
parameter_list|(
name|size_t
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stopevent
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|threadinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_idle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|cpu_idle_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hook to machdep CPU idler. */
end_comment

begin_function_decl
name|void
name|cpu_switch
parameter_list|(
name|struct
name|thread
modifier|*
name|old
parameter_list|,
name|struct
name|thread
modifier|*
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|cpu_throw
argument_list|(
expr|struct
name|thread
operator|*
name|old
argument_list|,
expr|struct
name|thread
operator|*
name|new
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|unsleep
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|userret
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_exit
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|exit1
argument_list|(
expr|struct
name|thread
operator|*
argument_list|,
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cpu_fork
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_set_fork_handler
parameter_list|(
name|struct
name|thread
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
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* New in KSE. */
end_comment

begin_function_decl
name|void
name|kse_GC
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kseinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_set_upcall
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
name|td0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_set_upcall_kse
parameter_list|(
name|struct
name|thread
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
parameter_list|,
name|void
modifier|*
parameter_list|,
name|stack_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpu_set_user_tls
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|void
modifier|*
name|tls_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_clean
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_exit
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_setup
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_swapin
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_swapout
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|thread_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_continued
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|thread_exit
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|thread_export_context
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|willexit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_free
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_link
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_reap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|thread_schedule_upcall
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|kse_upcall
modifier|*
name|ku
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_signal_add
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|ksiginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thread_single
parameter_list|(
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_single_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_stash
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thread_statclock
parameter_list|(
name|int
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_stopped
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|childproc_stopped
parameter_list|(
name|struct
name|proc
modifier|*
name|child
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|childproc_continued
parameter_list|(
name|struct
name|proc
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|childproc_exited
parameter_list|(
name|struct
name|proc
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thread_suspend_check
parameter_list|(
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_suspend_one
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|thread_switchout
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|newtd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_unlink
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_unsuspend
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_unsuspend_one
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_unthread
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thread_userret
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_user_enter
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thread_wait
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|thread_find
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|lwpid_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thr_exit1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kse_upcall
modifier|*
name|upcall_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upcall_free
parameter_list|(
name|struct
name|kse_upcall
modifier|*
name|ku
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upcall_link
parameter_list|(
name|struct
name|kse_upcall
modifier|*
name|ku
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upcall_unlink
parameter_list|(
name|struct
name|kse_upcall
modifier|*
name|ku
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upcall_remove
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upcall_stash
parameter_list|(
name|struct
name|kse_upcall
modifier|*
name|ke
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PROC_H_ */
end_comment

end_unit

