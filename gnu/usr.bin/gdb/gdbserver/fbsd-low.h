begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal interfaces for the GNU/Linux specific target code for gdbserver.    Copyright 2002, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|regset_fill_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|regset_store_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
name|regset_type
block|{
name|GENERAL_REGS
block|,
name|FP_REGS
block|,
name|EXTENDED_REGS
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|regset_info
block|{
name|int
name|get_request
decl_stmt|,
name|set_request
decl_stmt|;
name|int
name|size
decl_stmt|;
name|enum
name|regset_type
name|type
decl_stmt|;
name|regset_fill_func
name|fill_function
decl_stmt|;
name|regset_store_func
name|store_function
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|regset_info
name|target_regsets
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|fbsd_target_ops
block|{
name|int
name|num_regs
decl_stmt|;
name|int
modifier|*
name|regmap
decl_stmt|;
name|int
function_decl|(
modifier|*
name|cannot_fetch_register
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Returns 0 if we can store the register, 1 if we can not      store the register, and 2 if failure to store the register      is acceptable.  */
name|int
function_decl|(
modifier|*
name|cannot_store_register
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|CORE_ADDR
function_decl|(
modifier|*
name|get_pc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_pc
function_decl|)
parameter_list|(
name|CORE_ADDR
name|newpc
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|breakpoint
decl_stmt|;
name|int
name|breakpoint_len
decl_stmt|;
name|CORE_ADDR
function_decl|(
modifier|*
name|breakpoint_reinsert_addr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|decr_pc_after_break
decl_stmt|;
name|int
function_decl|(
modifier|*
name|breakpoint_at
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fbsd_target_ops
name|the_low_target
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|get_process
parameter_list|(
name|inf
parameter_list|)
value|((struct process_info *)(inf))
end_define

begin_define
define|#
directive|define
name|get_thread_process
parameter_list|(
name|thr
parameter_list|)
value|(get_process (inferior_target_data (thr)))
end_define

begin_define
define|#
directive|define
name|get_process_thread
parameter_list|(
name|proc
parameter_list|)
value|((struct thread_info *) \ 				  find_inferior_id (&all_threads, \ 				  get_process (proc)->tid))
end_define

begin_struct
struct|struct
name|process_info
block|{
name|struct
name|inferior_list_entry
name|head
decl_stmt|;
name|int
name|thread_known
decl_stmt|;
name|int
name|lwpid
decl_stmt|;
name|int
name|tid
decl_stmt|;
comment|/* If this flag is set, the next SIGSTOP will be ignored (the process will      be immediately resumed).  */
name|int
name|stop_expected
decl_stmt|;
comment|/* If this flag is set, the process is known to be stopped right now (stop      event already received in a wait()).  */
name|int
name|stopped
decl_stmt|;
comment|/* If this flag is set, we have sent a SIGSTOP to this process and are      waiting for it to stop.  */
name|int
name|sigstop_sent
decl_stmt|;
comment|/* If this flag is set, STATUS_PENDING is a waitstatus that has not yet      been reported.  */
name|int
name|status_pending_p
decl_stmt|;
name|int
name|status_pending
decl_stmt|;
comment|/* If this flag is set, the pending status is a (GDB-placed) breakpoint.  */
name|int
name|pending_is_breakpoint
decl_stmt|;
name|CORE_ADDR
name|pending_stop_pc
decl_stmt|;
comment|/* If this is non-zero, it is a breakpoint to be reinserted at our next      stop (SIGTRAP stops only).  */
name|CORE_ADDR
name|bp_reinsert
decl_stmt|;
comment|/* If this flag is set, the last continue operation on this process      was a single-step.  */
name|int
name|stepping
decl_stmt|;
comment|/* If this is non-zero, it points to a chain of signals which need to      be delivered to this process.  */
name|struct
name|pending_signals
modifier|*
name|pending_signals
decl_stmt|;
comment|/* A link used when resuming.  It is initialized from the resume request,      and then processed and cleared in fbsd_resume_one_process.  */
name|struct
name|thread_resume
modifier|*
name|resume
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|inferior_list
name|all_processes
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fbsd_attach_lwp
parameter_list|(
name|int
name|pid
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thread_db_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

