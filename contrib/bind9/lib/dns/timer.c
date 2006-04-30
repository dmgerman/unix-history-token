begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: timer.c,v 1.2.206.1 2004/03/06 08:13:46 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<isc/time.h>
end_include

begin_include
include|#
directive|include
file|<isc/timer.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/timer.h>
end_include

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|op
parameter_list|)
define|\
value|do { result = (op);					\ 		if (result != ISC_R_SUCCESS) goto failure;	\ 	} while (0)
end_define

begin_function
name|isc_result_t
name|dns_timer_setidle
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|,
name|unsigned
name|int
name|maxtime
parameter_list|,
name|unsigned
name|int
name|idletime
parameter_list|,
name|isc_boolean_t
name|purge
parameter_list|)
block|{
name|isc_result_t
name|result
decl_stmt|;
name|isc_interval_t
name|maxinterval
decl_stmt|,
name|idleinterval
decl_stmt|;
name|isc_time_t
name|expires
decl_stmt|;
comment|/* Compute the time of expiry. */
name|isc_interval_set
argument_list|(
operator|&
name|maxinterval
argument_list|,
name|maxtime
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|CHECK
argument_list|(
name|isc_time_nowplusinterval
argument_list|(
operator|&
name|expires
argument_list|,
operator|&
name|maxinterval
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Compute the idle interval, and add a spare nanosecond to 	 * work around the silly limitation of the ISC timer interface 	 * that you cannot specify an idle interval of zero. 	 */
name|isc_interval_set
argument_list|(
operator|&
name|idleinterval
argument_list|,
name|idletime
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|CHECK
argument_list|(
name|isc_timer_reset
argument_list|(
name|timer
argument_list|,
name|isc_timertype_once
argument_list|,
operator|&
name|expires
argument_list|,
operator|&
name|idleinterval
argument_list|,
name|purge
argument_list|)
argument_list|)
expr_stmt|;
name|failure
label|:
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

end_unit

