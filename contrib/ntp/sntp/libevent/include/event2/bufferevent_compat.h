begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007-2012 Niels Provos, Nick Mathewson  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_BUFFEREVENT_COMPAT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_BUFFEREVENT_COMPAT_H_INCLUDED_
end_define

begin_define
define|#
directive|define
name|evbuffercb
value|bufferevent_data_cb
end_define

begin_define
define|#
directive|define
name|everrorcb
value|bufferevent_event_cb
end_define

begin_comment
comment|/**   Create a new bufferevent for an fd.    This function is deprecated.  Use bufferevent_socket_new and   bufferevent_set_callbacks instead.    Libevent provides an abstraction on top of the regular event callbacks.   This abstraction is called a buffered event.  A buffered event provides   input and output buffers that get filled and drained automatically.  The   user of a buffered event no longer deals directly with the I/O, but   instead is reading from input and writing to output buffers.    Once initialized, the bufferevent structure can be used repeatedly with   bufferevent_enable() and bufferevent_disable().    When read enabled the bufferevent will try to read from the file descriptor   and call the read callback.  The write callback is executed whenever the   output buffer is drained below the write low watermark, which is 0 by   default.    If multiple bases are in use, bufferevent_base_set() must be called before   enabling the bufferevent for the first time.    @deprecated This function is deprecated because it uses the current     event base, and as such can be error prone for multithreaded programs.     Use bufferevent_socket_new() instead.    @param fd the file descriptor from which data is read and written to. 	 This file descriptor is not allowed to be a pipe(2).   @param readcb callback to invoke when there is data to be read, or NULL if 	 no callback is desired   @param writecb callback to invoke when the file descriptor is ready for 	 writing, or NULL if no callback is desired   @param errorcb callback to invoke when there is an error on the file 	 descriptor   @param cbarg an argument that will be supplied to each of the callbacks 	 (readcb, writecb, and errorcb)   @return a pointer to a newly allocated bufferevent struct, or NULL if an 	  error occurred   @see bufferevent_base_set(), bufferevent_free()   */
end_comment

begin_function_decl
name|struct
name|bufferevent
modifier|*
name|bufferevent_new
parameter_list|(
name|evutil_socket_t
name|fd
parameter_list|,
name|evbuffercb
name|readcb
parameter_list|,
name|evbuffercb
name|writecb
parameter_list|,
name|everrorcb
name|errorcb
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the read and write timeout for a buffered event.    @param bufev the bufferevent to be modified   @param timeout_read the read timeout   @param timeout_write the write timeout  */
end_comment

begin_function_decl
name|void
name|bufferevent_settimeout
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|int
name|timeout_read
parameter_list|,
name|int
name|timeout_write
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|EVBUFFER_READ
value|BEV_EVENT_READING
end_define

begin_define
define|#
directive|define
name|EVBUFFER_WRITE
value|BEV_EVENT_WRITING
end_define

begin_define
define|#
directive|define
name|EVBUFFER_EOF
value|BEV_EVENT_EOF
end_define

begin_define
define|#
directive|define
name|EVBUFFER_ERROR
value|BEV_EVENT_ERROR
end_define

begin_define
define|#
directive|define
name|EVBUFFER_TIMEOUT
value|BEV_EVENT_TIMEOUT
end_define

begin_comment
comment|/** macro for getting access to the input buffer of a bufferevent */
end_comment

begin_define
define|#
directive|define
name|EVBUFFER_INPUT
parameter_list|(
name|x
parameter_list|)
value|bufferevent_get_input(x)
end_define

begin_comment
comment|/** macro for getting access to the output buffer of a bufferevent */
end_comment

begin_define
define|#
directive|define
name|EVBUFFER_OUTPUT
parameter_list|(
name|x
parameter_list|)
value|bufferevent_get_output(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

