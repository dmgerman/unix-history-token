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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SNPRINTB
end_ifdef

begin_include
include|#
directive|include
file|<util.h>
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
file|<limits.h>
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
value|300.
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
name|CLOCK_FLOOR
value|.0005
end_define

begin_comment
comment|/* startup offset floor (s) */
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
name|clock_max_back
init|=
name|CLOCK_MAX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* step threshold */
end_comment

begin_decl_stmt
name|double
name|clock_max_fwd
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
specifier|static
name|double
name|init_drift_comp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial frequency (PPM) */
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

begin_decl_stmt
specifier|static
name|int
name|loop_started
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE after LOOP_DRIFTINIT */
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

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAX_PATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
name|relative_path
index|[
name|PATH_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* relative path per recursive make */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|this_file
init|=
name|NULL
decl_stmt|;
end_decl_stmt

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

begin_function_decl
specifier|static
name|void
name|start_kern_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|stop_kern_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|TRUE
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
name|TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel support enabled */
end_comment

begin_decl_stmt
name|int
name|hardpps_enable
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
name|kernel_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from ntp_adjtime */
end_comment

begin_decl_stmt
name|int
name|force_step_once
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* always step time once at startup (-G) */
end_comment

begin_decl_stmt
name|int
name|mode_ntpdate
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit on first clock set (-q) */
end_comment

begin_decl_stmt
name|int
name|freq_cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial frequency clamp */
end_comment

begin_decl_stmt
name|int
name|freq_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial set frequency switch */
end_comment

begin_comment
comment|/*  * Clock state machine variables  */
end_comment

begin_decl_stmt
name|int
name|state
init|=
literal|0
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

begin_function
specifier|static
name|void
name|sync_status
parameter_list|(
specifier|const
name|char
modifier|*
name|what
parameter_list|,
name|int
name|ostatus
parameter_list|,
name|int
name|nstatus
parameter_list|)
block|{
name|char
name|obuf
index|[
literal|256
index|]
decl_stmt|,
name|nbuf
index|[
literal|256
index|]
decl_stmt|,
name|tbuf
index|[
literal|1024
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|USE_SNPRINTB
argument_list|)
operator|&&
name|defined
argument_list|(
name|STA_FMT
argument_list|)
name|snprintb
argument_list|(
name|obuf
argument_list|,
sizeof|sizeof
argument_list|(
name|obuf
argument_list|)
argument_list|,
name|STA_FMT
argument_list|,
name|ostatus
argument_list|)
expr_stmt|;
name|snprintb
argument_list|(
name|nbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|nbuf
argument_list|)
argument_list|,
name|STA_FMT
argument_list|,
name|nstatus
argument_list|)
expr_stmt|;
else|#
directive|else
name|snprintf
argument_list|(
name|obuf
argument_list|,
sizeof|sizeof
argument_list|(
name|obuf
argument_list|)
argument_list|,
literal|"%04x"
argument_list|,
name|ostatus
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|nbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|nbuf
argument_list|)
argument_list|,
literal|"%04x"
argument_list|,
name|nstatus
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"%s status: %s -> %s"
argument_list|,
name|what
argument_list|,
name|obuf
argument_list|,
name|nbuf
argument_list|)
expr_stmt|;
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * file_name - return pointer to non-relative portion of this C file pathname  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|file_name
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|this_file
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|relative_path
argument_list|,
name|__FILE__
argument_list|,
name|PATH_MAX
argument_list|)
expr_stmt|;
for|for
control|(
name|this_file
operator|=
name|relative_path
init|;
operator|*
name|this_file
operator|&&
operator|!
name|isalnum
argument_list|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|this_file
argument_list|)
condition|;
name|this_file
operator|++
control|)
empty_stmt|;
block|}
return|return
name|this_file
return|;
block|}
end_function

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
name|freq_cnt
operator|=
operator|(
name|int
operator|)
name|clock_minstep
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_comment
comment|/*  * ntp_adjtime_error_handler - process errors from ntp_adjtime  */
end_comment

