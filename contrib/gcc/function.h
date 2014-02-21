begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Structure for saving state for a nested function.    Copyright (C) 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_FUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_FUNCTION_H
end_define

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_decl_stmt
name|struct
name|var_refs_queue
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Stack of pending (incomplete) sequences saved by `start_sequence'.    Each element describes one pending sequence.    The main insn-chain is saved in the last element of the chain,    unless the chain is empty.  */
end_comment

begin_decl_stmt
name|struct
name|sequence_stack
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* First and last insns in the chain of the saved sequence.  */
name|rtx
name|first
decl_stmt|;
name|rtx
name|last
decl_stmt|;
name|struct
name|sequence_stack
modifier|*
name|next
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

begin_decl_stmt
name|struct
name|emit_status
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* This is reset to LAST_VIRTUAL_REGISTER + 1 at the start of each function.      After rtl generation, it is 1 plus the largest register number used.  */
name|int
name|x_reg_rtx_no
decl_stmt|;
comment|/* Lowest label number in current function.  */
name|int
name|x_first_label_num
decl_stmt|;
comment|/* The ends of the doubly-linked chain of rtl for the current function.      Both are reset to null at the start of rtl generation for the function.       start_sequence saves both of these on `sequence_stack' and then starts      a new, nested sequence of insns.  */
name|rtx
name|x_first_insn
decl_stmt|;
name|rtx
name|x_last_insn
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
comment|/* Location the last line-number NOTE emitted.      This is used to avoid generating duplicates.  */
name|location_t
name|x_last_location
decl_stmt|;
comment|/* The length of the regno_pointer_align, regno_decl, and x_regno_reg_rtx      vectors.  Since these vectors are needed during the expansion phase when      the total number of registers in the function is not yet known, the      vectors are copied and made bigger when necessary.  */
name|int
name|regno_pointer_align_length
decl_stmt|;
comment|/* Indexed by pseudo register number, if nonzero gives the known alignment      for that pseudo (if REG_POINTER is set in x_regno_reg_rtx).      Allocated in parallel with x_regno_reg_rtx.  */
name|unsigned
name|char
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%h.x_reg_rtx_no"
argument_list|)
operator|)
argument_list|)
name|regno_pointer_align
decl_stmt|;
comment|/* Indexed by pseudo register number, gives the rtx for that pseudo.      Allocated in parallel with regno_pointer_align.  */
name|rtx
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%h.x_reg_rtx_no"
argument_list|)
operator|)
argument_list|)
name|x_regno_reg_rtx
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

begin_decl_stmt
name|struct
name|expr_status
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Number of units that we should eventually pop off the stack.      These are the arguments to function calls that have already returned.  */
name|int
name|x_pending_stack_adjust
decl_stmt|;
comment|/* Under some ABIs, it is the caller's responsibility to pop arguments      pushed for function calls.  A naive implementation would simply pop      the arguments immediately after each call.  However, if several      function calls are made in a row, it is typically cheaper to pop      all the arguments after all of the calls are complete since a      single pop instruction can be used.  Therefore, GCC attempts to      defer popping the arguments until absolutely necessary.  (For      example, at the end of a conditional, the arguments must be popped,      since code outside the conditional won't know whether or not the      arguments need to be popped.)       When INHIBIT_DEFER_POP is nonzero, however, the compiler does not      attempt to defer pops.  Instead, the stack is popped immediately      after each call.  Rather then setting this variable directly, use      NO_DEFER_POP and OK_DEFER_POP.  */
name|int
name|x_inhibit_defer_pop
decl_stmt|;
comment|/* If PREFERRED_STACK_BOUNDARY and PUSH_ROUNDING are defined, the stack      boundary can be momentarily unaligned while pushing the arguments.      Record the delta since last aligned boundary here in order to get      stack alignment in the nested function calls working right.  */
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|stack_pointer_delta
value|(cfun->expr->x_stack_pointer_delta)
end_define

