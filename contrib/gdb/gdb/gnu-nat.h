begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common things used by the various *gnu-nat.c files     Copyright (C) 1995 Free Software Foundation, Inc.     Written by Miles Bader<miles@gnu.ai.mit.edu>     The GNU Hurd is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     The GNU Hurd is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_NAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__GNU_NAT_H__
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<mach.h>
end_include

begin_struct_decl
struct_decl|struct
name|inf
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|inf
modifier|*
name|current_inferior
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Converts a GDB pid to a struct proc.  */
end_comment

begin_function_decl
name|struct
name|proc
modifier|*
name|inf_tid_to_thread
parameter_list|(
name|struct
name|inf
modifier|*
name|inf
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A proc is either a thread, or the task (there can only be one task proc    because it always has the same TID, PROC_TID_TASK).  */
end_comment

begin_struct
struct|struct
name|proc
block|{
name|thread_t
name|port
decl_stmt|;
comment|/* The task or thread port.  */
name|int
name|tid
decl_stmt|;
comment|/* The GDB pid (actually a thread id).  */
name|int
name|num
decl_stmt|;
comment|/* An id number for threads, to print.  */
name|mach_port_t
name|saved_exc_port
decl_stmt|;
comment|/* The task/thread's real exception port.  */
name|mach_port_t
name|exc_port
decl_stmt|;
comment|/* Our replacement, which for.  */
name|int
name|sc
decl_stmt|;
comment|/* Desired suspend count.   */
name|int
name|cur_sc
decl_stmt|;
comment|/* Implemented suspend count.  */
name|int
name|run_sc
decl_stmt|;
comment|/* Default sc when the program is running. */
name|int
name|pause_sc
decl_stmt|;
comment|/* Default sc when gdb has control. */
name|int
name|resume_sc
decl_stmt|;
comment|/* Sc resulting form the last resume. */
name|thread_state_data_t
name|state
decl_stmt|;
comment|/* Registers,&c. */
name|int
name|state_valid
range|:
literal|1
decl_stmt|;
comment|/* True if STATE is up to date. */
name|int
name|state_changed
range|:
literal|1
decl_stmt|;
name|int
name|aborted
range|:
literal|1
decl_stmt|;
comment|/* True if thread_abort has been called.  */
comment|/* Bit mask of registers fetched by gdb.  This is used when we re-fetch      STATE after aborting the thread, to detect that gdb may have out-of-date      information.  */
name|unsigned
name|long
name|fetched_regs
decl_stmt|;
name|struct
name|inf
modifier|*
name|inf
decl_stmt|;
comment|/* Where we come from.  */
name|struct
name|proc
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The task has a thread entry with this TID.  */
end_comment

begin_define
define|#
directive|define
name|PROC_TID_TASK
value|(-1)
end_define

begin_define
define|#
directive|define
name|proc_is_task
parameter_list|(
name|proc
parameter_list|)
value|((proc)->tid == PROC_TID_TASK)
end_define

begin_define
define|#
directive|define
name|proc_is_thread
parameter_list|(
name|proc
parameter_list|)
value|((proc)->tid != PROC_TID_TASK)
end_define

begin_function_decl
specifier|extern
name|int
name|__proc_pid
parameter_list|(
name|struct
name|proc
modifier|*
name|proc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|thread_state_t
name|proc_get_state
parameter_list|(
name|struct
name|proc
modifier|*
name|proc
parameter_list|,
name|int
name|will_modify
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|proc_debug
parameter_list|(
name|_proc
parameter_list|,
name|msg
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do { struct proc *__proc = (_proc); \        debug ("{proc %d/%d %p}: " msg, \ 	      __proc_pid (__proc), __proc->tid, __proc , ##args); } while (0)
end_define

begin_if
if|#
directive|if
name|MAINTENANCE_CMDS
end_if

begin_decl_stmt
specifier|extern
name|int
name|gnu_debug_flag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|msg
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do { if (gnu_debug_flag) \         fprintf (stderr, "%s: " msg "\r\n", __FUNCTION__ , ##args); } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|msg
parameter_list|,
name|args
modifier|...
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_NAT_H__ */
end_comment

end_unit

