begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions used by the GDB event loop.    Copyright 1999, 2000 Free Software Foundation, Inc.    Written by Elena Zannoni<ezannoni@cygnus.com> of Cygnus Solutions.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* An event loop listens for events from multiple event sources. When    an event arrives, it is queued and processed by calling the    appropriate event handler. The event loop then continues to listen    for more events. An event loop completes when there are no event    sources to listen on.  External event sources can be plugged into    the loop.     There are 3 main components:     - a list of file descriptors to be monitored, GDB_NOTIFIER.      - a list of events that have occurred, EVENT_QUEUE.      - a list of signal handling functions, SIGHANDLER_LIST.     GDB_NOTIFIER keeps track of the event sources. Event sources for    gdb are currently the UI and the target.  Gdb communicates with the    command line user interface via the readline library and usually    communicates with remote targets via a serial port. Serial ports    are represented in GDB as file descriptors and select/poll calls.    For native targets instead, the communication consists of calls to    ptrace and waits (via signals) or calls to poll/select (via file    descriptors). In the current gdb, the code handling events related    to the target resides in the wait_for_inferior function and in    various target specific files (*-tdep.c).     EVENT_QUEUE keeps track of the events that have happened during the    last iteration of the event loop, and need to be processed.  An    event is represented by a procedure to be invoked in order to    process the event.  The queue is scanned head to tail.  If the    event of interest is a change of state in a file descriptor, then a    call to poll or select will be made to detect it.     If the events generate signals, they are also queued by special    functions that are invoked through traditional signal handlers.    The actions to be taken is response to such events will be executed    when the SIGHANDLER_LIST is scanned, the next time through the    infinite loop.       Corollary tasks are the creation and deletion of event sources. */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|gdb_client_data
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|async_signal_handler
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|handler_func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|gdb_client_data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|sig_handler_func
function_decl|)
parameter_list|(
name|gdb_client_data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|timer_handler_func
function_decl|)
parameter_list|(
name|gdb_client_data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Where to add an event onto the event queue, by queue_event. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Add at tail of queue. It will be processed in first in first        out order. */
name|TAIL
block|,
comment|/* Add at head of queue. It will be processed in last in first out        order. */
name|HEAD
block|}
name|queue_position
typedef|;
end_typedef

begin_comment
comment|/* Tell create_file_handler what events we are interested in.     This is used by the select version of the event loop. */
end_comment

begin_define
define|#
directive|define
name|GDB_READABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GDB_WRITABLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GDB_EXCEPTION
value|(1<<3)
end_define

begin_comment
comment|/* Exported functions from event-loop.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|start_event_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdb_do_one_event
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_file_handler
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_file_handler
parameter_list|(
name|int
name|fd
parameter_list|,
name|handler_func
modifier|*
name|proc
parameter_list|,
name|gdb_client_data
name|client_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_async_signal_handler
parameter_list|(
name|struct
name|async_signal_handler
modifier|*
name|async_handler_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|async_signal_handler
modifier|*
name|create_async_signal_handler
parameter_list|(
name|sig_handler_func
modifier|*
name|proc
parameter_list|,
name|gdb_client_data
name|client_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_async_signal_handler
parameter_list|(
name|struct
name|async_signal_handler
modifier|*
modifier|*
name|async_handler_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_timer
parameter_list|(
name|int
name|milliseconds
parameter_list|,
name|timer_handler_func
modifier|*
name|proc
parameter_list|,
name|gdb_client_data
name|client_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_timer
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

end_unit

