begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function integration definitions for GNU C-Compiler    Copyright (C) 1990, 1995, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_comment
comment|/* This structure is used to remap objects in the function being inlined to    those belonging to the calling function.  It is passed by    expand_inline_function to its children.     This structure is also used when unrolling loops and otherwise    replicating code, although not all fields are needed in this case;    only those fields needed by copy_rtx_and_substitute() and its children    are used.     This structure is used instead of static variables because    expand_inline_function may be called recursively via expand_expr.  */
end_comment

begin_struct
struct|struct
name|inline_remap
block|{
comment|/* True if we are doing function integration, false otherwise.      Used to control whether RTX_UNCHANGING bits are copied by      copy_rtx_and_substitute.  */
name|int
name|integrating
decl_stmt|;
comment|/* Definition of function be inlined.  */
name|union
name|tree_node
modifier|*
name|fndecl
decl_stmt|;
comment|/* Place to put insns needed at start of function.  */
name|rtx
name|insns_at_start
decl_stmt|;
comment|/* Mapping from old BLOCKs to new BLOCKs.  */
name|varray_type
name|block_map
decl_stmt|;
comment|/* Mapping from old registers to new registers.      It is allocated and deallocated in `expand_inline_function' */
name|rtx
modifier|*
name|reg_map
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|LEAF_REGISTERS
argument_list|)
operator|&&
name|defined
argument_list|(
name|LEAF_REG_REMAP
argument_list|)
comment|/* Mapping from old leaf registers to new leaf registers.  */
name|rtx
name|leaf_reg_map
index|[
name|FIRST_PSEUDO_REGISTER
index|]
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* Mapping from old code-labels to new code-labels.      The first element of this map is label_map[min_labelno].  */
name|rtx
modifier|*
name|label_map
decl_stmt|;
comment|/* Mapping from old insn uid's to copied insns.  The first element    of this map is insn_map[min_insnno]; the last element is    insn_map[max_insnno].  We keep the bounds here for when the map    only covers a partial range of insns (such as loop unrolling or    code replication).  */
name|rtx
modifier|*
name|insn_map
decl_stmt|;
name|int
name|min_insnno
decl_stmt|,
name|max_insnno
decl_stmt|;
comment|/* Map pseudo reg number in calling function to equivalent constant.  We      cannot in general substitute constants into parameter pseudo registers,      since some machine descriptions (many RISCs) won't always handle      the resulting insns.  So if an incoming parameter has a constant      equivalent, we record it here, and if the resulting insn is      recognizable, we go with it.       We also use this mechanism to convert references to incoming arguments      and stacked variables.  copy_rtx_and_substitute will replace the virtual      incoming argument and virtual stacked variables registers with new      pseudos that contain pointers into the replacement area allocated for      this inline instance.  These pseudos are then marked as being equivalent      to the appropriate address and substituted if valid.  */
name|varray_type
name|const_equiv_varray
decl_stmt|;
comment|/* This is incremented for each new basic block.      It is used to store in the age field to record the domain of validity      of each entry in const_equiv_varray.      A value of -1 indicates an entry for a reg which is a parm.      All other values are "positive".  */
define|#
directive|define
name|CONST_AGE_PARM
value|(-1)
name|unsigned
name|int
name|const_age
decl_stmt|;
comment|/* Target of the inline function being expanded, or NULL if none.  */
name|rtx
name|inline_target
decl_stmt|;
comment|/* When an insn is being copied by copy_rtx_and_substitute,      this is nonzero if we have copied an ASM_OPERANDS.      In that case, it is the original input-operand vector.  */
name|rtvec
name|orig_asm_operands_vector
decl_stmt|;
comment|/* When an insn is being copied by copy_rtx_and_substitute,      this is nonzero if we have copied an ASM_OPERANDS.      In that case, it is the copied input-operand vector.  */
name|rtvec
name|copy_asm_operands_vector
decl_stmt|;
comment|/* Likewise, this is the copied constraints vector.  */
name|rtvec
name|copy_asm_constraints_vector
decl_stmt|;
comment|/* Target of a return insn, if needed and inlining.  */
name|rtx
name|local_return_label
decl_stmt|;
comment|/* Indications for regs being pointers and their alignment.  */
name|unsigned
name|char
modifier|*
name|regno_pointer_align
decl_stmt|;
name|rtx
modifier|*
name|x_regno_reg_rtx
decl_stmt|;
comment|/* The next few fields are used for subst_constants to record the SETs      that it saw.  */
name|int
name|num_sets
decl_stmt|;
struct|struct
name|equiv_table
block|{
name|rtx
name|dest
decl_stmt|;
name|rtx
name|equiv
decl_stmt|;
block|}
name|equiv_sets
index|[
name|MAX_RECOG_OPERANDS
index|]
struct|;
comment|/* Record the last thing assigned to pc.  This is used for folded       conditional branch insns.  */
name|rtx
name|last_pc_value
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_cc0
comment|/* Record the last thing assigned to cc0.  */
name|rtx
name|last_cc0_value
decl_stmt|;
endif|#
directive|endif
comment|/* Note mode of COMPARE if the mode would be otherwise lost (comparing of      two VOIDmode constants.  */
name|rtx
name|compare_src
decl_stmt|;
name|enum
name|machine_mode
name|compare_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Return a copy of an rtx (as needed), substituting pseudo-register,    labels, and frame-pointer offsets as necessary.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_rtx_and_substitute
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|struct
name|inline_remap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a pseudo that corresponds to the value in the specified hard    reg as of the start of the function (for inlined functions, the    value at the start of the parent function).  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_hard_reg_initial_val
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise, but for a different than the current function, or    arbitrary expression.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_func_hard_reg_initial_val
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise, but iff someone else has caused it to become allocated.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|has_func_hard_reg_initial_val
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise, but for common cases.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|has_hard_reg_initial_val
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If a pseudo represents an initial hard reg (or expression), return    it, else return NULL_RTX.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_hard_reg_initial_reg
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is for GC.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_hard_reg_initial_vals
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called from rest_of_compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_initial_value_sets
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|allocate_initial_values
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy a declaration when one function is substituted inline into    another.  */
end_comment

