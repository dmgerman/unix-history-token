begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This program simulates a first-order, type-II phase-lock loop using  * actual code segments from modified kernel distributions for SunOS,  * Ultrix and OSF/1 kernels. These segments do not use any licensed code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIMEX_H
end_ifdef

begin_include
include|#
directive|include
file|"timex.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Phase-lock loop definitions  */
end_comment

begin_define
define|#
directive|define
name|HZ
value|100
end_define

begin_comment
comment|/* timer interrupt frequency (Hz) */
end_comment

begin_define
define|#
directive|define
name|MAXPHASE
value|512000
end_define

begin_comment
comment|/* max phase error (us) */
end_comment

begin_define
define|#
directive|define
name|MAXFREQ
value|200
end_define

begin_comment
comment|/* max frequency error (ppm) */
end_comment

begin_define
define|#
directive|define
name|TAU
value|2
end_define

begin_comment
comment|/* time constant (shift 0 - 6) */
end_comment

begin_define
define|#
directive|define
name|POLL
value|16
end_define

begin_comment
comment|/* interval between updates (s) */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|1200
end_define

begin_comment
comment|/* max interval between updates (s) */
end_comment

begin_comment
comment|/*  * Function declarations  */
end_comment

begin_function_decl
name|void
name|hardupdate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|second_overflow
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Kernel variables  */
end_comment

begin_decl_stmt
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timer interrupt period (us) */
end_comment

begin_decl_stmt
name|int
name|fixtick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amortization constant (ppm) */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|timex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ripoff of kernel time variable */
end_comment

begin_comment
comment|/*  * Phase-lock loop variables  */
end_comment

begin_decl_stmt
name|int
name|time_status
init|=
name|TIME_BAD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock synchronization status */
end_comment

begin_decl_stmt
name|long
name|time_offset
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time adjustment (us) */
end_comment

begin_decl_stmt
name|long
name|time_constant
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pll time constant */
end_comment

begin_decl_stmt
name|long
name|time_tolerance
init|=
name|MAXFREQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency tolerance (ppm) */
end_comment

begin_decl_stmt
name|long
name|time_precision
init|=
literal|1000000
operator|/
name|HZ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock precision (us) */
end_comment

begin_decl_stmt
name|long
name|time_maxerror
init|=
name|MAXPHASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum error (us) */
end_comment

begin_decl_stmt
name|long
name|time_esterror
init|=
name|MAXPHASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimated error (us) */
end_comment

begin_decl_stmt
name|long
name|time_phase
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* phase offset (scaled us) */
end_comment

begin_decl_stmt
name|long
name|time_freq
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency offset (scaled ppm) */
end_comment

begin_decl_stmt
name|long
name|time_adj
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tick adjust (scaled 1 / HZ) */
end_comment

begin_decl_stmt
name|long
name|time_reftime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time at last adjustment (s) */
end_comment

begin_comment
comment|/*  * Simulation variables  */
end_comment

begin_decl_stmt
name|double
name|timey
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* simulation time (us) */
end_comment

begin_decl_stmt
name|long
name|timez
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current error (us) */
end_comment

begin_decl_stmt
name|long
name|poll_interval
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poll counter */
end_comment

