begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 The FreeBSD Foundation  * Copyright (c) 2011 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PJDLOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_PJDLOG_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_define
define|#
directive|define
name|PJDLOG_MODE_STD
value|0
end_define

begin_define
define|#
directive|define
name|PJDLOG_MODE_SYSLOG
value|1
end_define

begin_define
define|#
directive|define
name|PJDLOG_MODE_SOCK
value|2
end_define

begin_function_decl
name|void
name|pjdlog_init
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pjdlog_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pjdlog_mode_set
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pjdlog_mode_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|void
name|pjdlog_sock_set
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pjdlog_sock_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|pjdlog_debug_set
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pjdlog_debug_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pjdlog_prefix_set
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
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
name|pjdlogv_prefix_set
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|pjdlog_prefix_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pjdlog_prefix_push
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
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
name|pjdlogv_prefix_push
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|pjdlog_prefix_pop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pjdlogv_common
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|loglevel
parameter_list|,
name|int
name|debuglevel
parameter_list|,
name|int
name|error
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|7
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_pjdlog_common
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|loglevel
parameter_list|,
name|int
name|debuglevel
parameter_list|,
name|int
name|error
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|7
operator|,
function_decl|8
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|_pjdlogv_exit
argument_list|(
specifier|const
name|char
operator|*
name|func
argument_list|,
specifier|const
name|char
operator|*
name|file
argument_list|,
name|int
name|line
argument_list|,
name|int
name|exitcode
argument_list|,
name|int
name|error
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|ap
argument_list|)
name|__printflike
argument_list|(
literal|6
argument_list|,
literal|0
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_pjdlog_exit
argument_list|(
specifier|const
name|char
operator|*
name|func
argument_list|,
specifier|const
name|char
operator|*
name|file
argument_list|,
name|int
name|line
argument_list|,
name|int
name|exitcode
argument_list|,
name|int
name|error
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|__printflike
argument_list|(
literal|6
argument_list|,
literal|7
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_pjdlog_abort
argument_list|(
specifier|const
name|char
operator|*
name|func
argument_list|,
specifier|const
name|char
operator|*
name|file
argument_list|,
name|int
name|line
argument_list|,
name|int
name|error
argument_list|,
specifier|const
name|char
operator|*
name|failedexpr
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|__printflike
argument_list|(
literal|6
argument_list|,
literal|7
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|int
name|pjdlog_receive
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pjdlogv_common
parameter_list|(
name|loglevel
parameter_list|,
name|debuglevel
parameter_list|,
name|error
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
define|\
value|_pjdlogv_common(__func__, __FILE__, __LINE__, (loglevel),	\ 	    (debuglevel), (error), (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_common
parameter_list|(
name|loglevel
parameter_list|,
name|debuglevel
parameter_list|,
name|error
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_pjdlog_common(__func__, __FILE__, __LINE__, (loglevel),	\ 	    (debuglevel), (error), __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv
parameter_list|(
name|loglevel
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
define|\
value|pjdlogv_common((loglevel), 0, -1, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog
parameter_list|(
name|loglevel
parameter_list|,
modifier|...
parameter_list|)
define|\
value|pjdlog_common((loglevel), 0, -1, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_emergency
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_EMERG, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_emergency
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_EMERG, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_alert
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_ALERT, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_alert
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_ALERT, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_critical
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_CRIT, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_critical
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_CRIT, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_error
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_ERR, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_error
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_ERR, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_warning
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_WARNING, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_warning
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_WARNING, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_notice
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_NOTICE, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_notice
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_NOTICE, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_info
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|pjdlogv(LOG_INFO, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_info
parameter_list|(
modifier|...
parameter_list|)
value|pjdlog(LOG_INFO, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlog_debug
parameter_list|(
name|debuglevel
parameter_list|,
modifier|...
parameter_list|)
define|\
value|pjdlog_common(LOG_DEBUG, (debuglevel), -1, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_debug
parameter_list|(
name|debuglevel
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
define|\
value|pjdlogv_common(LOG_DEBUG, (debuglevel), -1, (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_errno
parameter_list|(
name|loglevel
parameter_list|,
modifier|...
parameter_list|)
define|\
value|pjdlog_common((loglevel), 0, (errno), __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_errno
parameter_list|(
name|loglevel
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
define|\
value|pjdlogv_common((loglevel), 0, (errno), (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlogv_exit
parameter_list|(
name|exitcode
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
define|\
value|_pjdlogv_exit(__func__, __FILE__, __LINE__, (exitcode),		\ 	    (errno), (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_exit
parameter_list|(
name|exitcode
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_pjdlog_exit(__func__, __FILE__, __LINE__, (exitcode), (errno),	\ 	    __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pjdlogv_exitx
parameter_list|(
name|exitcode
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
define|\
value|_pjdlogv_exit(__func__, __FILE__, __LINE__, (exitcode), -1,	\ 	    (fmt), (ap))
end_define

begin_define
define|#
directive|define
name|pjdlog_exitx
parameter_list|(
name|exitcode
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_pjdlog_exit(__func__, __FILE__, __LINE__, (exitcode), -1,	\ 	    __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|PJDLOG_VERIFY
parameter_list|(
name|expr
parameter_list|)
value|do {					\ 	if (!(expr)) {							\ 		_pjdlog_abort(__func__, __FILE__, __LINE__, -1, #expr,	\ 		    __func__);						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|PJDLOG_RVERIFY
parameter_list|(
name|expr
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (!(expr)) {							\ 		_pjdlog_abort(__func__, __FILE__, __LINE__, -1, #expr,	\ 		    __VA_ARGS__);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|PJDLOG_EVERIFY
parameter_list|(
name|expr
parameter_list|)
value|do {				\ 	if (!(expr)) {							\ 		_pjdlog_abort(__func__, __FILE__, __LINE__, errno,	\ 		    #expr, __func__);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|PJDLOG_ABORT
parameter_list|(
modifier|...
parameter_list|)
value|_pjdlog_abort(__func__, __FILE__,	\ 				    __LINE__, -1, NULL, __VA_ARGS__)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|PJDLOG_ASSERT
parameter_list|(
name|expr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|PJDLOG_RASSERT
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PJDLOG_ASSERT
parameter_list|(
name|expr
parameter_list|)
value|do {					\ 	if (!(expr)) {							\ 		_pjdlog_abort(__func__, __FILE__, __LINE__, -1, #expr,	\ 		    __func__);						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|PJDLOG_RASSERT
parameter_list|(
name|expr
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (!(expr)) {							\ 		_pjdlog_abort(__func__, __FILE__, __LINE__, -1, #expr,	\ 		    __VA_ARGS__);					\ 	}								\ } while (0)
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
comment|/* !_PJDLOG_H_ */
end_comment

end_unit