begin_struct_decl
struct_decl|struct
name|temp_slot
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|temp_slot
modifier|*
name|temp_slot_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|temp_slot_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|temp_slot_p
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|function_frequency
block|{
comment|/* This function most likely won't be executed at all.      (set only when profile feedback is available).  */
name|FUNCTION_FREQUENCY_UNLIKELY_EXECUTED
block|,
comment|/* The default value.  */
name|FUNCTION_FREQUENCY_NORMAL
block|,
comment|/* Optimize this function hard      (set only when profile feedback is available).  */
name|FUNCTION_FREQUENCY_HOT
block|}
enum|;
end_enum

begin_comment
comment|/* This structure can save all the important global and static variables    describing the status of the current function.  */
end_comment

begin_decl_stmt
name|struct
name|function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|eh_status
modifier|*
name|eh
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
comment|/* The control flow graph for this function.  */
name|struct
name|control_flow_graph
modifier|*
name|cfg
decl_stmt|;
comment|/* For function.c.  */
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
comment|/* If nonzero, an RTL expression for the location at which the current      function returns its result.  If the current function returns its      result in a register, current_function_return_rtx will always be      the hard register containing the result.  */
name|rtx
name|return_rtx
decl_stmt|;
comment|/* The arg pointer hard register, or the pseudo into which it was copied.  */
name|rtx
name|internal_arg_pointer
decl_stmt|;
comment|/* Opaque pointer used by get_hard_reg_initial_val and      has_hard_reg_initial_val (see integrate.[hc]).  */
name|struct
name|initial_value_struct
modifier|*
name|hard_reg_initial_vals
decl_stmt|;
comment|/* List (chain of EXPR_LIST) of labels heading the current handlers for      nonlocal gotos.  */
name|rtx
name|x_nonlocal_goto_handler_labels
decl_stmt|;
comment|/* Label that will go on function epilogue.      Jumping to this label serves as a "return" instruction      on machines which require execution of the epilogue on all returns.  */
name|rtx
name|x_return_label
decl_stmt|;
comment|/* Label that will go on the end of function epilogue.      Jumping to this label serves as a "naked return" instruction      on machines which require execution of the epilogue on all returns.  */
name|rtx
name|x_naked_return_label
decl_stmt|;
comment|/* List (chain of EXPR_LISTs) of all stack slots in this function.      Made for the sake of unshare_all_rtl.  */
name|rtx
name|x_stack_slot_list
decl_stmt|;
comment|/* Place after which to insert the tail_recursion_label if we need one.  */
name|rtx
name|x_stack_check_probe_note
decl_stmt|;
comment|/* Location at which to save the argument pointer if it will need to be      referenced.  There are two cases where this is done: if nonlocal gotos      exist, or if vars stored at an offset from the argument pointer will be      needed by inner routines.  */
name|rtx
name|x_arg_pointer_save_area
decl_stmt|;
comment|/* APPLE LOCAL begin radar 6411649 */
comment|/* Holds a unique number for this function. It is used to      generate block number for block names. */
name|int
name|unqiue_block_number
decl_stmt|;
comment|/* APPLE LOCAL end radar 6411649 */
comment|/* Offset to end of allocated area of stack frame.      If stack grows down, this is the address of the last stack slot allocated.      If stack grows up, this is the address for the next slot.  */
name|HOST_WIDE_INT
name|x_frame_offset
decl_stmt|;
comment|/* A PARM_DECL that should contain the static chain for this function.      It will be initialized at the beginning of the function.  */
name|tree
name|static_chain_decl
decl_stmt|;
comment|/* An expression that contains the non-local goto save area.  The first      word is the saved frame pointer and the second is the saved stack       pointer.  */
name|tree
name|nonlocal_goto_save_area
decl_stmt|;
comment|/* Insn after which register parms and SAVE_EXPRs are born, if nonopt.  */
name|rtx
name|x_parm_birth_insn
decl_stmt|;
comment|/* List of all used temporaries allocated, by level.  */
name|VEC
argument_list|(
name|temp_slot_p
argument_list|,
name|gc
argument_list|)
operator|*
name|x_used_temp_slots
expr_stmt|;
comment|/* List of available temp slots.  */
name|struct
name|temp_slot
modifier|*
name|x_avail_temp_slots
decl_stmt|;
comment|/* This slot is initialized as 0 and is added to      during the nested function.  */
name|struct
name|var_refs_queue
modifier|*
name|fixup_var_refs_queue
decl_stmt|;
comment|/* Current nesting level for temporaries.  */
name|int
name|x_temp_slot_level
decl_stmt|;
comment|/* Highest label number in current function.  */
name|int
name|inl_max_label_num
decl_stmt|;
comment|/* Function sequence number for profiling, debugging, etc.  */
name|int
name|funcdef_no
decl_stmt|;
comment|/* For flow.c.  */
comment|/* Highest loop depth seen so far in loop analysis.  Used in flow.c      for the "failure strategy" when doing liveness analysis starting      with non-empty initial sets.  */
name|int
name|max_loop_depth
decl_stmt|;
comment|/* For md files.  */
comment|/* tm.h can use this to store whatever it likes.  */
name|struct
name|machine_function
modifier|*
name|GTY
argument_list|(
operator|(
name|maybe_undef
operator|)
argument_list|)
name|machine
decl_stmt|;
comment|/* The largest alignment of slot allocated on the stack.  */
name|unsigned
name|int
name|stack_alignment_needed
decl_stmt|;
comment|/* Preferred alignment of the end of stack frame.  */
name|unsigned
name|int
name|preferred_stack_boundary
decl_stmt|;
comment|/* Language-specific code can use this to store whatever it likes.  */
name|struct
name|language_function
modifier|*
name|language
decl_stmt|;
comment|/* Used types hash table.  */
name|htab_t
name|GTY
argument_list|(
operator|(
name|param_is
argument_list|(
expr|union
name|tree_node
argument_list|)
operator|)
argument_list|)
name|used_types_hash
decl_stmt|;
comment|/* For reorg.  */
comment|/* If some insns can be deferred to the delay slots of the epilogue, the      delay list for them is recorded here.  */
name|rtx
name|epilogue_delay_list
decl_stmt|;
comment|/* Maximal number of entities in the single jumptable.  Used to estimate      final flowgraph size.  */
name|int
name|max_jumptable_ents
decl_stmt|;
comment|/* UIDs for LABEL_DECLs.  */
name|int
name|last_label_uid
decl_stmt|;
comment|/* Line number of the end of the function.  */
name|location_t
name|function_end_locus
decl_stmt|;
comment|/* Array mapping insn uids to blocks.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|ib_boundaries_block
expr_stmt|;
comment|/* The variables unexpanded so far.  */
name|tree
name|unexpanded_var_list
decl_stmt|;
comment|/* Assembly labels for the hot and cold text sections, to      be used by debugger functions for determining the size of text      sections.  */
specifier|const
name|char
modifier|*
name|hot_section_label
decl_stmt|;
specifier|const
name|char
modifier|*
name|cold_section_label
decl_stmt|;
specifier|const
name|char
modifier|*
name|hot_section_end_label
decl_stmt|;
specifier|const
name|char
modifier|*
name|cold_section_end_label
decl_stmt|;
comment|/* String to be used for name of cold text sections, via      targetm.asm_out.named_section.  */
specifier|const
name|char
modifier|*
name|unlikely_text_section_name
decl_stmt|;
comment|/* A variable living at the top of the frame that holds a known value.      Used for detecting stack clobbers.  */
name|tree
name|stack_protect_guard
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
comment|/* Nonzero if function being compiled can call setjmp.  */
name|unsigned
name|int
name|calls_setjmp
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
comment|/* Nonzero if function being compiled called builtin_return_addr or      builtin_frame_address with nonzero count.  */
name|unsigned
name|int
name|accesses_prior_frames
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
comment|/* Nonzero if the current function is a thunk, i.e., a lightweight      function implemented by the output_mi_thunk hook) that just      adjusts one of its arguments and forwards to another      function.  */
name|unsigned
name|int
name|is_thunk
range|:
literal|1
decl_stmt|;
comment|/* This bit is used by the exception handling logic.  It is set if all      calls (if any) are sibling calls.  Such functions do not have to      have EH tables generated, as they cannot throw.  A call to such a      function, however, should be treated as throwing if any of its callees      can throw.  */
name|unsigned
name|int
name|all_throwers_are_sibcalls
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
comment|/* Nonzero if current function uses stdarg.h or equivalent.  */
name|unsigned
name|int
name|stdarg
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
comment|/* Nonzero if code to initialize arg_pointer_save_area has been emitted.  */
name|unsigned
name|int
name|arg_pointer_save_area_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|after_inlining
range|:
literal|1
decl_stmt|;
comment|/* Set when the call to function itself has been emit.  */
name|unsigned
name|int
name|recursive_call_emit
range|:
literal|1
decl_stmt|;
comment|/* Set when the tail call has been produced.  */
name|unsigned
name|int
name|tail_call_emit
range|:
literal|1
decl_stmt|;
comment|/* How commonly executed the function is.  Initialized during branch      probabilities pass.  */
name|ENUM_BITFIELD
argument_list|(
argument|function_frequency
argument_list|)
name|function_frequency
label|:
literal|2
expr_stmt|;
comment|/* Number of units of general registers that need saving in stdarg      function.  What unit is depends on the backend, either it is number      of bytes, or it can be number of registers.  */
name|unsigned
name|int
name|va_list_gpr_size
range|:
literal|8
decl_stmt|;
comment|/* Number of units of floating point registers that need saving in stdarg      function.  */
name|unsigned
name|int
name|va_list_fpr_size
range|:
literal|8
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* If va_list_[gf]pr_size is set to this, it means we don't know how    many units need to be saved.  */
end_comment

