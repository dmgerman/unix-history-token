begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables that describe the inferior process running under GDB:    Where it is, why it stopped, and how to step it.    Copyright 1986, 1989, 1992, 1996, 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Structure in which to save the status of the inferior.  Save    through "save_inferior_status", restore through    "restore_inferior_status".    This pair of routines should be called around any transfer of    control to the inferior which you don't want showing up in your    control variables.  */
end_comment

begin_struct
struct|struct
name|inferior_status
block|{
name|enum
name|target_signal
name|stop_signal
decl_stmt|;
name|CORE_ADDR
name|stop_pc
decl_stmt|;
name|bpstat
name|stop_bpstat
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
name|CORE_ADDR
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
name|stop_soon_quietly
decl_stmt|;
name|CORE_ADDR
name|selected_frame_address
decl_stmt|;
name|char
name|stop_registers
index|[
name|REGISTER_BYTES
index|]
decl_stmt|;
comment|/* These are here because if call_function_by_hand has written some      registers and then decides to call error(), we better not have changed      any registers.  */
name|char
name|registers
index|[
name|REGISTER_BYTES
index|]
decl_stmt|;
name|int
name|selected_level
decl_stmt|;
name|int
name|breakpoint_proceeded
decl_stmt|;
name|int
name|restore_stack_info
decl_stmt|;
name|int
name|proceed_to_finish
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This macro gives the number of registers actually in use by the    inferior.  This may be less than the total number of registers,    perhaps depending on the actual CPU in use or program being run.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCH_NUM_REGS
end_ifndef

begin_define
define|#
directive|define
name|ARCH_NUM_REGS
value|NUM_REGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|save_inferior_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|inferior_status
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|restore_inferior_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|inferior_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_sigint_trap
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
name|clear_sigint_trap
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
name|set_sigio_trap
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
name|clear_sigio_trap
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
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
comment|/* This is only valid when inferior_pid is non-zero.     If this is 0, then exec events should be noticed and responded to    by the debugger (i.e., be reported to the user).     If this is> 0, then that many subsequent exec events should be    ignored (i.e., not be reported to the user).    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inferior_ignoring_startup_exec_events
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is only valid when inferior_ignoring_startup_exec_events is    zero.     Some targets (stupidly) report more than one exec event per actual    call to an event() system call.  If only the last such exec event    need actually be noticed and responded to by the debugger (i.e.,    be reported to the user), then this is the number of "leading"    exec events which should be ignored.    */
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

begin_comment
comment|/* Character array containing an image of the inferior programs' registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|registers
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Array of validity bits (one per register).  Nonzero at position XXX_REGNUM    means that `registers' contains a valid copy of inferior register XXX.    -1 if register value is not available. */
end_comment

begin_decl_stmt
specifier|extern
name|SIGNED
name|char
name|register_valid
index|[
name|NUM_REGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_proceed_status
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
name|proceed
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
expr|enum
name|target_signal
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kill_inferior
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
name|generic_mourn_inferior
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
name|terminal_ours
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
name|run_stack_dummy
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
index|[
name|REGISTER_BYTES
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|read_pc
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
name|CORE_ADDR
name|read_pc_pid
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
name|void
name|write_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_pc_pid
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|read_sp
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
name|write_sp
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|read_fp
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
name|write_fp
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wait_for_inferior
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
name|init_wait_for_inferior
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
name|close_exec_file
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
name|reopen_exec_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The `resume' routine should only be called in special circumstances.    Normally, use `proceed', which handles a lot of bookkeeping.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|resume
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|enum
name|target_signal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From misc files */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|store_inferior_registers
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
name|void
name|fetch_inferior_registers
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
name|void
name|solib_create_inferior_hook
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
name|child_terminal_info
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|term_info
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|terminal_ours_for_output
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
name|terminal_inferior
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
name|terminal_init_inferior
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
name|terminal_init_inferior_with_pgrp
name|PARAMS
argument_list|(
operator|(
name|int
name|pgrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From infptrace.c or infttrace.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|attach
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|detach
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ptrace_wait
name|PARAMS
argument_list|(
operator|(
name|int
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
name|child_resume
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
expr|enum
name|target_signal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|call_ptrace
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|PTRACE_ARG3_TYPE
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pre_fork_inferior
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From procfs.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|proc_iterate_over_mappings
name|PARAMS
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|,
name|CORE_ADDR
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_first_available
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
name|procfs_get_pid_fd
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From fork-child.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fork_inferior
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clone_and_follow_inferior
name|PARAMS
argument_list|(
operator|(
name|int
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
name|startup_inferior
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From inflow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|new_tty_prefork
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gdb_has_a_terminal
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From infrun.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|start_remote
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
name|normal_stop
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
name|signal_stop_state
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
name|signal_print_state
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
name|signal_pass_state
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From infcmd.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tty_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|attach_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|stop_registers
index|[
name|REGISTER_BYTES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the child process in inferior_pid was attached rather    than forked.  */
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

begin_comment
comment|/* Are we in a call dummy?  The code below which allows DECR_PC_AFTER_BREAK    below is for infrun.c, which may give the macro a pc without that    subtracted out.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
end_if

begin_if
if|#
directive|if
name|CALL_DUMMY_LOCATION
operator|==
name|BEFORE_TEXT_END
end_if

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|text_end
decl_stmt|;
end_decl_stmt

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
define|\
value|((pc)>= text_end - CALL_DUMMY_LENGTH         \&& (pc)<= text_end + DECR_PC_AFTER_BREAK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Before text_end.  */
end_comment

begin_if
if|#
directive|if
name|CALL_DUMMY_LOCATION
operator|==
name|AFTER_TEXT_END
end_if

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|text_end
decl_stmt|;
end_decl_stmt

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
define|\
value|((pc)>= text_end   \&& (pc)<= text_end + CALL_DUMMY_LENGTH + DECR_PC_AFTER_BREAK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* After text_end.  */
end_comment

begin_if
if|#
directive|if
name|CALL_DUMMY_LOCATION
operator|==
name|ON_STACK
end_if

begin_comment
comment|/* Is the PC in a call dummy?  SP and FRAME_ADDRESS are the bottom and    top of the stack frame which we are checking, where "bottom" and    "top" refer to some section of memory which contains the code for    the call dummy.  Calls to this macro assume that the contents of    SP_REGNUM and FP_REGNUM (or the saved values thereof), respectively,    are the things to pass.     This won't work on the 29k, where SP_REGNUM and FP_REGNUM don't    have that meaning, but the 29k doesn't use ON_STACK.  This could be    fixed by generalizing this scheme, perhaps by passing in a frame    and adding a few fields, at least on machines which need them for    PC_IN_CALL_DUMMY.     Something simpler, like checking for the stack segment, doesn't work,    since various programs (threads implementations, gcc nested function    stubs, etc) may either allocate stack frames in another segment, or    allocate other kinds of code on the stack.  */
end_comment

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
define|\
value|(INNER_THAN ((sp), (pc))&& (frame_address != 0)&& INNER_THAN ((pc), (frame_address)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On stack.  */
end_comment

begin_if
if|#
directive|if
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
define|\
value|((pc)>= CALL_DUMMY_ADDRESS ()				\&& (pc)<= (CALL_DUMMY_ADDRESS () + DECR_PC_AFTER_BREAK))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* At entry point.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No PC_IN_CALL_DUMMY.  */
end_comment

begin_comment
comment|/* It's often not enough for our clients to know whether the PC is merely    somewhere within the call dummy.  They may need to know whether the    call dummy has actually completed.  (For example, wait_for_inferior    wants to know when it should truly stop because the call dummy has    completed.  If we're single-stepping because of slow watchpoints,    then we may find ourselves stopped at the entry of the call dummy,    and want to continue stepping until we reach the end.)     Note that this macro is intended for targets (like HP-UX) which    require more than a single breakpoint in their call dummies, and    therefore cannot use the CALL_DUMMY_BREAKPOINT_OFFSET mechanism.     If a target does define CALL_DUMMY_BREAKPOINT_OFFSET, then this    default implementation of CALL_DUMMY_HAS_COMPLETED is sufficient.    Else, a target may wish to supply an implementation that works in    the presense of multiple breakpoints in its call dummy.    */
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

