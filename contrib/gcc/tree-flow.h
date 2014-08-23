begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data and Control Flow Analysis for Trees.    Copyright (C) 2001, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Diego Novillo<dnovillo@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TREE_FLOW_H
end_ifndef

begin_define
define|#
directive|define
name|_TREE_FLOW_H
value|1
end_define

begin_include
include|#
directive|include
file|"bitmap.h"
end_include

begin_include
include|#
directive|include
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_include
include|#
directive|include
file|"tree-gimple.h"
end_include

begin_include
include|#
directive|include
file|"tree-ssa-operands.h"
end_include

begin_include
include|#
directive|include
file|"cgraph.h"
end_include

begin_include
include|#
directive|include
file|"ipa-reference.h"
end_include

begin_comment
comment|/* Forward declare structures for the garbage collector GTY markers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_BASIC_BLOCK_H
end_ifndef

begin_struct_decl
struct_decl|struct
name|edge_def
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|edge_def
modifier|*
name|edge
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|basic_block_def
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|basic_block_def
modifier|*
name|basic_block
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* True if the code is in ssa form.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|in_ssa_p
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|htab_t
name|htab
decl_stmt|;
name|PTR
modifier|*
name|slot
decl_stmt|;
name|PTR
modifier|*
name|limit
decl_stmt|;
block|}
name|htab_iterator
typedef|;
end_typedef

begin_comment
comment|/* Iterate through the elements of hashtable HTAB, using htab_iterator ITER,    storing each element in RESULT, which is of type TYPE.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_HTAB_ELEMENT
parameter_list|(
name|HTAB
parameter_list|,
name|RESULT
parameter_list|,
name|TYPE
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for (RESULT = (TYPE) first_htab_element (&(ITER), (HTAB)); \ 	!end_htab_p (&(ITER)); \ 	RESULT = (TYPE) next_htab_element (&(ITER)))
end_define

begin_comment
comment|/*--------------------------------------------------------------------------- 		      Attributes for SSA_NAMEs.      NOTE: These structures are stored in struct tree_ssa_name   but are only used by the tree optimizers, so it makes better sense   to declare them here to avoid recompiling unrelated files when   making changes. ---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Aliasing information for SSA_NAMEs representing pointer variables.  */
end_comment

begin_decl_stmt
name|struct
name|ptr_info_def
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Nonzero if points-to analysis couldn't determine where this pointer      is pointing to.  */
name|unsigned
name|int
name|pt_anything
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the value of this pointer escapes the current function.  */
name|unsigned
name|int
name|value_escapes_p
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this pointer is dereferenced.  */
name|unsigned
name|int
name|is_dereferenced
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this pointer points to a global variable.  */
name|unsigned
name|int
name|pt_global_mem
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this pointer points to NULL.  */
name|unsigned
name|int
name|pt_null
range|:
literal|1
decl_stmt|;
comment|/* Set of variables that this pointer may point to.  */
name|bitmap
name|pt_vars
decl_stmt|;
comment|/* If this pointer has been dereferenced, and points-to information is      more precise than type-based aliasing, indirect references to this      pointer will be represented by this memory tag, instead of the type      tag computed by TBAA.  */
name|tree
name|name_mem_tag
decl_stmt|;
comment|/* Mask of reasons this pointer's value escapes the function  */
name|unsigned
name|int
name|escape_mask
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*--------------------------------------------------------------------------- 		   Tree annotations stored in tree_common.ann ---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|tree_ann_type
block|{
name|TREE_ANN_COMMON
block|,
name|VAR_ANN
block|,
name|FUNCTION_ANN
block|,
name|STMT_ANN
block|}
enum|;
end_enum

begin_decl_stmt
name|struct
name|tree_ann_common_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Annotation type.  */
name|enum
name|tree_ann_type
name|type
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  At all times, this     should either point to valid data or be NULL.  */
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
comment|/* The value handle for this expression.  Used by GVN-PRE.  */
name|tree
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|value_handle
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* It is advantageous to avoid things like life analysis for variables which    do not need PHI nodes.  This enum describes whether or not a particular    variable may need a PHI node.  */
end_comment

