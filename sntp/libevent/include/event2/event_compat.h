begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_EVENT_COMPAT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_EVENT_COMPAT_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/event_compat.h    Potentially non-threadsafe versions of the functions in event.h: provided   only for backwards compatibility.    In the oldest versions of Libevent, event_base was not a first-class   structure.  Instead, there was a single event base that every function   manipulated.  Later, when separate event bases were added, the old functions   that didn't take an event_base argument needed to work by manipulating the   "current" event base.  This could lead to thread-safety issues, and obscure,   hard-to-diagnose bugs.    @deprecated All functions in this file are by definition deprecated.  */
end_comment

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
comment|/**   Initialize the event API.    The event API needs to be initialized with event_init() before it can be   used.  Sets the global current base that gets used for events that have no   base associated with them.    @deprecated This function is deprecated because it replaces the "current"     event_base, and is totally unsafe for multithreaded use.  The replacement     is event_base_new().    @see event_base_set(), event_base_new()  */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|event_base
modifier|*
name|event_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**   Loop to process events.    Like event_base_dispatch(), but uses the "current" base.    @deprecated This function is deprecated because it is easily confused by     multiple calls to event_init(), and because it is not safe for     multithreaded use.  The replacement is event_base_dispatch().    @see event_base_dispatch(), event_init()  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|event_dispatch
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**   Handle events.    This function behaves like event_base_loop(), but uses the "current" base    @deprecated This function is deprecated because it uses the event base from     the last call to event_init, and is therefore not safe for multithreaded     use.  The replacement is event_base_loop().    @see event_base_loop(), event_init() */
name|EVENT2_EXPORT_SYMBOL
name|int
name|event_loop
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/**   Exit the event loop after the specified time.    This function behaves like event_base_loopexit(), except that it uses the   "current" base.    @deprecated This function is deprecated because it uses the event base from     the last call to event_init, and is therefore not safe for multithreaded     use.  The replacement is event_base_loopexit().    @see event_init, event_base_loopexit()   */
name|EVENT2_EXPORT_SYMBOL
name|int
name|event_loopexit
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
comment|/**   Abort the active event_loop() immediately.    This function behaves like event_base_loopbreakt(), except that it uses the   "current" base.    @deprecated This function is deprecated because it uses the event base from     the last call to event_init, and is therefore not safe for multithreaded     use.  The replacement is event_base_loopbreak().    @see event_base_loopbreak(), event_init()  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|event_loopbreak
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**   Schedule a one-time event to occur.    @deprecated This function is obsolete, and has been replaced by     event_base_once(). Its use is deprecated because it relies on the     "current" base configured by event_init().    @see event_base_once()  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|event_once
parameter_list|(
name|evutil_socket_t
parameter_list|,
name|short
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|evutil_socket_t
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
comment|/**   Get the kernel event notification mechanism used by Libevent.    @deprecated This function is obsolete, and has been replaced by     event_base_get_method(). Its use is deprecated because it relies on the     "current" base configured by event_init().    @see event_base_get_method()  */
name|EVENT2_EXPORT_SYMBOL
specifier|const
name|char
modifier|*
name|event_get_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**   Set the number of different event priorities.    @deprecated This function is deprecated because it is easily confused by     multiple calls to event_init(), and because it is not safe for     multithreaded use.  The replacement is event_base_priority_init().    @see event_base_priority_init()  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|event_priority_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/**   Prepare an event structure to be added.    @deprecated event_set() is not recommended for new code, because it requires      a subsequent call to event_base_set() to be safe under most circumstances.      Use event_assign() or event_new() instead.  */
name|EVENT2_EXPORT_SYMBOL
name|void
name|event_set
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|,
name|evutil_socket_t
parameter_list|,
name|short
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|evutil_socket_t
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|evtimer_set
parameter_list|(
name|ev
parameter_list|,
name|cb
parameter_list|,
name|arg
parameter_list|)
value|event_set((ev), -1, 0, (cb), (arg))
define|#
directive|define
name|evsignal_set
parameter_list|(
name|ev
parameter_list|,
name|x
parameter_list|,
name|cb
parameter_list|,
name|arg
parameter_list|)
define|\
value|event_set((ev), (x), EV_SIGNAL|EV_PERSIST, (cb), (arg))
comment|/**    @name timeout_* macros     @deprecated These macros are deprecated because their naming is inconsistent      with the rest of Libevent.  Use the evtimer_* macros instead.    @{  */
define|#
directive|define
name|timeout_add
parameter_list|(
name|ev
parameter_list|,
name|tv
parameter_list|)
value|event_add((ev), (tv))
define|#
directive|define
name|timeout_set
parameter_list|(
name|ev
parameter_list|,
name|cb
parameter_list|,
name|arg
parameter_list|)
value|event_set((ev), -1, 0, (cb), (arg))
define|#
directive|define
name|timeout_del
parameter_list|(
name|ev
parameter_list|)
value|event_del(ev)
define|#
directive|define
name|timeout_pending
parameter_list|(
name|ev
parameter_list|,
name|tv
parameter_list|)
value|event_pending((ev), EV_TIMEOUT, (tv))
define|#
directive|define
name|timeout_initialized
parameter_list|(
name|ev
parameter_list|)
value|event_initialized(ev)
comment|/**@}*/
comment|/**    @name signal_* macros     @deprecated These macros are deprecated because their naming is inconsistent      with the rest of Libevent.  Use the evsignal_* macros instead.    @{  */
define|#
directive|define
name|signal_add
parameter_list|(
name|ev
parameter_list|,
name|tv
parameter_list|)
value|event_add((ev), (tv))
define|#
directive|define
name|signal_set
parameter_list|(
name|ev
parameter_list|,
name|x
parameter_list|,
name|cb
parameter_list|,
name|arg
parameter_list|)
define|\
value|event_set((ev), (x), EV_SIGNAL|EV_PERSIST, (cb), (arg))
define|#
directive|define
name|signal_del
parameter_list|(
name|ev
parameter_list|)
value|event_del(ev)
define|#
directive|define
name|signal_pending
parameter_list|(
name|ev
parameter_list|,
name|tv
parameter_list|)
value|event_pending((ev), EV_SIGNAL, (tv))
define|#
directive|define
name|signal_initialized
parameter_list|(
name|ev
parameter_list|)
value|event_initialized(ev)
comment|/**@}*/
ifndef|#
directive|ifndef
name|EVENT_FD
comment|/* These macros are obsolete; use event_get_fd and event_get_signal instead. */
define|#
directive|define
name|EVENT_FD
parameter_list|(
name|ev
parameter_list|)
value|((int)event_get_fd(ev))
define|#
directive|define
name|EVENT_SIGNAL
parameter_list|(
name|ev
parameter_list|)
value|event_get_signal(ev)
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
comment|/* EVENT2_EVENT_COMPAT_H_INCLUDED_ */
end_comment

end_unit

