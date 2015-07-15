begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LOG_H
end_ifndef

begin_define
define|#
directive|define
name|LOG_H
end_define

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* syslog as ntpd does, even though we are not a daemon */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LOG_NTP
end_ifdef

begin_define
define|#
directive|define
name|OPENLOG_FAC
value|LOG_NTP
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OPENLOG_FAC
value|LOG_DAEMON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|sntp_init_logging
parameter_list|(
specifier|const
name|char
modifier|*
name|program
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_logfile
parameter_list|(
specifier|const
name|char
modifier|*
name|logfile
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for msyslog use too */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

