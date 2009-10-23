begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: clock.c,v 1.9 2000/01/19 02:52:19 msaitoh Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2001 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
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
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_comment
comment|/*  * Initially we assume a processor with a bus frequency of 12.5 MHz.  */
end_comment

begin_decl_stmt
name|u_long
name|ns_per_tick
init|=
literal|80
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_long
name|ticks_per_sec
init|=
literal|12500000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|ticks_per_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|timecounter_get_t
name|decr_get_timecount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|timecounter
name|decr_timecounter
init|=
block|{
name|decr_get_timecount
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
literal|"decrementer"
comment|/* name */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|decr_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
block|{
name|int32_t
name|tick
decl_stmt|,
name|nticks
decl_stmt|;
comment|/* 	 * Check whether we are initialized. 	 */
if|if
condition|(
operator|!
name|ticks_per_intr
condition|)
return|return;
comment|/* 	 * Based on the actual time delay since the last decrementer reload, 	 * we arrange for earlier interrupt next time. 	 */
asm|__asm ("mfdec %0" : "=r"(tick));
for|for
control|(
name|nticks
operator|=
literal|0
init|;
name|tick
operator|<
literal|0
condition|;
name|nticks
operator|++
control|)
name|tick
operator|+=
name|ticks_per_intr
expr_stmt|;
name|mtdec
argument_list|(
name|tick
argument_list|)
expr_stmt|;
if|if
condition|(
name|nticks
operator|>
literal|5
condition|)
name|printf
argument_list|(
literal|"BIG NTICKS on CPU %d: %x\n"
argument_list|,
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
argument_list|,
name|nticks
argument_list|)
expr_stmt|;
while|while
condition|(
name|nticks
operator|--
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
operator|==
literal|0
condition|)
name|hardclock
argument_list|(
name|TRAPF_USERMODE
argument_list|(
name|frame
argument_list|)
argument_list|,
name|TRAPF_PC
argument_list|(
name|frame
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|hardclock_cpu
argument_list|(
name|TRAPF_USERMODE
argument_list|(
name|frame
argument_list|)
argument_list|)
expr_stmt|;
name|statclock
argument_list|(
name|TRAPF_USERMODE
argument_list|(
name|frame
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|profprocs
operator|!=
literal|0
condition|)
name|profclock
argument_list|(
name|TRAPF_USERMODE
argument_list|(
name|frame
argument_list|)
argument_list|,
name|TRAPF_PC
argument_list|(
name|frame
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|decr_init
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|cpuref
name|cpu
decl_stmt|;
name|register_t
name|msr
decl_stmt|;
comment|/* 	 * Check the BSP's timebase frequency. Sometimes we can't find the BSP, so fall 	 * back to the first CPU in this case. 	 */
if|if
condition|(
name|platform_smp_get_bsp
argument_list|(
operator|&
name|cpu
argument_list|)
operator|!=
literal|0
condition|)
name|platform_smp_first_cpu
argument_list|(
operator|&
name|cpu
argument_list|)
expr_stmt|;
name|ticks_per_sec
operator|=
name|platform_timebase_freq
argument_list|(
operator|&
name|cpu
argument_list|)
expr_stmt|;
name|msr
operator|=
name|mfmsr
argument_list|()
expr_stmt|;
name|mtmsr
argument_list|(
name|msr
operator|&
operator|~
name|PSL_EE
argument_list|)
expr_stmt|;
name|ns_per_tick
operator|=
literal|1000000000
operator|/
name|ticks_per_sec
expr_stmt|;
name|ticks_per_intr
operator|=
name|ticks_per_sec
operator|/
name|hz
expr_stmt|;
name|mtdec
argument_list|(
name|ticks_per_intr
argument_list|)
expr_stmt|;
name|set_cputicker
argument_list|(
name|mftb
argument_list|,
name|ticks_per_sec
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mtmsr
argument_list|(
name|msr
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function
name|void
name|decr_ap_init
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|decr_tc_init
parameter_list|(
name|void
parameter_list|)
block|{
name|decr_timecounter
operator|.
name|tc_frequency
operator|=
name|ticks_per_sec
expr_stmt|;
name|tc_init
argument_list|(
operator|&
name|decr_timecounter
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|decr_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
block|{
name|register_t
name|tb
decl_stmt|;
asm|__asm __volatile("mftb %0" : "=r"(tb));
return|return
operator|(
name|tb
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Wait for about n microseconds (at least!).  */
end_comment

begin_function
name|void
name|DELAY
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|u_quad_t
name|tb
decl_stmt|,
name|ttb
decl_stmt|;
name|tb
operator|=
name|mftb
argument_list|()
expr_stmt|;
name|ttb
operator|=
name|tb
operator|+
operator|(
name|n
operator|*
literal|1000
operator|+
name|ns_per_tick
operator|-
literal|1
operator|)
operator|/
name|ns_per_tick
expr_stmt|;
while|while
condition|(
name|tb
operator|<
name|ttb
condition|)
name|tb
operator|=
name|mftb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Nothing to do.  */
end_comment

begin_function
name|void
name|cpu_startprofclock
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Do nothing */
block|}
end_function

begin_function
name|void
name|cpu_stopprofclock
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

