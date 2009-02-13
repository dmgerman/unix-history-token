begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data structures and function declarations for the SSA value propagation    engine.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.    Contributed by Diego Novillo<dnovillo@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TREE_SSA_PROPAGATE_H
end_ifndef

begin_define
define|#
directive|define
name|_TREE_SSA_PROPAGATE_H
value|1
end_define

begin_comment
comment|/* Use the TREE_VISITED bitflag to mark statements and PHI nodes that    have been deemed varying and should not be simulated again.  */
end_comment

begin_define
define|#
directive|define
name|DONT_SIMULATE_AGAIN
parameter_list|(
name|T
parameter_list|)
value|TREE_VISITED (T)
end_define

begin_comment
comment|/* Lattice values used for propagation purposes.  Specific instances    of a propagation engine must return these values from the statement    and PHI visit functions to direct the engine.  */
end_comment

begin_enum
enum|enum
name|ssa_prop_result
block|{
comment|/* The statement produces nothing of interest.  No edges will be        added to the work lists.  */
name|SSA_PROP_NOT_INTERESTING
block|,
comment|/* The statement produces an interesting value.  The set SSA_NAMEs        returned by SSA_PROP_VISIT_STMT should be added to        INTERESTING_SSA_EDGES.  If the statement being visited is a        conditional jump, SSA_PROP_VISIT_STMT should indicate which edge        out of the basic block should be marked executable.  */
name|SSA_PROP_INTERESTING
block|,
comment|/* The statement produces a varying (i.e., useless) value and        should not be simulated again.  If the statement being visited        is a conditional jump, all the edges coming out of the block        will be considered executable.  */
name|SSA_PROP_VARYING
block|}
enum|;
end_enum

begin_struct
struct|struct
name|prop_value_d
block|{
comment|/* Lattice value.  Each propagator is free to define its own        lattice and this field is only meaningful while propagating.        It will not be used by substitute_and_fold.  */
name|unsigned
name|lattice_val
decl_stmt|;
comment|/* Propagated value.  */
name|tree
name|value
decl_stmt|;
comment|/* If this value is held in an SSA name for a non-register        variable, this field holds the actual memory reference        associated with this value.  This field is taken from         the LHS of the assignment that generated the associated SSA        name.  However, in the case of PHI nodes, this field is copied        from the PHI arguments (assuming that all the arguments have        the same memory reference).  See replace_vuses_in for a more        detailed description.  */
name|tree
name|mem_ref
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|prop_value_d
name|prop_value_t
typedef|;
end_typedef

begin_comment
comment|/* Type of value ranges.  See value_range_d for a description of these    types.  */
end_comment

begin_enum
enum|enum
name|value_range_type
block|{
name|VR_UNDEFINED
block|,
name|VR_RANGE
block|,
name|VR_ANTI_RANGE
block|,
name|VR_VARYING
block|}
enum|;
end_enum

begin_comment
comment|/* Range of values that can be associated with an SSA_NAME after VRP    has executed.  */
end_comment

begin_struct
struct|struct
name|value_range_d
block|{
comment|/* Lattice value represented by this range.  */
name|enum
name|value_range_type
name|type
decl_stmt|;
comment|/* Minimum and maximum values represented by this range.  These      values should be interpreted as follows:  	- If TYPE is VR_UNDEFINED or VR_VARYING then MIN and MAX must 	  be NULL.  	- If TYPE == VR_RANGE then MIN holds the minimum value and 	  MAX holds the maximum value of the range [MIN, MAX].  	- If TYPE == ANTI_RANGE the variable is known to NOT 	  take any values in the range [MIN, MAX].  */
name|tree
name|min
decl_stmt|;
name|tree
name|max
decl_stmt|;
comment|/* Set of SSA names whose value ranges are equivalent to this one.      This set is only valid when TYPE is VR_RANGE or VR_ANTI_RANGE.  */
name|bitmap
name|equiv
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|value_range_d
name|value_range_t
typedef|;
end_typedef

begin_comment
comment|/* Call-back functions used by the value propagation engine.  */
end_comment

begin_typedef
typedef|typedef
name|enum
name|ssa_prop_result
function_decl|(
modifier|*
name|ssa_prop_visit_stmt_fn
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|edge
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|ssa_prop_result
function_decl|(
modifier|*
name|ssa_prop_visit_phi_fn
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* In tree-ssa-propagate.c  */
end_comment

begin_function_decl
name|void
name|ssa_propagate
parameter_list|(
name|ssa_prop_visit_stmt_fn
parameter_list|,
name|ssa_prop_visit_phi_fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_rhs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|set_rhs
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|first_vdef
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|stmt_makes_single_load
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|stmt_makes_single_store
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prop_value_t
modifier|*
name|get_value_loaded_by
parameter_list|(
name|tree
parameter_list|,
name|prop_value_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|replace_uses_in
parameter_list|(
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|prop_value_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|substitute_and_fold
parameter_list|(
name|prop_value_t
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TREE_SSA_PROPAGATE_H  */
end_comment

end_unit