begin_function
specifier|static
name|void
name|ntp_adjtime_error_handler
parameter_list|(
specifier|const
name|char
modifier|*
name|caller
parameter_list|,
comment|/* name of calling function */
name|struct
name|timex
modifier|*
name|ptimex
parameter_list|,
comment|/* pointer to struct timex */
name|int
name|ret
parameter_list|,
comment|/* return value from ntp_adjtime */
name|int
name|saved_errno
parameter_list|,
comment|/* value of errno when ntp_adjtime returned */
name|int
name|pps_call
parameter_list|,
comment|/* ntp_adjtime call was PPS-related */
name|int
name|tai_call
parameter_list|,
comment|/* ntp_adjtime call was TAI-related */
name|int
name|line
comment|/* line number of ntp_adjtime call */
parameter_list|)
block|{
name|char
name|des
index|[
literal|1024
index|]
init|=
literal|""
decl_stmt|;
comment|/* Decoded Error Status */
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
operator|-
literal|1
case|:
switch|switch
condition|(
name|saved_errno
condition|)
block|{
case|case
name|EFAULT
case|:
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"%s: %s line %d: invalid struct timex pointer: 0x%lx"
argument_list|,
name|caller
argument_list|,
name|file_name
argument_list|()
argument_list|,
name|line
argument_list|,
call|(
name|long
call|)
argument_list|(
operator|(
name|void
operator|*
operator|)
name|ptimex
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EINVAL
case|:
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"%s: %s line %d: invalid struct timex \"constant\" element value: %ld"
argument_list|,
name|caller
argument_list|,
name|file_name
argument_list|()
argument_list|,
name|line
argument_list|,
call|(
name|long
call|)
argument_list|(
name|ptimex
operator|->
name|constant
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EPERM
case|:
if|if
condition|(
name|tai_call
condition|)
block|{
name|errno
operator|=
name|saved_errno
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"%s: ntp_adjtime(TAI) failed: %m"
argument_list|,
name|caller
argument_list|)
expr_stmt|;
block|}
name|errno
operator|=
name|saved_errno
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"%s: %s line %d: ntp_adjtime: %m"
argument_list|,
name|caller
argument_list|,
name|file_name
argument_list|()
argument_list|,
name|line
argument_list|)
expr_stmt|;
break|break;
default|default:
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"%s: %s line %d: unhandled errno value %d after failed ntp_adjtime call"
argument_list|,
name|caller
argument_list|,
name|file_name
argument_list|()
argument_list|,
name|line
argument_list|,
name|saved_errno
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
ifdef|#
directive|ifdef
name|TIME_OK
case|case
name|TIME_OK
case|:
comment|/* 0: synchronized, no leap second warning */
comment|/* msyslog(LOG_INFO, "kernel reports time is synchronized normally"); */
break|break;
else|#
directive|else
warning|#
directive|warning
warning|TIME_OK is not defined
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIME_INS
case|case
name|TIME_INS
case|:
comment|/* 1: positive leap second warning */
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"kernel reports leap second insertion scheduled"
argument_list|)
expr_stmt|;
break|break;
else|#
directive|else
warning|#
directive|warning
warning|TIME_INS is not defined
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIME_DEL
case|case
name|TIME_DEL
case|:
comment|/* 2: negative leap second warning */
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"kernel reports leap second deletion scheduled"
argument_list|)
expr_stmt|;
break|break;
else|#
directive|else
warning|#
directive|warning
warning|TIME_DEL is not defined
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIME_OOP
case|case
name|TIME_OOP
case|:
comment|/* 3: leap second in progress */
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"kernel reports leap second in progress"
argument_list|)
expr_stmt|;
break|break;
else|#
directive|else
warning|#
directive|warning
warning|TIME_OOP is not defined
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIME_WAIT
case|case
name|TIME_WAIT
case|:
comment|/* 4: leap second has occured */
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"kernel reports leap second has occurred"
argument_list|)
expr_stmt|;
break|break;
else|#
directive|else
warning|#
directive|warning
warning|TIME_WAIT is not defined
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIME_ERROR
if|#
directive|if
literal|0
block|from the reference implementation of ntp_gettime():
comment|// Hardware or software error
block|if ((time_status& (STA_UNSYNC | STA_CLOCKERR))
comment|/*          * PPS signal lost when either time or frequency synchronization          * requested          */
block||| (time_status& (STA_PPSFREQ | STA_PPSTIME)&& !(time_status& STA_PPSSIGNAL))
comment|/*          * PPS jitter exceeded when time synchronization requested          */
block||| (time_status& STA_PPSTIME&&             time_status& STA_PPSJITTER)
comment|/*          * PPS wander exceeded or calibration error when frequency          * synchronization requested          */
block||| (time_status& STA_PPSFREQ&&             time_status& (STA_PPSWANDER | STA_PPSERROR)))                 return (TIME_ERROR);  or, from ntp_adjtime():  	if (  (time_status& (STA_UNSYNC | STA_CLOCKERR)) 	    || (time_status& (STA_PPSFREQ | STA_PPSTIME)&& !(time_status& STA_PPSSIGNAL))  	    || (time_status& STA_PPSTIME&& time_status& STA_PPSJITTER) 	    || (time_status& STA_PPSFREQ&& time_status& (STA_PPSWANDER | STA_PPSERROR)) 	   ) 		return (TIME_ERROR);
endif|#
directive|endif
case|case
name|TIME_ERROR
case|:
comment|/* 5: unsynchronized, or loss of synchronization */
comment|/* error (see status word) */
if|if
condition|(
name|ptimex
operator|->
name|status
operator|&
name|STA_UNSYNC
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sClock Unsynchronized"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptimex
operator|->
name|status
operator|&
name|STA_CLOCKERR
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sClock Error"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSSIGNAL
operator|)
operator|&&
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSFREQ
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sPPS Frequency Sync wanted but no PPS"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSSIGNAL
operator|)
operator|&&
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSTIME
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sPPS Time Sync wanted but no PPS signal"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSTIME
operator|&&
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSJITTER
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sPPS Time Sync wanted but PPS Jitter exceeded"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSFREQ
operator|&&
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSWANDER
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sPPS Frequency Sync wanted but PPS Wander exceeded"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSFREQ
operator|&&
name|ptimex
operator|->
name|status
operator|&
name|STA_PPSERROR
condition|)
name|snprintf
argument_list|(
name|des
argument_list|,
sizeof|sizeof
argument_list|(
name|des
argument_list|)
argument_list|,
literal|"%s%sPPS Frequency Sync wanted but Calibration error detected"
argument_list|,
name|des
argument_list|,
operator|(
operator|*
name|des
operator|)
condition|?
literal|"; "
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|pps_call
operator|&&
operator|!
operator|(
name|ptimex
operator|->
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
literal|"no PPS signal"
argument_list|)
expr_stmt|;
name|DPRINTF
argument_list|(
literal|1
argument_list|,
operator|(
literal|"kernel loop status %#x (%s)\n"
operator|,
name|ptimex
operator|->
name|status
operator|,
name|des
operator|)
argument_list|)
expr_stmt|;
comment|/* 		 * This code may be returned when ntp_adjtime() has just 		 * been called for the first time, quite a while after 		 * startup, when ntpd just starts to discipline the kernel 		 * time. In this case the occurrence of this message 		 * can be pretty confusing. 		 * 		 * HMS: How about a message when we begin kernel processing: 		 *    Determining kernel clock state... 		 * so an initial TIME_ERROR message is less confising, 		 * or skipping the first message (ugh), 		 * or ??? 		 * msyslog(LOG_INFO, "kernel reports time synchronization lost"); 		 */
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"kernel reports TIME_ERROR: %#x: %s"
argument_list|,
name|ptimex
operator|->
name|status
argument_list|,
name|des
argument_list|)
expr_stmt|;
break|break;
else|#
directive|else
warning|#
directive|warning
warning|TIME_ERROR is not defined
endif|#
directive|endif
default|default:
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"%s: %s line %d: unhandled return value %d from ntp_adjtime() in %s at line %d"
argument_list|,
name|caller
argument_list|,
name|file_name
argument_list|()
argument_list|,
name|line
argument_list|,
name|ret
argument_list|,
name|__func__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
break|break;
block|}
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|ntp_adj_ret
decl_stmt|;
comment|/* returned by ntp_adjtime */
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
operator|(
name|void
operator|)
name|ntp_adj_ret
expr_stmt|;
comment|/* not always used below... */
comment|/* 	 * If the loop is opened or the NIST LOCKCLOCK is in use, 	 * monitor and record the offsets anyway in order to determine 	 * the open-loop response and then go home. 	 */
ifndef|#
directive|ifndef
name|LOCKCLOCK
if|if
condition|(
operator|!
name|ntp_enable
condition|)
endif|#
directive|endif
comment|/* not LOCKCLOCK */
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
ifndef|#
directive|ifndef
name|LOCKCLOCK
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
name|allow_panic
operator|=
name|FALSE
expr_stmt|;
comment|/* 	 * This section simulates ntpdate. If the offset exceeds the 	 * step threshold (128 ms), step the clock to that time and 	 * exit. Otherwise, slew the clock to that time and exit. Note 	 * that the slew will persist and eventually complete beyond the 	 * life of this program. Note that while ntpdate is active, the 	 * terminal does not detach, so the termination message prints 	 * directly to the terminal. 	 */
if|if
condition|(
name|mode_ntpdate
condition|)
block|{
if|if
condition|(
operator|(
name|fp_offset
operator|>
name|clock_max_fwd
operator|&&
name|clock_max_fwd
operator|>
literal|0
operator|)
operator|||
operator|(
operator|-
name|fp_offset
operator|>
name|clock_max_back
operator|&&
name|clock_max_back
operator|>
literal|0
operator|)
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
name|DPRINTF
argument_list|(
literal|1
argument_list|,
operator|(
literal|"local_clock: size %d mindly %.6f huffpuff %.6f\n"
operator|,
name|sys_hufflen
operator|,
name|sys_mindly
operator|,
name|dtemp
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Clock state machine transition function which defines how the 	 * system reacts to large phase and frequency excursion. There 	 * are two main regimes: when the offset exceeds the step 	 * threshold (128 ms) and when it does not. Under certain 	 * conditions updates are suspended until the stepout theshold 	 * (900 s) is exceeded. See the documentation on how these 	 * thresholds interact with commands and command line options. 	 * 	 * Note the kernel is disabled if step is disabled or greater 	 * than 0.5 s or in ntpdate mode. 	 */
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
operator|(
name|fp_offset
operator|>
name|clock_max_fwd
operator|&&
name|clock_max_fwd
operator|>
literal|0
operator|)
operator|||
operator|(
operator|-
name|fp_offset
operator|>
name|clock_max_back
operator|&&
name|clock_max_back
operator|>
literal|0
operator|)
operator|||
name|force_step_once
condition|)
block|{
if|if
condition|(
name|force_step_once
condition|)
block|{
name|force_step_once
operator|=
name|FALSE
expr_stmt|;
comment|/* we want this only once after startup */
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Doing intital time step"
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|state
condition|)
block|{
comment|/* 		 * In SYNC state we ignore the first outlier and switch 		 * to SPIK state. 		 */
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
comment|/* 		 * In FREQ state we ignore outliers and inlyers. At the 		 * first outlier after the stepout threshold, compute 		 * the apparent frequency correction and step the phase. 		 */
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
comment|/* fall through to EVNT_SPIK */
comment|/* 		 * In SPIK state we ignore succeeding outliers until 		 * either an inlyer is found or the stepout threshold is 		 * exceeded. 		 */
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
comment|/* 		 * The offset is less than the step threshold. Calculate 		 * the jitter as the exponentially weighted offset 		 * differences. 		 */
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
name|adj_systime
argument_list|(
name|fp_offset
argument_list|)
expr_stmt|;
name|rstclock
argument_list|(
name|EVNT_FREQ
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
break|break;
comment|/* 		 * In FREQ state ignore updates until the stepout 		 * threshold. After that, compute the new frequency, but 		 * do not adjust the frequency until the holdoff counter 		 * decrements to zero. 		 */
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
comment|/* fall through */
comment|/* 		 * We get here by default in FSET, SPIK and SYNC states. 		 * Here compute the frequency update due to PLL and FLL 		 * contributions. Note, we avoid frequency discipline at 		 * startup until the initial transient has subsided. 		 */
default|default:
if|if
condition|(
name|freq_cnt
operator|==
literal|0
condition|)
block|{
comment|/* 				 * The FLL and PLL frequency gain constants 				 * depend on the time constant and Allan 				 * intercept. The PLL is always used, but 				 * becomes ineffective above the Allan intercept 				 * where the FLL becomes effective. 				 */
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
comment|/* 				 * The PLL frequency gain (numerator) depends on 				 * the minimum of the update interval and Allan 				 * intercept. This reduces the PLL gain when the 				 * FLL becomes effective. 				 */
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
block|}
name|rstclock
argument_list|(
name|EVNT_SYNC
argument_list|,
name|fp_offset
argument_list|)
expr_stmt|;
if|if
condition|(
name|fabs
argument_list|(
name|fp_offset
argument_list|)
operator|<
name|CLOCK_FLOOR
condition|)
name|freq_cnt
operator|=
literal|0
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
operator|&&
name|freq_cnt
operator|==
literal|0
condition|)
block|{
comment|/* 		 * We initialize the structure for the ntp_adjtime() 		 * system call. We have to convert everything to 		 * microseconds or nanoseconds first. Do not update the 		 * system variables if the ext_enable flag is set. In 		 * this case, the external clock driver will update the 		 * variables, which will be read later by the local 		 * clock driver. Afterwards, remember the time and 		 * frequency offsets for jitter and stability values and 		 * to update the frequency file. 		 */
name|ZERO
argument_list|(
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
if|if
condition|(
name|ntv
operator|.
name|constant
operator|<
literal|0
condition|)
name|ntv
operator|.
name|constant
operator|=
literal|0
expr_stmt|;
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
name|hardpps_enable
condition|)
block|{
name|ntv
operator|.
name|status
operator||=
operator|(
name|STA_PPSTIME
operator||
name|STA_PPSFREQ
operator|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|pll_status
operator|&
name|STA_PPSTIME
operator|)
condition|)
name|sync_status
argument_list|(
literal|"PPS enabled"
argument_list|,
name|pll_status
argument_list|,
name|ntv
operator|.
name|status
argument_list|)
expr_stmt|;
block|}
else|else
block|{
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
if|if
condition|(
name|pll_status
operator|&
name|STA_PPSTIME
condition|)
name|sync_status
argument_list|(
literal|"PPS disabled"
argument_list|,
name|pll_status
argument_list|,
name|ntv
operator|.
name|status
argument_list|)
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
name|ntp_adj_ret
operator|=
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
expr_stmt|;
comment|/* 		 * A squeal is a return status< 0, or a state change. 		 */
if|if
condition|(
operator|(
literal|0
operator|>
name|ntp_adj_ret
operator|)
operator|||
operator|(
name|ntp_adj_ret
operator|!=
name|kernel_status
operator|)
condition|)
block|{
name|kernel_status
operator|=
name|ntp_adj_ret
expr_stmt|;
name|ntp_adjtime_error_handler
argument_list|(
name|__func__
argument_list|,
operator|&
name|ntv
argument_list|,
name|ntp_adj_ret
argument_list|,
name|errno
argument_list|,
name|hardpps_enable
argument_list|,
literal|0
argument_list|,
name|__LINE__
operator|-
literal|1
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
if|if
condition|(
operator|(
name|ntp_adj_ret
operator|=
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|ntp_adjtime_error_handler
argument_list|(
name|__func__
argument_list|,
operator|&
name|ntv
argument_list|,
name|ntp_adj_ret
argument_list|,
name|errno
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|__LINE__
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
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
comment|/* 	 * Here we adjust the time constant by comparing the current 	 * offset with the clock jitter. If the offset is less than the 	 * clock jitter times a constant, then the averaging interval is 	 * increased, otherwise it is decreased. A bit of hysteresis 	 * helps calm the dance. Works best using burst mode. Don't 	 * fiddle with the poll during the startup clamp period. 	 */
if|if
condition|(
name|freq_cnt
operator|>
literal|0
condition|)
block|{
name|tc_counter
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
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
name|DPRINTF
argument_list|(
literal|1
argument_list|,
operator|(
literal|"local_clock: offset %.9f jit %.9f freq %.3f stab %.3f poll %d\n"
operator|,
name|clock_offset
operator|,
name|clock_jitter
operator|,
name|drift_comp
operator|*
literal|1e6
operator|,
name|clock_stability
operator|*
literal|1e6
operator|,
name|sys_poll
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
endif|#
directive|endif
comment|/* not LOCKCLOCK */
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
name|offset_adj
decl_stmt|;
name|double
name|freq_adj
decl_stmt|;
comment|/* 	 * Update the dispersion since the last update. In contrast to 	 * NTPv3, NTPv4 does not declare unsynchronized after one day, 	 * since the dispersion check serves this function. Also, 	 * since the poll interval can exceed one day, the old test 	 * would be counterproductive. During the startup clamp period, the 	 * time constant is clamped at 2. 	 */
name|sys_rootdisp
operator|+=
name|clock_phi
expr_stmt|;
ifndef|#
directive|ifndef
name|LOCKCLOCK
if|if
condition|(
operator|!
name|ntp_enable
operator|||
name|mode_ntpdate
condition|)
return|return;
comment|/* 	 * Determine the phase adjustment. The gain factor (denominator) 	 * increases with poll interval, so is dominated by the FLL 	 * above the Allan intercept. Note the reduced time constant at 	 * startup. 	 */
if|if
condition|(
name|state
operator|!=
name|EVNT_SYNC
condition|)
block|{
name|offset_adj
operator|=
literal|0.
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|freq_cnt
operator|>
literal|0
condition|)
block|{
name|offset_adj
operator|=
name|clock_offset
operator|/
operator|(
name|CLOCK_PLL
operator|*
name|ULOGTOD
argument_list|(
literal|1
argument_list|)
operator|)
expr_stmt|;
name|freq_cnt
operator|--
expr_stmt|;
ifdef|#
directive|ifdef
name|KERNEL_PLL
block|}
elseif|else
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
block|{
name|offset_adj
operator|=
literal|0.
expr_stmt|;
endif|#
directive|endif
comment|/* KERNEL_PLL */
block|}
else|else
block|{
name|offset_adj
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
block|}
comment|/* 	 * If the kernel discipline is enabled the frequency correction 	 * drift_comp has already been engaged via ntp_adjtime() in 	 * set_freq().  Otherwise it is a component of the adj_systime() 	 * offset. 	 */
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
name|freq_adj
operator|=
literal|0.
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* KERNEL_PLL */
name|freq_adj
operator|=
name|drift_comp
expr_stmt|;
comment|/* Bound absolute value of total adjustment to NTP_MAXFREQ. */
if|if
condition|(
name|offset_adj
operator|+
name|freq_adj
operator|>
name|NTP_MAXFREQ
condition|)
name|offset_adj
operator|=
name|NTP_MAXFREQ
operator|-
name|freq_adj
expr_stmt|;
elseif|else
if|if
condition|(
name|offset_adj
operator|+
name|freq_adj
operator|<
operator|-
name|NTP_MAXFREQ
condition|)
name|offset_adj
operator|=
operator|-
name|NTP_MAXFREQ
operator|-
name|freq_adj
expr_stmt|;
name|clock_offset
operator|-=
name|offset_adj
expr_stmt|;
comment|/* 	 * Windows port adj_systime() must be called each second, 	 * even if the argument is zero, to ease emulation of 	 * adjtime() using Windows' slew API which controls the rate 	 * but does not automatically stop slewing when an offset 	 * has decayed to zero. 	 */
name|DEBUG_INSIST
argument_list|(
name|enable_panic_check
operator|==
name|TRUE
argument_list|)
expr_stmt|;
name|enable_panic_check
operator|=
name|FALSE
expr_stmt|;
name|adj_systime
argument_list|(
name|offset_adj
operator|+
name|freq_adj
argument_list|)
expr_stmt|;
name|enable_panic_check
operator|=
name|TRUE
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
name|DPRINTF
argument_list|(
literal|2
argument_list|,
operator|(
literal|"rstclock: mu %lu state %d poll %d count %d\n"
operator|,
name|current_time
operator|-
name|clock_epoch
operator|,
name|trans
operator|,
name|sys_poll
operator|,
name|tc_counter
operator|)
argument_list|)
expr_stmt|;
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
name|set_freq
argument_list|(
name|fp_offset
operator|/
operator|(
name|current_time
operator|-
name|clock_epoch
operator|)
argument_list|)
expr_stmt|;
return|return
name|drift_comp
return|;
block|}
end_function

begin_comment
comment|/*  * set_freq - set clock frequency correction  *  * Used to step the frequency correction at startup, possibly again once  * the frequency is measured (that is, transitioning from EVNT_NSET to  * EVNT_FSET), and finally to switch between daemon and kernel loop  * discipline at runtime.  *  * When the kernel loop discipline is available but the daemon loop is  * in use, the kernel frequency correction is disabled (set to 0) to  * ensure drift_comp is applied by only one of the loops.  */
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
specifier|const
name|char
modifier|*
name|loop_desc
decl_stmt|;
name|int
name|ntp_adj_ret
decl_stmt|;
operator|(
name|void
operator|)
name|ntp_adj_ret
expr_stmt|;
comment|/* not always used below... */
name|drift_comp
operator|=
name|freq
expr_stmt|;
name|loop_desc
operator|=
literal|"ntpd"
expr_stmt|;
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|pll_control
condition|)
block|{
name|ZERO
argument_list|(
name|ntv
argument_list|)
expr_stmt|;
name|ntv
operator|.
name|modes
operator|=
name|MOD_FREQUENCY
expr_stmt|;
if|if
condition|(
name|kern_enable
condition|)
block|{
name|loop_desc
operator|=
literal|"kernel"
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
block|}
if|if
condition|(
operator|(
name|ntp_adj_ret
operator|=
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|ntp_adjtime_error_handler
argument_list|(
name|__func__
argument_list|,
operator|&
name|ntv
argument_list|,
name|ntp_adj_ret
argument_list|,
name|errno
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|__LINE__
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* KERNEL_PLL */
name|mprintf_event
argument_list|(
name|EVNT_FSET
argument_list|,
name|NULL
argument_list|,
literal|"%s %.3f PPM"
argument_list|,
name|loop_desc
argument_list|,
name|drift_comp
operator|*
literal|1e6
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_function
specifier|static
name|void
name|start_kern_loop
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|atexit_done
decl_stmt|;
name|int
name|ntp_adj_ret
decl_stmt|;
name|pll_control
operator|=
name|TRUE
expr_stmt|;
name|ZERO
argument_list|(
name|ntv
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
comment|/* why is it that here constant is unconditionally set to sys_poll, whereas elsewhere is is modified depending on nanosecond vs. microsecond kernel? */
ifdef|#
directive|ifdef
name|SIGSYS
comment|/* 	 * Use sigsetjmp() to save state and then call ntp_adjtime(); if 	 * it fails, then pll_trap() will set pll_control FALSE before 	 * returning control using siglogjmp(). 	 */
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
literal|"sigaction() trap SIGSYS: %m"
argument_list|)
expr_stmt|;
name|pll_control
operator|=
name|FALSE
expr_stmt|;
block|}
else|else
block|{
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
block|{
if|if
condition|(
operator|(
name|ntp_adj_ret
operator|=
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|ntp_adjtime_error_handler
argument_list|(
name|__func__
argument_list|,
operator|&
name|ntv
argument_list|,
name|ntp_adj_ret
argument_list|,
name|errno
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|__LINE__
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|sigaction
argument_list|(
name|SIGSYS
argument_list|,
operator|&
name|sigsys
argument_list|,
name|NULL
argument_list|)
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sigaction() restore SIGSYS: %m"
argument_list|)
expr_stmt|;
name|pll_control
operator|=
name|FALSE
expr_stmt|;
block|}
block|}
else|#
directive|else
comment|/* SIGSYS */
if|if
condition|(
operator|(
name|ntp_adj_ret
operator|=
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|ntp_adjtime_error_handler
argument_list|(
name|__func__
argument_list|,
operator|&
name|ntv
argument_list|,
name|ntp_adj_ret
argument_list|,
name|errno
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|__LINE__
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SIGSYS */
comment|/* 	 * Save the result status and light up an external clock 	 * if available. 	 */
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
if|if
condition|(
operator|!
name|atexit_done
condition|)
block|{
name|atexit_done
operator|=
name|TRUE
expr_stmt|;
name|atexit
argument_list|(
operator|&
name|stop_kern_loop
argument_list|)
expr_stmt|;
block|}
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
name|TRUE
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
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_function
specifier|static
name|void
name|stop_kern_loop
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pll_control
operator|&&
name|kern_enable
condition|)
name|report_event
argument_list|(
name|EVNT_KERN
argument_list|,
name|NULL
argument_list|,
literal|"kernel time sync disabled"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

begin_comment
comment|/*  * select_loop() - choose kernel or daemon loop discipline.  */
end_comment

begin_function
name|void
name|select_loop
parameter_list|(
name|int
name|use_kern_loop
parameter_list|)
block|{
if|if
condition|(
name|kern_enable
operator|==
name|use_kern_loop
condition|)
return|return;
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|pll_control
operator|&&
operator|!
name|use_kern_loop
condition|)
name|stop_kern_loop
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|kern_enable
operator|=
name|use_kern_loop
expr_stmt|;
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|pll_control
operator|&&
name|use_kern_loop
condition|)
name|start_kern_loop
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * If this loop selection change occurs after initial startup, 	 * call set_freq() to switch the frequency compensation to or 	 * from the kernel loop. 	 */
ifdef|#
directive|ifdef
name|KERNEL_PLL
if|if
condition|(
name|pll_control
operator|&&
name|loop_started
condition|)
name|set_freq
argument_list|(
name|drift_comp
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * huff-n'-puff filter  */
end_comment

begin_function
name|void
name|huffpuff
parameter_list|(
name|void
parameter_list|)
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
name|double
name|ftemp
decl_stmt|;
name|DPRINTF
argument_list|(
literal|2
argument_list|,
operator|(
literal|"loop_config: item %d freq %f\n"
operator|,
name|item
operator|,
name|freq
operator|)
argument_list|)
expr_stmt|;
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
name|start_kern_loop
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* KERNEL_PLL */
comment|/* 		 * Initialize frequency if given; otherwise, begin frequency 		 * calibration phase. 		 */
name|ftemp
operator|=
name|init_drift_comp
operator|/
literal|1e6
expr_stmt|;
if|if
condition|(
name|ftemp
operator|>
name|NTP_MAXFREQ
condition|)
name|ftemp
operator|=
name|NTP_MAXFREQ
expr_stmt|;
elseif|else
if|if
condition|(
name|ftemp
operator|<
operator|-
name|NTP_MAXFREQ
condition|)
name|ftemp
operator|=
operator|-
name|NTP_MAXFREQ
expr_stmt|;
name|set_freq
argument_list|(
name|ftemp
argument_list|)
expr_stmt|;
if|if
condition|(
name|freq_set
condition|)
name|rstclock
argument_list|(
name|EVNT_FSET
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|rstclock
argument_list|(
name|EVNT_NSET
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|loop_started
operator|=
name|TRUE
expr_stmt|;
endif|#
directive|endif
comment|/* LOCKCLOCK */
break|break;
case|case
name|LOOP_KERN_CLEAR
case|:
if|#
directive|if
literal|0
comment|/* XXX: needs more review, and how can we get here? */
ifndef|#
directive|ifndef
name|LOCKCLOCK
ifdef|#
directive|ifdef
name|KERNEL_PLL
block|if (pll_control&& kern_enable) { 			memset((char *)&ntv, 0, sizeof(ntv)); 			ntv.modes = MOD_STATUS; 			ntv.status = STA_UNSYNC; 			ntp_adjtime(&ntv); 			sync_status("kernel time sync disabled", 				pll_status, 				ntv.status); 		   }
endif|#
directive|endif
comment|/* KERNEL_PLL */
endif|#
directive|endif
comment|/* LOCKCLOCK */
endif|#
directive|endif
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
name|init_drift_comp
operator|=
name|freq
expr_stmt|;
name|freq_set
operator|++
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
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|sys_huffpuff
index|[
literal|0
index|]
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
name|clock_max_fwd
operator|=
name|clock_max_back
operator|=
name|freq
expr_stmt|;
if|if
condition|(
name|freq
operator|==
literal|0
operator|||
name|freq
operator|>
literal|0.5
condition|)
name|select_loop
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOOP_MAX_BACK
case|:
comment|/* step threshold (step) */
name|clock_max_back
operator|=
name|freq
expr_stmt|;
comment|/* 		 * Leave using the kernel discipline code unless both 		 * limits are massive.  This assumes the reason to stop 		 * using it is that it's pointless, not that it goes wrong. 		 */
if|if
condition|(
operator|(
name|clock_max_back
operator|==
literal|0
operator|||
name|clock_max_back
operator|>
literal|0.5
operator|)
operator|||
operator|(
name|clock_max_fwd
operator|==
literal|0
operator|||
name|clock_max_fwd
operator|>
literal|0.5
operator|)
condition|)
name|select_loop
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOOP_MAX_FWD
case|:
comment|/* step threshold (step) */
name|clock_max_fwd
operator|=
name|freq
expr_stmt|;
if|if
condition|(
operator|(
name|clock_max_back
operator|==
literal|0
operator|||
name|clock_max_back
operator|>
literal|0.5
operator|)
operator|||
operator|(
name|clock_max_fwd
operator|==
literal|0
operator|||
name|clock_max_fwd
operator|>
literal|0.5
operator|)
condition|)
name|select_loop
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOOP_MINSTEP
case|:
comment|/* stepout threshold (stepout) */
if|if
condition|(
name|freq
operator|<
name|CLOCK_MINSTEP
condition|)
name|clock_minstep
operator|=
name|CLOCK_MINSTEP
expr_stmt|;
else|else
name|clock_minstep
operator|=
name|freq
expr_stmt|;
break|break;
case|case
name|LOOP_TICK
case|:
comment|/* tick increment (tick) */
name|set_sys_tick_precision
argument_list|(
name|freq
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOOP_LEAP
case|:
comment|/* not used, fall through */
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
name|FALSE
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

