begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  * Modified 1990 by Van Jacobson at Lawrence Berkeley Laboratory.  *  *	@(#)inferior.h	6.3 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Variables that describe the inferior process running under GDB:    Where it is, why it stopped, and how to step it.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Structure in which to save the status of the inferior.  Save  * through "save_inferior_status", restore through  * "restore_inferior_status".  * This pair of routines should be called around any transfer of  * control to the inferior which you don't want showing up in your  * control variables.  */
end_comment

begin_struct
struct|struct
name|inferior_status
block|{
name|int
name|pc_changed
decl_stmt|;
name|int
name|stop_signal
decl_stmt|;
name|int
name|stop_pc
decl_stmt|;
name|int
name|stop_frame_address
decl_stmt|;
name|int
name|stop_breakpoint
decl_stmt|;
name|int
name|stop_step
decl_stmt|;
name|int
name|stop_stack_dummy
decl_stmt|;
name|int
name|stopped_by_random_signal
decl_stmt|;
name|int
name|trap_expected
decl_stmt|;
name|CORE_ADDR
name|step_range_start
decl_stmt|;
name|CORE_ADDR
name|step_range_end
decl_stmt|;
name|FRAME_ADDR
name|step_frame_address
decl_stmt|;
name|int
name|step_over_calls
decl_stmt|;
name|CORE_ADDR
name|step_resume_break_address
decl_stmt|;
name|int
name|stop_after_trap
decl_stmt|;
name|int
name|stop_after_attach
decl_stmt|;
name|FRAME_ADDR
name|selected_frame_address
decl_stmt|;
name|int
name|selected_level
decl_stmt|;
name|struct
name|command_line
modifier|*
name|breakpoint_commands
decl_stmt|;
name|char
name|register_context
index|[
name|REGISTER_BYTES
index|]
decl_stmt|;
name|int
name|restore_stack_info
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|save_inferior_status
argument_list|()
decl_stmt|,
name|restore_inferior_status
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File name for default use for standard in/out in the inferior.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inferior_io_terminal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pid of our debugged inferior, or 0 if no inferior now.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inferior_pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if debugging a remote machine via a serial link or ethernet.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|remote_debugging
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines for use in remote debugging.  Documented in remote.c.  */
end_comment

begin_function_decl
name|int
name|remote_read_inferior_memory
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remote_write_inferior_memory
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Last signal that the inferior received (why it stopped).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stop_signal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Address at which inferior stopped.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|stop_pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack frame when program stopped.  */
end_comment

begin_decl_stmt
specifier|extern
name|FRAME_ADDR
name|stop_frame_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of breakpoint it stopped at, or 0 if none.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stop_breakpoint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if stopped due to a step command.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stop_step
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if stopped due to completion of a stack dummy routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stop_stack_dummy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if program stopped due to a random (unexpected) signal in    inferior process.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stopped_by_random_signal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Range to single step within.    If this is nonzero, respond to a single-step signal    by continuing to step if the pc is in this range.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|step_range_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inclusive */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|step_range_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exclusive */
end_comment

begin_comment
comment|/* Stack frame address as of when stepping command was issued.    This is how we know when we step into a subroutine call,    and how to set the frame for the breakpoint used to step out.  */
end_comment

begin_decl_stmt
specifier|extern
name|FRAME_ADDR
name|step_frame_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 means step over all subroutine calls.    -1 means step over calls to undebuggable functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|step_over_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If stepping, nonzero means step count is> 1    so don't print frame next time inferior stops    if it stops due to stepping.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|step_multi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save register contents here when about to pop a stack dummy frame.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|stop_registers
index|[
name|REGISTER_BYTES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if pc has been changed by the debugger    since the inferior stopped.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pc_changed
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|read_memory_integer
parameter_list|()
function_decl|;
end_function_decl

end_unit

