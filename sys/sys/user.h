begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)user.h	8.2 (Berkeley) 9/23/93  * $FreeBSD$  */
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
file|<sys/lock.h>
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
comment|/*  * KERN_PROC subtype ops return arrays of augmented proc structures:  */
end_comment

begin_struct
struct|struct
name|kinfo_proc
block|{
name|struct
name|proc
name|kp_proc
decl_stmt|;
comment|/* proc structure */
struct|struct
name|eproc
block|{
name|struct
name|proc
modifier|*
name|e_paddr
decl_stmt|;
comment|/* address of proc */
name|struct
name|session
modifier|*
name|e_sess
decl_stmt|;
comment|/* session pointer */
name|struct
name|pcred
name|e_pcred
decl_stmt|;
comment|/* process credentials */
name|struct
name|ucred
name|e_ucred
decl_stmt|;
comment|/* current credentials */
name|struct
name|procsig
name|e_procsig
decl_stmt|;
comment|/* shared signal structure */
name|struct
name|vmspace
name|e_vm
decl_stmt|;
comment|/* address space */
name|struct
name|pstats
name|e_stats
decl_stmt|;
comment|/* process stats */
name|pid_t
name|e_ppid
decl_stmt|;
comment|/* parent process id */
name|pid_t
name|e_pgid
decl_stmt|;
comment|/* process group id */
name|short
name|e_jobc
decl_stmt|;
comment|/* job control counter */
name|udev_t
name|e_tdev
decl_stmt|;
comment|/* controlling tty dev */
name|pid_t
name|e_tpgid
decl_stmt|;
comment|/* tty process group id */
name|struct
name|session
modifier|*
name|e_tsess
decl_stmt|;
comment|/* tty session pointer */
define|#
directive|define
name|WMESGLEN
value|7
name|char
name|e_wmesg
index|[
name|WMESGLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* wchan message */
name|segsz_t
name|e_xsize
decl_stmt|;
comment|/* text size */
name|short
name|e_xrssize
decl_stmt|;
comment|/* text rss */
name|short
name|e_xccount
decl_stmt|;
comment|/* text references */
name|short
name|e_xswrss
decl_stmt|;
name|long
name|e_flag
decl_stmt|;
define|#
directive|define
name|EPROC_CTTY
value|0x01
comment|/* controlling tty vnode active */
define|#
directive|define
name|EPROC_SLEADER
value|0x02
comment|/* session leader */
name|char
name|e_login
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
comment|/* setlogin() name */
name|long
name|e_spare
index|[
literal|2
index|]
decl_stmt|;
block|}
name|kp_eproc
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|fill_eproc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|eproc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/*  * Redefinitions to make the debuggers happy for now...  This subterfuge  * brought to you by coredump() and trace_req().  These fields are *only*  * valid at those times!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|U_ar0
value|u_kproc.kp_proc.p_md.md_regs
end_define

begin_comment
comment|/* copy of curproc->p_md.md_regs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|U_ar0
value|u_kproc.kp_proc.p_md.md_tf
end_define

begin_comment
comment|/* copy of curproc->p_md.md_tf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
value|u_kproc.kp_proc.p_sig
end_define

begin_define
define|#
directive|define
name|U_code
value|u_kproc.kp_proc.p_code
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

