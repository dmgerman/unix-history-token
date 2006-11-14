begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Callgraph handling code.    Copyright (C) 2003, 2004 Free Software Foundation, Inc.    Contributed by Jan Hubicka  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Set when function function is visible in current compilation unit only      and it's address is never taken.  */
name|bool
name|local
decl_stmt|;
comment|/* Set once it has been finalized so we consider it to be output.  */
name|bool
name|finalized
decl_stmt|;
comment|/* False when there something makes inlining impossible (such as va_arg).  */
name|bool
name|inlinable
decl_stmt|;
comment|/* True when function should be inlined independently on it's size.  */
name|bool
name|disregard_inline_limits
decl_stmt|;
comment|/* True when the function has been originally extern inline, but it is      redefined now.  */
name|bool
name|redefined_extern_inline
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
comment|/* Estimated size of the function after inlining.  */
name|int
name|insns
decl_stmt|;
comment|/* Number of times given function will be cloned during output.  */
name|int
name|cloned_times
decl_stmt|;
comment|/* Set when the function will be inlined exactly once.  */
name|bool
name|inline_once
decl_stmt|;
comment|/* Set to true for all reachable functions before inlining is decided.      Once we inline all calls to the function and the function is local,      it is set to false.  */
name|bool
name|will_be_output
decl_stmt|;
comment|/* Set iff at least one of the caller edges has inline_call flag set.  */
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
name|bool
name|const_function
decl_stmt|;
name|bool
name|pure_function
decl_stmt|;
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
comment|/* Unique id of the node.  */
name|int
name|uid
decl_stmt|;
comment|/* Set when function must be output - it is externally visible      or it's address is taken.  */
name|bool
name|needed
decl_stmt|;
comment|/* Set when function is reachable by call from other function      that is either reachable or needed.  */
name|bool
name|reachable
decl_stmt|;
comment|/* Set once the function has been instantiated and its callee      lists created.  */
name|bool
name|analyzed
decl_stmt|;
comment|/* Set when function is scheduled to be assembled.  */
name|bool
name|output
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
name|next_caller
decl_stmt|;
name|struct
name|cgraph_edge
modifier|*
name|next_callee
decl_stmt|;
comment|/* When NULL, inline this call.  When non-NULL, points to the explanation      why function was not inlined.  */
specifier|const
name|char
modifier|*
name|inline_failed
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
comment|/* Pointer to the next function in cgraph_varpool_nodes_queue.  */
name|struct
name|cgraph_varpool_node
modifier|*
name|next_needed
decl_stmt|;
comment|/* Set when function must be output - it is externally visible      or it's address is taken.  */
name|bool
name|needed
decl_stmt|;
comment|/* Set once it has been finalized so we consider it to be output.  */
name|bool
name|finalized
decl_stmt|;
comment|/* Set when function is scheduled to be assembled.  */
name|bool
name|output
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

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|cgraph_dump_file
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|int
name|cgraph_varpool_n_nodes
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
name|cgraph_remove_edge
parameter_list|(
name|struct
name|cgraph_node
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
name|cgraph_remove_call
parameter_list|(
name|tree
parameter_list|,
name|tree
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
name|struct
name|cgraph_edge
modifier|*
name|cgraph_record_call
parameter_list|(
name|tree
parameter_list|,
name|tree
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
name|decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|cgraph_node_for_identifier
parameter_list|(
name|tree
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cgraph_calls_p
parameter_list|(
name|tree
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
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_node
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_varpool_node
modifier|*
name|cgraph_varpool_node_for_identifier
parameter_list|(
name|tree
name|id
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
name|bool
name|cgraph_varpool_assemble_pending_decls
parameter_list|(
name|void
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

begin_comment
comment|/* In cgraphunit.c  */
end_comment

begin_function_decl
name|bool
name|cgraph_assemble_pending_functions
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
name|cgraph_create_edges
parameter_list|(
name|tree
parameter_list|,
name|tree
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
name|tree
parameter_list|,
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|reason
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

