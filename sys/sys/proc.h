begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)proc.h	8.15 (Berkeley) 5/19/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
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
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/runq.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * One structure allocated per session.  */
end_comment

begin_struct
struct|struct
name|session
block|{
name|int
name|s_count
decl_stmt|;
comment|/* Ref cnt; pgrps in session. */
name|struct
name|proc
modifier|*
name|s_leader
decl_stmt|;
comment|/* Session leader. */
name|struct
name|vnode
modifier|*
name|s_ttyvp
decl_stmt|;
comment|/* Vnode of controlling terminal. */
name|struct
name|tty
modifier|*
name|s_ttyp
decl_stmt|;
comment|/* Controlling terminal. */
name|pid_t
name|s_sid
decl_stmt|;
comment|/* Session ID. */
comment|/* Setlogin() name: */
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * One structure allocated per process group.  */
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
comment|/* Hash chain. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|proc
argument_list|)
name|pg_members
expr_stmt|;
comment|/* Pointer to pgrp members. */
name|struct
name|session
modifier|*
name|pg_session
decl_stmt|;
comment|/* Pointer to session. */
name|struct
name|sigiolst
name|pg_sigiolst
decl_stmt|;
comment|/* List of sigio sources. */
name|pid_t
name|pg_id
decl_stmt|;
comment|/* Pgrp id. */
name|int
name|pg_jobc
decl_stmt|;
comment|/* # procs qualifying pgrp for job control */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|procsig
block|{
name|sigset_t
name|ps_sigignore
decl_stmt|;
comment|/* Signals being ignored. */
name|sigset_t
name|ps_sigcatch
decl_stmt|;
comment|/* Signals being caught by user. */
name|int
name|ps_flag
decl_stmt|;
name|struct
name|sigacts
modifier|*
name|ps_sigacts
decl_stmt|;
comment|/* Signal actions, state. */
name|int
name|ps_refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PS_NOCLDWAIT
value|0x0001
end_define

begin_comment
comment|/* No zombies if child dies */
end_comment

begin_define
define|#
directive|define
name|PS_NOCLDSTOP
value|0x0002
end_define

begin_comment
comment|/* No SIGCHLD when children stop. */
end_comment

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
literal|0
index|]
decl_stmt|;
comment|/* Arguments. */
block|}
struct|;
end_struct

