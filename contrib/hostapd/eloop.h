begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Event loop  * Copyright (c) 2002-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This file defines an event loop interface that supports processing events  * from registered timeouts (i.e., do something after N seconds), sockets  * (e.g., a new packet available for reading), and signals. eloop.c is an  * implementation of this interface using select() and sockets. This is  * suitable for most UNIX/POSIX systems. When porting to other operating  * systems, it may be necessary to replace that implementation with OS specific  * mechanisms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ELOOP_H
end_ifndef

begin_define
define|#
directive|define
name|ELOOP_H
end_define

begin_comment
comment|/* Magic number for eloop_cancel_timeout() */
end_comment

begin_define
define|#
directive|define
name|ELOOP_ALL_CTX
value|(void *) -1
end_define

begin_comment
comment|/**  * eloop_init() - Initialize global event loop data  * @user_data: Pointer to global data passed as eloop_ctx to signal handlers  *  * This function must be called before any other eloop_* function. user_data  * can be used to configure a global (to the process) pointer that will be  * passed as eloop_ctx parameter to signal handlers.  */
end_comment

begin_function_decl
name|void
name|eloop_init
parameter_list|(
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_register_read_sock - Register handler for read events  * @sock: File descriptor number for the socket  * @handler: Callback function to be called when data is available for reading  * @eloop_data: Callback context data (eloop_ctx)  * @user_data: Callback context data (sock_ctx)  * Returns: 0 on success, -1 on failure  *  * Register a read socket notifier for the given file descriptor. The handler  * function will be called whenever data is available for reading from the  * socket.  */
end_comment

begin_function_decl
name|int
name|eloop_register_read_sock
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|sock_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|eloop_data
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_unregister_read_sock - Unregister handler for read events  * @sock: File descriptor number for the socket  *  * Unregister a read socket notifier that was previously registered with  * eloop_register_read_sock().  */
end_comment

begin_function_decl
name|void
name|eloop_unregister_read_sock
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_register_timeout - Register timeout  * @secs: Number of seconds to the timeout  * @usecs: Number of microseconds to the timeout  * @handler: Callback function to be called when timeout occurs  * @eloop_data: Callback context data (eloop_ctx)  * @user_data: Callback context data (sock_ctx)  * Returns: 0 on success, -1 on failure  *  * Register a timeout that will cause the handler function to be called after  * given time.  */
end_comment

begin_function_decl
name|int
name|eloop_register_timeout
parameter_list|(
name|unsigned
name|int
name|secs
parameter_list|,
name|unsigned
name|int
name|usecs
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|timeout_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|eloop_data
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_cancel_timeout - Cancel timeouts  * @handler: Matching callback function  * @eloop_data: Matching eloop_data or %ELOOP_ALL_CTX to match all  * @user_data: Matching user_data or %ELOOP_ALL_CTX to match all  * Returns: Number of cancelled timeouts  *  * Cancel matching<handler,eloop_data,user_data> timeouts registered with  * eloop_register_timeout(). ELOOP_ALL_CTX can be used as a wildcard for  * cancelling all timeouts regardless of eloop_data/user_data.  */
end_comment

begin_function_decl
name|int
name|eloop_cancel_timeout
parameter_list|(
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|sock_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|eloop_data
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_register_signal - Register handler for signals  * @sig: Signal number (e.g., SIGHUP)  * @handler: Callback function to be called when the signal is received  * @user_data: Callback context data (signal_ctx)  * Returns: 0 on success, -1 on failure  *  * Register a callback function that will be called when a signal is received.  * The calback function is actually called only after the system signal handler  * has returned. This means that the normal limits for sighandlers (i.e., only  * "safe functions" allowed) do not apply for the registered callback.  *  * Signals are 'global' events and there is no local eloop_data pointer like  * with other handlers. The global user_data pointer registered with  * eloop_init() will be used as eloop_ctx for signal handlers.  */
end_comment

begin_function_decl
name|int
name|eloop_register_signal
parameter_list|(
name|int
name|sig
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|int
name|sig
parameter_list|,
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|signal_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_run - Start the event loop  *  * Start the event loop and continue running as long as there are any  * registered event handlers. This function is run after event loop has been  * initialized with event_init() and one or more events have been registered.  */
end_comment

begin_function_decl
name|void
name|eloop_run
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_terminate - Terminate event loop  *  * Terminate event loop even if there are registered events. This can be used  * to request the program to be terminated cleanly.  */
end_comment

begin_function_decl
name|void
name|eloop_terminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_destroy - Free any resources allocated for the event loop  *  * After calling eloop_destoy(), other eloop_* functions must not be called  * before re-running eloop_init().  */
end_comment

begin_function_decl
name|void
name|eloop_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * eloop_terminated - Check whether event loop has been terminated  * Returns: 1 = event loop terminate, 0 = event loop still running  *  * This function can be used to check whether eloop_terminate() has been called  * to request termination of the event loop. This is normally used to abort  * operations that may still be queued to be run when eloop_terminate() was  * called.  */
end_comment

begin_function_decl
name|int
name|eloop_terminated
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELOOP_H */
end_comment

end_unit

