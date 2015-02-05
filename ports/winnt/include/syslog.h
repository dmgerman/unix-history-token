begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* From BIND 9 lib/isc/include/isc/: syslog.h,v 1.4 2002/08/01 03:43:31 mayer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSLOG_H
end_ifndef

begin_define
define|#
directive|define
name|_SYSLOG_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Constant definitions for openlog() */
end_comment

begin_define
define|#
directive|define
name|LOG_PID
value|1
end_define

begin_define
define|#
directive|define
name|LOG_CONS
value|2
end_define

begin_comment
comment|/* NT event log does not support facility level */
end_comment

begin_define
define|#
directive|define
name|LOG_KERN
value|0
end_define

begin_define
define|#
directive|define
name|LOG_USER
value|0
end_define

begin_define
define|#
directive|define
name|LOG_MAIL
value|0
end_define

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_define
define|#
directive|define
name|LOG_AUTH
value|0
end_define

begin_define
define|#
directive|define
name|LOG_SYSLOG
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LPR
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL0
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL1
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL2
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL3
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL4
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL5
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL6
value|0
end_define

begin_define
define|#
directive|define
name|LOG_LOCAL7
value|0
end_define

begin_define
define|#
directive|define
name|LOG_EMERG
value|0
end_define

begin_comment
comment|/* system is unusable */
end_comment

begin_define
define|#
directive|define
name|LOG_ALERT
value|1
end_define

begin_comment
comment|/* action must be taken immediately */
end_comment

begin_define
define|#
directive|define
name|LOG_CRIT
value|2
end_define

begin_comment
comment|/* critical conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_ERR
value|3
end_define

begin_comment
comment|/* error conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_WARNING
value|4
end_define

begin_comment
comment|/* warning conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_NOTICE
value|5
end_define

begin_comment
comment|/* normal but signification condition */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO
value|6
end_define

begin_comment
comment|/* informational */
end_comment

begin_define
define|#
directive|define
name|LOG_DEBUG
value|7
end_define

begin_comment
comment|/* debug-level messages */
end_comment

begin_comment
comment|/*  * These are ignored on NT  */
end_comment

begin_define
define|#
directive|define
name|LOG_NDELAY
value|0
end_define

begin_comment
comment|/* Open the connection to syslogd immediately */
end_comment

begin_define
define|#
directive|define
name|LOG_UPTO
parameter_list|(
name|pri
parameter_list|)
value|((1<< ((pri)+1)) - 1)
end_define

begin_comment
comment|/* all priorities through pri */
end_comment

begin_function_decl
name|void
name|syslog
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openlog
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closelog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ModifyLogLevel
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setlogmask
parameter_list|(
name|int
name|maskpri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InitNTLogging
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NTReportError
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

