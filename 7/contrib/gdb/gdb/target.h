begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface between GDB and target environments, including files and processes     Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     Contributed by Cygnus Support.  Written by John Gilmore.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mem_attrib
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* This include file defines the interface between the main part    of the debugger, and the part which is target-specific, or    specific to the communications interface between us and the    target.     A TARGET is an interface between the debugger and a particular    kind of file or process.  Targets can be STACKED in STRATA,    so that more than one target can potentially respond to a request.    In particular, memory accesses will walk down the stack of targets    until they find a target that is interested in handling that particular    address.  STRATA are artificial boundaries on the stack, within    which particular kinds of targets live.  Strata exist so that    people don't get confused by pushing e.g. a process target and then    a file target, and wondering why they can't see the current values    of variables any more (the file target is handling them and they    never get to the process target).  So when you push a file target,    it goes into the file stratum, which is always below the process    stratum.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"dcache.h"
end_include

begin_include
include|#
directive|include
file|"memattr.h"
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
name|download_stratum
block|,
comment|/* Downloading of remote targets */
name|process_stratum
block|,
comment|/* Executing processes */
name|thread_stratum
comment|/* Executing threads */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|thread_control_capabilities
block|{
name|tc_none
init|=
literal|0
block|,
comment|/* Default: can't control thread execution.  */
name|tc_schedlock
init|=
literal|1
block|,
comment|/* Can lock the thread scheduler.  */
name|tc_switch
init|=
literal|2
comment|/* Can switch the running thread on demand.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Stuff for target_wait.  */
end_comment

begin_comment
comment|/* Generally, what has the program done?  */
end_comment

begin_enum
enum|enum
name|target_waitkind
block|{
comment|/* The program has exited.  The exit status is in value.integer.  */
name|TARGET_WAITKIND_EXITED
block|,
comment|/* The program has stopped with a signal.  Which signal is in        value.sig.  */
name|TARGET_WAITKIND_STOPPED
block|,
comment|/* The program has terminated with a signal.  Which signal is in        value.sig.  */
name|TARGET_WAITKIND_SIGNALLED
block|,
comment|/* The program is letting us know that it dynamically loaded something        (e.g. it called load(2) on AIX).  */
name|TARGET_WAITKIND_LOADED
block|,
comment|/* The program has forked.  A "related" process' ID is in        value.related_pid.  I.e., if the child forks, value.related_pid        is the parent's ID.  */
name|TARGET_WAITKIND_FORKED
block|,
comment|/* The program has vforked.  A "related" process's ID is in        value.related_pid.  */
name|TARGET_WAITKIND_VFORKED
block|,
comment|/* The program has exec'ed a new executable file.  The new file's        pathname is pointed to by value.execd_pathname.  */
name|TARGET_WAITKIND_EXECD
block|,
comment|/* The program has entered or returned from a system call.  On        HP-UX, this is used in the hardware watchpoint implementation.        The syscall's unique integer ID number is in value.syscall_id */
name|TARGET_WAITKIND_SYSCALL_ENTRY
block|,
name|TARGET_WAITKIND_SYSCALL_RETURN
block|,
comment|/* Nothing happened, but we stopped anyway.  This perhaps should be handled        within target_wait, but I'm not sure target_wait should be resuming the        inferior.  */
name|TARGET_WAITKIND_SPURIOUS
block|,
comment|/* An event has occured, but we should wait again.        Remote_async_wait() returns this when there is an event        on the inferior, but the rest of the world is not interested in        it. The inferior has not stopped, but has just sent some output        to the console, for instance. In this case, we want to go back        to the event loop and wait there for another event from the        inferior, rather than being stuck in the remote_async_wait()        function. This way the event loop is responsive to other events,        like for instance the user typing.  */
name|TARGET_WAITKIND_IGNORE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|target_waitstatus
block|{
name|enum
name|target_waitkind
name|kind
decl_stmt|;
comment|/* Forked child pid, execd pathname, exit status or signal number.  */
union|union
block|{
name|int
name|integer
decl_stmt|;
name|enum
name|target_signal
name|sig
decl_stmt|;
name|int
name|related_pid
decl_stmt|;
name|char
modifier|*
name|execd_pathname
decl_stmt|;
name|int
name|syscall_id
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Possible types of events that the inferior handler will have to    deal with.  */
end_comment

begin_enum
enum|enum
name|inferior_event_type
block|{
comment|/* There is a request to quit the inferior, abandon it.  */
name|INF_QUIT_REQ
block|,
comment|/* Process a normal inferior event which will result in target_wait        being called.  */
name|INF_REG_EVENT
block|,
comment|/* Deal with an error on the inferior.  */
name|INF_ERROR
block|,
comment|/* We are called because a timer went off.  */
name|INF_TIMER
block|,
comment|/* We are called to do stuff after the inferior stops.  */
name|INF_EXEC_COMPLETE
block|,
comment|/* We are called to do some stuff after the inferior stops, but we        are expected to reenter the proceed() and        handle_inferior_event() functions. This is used only in case of        'step n' like commands.  */
name|INF_EXEC_CONTINUE
block|}
enum|;
end_enum

begin_comment
comment|/* Return the string for a signal.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|target_signal_to_string
parameter_list|(
name|enum
name|target_signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the name (SIGHUP, etc.) for a signal.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|target_signal_to_name
parameter_list|(
name|enum
name|target_signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a name (SIGHUP, etc.), return its signal.  */
end_comment

begin_function_decl
name|enum
name|target_signal
name|target_signal_from_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Request the transfer of up to LEN 8-bit bytes of the target's    OBJECT.  The OFFSET, for a seekable object, specifies the starting    point.  The ANNEX can be used to provide additional data-specific    information to the target.     Return the number of bytes actually transfered, zero when no    further transfer is possible, and -1 when the transfer is not    supported.     NOTE: cagney/2003-10-17: The current interface does not support a    "retry" mechanism.  Instead it assumes that at least one byte will    be transfered on each call.     NOTE: cagney/2003-10-17: The current interface can lead to    fragmented transfers.  Lower target levels should not implement    hacks, such as enlarging the transfer, in an attempt to compensate    for this.  Instead, the target stack should be extended so that it    implements supply/collect methods and a look-aside object cache.    With that available, the lowest target can safely and freely "push"    data up the stack.     NOTE: cagney/2003-10-17: Unlike the old query and the memory    transfer mechanisms, these methods are explicitly parameterized by    the target that it should be applied to.     NOTE: cagney/2003-10-17: Just like the old query and memory xfer    methods, these new methods perform partial transfers.  The only    difference is that these new methods thought to include "partial"    in the name.  The old code's failure to do this lead to much    confusion and duplication of effort as each target object attempted    to locally take responsibility for something it didn't have to    worry about.     NOTE: cagney/2003-10-17: With a TARGET_OBJECT_KOD object, for    backward compatibility with the "target_query" method that this    replaced, when OFFSET and LEN are both zero, return the "minimum"    buffer size.  See "remote.c" for further information.  */
end_comment

begin_enum
enum|enum
name|target_object
block|{
comment|/* Kernel Object Display transfer.  See "kod.c" and "remote.c".  */
name|TARGET_OBJECT_KOD
block|,
comment|/* AVR target specific transfer.  See "avr-tdep.c" and "remote.c".  */
name|TARGET_OBJECT_AVR
block|,
comment|/* Transfer up-to LEN bytes of memory starting at OFFSET.  */
name|TARGET_OBJECT_MEMORY
block|,
comment|/* Kernel Unwind Table.  See "ia64-tdep.c".  */
name|TARGET_OBJECT_UNWIND_TABLE
block|,
comment|/* Transfer auxilliary vector.  */
name|TARGET_OBJECT_AUXV
block|,
comment|/* StackGhost cookie.  See "sparc-tdep.c".  */
name|TARGET_OBJECT_WCOOKIE
block|,
comment|/* Dirty registers. See "ia64-tdep.c".  */
name|TARGET_OBJECT_DIRTY
comment|/* Possible future objects: TARGET_OBJECT_FILE, TARGET_OBJECT_PROC, ... */
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|LONGEST
name|target_read_partial
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|enum
name|target_object
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|target_write_partial
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|enum
name|target_object
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wrappers to perform the full transfer.  */
end_comment

begin_function_decl
specifier|extern
name|LONGEST
name|target_read
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|enum
name|target_object
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|target_write
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|enum
name|target_object
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wrappers to target read/write that perform memory transfers.  They    throw an error if the memory transfer fails.     NOTE: cagney/2003-10-23: The naming schema is lifted from    "frame.h".  The parameter order is lifted from get_frame_memory,    which in turn lifted it from read_memory.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|get_target_memory
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ULONGEST
name|get_target_memory_unsigned
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* If certain kinds of activity happen, target_wait should perform    callbacks.  */
end_comment

begin_comment
comment|/* Right now we just call (*TARGET_ACTIVITY_FUNCTION) if I/O is possible    on TARGET_ACTIVITY_FD.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_activity_fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns zero to leave the inferior alone, one to interrupt it.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|target_activity_function
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_struct_decl
struct_decl|struct
name|thread_info
struct_decl|;
end_struct_decl

begin_comment
comment|/* fwd decl for parameter list below: */
end_comment

begin_struct
struct|struct
name|target_ops
block|{
name|struct
name|target_ops
modifier|*
name|beneath
decl_stmt|;
comment|/* To the target under this one.  */
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
comment|/* Documentation.  Does not include trailing 				   newline, and starts with a one-line descrip- 				   tion (probably similar to to_longname).  */
comment|/* Per-target scratch pad.  */
name|void
modifier|*
name|to_data
decl_stmt|;
comment|/* The open routine takes the rest of the parameters from the        command, and (if successful) pushes a new target onto the        stack.  Targets should supply this routine, if only to provide        an error message.  */
name|void
function_decl|(
modifier|*
name|to_open
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Old targets with a static target vector provide "to_close".        New re-entrant targets provide "to_xclose" and that is expected        to xfree everything (including the "struct target_ops").  */
name|void
function_decl|(
modifier|*
name|to_xclose
function_decl|)
parameter_list|(
name|struct
name|target_ops
modifier|*
name|targ
parameter_list|,
name|int
name|quitting
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_close
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_attach
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_post_attach
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_detach
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_disconnect
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_resume
function_decl|)
parameter_list|(
name|ptid_t
parameter_list|,
name|int
parameter_list|,
name|enum
name|target_signal
parameter_list|)
function_decl|;
name|ptid_t
function_decl|(
modifier|*
name|to_wait
function_decl|)
parameter_list|(
name|ptid_t
parameter_list|,
name|struct
name|target_waitstatus
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_post_wait
function_decl|)
parameter_list|(
name|ptid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_fetch_registers
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_store_registers
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_prepare_to_store
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Transfer LEN bytes of memory between GDB address MYADDR and        target address MEMADDR.  If WRITE, transfer them to the target, else        transfer them from the target.  TARGET is the target from which we        get this function.         Return value, N, is one of the following:         0 means that we can't handle this.  If errno has been set, it is the        error which prevented us from doing it (FIXME: What about bfd_error?).         positive (call it N) means that we have transferred N bytes        starting at MEMADDR.  We might be able to handle more bytes        beyond this length, but no promises.         negative (call its absolute value N) means that we cannot        transfer right at MEMADDR, but we could transfer at least        something at MEMADDR + N.  */
name|int
function_decl|(
modifier|*
name|to_xfer_memory
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
parameter_list|,
name|int
name|write
parameter_list|,
name|struct
name|mem_attrib
modifier|*
name|attrib
parameter_list|,
name|struct
name|target_ops
modifier|*
name|target
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_files_info
function_decl|)
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_insert_breakpoint
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_remove_breakpoint
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_can_use_hw_breakpoint
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_insert_hw_breakpoint
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_remove_hw_breakpoint
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_remove_watchpoint
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_insert_watchpoint
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_stopped_by_watchpoint
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|to_have_continuable_watchpoint
decl_stmt|;
name|CORE_ADDR
function_decl|(
modifier|*
name|to_stopped_data_address
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_region_size_ok_for_hw_watchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_terminal_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_terminal_inferior
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_terminal_ours_for_output
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_terminal_ours
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_terminal_save_ours
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_terminal_info
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_kill
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_load
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_lookup_symbol
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_create_inferior
function_decl|)
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
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_post_startup_inferior
function_decl|)
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_acknowledge_created_inferior
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_insert_fork_catchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_remove_fork_catchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_insert_vfork_catchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_remove_vfork_catchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_follow_fork
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_insert_exec_catchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_remove_exec_catchpoint
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_reported_exec_events_per_exec_call
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_has_exited
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_mourn_inferior
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_can_run
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_notice_signals
function_decl|)
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_thread_alive
function_decl|)
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_find_new_threads
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|to_pid_to_str
function_decl|)
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|to_extra_thread_info
function_decl|)
parameter_list|(
name|struct
name|thread_info
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_stop
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_rcmd
function_decl|)
parameter_list|(
name|char
modifier|*
name|command
parameter_list|,
name|struct
name|ui_file
modifier|*
name|output
parameter_list|)
function_decl|;
name|struct
name|symtab_and_line
modifier|*
function_decl|(
modifier|*
name|to_enable_exception_callback
function_decl|)
parameter_list|(
name|enum
name|exception_event_kind
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|struct
name|exception_event_record
modifier|*
function_decl|(
modifier|*
name|to_get_current_exception_event
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|to_pid_to_exec_file
function_decl|)
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
name|enum
name|strata
name|to_stratum
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
name|int
name|to_has_thread_control
decl_stmt|;
comment|/* control thread execution */
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
comment|/* ASYNC target controls */
name|int
function_decl|(
modifier|*
name|to_can_async_p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_is_async_p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|to_async
function_decl|)
parameter_list|(
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|enum
name|inferior_event_type
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|int
name|to_async_mask_value
decl_stmt|;
name|int
function_decl|(
modifier|*
name|to_find_memory_regions
function_decl|)
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|to_make_corefile_notes
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/* Return the thread-local address at OFFSET in the        thread-local storage for the thread PTID and the shared library        or executable file given by OBJFILE.  If that block of        thread-local storage hasn't been allocated yet, this function        may return an error.  */
name|CORE_ADDR
function_decl|(
modifier|*
name|to_get_thread_local_address
function_decl|)
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|,
name|CORE_ADDR
name|offset
parameter_list|)
function_decl|;
comment|/* Perform partial transfers on OBJECT.  See target_read_partial        and target_write_partial for details of each variant.  One, and        only one, of readbuf or writebuf must be non-NULL.  */
name|LONGEST
function_decl|(
modifier|*
name|to_xfer_partial
function_decl|)
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|enum
name|target_object
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
name|int
name|to_magic
decl_stmt|;
comment|/* Need sub-structure for target machine related rather than comm related?      */
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
value|(current_target.to_shortname)
end_define

begin_define
define|#
directive|define
name|target_longname
value|(current_target.to_longname)
end_define

begin_comment
comment|/* Does whatever cleanup is required for a target that we are no    longer going to be calling.  QUITTING indicates that GDB is exiting    and should not get hung on an error (otherwise it is important to    perform clean termination, even if it takes a while).  This routine    is automatically always called when popping the target off the    target stack (to_beneath is undefined).  Closing file descriptors    and freeing all memory allocated memory are typical things it    should do.  */
end_comment

begin_function_decl
name|void
name|target_close
parameter_list|(
name|struct
name|target_ops
modifier|*
name|targ
parameter_list|,
name|int
name|quitting
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Attaches to a process on the target side.  Arguments are as passed    to the `attach' command by the user.  This routine can be called    when the target is not on the target-stack, if the target_can_run    routine returns 1; in that case, it must push itself onto the stack.    Upon exit, the target should be ready for normal operations, and    should be ready to deliver the status of the process immediately    (without waiting) to an upcoming target_wait call.  */
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
value|(*current_target.to_attach) (args, from_tty)
end_define

begin_comment
comment|/* The target_attach operation places a process under debugger control,    and stops the process.     This operation provides a target-specific hook that allows the    necessary bookkeeping to be performed after an attach completes.  */
end_comment

begin_define
define|#
directive|define
name|target_post_attach
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_post_attach) (pid)
end_define

begin_comment
comment|/* Takes a program previously attached to and detaches it.    The program may resume execution (some targets do, some don't) and will    no longer stop on signals, etc.  We better not have left any breakpoints    in the program or it'll die when it hits one.  ARGS is arguments    typed by the user (e.g. a signal to send the process).  FROM_TTY    says whether to be verbose or not.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|target_detach
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disconnect from the current target without resuming it (leaving it    waiting for a debugger).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|target_disconnect
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Resume execution of the target process PTID.  STEP says whether to    single-step or to run free; SIGGNAL is the signal to be given to    the target, or TARGET_SIGNAL_0 for no signal.  The caller may not    pass TARGET_SIGNAL_DEFAULT.  */
end_comment

begin_define
define|#
directive|define
name|target_resume
parameter_list|(
name|ptid
parameter_list|,
name|step
parameter_list|,
name|siggnal
parameter_list|)
define|\
value|do {									\     dcache_invalidate(target_dcache);					\     (*current_target.to_resume) (ptid, step, siggnal);			\   } while (0)
end_define

begin_comment
comment|/* Wait for process pid to do something.  PTID = -1 to wait for any    pid to do something.  Return pid of child, or -1 in case of error;    store status through argument pointer STATUS.  Note that it is    _NOT_ OK to throw_exception() out of target_wait() without popping    the debugging target from the stack; GDB isn't prepared to get back    to the prompt with a debugging target but without the frame cache,    stop_pc, etc., set up.  */
end_comment

begin_define
define|#
directive|define
name|target_wait
parameter_list|(
name|ptid
parameter_list|,
name|status
parameter_list|)
define|\
value|(*current_target.to_wait) (ptid, status)
end_define

begin_comment
comment|/* The target_wait operation waits for a process event to occur, and    thereby stop the process.     On some targets, certain events may happen in sequences.  gdb's    correct response to any single event of such a sequence may require    knowledge of what earlier events in the sequence have been seen.     This operation provides a target-specific hook that allows the    necessary bookkeeping to be performed to track such sequences.  */
end_comment

begin_define
define|#
directive|define
name|target_post_wait
parameter_list|(
name|ptid
parameter_list|,
name|status
parameter_list|)
define|\
value|(*current_target.to_post_wait) (ptid, status)
end_define

begin_comment
comment|/* Fetch at least register REGNO, or all regs if regno == -1.  No result.  */
end_comment

begin_define
define|#
directive|define
name|target_fetch_registers
parameter_list|(
name|regno
parameter_list|)
define|\
value|(*current_target.to_fetch_registers) (regno)
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
value|(*current_target.to_store_registers) (regs)
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
value|(*current_target.to_prepare_to_store) ()
end_define

begin_decl_stmt
specifier|extern
name|DCACHE
modifier|*
name|target_dcache
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|do_xfer_memory
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
parameter_list|,
name|int
name|write
parameter_list|,
name|struct
name|mem_attrib
modifier|*
name|attrib
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|target_read_string
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|target_read_memory
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
specifier|extern
name|int
name|target_write_memory
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
specifier|extern
name|int
name|xfer_memory
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mem_attrib
modifier|*
parameter_list|,
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_xfer_memory
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mem_attrib
modifier|*
parameter_list|,
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make a single attempt at transfering LEN bytes.  On a successful    transfer, the number of bytes actually transfered is returned and    ERR is set to 0.  When a transfer fails, -1 is returned (the number    of bytes actually transfered is not defined) and ERR is set to a    non-zero error indication.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|target_read_memory_partial
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|target_write_memory_partial
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|child_pid_to_exec_file
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|child_core_file_to_sym_file
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CHILD_POST_ATTACH
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|child_post_attach
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|child_post_wait
parameter_list|(
name|ptid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|child_post_startup_inferior
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|child_acknowledge_created_inferior
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_insert_fork_catchpoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_remove_fork_catchpoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_insert_vfork_catchpoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_remove_vfork_catchpoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|child_acknowledge_created_inferior
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_follow_fork
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_insert_exec_catchpoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_remove_exec_catchpoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_reported_exec_events_per_exec_call
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_has_exited
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|child_thread_alive
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From infrun.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|inferior_has_forked
parameter_list|(
name|int
name|pid
parameter_list|,
name|int
modifier|*
name|child_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inferior_has_vforked
parameter_list|(
name|int
name|pid
parameter_list|,
name|int
modifier|*
name|child_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|inferior_has_execd
parameter_list|(
name|int
name|pid
parameter_list|,
name|char
modifier|*
modifier|*
name|execd_pathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From exec.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_section_info
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a line about the current target.  */
end_comment

begin_define
define|#
directive|define
name|target_files_info
parameter_list|()
define|\
value|(*current_target.to_files_info) (&current_target)
end_define

begin_comment
comment|/* Insert a breakpoint at address ADDR in the target machine.  SAVE is    a pointer to memory allocated for saving the target contents.  It    is guaranteed by the caller to be long enough to save the number of    breakpoint bytes indicated by BREAKPOINT_FROM_PC.  Result is 0 for    success, or an errno value.  */
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
value|(*current_target.to_insert_breakpoint) (addr, save)
end_define

begin_comment
comment|/* Remove a breakpoint at address ADDR in the target machine.    SAVE is a pointer to the same save area    that was previously passed to target_insert_breakpoint.    Result is 0 for success, or an errno value.  */
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
value|(*current_target.to_remove_breakpoint) (addr, save)
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
value|(*current_target.to_terminal_init) ()
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
value|(*current_target.to_terminal_inferior) ()
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
value|(*current_target.to_terminal_ours_for_output) ()
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
value|(*current_target.to_terminal_ours) ()
end_define

begin_comment
comment|/* Save our terminal settings.    This is called from TUI after entering or leaving the curses    mode.  Since curses modifies our terminal this call is here    to take this change into account.  */
end_comment

begin_define
define|#
directive|define
name|target_terminal_save_ours
parameter_list|()
define|\
value|(*current_target.to_terminal_save_ours) ()
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
value|(*current_target.to_terminal_info) (arg, from_tty)
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
value|(*current_target.to_kill) ()
end_define

begin_comment
comment|/* Load an executable file into the target process.  This is expected    to not only bring new code into the target process, but also to    update GDB's symbol tables to match.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|target_load
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Look up a symbol in the target's symbol table.  NAME is the symbol    name.  ADDRP is a CORE_ADDR * pointing to where the value of the    symbol should be returned.  The result is 0 if successful, nonzero    if the symbol does not exist in the target environment.  This    function should not call error() if communication with the target    is interrupted, since it is called from symbol reading, but should    return nonzero, possibly doing a complain().  */
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
value|(*current_target.to_lookup_symbol) (name, addrp)
end_define

begin_comment
comment|/* Start an inferior process and set inferior_ptid to its pid.    EXEC_FILE is the file to run.    ALLARGS is a string containing the arguments to the program.    ENV is the environment vector to pass.  Errors reported with error().    On VxWorks and various standalone systems, we ignore exec_file.  */
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
value|(*current_target.to_create_inferior) (exec_file, args, env)
end_define

begin_comment
comment|/* Some targets (such as ttrace-based HPUX) don't allow us to request    notification of inferior events such as fork and vork immediately    after the inferior is created.  (This because of how gdb gets an    inferior created via invoking a shell to do it.  In such a scenario,    if the shell init file has commands in it, the shell will fork and    exec for each of those commands, and we will see each such fork    event.  Very bad.)     Such targets will supply an appropriate definition for this function.  */
end_comment

begin_define
define|#
directive|define
name|target_post_startup_inferior
parameter_list|(
name|ptid
parameter_list|)
define|\
value|(*current_target.to_post_startup_inferior) (ptid)
end_define

begin_comment
comment|/* On some targets, the sequence of starting up an inferior requires    some synchronization between gdb and the new inferior process, PID.  */
end_comment

begin_define
define|#
directive|define
name|target_acknowledge_created_inferior
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_acknowledge_created_inferior) (pid)
end_define

begin_comment
comment|/* On some targets, we can catch an inferior fork or vfork event when    it occurs.  These functions insert/remove an already-created    catchpoint for such events.  */
end_comment

begin_define
define|#
directive|define
name|target_insert_fork_catchpoint
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_insert_fork_catchpoint) (pid)
end_define

begin_define
define|#
directive|define
name|target_remove_fork_catchpoint
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_remove_fork_catchpoint) (pid)
end_define

begin_define
define|#
directive|define
name|target_insert_vfork_catchpoint
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_insert_vfork_catchpoint) (pid)
end_define

begin_define
define|#
directive|define
name|target_remove_vfork_catchpoint
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_remove_vfork_catchpoint) (pid)
end_define

begin_comment
comment|/* If the inferior forks or vforks, this function will be called at    the next resume in order to perform any bookkeeping and fiddling    necessary to continue debugging either the parent or child, as    requested, and releasing the other.  Information about the fork    or vfork event is available via get_last_target_status ().    This function returns 1 if the inferior should not be resumed    (i.e. there is another event pending).  */
end_comment

begin_define
define|#
directive|define
name|target_follow_fork
parameter_list|(
name|follow_child
parameter_list|)
define|\
value|(*current_target.to_follow_fork) (follow_child)
end_define

begin_comment
comment|/* On some targets, we can catch an inferior exec event when it    occurs.  These functions insert/remove an already-created    catchpoint for such events.  */
end_comment

begin_define
define|#
directive|define
name|target_insert_exec_catchpoint
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_insert_exec_catchpoint) (pid)
end_define

begin_define
define|#
directive|define
name|target_remove_exec_catchpoint
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_remove_exec_catchpoint) (pid)
end_define

begin_comment
comment|/* Returns the number of exec events that are reported when a process    invokes a flavor of the exec() system call on this target, if exec    events are being reported.  */
end_comment

begin_define
define|#
directive|define
name|target_reported_exec_events_per_exec_call
parameter_list|()
define|\
value|(*current_target.to_reported_exec_events_per_exec_call) ()
end_define

begin_comment
comment|/* Returns TRUE if PID has exited.  And, also sets EXIT_STATUS to the    exit code of PID, if any.  */
end_comment

begin_define
define|#
directive|define
name|target_has_exited
parameter_list|(
name|pid
parameter_list|,
name|wait_status
parameter_list|,
name|exit_status
parameter_list|)
define|\
value|(*current_target.to_has_exited) (pid,wait_status,exit_status)
end_define

begin_comment
comment|/* The debugger has completed a blocking wait() call.  There is now    some process event that must be processed.  This function should    be defined by those targets that require the debugger to perform    cleanup or internal state changes in response to the process event.  */
end_comment

begin_comment
comment|/* The inferior process has died.  Do what is right.  */
end_comment

begin_define
define|#
directive|define
name|target_mourn_inferior
parameter_list|()
define|\
value|(*current_target.to_mourn_inferior) ()
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
name|ptid
parameter_list|)
define|\
value|(*current_target.to_notice_signals) (ptid)
end_define

begin_comment
comment|/* Check to see if a thread is still alive.  */
end_comment

begin_define
define|#
directive|define
name|target_thread_alive
parameter_list|(
name|ptid
parameter_list|)
define|\
value|(*current_target.to_thread_alive) (ptid)
end_define

begin_comment
comment|/* Query for new threads and add them to the thread list.  */
end_comment

begin_define
define|#
directive|define
name|target_find_new_threads
parameter_list|()
define|\
value|(*current_target.to_find_new_threads) ();
end_define

begin_comment
unit|\
comment|/* Make target stop in a continuable fashion.  (For instance, under    Unix, this should act like SIGSTOP).  This function is normally    used by GUIs to implement a stop button.  */
end_comment

begin_define
define|#
directive|define
name|target_stop
value|current_target.to_stop
end_define

begin_comment
comment|/* Send the specified COMMAND to the target's monitor    (shell,interpreter) for execution.  The result of the query is    placed in OUTBUF.  */
end_comment

begin_define
define|#
directive|define
name|target_rcmd
parameter_list|(
name|command
parameter_list|,
name|outbuf
parameter_list|)
define|\
value|(*current_target.to_rcmd) (command, outbuf)
end_define

begin_comment
comment|/* Get the symbol information for a breakpointable routine called when    an exception event occurs.    Intended mainly for C++, and for those    platforms/implementations where such a callback mechanism is available,    e.g. HP-UX with ANSI C++ (aCC).  Some compilers (e.g. g++) support    different mechanisms for debugging exceptions.  */
end_comment

begin_define
define|#
directive|define
name|target_enable_exception_callback
parameter_list|(
name|kind
parameter_list|,
name|enable
parameter_list|)
define|\
value|(*current_target.to_enable_exception_callback) (kind, enable)
end_define

begin_comment
comment|/* Get the current exception event kind -- throw or catch, etc.  */
end_comment

begin_define
define|#
directive|define
name|target_get_current_exception_event
parameter_list|()
define|\
value|(*current_target.to_get_current_exception_event) ()
end_define

begin_comment
comment|/* Does the target include all of memory, or only part of it?  This    determines whether we look up the target chain for other parts of    memory if this target can't satisfy a request.  */
end_comment

begin_define
define|#
directive|define
name|target_has_all_memory
define|\
value|(current_target.to_has_all_memory)
end_define

begin_comment
comment|/* Does the target include memory?  (Dummy targets don't.)  */
end_comment

begin_define
define|#
directive|define
name|target_has_memory
define|\
value|(current_target.to_has_memory)
end_define

begin_comment
comment|/* Does the target have a stack?  (Exec files don't, VxWorks doesn't, until    we start a process.)  */
end_comment

begin_define
define|#
directive|define
name|target_has_stack
define|\
value|(current_target.to_has_stack)
end_define

begin_comment
comment|/* Does the target have registers?  (Exec files don't.)  */
end_comment

begin_define
define|#
directive|define
name|target_has_registers
define|\
value|(current_target.to_has_registers)
end_define

begin_comment
comment|/* Does the target have execution?  Can we make it jump (through    hoops), or pop its stack a few times?  FIXME: If this is to work that    way, it needs to check whether an inferior actually exists.    remote-udi.c and probably other targets can be the current target    when the inferior doesn't actually exist at the moment.  Right now    this just tells us whether this target is *capable* of execution.  */
end_comment

begin_define
define|#
directive|define
name|target_has_execution
define|\
value|(current_target.to_has_execution)
end_define

begin_comment
comment|/* Can the target support the debugger control of thread execution?    a) Can it lock the thread scheduler?    b) Can it switch the currently running thread?  */
end_comment

begin_define
define|#
directive|define
name|target_can_lock_scheduler
define|\
value|(current_target.to_has_thread_control& tc_schedlock)
end_define

begin_define
define|#
directive|define
name|target_can_switch_threads
define|\
value|(current_target.to_has_thread_control& tc_switch)
end_define

begin_comment
comment|/* Can the target support asynchronous execution? */
end_comment

begin_define
define|#
directive|define
name|target_can_async_p
parameter_list|()
value|(current_target.to_can_async_p ())
end_define

begin_comment
comment|/* Is the target in asynchronous execution mode? */
end_comment

begin_define
define|#
directive|define
name|target_is_async_p
parameter_list|()
value|(current_target.to_is_async_p())
end_define

begin_comment
comment|/* Put the target in async mode with the specified callback function. */
end_comment

begin_define
define|#
directive|define
name|target_async
parameter_list|(
name|CALLBACK
parameter_list|,
name|CONTEXT
parameter_list|)
define|\
value|(current_target.to_async((CALLBACK), (CONTEXT)))
end_define

begin_comment
comment|/* This is to be used ONLY within call_function_by_hand(). It provides    a workaround, to have inferior function calls done in sychronous    mode, even though the target is asynchronous. After    target_async_mask(0) is called, calls to target_can_async_p() will    return FALSE , so that target_resume() will not try to start the    target asynchronously. After the inferior stops, we IMMEDIATELY    restore the previous nature of the target, by calling    target_async_mask(1). After that, target_can_async_p() will return    TRUE. ANY OTHER USE OF THIS FEATURE IS DEPRECATED.     FIXME ezannoni 1999-12-13: we won't need this once we move    the turning async on and off to the single execution commands,    from where it is done currently, in remote_resume().  */
end_comment

begin_define
define|#
directive|define
name|target_async_mask_value
define|\
value|(current_target.to_async_mask_value)
end_define

begin_function_decl
specifier|extern
name|int
name|target_async_mask
parameter_list|(
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|target_link
parameter_list|(
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts a process id to a string.  Usually, the string just contains    `process xyz', but on some systems it may contain    `process xyz thread abc'.  */
end_comment

begin_undef
undef|#
directive|undef
name|target_pid_to_str
end_undef

begin_define
define|#
directive|define
name|target_pid_to_str
parameter_list|(
name|PID
parameter_list|)
value|current_target.to_pid_to_str (PID)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|target_tid_to_str
end_ifndef

begin_define
define|#
directive|define
name|target_tid_to_str
parameter_list|(
name|PID
parameter_list|)
define|\
value|target_pid_to_str (PID)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|normal_pid_to_str
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return a short string describing extra information about PID,    e.g. "sleeping", "runnable", "running on LWP 3".  Null return value    is okay.  */
end_comment

begin_define
define|#
directive|define
name|target_extra_thread_info
parameter_list|(
name|TP
parameter_list|)
define|\
value|(current_target.to_extra_thread_info (TP))
end_define

begin_comment
comment|/*  * New Objfile Event Hook:  *  * Sometimes a GDB component wants to get notified whenever a new  * objfile is loaded.  Mainly this is used by thread-debugging  * implementations that need to know when symbols for the target  * thread implemenation are available.  *  * The old way of doing this is to define a macro 'target_new_objfile'  * that points to the function that you want to be called on every  * objfile/shlib load.  *  * The new way is to grab the function pointer, 'target_new_objfile_hook',  * and point it to the function that you want to be called on every  * objfile/shlib load.  *  * If multiple clients are willing to be cooperative, they can each  * save a pointer to the previous value of target_new_objfile_hook  * before modifying it, and arrange for their function to call the  * previous function in the chain.  In that way, multiple clients  * can receive this notification (something like with signal handlers).  */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|target_new_objfile_hook
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|target_pid_or_tid_to_str
end_ifndef

begin_define
define|#
directive|define
name|target_pid_or_tid_to_str
parameter_list|(
name|ID
parameter_list|)
define|\
value|target_pid_to_str (ID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Attempts to find the pathname of the executable file    that was run to create a specified process.     The process PID must be stopped when this operation is used.     If the executable file cannot be determined, NULL is returned.     Else, a pointer to a character string containing the pathname    is returned.  This string should be copied into a buffer by    the client if the string will not be immediately used, or if    it must persist.  */
end_comment

begin_define
define|#
directive|define
name|target_pid_to_exec_file
parameter_list|(
name|pid
parameter_list|)
define|\
value|(current_target.to_pid_to_exec_file) (pid)
end_define

begin_comment
comment|/*  * Iterator function for target memory regions.  * Calls a callback function once for each memory region 'mapped'  * in the child process.  Defined as a simple macro rather than  * as a function macro so that it can be tested for nullity.  */
end_comment

begin_define
define|#
directive|define
name|target_find_memory_regions
parameter_list|(
name|FUNC
parameter_list|,
name|DATA
parameter_list|)
define|\
value|(current_target.to_find_memory_regions) (FUNC, DATA)
end_define

begin_comment
comment|/*  * Compose corefile .note section.  */
end_comment

begin_define
define|#
directive|define
name|target_make_corefile_notes
parameter_list|(
name|BFD
parameter_list|,
name|SIZE_P
parameter_list|)
define|\
value|(current_target.to_make_corefile_notes) (BFD, SIZE_P)
end_define

begin_comment
comment|/* Thread-local values.  */
end_comment

begin_define
define|#
directive|define
name|target_get_thread_local_address
define|\
value|(current_target.to_get_thread_local_address)
end_define

begin_define
define|#
directive|define
name|target_get_thread_local_address_p
parameter_list|()
define|\
value|(target_get_thread_local_address != NULL)
end_define

begin_comment
comment|/* Hook to call target dependent code just after inferior target process has    started.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CREATE_INFERIOR_HOOK
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CREATE_INFERIOR_HOOK
parameter_list|(
name|PID
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hardware watchpoint interfaces.  */
end_comment

begin_comment
comment|/* Returns non-zero if we were stopped by a hardware watchpoint (memory read or    write).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STOPPED_BY_WATCHPOINT
end_ifndef

begin_define
define|#
directive|define
name|STOPPED_BY_WATCHPOINT
parameter_list|(
name|w
parameter_list|)
define|\
value|(*current_target.to_stopped_by_watchpoint) ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Non-zero if we have continuable watchpoints  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CONTINUABLE_WATCHPOINT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
define|\
value|(current_target.to_have_continuable_watchpoint)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP-UX supplies these operations, which respectively disable and enable    the memory page-protections that are used to implement hardware watchpoints    on that platform.  See wait_for_inferior's use of these.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_DISABLE_HW_WATCHPOINTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DISABLE_HW_WATCHPOINTS
parameter_list|(
name|pid
parameter_list|)
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
name|TARGET_ENABLE_HW_WATCHPOINTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_ENABLE_HW_WATCHPOINTS
parameter_list|(
name|pid
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide defaults for hardware watchpoint functions.  */
end_comment

begin_comment
comment|/* If the *_hw_beakpoint functions have not been defined    elsewhere use the definitions in the target vector.  */
end_comment

begin_comment
comment|/* Returns non-zero if we can set a hardware watchpoint of type TYPE.  TYPE is    one of bp_hardware_watchpoint, bp_read_watchpoint, bp_write_watchpoint, or    bp_hardware_breakpoint.  CNT is the number of such watchpoints used so far    (including this one?).  OTHERTYPE is who knows what...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CAN_USE_HARDWARE_WATCHPOINT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CAN_USE_HARDWARE_WATCHPOINT
parameter_list|(
name|TYPE
parameter_list|,
name|CNT
parameter_list|,
name|OTHERTYPE
parameter_list|)
define|\
value|(*current_target.to_can_use_hw_breakpoint) (TYPE, CNT, OTHERTYPE);
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
name|TARGET_REGION_SIZE_OK_FOR_HW_WATCHPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_REGION_SIZE_OK_FOR_HW_WATCHPOINT
parameter_list|(
name|byte_count
parameter_list|)
define|\
value|(*current_target.to_region_size_ok_for_hw_watchpoint) (byte_count)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set/clear a hardware watchpoint starting at ADDR, for LEN bytes.  TYPE is 0    for write, 1 for read, and 2 for read/write accesses.  Returns 0 for    success, non-zero for failure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|target_insert_watchpoint
end_ifndef

begin_define
define|#
directive|define
name|target_insert_watchpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
define|\
value|(*current_target.to_insert_watchpoint) (addr, len, type)
end_define

begin_define
define|#
directive|define
name|target_remove_watchpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
define|\
value|(*current_target.to_remove_watchpoint) (addr, len, type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|target_insert_hw_breakpoint
end_ifndef

begin_define
define|#
directive|define
name|target_insert_hw_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|save
parameter_list|)
define|\
value|(*current_target.to_insert_hw_breakpoint) (addr, save)
end_define

begin_define
define|#
directive|define
name|target_remove_hw_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|save
parameter_list|)
define|\
value|(*current_target.to_remove_hw_breakpoint) (addr, save)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|target_stopped_data_address
end_ifndef

begin_define
define|#
directive|define
name|target_stopped_data_address
parameter_list|()
define|\
value|(*current_target.to_stopped_data_address) ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sometimes gdb may pick up what appears to be a valid target address    from a minimal symbol, but the value really means, essentially,    "This is an index into a table which is populated when the inferior    is run.  Therefore, do not attempt to use this as a PC."  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_REQUIRES_RUN_BEFORE_USE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PC_REQUIRES_RUN_BEFORE_USE
parameter_list|(
name|pc
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This will only be defined by a target that supports catching vfork events,    such as HP-UX.     On some targets (such as HP-UX 10.20 and earlier), resuming a newly vforked    child process after it has exec'd, causes the parent process to resume as    well.  To prevent the parent from running spontaneously, such targets should    define this to a function that prevents that from happening.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ENSURE_VFORKING_PARENT_REMAINS_STOPPED
argument_list|)
end_if

begin_define
define|#
directive|define
name|ENSURE_VFORKING_PARENT_REMAINS_STOPPED
parameter_list|(
name|PID
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This will only be defined by a target that supports catching vfork events,    such as HP-UX.     On some targets (such as HP-UX 10.20 and earlier), a newly vforked child    process must be resumed when it delivers its exec event, before the parent    vfork event will be delivered to us.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RESUME_EXECD_VFORKING_CHILD_TO_GET_PARENT_VFORK
argument_list|)
end_if

begin_define
define|#
directive|define
name|RESUME_EXECD_VFORKING_CHILD_TO_GET_PARENT_VFORK
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Routines for maintenance of the target structures...     add_target:   Add a target to the list of all possible targets.     push_target:  Make this target the top of the stack of currently used    targets, within its particular stratum of the stack.  Result    is 0 if now atop the stack, nonzero if not on top (maybe    should warn user).     unpush_target: Remove this from the stack of currently used targets,    no matter where it is on the list.  Returns 0 if no    change, 1 if removed from stack.     pop_target:   Remove the top thing on the stack of current targets.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_target
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|push_target
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unpush_target
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|target_preopen
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_target
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|struct
name|bfd_section
modifier|*
name|the_bfd_section
decl_stmt|;
name|bfd
modifier|*
name|bfd
decl_stmt|;
comment|/* BFD file pointer */
block|}
struct|;
end_struct

begin_comment
comment|/* Return the "section" containing the specified address.  */
end_comment

begin_function_decl
name|struct
name|section_table
modifier|*
name|target_section_by_addr
parameter_list|(
name|struct
name|target_ops
modifier|*
name|target
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From mem-break.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|memory_remove_breakpoint
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
name|int
name|memory_insert_breakpoint
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
name|int
name|default_memory_remove_breakpoint
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
name|int
name|default_memory_insert_breakpoint
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From target.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|initialize_targets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|noprocess
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_default_attach
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
name|find_default_create_inferior
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|target_ops
modifier|*
name|find_run_target
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|target_ops
modifier|*
name|find_core_target
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|target_ops
modifier|*
name|find_target_beneath
parameter_list|(
name|struct
name|target_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|target_resize_to_sections
parameter_list|(
name|struct
name|target_ops
modifier|*
name|target
parameter_list|,
name|int
name|num_added
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_target_sections
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Stuff that should be shared among the various remote targets.  */
end_comment

begin_comment
comment|/* Debugging level.  0 is off, and non-zero values mean to print some debug    information (higher values, more information).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|remote_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Speed in bits per second, or -1 which means don't mess with the speed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|baud_rate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Timeout limit for response from target. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|remote_timeout
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Functions for helping to write a native target.  */
end_comment

begin_comment
comment|/* This is for native targets which use a unix/POSIX-style waitstatus.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|store_waitstatus
parameter_list|(
name|struct
name|target_waitstatus
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Predicate to target_signal_to_host(). Return non-zero if the enum    targ_signal SIGNO has an equivalent ``host'' representation.  */
end_comment

begin_comment
comment|/* FIXME: cagney/1999-11-22: The name below was chosen in preference    to the shorter target_signal_p() because it is far less ambigious.    In this context ``target_signal'' refers to GDB's internal    representation of the target's set of signals while ``host signal''    refers to the target operating system's signal.  Confused?  */
end_comment

begin_function_decl
specifier|extern
name|int
name|target_signal_to_host_p
parameter_list|(
name|enum
name|target_signal
name|signo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert between host signal numbers and enum target_signal's.    target_signal_to_host() returns 0 and prints a warning() on GDB's    console if SIGNO has no equivalent host representation.  */
end_comment

begin_comment
comment|/* FIXME: cagney/1999-11-22: Here ``host'' is used incorrectly, it is    refering to the target operating system's signal numbering.    Similarly, ``enum target_signal'' is named incorrectly, ``enum    gdb_signal'' would probably be better as it is refering to GDB's    internal representation of a target operating system's signal.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|target_signal
name|target_signal_from_host
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|target_signal_to_host
parameter_list|(
name|enum
name|target_signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert from a number used in a GDB command to an enum target_signal.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|target_signal
name|target_signal_from_command
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Any target can call this to switch to remote protocol (in remote.c). */
end_comment

begin_function_decl
specifier|extern
name|void
name|push_remote_target
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Imported from machine dependent code */
end_comment

begin_comment
comment|/* Blank target vector entries are initialized to target_ignore. */
end_comment

begin_function_decl
name|void
name|target_ignore
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TARGET_H) */
end_comment

end_unit

