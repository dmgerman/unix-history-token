begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: cpu.h,v 1.18 1997/09/23 23:17:49 mjacob Exp */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cpu.h 1.16 91/03/25$  *  *	@(#)cpu.h	8.4 (Berkeley) 1/5/94  */
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

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|framep
parameter_list|)
define|\
value|(((framep)->tf_regs[FRAME_PS]& ALPHA_PSL_USERMODE) != 0)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->tf_regs[FRAME_PC])
end_define

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|btext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|(alpha_pal_rdusp())
end_define

begin_define
define|#
directive|define
name|cpu_spinwait
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|get_cyclecount
parameter_list|()
value|read_cycle_count()
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
name|uint64_t
name|read_cycle_count
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _ALPHA_CPU_H_ */
end_comment

end_unit

