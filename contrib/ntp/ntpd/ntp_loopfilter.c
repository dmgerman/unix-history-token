begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_loopfilter.c - implements the NTP loop filter algorithm  *  */
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_io.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
name|defined
argument_list|(
name|VMS_LOCALUNIT
argument_list|)
end_if

begin_comment
comment|/*wjm*/
end_comment

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_include
include|#
directive|include
file|"ntp_syscall.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

begin_comment
comment|/*  * This is an implementation of the clock discipline algorithm described  * in UDel TR 97-4-3, as amended. It operates as an adaptive parameter,  * hybrid phase/frequency-lock loop. A number of sanity checks are  * included to protect against timewarps, timespikes and general mayhem.  * All units are in s and s/s, unless noted otherwise.  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAX
value|.128
end_define

begin_comment
comment|/* default max offset (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PANIC
value|1000.
end_define

begin_comment
comment|/* default panic offset (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAXSTAB
value|2e-6
end_define

begin_comment
comment|/* max frequency stability */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAXERR
value|1e-2
end_define

begin_comment
comment|/* max phase jitter (s) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_PLL
value|4
end_define

begin_comment
comment|/* PLL loop gain (shift) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_AVG
value|4.
end_define

begin_comment
comment|/* FLL loop gain */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MINSEC
value|256.
end_define

begin_comment
comment|/* min FLL update interval (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MINSTEP
value|900.
end_define

begin_comment
comment|/* step-change timeout (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_DAY
value|86400.
end_define

begin_comment
comment|/* one day of seconds */
end_comment

begin_define
define|#
directive|define
name|CLOCK_LIMIT
value|30
end_define

begin_comment
comment|/* poll-adjust threshold */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PGATE
value|4.
end_define

begin_comment
comment|/* poll-adjust gate */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ALLAN
value|1024.
end_define

begin_comment
comment|/* min Allan intercept (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ADF
value|1e11
end_define

begin_comment
comment|/* Allan deviation factor */
end_comment

begin_comment
comment|/*  * Clock discipline state machine. This is used to control the  * synchronization behavior during initialization and following a  * timewarp.   */
end_comment

begin_define
define|#
directive|define
name|S_NSET
value|0
end_define

begin_comment
comment|/* clock never set */
end_comment

begin_define
define|#
directive|define
name|S_FSET
value|1
end_define

begin_comment
comment|/* frequency set from the drift file */
end_comment

begin_define
define|#
directive|define
name|S_TSET
value|2
end_define

begin_comment
comment|/* time set */
end_comment

begin_define
define|#
directive|define
name|S_FREQ
value|3
end_define

begin_comment
comment|/* frequency mode */
end_comment

begin_define
define|#
directive|define
name|S_SYNC
value|4
end_define

begin_comment
comment|/* clock synchronized */
end_comment

begin_define
define|#
directive|define
name|S_SPIK
value|5
end_define

begin_comment
comment|/* spike detected */
end_comment

begin_comment
comment|/*  * Kernel PLL/PPS state machine. This is used with the kernel PLL  * modifications described in the README.kernel file.  *  * If kernel support for the ntp_adjtime() system call is available, the  * ntp_control flag is set. The ntp_enable and kern_enable flags can be  * set at configuration time or run time using ntpdc. If ntp_enable is  * false, the discipline loop is unlocked and no correctios of any kind  * are made. If both ntp_control and kern_enable are set, the kernel  * support is used as described above; if false, the kernel is bypassed  * entirely and the daemon PLL used instead.  *  * Each update to a prefer peer sets pps_update if it survives the  * intersection algorithm and its time is within range. The PPS time  * discipline is enabled (STA_PPSTIME bit set in the status word) when  * pps_update is true and the PPS frequency discipline is enabled. If  * the PPS time discipline is enabled and the kernel reports a PPS  * signal is present, the pps_control variable is set to the current  * time. If the current time is later than pps_control by PPS_MAXAGE  * (120 s), this variable is set to zero.  *  * If an external clock is present, the clock driver sets STA_CLK in the  * status word. When the local clock driver sees this bit, it updates  * via this routine, which then calls ntp_adjtime() with the STA_PLL bit  * set to zero, in which case the system clock is not adjusted. This is  * also a signal for the external clock driver to discipline the system  * clock.  */
end_comment

begin_define
define|#
directive|define
name|PPS_MAXAGE
value|120
end_define

begin_comment
comment|/* kernel pps signal timeout (s) */
end_comment

begin_comment
comment|/*  * Program variables  */
end_comment

begin_decl_stmt
specifier|static
name|double
name|clock_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock offset adjustment (s) */
end_comment

begin_decl_stmt
name|double
name|drift_comp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock frequency (ppm) */
end_comment

begin_decl_stmt
name|double
name|clock_stability
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock stability (ppm) */
end_comment

begin_decl_stmt
name|double
name|clock_max
init|=
name|CLOCK_MAX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max offset allowed before step (s) */
end_comment

begin_decl_stmt
specifier|static
name|double
name|clock_panic
init|=
name|CLOCK_PANIC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max offset allowed before panic */
end_comment

begin_decl_stmt
name|u_long
name|pps_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last pps sample time */
end_comment

