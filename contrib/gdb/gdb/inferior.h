begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables that describe the inferior process running under GDB:    Where it is, why it stopped, and how to step it.     Copyright 1986, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995,    1996, 1998, 1999, 2000, 2001, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INFERIOR_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|INFERIOR_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|target_waitstatus
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_comment
comment|/* For bpstat.  */
end_comment

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_comment
comment|/* For enum target_signal.  */
end_comment

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_comment
comment|/* For struct frame_id.  */
end_comment

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_comment
comment|/* Structure in which to save the status of the inferior.  Create/Save    through "save_inferior_status", restore through    "restore_inferior_status".     This pair of routines should be called around any transfer of    control to the inferior which you don't want showing up in your    control variables.  */
end_comment

begin_struct_decl
struct_decl|struct
name|inferior_status
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|struct
name|inferior_status
modifier|*
name|save_inferior_status
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_inferior_status
parameter_list|(
name|struct
name|inferior_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup_restore_inferior_status
parameter_list|(
name|struct
name|inferior_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|discard_inferior_status
parameter_list|(
name|struct
name|inferior_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_inferior_status_register
parameter_list|(
name|struct
name|inferior_status
modifier|*
name|inf_status
parameter_list|,
name|int
name|regno
parameter_list|,
name|LONGEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The -1 ptid, often used to indicate either an error condition    or a "don't care" condition, i.e, "run all threads."  */
end_comment

begin_decl_stmt
specifier|extern
name|ptid_t
name|minus_one_ptid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The null or zero ptid, often used to indicate no process. */
end_comment

begin_decl_stmt
specifier|extern
name|ptid_t
name|null_ptid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Attempt to find and return an existing ptid with the given PID, LWP,    and TID components.  If none exists, create a new one and return    that.  */
end_comment

begin_function_decl
name|ptid_t
name|ptid_build
parameter_list|(
name|int
name|pid
parameter_list|,
name|long
name|lwp
parameter_list|,
name|long
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find/Create a ptid from just a pid. */
end_comment

begin_function_decl
name|ptid_t
name|pid_to_ptid
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch the pid (process id) component from a ptid. */
end_comment

begin_function_decl
name|int
name|ptid_get_pid
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch the lwp (lightweight process) component from a ptid. */
end_comment

begin_function_decl
name|long
name|ptid_get_lwp
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch the tid (thread id) component from a ptid. */
end_comment

begin_function_decl
name|long
name|ptid_get_tid
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compare two ptids to see if they are equal */
end_comment

begin_function_decl
specifier|extern
name|int
name|ptid_equal
parameter_list|(
name|ptid_t
name|p1
parameter_list|,
name|ptid_t
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Save value of inferior_ptid so that it may be restored by    a later call to do_cleanups().  Returns the struct cleanup    pointer needed for later doing the cleanup.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|save_inferior_ptid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_sigint_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_sigint_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_sigio_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_sigio_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Collected pid, tid, etc. of the debugged inferior.  When there's    no inferior, PIDGET (inferior_ptid) will be 0. */
end_comment

begin_decl_stmt
specifier|extern
name|ptid_t
name|inferior_ptid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is the inferior running right now, as a result of a 'run&',    'continue&' etc command? This is used in asycn gdb to determine    whether a command that the user enters while the target is running    is allowed or not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_executing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we simulating synchronous execution? This is used in async gdb    to implement the 'run', 'continue' etc commands, which will not    redisplay the prompt until the execution is actually over. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sync_execution
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is only valid when inferior_ptid is non-zero.     If this is 0, then exec events should be noticed and responded to    by the debugger (i.e., be reported to the user).     If this is> 0, then that many subsequent exec events should be    ignored (i.e., not be reported to the user).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inferior_ignoring_startup_exec_events
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is only valid when inferior_ignoring_startup_exec_events is    zero.     Some targets (stupidly) report more than one exec event per actual    call to an event() system call.  If only the last such exec event    need actually be noticed and responded to by the debugger (i.e.,    be reported to the user), then this is the number of "leading"    exec events which should be ignored.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inferior_ignoring_leading_exec_events
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inferior environment. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|environ
modifier|*
name|inferior_environ
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|clear_proceed_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proceed
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|enum
name|target_signal
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When set, stop the 'step' command if we enter a function which has    no line number information.  The normal behavior is that we step    over such function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|step_stop_if_no_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|kill_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_mourn_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminal_save_ours
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminal_ours
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|read_pc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|read_pc_pid
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_pc_pid
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_target_write_pc
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|read_sp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deprecated_write_sp
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|deprecated_read_fp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|unsigned_pointer_to_address
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unsigned_address_to_pointer
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|signed_pointer_to_address
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|address_to_signed_pointer
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wait_for_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fetch_inferior_event
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_wait_for_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_exec_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reopen_exec_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The `resume' routine should only be called in special circumstances.    Normally, use `proceed', which handles a lot of bookkeeping.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|resume
parameter_list|(
name|int
parameter_list|,
name|enum
name|target_signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From misc files */
end_comment

begin_function_decl
specifier|extern
name|void
name|default_print_registers_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|ui_file
modifier|*
name|file
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|all
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_inferior_registers
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fetch_inferior_registers
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|solib_create_inferior_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|child_terminal_info
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|term_info
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminal_ours_for_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminal_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminal_init_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|terminal_init_inferior_with_pgrp
parameter_list|(
name|int
name|pgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From infptrace.c or infttrace.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|attach
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|detach
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PTRACE method of waiting for inferior process.  */
end_comment

begin_function_decl
name|int
name|ptrace_wait
parameter_list|(
name|ptid_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|child_resume
parameter_list|(
name|ptid_t
parameter_list|,
name|int
parameter_list|,
name|enum
name|target_signal
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_ARG3_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|int
end_define

begin_comment
comment|/* Correct definition for most systems. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|call_ptrace
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|PTRACE_ARG3_TYPE
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pre_fork_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From procfs.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|proc_iterate_over_mappings
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptid_t
name|procfs_first_available
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From fork-child.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|fork_inferior
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|startup_inferior
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|construct_inferior_arguments
parameter_list|(
name|struct
name|gdbarch
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From inflow.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|new_tty_prefork
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdb_has_a_terminal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From infrun.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|start_remote
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|normal_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_stop_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_print_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_pass_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_stop_update
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_print_update
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_pass_update
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_last_target_status
parameter_list|(
name|ptid_t
modifier|*
name|ptid
parameter_list|,
name|struct
name|target_waitstatus
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|follow_inferior_reset_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From infcmd.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|tty_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|attach_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_inferior_args
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|set_inferior_args
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_inferior_args_vector
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|registers_info
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nexti_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stepi_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|continue_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|interrupt_target_command
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Last signal that the inferior received (why it stopped).  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|target_signal
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
comment|/* Chain containing status of breakpoint(s) that we have stopped at.  */
end_comment

begin_decl_stmt
specifier|extern
name|bpstat
name|stop_bpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag indicating that a command has proceeded the inferior past the    current breakpoint.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|breakpoint_proceeded
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
comment|/* Range to single step within.    If this is nonzero, respond to a single-step signal    by continuing to step if the pc is in this range.     If step_range_start and step_range_end are both 1, it means to step for    a single instruction (FIXME: it might clean up wait_for_inferior in a    minor way if this were changed to the address of the instruction and    that address plus one.  But maybe not.).  */
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
name|struct
name|frame_id
name|step_frame_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our notion of the current stack pointer.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|step_sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 means step over all subroutine calls.    -1 means step over calls to undebuggable functions.  */
end_comment

begin_enum
enum|enum
name|step_over_calls_kind
block|{
name|STEP_OVER_NONE
block|,
name|STEP_OVER_ALL
block|,
name|STEP_OVER_UNDEBUGGABLE
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|step_over_calls_kind
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
comment|/* Nonzero means expecting a trap and caller will handle it    themselves.  It is used when running in the shell before the child    program has been exec'd; and when running some kinds of remote    stuff (FIXME?).  */
end_comment

begin_comment
comment|/* It is also used after attach, due to attaching to a process. This    is a bit trickier.  When doing an attach, the kernel stops the    debuggee with a SIGSTOP.  On newer GNU/Linux kernels (>= 2.5.61)    the handling of SIGSTOP for a ptraced process has changed. Earlier    versions of the kernel would ignore these SIGSTOPs, while now    SIGSTOP is treated like any other signal, i.e. it is not muffled.        If the gdb user does a 'continue' after the 'attach', gdb passes    the global variable stop_signal (which stores the signal from the    attach, SIGSTOP) to the ptrace(PTRACE_CONT,...)  call.  This is    problematic, because the kernel doesn't ignore such SIGSTOP    now. I.e. it is reported back to gdb, which in turn presents it    back to the user.      To avoid the problem, we use STOP_QUIETLY_NO_SIGSTOP, which allows    gdb to clear the value of stop_signal after the attach, so that it    is not passed back down to the kernel.  */
end_comment

begin_enum
enum|enum
name|stop_kind
block|{
name|NO_STOP_QUIETLY
init|=
literal|0
block|,
name|STOP_QUIETLY
block|,
name|STOP_QUIETLY_NO_SIGSTOP
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|stop_kind
name|stop_soon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if proceed is being used for a "finish" command or a similar    situation when stop_registers should be saved.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|proceed_to_finish
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save register contents here when about to pop a stack dummy frame,    if-and-only-if proceed_to_finish is set.    Thus this contains the return value from the called function (assuming    values are returned in a register).  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|regcache
modifier|*
name|stop_registers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the child process in inferior_ptid was attached rather    than forked.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|attach_flag
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Possible values for CALL_DUMMY_LOCATION.  */
end_comment

begin_define
define|#
directive|define
name|ON_STACK
value|1
end_define

begin_define
define|#
directive|define
name|AT_ENTRY_POINT
value|4
end_define

begin_define
define|#
directive|define
name|AT_SYMBOL
value|5
end_define

begin_comment
comment|/* FIXME: cagney/2000-04-17: gdbarch should manage this.  The default    shouldn't be necessary. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PUSH_DUMMY_FRAME
end_if

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|(internal_error (__FILE__, __LINE__, "PUSH_DUMMY_FRAME"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|STORE_STRUCT_RETURN
end_if

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "STORE_STRUCT_RETURN"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Are we in a call dummy? */
end_comment

begin_comment
comment|/* NOTE: cagney/2002-11-24: Targets need to both switch to generic    dummy frames, and use generic_pc_in_call_dummy().  The generic    version should be able to handle all cases since that code works by    saving the address of the dummy's breakpoint (where ever it is).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|deprecated_pc_in_call_dummy_on_stack
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|frame_address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOTE: cagney/2002-11-24: Targets need to both switch to generic    dummy frames, and use generic_pc_in_call_dummy().  The generic    version should be able to handle all cases since that code works by    saving the address of the dummy's breakpoint (where ever it is).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|deprecated_pc_in_call_dummy_at_entry_point
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|frame_address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If STARTUP_WITH_SHELL is set, GDB's "run"    will attempts to start up the debugee under a shell.    This is in order for argument-expansion to occur. E.g.,    (gdb) run *    The "*" gets expanded by the shell into a list of files.    While this is a nice feature, it turns out to interact badly    with some of the catch-fork/catch-exec features we have added.    In particular, if the shell does any fork/exec's before    the exec of the target program, that can confuse GDB.    To disable this feature, set STARTUP_WITH_SHELL to 0.    To enable this feature, set STARTUP_WITH_SHELL to 1.    The catch-exec traps expected during start-up will    be 1 if target is not started up with a shell, 2 if it is.    - RT    If you disable this, you need to decrement    START_INFERIOR_TRAPS_EXPECTED in tm.h. */
end_comment

begin_define
define|#
directive|define
name|STARTUP_WITH_SHELL
value|1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|START_INFERIOR_TRAPS_EXPECTED
argument_list|)
end_if

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
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
comment|/* !defined (INFERIOR_H) */
end_comment

end_unit

