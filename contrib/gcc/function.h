begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Structure for saving state for a nested function.    Copyright (C) 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_struct
struct|struct
name|var_refs_queue
block|{
name|rtx
name|modified
decl_stmt|;
name|enum
name|machine_mode
name|promoted_mode
decl_stmt|;
name|int
name|unsignedp
decl_stmt|;
name|struct
name|var_refs_queue
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Stack of pending (incomplete) sequences saved by `start_sequence'.    Each element describes one pending sequence.    The main insn-chain is saved in the last element of the chain,    unless the chain is empty.  */
end_comment

begin_struct
struct|struct
name|sequence_stack
block|{
comment|/* First and last insns in the chain of the saved sequence.  */
name|rtx
name|first
decl_stmt|,
name|last
decl_stmt|;
name|tree
name|sequence_rtl_expr
decl_stmt|;
name|struct
name|sequence_stack
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sequence_stack
modifier|*
name|sequence_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of single obstacks.  */
end_comment

begin_struct
struct|struct
name|simple_obstack_stack
block|{
name|struct
name|obstack
modifier|*
name|obstack
decl_stmt|;
name|struct
name|simple_obstack_stack
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_struct
struct|struct
name|emit_status
block|{
comment|/* This is reset to LAST_VIRTUAL_REGISTER + 1 at the start of each function.      After rtl generation, it is 1 plus the largest register number used.  */
name|int
name|x_reg_rtx_no
decl_stmt|;
comment|/* Lowest label number in current function.  */
name|int
name|x_first_label_num
decl_stmt|;
comment|/* The ends of the doubly-linked chain of rtl for the current function.      Both are reset to null at the start of rtl generation for the function.          start_sequence saves both of these on `sequence_stack' along with      `sequence_rtl_expr' and then starts a new, nested sequence of insns.  */
name|rtx
name|x_first_insn
decl_stmt|;
name|rtx
name|x_last_insn
decl_stmt|;
comment|/* RTL_EXPR within which the current sequence will be placed.  Use to      prevent reuse of any temporaries within the sequence until after the      RTL_EXPR is emitted.  */
name|tree
name|sequence_rtl_expr
decl_stmt|;
comment|/* Stack of pending (incomplete) sequences saved by `start_sequence'.      Each element describes one pending sequence.      The main insn-chain is saved in the last element of the chain,      unless the chain is empty.  */
name|struct
name|sequence_stack
modifier|*
name|sequence_stack
decl_stmt|;
comment|/* INSN_UID for next insn emitted.      Reset to 1 for each function compiled.  */
name|int
name|x_cur_insn_uid
decl_stmt|;
comment|/* Line number and source file of the last line-number NOTE emitted.      This is used to avoid generating duplicates.  */
name|int
name|x_last_linenum
decl_stmt|;
specifier|const
name|char
modifier|*
name|x_last_filename
decl_stmt|;
comment|/* The length of the regno_pointer_align, regno_decl, and x_regno_reg_rtx      vectors.  Since these vectors are needed during the expansion phase when      the total number of registers in the function is not yet known, the      vectors are copied and made bigger when necessary.  */
name|int
name|regno_pointer_align_length
decl_stmt|;
comment|/* Indexed by pseudo register number, if nonzero gives the known alignment      for that pseudo (if REG_POINTER is set in x_regno_reg_rtx).      Allocated in parallel with x_regno_reg_rtx.  */
name|unsigned
name|char
modifier|*
name|regno_pointer_align
decl_stmt|;
comment|/* Indexed by pseudo register number, if nonzero gives the decl      corresponding to that register.  */
name|tree
modifier|*
name|regno_decl
decl_stmt|;
comment|/* Indexed by pseudo register number, gives the rtx for that pseudo.      Allocated in parallel with regno_pointer_align.  */
name|rtx
modifier|*
name|x_regno_reg_rtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For backward compatibility... eventually these should all go away.  */
end_comment

begin_define
define|#
directive|define
name|reg_rtx_no
value|(cfun->emit->x_reg_rtx_no)
end_define

begin_define
define|#
directive|define
name|seq_rtl_expr
value|(cfun->emit->sequence_rtl_expr)
end_define

begin_define
define|#
directive|define
name|regno_reg_rtx
value|(cfun->emit->x_regno_reg_rtx)
end_define

begin_define
define|#
directive|define
name|seq_stack
value|(cfun->emit->sequence_stack)
end_define

begin_define
define|#
directive|define
name|REGNO_POINTER_ALIGN
parameter_list|(
name|REGNO
parameter_list|)
value|(cfun->emit->regno_pointer_align[REGNO])
end_define

begin_define
define|#
directive|define
name|REGNO_DECL
parameter_list|(
name|REGNO
parameter_list|)
value|(cfun->emit->regno_decl[REGNO])
end_define

begin_struct
struct|struct
name|expr_status
block|{
comment|/* Number of units that we should eventually pop off the stack.      These are the arguments to function calls that have already returned.  */
name|int
name|x_pending_stack_adjust
decl_stmt|;
comment|/* Under some ABIs, it is the caller's responsibility to pop arguments      pushed for function calls.  A naive implementation would simply pop      the arguments immediately after each call.  However, if several      function calls are made in a row, it is typically cheaper to pop      all the arguments after all of the calls are complete since a      single pop instruction can be used.  Therefore, GCC attempts to      defer popping the arguments until absolutely necessary.  (For      example, at the end of a conditional, the arguments must be popped,      since code outside the conditional won't know whether or not the      arguments need to be popped.)       When INHIBIT_DEFER_POP is non-zero, however, the compiler does not      attempt to defer pops.  Instead, the stack is popped immediately      after each call.  Rather then setting this variable directly, use      NO_DEFER_POP and OK_DEFER_POP.  */
name|int
name|x_inhibit_defer_pop
decl_stmt|;
comment|/* If PREFERRED_STACK_BOUNDARY and PUSH_ROUNDING are defined, the stack      boundary can be momentairly unaligned while pushing the arguments.      Record the delta since last aligned boundary here in order to get      stack alignment in the nested function calls working right.  */
name|int
name|x_stack_pointer_delta
decl_stmt|;
comment|/* Nonzero means __builtin_saveregs has already been done in this function.      The value is the pseudoreg containing the value __builtin_saveregs      returned.  */
name|rtx
name|x_saveregs_value
decl_stmt|;
comment|/* Similarly for __builtin_apply_args.  */
name|rtx
name|x_apply_args_value
decl_stmt|;
comment|/* List of labels that must never be deleted.  */
name|rtx
name|x_forced_labels
decl_stmt|;
comment|/* Postincrements that still need to be expanded.  */
name|rtx
name|x_pending_chain
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pending_stack_adjust
value|(cfun->expr->x_pending_stack_adjust)
end_define

begin_define
define|#
directive|define
name|inhibit_defer_pop
value|(cfun->expr->x_inhibit_defer_pop)
end_define

begin_define
define|#
directive|define
name|saveregs_value
value|(cfun->expr->x_saveregs_value)
end_define

begin_define
define|#
directive|define
name|apply_args_value
value|(cfun->expr->x_apply_args_value)
end_define

begin_define
define|#
directive|define
name|forced_labels
value|(cfun->expr->x_forced_labels)
end_define

begin_define
define|#
directive|define
name|pending_chain
value|(cfun->expr->x_pending_chain)
end_define

begin_define
define|#
directive|define
name|stack_pointer_delta
value|(cfun->expr->x_stack_pointer_delta)
end_define

begin_comment
comment|/* This structure can save all the important global and static variables    describing the status of the current function.  */
end_comment

begin_struct
struct|struct
name|function
block|{
name|struct
name|eh_status
modifier|*
name|eh
decl_stmt|;
name|struct
name|stmt_status
modifier|*
name|stmt
decl_stmt|;
name|struct
name|expr_status
modifier|*
name|expr
decl_stmt|;
name|struct
name|emit_status
modifier|*
name|emit
decl_stmt|;
name|struct
name|varasm_status
modifier|*
name|varasm
decl_stmt|;
comment|/* For function.c.  */
comment|/* Name of this function.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Points to the FUNCTION_DECL of this function.  */
name|tree
name|decl
decl_stmt|;
comment|/* Function containing this function, if any.  */
name|struct
name|function
modifier|*
name|outer
decl_stmt|;
comment|/* Number of bytes of args popped by function being compiled on its return.      Zero if no bytes are to be popped.      May affect compilation of return insn or of function epilogue.  */
name|int
name|pops_args
decl_stmt|;
comment|/* If function's args have a fixed size, this is that size, in bytes.      Otherwise, it is -1.      May affect compilation of return insn or of function epilogue.  */
name|int
name|args_size
decl_stmt|;
comment|/* # bytes the prologue should push and pretend that the caller pushed them.      The prologue must do this, but only if parms can be passed in      registers.  */
name|int
name|pretend_args_size
decl_stmt|;
comment|/* # of bytes of outgoing arguments.  If ACCUMULATE_OUTGOING_ARGS is      defined, the needed space is pushed by the prologue.  */
name|int
name|outgoing_args_size
decl_stmt|;
comment|/* This is the offset from the arg pointer to the place where the first      anonymous arg can be found, if there is one.  */
name|rtx
name|arg_offset_rtx
decl_stmt|;
comment|/* Quantities of various kinds of registers      used for the current function's args.  */
name|CUMULATIVE_ARGS
name|args_info
decl_stmt|;
comment|/* If non-zero, an RTL expression for the location at which the current       function returns its result.  If the current function returns its      result in a register, current_function_return_rtx will always be      the hard register containing the result.  */
name|rtx
name|return_rtx
decl_stmt|;
comment|/* The arg pointer hard register, or the pseudo into which it was copied.  */
name|rtx
name|internal_arg_pointer
decl_stmt|;
comment|/* Language-specific reason why the current function cannot be made      inline.  */
specifier|const
name|char
modifier|*
name|cannot_inline
decl_stmt|;
comment|/* Opaque pointer used by get_hard_reg_initial_val and      has_hard_reg_initial_val (see integrate.[hc]).  */
name|struct
name|initial_value_struct
modifier|*
name|hard_reg_initial_vals
decl_stmt|;
comment|/* Number of function calls seen so far in current function.  */
name|int
name|x_function_call_count
decl_stmt|;
comment|/* List (chain of TREE_LIST) of LABEL_DECLs for all nonlocal labels      (labels to which there can be nonlocal gotos from nested functions)      in this function.  */
name|tree
name|x_nonlocal_labels
decl_stmt|;
comment|/* List (chain of EXPR_LIST) of stack slots that hold the current handlers      for nonlocal gotos.  There is one for every nonlocal label in the      function; this list matches the one in nonlocal_labels.      Zero when function does not have nonlocal labels.  */
name|rtx
name|x_nonlocal_goto_handler_slots
decl_stmt|;
comment|/* List (chain of EXPR_LIST) of labels heading the current handlers for      nonlocal gotos.  */
name|rtx
name|x_nonlocal_goto_handler_labels
decl_stmt|;
comment|/* RTX for stack slot that holds the stack pointer value to restore      for a nonlocal goto.      Zero when function does not have nonlocal labels.  */
name|rtx
name|x_nonlocal_goto_stack_level
decl_stmt|;
comment|/* Label that will go on parm cleanup code, if any.      Jumping to this label runs cleanup code for parameters, if      such code must be run.  Following this code is the logical return      label.  */
name|rtx
name|x_cleanup_label
decl_stmt|;
comment|/* Label that will go on function epilogue.      Jumping to this label serves as a "return" instruction      on machines which require execution of the epilogue on all returns.  */
name|rtx
name|x_return_label
decl_stmt|;
comment|/* List (chain of EXPR_LISTs) of pseudo-regs of SAVE_EXPRs.      So we can mark them all live at the end of the function, if nonopt.  */
name|rtx
name|x_save_expr_regs
decl_stmt|;
comment|/* List (chain of EXPR_LISTs) of all stack slots in this function.      Made for the sake of unshare_all_rtl.  */
name|rtx
name|x_stack_slot_list
decl_stmt|;
comment|/* Chain of all RTL_EXPRs that have insns in them.  */
name|tree
name|x_rtl_expr_chain
decl_stmt|;
comment|/* Label to jump back to for tail recursion, or 0 if we have      not yet needed one for this function.  */
name|rtx
name|x_tail_recursion_label
decl_stmt|;
comment|/* Place after which to insert the tail_recursion_label if we need one.  */
name|rtx
name|x_tail_recursion_reentry
decl_stmt|;
comment|/* Location at which to save the argument pointer if it will need to be      referenced.  There are two cases where this is done: if nonlocal gotos      exist, or if vars stored at an offset from the argument pointer will be      needed by inner routines.  */
name|rtx
name|x_arg_pointer_save_area
decl_stmt|;
comment|/* If the function returns non-void, we will emit a clobber of the      return registers just in case the user fell off the end without      returning a proper value.  This is that insn.  */
name|rtx
name|x_clobber_return_insn
decl_stmt|;
comment|/* Offset to end of allocated area of stack frame.      If stack grows down, this is the address of the last stack slot allocated.      If stack grows up, this is the address for the next slot.  */
name|HOST_WIDE_INT
name|x_frame_offset
decl_stmt|;
comment|/* List (chain of TREE_LISTs) of static chains for containing functions.      Each link has a FUNCTION_DECL in the TREE_PURPOSE and a reg rtx      in an RTL_EXPR in the TREE_VALUE.  */
name|tree
name|x_context_display
decl_stmt|;
comment|/* List (chain of TREE_LISTs) of trampolines for nested functions.      The trampoline sets up the static chain and jumps to the function.      We supply the trampoline's address when the function's address is      requested.       Each link has a FUNCTION_DECL in the TREE_PURPOSE and a reg rtx      in an RTL_EXPR in the TREE_VALUE.  */
name|tree
name|x_trampoline_list
decl_stmt|;
comment|/* Insn after which register parms and SAVE_EXPRs are born, if nonopt.  */
name|rtx
name|x_parm_birth_insn
decl_stmt|;
comment|/* Last insn of those whose job was to put parms into their nominal      homes.  */
name|rtx
name|x_last_parm_insn
decl_stmt|;
comment|/* 1 + last pseudo register number possibly used for loading a copy      of a parameter of this function.  */
name|unsigned
name|int
name|x_max_parm_reg
decl_stmt|;
comment|/* Vector indexed by REGNO, containing location on stack in which      to put the parm which is nominally in pseudo register REGNO,      if we discover that that parm must go in the stack.  The highest      element in this vector is one less than MAX_PARM_REG, above.  */
name|rtx
modifier|*
name|x_parm_reg_stack_loc
decl_stmt|;
comment|/* List of all temporaries allocated, both available and in use.  */
name|struct
name|temp_slot
modifier|*
name|x_temp_slots
decl_stmt|;
comment|/* Current nesting level for temporaries.  */
name|int
name|x_temp_slot_level
decl_stmt|;
comment|/* Current nesting level for variables in a block.  */
name|int
name|x_var_temp_slot_level
decl_stmt|;
comment|/* When temporaries are created by TARGET_EXPRs, they are created at      this level of temp_slot_level, so that they can remain allocated      until no longer needed.  CLEANUP_POINT_EXPRs define the lifetime      of TARGET_EXPRs.  */
name|int
name|x_target_temp_slot_level
decl_stmt|;
comment|/* This slot is initialized as 0 and is added to      during the nested function.  */
name|struct
name|var_refs_queue
modifier|*
name|fixup_var_refs_queue
decl_stmt|;
comment|/* For integrate.c.  */
name|int
name|inlinable
decl_stmt|;
name|int
name|no_debugging_symbols
decl_stmt|;
comment|/* This is in fact an rtvec.  */
name|void
modifier|*
name|original_arg_vector
decl_stmt|;
name|tree
name|original_decl_initial
decl_stmt|;
comment|/* Last insn of those whose job was to put parms into their nominal      homes.  */
name|rtx
name|inl_last_parm_insn
decl_stmt|;
comment|/* Highest label number in current function.  */
name|int
name|inl_max_label_num
decl_stmt|;
comment|/* For md files.  */
comment|/* tm.h can use this to store whatever it likes.  */
name|struct
name|machine_function
modifier|*
name|machine
decl_stmt|;
comment|/* The largest alignment of slot allocated on the stack.  */
name|int
name|stack_alignment_needed
decl_stmt|;
comment|/* Preferred alignment of the end of stack frame.  */
name|int
name|preferred_stack_boundary
decl_stmt|;
comment|/* Language-specific code can use this to store whatever it likes.  */
name|struct
name|language_function
modifier|*
name|language
decl_stmt|;
comment|/* For reorg.  */
comment|/* If some insns can be deferred to the delay slots of the epilogue, the      delay list for them is recorded here.  */
name|rtx
name|epilogue_delay_list
decl_stmt|;
comment|/* Collected bit flags.  */
comment|/* Nonzero if function being compiled needs to be given an address      where the value should be stored.  */
name|unsigned
name|int
name|returns_struct
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled needs to      return the address of where it has put a structure value.  */
name|unsigned
name|int
name|returns_pcc_struct
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the current function returns a pointer type.  */
name|unsigned
name|int
name|returns_pointer
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled needs to be passed a static chain.  */
name|unsigned
name|int
name|needs_context
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled can call setjmp.  */
name|unsigned
name|int
name|calls_setjmp
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled can call longjmp.  */
name|unsigned
name|int
name|calls_longjmp
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled can call alloca,      either as a subroutine or builtin.  */
name|unsigned
name|int
name|calls_alloca
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the function calls __builtin_eh_return.  */
name|unsigned
name|int
name|calls_eh_return
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled receives nonlocal gotos      from nested functions.  */
name|unsigned
name|int
name|has_nonlocal_label
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled has nonlocal gotos to parent      function.  */
name|unsigned
name|int
name|has_nonlocal_goto
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if function being compiled contains nested functions.  */
name|unsigned
name|int
name|contains_functions
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the function being compiled issues a computed jump.  */
name|unsigned
name|int
name|has_computed_jump
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the current function is a thunk (a lightweight function that      just adjusts one of its arguments and forwards to another function), so      we should try to cut corners where we can.  */
name|unsigned
name|int
name|is_thunk
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if instrumentation calls for function entry and exit should be      generated.  */
name|unsigned
name|int
name|instrument_entry_exit
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if profiling code should be generated.  */
name|unsigned
name|int
name|profile
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if stack limit checking should be enabled in the current      function.  */
name|unsigned
name|int
name|limit_stack
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if current function uses varargs.h or equivalent.      Zero for functions that use stdarg.h.  */
name|unsigned
name|int
name|varargs
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if current function uses stdarg.h or equivalent.      Zero for functions that use varargs.h.  */
name|unsigned
name|int
name|stdarg
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this function is being processed in function-at-a-time      mode.  In other words, if all tree structure for this function,      including the BLOCK tree, is created before RTL generation      commences.  */
name|unsigned
name|int
name|x_whole_function_mode_p
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the back-end should not keep track of expressions that      determine the size of variable-sized objects.  Normally, such      expressions are saved away, and then expanded when the next      function is started.  For example, if a parameter has a      variable-sized type, then the size of the parameter is computed      when the function body is entered.  However, some front-ends do      not desire this behavior.  */
name|unsigned
name|int
name|x_dont_save_pending_sizes_p
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the current function uses the constant pool.  */
name|unsigned
name|int
name|uses_const_pool
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the current function uses pic_offset_table_rtx.  */
name|unsigned
name|int
name|uses_pic_offset_table
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the current function needs an lsda for exception handling.  */
name|unsigned
name|int
name|uses_eh_lsda
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if code to initialize arg_pointer_save_area has been emited.  */
name|unsigned
name|int
name|arg_pointer_save_area_init
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The function currently being compiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|function
modifier|*
name|cfun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we've already converted virtual regs to hard regs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|virtuals_instantiated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For backward compatibility... eventually these should all go away.  */
end_comment

begin_define
define|#
directive|define
name|current_function_name
value|(cfun->name)
end_define

begin_define
define|#
directive|define
name|current_function_pops_args
value|(cfun->pops_args)
end_define

begin_define
define|#
directive|define
name|current_function_returns_struct
value|(cfun->returns_struct)
end_define

begin_define
define|#
directive|define
name|current_function_returns_pcc_struct
value|(cfun->returns_pcc_struct)
end_define

begin_define
define|#
directive|define
name|current_function_returns_pointer
value|(cfun->returns_pointer)
end_define

begin_define
define|#
directive|define
name|current_function_needs_context
value|(cfun->needs_context)
end_define

begin_define
define|#
directive|define
name|current_function_calls_setjmp
value|(cfun->calls_setjmp)
end_define

begin_define
define|#
directive|define
name|current_function_calls_alloca
value|(cfun->calls_alloca)
end_define

begin_define
define|#
directive|define
name|current_function_calls_longjmp
value|(cfun->calls_longjmp)
end_define

begin_define
define|#
directive|define
name|current_function_calls_eh_return
value|(cfun->calls_eh_return)
end_define

begin_define
define|#
directive|define
name|current_function_has_computed_jump
value|(cfun->has_computed_jump)
end_define

begin_define
define|#
directive|define
name|current_function_contains_functions
value|(cfun->contains_functions)
end_define

begin_define
define|#
directive|define
name|current_function_is_thunk
value|(cfun->is_thunk)
end_define

begin_define
define|#
directive|define
name|current_function_args_info
value|(cfun->args_info)
end_define

begin_define
define|#
directive|define
name|current_function_args_size
value|(cfun->args_size)
end_define

begin_define
define|#
directive|define
name|current_function_pretend_args_size
value|(cfun->pretend_args_size)
end_define

begin_define
define|#
directive|define
name|current_function_outgoing_args_size
value|(cfun->outgoing_args_size)
end_define

begin_define
define|#
directive|define
name|current_function_arg_offset_rtx
value|(cfun->arg_offset_rtx)
end_define

begin_define
define|#
directive|define
name|current_function_varargs
value|(cfun->varargs)
end_define

begin_define
define|#
directive|define
name|current_function_stdarg
value|(cfun->stdarg)
end_define

begin_define
define|#
directive|define
name|current_function_internal_arg_pointer
value|(cfun->internal_arg_pointer)
end_define

begin_define
define|#
directive|define
name|current_function_return_rtx
value|(cfun->return_rtx)
end_define

begin_define
define|#
directive|define
name|current_function_instrument_entry_exit
value|(cfun->instrument_entry_exit)
end_define

begin_define
define|#
directive|define
name|current_function_profile
value|(cfun->profile)
end_define

begin_define
define|#
directive|define
name|current_function_limit_stack
value|(cfun->limit_stack)
end_define

begin_define
define|#
directive|define
name|current_function_uses_pic_offset_table
value|(cfun->uses_pic_offset_table)
end_define

begin_define
define|#
directive|define
name|current_function_uses_const_pool
value|(cfun->uses_const_pool)
end_define

begin_define
define|#
directive|define
name|current_function_cannot_inline
value|(cfun->cannot_inline)
end_define

begin_define
define|#
directive|define
name|current_function_epilogue_delay_list
value|(cfun->epilogue_delay_list)
end_define

begin_define
define|#
directive|define
name|current_function_has_nonlocal_label
value|(cfun->has_nonlocal_label)
end_define

begin_define
define|#
directive|define
name|current_function_has_nonlocal_goto
value|(cfun->has_nonlocal_goto)
end_define

begin_define
define|#
directive|define
name|max_parm_reg
value|(cfun->x_max_parm_reg)
end_define

begin_define
define|#
directive|define
name|parm_reg_stack_loc
value|(cfun->x_parm_reg_stack_loc)
end_define

begin_define
define|#
directive|define
name|cleanup_label
value|(cfun->x_cleanup_label)
end_define

begin_define
define|#
directive|define
name|return_label
value|(cfun->x_return_label)
end_define

begin_define
define|#
directive|define
name|save_expr_regs
value|(cfun->x_save_expr_regs)
end_define

begin_define
define|#
directive|define
name|stack_slot_list
value|(cfun->x_stack_slot_list)
end_define

begin_define
define|#
directive|define
name|parm_birth_insn
value|(cfun->x_parm_birth_insn)
end_define

begin_define
define|#
directive|define
name|frame_offset
value|(cfun->x_frame_offset)
end_define

begin_define
define|#
directive|define
name|tail_recursion_label
value|(cfun->x_tail_recursion_label)
end_define

begin_define
define|#
directive|define
name|tail_recursion_reentry
value|(cfun->x_tail_recursion_reentry)
end_define

begin_define
define|#
directive|define
name|arg_pointer_save_area
value|(cfun->x_arg_pointer_save_area)
end_define

begin_define
define|#
directive|define
name|rtl_expr_chain
value|(cfun->x_rtl_expr_chain)
end_define

begin_define
define|#
directive|define
name|last_parm_insn
value|(cfun->x_last_parm_insn)
end_define

begin_define
define|#
directive|define
name|context_display
value|(cfun->x_context_display)
end_define

begin_define
define|#
directive|define
name|trampoline_list
value|(cfun->x_trampoline_list)
end_define

begin_define
define|#
directive|define
name|function_call_count
value|(cfun->x_function_call_count)
end_define

begin_define
define|#
directive|define
name|temp_slots
value|(cfun->x_temp_slots)
end_define

begin_define
define|#
directive|define
name|temp_slot_level
value|(cfun->x_temp_slot_level)
end_define

begin_define
define|#
directive|define
name|target_temp_slot_level
value|(cfun->x_target_temp_slot_level)
end_define

begin_define
define|#
directive|define
name|var_temp_slot_level
value|(cfun->x_var_temp_slot_level)
end_define

begin_define
define|#
directive|define
name|nonlocal_labels
value|(cfun->x_nonlocal_labels)
end_define

begin_define
define|#
directive|define
name|nonlocal_goto_handler_slots
value|(cfun->x_nonlocal_goto_handler_slots)
end_define

begin_define
define|#
directive|define
name|nonlocal_goto_handler_labels
value|(cfun->x_nonlocal_goto_handler_labels)
end_define

begin_define
define|#
directive|define
name|nonlocal_goto_stack_level
value|(cfun->x_nonlocal_goto_stack_level)
end_define

begin_comment
comment|/* The FUNCTION_DECL for an inline function currently being expanded.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|inline_function_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a function decl for a containing function,    return the `struct function' for it.  */
end_comment

begin_decl_stmt
name|struct
name|function
modifier|*
name|find_function_data
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set NOTE_BLOCK for each block note in the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|identify_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Identify BLOCKs referenced by more than one NOTE_INSN_BLOCK_{BEG,END},    and create duplicate blocks.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|reorder_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set BLOCK_NUMBER for all the blocks in FN.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|number_blocks
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return size needed for stack frame based on slots so far allocated.    This size counts from zero.  It is not rounded to STACK_BOUNDARY;    the caller may have to do that.  */
end_comment

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|get_frame_size
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise, but for a different than the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|get_func_frame_size
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These variables hold pointers to functions to create and destroy    target specific, per-function data structures.  */
end_comment

begin_extern
extern|extern void (*init_machine_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*free_machine_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This variable holds a pointer to a function to register any    data items in the target specific, per-function data structure    that will need garbage collection.  */
end_comment

begin_extern
extern|extern void (*mark_machine_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Likewise, but for language-specific data.  */
end_comment

begin_extern
extern|extern void (*init_lang_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*mark_lang_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*save_lang_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*restore_lang_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*free_lang_status
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Save and restore status information for a nested function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|restore_emit_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_after_parsing
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_after_compilation
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_varasm_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_varasm_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_emit_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_stmt_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_eh_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_expr_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_first_block_beg
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|diddle_return_value
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|rtx
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clobber_return_register
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
name|use_return_register
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

begin_decl_stmt
specifier|extern
name|rtx
name|get_arg_pointer_save_area
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_virtual_regs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|emit_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called once, at initialization, to initialize function.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_function_once
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

