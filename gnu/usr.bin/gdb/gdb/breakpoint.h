begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data structures associated with breakpoints in GDB.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* FIXME In the future, we should fold all other breakpoint-like things into    here.  This includes:     * single-step (for machines where we have to simulate single stepping)       (probably, though perhaps it is better for it to look as much as       possible like a single-step to wait_for_inferior).  */
end_comment

begin_enum
enum|enum
name|bptype
block|{
name|bp_breakpoint
block|,
comment|/* Normal breakpoint */
name|bp_until
block|,
comment|/* used by until command */
name|bp_finish
block|,
comment|/* used by finish command */
name|bp_watchpoint
block|,
comment|/* Watchpoint */
name|bp_longjmp
block|,
comment|/* secret breakpoint to find longjmp() */
name|bp_longjmp_resume
block|,
comment|/* secret breakpoint to escape longjmp() */
comment|/* Used by wait_for_inferior for stepping over subroutine calls, for      stepping over signal handlers, and for skipping prologues.  */
name|bp_step_resume
block|,
comment|/* The breakpoint at the end of a call dummy.  */
comment|/* FIXME: What if the function we are calling longjmp()s out of the      call, or the user gets out with the "return" command?  We currently      have no way of cleaning up the breakpoint in these (obscure) situations.      (Probably can solve this by noticing longjmp, "return", etc., it's      similar to noticing when a watchpoint on a local variable goes out      of scope (with hardware support for watchpoints)).  */
name|bp_call_dummy
block|}
enum|;
end_enum

begin_comment
comment|/* States of enablement of breakpoint. */
end_comment

begin_enum
enum|enum
name|enable
block|{
name|disabled
block|,
name|enabled
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
name|delete
block|,
comment|/* Delete it */
name|disable
block|,
comment|/* Disable it */
name|donttouch
comment|/* Leave it alone */
block|}
enum|;
end_enum

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
name|enable
name|enable
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
comment|/* Address to break at, or NULL if not a breakpoint.  */
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* Line number of this address.  Only matters if address is      non-NULL.  */
name|int
name|line_number
decl_stmt|;
comment|/* Source file name of this address.  Only matters if address is      non-NULL.  */
name|char
modifier|*
name|source_file
decl_stmt|;
comment|/* Non-zero means a silent breakpoint (don't print frame info      if we stop here). */
name|unsigned
name|char
name|silent
decl_stmt|;
comment|/* Number of stops at this breakpoint that should      be continued automatically before really stopping.  */
name|int
name|ignore_count
decl_stmt|;
comment|/* "Real" contents of byte where breakpoint has been inserted.      Valid only when breakpoints are in the program.  Under the complete      control of the target insert_breakpoint and remove_breakpoint routines.      No other code should assume anything about the value(s) here.  */
name|char
name|shadow_contents
index|[
name|BREAKPOINT_MAX
index|]
decl_stmt|;
comment|/* Nonzero if this breakpoint is now inserted.  Only matters if address      is non-NULL.  */
name|char
name|inserted
decl_stmt|;
comment|/* Nonzero if this is not the first breakpoint in the list      for the given address.  Only matters if address is non-NULL.  */
name|char
name|duplicate
decl_stmt|;
comment|/* Chain of command lines to execute when this breakpoint is hit.  */
name|struct
name|command_line
modifier|*
name|commands
decl_stmt|;
comment|/* Stack depth (address of frame).  If nonzero, break only if fp      equals this.  */
name|FRAME_ADDR
name|frame
decl_stmt|;
comment|/* Conditional.  Break only if this expression's value is nonzero.  */
name|struct
name|expression
modifier|*
name|cond
decl_stmt|;
comment|/* String we used to set the breakpoint (malloc'd).  Only matters if      address is non-NULL.  */
name|char
modifier|*
name|addr_string
decl_stmt|;
comment|/* String form of the breakpoint condition (malloc'd), or NULL if there      is no condition.  */
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
comment|/* The largest block within which it is valid, or NULL if it is      valid anywhere (e.g. consists just of global symbols).  */
name|struct
name|block
modifier|*
name|exp_valid_block
decl_stmt|;
comment|/* Value of the watchpoint the last time we checked it.  */
name|value
name|val
decl_stmt|;
comment|/* Thread number for thread-specific breakpoint, or -1 if don't care */
name|int
name|thread
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The following stuff is an abstract data type "bpstat" ("breakpoint status").    This provides the ability to determine whether we have stopped at a    breakpoint, and what we should do about it.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bpstat
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

begin_decl_stmt
specifier|extern
name|void
name|bpstat_clear
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a copy of a bpstat.  Like "bs1 = bs2" but all storage that    is part of the bpstat is copied as well.  */
end_comment

begin_decl_stmt
specifier|extern
name|bpstat
name|bpstat_copy
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FIXME:  prototypes uses equivalence between FRAME_ADDR and CORE_ADDR */
end_comment

begin_decl_stmt
specifier|extern
name|bpstat
name|bpstat_stop_status
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* This bpstat_what stuff tells wait_for_inferior what to do with a    breakpoint (a challenging task).  */
end_comment

