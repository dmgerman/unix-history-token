begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)user.h	8.2 (Berkeley) 9/23/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_USER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_USER_H_
end_define

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* stuff that *used* to be included by user.h, or is now needed */
end_comment

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
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RESOURCEVAR_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SIGNALVAR_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * KERN_PROC subtype ops return arrays of selected proc structure entries:  *  * This struct includes several arrays of spare space, with different arrays  * for different standard C-types.  When adding new variables to this struct,  * the space for byte-aligned data should be taken from the ki_sparestring,  * pointers from ki_spareptrs, word-aligned data from ki_spareints, and  * doubleword-aligned data from ki_sparelongs.  Make sure the space for new  * variables come from the array which matches the size and alignment of  * those variables on ALL hardware platforms, and then adjust the appropriate  * KI_NSPARE_* value(s) to match.  *  * Always verify that sizeof(struct kinfo_proc) == KINFO_PROC_SIZE on all  * platforms after you have added new variables.  Note that if you change  * the value of KINFO_PROC_SIZE, then many userland programs will stop  * working until they are recompiled!  *  * Once you have added the new field, you will need to add code to initialize  * it in two places: function fill_kinfo_proc in sys/kern/kern_proc.c and  * function kvm_proclist in lib/libkvm/kvm_proc.c .  */
end_comment

begin_define
define|#
directive|define
name|KI_NSPARE_INT
value|10
end_define

begin_define
define|#
directive|define
name|KI_NSPARE_LONG
value|12
end_define

begin_define
define|#
directive|define
name|KI_NSPARE_PTR
value|7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|1088
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__arm__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|768
end_define

begin_comment
comment|/* value has not been tested... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|1088
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|1088
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KINFO_PROC_SIZE
end_ifndef

begin_error
error|#
directive|error
literal|"Unknown architecture"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WMESGLEN
value|8
end_define

begin_comment
comment|/* size of returned wchan message */
end_comment

begin_define
define|#
directive|define
name|LOCKNAMELEN
value|8
end_define

begin_comment
comment|/* size of returned lock name */
end_comment

begin_define
define|#
directive|define
name|OCOMMLEN
value|16
end_define

begin_comment
comment|/* size of returned thread name */
end_comment

begin_define
define|#
directive|define
name|COMMLEN
value|19
end_define

begin_comment
comment|/* size of returned ki_comm name */
end_comment

begin_define
define|#
directive|define
name|KI_EMULNAMELEN
value|16
end_define

begin_comment
comment|/* size of returned ki_emul */
end_comment

begin_define
define|#
directive|define
name|KI_NGROUPS
value|16
end_define

begin_comment
comment|/* number of groups in ki_groups */
end_comment

begin_define
define|#
directive|define
name|LOGNAMELEN
value|17
end_define

begin_comment
comment|/* size of returned ki_login */
end_comment

