begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/libntp/gpstolfp.c,v 4.3 1999/02/28 11:42:44 kardel RELEASE_19990228_A  *  * $Created: Sun Jun 28 16:30:38 1998 $  *  * Copyright (C) 1998 by Frank Kardel  */
end_comment

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_define
define|#
directive|define
name|GPSORIGIN
value|(unsigned)(2524953600L)
end_define

begin_comment
comment|/* NTP origin - GPS origin in seconds */
end_comment

begin_define
define|#
directive|define
name|SECSPERWEEK
value|(unsigned)(604800)
end_define

begin_comment
comment|/* seconds per week - GPS tells us about weeks */
end_comment

begin_define
define|#
directive|define
name|GPSWRAP
value|990
end_define

begin_comment
comment|/* assume week count less than this in the previous epoch */
end_comment

begin_function
name|void
name|gpstolfp
parameter_list|(
name|int
name|weeks
parameter_list|,
name|int
name|days
parameter_list|,
name|unsigned
name|long
name|seconds
parameter_list|,
name|l_fp
modifier|*
name|lfp
parameter_list|)
block|{
if|if
condition|(
name|weeks
operator|<
name|GPSWRAP
condition|)
block|{
name|weeks
operator|+=
literal|1024
expr_stmt|;
block|}
name|lfp
operator|->
name|l_ui
operator|=
name|weeks
operator|*
name|SECSPERWEEK
operator|+
name|days
operator|*
literal|86400
operator|+
name|seconds
operator|+
name|GPSORIGIN
expr_stmt|;
comment|/* convert to NTP time */
name|lfp
operator|->
name|l_uf
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * gpstolfp.c,v  * Revision 4.3  1999/02/28 11:42:44  kardel  * (GPSWRAP): update GPS rollover to 990 weeks  *  * Revision 4.2  1998/07/11 10:05:25  kardel  * Release 4.0.73d reconcilation  *  * Revision 4.1  1998/06/28 16:47:15  kardel  * added gpstolfp() function  */
end_comment

end_unit

