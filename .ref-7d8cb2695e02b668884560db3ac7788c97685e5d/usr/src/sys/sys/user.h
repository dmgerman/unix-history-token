begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)user.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_comment
comment|/* stuff that *used* to be included by user.h, or is now needed */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
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
file|<sys/sysctl.h>
end_include

begin_comment
comment|/*  * Per process structure containing data that isn't needed in core  * when the process isn't running (esp. when swapped out).  * This structure may or may not be at the same kernel address  * in all processes.  */
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
name|sigacts
name|u_sigacts
decl_stmt|;
comment|/* p_sigacts points here (use it!) */
name|struct
name|pstats
name|u_stats
decl_stmt|;
comment|/* p_stats points here (use it!) */
comment|/* 	 * Remaining fields only for core dump and/or ptrace-- 	 * not valid at other times! 	 */
name|struct
name|kinfo_proc
name|u_kproc
decl_stmt|;
comment|/* proc + eproc */
name|struct
name|md_coredump
name|u_md
decl_stmt|;
comment|/* machine dependent glop */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Redefinitions to make the debuggers happy for now...  * This subterfuge brought to you by coredump() and procxmt().  * These fields are *only* valid at those times!  */
end_comment

begin_define
define|#
directive|define
name|U_ar0
value|u_kproc.kp_proc.p_md.md_regs
end_define

begin_comment
comment|/* copy of curproc->p_md.md_regs */
end_comment

begin_define
define|#
directive|define
name|U_tsize
value|u_kproc.kp_eproc.e_vm.vm_tsize
end_define

begin_define
define|#
directive|define
name|U_dsize
value|u_kproc.kp_eproc.e_vm.vm_dsize
end_define

begin_define
define|#
directive|define
name|U_ssize
value|u_kproc.kp_eproc.e_vm.vm_ssize
end_define

begin_define
define|#
directive|define
name|U_sig
value|u_sigacts.ps_sig
end_define

begin_define
define|#
directive|define
name|U_code
value|u_sigacts.ps_code
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|u_ar0
value|U_ar0
end_define

begin_define
define|#
directive|define
name|u_tsize
value|U_tsize
end_define

begin_define
define|#
directive|define
name|u_dsize
value|U_dsize
end_define

begin_define
define|#
directive|define
name|u_ssize
value|U_ssize
end_define

begin_define
define|#
directive|define
name|u_sig
value|U_sig
end_define

begin_define
define|#
directive|define
name|u_code
value|U_code
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

