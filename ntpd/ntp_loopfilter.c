begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_loopfilter.c - implements the NTP loop filter algorithm  *  * ATTENTION: Get approval from Dave Mills on all changes to this file!  *  */
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
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
comment|/* default step threshold (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MINSTEP
value|900.
end_define

begin_comment
comment|/* default stepout threshold (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PANIC
value|1000.
end_define

begin_comment
comment|/* default panic threshold (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PHI
value|15e-6
end_define

begin_comment
comment|/* max frequency error (s/s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PLL
value|16.
end_define

begin_comment
comment|/* PLL loop gain (log2) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_AVG
value|8.
end_define

begin_comment
comment|/* parameter averaging constant */
end_comment

begin_define
define|#
directive|define
name|CLOCK_FLL
value|.25
end_define

begin_comment
comment|/* FLL loop gain */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ALLAN
value|11
end_define

begin_comment
comment|/* Allan intercept (log2 s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_DAY
value|86400.
end_define

begin_comment
comment|/* one day in seconds (s) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_JUNE
value|(CLOCK_DAY * 30)
end_define

begin_comment
comment|/* June in seconds (s) */
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
name|PPS_MAXAGE
value|120
end_define

begin_comment
comment|/* kernel pps signal timeout (s) */
end_comment

begin_define
define|#
directive|define
name|FREQTOD
parameter_list|(
name|x
parameter_list|)
value|((x) / 65536e6)
end_define

begin_comment
comment|/* NTP to double */
end_comment

begin_define
define|#
directive|define
name|DTOFREQ
parameter_list|(
name|x
parameter_list|)
value|((int32)((x) * 65536e6))
end_define

begin_comment
comment|/* double to NTP */
end_comment

begin_comment
comment|/*  * Clock discipline state machine. This is used to control the  * synchronization behavior during initialization and following a  * timewarp.  *  *	State< step> step		Comments  *	========================================================  *	NSET	FREQ		step, FREQ	freq not set  *  *	FSET	SYNC		step, SYNC	freq set  *  *	FREQ	if (mu< 900)	if (mu< 900)	set freq direct  *		    ignore	    ignore  *		else		else  *		    freq, SYNC	    freq, step, SYNC  *  *	SYNC	SYNC		SPIK, ignore	adjust phase/freq  *  *	SPIK	SYNC		if (mu< 900)	adjust phase/freq  *				    ignore  *				step, SYNC  */
end_comment

begin_comment
comment|/*  * Kernel PLL/PPS state machine. This is used with the kernel PLL  * modifications described in the documentation.  *  * If kernel support for the ntp_adjtime() system call is available, the  * ntp_control flag is set. The ntp_enable and kern_enable flags can be  * set at configuration time or run time using ntpdc. If ntp_enable is  * false, the discipline loop is unlocked and no corrections of any kind  * are made. If both ntp_control and kern_enable are set, the kernel  * support is used as described above; if false, the kernel is bypassed  * entirely and the daemon discipline used instead.  *  * There have been three versions of the kernel discipline code. The  * first (microkernel) now in Solaris discipilnes the microseconds. The  * second and third (nanokernel) disciplines the clock in nanoseconds.  * These versions are identifed if the symbol STA_PLL is present in the  * header file /usr/include/sys/timex.h. The third and current version  * includes TAI offset and is identified by the symbol NTP_API with  * value 4.  *  * Each PPS time/frequency discipline can be enabled by the atom driver  * or another driver. If enabled, the STA_PPSTIME and STA_FREQ bits are  * set in the kernel status word; otherwise, these bits are cleared.  * These bits are also cleard if the kernel reports an error.  *  * If an external clock is present, the clock driver sets STA_CLK in the  * status word. When the local clock driver sees this bit, it updates  * via this routine, which then calls ntp_adjtime() with the STA_PLL bit  * set to zero, in which case the system clock is not adjusted. This is  * also a signal for the external clock driver to discipline the system  * clock. Unless specified otherwise, all times are in seconds.  */
end_comment

begin_comment
comment|/*  * Program variables that can be tinkered.  */
end_comment

begin_decl_stmt
name|double
name|clock_max
init|=
name|CLOCK_MAX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* step threshold */
end_comment

begin_decl_stmt
name|double
name|clock_minstep
init|=
name|CLOCK_MINSTEP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stepout threshold */
end_comment

begin_decl_stmt
name|double
name|clock_panic
init|=
name|CLOCK_PANIC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* panic threshold */
end_comment

begin_decl_stmt
name|double
name|clock_phi
init|=
name|CLOCK_PHI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dispersion rate (s/s) */
end_comment

begin_decl_stmt
name|u_char
name|allan_xpt
init|=
name|CLOCK_ALLAN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allan intercept (log2 s) */
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
comment|/* offset */
end_comment

begin_decl_stmt
name|double
name|clock_jitter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset jitter */
end_comment

