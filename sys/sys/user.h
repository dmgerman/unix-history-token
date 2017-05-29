begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  * Copyright (c) 2007 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)user.h	8.2 (Berkeley) 9/23/93  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKET_VAR_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/caprights.h>
end_include

begin_comment
comment|/*  * KERN_PROC subtype ops return arrays of selected proc structure entries:  *  * This struct includes several arrays of spare space, with different arrays  * for different standard C-types.  When adding new variables to this struct,  * the space for byte-aligned data should be taken from the ki_sparestring,  * pointers from ki_spareptrs, word-aligned data from ki_spareints, and  * doubleword-aligned data from ki_sparelongs.  Make sure the space for new  * variables come from the array which matches the size and alignment of  * those variables on ALL hardware platforms, and then adjust the appropriate  * KI_NSPARE_* value(s) to match.  *  * Always verify that sizeof(struct kinfo_proc) == KINFO_PROC_SIZE on all  * platforms after you have added new variables.  Note that if you change  * the value of KINFO_PROC_SIZE, then many userland programs will stop  * working until they are recompiled!  *  * Once you have added the new field, you will need to add code to initialize  * it in two places: function fill_kinfo_proc in sys/kern/kern_proc.c and  * function kvm_proclist in lib/libkvm/kvm_proc.c .  */
end_comment

begin_define
define|#
directive|define
name|KI_NSPARE_INT
value|2
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
value|6
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

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
name|TDNAMLEN
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

begin_define
define|#
directive|define
name|LOGINCLASSLEN
value|17
end_define

begin_comment
comment|/* size of returned ki_loginclass */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BURN_BRIDGES
end_ifndef

begin_define
define|#
directive|define
name|OCOMMLEN
value|TDNAMLEN
end_define

begin_define
define|#
directive|define
name|ki_ocomm
value|ki_tdname
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Flags for the process credential. */
end_comment

begin_define
define|#
directive|define
name|KI_CRF_CAPABILITY_MODE
value|0x00000001
end_define

begin_comment
comment|/*  * Steal a bit from ki_cr_flags to indicate that the cred had more than  * KI_NGROUPS groups.  */
end_comment

