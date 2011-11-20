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
comment|/*  * Clock flags to select how the feed-forward counter is converted to absolute  * time by ffclock_convert_abs().  * FAST:    do not read the hardware counter, return feed-forward clock time  *          at last tick. The time returned has the resolution of the kernel  *          tick (1/hz [s]).  * LERP:    linear interpolation of ffclock time to guarantee monotonic time.  * LEAPSEC: include leap seconds.  * UPTIME:  removes time of boot.  */
end_comment

begin_define
define|#
directive|define
name|FFCLOCK_FAST
value|1
end_define

begin_define
define|#
directive|define
name|FFCLOCK_LERP
value|2
end_define

begin_define
define|#
directive|define
name|FFCLOCK_LEAPSEC
value|4
end_define

begin_define
define|#
directive|define
name|FFCLOCK_UPTIME
value|8
end_define

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