begin_enum
enum|enum
name|need_phi_state
block|{
comment|/* This is the default.  If we are still in this state after finding      all the definition and use sites, then we will assume the variable      needs PHI nodes.  This is probably an overly conservative assumption.  */
name|NEED_PHI_STATE_UNKNOWN
block|,
comment|/* This state indicates that we have seen one or more sets of the       variable in a single basic block and that the sets dominate all      uses seen so far.  If after finding all definition and use sites      we are still in this state, then the variable does not need any      PHI nodes.  */
name|NEED_PHI_STATE_NO
block|,
comment|/* This state indicates that we have either seen multiple definitions of      the variable in multiple blocks, or that we encountered a use in a      block that was not dominated by the block containing the set(s) of      this variable.  This variable is assumed to need PHI nodes.  */
name|NEED_PHI_STATE_MAYBE
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|subvar
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|subvar
modifier|*
name|subvar_t
typedef|;
end_typedef

begin_comment
comment|/* This structure represents a fake sub-variable for a structure field.  */
end_comment

begin_decl_stmt
name|struct
name|subvar
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Fake variable.  */
name|tree
name|var
decl_stmt|;
comment|/* Next subvar for this structure.  */
name|subvar_t
name|next
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|var_ann_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_ann_common_d
name|common
decl_stmt|;
comment|/* Used by the out of SSA pass to determine whether this variable has      been seen yet or not.  */
name|unsigned
name|out_of_ssa_tag
range|:
literal|1
decl_stmt|;
comment|/* Used when building root_var structures in tree_ssa_live.[ch].  */
name|unsigned
name|root_var_processed
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this variable is in the alias set of another variable.  */
name|unsigned
name|is_aliased
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this variable was used after SSA optimizations were      applied.  We set this when translating out of SSA form.  */
name|unsigned
name|used
range|:
literal|1
decl_stmt|;
comment|/* This field indicates whether or not the variable may need PHI nodes.      See the enum's definition for more detailed information about the      states.  */
name|ENUM_BITFIELD
argument_list|(
argument|need_phi_state
argument_list|)
name|need_phi_state
label|:
literal|2
expr_stmt|;
comment|/* Used during operand processing to determine if this variable is already       in the vuse list.  */
name|unsigned
name|in_vuse_list
range|:
literal|1
decl_stmt|;
comment|/* Used during operand processing to determine if this variable is already       in the v_may_def list.  */
name|unsigned
name|in_v_may_def_list
range|:
literal|1
decl_stmt|;
comment|/* An artificial variable representing the memory location pointed-to by      all the pointer symbols that flow-insensitive alias analysis      (mostly type-based) considers to be aliased.  If the variable is      not a pointer or if it is never dereferenced, this must be NULL.  */
name|tree
name|symbol_mem_tag
decl_stmt|;
comment|/* Variables that may alias this variable.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|may_aliases
expr_stmt|;
comment|/* Used when going out of SSA form to indicate which partition this      variable represents storage for.  */
name|unsigned
name|partition
decl_stmt|;
comment|/* Used by the root-var object in tree-ssa-live.[ch].  */
name|unsigned
name|root_index
decl_stmt|;
comment|/* During into-ssa and the dominator optimizer, this field holds the      current version of this variable (an SSA_NAME).  */
name|tree
name|current_def
decl_stmt|;
comment|/* If this variable is a structure, this fields holds a list of      symbols representing each of the fields of the structure.  */
name|subvar_t
name|subvars
decl_stmt|;
comment|/* Mask of values saying the reasons why this variable has escaped      the function.  */
name|unsigned
name|int
name|escape_mask
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|function_ann_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_ann_common_d
name|common
decl_stmt|;
comment|/* Pointer to the structure that contains the sets of global      variables modified by function calls.  This field is only used      for FUNCTION_DECLs.  */
name|ipa_reference_vars_info_t
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|reference_vars_info
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
struct|struct
name|immediate_use_iterator_d
block|{
comment|/* This is the current use the iterator is processing.  */
name|ssa_use_operand_t
modifier|*
name|imm_use
decl_stmt|;
comment|/* This marks the last use in the list (use node from SSA_NAME)  */
name|ssa_use_operand_t
modifier|*
name|end_p
decl_stmt|;
comment|/* This node is inserted and used to mark the end of the uses for a stmt.  */
name|ssa_use_operand_t
name|iter_node
decl_stmt|;
comment|/* This is the next ssa_name to visit.  IMM_USE may get removed before      the next one is traversed to, so it must be cached early.  */
name|ssa_use_operand_t
modifier|*
name|next_imm_name
decl_stmt|;
block|}
name|imm_use_iterator
typedef|;
end_typedef

begin_comment
comment|/* Use this iterator when simply looking at stmts.  Adding, deleting or    modifying stmts will cause this iterator to malfunction.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_IMM_USE_FAST
parameter_list|(
name|DEST
parameter_list|,
name|ITER
parameter_list|,
name|SSAVAR
parameter_list|)
define|\
value|for ((DEST) = first_readonly_imm_use (&(ITER), (SSAVAR));	\        !end_readonly_imm_use_p (&(ITER));			\        (DEST) = next_readonly_imm_use (&(ITER)))
end_define

begin_comment
comment|/* Use this iterator to visit each stmt which has a use of SSAVAR.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_IMM_USE_STMT
parameter_list|(
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|SSAVAR
parameter_list|)
define|\
value|for ((STMT) = first_imm_use_stmt (&(ITER), (SSAVAR));		\        !end_imm_use_stmt_p (&(ITER));				\        (STMT) = next_imm_use_stmt (&(ITER)))
end_define

begin_comment
comment|/* Use this to terminate the FOR_EACH_IMM_USE_STMT loop early.  Failure to     do so will result in leaving a iterator marker node in the immediate    use list, and nothing good will come from that.   */
end_comment

begin_define
define|#
directive|define
name|BREAK_FROM_IMM_USE_STMT
parameter_list|(
name|ITER
parameter_list|)
define|\
value|{								\      end_imm_use_stmt_traverse (&(ITER));			\      break;							\    }
end_define

begin_comment
comment|/* Use this iterator in combination with FOR_EACH_IMM_USE_STMT to     get access to each occurrence of ssavar on the stmt returned by    that iterator..  for instance:       FOR_EACH_IMM_USE_STMT (stmt, iter, var)        {          FOR_EACH_IMM_USE_ON_STMT (use_p, iter) 	   { 	     SET_USE (use_p) = blah; 	   } 	 update_stmt (stmt);        }							 */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_IMM_USE_ON_STMT
parameter_list|(
name|DEST
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for ((DEST) = first_imm_use_on_stmt (&(ITER));		\        !end_imm_use_on_stmt_p (&(ITER));			\        (DEST) = next_imm_use_on_stmt (&(ITER)))
end_define

begin_decl_stmt
name|struct
name|stmt_ann_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_ann_common_d
name|common
decl_stmt|;
comment|/* Nonzero if the statement has been modified (meaning that the operands      need to be scanned again).  */
name|unsigned
name|modified
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the statement makes references to volatile storage.  */
name|unsigned
name|has_volatile_ops
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if the statement makes a function call that may clobber global      and local addressable variables.  */
name|unsigned
name|makes_clobbering_call
range|:
literal|1
decl_stmt|;
comment|/* Basic block that contains this statement.  */
name|basic_block
name|bb
decl_stmt|;
comment|/* Operand cache for stmt.  */
name|struct
name|stmt_operands_d
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|operands
decl_stmt|;
comment|/* Set of variables that have had their address taken in the statement.  */
name|bitmap
name|addresses_taken
decl_stmt|;
comment|/* Unique identifier for this statement.  These ID's are to be created      by each pass on an as-needed basis in any order convenient for the      pass which needs statement UIDs.  */
name|unsigned
name|int
name|uid
decl_stmt|;
comment|/* Linked list of histograms for value-based profiling.  This is really a      struct histogram_value*.  We use void* to avoid having to export that      everywhere, and to avoid having to put it in GC memory.  */
name|void
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|histograms
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|union
name|tree_ann_d
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"ann_type ((tree_ann_t)&%h)"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|tree_ann_common_d
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TREE_ANN_COMMON"
argument_list|)
operator|)
argument_list|)
name|common
decl_stmt|;
name|struct
name|var_ann_d
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"VAR_ANN"
argument_list|)
operator|)
argument_list|)
name|vdecl
decl_stmt|;
name|struct
name|function_ann_d
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"FUNCTION_ANN"
argument_list|)
operator|)
argument_list|)
name|fdecl
decl_stmt|;
name|struct
name|stmt_ann_d
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"STMT_ANN"
argument_list|)
operator|)
argument_list|)
name|stmt
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GTY((
end_extern

begin_expr_stmt
unit|))
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|modified_noreturn_calls
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|union
name|tree_ann_d
modifier|*
name|tree_ann_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|var_ann_d
modifier|*
name|var_ann_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|function_ann_d
modifier|*
name|function_ann_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|stmt_ann_d
modifier|*
name|stmt_ann_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tree_ann_common_d
modifier|*
name|tree_ann_common_t
typedef|;
end_typedef