begin_comment
comment|/*-  * Description of a process.  *  * This structure contains the information needed to manage a thread of  * control, known in UN*X as a process; it has references to substructures  * containing descriptions of things that the process uses, but may share  * with related processes.  The process structure and the substructures  * are always addressable except for those marked "(CPU)" below,  * which might be addressable only on a processor on which the process  * is running.  *  * Below is a key of locks used to protect each member of struct proc.  The  * lock is indicated by a reference to a specific character in parens in the  * associated comment.  *      * - not yet protected  *      a - only touched by curproc or parent during fork/wait  *      b - created at fork, never changes  *      	(exception aiods switch vmspaces, but they are also  *      	marked 'P_SYSTEM' so hopefully it will be left alone)  *      c - locked by proc mtx  *      d - locked by allproc_lock lock  *      e - locked by proctree_lock lock  *      f - session mtx  *      g - process group mtx  *      h - callout_lock mtx  *      i - by curproc or the master session mtx  *      j - locked by sched_lock mtx  *      k - either by curproc or a lock which prevents the lock from  *          going away, such as (d,e)  *      l - the attaching proc or attaching proc parent  *      m - Giant  *      n - not locked, lazy  *  * If the locking key specifies two identifiers (for example, p_pptr) then  * either lock is sufficient for read access, but both locks must be held  * for write access.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ithd
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nlminfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|proc
block|{
name|TAILQ_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_procq
expr_stmt|;
comment|/* (j) Run/mutex queue. */
name|TAILQ_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_slpq
expr_stmt|;
comment|/* (j) Sleep queue. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_list
expr_stmt|;
comment|/* (d) List of all processes. */
comment|/* substructures: */
name|struct
name|ucred
modifier|*
name|p_ucred
decl_stmt|;
comment|/* (c + k) Process owner's identity. */
name|struct
name|filedesc
modifier|*
name|p_fd
decl_stmt|;
comment|/* (b) Ptr to open files structure. */
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
comment|/* (m) Process limits. */
name|struct
name|vm_object
modifier|*
name|p_upages_obj
decl_stmt|;
comment|/* (a) Upages object. */
name|struct
name|procsig
modifier|*
name|p_procsig
decl_stmt|;
comment|/* (c) Signal actions, state (CPU). */
define|#
directive|define
name|p_sigacts
value|p_procsig->ps_sigacts
define|#
directive|define
name|p_sigignore
value|p_procsig->ps_sigignore
define|#
directive|define
name|p_sigcatch
value|p_procsig->ps_sigcatch
define|#
directive|define
name|p_rlimit
value|p_limit->pl_rlimit
name|int
name|p_flag
decl_stmt|;
comment|/* (c) P_* flags. */
name|int
name|p_sflag
decl_stmt|;
comment|/* (j) PS_* flags. */
name|int
name|p_stat
decl_stmt|;
comment|/* (j) S* process status. */
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
comment|/* (c) List of processes in pgrp. */
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
comment|/* The following fields are all zeroed upon creation in fork. */
define|#
directive|define
name|p_startzero
value|p_oppid
name|pid_t
name|p_oppid
decl_stmt|;
comment|/* (c + e) Save parent pid during ptrace. XXX */
name|int
name|p_dupfd
decl_stmt|;
comment|/* (c) Sideways ret value from fdopen. XXX */
name|struct
name|vmspace
modifier|*
name|p_vmspace
decl_stmt|;
comment|/* (b) Address space. */
comment|/* scheduling */
name|u_int
name|p_estcpu
decl_stmt|;
comment|/* (j) Time averaged value of p_cpticks. */
name|int
name|p_cpticks
decl_stmt|;
comment|/* (j) Ticks of cpu time. */
name|fixpt_t
name|p_pctcpu
decl_stmt|;
comment|/* (j) %cpu during p_swtime. */
name|struct
name|callout
name|p_slpcallout
decl_stmt|;
comment|/* (h) Callout for sleep. */
name|void
modifier|*
name|p_wchan
decl_stmt|;
comment|/* (j) Sleep address. */
specifier|const
name|char
modifier|*
name|p_wmesg
decl_stmt|;
comment|/* (j) Reason for sleep. */
name|u_int
name|p_swtime
decl_stmt|;
comment|/* (j) Time swapped in or out. */
name|u_int
name|p_slptime
decl_stmt|;
comment|/* (j) Time since last blocked. */
name|struct
name|callout
name|p_itcallout
decl_stmt|;
comment|/* (h) Interval timer callout. */
name|struct
name|itimerval
name|p_realtimer
decl_stmt|;
comment|/* (h?/k?) Alarm timer. */
name|u_int64_t
name|p_runtime
decl_stmt|;
comment|/* (j) Real time in microsec. */
name|u_int64_t
name|p_uu
decl_stmt|;
comment|/* (j) Previous user time in microsec. */
name|u_int64_t
name|p_su
decl_stmt|;
comment|/* (j) Previous system time in microsec. */
name|u_int64_t
name|p_iu
decl_stmt|;
comment|/* (j) Previous interrupt time in microsec. */
name|u_int64_t
name|p_uticks
decl_stmt|;
comment|/* (j) Statclock hits in user mode. */
name|u_int64_t
name|p_sticks
decl_stmt|;
comment|/* (j) Statclock hits in system mode. */
name|u_int64_t
name|p_iticks
decl_stmt|;
comment|/* (j) Statclock hits processing intr. */
name|int
name|p_traceflag
decl_stmt|;
comment|/* (j?) Kernel trace points. */
name|struct
name|vnode
modifier|*
name|p_tracep
decl_stmt|;
comment|/* (j?) Trace to vnode. */
name|sigset_t
name|p_siglist
decl_stmt|;
comment|/* (c) Signals arrived but not delivered. */
name|struct
name|vnode
modifier|*
name|p_textvp
decl_stmt|;
comment|/* (b) Vnode of executable. */
name|struct
name|mtx
name|p_mtx
decl_stmt|;
comment|/* (k) Lock for this struct. */
name|char
name|p_lock
decl_stmt|;
comment|/* (c) Process lock (prevent swap) count. */
name|u_char
name|p_oncpu
decl_stmt|;
comment|/* (j) Which cpu we are on. */
name|u_char
name|p_lastcpu
decl_stmt|;
comment|/* (j) Last cpu we were on. */
name|char
name|p_rqindex
decl_stmt|;
comment|/* (j) Run queue index. */
name|short
name|p_locks
decl_stmt|;
comment|/* (*) DEBUG: lockmgr count of held locks */
name|u_int
name|p_stops
decl_stmt|;
comment|/* (c) Procfs event bitmask. */
name|u_int
name|p_stype
decl_stmt|;
comment|/* (c) Procfs stop event type. */
name|char
name|p_step
decl_stmt|;
comment|/* (c) Procfs stop *once* flag. */
name|u_char
name|p_pfsflags
decl_stmt|;
comment|/* (c) Procfs flags. */
name|char
name|p_pad3
index|[
literal|2
index|]
decl_stmt|;
comment|/* Alignment. */
name|register_t
name|p_retval
index|[
literal|2
index|]
decl_stmt|;
comment|/* (k) Syscall aux returns. */
name|struct
name|sigiolst
name|p_sigiolst
decl_stmt|;
comment|/* (c) List of sigio sources. */
name|int
name|p_sigparent
decl_stmt|;
comment|/* (c) Signal to parent on exit. */
name|sigset_t
name|p_oldsigmask
decl_stmt|;
comment|/* (c) Saved mask from before sigpause. */
name|int
name|p_sig
decl_stmt|;
comment|/* (n) For core dump/debugger XXX. */
name|u_long
name|p_code
decl_stmt|;
comment|/* (n) For core dump/debugger XXX. */
name|struct
name|klist
name|p_klist
decl_stmt|;
comment|/* (c) Knotes attached to this process. */
name|struct
name|lock_list_entry
modifier|*
name|p_sleeplocks
decl_stmt|;
comment|/* (k) Held sleep locks. */
name|struct
name|mtx
modifier|*
name|p_blocked
decl_stmt|;
comment|/* (j) Mutex process is blocked on. */
specifier|const
name|char
modifier|*
name|p_mtxname
decl_stmt|;
comment|/* (j) Name of mutex blocked on. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|mtx
argument_list|)
name|p_contested
expr_stmt|;
comment|/* (j) Contested locks. */
name|struct
name|nlminfo
modifier|*
name|p_nlminfo
decl_stmt|;
comment|/* (?) only used by/for lockd */
name|void
modifier|*
name|p_aioinfo
decl_stmt|;
comment|/* (c) ASYNC I/O info. */
name|struct
name|ithd
modifier|*
name|p_ithd
decl_stmt|;
comment|/* (b) For interrupt threads only. */
name|int
name|p_intr_nesting_level
decl_stmt|;
comment|/* (k) Interrupt recursion. */
name|int
name|p_giant_optional
decl_stmt|;
comment|/* (i) Giant Lock Sanity */
comment|/* End area that is zeroed on creation. */
define|#
directive|define
name|p_endzero
value|p_startcopy
comment|/* The following fields are all copied upon creation in fork. */
define|#
directive|define
name|p_startcopy
value|p_sigmask
name|sigset_t
name|p_sigmask
decl_stmt|;
comment|/* (c) Current signal mask. */
name|stack_t
name|p_sigstk
decl_stmt|;
comment|/* (c) Stack pointer and on-stack flag. */
name|int
name|p_magic
decl_stmt|;
comment|/* (b) Magic number. */
name|struct
name|priority
name|p_pri
decl_stmt|;
comment|/* (j) Process priority. */
name|char
name|p_nice
decl_stmt|;
comment|/* (j?/k?) Process "nice" value. */
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
comment|/* (e?/c?) Pointer to process group. */
name|struct
name|sysentvec
modifier|*
name|p_sysent
decl_stmt|;
comment|/* (b) System call dispatch information. */
name|struct
name|pargs
modifier|*
name|p_args
decl_stmt|;
comment|/* (c + k) Process arguments. */
comment|/* End area that is copied on creation. */
define|#
directive|define
name|p_endcopy
value|p_addr
name|struct
name|user
modifier|*
name|p_addr
decl_stmt|;
comment|/* (k) Kernel virtual addr of u-area (CPU). */
name|struct
name|mdproc
name|p_md
decl_stmt|;
comment|/* (k) Any machine-dependent fields. */
name|u_short
name|p_xstat
decl_stmt|;
comment|/* (c) Exit status for wait; also stop sig. */
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
comment|/* (c) */
name|struct
name|proc
modifier|*
name|p_leader
decl_stmt|;
comment|/* (c) */
name|void
modifier|*
name|p_emuldata
decl_stmt|;
comment|/* (c) Emulator state data. */
name|struct
name|trapframe
modifier|*
name|p_frame
decl_stmt|;
comment|/* (k) */
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
comment|/* For p_oncpu when we aren't on a CPU. */
end_comment

