begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)proc.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROC_H_
end_define

begin_include
include|#
directive|include
file|<machine/proc.h>
end_include

begin_comment
comment|/* machine-dependent proc substruct */
end_comment

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/* for struct selinfo */
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
comment|/* ref cnt; pgrps in session */
name|struct
name|proc
modifier|*
name|s_leader
decl_stmt|;
comment|/* session leader */
name|struct
name|vnode
modifier|*
name|s_ttyvp
decl_stmt|;
comment|/* vnode of controlling terminal */
name|struct
name|tty
modifier|*
name|s_ttyp
decl_stmt|;
comment|/* controlling terminal */
name|char
name|s_login
index|[
name|MAXLOGNAME
index|]
decl_stmt|;
comment|/* setlogin() name */
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
name|struct
name|pgrp
modifier|*
name|pg_hforw
decl_stmt|;
comment|/* forward link in hash bucket */
name|struct
name|proc
modifier|*
name|pg_mem
decl_stmt|;
comment|/* pointer to pgrp members */
name|struct
name|session
modifier|*
name|pg_session
decl_stmt|;
comment|/* pointer to session */
name|pid_t
name|pg_id
decl_stmt|;
comment|/* pgrp id */
name|int
name|pg_jobc
decl_stmt|;
comment|/* # procs qualifying pgrp for job control */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of a process.  * This structure contains the information needed to manage a thread  * of control, known in UN*X as a process; it has references to substructures  * containing descriptions of things that the process uses, but may share  * with related processes.  The process structure and the substructures  * are always addressible except for those marked "(PROC ONLY)" below,  * which might be addressible only on a processor on which the process  * is running.  */
end_comment

