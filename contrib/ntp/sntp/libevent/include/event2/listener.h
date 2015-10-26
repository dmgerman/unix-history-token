begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_LISTENER_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_LISTENER_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|<event2/visibility.h>
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
include|#
directive|include
file|<event2/event.h>
struct_decl|struct
name|sockaddr
struct_decl|;
struct_decl|struct
name|evconnlistener
struct_decl|;
comment|/**    A callback that we invoke when a listener has a new connection.     @param listener The evconnlistener    @param fd The new file descriptor    @param addr The source address of the connection    @param socklen The length of addr    @param user_arg the pointer passed to evconnlistener_new()  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|evconnlistener_cb
function_decl|)
parameter_list|(
name|struct
name|evconnlistener
modifier|*
parameter_list|,
name|evutil_socket_t
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
name|socklen
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    A callback that we invoke when a listener encounters a non-retriable error.     @param listener The evconnlistener    @param user_arg the pointer passed to evconnlistener_new()  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|evconnlistener_errorcb
function_decl|)
parameter_list|(
name|struct
name|evconnlistener
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** Flag: Indicates that we should not make incoming sockets nonblocking  * before passing them to the callback. */
define|#
directive|define
name|LEV_OPT_LEAVE_SOCKETS_BLOCKING
value|(1u<<0)
comment|/** Flag: Indicates that freeing the listener should close the underlying  * socket. */
define|#
directive|define
name|LEV_OPT_CLOSE_ON_FREE
value|(1u<<1)
comment|/** Flag: Indicates that we should set the close-on-exec flag, if possible */
define|#
directive|define
name|LEV_OPT_CLOSE_ON_EXEC
value|(1u<<2)
comment|/** Flag: Indicates that we should disable the timeout (if any) between when  * this socket is closed and when we can listen again on the same port. */
define|#
directive|define
name|LEV_OPT_REUSEABLE
value|(1u<<3)
comment|/** Flag: Indicates that the listener should be locked so it's safe to use  * from multiple threadcs at once. */
define|#
directive|define
name|LEV_OPT_THREADSAFE
value|(1u<<4)
comment|/** Flag: Indicates that the listener should be created in disabled  * state. Use evconnlistener_enable() to enable it later. */
define|#
directive|define
name|LEV_OPT_DISABLED
value|(1u<<5)
comment|/** Flag: Indicates that the listener should defer accept() until data is  * available, if possible.  Ignored on platforms that do not support this.  *  * This option can help performance for protocols where the client transmits  * immediately after connecting.  Do not use this option if your protocol  * _doesn't_ start out with the client transmitting data, since in that case  * this option will sometimes cause the kernel to never tell you about the  * connection.  *  * This option is only supported by evconnlistener_new_bind(): it can't  * work with evconnlistener_new_fd(), since the listener needs to be told  * to use the option before it is actually bound.  */
define|#
directive|define
name|LEV_OPT_DEFERRED_ACCEPT
value|(1u<<6)
comment|/** Flag: Indicates that we ask to allow multiple servers (processes or  * threads) to bind to the same port if they each set the option.   *   * SO_REUSEPORT is what most people would expect SO_REUSEADDR to be, however  * SO_REUSEPORT does not imply SO_REUSEADDR.  *  * This is only available on Linux and kernel 3.9+  */
define|#
directive|define
name|LEV_OPT_REUSEABLE_PORT
value|(1u<<7)
comment|/**    Allocate a new evconnlistener object to listen for incoming TCP connections    on a given file descriptor.     @param base The event base to associate the listener with.    @param cb A callback to be invoked when a new connection arrives.  If the       callback is NULL, the listener will be treated as disabled until the       callback is set.    @param ptr A user-supplied pointer to give to the callback.    @param flags Any number of LEV_OPT_* flags    @param backlog Passed to the listen() call to determine the length of the       acceptable connection backlog.  Set to -1 for a reasonable default.       Set to 0 if the socket is already listening.    @param fd The file descriptor to listen on.  It must be a nonblocking       file descriptor, and it should already be bound to an appropriate       port and address. */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evconnlistener
modifier|*
name|evconnlistener_new
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|evconnlistener_cb
name|cb
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|unsigned
name|flags
parameter_list|,
name|int
name|backlog
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|)
function_decl|;
comment|/**    Allocate a new evconnlistener object to listen for incoming TCP connections    on a given address.     @param base The event base to associate the listener with.    @param cb A callback to be invoked when a new connection arrives. If the       callback is NULL, the listener will be treated as disabled until the       callback is set.    @param ptr A user-supplied pointer to give to the callback.    @param flags Any number of LEV_OPT_* flags    @param backlog Passed to the listen() call to determine the length of the       acceptable connection backlog.  Set to -1 for a reasonable default.    @param addr The address to listen for connections on.    @param socklen The length of the address.  */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evconnlistener
modifier|*
name|evconnlistener_new_bind
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|evconnlistener_cb
name|cb
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|unsigned
name|flags
parameter_list|,
name|int
name|backlog
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|int
name|socklen
parameter_list|)
function_decl|;
comment|/**    Disable and deallocate an evconnlistener.  */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evconnlistener_free
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|)
function_decl|;
comment|/**    Re-enable an evconnlistener that has been disabled.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evconnlistener_enable
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|)
function_decl|;
comment|/**    Stop listening for connections on an evconnlistener.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evconnlistener_disable
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|)
function_decl|;
comment|/** Return an evconnlistener's associated event_base. */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|event_base
modifier|*
name|evconnlistener_get_base
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|)
function_decl|;
comment|/** Return the socket that an evconnlistner is listening on. */
name|EVENT2_EXPORT_SYMBOL
name|evutil_socket_t
name|evconnlistener_get_fd
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|)
function_decl|;
comment|/** Change the callback on the listener to cb and its user_data to arg.  */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evconnlistener_set_cb
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|,
name|evconnlistener_cb
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/** Set an evconnlistener's error callback. */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evconnlistener_set_error_cb
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|,
name|evconnlistener_errorcb
name|errorcb
parameter_list|)
function_decl|;
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

end_unit

