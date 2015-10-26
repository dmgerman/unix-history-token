begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_BUFFEREVENT_SSL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_BUFFEREVENT_SSL_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/bufferevent_ssl.h      OpenSSL support for bufferevents.  */
end_comment

begin_include
include|#
directive|include
file|<event2/visibility.h>
end_include

begin_include
include|#
directive|include
file|<event2/event-config.h>
end_include

begin_include
include|#
directive|include
file|<event2/bufferevent.h>
end_include

begin_include
include|#
directive|include
file|<event2/util.h>
end_include

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
comment|/* This is what openssl's SSL objects are underneath. */
struct_decl|struct
name|ssl_st
struct_decl|;
comment|/**    The state of an SSL object to be used when creating a new    SSL bufferevent.  */
enum|enum
name|bufferevent_ssl_state
block|{
name|BUFFEREVENT_SSL_OPEN
init|=
literal|0
block|,
name|BUFFEREVENT_SSL_CONNECTING
init|=
literal|1
block|,
name|BUFFEREVENT_SSL_ACCEPTING
init|=
literal|2
block|}
enum|;
if|#
directive|if
name|defined
argument_list|(
name|EVENT__HAVE_OPENSSL
argument_list|)
operator|||
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
comment|/**    Create a new SSL bufferevent to send its data over another bufferevent.     @param base An event_base to use to detect reading and writing.  It       must also be the base for the underlying bufferevent.    @param underlying A socket to use for this SSL    @param ssl A SSL* object from openssl.    @param state The current state of the SSL connection    @param options One or more bufferevent_options    @return A new bufferevent on success, or NULL on failure */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|bufferevent
modifier|*
name|bufferevent_openssl_filter_new
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|struct
name|bufferevent
modifier|*
name|underlying
parameter_list|,
name|struct
name|ssl_st
modifier|*
name|ssl
parameter_list|,
name|enum
name|bufferevent_ssl_state
name|state
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
comment|/**    Create a new SSL bufferevent to send its data over an SSL * on a socket.     @param base An event_base to use to detect reading and writing    @param fd A socket to use for this SSL    @param ssl A SSL* object from openssl.    @param state The current state of the SSL connection    @param options One or more bufferevent_options    @return A new bufferevent on success, or NULL on failure. */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|bufferevent
modifier|*
name|bufferevent_openssl_socket_new
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|,
name|struct
name|ssl_st
modifier|*
name|ssl
parameter_list|,
name|enum
name|bufferevent_ssl_state
name|state
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
comment|/** Control how to report dirty SSL shutdowns.      If the peer (or the network, or an attacker) closes the TCP     connection before closing the SSL channel, and the protocol is SSL>= v3,     this is a "dirty" shutdown.  If allow_dirty_shutdown is 0 (default),     this is reported as BEV_EVENT_ERROR.      If instead allow_dirty_shutdown=1, a dirty shutdown is reported as     BEV_EVENT_EOF.      (Note that if the protocol is< SSLv3, you will always receive     BEV_EVENT_EOF, since SSL 2 and earlier cannot distinguish a secure     connection close from a dirty one.  This is one reason (among many)     not to use SSL 2.) */
name|EVENT2_EXPORT_SYMBOL
name|int
name|bufferevent_openssl_get_allow_dirty_shutdown
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
name|EVENT2_EXPORT_SYMBOL
name|void
name|bufferevent_openssl_set_allow_dirty_shutdown
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|,
name|int
name|allow_dirty_shutdown
parameter_list|)
function_decl|;
comment|/** Return the underlying openssl SSL * object for an SSL bufferevent. */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|ssl_st
modifier|*
name|bufferevent_openssl_get_ssl
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|)
function_decl|;
comment|/** Tells a bufferevent to begin SSL renegotiation. */
name|EVENT2_EXPORT_SYMBOL
name|int
name|bufferevent_ssl_renegotiate
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
comment|/** Return the most recent OpenSSL error reported on an SSL bufferevent. */
name|EVENT2_EXPORT_SYMBOL
name|unsigned
name|long
name|bufferevent_get_openssl_error
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
endif|#
directive|endif
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
comment|/* EVENT2_BUFFEREVENT_SSL_H_INCLUDED_ */
end_comment

end_unit