begin_define
define|#
directive|define
name|VA_LIST_MAX_GPR_SIZE
value|255
end_define

begin_define
define|#
directive|define
name|VA_LIST_MAX_FPR_SIZE
value|255
end_define

begin_comment
comment|/* The function currently being compiled.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|function
modifier|*
name|cfun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to chain of `struct function' for containing functions.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|function
modifier|*
name|outer_function_chain
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
comment|/* Nonzero if at least one trampoline has been created.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|trampolines_created
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For backward compatibility... eventually these should all go away.  */
end_comment

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
name|current_function_accesses_prior_frames
value|(cfun->accesses_prior_frames)
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
name|current_function_profile
value|(cfun->profile)
end_define

begin_define
define|#
directive|define
name|current_function_funcdef_no
value|(cfun->funcdef_no)
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
name|return_label
value|(cfun->x_return_label)
end_define

begin_define
define|#
directive|define
name|naked_return_label
value|(cfun->x_naked_return_label)
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
name|stack_check_probe_note
value|(cfun->x_stack_check_probe_note)
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
name|used_temp_slots
value|(cfun->x_used_temp_slots)
end_define

begin_define
define|#
directive|define
name|avail_temp_slots
value|(cfun->x_avail_temp_slots)
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
name|nonlocal_goto_handler_labels
value|(cfun->x_nonlocal_goto_handler_labels)
end_define

