begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gettstamp.c,v 3.1 1993/07/06 01:08:20 jbj Exp  * gettstamp - return the system time in timestamp format  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_function
name|void
name|gettstamp
parameter_list|(
name|ts
parameter_list|)
name|l_fp
modifier|*
name|ts
decl_stmt|;
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* 	 * Quickly get the time of day and convert it 	 */
operator|(
name|void
operator|)
name|GETTIMEOFDAY
argument_list|(
operator|&
name|tv
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|tv
operator|.
name|tv_usec
operator|>=
literal|1000000
condition|)
block|{
comment|/* bum solaris */
name|tv
operator|.
name|tv_usec
operator|-=
literal|1000000
expr_stmt|;
name|tv
operator|.
name|tv_sec
operator|++
expr_stmt|;
block|}
name|TVTOTS
argument_list|(
operator|&
name|tv
argument_list|,
name|ts
argument_list|)
expr_stmt|;
name|ts
operator|->
name|l_uf
operator|+=
name|TS_ROUNDBIT
expr_stmt|;
comment|/* guaranteed not to overflow */
name|ts
operator|->
name|l_ui
operator|+=
name|JAN_1970
expr_stmt|;
name|ts
operator|->
name|l_uf
operator|&=
name|TS_MASK
expr_stmt|;
block|}
end_function

end_unit

