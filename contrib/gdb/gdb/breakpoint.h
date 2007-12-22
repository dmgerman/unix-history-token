begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data structures associated with breakpoints in GDB.    Copyright 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001,    2002, 2003, 2004    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BREAKPOINT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|BREAKPOINT_H
value|1
end_define

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"gdb-events.h"
end_include

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|block
struct_decl|;
end_struct_decl

begin_comment
comment|/* This is the maximum number of bytes a breakpoint instruction can take.    Feel free to increase it.  It's just used in a few places to size    arrays that should be independent of the target architecture.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT_MAX
value|16
end_define

begin_escape
end_escape

begin_comment
comment|/* Type of breakpoint. */
end_comment

begin_comment
comment|/* FIXME In the future, we should fold all other breakpoint-like things into    here.  This includes:     * single-step (for machines where we have to simulate single stepping)    (probably, though perhaps it is better for it to look as much as    possible like a single-step to wait_for_inferior).  */
end_comment

begin_enum
enum|enum
name|bptype
block|{
name|bp_none
init|=
literal|0
block|,
comment|/* Eventpoint has been deleted. */
name|bp_breakpoint
block|,
comment|/* Normal breakpoint */
name|bp_hardware_breakpoint
block|,
comment|/* Hardware assisted breakpoint */
name|bp_until
block|,
comment|/* used by until command */
name|bp_finish
block|,
comment|/* used by finish command */
name|bp_watchpoint
block|,
comment|/* Watchpoint */
name|bp_hardware_watchpoint
block|,
comment|/* Hardware assisted watchpoint */
name|bp_read_watchpoint
block|,
comment|/* read watchpoint, (hardware assisted) */
name|bp_access_watchpoint
block|,
comment|/* access watchpoint, (hardware assisted) */
name|bp_longjmp
block|,
comment|/* secret breakpoint to find longjmp() */
name|bp_longjmp_resume
block|,
comment|/* secret breakpoint to escape longjmp() */
comment|/* Used by wait_for_inferior for stepping over subroutine calls, for        stepping over signal handlers, and for skipping prologues.  */
name|bp_step_resume
block|,
comment|/* Used by wait_for_inferior for stepping over signal handlers.  */
name|bp_through_sigtramp
block|,
comment|/* Used to detect when a watchpoint expression has gone out of        scope.  These breakpoints are usually not visible to the user.         This breakpoint has some interesting properties:         1) There's always a 1:1 mapping between watchpoints        on local variables and watchpoint_scope breakpoints.         2) It automatically deletes itself and the watchpoint it's        associated with when hit.         3) It can never be disabled.  */
name|bp_watchpoint_scope
block|,
comment|/* The breakpoint at the end of a call dummy.  */
comment|/* FIXME: What if the function we are calling longjmp()s out of the        call, or the user gets out with the "return" command?  We currently        have no way of cleaning up the breakpoint in these (obscure) situations.        (Probably can solve this by noticing longjmp, "return", etc., it's        similar to noticing when a watchpoint on a local variable goes out        of scope (with hardware support for watchpoints)).  */
name|bp_call_dummy
block|,
comment|/* Some dynamic linkers (HP, maybe Solaris) can arrange for special        code in the inferior to run when significant events occur in the        dynamic linker (for example a library is loaded or unloaded).         By placing a breakpoint in this magic code GDB will get control        when these significant events occur.  GDB can then re-examine        the dynamic linker's data structures to discover any newly loaded        dynamic libraries.  */
name|bp_shlib_event
block|,
comment|/* Some multi-threaded systems can arrange for a location in the         inferior to be executed when certain thread-related events occur        (such as thread creation or thread death).         By placing a breakpoint at one of these locations, GDB will get        control when these events occur.  GDB can then update its thread        lists etc.  */
name|bp_thread_event
block|,
comment|/* On the same principal, an overlay manager can arrange to call a        magic location in the inferior whenever there is an interesting        change in overlay status.  GDB can update its overlay tables        and fiddle with breakpoints in overlays when this breakpoint         is hit.  */
name|bp_overlay_event
block|,
comment|/* These breakpoints are used to implement the "catch load" command        on platforms whose dynamic linkers support such functionality.  */
name|bp_catch_load
block|,
comment|/* These breakpoints are used to implement the "catch unload" command        on platforms whose dynamic linkers support such functionality.  */
name|bp_catch_unload
block|,
comment|/* These are not really breakpoints, but are catchpoints that        implement the "catch fork", "catch vfork" and "catch exec" commands        on platforms whose kernel support such functionality.  (I.e.,        kernels which can raise an event when a fork or exec occurs, as        opposed to the debugger setting breakpoints on functions named        "fork" or "exec".) */
name|bp_catch_fork
block|,
name|bp_catch_vfork
block|,
name|bp_catch_exec
block|,
comment|/* These are catchpoints to implement "catch catch" and "catch throw"        commands for C++ exception handling. */
name|bp_catch_catch
block|,
name|bp_catch_throw
block|}
enum|;
end_enum

