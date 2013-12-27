begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tree based points-to analysis    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Daniel Berlin<dberlin@dberlin.org>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TREE_SSA_STRUCTALIAS_H
end_ifndef

begin_define
define|#
directive|define
name|TREE_SSA_STRUCTALIAS_H
end_define

begin_comment
comment|/* True if the data pointed to by PTR can alias anything.  */
end_comment

begin_define
define|#
directive|define
name|PTR_IS_REF_ALL
parameter_list|(
name|PTR
parameter_list|)
value|TYPE_REF_CAN_ALIAS_ALL (TREE_TYPE (PTR))
end_define

begin_struct_decl
struct_decl|struct
name|constraint
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|constraint
modifier|*
name|constraint_t
typedef|;
end_typedef

begin_comment
comment|/* Alias information used by compute_may_aliases and its helpers.  */
end_comment

begin_struct
struct|struct
name|alias_info
block|{
comment|/* SSA names visited while collecting points-to information.  If bit I      is set, it means that SSA variable with version I has already been      visited.  */
name|sbitmap
name|ssa_names_visited
decl_stmt|;
comment|/* Array of SSA_NAME pointers processed by the points-to collector.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
operator|*
name|processed_ptrs
expr_stmt|;
comment|/* ADDRESSABLE_VARS contains all the global variables and locals that      have had their address taken.  */
name|struct
name|alias_map_d
modifier|*
modifier|*
name|addressable_vars
decl_stmt|;
name|size_t
name|num_addressable_vars
decl_stmt|;
comment|/* POINTERS contains all the _DECL pointers with unique memory tags      that have been referenced in the program.  */
name|struct
name|alias_map_d
modifier|*
modifier|*
name|pointers
decl_stmt|;
name|size_t
name|num_pointers
decl_stmt|;
comment|/* Number of function calls found in the program.  */
name|size_t
name|num_calls_found
decl_stmt|;
comment|/* Number of const/pure function calls found in the program.  */
name|size_t
name|num_pure_const_calls_found
decl_stmt|;
comment|/* Total number of virtual operands that will be needed to represent      all the aliases of all the pointers found in the program.  */
name|long
name|total_alias_vops
decl_stmt|;
comment|/* Variables that have been written to.  */
name|bitmap
name|written_vars
decl_stmt|;
comment|/* Pointers that have been used in an indirect store operation.  */
name|bitmap
name|dereferenced_ptrs_store
decl_stmt|;
comment|/* Pointers that have been used in an indirect load operation.  */
name|bitmap
name|dereferenced_ptrs_load
decl_stmt|;
comment|/* Memory tag for all the PTR_IS_REF_ALL pointers.  */
name|tree
name|ref_all_symbol_mem_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep track of how many times each pointer has been dereferenced in    the program using the aux variable.  This is used by the alias    grouping heuristic in compute_flow_insensitive_aliasing.  */
end_comment

begin_define
define|#
directive|define
name|NUM_REFERENCES
parameter_list|(
name|ANN
parameter_list|)
value|((size_t)((ANN)->common.aux))
end_define

begin_define
define|#
directive|define
name|NUM_REFERENCES_CLEAR
parameter_list|(
name|ANN
parameter_list|)
value|((ANN)->common.aux) = 0
end_define

begin_define
define|#
directive|define
name|NUM_REFERENCES_INC
parameter_list|(
name|ANN
parameter_list|)
value|(ANN)->common.aux = (void*) (((size_t)((ANN)->common.aux)) + 1)
end_define

begin_define
define|#
directive|define
name|NUM_REFERENCES_SET
parameter_list|(
name|ANN
parameter_list|,
name|VAL
parameter_list|)
value|(ANN)->common.aux = (void*) ((void *)(VAL))
end_define

begin_comment
comment|/* In tree-ssa-alias.c.  */
end_comment

begin_function_decl
name|enum
name|escape_type
name|is_escape_site
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-ssa-structalias.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|compute_points_to_sets
parameter_list|(
name|struct
name|alias_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_points_to_sets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_constraint
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|constraint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_constraints
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_constraint
parameter_list|(
name|constraint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_constraints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_solution_for_var
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_solution_for_var
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_sa_points_to_info
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_sa_points_to_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TREE_SSA_STRUCTALIAS_H  */
end_comment

end_unit

