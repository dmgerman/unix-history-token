begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * event.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Hack to provide libevent (see devel/libevent port) like API.  * Should be removed if FreeBSD ever decides to import libevent into base.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_EVENT_H_
value|1
end_define

begin_define
define|#
directive|define
name|EV_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|EV_WRITE
value|0x04
end_define

begin_define
define|#
directive|define
name|EV_PERSIST
value|0x10
end_define

begin_comment
comment|/* Persistant event */
end_comment

begin_define
define|#
directive|define
name|EV_PENDING
value|(1<< 13)
end_define

begin_comment
comment|/* internal use only! */
end_comment

begin_define
define|#
directive|define
name|EV_HAS_TIMEOUT
value|(1<< 14)
end_define

begin_comment
comment|/* internal use only! */
end_comment

begin_define
define|#
directive|define
name|EV_CURRENT
value|(1<< 15)
end_define

begin_comment
comment|/* internal use only! */
end_comment

begin_struct
struct|struct
name|event
block|{
name|int
name|fd
decl_stmt|;
name|short
name|flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cbarg
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|struct
name|timeval
name|expire
decl_stmt|;
ifdef|#
directive|ifdef
name|EVENT_DEBUG
name|char
specifier|const
modifier|*
name|files
index|[
literal|3
index|]
decl_stmt|;
name|int
name|lines
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
name|TAILQ_ENTRY
argument_list|(
argument|event
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|event_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|event_dispatch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__event_set
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|,
name|int
parameter_list|,
name|short
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__event_add
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|,
name|struct
name|timeval
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__event_del
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|event_log_err
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_ERR, fmt, ##args)
end_define

begin_define
define|#
directive|define
name|event_log_info
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_INFO, fmt, ##args)
end_define

begin_define
define|#
directive|define
name|event_log_notice
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_NOTICE, fmt, ##args)
end_define

begin_define
define|#
directive|define
name|event_log_debug
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|syslog(LOG_DEBUG, fmt, ##args)
end_define

begin_define
define|#
directive|define
name|event_set
parameter_list|(
name|ev
parameter_list|,
name|fd
parameter_list|,
name|flags
parameter_list|,
name|cb
parameter_list|,
name|cbarg
parameter_list|)
define|\
value|_event_set(__FILE__, __LINE__, ev, fd, flags, cb, cbarg)
end_define

begin_define
define|#
directive|define
name|event_add
parameter_list|(
name|ev
parameter_list|,
name|timeout
parameter_list|)
define|\
value|_event_add(__FILE__, __LINE__, ev, timeout)
end_define

begin_define
define|#
directive|define
name|event_del
parameter_list|(
name|ev
parameter_list|)
define|\
value|_event_del(__FILE__, __LINE__, ev)
end_define

begin_define
define|#
directive|define
name|evtimer_set
parameter_list|(
name|ev
parameter_list|,
name|cb
parameter_list|,
name|cbarg
parameter_list|)
define|\
value|_event_set(__FILE__, __LINE__, ev, -1, 0, cb, cbarg)
end_define

begin_define
define|#
directive|define
name|evtimer_add
parameter_list|(
name|ev
parameter_list|,
name|timeout
parameter_list|)
define|\
value|_event_add(__FILE__, __LINE__, ev, timeout)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|_event_set
parameter_list|(
name|char
specifier|const
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|struct
name|event
modifier|*
name|ev
parameter_list|,
name|int
name|fd
parameter_list|,
name|short
name|flags
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
block|{
name|event_log_debug
argument_list|(
literal|"set %s:%d ev=%p, fd=%d, flags=%#x, cb=%p, cbarg=%p"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|ev
argument_list|,
name|fd
argument_list|,
name|flags
argument_list|,
name|cb
argument_list|,
name|cbarg
argument_list|)
expr_stmt|;
name|ev
operator|->
name|files
index|[
literal|0
index|]
operator|=
name|file
expr_stmt|;
name|ev
operator|->
name|lines
index|[
literal|0
index|]
operator|=
name|line
expr_stmt|;
name|__event_set
argument_list|(
name|ev
argument_list|,
name|fd
argument_list|,
name|flags
argument_list|,
name|cb
argument_list|,
name|cbarg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|_event_add
parameter_list|(
name|char
specifier|const
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|struct
name|event
modifier|*
name|ev
parameter_list|,
name|struct
name|timeval
specifier|const
modifier|*
name|timeout
parameter_list|)
block|{
name|event_log_debug
argument_list|(
literal|"add %s:%d ev=%p, fd=%d, flags=%#x, cb=%p, cbarg=%p, "
expr|\
literal|"timeout=%p"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|ev
argument_list|,
name|ev
operator|->
name|fd
argument_list|,
name|ev
operator|->
name|flags
argument_list|,
name|ev
operator|->
name|cb
argument_list|,
name|ev
operator|->
name|cbarg
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|ev
operator|->
name|files
index|[
literal|1
index|]
operator|=
name|file
expr_stmt|;
name|ev
operator|->
name|lines
index|[
literal|1
index|]
operator|=
name|line
expr_stmt|;
return|return
operator|(
name|__event_add
argument_list|(
name|ev
argument_list|,
name|timeout
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|_event_del
parameter_list|(
name|char
specifier|const
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|struct
name|event
modifier|*
name|ev
parameter_list|)
block|{
name|event_log_debug
argument_list|(
literal|"del %s:%d ev=%p, fd=%d, flags=%#x, cb=%p, cbarg=%p"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|ev
argument_list|,
name|ev
operator|->
name|fd
argument_list|,
name|ev
operator|->
name|flags
argument_list|,
name|ev
operator|->
name|cb
argument_list|,
name|ev
operator|->
name|cbarg
argument_list|)
expr_stmt|;
name|ev
operator|->
name|files
index|[
literal|2
index|]
operator|=
name|file
expr_stmt|;
name|ev
operator|->
name|lines
index|[
literal|2
index|]
operator|=
name|line
expr_stmt|;
return|return
operator|(
name|__event_del
argument_list|(
name|ev
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|event_log_err
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|event_log_info
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|event_log_notice
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|event_log_debug
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|event_set
parameter_list|(
name|ev
parameter_list|,
name|fd
parameter_list|,
name|flags
parameter_list|,
name|cb
parameter_list|,
name|cbarg
parameter_list|)
define|\
value|__event_set(ev, fd, flags, cb, cbarg)
end_define

begin_define
define|#
directive|define
name|event_add
parameter_list|(
name|ev
parameter_list|,
name|timeout
parameter_list|)
define|\
value|__event_add(ev, timeout)
end_define

begin_define
define|#
directive|define
name|event_del
parameter_list|(
name|ev
parameter_list|)
define|\
value|__event_del(ev)
end_define

begin_define
define|#
directive|define
name|evtimer_set
parameter_list|(
name|ev
parameter_list|,
name|cb
parameter_list|,
name|cbarg
parameter_list|)
define|\
value|__event_set(ev, -1, 0, cb, cbarg)
end_define

begin_define
define|#
directive|define
name|evtimer_add
parameter_list|(
name|ev
parameter_list|,
name|timeout
parameter_list|)
define|\
value|__event_add(ev, timeout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _EVENT_H_ */
end_comment

end_unit

