begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVMAP_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVMAP_INTERNAL_H_INCLUDED_
end_define

begin_comment
comment|/** @file evmap-internal.h  *  * An event_map is a utility structure to map each fd or signal to zero or  * more events.  Functions to manipulate event_maps should only be used from  * inside libevent.  They generally need to hold the lock on the corresponding  * event_base.  **/
end_comment

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|event
struct_decl|;
end_struct_decl

begin_comment
comment|/** Initialize an event_map for use.  */
end_comment

begin_function_decl
name|void
name|evmap_io_initmap_
parameter_list|(
name|struct
name|event_io_map
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evmap_signal_initmap_
parameter_list|(
name|struct
name|event_signal_map
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Remove all entries from an event_map.  	@param ctx the map to clear.  */
end_comment

begin_function_decl
name|void
name|evmap_io_clear_
parameter_list|(
name|struct
name|event_io_map
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evmap_signal_clear_
parameter_list|(
name|struct
name|event_signal_map
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Add an IO event (some combination of EV_READ or EV_WRITE) to an     event_base's list of events on a given file descriptor, and tell the     underlying eventops about the fd if its state has changed.      Requires that ev is not already added.      @param base the event_base to operate on.     @param fd the file descriptor corresponding to ev.     @param ev the event to add. */
end_comment

begin_function_decl
name|int
name|evmap_io_add_
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
name|event
modifier|*
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Remove an IO event (some combination of EV_READ or EV_WRITE) to an     event_base's list of events on a given file descriptor, and tell the     underlying eventops about the fd if its state has changed.      @param base the event_base to operate on.     @param fd the file descriptor corresponding to ev.     @param ev the event to remove.  */
end_comment

begin_function_decl
name|int
name|evmap_io_del_
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
name|event
modifier|*
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Active the set of events waiting on an event_base for a given fd.      @param base the event_base to operate on.     @param fd the file descriptor that has become active.     @param events a bitmask of EV_READ|EV_WRITE|EV_ET. */
end_comment

begin_function_decl
name|void
name|evmap_io_active_
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
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions behave in the same way as evmap_io_*, except they work on  * signals rather than fds.  signals use a linear map everywhere; fds use  * either a linear map or a hashtable. */
end_comment

begin_function_decl
name|int
name|evmap_signal_add_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|int
name|signum
parameter_list|,
name|struct
name|event
modifier|*
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|evmap_signal_del_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|int
name|signum
parameter_list|,
name|struct
name|event
modifier|*
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evmap_signal_active_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|evutil_socket_t
name|signum
parameter_list|,
name|int
name|ncalls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the fdinfo object associated with a given fd.  If the fd has no  * events associated with it, the result may be NULL.  */
end_comment

begin_function_decl
name|void
modifier|*
name|evmap_io_get_fdinfo_
parameter_list|(
name|struct
name|event_io_map
modifier|*
name|ctx
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper for event_reinit(): Tell the backend to re-add every fd and signal  * for which we have a pending event.  */
end_comment

begin_function_decl
name|int
name|evmap_reinit_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper for event_base_free(): Call event_del() on every pending fd and  * signal event.  */
end_comment

begin_function_decl
name|void
name|evmap_delete_all_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper for event_base_assert_ok_(): Check referential integrity of the  * evmaps.  */
end_comment

begin_function_decl
name|void
name|evmap_check_integrity_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper: Call fn on every fd or signal event, passing as its arguments the  * provided event_base, the event, and arg.  If fn returns 0, process the next  * event.  If it returns any other value, return that value and process no  * more events.  */
end_comment

begin_function_decl
name|int
name|evmap_foreach_event_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|event_base_foreach_event_cb
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVMAP_INTERNAL_H_INCLUDED_ */
end_comment

end_unit

