begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface between GDB and target environments, including files and processes    Copyright 1990, 91, 92, 93, 94, 1999 Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by John Gilmore.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"symtab.h"
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
name|kcore_stratum
block|,
comment|/* Kernel core files */
name|download_stratum
block|,
comment|/* Downloading of remote targets */
name|process_stratum
comment|/* Executing processes */
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
comment|/* Default: can't control thread execution. */
name|tc_schedlock
init|=
literal|1
block|,
comment|/* Can lock the thread scheduler. */
name|tc_switch
init|=
literal|2
comment|/* Can switch the running thread on demand. */
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
comment|/* The program has stopped with a signal.  Which signal is in value.sig.  */
name|TARGET_WAITKIND_STOPPED
block|,
comment|/* The program has terminated with a signal.  Which signal is in      value.sig.  */
name|TARGET_WAITKIND_SIGNALLED
block|,
comment|/* The program is letting us know that it dynamically loaded something      (e.g. it called load(2) on AIX).  */
name|TARGET_WAITKIND_LOADED
block|,
comment|/* The program has forked.  A "related" process' ID is in value.related_pid.      I.e., if the child forks, value.related_pid is the parent's ID.      */
name|TARGET_WAITKIND_FORKED
block|,
comment|/* The program has vforked.  A "related" process's ID is in value.related_pid.      */
name|TARGET_WAITKIND_VFORKED
block|,
comment|/* The program has exec'ed a new executable file.  The new file's pathname      is pointed to by value.execd_pathname.      */
name|TARGET_WAITKIND_EXECD
block|,
comment|/* The program has entered or returned from a system call.  On HP-UX, this      is used in the hardware watchpoint implementation.  The syscall's unique      integer ID number is in value.syscall_id;      */
name|TARGET_WAITKIND_SYSCALL_ENTRY
block|,
name|TARGET_WAITKIND_SYSCALL_RETURN
block|,
comment|/* Nothing happened, but we stopped anyway.  This perhaps should be handled      within target_wait, but I'm not sure target_wait should be resuming the      inferior.  */
name|TARGET_WAITKIND_SPURIOUS
block|}
enum|;
end_enum

begin_comment
comment|/* The numbering of these signals is chosen to match traditional unix    signals (insofar as various unices use the same numbers, anyway).    It is also the numbering of the GDB remote protocol.  Other remote    protocols, if they use a different numbering, should make sure to    translate appropriately.  */
end_comment

begin_comment
comment|/* This is based strongly on Unix/POSIX signals for several reasons:    (1) This set of signals represents a widely-accepted attempt to    represent events of this sort in a portable fashion, (2) we want a    signal to make it from wait to child_wait to the user intact, (3) many    remote protocols use a similar encoding.  However, it is    recognized that this set of signals has limitations (such as not    distinguishing between various kinds of SIGSEGV, or not    distinguishing hitting a breakpoint from finishing a single step).    So in the future we may get around this either by adding additional    signals for breakpoint, single-step, etc., or by adding signal    codes; the latter seems more in the spirit of what BSD, System V,    etc. are doing to address these issues.  */
end_comment

begin_comment
comment|/* For an explanation of what each signal means, see    target_signal_to_string.  */
end_comment

