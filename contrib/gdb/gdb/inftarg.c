begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-vector operations for controlling Unix child processes, for GDB.    Copyright 1990, 1991, 1992, 1993, 1994, 1995    Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_comment
comment|/* required by inferior.h */
end_comment

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"wait.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_decl_stmt
specifier|static
name|void
name|child_prepare_to_store
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|CHILD_WAIT
end_ifndef

begin_decl_stmt
specifier|static
name|int
name|child_wait
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|target_waitstatus
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHILD_WAIT */
end_comment

begin_decl_stmt
specifier|static
name|void
name|child_open
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
specifier|static
name|void
name|child_files_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_ops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|child_detach
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
specifier|static
name|void
name|child_attach
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
specifier|static
name|void
name|ptrace_me
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ptrace_him
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|child_create_inferior
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|child_mourn_inferior
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|child_can_run
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|child_thread_alive
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
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declaration */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
name|child_ops
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|proc_wait
parameter_list|(
name|pid
parameter_list|,
name|status
parameter_list|)
name|int
name|pid
decl_stmt|;
name|int
modifier|*
name|status
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|__GO32__
return|return
name|wait
argument_list|(
name|status
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|CHILD_WAIT
end_ifndef

begin_comment
comment|/* Wait for child to do something.  Return pid of child, or -1 in case    of error; store status through argument pointer OURSTATUS.  */
end_comment

begin_function
specifier|static
name|int
name|child_wait
parameter_list|(
name|pid
parameter_list|,
name|ourstatus
parameter_list|)
name|int
name|pid
decl_stmt|;
name|struct
name|target_waitstatus
modifier|*
name|ourstatus
decl_stmt|;
block|{
name|int
name|save_errno
decl_stmt|;
name|int
name|status
decl_stmt|;
do|do
block|{
name|set_sigint_trap
argument_list|()
expr_stmt|;
comment|/* Causes SIGINT to be passed on to the 			   attached process. */
name|set_sigio_trap
argument_list|()
expr_stmt|;
name|pid
operator|=
name|proc_wait
argument_list|(
name|inferior_pid
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
name|save_errno
operator|=
name|errno
expr_stmt|;
name|clear_sigio_trap
argument_list|()
expr_stmt|;
name|clear_sigint_trap
argument_list|()
expr_stmt|;
if|if
condition|(
name|pid
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|save_errno
operator|==
name|EINTR
condition|)
continue|continue;
name|fprintf_unfiltered
argument_list|(
name|gdb_stderr
argument_list|,
literal|"Child process unexpectedly missing: %s.\n"
argument_list|,
name|safe_strerror
argument_list|(
name|save_errno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Claim it exited with unknown signal.  */
name|ourstatus
operator|->
name|kind
operator|=
name|TARGET_WAITKIND_SIGNALLED
expr_stmt|;
name|ourstatus
operator|->
name|value
operator|.
name|sig
operator|=
name|TARGET_SIGNAL_UNKNOWN
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
do|while
condition|(
name|pid
operator|!=
name|inferior_pid
condition|)
do|;
comment|/* Some other child died or stopped */
name|store_waitstatus
argument_list|(
name|ourstatus
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return
name|pid
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHILD_WAIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHILD_THREAD_ALIVE
end_ifndef

begin_comment
comment|/* Check to see if the given thread is alive.     FIXME: Is kill() ever the right way to do this?  I doubt it, but    for now we're going to try and be compatable with the old thread    code.  */
end_comment

begin_function
specifier|static
name|int
name|child_thread_alive
parameter_list|(
name|pid
parameter_list|)
name|int
name|pid
decl_stmt|;
block|{
return|return
operator|(
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
operator|!=
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Attach to process PID, then initialize for debugging it.  */
end_comment

begin_function
specifier|static
name|void
name|child_attach
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|args
condition|)
name|error_no_arg
argument_list|(
literal|"process-id to attach"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|ATTACH_DETACH
name|error
argument_list|(
literal|"Can't attach to a process on this machine."
argument_list|)
expr_stmt|;
else|#
directive|else
block|{
name|char
modifier|*
name|exec_file
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|pid
operator|=
name|atoi
argument_list|(
name|args
argument_list|)
expr_stmt|;
if|if
condition|(
name|pid
operator|==
name|getpid
argument_list|()
condition|)
comment|/* Trying to masturbate? */
name|error
argument_list|(
literal|"I refuse to debug myself!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|from_tty
condition|)
block|{
name|exec_file
operator|=
operator|(
name|char
operator|*
operator|)
name|get_exec_file
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|exec_file
condition|)
name|printf_unfiltered
argument_list|(
literal|"Attaching to program `%s', %s\n"
argument_list|,
name|exec_file
argument_list|,
name|target_pid_to_str
argument_list|(
name|pid
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|printf_unfiltered
argument_list|(
literal|"Attaching to %s\n"
argument_list|,
name|target_pid_to_str
argument_list|(
name|pid
argument_list|)
argument_list|)
expr_stmt|;
name|gdb_flush
argument_list|(
name|gdb_stdout
argument_list|)
expr_stmt|;
block|}
name|attach
argument_list|(
name|pid
argument_list|)
expr_stmt|;
name|inferior_pid
operator|=
name|pid
expr_stmt|;
name|push_target
argument_list|(
operator|&
name|child_ops
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* ATTACH_DETACH */
block|}
end_function

begin_comment
comment|/* Take a program previously attached to and detaches it.    The program resumes execution and will no longer stop    on signals, etc.  We'd better not have left any breakpoints    in the program or it'll die when it hits one.  For this    to work, it may be necessary for the process to have been    previously attached.  It *might* work if the program was    started via the normal ptrace (PTRACE_TRACEME).  */
end_comment

begin_function
specifier|static
name|void
name|child_detach
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|ATTACH_DETACH
block|{
name|int
name|siggnal
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|from_tty
condition|)
block|{
name|char
modifier|*
name|exec_file
init|=
name|get_exec_file
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|exec_file
operator|==
literal|0
condition|)
name|exec_file
operator|=
literal|""
expr_stmt|;
name|printf_unfiltered
argument_list|(
literal|"Detaching from program: %s %s\n"
argument_list|,
name|exec_file
argument_list|,
name|target_pid_to_str
argument_list|(
name|inferior_pid
argument_list|)
argument_list|)
expr_stmt|;
name|gdb_flush
argument_list|(
name|gdb_stdout
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|args
condition|)
name|siggnal
operator|=
name|atoi
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|detach
argument_list|(
name|siggnal
argument_list|)
expr_stmt|;
name|inferior_pid
operator|=
literal|0
expr_stmt|;
name|unpush_target
argument_list|(
operator|&
name|child_ops
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|error
argument_list|(
literal|"This version of Unix does not support detaching a process."
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Get ready to modify the registers array.  On machines which store    individual registers, this doesn't need to do anything.  On machines    which store all the registers in one fell swoop, this makes sure    that registers contains all the registers from the program being    debugged.  */
end_comment

begin_function
specifier|static
name|void
name|child_prepare_to_store
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|CHILD_PREPARE_TO_STORE
name|CHILD_PREPARE_TO_STORE
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Print status information about what we're accessing.  */
end_comment

begin_function
specifier|static
name|void
name|child_files_info
parameter_list|(
name|ignore
parameter_list|)
name|struct
name|target_ops
modifier|*
name|ignore
decl_stmt|;
block|{
name|printf_unfiltered
argument_list|(
literal|"\tUsing the running image of %s %s.\n"
argument_list|,
name|attach_flag
condition|?
literal|"attached"
else|:
literal|"child"
argument_list|,
name|target_pid_to_str
argument_list|(
name|inferior_pid
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|child_open
parameter_list|(
name|arg
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|arg
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|error
argument_list|(
literal|"Use the \"run\" command to start a Unix child process."
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Stub function which causes the inferior that runs it, to be ptrace-able    by its parent process.  */
end_comment

begin_function
specifier|static
name|void
name|ptrace_me
parameter_list|()
block|{
comment|/* "Trace me, Dr. Memory!" */
name|call_ptrace
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Stub function which causes the GDB that runs it, to start ptrace-ing    the child process.  */
end_comment

begin_function
specifier|static
name|void
name|ptrace_him
parameter_list|(
name|pid
parameter_list|)
name|int
name|pid
decl_stmt|;
block|{
name|push_target
argument_list|(
operator|&
name|child_ops
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|START_INFERIOR_TRAPS_EXPECTED
name|startup_inferior
argument_list|(
name|START_INFERIOR_TRAPS_EXPECTED
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* One trap to exec the shell, one to exec the program being debugged.  */
name|startup_inferior
argument_list|(
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Start an inferior Unix child process and sets inferior_pid to its pid.    EXEC_FILE is the file to run.    ALLARGS is a string containing the arguments to the program.    ENV is the environment vector to pass.  Errors reported with error().  */
end_comment

begin_function
specifier|static
name|void
name|child_create_inferior
parameter_list|(
name|exec_file
parameter_list|,
name|allargs
parameter_list|,
name|env
parameter_list|)
name|char
modifier|*
name|exec_file
decl_stmt|;
name|char
modifier|*
name|allargs
decl_stmt|;
name|char
modifier|*
modifier|*
name|env
decl_stmt|;
block|{
name|fork_inferior
argument_list|(
name|exec_file
argument_list|,
name|allargs
argument_list|,
name|env
argument_list|,
name|ptrace_me
argument_list|,
name|ptrace_him
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* We are at the first instruction we care about.  */
comment|/* Pedal to the metal... */
name|proceed
argument_list|(
operator|(
name|CORE_ADDR
operator|)
operator|-
literal|1
argument_list|,
name|TARGET_SIGNAL_0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|child_mourn_inferior
parameter_list|()
block|{
name|unpush_target
argument_list|(
operator|&
name|child_ops
argument_list|)
expr_stmt|;
name|proc_remove_foreign
argument_list|(
name|inferior_pid
argument_list|)
expr_stmt|;
name|generic_mourn_inferior
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|child_can_run
parameter_list|()
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Send a SIGINT to the process group.  This acts just like the user typed a    ^C on the controlling terminal.     XXX - This may not be correct for all systems.  Some may want to use    killpg() instead of kill (-pgrp). */
end_comment

begin_function
name|void
name|child_stop
parameter_list|()
block|{
specifier|extern
name|pid_t
name|inferior_process_group
decl_stmt|;
name|kill
argument_list|(
operator|-
name|inferior_process_group
argument_list|,
name|SIGINT
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_decl_stmt
name|struct
name|target_ops
name|child_ops
init|=
block|{
literal|"child"
block|,
comment|/* to_shortname */
literal|"Unix child process"
block|,
comment|/* to_longname */
literal|"Unix child process (started by the \"run\" command)."
block|,
comment|/* to_doc */
name|child_open
block|,
comment|/* to_open */
literal|0
block|,
comment|/* to_close */
name|child_attach
block|,
comment|/* to_attach */
name|child_detach
block|,
comment|/* to_detach */
name|child_resume
block|,
comment|/* to_resume */
name|child_wait
block|,
comment|/* to_wait */
name|fetch_inferior_registers
block|,
comment|/* to_fetch_registers */
name|store_inferior_registers
block|,
comment|/* to_store_registers */
name|child_prepare_to_store
block|,
comment|/* to_prepare_to_store */
name|child_xfer_memory
block|,
comment|/* to_xfer_memory */
name|child_files_info
block|,
comment|/* to_files_info */
name|memory_insert_breakpoint
block|,
comment|/* to_insert_breakpoint */
name|memory_remove_breakpoint
block|,
comment|/* to_remove_breakpoint */
name|terminal_init_inferior
block|,
comment|/* to_terminal_init */
name|terminal_inferior
block|,
comment|/* to_terminal_inferior */
name|terminal_ours_for_output
block|,
comment|/* to_terminal_ours_for_output */
name|terminal_ours
block|,
comment|/* to_terminal_ours */
name|child_terminal_info
block|,
comment|/* to_terminal_info */
name|kill_inferior
block|,
comment|/* to_kill */
literal|0
block|,
comment|/* to_load */
literal|0
block|,
comment|/* to_lookup_symbol */
name|child_create_inferior
block|,
comment|/* to_create_inferior */
name|child_mourn_inferior
block|,
comment|/* to_mourn_inferior */
name|child_can_run
block|,
comment|/* to_can_run */
literal|0
block|,
comment|/* to_notice_signals */
name|child_thread_alive
block|,
comment|/* to_thread_alive */
name|child_stop
block|,
comment|/* to_stop */
name|process_stratum
block|,
comment|/* to_stratum */
literal|0
block|,
comment|/* to_next */
literal|1
block|,
comment|/* to_has_all_memory */
literal|1
block|,
comment|/* to_has_memory */
literal|1
block|,
comment|/* to_has_stack */
literal|1
block|,
comment|/* to_has_registers */
literal|1
block|,
comment|/* to_has_execution */
literal|0
block|,
comment|/* to_sections */
literal|0
block|,
comment|/* to_sections_end */
name|OPS_MAGIC
comment|/* to_magic */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_initialize_inftarg
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_OPTIONAL_PROC_FS
name|char
name|procname
index|[
literal|32
index|]
decl_stmt|;
name|int
name|fd
decl_stmt|;
comment|/* If we have an optional /proc filesystem (e.g. under OSF/1),      don't add ptrace support if we can access the running GDB via /proc.  */
ifndef|#
directive|ifndef
name|PROC_NAME_FMT
define|#
directive|define
name|PROC_NAME_FMT
value|"/proc/%05d"
endif|#
directive|endif
name|sprintf
argument_list|(
name|procname
argument_list|,
name|PROC_NAME_FMT
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|procname
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|>=
literal|0
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|add_target
argument_list|(
operator|&
name|child_ops
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

