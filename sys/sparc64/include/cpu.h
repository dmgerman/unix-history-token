begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|cfp
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|cfp
parameter_list|)
value|((cfp)->cf_tf.tf_tpc)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|tfp
parameter_list|)
value|((tfp)->tf_tpc)
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|tfp
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|p
parameter_list|)
value|((p)->p_frame->tf_sp)
end_define

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|p
parameter_list|,
name|sp
parameter_list|)
value|((p)->p_frame->tf_sp = (sp))
end_define

begin_comment
comment|/*  * Arrange to handle pending profiling ticks before returning to user mode.  */
end_comment

begin_define
define|#
directive|define
name|need_proftick
parameter_list|(
name|p
parameter_list|)
value|do {						\ 	mtx_lock_spin(&sched_lock);					\ 	(p)->p_sflag |= PS_OWEUPC;					\ 	aston(p);							\ 	mtx_unlock_spin(&sched_lock);					\ } while (0)
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

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|u_int64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|rd
argument_list|(
name|tick
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPU_H_ */
end_comment

end_unit

