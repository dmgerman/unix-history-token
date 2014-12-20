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
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/* gregorian calendar date */
end_comment

begin_struct
struct|struct
name|calendar
block|{
name|uint16_t
name|year
decl_stmt|;
comment|/* year (A.D.) */
name|uint16_t
name|yearday
decl_stmt|;
comment|/* day of year, 1 = January 1 */
name|uint8_t
name|month
decl_stmt|;
comment|/* month, 1 = January */
name|uint8_t
name|monthday
decl_stmt|;
comment|/* day of month */
name|uint8_t
name|hour
decl_stmt|;
comment|/* hour of day, midnight = 0 */
name|uint8_t
name|minute
decl_stmt|;
comment|/* minute of hour */
name|uint8_t
name|second
decl_stmt|;
comment|/* second of minute */
name|uint8_t
name|weekday
decl_stmt|;
comment|/* 0..7, 0=Sunday */
block|}
struct|;
end_struct

begin_comment
comment|/* ISO week calendar date */
end_comment

begin_struct
struct|struct
name|isodate
block|{
name|uint16_t
name|year
decl_stmt|;
comment|/* year (A.D.) */
name|uint8_t
name|week
decl_stmt|;
comment|/* 1..53, week in year */
name|uint8_t
name|weekday
decl_stmt|;
comment|/* 1..7, 1=Monday */
name|uint8_t
name|hour
decl_stmt|;
comment|/* hour of day, midnight = 0 */
name|uint8_t
name|minute
decl_stmt|;
comment|/* minute of hour */
name|uint8_t
name|second
decl_stmt|;
comment|/* second of minute */
block|}
struct|;
end_struct

