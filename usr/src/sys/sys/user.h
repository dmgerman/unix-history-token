begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)user.h	7.11 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"machine/pcb.h"
end_include

begin_include
include|#
directive|include
file|"dmap.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"resource.h"
end_include

begin_include
include|#
directive|include
file|"namei.h"
end_include

begin_include
include|#
directive|include
file|"ucred.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmap.h>
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
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Per process structure containing data that  * isn't needed in core when the process is swapped out.  */
end_comment

begin_struct
struct|struct
name|user
block|{
name|struct
name|pcb
name|u_pcb
decl_stmt|;
name|struct
name|proc
modifier|*
name|u_procp
decl_stmt|;
comment|/* pointer to proc structure */
name|int
modifier|*
name|u_ar0
decl_stmt|;
comment|/* address of users saved R0 */
comment|/* syscall parameters, results and catches */
name|int
name|u_arg
index|[
literal|8
index|]
decl_stmt|;
comment|/* arguments to current system call */
name|int
modifier|*
name|u_ap
decl_stmt|;
comment|/* pointer to arglist */
union|union
block|{
comment|/* syscall return values */
struct|struct
block|{
name|int
name|R_val1
decl_stmt|;
name|int
name|R_val2
decl_stmt|;
block|}
name|u_rv
struct|;
define|#
directive|define
name|r_val1
value|u_rv.R_val1
define|#
directive|define
name|r_val2
value|u_rv.R_val2
name|off_t
name|r_off
decl_stmt|;
name|time_t
name|r_time
decl_stmt|;
block|}
name|u_r
union|;
name|int
name|u_error
decl_stmt|;
comment|/* return error code */
comment|/* 1.1 - processes and protection */
define|#
directive|define
name|u_cred
value|u_nd.ni_cred
define|#
directive|define
name|u_uid
value|u_cred->cr_uid
comment|/* effective user id */
define|#
directive|define
name|u_gid
value|u_cred->cr_gid
comment|/* effective group id */
comment|/* 1.2 - memory management */
name|segsz_t
name|u_tsize
decl_stmt|;
comment|/* text size (clicks) */
name|segsz_t
name|u_dsize
decl_stmt|;
comment|/* data size (clicks) */
name|segsz_t
name|u_ssize
decl_stmt|;
comment|/* stack size (clicks) */
name|struct
name|dmap
name|u_dmap
decl_stmt|;
comment|/* disk map for data segment */
name|struct
name|dmap
name|u_smap
decl_stmt|;
comment|/* disk map for stack segment */
name|struct
name|dmap
name|u_cdmap
decl_stmt|;
comment|/* temp data segment disk map */
name|struct
name|dmap
name|u_csmap
decl_stmt|;
comment|/* temp stack segment disk map */
name|label_t
name|u_ssave
decl_stmt|;
comment|/* label variable for swapping */
name|segsz_t
name|u_odsize
decl_stmt|,
name|u_ossize
decl_stmt|;
comment|/* for (clumsy) expansion swaps */
name|time_t
name|u_outime
decl_stmt|;
comment|/* user time at last sample */
name|struct
name|mapmem
modifier|*
name|u_mmap
decl_stmt|;
comment|/* list of mapped memory regions */
comment|/* 1.3 - signal management */
name|sig_t
name|u_signal
index|[
name|NSIG
index|]
decl_stmt|;
comment|/* disposition of signals */
name|int
name|u_sigmask
index|[
name|NSIG
index|]
decl_stmt|;
comment|/* signals to be blocked */
name|int
name|u_sigonstack
decl_stmt|;
comment|/* signals to take on sigstack */
name|int
name|u_sigintr
decl_stmt|;
comment|/* signals that interrupt syscalls */
name|int
name|u_oldmask
decl_stmt|;
comment|/* saved mask from before sigpause */
name|struct
name|sigstack
name|u_sigstack
decl_stmt|;
comment|/* sp& on stack state variable */
define|#
directive|define
name|u_onstack
value|u_sigstack.ss_onstack
define|#
directive|define
name|u_sigsp
value|u_sigstack.ss_sp
define|#
directive|define
name|u_sig
value|u_arg[0]
comment|/* for core dump/debugger XXX */
define|#
directive|define
name|u_code
value|u_arg[1]
comment|/* for core dump/debugger XXX */
comment|/* 1.4 - descriptor management */
name|struct
name|file
modifier|*
name|u_ofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* file structures for open files */
name|char
name|u_pofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* per-process flags of open files */
name|int
name|u_lastfile
decl_stmt|;
comment|/* high-water mark of u_ofile */
define|#
directive|define
name|UF_EXCLOSE
value|0x1
comment|/* auto-close on exec */
define|#
directive|define
name|UF_MAPPED
value|0x2
comment|/* mapped from device */
define|#
directive|define
name|u_cdir
value|u_nd.ni_cdir
comment|/* current directory */
define|#
directive|define
name|u_rdir
value|u_nd.ni_rdir
comment|/* root directory of current process */
name|short
name|u_cmask
decl_stmt|;
comment|/* mask for file creation */
comment|/* 1.5 - timing and statistics */
name|struct
name|rusage
name|u_ru
decl_stmt|;
comment|/* stats for this proc */
name|struct
name|rusage
name|u_cru
decl_stmt|;
comment|/* sum of stats for reaped children */
name|struct
name|itimerval
name|u_timer
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|timeval
name|u_start
decl_stmt|;
name|short
name|u_acflag
decl_stmt|;
struct|struct
name|uprof
block|{
comment|/* profile arguments */
name|short
modifier|*
name|pr_base
decl_stmt|;
comment|/* buffer base */
name|unsigned
name|pr_size
decl_stmt|;
comment|/* buffer size */
name|unsigned
name|pr_off
decl_stmt|;
comment|/* pc offset */
name|unsigned
name|pr_scale
decl_stmt|;
comment|/* pc scaling */
block|}
name|u_prof
struct|;
comment|/* 1.6 - resource controls */
name|struct
name|rlimit
name|u_rlimit
index|[
name|RLIM_NLIMITS
index|]
decl_stmt|;
comment|/* namei& co. */
name|struct
name|nameidata
name|u_nd
decl_stmt|;
name|long
name|u_spare
index|[
literal|8
index|]
decl_stmt|;
name|int
name|u_stack
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* u_eosys values */
end_comment

begin_define
define|#
directive|define
name|JUSTRETURN
value|1
end_define

begin_define
define|#
directive|define
name|RESTARTSYS
value|2
end_define

begin_define
define|#
directive|define
name|NORMALRETURN
value|3
end_define

begin_comment
comment|/* u_error codes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|user
name|u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|swaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|forkutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|xswaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|xswap2utl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|pushutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|vfutl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

