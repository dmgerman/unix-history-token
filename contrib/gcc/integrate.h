begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function integration definitions for GNU C-Compiler    Copyright (C) 1990, 1995, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* True if we are doing function integration, false otherwise.      Used to control whether RTX_UNCHANGING bits are copied by      copy_rtx_and_substitute. */
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
comment|/* Mapping from old registers to new registers.      It is allocated and deallocated in `expand_inline_function' */
name|rtx
modifier|*
name|reg_map
decl_stmt|;
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
comment|/* Indications for regs being pointers and their alignment.  */
name|char
modifier|*
name|regno_pointer_flag
decl_stmt|;
name|char
modifier|*
name|regno_pointer_align
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
name|PROTO
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

begin_decl_stmt
specifier|extern
name|void
name|try_constants
name|PROTO
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

begin_decl_stmt
specifier|extern
name|void
name|mark_stores
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
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
name|PROTO
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
value|{									\     if ((MAX)>= VARRAY_SIZE ((MAP)->const_equiv_varray))		\       {									\         int is_global = (global_const_equiv_varray			\ 			 == (MAP)->const_equiv_varray);			\         VARRAY_GROW ((MAP)->const_equiv_varray, (MAX)+1);		\ 	if (is_global)							\ 	   global_const_equiv_varray = (MAP)->const_equiv_varray;	\       }									\   }
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