begin_decl_stmt
name|double
name|drift_comp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency (s/s) */
end_comment

begin_decl_stmt
name|double
name|clock_stability
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency stability (wander) (s/s) */
end_comment

begin_decl_stmt
name|double
name|clock_codec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* audio codec frequency (samples/s) */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|clock_epoch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last update */
end_comment

begin_decl_stmt
name|u_int
name|sys_tai
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TAI offset from UTC */
end_comment

begin_function_decl
specifier|static
name|void
name|rstclock
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* transition function */
end_comment

begin_function_decl
specifier|static
name|double
name|direct_freq
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* direct set frequency */
end_comment

begin_function_decl
specifier|static
name|void
name|set_freq
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set frequency */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|timex
name|ntv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_adjtime() parameters */
end_comment

begin_decl_stmt
name|int
name|pll_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last kernel status bits */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STA_NANO
argument_list|)
operator|&&
name|NTP_API
operator|==
literal|4
end_if

begin_decl_stmt
specifier|static
name|u_int
name|loop_tai
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last TAI offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STA_NANO */
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
init|=
literal|1
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
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel support enabled */
end_comment

begin_decl_stmt
name|int
name|pps_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel PPS discipline enabled */
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
name|pps_stratum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pps stratum */
end_comment

begin_decl_stmt
name|int
name|allow_panic
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow panic correction */
end_comment

begin_decl_stmt
name|int
name|mode_ntpdate
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit on first clock set */
end_comment

begin_comment
comment|/*  * Clock state machine variables  */
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
name|u_char
name|sys_poll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time constant/poll (log2 s) */
end_comment

begin_decl_stmt
name|int
name|tc_counter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* jiggle counter */
end_comment

begin_decl_stmt
name|double
name|last_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last offset (s) */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|last_step
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last clock step */
end_comment

begin_comment
comment|/*  * Huff-n'-puff filter variables  */
end_comment

begin_decl_stmt
specifier|static
name|double
modifier|*
name|sys_huffpuff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* huff-n'-puff filter */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sys_hufflen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* huff-n'-puff filter stages */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sys_huffptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* huff-n'-puff filter pointer */
end_comment

begin_decl_stmt
specifier|static
name|double
name|sys_mindly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* huff-n'-puff filter min delay */
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

begin_ifdef
ifdef|#
directive|ifdef
name|SIGSYS
end_ifdef

