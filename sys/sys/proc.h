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
file|<machine/proc.h>
end_include

begin_comment
comment|/* Machine-dependent proc substruct. */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/* For struct callout_handle. */
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
file|<sys/rtprio.h>
end_include

begin_comment
comment|/* For struct rtprio. */
end_comment

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
file|<sys/event.h>
end_include

begin_comment
comment|/* For struct klist */
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
comment|/* Session ID */
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
comment|/* Setlogin() name. */
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
comment|/*  * pasleep structure, used by asleep() syscall to hold requested priority  * and timeout values for await().  */
end_comment

begin_struct
struct|struct
name|pasleep
block|{
name|int
name|as_priority
decl_stmt|;
comment|/* Async priority. */
name|int
name|as_timo
decl_stmt|;
comment|/* Async timeout. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * pargs, used to hold a copy of the command line, if it had a sane  * length  */
end_comment

begin_struct
struct|struct
name|pargs
block|{
name|u_int
name|ar_ref
decl_stmt|;
comment|/* Reference count */
name|u_int
name|ar_length
decl_stmt|;
comment|/* Length */
name|u_char
name|ar_args
index|[
literal|0
index|]
decl_stmt|;
comment|/* Arguments */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of a process.  *  * This structure contains the information needed to manage a thread of  * control, known in UN*X as a process; it has references to substructures  * containing descriptions of things that the process uses, but may share  * with related processes.  The process structure and the substructures  * are always addressable except for those marked "(PROC ONLY)" below,  * which might be addressable only on a processor on which the process  * is running.  */
end_comment

begin_struct_decl
struct_decl|struct
name|jail
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
comment|/* run/sleep queue. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_list
expr_stmt|;
comment|/* List of all processes. */
comment|/* substructures: */
name|struct
name|pcred
modifier|*
name|p_cred
decl_stmt|;
comment|/* Process owner's identity. */
name|struct
name|filedesc
modifier|*
name|p_fd
decl_stmt|;
comment|/* Ptr to open files structure. */
name|struct
name|pstats
modifier|*
name|p_stats
decl_stmt|;
comment|/* Accounting/statistics (PROC ONLY). */
name|struct
name|plimit
modifier|*
name|p_limit
decl_stmt|;
comment|/* Process limits. */
name|struct
name|vm_object
modifier|*
name|p_upages_obj
decl_stmt|;
comment|/* Upages object */
name|struct
name|procsig
modifier|*
name|p_procsig
decl_stmt|;
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
name|p_ucred
value|p_cred->pc_ucred
define|#
directive|define
name|p_rlimit
value|p_limit->pl_rlimit
name|int
name|p_flag
decl_stmt|;
comment|/* P_* flags. */
name|char
name|p_stat
decl_stmt|;
comment|/* S* process status. */
name|char
name|p_pad1
index|[
literal|3
index|]
decl_stmt|;
name|pid_t
name|p_pid
decl_stmt|;
comment|/* Process identifier. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_hash
expr_stmt|;
comment|/* Hash chain. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_pglist
expr_stmt|;
comment|/* List of processes in pgrp. */
name|struct
name|proc
modifier|*
name|p_pptr
decl_stmt|;
comment|/* Pointer to parent process. */
name|LIST_ENTRY
argument_list|(
argument|proc
argument_list|)
name|p_sibling
expr_stmt|;
comment|/* List of sibling processes. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|proc
argument_list|)
name|p_children
expr_stmt|;
comment|/* Pointer to list of children. */
name|struct
name|callout_handle
name|p_ithandle
decl_stmt|;
comment|/* 					      * Callout handle for scheduling 					      * p_realtimer. 					      */
comment|/* The following fields are all zeroed upon creation in fork. */
define|#
directive|define
name|p_startzero
value|p_oppid
name|pid_t
name|p_oppid
decl_stmt|;
comment|/* Save parent pid during ptrace. XXX */
name|int
name|p_dupfd
decl_stmt|;
comment|/* Sideways return value from fdopen. XXX */
name|struct
name|vmspace
modifier|*
name|p_vmspace
decl_stmt|;
comment|/* Address space. */
comment|/* scheduling */
name|u_int
name|p_estcpu
decl_stmt|;
comment|/* Time averaged value of p_cpticks. */
name|int
name|p_cpticks
decl_stmt|;
comment|/* Ticks of cpu time. */
name|fixpt_t
name|p_pctcpu
decl_stmt|;
comment|/* %cpu for this process during p_swtime */
name|void
modifier|*
name|p_wchan
decl_stmt|;
comment|/* Sleep address. */
specifier|const
name|char
modifier|*
name|p_wmesg
decl_stmt|;
comment|/* Reason for sleep. */
name|u_int
name|p_swtime
decl_stmt|;
comment|/* Time swapped in or out. */
name|u_int
name|p_slptime
decl_stmt|;
comment|/* Time since last blocked. */
name|struct
name|itimerval
name|p_realtimer
decl_stmt|;
comment|/* Alarm timer. */
name|u_int64_t
name|p_runtime
decl_stmt|;
comment|/* Real time in microsec. */
name|u_int64_t
name|p_uu
decl_stmt|;
comment|/* Previous user time in microsec. */
name|u_int64_t
name|p_su
decl_stmt|;
comment|/* Previous system time in microsec. */
name|u_int64_t
name|p_iu
decl_stmt|;
comment|/* Previous interrupt time in usec. */
name|u_int64_t
name|p_uticks
decl_stmt|;
comment|/* Statclock hits in user mode. */
name|u_int64_t
name|p_sticks
decl_stmt|;
comment|/* Statclock hits in system mode. */
name|u_int64_t
name|p_iticks
decl_stmt|;
comment|/* Statclock hits processing intr. */
name|int
name|p_traceflag
decl_stmt|;
comment|/* Kernel trace points. */
name|struct
name|vnode
modifier|*
name|p_tracep
decl_stmt|;
comment|/* Trace to vnode. */
name|sigset_t
name|p_siglist
decl_stmt|;
comment|/* Signals arrived but not delivered. */
name|struct
name|vnode
modifier|*
name|p_textvp
decl_stmt|;
comment|/* Vnode of executable. */
name|char
name|p_lock
decl_stmt|;
comment|/* Process lock (prevent swap) count. */
name|u_char
name|p_oncpu
decl_stmt|;
comment|/* Which cpu we are on */
name|u_char
name|p_lastcpu
decl_stmt|;
comment|/* Last cpu we were on */
name|char
name|p_rqindex
decl_stmt|;
comment|/* Run queue index */
name|short
name|p_locks
decl_stmt|;
comment|/* DEBUG: lockmgr count of held locks */
name|short
name|p_simple_locks
decl_stmt|;
comment|/* DEBUG: count of held simple locks */
name|unsigned
name|int
name|p_stops
decl_stmt|;
comment|/* procfs event bitmask */
name|unsigned
name|int
name|p_stype
decl_stmt|;
comment|/* procfs stop event type */
name|char
name|p_step
decl_stmt|;
comment|/* procfs stop *once* flag */
name|unsigned
name|char
name|p_pfsflags
decl_stmt|;
comment|/* procfs flags */
name|char
name|p_pad3
index|[
literal|2
index|]
decl_stmt|;
comment|/* padding for alignment */
name|register_t
name|p_retval
index|[
literal|2
index|]
decl_stmt|;
comment|/* syscall aux returns */
name|struct
name|sigiolst
name|p_sigiolst
decl_stmt|;
comment|/* list of sigio sources */
name|int
name|p_sigparent
decl_stmt|;
comment|/* signal to parent on exit */
name|sigset_t
name|p_oldsigmask
decl_stmt|;
comment|/* saved mask from before sigpause */
name|int
name|p_sig
decl_stmt|;
comment|/* for core dump/debugger XXX */
name|u_long
name|p_code
decl_stmt|;
comment|/* for core dump/debugger XXX */
name|struct
name|klist
name|p_klist
decl_stmt|;
comment|/* knotes attached to this process */
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
comment|/* Current signal mask. */
name|stack_t
name|p_sigstk
decl_stmt|;
comment|/* sp& on stack state variable */
name|u_char
name|p_priority
decl_stmt|;
comment|/* Process priority. */
name|u_char
name|p_usrpri
decl_stmt|;
comment|/* User-priority based on p_cpu and p_nice. */
name|char
name|p_nice
decl_stmt|;
comment|/* Process "nice" value. */
name|char
name|p_comm
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|pgrp
modifier|*
name|p_pgrp
decl_stmt|;
comment|/* Pointer to process group. */
name|struct
name|sysentvec
modifier|*
name|p_sysent
decl_stmt|;
comment|/* System call dispatch information. */
name|struct
name|rtprio
name|p_rtprio
decl_stmt|;
comment|/* Realtime priority. */
name|struct
name|prison
modifier|*
name|p_prison
decl_stmt|;
name|struct
name|pargs
modifier|*
name|p_args
decl_stmt|;
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
comment|/* Kernel virtual addr of u-area (PROC ONLY). */
name|struct
name|mdproc
name|p_md
decl_stmt|;
comment|/* Any machine-dependent fields. */
name|u_short
name|p_xstat
decl_stmt|;
comment|/* Exit status for wait; also stop signal. */
name|u_short
name|p_acflag
decl_stmt|;
comment|/* Accounting flags. */
name|struct
name|rusage
modifier|*
name|p_ru
decl_stmt|;
comment|/* Exit information. XXX */
name|int
name|p_nthreads
decl_stmt|;
comment|/* number of threads (only in leader) */
name|void
modifier|*
name|p_aioinfo
decl_stmt|;
comment|/* ASYNC I/O info */
name|int
name|p_wakeup
decl_stmt|;
comment|/* thread id */
name|struct
name|proc
modifier|*
name|p_peers
decl_stmt|;
name|struct
name|proc
modifier|*
name|p_leader
decl_stmt|;
name|struct
name|pasleep
name|p_asleep
decl_stmt|;
comment|/* Used by asleep()/await(). */
name|void
modifier|*
name|p_emuldata
decl_stmt|;
comment|/* process-specific emulator state data */
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

begin_comment
comment|/* Status values. */
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

begin_comment
comment|/* These flags are kept in p_flags. */
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
name|P_INMEM
value|0x00004
end_define

begin_comment
comment|/* Loaded into memory. */
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
name|P_SELECT
value|0x00040
end_define

begin_comment
comment|/* Selecting; wakeup/waiting danger. */
end_comment

begin_define
define|#
directive|define
name|P_SINTR
value|0x00080
end_define

begin_comment
comment|/* Sleep is interruptible. */
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
name|P_TIMEOUT
value|0x00400
end_define

begin_comment
comment|/* Timing out during sleep. */
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
comment|/* Should probably be changed into a hold count. */
end_comment

begin_comment
comment|/* was	P_NOSWAP	0x08000	was: Do not swap upages; p->p_hold */
end_comment

begin_comment
comment|/* was	P_PHYSIO	0x10000	was: Doing physical I/O; use p->p_hold */
end_comment

begin_comment
comment|/* Should be moved to machine-dependent areas. */
end_comment

begin_define
define|#
directive|define
name|P_OWEUPC
value|0x20000
end_define

begin_comment
comment|/* Owe process an addupc() call at next ast. */
end_comment

begin_define
define|#
directive|define
name|P_SWAPPING
value|0x40000
end_define

begin_comment
comment|/* Process is being swapped. */
end_comment

begin_define
define|#
directive|define
name|P_SWAPINREQ
value|0x80000
end_define

begin_comment
comment|/* Swapin request due to wakeup */
end_comment

begin_comment
comment|/* Marked a kernel thread */
end_comment

begin_define
define|#
directive|define
name|P_UNUSED100000
value|0x100000
end_define

begin_define
define|#
directive|define
name|P_KTHREADP
value|0x200000
end_define

begin_comment
comment|/* Process is really a kernel thread */
end_comment

begin_define
define|#
directive|define
name|P_DEADLKTREAT
value|0x800000
end_define

begin_comment
comment|/* lock aquisition - deadlock treatment */
end_comment

begin_define
define|#
directive|define
name|P_JAILED
value|0x1000000
end_define

begin_comment
comment|/* Process is in jail */
end_comment

begin_define
define|#
directive|define
name|P_OLDMASK
value|0x2000000
end_define

begin_comment
comment|/* need to restore mask before pause */
end_comment

begin_define
define|#
directive|define
name|P_ALTSTACK
value|0x4000000
end_define

begin_comment
comment|/* have alternate signal stack */
end_comment

begin_define
define|#
directive|define
name|P_INEXEC
value|0x8000000
end_define

begin_comment
comment|/* Process is in execve(). */
end_comment

begin_comment
comment|/*  * MOVE TO ucred.h?  *  * Shareable process credentials (always resident).  This includes a reference  * to the current user credentials as well as real and saved ids that may be  * used to change ids.  */
end_comment

begin_struct
struct|struct
name|pcred
block|{
name|struct
name|ucred
modifier|*
name|pc_ucred
decl_stmt|;
comment|/* Current credentials. */
name|uid_t
name|p_ruid
decl_stmt|;
comment|/* Real user id. */
name|uid_t
name|p_svuid
decl_stmt|;
comment|/* Saved effective user id. */
name|gid_t
name|p_rgid
decl_stmt|;
comment|/* Real group id. */
name|gid_t
name|p_svgid
decl_stmt|;
comment|/* Saved effective group id. */
name|int
name|p_refcnt
decl_stmt|;
comment|/* Number of references. */
name|struct
name|uidinfo
modifier|*
name|p_uidinfo
decl_stmt|;
comment|/* Per uid resource consumption */
block|}
struct|;
end_struct

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

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PARGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags for suser_xxx() */
end_comment

begin_define
define|#
directive|define
name|PRISON_ROOT
value|1
end_define

begin_comment
comment|/* Handy macro to determine of p1 can mangle p2 */
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
value|((!(p1)->p_prison) || (p1)->p_prison == (p2)->p_prison)
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

begin_comment
comment|/*  * STOPEVENT is MP SAFE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|stopevent
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

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
define|\
value|do {					\ 		if ((p)->p_stops& (e)) {	\ 			get_mplock();		\ 			stopevent(p,e,v);	\ 			rel_mplock(); 		\ 		}				\ 	} while (0)
end_define

begin_comment
comment|/* hold process U-area in memory, normally for ptrace/procfs work */
end_comment

begin_define
define|#
directive|define
name|PHOLD
parameter_list|(
name|p
parameter_list|)
value|{							\ 	if ((p)->p_lock++ == 0&& ((p)->p_flag& P_INMEM) == 0)	\ 		faultin(p);						\ }
end_define

begin_define
define|#
directive|define
name|PRELE
parameter_list|(
name|p
parameter_list|)
value|(--(p)->p_lock)
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

begin_ifndef
ifndef|#
directive|ifndef
name|SET_CURPROC
end_ifndef

begin_define
define|#
directive|define
name|SET_CURPROC
parameter_list|(
name|p
parameter_list|)
value|(curproc = (p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|curproc
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|curproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current running proc. */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|astpending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* software interrupt pending */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|switchticks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `ticks' at last context switch. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|switchtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Uptime at last context switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|sched_quantum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scheduling quantum in ticks */
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
decl_stmt|,
modifier|*
name|updateproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process slots for init, pager. */
end_comment

begin_define
define|#
directive|define
name|NQS
value|32
end_define

begin_comment
comment|/* 32 run queues. */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|rq
argument_list|,
name|proc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rq
name|queues
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rq
name|rtqueues
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rq
name|idqueues
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|whichqs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bit mask summary of non-empty Q's. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|whichrtqs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bit mask summary of non-empty Q's. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|whichidqs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bit mask summary of non-empty Q's. */
end_comment

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
value|min((e), INVERSE_ESTCPU_WEIGHT * (NICE_WEIGHT * PRIO_MAX - PPQ) + \ 	     INVERSE_ESTCPU_WEIGHT - 1)
end_define

begin_define
define|#
directive|define
name|INVERSE_ESTCPU_WEIGHT
value|8
end_define

begin_comment
comment|/* 1 / (priorities per estcpu level) */
end_comment

begin_define
define|#
directive|define
name|NICE_WEIGHT
value|2
end_define

begin_comment
comment|/* priorities per nice level */
end_comment

begin_define
define|#
directive|define
name|PPQ
value|(128 / NQS)
end_define

begin_comment
comment|/* priorities per queue */
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

begin_struct_decl
struct_decl|struct
name|vm_zone
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|vm_zone
modifier|*
name|proc_zone
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
name|int
name|suser
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
name|suser_xxx
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|proc
operator|,
name|int
name|flag
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
name|cpu_switch
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
name|u_int32_t
name|procrunnable
name|__P
argument_list|(
operator|(
name|void
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

