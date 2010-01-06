begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/efi.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_decl_stmt
name|uint64_t
name|ia64_clock_reload
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_decl_stmt
specifier|static
name|timecounter_get_t
name|ia64_get_timecount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|timecounter
name|ia64_timecounter
init|=
block|{
name|ia64_get_timecount
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
literal|"ITC"
comment|/* name */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|ia64_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
block|{
return|return
name|ia64_get_itc
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|pcpu_initclock
parameter_list|(
name|void
parameter_list|)
block|{
name|PCPU_SET
argument_list|(
name|md
operator|.
name|clockadj
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|PCPU_SET
argument_list|(
name|md
operator|.
name|clock
argument_list|,
name|ia64_get_itc
argument_list|()
argument_list|)
expr_stmt|;
name|ia64_set_itm
argument_list|(
name|PCPU_GET
argument_list|(
name|md
operator|.
name|clock
argument_list|)
operator|+
name|ia64_clock_reload
argument_list|)
expr_stmt|;
name|ia64_set_itv
argument_list|(
name|CLOCK_VECTOR
argument_list|)
expr_stmt|;
comment|/* highest priority class */
name|ia64_srlz_d
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Start the real-time and statistics clocks. We use cr.itc and cr.itm  * to implement a 1000hz clock.  */
end_comment

begin_function
name|void
name|cpu_initclocks
parameter_list|()
block|{
name|u_long
name|itc_freq
decl_stmt|;
name|itc_freq
operator|=
operator|(
name|u_long
operator|)
name|ia64_itc_freq
argument_list|()
operator|*
literal|1000000ul
expr_stmt|;
name|stathz
operator|=
name|hz
expr_stmt|;
name|ia64_clock_reload
operator|=
operator|(
name|itc_freq
operator|+
name|hz
operator|/
literal|2
operator|)
operator|/
name|hz
expr_stmt|;
ifndef|#
directive|ifndef
name|SMP
name|ia64_timecounter
operator|.
name|tc_frequency
operator|=
name|itc_freq
expr_stmt|;
name|tc_init
argument_list|(
operator|&
name|ia64_timecounter
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pcpu_initclock
argument_list|()
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

end_unit

