begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data references and dependences detectors.     Copyright (C) 2003, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Sebastian Pop<pop@cri.ensmp.fr>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_DATA_REF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_DATA_REF_H
end_define

begin_include
include|#
directive|include
file|"lambda.h"
end_include

begin_comment
comment|/** {base_address + offset + init} is the first location accessed by data-ref        in the loop, and step is the stride of data-ref in the loop in bytes;       e.g.:                             Example 1                      Example 2       data-ref         a[j].b[i][j]                   a + x + 16B (a is int*)        First location info:       base_address&a                             a       offset           j_0*D_j + i_0*D_i + C_a        x       init             C_b                            16       step             D_j                            4       access_fn        NULL                           {16, +, 1}  Base object info:       base_object      a                              NULL       access_fn<access_fns of indexes of b>   NULL    **/
end_comment

begin_struct
struct|struct
name|first_location_in_loop
block|{
name|tree
name|base_address
decl_stmt|;
name|tree
name|offset
decl_stmt|;
name|tree
name|init
decl_stmt|;
name|tree
name|step
decl_stmt|;
comment|/* Access function related to first location in the loop.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
operator|*
name|access_fns
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|base_object_info
block|{
comment|/* The object.  */
name|tree
name|base_object
decl_stmt|;
comment|/* A list of chrecs.  Access functions related to BASE_OBJECT.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
operator|*
name|access_fns
expr_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|data_ref_type
block|{
name|ARRAY_REF_TYPE
block|,
name|POINTER_REF_TYPE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|data_reference
block|{
comment|/* A pointer to the statement that contains this DR.  */
name|tree
name|stmt
decl_stmt|;
comment|/* A pointer to the ARRAY_REF node.  */
name|tree
name|ref
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|int
name|aux
decl_stmt|;
comment|/* True when the data reference is in RHS of a stmt.  */
name|bool
name|is_read
decl_stmt|;
comment|/* First location accessed by the data-ref in the loop.  */
name|struct
name|first_location_in_loop
name|first_location
decl_stmt|;
comment|/* Base object related info.  */
name|struct
name|base_object_info
name|object_info
decl_stmt|;
comment|/* Aliasing information.  This field represents the symbol that      should be aliased by a pointer holding the address of this data      reference.  If the original data reference was a pointer      dereference, then this field contains the memory tag that should      be used by the new vector-pointer.  */
name|tree
name|memtag
decl_stmt|;
name|struct
name|ptr_info_def
modifier|*
name|ptr_info
decl_stmt|;
name|subvar_t
name|subvars
decl_stmt|;
comment|/* Alignment information.  */
comment|/* The offset of the data-reference from its base in bytes.  */
name|tree
name|misalignment
decl_stmt|;
comment|/* The maximum data-ref's alignment.  */
name|tree
name|aligned_to
decl_stmt|;
comment|/* The type of the data-ref.  */
name|enum
name|data_ref_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|data_reference
modifier|*
name|data_reference_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|data_reference_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|data_reference_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DR_STMT
parameter_list|(
name|DR
parameter_list|)
value|(DR)->stmt
end_define

begin_define
define|#
directive|define
name|DR_REF
parameter_list|(
name|DR
parameter_list|)
value|(DR)->ref
end_define

begin_define
define|#
directive|define
name|DR_BASE_OBJECT
parameter_list|(
name|DR
parameter_list|)
value|(DR)->object_info.base_object
end_define

begin_define
define|#
directive|define
name|DR_TYPE
parameter_list|(
name|DR
parameter_list|)
value|(DR)->type
end_define

begin_define
define|#
directive|define
name|DR_ACCESS_FNS
parameter_list|(
name|DR
parameter_list|)
define|\
value|(DR_TYPE(DR) == ARRAY_REF_TYPE ?  \    (DR)->object_info.access_fns : (DR)->first_location.access_fns)
end_define

begin_define
define|#
directive|define
name|DR_ACCESS_FN
parameter_list|(
name|DR
parameter_list|,
name|I
parameter_list|)
value|VEC_index (tree, DR_ACCESS_FNS (DR), I)
end_define

begin_define
define|#
directive|define
name|DR_NUM_DIMENSIONS
parameter_list|(
name|DR
parameter_list|)
value|VEC_length (tree, DR_ACCESS_FNS (DR))
end_define

begin_define
define|#
directive|define
name|DR_IS_READ
parameter_list|(
name|DR
parameter_list|)
value|(DR)->is_read
end_define

begin_define
define|#
directive|define
name|DR_BASE_ADDRESS
parameter_list|(
name|DR
parameter_list|)
value|(DR)->first_location.base_address
end_define

begin_define
define|#
directive|define
name|DR_OFFSET
parameter_list|(
name|DR
parameter_list|)
value|(DR)->first_location.offset
end_define

begin_define
define|#
directive|define
name|DR_INIT
parameter_list|(
name|DR
parameter_list|)
value|(DR)->first_location.init
end_define

begin_define
define|#
directive|define
name|DR_STEP
parameter_list|(
name|DR
parameter_list|)
value|(DR)->first_location.step
end_define

begin_define
define|#
directive|define
name|DR_MEMTAG
parameter_list|(
name|DR
parameter_list|)
value|(DR)->memtag
end_define

begin_define
define|#
directive|define
name|DR_ALIGNED_TO
parameter_list|(
name|DR
parameter_list|)
value|(DR)->aligned_to
end_define

begin_define
define|#
directive|define
name|DR_OFFSET_MISALIGNMENT
parameter_list|(
name|DR
parameter_list|)
value|(DR)->misalignment
end_define

begin_define
define|#
directive|define
name|DR_PTR_INFO
parameter_list|(
name|DR
parameter_list|)
value|(DR)->ptr_info
end_define

begin_define
define|#
directive|define
name|DR_SUBVARS
parameter_list|(
name|DR
parameter_list|)
value|(DR)->subvars
end_define

begin_define
define|#
directive|define
name|DR_ACCESS_FNS_ADDR
parameter_list|(
name|DR
parameter_list|)
define|\
value|(DR_TYPE(DR) == ARRAY_REF_TYPE ?   \&((DR)->object_info.access_fns) :&((DR)->first_location.access_fns))
end_define

begin_define
define|#
directive|define
name|DR_SET_ACCESS_FNS
parameter_list|(
name|DR
parameter_list|,
name|ACC_FNS
parameter_list|)
define|\
value|{                                              \   if (DR_TYPE(DR) == ARRAY_REF_TYPE)           \     (DR)->object_info.access_fns = ACC_FNS;    \   else                                         \     (DR)->first_location.access_fns = ACC_FNS; \ }
end_define

begin_define
define|#
directive|define
name|DR_FREE_ACCESS_FNS
parameter_list|(
name|DR
parameter_list|)
define|\
value|{                                                           \   if (DR_TYPE(DR) == ARRAY_REF_TYPE)                        \     VEC_free (tree, heap, (DR)->object_info.access_fns);    \   else                                                      \     VEC_free (tree, heap, (DR)->first_location.access_fns); \ }
end_define

begin_enum
enum|enum
name|data_dependence_direction
block|{
name|dir_positive
block|,
name|dir_negative
block|,
name|dir_equal
block|,
name|dir_positive_or_negative
block|,
name|dir_positive_or_equal
block|,
name|dir_negative_or_equal
block|,
name|dir_star
block|,
name|dir_independent
block|}
enum|;
end_enum

begin_comment
comment|/* What is a subscript?  Given two array accesses a subscript is the    tuple composed of the access functions for a given dimension.    Example: Given A[f1][f2][f3] and B[g1][g2][g3], there are three    subscripts: (f1, g1), (f2, g2), (f3, g3).  These three subscripts    are stored in the data_dependence_relation structure under the form    of an array of subscripts.  */
end_comment

begin_struct
struct|struct
name|subscript
block|{
comment|/* A description of the iterations for which the elements are      accessed twice.  */
name|tree
name|conflicting_iterations_in_a
decl_stmt|;
name|tree
name|conflicting_iterations_in_b
decl_stmt|;
comment|/* This field stores the information about the iteration domain      validity of the dependence relation.  */
name|tree
name|last_conflict
decl_stmt|;
comment|/* Distance from the iteration that access a conflicting element in      A to the iteration that access this same conflicting element in      B.  The distance is a tree scalar expression, i.e. a constant or a      symbolic expression, but certainly not a chrec function.  */
name|tree
name|distance
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|subscript
modifier|*
name|subscript_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|subscript_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|subscript_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SUB_CONFLICTS_IN_A
parameter_list|(
name|SUB
parameter_list|)
value|SUB->conflicting_iterations_in_a
end_define

begin_define
define|#
directive|define
name|SUB_CONFLICTS_IN_B
parameter_list|(
name|SUB
parameter_list|)
value|SUB->conflicting_iterations_in_b
end_define

begin_define
define|#
directive|define
name|SUB_LAST_CONFLICT
parameter_list|(
name|SUB
parameter_list|)
value|SUB->last_conflict
end_define

begin_define
define|#
directive|define
name|SUB_DISTANCE
parameter_list|(
name|SUB
parameter_list|)
value|SUB->distance
end_define

begin_typedef
typedef|typedef
name|struct
name|loop
modifier|*
name|loop_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|loop_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|loop_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* A data_dependence_relation represents a relation between two    data_references A and B.  */
end_comment

begin_struct
struct|struct
name|data_dependence_relation
block|{
name|struct
name|data_reference
modifier|*
name|a
decl_stmt|;
name|struct
name|data_reference
modifier|*
name|b
decl_stmt|;
comment|/* When the dependence relation is affine, it can be represented by      a distance vector.  */
name|bool
name|affine_p
decl_stmt|;
comment|/* A "yes/no/maybe" field for the dependence relation:            - when "ARE_DEPENDENT == NULL_TREE", there exist a dependence        relation between A and B, and the description of this relation        is given in the SUBSCRIPTS array,            - when "ARE_DEPENDENT == chrec_known", there is no dependence and        SUBSCRIPTS is empty,            - when "ARE_DEPENDENT == chrec_dont_know", there may be a dependence,        but the analyzer cannot be more specific.  */
name|tree
name|are_dependent
decl_stmt|;
comment|/* For each subscript in the dependence test, there is an element in      this array.  This is the attribute that labels the edge A->B of      the data_dependence_relation.  */
name|VEC
argument_list|(
name|subscript_p
argument_list|,
name|heap
argument_list|)
operator|*
name|subscripts
expr_stmt|;
comment|/* The analyzed loop nest.  */
name|VEC
argument_list|(
name|loop_p
argument_list|,
name|heap
argument_list|)
operator|*
name|loop_nest
expr_stmt|;
comment|/* The classic direction vector.  */
name|VEC
argument_list|(
name|lambda_vector
argument_list|,
name|heap
argument_list|)
operator|*
name|dir_vects
expr_stmt|;
comment|/* The classic distance vector.  */
name|VEC
argument_list|(
name|lambda_vector
argument_list|,
name|heap
argument_list|)
operator|*
name|dist_vects
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|data_dependence_relation
modifier|*
name|ddr_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|ddr_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DDR_A
parameter_list|(
name|DDR
parameter_list|)
value|DDR->a
end_define

begin_define
define|#
directive|define
name|DDR_B
parameter_list|(
name|DDR
parameter_list|)
value|DDR->b
end_define

begin_define
define|#
directive|define
name|DDR_AFFINE_P
parameter_list|(
name|DDR
parameter_list|)
value|DDR->affine_p
end_define

begin_define
define|#
directive|define
name|DDR_ARE_DEPENDENT
parameter_list|(
name|DDR
parameter_list|)
value|DDR->are_dependent
end_define

begin_define
define|#
directive|define
name|DDR_SUBSCRIPTS
parameter_list|(
name|DDR
parameter_list|)
value|DDR->subscripts
end_define

begin_define
define|#
directive|define
name|DDR_SUBSCRIPT
parameter_list|(
name|DDR
parameter_list|,
name|I
parameter_list|)
value|VEC_index (subscript_p, DDR_SUBSCRIPTS (DDR), I)
end_define

begin_define
define|#
directive|define
name|DDR_NUM_SUBSCRIPTS
parameter_list|(
name|DDR
parameter_list|)
value|VEC_length (subscript_p, DDR_SUBSCRIPTS (DDR))
end_define

begin_define
define|#
directive|define
name|DDR_LOOP_NEST
parameter_list|(
name|DDR
parameter_list|)
value|DDR->loop_nest
end_define

begin_comment
comment|/* The size of the direction/distance vectors: the number of loops in    the loop nest.  */
end_comment

begin_define
define|#
directive|define
name|DDR_NB_LOOPS
parameter_list|(
name|DDR
parameter_list|)
value|(VEC_length (loop_p, DDR_LOOP_NEST (DDR)))
end_define

begin_define
define|#
directive|define
name|DDR_DIST_VECTS
parameter_list|(
name|DDR
parameter_list|)
value|((DDR)->dist_vects)
end_define

begin_define
define|#
directive|define
name|DDR_DIR_VECTS
parameter_list|(
name|DDR
parameter_list|)
value|((DDR)->dir_vects)
end_define

begin_define
define|#
directive|define
name|DDR_NUM_DIST_VECTS
parameter_list|(
name|DDR
parameter_list|)
define|\
value|(VEC_length (lambda_vector, DDR_DIST_VECTS (DDR)))
end_define

begin_define
define|#
directive|define
name|DDR_NUM_DIR_VECTS
parameter_list|(
name|DDR
parameter_list|)
define|\
value|(VEC_length (lambda_vector, DDR_DIR_VECTS (DDR)))
end_define

begin_define
define|#
directive|define
name|DDR_DIR_VECT
parameter_list|(
name|DDR
parameter_list|,
name|I
parameter_list|)
define|\
value|VEC_index (lambda_vector, DDR_DIR_VECTS (DDR), I)
end_define

begin_define
define|#
directive|define
name|DDR_DIST_VECT
parameter_list|(
name|DDR
parameter_list|,
name|I
parameter_list|)
define|\
value|VEC_index (lambda_vector, DDR_DIST_VECTS (DDR), I)
end_define

begin_escape
end_escape

begin_decl_stmt
specifier|extern
name|tree
name|find_data_references_in_loop
argument_list|(
expr|struct
name|loop
operator|*
argument_list|,
name|VEC
argument_list|(
name|data_reference_p
argument_list|,
name|heap
argument_list|)
operator|*
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|compute_data_dependences_for_loop
argument_list|(
expr|struct
name|loop
operator|*
argument_list|,
name|bool
argument_list|,
name|VEC
argument_list|(
name|data_reference_p
argument_list|,
name|heap
argument_list|)
operator|*
operator|*
argument_list|,
name|VEC
argument_list|(
name|ddr_p
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
name|print_direction_vector
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|lambda_vector
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|print_dir_vectors
argument_list|(
name|FILE
operator|*
argument_list|,
name|VEC
argument_list|(
name|lambda_vector
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_dist_vectors
argument_list|(
name|FILE
operator|*
argument_list|,
name|VEC
argument_list|(
name|lambda_vector
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|dump_subscript
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|subscript
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|dump_ddrs
argument_list|(
name|FILE
operator|*
argument_list|,
name|VEC
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_dist_dir_vectors
argument_list|(
name|FILE
operator|*
argument_list|,
name|VEC
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|dump_data_reference
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|data_reference
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|dump_data_references
argument_list|(
name|FILE
operator|*
argument_list|,
name|VEC
argument_list|(
name|data_reference_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|debug_data_dependence_relation
parameter_list|(
name|struct
name|data_dependence_relation
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_data_dependence_relation
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|data_dependence_relation
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|dump_data_dependence_relations
argument_list|(
name|FILE
operator|*
argument_list|,
name|VEC
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|dump_data_dependence_direction
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|enum
name|data_dependence_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_dependence_relation
parameter_list|(
name|struct
name|data_dependence_relation
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|free_dependence_relations
argument_list|(
name|VEC
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_data_refs
argument_list|(
name|VEC
argument_list|(
name|data_reference_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|data_reference
modifier|*
name|analyze_array
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
name|estimate_iters_using_array
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the index of the variable VAR in the LOOP_NEST array.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|index_in_loop_nest
argument_list|(
name|int
name|var
argument_list|,
name|VEC
argument_list|(
name|loop_p
argument_list|,
name|heap
argument_list|)
operator|*
name|loop_nest
argument_list|)
block|{
name|struct
name|loop
modifier|*
name|loopi
decl_stmt|;
name|int
name|var_index
decl_stmt|;
for|for
control|(
name|var_index
operator|=
literal|0
init|;
name|VEC_iterate
argument_list|(
name|loop_p
argument_list|,
name|loop_nest
argument_list|,
name|var_index
argument_list|,
name|loopi
argument_list|)
condition|;
name|var_index
operator|++
control|)
if|if
condition|(
name|loopi
operator|->
name|num
operator|==
name|var
condition|)
break|break;
return|return
name|var_index
return|;
block|}
end_decl_stmt

begin_comment
comment|/* In lambda-code.c  */
end_comment

begin_decl_stmt
name|bool
name|lambda_transform_legal_p
argument_list|(
name|lambda_trans_matrix
argument_list|,
name|int
argument_list|,
name|VEC
argument_list|(
name|ddr_p
argument_list|,
name|heap
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_DATA_REF_H  */
end_comment

end_unit