begin_struct
struct|struct
name|proc
block|{
name|struct
name|proc
modifier|*
name|p_link
decl_stmt|;
comment|/* doubly-linked run/sleep queue */
name|struct
name|proc
modifier|*
name|p_rlink
decl_stmt|;
name|struct
name|proc
modifier|*
name|p_nxt
decl_stmt|;
comment|/* linked list of active procs */
name|struct
name|proc
modifier|*
modifier|*
name|p_prev
decl_stmt|;
comment|/*    and zombies */
comment|/* substructures: */
name|struct
name|pcred
modifier|*
name|p_cred
decl_stmt|;
comment|/* process owner's identity */
name|struct
name|filedesc
modifier|*
name|p_fd
decl_stmt|;
comment|/* ptr to open files structure */
name|struct
name|pstats
modifier|*
name|p_stats
decl_stmt|;
comment|/* accounting/statistics (PROC ONLY) */
name|struct
name|plimit
modifier|*
name|p_limit
decl_stmt|;
comment|/* process limits */
name|struct
name|vmspace
modifier|*
name|p_vmspace
decl_stmt|;
comment|/* address space */
name|struct
name|sigacts
modifier|*
name|p_sigacts
decl_stmt|;
comment|/* signal actions, state (PROC ONLY) */
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
name|char
name|p_stat
decl_stmt|;
name|char
name|p_pad1
index|[
literal|3
index|]
decl_stmt|;
name|pid_t
name|p_pid
decl_stmt|;
comment|/* unique process id */
name|struct
name|proc
modifier|*
name|p_hash
decl_stmt|;
comment|/* hashed based on p_pid for kill+exit+... */
name|struct
name|proc
modifier|*
name|p_pgrpnxt
decl_stmt|;
comment|/* pointer to next process in process group */
name|struct
name|proc
modifier|*
name|p_pptr
decl_stmt|;
comment|/* pointer to process structure of parent */
name|struct
name|proc
modifier|*
name|p_osptr
decl_stmt|;
comment|/* pointer to older sibling processes */
comment|/* The following fields are all zeroed upon creation in fork */
define|#
directive|define
name|p_startzero
value|p_ysptr
name|struct
name|proc
modifier|*
name|p_ysptr
decl_stmt|;
comment|/* pointer to younger siblings */
name|struct
name|proc
modifier|*
name|p_cptr
decl_stmt|;
comment|/* pointer to youngest living child */
name|pid_t
name|p_oppid
decl_stmt|;
comment|/* save parent pid during ptrace XXX */
name|int
name|p_dupfd
decl_stmt|;
comment|/* sideways return value from fdopen XXX */
comment|/* scheduling */
name|u_int
name|p_cpu
decl_stmt|;
comment|/* cpu usage for scheduling */
name|int
name|p_cpticks
decl_stmt|;
comment|/* ticks of cpu time */
name|fixpt_t
name|p_pctcpu
decl_stmt|;
comment|/* %cpu for this process during p_time */
name|caddr_t
name|p_wchan
decl_stmt|;
comment|/* event process is awaiting */
name|char
modifier|*
name|p_wmesg
decl_stmt|;
comment|/* reason for sleep */
name|u_int
name|p_time
decl_stmt|;
comment|/* resident/nonresident time for swapping */
name|u_int
name|p_slptime
decl_stmt|;
comment|/* time since last block */
name|struct
name|itimerval
name|p_realtimer
decl_stmt|;
comment|/* alarm timer */
name|struct
name|timeval
name|p_rtime
decl_stmt|;
comment|/* real time */
name|u_quad_t
name|p_uticks
decl_stmt|;
comment|/* statclock hits in user mode */
name|u_quad_t
name|p_sticks
decl_stmt|;
comment|/* statclock hits in system mode */
name|u_quad_t
name|p_iticks
decl_stmt|;
comment|/* statclock hits processing intr */
name|int
name|p_traceflag
decl_stmt|;
comment|/* kernel trace points */
name|struct
name|vnode
modifier|*
name|p_tracep
decl_stmt|;
comment|/* trace to vnode */
name|int
name|p_sig
decl_stmt|;
comment|/* signals pending to this process */
name|long
name|p_spare
index|[
literal|6
index|]
decl_stmt|;
comment|/* pad to 256 and to avoid shifting eproc */
comment|/* end area that is zeroed on creation */
define|#
directive|define
name|p_endzero
value|p_startcopy
comment|/* The following fields are all copied upon creation in fork */
name|sigset_t
name|p_sigmask
decl_stmt|;
comment|/* current signal mask */
define|#
directive|define
name|p_startcopy
value|p_sigmask
name|sigset_t
name|p_sigignore
decl_stmt|;
comment|/* signals being ignored */
name|sigset_t
name|p_sigcatch
decl_stmt|;
comment|/* signals being caught by user */
name|u_char
name|p_pri
decl_stmt|;
comment|/* priority, negative is high */
name|u_char
name|p_usrpri
decl_stmt|;
comment|/* user-priority based on p_cpu and p_nice */
name|char
name|p_nice
decl_stmt|;
comment|/* nice for cpu usage */
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
comment|/* pointer to process group */
comment|/* end area that is copied on creation */
define|#
directive|define
name|p_endcopy
value|p_thread
name|int
name|p_thread
decl_stmt|;
comment|/* id for this "thread" (Mach glue) XXX */
name|struct
name|user
modifier|*
name|p_addr
decl_stmt|;
comment|/* kernel virtual addr of u-area (PROC ONLY) */
name|struct
name|mdproc
name|p_md
decl_stmt|;
comment|/* any machine-dependent fields */
name|u_short
name|p_xstat
decl_stmt|;
comment|/* Exit status for wait; also stop signal */
name|u_short
name|p_acflag
decl_stmt|;
comment|/* accounting flags */
name|struct
name|rusage
modifier|*
name|p_ru
decl_stmt|;
comment|/* exit information XXX */
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
comment|/* MOVE TO ucred.h? */
end_comment

begin_comment
comment|/*  * Shareable process credentials (always resident).  * This includes a reference to the current user credentials  * as well as real and saved ids that may be used to change ids.  */
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
comment|/* current credentials */
name|uid_t
name|p_ruid
decl_stmt|;
comment|/* real user id */
name|uid_t
name|p_svuid
decl_stmt|;
comment|/* saved effective user id */
name|gid_t
name|p_rgid
decl_stmt|;
comment|/* real group id */
name|gid_t
name|p_svgid
decl_stmt|;
comment|/* saved effective group id */
name|int
name|p_refcnt
decl_stmt|;
comment|/* number of references */
block|}
struct|;
end_struct

begin_comment
comment|/* stat codes */
end_comment

begin_define
define|#
directive|define
name|SSLEEP
value|1
end_define

begin_comment
comment|/* awaiting an event */
end_comment

begin_define
define|#
directive|define
name|SWAIT
value|2
end_define

begin_comment
comment|/* (abandoned state) */
end_comment

begin_define
define|#
directive|define
name|SRUN
value|3
end_define

begin_comment
comment|/* running */
end_comment

begin_define
define|#
directive|define
name|SIDL
value|4
end_define

begin_comment
comment|/* intermediate state in process creation */
end_comment

begin_define
define|#
directive|define
name|SZOMB
value|5
end_define

begin_comment
comment|/* intermediate state in process termination */
end_comment

begin_define
define|#
directive|define
name|SSTOP
value|6
end_define

begin_comment
comment|/* process being traced */
end_comment

begin_comment
comment|/* flag codes */
end_comment

begin_define
define|#
directive|define
name|SLOAD
value|0x0000001
end_define

begin_comment
comment|/* in core */
end_comment

begin_define
define|#
directive|define
name|SSYS
value|0x0000002
end_define

begin_comment
comment|/* system proc: no sigs, stats or swapping */
end_comment

begin_define
define|#
directive|define
name|SSINTR
value|0x0000004
end_define

begin_comment
comment|/* sleep is interruptible */
end_comment

begin_define
define|#
directive|define
name|SCTTY
value|0x0000008
end_define

begin_comment
comment|/* has a controlling terminal */
end_comment

