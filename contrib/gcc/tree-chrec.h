begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Chains of recurrences.    Copyright (C) 2003, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Sebastian Pop<pop@cri.ensmp.fr>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_CHREC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_CHREC_H
end_define

begin_comment
comment|/* Accessors for the chains of recurrences.  */
end_comment

begin_define
define|#
directive|define
name|CHREC_VAR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|CHREC_LEFT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|CHREC_RIGHT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 2)
end_define

begin_define
define|#
directive|define
name|CHREC_VARIABLE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_INT_CST_LOW (CHREC_VAR (NODE))
end_define

begin_escape
end_escape

begin_comment
comment|/* The following trees are unique elements.  Thus the comparison of another     element to these elements should be done on the pointer to these trees,     and not on their value.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|chrec_not_analyzed_yet
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|chrec_dont_know
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|chrec_known
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After having added an automatically generated element, please    include it in the following function.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|automatically_generated_chrec_p
parameter_list|(
name|tree
name|chrec
parameter_list|)
block|{
return|return
operator|(
name|chrec
operator|==
name|chrec_not_analyzed_yet
operator|||
name|chrec
operator|==
name|chrec_dont_know
operator|||
name|chrec
operator|==
name|chrec_known
operator|)
return|;
block|}
end_function

begin_comment
comment|/* The tree nodes aka. CHRECs.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|tree_is_chrec
parameter_list|(
name|tree
name|expr
parameter_list|)
block|{
if|if
condition|(
name|TREE_CODE
argument_list|(
name|expr
argument_list|)
operator|==
name|POLYNOMIAL_CHREC
operator|||
name|automatically_generated_chrec_p
argument_list|(
name|expr
argument_list|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Chrec folding functions.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|chrec_fold_plus
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
name|chrec_fold_minus
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
name|chrec_fold_multiply
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
name|chrec_convert
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
name|chrec_convert_aggressive
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operations.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|chrec_apply
parameter_list|(
name|unsigned
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
name|chrec_replace_initial_condition
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
name|initial_condition
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|initial_condition_in_loop_num
parameter_list|(
name|tree
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|evolution_part_in_loop_num
parameter_list|(
name|tree
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|hide_evolution_in_other_loops_than_loop
parameter_list|(
name|tree
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|reset_evolution_in_loop
parameter_list|(
name|unsigned
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
name|chrec_merge
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Observers.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|eq_evolutions_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_multivariate_chrec
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|chrec_is_positive
parameter_list|(
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|chrec_contains_symbols
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|chrec_contains_symbols_defined_in_loop
parameter_list|(
name|tree
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|chrec_contains_undetermined
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_contains_chrecs
parameter_list|(
name|tree
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|evolution_function_is_affine_multivariate_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|evolution_function_is_univariate_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|nb_vars_in_chrec
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Build a polynomial chain of recurrence.  */
end_comment

