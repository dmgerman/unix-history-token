begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: log.h,v 1.2 2001/01/29 01:58:16 niklas Exp $	*/
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
block|}
name|LogLevel
typedef|;
end_typedef

begin_comment
comment|/* Initializes logging. */
end_comment

begin_function_decl
name|void
name|log_init
parameter_list|(
name|char
modifier|*
name|av0
parameter_list|,
name|LogLevel
name|level
parameter_list|,
name|SyslogFacility
name|facility
parameter_list|,
name|int
name|on_stderr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Logging implementation, depending on server or client */
end_comment

begin_function_decl
name|void
name|do_log
parameter_list|(
name|LogLevel
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* name to facility/level */
end_comment

begin_function_decl
name|SyslogFacility
name|log_facility_number
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LogLevel
name|log_level_number
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output a message to syslog or stderr */
end_comment

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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
name|log
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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
name|fmt
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
name|fmt
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
name|fmt
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
name|fmt
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

begin_comment
comment|/* same as fatal() but w/o logging */
end_comment

begin_function_decl
name|void
name|fatal_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Registers a cleanup function to be called by fatal()/fatal_cleanup()  * before exiting. It is permissible to call fatal_remove_cleanup for the  * function itself from the function.  */
end_comment

begin_function_decl
name|void
name|fatal_add_cleanup
parameter_list|(
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Removes a cleanup function to be called at fatal(). */
end_comment

begin_function_decl
name|void
name|fatal_remove_cleanup
parameter_list|(
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