begin_function_decl
specifier|static
name|void
name|pll_trap
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* configuration trap */
end_comment

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
comment|/* 	 * Initialize state variables. 	 */
name|sys_poll
operator|=
name|ntp_minpoll
expr_stmt|;
name|clock_jitter
operator|=
name|LOGTOD
argument_list|(
name|sys_precision
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * local_clock - the NTP logical clock loop filter.  *  * Return codes:  * -1	update ignored: exceeds panic threshold  * 0	update ignored: popcorn or exceeds step threshold  * 1	clock was slewed  * 2	clock was stepped  *  * LOCKCLOCK: The only thing this routine does is set the  * sys_rootdisp variable equal to the peer dispersion.  */
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
comment|/* clock offset (s) */
parameter_list|)
block|{
name|int
name|rval
decl_stmt|;
comment|/* return code */
name|int
name|osys_poll
decl_stmt|;
comment|/* old system poll */
name|double
name|mu
decl_stmt|;
comment|/* interval since last update */
name|double
name|clock_frequency
decl_stmt|;
comment|/* clock frequency */
name|double
name|dtemp
decl_stmt|,
name|etemp
decl_stmt|;
comment|/* double temps */
name|char
name|tbuf
index|[
literal|80
index|]
decl_stmt|;
comment|/* report buffer */
comment|/* 	 * If the loop is opened or the NIST LOCKCLOCK is in use, 	 * monitor and record the offsets anyway in order to determine 	 * the open-loop response and then go home. 	 */
ifdef|#
directive|ifdef
name|LOCKCLOCK
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
comment|/* LOCKCLOCK */
if|if
condition|(
operator|!
name|ntp_enable
condition|)
block|{
name|record_loop_stats
argument_list|(
name|fp_offset
argument_list|,
name|drift_comp
argument_list|,
name|clock_jitter
argument_list|,
name|clock_stability
argument_list|,
name|sys_poll
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * If the clock is way off, panic is declared. The clock_panic 	 * defaults to 1000 s; if set to zero, the panic will never 	 * occur. The allow_panic defaults to FALSE, so the first panic 	 * will exit. It can be set TRUE by a command line option, in 	 * which case the clock will be set anyway and time marches on. 	 * But, allow_panic will be set FALSE when the update is less 	 * than the step threshold; so, subsequent panics will exit. 	 */
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
argument_list|)
operator|>
name|clock_panic
operator|&&
name|clock_panic
operator|>
literal|0
operator|&&
operator|!
name|allow_panic
condition|)
block|{
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"%+.0f s; set clock manually within %.0f s."
argument_list|,
name|fp_offset
argument_list|,
name|clock_panic
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_SYSFAULT
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * This section simulates ntpdate. If the offset exceeds the 	 * step threshold (128 ms), step the clock to that time and 	 * exit. Othewise, slew the clock to that time and exit. Note 	 * that the slew will persist and eventually complete beyond the 	 * life of this program. Note that while ntpdate is active, the 	 * terminal does not detach, so the termination message prints 	 * directly to the terminal. 	 */
if|if
condition|(
name|mode_ntpdate
condition|)
block|{
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
argument_list|)
operator|>
name|clock_max
operator|&&
name|clock_max
operator|>
literal|0
condition|)
block|{
name|step_systime
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ntpd: time set %+.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ntpd: time set %+.6fs\n"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|adj_systime
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ntpd: time slew %+.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ntpd: time slew %+.6fs\n"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
block|}
name|record_loop_stats
argument_list|(
name|fp_offset
argument_list|,
name|drift_comp
argument_list|,
name|clock_jitter
argument_list|,
name|clock_stability
argument_list|,
name|sys_poll
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * The huff-n'-puff filter finds the lowest delay in the recent 	 * interval. This is used to correct the offset by one-half the 	 * difference between the sample delay and minimum delay. This 	 * is most effective if the delays are highly assymetric and 	 * clockhopping is avoided and the clock frequency wander is 	 * relatively small. 	 */
if|if
condition|(
name|sys_huffpuff
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|peer
operator|->
name|delay
operator|<
name|sys_huffpuff
index|[
name|sys_huffptr
index|]
condition|)
name|sys_huffpuff
index|[
name|sys_huffptr
index|]
operator|=
name|peer
operator|->
name|delay
expr_stmt|;
if|if
condition|(
name|peer
operator|->
name|delay
operator|<
name|sys_mindly
condition|)
name|sys_mindly
operator|=
name|peer
operator|->
name|delay
expr_stmt|;
if|if
condition|(
name|fp_offset
operator|>
literal|0
condition|)
name|dtemp
operator|=
operator|-
operator|(
name|peer
operator|->
name|delay
operator|-
name|sys_mindly
operator|)
operator|/
literal|2
expr_stmt|;
else|else
name|dtemp
operator|=
operator|(
name|peer
operator|->
name|delay
operator|-
name|sys_mindly
operator|)
operator|/
literal|2
expr_stmt|;
name|fp_offset
operator|+=
name|dtemp
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
literal|"local_clock: size %d mindly %.6f huffpuff %.6f\n"
argument_list|,
name|sys_hufflen
argument_list|,
name|sys_mindly
argument_list|,
name|dtemp
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* 	 * Clock state machine transition function which defines how the 	 * system reacts to large phase and frequency excursion. There 	 * are two main regimes: when the offset exceeds the step 	 * threshold (128 ms) and when it does not. Under certain 	 * conditions updates are suspended until the stepout theshold 	 * (900 s) is exceeded. See the documentation on how these 	 * thresholds interact with commands and command line options.  	 * 	 * Note the kernel is disabled if step is disabled or greater 	 * than 0.5 s or in ntpdate mode.  	 */
name|osys_poll
operator|=
name|sys_poll
expr_stmt|;
if|if
condition|(
name|sys_poll
operator|<
name|peer
operator|->
name|minpoll
condition|)
name|sys_poll
operator|=
name|peer
operator|->
name|minpoll
expr_stmt|;
if|if
condition|(
name|sys_poll
operator|>
name|peer
operator|->
name|maxpoll
condition|)
name|sys_poll
operator|=
name|peer
operator|->
name|maxpoll
expr_stmt|;
name|mu
operator|=
name|current_time
operator|-
name|clock_epoch
expr_stmt|;
name|clock_frequency
operator|=
name|drift_comp
expr_stmt|;
name|rval
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
argument_list|)
operator|>
name|clock_max
operator|&&
name|clock_max
operator|>
literal|0
condition|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
comment|/* 		 * In SYNC state we ignore the first outlyer and switch 		 * to SPIK state. 		 */
case|case
name|EVNT_SYNC
case|:
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"%+.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_SPIK
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
name|state
operator|=
name|EVNT_SPIK
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 		 * In FREQ state we ignore outlyers and inlyers. At the 		 * first outlyer after the stepout threshold, compute 		 * the apparent frequency correction and step the phase. 		 */
case|case
name|EVNT_FREQ
case|:
if|if
condition|(
name|mu
operator|<
name|clock_minstep
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|clock_frequency
operator|=
name|direct_freq
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
comment|/* fall through to S_SPIK */
comment|/* 		 * In SPIK state we ignore succeeding outlyers until 		 * either an inlyer is found or the stepout threshold is 		 * exceeded. 		 */
case|case
name|EVNT_SPIK
case|:
if|if
condition|(
name|mu
operator|<
name|clock_minstep
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* fall through to default */
comment|/* 		 * We get here by default in NSET and FSET states and 		 * from above in FREQ or SPIK states. 		 * 		 * In NSET state an initial frequency correction is not 		 * available, usually because the frequency file has not 		 * yet been written. Since the time is outside the step 		 * threshold, the clock is stepped. The frequency will 		 * be set directly following the stepout interval. 		 * 		 * In FSET state the initial frequency has been set from 		 * the frequency file. Since the time is outside the 		 * step threshold, the clock is stepped immediately, 		 * rather than after the stepout interval. Guys get 		 * nervous if it takes 15 minutes to set the clock for 		 * the first time. 		 * 		 * In FREQ and SPIK states the stepout threshold has 		 * expired and the phase is still above the step 		 * threshold. Note that a single spike greater than the 		 * step threshold is always suppressed, even with a 		 * long time constant. 		 */
default|default:
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"%+.6f s"
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_CLOCKRESET
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
name|step_systime
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|reinit_timer
argument_list|()
expr_stmt|;
name|tc_counter
operator|=
literal|0
expr_stmt|;
name|clock_jitter
operator|=
name|LOGTOD
argument_list|(
name|sys_precision
argument_list|)
expr_stmt|;
name|rval
operator|=
literal|2
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|EVNT_NSET
operator|||
operator|(
name|current_time
operator|-
name|last_step
operator|)
operator|<
name|clock_minstep
operator|*
literal|2
condition|)
block|{
name|rstclock
argument_list|(
name|EVNT_FREQ
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
name|last_step
operator|=
name|current_time
expr_stmt|;
break|break;
block|}
name|rstclock
argument_list|(
name|EVNT_SYNC
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * The offset is less than the step threshold. Calculate 		 * the jitter as the exponentially weighted offset 		 * differences.  	      	 */
name|etemp
operator|=
name|SQUARE
argument_list|(
name|clock_jitter
argument_list|)
expr_stmt|;
name|dtemp
operator|=
name|SQUARE
argument_list|(
name|max
argument_list|(
name|fabs
argument_list|(
name|fp_offset
operator|-
name|last_offset
argument_list|)
argument_list|,
name|LOGTOD
argument_list|(
name|sys_precision
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|clock_jitter
operator|=
name|SQRT
argument_list|(
name|etemp
operator|+
operator|(
name|dtemp
operator|-
name|etemp
operator|)
operator|/
name|CLOCK_AVG
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|state
condition|)
block|{
comment|/* 		 * In NSET state this is the first update received and 		 * the frequency has not been initialized. Adjust the 		 * phase, but do not adjust the frequency until after 		 * the stepout threshold. 		 */
case|case
name|EVNT_NSET
case|:
name|rstclock
argument_list|(
name|EVNT_FREQ
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
break|break;
comment|/* 		 * In FSET state this is the first update received and 		 * the frequency has been initialized. Adjust the phase, 		 * but do not adjust the frequency until the next 		 * update. 		 */
case|case
name|EVNT_FSET
case|:
name|rstclock
argument_list|(
name|EVNT_SYNC
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
break|break;
comment|/* 		 * In FREQ state ignore updates until the stepout 		 * threshold. After that, compute the new frequency, but 		 * do not adjust the phase or frequency until the next 		 * update. 		 */
case|case
name|EVNT_FREQ
case|:
if|if
condition|(
name|mu
operator|<
name|clock_minstep
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|clock_frequency
operator|=
name|direct_freq
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|EVNT_SYNC
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
comment|/* 		 * We get here by default in SYNC and SPIK states. Here 		 * we compute the frequency update due to PLL and FLL 		 * contributions. 		 */
default|default:
name|allow_panic
operator|=
name|FALSE
expr_stmt|;
comment|/* 			 * The FLL and PLL frequency gain constants 			 * depend on the time constant and Allan 			 * intercept. The PLL is always used, but 			 * becomes ineffective above the Allan intercept 			 * where the FLL becomes effective. 			 */
if|if
condition|(
name|sys_poll
operator|>=
name|allan_xpt
condition|)
name|clock_frequency
operator|+=
operator|(
name|fp_offset
operator|-
name|clock_offset
operator|)
operator|/
name|max
argument_list|(
name|ULOGTOD
argument_list|(
name|sys_poll
argument_list|)
argument_list|,
name|mu
argument_list|)
operator|*
name|CLOCK_FLL
expr_stmt|;
comment|/* 			 * The PLL frequency gain (numerator) depends on 			 * the minimum of the update interval and Allan 			 * intercept. This reduces the PLL gain when the  			 * FLL becomes effective. 			 */
name|etemp
operator|=
name|min
argument_list|(
name|ULOGTOD
argument_list|(
name|allan_xpt
argument_list|)
argument_list|,
name|mu
argument_list|)
expr_stmt|;
name|dtemp
operator|=
literal|4
operator|*
name|CLOCK_PLL
operator|*
name|ULOGTOD
argument_list|(
name|sys_poll
argument_list|)
expr_stmt|;
name|clock_frequency
operator|+=
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
name|rstclock
argument_list|(
name|EVNT_SYNC
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
ifdef|#
directive|ifdef
name|KERNEL_PLL
comment|/* 	 * This code segment works when clock adjustments are made using 	 * precision time kernel support and the ntp_adjtime() system 	 * call. This support is available in Solaris 2.6 and later, 	 * Digital Unix 4.0 and later, FreeBSD, Linux and specially 	 * modified kernels for HP-UX 9 and Ultrix 4. In the case of the 	 * DECstation 5000/240 and Alpha AXP, additional kernel 	 * modifications provide a true microsecond clock and nanosecond 	 * clock, respectively. 	 * 	 * Important note: The kernel discipline is used only if the 	 * step threshold is less than 0.5 s, as anything higher can 	 * lead to overflow problems. This might occur if some misguided 	 * lad set the step threshold to something ridiculous. 	 */
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
comment|/* 		 * We initialize the structure for the ntp_adjtime() 		 * system call. We have to convert everything to 		 * microseconds or nanoseconds first. Do not update the 		 * system variables if the ext_enable flag is set. In 		 * this case, the external clock driver will update the 		 * variables, which will be read later by the local 		 * clock driver. Afterwards, remember the time and 		 * frequency offsets for jitter and stability values and 		 * to update the frequency file. 		 */
name|memset
argument_list|(
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
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
ifdef|#
directive|ifdef
name|STA_NANO
name|ntv
operator|.
name|modes
operator|=
name|MOD_BITS
operator||
name|MOD_NANO
expr_stmt|;
else|#
directive|else
comment|/* STA_NANO */
name|ntv
operator|.
name|modes
operator|=
name|MOD_BITS
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
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
name|ntv
operator|.
name|constant
operator|=
name|sys_poll
expr_stmt|;
else|#
directive|else
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
name|clock_jitter
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
name|sys_rootdisp
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
comment|/* 			 * Enable/disable the PPS if requested. 			 */
if|if
condition|(
name|pps_enable
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|pll_status
operator|&
name|STA_PPSTIME
operator|)
condition|)
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
literal|"PPS enabled"
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|status
operator||=
name|STA_PPSTIME
operator||
name|STA_PPSFREQ
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|pll_status
operator|&
name|STA_PPSTIME
condition|)
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
literal|"PPS disabled"
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|status
operator|&=
operator|~
operator|(
name|STA_PPSTIME
operator||
name|STA_PPSFREQ
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|sys_leap
operator|==
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
operator|==
name|LEAP_DELSECOND
condition|)
name|ntv
operator|.
name|status
operator||=
name|STA_DEL
expr_stmt|;
block|}
comment|/* 		 * Pass the stuff to the kernel. If it squeals, turn off 		 * the pps. In any case, fetch the kernel offset, 		 * frequency and jitter. 		 */
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
operator|!
operator|(
name|ntv
operator|.
name|status
operator|&
name|STA_PPSSIGNAL
operator|)
condition|)
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
literal|"PPS no signal"
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
name|clock_offset
operator|=
name|ntv
operator|.
name|offset
operator|/
literal|1e9
expr_stmt|;
else|#
directive|else
comment|/* STA_NANO */
name|clock_offset
operator|=
name|ntv
operator|.
name|offset
operator|/
literal|1e6
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
name|clock_frequency
operator|=
name|FREQTOD
argument_list|(
name|ntv
operator|.
name|freq
argument_list|)
expr_stmt|;
comment|/* 		 * If the kernel PPS is lit, monitor its performance. 		 */
if|if
condition|(
name|ntv
operator|.
name|status
operator|&
name|STA_PPSTIME
condition|)
block|{
ifdef|#
directive|ifdef
name|STA_NANO
name|clock_jitter
operator|=
name|ntv
operator|.
name|jitter
operator|/
literal|1e9
expr_stmt|;
else|#
directive|else
comment|/* STA_NANO */
name|clock_jitter
operator|=
name|ntv
operator|.
name|jitter
operator|/
literal|1e6
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
block|}
if|#
directive|if
name|defined
argument_list|(
name|STA_NANO
argument_list|)
operator|&&
name|NTP_API
operator|==
literal|4
comment|/* 		 * If the TAI changes, update the kernel TAI. 		 */
if|if
condition|(
name|loop_tai
operator|!=
name|sys_tai
condition|)
block|{
name|loop_tai
operator|=
name|sys_tai
expr_stmt|;
name|ntv
operator|.
name|modes
operator|=
name|MOD_TAI
expr_stmt|;
name|ntv
operator|.
name|constant
operator|=
name|sys_tai
expr_stmt|;
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* STA_NANO */
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
comment|/* 	 * Clamp the frequency within the tolerance range and calculate 	 * the frequency difference since the last update. 	 */
if|if
condition|(
name|fabs
argument_list|(
name|clock_frequency
argument_list|)
operator|>
name|NTP_MAXFREQ
condition|)
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"frequency error %.0f PPM exceeds tolerance %.0f PPM"
argument_list|,
name|clock_frequency
operator|*
literal|1e6
argument_list|,
name|NTP_MAXFREQ
operator|*
literal|1e6
argument_list|)
expr_stmt|;
name|dtemp
operator|=
name|SQUARE
argument_list|(
name|clock_frequency
operator|-
name|drift_comp
argument_list|)
expr_stmt|;
if|if
condition|(
name|clock_frequency
operator|>
name|NTP_MAXFREQ
condition|)
name|drift_comp
operator|=
name|NTP_MAXFREQ
expr_stmt|;
elseif|else
if|if
condition|(
name|clock_frequency
operator|<
operator|-
name|NTP_MAXFREQ
condition|)
name|drift_comp
operator|=
operator|-
name|NTP_MAXFREQ
expr_stmt|;
else|else
name|drift_comp
operator|=
name|clock_frequency
expr_stmt|;
comment|/* 	 * Calculate the wander as the exponentially weighted RMS 	 * frequency differences. Record the change for the frequency 	 * file update. 	 */
name|etemp
operator|=
name|SQUARE
argument_list|(
name|clock_stability
argument_list|)
expr_stmt|;
name|clock_stability
operator|=
name|SQRT
argument_list|(
name|etemp
operator|+
operator|(
name|dtemp
operator|-
name|etemp
operator|)
operator|/
name|CLOCK_AVG
argument_list|)
expr_stmt|;
name|drift_file_sw
operator|=
name|TRUE
expr_stmt|;
comment|/* 	 * Here we adjust the timeconstan by comparing the current 	 * offset with the clock jitter. If the offset is less than the 	 * clock jitter times a constant, then the averaging interval is 	 * increased, otherwise it is decreased. A bit of hysteresis 	 * helps calm the dance. Works best using burst mode. 	 */
if|if
condition|(
name|fabs
argument_list|(
name|clock_offset
argument_list|)
operator|<
name|CLOCK_PGATE
operator|*
name|clock_jitter
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
comment|/* 	 * If the time constant has changed, update the poll variables. 	 */
if|if
condition|(
name|osys_poll
operator|!=
name|sys_poll
condition|)
name|poll_update
argument_list|(
name|peer
argument_list|,
name|sys_poll
argument_list|)
expr_stmt|;
comment|/* 	 * Yibbidy, yibbbidy, yibbidy; that'h all folks. 	 */
name|record_loop_stats
argument_list|(
name|clock_offset
argument_list|,
name|drift_comp
argument_list|,
name|clock_jitter
argument_list|,
name|clock_stability
argument_list|,
name|sys_poll
argument_list|)
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
literal|"local_clock: offset %.9f jit %.9f freq %.3f stab %.3f poll %d\n"
argument_list|,
name|clock_offset
argument_list|,
name|clock_jitter
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
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
return|return
operator|(
name|rval
operator|)
return|;
endif|#
directive|endif
comment|/* LOCKCLOCK */
block|}
end_function

begin_comment
comment|/*  * adj_host_clock - Called once every second to update the local clock.  *  * LOCKCLOCK: The only thing this routine does is increment the  * sys_rootdisp variable.  */
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
comment|/* 	 * Update the dispersion since the last update. In contrast to 	 * NTPv3, NTPv4 does not declare unsynchronized after one day, 	 * since the dispersion check serves this function. Also, 	 * since the poll interval can exceed one day, the old test 	 * would be counterproductive. 	 */
name|sys_rootdisp
operator|+=
name|clock_phi
expr_stmt|;
ifndef|#
directive|ifndef
name|LOCKCLOCK
comment|/* 	 * If clock discipline is disabled or if the kernel is enabled, 	 * get out of Dodge quick. 	 */
if|if
condition|(
operator|!
name|ntp_enable
operator|||
name|mode_ntpdate
operator|||
operator|(
name|pll_control
operator|&&
name|kern_enable
operator|)
condition|)
return|return;
comment|/* 	 * Implement the phase and frequency adjustments. The gain 	 * factor (denominator) increases with poll interval, so is 	 * dominated by the FLL above the Allan intercept.  	 */
name|adjustment
operator|=
name|clock_offset
operator|/
operator|(
name|CLOCK_PLL
operator|*
name|ULOGTOD
argument_list|(
name|sys_poll
argument_list|)
operator|)
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
endif|#
directive|endif
comment|/* LOCKCLOCK */
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
parameter_list|,
comment|/* new state */
name|double
name|offset
comment|/* new offset */
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"local_clock: mu %lu state %d poll %d count %d\n"
argument_list|,
name|current_time
operator|-
name|clock_epoch
argument_list|,
name|trans
argument_list|,
name|sys_poll
argument_list|,
name|tc_counter
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|trans
operator|!=
name|state
operator|&&
name|trans
operator|!=
name|EVNT_FSET
condition|)
name|report_event
argument_list|(
name|trans
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|state
operator|=
name|trans
expr_stmt|;
name|last_offset
operator|=
name|clock_offset
operator|=
name|offset
expr_stmt|;
name|clock_epoch
operator|=
name|current_time
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * calc_freq - calculate frequency directly  *  * This is very carefully done. When the offset is first computed at the  * first update, a residual frequency component results. Subsequently,  * updates are suppresed until the end of the measurement interval while  * the offset is amortized. At the end of the interval the frequency is  * calculated from the current offset, residual offset, length of the  * interval and residual frequency component. At the same time the  * frequenchy file is armed for update at the next hourly stats.  */
end_comment

begin_function
specifier|static
name|double
name|direct_freq
parameter_list|(
name|double
name|fp_offset
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|KERNEL_PLL
comment|/* 	 * If the kernel is enabled, we need the residual offset to 	 * calculate the frequency correction. 	 */
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
name|memset
argument_list|(
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|STA_NANO
name|clock_offset
operator|=
name|ntv
operator|.
name|offset
operator|/
literal|1e9
expr_stmt|;
else|#
directive|else
comment|/* STA_NANO */
name|clock_offset
operator|=
name|ntv
operator|.
name|offset
operator|/
literal|1e6
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
name|drift_comp
operator|=
name|FREQTOD
argument_list|(
name|ntv
operator|.
name|freq
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
name|set_freq
argument_list|(
operator|(
name|fp_offset
operator|-
name|clock_offset
operator|)
operator|/
operator|(
name|current_time
operator|-
name|clock_epoch
operator|)
operator|+
name|drift_comp
argument_list|)
expr_stmt|;
name|wander_resid
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|drift_comp
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * set_freq - set clock frequency  */
end_comment

begin_function
specifier|static
name|void
name|set_freq
parameter_list|(
name|double
name|freq
comment|/* frequency update */
parameter_list|)
block|{
name|char
name|tbuf
index|[
literal|80
index|]
decl_stmt|;
name|drift_comp
operator|=
name|freq
expr_stmt|;
ifdef|#
directive|ifdef
name|KERNEL_PLL
comment|/* 	 * If the kernel is enabled, update the kernel frequency. 	 */
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
name|memset
argument_list|(
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|modes
operator|=
name|MOD_FREQUENCY
expr_stmt|;
name|ntv
operator|.
name|freq
operator|=
name|DTOFREQ
argument_list|(
name|drift_comp
argument_list|)
expr_stmt|;
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"kernel %.3f PPM"
argument_list|,
name|drift_comp
operator|*
literal|1e6
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_FSET
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"ntpd %.3f PPM"
argument_list|,
name|drift_comp
operator|*
literal|1e6
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_FSET
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* KERNEL_PLL */
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"ntpd %.3f PPM"
argument_list|,
name|drift_comp
operator|*
literal|1e6
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_FSET
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* KERNEL_PLL */
block|}
end_function

begin_comment
comment|/*  * huff-n'-puff filter  */
end_comment

begin_function
name|void
name|huffpuff
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|sys_huffpuff
operator|==
name|NULL
condition|)
return|return;
name|sys_huffptr
operator|=
operator|(
name|sys_huffptr
operator|+
literal|1
operator|)
operator|%
name|sys_hufflen
expr_stmt|;
name|sys_huffpuff
index|[
name|sys_huffptr
index|]
operator|=
literal|1e9
expr_stmt|;
name|sys_mindly
operator|=
literal|1e9
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|sys_hufflen
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|sys_huffpuff
index|[
name|i
index|]
operator|<
name|sys_mindly
condition|)
name|sys_mindly
operator|=
name|sys_huffpuff
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * loop_config - configure the loop filter  *  * LOCKCLOCK: The LOOP_DRIFTINIT and LOOP_DRIFTCOMP cases are no-ops.  */
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
name|int
name|i
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"loop_config: item %d freq %f\n"
argument_list|,
name|item
argument_list|,
name|freq
argument_list|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
name|item
condition|)
block|{
comment|/* 	 * We first assume the kernel supports the ntp_adjtime() 	 * syscall. If that syscall works, initialize the kernel time 	 * variables. Otherwise, continue leaving no harm behind. 	 */
case|case
name|LOOP_DRIFTINIT
case|:
ifndef|#
directive|ifndef
name|LOCKCLOCK
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|mode_ntpdate
condition|)
break|break;
name|pll_control
operator|=
literal|1
expr_stmt|;
name|memset
argument_list|(
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|modes
operator|=
name|MOD_BITS
expr_stmt|;
name|ntv
operator|.
name|status
operator|=
name|STA_PLL
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
name|constant
operator|=
name|sys_poll
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGSYS
comment|/* 		 * Use sigsetjmp() to save state and then call 		 * ntp_adjtime(); if it fails, then siglongjmp() is used 		 * to return control 		 */
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
block|}
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
block|}
else|#
directive|else
comment|/* SIGSYS */
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGSYS */
comment|/* 		 * Save the result status and light up an external clock 		 * if available. 		 */
name|pll_status
operator|=
name|ntv
operator|.
name|status
expr_stmt|;
if|if
condition|(
name|pll_control
condition|)
block|{
ifdef|#
directive|ifdef
name|STA_NANO
if|if
condition|(
name|pll_status
operator|&
name|STA_CLK
condition|)
name|ext_enable
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* STA_NANO */
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
literal|"kernel time sync enabled"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
endif|#
directive|endif
comment|/* LOCKCLOCK */
break|break;
comment|/* 	 * Initialize the frequency. If the frequency file is missing or 	 * broken, set the initial frequency to zero and set the state 	 * to NSET. Otherwise, set the initial frequency to the given 	 * value and the state to FSET. 	 */
case|case
name|LOOP_DRIFTCOMP
case|:
ifndef|#
directive|ifndef
name|LOCKCLOCK
if|if
condition|(
name|freq
operator|>
name|NTP_MAXFREQ
operator|||
name|freq
operator|<
operator|-
name|NTP_MAXFREQ
condition|)
block|{
name|set_freq
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|EVNT_NSET
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|set_freq
argument_list|(
name|freq
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|EVNT_FSET
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* LOCKCLOCK */
break|break;
comment|/* 	 * Disable the kernel at shutdown. The microkernel just abandons 	 * ship. The nanokernel carefully cleans up so applications can 	 * see this. Note the last programmed offset and frequency are 	 * left in place. 	 */
case|case
name|LOOP_KERN_CLEAR
case|:
ifndef|#
directive|ifndef
name|LOCKCLOCK
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
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
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|modes
operator|=
name|MOD_STATUS
expr_stmt|;
name|ntv
operator|.
name|status
operator|=
name|STA_UNSYNC
expr_stmt|;
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
literal|"kernel time sync disabledx"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
endif|#
directive|endif
comment|/* LOCKCLOCK */
break|break;
comment|/* 	 * Tinker command variables for Ulrich Windl. Very dangerous. 	 */
case|case
name|LOOP_ALLAN
case|:
comment|/* Allan intercept (log2) (allan) */
name|allan_xpt
operator|=
operator|(
name|u_char
operator|)
name|freq
expr_stmt|;
break|break;
case|case
name|LOOP_CODEC
case|:
comment|/* audio codec frequency (codec) */
name|clock_codec
operator|=
name|freq
operator|/
literal|1e6
expr_stmt|;
break|break;
case|case
name|LOOP_PHI
case|:
comment|/* dispersion threshold (dispersion) */
name|clock_phi
operator|=
name|freq
operator|/
literal|1e6
expr_stmt|;
break|break;
case|case
name|LOOP_FREQ
case|:
comment|/* initial frequency (freq) */
name|set_freq
argument_list|(
name|freq
operator|/
literal|1e6
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|EVNT_FSET
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOOP_HUFFPUFF
case|:
comment|/* huff-n'-puff length (huffpuff) */
if|if
condition|(
name|freq
operator|<
name|HUFFPUFF
condition|)
name|freq
operator|=
name|HUFFPUFF
expr_stmt|;
name|sys_hufflen
operator|=
call|(
name|int
call|)
argument_list|(
name|freq
operator|/
name|HUFFPUFF
argument_list|)
expr_stmt|;
name|sys_huffpuff
operator|=
operator|(
name|double
operator|*
operator|)
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
operator|*
name|sys_hufflen
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|sys_hufflen
condition|;
name|i
operator|++
control|)
name|sys_huffpuff
index|[
name|i
index|]
operator|=
literal|1e9
expr_stmt|;
name|sys_mindly
operator|=
literal|1e9
expr_stmt|;
break|break;
case|case
name|LOOP_PANIC
case|:
comment|/* panic threshold (panic) */
name|clock_panic
operator|=
name|freq
expr_stmt|;
break|break;
case|case
name|LOOP_MAX
case|:
comment|/* step threshold (step) */
name|clock_max
operator|=
name|freq
expr_stmt|;
if|if
condition|(
name|clock_max
operator|==
literal|0
operator|||
name|clock_max
operator|>
literal|0.5
condition|)
name|kern_enable
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|LOOP_MINSTEP
case|:
comment|/* stepout threshold (stepout) */
name|clock_minstep
operator|=
name|freq
expr_stmt|;
break|break;
case|case
name|LOOP_LEAP
case|:
comment|/* not used */
default|default:
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"loop_config: unsupported option %d"
argument_list|,
name|item
argument_list|)
expr_stmt|;
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

