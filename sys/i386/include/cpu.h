begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cpu.h	5.4 (Berkeley) 5/9/91  *	$Id: cpu.h,v 1.12 1994/10/08 22:21:32 phk Exp $  */
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

begin_comment
comment|/*  * Definitions unique to i386 cpu support.  */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
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

begin_define
define|#
directive|define
name|cpu_swapin
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|p
parameter_list|,
name|ap
parameter_list|)
value|(p)->p_md.md_regs = ap
end_define

begin_define
define|#
directive|define
name|cpu_set_init_frame
parameter_list|(
name|p
parameter_list|,
name|fp
parameter_list|)
value|(p)->p_md.md_regs = fp
end_define

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|(ISPL((framep)->cf_cs) == SEL_UPL)
end_define

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->cf_ppl& ~SWI_AST_MASK) == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->cf_eip)
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
comment|/*  * Give a profiling tick to the current process from the softclock  * interrupt.  On tahoe, request an ast to send us through trap(),  * marking the proc as needing a profiling tick.  */
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
value|setsoftast()
end_define

begin_define
define|#
directive|define
name|astoff
parameter_list|()
end_define

begin_comment
comment|/*  * pull in #defines for kinds of processors  */
end_comment

begin_include
include|#
directive|include
file|<machine/cputypes.h>
end_include

begin_struct
struct|struct
name|cpu_nameclass
block|{
name|char
modifier|*
name|cpu_name
decl_stmt|;
name|int
name|cpu_class
decl_stmt|;
block|}
struct|;
end_struct

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
name|CPU_ADJKERNTZ
value|2
end_define

begin_comment
comment|/* int:	timezone offset	for resettodr()	*/
end_comment

begin_define
define|#
directive|define
name|CPU_DISRTCSET
value|3
end_define

begin_comment
comment|/* int:	disable	resettodr() call */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|4
end_define

begin_comment
comment|/* number of valid machdep ids */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ 	{ "adjkerntz", CTLTYPE_INT }, \ 	{ "disable_rtc_set", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|want_resched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resched was called */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cpu_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpu_nameclass
name|i386_cpus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpu_fork
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|npxdna
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
name|npxexit
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
name|resettodr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPU_H_ */
end_comment

end_unit

