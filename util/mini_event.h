begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * mini-event.h - micro implementation of libevent api, using select() only.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  * This file implements part of the event(3) libevent api.  * The back end is only select. Max number of fds is limited.  * Max number of signals is limited, one handler per signal only.  * And one handler per fd.  *  * Although limited to select() and a max (1024) open fds, it  * is efficient:  * o dispatch call caches fd_sets to use.   * o handler calling takes time ~ to the number of fds.  * o timeouts are stored in a redblack tree, sorted, so take log(n).  * Timeouts are only accurate to the second (no subsecond accuracy).  * To avoid cpu hogging, fractional timeouts are rounded up to a whole second.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MINI_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|MINI_EVENT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_MINI_EVENT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_WINSOCK
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EVENT_BASE_FREE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_EVENT_BASE_FREE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** event timeout */
end_comment

begin_define
define|#
directive|define
name|EV_TIMEOUT
value|0x01
end_define

begin_comment
comment|/** event fd readable */
end_comment

begin_define
define|#
directive|define
name|EV_READ
value|0x02
end_define

begin_comment
comment|/** event fd writable */
end_comment

begin_define
define|#
directive|define
name|EV_WRITE
value|0x04
end_define

begin_comment
comment|/** event signal */
end_comment

begin_define
define|#
directive|define
name|EV_SIGNAL
value|0x08
end_define

begin_comment
comment|/** event must persist */
end_comment

begin_define
define|#
directive|define
name|EV_PERSIST
value|0x10
end_define

begin_comment
comment|/* needs our redblack tree */
end_comment

begin_include
include|#
directive|include
file|"rbtree.h"
end_include

begin_comment
comment|/** max number of file descriptors to support */
end_comment

begin_define
define|#
directive|define
name|MAX_FDS
value|1024
end_define

begin_comment
comment|/** max number of signals to support */
end_comment

begin_define
define|#
directive|define
name|MAX_SIG
value|32
end_define

begin_comment
comment|/** event base */
end_comment

begin_struct
struct|struct
name|event_base
block|{
comment|/** sorted by timeout (absolute), ptr */
name|rbtree_t
modifier|*
name|times
decl_stmt|;
comment|/** array of 0 - maxfd of ptr to event for it */
name|struct
name|event
modifier|*
modifier|*
name|fds
decl_stmt|;
comment|/** max fd in use */
name|int
name|maxfd
decl_stmt|;
comment|/** capacity - size of the fds array */
name|int
name|capfd
decl_stmt|;
comment|/* fdset for read write, for fds ready, and added */
name|fd_set
comment|/** fds for reading */
name|reads
decl_stmt|,
comment|/** fds for writing */
name|writes
decl_stmt|,
comment|/** fds determined ready for use */
name|ready
decl_stmt|,
comment|/** ready plus newly added events. */
name|content
decl_stmt|;
comment|/** array of 0 - maxsig of ptr to event for it */
name|struct
name|event
modifier|*
modifier|*
name|signals
decl_stmt|;
comment|/** if we need to exit */
name|int
name|need_to_exit
decl_stmt|;
comment|/** where to store time in seconds */
name|time_t
modifier|*
name|time_secs
decl_stmt|;
comment|/** where to store time in microseconds */
name|struct
name|timeval
modifier|*
name|time_tv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Event structure. Has some of the event elements.  */
end_comment

begin_struct
struct|struct
name|event
block|{
comment|/** node in timeout rbtree */
name|rbnode_t
name|node
decl_stmt|;
comment|/** is event already added */
name|int
name|added
decl_stmt|;
comment|/** event base it belongs to */
name|struct
name|event_base
modifier|*
name|ev_base
decl_stmt|;
comment|/** fd to poll or -1 for timeouts. signal number for sigs. */
name|int
name|ev_fd
decl_stmt|;
comment|/** what events this event is interested in, see EV_.. above. */
name|short
name|ev_events
decl_stmt|;
comment|/** timeout value */
name|struct
name|timeval
name|ev_timeout
decl_stmt|;
comment|/** callback to call: fd, eventbits, userarg */
name|void
function_decl|(
modifier|*
name|ev_callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/** callback user arg */
name|void
modifier|*
name|ev_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* function prototypes (some are as they appear in event.h) */
end_comment

begin_comment
comment|/** create event base */
end_comment

begin_function_decl
name|void
modifier|*
name|event_init
parameter_list|(
name|time_t
modifier|*
name|time_secs
parameter_list|,
name|struct
name|timeval
modifier|*
name|time_tv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** get version */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|event_get_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** get polling method, select */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|event_get_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** run select in a loop */
end_comment

begin_function_decl
name|int
name|event_base_dispatch
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** exit that loop */
end_comment

begin_function_decl
name|int
name|event_base_loopexit
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** free event base. Free events yourself */
end_comment

begin_function_decl
name|void
name|event_base_free
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** set content of event */
end_comment

begin_function_decl
name|void
name|event_set
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|,
name|int
parameter_list|,
name|short
parameter_list|,
name|void
function_decl|(
modifier|*
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** add event to a base. You *must* call this for every event. */
end_comment

begin_function_decl
name|int
name|event_base_set
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|,
name|struct
name|event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** add event to make it active. You may not change it with event_set anymore */
end_comment

begin_function_decl
name|int
name|event_add
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** remove event. You may change it again */
end_comment

begin_function_decl
name|int
name|event_del
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** add a timer */
end_comment

begin_define
define|#
directive|define
name|evtimer_add
parameter_list|(
name|ev
parameter_list|,
name|tv
parameter_list|)
value|event_add(ev, tv)
end_define

begin_comment
comment|/** remove a timer */
end_comment

begin_define
define|#
directive|define
name|evtimer_del
parameter_list|(
name|ev
parameter_list|)
value|event_del(ev)
end_define

begin_comment
comment|/* uses different implementation. Cannot mix fd/timeouts and signals inside  * the same struct event. create several event structs for that.  */
end_comment

begin_comment
comment|/** install signal handler */
end_comment

begin_function_decl
name|int
name|signal_add
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** set signal event contents */
end_comment

begin_define
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
value|event_set(ev, x, EV_SIGNAL|EV_PERSIST, cb, arg)
end_define

begin_comment
comment|/** remove signal handler */
end_comment

begin_function_decl
name|int
name|signal_del
parameter_list|(
name|struct
name|event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MINI_EVENT and not USE_WINSOCK */
end_comment

begin_comment
comment|/** compare events in tree, based on timevalue, ptr for uniqueness */
end_comment

begin_function_decl
name|int
name|mini_ev_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINI_EVENT_H */
end_comment

end_unit