begin_comment
comment|/* Given a function decl for a containing function,    return the `struct function' for it.  */
end_comment

begin_function_decl
name|struct
name|function
modifier|*
name|find_function_data
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Identify BLOCKs referenced by more than one NOTE_INSN_BLOCK_{BEG,END},    and create duplicate blocks.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|reorder_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set BLOCK_NUMBER for all the blocks in FN.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|number_blocks
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_block_marks
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|blocks_nreverse
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reset_block_changes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_block_change
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finalize_block_changes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_block_change
parameter_list|(
name|rtx
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_block_changes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return size needed for stack frame based on slots so far allocated.    This size counts from zero.  It is not rounded to STACK_BOUNDARY;    the caller may have to do that.  */
end_comment

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|get_frame_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Issue an error message and return TRUE if frame OFFSET overflows in    the signed target pointer arithmetics for function FUNC.  Otherwise    return FALSE.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|frame_offset_overflow
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A pointer to a function to create target specific, per-function    data structures.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|machine_function
modifier|*
function_decl|(
modifier|*
name|init_machine_status
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Save and restore status information for a nested function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|free_after_parsing
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_after_compilation
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_varasm_status
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|diddle_return_value
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clobber_return_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|rtx
name|get_arg_pointer_save_area
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the name of the current function.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|current_function_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_warn_unused_parameter
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|pass_by_reference
parameter_list|(
name|CUMULATIVE_ARGS
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|reference_callee_copied
parameter_list|(
name|CUMULATIVE_ARGS
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|used_types_insert
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL radar 5732232 - blocks */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|block_sema_info
modifier|*
name|cur_block
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_FUNCTION_H */
end_comment

end_unit