begin_decl_stmt
specifier|extern
name|union
name|tree_node
modifier|*
name|copy_decl_for_inlining
name|PARAMS
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|,
expr|union
name|tree_node
operator|*
operator|,
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check whether there's any attribute in a function declaration that    makes the function uninlinable.  Returns false if it finds any,    true otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|function_attribute_inlinable_p
name|PARAMS
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|try_constants
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|struct
name|inline_remap
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the label indicated.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_label_from_map
name|PARAMS
argument_list|(
operator|(
expr|struct
name|inline_remap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the label indicated.  */
end_comment

begin_define
define|#
directive|define
name|set_label_in_map
parameter_list|(
name|MAP
parameter_list|,
name|I
parameter_list|,
name|X
parameter_list|)
value|((MAP)->label_map[I] = (X))
end_define

begin_comment
comment|/* Unfortunately, we need a global copy of const_equiv varray for    communication with a function called from note_stores.  Be *very*    careful that this is used properly in the presence of recursion.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|global_const_equiv_varray
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAYBE_EXTEND_CONST_EQUIV_VARRAY
parameter_list|(
name|MAP
parameter_list|,
name|MAX
parameter_list|)
define|\
value|{									\     if ((size_t)(MAX)>= VARRAY_SIZE ((MAP)->const_equiv_varray))	\       {									\         int is_global = (global_const_equiv_varray			\ 			 == (MAP)->const_equiv_varray);			\         VARRAY_GROW ((MAP)->const_equiv_varray, (MAX)+1);		\ 	if (is_global)							\ 	   global_const_equiv_varray = (MAP)->const_equiv_varray;	\       }									\   }
end_define

begin_define
define|#
directive|define
name|SET_CONST_EQUIV_DATA
parameter_list|(
name|MAP
parameter_list|,
name|REG
parameter_list|,
name|RTX
parameter_list|,
name|AGE
parameter_list|)
define|\
value|{									\     struct const_equiv_data *p;						\     MAYBE_EXTEND_CONST_EQUIV_VARRAY ((MAP), REGNO (REG));		\     p =&VARRAY_CONST_EQUIV ((MAP)->const_equiv_varray, REGNO (REG));	\     p->rtx = (RTX);							\     p->age = (AGE);							\   }
end_define

end_unit

