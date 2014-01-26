begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Functions to analyze and validate GIMPLE trees.    Copyright (C) 2002, 2003, 2005 Free Software Foundation, Inc.    Contributed by Diego Novillo<dnovillo@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TREE_SIMPLE_H
end_ifndef

begin_define
define|#
directive|define
name|_TREE_SIMPLE_H
value|1
end_define

begin_include
include|#
directive|include
file|"tree-iterator.h"
end_include

begin_function_decl
specifier|extern
name|tree
name|create_tmp_var_raw
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|create_tmp_var_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|create_tmp_var
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_initialized_tmp_var
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_formal_tmp_var
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|declare_vars
parameter_list|(
name|tree
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
name|annotate_all_with_locus
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Validation of GIMPLE expressions.  Note that these predicates only check    the basic form of the expression, they don't recurse to make sure that    underlying nodes are also of the right form.  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|gimple_predicate
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Returns true iff T is a valid GIMPLE statement.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff TYPE is a valid type for a scalar register variable.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_reg_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a scalar register variable.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_reg
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if T is a GIMPLE temporary variable, false otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_formal_tmp_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if T is a GIMPLE temporary register variable.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_formal_tmp_reg
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is any sort of variable.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is any sort of symbol.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_id
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a variable or an INDIRECT_REF (of a variable).  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_min_lval
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is something whose address can be taken.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_addressable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is any valid GIMPLE lvalue.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_lvalue
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a GIMPLE restricted function invariant.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_min_invariant
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a GIMPLE rvalue.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_val
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a GIMPLE asm statement input.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_asm_val
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a valid rhs for a MODIFY_EXPR where the LHS is a    GIMPLE temporary, a renamed user variable, or something else,    respectively.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_formal_tmp_rhs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_gimple_reg_rhs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_gimple_mem_rhs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the appropriate one of the above three predicates for the LHS    T.  */
end_comment

begin_function_decl
specifier|extern
name|gimple_predicate
name|rhs_predicate_for
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a valid if-statement condition.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_condexpr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a type conversion.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_cast
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a variable that does not need to live in memory.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_non_addressable
parameter_list|(
name|tree
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true iff T is a valid call address expression.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_gimple_call_addr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If T makes a function call, returns the CALL_EXPR operand.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_call_expr_in
parameter_list|(
name|tree
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|recalculate_side_effects
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME we should deduce this from the predicate.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|fallback_t
block|{
name|fb_none
init|=
literal|0
block|,
name|fb_rvalue
init|=
literal|1
block|,
name|fb_lvalue
init|=
literal|2
block|,
name|fb_mayfail
init|=
literal|4
block|,
name|fb_either
init|=
name|fb_rvalue
operator||
name|fb_lvalue
block|}
name|fallback_t
typedef|;
end_typedef

begin_enum
enum|enum
name|gimplify_status
block|{
name|GS_ERROR
init|=
operator|-
literal|2
block|,
comment|/* Something Bad Seen.  */
name|GS_UNHANDLED
init|=
operator|-
literal|1
block|,
comment|/* A langhook result for "I dunno".  */
name|GS_OK
init|=
literal|0
block|,
comment|/* We did something, maybe more to do.  */
name|GS_ALL_DONE
init|=
literal|1
comment|/* The expression is fully gimplified.  */
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|enum
name|gimplify_status
name|gimplify_expr
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|bool
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|tree
parameter_list|)
parameter_list|,
name|fallback_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_type_sizes
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_one_sizepos
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_stmt
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_to_stmt_list
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_body
parameter_list|(
name|tree
modifier|*
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
name|push_gimplify_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_gimplify_context
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_and_add
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Miscellaneous helpers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gimple_add_tmp_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|gimple_current_bind_expr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|voidify_wrapper_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|gimple_build_eh_filter
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_and_jump
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|alloc_stmt_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_stmt_list
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|force_labels_r
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|gimplify_status
name|gimplify_va_arg_expr
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|gimplify_omp_ctx
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|omp_firstprivatize_variable
parameter_list|(
name|struct
name|gimplify_omp_ctx
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|gimple_boolify
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In omp-low.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|diagnose_omp_structured_block_errors
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|omp_reduction_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-nested.c.  */
end_comment

begin_comment
comment|/* APPLE LOCAL radar 6305545 */
end_comment

begin_function_decl
specifier|extern
name|void
name|lower_nested_functions
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_field_into_struct
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convenience routines to walk all statements of a gimple function.    The difference between these walkers and the generic walk_tree is    that walk_stmt provides context information to the callback    routine to know whether it is currently on the LHS or RHS of an    assignment (IS_LHS) or contexts where only GIMPLE values are    allowed (VAL_ONLY).        This is useful in walkers that need to re-write sub-expressions    inside statements while making sure the result is still in GIMPLE    form.     Note that this is useful exclusively before the code is converted    into SSA form.  Once the program is in SSA form, the standard    operand interface should be used to analyze/modify statements.  */
end_comment

begin_struct
struct|struct
name|walk_stmt_info
block|{
comment|/* For each statement, we invoke CALLBACK via walk_tree.  The passed      data is a walk_stmt_info structure.  */
name|walk_tree_fn
name|callback
decl_stmt|;
comment|/* Points to the current statement being walked.  */
name|tree_stmt_iterator
name|tsi
decl_stmt|;
comment|/* Additional data that CALLBACK may want to carry through the      recursion.  */
name|void
modifier|*
name|info
decl_stmt|;
comment|/* Indicates whether the *TP being examined may be replaced       with something that matches is_gimple_val (if true) or something      slightly more complicated (if false).  "Something" technically       means the common subset of is_gimple_lvalue and is_gimple_rhs,       but we never try to form anything more complicated than that, so      we don't bother checking.       Also note that CALLBACK should update this flag while walking the      sub-expressions of a statement.  For instance, when walking the      statement 'foo (&var)', the flag VAL_ONLY will initially be set      to true, however, when walking&var, the operand of that      ADDR_EXPR does not need to be a GIMPLE value.  */
name|bool
name|val_only
decl_stmt|;
comment|/* True if we are currently walking the LHS of an assignment.  */
name|bool
name|is_lhs
decl_stmt|;
comment|/* Optional.  Set to true by CALLBACK if it made any changes.  */
name|bool
name|changed
decl_stmt|;
comment|/* True if we're interested in seeing BIND_EXPRs.  */
name|bool
name|want_bind_expr
decl_stmt|;
comment|/* True if we're interested in seeing RETURN_EXPRs.  */
name|bool
name|want_return_expr
decl_stmt|;
comment|/* True if we're interested in location information.  */
name|bool
name|want_locations
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|walk_stmts
parameter_list|(
name|struct
name|walk_stmt_info
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TREE_SIMPLE_H  */
end_comment

end_unit

