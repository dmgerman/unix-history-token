begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)proc.h	7.2 (Berkeley) 10/13/86  */
end_comment

begin_comment
comment|/*  * One structure allocated per active  * process. It contains all data needed  * about the process while the  * process may be swapped out.  * Other per process data (user.h)  * is swapped with the process.  */
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
comment|/* linked list of running processes */
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
comment|/* linked list of allocated proc slots */
name|struct
name|proc
modifier|*
modifier|*
name|p_prev
decl_stmt|;
comment|/* also zombies, and free proc's */
name|struct
name|pte
modifier|*
name|p_addr
decl_stmt|;
comment|/* u-area kernel map address */
name|char
name|p_usrpri
decl_stmt|;
comment|/* user-priority based on p_cpu and p_nice */
name|char
name|p_pri
decl_stmt|;
comment|/* priority, negative is high */
name|char
name|p_cpu
decl_stmt|;
comment|/* cpu usage for scheduling */
name|char
name|p_stat
decl_stmt|;
name|char
name|p_time
decl_stmt|;
comment|/* resident time for scheduling */
name|char
name|p_nice
decl_stmt|;
comment|/* nice for cpu usage */
name|char
name|p_slptime
decl_stmt|;
comment|/* time since last block */
name|char
name|p_cursig
decl_stmt|;
name|int
name|p_sig
decl_stmt|;
comment|/* signals pending to this process */
name|int
name|p_sigmask
decl_stmt|;
comment|/* current signal mask */
name|int
name|p_sigignore
decl_stmt|;
comment|/* signals being ignored */
name|int
name|p_sigcatch
decl_stmt|;
comment|/* signals being caught by user */
name|int
name|p_flag
decl_stmt|;
name|uid_t
name|p_uid
decl_stmt|;
comment|/* user id, used to direct tty signals */
name|short
name|p_pgrp
decl_stmt|;
comment|/* name of process group leader */
name|short
name|p_pid
decl_stmt|;
comment|/* unique process id */
name|short
name|p_ppid
decl_stmt|;
comment|/* process id of parent */
name|u_short
name|p_xstat
decl_stmt|;
comment|/* Exit status for wait */
name|struct
name|rusage
modifier|*
name|p_ru
decl_stmt|;
comment|/* mbuf holding exit information */
name|short
name|p_poip
decl_stmt|;
comment|/* page outs in progress */
name|short
name|p_szpt
decl_stmt|;
comment|/* copy of page table size */
name|size_t
name|p_tsize
decl_stmt|;
comment|/* size of text (clicks) */
name|size_t
name|p_dsize
decl_stmt|;
comment|/* size of data space (clicks) */
name|size_t
name|p_ssize
decl_stmt|;
comment|/* copy of stack size (clicks) */
name|size_t
name|p_rssize
decl_stmt|;
comment|/* current resident set size in clicks */
name|size_t
name|p_maxrss
decl_stmt|;
comment|/* copy of u.u_limit[MAXRSS] */
name|size_t
name|p_swrss
decl_stmt|;
comment|/* resident set size before last swap */
name|swblk_t
name|p_swaddr
decl_stmt|;
comment|/* disk address of u area when swapped */
name|caddr_t
name|p_wchan
decl_stmt|;
comment|/* event process is awaiting */
name|struct
name|text
modifier|*
name|p_textp
decl_stmt|;
comment|/* pointer to text structure */
name|struct
name|pte
modifier|*
name|p_p0br
decl_stmt|;
comment|/* page table base P0BR */
name|struct
name|proc
modifier|*
name|p_xlink
decl_stmt|;
comment|/* linked list of procs sharing same text */
name|short
name|p_cpticks
decl_stmt|;
comment|/* ticks of cpu time */
name|float
name|p_pctcpu
decl_stmt|;
comment|/* %cpu for this process during p_time */
name|short
name|p_ndx
decl_stmt|;
comment|/* proc index for memall (because of vfork) */
name|short
name|p_idhash
decl_stmt|;
comment|/* hashed based on p_pid for kill+exit+... */
name|struct
name|proc
modifier|*
name|p_pptr
decl_stmt|;
comment|/* pointer to process structure of parent */
name|struct
name|proc
modifier|*
name|p_cptr
decl_stmt|;
comment|/* pointer to youngest living child */
name|struct
name|proc
modifier|*
name|p_osptr
decl_stmt|;
comment|/* pointer to older sibling processes */
name|struct
name|proc
modifier|*
name|p_ysptr
decl_stmt|;
comment|/* pointer to younger siblings */
name|struct
name|itimerval
name|p_realtimer
decl_stmt|;
name|struct
name|quota
modifier|*
name|p_quota
decl_stmt|;
comment|/* quotas for this process */
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
name|int
name|p_ckey
decl_stmt|;
comment|/* code cache key */
name|int
name|p_dkey
decl_stmt|;
comment|/* data cache key */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PIDHSZ
value|64
end_define

