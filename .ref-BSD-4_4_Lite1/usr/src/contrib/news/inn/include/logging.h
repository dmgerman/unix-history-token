begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.8 $ ** **  The logging levels in syslog(3) are confusing.  We use only three, **  and give them more meaningful names.  See section 2 in config.dist. */
end_comment

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_comment
comment|/* **  2.  LOGGING LEVELS */
end_comment

begin_comment
comment|/* Facility innd should log under. */
end_comment

begin_comment
comment|/* =()<#define LOG_INN_SERVER		@<LOG_INN_SERVER>@>()= */
end_comment

begin_define
define|#
directive|define
name|LOG_INN_SERVER
value|LOG_NEWS
end_define

begin_comment
comment|/* Facility all other programs should log under. */
end_comment

begin_comment
comment|/* =()<#define LOG_INN_PROG		@<LOG_INN_PROG>@>()= */
end_comment

begin_define
define|#
directive|define
name|LOG_INN_PROG
value|LOG_NEWS
end_define

begin_comment
comment|/* Flags to use in opening the logs; some programs add LOG_PID. */
end_comment

begin_comment
comment|/* =()<#define L_OPENLOG_FLAGS		@<L_OPENLOG_FLAGS>@>()= */
end_comment

begin_define
define|#
directive|define
name|L_OPENLOG_FLAGS
value|(LOG_CONS | LOG_NDELAY)
end_define

begin_comment
comment|/* Fatal error, program is about to exit. */
end_comment

begin_comment
comment|/* =()<#define L_FATAL		@<L_FATAL>@>()= */
end_comment

begin_define
define|#
directive|define
name|L_FATAL
value|LOG_CRIT
end_define

begin_comment
comment|/* Log an error that might mean one or more articles get lost. */
end_comment

begin_comment
comment|/* =()<#define L_ERROR		@<L_ERROR>@>()= */
end_comment

begin_define
define|#
directive|define
name|L_ERROR
value|LOG_ERR
end_define

begin_comment
comment|/* Informational notice, usually not worth caring about. */
end_comment

begin_comment
comment|/* =()<#define L_NOTICE		@<L_NOTICE>@>()= */
end_comment

begin_define
define|#
directive|define
name|L_NOTICE
value|LOG_WARNING
end_define

begin_comment
comment|/* A protocol trace. */
end_comment

begin_comment
comment|/* =()<#define L_TRACE		@<L_TRACE>@>()= */
end_comment

begin_define
define|#
directive|define
name|L_TRACE
value|LOG_DEBUG
end_define

begin_comment
comment|/* All incoming control commands (ctlinnd, etc). */
end_comment

begin_comment
comment|/* =()<#define L_CC_CMD		@<L_CC_CMD>@>()= */
end_comment

begin_define
define|#
directive|define
name|L_CC_CMD
value|LOG_INFO
end_define

end_unit

