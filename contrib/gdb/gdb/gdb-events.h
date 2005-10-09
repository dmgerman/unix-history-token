begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* User Interface Events.     Copyright 1999, 2001, 2002, 2004 Free Software Foundation, Inc.     Contributed by Cygnus Solutions.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Work in progress */
end_comment

begin_comment
comment|/* This file was created with the aid of ``gdb-events.sh''.     The bourn shell script ``gdb-events.sh'' creates the files    ``new-gdb-events.c'' and ``new-gdb-events.h and then compares    them against the existing ``gdb-events.[hc]''.  Any differences    found being reported.     If editing this file, please also run gdb-events.sh and merge any    changes into that script. Conversely, when making sweeping changes    to this file, modifying gdb-events.sh and using its output may    prove easier. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_EVENTS_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_EVENTS_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WITH_GDB_EVENTS
end_ifndef

begin_define
define|#
directive|define
name|WITH_GDB_EVENTS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT: pointer variables for old, unconverted events.    A call to set_gdb_events() will automatically update these. */
end_comment

begin_comment
comment|/* Type definition of all hook functions.    Recommended pratice is to first declare each hook function using    the below ftype and then define it. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_breakpoint_create_ftype
function_decl|)
parameter_list|(
name|int
name|b
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_breakpoint_delete_ftype
function_decl|)
parameter_list|(
name|int
name|b
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_breakpoint_modify_ftype
function_decl|)
parameter_list|(
name|int
name|b
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_tracepoint_create_ftype
function_decl|)
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_tracepoint_delete_ftype
function_decl|)
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_tracepoint_modify_ftype
function_decl|)
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_architecture_changed_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_target_changed_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_selected_frame_level_changed_ftype
function_decl|)
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdb_events_selected_thread_changed_ftype
function_decl|)
parameter_list|(
name|int
name|thread_num
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* gdb-events: object. */
end_comment

begin_struct
struct|struct
name|gdb_events
block|{
name|gdb_events_breakpoint_create_ftype
modifier|*
name|breakpoint_create
decl_stmt|;
name|gdb_events_breakpoint_delete_ftype
modifier|*
name|breakpoint_delete
decl_stmt|;
name|gdb_events_breakpoint_modify_ftype
modifier|*
name|breakpoint_modify
decl_stmt|;
name|gdb_events_tracepoint_create_ftype
modifier|*
name|tracepoint_create
decl_stmt|;
name|gdb_events_tracepoint_delete_ftype
modifier|*
name|tracepoint_delete
decl_stmt|;
name|gdb_events_tracepoint_modify_ftype
modifier|*
name|tracepoint_modify
decl_stmt|;
name|gdb_events_architecture_changed_ftype
modifier|*
name|architecture_changed
decl_stmt|;
name|gdb_events_target_changed_ftype
modifier|*
name|target_changed
decl_stmt|;
name|gdb_events_selected_frame_level_changed_ftype
modifier|*
name|selected_frame_level_changed
decl_stmt|;
name|gdb_events_selected_thread_changed_ftype
modifier|*
name|selected_thread_changed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interface into events functions.    Where a *_p() predicate is present, it must be called before    calling the hook proper. */
end_comment

begin_function_decl
specifier|extern
name|void
name|breakpoint_create_event
parameter_list|(
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_delete_event
parameter_list|(
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_modify_event
parameter_list|(
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tracepoint_create_event
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tracepoint_delete_event
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tracepoint_modify_event
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|architecture_changed_event
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|target_changed_event
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|selected_frame_level_changed_event
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|selected_thread_changed_event
parameter_list|(
name|int
name|thread_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When GDB_EVENTS are not being used, completely disable them. */
end_comment

begin_if
if|#
directive|if
operator|!
name|WITH_GDB_EVENTS
end_if

begin_define
define|#
directive|define
name|breakpoint_create_event
parameter_list|(
name|b
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|breakpoint_delete_event
parameter_list|(
name|b
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|breakpoint_modify_event
parameter_list|(
name|b
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|tracepoint_create_event
parameter_list|(
name|number
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|tracepoint_delete_event
parameter_list|(
name|number
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|tracepoint_modify_event
parameter_list|(
name|number
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|architecture_changed_event
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|target_changed_event
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|selected_frame_level_changed_event
parameter_list|(
name|level
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|selected_thread_changed_event
parameter_list|(
name|thread_num
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Install custom gdb-events hooks. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdb_events
modifier|*
name|set_gdb_event_hooks
parameter_list|(
name|struct
name|gdb_events
modifier|*
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deliver any pending events. */
end_comment

begin_function_decl
specifier|extern
name|void
name|gdb_events_deliver
parameter_list|(
name|struct
name|gdb_events
modifier|*
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clear event handlers */
end_comment

begin_function_decl
specifier|extern
name|void
name|clear_gdb_event_hooks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|WITH_GDB_EVENTS
end_if

begin_define
define|#
directive|define
name|set_gdb_events
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|set_gdb_event_hooks
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|gdb_events_deliver
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

