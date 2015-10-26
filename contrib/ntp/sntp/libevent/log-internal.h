begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|LOG_INTERNAL_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|"event2/util.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|EV_CHECK_FMT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__attribute__((format(printf, a, b)))
end_define

begin_define
define|#
directive|define
name|EV_NORETURN
value|__attribute__((noreturn))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EV_CHECK_FMT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EV_NORETURN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EVENT_ERR_ABORT_
value|((int)0xdeaddead)
end_define

begin_define
define|#
directive|define
name|USE_GLOBAL_FOR_DEBUG_LOGGING
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVENT__DISABLE_DEBUG_MODE
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVENT_DEBUG_LOGGING_ENABLED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT_DEBUG_LOGGING_ENABLED
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GLOBAL_FOR_DEBUG_LOGGING
end_ifdef

begin_decl_stmt
specifier|extern
name|ev_uint32_t
name|event_debug_logging_mask_
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|event_debug_get_logging_mask_
parameter_list|()
value|(event_debug_logging_mask_)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|ev_uint32_t
name|event_debug_get_logging_mask_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|event_debug_get_logging_mask_
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|event_err
argument_list|(
name|int
name|eval
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|EV_CHECK_FMT
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
name|EV_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|event_warn
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|EV_CHECK_FMT
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|event_sock_err
argument_list|(
name|int
name|eval
argument_list|,
name|evutil_socket_t
name|sock
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|EV_CHECK_FMT
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
name|EV_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|event_sock_warn
parameter_list|(
name|evutil_socket_t
name|sock
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|EV_CHECK_FMT
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|event_errx
argument_list|(
name|int
name|eval
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|EV_CHECK_FMT
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
name|EV_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|event_warnx
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|EV_CHECK_FMT
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|event_msgx
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|EV_CHECK_FMT
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|event_debugx_
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|EV_CHECK_FMT
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|event_logv_
parameter_list|(
name|int
name|severity
parameter_list|,
specifier|const
name|char
modifier|*
name|errstr
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|EV_CHECK_FMT
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT_DEBUG_LOGGING_ENABLED
end_ifdef

begin_define
define|#
directive|define
name|event_debug
parameter_list|(
name|x
parameter_list|)
value|do {			\ 	if (event_debug_get_logging_mask_()) {	\ 		event_debugx_ x;		\ 	}					\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|event_debug
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|EV_CHECK_FMT
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