begin_comment
comment|/* Status values (p_stat). */
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
name|SMTX
value|7
end_define

begin_comment
comment|/* Blocked on a mutex. */
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
comment|/* Kernel thread. */
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
name|P_SELECT
value|0x00040
end_define

begin_comment
comment|/* Selecting; wakeup/waiting danger. */
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
comment|/* Debugging process has waited for child. */
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

begin_comment
comment|/* Should be moved to machine-dependent areas. */
end_comment

begin_define
define|#
directive|define
name|P_BUFEXHAUST
value|0x100000
end_define

begin_comment
comment|/* Dirty buffers flush is in progress. */
end_comment

begin_define
define|#
directive|define
name|P_COWINPROGRESS
value|0x400000
end_define

begin_comment
comment|/* Snapshot copy-on-write in progress. */
end_comment

begin_define
define|#
directive|define
name|P_DEADLKTREAT
value|0x800000
end_define

begin_comment
comment|/* Lock aquisition - deadlock treatment. */
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
name|P_OLDMASK
value|0x2000000
end_define

begin_comment
comment|/* Need to restore mask after suspend. */
end_comment

begin_define
define|#
directive|define
name|P_ALTSTACK
value|0x4000000
end_define

begin_comment
comment|/* Have alternate signal stack. */
end_comment

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
name|PS_OWEUPC
value|0x00002
end_define

