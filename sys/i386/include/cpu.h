begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cpu.h	5.4 (Berkeley) 5/9/91  *	$Id: cpu.h,v 1.34 1997/10/27 17:23:02 bde Exp $  */
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
file|<machine/psl.h>
end_include

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
comment|/*  * Architecture dependent constant for i386 based machines.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* NEC PC-9801/9821 series and compatibles. */
end_comment

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"pc-98"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBM-PC compatibles. */
end_comment

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"ibm-pc"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|((p)->p_md.md_regs[SP] = (ap))
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
value|((p)->p_md.md_regs = (fp))
end_define

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
define|\
value|((ISPL((framep)->cf_cs) == SEL_UPL) || (framep->cf_eflags& PSL_VM))
end_define

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|(intr_nesting_level>= 2)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * XXX splsoftclock() is very broken and barely worth fixing.  It doesn't  * turn off the clock bit in imen or in the icu.  (This is not a serious  * problem at 100 Hz but it is serious at 16000 Hz for pcaudio.  softclock()  * can take more than 62.5 usec so clock interrupts are lost.)  It doesn't  * check for pending interrupts being unmasked.  clkintr() and Xintr0()  * assume that the ipl is high when hardclock() returns.  Our SWI_AST  * handling is efficient enough that little is gained by calling  * softclock() directly.  */
end_comment

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->cf_ppl& ~SWI_AST_MASK) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Arrange to handle pending profiling ticks before returning to user mode.  *  * XXX this is now poorly named and implemented.  It used to handle only a  * single tick and the P_OWEUPC flag served as a counter.  Now there is a  * counter in the proc table and flag isn't really necessary.  */
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
name|CPU_BOOTINFO
value|4
end_define

begin_comment
comment|/* struct: bootinfo */
end_comment

begin_define
define|#
directive|define
name|CPU_WALLCLOCK
value|5
end_define

begin_comment
comment|/* int:	indicates wall CMOS clock */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|6
end_define

begin_comment
comment|/* number of valid machdep ids */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ 	{ "adjkerntz", CTLTYPE_INT }, \ 	{ "disable_rtc_set", CTLTYPE_INT }, \ 	{ "bootinfo", CTLTYPE_STRUCT }, \ 	{ "wall_cmos_clock", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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

begin_decl_stmt
specifier|extern
name|u_char
name|intr_nesting_level
decl_stmt|;
end_decl_stmt

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
name|void
name|fork_trampoline
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
name|fork_return
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|trapframe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_set_fork_handler
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|void
argument_list|(
operator|*
name|pc
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
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

