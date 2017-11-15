begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Mariusz Zaborski<oshogbo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAP_SYSLOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_CAP_SYSLOG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|void
name|cap_syslog
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|pri
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
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|cap_vsyslog
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|priority
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
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|cap_openlog
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
specifier|const
name|char
modifier|*
name|ident
parameter_list|,
name|int
name|logopt
parameter_list|,
name|int
name|facility
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cap_closelog
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_setlogmask
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|maskpri
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_syslog
parameter_list|(
name|chan
parameter_list|,
name|pri
parameter_list|,
modifier|...
parameter_list|)
value|syslog(pri, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|cap_vsyslog
parameter_list|(
name|chan
parameter_list|,
name|pri
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|vsyslog(pri, fmt, ap)
end_define

begin_define
define|#
directive|define
name|cap_openlog
parameter_list|(
name|chan
parameter_list|,
name|ident
parameter_list|,
name|logopt
parameter_list|,
name|facility
parameter_list|)
define|\
value|openlog(ident, logopt, facility)
end_define

begin_define
define|#
directive|define
name|cap_closelog
parameter_list|(
name|chan
parameter_list|)
value|closelog()
end_define

begin_define
define|#
directive|define
name|cap_setlogmask
parameter_list|(
name|chan
parameter_list|,
name|maskpri
parameter_list|)
value|setlogmask(maskpri)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WITH_CASPER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CAP_SYSLOG_H_ */
end_comment

end_unit

