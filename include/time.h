begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.3 (Berkeley) 1/21/94  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_TIME_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>
literal|0
operator|&&
name|__POSIX_VISIBLE
operator|<
literal|200112
operator|||
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * Frequency of the clock ticks reported by times().  Deprecated - use  * sysconf(_SC_CLK_TCK) instead.  (Removed in 1003.1-2001.)  */
end_comment

begin_define
define|#
directive|define
name|CLK_TCK
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Frequency of the clock ticks reported by clock().  */
end_comment

begin_define
define|#
directive|define
name|CLOCKS_PER_SEC
value|128
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCK_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__clock_t
name|clock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_CLOCK_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__time_t
name|time_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_TIME_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
end_if

begin_comment
comment|/*  * New in POSIX 1003.1b-1993.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCKID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__clockid_t
name|clockid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_CLOCKID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TIMER_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__timer_t
name|timer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_TIMER_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/timespec.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE>= 199309 */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These macros are also in sys/time.h. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CLOCK_REALTIME
argument_list|)
operator|&&
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|CLOCK_REALTIME
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BSD_VISIBLE
end_ifdef

begin_define
define|#
directive|define
name|CLOCK_VIRTUAL
value|1
end_define

begin_define
define|#
directive|define
name|CLOCK_PROF
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CLOCK_MONOTONIC
value|4
end_define

begin_define
define|#
directive|define
name|CLOCK_UPTIME
value|5
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_UPTIME_PRECISE
value|7
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_UPTIME_FAST
value|8
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_REALTIME_PRECISE
value|9
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_REALTIME_FAST
value|10
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MONOTONIC_PRECISE
value|11
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MONOTONIC_FAST
value|12
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SECOND
value|13
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|CLOCK_THREAD_CPUTIME_ID
value|14
end_define

begin_define
define|#
directive|define
name|CLOCK_PROCESS_CPUTIME_ID
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(CLOCK_REALTIME)&& __POSIX_VISIBLE>= 200112 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIMER_ABSTIME
argument_list|)
operator|&&
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|TIMER_RELTIME
value|0x0
end_define

begin_comment
comment|/* relative timer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMER_ABSTIME
value|0x1
end_define

begin_comment
comment|/* absolute timer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(TIMER_ABSTIME)&& __POSIX_VISIBLE>= 200112 */
end_comment

begin_struct
struct|struct
name|tm
block|{
name|int
name|tm_sec
decl_stmt|;
comment|/* seconds after the minute [0-60] */
name|int
name|tm_min
decl_stmt|;
comment|/* minutes after the hour [0-59] */
name|int
name|tm_hour
decl_stmt|;
comment|/* hours since midnight [0-23] */
name|int
name|tm_mday
decl_stmt|;
comment|/* day of the month [1-31] */
name|int
name|tm_mon
decl_stmt|;
comment|/* months since January [0-11] */
name|int
name|tm_year
decl_stmt|;
comment|/* years since 1900 */
name|int
name|tm_wday
decl_stmt|;
comment|/* days since Sunday [0-6] */
name|int
name|tm_yday
decl_stmt|;
comment|/* days since January 1 [0-365] */
name|int
name|tm_isdst
decl_stmt|;
comment|/* Daylight Savings Time flag */
name|long
name|tm_gmtoff
decl_stmt|;
comment|/* offset from UTC in seconds */
name|char
modifier|*
name|tm_zone
decl_stmt|;
comment|/* timezone abbreviation */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tzname
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|char
modifier|*
name|asctime
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|clock_t
name|clock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ctime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|difftime
parameter_list|(
name|time_t
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX missing: getdate() */
end_comment

begin_function_decl
name|struct
name|tm
modifier|*
name|gmtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|mktime
parameter_list|(
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|strftime
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|struct
name|tm
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_struct_decl
struct_decl|struct
name|sigevent
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|timer_create
parameter_list|(
name|clockid_t
parameter_list|,
name|struct
name|sigevent
modifier|*
name|__restrict
parameter_list|,
name|timer_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timer_delete
parameter_list|(
name|timer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timer_gettime
parameter_list|(
name|timer_t
parameter_list|,
name|struct
name|itimerspec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timer_getoverrun
parameter_list|(
name|timer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timer_settime
parameter_list|(
name|timer_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|itimerspec
modifier|*
name|__restrict
parameter_list|,
name|struct
name|itimerspec
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_function_decl
name|void
name|tzset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
end_if

begin_function_decl
name|int
name|clock_getres
parameter_list|(
name|clockid_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clock_gettime
parameter_list|(
name|clockid_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clock_settime
parameter_list|(
name|clockid_t
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nanosleep
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE>= 199309 */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|int
name|clock_getcpuclockid
parameter_list|(
name|pid_t
parameter_list|,
name|clockid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clock_nanosleep
parameter_list|(
name|clockid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
end_if

begin_function_decl
name|char
modifier|*
name|asctime_r
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ctime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|gmtime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|,
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|,
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_function_decl
name|char
modifier|*
name|strptime
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|struct
name|tm
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|char
modifier|*
name|timezone
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX XSI conflict */
end_comment

begin_function_decl
name|void
name|tzsetwall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|timelocal
parameter_list|(
name|struct
name|tm
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|timegm
parameter_list|(
name|struct
name|tm
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timer_oshandle_np
parameter_list|(
name|timer_t
name|timerid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
operator|||
name|defined
argument_list|(
name|_XLOCALE_H_
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xlocale/_time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TIME_H_ */
end_comment

end_unit