begin_comment
comment|/*  * Simulation test program  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|tick
operator|=
literal|1000000
operator|/
name|HZ
expr_stmt|;
name|fixtick
operator|=
literal|1000000
operator|%
name|HZ
expr_stmt|;
name|timex
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|timex
operator|.
name|tv_usec
operator|=
name|MAXPHASE
expr_stmt|;
name|time_freq
operator|=
literal|0
expr_stmt|;
name|time_constant
operator|=
name|TAU
expr_stmt|;
name|printf
argument_list|(
literal|"tick %d us, fixtick %d us\n"
argument_list|,
name|tick
argument_list|,
name|fixtick
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"      time    offset      freq   _offset     _freq      _adj\n"
argument_list|)
expr_stmt|;
comment|/* 	 * Grind the loop until ^C 	 */
while|while
condition|(
literal|1
condition|)
block|{
name|timey
operator|+=
call|(
name|double
call|)
argument_list|(
literal|1000000
argument_list|)
operator|/
name|HZ
expr_stmt|;
if|if
condition|(
name|timey
operator|>=
literal|1000000
condition|)
name|timey
operator|-=
literal|1000000
expr_stmt|;
name|hardclock
argument_list|()
expr_stmt|;
if|if
condition|(
name|timex
operator|.
name|tv_usec
operator|>=
literal|1000000
condition|)
block|{
name|timex
operator|.
name|tv_usec
operator|-=
literal|1000000
expr_stmt|;
name|timex
operator|.
name|tv_sec
operator|++
expr_stmt|;
name|second_overflow
argument_list|()
expr_stmt|;
name|poll_interval
operator|++
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|poll_interval
operator|%
name|POLL
operator|)
condition|)
block|{
name|timez
operator|=
operator|(
name|long
operator|)
name|timey
operator|-
name|timex
operator|.
name|tv_usec
expr_stmt|;
if|if
condition|(
name|timez
operator|>
literal|500000
condition|)
name|timez
operator|-=
literal|1000000
expr_stmt|;
if|if
condition|(
name|timez
operator|<
operator|-
literal|500000
condition|)
name|timez
operator|+=
literal|1000000
expr_stmt|;
name|hardupdate
argument_list|(
name|timez
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%10li%10li%10.2f  %08lx  %08lx  %08lx\n"
argument_list|,
name|timex
operator|.
name|tv_sec
argument_list|,
name|timez
argument_list|,
operator|(
name|double
operator|)
name|time_freq
operator|/
operator|(
literal|1
operator|<<
name|SHIFT_KF
operator|)
argument_list|,
name|time_offset
argument_list|,
name|time_freq
argument_list|,
name|time_adj
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|/*  * This routine simulates the ntp_adjtime() call  *  * For default SHIFT_UPDATE = 12, offset is limited to +-512 ms, the  * maximum interval between updates is 4096 s and the maximum frequency  * offset is +-31.25 ms/s.  */
end_comment

begin_function
name|void
name|hardupdate
parameter_list|(
name|long
name|offset
parameter_list|)
block|{
name|long
name|ltemp
decl_stmt|,
name|mtemp
decl_stmt|;
name|time_offset
operator|=
name|offset
operator|<<
name|SHIFT_UPDATE
expr_stmt|;
name|mtemp
operator|=
name|timex
operator|.
name|tv_sec
operator|-
name|time_reftime
expr_stmt|;
name|time_reftime
operator|=
name|timex
operator|.
name|tv_sec
expr_stmt|;
if|if
condition|(
name|mtemp
operator|>
name|MAXSEC
condition|)
name|mtemp
operator|=
literal|0
expr_stmt|;
comment|/* ugly multiply should be replaced */
if|if
condition|(
name|offset
operator|<
literal|0
condition|)
name|time_freq
operator|-=
operator|(
operator|-
name|offset
operator|*
name|mtemp
operator|)
operator|>>
operator|(
name|time_constant
operator|+
name|time_constant
operator|)
expr_stmt|;
else|else
name|time_freq
operator|+=
operator|(
name|offset
operator|*
name|mtemp
operator|)
operator|>>
operator|(
name|time_constant
operator|+
name|time_constant
operator|)
expr_stmt|;
name|ltemp
operator|=
name|time_tolerance
operator|<<
name|SHIFT_KF
expr_stmt|;
if|if
condition|(
name|time_freq
operator|>
name|ltemp
condition|)
name|time_freq
operator|=
name|ltemp
expr_stmt|;
elseif|else
if|if
condition|(
name|time_freq
operator|<
operator|-
name|ltemp
condition|)
name|time_freq
operator|=
operator|-
name|ltemp
expr_stmt|;
if|if
condition|(
name|time_status
operator|==
name|TIME_BAD
condition|)
name|time_status
operator|=
name|TIME_OK
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This routine simulates the timer interrupt  */
end_comment

begin_function
name|void
name|hardclock
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ltemp
decl_stmt|,
name|time_update
decl_stmt|;
name|time_update
operator|=
name|tick
expr_stmt|;
comment|/* computed by adjtime() */
name|time_phase
operator|+=
name|time_adj
expr_stmt|;
if|if
condition|(
name|time_phase
operator|<
operator|-
name|FINEUSEC
condition|)
block|{
name|ltemp
operator|=
operator|-
name|time_phase
operator|>>
name|SHIFT_SCALE
expr_stmt|;
name|time_phase
operator|+=
name|ltemp
operator|<<
name|SHIFT_SCALE
expr_stmt|;
name|time_update
operator|-=
name|ltemp
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|time_phase
operator|>
name|FINEUSEC
condition|)
block|{
name|ltemp
operator|=
name|time_phase
operator|>>
name|SHIFT_SCALE
expr_stmt|;
name|time_phase
operator|-=
name|ltemp
operator|<<
name|SHIFT_SCALE
expr_stmt|;
name|time_update
operator|+=
name|ltemp
expr_stmt|;
block|}
name|timex
operator|.
name|tv_usec
operator|+=
name|time_update
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This routine simulates the overflow of the microsecond field  *  * With SHIFT_SCALE = 23, the maximum frequency adjustment is +-256 us  * per tick, or 25.6 ms/s at a clock frequency of 100 Hz. The time  * contribution is shifted right a minimum of two bits, while the frequency  * contribution is a right shift. Thus, overflow is prevented if the  * frequency contribution is limited to half the maximum or 15.625 ms/s.  */
end_comment

begin_function
name|void
name|second_overflow
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ltemp
decl_stmt|;
name|time_maxerror
operator|+=
name|time_tolerance
expr_stmt|;
if|if
condition|(
name|time_offset
operator|<
literal|0
condition|)
block|{
name|ltemp
operator|=
operator|-
name|time_offset
operator|>>
operator|(
name|SHIFT_KG
operator|+
name|time_constant
operator|)
expr_stmt|;
name|time_offset
operator|+=
name|ltemp
expr_stmt|;
name|time_adj
operator|=
operator|-
operator|(
name|ltemp
operator|<<
operator|(
name|SHIFT_SCALE
operator|-
name|SHIFT_HZ
operator|-
name|SHIFT_UPDATE
operator|)
operator|)
expr_stmt|;
block|}
else|else
block|{
name|ltemp
operator|=
name|time_offset
operator|>>
operator|(
name|SHIFT_KG
operator|+
name|time_constant
operator|)
expr_stmt|;
name|time_offset
operator|-=
name|ltemp
expr_stmt|;
name|time_adj
operator|=
name|ltemp
operator|<<
operator|(
name|SHIFT_SCALE
operator|-
name|SHIFT_HZ
operator|-
name|SHIFT_UPDATE
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|time_freq
operator|<
literal|0
condition|)
name|time_adj
operator|-=
operator|-
name|time_freq
operator|>>
operator|(
name|SHIFT_KF
operator|+
name|SHIFT_HZ
operator|-
name|SHIFT_SCALE
operator|)
expr_stmt|;
else|else
name|time_adj
operator|+=
name|time_freq
operator|>>
operator|(
name|SHIFT_KF
operator|+
name|SHIFT_HZ
operator|-
name|SHIFT_SCALE
operator|)
expr_stmt|;
name|time_adj
operator|+=
name|fixtick
operator|<<
operator|(
name|SHIFT_SCALE
operator|-
name|SHIFT_HZ
operator|)
expr_stmt|;
comment|/* ugly divide should be replaced */
if|if
condition|(
name|timex
operator|.
name|tv_sec
operator|%
literal|86400
operator|==
literal|0
condition|)
block|{
switch|switch
condition|(
name|time_status
condition|)
block|{
case|case
name|TIME_INS
case|:
name|timex
operator|.
name|tv_sec
operator|--
expr_stmt|;
comment|/* !! */
name|time_status
operator|=
name|TIME_OOP
expr_stmt|;
break|break;
case|case
name|TIME_DEL
case|:
name|timex
operator|.
name|tv_sec
operator|++
expr_stmt|;
name|time_status
operator|=
name|TIME_OK
expr_stmt|;
break|break;
case|case
name|TIME_OOP
case|:
name|time_status
operator|=
name|TIME_OK
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

end_unit

