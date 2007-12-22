begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Multi-process/thread control defs for GDB, the GNU debugger.    Copyright 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1997, 1998, 1999,    2000    Free Software Foundation, Inc.    Contributed by Lynx Real-Time Systems, Inc.  Los Gatos, CA.         This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|breakpoint
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_id
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|symtab
struct_decl|;
end_struct_decl

begin_comment
comment|/* For bpstat */
end_comment

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_comment
comment|/* For struct frame_id.  */
end_comment

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_struct
struct|struct
name|thread_info
block|{
name|struct
name|thread_info
modifier|*
name|next
decl_stmt|;
name|ptid_t
name|ptid
decl_stmt|;
comment|/* "Actual process id"; 				    In fact, this may be overloaded with  				    kernel thread id, etc.  */
name|int
name|num
decl_stmt|;
comment|/* Convenient handle (GDB thread id) */
comment|/* State from wait_for_inferior */
name|CORE_ADDR
name|prev_pc
decl_stmt|;
name|struct
name|breakpoint
modifier|*
name|step_resume_breakpoint
decl_stmt|;
name|struct
name|breakpoint
modifier|*
name|through_sigtramp_breakpoint
decl_stmt|;
name|CORE_ADDR
name|step_range_start
decl_stmt|;
name|CORE_ADDR
name|step_range_end
decl_stmt|;
name|struct
name|frame_id
name|step_frame_id
decl_stmt|;
name|CORE_ADDR
name|step_sp
decl_stmt|;
name|int
name|current_line
decl_stmt|;
name|struct
name|symtab
modifier|*
name|current_symtab
decl_stmt|;
name|int
name|trap_expected
decl_stmt|;
name|int
name|handling_longjmp
decl_stmt|;
name|int
name|another_trap
decl_stmt|;
comment|/* This is set TRUE when a catchpoint of a shared library event      triggers.  Since we don't wish to leave the inferior in the      solib hook when we report the event, we step the inferior      back to user code before stopping and reporting the event.  */
name|int
name|stepping_through_solib_after_catch
decl_stmt|;
comment|/* When stepping_through_solib_after_catch is TRUE, this is a      list of the catchpoints that should be reported as triggering      when we finally do stop stepping.  */
name|bpstat
name|stepping_through_solib_catchpoints
decl_stmt|;
comment|/* This is set to TRUE when this thread is in a signal handler      trampoline and we're single-stepping through it.  */
name|int
name|stepping_through_sigtramp
decl_stmt|;
comment|/* Private data used by the target vector implementation.  */
name|struct
name|private_thread_info
modifier|*
name|private
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Create an empty thread list, or empty the existing one.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_thread_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a thread to the thread list.    Note that add_thread now returns the handle of the new thread,    so that the caller may initialize the private thread data.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|thread_info
modifier|*
name|add_thread
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete an existing thread list entry.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|delete_thread
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete a step_resume_breakpoint from the thread database. */
end_comment

begin_function_decl
specifier|extern
name|void
name|delete_step_resume_breakpoint
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Translate the integer thread id (GDB's homegrown id, not the system's)    into a "pid" (which may be overloaded with extra thread information).  */
end_comment

begin_function_decl
specifier|extern
name|ptid_t
name|thread_id_to_pid
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Translate a 'pid' (which may be overloaded with extra thread information)     into the integer thread id (GDB's homegrown id, not the system's).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|pid_to_thread_id
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boolean test for an already-known pid (which may be overloaded with    extra thread information).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|in_thread_list
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boolean test for an already-known thread id (GDB's homegrown id,     not the system's).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|valid_thread_id
parameter_list|(
name|int
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Search function to lookup a thread by 'pid'.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|thread_info
modifier|*
name|find_thread_pid
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Iterator function to call a user-provided callback function    once for each known thread.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|thread_callback_func
function_decl|)
parameter_list|(
name|struct
name|thread_info
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|thread_info
modifier|*
name|iterate_over_threads
parameter_list|(
name|thread_callback_func
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* infrun context switch: save the debugger state for the given thread.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|save_infrun_state
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|CORE_ADDR
name|prev_pc
parameter_list|,
name|int
name|trap_expected
parameter_list|,
name|struct
name|breakpoint
modifier|*
name|step_resume_breakpoint
parameter_list|,
name|struct
name|breakpoint
modifier|*
name|through_sigtramp_breakpoint
parameter_list|,
name|CORE_ADDR
name|step_range_start
parameter_list|,
name|CORE_ADDR
name|step_range_end
parameter_list|,
specifier|const
name|struct
name|frame_id
modifier|*
name|step_frame_id
parameter_list|,
name|int
name|handling_longjmp
parameter_list|,
name|int
name|another_trap
parameter_list|,
name|int
name|stepping_through_solib_after_catch
parameter_list|,
name|bpstat
name|stepping_through_solib_catchpoints
parameter_list|,
name|int
name|stepping_through_sigtramp
parameter_list|,
name|int
name|current_line
parameter_list|,
name|struct
name|symtab
modifier|*
name|current_symtab
parameter_list|,
name|CORE_ADDR
name|step_sp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* infrun context switch: load the debugger state previously saved    for the given thread.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|load_infrun_state
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|CORE_ADDR
modifier|*
name|prev_pc
parameter_list|,
name|int
modifier|*
name|trap_expected
parameter_list|,
name|struct
name|breakpoint
modifier|*
modifier|*
name|step_resume_breakpoint
parameter_list|,
name|struct
name|breakpoint
modifier|*
modifier|*
name|through_sigtramp_breakpoint
parameter_list|,
name|CORE_ADDR
modifier|*
name|step_range_start
parameter_list|,
name|CORE_ADDR
modifier|*
name|step_range_end
parameter_list|,
name|struct
name|frame_id
modifier|*
name|step_frame_id
parameter_list|,
name|int
modifier|*
name|handling_longjmp
parameter_list|,
name|int
modifier|*
name|another_trap
parameter_list|,
name|int
modifier|*
name|stepping_through_solib_affter_catch
parameter_list|,
name|bpstat
modifier|*
name|stepping_through_solib_catchpoints
parameter_list|,
name|int
modifier|*
name|stepping_through_sigtramp
parameter_list|,
name|int
modifier|*
name|current_line
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
name|current_symtab
parameter_list|,
name|CORE_ADDR
modifier|*
name|step_sp
parameter_list|)
function_decl|;
end_function_decl

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDBTHREAD_H */
end_comment

end_unit

