begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.5 (Berkeley) 5/4/95  * $FreeBSD$  */
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
file|<sys/_timeval.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/timespec.h>
end_include

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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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
name|_bt
parameter_list|,
name|uint64_t
name|_x
parameter_list|)
block|{
name|uint64_t
name|_u
decl_stmt|;
name|_u
operator|=
name|_bt
operator|->
name|frac
expr_stmt|;
name|_bt
operator|->
name|frac
operator|+=
name|_x
expr_stmt|;
if|if
condition|(
name|_u
operator|>
name|_bt
operator|->
name|frac
condition|)
name|_bt
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
name|_bt
parameter_list|,
specifier|const
name|struct
name|bintime
modifier|*
name|_bt2
parameter_list|)
block|{
name|uint64_t
name|_u
decl_stmt|;
name|_u
operator|=
name|_bt
operator|->
name|frac
expr_stmt|;
name|_bt
operator|->
name|frac
operator|+=
name|_bt2
operator|->
name|frac
expr_stmt|;
if|if
condition|(
name|_u
operator|>
name|_bt
operator|->
name|frac
condition|)
name|_bt
operator|->
name|sec
operator|++
expr_stmt|;
name|_bt
operator|->
name|sec
operator|+=
name|_bt2
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
name|_bt
parameter_list|,
specifier|const
name|struct
name|bintime
modifier|*
name|_bt2
parameter_list|)
block|{
name|uint64_t
name|_u
decl_stmt|;
name|_u
operator|=
name|_bt
operator|->
name|frac
expr_stmt|;
name|_bt
operator|->
name|frac
operator|-=
name|_bt2
operator|->
name|frac
expr_stmt|;
if|if
condition|(
name|_u
operator|<
name|_bt
operator|->
name|frac
condition|)
name|_bt
operator|->
name|sec
operator|--
expr_stmt|;
name|_bt
operator|->
name|sec
operator|-=
name|_bt2
operator|->
name|sec
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bintime_mul
parameter_list|(
name|struct
name|bintime
modifier|*
name|_bt
parameter_list|,
name|u_int
name|_x
parameter_list|)
block|{
name|uint64_t
name|_p1
decl_stmt|,
name|_p2
decl_stmt|;
name|_p1
operator|=
operator|(
name|_bt
operator|->
name|frac
operator|&
literal|0xffffffffull
operator|)
operator|*
name|_x
expr_stmt|;
name|_p2
operator|=
operator|(
name|_bt
operator|->
name|frac
operator|>>
literal|32
operator|)
operator|*
name|_x
operator|+
operator|(
name|_p1
operator|>>
literal|32
operator|)
expr_stmt|;
name|_bt
operator|->
name|sec
operator|*=
name|_x
expr_stmt|;
name|_bt
operator|->
name|sec
operator|+=
operator|(
name|_p2
operator|>>
literal|32
operator|)
expr_stmt|;
name|_bt
operator|->
name|frac
operator|=
operator|(
name|_p2
operator|<<
literal|32
operator|)
operator||
operator|(
name|_p1
operator|&
literal|0xffffffffull
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bintime_shift
parameter_list|(
name|struct
name|bintime
modifier|*
name|_bt
parameter_list|,
name|int
name|_exp
parameter_list|)
block|{
if|if
condition|(
name|_exp
operator|>
literal|0
condition|)
block|{
name|_bt
operator|->
name|sec
operator|<<=
name|_exp
expr_stmt|;
name|_bt
operator|->
name|sec
operator||=
name|_bt
operator|->
name|frac
operator|>>
operator|(
literal|64
operator|-
name|_exp
operator|)
expr_stmt|;
name|_bt
operator|->
name|frac
operator|<<=
name|_exp
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|_exp
operator|<
literal|0
condition|)
block|{
name|_bt
operator|->
name|frac
operator|>>=
operator|-
name|_exp
expr_stmt|;
name|_bt
operator|->
name|frac
operator||=
operator|(
name|uint64_t
operator|)
name|_bt
operator|->
name|sec
operator|<<
operator|(
literal|64
operator|+
name|_exp
operator|)
expr_stmt|;
name|_bt
operator|->
name|sec
operator|>>=
operator|-
name|_exp
expr_stmt|;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|bintime_clear
parameter_list|(
name|a
parameter_list|)
value|((a)->sec = (a)->frac = 0)
end_define

begin_define
define|#
directive|define
name|bintime_isset
parameter_list|(
name|a
parameter_list|)
value|((a)->sec || (a)->frac)
end_define

begin_define
define|#
directive|define
name|bintime_cmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((a)->sec == (b)->sec) ?					\ 	    ((a)->frac cmp (b)->frac) :					\ 	    ((a)->sec cmp (b)->sec))
end_define

begin_define
define|#
directive|define
name|SBT_1S
value|((sbintime_t)1<< 32)
end_define

begin_define
define|#
directive|define
name|SBT_1M
value|(SBT_1S * 60)
end_define

begin_define
define|#
directive|define
name|SBT_1MS
value|(SBT_1S / 1000)
end_define

begin_define
define|#
directive|define
name|SBT_1US
value|(SBT_1S / 1000000)
end_define

begin_define
define|#
directive|define
name|SBT_1NS
value|(SBT_1S / 1000000000)
end_define

begin_comment
comment|/* beware rounding, see nstosbt() */
end_comment

begin_define
define|#
directive|define
name|SBT_MAX
value|0x7fffffffffffffffLL
end_define

begin_function
specifier|static
name|__inline
name|int
name|sbintime_getsec
parameter_list|(
name|sbintime_t
name|_sbt
parameter_list|)
block|{
return|return
operator|(
name|_sbt
operator|>>
literal|32
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|sbintime_t
name|bttosbt
parameter_list|(
specifier|const
name|struct
name|bintime
name|_bt
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|sbintime_t
operator|)
name|_bt
operator|.
name|sec
operator|<<
literal|32
operator|)
operator|+
operator|(
name|_bt
operator|.
name|frac
operator|>>
literal|32
operator|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|bintime
name|sbttobt
argument_list|(
argument|sbintime_t _sbt
argument_list|)
block|{ 	struct
name|bintime
name|_bt
block|;
name|_bt
operator|.
name|sec
operator|=
name|_sbt
operator|>>
literal|32
block|;
name|_bt
operator|.
name|frac
operator|=
name|_sbt
operator|<<
literal|32
block|;
return|return
operator|(
name|_bt
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * Decimal<->sbt conversions.  Multiplying or dividing by SBT_1NS results in  * large roundoff errors which sbttons() and nstosbt() avoid.  Millisecond and  * microsecond functions are also provided for completeness.  */
end_comment

begin_function
specifier|static
name|__inline
name|int64_t
name|sbttons
parameter_list|(
name|sbintime_t
name|_sbt
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|1000000000
operator|*
name|_sbt
operator|)
operator|>>
literal|32
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|sbintime_t
name|nstosbt
parameter_list|(
name|int64_t
name|_ns
parameter_list|)
block|{
return|return
operator|(
operator|(
name|_ns
operator|*
operator|(
operator|(
operator|(
name|uint64_t
operator|)
literal|1
operator|<<
literal|63
operator|)
operator|/
literal|500000000
operator|)
operator|>>
literal|32
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int64_t
name|sbttous
parameter_list|(
name|sbintime_t
name|_sbt
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|1000000
operator|*
name|_sbt
operator|)
operator|>>
literal|32
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|sbintime_t
name|ustosbt
parameter_list|(
name|int64_t
name|_us
parameter_list|)
block|{
return|return
operator|(
operator|(
name|_us
operator|*
operator|(
operator|(
operator|(
name|uint64_t
operator|)
literal|1
operator|<<
literal|63
operator|)
operator|/
literal|500000
operator|)
operator|>>
literal|32
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int64_t
name|sbttoms
parameter_list|(
name|sbintime_t
name|_sbt
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|1000
operator|*
name|_sbt
operator|)
operator|>>
literal|32
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|sbintime_t
name|mstosbt
parameter_list|(
name|int64_t
name|_ms
parameter_list|)
block|{
return|return
operator|(
operator|(
name|_ms
operator|*
operator|(
operator|(
operator|(
name|uint64_t
operator|)
literal|1
operator|<<
literal|63
operator|)
operator|/
literal|500
operator|)
operator|>>
literal|32
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*-  * Background information:  *  * When converting between timestamps on parallel timescales of differing  * resolutions it is historical and scientific practice to round down rather  * than doing 4/5 rounding.  *  *   The date changes at midnight, not at noon.  *  *   Even at 15:59:59.999999999 it's not four'o'clock.  *  *   time_second ticks after N.999999999 not after N.4999999999  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bintime2timespec
parameter_list|(
specifier|const
name|struct
name|bintime
modifier|*
name|_bt
parameter_list|,
name|struct
name|timespec
modifier|*
name|_ts
parameter_list|)
block|{
name|_ts
operator|->
name|tv_sec
operator|=
name|_bt
operator|->
name|sec
expr_stmt|;
name|_ts
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
name|_bt
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
specifier|const
name|struct
name|timespec
modifier|*
name|_ts
parameter_list|,
name|struct
name|bintime
modifier|*
name|_bt
parameter_list|)
block|{
name|_bt
operator|->
name|sec
operator|=
name|_ts
operator|->
name|tv_sec
expr_stmt|;
comment|/* 18446744073 = int(2^64 / 1000000000) */
name|_bt
operator|->
name|frac
operator|=
name|_ts
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
specifier|const
name|struct
name|bintime
modifier|*
name|_bt
parameter_list|,
name|struct
name|timeval
modifier|*
name|_tv
parameter_list|)
block|{
name|_tv
operator|->
name|tv_sec
operator|=
name|_bt
operator|->
name|sec
expr_stmt|;
name|_tv
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
name|_bt
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
specifier|const
name|struct
name|timeval
modifier|*
name|_tv
parameter_list|,
name|struct
name|bintime
modifier|*
name|_bt
parameter_list|)
block|{
name|_bt
operator|->
name|sec
operator|=
name|_tv
operator|->
name|tv_sec
expr_stmt|;
comment|/* 18446744073709 = int(2^64 / 1000000) */
name|_bt
operator|->
name|frac
operator|=
name|_tv
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

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|timespec
name|sbttots
argument_list|(
argument|sbintime_t _sbt
argument_list|)
block|{ 	struct
name|timespec
name|_ts
block|;
name|_ts
operator|.
name|tv_sec
operator|=
name|_sbt
operator|>>
literal|32
block|;
name|_ts
operator|.
name|tv_nsec
operator|=
name|sbttons
argument_list|(
operator|(
name|uint32_t
operator|)
name|_sbt
argument_list|)
block|;
return|return
operator|(
name|_ts
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|sbintime_t
name|tstosbt
parameter_list|(
name|struct
name|timespec
name|_ts
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|sbintime_t
operator|)
name|_ts
operator|.
name|tv_sec
operator|<<
literal|32
operator|)
operator|+
name|nstosbt
argument_list|(
name|_ts
operator|.
name|tv_nsec
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|timeval
name|sbttotv
argument_list|(
argument|sbintime_t _sbt
argument_list|)
block|{ 	struct
name|timeval
name|_tv
block|;
name|_tv
operator|.
name|tv_sec
operator|=
name|_sbt
operator|>>
literal|32
block|;
name|_tv
operator|.
name|tv_usec
operator|=
name|sbttous
argument_list|(
operator|(
name|uint32_t
operator|)
name|_sbt
argument_list|)
block|;
return|return
operator|(
name|_tv
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|sbintime_t
name|tvtosbt
parameter_list|(
name|struct
name|timeval
name|_tv
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|sbintime_t
operator|)
name|_tv
operator|.
name|tv_sec
operator|<<
literal|32
operator|)
operator|+
name|ustosbt
argument_list|(
name|_tv
operator|.
name|tv_usec
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
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
name|spare
decl_stmt|;
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
comment|/* These macros are also in time.h. */
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

begin_ifndef
ifndef|#
directive|ifndef
name|TIMER_ABSTIME
end_ifndef

begin_define
define|#
directive|define
name|TIMER_RELTIME
value|0x0
end_define

begin_comment
comment|/* relative timer */
end_comment

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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|CPUCLOCK_WHICH_PID
value|0
end_define

begin_define
define|#
directive|define
name|CPUCLOCK_WHICH_TID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel to clock driver interface.  */
end_comment

begin_function_decl
name|void
name|inittodr
parameter_list|(
name|time_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resettodr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|volatile
name|time_t
name|time_second
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|time_t
name|time_uptime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bintime
name|tc_tick_bt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbintime_t
name|tc_tick_sbt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bintime
name|tick_bt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbintime_t
name|tick_sbt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tc_precexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tc_timepercentage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bintime
name|bt_timethreshold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bintime
name|bt_tickthreshold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbintime_t
name|sbt_timethreshold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbintime_t
name|sbt_tickthreshold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|rtc_generation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Functions for looking at our clock: [get]{bin,nano,micro}[up]time()  *  * Functions without the "get" prefix returns the best timestamp  * we can produce in the given format.  *  * "bin"   == struct bintime  == seconds + 64 bit fraction of seconds.  * "nano"  == struct timespec == seconds + nanoseconds.  * "micro" == struct timeval  == seconds + microseconds.  *  * Functions containing "up" returns time relative to boot and  * should be used for calculating time intervals.  *  * Functions without "up" returns UTC time.  *  * Functions with the "get" prefix returns a less precise result  * much faster than the functions without "get" prefix and should  * be used where a precision of 1/hz seconds is acceptable or where  * performance is priority. (NB: "precision", _not_ "resolution" !)  */
end_comment

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
name|nanouptime
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
name|microuptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|sbintime_t
name|sbinuptime
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|bintime
name|_bt
decl_stmt|;
name|binuptime
argument_list|(
operator|&
name|_bt
argument_list|)
expr_stmt|;
return|return
operator|(
name|bttosbt
argument_list|(
name|_bt
argument_list|)
operator|)
return|;
block|}
end_function

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
name|nanotime
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
name|microtime
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
name|getbinuptime
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
name|getmicrouptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|sbintime_t
name|getsbinuptime
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|bintime
name|_bt
decl_stmt|;
name|getbinuptime
argument_list|(
operator|&
name|_bt
argument_list|)
expr_stmt|;
return|return
operator|(
name|bttosbt
argument_list|(
name|_bt
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|void
name|getbintime
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
name|void
name|getmicrotime
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
name|getboottime
parameter_list|(
name|struct
name|timeval
modifier|*
name|boottime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getboottimebin
parameter_list|(
name|struct
name|bintime
modifier|*
name|boottimebin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Other functions */
end_comment

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
name|int
name|ppsratecheck
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ratecheck
parameter_list|(
name|struct
name|timeval
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
name|void
name|timevaladd
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|t2
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
name|t1
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|t2
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
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TC_DEFAULTPERC
value|5
end_define

begin_define
define|#
directive|define
name|BT2FREQ
parameter_list|(
name|bt
parameter_list|)
define|\
value|(((uint64_t)0x8000000000000000 + ((bt)->frac>> 2)) /           \ 	    ((bt)->frac>> 1))
end_define

begin_define
define|#
directive|define
name|SBT2FREQ
parameter_list|(
name|sbt
parameter_list|)
value|((SBT_1S + ((sbt)>> 1)) / (sbt))
end_define

begin_define
define|#
directive|define
name|FREQ2BT
parameter_list|(
name|freq
parameter_list|,
name|bt
parameter_list|)
define|\
value|{									\ 	(bt)->sec = 0;                                                  \ 	(bt)->frac = ((uint64_t)0x8000000000000000  / (freq))<< 1;     \ }
end_define

begin_define
define|#
directive|define
name|TIMESEL
parameter_list|(
name|sbt
parameter_list|,
name|sbt2
parameter_list|)
define|\
value|(((sbt2)>= sbt_timethreshold) ?				\ 	    ((*(sbt) = getsbinuptime()), 1) : ((*(sbt) = sbinuptime()), 0))
end_define

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

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
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
name|clock_getcpuclockid2
parameter_list|(
name|id_t
parameter_list|,
name|int
parameter_list|,
name|clockid_t
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
name|futimesat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
type|[
function_decl|2]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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