begin_enum
enum|enum
name|target_signal
block|{
comment|/* Used some places (e.g. stop_signal) to record the concept that      there is no signal.  */
name|TARGET_SIGNAL_0
init|=
literal|0
block|,
name|TARGET_SIGNAL_FIRST
init|=
literal|0
block|,
name|TARGET_SIGNAL_HUP
init|=
literal|1
block|,
name|TARGET_SIGNAL_INT
init|=
literal|2
block|,
name|TARGET_SIGNAL_QUIT
init|=
literal|3
block|,
name|TARGET_SIGNAL_ILL
init|=
literal|4
block|,
name|TARGET_SIGNAL_TRAP
init|=
literal|5
block|,
name|TARGET_SIGNAL_ABRT
init|=
literal|6
block|,
name|TARGET_SIGNAL_EMT
init|=
literal|7
block|,
name|TARGET_SIGNAL_FPE
init|=
literal|8
block|,
name|TARGET_SIGNAL_KILL
init|=
literal|9
block|,
name|TARGET_SIGNAL_BUS
init|=
literal|10
block|,
name|TARGET_SIGNAL_SEGV
init|=
literal|11
block|,
name|TARGET_SIGNAL_SYS
init|=
literal|12
block|,
name|TARGET_SIGNAL_PIPE
init|=
literal|13
block|,
name|TARGET_SIGNAL_ALRM
init|=
literal|14
block|,
name|TARGET_SIGNAL_TERM
init|=
literal|15
block|,
name|TARGET_SIGNAL_URG
init|=
literal|16
block|,
name|TARGET_SIGNAL_STOP
init|=
literal|17
block|,
name|TARGET_SIGNAL_TSTP
init|=
literal|18
block|,
name|TARGET_SIGNAL_CONT
init|=
literal|19
block|,
name|TARGET_SIGNAL_CHLD
init|=
literal|20
block|,
name|TARGET_SIGNAL_TTIN
init|=
literal|21
block|,
name|TARGET_SIGNAL_TTOU
init|=
literal|22
block|,
name|TARGET_SIGNAL_IO
init|=
literal|23
block|,
name|TARGET_SIGNAL_XCPU
init|=
literal|24
block|,
name|TARGET_SIGNAL_XFSZ
init|=
literal|25
block|,
name|TARGET_SIGNAL_VTALRM
init|=
literal|26
block|,
name|TARGET_SIGNAL_PROF
init|=
literal|27
block|,
name|TARGET_SIGNAL_WINCH
init|=
literal|28
block|,
name|TARGET_SIGNAL_LOST
init|=
literal|29
block|,
name|TARGET_SIGNAL_USR1
init|=
literal|30
block|,
name|TARGET_SIGNAL_USR2
init|=
literal|31
block|,
name|TARGET_SIGNAL_PWR
init|=
literal|32
block|,
comment|/* Similar to SIGIO.  Perhaps they should have the same number.  */
name|TARGET_SIGNAL_POLL
init|=
literal|33
block|,
name|TARGET_SIGNAL_WIND
init|=
literal|34
block|,
name|TARGET_SIGNAL_PHONE
init|=
literal|35
block|,
name|TARGET_SIGNAL_WAITING
init|=
literal|36
block|,
name|TARGET_SIGNAL_LWP
init|=
literal|37
block|,
name|TARGET_SIGNAL_DANGER
init|=
literal|38
block|,
name|TARGET_SIGNAL_GRANT
init|=
literal|39
block|,
name|TARGET_SIGNAL_RETRACT
init|=
literal|40
block|,
name|TARGET_SIGNAL_MSG
init|=
literal|41
block|,
name|TARGET_SIGNAL_SOUND
init|=
literal|42
block|,
name|TARGET_SIGNAL_SAK
init|=
literal|43
block|,
name|TARGET_SIGNAL_PRIO
init|=
literal|44
block|,
name|TARGET_SIGNAL_REALTIME_33
init|=
literal|45
block|,
name|TARGET_SIGNAL_REALTIME_34
init|=
literal|46
block|,
name|TARGET_SIGNAL_REALTIME_35
init|=
literal|47
block|,
name|TARGET_SIGNAL_REALTIME_36
init|=
literal|48
block|,
name|TARGET_SIGNAL_REALTIME_37
init|=
literal|49
block|,
name|TARGET_SIGNAL_REALTIME_38
init|=
literal|50
block|,
name|TARGET_SIGNAL_REALTIME_39
init|=
literal|51
block|,
name|TARGET_SIGNAL_REALTIME_40
init|=
literal|52
block|,
name|TARGET_SIGNAL_REALTIME_41
init|=
literal|53
block|,
name|TARGET_SIGNAL_REALTIME_42
init|=
literal|54
block|,
name|TARGET_SIGNAL_REALTIME_43
init|=
literal|55
block|,
name|TARGET_SIGNAL_REALTIME_44
init|=
literal|56
block|,
name|TARGET_SIGNAL_REALTIME_45
init|=
literal|57
block|,
name|TARGET_SIGNAL_REALTIME_46
init|=
literal|58
block|,
name|TARGET_SIGNAL_REALTIME_47
init|=
literal|59
block|,
name|TARGET_SIGNAL_REALTIME_48
init|=
literal|60
block|,
name|TARGET_SIGNAL_REALTIME_49
init|=
literal|61
block|,
name|TARGET_SIGNAL_REALTIME_50
init|=
literal|62
block|,
name|TARGET_SIGNAL_REALTIME_51
init|=
literal|63
block|,
name|TARGET_SIGNAL_REALTIME_52
init|=
literal|64
block|,
name|TARGET_SIGNAL_REALTIME_53
init|=
literal|65
block|,
name|TARGET_SIGNAL_REALTIME_54
init|=
literal|66
block|,
name|TARGET_SIGNAL_REALTIME_55
init|=
literal|67
block|,
name|TARGET_SIGNAL_REALTIME_56
init|=
literal|68
block|,
name|TARGET_SIGNAL_REALTIME_57
init|=
literal|69
block|,
name|TARGET_SIGNAL_REALTIME_58
init|=
literal|70
block|,
name|TARGET_SIGNAL_REALTIME_59
init|=
literal|71
block|,
name|TARGET_SIGNAL_REALTIME_60
init|=
literal|72
block|,
name|TARGET_SIGNAL_REALTIME_61
init|=
literal|73
block|,
name|TARGET_SIGNAL_REALTIME_62
init|=
literal|74
block|,
name|TARGET_SIGNAL_REALTIME_63
init|=
literal|75
block|,
if|#
directive|if
name|defined
argument_list|(
name|MACH
argument_list|)
operator|||
name|defined
argument_list|(
name|__MACH__
argument_list|)
comment|/* Mach exceptions */
name|TARGET_EXC_BAD_ACCESS
init|=
literal|76
block|,
name|TARGET_EXC_BAD_INSTRUCTION
init|=
literal|77
block|,
name|TARGET_EXC_ARITHMETIC
init|=
literal|78
block|,
name|TARGET_EXC_EMULATION
init|=
literal|79
block|,
name|TARGET_EXC_SOFTWARE
init|=
literal|80
block|,
name|TARGET_EXC_BREAKPOINT
init|=
literal|81
block|,
endif|#
directive|endif
comment|/* Some signal we don't know about.  */
name|TARGET_SIGNAL_UNKNOWN
block|,
comment|/* Use whatever signal we use when one is not specifically specified      (for passing to proceed and so on).  */
name|TARGET_SIGNAL_DEFAULT
block|,
comment|/* Last and unused enum value, for sizing arrays, etc.  */
name|TARGET_SIGNAL_LAST
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
comment|/* Return the string for a signal.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|target_signal_to_string
name|PARAMS
argument_list|(
operator|(
expr|enum
name|target_signal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the name (SIGHUP, etc.) for a signal.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|target_signal_to_name
name|PARAMS
argument_list|(
operator|(
expr|enum
name|target_signal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a name (SIGHUP, etc.), return its signal.  */
end_comment

begin_decl_stmt
name|enum
name|target_signal
name|target_signal_from_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* If certain kinds of activity happen, target_wait should perform    callbacks.  */
end_comment

begin_comment
comment|/* Right now we just call (*TARGET_ACTIVITY_FUNCTION) if I/O is possible    on TARGET_ACTIVITY_FD.   */
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

begin_extern
extern|extern int (*target_activity_function
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

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
argument|*to_post_attach
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
argument|*to_require_attach
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
argument|*to_require_detach
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
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
expr|enum
name|target_signal
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
expr|struct
name|target_waitstatus
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_post_wait
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
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
if|#
directive|if
literal|0
comment|/* Enable this after 4.12.  */
comment|/* Search target memory.  Start at STARTADDR and take LEN bytes of      target memory, and them with MASK, and compare to DATA.  If they      match, set *ADDR_FOUND to the address we found it at, store the data      we found at LEN bytes starting at DATA_FOUND, and return.  If      not, add INCREMENT to the search address and keep trying until      the search address is outside of the range [LORANGE,HIRANGE).       If we don't find anything, set *ADDR_FOUND to (CORE_ADDR)0 and return.  */
block|void (*to_search) PARAMS ((int len, char *data, char *mask, 			     CORE_ADDR startaddr, int increment, 			     CORE_ADDR lorange, CORE_ADDR hirange, 			     CORE_ADDR *addr_found, char *data_found));
define|#
directive|define
name|target_search
parameter_list|(
name|len
parameter_list|,
name|data
parameter_list|,
name|mask
parameter_list|,
name|startaddr
parameter_list|,
name|increment
parameter_list|,
name|lorange
parameter_list|,
name|hirange
parameter_list|,
name|addr_found
parameter_list|,
name|data_found
parameter_list|)
define|\
value|(*current_target.to_search) (len, data, mask, startaddr, increment, \ 				lorange, hirange, addr_found, data_found)
endif|#
directive|endif
comment|/* 0 */
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
argument|*to_post_startup_inferior
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
argument|*to_acknowledge_created_inferior
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
argument|*to_clone_and_follow_inferior
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
argument|*to_post_follow_inferior_by_clone
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
argument|*to_insert_fork_catchpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_remove_fork_catchpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_insert_vfork_catchpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_remove_vfork_catchpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_has_forked
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
name|int
argument_list|(
argument|*to_has_vforked
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
name|int
argument_list|(
argument|*to_can_follow_vfork_prior_to_exec
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
argument|*to_post_follow_vfork
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
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
argument|*to_insert_exec_catchpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_remove_exec_catchpoint
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_has_execd
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_reported_exec_events_per_exec_call
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
argument|*to_has_syscall_event
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|enum
name|target_waitkind
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*to_has_exited
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
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
name|int
argument_list|(
argument|*to_thread_alive
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*to_stop
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
argument|*to_query
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
comment|/*char*/
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|struct
name|symtab_and_line
modifier|*
argument_list|(
operator|*
name|to_enable_exception_callback
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|enum
name|exception_event_kind
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
name|struct
name|exception_event_record
modifier|*
argument_list|(
operator|*
name|to_get_current_exception_event
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
name|char
operator|*
operator|(
operator|*
name|to_pid_to_exec_file
operator|)
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
expr_stmt|;
name|char
operator|*
operator|(
operator|*
name|to_core_file_to_sym_file
operator|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
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
name|DONT_USE
decl_stmt|;
comment|/* formerly to_next */
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
name|current_target
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An item on the target stack.  */
end_comment

begin_struct
struct|struct
name|target_stack_item
block|{
name|struct
name|target_stack_item
modifier|*
name|next
decl_stmt|;
name|struct
name|target_ops
modifier|*
name|target_ops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The target stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_stack_item
modifier|*
name|target_stack
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
value|(*current_target.to_open) (name, from_tty)
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
value|(*current_target.to_close) (quitting)
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
value|(*current_target.to_attach) (args, from_tty)
end_define

begin_comment
comment|/* The target_attach operation places a process under debugger control,    and stops the process.     This operation provides a target-specific hook that allows the    necessary bookkeeping to be performed after an attach completes.    */
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
comment|/* Attaches to a process on the target side, if not already attached.    (If already attached, takes no action.)     This operation can be used to follow the child process of a fork.    On some targets, such child processes of an original inferior process    are automatically under debugger control, and thus do not require an    actual attach operation.  */
end_comment

begin_define
define|#
directive|define
name|target_require_attach
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
define|\
value|(*current_target.to_require_attach) (args, from_tty)
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
comment|/* Detaches from a process on the target side, if not already dettached.    (If already detached, takes no action.)     This operation can be used to follow the parent process of a fork.    On some targets, such child processes of an original inferior process    are automatically under debugger control, and thus do require an actual    detach operation.     PID is the process id of the child to detach from.    ARGS is arguments typed by the user (e.g. a signal to send the process).    FROM_TTY says whether to be verbose or not.  */
end_comment

begin_define
define|#
directive|define
name|target_require_detach
parameter_list|(
name|pid
parameter_list|,
name|args
parameter_list|,
name|from_tty
parameter_list|)
define|\
value|(*current_target.to_require_detach) (pid, args, from_tty)
end_define

begin_comment
comment|/* Resume execution of the target process PID.  STEP says whether to    single-step or to run free; SIGGNAL is the signal to be given to    the target, or TARGET_SIGNAL_0 for no signal.  The caller may not    pass TARGET_SIGNAL_DEFAULT.  */
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
value|(*current_target.to_resume) (pid, step, siggnal)
end_define

begin_comment
comment|/* Wait for process pid to do something.  Pid = -1 to wait for any pid    to do something.  Return pid of child, or -1 in case of error;    store status through argument pointer STATUS.  Note that it is    *not* OK to return_to_top_level out of target_wait without popping    the debugging target from the stack; GDB isn't prepared to get back    to the prompt with a debugging target but without the frame cache,    stop_pc, etc., set up.  */
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
value|(*current_target.to_wait) (pid, status)
end_define

begin_comment
comment|/* The target_wait operation waits for a process event to occur, and    thereby stop the process.     On some targets, certain events may happen in sequences.  gdb's    correct response to any single event of such a sequence may require    knowledge of what earlier events in the sequence have been seen.     This operation provides a target-specific hook that allows the    necessary bookkeeping to be performed to track such sequences.    */
end_comment

begin_define
define|#
directive|define
name|target_post_wait
parameter_list|(
name|pid
parameter_list|,
name|status
parameter_list|)
define|\
value|(*current_target.to_post_wait) (pid, status)
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
name|int
name|target_read_string
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
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
name|target_read_memory
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_read_memory_section
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
name|asection
operator|*
name|bfd_section
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|child_pid_to_exec_file
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
name|child_core_file_to_sym_file
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CHILD_POST_ATTACH
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|child_post_attach
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|child_post_wait
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|child_post_startup_inferior
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
name|child_acknowledge_created_inferior
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
name|child_clone_and_follow_inferior
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
name|child_post_follow_inferior_by_clone
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
name|child_insert_fork_catchpoint
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
name|child_remove_fork_catchpoint
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
name|child_insert_vfork_catchpoint
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
name|child_remove_vfork_catchpoint
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
name|child_has_forked
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
name|int
name|child_has_vforked
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
name|child_acknowledge_created_inferior
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
name|child_can_follow_vfork_prior_to_exec
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
name|child_post_follow_vfork
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|child_insert_exec_catchpoint
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
name|child_remove_exec_catchpoint
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
name|child_has_execd
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|child_reported_exec_events_per_exec_call
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
name|child_has_syscall_event
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|enum
name|target_waitkind
operator|*
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
name|child_has_exited
name|PARAMS
argument_list|(
operator|(
name|int
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
name|child_thread_alive
name|PARAMS
argument_list|(
operator|(
name|int
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
value|(*current_target.to_files_info) (&current_target)
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
value|(*current_target.to_insert_breakpoint) (addr, save)
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
value|(*current_target.to_load) (arg, from_tty)
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
value|(*current_target.to_lookup_symbol) (name, addrp)
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
value|(*current_target.to_create_inferior) (exec_file, args, env)
end_define

begin_comment
comment|/* Some targets (such as ttrace-based HPUX) don't allow us to request    notification of inferior events such as fork and vork immediately    after the inferior is created.  (This because of how gdb gets an    inferior created via invoking a shell to do it.  In such a scenario,    if the shell init file has commands in it, the shell will fork and    exec for each of those commands, and we will see each such fork    event.  Very bad.)        Such targets will supply an appropriate definition for this function.    */
end_comment

begin_define
define|#
directive|define
name|target_post_startup_inferior
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_post_startup_inferior) (pid)
end_define

begin_comment
comment|/* On some targets, the sequence of starting up an inferior requires    some synchronization between gdb and the new inferior process, PID.    */
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
comment|/* An inferior process has been created via a fork() or similar    system call.  This function will clone the debugger, then ensure    that CHILD_PID is attached to by that debugger.     FOLLOWED_CHILD is set TRUE on return *for the clone debugger only*,    and FALSE otherwise.  (The original and clone debuggers can use this    to determine which they are, if need be.)     (This is not a terribly useful feature without a GUI to prevent    the two debuggers from competing for shell input.)    */
end_comment

begin_define
define|#
directive|define
name|target_clone_and_follow_inferior
parameter_list|(
name|child_pid
parameter_list|,
name|followed_child
parameter_list|)
define|\
value|(*current_target.to_clone_and_follow_inferior) (child_pid, followed_child)
end_define

begin_comment
comment|/* This operation is intended to be used as the last in a sequence of    steps taken when following both parent and child of a fork.  This    is used by a clone of the debugger, which will follow the child.     The original debugger has detached from this process, and the    clone has attached to it.     On some targets, this requires a bit of cleanup to make it work    correctly.    */
end_comment

begin_define
define|#
directive|define
name|target_post_follow_inferior_by_clone
parameter_list|()
define|\
value|(*current_target.to_post_follow_inferior_by_clone) ()
end_define

begin_comment
comment|/* On some targets, we can catch an inferior fork or vfork event when it    occurs.  These functions insert/remove an already-created catchpoint for    such events.    */
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
comment|/* Returns TRUE if PID has invoked the fork() system call.  And,    also sets CHILD_PID to the process id of the other ("child")    inferior process that was created by that call.    */
end_comment

begin_define
define|#
directive|define
name|target_has_forked
parameter_list|(
name|pid
parameter_list|,
name|child_pid
parameter_list|)
define|\
value|(*current_target.to_has_forked) (pid,child_pid)
end_define

begin_comment
comment|/* Returns TRUE if PID has invoked the vfork() system call.  And,    also sets CHILD_PID to the process id of the other ("child")    inferior process that was created by that call.    */
end_comment

begin_define
define|#
directive|define
name|target_has_vforked
parameter_list|(
name|pid
parameter_list|,
name|child_pid
parameter_list|)
define|\
value|(*current_target.to_has_vforked) (pid,child_pid)
end_define

begin_comment
comment|/* Some platforms (such as pre-10.20 HP-UX) don't allow us to do    anything to a vforked child before it subsequently calls exec().    On such platforms, we say that the debugger cannot "follow" the    child until it has vforked.     This function should be defined to return 1 by those targets    which can allow the debugger to immediately follow a vforked    child, and 0 if they cannot.    */
end_comment

begin_define
define|#
directive|define
name|target_can_follow_vfork_prior_to_exec
parameter_list|()
define|\
value|(*current_target.to_can_follow_vfork_prior_to_exec) ()
end_define

begin_comment
comment|/* An inferior process has been created via a vfork() system call.    The debugger has followed the parent, the child, or both.  The    process of setting up for that follow may have required some    target-specific trickery to track the sequence of reported events.    If so, this function should be defined by those targets that    require the debugger to perform cleanup or initialization after    the vfork follow.    */
end_comment

begin_define
define|#
directive|define
name|target_post_follow_vfork
parameter_list|(
name|parent_pid
parameter_list|,
name|followed_parent
parameter_list|,
name|child_pid
parameter_list|,
name|followed_child
parameter_list|)
define|\
value|(*current_target.to_post_follow_vfork) (parent_pid,followed_parent,child_pid,followed_child)
end_define

begin_comment
comment|/* On some targets, we can catch an inferior exec event when it    occurs.  These functions insert/remove an already-created catchpoint    for such events.    */
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
comment|/* Returns TRUE if PID has invoked a flavor of the exec() system call.    And, also sets EXECD_PATHNAME to the pathname of the executable file    that was passed to exec(), and is now being executed.    */
end_comment

begin_define
define|#
directive|define
name|target_has_execd
parameter_list|(
name|pid
parameter_list|,
name|execd_pathname
parameter_list|)
define|\
value|(*current_target.to_has_execd) (pid,execd_pathname)
end_define

begin_comment
comment|/* Returns the number of exec events that are reported when a process    invokes a flavor of the exec() system call on this target, if exec    events are being reported.    */
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
comment|/* Returns TRUE if PID has reported a syscall event.  And, also sets    KIND to the appropriate TARGET_WAITKIND_, and sets SYSCALL_ID to    the unique integer ID of the syscall.    */
end_comment

begin_define
define|#
directive|define
name|target_has_syscall_event
parameter_list|(
name|pid
parameter_list|,
name|kind
parameter_list|,
name|syscall_id
parameter_list|)
define|\
value|(*current_target.to_has_syscall_event) (pid,kind,syscall_id)
end_define

begin_comment
comment|/* Returns TRUE if PID has exited.  And, also sets EXIT_STATUS to the    exit code of PID, if any.    */
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
comment|/* The debugger has completed a blocking wait() call.  There is now    some process event that must be processed.  This function should    be defined by those targets that require the debugger to perform    cleanup or internal state changes in response to the process event.    */
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
name|pid
parameter_list|)
define|\
value|(*current_target.to_notice_signals) (pid)
end_define

begin_comment
comment|/* Check to see if a thread is still alive.  */
end_comment

begin_define
define|#
directive|define
name|target_thread_alive
parameter_list|(
name|pid
parameter_list|)
define|\
value|(*current_target.to_thread_alive) (pid)
end_define

begin_comment
comment|/* Make target stop in a continuable fashion.  (For instance, under Unix, this    should act like SIGSTOP).  This function is normally used by GUIs to    implement a stop button.  */
end_comment

begin_define
define|#
directive|define
name|target_stop
value|current_target.to_stop
end_define

begin_comment
comment|/* Queries the target side for some information.  The first argument is a    letter specifying the type of the query, which is used to determine who    should process it.  The second argument is a string that specifies which     information is desired and the third is a buffer that carries back the     response from the target side. The fourth parameter is the size of the    output buffer supplied. */
end_comment

begin_define
define|#
directive|define
name|target_query
parameter_list|(
name|query_type
parameter_list|,
name|query
parameter_list|,
name|resp_buffer
parameter_list|,
name|bufffer_size
parameter_list|)
define|\
value|(*current_target.to_query) (query_type, query, resp_buffer, bufffer_size)
end_define

begin_comment
comment|/* Get the symbol information for a breakpointable routine called when    an exception event occurs.     Intended mainly for C++, and for those    platforms/implementations where such a callback mechanism is available,    e.g. HP-UX with ANSI C++ (aCC).  Some compilers (e.g. g++) support    different mechanisms for debugging exceptions. */
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
comment|/* Get the current exception event kind -- throw or catch, etc. */
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
comment|/* Pointer to next target in the chain, e.g. a core file and an exec file.  */
end_comment

begin_define
define|#
directive|define
name|target_next
define|\
value|(current_target.to_next)
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

begin_decl_stmt
specifier|extern
name|void
name|target_link
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
decl_stmt|;
end_decl_stmt

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

begin_ifndef
ifndef|#
directive|ifndef
name|target_new_objfile
end_ifndef

begin_define
define|#
directive|define
name|target_new_objfile
parameter_list|(
name|OBJFILE
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|normal_pid_to_str (ID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Attempts to find the pathname of the executable file    that was run to create a specified process.     The process PID must be stopped when this operation is used.        If the executable file cannot be determined, NULL is returned.     Else, a pointer to a character string containing the pathname    is returned.  This string should be copied into a buffer by    the client if the string will not be immediately used, or if    it must persist.    */
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
comment|/* Hook to call target-dependant code after reading in a new symbol table. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SYMFILE_POSTREAD
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SYMFILE_POSTREAD
parameter_list|(
name|OBJFILE
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hook to call target dependant code just after inferior target process has    started.  */
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
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP-UX supplies these operations, which respectively disable and enable    the memory page-protections that are used to implement hardware watchpoints    on that platform.  See wait_for_inferior's use of these.    */
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
comment|/* Provide defaults for systems that don't support hardware watchpoints. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_ifndef

begin_comment
comment|/* Returns non-zero if we can set a hardware watchpoint of type TYPE.  TYPE is    one of bp_hardware_watchpoint, bp_read_watchpoint, bp_write_watchpoint, or    bp_hardware_breakpoint.  CNT is the number of such watchpoints used so far    (including this one?).  OTHERTYPE is who knows what...  */
end_comment

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
value|0
end_define

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
value|(LONGEST)(byte_count)<= REGISTER_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* However, some addresses may not be profitable to use hardware to watch,    or may be difficult to understand when the addressed object is out of    scope, and hence should be unwatched.  On some targets, this may have    severe performance penalties, such that we might as well use regular    watchpoints, and save (possibly precious) hardware watchpoints for other    locations.    */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_RANGE_PROFITABLE_FOR_HW_WATCHPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_RANGE_PROFITABLE_FOR_HW_WATCHPOINT
parameter_list|(
name|pid
parameter_list|,
name|start
parameter_list|,
name|len
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set/clear a hardware watchpoint starting at ADDR, for LEN bytes.  TYPE is 0    for write, 1 for read, and 2 for read/write accesses.  Returns 0 for    success, non-zero for failure.  */
end_comment

begin_define
define|#
directive|define
name|target_remove_watchpoint
parameter_list|(
name|ADDR
parameter_list|,
name|LEN
parameter_list|,
name|TYPE
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|target_insert_watchpoint
parameter_list|(
name|ADDR
parameter_list|,
name|LEN
parameter_list|,
name|TYPE
parameter_list|)
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_HAS_HARDWARE_WATCHPOINTS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|target_insert_hw_breakpoint
end_ifndef

begin_define
define|#
directive|define
name|target_remove_hw_breakpoint
parameter_list|(
name|ADDR
parameter_list|,
name|SHADOW
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|target_insert_hw_breakpoint
parameter_list|(
name|ADDR
parameter_list|,
name|SHADOW
parameter_list|)
value|-1
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
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If defined, then we need to decr pc by this much after a hardware break-    point.  Presumably this overrides DECR_PC_AFTER_BREAK...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECR_PC_AFTER_HW_BREAK
end_ifndef

begin_define
define|#
directive|define
name|DECR_PC_AFTER_HW_BREAK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sometimes gdb may pick up what appears to be a valid target address    from a minimal symbol, but the value really means, essentially,    "This is an index into a table which is populated when the inferior    is run.  Therefore, do not attempt to use this as a PC."    */
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
comment|/* This will only be defined by a target that supports catching vfork events,    such as HP-UX.     On some targets (such as HP-UX 10.20 and earlier), resuming a newly vforked    child process after it has exec'd, causes the parent process to resume as    well.  To prevent the parent from running spontaneously, such targets should    define this to a function that prevents that from happening.    */
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
comment|/* This will only be defined by a target that supports catching vfork events,    such as HP-UX.     On some targets (such as HP-UX 10.20 and earlier), a newly vforked child    process must be resumed when it delivers its exec event, before the parent    vfork event will be delivered to us.    */
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

begin_decl_stmt
specifier|extern
name|breakpoint_from_pc_fn
name|memory_breakpoint_from_pc
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BREAKPOINT_FROM_PC
end_ifndef

begin_define
define|#
directive|define
name|BREAKPOINT_FROM_PC
parameter_list|(
name|pcptr
parameter_list|,
name|lenptr
parameter_list|)
value|memory_breakpoint_from_pc (pcptr, lenptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* From target.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|initialize_targets
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
specifier|extern
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
name|find_default_require_attach
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
name|find_default_require_detach
name|PARAMS
argument_list|(
operator|(
name|int
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
name|void
name|find_default_clone_and_follow_inferior
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

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|target_memory_bfd_section
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

begin_decl_stmt
specifier|extern
name|void
name|store_waitstatus
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_waitstatus
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert between host signal numbers and enum target_signal's.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|target_signal
name|target_signal_from_host
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
name|target_signal_to_host
name|PARAMS
argument_list|(
operator|(
expr|enum
name|target_signal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert from a number used in a GDB command to an enum target_signal.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|target_signal
name|target_signal_from_command
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Any target can call this to switch to remote protocol (in remote.c). */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|push_remote_target
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Imported from machine dependent code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOFTWARE_SINGLE_STEP_P
end_ifndef

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP_P
value|0
end_define

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP
parameter_list|(
name|sig
parameter_list|,
name|bp_p
parameter_list|)
value|abort ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOFTWARE_SINGLE_STEP_P */
end_comment

begin_comment
comment|/* Blank target vector entries are initialized to target_ignore. */
end_comment

begin_decl_stmt
name|void
name|target_ignore
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro for getting target's idea of a frame pointer.    FIXME: GDB's whole scheme for dealing with "frames" and    "frame pointers" needs a serious shakedown.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VIRTUAL_FRAME_POINTER
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VIRTUAL_FRAME_POINTER
parameter_list|(
name|ADDR
parameter_list|,
name|REGP
parameter_list|,
name|OFFP
parameter_list|)
define|\
value|do { *(REGP) = FP_REGNUM; *(OFFP) =  0; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_VIRTUAL_FRAME_POINTER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TARGET_H) */
end_comment

end_unit

