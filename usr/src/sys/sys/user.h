begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)user.h	7.16 (Berkeley) %G%  */
end_comment

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
name|u_pad1
index|[
literal|4
index|]
decl_stmt|;
name|label_t
name|u_ssave
decl_stmt|;
comment|/* label variable for swapping */
name|caddr_t
name|u_taddr
decl_stmt|;
comment|/* user virtual address of text */
name|caddr_t
name|u_daddr
decl_stmt|;
comment|/* user virtual address of data */
name|time_t
name|u_outime
decl_stmt|;
comment|/* user time at last sample */
name|caddr_t
name|u_maxsaddr
decl_stmt|;
comment|/* user VA at max stack growth */
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
name|int
name|u_sig
decl_stmt|;
comment|/* for core dump/debugger XXX */
name|int
name|u_code
decl_stmt|;
comment|/* for core dump/debugger XXX */
comment|/* 1.4 - descriptor management */
name|long
name|u_pad2
index|[
literal|82
index|]
decl_stmt|;
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
modifier|*
name|swaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|forkutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|xswaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|xswap2utl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|pushutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|vfutl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

