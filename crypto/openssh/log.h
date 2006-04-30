begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: log.h,v 1.11 2004/06/21 22:02:58 djm Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|SSH_LOG_H
end_define

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_comment
comment|/* Needed for LOG_AUTHPRIV (if present) */
end_comment

begin_comment
comment|/* Supported syslog facilities and levels. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SYSLOG_FACILITY_DAEMON
block|,
name|SYSLOG_FACILITY_USER
block|,
name|SYSLOG_FACILITY_AUTH
block|,
ifdef|#
directive|ifdef
name|LOG_AUTHPRIV
name|SYSLOG_FACILITY_AUTHPRIV
block|,
endif|#
directive|endif
name|SYSLOG_FACILITY_LOCAL0
block|,
name|SYSLOG_FACILITY_LOCAL1
block|,
name|SYSLOG_FACILITY_LOCAL2
block|,
name|SYSLOG_FACILITY_LOCAL3
block|,
name|SYSLOG_FACILITY_LOCAL4
block|,
name|SYSLOG_FACILITY_LOCAL5
block|,
name|SYSLOG_FACILITY_LOCAL6
block|,
name|SYSLOG_FACILITY_LOCAL7
block|,
name|SYSLOG_FACILITY_NOT_SET
init|=
operator|-
literal|1
block|}
name|SyslogFacility
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SYSLOG_LEVEL_QUIET
block|,
name|SYSLOG_LEVEL_FATAL
block|,
name|SYSLOG_LEVEL_ERROR
block|,
name|SYSLOG_LEVEL_INFO
block|,
name|SYSLOG_LEVEL_VERBOSE
block|,
name|SYSLOG_LEVEL_DEBUG1
block|,
name|SYSLOG_LEVEL_DEBUG2
block|,
name|SYSLOG_LEVEL_DEBUG3
block|,
name|SYSLOG_LEVEL_NOT_SET
init|=
operator|-
literal|1
block|}
name|LogLevel
typedef|;
end_typedef

begin_function_decl
name|void
name|log_init
parameter_list|(
name|char
modifier|*
parameter_list|,
name|LogLevel
parameter_list|,
name|SyslogFacility
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SyslogFacility
name|log_facility_number
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LogLevel
name|log_level_number
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fatal
value|ssh_fatal
end_define

begin_define
define|#
directive|define
name|error
value|ssh_error
end_define

begin_define
define|#
directive|define
name|logit
value|ssh_logit
end_define

begin_define
define|#
directive|define
name|verbose
value|ssh_verbose
end_define

begin_define
define|#
directive|define
name|debug
value|ssh_debug
end_define

begin_define
define|#
directive|define
name|debug2
value|ssh_debug2
end_define

begin_define
define|#
directive|define
name|debug3
value|ssh_debug3
end_define

begin_decl_stmt
name|void
name|fatal
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__dead
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|logit
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|verbose
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug3
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|do_log
parameter_list|(
name|LogLevel
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|cleanup_exit
argument_list|(
name|int
argument_list|)
name|__dead
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

