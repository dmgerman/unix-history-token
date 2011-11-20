begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  * Copyright (c) 2011 The FreeBSD Foundation  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Portions of this software were developed by Julien Ridoux at the University  * of Melbourne under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah $Hdr: clock.c 1.18 91/01/21$  *	from: @(#)clock.c	8.2 (Berkeley) 1/12/94  *	from: NetBSD: clock_subr.c,v 1.6 2001/07/07 17:04:02 thorpej Exp  *	and  *	from: src/sys/i386/isa/clock.c,v 1.176 2001/09/04  */
end_comment

begin_comment
comment|/*  * Helpers for time-of-day clocks. This is useful for architectures that need  * support multiple models of such clocks, and generally serves to make the  * code more machine-independent.  * If the clock in question can also be used as a time counter, the driver  * needs to initiate this.  * This code is not yet used by all architectures.  */
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
file|"opt_ffclock.h"
end_include

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
file|<sys/clock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FFCLOCK
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeffc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|"clock_if.h"
end_include

begin_decl_stmt
specifier|static
name|device_t
name|clock_dev
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|clock_res
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|timespec
name|clock_adj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX: should be kern. now, it's no longer machdep.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|disable_rtc_set
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_machdep
argument_list|,
name|OID_AUTO
argument_list|,
name|disable_rtc_set
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|disable_rtc_set
argument_list|,
literal|0
argument_list|,
literal|"Disallow adjusting time-of-day clock"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|clock_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|long
name|res
parameter_list|)
comment|/* res has units of microseconds */
block|{
if|if
condition|(
name|clock_dev
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|clock_res
operator|>
name|res
condition|)
block|{
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"not installed as "
literal|"time-of-day clock: clock %s has higher "
literal|"resolution\n"
argument_list|,
name|device_get_name
argument_list|(
name|clock_dev
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|clock_dev
argument_list|,
literal|"removed as "
literal|"time-of-day clock: clock %s has higher "
literal|"resolution\n"
argument_list|,
name|device_get_name
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|clock_dev
operator|=
name|dev
expr_stmt|;
name|clock_res
operator|=
name|res
expr_stmt|;
name|clock_adj
operator|.
name|tv_sec
operator|=
name|res
operator|/
literal|2
operator|/
literal|1000000
expr_stmt|;
name|clock_adj
operator|.
name|tv_nsec
operator|=
name|res
operator|/
literal|2
operator|%
literal|1000000
operator|*
literal|1000
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"registered as a time-of-day clock "
literal|"(resolution %ldus, adjustment %jd.%09jds)\n"
argument_list|,
name|res
argument_list|,
operator|(
name|intmax_t
operator|)
name|clock_adj
operator|.
name|tv_sec
argument_list|,
operator|(
name|intmax_t
operator|)
name|clock_adj
operator|.
name|tv_nsec
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * inittodr and settodr derived from the i386 versions written  * by Christoph Robitschko<chmr@edvz.tu-graz.ac.at>,  reintroduced and  * updated by Chris Stenton<chris@gnome.co.uk> 8/10/94  */
end_comment

begin_comment
comment|/*  * Initialize the time of day register, based on the time base which is, e.g.  * from a filesystem.  */
end_comment

begin_function
name|void
name|inittodr
parameter_list|(
name|time_t
name|base
parameter_list|)
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
name|clock_dev
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"warning: no time-of-day clock registered, system time "
literal|"will not be set accurately\n"
argument_list|)
expr_stmt|;
goto|goto
name|wrong_time
goto|;
block|}
comment|/* XXX: We should poll all registered RTCs in case of failure */
name|error
operator|=
name|CLOCK_GETTIME
argument_list|(
name|clock_dev
argument_list|,
operator|&
name|ts
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
operator|&&
name|error
operator|!=
name|EINVAL
condition|)
block|{
name|printf
argument_list|(
literal|"warning: clock_gettime failed (%d), the system time "
literal|"will not be set accurately\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
goto|goto
name|wrong_time
goto|;
block|}
if|if
condition|(
name|error
operator|==
name|EINVAL
operator|||
name|ts
operator|.
name|tv_sec
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Invalid time in real time clock.\n"
literal|"Check and reset the date immediately!\n"
argument_list|)
expr_stmt|;
goto|goto
name|wrong_time
goto|;
block|}
name|ts
operator|.
name|tv_sec
operator|+=
name|utc_offset
argument_list|()
expr_stmt|;
name|timespecadd
argument_list|(
operator|&
name|ts
argument_list|,
operator|&
name|clock_adj
argument_list|)
expr_stmt|;
name|tc_setclock
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|FFCLOCK
name|ffclock_reset_clock
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
name|wrong_time
label|:
if|if
condition|(
name|base
operator|>
literal|0
condition|)
block|{
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
block|}
block|}
end_function

begin_comment
comment|/*  * Write system time back to RTC  */
end_comment

begin_function
name|void
name|resettodr
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
name|disable_rtc_set
operator|||
name|clock_dev
operator|==
name|NULL
condition|)
return|return;
name|getnanotime
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
name|timespecadd
argument_list|(
operator|&
name|ts
argument_list|,
operator|&
name|clock_adj
argument_list|)
expr_stmt|;
name|ts
operator|.
name|tv_sec
operator|-=
name|utc_offset
argument_list|()
expr_stmt|;
comment|/* XXX: We should really set all registered RTCs */
if|if
condition|(
operator|(
name|error
operator|=
name|CLOCK_SETTIME
argument_list|(
name|clock_dev
argument_list|,
operator|&
name|ts
argument_list|)
operator|)
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"warning: clock_settime failed (%d), time-of-day clock "
literal|"not adjusted to system time\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

