begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables that describe the inferior process running under GDB:    Where it is, why it stopped, and how to step it.    Copyright 1986, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996,    1998, 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
name|terminal_ours
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|run_stack_dummy
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
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
name|CORE_ADDR
name|generic_target_read_pc
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
name|CORE_ADDR
name|generic_target_read_sp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_sp
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_target_write_sp
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|read_fp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|generic_target_read_fp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_fp
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_target_write_fp
parameter_list|(
name|CORE_ADDR
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
name|do_registers_info
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REQUIRE_ATTACH
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRE_ATTACH
value|attach
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
argument_list|(
name|REQUIRE_DETACH
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRE_DETACH
parameter_list|(
name|pid
parameter_list|,
name|siggnal
parameter_list|)
value|detach (siggnal)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|clone_and_follow_inferior
parameter_list|(
name|int
parameter_list|,
name|int
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
name|CORE_ADDR
name|step_frame_address
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
comment|/* Nonzero means expecting a trap and caller will handle it themselves.    It is used after attach, due to attaching to a process;    when running in the shell before the child program has been exec'd;    and when running some kinds of remote stuff (FIXME?).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stop_soon_quietly
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
name|char
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
comment|/* Sigtramp is a routine that the kernel calls (which then calls the    signal handler).  On most machines it is a library routine that    is linked into the executable.     This macro, given a program counter value and the name of the    function in which that PC resides (which can be null if the    name is not known), returns nonzero if the PC and name show    that we are in sigtramp.     On most machines just see if the name is sigtramp (and if we have    no name, assume we are not in sigtramp).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IN_SIGTRAMP
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGTRAMP_START
argument_list|)
end_if

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
define|\
value|((pc)>= SIGTRAMP_START(pc)   \&& (pc)< SIGTRAMP_END(pc) \         )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
define|\
value|(name&& STREQ ("_sigtramp", name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|BEFORE_TEXT_END
value|2
end_define

begin_define
define|#
directive|define
name|AFTER_TEXT_END
value|3
end_define

begin_define
define|#
directive|define
name|AT_ENTRY_POINT
value|4
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_GENERIC_DUMMY_FRAMES
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_GENERIC_DUMMY_FRAMES
value|0
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
argument_list|(
name|CALL_DUMMY_LOCATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|ON_STACK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No CALL_DUMMY_LOCATION.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_ADDRESS
parameter_list|()
value|(internal_error (__FILE__, __LINE__, "CALL_DUMMY_ADDRESS"), 0)
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
argument_list|(
name|CALL_DUMMY_START_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|(internal_error (__FILE__, __LINE__, "CALL_DUMMY_START_OFFSET"), 0)
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
argument_list|(
name|CALL_DUMMY_BREAKPOINT_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
value|(0)
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|(internal_error (__FILE__, __LINE__, "CALL_DUMMY_BREAKPOINT_OFFSET"), 0)
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
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
value|(1)
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
argument_list|(
name|CALL_DUMMY_LENGTH
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|(internal_error (__FILE__, __LINE__, "CALL_DUMMY_LENGTH"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST_P
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST
value|(internal_error (__FILE__, __LINE__, "CALL_DUMMY_STACK_ADJUST"), 0)
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
argument_list|(
name|CALL_DUMMY_STACK_ADJUST_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST_P
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME: cagney/2000-04-17: gdbarch should manage this.  The default    shouldn't be necessary. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_P
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CALL_DUMMY
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_P
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CALL_DUMMY_P
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
name|FIX_CALL_DUMMY
end_if

begin_define
define|#
directive|define
name|FIX_CALL_DUMMY
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "FIX_CALL_DUMMY"), 0)
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

begin_function_decl
specifier|extern
name|int
name|pc_in_call_dummy_before_text_end
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

begin_if
if|#
directive|if
operator|!
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
operator|&&
name|CALL_DUMMY_LOCATION
operator|==
name|BEFORE_TEXT_END
end_if

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
value|pc_in_call_dummy_before_text_end (pc, sp, frame_address)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Before text_end.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|pc_in_call_dummy_after_text_end
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

begin_if
if|#
directive|if
operator|!
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
operator|&&
name|CALL_DUMMY_LOCATION
operator|==
name|AFTER_TEXT_END
end_if

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
value|pc_in_call_dummy_after_text_end (pc, sp, frame_address)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|pc_in_call_dummy_on_stack
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

begin_if
if|#
directive|if
operator|!
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
operator|&&
name|CALL_DUMMY_LOCATION
operator|==
name|ON_STACK
end_if

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
value|pc_in_call_dummy_on_stack (pc, sp, frame_address)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|pc_in_call_dummy_at_entry_point
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

begin_if
if|#
directive|if
operator|!
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
operator|&&
name|CALL_DUMMY_LOCATION
operator|==
name|AT_ENTRY_POINT
end_if

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
value|pc_in_call_dummy_at_entry_point (pc, sp, frame_address)
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
comment|/* It's often not enough for our clients to know whether the PC is merely    somewhere within the call dummy.  They may need to know whether the    call dummy has actually completed.  (For example, wait_for_inferior    wants to know when it should truly stop because the call dummy has    completed.  If we're single-stepping because of slow watchpoints,    then we may find ourselves stopped at the entry of the call dummy,    and want to continue stepping until we reach the end.)     Note that this macro is intended for targets (like HP-UX) which    require more than a single breakpoint in their call dummies, and    therefore cannot use the CALL_DUMMY_BREAKPOINT_OFFSET mechanism.     If a target does define CALL_DUMMY_BREAKPOINT_OFFSET, then this    default implementation of CALL_DUMMY_HAS_COMPLETED is sufficient.    Else, a target may wish to supply an implementation that works in    the presense of multiple breakpoints in its call dummy.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_HAS_COMPLETED
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_HAS_COMPLETED
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
define|\
value|PC_IN_CALL_DUMMY((pc), (sp), (frame_address))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

