begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Callgraph handling code.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Jan Hubicka  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CGRAPH_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CGRAPH_H
end_define

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_enum
enum|enum
name|availability
block|{
comment|/* Not yet set by cgraph_function_body_availability.  */
name|AVAIL_UNSET
block|,
comment|/* Function body/variable initializer is unknown.  */
name|AVAIL_NOT_AVAILABLE
block|,
comment|/* Function body/variable initializer is known but might be replaced      by a different one from other compilation unit and thus needs to      be dealt with a care.  Like AVAIL_NOT_AVAILABLE it can have      arbitrary side effects on escaping variables and functions, while      like AVAILABLE it might access static variables.  */
name|AVAIL_OVERWRITABLE
block|,
comment|/* Function body/variable initializer is known and will be used in final      program.  */
name|AVAIL_AVAILABLE
block|,
comment|/* Function body/variable initializer is known and all it's uses are explicitly      visible within current unit (ie it's address is never taken and it is not      exported to other units).      Currently used only for functions.  */
name|AVAIL_LOCAL
block|}
enum|;
end_enum

begin_comment
comment|/* Information about the function collected locally.    Available after function is analyzed.  */
end_comment

begin_decl_stmt
name|struct
name|cgraph_local_info
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Size of the function before inlining.  */
name|int
name|self_insns
decl_stmt|;
comment|/* Set when function function is visible in current compilation unit only      and its address is never taken.  */
name|unsigned
name|local
range|:
literal|1
decl_stmt|;
comment|/* Set when function is visible by other units.  */
name|unsigned
name|externally_visible
range|:
literal|1
decl_stmt|;
comment|/* Set once it has been finalized so we consider it to be output.  */
name|unsigned
name|finalized
range|:
literal|1
decl_stmt|;
comment|/* False when there something makes inlining impossible (such as va_arg).  */
name|unsigned
name|inlinable
range|:
literal|1
decl_stmt|;
comment|/* True when function should be inlined independently on its size.  */
name|unsigned
name|disregard_inline_limits
range|:
literal|1
decl_stmt|;
comment|/* True when the function has been originally extern inline, but it is      redefined now.  */
name|unsigned
name|redefined_extern_inline
range|:
literal|1
decl_stmt|;
comment|/* True if statics_read_for_function and      statics_written_for_function contain valid data.  */
name|unsigned
name|for_functions_valid
range|:
literal|1
decl_stmt|;
comment|/* True if the function is going to be emitted in some other translation      unit, referenced from vtable.  */
name|unsigned
name|vtable_method
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Information about the function that needs to be computed globally    once compilation is finished.  Available only with -funit-at-time.  */
end_comment

begin_decl_stmt
name|struct
name|cgraph_global_info
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* For inline clones this points to the function they will be inlined into.  */
name|struct
name|cgraph_node
modifier|*
name|inlined_to
decl_stmt|;
comment|/* Estimated size of the function after inlining.  */
name|int
name|insns
decl_stmt|;
comment|/* Estimated growth after inlining.  INT_MIN if not computed.  */
name|int
name|estimated_growth
decl_stmt|;
comment|/* Set iff the function has been inlined at least once.  */
name|bool
name|inlined
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Information about the function that is propagated by the RTL backend.    Available only for functions that has been already assembled.  */
end_comment

begin_decl_stmt
name|struct
name|cgraph_rtl_info
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|int
name|preferred_incoming_stack_boundary
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The cgraph data structure.    Each function decl has assigned cgraph_node listing callees and callers.  */
end_comment

