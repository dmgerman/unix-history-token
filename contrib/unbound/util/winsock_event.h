begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/winsock_event.h - unbound event handling for winsock on windows  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains interface functions with the WinSock2 API on Windows.  * It uses the winsock WSAWaitForMultipleEvents interface on a number of  * sockets.  *  * Note that windows can only wait for max 64 events at one time.  *   * Also, file descriptors cannot be waited for.  *  * Named pipes are not easily available (and are not usable in select() ).  * For interprocess communication, it is possible to wait for a hEvent to  * be signaled by another thread.  *  * When a socket becomes readable, then it will not be flagged as   * readable again until you have gotten WOULDBLOCK from a recv routine.  * That means the event handler must store the readability (edge notify)  * and process the incoming data until it blocks.   * The function performing recv then has to inform the event handler that  * the socket has blocked, and the event handler can mark it as such.  * Thus, this file transforms the edge notify from windows to a level notify  * that is compatible with UNIX.  * The WSAEventSelect page says that it does do level notify, as long  * as you call a recv/write/accept at least once when it is signalled.  * This last bit is not true, even though documented in server2008 api docs  * from microsoft, it does not happen at all. Instead you have to test for  * WSAEWOULDBLOCK on a tcp stream, and only then retest the socket.  * And before that remember the previous result as still valid.  *  * To stay 'fair', instead of emptying a socket completely, the event handler  * can test the other (marked as blocking) sockets for new events.  *  * Additionally, TCP accept sockets get special event support.  *  * Socket numbers are not starting small, they can be any number (say 33060).  * Therefore, bitmaps are not used, but arrays.  *  * on winsock, you must use recv() and send() for TCP reads and writes,  * not read() and write(), those work only on files.  *  * Also fseek and fseeko do not work if a FILE is not fopen-ed in binary mode.  *  * When under a high load windows gives out lots of errors, from recvfrom  * on udp sockets for example (WSAECONNRESET). Even though the udp socket  * has no connection per se.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_WINSOCK_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_WINSOCK_EVENT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WINSOCK
end_ifdef

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
comment|/** max number of signals to support */
end_comment

begin_define
define|#
directive|define
name|MAX_SIG
value|32
end_define

begin_comment
comment|/** The number of items that the winsock event handler can service.  * Windows cannot handle more anyway */
end_comment

begin_define
define|#
directive|define
name|WSK_MAX_ITEMS
value|64
end_define

begin_comment
comment|/**  * event base for winsock event handler  */
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
comment|/** array (first part in use) of handles to work on */
name|struct
name|event
modifier|*
modifier|*
name|items
decl_stmt|;
comment|/** number of items in use in array */
name|int
name|max
decl_stmt|;
comment|/** capacity of array, size of array in items */
name|int
name|cap
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
comment|/**  	 * TCP streams have sticky events to them, these are not 	 * reported by the windows event system anymore, we have to 	 * keep reporting those events as present until wouldblock() is 	 * signalled by the handler back to use. 	 */
name|int
name|tcp_stickies
decl_stmt|;
comment|/** 	 * should next cycle process reinvigorated stickies, 	 * these are stickies that have been stored, but due to a new 	 * event_add a sudden interest in the event has incepted. 	 */
name|int
name|tcp_reinvigorated
decl_stmt|;
comment|/** The list of events that is currently being processed. */
name|WSAEVENT
name|waitfor
index|[
name|WSK_MAX_ITEMS
index|]
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
parameter_list|)
function_decl|;
comment|/** callback user arg */
name|void
modifier|*
name|ev_arg
decl_stmt|;
comment|/* ----- nonpublic part, for winsock_event only ----- */
comment|/** index of this event in the items array (if added) */
name|int
name|idx
decl_stmt|;
comment|/** the event handle to wait for new events to become ready */
name|WSAEVENT
name|hEvent
decl_stmt|;
comment|/** true if this filedes is a TCP socket and needs special attention */
name|int
name|is_tcp
decl_stmt|;
comment|/** remembered EV_ values */
name|short
name|old_events
decl_stmt|;
comment|/** should remembered EV_ values be used for TCP streams.  	 * Reset after WOULDBLOCK is signaled using the function. */
name|int
name|stick_events
decl_stmt|;
comment|/** true if this event is a signaling WSAEvent by the user.  	 * User created and user closed WSAEvent. Only signaled/unsigneled, 	 * no read/write/distinctions needed. */
name|int
name|is_signal
decl_stmt|;
comment|/** used during callbacks to see which events were just checked */
name|int
name|just_checked
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/** get polling method (select,epoll) */
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

begin_comment
comment|/**  * Routine for windows only, where the handling layer can signal that  * a TCP stream encountered WSAEWOULDBLOCK for a stream and thus needs  * retesting the event.  * Pass if EV_READ or EV_WRITE gave wouldblock.  */
end_comment

begin_function_decl
name|void
name|winsock_tcp_wouldblock
parameter_list|(
name|struct
name|event
modifier|*
name|ev
parameter_list|,
name|int
name|eventbit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Routine for windows only. where you pass a signal WSAEvent that  * you wait for. When the event is signaled, the callback gets called.  * The callback has to WSAResetEvent to disable the signal.   * @param base: the event base.  * @param ev: the event structure for data storage  * 	can be passed uninitialised.  * @param wsaevent: the WSAEvent that gets signaled.  * @param cb: callback routine.  * @param arg: user argument to callback routine.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|winsock_register_wsaevent
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|struct
name|event
modifier|*
name|ev
parameter_list|,
name|WSAEVENT
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
comment|/**  * Unregister a wsaevent. User has to close the WSAEVENT itself.  * @param ev: event data storage.  */
end_comment

begin_function_decl
name|void
name|winsock_unregister_wsaevent
parameter_list|(
name|struct
name|event
modifier|*
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_WINSOCK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_WINSOCK_EVENT_H */
end_comment

end_unit

