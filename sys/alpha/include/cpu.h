begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: cpu.h,v 1.1 1998/01/10 10:13:14 jb Exp $ */
end_comment

begin_comment
comment|/* From: NetBSD: cpu.h,v 1.18 1997/09/23 23:17:49 mjacob Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cpu.h 1.16 91/03/25$  *  *	@(#)cpu.h	8.4 (Berkeley) 1/5/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_CPU_H_
end_define

begin_comment
comment|/*  * Exported definitions unique to Alpha cpu support.  */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_define
define|#
directive|define
name|cpu_wait
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_comment
comment|/*  * Arguments to hardclock and gatherstats encapsulate the previous  * machine state in an opaque clockframe.  One the Alpha, we use  * what we push on an interrupt (a trapframe).  */
end_comment

begin_struct
struct|struct
name|clockframe
block|{
name|struct
name|trapframe
name|cf_tf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
define|\
value|(((framep)->cf_tf.tf_regs[FRAME_PS]& ALPHA_PSL_USERMODE) != 0)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
define|\
value|(((framep)->cf_tf.tf_regs[FRAME_PS]& ALPHA_PSL_IPL_MASK) == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->cf_tf.tf_regs[FRAME_PC])
end_define

begin_comment
comment|/*  * XXX No way to accurately tell if we were in interrupt mode before taking  * clock interrupt.  */
end_comment

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|(0)
end_define

begin_comment
comment|/*  * Preempt the current process if in interrupt from user mode,  * or after the current trap/syscall if in system mode.  */
end_comment

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|{ want_resched = 1; aston(); }
end_define

begin_comment
comment|/*  * Give a profiling tick to the current process when the user profiling  * buffer pages are invalid.  On the hp300, request an ast to send us  * through trap, marking the proc as needing a profiling tick.  */
end_comment

begin_define
define|#
directive|define
name|need_proftick
parameter_list|(
name|p
parameter_list|)
value|{ (p)->p_flag |= P_OWEUPC; aston(); }
end_define

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
value|aston()
end_define

begin_define
define|#
directive|define
name|aston
parameter_list|()
value|(astpending = 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
name|u_int64_t
name|astpending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to trap before returning to user mode */
end_comment

begin_decl_stmt
name|u_int64_t
name|want_resched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resched() was called */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CONSDEV
value|1
end_define

begin_comment
comment|/* dev_t: console terminal device */
end_comment

begin_define
define|#
directive|define
name|CPU_ROOT_DEVICE
value|2
end_define

begin_comment
comment|/* string: root device name */
end_comment

begin_define
define|#
directive|define
name|CPU_UNALIGNED_PRINT
value|3
end_define

begin_comment
comment|/* int: print unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|CPU_UNALIGNED_FIX
value|4
end_define

begin_comment
comment|/* int: fix unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|CPU_UNALIGNED_SIGBUS
value|5
end_define

begin_comment
comment|/* int: SIGBUS unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|CPU_BOOTED_KERNEL
value|6
end_define

begin_comment
comment|/* string: booted kernel name */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|7
end_define

begin_comment
comment|/* 6 valid machdep IDs */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ 	{ "root_device", CTLTYPE_STRING }, \ 	{ "unaligned_print", CTLTYPE_INT }, \ 	{ "unaligned_fix", CTLTYPE_INT }, \ 	{ "unaligned_sigbus", CTLTYPE_INT }, \ 	{ "booted_kernel", CTLTYPE_STRING }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rpb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|cold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|fpcurproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rpb
modifier|*
name|hwrpb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|mc_expected
decl_stmt|,
name|mc_received
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|XentArith
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|XentIF
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|XentInt
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|XentMM
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|XentRestart
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|XentSys
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|XentUna
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|alpha_init
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ast
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|badaddr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|badaddr_read
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|child_return
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
name|configure
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int64_t
name|console_restart
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|u_int64_t
operator|,
name|u_int64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|do_sir
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
name|dumpconf
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
name|exception_return
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|frametoreg
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
operator|*
operator|,
expr|struct
name|reg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|fswintrberr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|init_prom_interface
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
name|interrupt
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
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
name|machine_check
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
expr|struct
name|trapframe
operator|*
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int64_t
name|hwrpb_checksum
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
name|hwrpb_restart_setup
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
name|regdump
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|regtoframe
name|__P
argument_list|(
operator|(
expr|struct
name|reg
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
name|savectx
name|__P
argument_list|(
operator|(
expr|struct
name|pcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_iointr
name|__P
argument_list|(
operator|(
name|void
argument_list|(
argument|*
argument_list|)
operator|(
name|void
operator|*
operator|,
name|unsigned
name|long
operator|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|switch_exit
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

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|switch_trampoline
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAGIC */
end_comment

begin_decl_stmt
name|void
name|syscall
name|__P
argument_list|(
operator|(
name|u_int64_t
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
name|trap
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
expr|struct
name|trapframe
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
comment|/* _ALPHA_CPU_H_ */
end_comment

end_unit

