begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_unixtime.h - contains constants and macros for converting between  *		    NTP time stamps (l_fp) and Unix times (struct timeval)  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/* gettimeofday() takes two args in BSD and only one in SYSV */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_TIMERS_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GETCLOCK
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/timers.h>
end_include

begin_function_decl
name|int
name|getclock
parameter_list|(
name|int
name|clock_type
parameter_list|,
name|struct
name|timespec
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Don't #define GETTIMEOFDAY because we shouldn't be using it in this case. */
end_comment

begin_define
define|#
directive|define
name|SETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(settimeofday(a, b))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (HAVE_SYS_TIMERS_H&& HAVE_GETCLOCK) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_TIMEOFDAY
end_ifdef

begin_define
define|#
directive|define
name|GETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(gettimeofday(a))
end_define

begin_define
define|#
directive|define
name|SETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(settimeofday(a))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SYSV_TIMEOFDAY */
end_comment

begin_if
if|#
directive|if
name|defined
name|SYS_CYGWIN32
end_if

begin_define
define|#
directive|define
name|GETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(gettimeofday(a, b))
end_define

begin_define
define|#
directive|define
name|SETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(settimeofday_NT(a))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(gettimeofday(a, b))
end_define

begin_define
define|#
directive|define
name|SETTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(settimeofday(a, b))
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
comment|/* SYSV_TIMEOFDAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not (HAVE_SYS_TIMERS_H&& HAVE_GETCLOCK) */
end_comment

begin_comment
comment|/*  * Time of day conversion constant.  Ntp's time scale starts in 1900,  * Unix in 1970.  */
end_comment

begin_define
define|#
directive|define
name|JAN_1970
value|0x83aa7e80
end_define

begin_comment
comment|/* 2208988800 1970 - 1900 in seconds */
end_comment

begin_comment
comment|/*  * These constants are used to round the time stamps computed from  * a struct timeval to the microsecond (more or less).  This keeps  * things neat.  */
end_comment

begin_define
define|#
directive|define
name|TS_MASK
value|0xfffff000
end_define

begin_comment
comment|/* mask to usec, for time stamps */
end_comment

begin_define
define|#
directive|define
name|TS_ROUNDBIT
value|0x00000800
end_define

begin_comment
comment|/* round at this bit */
end_comment

begin_comment
comment|/*  * Convert usec to a time stamp fraction.  If you use this the program  * must include the following declarations:  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|ustotslo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|ustotsmid
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|ustotshi
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TVUTOTSF
parameter_list|(
name|tvu
parameter_list|,
name|tsf
parameter_list|)
define|\
value|(tsf) = ustotslo[(tvu)& 0xff] \ 	    + ustotsmid[((tvu)>> 8)& 0xff] \ 	    + ustotshi[((tvu)>> 16)& 0xf]
end_define

begin_comment
comment|/*  * Convert a struct timeval to a time stamp.  */
end_comment

begin_define
define|#
directive|define
name|TVTOTS
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
define|\
value|do { \ 		(ts)->l_ui = (u_long)(tv)->tv_sec; \ 		TVUTOTSF((tv)->tv_usec, (ts)->l_uf); \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|sTVTOTS
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
define|\
value|do { \ 		int isneg = 0; \ 		long usec; \ 		(ts)->l_ui = (tv)->tv_sec; \ 		usec = (tv)->tv_usec; \ 		if (((tv)->tv_sec< 0) || ((tv)->tv_usec< 0)) { \ 			usec = -usec; \ 			(ts)->l_ui = -(ts)->l_ui; \ 			isneg = 1; \ 		} \ 		TVUTOTSF(usec, (ts)->l_uf); \ 		if (isneg) { \ 			L_NEG((ts)); \ 		} \ 	} while(0)
end_define

begin_comment
comment|/*  * TV_SHIFT is used to turn the table result into a usec value.  To round,  * add in TV_ROUNDBIT before shifting  */
end_comment

begin_define
define|#
directive|define
name|TV_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|TV_ROUNDBIT
value|0x4
end_define

begin_comment
comment|/*  * Convert a time stamp fraction to microseconds.  The time stamp  * fraction is assumed to be unsigned.  To use this in a program, declare:  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|tstouslo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tstousmid
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tstoushi
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TSFTOTVU
parameter_list|(
name|tsf
parameter_list|,
name|tvu
parameter_list|)
define|\
value|(tvu) = (tstoushi[((tsf)>> 24)& 0xff] \ 	    + tstousmid[((tsf)>> 16)& 0xff] \ 	    + tstouslo[((tsf)>> 9)& 0x7f] \ 	    + TV_ROUNDBIT)>> TV_SHIFT
end_define

begin_comment
comment|/*  * Convert a time stamp to a struct timeval.  The time stamp  * has to be positive.  */
end_comment

begin_define
define|#
directive|define
name|TSTOTV
parameter_list|(
name|ts
parameter_list|,
name|tv
parameter_list|)
define|\
value|do { \ 		(tv)->tv_sec = (ts)->l_ui; \ 		TSFTOTVU((ts)->l_uf, (tv)->tv_usec); \ 		if ((tv)->tv_usec == 1000000) { \ 			(tv)->tv_sec++; \ 			(tv)->tv_usec = 0; \ 		} \ 	} while (0)
end_define

begin_comment
comment|/*  * Convert milliseconds to a time stamp fraction.  This shouldn't be  * here, but it is convenient since the guys who use the definition will  * often be including this file anyway.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|msutotsflo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|msutotsfhi
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MSUTOTSF
parameter_list|(
name|msu
parameter_list|,
name|tsf
parameter_list|)
define|\
value|(tsf) = msutotsfhi[((msu)>> 5)& 0x1f] + msutotsflo[(msu)& 0x1f]
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tvtoa
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|utvtoa
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

