begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Multi-process/thread control defs for GDB, the GNU debugger.    Copyright 1987, 88, 89, 90, 91, 92, 1993, 1998     Contributed by Lynx Real-Time Systems, Inc.  Los Gatos, CA.    Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDBTHREAD_H
end_ifndef

begin_define
define|#
directive|define
name|GDBTHREAD_H
end_define

begin_comment
comment|/* For bpstat */
end_comment

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_decl_stmt
specifier|extern
name|void
name|init_thread_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_thread
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_thread
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|thread_id_to_pid
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_thread_list
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pid_to_thread_id
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|valid_thread_id
name|PARAMS
argument_list|(
operator|(
name|int
name|thread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|load_infrun_state
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
expr|struct
name|breakpoint
operator|*
operator|*
operator|,
expr|struct
name|breakpoint
operator|*
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|bpstat
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|save_infrun_state
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|CORE_ADDR
operator|,
name|CORE_ADDR
operator|,
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|breakpoint
operator|*
operator|,
expr|struct
name|breakpoint
operator|*
operator|,
name|CORE_ADDR
operator|,
name|CORE_ADDR
operator|,
name|CORE_ADDR
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|bpstat
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Commands with a prefix of `thread'.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|thread_cmd_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Support for external (remote) systems with threads (processes) */
end_comment

begin_comment
comment|/* For example real time operating systems */
end_comment

begin_define
define|#
directive|define
name|OPAQUETHREADBYTES
value|8
end_define

begin_comment
comment|/* a 64 bit opaque identifier */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|threadref
index|[
name|OPAQUETHREADBYTES
index|]
typedef|;
end_typedef

begin_comment
comment|/* WARNING: This threadref data structure comes from the remote O.S., libstub    protocol encoding, and remote.c. it is not particularly changable */
end_comment

begin_comment
comment|/* Right now, the internal structure is int. We want it to be bigger.    Plan to fix this.    */
end_comment

begin_typedef
typedef|typedef
name|int
name|gdb_threadref
typedef|;
end_typedef

begin_comment
comment|/* internal GDB thread reference */
end_comment

begin_comment
comment|/*  gdb_ext_thread_info is an internal GDB data structure which is    equivalint to the reply of the remote threadinfo packet */
end_comment

begin_struct
struct|struct
name|gdb_ext_thread_info
block|{
name|threadref
name|threadid
decl_stmt|;
comment|/* External form of thread reference */
name|int
name|active
decl_stmt|;
comment|/* Has state interesting to GDB? , regs, stack */
name|char
name|display
index|[
literal|256
index|]
decl_stmt|;
comment|/* Brief state display, name, blocked/syspended */
name|char
name|shortname
index|[
literal|32
index|]
decl_stmt|;
comment|/* To be used to name threads */
name|char
name|more_display
index|[
literal|256
index|]
decl_stmt|;
comment|/* Long info, statistics, queue depth, whatever */
block|}
struct|;
end_struct

begin_comment
comment|/* The volume of remote transfers can be limited by submitting    a mask containing bits specifying the desired information.    Use a union of these values as the 'selection' parameter to    get_thread_info. FIXME: Make these TAG names more thread specific.    */
end_comment

begin_define
define|#
directive|define
name|TAG_THREADID
value|1
end_define

begin_define
define|#
directive|define
name|TAG_EXISTS
value|2
end_define

begin_define
define|#
directive|define
name|TAG_DISPLAY
value|4
end_define

begin_define
define|#
directive|define
name|TAG_THREADNAME
value|8
end_define

begin_define
define|#
directive|define
name|TAG_MOREDISPLAY
value|16
end_define

begin_comment
comment|/* Always initialize an instance of this structure using run time assignments */
end_comment

begin_comment
comment|/* Because we are likely to add entrtries to it. */
end_comment

begin_comment
comment|/* Alternatly, WE COULD ADD THESE TO THE TARGET VECTOR */
end_comment

begin_struct
struct|struct
name|target_thread_vector
block|{
name|int
argument_list|(
argument|*find_new_threads
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*get_thread_info
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|gdb_threadref
operator|*
name|ref
operator|,
name|int
name|selection
operator|,
expr|struct
name|gdb_ext_thread_info
operator|*
name|info
operator|)
argument_list|)
expr_stmt|;
comment|/* to_thread_alive - Already in the target vector */
comment|/* to_switch_thread - Done via select frame */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|bind_target_thread_vector
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_thread_vector
operator|*
name|vec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|target_thread_vector
modifier|*
name|unbind_target_thread_vector
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_get_thread_info
name|PARAMS
argument_list|(
operator|(
name|gdb_threadref
operator|*
name|ref
operator|,
name|int
name|selection
operator|,
expr|struct
name|gdb_ext_thread_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDBTHREAD_H */
end_comment

end_unit

