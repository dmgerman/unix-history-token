begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: cpu.h,v 1.18 1997/09/23 23:17:49 mjacob Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cpu.h 1.16 91/03/25$  *  *	@(#)cpu.h	8.4 (Berkeley) 1/5/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPU_H_
end_define

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/*  * Arguments to hardclock and gatherstats encapsulate the previous machine  * state in an opaque clockframe.  */
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
name|CLKF_PC
parameter_list|(
name|cf
parameter_list|)
value|((cf)->cf_tf.tf_special.iip)
end_define

begin_define
define|#
directive|define
name|CLKF_CPL
parameter_list|(
name|cf
parameter_list|)
value|((cf)->cf_tf.tf_special.psr& IA64_PSR_CPL)
end_define

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|cf
parameter_list|)
value|(CLKF_CPL(cf) != IA64_PSR_CPL_KERN)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|tf
parameter_list|)
value|((tf)->tf_special.iip)
end_define

begin_define
define|#
directive|define
name|TRAPF_CPL
parameter_list|(
name|tf
parameter_list|)
value|((tf)->tf_special.psr& IA64_PSR_CPL)
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|tf
parameter_list|)
value|(TRAPF_CPL(tf) != IA64_PSR_CPL_KERN)
end_define

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
comment|/* struct cdev *: console terminal device */
end_comment

begin_define
define|#
directive|define
name|CPU_ADJKERNTZ
value|2
end_define

begin_comment
comment|/* int:	timezone offset	(seconds) */
end_comment

begin_define
define|#
directive|define
name|CPU_DISRTCSET
value|3
end_define

begin_comment
comment|/* int: disable resettodr() call */
end_comment

begin_define
define|#
directive|define
name|CPU_WALLCLOCK
value|4
end_define

begin_comment
comment|/* int:	indicates wall CMOS clock */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|5
end_define

begin_comment
comment|/* valid machdep IDs */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ 	{ "adjkerntz", CTLTYPE_INT }, \ 	{ "disable_rtc_set", CTLTYPE_INT }, \ 	{ "wall_cmos_clock", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Return contents of in-cpu fast counter as a sort of "bogo-time"  * for non-critical timing.  */
end_comment

begin_define
define|#
directive|define
name|get_cyclecount
value|ia64_get_itc
end_define

begin_comment
comment|/* Used by signaling code. */
end_comment

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->tf_special.sp)
end_define

begin_function_decl
name|void
name|cpu_halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _MACHINE_CPU_H_ */
end_comment

end_unit

