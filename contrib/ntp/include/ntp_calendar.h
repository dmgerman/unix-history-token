begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_calendar.h - definitions for the calendar time-of-day routine  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_CALENDAR_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_CALENDAR_H
end_define

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_struct
struct|struct
name|calendar
block|{
name|u_short
name|year
decl_stmt|;
comment|/* year (A.D.) */
name|u_short
name|yearday
decl_stmt|;
comment|/* day of year, 1 = January 1 */
name|u_char
name|month
decl_stmt|;
comment|/* month, 1 = January */
name|u_char
name|monthday
decl_stmt|;
comment|/* day of month */
name|u_char
name|hour
decl_stmt|;
comment|/* hour of day, midnight = 0 */
name|u_char
name|minute
decl_stmt|;
comment|/* minute of hour */
name|u_char
name|second
decl_stmt|;
comment|/* second of minute */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Days in each month.  30 days hath September...  */
end_comment

begin_define
define|#
directive|define
name|JAN
value|31
end_define

begin_define
define|#
directive|define
name|FEB
value|28
end_define

begin_define
define|#
directive|define
name|FEBLEAP
value|29
end_define

begin_define
define|#
directive|define
name|MAR
value|31
end_define

begin_define
define|#
directive|define
name|APR
value|30
end_define

begin_define
define|#
directive|define
name|MAY
value|31
end_define

begin_define
define|#
directive|define
name|JUN
value|30
end_define

begin_define
define|#
directive|define
name|JUL
value|31
end_define

begin_define
define|#
directive|define
name|AUG
value|31
end_define

begin_define
define|#
directive|define
name|SEP
value|30
end_define

begin_define
define|#
directive|define
name|OCT
value|31
end_define

begin_define
define|#
directive|define
name|NOV
value|30
end_define

begin_define
define|#
directive|define
name|DEC
value|31
end_define

begin_comment
comment|/*  * We deal in a 4 year cycle starting at March 1, 1900.  We assume  * we will only want to deal with dates since then, and not to exceed  * the rollover day in 2036.  */
end_comment

begin_define
define|#
directive|define
name|SECSPERMIN
value|(60)
end_define

begin_comment
comment|/* seconds per minute */
end_comment

begin_define
define|#
directive|define
name|MINSPERHR
value|(60)
end_define

begin_comment
comment|/* minutes per hour */
end_comment

begin_define
define|#
directive|define
name|HRSPERDAY
value|(24)
end_define

begin_comment
comment|/* hours per day */
end_comment

begin_define
define|#
directive|define
name|DAYSPERYEAR
value|(365)
end_define

begin_comment
comment|/* days per year */
end_comment

begin_define
define|#
directive|define
name|SECSPERDAY
value|(SECSPERMIN*MINSPERHR*HRSPERDAY)
end_define

begin_define
define|#
directive|define
name|SECSPERYEAR
value|(365 * SECSPERDAY)
end_define

begin_comment
comment|/* regular year */
end_comment

begin_define
define|#
directive|define
name|SECSPERLEAPYEAR
value|(366 * SECSPERDAY)
end_define

begin_comment
comment|/* leap year */
end_comment

begin_define
define|#
directive|define
name|MAR1900
value|((JAN+FEB) * SECSPERDAY)
end_define

begin_comment
comment|/* no leap year in 1900 */
end_comment

begin_define
define|#
directive|define
name|DAYSPERCYCLE
value|(365+365+365+366)
end_define

begin_comment
comment|/* 3 normal years plus leap */
end_comment

begin_define
define|#
directive|define
name|SECSPERCYCLE
value|(DAYSPERCYCLE*SECSPERDAY)
end_define

begin_define
define|#
directive|define
name|YEARSPERCYCLE
value|4
end_define

begin_comment
comment|/*  * Gross hacks.  I have illicit knowlege that there won't be overflows  * here, the compiler often can't tell this.  */
end_comment

begin_define
define|#
directive|define
name|TIMES60
parameter_list|(
name|val
parameter_list|)
value|((((val)<<4) - (val))<<2)
end_define

begin_comment
comment|/* *(16 - 1) * 4 */
end_comment

begin_define
define|#
directive|define
name|TIMES24
parameter_list|(
name|val
parameter_list|)
value|(((val)<<4) + ((val)<<3))
end_define

begin_comment
comment|/* *16 + *8 */
end_comment

begin_define
define|#
directive|define
name|TIMES7
parameter_list|(
name|val
parameter_list|)
value|(((val)<<3) - (val))
end_define

begin_comment
comment|/* *8  - *1 */
end_comment

begin_define
define|#
directive|define
name|TIMESDPERC
parameter_list|(
name|val
parameter_list|)
value|(((val)<<10) + ((val)<<8) \ 			+ ((val)<<7) + ((val)<<5) \ 			+ ((val)<<4) + ((val)<<2) + (val))
end_define

begin_comment
comment|/* *big* hack */
end_comment

begin_comment
comment|/*  * Another big hack.  Cycle 22 started on March 1, 1988.  This is  * STARTCYCLE22 seconds after the start of cycle 0.  */
end_comment

begin_define
define|#
directive|define
name|CYCLE22
value|(22)
end_define

begin_define
define|#
directive|define
name|STARTCYCLE22
value|(u_long)(0xa586b500)
end_define

begin_comment
comment|/* 2777068800 */
end_comment

begin_define
define|#
directive|define
name|MAR1988
value|(u_long)(STARTCYCLE22 + (u_long)MAR1900)
end_define

begin_comment
comment|/*  * The length of January + February in leap and non-leap years.  */
end_comment

begin_define
define|#
directive|define
name|JANFEBNOLEAP
value|((JAN+FEB) * SECSPERDAY)
end_define

begin_define
define|#
directive|define
name|JANFEBLEAP
value|((JAN+FEBLEAP) * SECSPERDAY)
end_define

begin_decl_stmt
specifier|extern
name|void
name|caljulian
name|P
argument_list|(
operator|(
name|u_long
operator|,
expr|struct
name|calendar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|caltontp
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|calendar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Additional support stuff for Ed Rheingold's calendrical calculations  */
end_comment

begin_comment
comment|/*  * Start day of NTP time as days past the imaginary date 12/1/1 BC.  * P((This is the beginning of the Christian Era, or BCE.))  */
end_comment

begin_define
define|#
directive|define
name|DAY_NTP_STARTS
value|693596
end_define

begin_comment
comment|/*  * The Gregorian calendar is based on a 400 year cycle.  This is the number  * of days in each cycle.  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_CYCLE_DAYS
value|146097
end_define

begin_comment
comment|/*  * Days in a normal 100 year leap year calendar.  We lose a leap year day  * in years evenly divisible by 100 but not by 400.  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_NORMAL_CENTURY_DAYS
value|36524
end_define

begin_comment
comment|/*  * Days in a normal 4 year leap year calendar cycle.  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_NORMAL_LEAP_CYCLE_DAYS
value|1461
end_define

begin_define
define|#
directive|define
name|is_leapyear
parameter_list|(
name|y
parameter_list|)
value|(y%4 == 0&& !(y%100 == 0&& !(y%400 == 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