begin_decl_stmt
name|struct
name|cgraph_node
name|GTY
argument_list|(
operator|(
name|chain_next
argument_list|(
literal|"%h.next"
argument_list|)
operator|,
name|chain_prev
argument_list|(
literal|"%h.previous"
argument_list|)
operator|)
argument_list|)
block|{
name|tree
name|decl
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|callees
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|callers
decl_stmt|;
name|struct
name|cgraph_node
modifier|*
name|next
decl_stmt|;
name|struct
name|cgraph_node
modifier|*
name|previous
decl_stmt|;
comment|/* For nested functions points to function the node is nested in.  */
name|struct
name|cgraph_node
modifier|*
name|origin
decl_stmt|;
comment|/* Points to first nested function, if any.  */
name|struct
name|cgraph_node
modifier|*
name|nested
decl_stmt|;
comment|/* Pointer to the next function with same origin, if any.  */
name|struct
name|cgraph_node
modifier|*
name|next_nested
decl_stmt|;
comment|/* Pointer to the next function in cgraph_nodes_queue.  */
name|struct
name|cgraph_node
modifier|*
name|next_needed
decl_stmt|;
comment|/* Pointer to the next clone.  */
name|struct
name|cgraph_node
modifier|*
name|next_clone
decl_stmt|;
name|struct
name|cgraph_node
modifier|*
name|prev_clone
decl_stmt|;
comment|/* Pointer to a single unique cgraph node for this function.  If the      function is to be output, this is the copy that will survive.  */
name|struct
name|cgraph_node
modifier|*
name|master_clone
decl_stmt|;
comment|/* For functions with many calls sites it holds map from call expression      to the edge to speed up cgraph_edge function.  */
name|htab_t
name|GTY
argument_list|(
operator|(
name|param_is
argument_list|(
expr|struct
name|cgraph_edge
argument_list|)
operator|)
argument_list|)
name|call_site_hash
decl_stmt|;
name|PTR
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|aux
decl_stmt|;
name|struct
name|cgraph_local_info
name|local
decl_stmt|;
name|struct
name|cgraph_global_info
name|global
decl_stmt|;
name|struct
name|cgraph_rtl_info
name|rtl
decl_stmt|;
comment|/* Expected number of executions: calculated in profile.c.  */
name|gcov_type
name|count
decl_stmt|;
comment|/* Unique id of the node.  */
name|int
name|uid
decl_stmt|;
comment|/* Ordering of all cgraph nodes.  */
name|int
name|order
decl_stmt|;
comment|/* Set when function must be output - it is externally visible      or its address is taken.  */
name|unsigned
name|needed
range|:
literal|1
decl_stmt|;
comment|/* Set when function is reachable by call from other function      that is either reachable or needed.  */
name|unsigned
name|reachable
range|:
literal|1
decl_stmt|;
comment|/* Set once the function is lowered (i.e. its CFG is built).  */
name|unsigned
name|lowered
range|:
literal|1
decl_stmt|;
comment|/* Set once the function has been instantiated and its callee      lists created.  */
name|unsigned
name|analyzed
range|:
literal|1
decl_stmt|;
comment|/* Set when function is scheduled to be assembled.  */
name|unsigned
name|output
range|:
literal|1
decl_stmt|;
comment|/* Set for aliases once they got through assemble_alias.  */
name|unsigned
name|alias
range|:
literal|1
decl_stmt|;
comment|/* In non-unit-at-a-time mode the function body of inline candidates is saved      into clone before compiling so the function in original form can be      inlined later.  This pointer points to the clone.  */
name|tree
name|inline_decl
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|cgraph_edge
name|GTY
argument_list|(
operator|(
name|chain_next
argument_list|(
literal|"%h.next_caller"
argument_list|)
operator|,
name|chain_prev
argument_list|(
literal|"%h.prev_caller"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|cgraph_node
modifier|*
name|caller
decl_stmt|;
name|struct
name|cgraph_node
modifier|*
name|callee
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|prev_caller
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|next_caller
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|prev_callee
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|next_callee
decl_stmt|;
name|tree
name|call_stmt
decl_stmt|;
name|PTR
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|aux
decl_stmt|;
comment|/* When NULL, inline this call.  When non-NULL, points to the explanation      why function was not inlined.  */
specifier|const
name|char
modifier|*
name|inline_failed
decl_stmt|;
comment|/* Expected number of executions: calculated in profile.c.  */
name|gcov_type
name|count
decl_stmt|;
comment|/* Depth of loop nest, 1 means no loop nest.  */
name|int
name|loop_nest
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|cgraph_edge
modifier|*
name|cgraph_edge_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|cgraph_edge_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|cgraph_edge_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The cgraph_varpool data structure.    Each static variable decl has assigned cgraph_varpool_node.  */
end_comment

begin_decl_stmt
name|struct
name|cgraph_varpool_node
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|tree
name|decl
decl_stmt|;
comment|/* Pointer to the next function in cgraph_varpool_nodes.  */
name|struct
name|cgraph_varpool_node
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to the next function in cgraph_varpool_nodes_queue.  */
name|struct
name|cgraph_varpool_node
modifier|*
name|next_needed
decl_stmt|;
comment|/* Ordering of all cgraph nodes.  */
name|int
name|order
decl_stmt|;
comment|/* Set when function must be output - it is externally visible      or its address is taken.  */
name|unsigned
name|needed
range|:
literal|1
decl_stmt|;
comment|/* Needed variables might become dead by optimization.  This flag      forces the variable to be output even if it appears dead otherwise.  */
name|unsigned
name|force_output
range|:
literal|1
decl_stmt|;
comment|/* Set once the variable has been instantiated and its callee      lists created.  */
name|unsigned
name|analyzed
range|:
literal|1
decl_stmt|;
comment|/* Set once it has been finalized so we consider it to be output.  */
name|unsigned
name|finalized
range|:
literal|1
decl_stmt|;
comment|/* Set when variable is scheduled to be assembled.  */
name|unsigned
name|output
range|:
literal|1
decl_stmt|;
comment|/* Set when function is visible by other units.  */
name|unsigned
name|externally_visible
range|:
literal|1
decl_stmt|;
comment|/* Set for aliases once they got through assemble_alias.  */
name|unsigned
name|alias
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Every top level asm statement is put into a cgraph_asm_node.  */
end_comment

begin_decl_stmt
name|struct
name|cgraph_asm_node
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Next asm node.  */
name|struct
name|cgraph_asm_node
modifier|*
name|next
decl_stmt|;
comment|/* String for this asm node.  */
name|tree
name|asm_str
decl_stmt|;
comment|/* Ordering of all cgraph nodes.  */
name|int
name|order
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_node
modifier|*
name|cgraph_nodes
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|int
name|cgraph_n_nodes
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|int
name|cgraph_max_uid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|cgraph_global_info_ready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|cgraph_function_flags_ready
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_node
modifier|*
name|cgraph_nodes_queue
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_node
modifier|*
name|cgraph_expand_queue
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_first_unanalyzed_node
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_last_needed_node
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_nodes_queue
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_nodes
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|cgraph_asm_node
modifier|*
name|cgraph_asm_nodes
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|int
name|cgraph_order
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cgraph.c  */
end_comment

begin_function_decl
name|void
name|dump_cgraph
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_cgraph_node
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_insert_node_to_hashtable
parameter_list|(
name|struct
name|cgraph_node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_varpool
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_cgraph_varpool_node
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|cgraph_varpool_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_remove_edge
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_remove_node
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_node_remove_callees
parameter_list|(
name|struct
name|cgraph_node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_edge
modifier|*
name|cgraph_create_edge
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|gcov_type
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|cgraph_node
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|cgraph_node_for_asm
parameter_list|(
name|tree
name|asmname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_edge
modifier|*
name|cgraph_edge
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_set_call_stmt
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_local_info
modifier|*
name|cgraph_local_info
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_global_info
modifier|*
name|cgraph_global_info
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_rtl_info
modifier|*
name|cgraph_rtl_info
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|cgraph_node_name
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_edge
modifier|*
name|cgraph_clone_edge
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|gcov_type
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|cgraph_clone_node
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|gcov_type
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_node
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_node_for_asm
parameter_list|(
name|tree
name|asmname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_varpool_mark_needed_node
parameter_list|(
name|struct
name|cgraph_varpool_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_varpool_finalize_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_redirect_edge_callee
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_asm_node
modifier|*
name|cgraph_add_asm_node
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_function_possibly_inlined_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_unnest_node
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_varpool_enqueue_needed_node
parameter_list|(
name|struct
name|cgraph_varpool_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_varpool_reset_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decide_is_variable_needed
parameter_list|(
name|struct
name|cgraph_varpool_node
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|availability
name|cgraph_function_body_availability
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|availability
name|cgraph_variable_initializer_availability
parameter_list|(
name|struct
name|cgraph_varpool_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_is_master_clone
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|cgraph_master_clone
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_add_new_function
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cgraphunit.c  */
end_comment

begin_comment
comment|/* APPLE LOCAL radar 6305545 */
end_comment

begin_function_decl
name|void
name|lower_if_nested_functions
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_assemble_pending_functions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_varpool_assemble_pending_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_finalize_function
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_finalize_compilation_unit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_optimize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_mark_needed_node
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_mark_reachable_node
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_inline_p
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_preserve_function_body_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_cgraph
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_cgraph_node
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_build_static_cdtor
parameter_list|(
name|char
name|which
parameter_list|,
name|tree
name|body
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_reset_static_var_maps
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_cgraph
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|cgraph_node
modifier|*
name|cgraph_function_versioning
argument_list|(
expr|struct
name|cgraph_node
operator|*
argument_list|,
name|VEC
argument_list|(
name|cgraph_edge_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|,
name|varray_type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cgraph_analyze_function
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|save_inline_function_body
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ipa.c  */
end_comment

begin_function_decl
name|bool
name|cgraph_remove_unreachable_nodes
parameter_list|(
name|bool
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgraph_postorder
parameter_list|(
name|struct
name|cgraph_node
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ipa-inline.c  */
end_comment

begin_function_decl
name|bool
name|cgraph_decide_inlining_incrementally
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_clone_inlined_nodes
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cgraph_mark_inline_edge
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_default_inline_p
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_CGRAPH_H  */
end_comment

end_unit

