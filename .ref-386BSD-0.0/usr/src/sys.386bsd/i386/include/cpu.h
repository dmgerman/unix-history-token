begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cpu.h	5.4 (Berkeley) 5/9/91  */
end_comment

begin_comment
comment|/*  * Definitions unique to i386 cpu support.  */
end_comment

begin_include
include|#
directive|include
file|"machine/frame.h"
end_include

begin_include
include|#
directive|include
file|"machine/segments.h"
end_include

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_undef
undef|#
directive|undef
name|COPY_SIGCODE
end_undef

begin_comment
comment|/* don't copy sigcode above user stack in exec */
end_comment

begin_comment
comment|/*  * function vs. inline configuration;  * these are defined to get generic functions  * rather than inline or machine-dependent implementations  */
end_comment

begin_define
define|#
directive|define
name|NEED_MINMAX
end_define

begin_comment
comment|/* need {,i,l,ul}{min,max} functions */
end_comment

begin_define
define|#
directive|define
name|NEED_FFS
end_define

begin_comment
comment|/* need ffs function */
end_comment

begin_define
define|#
directive|define
name|NEED_BCMP
end_define

begin_comment
comment|/* need bcmp function */
end_comment

begin_define
define|#
directive|define
name|NEED_STRLEN
end_define

begin_comment
comment|/* need strlen function */
end_comment

begin_define
define|#
directive|define
name|cpu_exec
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_comment
comment|/*  * Arguments to hardclock, softclock and gatherstats  * encapsulate the previous machine state in an opaque  * clockframe; for now, use generic intrframe.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|intrframe
name|clockframe
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|(ISPL((framep)->if_cs) == SEL_UPL)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|((framep)->if_ppl == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->if_eip)
end_define

begin_define
define|#
directive|define
name|resettodr
parameter_list|()
end_define

begin_comment
comment|/* no todr to set */
end_comment

begin_comment
comment|/*  * Preempt the current process if in interrupt from user mode,  * or after the current trap/syscall if in system mode.  */
end_comment

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|{ want_resched++; aston(); }
end_define

begin_comment
comment|/*  * Give a profiling tick to the current process from the softclock  * interrupt.  On tahoe, request an ast to send us through trap(),  * marking the proc as needing a profiling tick.  */
end_comment

begin_define
define|#
directive|define
name|profile_tick
parameter_list|(
name|p
parameter_list|,
name|framep
parameter_list|)
value|{ (p)->p_flag |= SOWEUPC; aston(); }
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
value|(astpending++)
end_define

begin_decl_stmt
name|int
name|astpending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to trap before returning to user mode */
end_comment

begin_decl_stmt
name|int
name|want_resched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resched() was called */
end_comment

begin_comment
comment|/*  * Kinds of processor  */
end_comment

begin_define
define|#
directive|define
name|CPU_386SX
value|0
end_define

begin_define
define|#
directive|define
name|CPU_386
value|1
end_define

begin_define
define|#
directive|define
name|CPU_486SX
value|2
end_define

begin_define
define|#
directive|define
name|CPU_486
value|3
end_define

begin_define
define|#
directive|define
name|CPU_586
value|4
end_define

end_unit

