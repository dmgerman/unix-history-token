begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Structure for saving state for a nested function.    Copyright (C) 1989, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_TREE
end_ifndef

begin_define
define|#
directive|define
name|tree
value|int *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_CODE
end_ifndef

begin_define
define|#
directive|define
name|rtx
value|int *
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_escape
end_escape

begin_comment
comment|/* This structure can save all the important global and static variables    describing the status of the current function.  */
end_comment

begin_struct
struct|struct
name|function
block|{
name|struct
name|function
modifier|*
name|next
decl_stmt|;
comment|/* For function.c.  */
name|char
modifier|*
name|name
decl_stmt|;
name|tree
name|decl
decl_stmt|;
name|int
name|pops_args
decl_stmt|;
name|int
name|returns_struct
decl_stmt|;
name|int
name|returns_pcc_struct
decl_stmt|;
name|int
name|needs_context
decl_stmt|;
name|int
name|calls_setjmp
decl_stmt|;
name|int
name|calls_longjmp
decl_stmt|;
name|int
name|calls_alloca
decl_stmt|;
name|int
name|has_nonlocal_label
decl_stmt|;
name|rtx
name|nonlocal_goto_handler_slot
decl_stmt|;
name|rtx
name|nonlocal_goto_stack_level
decl_stmt|;
name|tree
name|nonlocal_labels
decl_stmt|;
name|int
name|args_size
decl_stmt|;
name|int
name|pretend_args_size
decl_stmt|;
name|rtx
name|arg_offset_rtx
decl_stmt|;
name|int
name|max_parm_reg
decl_stmt|;
name|rtx
modifier|*
name|parm_reg_stack_loc
decl_stmt|;
name|int
name|outgoing_args_size
decl_stmt|;
name|rtx
name|return_rtx
decl_stmt|;
name|rtx
name|cleanup_label
decl_stmt|;
name|rtx
name|return_label
decl_stmt|;
name|rtx
name|save_expr_regs
decl_stmt|;
name|rtx
name|stack_slot_list
decl_stmt|;
name|rtx
name|parm_birth_insn
decl_stmt|;
name|int
name|frame_offset
decl_stmt|;
name|rtx
name|tail_recursion_label
decl_stmt|;
name|rtx
name|tail_recursion_reentry
decl_stmt|;
name|rtx
name|internal_arg_pointer
decl_stmt|;
name|rtx
name|arg_pointer_save_area
decl_stmt|;
name|tree
name|rtl_expr_chain
decl_stmt|;
name|rtx
name|last_parm_insn
decl_stmt|;
name|tree
name|context_display
decl_stmt|;
name|tree
name|trampoline_list
decl_stmt|;
name|int
name|function_call_count
decl_stmt|;
name|struct
name|temp_slot
modifier|*
name|temp_slots
decl_stmt|;
name|int
name|temp_slot_level
decl_stmt|;
comment|/* This slot is initialized as 0 and is added to      during the nested function.  */
name|struct
name|var_refs_queue
modifier|*
name|fixup_var_refs_queue
decl_stmt|;
comment|/* For stmt.c  */
name|struct
name|nesting
modifier|*
name|block_stack
decl_stmt|;
name|struct
name|nesting
modifier|*
name|stack_block_stack
decl_stmt|;
name|struct
name|nesting
modifier|*
name|cond_stack
decl_stmt|;
name|struct
name|nesting
modifier|*
name|loop_stack
decl_stmt|;
name|struct
name|nesting
modifier|*
name|case_stack
decl_stmt|;
name|struct
name|nesting
modifier|*
name|nesting_stack
decl_stmt|;
name|int
name|nesting_depth
decl_stmt|;
name|int
name|block_start_count
decl_stmt|;
name|tree
name|last_expr_type
decl_stmt|;
name|rtx
name|last_expr_value
decl_stmt|;
name|int
name|expr_stmts_for_value
decl_stmt|;
name|char
modifier|*
name|emit_filename
decl_stmt|;
name|int
name|emit_lineno
decl_stmt|;
name|struct
name|goto_fixup
modifier|*
name|goto_fixup_chain
decl_stmt|;
comment|/* For expr.c.  */
name|int
name|pending_stack_adjust
decl_stmt|;
name|int
name|inhibit_defer_pop
decl_stmt|;
name|tree
name|cleanups_this_call
decl_stmt|;
name|rtx
name|saveregs_value
decl_stmt|;
name|rtx
name|forced_labels
decl_stmt|;
comment|/* For emit-rtl.c.  */
name|int
name|reg_rtx_no
decl_stmt|;
name|int
name|first_label_num
decl_stmt|;
name|rtx
name|first_insn
decl_stmt|;
name|rtx
name|last_insn
decl_stmt|;
name|struct
name|sequence_stack
modifier|*
name|sequence_stack
decl_stmt|;
name|int
name|cur_insn_uid
decl_stmt|;
name|int
name|last_linenum
decl_stmt|;
name|char
modifier|*
name|last_filename
decl_stmt|;
name|char
modifier|*
name|regno_pointer_flag
decl_stmt|;
name|int
name|regno_pointer_flag_length
decl_stmt|;
name|rtx
modifier|*
name|regno_reg_rtx
decl_stmt|;
comment|/* For stor-layout.c.  */
name|tree
name|permanent_type_chain
decl_stmt|;
name|tree
name|temporary_type_chain
decl_stmt|;
name|tree
name|permanent_type_end
decl_stmt|;
name|tree
name|temporary_type_end
decl_stmt|;
name|tree
name|pending_sizes
decl_stmt|;
name|int
name|immediate_size_expand
decl_stmt|;
comment|/* For tree.c.  */
name|int
name|all_types_permanent
decl_stmt|;
name|struct
name|momentary_level
modifier|*
name|momentary_stack
decl_stmt|;
name|char
modifier|*
name|maybepermanent_firstobj
decl_stmt|;
name|char
modifier|*
name|temporary_firstobj
decl_stmt|;
name|char
modifier|*
name|momentary_firstobj
decl_stmt|;
name|struct
name|obstack
modifier|*
name|current_obstack
decl_stmt|;
name|struct
name|obstack
modifier|*
name|function_obstack
decl_stmt|;
name|struct
name|obstack
modifier|*
name|function_maybepermanent_obstack
decl_stmt|;
name|struct
name|obstack
modifier|*
name|expression_obstack
decl_stmt|;
name|struct
name|obstack
modifier|*
name|saveable_obstack
decl_stmt|;
name|struct
name|obstack
modifier|*
name|rtl_obstack
decl_stmt|;
comment|/* For integrate.c.  */
name|int
name|uses_const_pool
decl_stmt|;
comment|/* For md files.  */
name|int
name|uses_pic_offset_table
decl_stmt|;
comment|/* For reorg.  */
name|rtx
name|epilogue_delay_list
decl_stmt|;
comment|/* For varasm.  */
name|struct
name|constant_descriptor
modifier|*
modifier|*
name|const_rtx_hash_table
decl_stmt|;
name|struct
name|pool_sym
modifier|*
modifier|*
name|const_rtx_sym_hash_table
decl_stmt|;
name|struct
name|pool_constant
modifier|*
name|first_pool
decl_stmt|,
modifier|*
name|last_pool
decl_stmt|;
name|int
name|pool_offset
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* Label that will go on function epilogue.    Jumping to this label serves as a "return" instruction    on machines which require execution of the epilogue on all returns.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|return_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List (chain of EXPR_LISTs) of all stack slots in this function.    Made for the sake of unshare_all_rtl.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|stack_slot_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a function decl for a containing function,    return the `struct function' for it.  */
end_comment

begin_function_decl
name|struct
name|function
modifier|*
name|find_function_data
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Pointer to chain of `struct function' for containing functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|function
modifier|*
name|outer_function_chain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Put all this function's BLOCK nodes into a vector and return it.    Also store in each NOTE for the beginning or end of a block    the index of that block in the vector.  */
end_comment

begin_function_decl
name|tree
modifier|*
name|identify_blocks
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|rtx
end_ifdef

begin_undef
undef|#
directive|undef
name|rtx
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tree
end_ifdef

begin_undef
undef|#
directive|undef
name|tree
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