begin_define
define|#
directive|define
name|PIDHASH
parameter_list|(
name|pid
parameter_list|)
value|((pid)& (PIDHSZ - 1))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|short
name|pidhash
index|[
name|PIDHSZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|proc
modifier|*
name|pfind
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|proc
modifier|*
name|proc
decl_stmt|,
modifier|*
name|procNPROC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the proc table itself */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|freeproc
decl_stmt|,
modifier|*
name|zombproc
decl_stmt|,
modifier|*
name|allproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lists of procs in various states */
end_comment

begin_decl_stmt
name|int
name|nproc
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* swapper or pager process */
end_comment

begin_define
define|#
directive|define
name|SLOCK
value|0x0000004
end_define

begin_comment
comment|/* process being swapped out */
end_comment

begin_define
define|#
directive|define
name|SSWAP
value|0x0000008
end_define

begin_comment
comment|/* save area flag */
end_comment

begin_define
define|#
directive|define
name|STRC
value|0x0000010
end_define

begin_comment
comment|/* process is being traced */
end_comment

begin_define
define|#
directive|define
name|SWTED
value|0x0000020
end_define

begin_comment
comment|/* another tracing flag */
end_comment

begin_define
define|#
directive|define
name|SULOCK
value|0x0000040
end_define

begin_comment
comment|/* user settable lock in core */
end_comment

begin_define
define|#
directive|define
name|SPAGE
value|0x0000080
end_define

begin_comment
comment|/* process in page wait state */
end_comment

begin_define
define|#
directive|define
name|SKEEP
value|0x0000100
end_define

begin_comment
comment|/* another flag to prevent swap out */
end_comment

begin_define
define|#
directive|define
name|SOMASK
value|0x0000200
end_define

begin_comment
comment|/* restore old mask after taking signal */
end_comment

begin_define
define|#
directive|define
name|SWEXIT
value|0x0000400
end_define

begin_comment
comment|/* working on exiting */
end_comment

begin_define
define|#
directive|define
name|SPHYSIO
value|0x0000800
end_define

begin_comment
comment|/* doing physical i/o (bio.c) */
end_comment

begin_define
define|#
directive|define
name|SVFORK
value|0x0001000
end_define

begin_comment
comment|/* process resulted from vfork() */
end_comment

begin_define
define|#
directive|define
name|SVFDONE
value|0x0002000
end_define

begin_comment
comment|/* another vfork flag */
end_comment

begin_define
define|#
directive|define
name|SNOVM
value|0x0004000
end_define

begin_comment
comment|/* no vm, parent in a vfork() */
end_comment

begin_define
define|#
directive|define
name|SPAGI
value|0x0008000
end_define

begin_comment
comment|/* init data space on demand, from inode */
end_comment

begin_define
define|#
directive|define
name|SSEQL
value|0x0010000
end_define

begin_comment
comment|/* user warned of sequential vm behavior */
end_comment

begin_define
define|#
directive|define
name|SUANOM
value|0x0020000
end_define

begin_comment
comment|/* user warned of random vm behavior */
end_comment

begin_define
define|#
directive|define
name|STIMO
value|0x0040000
end_define

begin_comment
comment|/* timing out during sleep */
end_comment

begin_comment
comment|/* was SDETACH */
end_comment

begin_define
define|#
directive|define
name|SOUSIG
value|0x0100000
end_define

begin_comment
comment|/* using old signal mechanism */
end_comment

begin_define
define|#
directive|define
name|SOWEUPC
value|0x0200000
end_define

begin_comment
comment|/* owe process an addupc() call at next ast */
end_comment

begin_define
define|#
directive|define
name|SSEL
value|0x0400000
end_define

begin_comment
comment|/* selecting; wakeup/waiting danger */
end_comment

begin_define
define|#
directive|define
name|SLOGIN
value|0x0800000
end_define

begin_comment
comment|/* a login process (legit child of init) */
end_comment

begin_define
define|#
directive|define
name|SPTECHG
value|0x1000000
end_define

begin_comment
comment|/* pte's for process have changed */
end_comment

end_unit

