begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.5 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIME_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Structure returned by gettimeofday(2) system call,  * and used in other calls.  */
end_comment

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|long
name|tv_usec
decl_stmt|;
comment|/* and microseconds */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_TIMESPEC_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_TIMESPEC_DECLARED
end_define

begin_struct
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|long
name|tv_nsec
decl_stmt|;
comment|/* and nanoseconds */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMEVAL_TO_TIMESPEC
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
define|\
value|do {								\ 		(ts)->tv_sec = (tv)->tv_sec;				\ 		(ts)->tv_nsec = (tv)->tv_usec * 1000;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TIMESPEC_TO_TIMEVAL
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
define|\
value|do {								\ 		(tv)->tv_sec = (ts)->tv_sec;				\ 		(tv)->tv_usec = (ts)->tv_nsec / 1000;			\ 	} while (0)
end_define

begin_struct
struct|struct
name|timezone
block|{
name|int
name|tz_minuteswest
decl_stmt|;
comment|/* minutes west of Greenwich */
name|int
name|tz_dsttime
decl_stmt|;
comment|/* type of dst correction */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DST_NONE
value|0
end_define

begin_comment
comment|/* not on dst */
end_comment

begin_define
define|#
directive|define
name|DST_USA
value|1
end_define

begin_comment
comment|/* USA style dst */
end_comment

begin_define
define|#
directive|define
name|DST_AUST
value|2
end_define

begin_comment
comment|/* Australian style dst */
end_comment

begin_define
define|#
directive|define
name|DST_WET
value|3
end_define

begin_comment
comment|/* Western European dst */
end_comment

begin_define
define|#
directive|define
name|DST_MET
value|4
end_define

begin_comment
comment|/* Middle European dst */
end_comment

begin_define
define|#
directive|define
name|DST_EET
value|5
end_define

begin_comment
comment|/* Eastern European dst */
end_comment

begin_define
define|#
directive|define
name|DST_CAN
value|6
end_define

begin_comment
comment|/* Canada */
end_comment

begin_comment
comment|/* start of struct bintime stuff */
end_comment

begin_struct
struct|struct
name|bintime
block|{
name|time_t
name|sec
decl_stmt|;
name|uint64_t
name|frac
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|void
name|bintime_addx
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|uint64_t
name|x
parameter_list|)
block|{
name|uint64_t
name|u
decl_stmt|;
name|u
operator|=
name|bt
operator|->
name|frac
expr_stmt|;
name|bt
operator|->
name|frac
operator|+=
name|x
expr_stmt|;
if|if
condition|(
name|u
operator|>
name|bt
operator|->
name|frac
condition|)
name|bt
operator|->
name|sec
operator|++
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bintime_add
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt2
parameter_list|)
block|{
name|uint64_t
name|u
decl_stmt|;
name|u
operator|=
name|bt
operator|->
name|frac
expr_stmt|;
name|bt
operator|->
name|frac
operator|+=
name|bt2
operator|->
name|frac
expr_stmt|;
if|if
condition|(
name|u
operator|>
name|bt
operator|->
name|frac
condition|)
name|bt
operator|->
name|sec
operator|++
expr_stmt|;
name|bt
operator|->
name|sec
operator|+=
name|bt2
operator|->
name|sec
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bintime_sub
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt2
parameter_list|)
block|{
name|uint64_t
name|u
decl_stmt|;
name|u
operator|=
name|bt
operator|->
name|frac
expr_stmt|;
name|bt
operator|->
name|frac
operator|-=
name|bt2
operator|->
name|frac
expr_stmt|;
if|if
condition|(
name|u
operator|<
name|bt
operator|->
name|frac
condition|)
name|bt
operator|->
name|sec
operator|--
expr_stmt|;
name|bt
operator|->
name|sec
operator|-=
name|bt2
operator|->
name|sec
expr_stmt|;
block|}
end_function

begin_comment
comment|/*-  * Background information:  *  * When converting between timestamps on parallel timescales of differing  * resolutions it is historical and scientific practice to round down rather  * than doing 4/5 rounding.  *  *   The date changes at midnight, not at noon.  *  *   Even at 15:59:59.999999999 it's not four'o'clock.  *  *   time_second ticks after N.999999999 not after N.4999999999  *  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bintime2timespec
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
name|ts
operator|->
name|tv_sec
operator|=
name|bt
operator|->
name|sec
expr_stmt|;
name|ts
operator|->
name|tv_nsec
operator|=
operator|(
operator|(
name|uint64_t
operator|)
literal|1000000000
operator|*
call|(
name|uint32_t
call|)
argument_list|(
name|bt
operator|->
name|frac
operator|>>
literal|32
argument_list|)
operator|)
operator|>>
literal|32
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|timespec2bintime
parameter_list|(
name|struct
name|timespec
modifier|*
name|ts
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
block|{
name|bt
operator|->
name|sec
operator|=
name|ts
operator|->
name|tv_sec
expr_stmt|;
comment|/* 18446744073 = int(2^64 / 1000000000) */
name|bt
operator|->
name|frac
operator|=
name|ts
operator|->
name|tv_nsec
operator|*
operator|(
name|uint64_t
operator|)
literal|18446744073LL
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bintime2timeval
parameter_list|(
name|struct
name|bintime
modifier|*
name|bt
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
block|{
name|tv
operator|->
name|tv_sec
operator|=
name|bt
operator|->
name|sec
expr_stmt|;
name|tv
operator|->
name|tv_usec
operator|=
operator|(
operator|(
name|uint64_t
operator|)
literal|1000000
operator|*
call|(
name|uint32_t
call|)
argument_list|(
name|bt
operator|->
name|frac
operator|>>
literal|32
argument_list|)
operator|)
operator|>>
literal|32
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|timeval2bintime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|struct
name|bintime
modifier|*
name|bt
parameter_list|)
block|{
name|bt
operator|->
name|sec
operator|=
name|tv
operator|->
name|tv_sec
expr_stmt|;
comment|/* 18446744073709 = int(2^64 / 1000000) */
name|bt
operator|->
name|frac
operator|=
name|tv
operator|->
name|tv_usec
operator|*
operator|(
name|uint64_t
operator|)
literal|18446744073709LL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* end of struct bintime stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Operations on timespecs */
end_comment

begin_define
define|#
directive|define
name|timespecclear
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec = (tvp)->tv_nsec = 0)
end_define

begin_define
define|#
directive|define
name|timespecisset
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec || (tvp)->tv_nsec)
end_define

begin_define
define|#
directive|define
name|timespeccmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tvp)->tv_sec == (uvp)->tv_sec) ?				\ 	    ((tvp)->tv_nsec cmp (uvp)->tv_nsec) :			\ 	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
end_define