begin_comment
comment|/* Owe process an addupc() call at next ast. */
end_comment

begin_define
define|#
directive|define
name|PS_PROFIL
value|0x00004
end_define

begin_comment
comment|/* Has started profiling. */
end_comment

begin_define
define|#
directive|define
name|PS_SINTR
value|0x00008
end_define

begin_comment
comment|/* Sleep is interruptible. */
end_comment

begin_define
define|#
directive|define
name|PS_TIMEOUT
value|0x00010
end_define

begin_comment
comment|/* Timing out during sleep. */
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
name|PS_CVWAITQ
value|0x00080
end_define

begin_comment
comment|/* Proces is on a cv_waitq (not slpq). */
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
name|PS_SWAPPING
value|0x00200
end_define

begin_comment
comment|/* Process is being swapped. */
end_comment

begin_define
define|#
directive|define
name|PS_ASTPENDING
value|0x00400
end_define

begin_comment
comment|/* Process has a pending ast. */
end_comment

begin_define
define|#
directive|define
name|PS_NEEDRESCHED
value|0x00800
end_define

begin_comment
comment|/* Process needs to yield. */
end_comment

begin_define
define|#
directive|define
name|PS_TIMOFAIL
value|0x01000
end_define

begin_comment
comment|/* Timeout from sleep after we were awake. */
end_comment

begin_define
define|#
directive|define
name|P_MAGIC
value|0xbeefface
end_define

begin_define
define|#
directive|define
name|P_CAN_SEE
value|1
end_define

begin_define
define|#
directive|define
name|P_CAN_SCHED
value|3
end_define