begin_decl_stmt
specifier|static
name|void
name|rstclock
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* state transition function */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_decl_stmt
name|int
name|pll_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status bits for kernel pll */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

begin_comment
comment|/*  * Clock state machine control flags  */
end_comment

begin_decl_stmt
name|int
name|ntp_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock discipline enabled */
end_comment

begin_decl_stmt
name|int
name|pll_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel support available */
end_comment

begin_decl_stmt
name|int
name|kern_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel support enabled */
end_comment

begin_decl_stmt
name|int
name|ext_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external clock enabled */
end_comment

begin_decl_stmt
name|int
name|pps_update
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pps update valid */
end_comment

begin_decl_stmt
name|int
name|allow_set_backward
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* step corrections allowed */
end_comment

begin_decl_stmt
name|int
name|correct_any
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* corrections> 1000 s allowed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STA_NANO
end_ifdef

begin_decl_stmt
name|int
name|pll_nano
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nanosecond kernel switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STA_NANO */
end_comment

begin_comment
comment|/*  * Clock state machine variables  */
end_comment

begin_decl_stmt
name|u_char
name|sys_poll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log2 of system poll interval */
end_comment

begin_decl_stmt
name|int
name|state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock discipline state */
end_comment

begin_decl_stmt
name|int
name|tc_counter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poll-adjust counter */
end_comment

begin_decl_stmt
name|u_long
name|last_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of last clock update (s) */
end_comment

begin_decl_stmt
name|double
name|last_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last clock offset (s) */
end_comment

begin_decl_stmt
name|double
name|allan_xpt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allan intercept (s) */
end_comment

begin_decl_stmt
name|double
name|sys_error
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system standard error (s) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
end_if

begin_comment
comment|/* Emacs cc-mode goes nuts if we split the next line... */
end_comment

begin_define
define|#
directive|define
name|MOD_BITS
value|(MOD_OFFSET | MOD_MAXERROR | MOD_ESTERROR | \     MOD_STATUS | MOD_TIMECONST)
end_define

begin_decl_stmt
specifier|static
name|void
name|pll_trap
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration trap */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGSYS
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|sigaction
name|sigsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current sigaction status */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sigaction
name|newsigsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new sigaction status */
end_comment

begin_decl_stmt
specifier|static
name|sigjmp_buf
name|env
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environment var. for pll_trap() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGSYS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

begin_comment
comment|/*  * init_loopfilter - initialize loop filter data  */
end_comment