begin_struct
struct|struct
name|kinfo_proc
block|{
name|int
name|ki_structsize
decl_stmt|;
comment|/* size of this structure */
name|int
name|ki_layout
decl_stmt|;
comment|/* reserved: layout identifier */
name|struct
name|pargs
modifier|*
name|ki_args
decl_stmt|;
comment|/* address of command arguments */
name|struct
name|proc
modifier|*
name|ki_paddr
decl_stmt|;
comment|/* address of proc */
name|struct
name|user
modifier|*
name|ki_addr
decl_stmt|;
comment|/* kernel virtual addr of u-area */
name|struct
name|vnode
modifier|*
name|ki_tracep
decl_stmt|;
comment|/* pointer to trace file */
name|struct
name|vnode
modifier|*
name|ki_textvp
decl_stmt|;
comment|/* pointer to executable file */
name|struct
name|filedesc
modifier|*
name|ki_fd
decl_stmt|;
comment|/* pointer to open file info */
name|struct
name|vmspace
modifier|*
name|ki_vmspace
decl_stmt|;
comment|/* pointer to kernel vmspace struct */
name|void
modifier|*
name|ki_wchan
decl_stmt|;
comment|/* sleep address */
name|pid_t
name|ki_pid
decl_stmt|;
comment|/* Process identifier */
name|pid_t
name|ki_ppid
decl_stmt|;
comment|/* parent process id */
name|pid_t
name|ki_pgid
decl_stmt|;
comment|/* process group id */
name|pid_t
name|ki_tpgid
decl_stmt|;
comment|/* tty process group id */
name|pid_t
name|ki_sid
decl_stmt|;
comment|/* Process session ID */
name|pid_t
name|ki_tsid
decl_stmt|;
comment|/* Terminal session ID */
name|short
name|ki_jobc
decl_stmt|;
comment|/* job control counter */
name|short
name|ki_spare_short1
decl_stmt|;
comment|/* unused (just here for alignment) */
name|dev_t
name|ki_tdev
decl_stmt|;
comment|/* controlling tty dev */
name|sigset_t
name|ki_siglist
decl_stmt|;
comment|/* Signals arrived but not delivered */
name|sigset_t
name|ki_sigmask
decl_stmt|;
comment|/* Current signal mask */
name|sigset_t
name|ki_sigignore
decl_stmt|;
comment|/* Signals being ignored */
name|sigset_t
name|ki_sigcatch
decl_stmt|;
comment|/* Signals being caught by user */
name|uid_t
name|ki_uid
decl_stmt|;
comment|/* effective user id */
name|uid_t
name|ki_ruid
decl_stmt|;
comment|/* Real user id */
name|uid_t
name|ki_svuid
decl_stmt|;
comment|/* Saved effective user id */
name|gid_t
name|ki_rgid
decl_stmt|;
comment|/* Real group id */
name|gid_t
name|ki_svgid
decl_stmt|;
comment|/* Saved effective group id */
name|short
name|ki_ngroups
decl_stmt|;
comment|/* number of groups */
name|short
name|ki_spare_short2
decl_stmt|;
comment|/* unused (just here for alignment) */
name|gid_t
name|ki_groups
index|[
name|KI_NGROUPS
index|]
decl_stmt|;
comment|/* groups */
name|vm_size_t
name|ki_size
decl_stmt|;
comment|/* virtual size */
name|segsz_t
name|ki_rssize
decl_stmt|;
comment|/* current resident set size in pages */
name|segsz_t
name|ki_swrss
decl_stmt|;
comment|/* resident set size before last swap */
name|segsz_t
name|ki_tsize
decl_stmt|;
comment|/* text size (pages) XXX */
name|segsz_t
name|ki_dsize
decl_stmt|;
comment|/* data size (pages) XXX */
name|segsz_t
name|ki_ssize
decl_stmt|;
comment|/* stack size (pages) */
name|u_short
name|ki_xstat
decl_stmt|;
comment|/* Exit status for wait& stop signal */
name|u_short
name|ki_acflag
decl_stmt|;
comment|/* Accounting flags */
name|fixpt_t
name|ki_pctcpu
decl_stmt|;
comment|/* %cpu for process during ki_swtime */
name|u_int
name|ki_estcpu
decl_stmt|;
comment|/* Time averaged value of ki_cpticks */
name|u_int
name|ki_slptime
decl_stmt|;
comment|/* Time since last blocked */
name|u_int
name|ki_swtime
decl_stmt|;
comment|/* Time swapped in or out */
name|int
name|ki_spareint1
decl_stmt|;
comment|/* unused (just here for alignment) */
name|u_int64_t
name|ki_runtime
decl_stmt|;
comment|/* Real time in microsec */
name|struct
name|timeval
name|ki_start
decl_stmt|;
comment|/* starting time */
name|struct
name|timeval
name|ki_childtime
decl_stmt|;
comment|/* time used by process children */
name|long
name|ki_flag
decl_stmt|;
comment|/* P_* flags */
name|long
name|ki_kiflag
decl_stmt|;
comment|/* KI_* flags (below) */
name|int
name|ki_traceflag
decl_stmt|;
comment|/* Kernel trace points */
name|char
name|ki_stat
decl_stmt|;
comment|/* S* process status */
name|signed
name|char
name|ki_nice
decl_stmt|;
comment|/* Process "nice" value */
name|char
name|ki_lock
decl_stmt|;
comment|/* Process lock (prevent swap) count */
name|char
name|ki_rqindex
decl_stmt|;
comment|/* Run queue index */
name|u_char
name|ki_oncpu
decl_stmt|;
comment|/* Which cpu we are on */
name|u_char
name|ki_lastcpu
decl_stmt|;
comment|/* Last cpu we were on */
name|char
name|ki_ocomm
index|[
name|OCOMMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* thread name */
name|char
name|ki_wmesg
index|[
name|WMESGLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* wchan message */
name|char
name|ki_login
index|[
name|LOGNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* setlogin name */
name|char
name|ki_lockname
index|[
name|LOCKNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* lock name */
name|char
name|ki_comm
index|[
name|COMMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* command name */
name|char
name|ki_emul
index|[
name|KI_EMULNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* emulation name */
comment|/* 	 * When adding new variables, take space for char-strings from the 	 * front of ki_sparestrings, and ints from the end of ki_spareints. 	 * That way the spare room from both arrays will remain contiguous. 	 */
name|char
name|ki_sparestrings
index|[
literal|68
index|]
decl_stmt|;
comment|/* spare string space */
name|int
name|ki_spareints
index|[
name|KI_NSPARE_INT
index|]
decl_stmt|;
comment|/* spare room for growth */
name|int
name|ki_jid
decl_stmt|;
comment|/* Process jail ID */
name|int
name|ki_numthreads
decl_stmt|;
comment|/* XXXKSE number of threads in total */
name|lwpid_t
name|ki_tid
decl_stmt|;
comment|/* XXXKSE thread id */
name|struct
name|priority
name|ki_pri
decl_stmt|;
comment|/* process priority */
name|struct
name|rusage
name|ki_rusage
decl_stmt|;
comment|/* process rusage statistics */
comment|/* XXX - most fields in ki_rusage_ch are not (yet) filled in */
name|struct
name|rusage
name|ki_rusage_ch
decl_stmt|;
comment|/* rusage of children processes */
name|struct
name|pcb
modifier|*
name|ki_pcb
decl_stmt|;
comment|/* kernel virtual addr of pcb */
name|void
modifier|*
name|ki_kstack
decl_stmt|;
comment|/* kernel virtual addr of stack */
name|void
modifier|*
name|ki_udata
decl_stmt|;
comment|/* User convenience pointer */
comment|/* 	 * When adding new variables, take space for pointers from the 	 * front of ki_spareptrs, and longs from the end of ki_sparelongs. 	 * That way the spare room from both arrays will remain contiguous. 	 */
name|void
modifier|*
name|ki_spareptrs
index|[
name|KI_NSPARE_PTR
index|]
decl_stmt|;
comment|/* spare room for growth */
name|long
name|ki_sparelongs
index|[
name|KI_NSPARE_LONG
index|]
decl_stmt|;
comment|/* spare room for growth */
name|long
name|ki_sflag
decl_stmt|;
comment|/* PS_* flags */
name|long
name|ki_tdflags
decl_stmt|;
comment|/* XXXKSE kthread flag */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|fill_kinfo_proc
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|kinfo_proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX - the following two defines are temporary */
end_comment

begin_define
define|#
directive|define
name|ki_childstime
value|ki_rusage_ch.ru_stime
end_define

begin_define
define|#
directive|define
name|ki_childutime
value|ki_rusage_ch.ru_utime
end_define

begin_comment
comment|/* ki_sessflag values */
end_comment

begin_define
define|#
directive|define
name|KI_CTTY
value|0x00000001
end_define

begin_comment
comment|/* controlling tty vnode active */
end_comment

begin_define
define|#
directive|define
name|KI_SLEADER
value|0x00000002
end_define

begin_comment
comment|/* session leader */
end_comment

begin_define
define|#
directive|define
name|KI_LOCKBLOCK
value|0x00000004
end_define

begin_comment
comment|/* proc blocked on lock ki_lockname */
end_comment

begin_comment
comment|/*  * This used to be the per-process structure containing data that  * isn't needed in core when the process is swapped out, but now it  * remains only for the benefit of a.out core dumps.  */
end_comment

begin_struct
struct|struct
name|user
block|{
name|struct
name|pstats
name|u_stats
decl_stmt|;
comment|/* *p_stats */
name|struct
name|kinfo_proc
name|u_kproc
decl_stmt|;
comment|/* eproc */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

