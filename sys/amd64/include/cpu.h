begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cpu.h	5.4 (Berkeley) 5/9/91  * $FreeBSD$  */
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
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->tf_esp)
end_define

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|td
parameter_list|,
name|ap
parameter_list|)
value|((td)->td_frame->tf_esp = (ap))
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|framep
parameter_list|)
define|\
value|((ISPL((framep)->tf_cs) == SEL_UPL) || ((framep)->tf_eflags& PSL_VM))
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->tf_eip)
end_define

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
define|\
value|((ISPL((framep)->cf_cs) == SEL_UPL) || ((framep)->cf_eflags& PSL_VM))
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
name|_KERNEL
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
name|u_int
name|tsc_present
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return contents of in-cpu fast counter as a sort of "bogo-time"  * for non-critical timing.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|I386_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I486_CPU
argument_list|)
name|struct
name|timespec
name|tv
decl_stmt|;
if|if
condition|(
operator|!
name|tsc_present
condition|)
block|{
name|nanotime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
return|return
operator|(
name|tv
operator|.
name|tv_sec
operator|*
operator|(
name|u_int64_t
operator|)
literal|1000000000
operator|+
name|tv
operator|.
name|tv_nsec
operator|)
return|;
block|}
endif|#
directive|endif
return|return
operator|(
name|rdtsc
argument_list|()
operator|)
return|;
block|}
end_function

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

