begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface between GDB and target environments, including files and processes    Copyright 1990, 1991, 1992 Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by John Gilmore.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_H
end_define

begin_comment
comment|/* This include file defines the interface between the main part    of the debugger, and the part which is target-specific, or    specific to the communications interface between us and the    target.     A TARGET is an interface between the debugger and a particular     kind of file or process.  Targets can be STACKED in STRATA,     so that more than one target can potentially respond to a request.    In particular, memory accesses will walk down the stack of targets    until they find a target that is interested in handling that particular    address.  STRATA are artificial boundaries on the stack, within    which particular kinds of targets live.  Strata exist so that    people don't get confused by pushing e.g. a process target and then    a file target, and wondering why they can't see the current values    of variables any more (the file target is handling them and they    never get to the process target).  So when you push a file target,    it goes into the file stratum, which is always below the process    stratum.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_enum
enum|enum
name|strata
block|{
name|dummy_stratum
block|,
comment|/* The lowest of the low */
name|file_stratum
block|,
comment|/* Executable files, etc */
name|core_stratum
block|,
comment|/* Core dump files */
name|process_stratum
comment|/* Executing processes */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|target_ops
block|{
name|char
modifier|*
name|to_shortname
decl_stmt|;
comment|/* Name this target type */
name|char
modifier|*
name|to_longname
decl_stmt|;
comment|/* Name for printing */
name|char
modifier|*
name|to_doc
decl_stmt|;
comment|/* Documentation.  Does not include trailing 				   newline, and starts with a one-line descrip- 				   tion (probably similar to to_longname). */
name|void
argument_list|(
argument|*to_open
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_close
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_attach
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_detach
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_resume
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_wait
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_fetch_registers
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_store_registers
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_prepare_to_store
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Transfer LEN bytes of memory between GDB address MYADDR and      target address MEMADDR.  If WRITE, transfer them to the target, else      transfer them from the target.  TARGET is the target from which we      get this function.       Return value, N, is one of the following:       0 means that we can't handle this.  If errno has been set, it is the      error which prevented us from doing it (FIXME: What about bfd_error?).       positive (call it N) means that we have transferred N bytes      starting at MEMADDR.  We might be able to handle more bytes      beyond this length, but no promises.       negative (call its absolute value N) means that we cannot      transfer right at MEMADDR, but we could transfer at least      something at MEMADDR + N.  */
name|int
argument_list|(
argument|*to_xfer_memory
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|char
operator|*
name|myaddr
operator|,
name|int
name|len
operator|,
name|int
name|write
operator|,
expr|struct
name|target_ops
operator|*
name|target
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_files_info
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_ops
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_insert_breakpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_remove_breakpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_terminal_init
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_terminal_inferior
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_terminal_ours_for_output
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_terminal_ours
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_terminal_info
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_kill
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_load
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_lookup_symbol
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_create_inferior
argument_list|)
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
expr_stmt|;
name|void
argument_list|(
argument|*to_mourn_inferior
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
argument|*to_can_run
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_notice_signals
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
expr_stmt|;
name|enum
name|strata
name|to_stratum
decl_stmt|;
name|struct
name|target_ops
modifier|*
name|to_next
decl_stmt|;
name|int
name|to_has_all_memory
decl_stmt|;
name|int
name|to_has_memory
decl_stmt|;
name|int
name|to_has_stack
decl_stmt|;
name|int
name|to_has_registers
decl_stmt|;
name|int
name|to_has_execution
decl_stmt|;
name|struct
name|section_table
modifier|*
name|to_sections
decl_stmt|;
name|struct
name|section_table
modifier|*
name|to_sections_end
decl_stmt|;
name|int
name|to_magic
decl_stmt|;
comment|/* Need sub-structure for target machine related rather than comm related? */
block|}
struct|;
end_struct

begin_comment
comment|/* Magic number for checking ops size.  If a struct doesn't end with this    number, somebody changed the declaration but didn't change all the    places that initialize one.  */
end_comment

begin_define
define|#
directive|define
name|OPS_MAGIC
value|3840
end_define

begin_comment
comment|/* The ops structure for our "current" target process.  This should    never be NULL.  If there is no target, it points to the dummy_target.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
modifier|*
name|current_target
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define easy words for doing these operations on our current target.  */
end_comment

begin_define
define|#
directive|define
name|target_shortname
value|(current_target->to_shortname)
end_define

begin_define
define|#
directive|define
name|target_longname
value|(current_target->to_longname)
end_define

begin_comment
comment|/* The open routine takes the rest of the parameters from the command,    and (if successful) pushes a new target onto the stack.    Targets should supply this routine, if only to provide an error message.  */
end_comment

begin_define
define|#
directive|define
name|target_open
parameter_list|(
name|name
parameter_list|,
name|from_tty
parameter_list|)
define|\
value|(*current_target->to_open) (name, from_tty)
end_define

begin_comment
comment|/* Does whatever cleanup is required for a target that we are no longer    going to be calling.  Argument says whether we are quitting gdb and    should not get hung in case of errors, or whether we want a clean    termination even if it takes a while.  This routine is automatically    always called just before a routine is popped off the target stack.    Closing file descriptors and freeing memory are typical things it should    do.  */
end_comment

begin_define
define|#
directive|define
name|target_close
parameter_list|(
name|quitting
parameter_list|)
define|\
value|(*current_target->to_close) (quitting)
end_define

begin_comment
comment|/* Attaches to a process on the target side.  Arguments are as passed    to the `attach' command by the user.  This routine can be called    when the target is not on the target-stack, if the target_can_run    routine returns 1; in that case, it must push itself onto the stack.      Upon exit, the target should be ready for normal operations, and    should be ready to deliver the status of the process immediately     (without waiting) to an upcoming target_wait call.  */
end_comment

begin_define
define|#
directive|define
name|target_attach
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
define|\
value|(*current_target->to_attach) (args, from_tty)
end_define

begin_comment
comment|/* Takes a program previously attached to and detaches it.    The program may resume execution (some targets do, some don't) and will    no longer stop on signals, etc.  We better not have left any breakpoints    in the program or it'll die when it hits one.  ARGS is arguments    typed by the user (e.g. a signal to send the process).  FROM_TTY    says whether to be verbose or not.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|target_detach
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
comment|/* Resume execution of the target process PID.  STEP says whether to    single-step or to run free; SIGGNAL is the signal value (e.g. SIGINT) to be    given to the target, or zero for no signal.  */
end_comment

begin_define
define|#
directive|define
name|target_resume
parameter_list|(
name|pid
parameter_list|,
name|step
parameter_list|,
name|siggnal
parameter_list|)
define|\
value|(*current_target->to_resume) (pid, step, siggnal)
end_define

begin_comment
comment|/* Wait for process pid to do something.  Pid = -1 to wait for any pid to do    something.  Return pid of child, or -1 in case of error; store status    through argument pointer STATUS.  */
end_comment

begin_define
define|#
directive|define
name|target_wait
parameter_list|(
name|pid
parameter_list|,
name|status
parameter_list|)
define|\
value|(*current_target->to_wait) (pid, status)
end_define

begin_comment
comment|/* Fetch register REGNO, or all regs if regno == -1.  No result.  */
end_comment

begin_define
define|#
directive|define
name|target_fetch_registers
parameter_list|(
name|regno
parameter_list|)
define|\
value|(*current_target->to_fetch_registers) (regno)
end_define

begin_comment
comment|/* Store at least register REGNO, or all regs if REGNO == -1.    It can store as many registers as it wants to, so target_prepare_to_store    must have been previously called.  Calls error() if there are problems.  */
end_comment

begin_define
define|#
directive|define
name|target_store_registers
parameter_list|(
name|regs
parameter_list|)
define|\
value|(*current_target->to_store_registers) (regs)
end_define

begin_comment
comment|/* Get ready to modify the registers array.  On machines which store    individual registers, this doesn't need to do anything.  On machines    which store all the registers in one fell swoop, this makes sure    that REGISTERS contains all the registers from the program being    debugged.  */
end_comment

begin_define
define|#
directive|define
name|target_prepare_to_store
parameter_list|()
define|\
value|(*current_target->to_prepare_to_store) ()
end_define

begin_decl_stmt
specifier|extern
name|int
name|target_read_string
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
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
name|int
name|target_read_memory
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
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
name|int
name|target_read_memory_partial
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|,
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
name|int
name|target_write_memory
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
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
name|int
name|xfer_memory
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|target_ops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|child_xfer_memory
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|target_ops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transfer LEN bytes between target address MEMADDR and GDB address MYADDR.    Returns 0 for success, errno code for failure (which includes partial    transfers--if you want a more useful response to partial transfers, try    target_read_memory_partial).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_xfer_memory
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|char
operator|*
name|myaddr
operator|,
name|int
name|len
operator|,
name|int
name|write
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From exec.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|print_section_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_ops
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a line about the current target.  */
end_comment

begin_define
define|#
directive|define
name|target_files_info
parameter_list|()
define|\
value|(*current_target->to_files_info) (current_target)
end_define

begin_comment
comment|/* Insert a breakpoint at address ADDR in the target machine.    SAVE is a pointer to memory allocated for saving the    target contents.  It is guaranteed by the caller to be long enough    to save "sizeof BREAKPOINT" bytes.  Result is 0 for success, or    an errno value.  */
end_comment

begin_define
define|#
directive|define
name|target_insert_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|save
parameter_list|)
define|\
value|(*current_target->to_insert_breakpoint) (addr, save)
end_define

begin_comment
comment|/* Remove a breakpoint at address ADDR in the target machine.    SAVE is a pointer to the same save area     that was previously passed to target_insert_breakpoint.      Result is 0 for success, or an errno value.  */
end_comment

begin_define
define|#
directive|define
name|target_remove_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|save
parameter_list|)
define|\
value|(*current_target->to_remove_breakpoint) (addr, save)
end_define

