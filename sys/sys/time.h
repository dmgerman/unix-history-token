begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.5 (Berkeley) 5/4/95  * $Id: time.h,v 1.8 1996/09/19 18:21:20 nate Exp $  */
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

begin_comment
comment|/*  * Structure defined by POSIX.4 to be like a timeval.  */
end_comment

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

begin_define
define|#
directive|define
name|TIMEVAL_TO_TIMESPEC
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
value|{					\ 	(ts)->tv_sec = (tv)->tv_sec;					\ 	(ts)->tv_nsec = (tv)->tv_usec * 1000;				\ }
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
value|{					\ 	(tv)->tv_sec = (ts)->tv_sec;					\ 	(tv)->tv_usec = (ts)->tv_nsec / 1000;				\ }
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
comment|/* Operations on timevals. */
end_comment

begin_define
define|#
directive|define
name|timerclear
parameter_list|(
name|tvp
parameter_list|)
value|(tvp)->tv_sec = (tvp)->tv_usec = 0
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

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_comment
comment|/* use timevaladd/timevalsub in kernel */
end_comment

begin_comment
comment|/* NetBSD/OpenBSD compatable interfaces */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|itimerfix
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|itimerdecr
name|__P
argument_list|(
operator|(
expr|struct
name|itimerval
operator|*
name|itp
operator|,
name|int
name|usec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|microtime
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|timevaladd
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|timevalsub
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|adjtime
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getitimer
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|itimerval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gettimeofday
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|timezone
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setitimer
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|itimerval
operator|*
operator|,
expr|struct
name|itimerval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|settimeofday
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|timeval
operator|*
operator|,
specifier|const
expr|struct
name|timezone
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|utimes
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !POSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TIME_H_ */
end_comment

end_unit

