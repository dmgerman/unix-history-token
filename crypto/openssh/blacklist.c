begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The NetBSD Foundation, Inc.  * Copyright (c) 2016 The FreeBSD Foundation, Inc.  * All rights reserved.  *  * Portions of this software were developed by Kurt Lidl  * under sponsorship from the FreeBSD Foundation.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
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
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"ssh.h"
end_include

begin_include
include|#
directive|include
file|"packet.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_include
include|#
directive|include
file|"servconf.h"
end_include

begin_include
include|#
directive|include
file|<blacklist.h>
end_include

begin_include
include|#
directive|include
file|"blacklist_client.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|blacklist
modifier|*
name|blstate
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* import */
end_comment

begin_decl_stmt
specifier|extern
name|ServerOptions
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* internal definition from bl.h */
end_comment

begin_function_decl
name|struct
name|blacklist
modifier|*
name|bl_create
parameter_list|(
name|bool
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* impedence match vsyslog() to sshd's internal logging levels */
end_comment

begin_function
name|void
name|im_log
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|va_list
name|args
parameter_list|)
block|{
name|LogLevel
name|imlevel
decl_stmt|;
switch|switch
condition|(
name|priority
condition|)
block|{
case|case
name|LOG_ERR
case|:
name|imlevel
operator|=
name|SYSLOG_LEVEL_ERROR
expr_stmt|;
break|break;
case|case
name|LOG_DEBUG
case|:
name|imlevel
operator|=
name|SYSLOG_LEVEL_DEBUG1
expr_stmt|;
break|break;
case|case
name|LOG_INFO
case|:
name|imlevel
operator|=
name|SYSLOG_LEVEL_INFO
expr_stmt|;
break|break;
default|default:
name|imlevel
operator|=
name|SYSLOG_LEVEL_DEBUG2
expr_stmt|;
block|}
name|do_log
argument_list|(
name|imlevel
argument_list|,
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|blacklist_init
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|options
operator|.
name|use_blacklist
condition|)
name|blstate
operator|=
name|bl_create
argument_list|(
name|false
argument_list|,
name|NULL
argument_list|,
name|im_log
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|blacklist_notify
parameter_list|(
name|int
name|action
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
name|blstate
operator|!=
name|NULL
operator|&&
name|packet_connection_is_on_socket
argument_list|()
condition|)
operator|(
name|void
operator|)
name|blacklist_r
argument_list|(
name|blstate
argument_list|,
name|action
argument_list|,
name|packet_get_connection_in
argument_list|()
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