begin_define
define|#
directive|define
name|P_CAN_DEBUG
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_function
specifier|static
name|__inline
name|int
name|sigonstack
parameter_list|(
name|size_t
name|sp
parameter_list|)
block|{
specifier|register
name|struct
name|proc
modifier|*
name|p
init|=
name|curproc
decl_stmt|;
return|return
operator|(
operator|(
name|p
operator|->
name|p_flag
operator|&
name|P_ALTSTACK
operator|)
condition|?
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
operator|(
operator|(
name|p
operator|->
name|p_sigstk
operator|.
name|ss_size
operator|==
literal|0
operator|)
condition|?
operator|(
name|p
operator|->
name|p_sigstk
operator|.
name|ss_flags
operator|&
name|SS_ONSTACK
operator|)
else|:
operator|(
operator|(
name|sp
operator|-
operator|(
name|size_t
operator|)
name|p
operator|->
name|p_sigstk
operator|.
name|ss_sp
operator|)
operator|<
name|p
operator|->
name|p_sigstk
operator|.
name|ss_size
operator|)
operator|)
else|#
directive|else
operator|(
operator|(
name|sp
operator|-
operator|(
name|size_t
operator|)
name|p
operator|->
name|p_sigstk
operator|.
name|ss_sp
operator|)
operator|<
name|p
operator|->
name|p_sigstk
operator|.
name|ss_size
operator|)
endif|#
directive|endif
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Notify the current process (p) that it has a signal pending,  * process as soon as possible.  */
end_comment

begin_define
define|#
directive|define
name|signotify
parameter_list|(
name|p
parameter_list|)
value|do {						\ 	mtx_assert(&sched_lock, MA_OWNED);				\ 	(p)->p_sflag |= PS_ASTPENDING;					\ } while (0)
end_define

begin_comment
comment|/* Handy macro to determine if p1 can mangle p2. */
end_comment

begin_define
define|#
directive|define
name|PRISON_CHECK
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|((p1)->p_prison == NULL || (p1)->p_prison == (p2)->p_prison)
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
value|{							\ 	if (--(s)->s_count == 0)					\ 		FREE(s, M_SESSION);					\ }
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
value|do {						\ 	PROC_LOCK(p);							\ 	_STOPEVENT((p), (e), (v));					\ 	PROC_UNLOCK(p);							\ } while (0)
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
value|do {					\ 	PROC_LOCK_ASSERT(p, MA_OWNED);					\ 	if ((p)->p_stops& (e)) {					\ 		stopevent((p), (e), (v));				\ 	}								\ } while (0)
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
name|PROC_UNLOCK_NOSWITCH
parameter_list|(
name|p
parameter_list|)
define|\
value|mtx_unlock_flags(&(p)->p_mtx, MTX_NOSWITCH)
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
value|do {							\ 	PROC_LOCK_ASSERT((p), MA_OWNED);				\ 	if ((p)->p_lock++ == 0)						\ 		faultin((p));						\ } while (0)
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
value|do {							\ 	PROC_LOCK_ASSERT((p), MA_OWNED);				\ 	(--(p)->p_lock);						\ } while (0)
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
name|proc
name|proc0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process slot for swapper. */
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

begin_decl_stmt
specifier|extern
name|int
name|ps_argsopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ps_showallprocs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sched_quantum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scheduling quantum in ticks. */
end_comment

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
name|proc
modifier|*
name|updateproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process slot for syncer (sic). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vm_zone
modifier|*
name|proc_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX macros for scheduler.  Shouldn't be here, but currently needed for  * bounding the dubious p_estcpu inheritance in wait1().  * INVERSE_ESTCPU_WEIGHT is only suitable for statclock() frequencies in  * the range 100-256 Hz (approximately).  */
end_comment

begin_define
define|#
directive|define
name|ESTCPULIM
parameter_list|(
name|e
parameter_list|)
define|\
value|min((e), INVERSE_ESTCPU_WEIGHT * (NICE_WEIGHT * (PRIO_MAX - PRIO_MIN) - \ 	     RQ_PPQ) + INVERSE_ESTCPU_WEIGHT - 1)
end_define

begin_define
define|#
directive|define
name|INVERSE_ESTCPU_WEIGHT
value|8
end_define

begin_comment
comment|/* 1 / (priorities per estcpu level). */
end_comment

begin_define
define|#
directive|define
name|NICE_WEIGHT
value|1
end_define

begin_comment
comment|/* Priorities per nice level. */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|pfind
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find process by id. */
end_comment

begin_decl_stmt
name|struct
name|pgrp
modifier|*
name|pgfind
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find process group by id. */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|zpfind
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find zombie process by id. */
end_comment

begin_decl_stmt
name|void
name|ast
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
operator|*
name|framep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|chooseproc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|enterpgrp
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|pid_t
name|pgid
operator|,
name|int
name|mksess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|faultin
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fixjobc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|pgrp
operator|*
name|pgrp
operator|,
name|int
name|entering
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fork1
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fork_exit
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
expr|struct
name|trapframe
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|,
expr|struct
name|trapframe
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fork_return
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|trapframe
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inferior
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|leavepgrp
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mi_switch
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p_candebug
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p1
operator|,
expr|struct
name|proc
operator|*
name|p2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p_cansee
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p1
operator|,
expr|struct
name|proc
operator|*
name|p2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p_cansched
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p1
operator|,
expr|struct
name|proc
operator|*
name|p2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p_cansignal
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p1
operator|,
expr|struct
name|proc
operator|*
name|p2
operator|,
name|int
name|signum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p_trespass
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p1
operator|,
expr|struct
name|proc
operator|*
name|p2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|procinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|proc_reparent
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|child
operator|,
expr|struct
name|proc
operator|*
name|newparent
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procrunnable
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|remrunqueue
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|resetpriority
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|roundrobin_interval
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|schedclock
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setrunnable
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setrunqueue
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setsugid
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sleepinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stopevent
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_idle
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_switch
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_throw
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unsleep
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|updatepri
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|userret
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|trapframe
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maybe_resched
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_exit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exit1
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|int
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_fork
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_set_fork_handler
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trace_req
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_wait
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpu_coredump
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