begin_enum
enum|enum
name|bpstat_what_main_action
block|{
comment|/* Perform various other tests; that is, this bpstat does not      say to perform any action (e.g. failed watchpoint and nothing      else).  */
name|BPSTAT_WHAT_KEEP_CHECKING
block|,
comment|/* Rather than distinguish between noisy and silent stops here, it      might be cleaner to have bpstat_print make that decision (also      taking into account stop_print_frame and source_only).  But the      implications are a bit scary (interaction with auto-displays, etc.),      so I won't try it.  */
comment|/* Stop silently.  */
name|BPSTAT_WHAT_STOP_SILENT
block|,
comment|/* Stop and print.  */
name|BPSTAT_WHAT_STOP_NOISY
block|,
comment|/* Remove breakpoints, single step once, then put them back in and      go back to what we were doing.  It's possible that this should be      removed from the main_action and put into a separate field, to more      cleanly handle BPSTAT_WHAT_CLEAR_LONGJMP_RESUME_SINGLE.  */
name|BPSTAT_WHAT_SINGLE
block|,
comment|/* Set longjmp_resume breakpoint, remove all other breakpoints,      and continue.  The "remove all other breakpoints" part is required      if we are also stepping over another breakpoint as well as doing      the longjmp handling.  */
name|BPSTAT_WHAT_SET_LONGJMP_RESUME
block|,
comment|/* Clear longjmp_resume breakpoint, then handle as      BPSTAT_WHAT_KEEP_CHECKING.  */
name|BPSTAT_WHAT_CLEAR_LONGJMP_RESUME
block|,
comment|/* Clear longjmp_resume breakpoint, then handle as BPSTAT_WHAT_SINGLE.  */
name|BPSTAT_WHAT_CLEAR_LONGJMP_RESUME_SINGLE
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
comment|/* Did we hit the step resume breakpoint?  This is separate from the      main_action to allow for it to be combined with any of the main      actions.  */
name|int
name|step_resume
decl_stmt|;
comment|/* Did we hit a call dummy breakpoint?  This only goes with a main_action      of BPSTAT_WHAT_STOP_SILENT or BPSTAT_WHAT_STOP_NOISY (the concept of      continuing from a call dummy without popping the frame is not a      useful one).  */
name|int
name|call_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tell what to do about this bpstat.  */
end_comment

begin_decl_stmt
name|struct
name|bpstat_what
name|bpstat_what
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Find the bpstat associated with a breakpoint.  NULL otherwise. */
end_comment

begin_decl_stmt
name|bpstat
name|bpstat_find_breakpoint
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|,
expr|struct
name|breakpoint
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|bpstat_should_step
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a message indicating what happened.  Returns nonzero to    say that only the source line should be printed after this (zero    return means print the frame as well as the source line).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bpstat_print
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the breakpoint number of the first breakpoint we are stopped    at.  *BSP upon return is a bpstat which points to the remaining    breakpoints stopped at (but which is not guaranteed to be good for    anything but further calls to bpstat_num).    Return 0 if passed a bpstat which does not indicate any breakpoints.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bpstat_num
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform actions associated with having stopped at *BSP.  Actually, we just    use this for breakpoint commands.  Perhaps other actions will go here    later, but this is executed at a late time (from the command loop).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bpstat_do_actions
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modify BS so that the actions will not be performed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bpstat_clear_actions
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implementation:  */
end_comment

begin_struct
struct|struct
name|bpstat
block|{
comment|/* Linked list because there can be two breakpoints at the      same place, and a bpstat reflects the fact that both have been hit.  */
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
name|value
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
comment|/* Function called by bpstat_print to print stuff associated with      this element of the bpstat chain.  Returns 0 or 1 just like      bpstat_print, or -1 if it can't deal with it.  */
name|int
argument_list|(
argument|*print_it
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bpstat
name|bs
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Prototypes for breakpoint-related functions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Forward declarations for prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|breakpoint_here_p
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
name|int
name|breakpoint_thread_match
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
name|void
name|until_break_command
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
name|breakpoint_re_set
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
name|clear_momentary_breakpoints
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FIXME:  Prototype uses equivalence of "struct frame_info *" and FRAME */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|breakpoint
modifier|*
name|set_momentary_breakpoint
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab_and_line
operator|,
expr|struct
name|frame_info
operator|*
operator|,
expr|enum
name|bptype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_ignore_count
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_default_breakpoint
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|CORE_ADDR
operator|,
expr|struct
name|symtab
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
name|mark_breakpoints_out
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
name|breakpoint_init_inferior
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
name|delete_breakpoint
name|PARAMS
argument_list|(
operator|(
expr|struct
name|breakpoint
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|breakpoint_auto_delete
name|PARAMS
argument_list|(
operator|(
name|bpstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|breakpoint_clear_ignore_counts
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
name|break_command
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
name|int
name|insert_breakpoints
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
name|remove_breakpoints
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
name|enable_longjmp_breakpoint
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
name|disable_longjmp_breakpoint
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
name|set_longjmp_resume_breakpoint
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|FRAME
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following are for displays, which aren't really breakpoints, but    here is as good a place as any for them.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|disable_current_display
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
name|do_displays
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
name|disable_display
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
name|clear_displays
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (BREAKPOINT_H) */
end_comment

end_unit