begin_comment
comment|/* States of enablement of breakpoint. */
end_comment

begin_enum
enum|enum
name|enable_state
block|{
name|bp_disabled
block|,
comment|/* The eventpoint is inactive, and cannot trigger. */
name|bp_enabled
block|,
comment|/* The eventpoint is active, and can trigger. */
name|bp_shlib_disabled
block|,
comment|/* The eventpoint's address is in an unloaded solib. 			   The eventpoint will be automatically enabled  			   and reset when that solib is loaded. */
name|bp_call_disabled
block|,
comment|/* The eventpoint has been disabled while a call  			   into the inferior is "in flight", because some  			   eventpoints interfere with the implementation of  			   a call on some targets.  The eventpoint will be  			   automatically enabled and reset when the call  			   "lands" (either completes, or stops at another  			   eventpoint). */
name|bp_permanent
comment|/* There is a breakpoint instruction hard-wired into 			   the target's code.  Don't try to write another 			   breakpoint instruction on top of it, or restore 			   its value.  Step over it using the architecture's 			   SKIP_INSN macro.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Disposition of breakpoint.  Ie: what to do after hitting it. */
end_comment

begin_enum
enum|enum
name|bpdisp
block|{
name|disp_del
block|,
comment|/* Delete it */
name|disp_del_at_next_stop
block|,
comment|/* Delete at next stop, whether hit or not */
name|disp_disable
block|,
comment|/* Disable it */
name|disp_donttouch
comment|/* Leave it alone */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|target_hw_bp_type
block|{
name|hw_write
init|=
literal|0
block|,
comment|/* Common  HW watchpoint */
name|hw_read
init|=
literal|1
block|,
comment|/* Read    HW watchpoint */
name|hw_access
init|=
literal|2
block|,
comment|/* Access  HW watchpoint */
name|hw_execute
init|=
literal|3
comment|/* Execute HW breakpoint */
block|}
enum|;
end_enum

begin_comment
comment|/* GDB maintains two types of information about each breakpoint (or    watchpoint, or other related event).  The first type corresponds    to struct breakpoint; this is a relatively high-level structure    which contains the source location(s), stopping conditions, user    commands to execute when the breakpoint is hit, and so forth.     The second type of information corresponds to struct bp_location.    Each breakpoint has one or (eventually) more locations associated    with it, which represent target-specific and machine-specific    mechanisms for stopping the program.  For instance, a watchpoint    expression may require multiple hardware watchpoints in order to    catch all changes in the value of the expression being watched.  */
end_comment

begin_enum
enum|enum
name|bp_loc_type
block|{
name|bp_loc_software_breakpoint
block|,
name|bp_loc_hardware_breakpoint
block|,
name|bp_loc_hardware_watchpoint
block|,
name|bp_loc_other
comment|/* Miscellaneous...  */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|bp_location
block|{
comment|/* Chain pointer to the next breakpoint location.  */
name|struct
name|bp_location
modifier|*
name|next
decl_stmt|;
comment|/* Type of this breakpoint location.  */
name|enum
name|bp_loc_type
name|loc_type
decl_stmt|;
comment|/* Each breakpoint location must belong to exactly one higher-level      breakpoint.  This and the DUPLICATE flag are more straightforward      than reference counting.  */
name|struct
name|breakpoint
modifier|*
name|owner
decl_stmt|;
comment|/* Nonzero if this breakpoint is now inserted.  */
name|char
name|inserted
decl_stmt|;
comment|/* Nonzero if this is not the first breakpoint in the list      for the given address.  */
name|char
name|duplicate
decl_stmt|;
comment|/* If we someday support real thread-specific breakpoints, then      the breakpoint location will need a thread identifier.  */
comment|/* Data for specific breakpoint types.  These could be a union, but      simplicity is more important than memory usage for breakpoints.  */
comment|/* Note that zero is a perfectly valid code address on some platforms      (for example, the mn10200 (OBSOLETE) and mn10300 simulators).  NULL      is not a special value for this field.  Valid for all types except      bp_loc_other.  */
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* For any breakpoint type with an address, this is the BFD section      associated with the address.  Used primarily for overlay debugging.  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* "Real" contents of byte where breakpoint has been inserted.      Valid only when breakpoints are in the program.  Under the complete      control of the target insert_breakpoint and remove_breakpoint routines.      No other code should assume anything about the value(s) here.      Valid only for bp_loc_software_breakpoint.  */
name|char
name|shadow_contents
index|[
name|BREAKPOINT_MAX
index|]
decl_stmt|;
comment|/* Address at which breakpoint was requested, either by the user or      by GDB for internal breakpoints.  This will usually be the same      as ``address'' (above) except for cases in which      ADJUST_BREAKPOINT_ADDRESS has computed a different address at      which to place the breakpoint in order to comply with a      processor's architectual constraints.  */
name|CORE_ADDR
name|requested_address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is a collection of function pointers that, if available,    will be called instead of the performing the default action for this    bptype.  */
end_comment

begin_struct
struct|struct
name|breakpoint_ops
block|{
comment|/* The normal print routine for this breakpoint, called when we      hit it.  */
name|enum
name|print_stop_action
function_decl|(
modifier|*
name|print_it
function_decl|)
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
comment|/* Display information about this breakpoint, for "info breakpoints".  */
name|void
function_decl|(
modifier|*
name|print_one
function_decl|)
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
comment|/* Display information about this breakpoint after setting it (roughly      speaking; this is called from "mention").  */
name|void
function_decl|(
modifier|*
name|print_mention
function_decl|)
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Note that the ->silent field is not currently used by any commands    (though the code is in there if it was to be, and set_raw_breakpoint    does set it to 0).  I implemented it because I thought it would be    useful for a hack I had to put in; I'm going to leave it in because    I can see how there might be times when it would indeed be useful */
end_comment

begin_comment
comment|/* This is for a breakpoint or a watchpoint.  */
end_comment

begin_struct
struct|struct
name|breakpoint
block|{
name|struct
name|breakpoint
modifier|*
name|next
decl_stmt|;
comment|/* Type of breakpoint. */
name|enum
name|bptype
name|type
decl_stmt|;
comment|/* Zero means disabled; remember the info but don't break here.  */
name|enum
name|enable_state
name|enable_state
decl_stmt|;
comment|/* What to do with this breakpoint after we hit it. */
name|enum
name|bpdisp
name|disposition
decl_stmt|;
comment|/* Number assigned to distinguish breakpoints.  */
name|int
name|number
decl_stmt|;
comment|/* Location(s) associated with this high-level breakpoint.  */
name|struct
name|bp_location
modifier|*
name|loc
decl_stmt|;
comment|/* Line number of this address.  */
name|int
name|line_number
decl_stmt|;
comment|/* Source file name of this address.  */
name|char
modifier|*
name|source_file
decl_stmt|;
comment|/* Non-zero means a silent breakpoint (don't print frame info        if we stop here). */
name|unsigned
name|char
name|silent
decl_stmt|;
comment|/* Number of stops at this breakpoint that should        be continued automatically before really stopping.  */
name|int
name|ignore_count
decl_stmt|;
comment|/* Chain of command lines to execute when this breakpoint is hit.  */
name|struct
name|command_line
modifier|*
name|commands
decl_stmt|;
comment|/* Stack depth (address of frame).  If nonzero, break only if fp        equals this.  */
name|struct
name|frame_id
name|frame_id
decl_stmt|;
comment|/* Conditional.  Break only if this expression's value is nonzero.  */
name|struct
name|expression
modifier|*
name|cond
decl_stmt|;
comment|/* String we used to set the breakpoint (malloc'd).  */
name|char
modifier|*
name|addr_string
decl_stmt|;
comment|/* Language we used to set the breakpoint.  */
name|enum
name|language
name|language
decl_stmt|;
comment|/* Input radix we used to set the breakpoint.  */
name|int
name|input_radix
decl_stmt|;
comment|/* String form of the breakpoint condition (malloc'd), or NULL if there        is no condition.  */
name|char
modifier|*
name|cond_string
decl_stmt|;
comment|/* String form of exp (malloc'd), or NULL if none.  */
name|char
modifier|*
name|exp_string
decl_stmt|;
comment|/* The expression we are watching, or NULL if not a watchpoint.  */
name|struct
name|expression
modifier|*
name|exp
decl_stmt|;
comment|/* The largest block within which it is valid, or NULL if it is        valid anywhere (e.g. consists just of global symbols).  */
name|struct
name|block
modifier|*
name|exp_valid_block
decl_stmt|;
comment|/* Value of the watchpoint the last time we checked it.  */
name|struct
name|value
modifier|*
name|val
decl_stmt|;
comment|/* Holds the value chain for a hardware watchpoint expression.  */
name|struct
name|value
modifier|*
name|val_chain
decl_stmt|;
comment|/* Holds the address of the related watchpoint_scope breakpoint        when using watchpoints on local variables (might the concept        of a related breakpoint be useful elsewhere, if not just call        it the watchpoint_scope breakpoint or something like that. FIXME).  */
name|struct
name|breakpoint
modifier|*
name|related_breakpoint
decl_stmt|;
comment|/* Holds the frame address which identifies the frame this        watchpoint should be evaluated in, or `null' if the watchpoint        should be evaluated on the outermost frame.  */
name|struct
name|frame_id
name|watchpoint_frame
decl_stmt|;
comment|/* Thread number for thread-specific breakpoint, or -1 if don't care */
name|int
name|thread
decl_stmt|;
comment|/* Count of the number of times this breakpoint was taken, dumped        with the info, but not used for anything else.  Useful for        seeing how many times you hit a break prior to the program        aborting, so you can back up to just before the abort.  */
name|int
name|hit_count
decl_stmt|;
comment|/* Filename of a dynamically-linked library (dll), used for        bp_catch_load and bp_catch_unload (malloc'd), or NULL if any        library is significant.  */
name|char
modifier|*
name|dll_pathname
decl_stmt|;
comment|/* Filename of a dll whose state change (e.g., load or unload)        triggered this catchpoint.  This field is only valid immediately        after this catchpoint has triggered.  */
name|char
modifier|*
name|triggered_dll_pathname
decl_stmt|;
comment|/* Process id of a child process whose forking triggered this        catchpoint.  This field is only valid immediately after this        catchpoint has triggered.  */
name|int
name|forked_inferior_pid
decl_stmt|;
comment|/* Filename of a program whose exec triggered this catchpoint.        This field is only valid immediately after this catchpoint has        triggered.  */
name|char
modifier|*
name|exec_pathname
decl_stmt|;
comment|/* Methods associated with this breakpoint.  */
name|struct
name|breakpoint_ops
modifier|*
name|ops
decl_stmt|;
comment|/* Was breakpoint issued from a tty?  Saved for the use of pending breakpoints.  */
name|int
name|from_tty
decl_stmt|;
comment|/* Flag value for pending breakpoint.        first bit  : 0 non-temporary, 1 temporary.        second bit : 0 normal breakpoint, 1 hardware breakpoint. */
name|int
name|flag
decl_stmt|;
comment|/* Is breakpoint pending on shlib loads?  */
name|int
name|pending
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The following stuff is an abstract data type "bpstat" ("breakpoint    status").  This provides the ability to determine whether we have    stopped at a breakpoint, and what we should do about it.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bpstats
modifier|*
name|bpstat
typedef|;
end_typedef

begin_comment
comment|/* Interface:  */
end_comment

begin_comment
comment|/* Clear a bpstat so that it says we are not at any breakpoint.    Also free any storage that is part of a bpstat.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bpstat_clear
parameter_list|(
name|bpstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a copy of a bpstat.  Like "bs1 = bs2" but all storage that    is part of the bpstat is copied as well.  */
end_comment

begin_function_decl
specifier|extern
name|bpstat
name|bpstat_copy
parameter_list|(
name|bpstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bpstat
name|bpstat_stop_status
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* This bpstat_what stuff tells wait_for_inferior what to do with a    breakpoint (a challenging task).  */
end_comment

begin_enum
enum|enum
name|bpstat_what_main_action
block|{
comment|/* Perform various other tests; that is, this bpstat does not        say to perform any action (e.g. failed watchpoint and nothing        else).  */
name|BPSTAT_WHAT_KEEP_CHECKING
block|,
comment|/* Rather than distinguish between noisy and silent stops here, it        might be cleaner to have bpstat_print make that decision (also        taking into account stop_print_frame and source_only).  But the        implications are a bit scary (interaction with auto-displays, etc.),        so I won't try it.  */
comment|/* Stop silently.  */
name|BPSTAT_WHAT_STOP_SILENT
block|,
comment|/* Stop and print.  */
name|BPSTAT_WHAT_STOP_NOISY
block|,
comment|/* Remove breakpoints, single step once, then put them back in and        go back to what we were doing.  It's possible that this should be        removed from the main_action and put into a separate field, to more        cleanly handle BPSTAT_WHAT_CLEAR_LONGJMP_RESUME_SINGLE.  */
name|BPSTAT_WHAT_SINGLE
block|,
comment|/* Set longjmp_resume breakpoint, remove all other breakpoints,        and continue.  The "remove all other breakpoints" part is required        if we are also stepping over another breakpoint as well as doing        the longjmp handling.  */
name|BPSTAT_WHAT_SET_LONGJMP_RESUME
block|,
comment|/* Clear longjmp_resume breakpoint, then handle as        BPSTAT_WHAT_KEEP_CHECKING.  */
name|BPSTAT_WHAT_CLEAR_LONGJMP_RESUME
block|,
comment|/* Clear longjmp_resume breakpoint, then handle as BPSTAT_WHAT_SINGLE.  */
name|BPSTAT_WHAT_CLEAR_LONGJMP_RESUME_SINGLE
block|,
comment|/* Clear step resume breakpoint, and keep checking.  */
name|BPSTAT_WHAT_STEP_RESUME
block|,
comment|/* Clear through_sigtramp breakpoint, muck with trap_expected, and keep        checking.  */
name|BPSTAT_WHAT_THROUGH_SIGTRAMP
block|,
comment|/* Check the dynamic linker's data structures for new libraries, then        keep checking.  */
name|BPSTAT_WHAT_CHECK_SHLIBS
block|,
comment|/* Check the dynamic linker's data structures for new libraries, then        resume out of the dynamic linker's callback, stop and print.  */
name|BPSTAT_WHAT_CHECK_SHLIBS_RESUME_FROM_HOOK
block|,
comment|/* This is just used to keep track of how many enums there are.  */
name|BPSTAT_WHAT_LAST
block|}
enum|;
end_enum

begin_struct
struct|struct
name|bpstat_what
block|{
name|enum
name|bpstat_what_main_action
name|main_action
decl_stmt|;
comment|/* Did we hit a call dummy breakpoint?  This only goes with a main_action        of BPSTAT_WHAT_STOP_SILENT or BPSTAT_WHAT_STOP_NOISY (the concept of        continuing from a call dummy without popping the frame is not a        useful one).  */
name|int
name|call_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The possible return values for print_bpstat, print_it_normal,    print_it_done, print_it_noop. */
end_comment

begin_enum
enum|enum
name|print_stop_action
block|{
name|PRINT_UNKNOWN
init|=
operator|-
literal|1
block|,
name|PRINT_SRC_AND_LOC
block|,
name|PRINT_SRC_ONLY
block|,
name|PRINT_NOTHING
block|}
enum|;
end_enum

begin_comment
comment|/* Tell what to do about this bpstat.  */
end_comment

begin_function_decl
name|struct
name|bpstat_what
name|bpstat_what
parameter_list|(
name|bpstat
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Find the bpstat associated with a breakpoint.  NULL otherwise. */
end_comment

begin_function_decl
name|bpstat
name|bpstat_find_breakpoint
parameter_list|(
name|bpstat
parameter_list|,
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find a step_resume breakpoint associated with this bpstat.    (If there are multiple step_resume bp's on the list, this function    will arbitrarily pick one.)     It is an error to use this function if BPSTAT doesn't contain a    step_resume breakpoint.     See wait_for_inferior's use of this function.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|breakpoint
modifier|*
name|bpstat_find_step_resume_breakpoint
parameter_list|(
name|bpstat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero if a signal that we got in wait() was due to circumstances    explained by the BS.  */
end_comment

begin_comment
comment|/* Currently that is true if we have hit a breakpoint, or if there is    a watchpoint enabled.  */
end_comment

begin_define
define|#
directive|define
name|bpstat_explains_signal
parameter_list|(
name|bs
parameter_list|)
value|((bs) != NULL)
end_define

begin_comment
comment|/* Nonzero if we should step constantly (e.g. watchpoints on machines    without hardware support).  This isn't related to a specific bpstat,    just to things like whether watchpoints are set.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bpstat_should_step
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero if there are enabled hardware watchpoints. */
end_comment

begin_function_decl
specifier|extern
name|int
name|bpstat_have_active_hw_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a message indicating what happened.  Returns nonzero to    say that only the source line should be printed after this (zero    return means print the frame as well as the source line).  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|print_stop_action
name|bpstat_print
parameter_list|(
name|bpstat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the breakpoint number of the first breakpoint we are stopped    at.  *BSP upon return is a bpstat which points to the remaining    breakpoints stopped at (but which is not guaranteed to be good for    anything but further calls to bpstat_num).    Return 0 if passed a bpstat which does not indicate any breakpoints.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bpstat_num
parameter_list|(
name|bpstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Perform actions associated with having stopped at *BSP.  Actually, we just    use this for breakpoint commands.  Perhaps other actions will go here    later, but this is executed at a late time (from the command loop).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bpstat_do_actions
parameter_list|(
name|bpstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Modify BS so that the actions will not be performed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bpstat_clear_actions
parameter_list|(
name|bpstat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a bpstat that records zero or more triggered eventpoints, this    function returns another bpstat which contains only the catchpoints    on that first list, if any.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bpstat_get_triggered_catchpoints
parameter_list|(
name|bpstat
parameter_list|,
name|bpstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implementation:  */
end_comment

begin_comment
comment|/* Values used to tell the printing routine how to behave for this bpstat. */
end_comment

begin_enum
enum|enum
name|bp_print_how
block|{
comment|/* This is used when we want to do a normal printing of the reason        for stopping. The output will depend on the type of eventpoint        we are dealing with. This is the default value, most commonly        used. */
name|print_it_normal
block|,
comment|/* This is used when nothing should be printed for this bpstat entry.  */
name|print_it_noop
block|,
comment|/* This is used when everything which needs to be printed has        already been printed.  But we still want to print the frame.  */
name|print_it_done
block|}
enum|;
end_enum

begin_struct
struct|struct
name|bpstats
block|{
comment|/* Linked list because there can be two breakpoints at the same        place, and a bpstat reflects the fact that both have been hit.  */
name|bpstat
name|next
decl_stmt|;
comment|/* Breakpoint that we are at.  */
name|struct
name|breakpoint
modifier|*
name|breakpoint_at
decl_stmt|;
comment|/* Commands left to be done.  */
name|struct
name|command_line
modifier|*
name|commands
decl_stmt|;
comment|/* Old value associated with a watchpoint.  */
name|struct
name|value
modifier|*
name|old_val
decl_stmt|;
comment|/* Nonzero if this breakpoint tells us to print the frame.  */
name|char
name|print
decl_stmt|;
comment|/* Nonzero if this breakpoint tells us to stop.  */
name|char
name|stop
decl_stmt|;
comment|/* Tell bpstat_print and print_bp_stop_message how to print stuff        associated with this element of the bpstat chain.  */
name|enum
name|bp_print_how
name|print_it
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|inf_context
block|{
name|inf_starting
block|,
name|inf_running
block|,
name|inf_exited
block|}
enum|;
end_enum

begin_comment
comment|/* The possible return values for breakpoint_here_p.    We guarantee that zero always means "no breakpoint here".  */
end_comment

begin_enum
enum|enum
name|breakpoint_here
block|{
name|no_breakpoint_here
init|=
literal|0
block|,
name|ordinary_breakpoint_here
block|,
name|permanent_breakpoint_here
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Prototypes for breakpoint-related functions.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|breakpoint_here
name|breakpoint_here_p
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|breakpoint_inserted_here_p
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|software_breakpoint_inserted_here_p
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/2002-11-10: The current [generic] dummy-frame code    implements a functional superset of this function.  The only reason    it hasn't been removed is because some architectures still don't    use the new framework.  Once they have been fixed, this can go.  */
end_comment

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|deprecated_frame_in_dummy
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|breakpoint_thread_match
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
name|until_break_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_re_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_re_set_thread
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ep_is_exception_catchpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|breakpoint
modifier|*
name|set_momentary_breakpoint
parameter_list|(
name|struct
name|symtab_and_line
parameter_list|,
name|struct
name|frame_id
parameter_list|,
name|enum
name|bptype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_ignore_count
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_default_breakpoint
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|struct
name|symtab
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_breakpoints_out
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_init_inferior
parameter_list|(
name|enum
name|inf_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup_delete_breakpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_exec_cleanup_delete_breakpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_breakpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_auto_delete
parameter_list|(
name|bpstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint_clear_ignore_counts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|break_command
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
name|hbreak_command_wrapper
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
name|thbreak_command_wrapper
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
name|rbreak_command_wrapper
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
name|watch_command_wrapper
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
name|awatch_command_wrapper
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
name|rwatch_command_wrapper
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
name|tbreak_command
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
name|int
name|insert_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|remove_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function can be used to physically insert eventpoints from the    specified traced inferior process, without modifying the breakpoint    package's state.  This can be useful for those targets which support    following the processes of a fork() or vfork() system call, when both    of the resulting two processes are to be followed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|reattach_breakpoints
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function can be used to update the breakpoint package's state    after an exec() system call has been executed.     This function causes the following:     - All eventpoints are marked "not inserted".    - All eventpoints with a symbolic address are reset such that    the symbolic address must be reevaluated before the eventpoints    can be reinserted.    - The solib breakpoints are explicitly removed from the breakpoint    list.    - A step-resume breakpoint, if any, is explicitly removed from the    breakpoint list.    - All eventpoints without a symbolic address are removed from the    breakpoint list. */
end_comment

begin_function_decl
specifier|extern
name|void
name|update_breakpoints_after_exec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function can be used to physically remove hardware breakpoints    and watchpoints from the specified traced inferior process, without    modifying the breakpoint package's state.  This can be useful for    those targets which support following the processes of a fork() or    vfork() system call, when one of the resulting two processes is to    be detached and allowed to run free.     It is an error to use this function on the process whose id is    inferior_ptid.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|detach_breakpoints
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_longjmp_breakpoint
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_longjmp_breakpoint
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_overlay_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_overlay_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_longjmp_resume_breakpoint
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|frame_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions respectively disable or reenable all currently    enabled watchpoints.  When disabled, the watchpoints are marked    call_disabled.  When reenabled, they are marked enabled.     The intended client of these functions is call_function_by_hand.     The inferior must be stopped, and all breakpoints removed, when    these functions are used.     The need for these functions is that on some targets (e.g., HP-UX),    gdb is unable to unwind through the dummy frame that is pushed as    part of the implementation of a call command.  Watchpoints can    cause the inferior to stop in places where this frame is visible,    and that can cause execution control to become very confused.     Note that if a user sets breakpoints in an interactively called    function, the call_disabled watchpoints will have been reenabled    when the first such breakpoint is reached.  However, on targets    that are unable to unwind through the call dummy frame, watches    of stack-based storage may then be deleted, because gdb will    believe that their watched storage is out of scope.  (Sigh.) */
end_comment

begin_function_decl
specifier|extern
name|void
name|disable_watchpoints_before_interactive_call_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_watchpoints_after_interactive_call_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_breakpoint_hit_counts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_number
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_number_or_range
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following are for displays, which aren't really breakpoints, but    here is as good a place as any for them.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|disable_current_display
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_displays
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_display
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_displays
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_breakpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_breakpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_breakpoint_permanent
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|breakpoint
modifier|*
name|create_solib_event_breakpoint
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|breakpoint
modifier|*
name|create_thread_event_breakpoint
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_solib_event_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_thread_event_breakpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_breakpoints_in_shlibs
parameter_list|(
name|int
name|silent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|re_enable_breakpoints_in_shlibs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|create_solib_load_event_breakpoint
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|create_solib_unload_event_breakpoint
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|create_fork_event_catchpoint
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|create_vfork_event_catchpoint
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|create_exec_event_catchpoint
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function returns TRUE if ep is a catchpoint. */
end_comment

begin_function_decl
specifier|extern
name|int
name|ep_is_catchpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function returns TRUE if ep is a catchpoint of a    shared library (aka dynamically-linked library) event,    such as a library load or unload. */
end_comment

begin_function_decl
specifier|extern
name|int
name|ep_is_shlib_catchpoint
parameter_list|(
name|struct
name|breakpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|breakpoint
modifier|*
name|set_breakpoint_sal
parameter_list|(
name|struct
name|symtab_and_line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable breakpoints and delete when hit.  Called with ARG == NULL    deletes all breakpoints. */
end_comment

begin_function_decl
specifier|extern
name|void
name|delete_command
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
comment|/* Pull all H/W watchpoints from the target. Return non-zero if the    remove fails. */
end_comment

begin_function_decl
specifier|extern
name|int
name|remove_hw_watchpoints
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
comment|/* !defined (BREAKPOINT_H) */
end_comment

end_unit

