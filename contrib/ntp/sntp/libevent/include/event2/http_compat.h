begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_HTTP_COMPAT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_HTTP_COMPAT_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/http_compat.h    Potentially non-threadsafe versions of the functions in http.h: provided   only for backwards compatibility.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<event2/event-config.h>
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TYPES_H
include|#
directive|include
file|<sys/types.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TIME_H
include|#
directive|include
file|<sys/time.h>
endif|#
directive|endif
comment|/* For int types. */
include|#
directive|include
file|<event2/util.h>
comment|/**  * Start an HTTP server on the specified address and port  *  * @deprecated It does not allow an event base to be specified  *  * @param address the address to which the HTTP server should be bound  * @param port the port number on which the HTTP server should listen  * @return an struct evhttp object  */
name|struct
name|evhttp
modifier|*
name|evhttp_start
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
comment|/**  * A connection object that can be used to for making HTTP requests.  The  * connection object tries to establish the connection when it is given an  * http request object.  *  * @deprecated It does not allow an event base to be specified  */
name|struct
name|evhttp_connection
modifier|*
name|evhttp_connection_new
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
comment|/**  * Associates an event base with the connection - can only be called  * on a freshly created connection object that has not been used yet.  *  * @deprecated XXXX Why?  */
name|void
name|evhttp_connection_set_base
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
name|evcon
parameter_list|,
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
comment|/** Returns the request URI */
define|#
directive|define
name|evhttp_request_uri
value|evhttp_request_get_uri
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT2_EVENT_COMPAT_H_INCLUDED_ */
end_comment

end_unit

