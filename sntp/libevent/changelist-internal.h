begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHANGELIST_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|CHANGELIST_INTERNAL_H_INCLUDED_
end_define

begin_comment
comment|/*   A "changelist" is a list of all the fd status changes that should be made   between calls to the backend's dispatch function.  There are a few reasons   that a backend would want to queue changes like this rather than processing   them immediately.      1) Sometimes applications will add and delete the same event more than        once between calls to dispatch.  Processing these changes immediately        is needless, and potentially expensive (especially if we're on a system        that makes one syscall per changed event).      2) Sometimes we can coalesce multiple changes on the same fd into a single        syscall if we know about them in advance.  For example, epoll can do an        add and a delete at the same time, but only if we have found out about        both of them before we tell epoll.      3) Sometimes adding an event that we immediately delete can cause        unintended consequences: in kqueue, this makes pending events get        reported spuriously.  */
end_comment

begin_include
include|#
directive|include
file|"event2/util.h"
end_include

begin_comment
comment|/** Represents a */
end_comment

begin_struct
struct|struct
name|event_change
block|{
comment|/** The fd or signal whose events are to be changed */
name|evutil_socket_t
name|fd
decl_stmt|;
comment|/* The events that were enabled on the fd before any of these changes 	   were made.  May include EV_READ or EV_WRITE. */
name|short
name|old_events
decl_stmt|;
comment|/* The changes that we want to make in reading and writing on this fd. 	 * If this is a signal, then read_change has EV_CHANGE_SIGNAL set, 	 * and write_change is unused. */
name|ev_uint8_t
name|read_change
decl_stmt|;
name|ev_uint8_t
name|write_change
decl_stmt|;
name|ev_uint8_t
name|close_change
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for read_change and write_change. */
end_comment

begin_comment
comment|/* If set, add the event. */
end_comment

begin_define
define|#
directive|define
name|EV_CHANGE_ADD
value|0x01
end_define

begin_comment
comment|/* If set, delete the event.  Exclusive with EV_CHANGE_ADD */
end_comment

begin_define
define|#
directive|define
name|EV_CHANGE_DEL
value|0x02
end_define

begin_comment
comment|/* If set, this event refers a signal, not an fd. */
end_comment

begin_define
define|#
directive|define
name|EV_CHANGE_SIGNAL
value|EV_SIGNAL
end_define

begin_comment
comment|/* Set for persistent events.  Currently not used. */
end_comment

begin_define
define|#
directive|define
name|EV_CHANGE_PERSIST
value|EV_PERSIST
end_define

begin_comment
comment|/* Set for adding edge-triggered events. */
end_comment

begin_define
define|#
directive|define
name|EV_CHANGE_ET
value|EV_ET
end_define

begin_comment
comment|/* The value of fdinfo_size that a backend should use if it is letting  * changelist handle its add and delete functions. */
end_comment

begin_define
define|#
directive|define
name|EVENT_CHANGELIST_FDINFO_SIZE
value|sizeof(int)
end_define

begin_comment
comment|/** Set up the data fields in a changelist. */
end_comment

begin_function_decl
name|void
name|event_changelist_init_
parameter_list|(
name|struct
name|event_changelist
modifier|*
name|changelist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Remove every change in the changelist, and make corresponding changes  * in the event maps in the base.  This function is generally used right  * after making all the changes in the changelist. */
end_comment

begin_function_decl
name|void
name|event_changelist_remove_all_
parameter_list|(
name|struct
name|event_changelist
modifier|*
name|changelist
parameter_list|,
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Free all memory held in a changelist. */
end_comment

begin_function_decl
name|void
name|event_changelist_freemem_
parameter_list|(
name|struct
name|event_changelist
modifier|*
name|changelist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Implementation of eventop_add that queues the event in a changelist. */
end_comment

begin_function_decl
name|int
name|event_changelist_add_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|,
name|short
name|old
parameter_list|,
name|short
name|events
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Implementation of eventop_del that queues the event in a changelist. */
end_comment

begin_function_decl
name|int
name|event_changelist_del_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|,
name|short
name|old
parameter_list|,
name|short
name|events
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

