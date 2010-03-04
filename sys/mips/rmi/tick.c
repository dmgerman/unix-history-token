begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2009 RMI Corporation  * Copyright (c) 2006 Bruce M. Simpson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Simple driver for the 32-bit interval counter built in to all  * MIPS32 CPUs.  * XXX: For calibration this either needs an external clock, or  * to be explicitly told what the frequency is.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/power.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/locore.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/hwfunc.h>
end_include

begin_decl_stmt
name|struct
name|timecounter
name|counter_timecounter
init|=
block|{
name|platform_get_timecount
block|,
comment|/* get_timecount */
literal|0
block|,
comment|/* no poll_pps */
operator|~
literal|0u
block|,
comment|/* counter_mask */
literal|0
block|,
comment|/* frequency */
literal|"MIPS32"
block|,
comment|/* name */
literal|800
block|,
comment|/* quality (adjusted in code) */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tick_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|tick_init
parameter_list|(
name|void
parameter_list|)
block|{
name|counter_freq
operator|=
name|platform_get_frequency
argument_list|()
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"MIPS32 clock: %u MHz"
argument_list|,
name|cpu_clock
argument_list|)
expr_stmt|;
name|counter_timecounter
operator|.
name|tc_frequency
operator|=
name|counter_freq
expr_stmt|;
name|tc_init
argument_list|(
operator|&
name|counter_timecounter
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_startprofclock
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* nothing to do */
block|}
end_function

begin_function
name|void
name|cpu_stopprofclock
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* nothing to do */
block|}
end_function

begin_function
specifier|static
name|int
name|sysctl_machdep_counter_freq
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|uint64_t
name|freq
decl_stmt|;
comment|/* 	 * RRS wonders if this will really work. You don't change the req of 	 * the system here, it would require changes to the RMI PIC in order 	 * to get the TC to run at a differrent frequency. 	 */
if|if
condition|(
name|counter_timecounter
operator|.
name|tc_frequency
operator|==
literal|0
condition|)
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
name|freq
operator|=
name|counter_freq
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|freq
argument_list|,
sizeof|sizeof
argument_list|(
name|freq
argument_list|)
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
operator|&&
name|req
operator|->
name|newptr
operator|!=
name|NULL
condition|)
block|{
name|counter_freq
operator|=
name|freq
expr_stmt|;
name|counter_timecounter
operator|.
name|tc_frequency
operator|=
name|counter_freq
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_machdep
argument_list|,
name|OID_AUTO
argument_list|,
name|counter_freq
argument_list|,
name|CTLTYPE_QUAD
operator||
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
argument_list|,
name|sysctl_machdep_counter_freq
argument_list|,
literal|"IU"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

