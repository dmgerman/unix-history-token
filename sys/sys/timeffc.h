begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 The University of Melbourne  * All rights reserved.  *  * This software was developed by Julien Ridoux at the University of Melbourne  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIMEFF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIMEFF_H_
end_define

begin_include
include|#
directive|include
file|<sys/_ffcounter.h>
end_include

begin_comment
comment|/*  * Feed-forward clock estimate  * Holds time mark as a ffcounter and conversion to bintime based on current  * timecounter period and offset estimate passed by the synchronization daemon.  * Provides time of last daemon update, clock status and bound on error.  */
end_comment

begin_struct
struct|struct
name|ffclock_estimate
block|{
name|struct
name|bintime
name|update_time
decl_stmt|;
comment|/* Time of last estimates update. */
name|ffcounter
name|update_ffcount
decl_stmt|;
comment|/* Counter value at last update. */
name|ffcounter
name|leapsec_next
decl_stmt|;
comment|/* Counter value of next leap second. */
name|uint64_t
name|period
decl_stmt|;
comment|/* Estimate of counter period. */
name|uint32_t
name|errb_abs
decl_stmt|;
comment|/* Bound on absolute clock error [ns]. */
name|uint32_t
name|errb_rate
decl_stmt|;
comment|/* Bound on counter rate error [ps/s]. */
name|uint32_t
name|status
decl_stmt|;
comment|/* Clock status. */
name|int16_t
name|leapsec_total
decl_stmt|;
comment|/* All leap seconds seen so far. */
name|int8_t
name|leapsec
decl_stmt|;
comment|/* Next leap second (in {-1,0,1}). */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Define the kern.sysclock sysctl tree. */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_sysclock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Define the kern.sysclock.ffclock sysctl tree. */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_sysclock_ffclock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Index into the sysclocks array for obtaining the ASCII name of a particular  * sysclock.  */
end_comment

begin_define
define|#
directive|define
name|SYSCLOCK_FBCK
value|0
end_define

begin_define
define|#
directive|define
name|SYSCLOCK_FFWD
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|sysclock_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Parameters of counter characterisation required by feed-forward algorithms.  */
end_comment

begin_define
define|#
directive|define
name|FFCLOCK_SKM_SCALE
value|1024
end_define

begin_comment
comment|/*  * Feed-forward clock status  */
end_comment

begin_define
define|#
directive|define
name|FFCLOCK_STA_UNSYNC
value|1
end_define

begin_define
define|#
directive|define
name|FFCLOCK_STA_WARMUP
value|2
end_define

begin_comment
comment|/*  * Flags for use by sysclock_snap2bintime() and various ffclock_ functions to  * control how the timecounter hardware is read and how the hardware snapshot is  * converted into absolute time.  * {FB|FF}CLOCK_FAST:	Do not read the hardware counter, instead using the  *			value at last tick. The time returned has a resolution  *			of the kernel tick timer (1/hz [s]).  * FFCLOCK_LERP:	Linear interpolation of ffclock time to guarantee  *			monotonic time.  * FFCLOCK_LEAPSEC:	Include leap seconds.  * {FB|FF}CLOCK_UPTIME:	Time stamp should be relative to system boot, not epoch.  */
end_comment

begin_define
define|#
directive|define
name|FFCLOCK_FAST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FFCLOCK_LERP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FFCLOCK_LEAPSEC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FFCLOCK_UPTIME
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FFCLOCK_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|FBCLOCK_FAST
value|0x00010000
end_define

begin_comment
comment|/* Currently unused. */
end_comment

begin_define
define|#
directive|define
name|FBCLOCK_UPTIME
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FBCLOCK_MASK
value|0xffff0000
end_define

begin_comment
comment|/*  * Feedback clock specific info structure. The feedback clock's estimation of  * clock error is an absolute figure determined by the NTP algorithm. The status  * is determined by the userland daemon.  */
end_comment

begin_struct
struct|struct
name|fbclock_info
block|{
name|struct
name|bintime
name|error
decl_stmt|;
name|struct
name|bintime
name|tick_time
decl_stmt|;
name|uint64_t
name|th_scale
decl_stmt|;
name|int
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Feed-forward clock specific info structure. The feed-forward clock's  * estimation of clock error is an upper bound, which although potentially  * looser than the feedback clock equivalent, is much more reliable. The status  * is determined by the userland daemon.  */
end_comment

begin_struct
struct|struct
name|ffclock_info
block|{
name|struct
name|bintime
name|error
decl_stmt|;
name|struct
name|bintime
name|tick_time
decl_stmt|;
name|struct
name|bintime
name|tick_time_lerp
decl_stmt|;
name|uint64_t
name|period
decl_stmt|;
name|uint64_t
name|period_lerp
decl_stmt|;
name|int
name|leapsec_adjustment
decl_stmt|;
name|int
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Snapshot of system clocks and related information. Holds time read from each  * clock based on a single read of the active hardware timecounter, as well as  * respective clock information such as error estimates and the ffcounter value  * at the time of the read.  */
end_comment

begin_struct
struct|struct
name|sysclock_snap
block|{
name|struct
name|fbclock_info
name|fb_info
decl_stmt|;
name|struct
name|ffclock_info
name|ff_info
decl_stmt|;
name|ffcounter
name|ffcount
decl_stmt|;
name|unsigned
name|int
name|delta
decl_stmt|;
name|int
name|sysclock_active
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Take a snapshot of the system clocks and related information. */
end_comment

begin_function_decl
name|void
name|sysclock_getsnapshot
parameter_list|(
name|struct
name|sysclock_snap
modifier|*
name|clock_snap
parameter_list|,
name|int
name|fast
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a timestamp from the selected system clock into bintime. */
end_comment

begin_function_decl
name|int
name|sysclock_snap2bintime
parameter_list|(
name|struct
name|sysclock_snap
modifier|*
name|cs
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|int
name|whichclock
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Resets feed-forward clock from RTC */
end_comment

begin_function_decl
name|void
name|ffclock_reset_clock
parameter_list|(
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current value of the feed-forward clock counter. Essential to  * measure time interval in counter units. If a fast timecounter is used by the  * system, may also allow fast but accurate timestamping.  */
end_comment

begin_function_decl
name|void
name|ffclock_read_counter
parameter_list|(
name|ffcounter
modifier|*
name|ffcount
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Retrieve feed-forward counter value and time of last kernel tick. This  * accepts the FFCLOCK_LERP flag.  */
end_comment

begin_function_decl
name|void
name|ffclock_last_tick
parameter_list|(
name|ffcounter
modifier|*
name|ffcount
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Low level routines to convert a counter timestamp into absolute time and a  * counter timestamp interval into an interval in seconds. The absolute time  * conversion accepts the FFCLOCK_LERP flag.  */
end_comment

begin_function_decl
name|void
name|ffclock_convert_abs
parameter_list|(
name|ffcounter
name|ffcount
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_convert_diff
parameter_list|(
name|ffcounter
name|ffdelta
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Feed-forward clock routines.  *  * These functions rely on the timecounters and ffclock_estimates stored in  * fftimehands. Note that the error_bound parameter is not the error of the  * clock but an upper bound on the error of the absolute time or time interval  * returned.  *  * ffclock_abstime(): retrieves current time as counter value and convert this  *     timestamp in seconds. The value (in seconds) of the converted timestamp  *     depends on the flags passed: for a given counter value, different  *     conversions are possible. Different clock models can be selected by  *     combining flags (for example (FFCLOCK_LERP|FFCLOCK_UPTIME) produces  *     linearly interpolated uptime).  * ffclock_difftime(): computes a time interval in seconds based on an interval  *     measured in ffcounter units. This should be the preferred way to measure  *     small time intervals very accurately.  */
end_comment

begin_function_decl
name|void
name|ffclock_abstime
parameter_list|(
name|ffcounter
modifier|*
name|ffcount
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|struct
name|bintime
modifier|*
name|error_bound
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_difftime
parameter_list|(
name|ffcounter
name|ffdelta
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|struct
name|bintime
modifier|*
name|error_bound
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wrapper routines to return current absolute time using the feed-forward  * clock. These functions are named after those defined in<sys/time.h>, which  * contains a description of the original ones.  */
end_comment

begin_function_decl
name|void
name|ffclock_bintime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_nanotime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_microtime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_getbintime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_getnanotime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_getmicrotime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_binuptime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_nanouptime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_microuptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_getbinuptime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_getnanouptime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_getmicrouptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wrapper routines to convert a time interval specified in ffcounter units into  * seconds using the current feed-forward clock estimates.  */
end_comment

begin_function_decl
name|void
name|ffclock_bindifftime
parameter_list|(
name|ffcounter
name|ffdelta
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_nanodifftime
parameter_list|(
name|ffcounter
name|ffdelta
parameter_list|,
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffclock_microdifftime
parameter_list|(
name|ffcounter
name|ffdelta
parameter_list|,
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * When FFCLOCK is enabled in the kernel, [get]{bin,nano,micro}[up]time() become  * wrappers around equivalent feedback or feed-forward functions. Provide access  * outside of kern_tc.c to the feedback clock equivalent functions for  * specialised use i.e. these are not for general consumption.  */
end_comment

begin_function_decl
name|void
name|fbclock_bintime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_nanotime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_microtime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_getbintime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_getnanotime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_getmicrotime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_binuptime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_nanouptime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_microuptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_getbinuptime
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_getnanouptime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbclock_getmicrouptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Public system clock wrapper API which allows consumers to select which clock  * to obtain time from, independent of the current default system clock. These  * wrappers should be used instead of directly calling the underlying fbclock_  * or ffclock_ functions.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bintime_fromclock
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_bintime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
else|else
name|fbclock_bintime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nanotime_fromclock
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_nanotime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
else|else
name|fbclock_nanotime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|microtime_fromclock
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_microtime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
else|else
name|fbclock_microtime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getbintime_fromclock
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_getbintime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
else|else
name|fbclock_getbintime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getnanotime_fromclock
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_getnanotime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
else|else
name|fbclock_getnanotime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getmicrotime_fromclock
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_getmicrotime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
else|else
name|fbclock_getmicrotime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|binuptime_fromclock
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_binuptime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
else|else
name|fbclock_binuptime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nanouptime_fromclock
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_nanouptime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
else|else
name|fbclock_nanouptime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|microuptime_fromclock
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_microuptime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
else|else
name|fbclock_microuptime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getbinuptime_fromclock
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_getbinuptime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
else|else
name|fbclock_getbinuptime
argument_list|(
name|bt
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getnanouptime_fromclock
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_getnanouptime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
else|else
name|fbclock_getnanouptime
argument_list|(
name|tsp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getmicrouptime_fromclock
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|int
name|whichclock
parameter_list|)
block|{
if|if
condition|(
name|whichclock
operator|==
name|SYSCLOCK_FFWD
condition|)
name|ffclock_getmicrouptime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
else|else
name|fbclock_getmicrouptime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/* Feed-Forward Clock system calls. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ffclock_getcounter
parameter_list|(
name|ffcounter
modifier|*
name|ffcount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffclock_getestimate
parameter_list|(
name|struct
name|ffclock_estimate
modifier|*
name|cest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffclock_setestimate
parameter_list|(
name|struct
name|ffclock_estimate
modifier|*
name|cest
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TIMEFF_H_ */
end_comment

end_unit