begin_function
specifier|static
specifier|inline
name|tree
name|build_polynomial_chrec
parameter_list|(
name|unsigned
name|loop_num
parameter_list|,
name|tree
name|left
parameter_list|,
name|tree
name|right
parameter_list|)
block|{
if|if
condition|(
name|left
operator|==
name|chrec_dont_know
operator|||
name|right
operator|==
name|chrec_dont_know
condition|)
return|return
name|chrec_dont_know
return|;
name|gcc_assert
argument_list|(
name|TREE_TYPE
argument_list|(
name|left
argument_list|)
operator|==
name|TREE_TYPE
argument_list|(
name|right
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|build3
argument_list|(
name|POLYNOMIAL_CHREC
argument_list|,
name|TREE_TYPE
argument_list|(
name|left
argument_list|)
argument_list|,
name|build_int_cst
argument_list|(
name|NULL_TREE
argument_list|,
name|loop_num
argument_list|)
argument_list|,
name|left
argument_list|,
name|right
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Observers.  */
end_comment

begin_comment
comment|/* Determines whether CHREC is equal to zero.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|chrec_zerop
parameter_list|(
name|tree
name|chrec
parameter_list|)
block|{
if|if
condition|(
name|chrec
operator|==
name|NULL_TREE
condition|)
return|return
name|false
return|;
if|if
condition|(
name|TREE_CODE
argument_list|(
name|chrec
argument_list|)
operator|==
name|INTEGER_CST
condition|)
return|return
name|integer_zerop
argument_list|(
name|chrec
argument_list|)
return|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Determines whether the expression CHREC is a constant.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|evolution_function_is_constant_p
parameter_list|(
name|tree
name|chrec
parameter_list|)
block|{
if|if
condition|(
name|chrec
operator|==
name|NULL_TREE
condition|)
return|return
name|false
return|;
switch|switch
condition|(
name|TREE_CODE
argument_list|(
name|chrec
argument_list|)
condition|)
block|{
case|case
name|INTEGER_CST
case|:
case|case
name|REAL_CST
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
end_function

begin_function_decl
specifier|extern
name|bool
name|evolution_function_is_invariant_p
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether the given tree is an affine evolution function or not.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|evolution_function_is_affine_p
parameter_list|(
name|tree
name|chrec
parameter_list|)
block|{
if|if
condition|(
name|chrec
operator|==
name|NULL_TREE
condition|)
return|return
name|false
return|;
switch|switch
condition|(
name|TREE_CODE
argument_list|(
name|chrec
argument_list|)
condition|)
block|{
case|case
name|POLYNOMIAL_CHREC
case|:
if|if
condition|(
name|evolution_function_is_invariant_p
argument_list|(
name|CHREC_LEFT
argument_list|(
name|chrec
argument_list|)
argument_list|,
name|CHREC_VARIABLE
argument_list|(
name|chrec
argument_list|)
argument_list|)
operator|&&
name|evolution_function_is_invariant_p
argument_list|(
name|CHREC_RIGHT
argument_list|(
name|chrec
argument_list|)
argument_list|,
name|CHREC_VARIABLE
argument_list|(
name|chrec
argument_list|)
argument_list|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
end_function

begin_comment
comment|/* Determine whether the given tree is an affine or constant evolution    function.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|evolution_function_is_affine_or_constant_p
parameter_list|(
name|tree
name|chrec
parameter_list|)
block|{
return|return
name|evolution_function_is_affine_p
argument_list|(
name|chrec
argument_list|)
operator|||
name|evolution_function_is_constant_p
argument_list|(
name|chrec
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Determines whether EXPR does not contains chrec expressions.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|tree_does_not_contain_chrecs
parameter_list|(
name|tree
name|expr
parameter_list|)
block|{
return|return
operator|!
name|tree_contains_chrecs
argument_list|(
name|expr
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Determines whether CHREC is a loop invariant with respect to LOOP_NUM.      Set the result in RES and return true when the property can be computed.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|no_evolution_in_loop_p
parameter_list|(
name|tree
name|chrec
parameter_list|,
name|unsigned
name|loop_num
parameter_list|,
name|bool
modifier|*
name|res
parameter_list|)
block|{
name|tree
name|scev
decl_stmt|;
if|if
condition|(
name|chrec
operator|==
name|chrec_not_analyzed_yet
operator|||
name|chrec
operator|==
name|chrec_dont_know
operator|||
name|chrec_contains_symbols_defined_in_loop
argument_list|(
name|chrec
argument_list|,
name|loop_num
argument_list|)
condition|)
return|return
name|false
return|;
name|scev
operator|=
name|hide_evolution_in_other_loops_than_loop
argument_list|(
name|chrec
argument_list|,
name|loop_num
argument_list|)
expr_stmt|;
operator|*
name|res
operator|=
operator|!
name|tree_is_chrec
argument_list|(
name|scev
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Returns the type of the chrec.  */
end_comment

begin_function
specifier|static
specifier|inline
name|tree
name|chrec_type
parameter_list|(
name|tree
name|chrec
parameter_list|)
block|{
if|if
condition|(
name|automatically_generated_chrec_p
argument_list|(
name|chrec
argument_list|)
condition|)
return|return
name|NULL_TREE
return|;
return|return
name|TREE_TYPE
argument_list|(
name|chrec
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_CHREC_H  */
end_comment

end_unit

