begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * caltontp - convert a date to an NTP time  */
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
file|"ntp_assert.h"
end_include

begin_comment
comment|/*  * Juergen Perlinger, 2008-11-12  * Add support for full calendar calculatios. If the day-of-year is provided  * (that is, not zero) it will be used instead of month and day-of-month;  * otherwise a full turn through the calendar calculations will be taken.  *  * I know that Harlan Stenn likes to see assertions in production code, and I  * agree there, but it would be a tricky thing here. The algorithm is quite  * capable of producing sensible answers even to seemingly weird inputs: the  * date<any year here>-03-00, the 0.th March of the year, will be automtically  * treated as the last day of February, no matter whether the year is a leap  * year or not. So adding constraints is merely for the benefit of the callers,  * because the only thing we can check for consistency is our input, produced  * by somebody else.  *  * BTW: A total roundtrip using 'caljulian' would be a quite shaky thing:  * Because of the truncation of the NTP time stamp to 32 bits and the epoch  * unfolding around the current time done by 'caljulian' the roundtrip does  * *not* necessarily reproduce the input, especially if the time spec is more  * than 68 years off from the current time...  */
end_comment

begin_function
name|u_long
name|caltontp
parameter_list|(
specifier|const
name|struct
name|calendar
modifier|*
name|jt
parameter_list|)
block|{
name|ntp_u_int32_t
name|days
decl_stmt|;
comment|/* full days in NTP epoch */
name|ntp_u_int32_t
name|years
decl_stmt|;
comment|/* complete ACE years before date */
name|ntp_u_int32_t
name|month
decl_stmt|;
comment|/* adjusted month for calendar */
name|NTP_INSIST
argument_list|(
name|jt
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|NTP_REQUIRE
argument_list|(
name|jt
operator|->
name|month
operator|<=
literal|13
argument_list|)
expr_stmt|;
comment|/* permit month 0..13! */
name|NTP_REQUIRE
argument_list|(
name|jt
operator|->
name|monthday
operator|<=
literal|32
argument_list|)
expr_stmt|;
name|NTP_REQUIRE
argument_list|(
name|jt
operator|->
name|yearday
operator|<=
literal|366
argument_list|)
expr_stmt|;
name|NTP_REQUIRE
argument_list|(
name|jt
operator|->
name|hour
operator|<=
literal|24
argument_list|)
expr_stmt|;
name|NTP_REQUIRE
argument_list|(
name|jt
operator|->
name|minute
operator|<=
name|MINSPERHR
argument_list|)
expr_stmt|;
name|NTP_REQUIRE
argument_list|(
name|jt
operator|->
name|second
operator|<=
name|SECSPERMIN
argument_list|)
expr_stmt|;
comment|/* 	 * First convert the date to fully elapsed days since NTP epoch. The 	 * expressions used here give us initially days since 0001-01-01, the 	 * beginning of the christian era in the proleptic gregorian calendar; 	 * they are rebased on-the-fly into days since beginning of the NTP 	 * epoch, 1900-01-01. 	 */
if|if
condition|(
name|jt
operator|->
name|yearday
condition|)
block|{
comment|/* 		 * Assume that the day-of-year contains a useable value and 		 * avoid all calculations involving month and day-of-month. 		 */
name|years
operator|=
name|jt
operator|->
name|year
operator|-
literal|1
expr_stmt|;
name|days
operator|=
name|years
operator|*
name|DAYSPERYEAR
comment|/* days in previous years */
operator|+
name|years
operator|/
literal|4
comment|/* plus prior years's leap days */
operator|-
name|years
operator|/
literal|100
comment|/* minus leapless century years */
operator|+
name|years
operator|/
literal|400
comment|/* plus leapful Gregorian yrs */
operator|+
name|jt
operator|->
name|yearday
comment|/* days this year */
operator|-
name|DAY_NTP_STARTS
expr_stmt|;
comment|/* rebase to NTP epoch */
block|}
else|else
block|{
comment|/* 		 * The following code is according to the excellent book 		 * 'Calendrical Calculations' by Nachum Dershowitz and Edward 		 * Reingold. It does a full calendar evaluation, using one of 		 * the alternate algorithms: Shift to a hypothetical year 		 * starting on the previous march,1st; merge years, month and 		 * days; undo the the 9 month shift (which is 306 days). The 		 * advantage is that we do NOT need to now whether a year is a 		 * leap year or not, because the leap day is the LAST day of 		 * the year. 		 */
name|month
operator|=
operator|(
name|ntp_u_int32_t
operator|)
name|jt
operator|->
name|month
operator|+
literal|9
expr_stmt|;
name|years
operator|=
name|jt
operator|->
name|year
operator|-
literal|1
operator|+
name|month
operator|/
literal|12
expr_stmt|;
name|month
operator|%=
literal|12
expr_stmt|;
name|days
operator|=
name|years
operator|*
name|DAYSPERYEAR
comment|/* days in previous years */
operator|+
name|years
operator|/
literal|4
comment|/* plus prior years's leap days */
operator|-
name|years
operator|/
literal|100
comment|/* minus leapless century years */
operator|+
name|years
operator|/
literal|400
comment|/* plus leapful Gregorian yrs */
operator|+
operator|(
name|month
operator|*
literal|153
operator|+
literal|2
operator|)
operator|/
literal|5
comment|/* plus days before month */
operator|+
name|jt
operator|->
name|monthday
comment|/* plus day-of-month */
operator|-
literal|306
comment|/* minus 9 months */
operator|-
name|DAY_NTP_STARTS
expr_stmt|;
comment|/* rebase to NTP epoch */
block|}
comment|/* 	 * Do the obvious: Merge everything together, making sure integer 	 * promotion doesn't play dirty tricks on us; there is probably some 	 * redundancy in the casts, but this drives it home with force. All 	 * arithmetic is done modulo 2**32, because the result is truncated 	 * anyway. 	 */
return|return
name|days
operator|*
name|SECSPERDAY
operator|+
operator|(
name|ntp_u_int32_t
operator|)
name|jt
operator|->
name|hour
operator|*
name|MINSPERHR
operator|*
name|SECSPERMIN
operator|+
operator|(
name|ntp_u_int32_t
operator|)
name|jt
operator|->
name|minute
operator|*
name|SECSPERMIN
operator|+
operator|(
name|ntp_u_int32_t
operator|)
name|jt
operator|->
name|second
return|;
block|}
end_function

end_unit

