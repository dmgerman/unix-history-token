begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)time.h	7.1 (Berkeley) 6/4/86  */
end_comment

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
comment|/*  * Operations on timevals.  *  * NB: timercmp does not work for>= or<=.  */
end_comment

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
value|((tvp)->tv_sec cmp (uvp)->tv_sec || \ 	 (tvp)->tv_sec == (uvp)->tv_sec&& (tvp)->tv_usec cmp (uvp)->tv_usec)
end_define

begin_define
define|#
directive|define
name|timerclear
parameter_list|(
name|tvp
parameter_list|)
value|(tvp)->tv_sec = (tvp)->tv_usec = 0
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

