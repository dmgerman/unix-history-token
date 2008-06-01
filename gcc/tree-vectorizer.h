begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Loop Vectorization    Copyright (C) 2003, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Dorit Naishlos<dorit@il.ibm.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_VECTORIZER_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_VECTORIZER_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MAPPED_LOCATION
end_ifdef

begin_typedef
typedef|typedef
name|source_location
name|LOC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNKNOWN_LOC
value|UNKNOWN_LOCATION
end_define

begin_define
define|#
directive|define
name|EXPR_LOC
parameter_list|(
name|e
parameter_list|)
value|EXPR_LOCATION(e)
end_define

begin_define
define|#
directive|define
name|LOC_FILE
parameter_list|(
name|l
parameter_list|)
value|LOCATION_FILE (l)
end_define

begin_define
define|#
directive|define
name|LOC_LINE
parameter_list|(
name|l
parameter_list|)
value|LOCATION_LINE (l)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|source_locus
name|LOC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNKNOWN_LOC
value|NULL
end_define

begin_define
define|#
directive|define
name|EXPR_LOC
parameter_list|(
name|e
parameter_list|)
value|EXPR_LOCUS(e)
end_define

begin_define
define|#
directive|define
name|LOC_FILE
parameter_list|(
name|l
parameter_list|)
value|(l)->file
end_define

begin_define
define|#
directive|define
name|LOC_LINE
parameter_list|(
name|l
parameter_list|)
value|(l)->line
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Used for naming of new temporaries.  */
end_comment

begin_enum
enum|enum
name|vect_var_kind
block|{
name|vect_simple_var
block|,
name|vect_pointer_var
block|,
name|vect_scalar_var
block|}
enum|;
end_enum

begin_comment
comment|/* Defines type of operation.  */
end_comment

begin_enum
enum|enum
name|operation_type
block|{
name|unary_op
init|=
literal|1
block|,
name|binary_op
block|,
name|ternary_op
block|}
enum|;
end_enum

begin_comment
comment|/* Define type of available alignment support.  */
end_comment

begin_enum
enum|enum
name|dr_alignment_support
block|{
name|dr_unaligned_unsupported
block|,
name|dr_unaligned_supported
block|,
name|dr_unaligned_software_pipeline
block|,
name|dr_aligned
block|}
enum|;
end_enum

begin_comment
comment|/* Define type of def-use cross-iteration cycle.  */
end_comment

begin_enum
enum|enum
name|vect_def_type
block|{
name|vect_constant_def
block|,
name|vect_invariant_def
block|,
name|vect_loop_def
block|,
name|vect_induction_def
block|,
name|vect_reduction_def
block|,
name|vect_unknown_def_type
block|}
enum|;
end_enum

begin_comment
comment|/* Define verbosity levels.  */
end_comment

begin_enum
enum|enum
name|verbosity_levels
block|{
name|REPORT_NONE
block|,
name|REPORT_VECTORIZED_LOOPS
block|,
name|REPORT_UNVECTORIZED_LOOPS
block|,
name|REPORT_ALIGNMENT
block|,
name|REPORT_DR_DETAILS
block|,
name|REPORT_BAD_FORM_LOOPS
block|,
name|REPORT_OUTER_LOOPS
block|,
name|REPORT_DETAILS
block|,
comment|/* New verbosity levels should be added before this one.  */
name|MAX_VERBOSITY_LEVEL
block|}
enum|;
end_enum

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Info on vectorized loops.                                       */
end_comment

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_loop_vec_info
block|{
comment|/* The loop to which this info struct refers to.  */
name|struct
name|loop
modifier|*
name|loop
decl_stmt|;
comment|/* The loop basic blocks.  */
name|basic_block
modifier|*
name|bbs
decl_stmt|;
comment|/* The loop exit_condition.  */
name|tree
name|exit_cond
decl_stmt|;
comment|/* Number of iterations.  */
name|tree
name|num_iters
decl_stmt|;
comment|/* Is the loop vectorizable? */
name|bool
name|vectorizable
decl_stmt|;
comment|/* Unrolling factor  */
name|int
name|vectorization_factor
decl_stmt|;
comment|/* Unknown DRs according to which loop was peeled.  */
name|struct
name|data_reference
modifier|*
name|unaligned_dr
decl_stmt|;
comment|/* peeling_for_alignment indicates whether peeling for alignment will take      place, and what the peeling factor should be:      peeling_for_alignment = X means:         If X=0: Peeling for alignment will not be applied.         If X>0: Peel first X iterations.         If X=-1: Generate a runtime test to calculate the number of iterations                  to be peeled, using the dataref recorded in the field                  unaligned_dr.  */
name|int
name|peeling_for_alignment
decl_stmt|;
comment|/* The mask used to check the alignment of pointers or arrays.  */
name|int
name|ptr_mask
decl_stmt|;
comment|/* All data references in the loop.  */
name|VEC
argument_list|(
name|data_reference_p
argument_list|,
name|heap
argument_list|)
operator|*
name|datarefs
expr_stmt|;
comment|/* All data dependences in the loop.  */
name|VEC
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
operator|*
name|ddrs
expr_stmt|;
comment|/* Statements in the loop that have data references that are candidates for a      runtime (loop versioning) misalignment check.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
operator|*
name|may_misalign_stmts
expr_stmt|;
comment|/* The loop location in the source.  */
name|LOC
name|loop_line_number
decl_stmt|;
block|}
typedef|*
name|loop_vec_info
typedef|;
end_typedef