begin_define
define|#
directive|define
name|SPPWAIT
value|0x0000010
end_define

begin_comment
comment|/* parent is waiting for child to exec/exit */
end_comment

begin_define
define|#
directive|define
name|SEXEC
value|0x0000020
end_define

begin_comment
comment|/* process called exec */
end_comment

begin_define
define|#
directive|define
name|STIMO
value|0x0000040
end_define

begin_comment
comment|/* timing out during sleep */
end_comment

begin_define
define|#
directive|define
name|SSEL
value|0x0000080
end_define

begin_comment
comment|/* selecting; wakeup/waiting danger */
end_comment

begin_define
define|#
directive|define
name|SWEXIT
value|0x0000100
end_define

begin_comment
comment|/* working on exiting */
end_comment

begin_define
define|#
directive|define
name|SNOCLDSTOP
value|0x0000200
end_define

begin_comment
comment|/* no SIGCHLD when children stop */
end_comment

begin_comment
comment|/* the following three should probably be changed into a hold count */
end_comment

begin_define
define|#
directive|define
name|SLOCK
value|0x0000400
end_define

begin_comment
comment|/* process being swapped out */
end_comment

begin_define
define|#
directive|define
name|SKEEP
value|0x0000800
end_define

begin_comment
comment|/* another flag to prevent swap out */
end_comment

begin_define
define|#
directive|define
name|SPHYSIO
value|0x0001000
end_define

begin_comment
comment|/* doing physical i/o */
end_comment

begin_define
define|#
directive|define
name|STRC
value|0x0004000
end_define

begin_comment
comment|/* process is being traced */
end_comment

begin_define
define|#
directive|define
name|SWTED
value|0x0008000
end_define

begin_comment
comment|/* another tracing flag */
end_comment

begin_define
define|#
directive|define
name|SUGID
value|0x0020000
end_define

begin_comment
comment|/* had set id privileges since last exec */
end_comment

begin_define
define|#
directive|define
name|SADVLCK
value|0x0040000
end_define

begin_comment
comment|/* process may hold a POSIX advisory lock */
end_comment

begin_define
define|#
directive|define
name|SPROFIL
value|0x0080000
end_define

begin_comment
comment|/* has started profiling */
end_comment

begin_comment
comment|/* the following should be moved to machine-dependent areas */
end_comment

begin_define
define|#
directive|define
name|SOWEUPC
value|0x0002000
end_define

begin_comment
comment|/* owe process an addupc() call at next ast */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * We use process IDs<= PID_MAX;  * PID_MAX + 1 must also fit in a pid_t  * (used to represent "no process group").  */
end_comment

begin_define
define|#
directive|define
name|PID_MAX
value|30000
end_define

begin_define
define|#
directive|define
name|NO_PID
value|30001
end_define

begin_define
define|#
directive|define
name|PIDHASH
parameter_list|(
name|pid
parameter_list|)
value|((pid)& pidhashmask)
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
value|{ \ 		if (--(s)->s_count == 0) \ 			FREE(s, M_SESSION); \ 	}
end_define

begin_decl_stmt
specifier|extern
name|int
name|pidhashmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in param.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|pidhash
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in param.c */
end_comment

begin_function_decl
name|struct
name|proc
modifier|*
name|pfind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find process by id */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pgrp
modifier|*
name|pgrphash
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in param.c */
end_comment

begin_function_decl
name|struct
name|pgrp
modifier|*
name|pgfind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find process group by id */
end_comment

begin_decl_stmt
specifier|volatile
name|struct
name|proc
modifier|*
name|allproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of active procs */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|zombproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of zombie procs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|proc
name|proc0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process slot for swapper */
end_comment

begin_decl_stmt
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
comment|/* process slots for init, pager */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|curproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current running proc */
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
comment|/* current and max number of procs */
end_comment

begin_define
define|#
directive|define
name|NQS
value|32
end_define

begin_comment
comment|/* 32 run queues */
end_comment

begin_struct
struct|struct
name|prochd
block|{
name|struct
name|proc
modifier|*
name|ph_link
decl_stmt|;
comment|/* linked list of running processes */
name|struct
name|proc
modifier|*
name|ph_rlink
decl_stmt|;
block|}
name|qs
index|[
name|NQS
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|whichqs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bit mask summarizing non-empty qs's */
end_comment

begin_decl_stmt
name|void
name|sleep
name|__P
argument_list|(
operator|(
name|void
operator|*
name|chan
operator|,
name|int
name|pri
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tsleep
name|__P
argument_list|(
operator|(
name|void
operator|*
name|chan
operator|,
name|int
name|pri
operator|,
name|char
operator|*
name|wmesg
operator|,
name|int
name|timo
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
name|wakeup
name|__P
argument_list|(
operator|(
name|void
operator|*
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setrun
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
name|setpri
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
name|swtch
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
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PROC_H_ */
end_comment

end_unit