begin_comment
comment|/* Initialize the terminal settings we record for the inferior,    before we actually run the inferior.  */
end_comment

begin_define
define|#
directive|define
name|target_terminal_init
parameter_list|()
define|\
value|(*current_target->to_terminal_init) ()
end_define

begin_comment
comment|/* Put the inferior's terminal settings into effect.    This is preparation for starting or resuming the inferior.  */
end_comment

begin_define
define|#
directive|define
name|target_terminal_inferior
parameter_list|()
define|\
value|(*current_target->to_terminal_inferior) ()
end_define

begin_comment
comment|/* Put some of our terminal settings into effect,    enough to get proper results from our output,    but do not change into or out of RAW mode    so that no input is discarded.     After doing this, either terminal_ours or terminal_inferior    should be called to get back to a normal state of affairs.  */
end_comment

begin_define
define|#
directive|define
name|target_terminal_ours_for_output
parameter_list|()
define|\
value|(*current_target->to_terminal_ours_for_output) ()
end_define

begin_comment
comment|/* Put our terminal settings into effect.    First record the inferior's terminal settings    so they can be restored properly later.  */
end_comment

begin_define
define|#
directive|define
name|target_terminal_ours
parameter_list|()
define|\
value|(*current_target->to_terminal_ours) ()
end_define

