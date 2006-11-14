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

begin_function
name|u_long
name|caltontp
parameter_list|(
specifier|register
specifier|const
name|struct
name|calendar
modifier|*
name|jt
parameter_list|)
block|{
name|u_long
name|ace_days
decl_stmt|;
comment|/* absolute Christian Era days */
name|u_long
name|ntp_days
decl_stmt|;
name|int
name|prior_years
decl_stmt|;
name|u_long
name|ntp_time
decl_stmt|;
comment|/*      * First convert today's date to absolute days past 12/1/1 BC      */
name|prior_years
operator|=
name|jt
operator|->
name|year
operator|-
literal|1
expr_stmt|;
name|ace_days
operator|=
name|jt
operator|->
name|yearday
comment|/* days this year */
operator|+
operator|(
name|DAYSPERYEAR
operator|*
name|prior_years
operator|)
comment|/* plus days in previous years */
operator|+
operator|(
name|prior_years
operator|/
literal|4
operator|)
comment|/* plus prior years's leap days */
operator|-
operator|(
name|prior_years
operator|/
literal|100
operator|)
comment|/* minus leapless century years */
operator|+
operator|(
name|prior_years
operator|/
literal|400
operator|)
expr_stmt|;
comment|/* plus leapful Gregorian yrs */
comment|/*      * Subtract out 1/1/1900, the beginning of the NTP epoch      */
name|ntp_days
operator|=
name|ace_days
operator|-
name|DAY_NTP_STARTS
expr_stmt|;
comment|/*      * Do the obvious:      */
name|ntp_time
operator|=
name|ntp_days
operator|*
name|SECSPERDAY
operator|+
name|SECSPERMIN
operator|*
operator|(
name|MINSPERHR
operator|*
name|jt
operator|->
name|hour
operator|+
name|jt
operator|->
name|minute
operator|)
expr_stmt|;
return|return
name|ntp_time
return|;
block|}
end_function

end_unit

