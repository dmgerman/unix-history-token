begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Exception Handling interface routines.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Mike Stump<mrs@cygnus.com>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NULL_RTX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|rtx
argument_list|)
end_if

begin_typedef
typedef|typedef
name|struct
name|rtx_def
modifier|*
name|_except_rtx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rtx
value|_except_rtx
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* A stack of labels. CHAIN points to the next entry in the stack.  */
end_comment

begin_struct
struct|struct
name|label_node
block|{
union|union
block|{
name|rtx
name|rlabel
decl_stmt|;
name|tree
name|tlabel
decl_stmt|;
block|}
name|u
union|;
name|struct
name|label_node
modifier|*
name|chain
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An eh_entry is used to describe one exception handling region.     OUTER_CONTEXT is the label used for rethrowing into the outer context.     EXCEPTION_HANDLER_LABEL is the label corresponding to the handler    for this region.     LABEL_USED indicates whether a CATCH block has already used this    label or not. New ones are needed for additional catch blocks if    it has.     FINALIZATION is the tree codes for the handler, or is NULL_TREE if    one hasn't been generated yet, or is integer_zero_node to mark the    end of a group of try blocks.  */
end_comment

begin_struct
struct|struct
name|eh_entry
block|{
name|rtx
name|outer_context
decl_stmt|;
name|rtx
name|exception_handler_label
decl_stmt|;
name|tree
name|finalization
decl_stmt|;
name|int
name|label_used
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A list of EH_ENTRYs. ENTRY is the entry; CHAIN points to the next    entry in the list, or is NULL if this is the last entry.  */
end_comment

begin_struct
struct|struct
name|eh_node
block|{
name|struct
name|eh_entry
modifier|*
name|entry
decl_stmt|;
name|struct
name|eh_node
modifier|*
name|chain
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A stack of EH_ENTRYs. TOP is the topmost entry on the stack. TOP is    NULL if the stack is empty.  */
end_comment

begin_struct
struct|struct
name|eh_stack
block|{
name|struct
name|eh_node
modifier|*
name|top
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A queue of EH_ENTRYs. HEAD is the front of the queue; TAIL is the    end (the latest entry). HEAD and TAIL are NULL if the queue is    empty.  */
end_comment

begin_struct
struct|struct
name|eh_queue
block|{
name|struct
name|eh_node
modifier|*
name|head
decl_stmt|;
name|struct
name|eh_node
modifier|*
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Start an exception handling region.  All instructions emitted after    this point are considered to be part of the region until    expand_eh_region_end () is invoked.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_eh_region_start
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Just like expand_eh_region_start, except if a cleanup action is    entered on the cleanup chain, the TREE_PURPOSE of the element put    on the chain is DECL.  DECL should be the associated VAR_DECL, if    any, otherwise it should be NULL_TREE.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_eh_region_start_for_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start an exception handling region for the given cleanup action.    All instructions emitted after this point are considered to be part    of the region until expand_eh_region_end () is invoked.  CLEANUP is    the cleanup action to perform.  The return value is true if the    exception region was optimized away.  If that case,    expand_eh_region_end does not need to be called for this cleanup,    nor should it be.     This routine notices one particular common case in C++ code    generation, and optimizes it so as to not need the exception    region.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|expand_eh_region_start_tree
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End an exception handling region.  The information about the region    is found on the top of ehstack.     HANDLER is either the cleanup for the exception region, or if we're    marking the end of a try block, HANDLER is integer_zero_node.     HANDLER will be transformed to rtl when expand_leftover_cleanups ()    is invoked.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_eh_region_end
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Push RLABEL or TLABEL onto LABELSTACK. Only one of RLABEL or TLABEL    should be set; the other must be NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|push_label_entry
name|PROTO
argument_list|(
operator|(
expr|struct
name|label_node
operator|*
operator|*
name|labelstack
operator|,
name|rtx
name|rlabel
operator|,
name|tree
name|tlabel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop the topmost entry from LABELSTACK and return its value as an    rtx node. If LABELSTACK is empty, return NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|pop_label_entry
name|PROTO
argument_list|(
operator|(
expr|struct
name|label_node
operator|*
operator|*
name|labelstack
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the topmost entry of LABELSTACK as a tree node, or return    NULL_TREE if LABELSTACK is empty.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|top_label_entry
name|PROTO
argument_list|(
operator|(
expr|struct
name|label_node
operator|*
operator|*
name|labelstack
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A set of insns for the catch clauses in the current function. They    will be emitted at the end of the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|catch_clauses
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test: is exception handling turned on? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doing_eh
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Toplevel initialization for EH.  */
end_comment

begin_decl_stmt
name|void
name|set_exception_lang_code
name|PROTO
argument_list|(
operator|(
name|short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_exception_version_code
name|PROTO
argument_list|(
operator|(
name|short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of handlers asocciated with an exception region. HANDLER_LABEL    is the the label that control should be transfered to if the data    in TYPE_INFO matches an exception. a value of NULL_TREE for TYPE_INFO    means This is a cleanup, and must always be called. A value of    CATCH_ALL_TYPE works like a cleanup, but a call to the runtime matcher    is still performed to avoid being caught by a different language    exception. NEXT is a pointer to the next handler for this region.     NULL means there are no more. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|handler_info
block|{
name|rtx
name|handler_label
decl_stmt|;
name|void
modifier|*
name|type_info
decl_stmt|;
name|struct
name|handler_info
modifier|*
name|next
decl_stmt|;
block|}
name|handler_info
typedef|;
end_typedef

begin_comment
comment|/* Add a new eh_entry for this function, The parameter specifies what    exception region number NOTE insns use to delimit this range.     The integer returned is uniquely identifies this exception range    within an internal table. */
end_comment

begin_decl_stmt
name|int
name|new_eh_region_entry
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add new handler information to an exception range. The  first parameter    specifies the range number (returned from new_eh_entry()). The second    parameter specifies the handler.  By default the handler is inserted at    the end of the list. A handler list may contain only ONE NULL_TREE    typeinfo entry. Regardless where it is positioned, a NULL_TREE entry    is always output as the LAST handler in the exception table for a region. */
end_comment

begin_decl_stmt
name|void
name|add_new_handler
name|PROTO
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|handler_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove a handler label. The handler label is being deleted, so all    regions which reference this handler should have it removed from their    list of possible handlers. Any region which has the final handler    removed can be deleted. */
end_comment

begin_decl_stmt
name|void
name|remove_handler
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a new handler structure initialized with the handler label and    typeinfo fields passed in. */
end_comment

begin_decl_stmt
name|struct
name|handler_info
modifier|*
name|get_new_handler
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a duplicate of an exception region by copying all the handlers    for an exception region. Return the new handler index. */
end_comment

begin_decl_stmt
name|int
name|duplicate_handlers
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a pointer to the first handler in an exception region's list. */
end_comment

begin_decl_stmt
name|struct
name|handler_info
modifier|*
name|get_first_handler
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find all the runtime handlers type matches currently referenced */
end_comment

begin_decl_stmt
name|int
name|find_all_handler_type_matches
name|PROTO
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_eh
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialization for the per-function EH data.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_eh_for_function
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate an exception label. Use instead of gen_label_rtx */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_exception_label
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Adds an EH table entry for EH entry number N. Called from    final_scan_insn for NOTE_INSN_EH_REGION_BEG.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_eh_table_entry
name|PROTO
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start a catch clause, triggered by runtime value paramter. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|start_catch_handler
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Returns a non-zero value if we need to output an exception table.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exception_table_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Outputs the exception table if we have one.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_exception_table
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a return address in ADDR, determine the address we should use    to find the corresponding EH region.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|eh_outer_context
name|PROTO
argument_list|(
operator|(
name|rtx
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called at the start of a block of try statements for which there is    a supplied catch handler.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_start_try_stmts
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called at the start of a block of catch statements. It terminates the    previous set of try statements.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_start_all_catch
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called at the end of a block of catch statements.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_end_all_catch
name|PROTO
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
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Create a new exception region and add the handler for the region    onto a list. These regions will be ended (and their handlers    emitted) when end_protect_partials is invoked.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_partial_entry
name|PROTO
argument_list|(
operator|(
name|tree
name|handler
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End all of the pending exception regions that have handlers added with    push_protect_entry ().  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|end_protect_partials
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An internal throw.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_internal_throw
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called from expand_exception_blocks and expand_end_catch_block to    expand and pending handlers.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_leftover_cleanups
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If necessary, emit insns to get EH context for the current    function. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_eh_context
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Builds a list of handler labels and puts them in the global    variable exception_handler_labels.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|find_exception_handler_labels
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine if an arbitrary label is an exception label */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|is_exception_handler_label
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Performs sanity checking on the check_exception_handler_labels    list.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|check_exception_handler_labels
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A stack used to keep track of the label used to resume normal program    flow out of the current exception handler region.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|label_node
modifier|*
name|caught_return_label_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keeps track of the label used as the context of a throw to rethrow an    exception to the outer exception region.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|label_node
modifier|*
name|outer_context_label_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A random area used for purposes elsewhere.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|label_node
modifier|*
name|false_label_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of labels used for exception handlers. It is created by    find_exception_handler_labels for the optimization passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|exception_handler_labels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Performs optimizations for exception handling, such as removing    unnecessary exception regions. Invoked from jump_optimize ().  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|exception_optimize
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return EH context (and set it up once per fn).  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_eh_context
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the dynamic handler chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_dynamic_handler_chain
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the dynamic cleanup chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_dynamic_cleanup_chain
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Throw an exception.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_throw
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One to use setjmp/longjmp method of generating code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exceptions_via_longjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One to enable asynchronous exception support.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|asynchronous_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One to protect cleanup actions with a handler that calls    __terminate, zero otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|protect_cleanup_actions_with_terminate
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_decl_stmt
specifier|extern
name|tree
name|protect_with_terminate
name|PROTO
argument_list|(
operator|(
name|tree
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
name|expand_fixup_region_start
name|PROTO
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
name|TREE_CODE
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|expand_fixup_region_end
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Various hooks for the DWARF 2 __throw routine.  */
end_comment

begin_decl_stmt
name|void
name|expand_builtin_unwind_init
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|expand_builtin_dwarf_fp_regnum
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|expand_builtin_eh_stub
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|expand_builtin_eh_stub_old
name|PROTO
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
name|TREE_CODE
end_ifdef

begin_decl_stmt
name|rtx
name|expand_builtin_frob_return_addr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|expand_builtin_extract_return_addr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|expand_builtin_set_return_addr_reg
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|expand_builtin_set_eh_regs
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|expand_builtin_dwarf_reg_size
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Checking whether 2 instructions are within the same exception region. */
end_comment

begin_decl_stmt
name|int
name|in_same_eh_region
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_insn_eh_region
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_insn_eh_region
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

end_unit