begin_comment
comment|/* Print useful information about our terminal status, if such a thing    exists.  */
end_comment

begin_define
define|#
directive|define
name|target_terminal_info
parameter_list|(
name|arg
parameter_list|,
name|from_tty
parameter_list|)
define|\
value|(*current_target->to_terminal_info) (arg, from_tty)
end_define

begin_comment
comment|/* Kill the inferior process.   Make it go away.  */
end_comment

begin_define
define|#
directive|define
name|target_kill
parameter_list|()
define|\
value|(*current_target->to_kill) ()
end_define

begin_comment
comment|/* Load an executable file into the target process.  This is expected to    not only bring new code into the target process, but also to update    GDB's symbol tables to match.  */
end_comment

begin_define
define|#
directive|define
name|target_load
parameter_list|(
name|arg
parameter_list|,
name|from_tty
parameter_list|)
define|\
value|(*current_target->to_load) (arg, from_tty)
end_define

begin_comment
comment|/* Look up a symbol in the target's symbol table.  NAME is the symbol    name.  ADDRP is a CORE_ADDR * pointing to where the value of the symbol    should be returned.  The result is 0 if successful, nonzero if the    symbol does not exist in the target environment.  This function should    not call error() if communication with the target is interrupted, since    it is called from symbol reading, but should return nonzero, possibly    doing a complain().  */
end_comment

begin_define
define|#
directive|define
name|target_lookup_symbol
parameter_list|(
name|name
parameter_list|,
name|addrp
parameter_list|)
define|\
value|(*current_target->to_lookup_symbol) (name, addrp)
end_define

begin_comment
comment|/* Start an inferior process and set inferior_pid to its pid.    EXEC_FILE is the file to run.    ALLARGS is a string containing the arguments to the program.    ENV is the environment vector to pass.  Errors reported with error().    On VxWorks and various standalone systems, we ignore exec_file.  */
end_comment

begin_define
define|#
directive|define
name|target_create_inferior
parameter_list|(
name|exec_file
parameter_list|,
name|args
parameter_list|,
name|env
parameter_list|)
define|\
value|(*current_target->to_create_inferior) (exec_file, args, env)
end_define

begin_comment
comment|/* The inferior process has died.  Do what is right.  */
end_comment