begin_function
name|void
name|init_loopfilter
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Initialize state variables. Initially, we expect no drift 	 * file, so set the state to S_NSET. 	 */
name|rstclock
argument_list|(
name|S_NSET
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * local_clock - the NTP logical clock loop filter. Returns 1 if the  * clock was stepped, 0 if it was slewed and -1 if it is hopeless.  */
end_comment

begin_function
name|int
name|local_clock
parameter_list|(
name|struct
name|peer
modifier|*
name|peer
parameter_list|,
comment|/* synch source peer structure */
name|double
name|fp_offset
parameter_list|,
comment|/* clock offset (s) */
name|double
name|epsil
comment|/* jittter (square s*s) */
parameter_list|)
block|{
name|double
name|mu
decl_stmt|;
comment|/* interval since last update (s) */
name|double
name|oerror
decl_stmt|;
comment|/* previous error estimate */
name|double
name|flladj
decl_stmt|;
comment|/* FLL frequency adjustment (ppm) */
name|double
name|plladj
decl_stmt|;
comment|/* PLL frequency adjustment (ppm) */
name|double
name|clock_frequency
decl_stmt|;
comment|/* clock frequency adjustment (ppm) */
name|double
name|dtemp
decl_stmt|,
name|etemp
decl_stmt|;
comment|/* double temps */
name|int
name|retval
decl_stmt|;
comment|/* return value */
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
name|struct
name|timex
name|ntv
decl_stmt|;
comment|/* kernel interface structure */
endif|#
directive|endif
comment|/* KERNEL_PLL */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"local_clock: offset %.6f jitter %.6f state %d\n"
argument_list|,
name|fp_offset
argument_list|,
name|SQRT
argument_list|(
name|epsil
argument_list|)
argument_list|,
name|state
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|ntp_enable
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * If the clock is way off, don't tempt fate by correcting it. 	 */
ifndef|#
directive|ifndef
name|SYS_WINNT
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
argument_list|)
operator|>=
name|clock_panic
operator|&&
operator|!
name|correct_any
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"time error %.0f over %d seconds; set clock manually"
argument_list|,
name|fp_offset
argument_list|,
operator|(
name|int
operator|)
name|clock_panic
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* 	 * If the clock has never been set, set it and initialize the 	 * discipline parameters. We then switch to frequency mode to 	 * speed the inital convergence process. If lucky, after an hour 	 * the ntp.drift file is created and initialized and we don't 	 * get here again. 	 */
if|if
condition|(
name|state
operator|==
name|S_NSET
condition|)
block|{
name|step_systime
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|NLOG
argument_list|(
argument|NLOG_SYNCEVENT|NLOG_SYSEVENT
argument_list|)
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"time set %.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|S_TSET
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|S_FREQ
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* 	 * Update the jitter estimate. 	 */
name|oerror
operator|=
name|sys_error
expr_stmt|;
name|dtemp
operator|=
name|SQUARE
argument_list|(
name|sys_error
argument_list|)
expr_stmt|;
name|sys_error
operator|=
name|SQRT
argument_list|(
name|dtemp
operator|+
operator|(
name|epsil
operator|-
name|dtemp
operator|)
operator|/
name|CLOCK_AVG
argument_list|)
expr_stmt|;
comment|/* 	 * Clock state machine transition function. This is where the 	 * action is and defines how the system reacts to large phase 	 * and frequency errors. There are two main regimes: when the 	 * phase error exceeds the maximum allowed for ordinary tracking 	 * and otherwise when it does not. 	 */
name|retval
operator|=
literal|0
expr_stmt|;
name|clock_frequency
operator|=
name|flladj
operator|=
name|plladj
operator|=
literal|0
expr_stmt|;
name|mu
operator|=
name|current_time
operator|-
name|last_time
expr_stmt|;
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
argument_list|)
operator|>
name|clock_max
condition|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
comment|/* 		 * In S_TSET state the time has been set at the last 		 * valid update and the offset at that time set to zero. 		 * If following that we cruise outside the capture 		 * range, assume a really bad frequency error and switch 		 * to S_FREQ state. 		 */
case|case
name|S_TSET
case|:
name|rstclock
argument_list|(
name|S_FREQ
argument_list|)
expr_stmt|;
name|last_offset
operator|=
name|clock_offset
operator|=
name|fp_offset
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 		 * In S_SYNC state we ignore outlyers. At the first 		 * outlyer after CLOCK_MINSTEP (900 s), switch to S_SPIK 		 * state. 		 */
case|case
name|S_SYNC
case|:
if|if
condition|(
name|mu
operator|<
name|CLOCK_MINSTEP
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|rstclock
argument_list|(
name|S_SPIK
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 		 * In S_FREQ state we ignore outlyers. At the first 		 * outlyer after CLOCK_MINSTEP (900 s), compute the 		 * apparent phase and frequency correction. 		 */
case|case
name|S_FREQ
case|:
if|if
condition|(
name|mu
operator|<
name|CLOCK_MINSTEP
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|clock_frequency
operator|=
operator|(
name|fp_offset
operator|-
name|clock_offset
operator|)
operator|/
name|mu
expr_stmt|;
comment|/* fall through to default */
comment|/* 		 * In S_SPIK state a large correction is necessary. 		 * Since the outlyer may be due to a large frequency 		 * error, compute the apparent frequency correction. 		 */
case|case
name|S_SPIK
case|:
name|clock_frequency
operator|=
operator|(
name|fp_offset
operator|-
name|clock_offset
operator|)
operator|/
name|mu
expr_stmt|;
comment|/* fall through to default */
comment|/* 		 * We get here directly in S_FSET state and indirectly 		 * from S_FREQ and S_SPIK states. The clock is either 		 * reset or shaken, but never stirred. 		 */
default|default:
if|if
condition|(
name|allow_set_backward
operator||
name|correct_any
condition|)
block|{
name|step_systime
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|NLOG
argument_list|(
argument|NLOG_SYNCEVENT|NLOG_SYSEVENT
argument_list|)
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"time reset %.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|S_TSET
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|NLOG
argument_list|(
argument|NLOG_SYNCEVENT|NLOG_SYSEVENT
argument_list|)
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"time slew %.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|S_FREQ
argument_list|)
expr_stmt|;
name|last_offset
operator|=
name|clock_offset
operator|=
name|fp_offset
expr_stmt|;
block|}
break|break;
block|}
block|}
else|else
block|{
switch|switch
condition|(
name|state
condition|)
block|{
comment|/* 		 * If this is the first update, initialize the 		 * discipline parameters and pretend we had just set the 		 * clock. We don't want to step the clock unless we have 		 * to. 		 */
case|case
name|S_FSET
case|:
name|rstclock
argument_list|(
name|S_TSET
argument_list|)
expr_stmt|;
name|last_offset
operator|=
name|clock_offset
operator|=
name|fp_offset
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 		 * In S_FREQ state we ignore updates until CLOCK_MINSTEP 		 * (900 s). After that, correct the phase and frequency 		 * and switch to S_SYNC state. 		 */
case|case
name|S_FREQ
case|:
if|if
condition|(
name|mu
operator|<
name|CLOCK_MINSTEP
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|clock_frequency
operator|=
operator|(
name|fp_offset
operator|-
name|clock_offset
operator|)
operator|/
name|mu
expr_stmt|;
name|clock_offset
operator|=
name|fp_offset
expr_stmt|;
name|rstclock
argument_list|(
name|S_SYNC
argument_list|)
expr_stmt|;
break|break;
comment|/* 		 * Either the clock has just been set or the previous 		 * update was a spike and ignored. Since this update is 		 * not an outlyer, fold the tent and resume life. 		 */
case|case
name|S_TSET
case|:
case|case
name|S_SPIK
case|:
name|rstclock
argument_list|(
name|S_SYNC
argument_list|)
expr_stmt|;
comment|/* fall through to default */
comment|/* 		 * We come here in the normal case for linear phase and 		 * frequency adjustments. If the offset exceeds the 		 * previous time error estimate by CLOCK_SGATE and the 		 * interval since the last update is less than twice the 		 * poll interval, consider the update a popcorn spike 		 * and ignore it. 		 */
default|default:
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
operator|-
name|last_offset
argument_list|)
operator|>
name|CLOCK_SGATE
operator|*
name|oerror
operator|&&
name|mu
operator|<
name|ULOGTOD
argument_list|(
name|sys_poll
operator|+
literal|1
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"local_clock: popcorn %.6f %.6f\n"
argument_list|,
name|fp_offset
argument_list|,
name|last_offset
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|last_offset
operator|=
name|fp_offset
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 			 * Compute the FLL and PLL frequency adjustments 			 * conditioned on intricate weighting factors. 			 * For the FLL, the averaging interval is 			 * clamped not to decrease below the Allan 			 * intercept and the gain is decreased from 			 * unity for mu above CLOCK_MINSEC (1024 s) to 			 * zero below CLOCK_MINSEC (256 s). For the PLL, 			 * the averaging interval is clamped not to 			 * exceed the sustem poll interval. These 			 * measures insure stability of the clock 			 * discipline even when the rules of fair 			 * engagement are broken. 			 */
name|dtemp
operator|=
name|max
argument_list|(
name|mu
argument_list|,
name|allan_xpt
argument_list|)
expr_stmt|;
name|etemp
operator|=
name|min
argument_list|(
name|max
argument_list|(
literal|0
argument_list|,
name|mu
operator|-
name|CLOCK_MINSEC
argument_list|)
operator|/
name|CLOCK_ALLAN
argument_list|,
literal|1.
argument_list|)
expr_stmt|;
name|flladj
operator|=
name|fp_offset
operator|*
name|etemp
operator|/
operator|(
name|dtemp
operator|*
name|CLOCK_AVG
operator|)
expr_stmt|;
name|dtemp
operator|=
name|ULOGTOD
argument_list|(
name|SHIFT_PLL
operator|+
literal|2
operator|+
name|sys_poll
argument_list|)
expr_stmt|;
name|etemp
operator|=
name|min
argument_list|(
name|mu
argument_list|,
name|ULOGTOD
argument_list|(
name|sys_poll
argument_list|)
argument_list|)
expr_stmt|;
name|plladj
operator|=
name|fp_offset
operator|*
name|etemp
operator|/
operator|(
name|dtemp
operator|*
name|dtemp
operator|)
expr_stmt|;
name|clock_offset
operator|=
name|fp_offset
expr_stmt|;
break|break;
block|}
block|}
comment|/* 	 * This code segment works when clock adjustments are made using 	 * precision time kernel support and the ntp_adjtime() system 	 * call. This support is available in Solaris 2.6 and later, 	 * Digital Unix 4.0 and later, FreeBSD, Linux and specially 	 * modified kernels for HP-UX 9 and Ultrix 4. In the case of the 	 * DECstation 5000/240 and Alpha AXP, additional kernel 	 * modifications provide a true microsecond clock and nanosecond 	 * clock, respectively. 	 */
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
comment|/* 		 * We initialize the structure for the ntp_adjtime() 		 * system call. We have to convert everything to 		 * microseconds or nanoseconds first. Do not update the 		 * system variables if the ext_enable flag is set. In 		 * this case, the external clock driver will update the 		 * variables, which will be read later by the local 		 * clock driver. Afterwards, remember the time and 		 * frequency offsets for jitter and stability values and 		 * to update the drift file. 		 */
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|ntv
argument_list|)
expr_stmt|;
if|if
condition|(
name|ext_enable
condition|)
block|{
name|ntv
operator|.
name|modes
operator|=
name|MOD_STATUS
expr_stmt|;
block|}
else|else
block|{
name|ntv
operator|.
name|modes
operator|=
name|MOD_BITS
expr_stmt|;
if|if
condition|(
name|clock_offset
operator|<
literal|0
condition|)
name|dtemp
operator|=
operator|-
literal|.5
expr_stmt|;
else|else
name|dtemp
operator|=
literal|.5
expr_stmt|;
ifdef|#
directive|ifdef
name|STA_NANO
if|if
condition|(
name|pll_nano
condition|)
name|ntv
operator|.
name|offset
operator|=
call|(
name|int32
call|)
argument_list|(
name|clock_offset
operator|*
literal|1e9
operator|+
name|dtemp
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* STA_NANO */
name|ntv
operator|.
name|offset
operator|=
call|(
name|int32
call|)
argument_list|(
name|clock_offset
operator|*
literal|1e6
operator|+
name|dtemp
argument_list|)
expr_stmt|;
if|if
condition|(
name|clock_frequency
operator|!=
literal|0
condition|)
block|{
name|ntv
operator|.
name|modes
operator||=
name|MOD_FREQUENCY
expr_stmt|;
name|ntv
operator|.
name|freq
operator|=
call|(
name|int32
call|)
argument_list|(
operator|(
name|clock_frequency
operator|+
name|drift_comp
operator|)
operator|*
literal|65536e6
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|STA_NANO
name|ntv
operator|.
name|constant
operator|=
name|sys_poll
expr_stmt|;
else|#
directive|else
name|ntv
operator|.
name|constant
operator|=
name|sys_poll
operator|-
literal|4
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
name|ntv
operator|.
name|esterror
operator|=
call|(
name|u_int32
call|)
argument_list|(
name|sys_error
operator|*
literal|1e6
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|maxerror
operator|=
call|(
name|u_int32
call|)
argument_list|(
operator|(
name|sys_rootdelay
operator|/
literal|2
operator|+
name|sys_rootdispersion
operator|)
operator|*
literal|1e6
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|status
operator|=
name|STA_PLL
expr_stmt|;
comment|/* 			 * Set the leap bits in the status word. 			 */
if|if
condition|(
name|sys_leap
operator|==
name|LEAP_NOTINSYNC
condition|)
block|{
name|ntv
operator|.
name|status
operator||=
name|STA_UNSYNC
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|calleapwhen
argument_list|(
name|sys_reftime
operator|.
name|l_ui
argument_list|)
operator|<
name|CLOCK_DAY
condition|)
block|{
if|if
condition|(
name|sys_leap
operator|&
name|LEAP_ADDSECOND
condition|)
name|ntv
operator|.
name|status
operator||=
name|STA_INS
expr_stmt|;
elseif|else
if|if
condition|(
name|sys_leap
operator|&
name|LEAP_DELSECOND
condition|)
name|ntv
operator|.
name|status
operator||=
name|STA_DEL
expr_stmt|;
block|}
comment|/* 			 * Switch to FLL mode if the poll interval is 			 * greater than MAXDPOLL, so that the kernel 			 * loop behaves as the daemon loop; viz., 			 * selects the FLL when necessary, etc. For 			 * legacy only. 			 */
if|if
condition|(
name|sys_poll
operator|>
name|NTP_MAXDPOLL
condition|)
name|ntv
operator|.
name|status
operator||=
name|STA_FLL
expr_stmt|;
block|}
comment|/* 		 * Wiggle the PPS bits according to the health of the 		 * prefer peer. 		 */
if|if
condition|(
name|pll_status
operator|&
name|STA_PPSSIGNAL
condition|)
name|ntv
operator|.
name|status
operator||=
name|STA_PPSFREQ
expr_stmt|;
if|if
condition|(
name|pll_status
operator|&
name|STA_PPSFREQ
operator|&&
name|pps_update
condition|)
name|ntv
operator|.
name|status
operator||=
name|STA_PPSTIME
expr_stmt|;
comment|/* 		 * Update the offset and frequency from the kernel 		 * variables. 		 */
if|if
condition|(
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
operator|==
name|TIME_ERROR
condition|)
block|{
if|if
condition|(
name|ntv
operator|.
name|status
operator|!=
name|pll_status
condition|)
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"kernel pll status change %x"
argument_list|,
name|ntv
operator|.
name|status
argument_list|)
expr_stmt|;
block|}
name|pll_status
operator|=
name|ntv
operator|.
name|status
expr_stmt|;
ifdef|#
directive|ifdef
name|STA_NANO
if|if
condition|(
name|pll_nano
condition|)
name|clock_offset
operator|=
name|ntv
operator|.
name|offset
operator|/
literal|1e9
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* STA_NANO */
name|clock_offset
operator|=
name|ntv
operator|.
name|offset
operator|/
literal|1e6
expr_stmt|;
ifdef|#
directive|ifdef
name|STA_NANO
name|sys_poll
operator|=
name|ntv
operator|.
name|constant
expr_stmt|;
else|#
directive|else
name|sys_poll
operator|=
name|ntv
operator|.
name|constant
operator|+
literal|4
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
name|clock_frequency
operator|=
name|ntv
operator|.
name|freq
operator|/
literal|65536e6
operator|-
name|drift_comp
expr_stmt|;
name|flladj
operator|=
name|plladj
operator|=
literal|0
expr_stmt|;
comment|/* 		 * If the kernel pps discipline is working, monitor its 		 * performance. 		 */
if|if
condition|(
name|ntv
operator|.
name|status
operator|&
name|STA_PPSTIME
condition|)
block|{
if|if
condition|(
operator|!
name|pps_control
condition|)
name|NLOG
argument_list|(
argument|NLOG_SYSEVENT
argument_list|)
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"pps sync enabled"
argument_list|)
expr_stmt|;
name|pps_control
operator|=
name|current_time
expr_stmt|;
ifdef|#
directive|ifdef
name|STA_NANO
if|if
condition|(
name|pll_nano
condition|)
name|record_peer_stats
argument_list|(
operator|&
name|loopback_interface
operator|->
name|sin
argument_list|,
name|ctlsysstatus
argument_list|()
argument_list|,
name|ntv
operator|.
name|offset
operator|/
literal|1e9
argument_list|,
literal|0.
argument_list|,
name|ntv
operator|.
name|jitter
operator|/
literal|1e9
argument_list|,
literal|0.
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* STA_NANO */
name|record_peer_stats
argument_list|(
operator|&
name|loopback_interface
operator|->
name|sin
argument_list|,
name|ctlsysstatus
argument_list|()
argument_list|,
name|ntv
operator|.
name|offset
operator|/
literal|1e6
argument_list|,
literal|0.
argument_list|,
name|ntv
operator|.
name|jitter
operator|/
literal|1e6
argument_list|,
literal|0.
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
comment|/* 	 * Adjust the clock frequency and calculate the stability. If 	 * kernel support is available, we use the results of the kernel 	 * discipline instead of the PLL/FLL discipline. In this case, 	 * drift_comp is a sham and used only for updating the drift 	 * file and for billboard eye candy. 	 */
name|etemp
operator|=
name|clock_frequency
operator|+
name|flladj
operator|+
name|plladj
expr_stmt|;
name|drift_comp
operator|+=
name|etemp
expr_stmt|;
if|if
condition|(
name|drift_comp
operator|>
name|sys_maxfreq
condition|)
name|drift_comp
operator|=
name|sys_maxfreq
expr_stmt|;
elseif|else
if|if
condition|(
name|drift_comp
operator|<=
operator|-
name|sys_maxfreq
condition|)
name|drift_comp
operator|=
operator|-
name|sys_maxfreq
expr_stmt|;
name|dtemp
operator|=
name|SQUARE
argument_list|(
name|clock_stability
argument_list|)
expr_stmt|;
name|etemp
operator|=
name|SQUARE
argument_list|(
name|etemp
argument_list|)
operator|-
name|dtemp
expr_stmt|;
name|clock_stability
operator|=
name|SQRT
argument_list|(
name|dtemp
operator|+
name|etemp
operator|/
name|CLOCK_AVG
argument_list|)
expr_stmt|;
name|allan_xpt
operator|=
name|max
argument_list|(
name|CLOCK_ALLAN
argument_list|,
name|clock_stability
operator|*
name|CLOCK_ADF
argument_list|)
expr_stmt|;
comment|/* 	 * In SYNC state, adjust the poll interval. 	 */
if|if
condition|(
name|state
operator|==
name|S_SYNC
condition|)
block|{
if|if
condition|(
name|clock_stability
operator|<
name|CLOCK_MAXSTAB
operator|&&
name|fabs
argument_list|(
name|clock_offset
argument_list|)
operator|<
name|CLOCK_PGATE
operator|*
name|sys_error
condition|)
block|{
name|tc_counter
operator|+=
name|sys_poll
expr_stmt|;
if|if
condition|(
name|tc_counter
operator|>
name|CLOCK_LIMIT
condition|)
block|{
name|tc_counter
operator|=
name|CLOCK_LIMIT
expr_stmt|;
if|if
condition|(
name|sys_poll
operator|<
name|peer
operator|->
name|maxpoll
condition|)
block|{
name|tc_counter
operator|=
literal|0
expr_stmt|;
name|sys_poll
operator|++
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|tc_counter
operator|-=
name|sys_poll
operator|<<
literal|1
expr_stmt|;
if|if
condition|(
name|tc_counter
operator|<
operator|-
name|CLOCK_LIMIT
condition|)
block|{
name|tc_counter
operator|=
operator|-
name|CLOCK_LIMIT
expr_stmt|;
if|if
condition|(
name|sys_poll
operator|>
name|peer
operator|->
name|minpoll
condition|)
block|{
name|tc_counter
operator|=
literal|0
expr_stmt|;
name|sys_poll
operator|--
expr_stmt|;
block|}
block|}
block|}
block|}
comment|/* 	 * Update the system time variables. 	 */
name|last_time
operator|=
name|current_time
expr_stmt|;
name|last_offset
operator|=
name|clock_offset
expr_stmt|;
name|dtemp
operator|=
name|peer
operator|->
name|disp
operator|+
name|SQRT
argument_list|(
name|peer
operator|->
name|variance
operator|+
name|SQUARE
argument_list|(
name|sys_error
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|peer
operator|->
name|flags
operator|&
name|FLAG_REFCLOCK
operator|)
operator|==
literal|0
operator|&&
name|dtemp
operator|<
name|MINDISPERSE
condition|)
name|dtemp
operator|=
name|MINDISPERSE
expr_stmt|;
name|sys_rootdispersion
operator|=
name|peer
operator|->
name|rootdispersion
operator|+
name|dtemp
expr_stmt|;
operator|(
name|void
operator|)
name|record_loop_stats
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"local_clock: mu %.0f allan %.0f fadj %.3f fll %.3f pll %.3f\n"
argument_list|,
name|mu
argument_list|,
name|allan_xpt
argument_list|,
name|clock_frequency
operator|*
literal|1e6
argument_list|,
name|flladj
operator|*
literal|1e6
argument_list|,
name|plladj
operator|*
literal|1e6
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"local_clock: jitter %.6f freq %.3f stab %.3f poll %d count %d\n"
argument_list|,
name|sys_error
argument_list|,
name|drift_comp
operator|*
literal|1e6
argument_list|,
name|clock_stability
operator|*
literal|1e6
argument_list|,
name|sys_poll
argument_list|,
name|tc_counter
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * adj_host_clock - Called once every second to update the local clock.  */
end_comment

begin_function
name|void
name|adj_host_clock
parameter_list|(
name|void
parameter_list|)
block|{
name|double
name|adjustment
decl_stmt|;
comment|/* 	 * Update the dispersion since the last update. In contrast to 	 * NTPv3, NTPv4 does not declare unsynchronized after one day, 	 * since the dispersion check serves this function. Also, 	 * since the poll interval can exceed one day, the old test 	 * would be counterproductive. Note we do this even with 	 * external clocks, since the clock driver will recompute the 	 * maximum error and the local clock driver will pick it up and 	 * pass to the common refclock routines. Very elegant. 	 */
name|sys_rootdispersion
operator|+=
name|CLOCK_PHI
expr_stmt|;
comment|/* 	 * Declare PPS kernel unsync if the pps signal has not been 	 * heard for a few minutes. 	 */
if|if
condition|(
name|pps_control
operator|&&
name|current_time
operator|-
name|pps_control
operator|>
name|PPS_MAXAGE
condition|)
block|{
if|if
condition|(
name|pps_control
condition|)
name|NLOG
argument_list|(
argument|NLOG_SYSEVENT
argument_list|)
comment|/* conditional if clause */
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"pps sync disabled"
argument_list|)
expr_stmt|;
name|pps_control
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|ntp_enable
condition|)
return|return;
comment|/* 	 * If the phase-lock loop is implemented in the kernel, we 	 * have no business going further. 	 */
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
return|return;
comment|/* 	 * Intricate wrinkle for legacy only. If the local clock driver 	 * is in use and selected for synchronization, somebody else may 	 * tinker the adjtime() syscall. If this is the case, the driver 	 * is marked prefer and we have to avoid calling adjtime(), 	 * since that may truncate the other guy's requests. 	 */
if|if
condition|(
name|sys_peer
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|sys_peer
operator|->
name|refclktype
operator|==
name|REFCLK_LOCALCLOCK
operator|&&
name|sys_peer
operator|->
name|flags
operator|&
name|FLAG_PREFER
condition|)
return|return;
block|}
name|adjustment
operator|=
name|clock_offset
operator|/
name|ULOGTOD
argument_list|(
name|SHIFT_PLL
operator|+
name|sys_poll
argument_list|)
expr_stmt|;
name|clock_offset
operator|-=
name|adjustment
expr_stmt|;
name|adj_systime
argument_list|(
name|adjustment
operator|+
name|drift_comp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Clock state machine. Enter new state and set state variables.  */
end_comment

begin_function
specifier|static
name|void
name|rstclock
parameter_list|(
name|int
name|trans
comment|/* new state */
parameter_list|)
block|{
name|correct_any
operator|=
name|FALSE
expr_stmt|;
name|state
operator|=
name|trans
expr_stmt|;
switch|switch
condition|(
name|state
condition|)
block|{
comment|/* 	 * Frequency mode. The clock has ben set, but the frequency has 	 * not yet been determined. Note that the Allan intercept is set 	 * insure the clock filter considers only the most recent 	 * measurements. 	 */
case|case
name|S_FREQ
case|:
name|sys_poll
operator|=
name|NTP_MINDPOLL
expr_stmt|;
name|allan_xpt
operator|=
name|CLOCK_ALLAN
expr_stmt|;
name|last_time
operator|=
name|current_time
expr_stmt|;
break|break;
comment|/* 	 * Synchronized mode. Discipline the poll interval. 	 */
case|case
name|S_SYNC
case|:
name|sys_poll
operator|=
name|NTP_MINDPOLL
expr_stmt|;
name|allan_xpt
operator|=
name|CLOCK_ALLAN
expr_stmt|;
name|tc_counter
operator|=
literal|0
expr_stmt|;
break|break;
comment|/* 	 * Don't do anything in S_SPIK state; just continue from S_SYNC 	 * state. 	 */
case|case
name|S_SPIK
case|:
break|break;
comment|/* 	 * S_NSET, S_FSET and S_TSET states. These transient states set 	 * the time reference for future frequency updates. 	 */
default|default:
name|sys_poll
operator|=
name|NTP_MINDPOLL
expr_stmt|;
name|allan_xpt
operator|=
name|CLOCK_ALLAN
expr_stmt|;
name|last_time
operator|=
name|current_time
expr_stmt|;
name|last_offset
operator|=
name|clock_offset
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/*  * loop_config - configure the loop filter  */
end_comment

begin_function
name|void
name|loop_config
parameter_list|(
name|int
name|item
parameter_list|,
name|double
name|freq
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
name|struct
name|timex
name|ntv
decl_stmt|;
endif|#
directive|endif
comment|/* KERNEL_PLL */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"loop_config: state %d freq %.3f\n"
argument_list|,
name|item
argument_list|,
name|freq
operator|*
literal|1e6
argument_list|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
name|item
condition|)
block|{
case|case
name|LOOP_DRIFTINIT
case|:
case|case
name|LOOP_DRIFTCOMP
case|:
comment|/* 		 * The drift file is present and the initial frequency 		 * is available, so set the state to S_FSET 		 */
name|rstclock
argument_list|(
name|S_FSET
argument_list|)
expr_stmt|;
name|drift_comp
operator|=
name|freq
expr_stmt|;
if|if
condition|(
name|drift_comp
operator|>
name|sys_maxfreq
condition|)
name|drift_comp
operator|=
name|sys_maxfreq
expr_stmt|;
if|if
condition|(
name|drift_comp
operator|<
operator|-
name|sys_maxfreq
condition|)
name|drift_comp
operator|=
operator|-
name|sys_maxfreq
expr_stmt|;
ifdef|#
directive|ifdef
name|KERNEL_PLL
comment|/* 		 * If the phase-lock code is implemented in the kernel, 		 * give the time_constant and saved frequency offset to 		 * the kernel. If not, no harm is done. Note the initial 		 * time constant is zero, but the first clock update 		 * will fix that. 		 */
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|ntv
argument_list|)
expr_stmt|;
name|pll_control
operator|=
literal|1
expr_stmt|;
ifdef|#
directive|ifdef
name|MOD_NANO
name|ntv
operator|.
name|modes
operator|=
name|MOD_NANO
expr_stmt|;
endif|#
directive|endif
comment|/* MOD_NANO */
ifdef|#
directive|ifdef
name|SIGSYS
name|newsigsys
operator|.
name|sa_handler
operator|=
name|pll_trap
expr_stmt|;
name|newsigsys
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sigaction
argument_list|(
name|SIGSYS
argument_list|,
operator|&
name|newsigsys
argument_list|,
operator|&
name|sigsys
argument_list|)
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sigaction() fails to save SIGSYS trap: %m"
argument_list|)
expr_stmt|;
name|pll_control
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* 		 * Use sigsetjmp() to save state and then call 		 * ntp_adjtime(); if it fails, then siglongjmp() is used 		 * to return control 		 */
if|if
condition|(
name|sigsetjmp
argument_list|(
name|env
argument_list|,
literal|1
argument_list|)
operator|==
literal|0
condition|)
operator|(
name|void
operator|)
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGSYS
argument_list|,
operator|&
name|sigsys
argument_list|,
operator|(
expr|struct
name|sigaction
operator|*
operator|)
name|NULL
argument_list|)
operator|)
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sigaction() fails to restore SIGSYS trap: %m"
argument_list|)
expr_stmt|;
name|pll_control
operator|=
literal|0
expr_stmt|;
return|return;
block|}
else|#
directive|else
comment|/* SIGSYS */
if|if
condition|(
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
operator|<
literal|0
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"loop_config: ntp_adjtime() failed: %m"
argument_list|)
expr_stmt|;
name|pll_control
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SIGSYS */
comment|/* 		 * If the kernel support is available and enabled, 		 * initialize the parameters, but only if the external 		 * clock is not present. 		 */
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"using kernel phase-lock loop %04x"
argument_list|,
name|ntv
operator|.
name|status
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|STA_NANO
if|if
condition|(
name|ntv
operator|.
name|status
operator|&
name|STA_NANO
condition|)
name|pll_nano
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
ifdef|#
directive|ifdef
name|STA_CLK
if|if
condition|(
name|ntv
operator|.
name|status
operator|&
name|STA_CLK
condition|)
block|{
name|ext_enable
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|ntv
operator|.
name|modes
operator|=
name|MOD_BITS
operator||
name|MOD_FREQUENCY
expr_stmt|;
name|ntv
operator|.
name|freq
operator|=
call|(
name|int32
call|)
argument_list|(
name|drift_comp
operator|*
literal|65536e6
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|maxerror
operator|=
name|MAXDISPERSE
expr_stmt|;
name|ntv
operator|.
name|esterror
operator|=
name|MAXDISPERSE
expr_stmt|;
name|ntv
operator|.
name|status
operator|=
name|STA_UNSYNC
operator||
name|STA_PLL
expr_stmt|;
operator|(
name|void
operator|)
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|ntv
operator|.
name|modes
operator|=
name|MOD_BITS
operator||
name|MOD_FREQUENCY
expr_stmt|;
name|ntv
operator|.
name|freq
operator|=
call|(
name|int32
call|)
argument_list|(
name|drift_comp
operator|*
literal|65536e6
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|maxerror
operator|=
name|MAXDISPERSE
expr_stmt|;
name|ntv
operator|.
name|esterror
operator|=
name|MAXDISPERSE
expr_stmt|;
name|ntv
operator|.
name|status
operator|=
name|STA_UNSYNC
operator||
name|STA_PLL
expr_stmt|;
operator|(
name|void
operator|)
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* STA_CLK */
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
block|}
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGSYS
argument_list|)
end_if

begin_comment
comment|/*  * _trap - trap processor for undefined syscalls  *  * This nugget is called by the kernel when the SYS_ntp_adjtime()  * syscall bombs because the silly thing has not been implemented in  * the kernel. In this case the phase-lock loop is emulated by  * the stock adjtime() syscall and a lot of indelicate abuse.  */
end_comment

begin_function
specifier|static
name|RETSIGTYPE
name|pll_trap
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
name|pll_control
operator|=
literal|0
expr_stmt|;
name|siglongjmp
argument_list|(
name|env
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL&& SIGSYS */
end_comment

end_unit