begin_function_decl
specifier|static
specifier|inline
name|tree_ann_common_t
name|tree_common_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|tree_ann_common_t
name|get_tree_common_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|var_ann_t
name|var_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|var_ann_t
name|get_var_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|function_ann_t
name|function_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|function_ann_t
name|get_function_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|stmt_ann_t
name|stmt_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|stmt_ann_t
name|get_stmt_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|enum
name|tree_ann_type
name|ann_type
parameter_list|(
name|tree_ann_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|basic_block
name|bb_for_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_bb_for_stmt
parameter_list|(
name|tree
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|noreturn_call_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|update_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|stmt_modified_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
specifier|inline
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|may_aliases
argument_list|(
name|tree
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
specifier|inline
name|int
name|get_lineno
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|get_filename
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|is_exec_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|is_label_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bitmap
name|addresses_taken
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*---------------------------------------------------------------------------                   Structure representing predictions in tree level. ---------------------------------------------------------------------------*/
end_comment

begin_decl_stmt
name|struct
name|edge_prediction
name|GTY
argument_list|(
operator|(
name|chain_next
argument_list|(
literal|"%h.ep_next"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|edge_prediction
modifier|*
name|ep_next
decl_stmt|;
name|edge
name|ep_edge
decl_stmt|;
name|enum
name|br_predictor
name|ep_predictor
decl_stmt|;
name|int
name|ep_probability
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Accessors for basic block annotations.  */
end_comment

begin_function_decl
specifier|static
specifier|inline
name|tree
name|phi_nodes
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|set_phi_nodes
parameter_list|(
name|basic_block
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*--------------------------------------------------------------------------- 			      Global declarations ---------------------------------------------------------------------------*/
end_comment

begin_decl_stmt
name|struct
name|int_tree_map
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|unsigned
name|int
name|uid
decl_stmt|;
name|tree
name|to
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|int
name|int_tree_map_hash
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|int_tree_map_eq
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|htab_iterator
name|hti
decl_stmt|;
block|}
name|referenced_var_iterator
typedef|;
end_typedef

begin_comment
comment|/* This macro loops over all the referenced vars, one at a time, putting the    current var in VAR.  Note:  You are not allowed to add referenced variables    to the hashtable while using this macro.  Doing so may cause it to behave    erratically.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_REFERENCED_VAR
parameter_list|(
name|VAR
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for ((VAR) = first_referenced_var (&(ITER)); \        !end_referenced_vars_p (&(ITER)); \        (VAR) = next_referenced_var (&(ITER)))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|safe_referenced_var_iterator
typedef|;
end_typedef

begin_comment
comment|/* This macro loops over all the referenced vars, one at a time, putting the    current var in VAR.  You are allowed to add referenced variables during the    execution of this macro, however, the macro will not iterate over them.  It    requires a temporary vector of trees, VEC, whose lifetime is controlled by    the caller.  The purpose of the vector is to temporarily store the    referenced_variables hashtable so that adding referenced variables does not    affect the hashtable.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_REFERENCED_VAR_SAFE
parameter_list|(
name|VAR
parameter_list|,
name|VEC
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for ((ITER).i = 0, fill_referenced_var_vec (&(VEC)); \        VEC_iterate (tree, (VEC), (ITER).i, (VAR)); \        (ITER).i++)
end_define

begin_comment
comment|/* Array of all variables referenced in the function.  */
end_comment

begin_extern
extern|extern GTY((param_is (struct int_tree_map
end_extern

begin_decl_stmt
unit|)))
name|htab_t
name|referenced_vars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default defs for undefined symbols. */
end_comment

begin_extern
extern|extern GTY((param_is (struct int_tree_map
end_extern

begin_decl_stmt
unit|)))
name|htab_t
name|default_defs
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|referenced_var_lookup
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|referenced_var_check_and_insert
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|num_referenced_vars
value|htab_elements (referenced_vars)
end_define

begin_define
define|#
directive|define
name|referenced_var
parameter_list|(
name|i
parameter_list|)
value|referenced_var_lookup (i)
end_define

begin_comment
comment|/* Array of all SSA_NAMEs used in the function.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_expr_stmt
unit|))
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|ssa_names
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|num_ssa_names
value|(VEC_length (tree, ssa_names))
end_define

begin_define
define|#
directive|define
name|ssa_name
parameter_list|(
name|i
parameter_list|)
value|(VEC_index (tree, ssa_names, (i)))
end_define

begin_comment
comment|/* Artificial variable used to model the effects of function calls.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|global_var
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Artificial variable used to model the effects of nonlocal    variables.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|nonlocal_all
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call clobbered variables in the function.  If bit I is set, then    REFERENCED_VARS (I) is call-clobbered.  */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap
name|call_clobbered_vars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Addressable variables in the function.  If bit I is set, then    REFERENCED_VARS (I) has had its address taken.  */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap
name|addressable_vars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'true' after aliases have been computed (see compute_may_aliases).  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|aliases_computed_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros for showing usage statistics.  */
end_comment

begin_define
define|#
directive|define
name|SCALE
parameter_list|(
name|x
parameter_list|)
value|((unsigned long) ((x)< 1024*10	\ 		  ? (x)					\ 		  : ((x)< 1024*1024*10			\ 		     ? (x) / 1024			\ 		     : (x) / (1024*1024))))
end_define

begin_define
define|#
directive|define
name|LABEL
parameter_list|(
name|x
parameter_list|)
value|((x)< 1024*10 ? 'b' : ((x)< 1024*1024*10 ? 'k' : 'M'))
end_define

begin_define
define|#
directive|define
name|PERCENT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((float)(x) * 100.0 / (float)(y))
end_define

begin_comment
comment|/*--------------------------------------------------------------------------- 			      Block iterators ---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tree_stmt_iterator
name|tsi
decl_stmt|;
name|basic_block
name|bb
decl_stmt|;
block|}
name|block_stmt_iterator
typedef|;
end_typedef

begin_function_decl
specifier|static
specifier|inline
name|block_stmt_iterator
name|bsi_start
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|block_stmt_iterator
name|bsi_last
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|block_stmt_iterator
name|bsi_after_labels
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|block_stmt_iterator
name|bsi_for_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|bsi_end_p
parameter_list|(
name|block_stmt_iterator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|bsi_next
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|bsi_prev
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|tree
name|bsi_stmt
parameter_list|(
name|block_stmt_iterator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|tree
modifier|*
name|bsi_stmt_ptr
parameter_list|(
name|block_stmt_iterator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_remove
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_move_before
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_move_after
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_move_to_bb_end
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|bsi_iterator_update
block|{
comment|/* Note that these are intentionally in the same order as TSI_FOO.  They      mean exactly the same as their TSI_* counterparts.  */
name|BSI_NEW_STMT
block|,
name|BSI_SAME_STMT
block|,
name|BSI_CHAIN_START
block|,
name|BSI_CHAIN_END
block|,
name|BSI_CONTINUE_LINKING
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|bsi_insert_before
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|enum
name|bsi_iterator_update
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_insert_after
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|enum
name|bsi_iterator_update
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_replace
parameter_list|(
specifier|const
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*--------------------------------------------------------------------------- 			      OpenMP Region Tree ---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Parallel region information.  Every parallel and workshare    directive is enclosed between two markers, the OMP_* directive    and a corresponding OMP_RETURN statement.  */
end_comment

begin_struct
struct|struct
name|omp_region
block|{
comment|/* The enclosing region.  */
name|struct
name|omp_region
modifier|*
name|outer
decl_stmt|;
comment|/* First child region.  */
name|struct
name|omp_region
modifier|*
name|inner
decl_stmt|;
comment|/* Next peer region.  */
name|struct
name|omp_region
modifier|*
name|next
decl_stmt|;
comment|/* Block containing the omp directive as its last stmt.  */
name|basic_block
name|entry
decl_stmt|;
comment|/* Block containing the OMP_RETURN as its last stmt.  */
name|basic_block
name|exit
decl_stmt|;
comment|/* Block containing the OMP_CONTINUE as its last stmt.  */
name|basic_block
name|cont
decl_stmt|;
comment|/* If this is a combined parallel+workshare region, this is a list      of additional arguments needed by the combined parallel+workshare      library call.  */
name|tree
name|ws_args
decl_stmt|;
comment|/* The code for the omp directive of this region.  */
name|enum
name|tree_code
name|type
decl_stmt|;
comment|/* Schedule kind, only used for OMP_FOR type regions.  */
name|enum
name|omp_clause_schedule_kind
name|sched_kind
decl_stmt|;
comment|/* True if this is a combined parallel+workshare region.  */
name|bool
name|is_combined_parallel
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|omp_region
modifier|*
name|root_omp_region
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|omp_region
modifier|*
name|new_omp_region
parameter_list|(
name|basic_block
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|struct
name|omp_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_omp_regions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*--------------------------------------------------------------------------- 			      Function prototypes ---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* In tree-cfg.c  */
end_comment

begin_comment
comment|/* Location to track pending stmt for edge insertion.  */
end_comment

begin_define
define|#
directive|define
name|PENDING_STMT
parameter_list|(
name|e
parameter_list|)
value|((e)->insns.t)
end_define

begin_function_decl
specifier|extern
name|void
name|delete_tree_cfg_annotations
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disband_implicit_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|stmt_ends_bb_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_ctrl_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_ctrl_altering_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|computed_goto_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|simple_goto_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_can_make_abnormal_goto
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|single_noncomplex_succ
parameter_list|(
name|basic_block
name|bb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tree_dump_bb
parameter_list|(
name|basic_block
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_tree_bb
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|debug_tree_bb_n
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_tree_cfg
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_tree_cfg
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_cfg_stats
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_cfg_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_loop_ir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_loop_ir
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cleanup_dead_labels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|group_case_labels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|first_stmt
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|last_stmt
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
modifier|*
name|last_stmt_ptr
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|last_and_only_stmt
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|find_taken_edge
parameter_list|(
name|basic_block
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|label_to_block_fn
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|label_to_block
parameter_list|(
name|t
parameter_list|)
value|(label_to_block_fn (cfun, t))
end_define

begin_function_decl
specifier|extern
name|void
name|bsi_insert_on_edge
parameter_list|(
name|edge
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|bsi_insert_on_edge_immediate
parameter_list|(
name|edge
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_commit_one_edge_insert
parameter_list|(
name|edge
parameter_list|,
name|basic_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bsi_commit_edge_inserts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|notice_special_calls
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_special_calls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_stmts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|tree_block_label
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|extract_true_false_edges_from_block
parameter_list|(
name|basic_block
parameter_list|,
name|edge
modifier|*
parameter_list|,
name|edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_duplicate_sese_region
parameter_list|(
name|edge
parameter_list|,
name|edge
parameter_list|,
name|basic_block
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|basic_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_phi_args_after_copy_bb
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_phi_args_after_copy
parameter_list|(
name|basic_block
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_purge_dead_abnormal_call_edges
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_purge_dead_eh_edges
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_purge_all_dead_eh_edges
parameter_list|(
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|gimplify_val
parameter_list|(
name|block_stmt_iterator
modifier|*
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
name|gimplify_build1
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|enum
name|tree_code
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
name|gimplify_build2
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|enum
name|tree_code
parameter_list|,
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
name|gimplify_build3
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
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
name|void
name|init_empty_tree_cfg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fold_cond_expr_cond
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_abnormal_goto_edges
parameter_list|(
name|basic_block
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|replace_uses_by
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_recording_case_labels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_recording_case_labels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|move_sese_region_to_fn
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-cfgcleanup.c  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|cleanup_tree_cfg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cleanup_tree_cfg_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-pretty-print.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dump_generic_bb
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-dfa.c  */
end_comment

begin_function_decl
specifier|extern
name|var_ann_t
name|create_var_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|function_ann_t
name|create_function_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|stmt_ann_t
name|create_stmt_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree_ann_common_t
name|create_tree_common_ann
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_dfa_stats
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_dfa_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_referenced_vars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_referenced_vars
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_variable
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_subvars_for
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_subvars_for
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_virtual_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_referenced_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_new_vars_to_rename
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_new_referenced_vars
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_rename_temp
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
name|void
name|set_default_def
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
name|default_def
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|default_def_fn
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-phinodes.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|reserve_phi_args_for_new_edge
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|create_phi_node
parameter_list|(
name|tree
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_phi_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_phi_args
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_phi_node
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
name|phi_reverse
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In gimple-low.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|record_vars_into
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_vars
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|block_may_fallthru
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-alias.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dump_may_aliases_for
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_may_aliases_for
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_alias_info
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_alias_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_points_to_info
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_points_to_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_points_to_info_for
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_points_to_info_for
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|may_be_aliased
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_aliased_with
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
name|may_aliases_intersect
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ptr_info_def
modifier|*
name|get_ptr_info
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|new_type_alias
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
name|void
name|count_uses_and_derefs
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|unsigned
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|subvar_t
name|get_subvars_for_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|tree
name|get_subvar_at
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|ref_contains_array_ref
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|array_ref_contains_indirect_ref
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_ref_base_and_extent
parameter_list|(
name|tree
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|var_can_have_subvars
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|overlap_subvar
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call-back function for walk_use_def_chains().  At each reaching    definition, a function with this prototype is called.  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|walk_use_def_chains_fn
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* In tree-ssa-alias-warnings.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|strict_aliasing_warning_backend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_tree_ssa
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|ssa_redirect_edge
parameter_list|(
name|edge
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_pending_stmts
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_ssa_useless_type_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_ssa_useless_type_conversion_1
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_ssa
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_tree_ssa
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|register_new_def
argument_list|(
name|tree
argument_list|,
name|VEC
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
operator|*
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|walk_use_def_chains
parameter_list|(
name|tree
parameter_list|,
name|walk_use_def_chains_fn
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|stmt_references_memory_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-into-ssa.c  */
end_comment

begin_function_decl
name|void
name|update_ssa
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_update_ssa
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|register_new_name_mapping
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|create_new_def_for
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|def_operand_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|need_ssa_update_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|name_registered_for_update_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bitmap
name|ssa_names_to_replace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|release_ssa_name_after_update_ssa
parameter_list|(
name|tree
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|compute_global_livein
parameter_list|(
name|bitmap
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|duplicate_ssa_name
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mark_sym_for_renaming
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mark_set_for_renaming
parameter_list|(
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_current_def
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_current_def
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-ccp.c  */
end_comment

begin_function_decl
name|bool
name|fold_stmt
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|fold_stmt_inplace
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|widen_bitfield
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-vrp.c  */
end_comment

begin_function_decl
name|tree
name|vrp_evaluate_conditional
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|simplify_stmt_using_ranges
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-dom.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dump_dominator_optimization_stats
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_dominator_optimization_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|loop_depth_of_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-copy.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|merge_alias_info
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|propagate_value
parameter_list|(
name|use_operand_p
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|propagate_tree_value
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|replace_exp
parameter_list|(
name|use_operand_p
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|may_propagate_copy
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
name|may_propagate_copy_into_asm
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Affine iv.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Iv = BASE + STEP * i.  */
name|tree
name|base
decl_stmt|,
name|step
decl_stmt|;
comment|/* True if this iv does not overflow.  */
name|bool
name|no_overflow
decl_stmt|;
block|}
name|affine_iv
typedef|;
end_typedef

begin_comment
comment|/* Description of number of iterations of a loop.  All the expressions inside    the structure can be evaluated at the end of the loop's preheader    (and due to ssa form, also anywhere inside the body of the loop).  */
end_comment

begin_struct
struct|struct
name|tree_niter_desc
block|{
name|tree
name|assumptions
decl_stmt|;
comment|/* The boolean expression.  If this expression evaluates 			   to false, then the other fields in this structure 			   should not be used; there is no guarantee that they 			   will be correct.  */
name|tree
name|may_be_zero
decl_stmt|;
comment|/* The boolean expression.  If it evaluates to true, 			   the loop will exit in the first iteration (i.e. 			   its latch will not be executed), even if the niter 			   field says otherwise.  */
name|tree
name|niter
decl_stmt|;
comment|/* The expression giving the number of iterations of 			   a loop (provided that assumptions == true and 			   may_be_zero == false), more precisely the number 			   of executions of the latch of the loop.  */
name|tree
name|additional_info
decl_stmt|;
comment|/* The boolean expression.  Sometimes we use additional 			   knowledge to simplify the other expressions 			   contained in this structure (for example the 			   knowledge about value ranges of operands on entry to 			   the loop).  If this is a case, conjunction of such 			   condition is stored in this field, so that we do not 			   lose the information: for example if may_be_zero 			   is (n<= 0) and niter is (unsigned) n, we know 			   that the number of iterations is at most 			   MAX_SIGNED_INT.  However if the (n<= 0) assumption 			   is eliminated (by looking at the guard on entry of 			   the loop), then the information would be lost.  */
comment|/* The simplified shape of the exit condition.  The loop exits if      CONTROL CMP BOUND is false, where CMP is one of NE_EXPR,      LT_EXPR, or GT_EXPR, and step of CONTROL is positive if CMP is      LE_EXPR and negative if CMP is GE_EXPR.  This information is used      by loop unrolling.  */
name|affine_iv
name|control
decl_stmt|;
name|tree
name|bound
decl_stmt|;
name|enum
name|tree_code
name|cmp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In tree-vectorizer.c */
end_comment

begin_function_decl
name|void
name|vectorize_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vect_can_force_dr_alignment_p
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_vectype_for_scalar_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-phiopt.c */
end_comment

begin_function_decl
name|bool
name|empty_block_p
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-loop*.c  */
end_comment

begin_function_decl
name|void
name|tree_ssa_lim
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|tree_ssa_unswitch_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|canonicalize_induction_variables
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|tree_unroll_loops_completely
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|tree_ssa_prefetch_arrays
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|remove_empty_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tree_ssa_iv_optimize
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|number_of_iterations_exit
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
parameter_list|,
name|struct
name|tree_niter_desc
modifier|*
name|niter
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|find_loop_niter
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|loop_niter_by_eval
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|find_loop_niter_by_eval
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|estimate_numbers_of_iterations
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|scev_probably_wraps_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|convert_affine_scev
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
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
name|bool
name|nowrap_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ev_direction
block|{
name|EV_DIR_GROWS
block|,
name|EV_DIR_DECREASES
block|,
name|EV_DIR_UNKNOWN
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|ev_direction
name|scev_direction
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_numbers_of_iterations_estimates
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_numbers_of_iterations_estimates_loop
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rewrite_into_loop_closed_ssa
parameter_list|(
name|bitmap
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_loop_closed_ssa
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|loop_commit_inserts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|for_each_index
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|bool
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
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
name|void
name|create_iv
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|bool
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
name|void
name|split_loop_exit_edge
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|force_expr_to_var_cost
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|basic_block
name|bsi_insert_on_edge_immediate_loop
parameter_list|(
name|edge
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|standard_iv_increment_position
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|basic_block
name|ip_end_pos
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|basic_block
name|ip_normal_pos
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tree_duplicate_loop_to_header_edge
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
parameter_list|,
name|struct
name|loops
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|sbitmap
parameter_list|,
name|edge
parameter_list|,
name|edge
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|loop
modifier|*
name|tree_ssa_loop_version
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|basic_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|expand_simple_operations
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|substitute_in_loop_info
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|edge
name|single_dom_exit
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|can_unroll_loop_p
parameter_list|(
name|struct
name|loop
modifier|*
name|loop
parameter_list|,
name|unsigned
name|factor
parameter_list|,
name|struct
name|tree_niter_desc
modifier|*
name|niter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tree_unroll_loop
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|edge
parameter_list|,
name|struct
name|tree_niter_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|contains_abnormal_ssa_name_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-threadedge.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|potentially_threadable_block
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|thread_across_edge
argument_list|(
name|tree
argument_list|,
name|edge
argument_list|,
name|bool
argument_list|,
name|VEC
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
operator|*
operator|*
argument_list|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|tree
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In tree-ssa-loop-im.c  */
end_comment

begin_comment
comment|/* The possibilities of statement movement.  */
end_comment

begin_enum
enum|enum
name|move_pos
block|{
name|MOVE_IMPOSSIBLE
block|,
comment|/* No movement -- side effect expression.  */
name|MOVE_PRESERVE_EXECUTION
block|,
comment|/* Must not cause the non-executed statement 				   become executed -- memory accesses, ... */
name|MOVE_POSSIBLE
comment|/* Unlimited movement.  */
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|enum
name|move_pos
name|movement_possibility
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The reasons a variable may escape a function.  */
end_comment

begin_enum
enum|enum
name|escape_type
block|{
name|NO_ESCAPE
init|=
literal|0
block|,
comment|/* Doesn't escape.  */
name|ESCAPE_STORED_IN_GLOBAL
init|=
literal|1
operator|<<
literal|1
block|,
name|ESCAPE_TO_ASM
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* Passed by address to an assembly 				statement.  */
name|ESCAPE_TO_CALL
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* Escapes to a function call.  */
name|ESCAPE_BAD_CAST
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* Cast from pointer to integer */
name|ESCAPE_TO_RETURN
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* Returned from function.  */
name|ESCAPE_TO_PURE_CONST
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* Escapes to a pure or constant 				      function call.  */
name|ESCAPE_IS_GLOBAL
init|=
literal|1
operator|<<
literal|7
block|,
comment|/* Is a global variable.  */
name|ESCAPE_IS_PARM
init|=
literal|1
operator|<<
literal|8
block|,
comment|/* Is an incoming function parameter.  */
name|ESCAPE_UNKNOWN
init|=
literal|1
operator|<<
literal|9
comment|/* We believe it escapes for some reason 			       not enumerated above.  */
block|}
enum|;
end_enum

begin_comment
comment|/* In tree-flow-inline.h  */
end_comment

begin_function_decl
specifier|static
specifier|inline
name|bool
name|is_call_clobbered
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|mark_call_clobbered
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|set_is_used
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|bool
name|unmodifiable_var_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-eh.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|make_eh_edges
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_could_trap_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_could_throw_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_can_throw_internal
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_can_throw_external
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lookup_stmt_eh_region
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_stmt_to_eh_region
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|remove_stmt_from_eh_region
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|maybe_clean_or_replace_eh_stmt
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-pre.c  */
end_comment

begin_function_decl
name|void
name|add_to_value
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_value_expressions
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_value_expressions
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-vn.c  */
end_comment

begin_function_decl
name|bool
name|expressions_equal_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_value_handle
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hashval_t
name|vn_compute
parameter_list|(
name|tree
parameter_list|,
name|hashval_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|sort_vuses
argument_list|(
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|tree
name|vn_lookup_or_add
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|tree
name|vn_lookup_or_add_with_vuses
argument_list|(
name|tree
argument_list|,
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|vn_add
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|vn_add_with_vuses
argument_list|(
name|tree
argument_list|,
name|tree
argument_list|,
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|tree
name|vn_lookup
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|tree
name|vn_lookup_with_vuses
argument_list|(
name|tree
argument_list|,
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|vn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vn_delete
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-sink.c  */
end_comment

begin_function_decl
name|bool
name|is_hidden_global_store
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-sra.c  */
end_comment

begin_function_decl
name|void
name|insert_edge_copies
parameter_list|(
name|tree
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sra_insert_before
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sra_insert_after
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sra_init_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|sra_type_can_be_decomposed_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-loop-linear.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|linear_transform_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-loop-ivopts.c  */
end_comment

begin_function_decl
name|bool
name|expr_invariant_in_loop_p
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|multiplier_allowed_in_address_p
parameter_list|(
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|multiply_by_cost
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-threadupdate.c.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|thread_through_all_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|register_jump_thread
parameter_list|(
name|edge
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In gimplify.c  */
end_comment

begin_function_decl
name|tree
name|force_gimple_operand
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|force_gimple_operand_bsi
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-structalias.c */
end_comment

begin_function_decl
name|bool
name|find_what_p_points_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-live.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|remove_unused_locals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-address.c  */
end_comment

begin_comment
comment|/* Affine combination of trees.  We keep track of at most MAX_AFF_ELTS elements    to make things simpler; this is sufficient in most cases.  */
end_comment

begin_define
define|#
directive|define
name|MAX_AFF_ELTS
value|8
end_define

begin_struct
struct|struct
name|affine_tree_combination
block|{
comment|/* Type of the result of the combination.  */
name|tree
name|type
decl_stmt|;
comment|/* Mask modulo that the operations are performed.  */
name|unsigned
name|HOST_WIDE_INT
name|mask
decl_stmt|;
comment|/* Constant offset.  */
name|unsigned
name|HOST_WIDE_INT
name|offset
decl_stmt|;
comment|/* Number of elements of the combination.  */
name|unsigned
name|n
decl_stmt|;
comment|/* Elements and their coefficients.  */
name|tree
name|elts
index|[
name|MAX_AFF_ELTS
index|]
decl_stmt|;
name|unsigned
name|HOST_WIDE_INT
name|coefs
index|[
name|MAX_AFF_ELTS
index|]
decl_stmt|;
comment|/* Remainder of the expression.  */
name|tree
name|rest
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Description of a memory address.  */
end_comment

begin_struct
struct|struct
name|mem_address
block|{
name|tree
name|symbol
decl_stmt|,
name|base
decl_stmt|,
name|index
decl_stmt|,
name|step
decl_stmt|,
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|tree
name|create_mem_ref
parameter_list|(
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|struct
name|affine_tree_combination
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|addr_for_mem_ref
parameter_list|(
name|struct
name|mem_address
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_address_description
parameter_list|(
name|tree
parameter_list|,
name|struct
name|mem_address
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|maybe_fold_tmr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This structure is simply used during pushing fields onto the fieldstack    to track the offset of the field, since bitpos_of_field gives it relative    to its immediate containing type, and we want it relative to the ultimate    containing object.  */
end_comment

begin_struct
struct|struct
name|fieldoff
block|{
name|tree
name|type
decl_stmt|;
name|tree
name|size
decl_stmt|;
name|tree
name|decl
decl_stmt|;
name|HOST_WIDE_INT
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fieldoff
name|fieldoff_s
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_O
argument_list|(
name|fieldoff_s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_O
argument_list|(
name|fieldoff_s
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|push_fields_onto_fieldstack
argument_list|(
name|tree
argument_list|,
name|VEC
argument_list|(
name|fieldoff_s
argument_list|,
name|heap
argument_list|)
operator|*
operator|*
argument_list|,
name|HOST_WIDE_INT
argument_list|,
name|bool
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sort_fieldstack
argument_list|(
name|VEC
argument_list|(
name|fieldoff_s
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|init_alias_heapvars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_alias_heapvars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"tree-flow-inline.h"
end_include

begin_function_decl
name|void
name|swap_tree_operands
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
name|void
name|recalculate_used_alone
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|updating_used_alone
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TREE_FLOW_H  */
end_comment

end_unit

