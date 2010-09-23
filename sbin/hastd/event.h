begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
end_define

begin_define
define|#
directive|define
name|EVENT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EVENT_CONNECT
value|1
end_define

begin_define
define|#
directive|define
name|EVENT_DISCONNECT
value|2
end_define

begin_define
define|#
directive|define
name|EVENT_SYNCSTART
value|3
end_define

begin_define
define|#
directive|define
name|EVENT_SYNCDONE
value|4
end_define

begin_define
define|#
directive|define
name|EVENT_SYNCINTR
value|5
end_define

begin_define
define|#
directive|define
name|EVENT_SPLITBRAIN
value|6
end_define

begin_define
define|#
directive|define
name|EVENT_MIN
value|EVENT_CONNECT
end_define

begin_define
define|#
directive|define
name|EVENT_MAX
value|EVENT_SPLITBRAIN
end_define

begin_function_decl
name|void
name|event_send
parameter_list|(
specifier|const
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|event_recv
parameter_list|(
specifier|const
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_EVENT_H_ */
end_comment

end_unit