begin_define
define|#
directive|define
name|timespecadd
parameter_list|(
name|vvp
parameter_list|,
name|uvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec += (uvp)->tv_sec;				\ 		(vvp)->tv_nsec += (uvp)->tv_nsec;			\ 		if ((vvp)->tv_nsec>= 1000000000) {			\ 			(vvp)->tv_sec++;				\ 			(vvp)->tv_nsec -= 1000000000;			\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|timespecsub
parameter_list|(
name|vvp
parameter_list|,
name|uvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec -= (uvp)->tv_sec;				\ 		(vvp)->tv_nsec -= (uvp)->tv_nsec;			\ 		if ((vvp)->tv_nsec< 0) {				\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_nsec += 1000000000;			\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Operations on timevals. */
end_comment

begin_define
define|#
directive|define
name|timevalclear
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec = (tvp)->tv_usec = 0)
end_define

begin_define
define|#
directive|define
name|timevalisset
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec || (tvp)->tv_usec)
end_define

begin_define
define|#
directive|define
name|timevalcmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tvp)->tv_sec == (uvp)->tv_sec) ?				\ 	    ((tvp)->tv_usec cmp (uvp)->tv_usec) :			\ 	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
end_define

begin_comment
comment|/* timevaladd and timevalsub are not inlined */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* NetBSD/OpenBSD compatible interfaces */
end_comment

begin_define
define|#
directive|define
name|timerclear
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec = (tvp)->tv_usec = 0)
end_define

begin_define
define|#
directive|define
name|timerisset
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec || (tvp)->tv_usec)
end_define

begin_define
define|#
directive|define
name|timercmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tvp)->tv_sec == (uvp)->tv_sec) ?				\ 	    ((tvp)->tv_usec cmp (uvp)->tv_usec) :			\ 	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
end_define

begin_define
define|#
directive|define
name|timeradd
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec>= 1000000) {			\ 			(vvp)->tv_sec++;				\ 			(vvp)->tv_usec -= 1000000;			\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|timersub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec< 0) {				\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_usec += 1000000;			\ 		}							\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Names of the interval timers, and structure  * defining a timer setting.  */
end_comment

begin_define
define|#
directive|define
name|ITIMER_REAL
value|0
end_define

begin_define
define|#
directive|define
name|ITIMER_VIRTUAL
value|1
end_define

begin_define
define|#
directive|define
name|ITIMER_PROF
value|2
end_define

begin_struct
struct|struct
name|itimerval
block|{
name|struct
name|timeval
name|it_interval
decl_stmt|;
comment|/* timer interval */
name|struct
name|timeval
name|it_value
decl_stmt|;
comment|/* current value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Getkerninfo clock information structure  */
end_comment

begin_struct
struct|struct
name|clockinfo
block|{
name|int
name|hz
decl_stmt|;
comment|/* clock frequency */
name|int
name|tick
decl_stmt|;
comment|/* micro-seconds per hz tick */
name|int
name|tickadj
decl_stmt|;
comment|/* clock skew rate for adjtime() */
name|int
name|stathz
decl_stmt|;
comment|/* statistics clock frequency */
name|int
name|profhz
decl_stmt|;
comment|/* profiling clock frequency */
block|}
struct|;
end_struct

begin_comment
comment|/* CLOCK_REALTIME and TIMER_ABSTIME are supposed to be in time.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLOCK_REALTIME
end_ifndef

begin_define
define|#
directive|define
name|CLOCK_REALTIME
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|TIMER_RELTIME
value|0x0
end_define

begin_comment
comment|/* relative timer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMER_ABSTIME
end_ifndef

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|time_t
name|time_second
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|binuptime
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
name|bintime
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
name|getmicrouptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getmicrotime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getnanouptime
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
name|getnanotime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|itimerdecr
parameter_list|(
name|struct
name|itimerval
modifier|*
name|itp
parameter_list|,
name|int
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|itimerfix
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|microuptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|microtime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nanouptime
parameter_list|(
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nanotime
parameter_list|(
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timevaladd
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timevalsub
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tvtohz
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|adjtime
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|futimes
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getitimer
parameter_list|(
name|int
parameter_list|,
name|struct
name|itimerval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timezone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lutimes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setitimer
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|itimerval
modifier|*
parameter_list|,
name|struct
name|itimerval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|settimeofday
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|,
specifier|const
name|struct
name|timezone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utimes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
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
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TIME_H_ */
end_comment

end_unit

