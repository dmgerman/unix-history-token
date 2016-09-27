begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/ub_event.h - indirection layer for pluggable events  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains prototypes for event loop functions.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UB_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|UB_EVENT_H
end_define

begin_struct_decl
struct_decl|struct
name|ub_event_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_event
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_comment
comment|/** event timeout */
end_comment

begin_define
define|#
directive|define
name|UB_EV_TIMEOUT
value|0x01
end_define

begin_comment
comment|/** event fd readable */
end_comment

begin_define
define|#
directive|define
name|UB_EV_READ
value|0x02
end_define

begin_comment
comment|/** event fd writable */
end_comment

begin_define
define|#
directive|define
name|UB_EV_WRITE
value|0x04
end_define

begin_comment
comment|/** event signal */
end_comment

begin_define
define|#
directive|define
name|UB_EV_SIGNAL
value|0x08
end_define

begin_comment
comment|/** event must persist */
end_comment

begin_define
define|#
directive|define
name|UB_EV_PERSIST
value|0x10
end_define

begin_comment
comment|/** Returns event-base type. Could be "mini-event", "winsock-event" for the  * daemon compile, and will be "pluggable-event<PACKAGE_VERSION>" for   * libunbound.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ub_event_get_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return the name, system and method for the pluggable event base */
end_comment

begin_function_decl
name|void
name|ub_get_event_sys
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return a default event base. In the deamon thess will be the only event   * bases used.  */
end_comment

begin_function_decl
name|struct
name|ub_event_base
modifier|*
name|ub_default_event_base
parameter_list|(
name|int
parameter_list|,
name|time_t
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return an ub_event_base constructed for the given libevent event base */
end_comment

begin_function_decl
name|struct
name|ub_event_base
modifier|*
name|ub_libevent_event_base
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return the libevent base underlying the given ub_event_base.  Will return  * NULL when the ub_event_base does not have an underlying libevent event base  */
end_comment

begin_function_decl
name|struct
name|event_base
modifier|*
name|ub_libevent_get_event_base
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Free event base. Free events yourself */
end_comment

begin_function_decl
name|void
name|ub_event_base_free
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Run the event base */
end_comment

begin_function_decl
name|int
name|ub_event_base_dispatch
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** exit that loop */
end_comment

begin_function_decl
name|int
name|ub_event_base_loopexit
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new ub_event for the event base */
end_comment

begin_function_decl
name|struct
name|ub_event
modifier|*
name|ub_event_new
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|,
name|short
name|bits
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new ub_event signal for the event base */
end_comment

begin_function_decl
name|struct
name|ub_event
modifier|*
name|ub_signal_new
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new ub_event associated with the wsaevent for the event base */
end_comment

begin_function_decl
name|struct
name|ub_event
modifier|*
name|ub_winsock_register_wsaevent
parameter_list|(
name|struct
name|ub_event_base
modifier|*
parameter_list|,
name|void
modifier|*
name|wsaevent
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Add event bits for this event to fire on */
end_comment

begin_function_decl
name|void
name|ub_event_add_bits
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|short
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Configure the event so it will not longer fire on given bits */
end_comment

begin_function_decl
name|void
name|ub_event_del_bits
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|short
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Change or set the file descriptor on the event */
end_comment

begin_function_decl
name|void
name|ub_event_set_fd
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** free the event */
end_comment

begin_function_decl
name|void
name|ub_event_free
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Activate the event.  The given timeval is an timeout value. */
end_comment

begin_function_decl
name|int
name|ub_event_add
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Deactivate the event */
end_comment

begin_function_decl
name|int
name|ub_event_del
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Reconfigure and activate a timeout event */
end_comment

begin_function_decl
name|int
name|ub_timer_add
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|struct
name|ub_event_base
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Deactivate the timeout event */
end_comment

begin_function_decl
name|int
name|ub_timer_del
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Activate a signal event */
end_comment

begin_function_decl
name|int
name|ub_signal_add
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Deactivate a signal event */
end_comment

begin_function_decl
name|int
name|ub_signal_del
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Free a with a wsaevent associated event */
end_comment

begin_function_decl
name|void
name|ub_winsock_unregister_wsaevent
parameter_list|(
name|struct
name|ub_event
modifier|*
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Signal the eventloop when a TCP windows socket will block on next read  * or write (given by the eventbits)  */
end_comment

begin_function_decl
name|void
name|ub_winsock_tcp_wouldblock
parameter_list|(
name|struct
name|ub_event
modifier|*
parameter_list|,
name|int
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Equip the comm_base with the current time */
end_comment

begin_function_decl
name|void
name|ub_comm_base_now
parameter_list|(
name|struct
name|comm_base
modifier|*
name|cb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UB_EVENT_H */
end_comment

end_unit

