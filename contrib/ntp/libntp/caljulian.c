begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * caljulian - determine the Julian date from an NTP time.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * calmonthtab - days-in-the-month table  */
end_comment

begin_comment
unit|static u_short calmonthtab[11] = { 	JAN, 	FEB, 	MAR, 	APR, 	MAY, 	JUN, 	JUL, 	AUG, 	SEP, 	OCT, 	NOV };  void caljulian( 	u_long		  		ntptime, 	register struct calendar	*jt 	) { 	u_long ntp_day; 	u_long minutes;
comment|/* 	 * Absolute, zero-adjusted Christian era day, starting from the 	 * mythical day 12/1/1 BC 	 */
end_comment

begin_comment
unit|u_long acez_day;  	u_long d400;
comment|/* Days into a Gregorian cycle */
end_comment

begin_comment
unit|u_long d100;
comment|/* Days into a normal century */
end_comment

begin_comment
unit|u_long d4;
comment|/* Days into a 4-year cycle */
end_comment

begin_comment
unit|u_long n400;
comment|/* # of Gregorian cycles */
end_comment

begin_comment
unit|u_long n100;
comment|/* # of normal centuries */
end_comment

begin_comment
unit|u_long n4;
comment|/* # of 4-year cycles */
end_comment

begin_comment
unit|u_long n1;
comment|/* # of years into a leap year */
end_comment

begin_comment
comment|/*   cycle */
end_comment

begin_comment
comment|/* 	 * Do the easy stuff first: take care of hh:mm:ss, ignoring leap 	 * seconds 	 */
end_comment

begin_comment
unit|jt->second = (u_char)(ntptime % SECSPERMIN); 	minutes    = ntptime / SECSPERMIN; 	jt->minute = (u_char)(minutes % MINSPERHR); 	jt->hour   = (u_char)((minutes / MINSPERHR) % HRSPERDAY);
comment|/* 	 * Find the day past 1900/01/01 00:00 UTC 	 */
end_comment

begin_comment
unit|ntp_day = ntptime / SECSPERDAY; 	acez_day = DAY_NTP_STARTS + ntp_day - 1; 	n400	 = acez_day/GREGORIAN_CYCLE_DAYS; 	d400	 = acez_day%GREGORIAN_CYCLE_DAYS; 	n100	 = d400 / GREGORIAN_NORMAL_CENTURY_DAYS; 	d100	 = d400 % GREGORIAN_NORMAL_CENTURY_DAYS; 	n4		 = d100 / GREGORIAN_NORMAL_LEAP_CYCLE_DAYS; 	d4		 = d100 % GREGORIAN_NORMAL_LEAP_CYCLE_DAYS; 	n1		 = d4 / DAYSPERYEAR;
comment|/* 	 * Calculate the year and year-of-day 	 */
end_comment

begin_comment
unit|jt->yearday = (u_short)(1 + d4%DAYSPERYEAR); 	jt->year	= (u_short)(400*n400 + 100*n100 + n4*4 + n1);  	if (n100 == 4 || n1 == 4) 	{
comment|/* 	 * If the cycle year ever comes out to 4, it must be December 31st 	 * of a leap year. 	 */
end_comment

begin_comment
unit|jt->month	 = 12; 	jt->monthday = 31; 	jt->yearday  = 366; 	} 	else 	{
comment|/* 	 * Else, search forwards through the months to get the right month 	 * and date. 	 */
end_comment

begin_else
unit|int monthday;  	jt->year++; 	monthday = jt->yearday;  	for (jt->month=0;jt->month<11; jt->month++) 	{ 		int t;  		t = monthday - calmonthtab[jt->month]; 		if (jt->month == 1&& is_leapyear(jt->year)) 		t--;  		if (t> 0) 		monthday = t; 		else 		break; 	} 	jt->month++; 	jt->monthday = (u_char) monthday; 	} }
else|#
directive|else
end_else

begin_comment
comment|/* Updated 2003-12-30 TMa     Uses common code with the *prettydate functions to convert an ntp    seconds count into a calendar date.    Will handle ntp epoch wraparound as long as the underlying os/library     does so for the unix epoch, i.e. works after 2038. */
end_comment

begin_function
name|void
name|caljulian
parameter_list|(
name|u_long
name|ntptime
parameter_list|,
specifier|register
name|struct
name|calendar
modifier|*
name|jt
parameter_list|)
block|{
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|tm
operator|=
name|ntp2unix_tm
argument_list|(
name|ntptime
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|jt
operator|->
name|hour
operator|=
operator|(
name|u_char
operator|)
name|tm
operator|->
name|tm_hour
expr_stmt|;
name|jt
operator|->
name|minute
operator|=
operator|(
name|u_char
operator|)
name|tm
operator|->
name|tm_min
expr_stmt|;
name|jt
operator|->
name|month
operator|=
call|(
name|u_char
call|)
argument_list|(
name|tm
operator|->
name|tm_mon
operator|+
literal|1
argument_list|)
expr_stmt|;
name|jt
operator|->
name|monthday
operator|=
operator|(
name|u_char
operator|)
name|tm
operator|->
name|tm_mday
expr_stmt|;
name|jt
operator|->
name|second
operator|=
operator|(
name|u_char
operator|)
name|tm
operator|->
name|tm_sec
expr_stmt|;
name|jt
operator|->
name|year
operator|=
call|(
name|u_short
call|)
argument_list|(
name|tm
operator|->
name|tm_year
operator|+
literal|1900
argument_list|)
expr_stmt|;
name|jt
operator|->
name|yearday
operator|=
call|(
name|u_short
call|)
argument_list|(
name|tm
operator|->
name|tm_yday
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Assumes tm_yday starts with day 0! */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

