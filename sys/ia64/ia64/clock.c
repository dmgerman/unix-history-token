begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: clock.c,v 1.20 1998/01/31 10:32:47 ross Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah Hdr: clock.c 1.18 91/01/21  *  *	@(#)clock.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* RCS ID& Copyright macro defns */
end_comment

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
file|<machine/pal.h>
end_include

begin_include
include|#
directive|include
file|<machine/sal.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/clockvar.h>
end_include

begin_include
include|#
directive|include
file|<isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<ia64/ia64/timerreg.h>
end_include

begin_define
define|#
directive|define
name|SECMIN
value|((unsigned)60)
end_define

begin_comment
comment|/* seconds per minute */
end_comment

begin_define
define|#
directive|define
name|SECHOUR
value|((unsigned)(60*SECMIN))
end_define

begin_comment
comment|/* seconds per hour */
end_comment

begin_define
define|#
directive|define
name|SECDAY
value|((unsigned)(24*SECHOUR))
end_define

begin_comment
comment|/* seconds per day */
end_comment

begin_define
define|#
directive|define
name|SECYR
value|((unsigned)(365*SECDAY))
end_define

begin_comment
comment|/* seconds per common year */
end_comment

begin_comment
comment|/*  * 32-bit time_t's can't reach leap years before 1904 or after 2036, so we  * can use a simple formula for leap years.  */
end_comment

begin_define
define|#
directive|define
name|LEAPYEAR
parameter_list|(
name|y
parameter_list|)
value|(((y) % 4) == 0)
end_define

begin_decl_stmt
name|kobj_t
name|clockdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clockinitted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tickfix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tickfixinterval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|adjkerntz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local offset	from GMT in seconds */
end_comment

begin_decl_stmt
name|int
name|disable_rtc_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disable resettodr() if != 0 */
end_comment

begin_decl_stmt
name|int
name|wall_cmos_clock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wall	CMOS clock assumed if != 0 */
end_comment

begin_decl_stmt
name|u_int64_t
name|itm_reload
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reload ticks for clock */
end_comment

begin_decl_stmt
specifier|static
name|int
name|beeping
init|=
literal|0
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
literal|"IA64 ITC"
comment|/* name */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Values for timerX_state: */
end_comment

begin_define
define|#
directive|define
name|RELEASED
value|0
end_define

begin_define
define|#
directive|define
name|RELEASE_PENDING
value|1
end_define

begin_define
define|#
directive|define
name|ACQUIRED
value|2
end_define

begin_define
define|#
directive|define
name|ACQUIRE_PENDING
value|3
end_define

begin_comment
comment|/* static	u_char	timer0_state; */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|timer2_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Algorithm for missed clock ticks from Linux/alpha.  */
end_comment

begin_comment
comment|/*  * Shift amount by which scaled_ticks_per_cycle is scaled.  Shifting  * by 48 gives us 16 bits for HZ while keeping the accuracy good even  * for large CPU clock rates.  */
end_comment

begin_define
define|#
directive|define
name|FIX_SHIFT
value|48
end_define

begin_decl_stmt
specifier|static
name|u_int64_t
name|scaled_ticks_per_cycle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|max_cycles_per_tick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|last_time
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not used yet */
end_comment

begin_endif
unit|static u_int32_t calibrate_clocks(u_int32_t firmware_freq);
endif|#
directive|endif
end_endif

begin_function
name|void
name|clockattach
parameter_list|(
name|kobj_t
name|dev
parameter_list|)
block|{
comment|/* 	 * Just bookkeeping. 	 */
if|if
condition|(
name|clockdev
condition|)
name|panic
argument_list|(
literal|"clockattach: multiple clocks"
argument_list|)
expr_stmt|;
name|clockdev
operator|=
name|dev
expr_stmt|;
ifdef|#
directive|ifdef
name|EVCNT_COUNTERS
name|evcnt_attach
argument_list|(
name|dev
argument_list|,
literal|"intr"
argument_list|,
operator|&
name|clock_intr_evcnt
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Get the clock started. 	 */
name|CLOCK_INIT
argument_list|(
name|clockdev
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Machine-dependent clock routines.  *  * Startrtclock restarts the real-time clock, which provides  * hardclock interrupts to kern_clock.c.  *  * Inittodr initializes the time of day hardware which provides  * date functions.  Its primary function is to use some file  * system information in case the hardare clock lost state.  *  * Resettodr restores the time of day hardware after a time change.  */
end_comment

begin_comment
comment|/*  * Start the real-time and statistics clocks. Leave stathz 0 since there  * are no other timers available.  */
end_comment

begin_function
name|void
name|cpu_initclocks
parameter_list|()
block|{
name|u_int32_t
name|freq
decl_stmt|;
comment|/* 	 * We use cr.itc and cr.itm to implement a 1024hz clock. 	 */
name|hz
operator|=
literal|1024
expr_stmt|;
name|tick
operator|=
literal|1000000
operator|/
name|hz
expr_stmt|;
comment|/* number of microseconds between interrupts */
name|tickfix
operator|=
literal|1000000
operator|-
operator|(
name|hz
operator|*
name|tick
operator|)
expr_stmt|;
if|if
condition|(
name|tickfix
condition|)
block|{
name|int
name|ftp
decl_stmt|;
name|ftp
operator|=
name|min
argument_list|(
name|ffs
argument_list|(
name|tickfix
argument_list|)
argument_list|,
name|ffs
argument_list|(
name|hz
argument_list|)
argument_list|)
expr_stmt|;
name|tickfix
operator|>>=
operator|(
name|ftp
operator|-
literal|1
operator|)
expr_stmt|;
name|tickfixinterval
operator|=
name|hz
operator|>>
operator|(
name|ftp
operator|-
literal|1
operator|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|itc_frequency
condition|)
name|panic
argument_list|(
literal|"Unknown clock frequency"
argument_list|)
expr_stmt|;
name|freq
operator|=
name|itc_frequency
expr_stmt|;
name|last_time
operator|=
name|ia64_get_itc
argument_list|()
expr_stmt|;
name|scaled_ticks_per_cycle
operator|=
operator|(
operator|(
name|u_int64_t
operator|)
name|hz
operator|<<
name|FIX_SHIFT
operator|)
operator|/
name|freq
expr_stmt|;
name|max_cycles_per_tick
operator|=
literal|2
operator|*
name|freq
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
name|freq
expr_stmt|;
name|tc_init
argument_list|(
operator|&
name|ia64_timecounter
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|itm_reload
operator|=
operator|(
name|itc_frequency
operator|+
name|hz
operator|/
literal|2
operator|)
operator|/
name|hz
expr_stmt|;
name|ia64_set_itm
argument_list|(
name|ia64_get_itc
argument_list|()
operator|+
name|itm_reload
argument_list|)
expr_stmt|;
name|ia64_set_itv
argument_list|(
literal|255
argument_list|)
expr_stmt|;
comment|/* highest priority class */
name|stathz
operator|=
literal|128
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not used yet */
end_comment

begin_comment
unit|static u_int32_t calibrate_clocks(u_int32_t firmware_freq) { 	u_int32_t start_pcc, stop_pcc; 	int sec, start_sec;  	if (bootverbose) 	        printf("Calibrating clock(s) ... ");
comment|/* Read the mc146818A seconds counter. */
end_comment

begin_comment
unit|if (CLOCK_GETSECS(clockdev,&sec)) 		goto fail;
comment|/* Wait for the mC146818A seconds counter to change. */
end_comment

begin_comment
unit|start_sec = sec; 	for (;;) { 		if (CLOCK_GETSECS(clockdev,&sec)) 			goto fail; 		if (sec != start_sec) 			break; 	}
comment|/* Start keeping track of the PCC. */
end_comment

begin_comment
unit|start_pcc = ia64_get_itc();
comment|/* 	 * Wait for the mc146818A seconds counter to change. 	 */
end_comment

begin_comment
unit|start_sec = sec; 	for (;;) { 		if (CLOCK_GETSECS(clockdev,&sec)) 			goto fail; 		if (sec != start_sec) 			break; 	}
comment|/* 	 * Read the PCC again to work out frequency. 	 */
end_comment

begin_endif
unit|stop_pcc = ia64_get_itc();  	if (bootverbose) { 	        printf("PCC clock: %u Hz (firmware %u Hz)\n", 		       stop_pcc - start_pcc, firmware_freq); 	} 	return (stop_pcc - start_pcc);  fail: 	if (bootverbose) 	        printf("failed, using firmware default of %u Hz\n", 		       firmware_freq); 	return (firmware_freq); }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We assume newhz is either stathz or profhz, and that neither will  * change after being set up above.  Could recalculate intervals here  * but that would be a drag.  */
end_comment

begin_function
name|void
name|setstatclockrate
parameter_list|(
name|newhz
parameter_list|)
name|int
name|newhz
decl_stmt|;
block|{
comment|/* nothing we can do */
block|}
end_function

begin_comment
comment|/*  * This code is defunct after 2099.  * Will Unix still be here then??  */
end_comment

begin_decl_stmt
specifier|static
name|short
name|dayyr
index|[
literal|12
index|]
init|=
block|{
literal|0
block|,
literal|31
block|,
literal|59
block|,
literal|90
block|,
literal|120
block|,
literal|151
block|,
literal|181
block|,
literal|212
block|,
literal|243
block|,
literal|273
block|,
literal|304
block|,
literal|334
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialze the time of day register, based on the time base which is, e.g.  * from a filesystem.  Base provides the time to within six months,  * and the time of year clock (if any) provides the rest.  */
end_comment

begin_function
name|void
name|inittodr
parameter_list|(
name|base
parameter_list|)
name|time_t
name|base
decl_stmt|;
block|{
specifier|register
name|int
name|days
decl_stmt|,
name|yr
decl_stmt|;
name|struct
name|clocktime
name|ct
decl_stmt|;
name|time_t
name|deltat
decl_stmt|;
name|int
name|badbase
decl_stmt|;
name|int
name|s
decl_stmt|;
name|struct
name|timespec
name|ts
decl_stmt|;
if|if
condition|(
name|base
operator|<
literal|5
operator|*
name|SECYR
condition|)
block|{
name|printf
argument_list|(
literal|"WARNING: preposterous time in filesystem"
argument_list|)
expr_stmt|;
comment|/* read the system clock anyway */
name|base
operator|=
literal|6
operator|*
name|SECYR
operator|+
literal|186
operator|*
name|SECDAY
operator|+
name|SECDAY
operator|/
literal|2
expr_stmt|;
name|badbase
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|badbase
operator|=
literal|0
expr_stmt|;
name|CLOCK_GET
argument_list|(
name|clockdev
argument_list|,
name|base
argument_list|,
operator|&
name|ct
argument_list|)
expr_stmt|;
name|clockinitted
operator|=
literal|1
expr_stmt|;
comment|/* simple sanity checks */
if|if
condition|(
name|ct
operator|.
name|year
operator|<
literal|70
operator|||
name|ct
operator|.
name|mon
operator|<
literal|1
operator|||
name|ct
operator|.
name|mon
operator|>
literal|12
operator|||
name|ct
operator|.
name|day
operator|<
literal|1
operator|||
name|ct
operator|.
name|day
operator|>
literal|31
operator|||
name|ct
operator|.
name|hour
operator|>
literal|23
operator|||
name|ct
operator|.
name|min
operator|>
literal|59
operator|||
name|ct
operator|.
name|sec
operator|>
literal|59
condition|)
block|{
comment|/* 		 * Believe the time in the filesystem for lack of 		 * anything better, resetting the TODR. 		 */
name|s
operator|=
name|splclock
argument_list|()
expr_stmt|;
name|ts
operator|.
name|tv_sec
operator|=
name|base
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
literal|0
expr_stmt|;
name|tc_setclock
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|badbase
condition|)
block|{
name|printf
argument_list|(
literal|"WARNING: preposterous clock chip time\n"
argument_list|)
expr_stmt|;
name|resettodr
argument_list|()
expr_stmt|;
block|}
goto|goto
name|bad
goto|;
block|}
name|days
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|yr
operator|=
literal|70
init|;
name|yr
operator|<
name|ct
operator|.
name|year
condition|;
name|yr
operator|++
control|)
name|days
operator|+=
name|LEAPYEAR
argument_list|(
name|yr
argument_list|)
condition|?
literal|366
else|:
literal|365
expr_stmt|;
name|days
operator|+=
name|dayyr
index|[
name|ct
operator|.
name|mon
operator|-
literal|1
index|]
operator|+
name|ct
operator|.
name|day
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|LEAPYEAR
argument_list|(
name|yr
argument_list|)
operator|&&
name|ct
operator|.
name|mon
operator|>
literal|2
condition|)
name|days
operator|++
expr_stmt|;
comment|/* now have days since Jan 1, 1970; the rest is easy... */
name|s
operator|=
name|splclock
argument_list|()
expr_stmt|;
name|ts
operator|.
name|tv_sec
operator|=
name|days
operator|*
name|SECDAY
operator|+
name|ct
operator|.
name|hour
operator|*
name|SECHOUR
operator|+
name|ct
operator|.
name|min
operator|*
name|SECMIN
operator|+
name|ct
operator|.
name|sec
expr_stmt|;
if|if
condition|(
name|wall_cmos_clock
condition|)
name|ts
operator|.
name|tv_sec
operator|+=
name|adjkerntz
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
literal|0
expr_stmt|;
name|tc_setclock
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|badbase
condition|)
block|{
comment|/* 		 * See if we gained/lost two or more days; 		 * if so, assume something is amiss. 		 */
name|deltat
operator|=
name|ts
operator|.
name|tv_sec
operator|-
name|base
expr_stmt|;
if|if
condition|(
name|deltat
operator|<
literal|0
condition|)
name|deltat
operator|=
operator|-
name|deltat
expr_stmt|;
if|if
condition|(
name|deltat
operator|<
literal|2
operator|*
name|SECDAY
condition|)
return|return;
name|printf
argument_list|(
literal|"WARNING: clock %s %ld days"
argument_list|,
name|ts
operator|.
name|tv_sec
operator|<
name|base
condition|?
literal|"lost"
else|:
literal|"gained"
argument_list|,
name|deltat
operator|/
name|SECDAY
argument_list|)
expr_stmt|;
block|}
name|bad
label|:
name|printf
argument_list|(
literal|" -- CHECK AND RESET THE DATE!\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Reset the TODR based on the time value; used when the TODR  * has a preposterous value and also when the time is reset  * by the stime system call.  Also called when the TODR goes past  * TODRZERO + 100*(SECYEAR+2*SECDAY) (e.g. on Jan 2 just after midnight)  * to wrap the TODR around.  */
end_comment

begin_function
name|void
name|resettodr
parameter_list|()
block|{
specifier|register
name|int
name|t
decl_stmt|,
name|t2
decl_stmt|,
name|s
decl_stmt|;
name|struct
name|clocktime
name|ct
decl_stmt|;
name|unsigned
name|long
name|tm
decl_stmt|;
if|if
condition|(
name|disable_rtc_set
condition|)
return|return;
name|s
operator|=
name|splclock
argument_list|()
expr_stmt|;
name|tm
operator|=
name|time_second
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|clockinitted
condition|)
return|return;
comment|/* Calculate local time	to put in RTC */
name|tm
operator|-=
operator|(
name|wall_cmos_clock
condition|?
name|adjkerntz
else|:
literal|0
operator|)
expr_stmt|;
comment|/* compute the day of week. */
name|t2
operator|=
name|tm
operator|/
name|SECDAY
expr_stmt|;
name|ct
operator|.
name|dow
operator|=
operator|(
name|t2
operator|+
literal|4
operator|)
operator|%
literal|7
expr_stmt|;
comment|/* 1/1/1970 was thursday */
comment|/* compute the year */
name|ct
operator|.
name|year
operator|=
literal|69
expr_stmt|;
name|t
operator|=
name|t2
expr_stmt|;
comment|/* XXX ? */
while|while
condition|(
name|t2
operator|>=
literal|0
condition|)
block|{
comment|/* whittle off years */
name|t
operator|=
name|t2
expr_stmt|;
name|ct
operator|.
name|year
operator|++
expr_stmt|;
name|t2
operator|-=
name|LEAPYEAR
argument_list|(
name|ct
operator|.
name|year
argument_list|)
condition|?
literal|366
else|:
literal|365
expr_stmt|;
block|}
comment|/* t = month + day; separate */
name|t2
operator|=
name|LEAPYEAR
argument_list|(
name|ct
operator|.
name|year
argument_list|)
expr_stmt|;
for|for
control|(
name|ct
operator|.
name|mon
operator|=
literal|1
init|;
name|ct
operator|.
name|mon
operator|<
literal|12
condition|;
name|ct
operator|.
name|mon
operator|++
control|)
if|if
condition|(
name|t
operator|<
name|dayyr
index|[
name|ct
operator|.
name|mon
index|]
operator|+
operator|(
name|t2
operator|&&
name|ct
operator|.
name|mon
operator|>
literal|1
operator|)
condition|)
break|break;
name|ct
operator|.
name|day
operator|=
name|t
operator|-
name|dayyr
index|[
name|ct
operator|.
name|mon
operator|-
literal|1
index|]
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|t2
operator|&&
name|ct
operator|.
name|mon
operator|>
literal|2
condition|)
name|ct
operator|.
name|day
operator|--
expr_stmt|;
comment|/* the rest is easy */
name|t
operator|=
name|tm
operator|%
name|SECDAY
expr_stmt|;
name|ct
operator|.
name|hour
operator|=
name|t
operator|/
name|SECHOUR
expr_stmt|;
name|t
operator|%=
literal|3600
expr_stmt|;
name|ct
operator|.
name|min
operator|=
name|t
operator|/
name|SECMIN
expr_stmt|;
name|ct
operator|.
name|sec
operator|=
name|t
operator|%
name|SECMIN
expr_stmt|;
name|CLOCK_SET
argument_list|(
name|clockdev
argument_list|,
operator|&
name|ct
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

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
name|int
name|acquire_timer2
parameter_list|(
name|int
name|mode
parameter_list|)
block|{
if|if
condition|(
name|timer2_state
operator|!=
name|RELEASED
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|timer2_state
operator|=
name|ACQUIRED
expr_stmt|;
comment|/* 	 * This access to the timer registers is as atomic as possible 	 * because it is a single instruction.  We could do better if we 	 * knew the rate.  Use of splclock() limits glitches to 10-100us, 	 * and this is probably good enough for timer2, so we aren't as 	 * careful with it as with timer0. 	 */
name|outb
argument_list|(
name|TIMER_MODE
argument_list|,
name|TIMER_SEL2
operator||
operator|(
name|mode
operator|&
literal|0x3f
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|release_timer2
parameter_list|()
block|{
if|if
condition|(
name|timer2_state
operator|!=
name|ACQUIRED
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|timer2_state
operator|=
name|RELEASED
expr_stmt|;
name|outb
argument_list|(
name|TIMER_MODE
argument_list|,
name|TIMER_SEL2
operator||
name|TIMER_SQWAVE
operator||
name|TIMER_16BIT
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|sysbeepstop
parameter_list|(
name|void
modifier|*
name|chan
parameter_list|)
block|{
name|outb
argument_list|(
name|IO_PPI
argument_list|,
name|inb
argument_list|(
name|IO_PPI
argument_list|)
operator|&
literal|0xFC
argument_list|)
expr_stmt|;
comment|/* disable counter2 output to speaker */
name|release_timer2
argument_list|()
expr_stmt|;
name|beeping
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Frequency of all three count-down timers; (TIMER_FREQ/freq) is the  * appropriate count to generate a frequency of freq hz.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMER_FREQ
end_ifndef

begin_define
define|#
directive|define
name|TIMER_FREQ
value|1193182
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMER_DIV
parameter_list|(
name|x
parameter_list|)
value|((TIMER_FREQ+(x)/2)/(x))
end_define

begin_function
name|int
name|sysbeep
parameter_list|(
name|int
name|pitch
parameter_list|,
name|int
name|period
parameter_list|)
block|{
name|int
name|x
init|=
name|splhigh
argument_list|()
decl_stmt|;
if|if
condition|(
name|acquire_timer2
argument_list|(
name|TIMER_SQWAVE
operator||
name|TIMER_16BIT
argument_list|)
condition|)
if|if
condition|(
operator|!
name|beeping
condition|)
block|{
comment|/* Something else owns it. */
name|splx
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* XXX Should be EBUSY, but nobody cares anyway. */
block|}
if|if
condition|(
name|pitch
condition|)
name|pitch
operator|=
name|TIMER_DIV
argument_list|(
name|pitch
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TIMER_CNTR2
argument_list|,
name|pitch
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TIMER_CNTR2
argument_list|,
operator|(
name|pitch
operator|>>
literal|8
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|beeping
condition|)
block|{
comment|/* enable counter2 output to speaker */
if|if
condition|(
name|pitch
condition|)
name|outb
argument_list|(
name|IO_PPI
argument_list|,
name|inb
argument_list|(
name|IO_PPI
argument_list|)
operator||
literal|3
argument_list|)
expr_stmt|;
name|beeping
operator|=
name|period
expr_stmt|;
name|timeout
argument_list|(
name|sysbeepstop
argument_list|,
operator|(
name|void
operator|*
operator|)
name|NULL
argument_list|,
name|period
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