begin_define
define|#
directive|define
name|KI_CRF_GRP_OVERFLOW
value|0x80000000
end_define

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
name|uint32_t
name|ki_tdev_freebsd11
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
name|u_int
name|ki_cow
decl_stmt|;
comment|/* number of copy-on-write faults */
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
name|ki_oncpu_old
decl_stmt|;
comment|/* Which cpu we are on (legacy) */
name|u_char
name|ki_lastcpu_old
decl_stmt|;
comment|/* Last cpu we were on (legacy) */
name|char
name|ki_tdname
index|[
name|TDNAMLEN
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
name|char
name|ki_loginclass
index|[
name|LOGINCLASSLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* login class */
name|char
name|ki_moretdname
index|[
name|MAXCOMLEN
operator|-
name|TDNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* more thread name */
comment|/* 	 * When adding new variables, take space for char-strings from the 	 * front of ki_sparestrings, and ints from the end of ki_spareints. 	 * That way the spare room from both arrays will remain contiguous. 	 */
name|char
name|ki_sparestrings
index|[
literal|46
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
name|uint64_t
name|ki_tdev
decl_stmt|;
comment|/* controlling tty dev */
name|int
name|ki_oncpu
decl_stmt|;
comment|/* Which cpu we are on */
name|int
name|ki_lastcpu
decl_stmt|;
comment|/* Last cpu we were on */
name|int
name|ki_tracer
decl_stmt|;
comment|/* Pid of tracing process */
name|int
name|ki_flag2
decl_stmt|;
comment|/* P2_* flags */
name|int
name|ki_fibnum
decl_stmt|;
comment|/* Default FIB number */
name|u_int
name|ki_cr_flags
decl_stmt|;
comment|/* Credential flags */
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
name|struct
name|thread
modifier|*
name|ki_tdaddr
decl_stmt|;
comment|/* address of thread */
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
comment|/*  *  Legacy PS_ flag.  This moved to p_flag but is maintained for  *  compatibility.  */
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

begin_comment
comment|/*  * The KERN_PROC_FILE sysctl allows a process to dump the file descriptor  * array of another process.  */
end_comment

begin_define
define|#
directive|define
name|KF_ATTR_VALID
value|0x0001
end_define

begin_define
define|#
directive|define
name|KF_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|KF_TYPE_VNODE
value|1
end_define

begin_define
define|#
directive|define
name|KF_TYPE_SOCKET
value|2
end_define

begin_define
define|#
directive|define
name|KF_TYPE_PIPE
value|3
end_define

begin_define
define|#
directive|define
name|KF_TYPE_FIFO
value|4
end_define

begin_define
define|#
directive|define
name|KF_TYPE_KQUEUE
value|5
end_define

begin_define
define|#
directive|define
name|KF_TYPE_CRYPTO
value|6
end_define

begin_define
define|#
directive|define
name|KF_TYPE_MQUEUE
value|7
end_define

begin_define
define|#
directive|define
name|KF_TYPE_SHM
value|8
end_define

begin_define
define|#
directive|define
name|KF_TYPE_SEM
value|9
end_define

begin_define
define|#
directive|define
name|KF_TYPE_PTS
value|10
end_define

begin_define
define|#
directive|define
name|KF_TYPE_PROCDESC
value|11
end_define

begin_define
define|#
directive|define
name|KF_TYPE_UNKNOWN
value|255
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VNON
value|0
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VREG
value|1
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VDIR
value|2
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VBLK
value|3
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VCHR
value|4
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VLNK
value|5
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VSOCK
value|6
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VFIFO
value|7
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_VBAD
value|8
end_define

begin_define
define|#
directive|define
name|KF_VTYPE_UNKNOWN
value|255
end_define

begin_define
define|#
directive|define
name|KF_FD_TYPE_CWD
value|-1
end_define

begin_comment
comment|/* Current working directory */
end_comment

begin_define
define|#
directive|define
name|KF_FD_TYPE_ROOT
value|-2
end_define

begin_comment
comment|/* Root directory */
end_comment

begin_define
define|#
directive|define
name|KF_FD_TYPE_JAIL
value|-3
end_define

begin_comment
comment|/* Jail directory */
end_comment

begin_define
define|#
directive|define
name|KF_FD_TYPE_TRACE
value|-4
end_define

begin_comment
comment|/* Ktrace vnode */
end_comment

begin_define
define|#
directive|define
name|KF_FD_TYPE_TEXT
value|-5
end_define

begin_comment
comment|/* Text vnode */
end_comment

begin_define
define|#
directive|define
name|KF_FD_TYPE_CTTY
value|-6
end_define

begin_comment
comment|/* Controlling terminal */
end_comment

begin_define
define|#
directive|define
name|KF_FLAG_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KF_FLAG_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KF_FLAG_APPEND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KF_FLAG_ASYNC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KF_FLAG_FSYNC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KF_FLAG_NONBLOCK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KF_FLAG_DIRECT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|KF_FLAG_HASLOCK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KF_FLAG_SHLOCK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KF_FLAG_EXLOCK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|KF_FLAG_NOFOLLOW
value|0x00000400
end_define

begin_define
define|#
directive|define
name|KF_FLAG_CREAT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|KF_FLAG_TRUNC
value|0x00001000
end_define

begin_define
define|#
directive|define
name|KF_FLAG_EXCL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|KF_FLAG_EXEC
value|0x00004000
end_define

begin_comment
comment|/*  * Old format.  Has variable hidden padding due to alignment.  * This is a compatibility hack for pre-build 7.1 packages.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KINFO_OFILE_SIZE
value|1328
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KINFO_OFILE_SIZE
value|1324
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|kinfo_ofile
block|{
name|int
name|kf_structsize
decl_stmt|;
comment|/* Size of kinfo_file. */
name|int
name|kf_type
decl_stmt|;
comment|/* Descriptor type. */
name|int
name|kf_fd
decl_stmt|;
comment|/* Array index. */
name|int
name|kf_ref_count
decl_stmt|;
comment|/* Reference count. */
name|int
name|kf_flags
decl_stmt|;
comment|/* Flags. */
comment|/* XXX Hidden alignment padding here on amd64 */
name|off_t
name|kf_offset
decl_stmt|;
comment|/* Seek location. */
name|int
name|kf_vnode_type
decl_stmt|;
comment|/* Vnode type. */
name|int
name|kf_sock_domain
decl_stmt|;
comment|/* Socket domain. */
name|int
name|kf_sock_type
decl_stmt|;
comment|/* Socket type. */
name|int
name|kf_sock_protocol
decl_stmt|;
comment|/* Socket protocol. */
name|char
name|kf_path
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Path to file, if any. */
name|struct
name|sockaddr_storage
name|kf_sa_local
decl_stmt|;
comment|/* Socket address. */
name|struct
name|sockaddr_storage
name|kf_sa_peer
decl_stmt|;
comment|/* Peer address. */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_comment
comment|/*  * This size should never be changed. If you really need to, you must provide  * backward ABI compatibility by allocating a new sysctl MIB that will return  * the new structure. The current structure has to be returned by the current  * sysctl MIB. See how it is done for the kinfo_ofile structure.  */
end_comment

begin_define
define|#
directive|define
name|KINFO_FILE_SIZE
value|1392
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|kinfo_file
block|{
name|int
name|kf_structsize
decl_stmt|;
comment|/* Variable size of record. */
name|int
name|kf_type
decl_stmt|;
comment|/* Descriptor type. */
name|int
name|kf_fd
decl_stmt|;
comment|/* Array index. */
name|int
name|kf_ref_count
decl_stmt|;
comment|/* Reference count. */
name|int
name|kf_flags
decl_stmt|;
comment|/* Flags. */
name|int
name|kf_pad0
decl_stmt|;
comment|/* Round to 64 bit alignment. */
name|int64_t
name|kf_offset
decl_stmt|;
comment|/* Seek location. */
union|union
block|{
struct|struct
block|{
comment|/* Sendq size */
name|uint32_t
name|kf_sock_sendq
decl_stmt|;
comment|/* Socket domain. */
name|int
name|kf_sock_domain0
decl_stmt|;
comment|/* Socket type. */
name|int
name|kf_sock_type0
decl_stmt|;
comment|/* Socket protocol. */
name|int
name|kf_sock_protocol0
decl_stmt|;
comment|/* Socket address. */
name|struct
name|sockaddr_storage
name|kf_sa_local
decl_stmt|;
comment|/* Peer address. */
name|struct
name|sockaddr_storage
name|kf_sa_peer
decl_stmt|;
comment|/* Address of so_pcb. */
name|uint64_t
name|kf_sock_pcb
decl_stmt|;
comment|/* Address of inp_ppcb. */
name|uint64_t
name|kf_sock_inpcb
decl_stmt|;
comment|/* Address of unp_conn. */
name|uint64_t
name|kf_sock_unpconn
decl_stmt|;
comment|/* Send buffer state. */
name|uint16_t
name|kf_sock_snd_sb_state
decl_stmt|;
comment|/* Receive buffer state. */
name|uint16_t
name|kf_sock_rcv_sb_state
decl_stmt|;
comment|/* Recvq size. */
name|uint32_t
name|kf_sock_recvq
decl_stmt|;
block|}
name|kf_sock
struct|;
struct|struct
block|{
comment|/* Vnode type. */
name|int
name|kf_file_type
decl_stmt|;
comment|/* Space for future use */
name|int
name|kf_spareint
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|kf_spareint64
index|[
literal|30
index|]
decl_stmt|;
comment|/* Vnode filesystem id. */
name|uint64_t
name|kf_file_fsid
decl_stmt|;
comment|/* File device. */
name|uint64_t
name|kf_file_rdev
decl_stmt|;
comment|/* Global file id. */
name|uint64_t
name|kf_file_fileid
decl_stmt|;
comment|/* File size. */
name|uint64_t
name|kf_file_size
decl_stmt|;
comment|/* Vnode filesystem id, FreeBSD 11 compat. */
name|uint32_t
name|kf_file_fsid_freebsd11
decl_stmt|;
comment|/* File device, FreeBSD 11 compat. */
name|uint32_t
name|kf_file_rdev_freebsd11
decl_stmt|;
comment|/* File mode. */
name|uint16_t
name|kf_file_mode
decl_stmt|;
comment|/* Round to 64 bit alignment. */
name|uint16_t
name|kf_file_pad0
decl_stmt|;
name|uint32_t
name|kf_file_pad1
decl_stmt|;
block|}
name|kf_file
struct|;
struct|struct
block|{
name|uint32_t
name|kf_spareint
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|kf_spareint64
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|kf_sem_value
decl_stmt|;
name|uint16_t
name|kf_sem_mode
decl_stmt|;
block|}
name|kf_sem
struct|;
struct|struct
block|{
name|uint32_t
name|kf_spareint
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|kf_spareint64
index|[
literal|32
index|]
decl_stmt|;
name|uint64_t
name|kf_pipe_addr
decl_stmt|;
name|uint64_t
name|kf_pipe_peer
decl_stmt|;
name|uint32_t
name|kf_pipe_buffer_cnt
decl_stmt|;
comment|/* Round to 64 bit alignment. */
name|uint32_t
name|kf_pipe_pad0
index|[
literal|3
index|]
decl_stmt|;
block|}
name|kf_pipe
struct|;
struct|struct
block|{
name|uint32_t
name|kf_spareint
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|kf_spareint64
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|kf_pts_dev_freebsd11
decl_stmt|;
name|uint32_t
name|kf_pts_pad0
decl_stmt|;
name|uint64_t
name|kf_pts_dev
decl_stmt|;
comment|/* Round to 64 bit alignment. */
name|uint32_t
name|kf_pts_pad1
index|[
literal|4
index|]
decl_stmt|;
block|}
name|kf_pts
struct|;
struct|struct
block|{
name|uint32_t
name|kf_spareint
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|kf_spareint64
index|[
literal|32
index|]
decl_stmt|;
name|pid_t
name|kf_pid
decl_stmt|;
block|}
name|kf_proc
struct|;
block|}
name|kf_un
union|;
name|uint16_t
name|kf_status
decl_stmt|;
comment|/* Status flags. */
name|uint16_t
name|kf_pad1
decl_stmt|;
comment|/* Round to 32 bit alignment. */
name|int
name|_kf_ispare0
decl_stmt|;
comment|/* Space for more stuff. */
name|cap_rights_t
name|kf_cap_rights
decl_stmt|;
comment|/* Capability rights. */
name|uint64_t
name|_kf_cap_spare
decl_stmt|;
comment|/* Space for future cap_rights_t. */
comment|/* Truncated before copyout in sysctl */
name|char
name|kf_path
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Path to file, if any. */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|kf_vnode_type
value|kf_un.kf_file.kf_file_type
end_define

begin_define
define|#
directive|define
name|kf_sock_domain
value|kf_un.kf_sock.kf_sock_domain0
end_define

begin_define
define|#
directive|define
name|kf_sock_type
value|kf_un.kf_sock.kf_sock_type0
end_define

begin_define
define|#
directive|define
name|kf_sock_protocol
value|kf_un.kf_sock.kf_sock_protocol0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The KERN_PROC_VMMAP sysctl allows a process to dump the VM layout of  * another process as a series of entries.  */
end_comment

begin_define
define|#
directive|define
name|KVME_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_VNODE
value|2
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_SWAP
value|3
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_DEVICE
value|4
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_PHYS
value|5
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_DEAD
value|6
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_SG
value|7
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_MGTDEVICE
value|8
end_define

begin_define
define|#
directive|define
name|KVME_TYPE_UNKNOWN
value|255
end_define

begin_define
define|#
directive|define
name|KVME_PROT_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KVME_PROT_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KVME_PROT_EXEC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KVME_FLAG_COW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KVME_FLAG_NEEDS_COPY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KVME_FLAG_NOCOREDUMP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KVME_FLAG_SUPER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KVME_FLAG_GROWS_UP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KVME_FLAG_GROWS_DOWN
value|0x00000020
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KINFO_OVMENTRY_SIZE
value|1168
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KINFO_OVMENTRY_SIZE
value|1128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|kinfo_ovmentry
block|{
name|int
name|kve_structsize
decl_stmt|;
comment|/* Size of kinfo_vmmapentry. */
name|int
name|kve_type
decl_stmt|;
comment|/* Type of map entry. */
name|void
modifier|*
name|kve_start
decl_stmt|;
comment|/* Starting address. */
name|void
modifier|*
name|kve_end
decl_stmt|;
comment|/* Finishing address. */
name|int
name|kve_flags
decl_stmt|;
comment|/* Flags on map entry. */
name|int
name|kve_resident
decl_stmt|;
comment|/* Number of resident pages. */
name|int
name|kve_private_resident
decl_stmt|;
comment|/* Number of private pages. */
name|int
name|kve_protection
decl_stmt|;
comment|/* Protection bitmask. */
name|int
name|kve_ref_count
decl_stmt|;
comment|/* VM obj ref count. */
name|int
name|kve_shadow_count
decl_stmt|;
comment|/* VM obj shadow count. */
name|char
name|kve_path
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Path to VM obj, if any. */
name|void
modifier|*
name|_kve_pspare
index|[
literal|8
index|]
decl_stmt|;
comment|/* Space for more stuff. */
name|off_t
name|kve_offset
decl_stmt|;
comment|/* Mapping offset in object */
name|uint64_t
name|kve_fileid
decl_stmt|;
comment|/* inode number if vnode */
name|uint32_t
name|kve_fsid
decl_stmt|;
comment|/* dev_t of vnode location */
name|int
name|_kve_ispare
index|[
literal|3
index|]
decl_stmt|;
comment|/* Space for more stuff. */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KINFO_VMENTRY_SIZE
value|1160
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|kinfo_vmentry
block|{
name|int
name|kve_structsize
decl_stmt|;
comment|/* Variable size of record. */
name|int
name|kve_type
decl_stmt|;
comment|/* Type of map entry. */
name|uint64_t
name|kve_start
decl_stmt|;
comment|/* Starting address. */
name|uint64_t
name|kve_end
decl_stmt|;
comment|/* Finishing address. */
name|uint64_t
name|kve_offset
decl_stmt|;
comment|/* Mapping offset in object */
name|uint64_t
name|kve_vn_fileid
decl_stmt|;
comment|/* inode number if vnode */
name|uint32_t
name|kve_vn_fsid_freebsd11
decl_stmt|;
comment|/* dev_t of vnode location */
name|int
name|kve_flags
decl_stmt|;
comment|/* Flags on map entry. */
name|int
name|kve_resident
decl_stmt|;
comment|/* Number of resident pages. */
name|int
name|kve_private_resident
decl_stmt|;
comment|/* Number of private pages. */
name|int
name|kve_protection
decl_stmt|;
comment|/* Protection bitmask. */
name|int
name|kve_ref_count
decl_stmt|;
comment|/* VM obj ref count. */
name|int
name|kve_shadow_count
decl_stmt|;
comment|/* VM obj shadow count. */
name|int
name|kve_vn_type
decl_stmt|;
comment|/* Vnode type. */
name|uint64_t
name|kve_vn_size
decl_stmt|;
comment|/* File size. */
name|uint32_t
name|kve_vn_rdev_freebsd11
decl_stmt|;
comment|/* Device id if device. */
name|uint16_t
name|kve_vn_mode
decl_stmt|;
comment|/* File mode. */
name|uint16_t
name|kve_status
decl_stmt|;
comment|/* Status flags. */
name|uint64_t
name|kve_vn_fsid
decl_stmt|;
comment|/* dev_t of vnode location */
name|uint64_t
name|kve_vn_rdev
decl_stmt|;
comment|/* Device id if device. */
name|int
name|_kve_ispare
index|[
literal|8
index|]
decl_stmt|;
comment|/* Space for more stuff. */
comment|/* Truncated before copyout in sysctl */
name|char
name|kve_path
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Path to VM obj, if any. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The "vm.objects" sysctl provides a list of all VM objects in the system  * via an array of these entries.  */
end_comment

begin_struct
struct|struct
name|kinfo_vmobject
block|{
name|int
name|kvo_structsize
decl_stmt|;
comment|/* Variable size of record. */
name|int
name|kvo_type
decl_stmt|;
comment|/* Object type: KVME_TYPE_*. */
name|uint64_t
name|kvo_size
decl_stmt|;
comment|/* Object size in pages. */
name|uint64_t
name|kvo_vn_fileid
decl_stmt|;
comment|/* inode number if vnode. */
name|uint32_t
name|kvo_vn_fsid_freebsd11
decl_stmt|;
comment|/* dev_t of vnode location. */
name|int
name|kvo_ref_count
decl_stmt|;
comment|/* Reference count. */
name|int
name|kvo_shadow_count
decl_stmt|;
comment|/* Shadow count. */
name|int
name|kvo_memattr
decl_stmt|;
comment|/* Memory attribute. */
name|uint64_t
name|kvo_resident
decl_stmt|;
comment|/* Number of resident pages. */
name|uint64_t
name|kvo_active
decl_stmt|;
comment|/* Number of active pages. */
name|uint64_t
name|kvo_inactive
decl_stmt|;
comment|/* Number of inactive pages. */
name|uint64_t
name|kvo_vn_fsid
decl_stmt|;
name|uint64_t
name|_kvo_qspare
index|[
literal|7
index|]
decl_stmt|;
name|uint32_t
name|_kvo_ispare
index|[
literal|8
index|]
decl_stmt|;
name|char
name|kvo_path
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Pathname, if any. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The KERN_PROC_KSTACK sysctl allows a process to dump the kernel stacks of  * another process as a series of entries.  Each stack is represented by a  * series of symbol names and offsets as generated by stack_sbuf_print(9).  */
end_comment

begin_define
define|#
directive|define
name|KKST_MAXLEN
value|1024
end_define

begin_define
define|#
directive|define
name|KKST_STATE_STACKOK
value|0
end_define

begin_comment
comment|/* Stack is valid. */
end_comment

begin_define
define|#
directive|define
name|KKST_STATE_SWAPPED
value|1
end_define

begin_comment
comment|/* Stack swapped out. */
end_comment

begin_define
define|#
directive|define
name|KKST_STATE_RUNNING
value|2
end_define

begin_comment
comment|/* Stack ephemeral. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KINFO_KSTACK_SIZE
value|1096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|kinfo_kstack
block|{
name|lwpid_t
name|kkst_tid
decl_stmt|;
comment|/* ID of thread. */
name|int
name|kkst_state
decl_stmt|;
comment|/* Validity of stack. */
name|char
name|kkst_trace
index|[
name|KKST_MAXLEN
index|]
decl_stmt|;
comment|/* String representing stack. */
name|int
name|_kkst_ispare
index|[
literal|16
index|]
decl_stmt|;
comment|/* Space for more stuff. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kinfo_sigtramp
block|{
name|void
modifier|*
name|ksigtramp_start
decl_stmt|;
name|void
modifier|*
name|ksigtramp_end
decl_stmt|;
name|void
modifier|*
name|ksigtramp_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Flags for kern_proc_out function. */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_NOTHREADS
value|0x1
end_define

begin_define
define|#
directive|define
name|KERN_PROC_MASK32
value|0x2
end_define

begin_comment
comment|/* Flags for kern_proc_filedesc_out. */
end_comment

begin_define
define|#
directive|define
name|KERN_FILEDESC_PACK_KINFO
value|0x00000001U
end_define

begin_comment
comment|/* Flags for kern_proc_vmmap_out. */
end_comment

begin_define
define|#
directive|define
name|KERN_VMMAP_PACK_KINFO
value|0x00000001U
end_define

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The kern_proc out functions are helper functions to dump process  * miscellaneous kinfo structures to sbuf.  The main consumers are KERN_PROC  * sysctls but they may also be used by other kernel subsystems.  *  * The functions manipulate the process locking state and expect the process  * to be locked on enter.  On return the process is unlocked.  */
end_comment

begin_function_decl
name|int
name|kern_proc_filedesc_out
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
name|ssize_t
name|maxlen
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_proc_cwd_out
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
name|ssize_t
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_proc_out
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_proc_vmmap_out
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
name|ssize_t
name|maxlen
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vntype_to_kinfo
parameter_list|(
name|int
name|vtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