begin_comment
comment|/* general split representation */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|hi
decl_stmt|;
name|int32_t
name|lo
decl_stmt|;
block|}
name|ntpcal_split
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|time_t
function_decl|(
modifier|*
name|systime_func_ptr
function_decl|)
parameter_list|(
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * set the function for getting the system time. This is mostly used for  * unit testing to provide a fixed / shifted time stamp. Setting the  * value to NULL restores the original function, that is, 'time()',  * which is also the automatic default.  */
end_comment

begin_function_decl
specifier|extern
name|systime_func_ptr
name|ntpcal_set_timefunc
parameter_list|(
name|systime_func_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * days-of-week  */
end_comment

begin_define
define|#
directive|define
name|CAL_SUNDAY
value|0
end_define

begin_define
define|#
directive|define
name|CAL_MONDAY
value|1
end_define

begin_define
define|#
directive|define
name|CAL_TUESDAY
value|2
end_define

begin_define
define|#
directive|define
name|CAL_WEDNESDAY
value|3
end_define

begin_define
define|#
directive|define
name|CAL_THURSDAY
value|4
end_define

begin_define
define|#
directive|define
name|CAL_FRIDAY
value|5
end_define

begin_define
define|#
directive|define
name|CAL_SATURDAY
value|6
end_define

begin_define
define|#
directive|define
name|CAL_SUNDAY7
value|7
end_define

begin_comment
comment|/* also sunday */
end_comment

begin_comment
comment|/*  * Days in each month.	30 days hath September...  */
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
comment|/*  * We deal in a 4 year cycle starting at March 1, 1900.	 We assume  * we will only want to deal with dates since then, and not to exceed  * the rollover day in 2036.  */
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
name|SECSPERHR
value|(SECSPERMIN * MINSPERHR)
end_define

begin_define
define|#
directive|define
name|SECSPERDAY
value|(SECSPERHR * HRSPERDAY)
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
name|SECSPERAVGYEAR
value|31556952
end_define

begin_comment
comment|/* mean year length over 400yrs */
end_comment

begin_comment
comment|/*  * Gross hacks.	 I have illicit knowlege that there won't be overflows  * here, the compiler often can't tell this.  */
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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|months
index|[
literal|12
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|daynames
index|[
literal|7
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|caljulian
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|calendar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|caltontp
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert between 'time_t' and 'vint64'  */
end_comment

begin_function_decl
specifier|extern
name|vint64
name|time_to_vint64
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|vint64_to_time
parameter_list|(
specifier|const
name|vint64
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the build date& time. ATTENTION: The time zone is not specified!  * This depends entirely on the C compilers' capabilities to properly  * expand the '__TIME__' and '__DATE__' macros, as required by the C  * standard.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ntpcal_get_build_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a timestamp in NTP scale to a time_t value in the UN*X  * scale with proper epoch unfolding around a given pivot or the  * current system time.  */
end_comment

begin_function_decl
specifier|extern
name|vint64
name|ntpcal_ntp_to_time
parameter_list|(
name|uint32_t
comment|/* ntp */
parameter_list|,
specifier|const
name|time_t
modifier|*
comment|/* pivot */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a timestamp in NTP scale to a 64bit seconds value in the NTP  * scale with proper epoch unfolding around a given pivot or the current  * system time.  * Note: The pivot must be given in UN*X time scale!  */
end_comment

begin_function_decl
specifier|extern
name|vint64
name|ntpcal_ntp_to_ntp
parameter_list|(
name|uint32_t
comment|/* ntp */
parameter_list|,
specifier|const
name|time_t
modifier|*
comment|/* pivot */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Split a time stamp in seconds into elapsed days and elapsed seconds  * since midnight.  */
end_comment

begin_function_decl
specifier|extern
name|ntpcal_split
name|ntpcal_daysplit
parameter_list|(
specifier|const
name|vint64
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Merge a number of days and a number of seconds into seconds,  * expressed in 64 bits to avoid overflow.  */
end_comment

begin_function_decl
specifier|extern
name|vint64
name|ntpcal_dayjoin
parameter_list|(
name|int32_t
comment|/* days */
parameter_list|,
name|int32_t
comment|/* seconds */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert elapsed years in Era into elapsed days in Era.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_days_in_years
parameter_list|(
name|int32_t
comment|/* years */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a number of elapsed month in a year into elapsed days  * in year.  *  * The month will be normalized, and 'res.hi' will contain the  * excessive years that must be considered when converting the years,  * while 'res.lo' will contain the days since start of the  * year. (Expect the resulting days to be negative, with a positive  * excess! But then, we need no leap year flag, either...)  */
end_comment

begin_function_decl
specifier|extern
name|ntpcal_split
name|ntpcal_days_in_months
parameter_list|(
name|int32_t
comment|/* months */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert ELAPSED years/months/days of gregorian calendar to elapsed  * days in Gregorian epoch. No range checks done here!  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_edate_to_eradays
parameter_list|(
name|int32_t
comment|/* years */
parameter_list|,
name|int32_t
comment|/* months */
parameter_list|,
name|int32_t
comment|/* mdays */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a time spec to seconds. No range checks done here!  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_etime_to_seconds
parameter_list|(
name|int32_t
comment|/* hours */
parameter_list|,
name|int32_t
comment|/* minutes */
parameter_list|,
name|int32_t
comment|/* seconds */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert ELAPSED years/months/days of gregorian calendar to elapsed  * days in year.  *  * Note: This will give the true difference to the start of the given year,  * even if months& days are off-scale.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_edate_to_yeardays
parameter_list|(
name|int32_t
comment|/* years */
parameter_list|,
name|int32_t
comment|/* months */
parameter_list|,
name|int32_t
comment|/* mdays */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert the date part of a 'struct tm' (that is, year, month,  * day-of-month) into the RataDie of that day.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_tm_to_rd
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
comment|/* utm */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert the date part of a 'struct calendar' (that is, year, month,  * day-of-month) into the RataDie of that day.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_date_to_rd
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
comment|/* jt */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given the number of elapsed days in the calendar era, split this  * number into the number of elapsed years in 'res.quot' and the  * number of elapsed days of that year in 'res.rem'.  *  * if 'isleapyear' is not NULL, it will receive an integer that is 0  * for regular years and a non-zero value for leap years.  */
end_comment

begin_function_decl
specifier|extern
name|ntpcal_split
name|ntpcal_split_eradays
parameter_list|(
name|int32_t
comment|/* days */
parameter_list|,
name|int
comment|/*BOOL*/
modifier|*
comment|/* isleapyear */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given a number of elapsed days in a year and a leap year indicator,  * split the number of elapsed days into the number of elapsed months  * in 'res.quot' and the number of elapsed days of that month in  * 'res.rem'.  */
end_comment

begin_function_decl
specifier|extern
name|ntpcal_split
name|ntpcal_split_yeardays
parameter_list|(
name|int32_t
comment|/* eyd */
parameter_list|,
name|int
comment|/*BOOL*/
comment|/* isleapyear */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a RataDie number into the date part of a 'struct  * calendar'. Return 0 if the year is regular year, !0 if the year is  * a leap year.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|ntpcal_rd_to_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jt */
parameter_list|,
name|int32_t
comment|/* rd */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a RataDie number into the date part of a 'struct  * tm'. Return 0 if the year is regular year, !0 if the year is a leap  * year.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|ntpcal_rd_to_tm
parameter_list|(
name|struct
name|tm
modifier|*
comment|/* utm */
parameter_list|,
name|int32_t
comment|/* rd */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Take a value of seconds since midnight and split it into hhmmss in  * a 'struct calendar'. Return excessive days.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_daysec_to_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jt */
parameter_list|,
name|int32_t
comment|/* secs */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Take the time part of a 'struct calendar' and return the seconds  * since midnight.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_date_to_daysec
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Take a value of seconds since midnight and split it into hhmmss in  * a 'struct tm'. Return excessive days.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_daysec_to_tm
parameter_list|(
name|struct
name|tm
modifier|*
comment|/* utm */
parameter_list|,
name|int32_t
comment|/* secs */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_tm_to_daysec
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
comment|/* utm */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * convert a year number to rata die of year start  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_year_to_ystart
parameter_list|(
name|int32_t
comment|/* year */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * For a given RataDie, get the RataDie of the associated year start,  * that is, the RataDie of the last January,1st on or before that day.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_rd_to_ystart
parameter_list|(
name|int32_t
comment|/* rd */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * convert a RataDie to the RataDie of start of the calendar month.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_rd_to_mstart
parameter_list|(
name|int32_t
comment|/* year */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpcal_daysplit_to_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jt */
parameter_list|,
specifier|const
name|ntpcal_split
modifier|*
comment|/* ds */
parameter_list|,
name|int32_t
comment|/* dof */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpcal_daysplit_to_tm
parameter_list|(
name|struct
name|tm
modifier|*
comment|/* utm */
parameter_list|,
specifier|const
name|ntpcal_split
modifier|*
comment|/* ds */
parameter_list|,
name|int32_t
comment|/* dof */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpcal_time_to_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|,
specifier|const
name|vint64
modifier|*
comment|/* ts */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_periodic_extend
parameter_list|(
name|int32_t
comment|/* pivot */
parameter_list|,
name|int32_t
comment|/* value */
parameter_list|,
name|int32_t
comment|/* cycle */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpcal_ntp64_to_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|,
specifier|const
name|vint64
modifier|*
comment|/* ntp */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpcal_ntp_to_date
parameter_list|(
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|,
name|uint32_t
comment|/* ntp */
parameter_list|,
specifier|const
name|time_t
modifier|*
comment|/* pivot */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|ntpcal_date_to_ntp64
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|ntpcal_date_to_ntp
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|ntpcal_date_to_time
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
comment|/* jd */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ISO week-calendar conversions  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|isocal_weeks_in_years
parameter_list|(
name|int32_t
comment|/* years */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ntpcal_split
name|isocal_split_eraweeks
parameter_list|(
name|int32_t
comment|/* weeks */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isocal_ntp64_to_date
parameter_list|(
name|struct
name|isodate
modifier|*
comment|/* id */
parameter_list|,
specifier|const
name|vint64
modifier|*
comment|/* ntp */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isocal_ntp_to_date
parameter_list|(
name|struct
name|isodate
modifier|*
comment|/* id */
parameter_list|,
name|uint32_t
comment|/* ntp */
parameter_list|,
specifier|const
name|time_t
modifier|*
comment|/* pivot */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|isocal_date_to_ntp64
parameter_list|(
specifier|const
name|struct
name|isodate
modifier|*
comment|/* id */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|isocal_date_to_ntp
parameter_list|(
specifier|const
name|struct
name|isodate
modifier|*
comment|/* id */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * day-of-week calculations  *  * Given a RataDie and a day-of-week, calculate a RDN that is reater-than,  * greater-or equal, closest, less-or-equal or less-than the given RDN  * and denotes the given day-of-week  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_weekday_gt
parameter_list|(
name|int32_t
comment|/* rdn */
parameter_list|,
name|int32_t
comment|/* dow */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_weekday_ge
parameter_list|(
name|int32_t
comment|/* rdn */
parameter_list|,
name|int32_t
comment|/* dow */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_weekday_close
parameter_list|(
name|int32_t
comment|/* rdn */
parameter_list|,
name|int32_t
comment|/* dow */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_weekday_le
parameter_list|(
name|int32_t
comment|/* rdn */
parameter_list|,
name|int32_t
comment|/* dow */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ntpcal_weekday_lt
parameter_list|(
name|int32_t
comment|/* rdn */
parameter_list|,
name|int32_t
comment|/* dow */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Additional support stuff for Ed Rheingold's calendrical calculations  */
end_comment

begin_comment
comment|/*  * Start day of NTP time as days past the imaginary date 12/1/1 BC.  * (This is the beginning of the Christian Era, or BCE.)  */
end_comment

begin_define
define|#
directive|define
name|DAY_NTP_STARTS
value|693596
end_define

begin_comment
comment|/*  * Start day of the UNIX epoch. This is the Rata Die of 1970-01-01.  */
end_comment

begin_define
define|#
directive|define
name|DAY_UNIX_STARTS
value|719163
end_define

begin_comment
comment|/*  * Difference between UN*X and NTP epoch (25567).  */
end_comment

begin_define
define|#
directive|define
name|NTP_TO_UNIX_DAYS
value|(DAY_UNIX_STARTS - DAY_NTP_STARTS)
end_define

begin_comment
comment|/*  * Days in a normal 4 year leap year calendar cycle (1461).  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_NORMAL_LEAP_CYCLE_DAYS
value|(3 * 365 + 366)
end_define

begin_comment
comment|/*  * Days in a normal 100 year leap year calendar (36524).  We lose a  * leap day in years evenly divisible by 100 but not by 400.  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_NORMAL_CENTURY_DAYS
define|\
value|(25 * GREGORIAN_NORMAL_LEAP_CYCLE_DAYS - 1)
end_define

begin_comment
comment|/*  * The Gregorian calendar is based on a 400 year cycle. This is the  * number of days in each cycle (146097).  We gain a leap day in years  * divisible by 400 relative to the "normal" century.  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_CYCLE_DAYS
value|(4 * GREGORIAN_NORMAL_CENTURY_DAYS + 1)
end_define

begin_comment
comment|/*  * Number of weeks in 400 years (20871).  */
end_comment

begin_define
define|#
directive|define
name|GREGORIAN_CYCLE_WEEKS
value|(GREGORIAN_CYCLE_DAYS / 7)
end_define

begin_define
define|#
directive|define
name|is_leapyear
parameter_list|(
name|y
parameter_list|)
value|(!((y) % 4)&& !(!((y) % 100)&& (y) % 400))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

