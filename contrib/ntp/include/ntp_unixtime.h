begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_unixtime.h - much of what was here is now in timevalops.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_UNIXTIME_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_UNIXTIME_H
end_define

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/* picks up time.h via ntp_machine.h */
end_comment

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIM
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
value|(node_gettime(&ntp_node, a))
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
value|(node_settime(&ntp_node, a))
end_define

begin_define
define|#
directive|define
name|ADJTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(node_adjtime(&ntp_node, a, b))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ADJTIMEOFDAY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(adjtime(a, b))
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIM */
end_comment

begin_comment
comment|/*  * Time of day conversion constant.  Ntp's time scale starts in 1900,  * Unix in 1970.  The value is 1970 - 1900 in seconds, 0x83aa7e80 or  * 2208988800.  This is larger than 32-bit INT_MAX, so unsigned  * type is forced.  */
end_comment

begin_define
define|#
directive|define
name|JAN_1970
value|((u_int)NTP_TO_UNIX_DAYS * (u_int)SECSPERDAY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NTP_UNIXTIME_H) */
end_comment

end_unit

