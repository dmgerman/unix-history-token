begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ymd2yd - compute the date in the year from y/m/d  *  * A thin wrapper around a more general calendar function.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_function
name|int
name|ymd2yd
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|d
parameter_list|)
block|{
comment|/* 	 * convert y/m/d to elapsed calendar units, convert that to 	 * elapsed days since the start of the given year and convert 	 * back to unity-based day in year. 	 * 	 * This does no further error checking, since the underlying 	 * function is assumed to work out how to handle the data. 	 */
return|return
name|ntpcal_edate_to_yeardays
argument_list|(
name|y
operator|-
literal|1
argument_list|,
name|m
operator|-
literal|1
argument_list|,
name|d
operator|-
literal|1
argument_list|)
operator|+
literal|1
return|;
block|}
end_function

end_unit

