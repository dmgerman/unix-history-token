begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target operations for the remote server for GDB.    Copyright 2002, 2003, 2004    Free Software Foundation, Inc.     Contributed by MontaVista Software.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_H
end_define

begin_comment
comment|/* This structure describes how to resume a particular thread (or    all threads) based on the client's request.  If thread is -1, then    this entry applies to all threads.  These are generally passed around    as an array, and terminated by a thread == -1 entry.  */
end_comment

begin_struct
struct|struct
name|thread_resume
block|{
name|int
name|thread
decl_stmt|;
comment|/* If non-zero, leave this thread stopped.  */
name|int
name|leave_stopped
decl_stmt|;
comment|/* If non-zero, we want to single-step.  */
name|int
name|step
decl_stmt|;
comment|/* If non-zero, send this signal when we resume.  */
name|int
name|sig
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|target_ops
block|{
comment|/* Start a new process.       PROGRAM is a path to the program to execute.      ARGS is a standard NULL-terminated array of arguments,      to be passed to the inferior as ``argv''.       Returns the new PID on success, -1 on failure.  Registers the new      process with the process list.  */
name|int
function_decl|(
modifier|*
name|create_inferior
function_decl|)
parameter_list|(
name|char
modifier|*
name|program
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
function_decl|;
comment|/* Attach to a running process.       PID is the process ID to attach to, specified by the user      or a higher layer.  */
name|int
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
comment|/* Kill all inferiors.  */
name|void
function_decl|(
modifier|*
name|kill
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Detach from all inferiors.  */
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return 1 iff the thread with process ID PID is alive.  */
name|int
function_decl|(
modifier|*
name|thread_alive
function_decl|)
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
comment|/* Resume the inferior process.  */
name|void
function_decl|(
modifier|*
name|resume
function_decl|)
parameter_list|(
name|struct
name|thread_resume
modifier|*
name|resume_info
parameter_list|)
function_decl|;
comment|/* Wait for the inferior process to change state.       STATUSP will be filled in with a response code to send to GDB.       Returns the signal which caused the process to stop.  */
name|unsigned
name|char
function_decl|(
modifier|*
name|wait
function_decl|)
parameter_list|(
name|char
modifier|*
name|status
parameter_list|)
function_decl|;
comment|/* Fetch registers from the inferior process.       If REGNO is -1, fetch all registers; otherwise, fetch at least REGNO.  */
name|void
function_decl|(
modifier|*
name|fetch_registers
function_decl|)
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
comment|/* Store registers to the inferior process.       If REGNO is -1, store all registers; otherwise, store at least REGNO.  */
name|void
function_decl|(
modifier|*
name|store_registers
function_decl|)
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
comment|/* Read memory from the inferior process.  This should generally be      called through read_inferior_memory, which handles breakpoint shadowing.       Read LEN bytes at MEMADDR into a buffer at MYADDR.         Returns 0 on success and errno on failure.  */
name|int
function_decl|(
modifier|*
name|read_memory
function_decl|)
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* Write memory to the inferior process.  This should generally be      called through write_inferior_memory, which handles breakpoint shadowing.       Write LEN bytes from the buffer at MYADDR to MEMADDR.       Returns 0 on success and errno on failure.  */
name|int
function_decl|(
modifier|*
name|write_memory
function_decl|)
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
specifier|const
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* Query GDB for the values of any symbols we're interested in.      This function is called whenever we receive a "qSymbols::"      query, which corresponds to every time more symbols (might)      become available.  NULL if we aren't interested in any      symbols.  */
name|void
function_decl|(
modifier|*
name|look_up_symbols
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Send a signal to the inferior process, however is appropriate.  */
name|void
function_decl|(
modifier|*
name|send_signal
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Read auxiliary vector data from the inferior process.       Read LEN bytes at OFFSET into a buffer at MYADDR.  */
name|int
function_decl|(
modifier|*
name|read_auxv
function_decl|)
parameter_list|(
name|CORE_ADDR
name|offset
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
modifier|*
name|the_target
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_target_ops
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|create_inferior
parameter_list|(
name|program
parameter_list|,
name|args
parameter_list|)
define|\
value|(*the_target->create_inferior) (program, args)
end_define

begin_define
define|#
directive|define
name|myattach
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*the_target->attach) (pid)
end_define

begin_define
define|#
directive|define
name|kill_inferior
parameter_list|()
define|\
value|(*the_target->kill) ()
end_define

begin_define
define|#
directive|define
name|detach_inferior
parameter_list|()
define|\
value|(*the_target->detach) ()
end_define

begin_define
define|#
directive|define
name|mythread_alive
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*the_target->thread_alive) (pid)
end_define

begin_define
define|#
directive|define
name|fetch_inferior_registers
parameter_list|(
name|regno
parameter_list|)
define|\
value|(*the_target->fetch_registers) (regno)
end_define

begin_define
define|#
directive|define
name|store_inferior_registers
parameter_list|(
name|regno
parameter_list|)
define|\
value|(*the_target->store_registers) (regno)
end_define

begin_function_decl
name|unsigned
name|char
name|mywait
parameter_list|(
name|char
modifier|*
name|statusp
parameter_list|,
name|int
name|connected_wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_inferior_memory
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_inferior_memory
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
specifier|const
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_desired_inferior
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_H */
end_comment

end_unit