begin_define
define|#
directive|define
name|target_mourn_inferior
parameter_list|()
define|\
value|(*current_target->to_mourn_inferior) ()
end_define

begin_comment
comment|/* Does target have enough data to do a run or attach command? */
end_comment

begin_define
define|#
directive|define
name|target_can_run
parameter_list|(
name|t
parameter_list|)
define|\
value|((t)->to_can_run) ()
end_define

begin_comment
comment|/* post process changes to signal handling in the inferior.  */
end_comment

begin_define
define|#
directive|define
name|target_notice_signals
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target->to_notice_signals) (pid)
end_define

begin_comment
comment|/* Pointer to next target in the chain, e.g. a core file and an exec file.  */
end_comment

begin_define
define|#
directive|define
name|target_next
define|\
value|(current_target->to_next)
end_define

begin_comment
comment|/* Does the target include all of memory, or only part of it?  This    determines whether we look up the target chain for other parts of    memory if this target can't satisfy a request.  */
end_comment

begin_define
define|#
directive|define
name|target_has_all_memory
define|\
value|(current_target->to_has_all_memory)
end_define

begin_comment
comment|/* Does the target include memory?  (Dummy targets don't.)  */
end_comment

begin_define
define|#
directive|define
name|target_has_memory
define|\
value|(current_target->to_has_memory)
end_define

begin_comment
comment|/* Does the target have a stack?  (Exec files don't, VxWorks doesn't, until    we start a process.)  */
end_comment

begin_define
define|#
directive|define
name|target_has_stack
define|\
value|(current_target->to_has_stack)
end_define

begin_comment
comment|/* Does the target have registers?  (Exec files don't.)  */
end_comment

begin_define
define|#
directive|define
name|target_has_registers
define|\
value|(current_target->to_has_registers)
end_define

begin_comment
comment|/* Does the target have execution?  Can we make it jump (through    hoops), or pop its stack a few times?  FIXME: If this is to work that    way, it needs to check whether an inferior actually exists.    remote-udi.c and probably other targets can be the current target    when the inferior doesn't actually exist at the moment.  Right now    this just tells us whether this target is *capable* of execution.  */
end_comment

begin_define
define|#
directive|define
name|target_has_execution
define|\
value|(current_target->to_has_execution)
end_define

begin_comment
comment|/* Converts a process id to a string.  Usually, the string just contains    `process xyz', but on some systems it may contain    `process xyz thread abc'.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|target_pid_to_str
end_ifndef

begin_define
define|#
directive|define
name|target_pid_to_str
parameter_list|(
name|PID
parameter_list|)
define|\
value|normal_pid_to_str (PID)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|normal_pid_to_str
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Routines for maintenance of the target structures...     add_target:   Add a target to the list of all possible targets.     push_target:  Make this target the top of the stack of currently used 		 targets, within its particular stratum of the stack.  Result 		 is 0 if now atop the stack, nonzero if not on top (maybe 		 should warn user).     unpush_target: Remove this from the stack of currently used targets, 		 no matter where it is on the list.  Returns 0 if no 		 change, 1 if removed from stack.     pop_target:	 Remove the top thing on the stack of current targets.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_target
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
specifier|extern
name|int
name|push_target
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
specifier|extern
name|int
name|unpush_target
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
specifier|extern
name|void
name|target_preopen
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
name|pop_target
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Struct section_table maps address ranges to file sections.  It is    mostly used with BFD files, but can be used without (e.g. for handling    raw disks, or files not in formats handled by BFD).  */
end_comment

begin_struct
struct|struct
name|section_table
block|{
name|CORE_ADDR
name|addr
decl_stmt|;
comment|/* Lowest address in section */
name|CORE_ADDR
name|endaddr
decl_stmt|;
comment|/* 1+highest address in section */
name|sec_ptr
name|sec_ptr
decl_stmt|;
comment|/* BFD section pointer */
name|bfd
modifier|*
name|bfd
decl_stmt|;
comment|/* BFD file pointer */
block|}
struct|;
end_struct

begin_comment
comment|/* Builds a section table, given args BFD, SECTABLE_PTR, SECEND_PTR.    Returns 0 if OK, 1 on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|build_section_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|section_table
operator|*
operator|*
operator|,
expr|struct
name|section_table
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From mem-break.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|memory_remove_breakpoint
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|memory_insert_breakpoint
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From target.c */
end_comment

begin_decl_stmt
name|void
name|noprocess
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|find_default_attach
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
name|void
name|find_default_create_inferior
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
name|struct
name|target_ops
modifier|*
name|find_core_target
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TARGET_H) */
end_comment

end_unit

