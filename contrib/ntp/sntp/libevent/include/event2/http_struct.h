begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_HTTP_STRUCT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_HTTP_STRUCT_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/http_struct.h    Data structures for http.  Using these structures may hurt forward   compatibility with later versions of Libevent: be careful!   */
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
comment|/**  * the request structure that a server receives.  * WARNING: expect this structure to change.  I will try to provide  * reasonable accessors.  */
struct|struct
name|evhttp_request
block|{
if|#
directive|if
name|defined
argument_list|(
name|TAILQ_ENTRY
argument_list|)
name|TAILQ_ENTRY
argument_list|(
argument|evhttp_request
argument_list|)
name|next
expr_stmt|;
else|#
directive|else
struct|struct
block|{
name|struct
name|evhttp_request
modifier|*
name|tqe_next
decl_stmt|;
name|struct
name|evhttp_request
modifier|*
modifier|*
name|tqe_prev
decl_stmt|;
block|}
name|next
struct|;
endif|#
directive|endif
comment|/* the connection object that this request belongs to */
name|struct
name|evhttp_connection
modifier|*
name|evcon
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/** The request obj owns the evhttp connection and needs to free it */
define|#
directive|define
name|EVHTTP_REQ_OWN_CONNECTION
value|0x0001
comment|/** Request was made via a proxy */
define|#
directive|define
name|EVHTTP_PROXY_REQUEST
value|0x0002
comment|/** The request object is owned by the user; the user must free it */
define|#
directive|define
name|EVHTTP_USER_OWNED
value|0x0004
comment|/** The request will be used again upstack; freeing must be deferred */
define|#
directive|define
name|EVHTTP_REQ_DEFER_FREE
value|0x0008
comment|/** The request should be freed upstack */
define|#
directive|define
name|EVHTTP_REQ_NEEDS_FREE
value|0x0010
name|struct
name|evkeyvalq
modifier|*
name|input_headers
decl_stmt|;
name|struct
name|evkeyvalq
modifier|*
name|output_headers
decl_stmt|;
comment|/* address of the remote host and the port connection came from */
name|char
modifier|*
name|remote_host
decl_stmt|;
name|ev_uint16_t
name|remote_port
decl_stmt|;
comment|/* cache of the hostname for evhttp_request_get_host */
name|char
modifier|*
name|host_cache
decl_stmt|;
name|enum
name|evhttp_request_kind
name|kind
decl_stmt|;
name|enum
name|evhttp_cmd_type
name|type
decl_stmt|;
name|size_t
name|headers_size
decl_stmt|;
name|size_t
name|body_size
decl_stmt|;
name|char
modifier|*
name|uri
decl_stmt|;
comment|/* uri after HTTP request was parsed */
name|struct
name|evhttp_uri
modifier|*
name|uri_elems
decl_stmt|;
comment|/* uri elements */
name|char
name|major
decl_stmt|;
comment|/* HTTP Major number */
name|char
name|minor
decl_stmt|;
comment|/* HTTP Minor number */
name|int
name|response_code
decl_stmt|;
comment|/* HTTP Response code */
name|char
modifier|*
name|response_code_line
decl_stmt|;
comment|/* Readable response */
name|struct
name|evbuffer
modifier|*
name|input_buffer
decl_stmt|;
comment|/* read data */
name|ev_int64_t
name|ntoread
decl_stmt|;
name|unsigned
name|chunked
range|:
literal|1
decl_stmt|,
comment|/* a chunked request */
name|userdone
range|:
literal|1
decl_stmt|;
comment|/* the user has sent all data */
name|struct
name|evbuffer
modifier|*
name|output_buffer
decl_stmt|;
comment|/* outgoing post or data */
comment|/* Callback */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/* 	 * Chunked data callback - call for each completed chunk if 	 * specified.  If not specified, all the data is delivered via 	 * the regular callback. 	 */
name|void
function_decl|(
modifier|*
name|chunk_cb
function_decl|)
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* 	 * Callback added for forked-daapd so they can collect ICY 	 * (shoutcast) metadata from the http header. If return 	 * int is negative the connection will be closed. 	 */
name|int
function_decl|(
modifier|*
name|header_cb
function_decl|)
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* 	 * Error callback - called when error is occured. 	 * @see evhttp_request_error for error types. 	 * 	 * @see evhttp_request_set_error_cb() 	 */
name|void
function_decl|(
modifier|*
name|error_cb
function_decl|)
parameter_list|(
name|enum
name|evhttp_request_error
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* 	 * Send complete callback - called when the request is actually 	 * sent and completed. 	 */
name|void
function_decl|(
modifier|*
name|on_complete_cb
function_decl|)
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|on_complete_cb_arg
decl_stmt|;
block|}
struct|;
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
comment|/* EVENT2_HTTP_STRUCT_H_INCLUDED_ */
end_comment

end_unit