begin_comment
comment|/* Access Functions.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_VINFO_LOOP
parameter_list|(
name|L
parameter_list|)
value|(L)->loop
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_BBS
parameter_list|(
name|L
parameter_list|)
value|(L)->bbs
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_EXIT_COND
parameter_list|(
name|L
parameter_list|)
value|(L)->exit_cond
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_NITERS
parameter_list|(
name|L
parameter_list|)
value|(L)->num_iters
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_VECTORIZABLE_P
parameter_list|(
name|L
parameter_list|)
value|(L)->vectorizable
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_VECT_FACTOR
parameter_list|(
name|L
parameter_list|)
value|(L)->vectorization_factor
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_PTR_MASK
parameter_list|(
name|L
parameter_list|)
value|(L)->ptr_mask
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_DATAREFS
parameter_list|(
name|L
parameter_list|)
value|(L)->datarefs
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_DDRS
parameter_list|(
name|L
parameter_list|)
value|(L)->ddrs
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_INT_NITERS
parameter_list|(
name|L
parameter_list|)
value|(TREE_INT_CST_LOW ((L)->num_iters))
end_define

begin_define
define|#
directive|define
name|LOOP_PEELING_FOR_ALIGNMENT
parameter_list|(
name|L
parameter_list|)
value|(L)->peeling_for_alignment
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_UNALIGNED_DR
parameter_list|(
name|L
parameter_list|)
value|(L)->unaligned_dr
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_MAY_MISALIGN_STMTS
parameter_list|(
name|L
parameter_list|)
value|(L)->may_misalign_stmts
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_LOC
parameter_list|(
name|L
parameter_list|)
value|(L)->loop_line_number
end_define

begin_define
define|#
directive|define
name|LOOP_VINFO_NITERS_KNOWN_P
parameter_list|(
name|L
parameter_list|)
define|\
value|(host_integerp ((L)->num_iters,0)                        \&& TREE_INT_CST_LOW ((L)->num_iters)> 0)
end_define

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Info on vectorized defs.                                        */
end_comment

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|stmt_vec_info_type
block|{
name|undef_vec_info_type
init|=
literal|0
block|,
name|load_vec_info_type
block|,
name|store_vec_info_type
block|,
name|op_vec_info_type
block|,
name|assignment_vec_info_type
block|,
name|condition_vec_info_type
block|,
name|reduc_vec_info_type
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|struct
name|data_reference
modifier|*
name|dr_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|dr_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|dr_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|_stmt_vec_info
block|{
name|enum
name|stmt_vec_info_type
name|type
decl_stmt|;
comment|/* The stmt to which this info struct refers to.  */
name|tree
name|stmt
decl_stmt|;
comment|/* The loop_vec_info with respect to which STMT is vectorized.  */
name|loop_vec_info
name|loop_vinfo
decl_stmt|;
comment|/* Not all stmts in the loop need to be vectorized. e.g, the incrementation      of the loop induction variable and computation of array indexes. relevant      indicates whether the stmt needs to be vectorized.  */
name|bool
name|relevant
decl_stmt|;
comment|/* Indicates whether this stmts is part of a computation whose result is      used outside the loop.  */
name|bool
name|live
decl_stmt|;
comment|/* The vector type to be used.  */
name|tree
name|vectype
decl_stmt|;
comment|/* The vectorized version of the stmt.  */
name|tree
name|vectorized_stmt
decl_stmt|;
comment|/** The following is relevant only for stmts that contain a non-scalar      data-ref (array/pointer/struct access). A GIMPLE stmt is expected to have       at most one such data-ref.  **/
comment|/* Information about the data-ref (access function, etc).  */
name|struct
name|data_reference
modifier|*
name|data_ref_info
decl_stmt|;
comment|/* Stmt is part of some pattern (computation idiom)  */
name|bool
name|in_pattern_p
decl_stmt|;
comment|/* Used for various bookkeeping purposes, generally holding a pointer to       some other stmt S that is in some way "related" to this stmt.       Current use of this field is:         If this stmt is part of a pattern (i.e. the field 'in_pattern_p' is          true): S is the "pattern stmt" that represents (and replaces) the          sequence of stmts that constitutes the pattern.  Similarly, the          related_stmt of the "pattern stmt" points back to this stmt (which is          the last stmt in the original sequence of stmts that constitutes the          pattern).  */
name|tree
name|related_stmt
decl_stmt|;
comment|/* List of datarefs that are known to have the same alignment as the dataref      of this stmt.  */
name|VEC
argument_list|(
name|dr_p
argument_list|,
name|heap
argument_list|)
operator|*
name|same_align_refs
expr_stmt|;
comment|/* Classify the def of this stmt.  */
name|enum
name|vect_def_type
name|def_type
decl_stmt|;
block|}
typedef|*
name|stmt_vec_info
typedef|;
end_typedef

begin_comment
comment|/* Access Functions.  */
end_comment

begin_define
define|#
directive|define
name|STMT_VINFO_TYPE
parameter_list|(
name|S
parameter_list|)
value|(S)->type
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_STMT
parameter_list|(
name|S
parameter_list|)
value|(S)->stmt
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_LOOP_VINFO
parameter_list|(
name|S
parameter_list|)
value|(S)->loop_vinfo
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_RELEVANT_P
parameter_list|(
name|S
parameter_list|)
value|(S)->relevant
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_LIVE_P
parameter_list|(
name|S
parameter_list|)
value|(S)->live
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_VECTYPE
parameter_list|(
name|S
parameter_list|)
value|(S)->vectype
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_VEC_STMT
parameter_list|(
name|S
parameter_list|)
value|(S)->vectorized_stmt
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_DATA_REF
parameter_list|(
name|S
parameter_list|)
value|(S)->data_ref_info
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_IN_PATTERN_P
parameter_list|(
name|S
parameter_list|)
value|(S)->in_pattern_p
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_RELATED_STMT
parameter_list|(
name|S
parameter_list|)
value|(S)->related_stmt
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_SAME_ALIGN_REFS
parameter_list|(
name|S
parameter_list|)
value|(S)->same_align_refs
end_define

begin_define
define|#
directive|define
name|STMT_VINFO_DEF_TYPE
parameter_list|(
name|S
parameter_list|)
value|(S)->def_type
end_define

begin_function_decl
specifier|static
specifier|inline
name|void
name|set_stmt_info
parameter_list|(
name|stmt_ann_t
name|ann
parameter_list|,
name|stmt_vec_info
name|stmt_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|stmt_vec_info
name|vinfo_for_stmt
parameter_list|(
name|tree
name|stmt
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|set_stmt_info
parameter_list|(
name|stmt_ann_t
name|ann
parameter_list|,
name|stmt_vec_info
name|stmt_info
parameter_list|)
block|{
if|if
condition|(
name|ann
condition|)
name|ann
operator|->
name|common
operator|.
name|aux
operator|=
operator|(
name|char
operator|*
operator|)
name|stmt_info
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|stmt_vec_info
name|vinfo_for_stmt
parameter_list|(
name|tree
name|stmt
parameter_list|)
block|{
name|stmt_ann_t
name|ann
init|=
name|stmt_ann
argument_list|(
name|stmt
argument_list|)
decl_stmt|;
return|return
name|ann
condition|?
operator|(
name|stmt_vec_info
operator|)
name|ann
operator|->
name|common
operator|.
name|aux
else|:
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Info on data references alignment.                              */
end_comment

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Reflects actual alignment of first access in the vectorized loop,    taking into account peeling/versioning if applied.  */
end_comment

begin_define
define|#
directive|define
name|DR_MISALIGNMENT
parameter_list|(
name|DR
parameter_list|)
value|(DR)->aux
end_define

begin_function
specifier|static
specifier|inline
name|bool
name|aligned_access_p
parameter_list|(
name|struct
name|data_reference
modifier|*
name|data_ref_info
parameter_list|)
block|{
return|return
operator|(
name|DR_MISALIGNMENT
argument_list|(
name|data_ref_info
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|known_alignment_for_access_p
parameter_list|(
name|struct
name|data_reference
modifier|*
name|data_ref_info
parameter_list|)
block|{
return|return
operator|(
name|DR_MISALIGNMENT
argument_list|(
name|data_ref_info
argument_list|)
operator|!=
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Perform signed modulo, always returning a non-negative value.  */
end_comment

begin_define
define|#
directive|define
name|VECT_SMODULO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) % (y)< 0 ? ((x) % (y) + (y)) : (x) % (y))
end_define

begin_comment
comment|/* vect_dump will be set to stderr or dump_file if exist.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|vect_dump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|verbosity_levels
name|vect_verbosity_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of loops, at the beginning of vectorization.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|vect_loops_num
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bitmap of virtual variables to be renamed.  */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap
name|vect_vnames_to_rename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Function prototypes.                                            */
end_comment

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_comment
comment|/*************************************************************************   Simple Loop Peeling Utilities - in tree-vectorizer.c  *************************************************************************/
end_comment

begin_comment
comment|/* Entry point for peeling of simple loops.    Peel the first/last iterations of a loop.    It can be used outside of the vectorizer for loops that are simple enough    (see function documentation).  In the vectorizer it is used to peel the    last few iterations when the loop bound is unknown or does not evenly    divide by the vectorization factor, and to peel the first few iterations    to force the alignment of data references in the loop.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|loop
modifier|*
name|slpeel_tree_peel_loop_to_edge
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|loops
modifier|*
parameter_list|,
name|edge
parameter_list|,
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
name|slpeel_make_loop_iterate_ntimes
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
specifier|extern
name|bool
name|slpeel_can_duplicate_loop_p
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
end_ifdef

begin_function_decl
specifier|extern
name|void
name|slpeel_verify_cfg_after_peeling
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************************   General Vectorization Utilities  *************************************************************************/
end_comment

begin_comment
comment|/** In tree-vectorizer.c **/
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_vectype_for_scalar_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vect_is_simple_use
parameter_list|(
name|tree
parameter_list|,
name|loop_vec_info
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|enum
name|vect_def_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vect_is_simple_iv_evolution
parameter_list|(
name|unsigned
parameter_list|,
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
name|vect_is_simple_reduction
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
name|enum
name|dr_alignment_support
name|vect_supportable_dr_alignment
parameter_list|(
name|struct
name|data_reference
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|reduction_code_for_scalar_code
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|enum
name|tree_code
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Creation and deletion of loop and stmt info structs.  */
end_comment

begin_function_decl
specifier|extern
name|loop_vec_info
name|new_loop_vec_info
parameter_list|(
name|struct
name|loop
modifier|*
name|loop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_loop_vec_info
parameter_list|(
name|loop_vec_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|stmt_vec_info
name|new_stmt_vec_info
parameter_list|(
name|tree
name|stmt
parameter_list|,
name|loop_vec_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Main driver.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|vectorize_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** In tree-vect-analyze.c  **/
end_comment

begin_comment
comment|/* Driver for analysis stage.  */
end_comment

begin_function_decl
specifier|extern
name|loop_vec_info
name|vect_analyze_loop
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** In tree-vect-patterns.c  **/
end_comment

begin_comment
comment|/* Pattern recognition functions.    Additional pattern recognition functions can (and will) be added    in the future.  */
end_comment

begin_typedef
typedef|typedef
name|tree
function_decl|(
modifier|*
name|vect_recog_func_ptr
function_decl|)
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
end_typedef

begin_define
define|#
directive|define
name|NUM_PATTERNS
value|3
end_define

begin_function_decl
name|void
name|vect_pattern_recog
parameter_list|(
name|loop_vec_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** In tree-vect-transform.c  **/
end_comment

begin_function_decl
specifier|extern
name|bool
name|vectorizable_load
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vectorizable_store
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vectorizable_operation
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vectorizable_assignment
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vectorizable_condition
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vectorizable_live_operation
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vectorizable_reduction
parameter_list|(
name|tree
parameter_list|,
name|block_stmt_iterator
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Driver for transformation stage.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|vect_transform_loop
parameter_list|(
name|loop_vec_info
parameter_list|,
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************************   Vectorization Debug Information - in tree-vectorizer.c  *************************************************************************/
end_comment

begin_function_decl
specifier|extern
name|bool
name|vect_print_dump_info
parameter_list|(
name|enum
name|verbosity_levels
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vect_set_verbosity_level
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LOC
name|find_loop_location
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_VECTORIZER_H  */
end_comment

end_unit

