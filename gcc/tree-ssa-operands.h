begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SSA operand management for trees.    Copyright (C) 2003, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_SSA_OPERANDS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_SSA_OPERANDS_H
end_define

begin_comment
comment|/* Interface to SSA operands.  */
end_comment

begin_comment
comment|/* This represents a pointer to a DEF operand.  */
end_comment

begin_typedef
typedef|typedef
name|tree
modifier|*
name|def_operand_p
typedef|;
end_typedef

begin_comment
comment|/* This represents a pointer to a USE operand.  */
end_comment

begin_typedef
typedef|typedef
name|ssa_use_operand_t
modifier|*
name|use_operand_p
typedef|;
end_typedef

begin_comment
comment|/* NULL operand types.  */
end_comment

begin_define
define|#
directive|define
name|NULL_USE_OPERAND_P
value|NULL
end_define

begin_define
define|#
directive|define
name|NULL_DEF_OPERAND_P
value|NULL
end_define

begin_comment
comment|/* This represents the DEF operands of a stmt.  */
end_comment

begin_struct
struct|struct
name|def_optype_d
block|{
name|struct
name|def_optype_d
modifier|*
name|next
decl_stmt|;
name|tree
modifier|*
name|def_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|def_optype_d
modifier|*
name|def_optype_p
typedef|;
end_typedef

begin_comment
comment|/* This represents the USE operands of a stmt.  */
end_comment

begin_struct
struct|struct
name|use_optype_d
block|{
name|struct
name|use_optype_d
modifier|*
name|next
decl_stmt|;
name|struct
name|ssa_use_operand_d
name|use_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|use_optype_d
modifier|*
name|use_optype_p
typedef|;
end_typedef

begin_comment
comment|/* This represents the MAY_DEFS for a stmt.  */
end_comment

begin_struct
struct|struct
name|maydef_optype_d
block|{
name|struct
name|maydef_optype_d
modifier|*
name|next
decl_stmt|;
name|tree
name|def_var
decl_stmt|;
name|tree
name|use_var
decl_stmt|;
name|struct
name|ssa_use_operand_d
name|use_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|maydef_optype_d
modifier|*
name|maydef_optype_p
typedef|;
end_typedef

begin_comment
comment|/* This represents the VUSEs for a stmt.  */
end_comment

begin_struct
struct|struct
name|vuse_optype_d
block|{
name|struct
name|vuse_optype_d
modifier|*
name|next
decl_stmt|;
name|tree
name|use_var
decl_stmt|;
name|struct
name|ssa_use_operand_d
name|use_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vuse_optype_d
modifier|*
name|vuse_optype_p
typedef|;
end_typedef

begin_comment
comment|/* This represents the V_MUST_DEFS for a stmt.  */
end_comment

begin_struct
struct|struct
name|mustdef_optype_d
block|{
name|struct
name|mustdef_optype_d
modifier|*
name|next
decl_stmt|;
name|tree
name|def_var
decl_stmt|;
name|tree
name|kill_var
decl_stmt|;
name|struct
name|ssa_use_operand_d
name|use_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mustdef_optype_d
modifier|*
name|mustdef_optype_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SSA_OPERAND_MEMORY_SIZE
value|(2048 - sizeof (void *))
end_define

begin_decl_stmt
name|struct
name|ssa_operand_memory_d
name|GTY
argument_list|(
operator|(
name|chain_next
argument_list|(
literal|"%h.next"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|ssa_operand_memory_d
modifier|*
name|next
decl_stmt|;
name|char
name|mem
index|[
name|SSA_OPERAND_MEMORY_SIZE
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* This represents the operand cache for a stmt.  */
end_comment

begin_struct
struct|struct
name|stmt_operands_d
block|{
comment|/* Statement operands.  */
name|struct
name|def_optype_d
modifier|*
name|def_ops
decl_stmt|;
name|struct
name|use_optype_d
modifier|*
name|use_ops
decl_stmt|;
comment|/* Virtual operands (V_MAY_DEF, VUSE, and V_MUST_DEF).  */
name|struct
name|maydef_optype_d
modifier|*
name|maydef_ops
decl_stmt|;
name|struct
name|vuse_optype_d
modifier|*
name|vuse_ops
decl_stmt|;
name|struct
name|mustdef_optype_d
modifier|*
name|mustdef_ops
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stmt_operands_d
modifier|*
name|stmt_operands_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USE_FROM_PTR
parameter_list|(
name|PTR
parameter_list|)
value|get_use_from_ptr (PTR)
end_define

begin_define
define|#
directive|define
name|DEF_FROM_PTR
parameter_list|(
name|PTR
parameter_list|)
value|get_def_from_ptr (PTR)
end_define

begin_define
define|#
directive|define
name|SET_USE
parameter_list|(
name|USE
parameter_list|,
name|V
parameter_list|)
value|set_ssa_use_from_ptr (USE, V)
end_define

begin_define
define|#
directive|define
name|SET_DEF
parameter_list|(
name|DEF
parameter_list|,
name|V
parameter_list|)
value|((*(DEF)) = (V))
end_define

begin_define
define|#
directive|define
name|USE_STMT
parameter_list|(
name|USE
parameter_list|)
value|(USE)->stmt
end_define

begin_define
define|#
directive|define
name|DEF_OPS
parameter_list|(
name|STMT
parameter_list|)
value|(stmt_ann (STMT)->operands.def_ops)
end_define

begin_define
define|#
directive|define
name|USE_OPS
parameter_list|(
name|STMT
parameter_list|)
value|(stmt_ann (STMT)->operands.use_ops)
end_define

begin_define
define|#
directive|define
name|VUSE_OPS
parameter_list|(
name|STMT
parameter_list|)
value|(stmt_ann (STMT)->operands.vuse_ops)
end_define

begin_define
define|#
directive|define
name|MAYDEF_OPS
parameter_list|(
name|STMT
parameter_list|)
value|(stmt_ann (STMT)->operands.maydef_ops)
end_define

begin_define
define|#
directive|define
name|MUSTDEF_OPS
parameter_list|(
name|STMT
parameter_list|)
value|(stmt_ann (STMT)->operands.mustdef_ops)
end_define

begin_define
define|#
directive|define
name|USE_OP_PTR
parameter_list|(
name|OP
parameter_list|)
value|(&((OP)->use_ptr))
end_define

begin_define
define|#
directive|define
name|USE_OP
parameter_list|(
name|OP
parameter_list|)
value|(USE_FROM_PTR (USE_OP_PTR (OP)))
end_define

begin_define
define|#
directive|define
name|DEF_OP_PTR
parameter_list|(
name|OP
parameter_list|)
value|((OP)->def_ptr)
end_define

begin_define
define|#
directive|define
name|DEF_OP
parameter_list|(
name|OP
parameter_list|)
value|(DEF_FROM_PTR (DEF_OP_PTR (OP)))
end_define

begin_define
define|#
directive|define
name|VUSE_OP_PTR
parameter_list|(
name|OP
parameter_list|)
value|USE_OP_PTR(OP)
end_define

begin_define
define|#
directive|define
name|VUSE_OP
parameter_list|(
name|OP
parameter_list|)
value|((OP)->use_var)
end_define

begin_define
define|#
directive|define
name|MAYDEF_RESULT_PTR
parameter_list|(
name|OP
parameter_list|)
value|(&((OP)->def_var))
end_define

begin_define
define|#
directive|define
name|MAYDEF_RESULT
parameter_list|(
name|OP
parameter_list|)
value|((OP)->def_var)
end_define

begin_define
define|#
directive|define
name|MAYDEF_OP_PTR
parameter_list|(
name|OP
parameter_list|)
value|USE_OP_PTR (OP)
end_define

begin_define
define|#
directive|define
name|MAYDEF_OP
parameter_list|(
name|OP
parameter_list|)
value|((OP)->use_var)
end_define

begin_define
define|#
directive|define
name|MUSTDEF_RESULT_PTR
parameter_list|(
name|OP
parameter_list|)
value|(&((OP)->def_var))
end_define

begin_define
define|#
directive|define
name|MUSTDEF_RESULT
parameter_list|(
name|OP
parameter_list|)
value|((OP)->def_var)
end_define

begin_define
define|#
directive|define
name|MUSTDEF_KILL_PTR
parameter_list|(
name|OP
parameter_list|)
value|USE_OP_PTR (OP)
end_define

begin_define
define|#
directive|define
name|MUSTDEF_KILL
parameter_list|(
name|OP
parameter_list|)
value|((OP)->kill_var)
end_define

begin_define
define|#
directive|define
name|PHI_RESULT_PTR
parameter_list|(
name|PHI
parameter_list|)
value|get_phi_result_ptr (PHI)
end_define

begin_define
define|#
directive|define
name|PHI_RESULT
parameter_list|(
name|PHI
parameter_list|)
value|DEF_FROM_PTR (PHI_RESULT_PTR (PHI))
end_define

begin_define
define|#
directive|define
name|SET_PHI_RESULT
parameter_list|(
name|PHI
parameter_list|,
name|V
parameter_list|)
value|SET_DEF (PHI_RESULT_PTR (PHI), (V))
end_define

begin_define
define|#
directive|define
name|PHI_ARG_DEF_PTR
parameter_list|(
name|PHI
parameter_list|,
name|I
parameter_list|)
value|get_phi_arg_def_ptr ((PHI), (I))
end_define

begin_define
define|#
directive|define
name|PHI_ARG_DEF
parameter_list|(
name|PHI
parameter_list|,
name|I
parameter_list|)
value|USE_FROM_PTR (PHI_ARG_DEF_PTR ((PHI), (I)))
end_define

begin_define
define|#
directive|define
name|SET_PHI_ARG_DEF
parameter_list|(
name|PHI
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
define|\
value|SET_USE (PHI_ARG_DEF_PTR ((PHI), (I)), (V))
end_define

begin_define
define|#
directive|define
name|PHI_ARG_DEF_FROM_EDGE
parameter_list|(
name|PHI
parameter_list|,
name|E
parameter_list|)
define|\
value|PHI_ARG_DEF ((PHI), (E)->dest_idx)
end_define

begin_define
define|#
directive|define
name|PHI_ARG_DEF_PTR_FROM_EDGE
parameter_list|(
name|PHI
parameter_list|,
name|E
parameter_list|)
define|\
value|PHI_ARG_DEF_PTR ((PHI), (E)->dest_idx)
end_define

begin_define
define|#
directive|define
name|PHI_ARG_INDEX_FROM_USE
parameter_list|(
name|USE
parameter_list|)
value|phi_arg_index_from_use (USE)
end_define

begin_function_decl
specifier|extern
name|void
name|init_ssa_operands
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fini_ssa_operands
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_ssa_operands
parameter_list|(
name|stmt_operands_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_stmt_operands
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|verify_imm_links
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|tree
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copy_virtual_operands
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
name|create_ssa_artficial_load_stmt
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
name|dump_immediate_uses
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_immediate_uses_for
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|tree
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_immediate_uses
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_immediate_uses_for
parameter_list|(
name|tree
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|ssa_operands_active
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_to_addressable_set
parameter_list|(
name|tree
parameter_list|,
name|bitmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ssa_op_iter_type
block|{
name|ssa_op_iter_none
init|=
literal|0
block|,
name|ssa_op_iter_tree
block|,
name|ssa_op_iter_use
block|,
name|ssa_op_iter_def
block|,
name|ssa_op_iter_maymustdef
block|}
enum|;
end_enum

begin_comment
comment|/* This structure is used in the operand iterator loops.  It contains the     items required to determine which operand is retrieved next.  During    optimization, this structure is scalarized, and any unused fields are     optimized away, resulting in little overhead.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ssa_operand_iterator_d
block|{
name|def_optype_p
name|defs
decl_stmt|;
name|use_optype_p
name|uses
decl_stmt|;
name|vuse_optype_p
name|vuses
decl_stmt|;
name|maydef_optype_p
name|maydefs
decl_stmt|;
name|maydef_optype_p
name|mayuses
decl_stmt|;
name|mustdef_optype_p
name|mustdefs
decl_stmt|;
name|mustdef_optype_p
name|mustkills
decl_stmt|;
name|enum
name|ssa_op_iter_type
name|iter_type
decl_stmt|;
name|int
name|phi_i
decl_stmt|;
name|int
name|num_phi
decl_stmt|;
name|tree
name|phi_stmt
decl_stmt|;
name|bool
name|done
decl_stmt|;
block|}
name|ssa_op_iter
typedef|;
end_typedef

begin_comment
comment|/* These flags are used to determine which operands are returned during     execution of the loop.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_USE
value|0x01
end_define

begin_comment
comment|/* Real USE operands.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_DEF
value|0x02
end_define

begin_comment
comment|/* Real DEF operands.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_VUSE
value|0x04
end_define

begin_comment
comment|/* VUSE operands.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_VMAYUSE
value|0x08
end_define

begin_comment
comment|/* USE portion of V_MAY_DEFS.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_VMAYDEF
value|0x10
end_define

begin_comment
comment|/* DEF portion of V_MAY_DEFS.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_VMUSTDEF
value|0x20
end_define

begin_comment
comment|/* V_MUST_DEF definitions.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_VMUSTKILL
value|0x40
end_define

begin_comment
comment|/* V_MUST_DEF kills.  */
end_comment

begin_comment
comment|/* These are commonly grouped operand flags.  */
end_comment

begin_define
define|#
directive|define
name|SSA_OP_VIRTUAL_USES
value|(SSA_OP_VUSE | SSA_OP_VMAYUSE)
end_define

begin_define
define|#
directive|define
name|SSA_OP_VIRTUAL_DEFS
value|(SSA_OP_VMAYDEF | SSA_OP_VMUSTDEF)
end_define

begin_define
define|#
directive|define
name|SSA_OP_VIRTUAL_KILLS
value|(SSA_OP_VMUSTKILL)
end_define

begin_define
define|#
directive|define
name|SSA_OP_ALL_VIRTUALS
value|(SSA_OP_VIRTUAL_USES | SSA_OP_VIRTUAL_KILLS \ 				 | SSA_OP_VIRTUAL_DEFS)
end_define

begin_define
define|#
directive|define
name|SSA_OP_ALL_USES
value|(SSA_OP_VIRTUAL_USES | SSA_OP_USE)
end_define

begin_define
define|#
directive|define
name|SSA_OP_ALL_DEFS
value|(SSA_OP_VIRTUAL_DEFS | SSA_OP_DEF)
end_define

begin_define
define|#
directive|define
name|SSA_OP_ALL_KILLS
value|(SSA_OP_VIRTUAL_KILLS)
end_define

begin_define
define|#
directive|define
name|SSA_OP_ALL_OPERANDS
value|(SSA_OP_ALL_USES | SSA_OP_ALL_DEFS	\ 				 | SSA_OP_ALL_KILLS)
end_define

begin_comment
comment|/* This macro executes a loop over the operands of STMT specified in FLAG,     returning each operand as a 'tree' in the variable TREEVAR.  ITER is an    ssa_op_iter structure used to control the loop.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_SSA_TREE_OPERAND
parameter_list|(
name|TREEVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|for (TREEVAR = op_iter_init_tree (&(ITER), STMT, FLAGS);	\        !op_iter_done (&(ITER));					\        TREEVAR = op_iter_next_tree (&(ITER)))
end_define

begin_comment
comment|/* This macro executes a loop over the operands of STMT specified in FLAG,     returning each operand as a 'use_operand_p' in the variable USEVAR.      ITER is an ssa_op_iter structure used to control the loop.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_SSA_USE_OPERAND
parameter_list|(
name|USEVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|for (USEVAR = op_iter_init_use (&(ITER), STMT, FLAGS);	\        !op_iter_done (&(ITER));					\        USEVAR = op_iter_next_use (&(ITER)))
end_define

begin_comment
comment|/* This macro executes a loop over the operands of STMT specified in FLAG,     returning each operand as a 'def_operand_p' in the variable DEFVAR.      ITER is an ssa_op_iter structure used to control the loop.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_SSA_DEF_OPERAND
parameter_list|(
name|DEFVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|for (DEFVAR = op_iter_init_def (&(ITER), STMT, FLAGS);	\        !op_iter_done (&(ITER));					\        DEFVAR = op_iter_next_def (&(ITER)))
end_define

begin_comment
comment|/* This macro executes a loop over the V_MAY_DEF operands of STMT.  The def    and use for each V_MAY_DEF is returned in DEFVAR and USEVAR.     ITER is an ssa_op_iter structure used to control the loop.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_SSA_MAYDEF_OPERAND
parameter_list|(
name|DEFVAR
parameter_list|,
name|USEVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for (op_iter_init_maydef (&(ITER), STMT,&(USEVAR),&(DEFVAR));	\        !op_iter_done (&(ITER));					\        op_iter_next_maymustdef (&(USEVAR),&(DEFVAR),&(ITER)))
end_define

begin_comment
comment|/* This macro executes a loop over the V_MUST_DEF operands of STMT.  The def    and kill for each V_MUST_DEF is returned in DEFVAR and KILLVAR.     ITER is an ssa_op_iter structure used to control the loop.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_SSA_MUSTDEF_OPERAND
parameter_list|(
name|DEFVAR
parameter_list|,
name|KILLVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for (op_iter_init_mustdef (&(ITER), STMT,&(KILLVAR),&(DEFVAR));	\        !op_iter_done (&(ITER));					\        op_iter_next_maymustdef (&(KILLVAR),&(DEFVAR),&(ITER)))
end_define

begin_comment
comment|/* This macro executes a loop over the V_{MUST,MAY}_DEF of STMT.  The def    and kill for each V_{MUST,MAY}_DEF is returned in DEFVAR and KILLVAR.     ITER is an ssa_op_iter structure used to control the loop.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_SSA_MUST_AND_MAY_DEF_OPERAND
parameter_list|(
name|DEFVAR
parameter_list|,
name|KILLVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|)
define|\
value|for (op_iter_init_must_and_may_def (&(ITER), STMT,&(KILLVAR),&(DEFVAR));\        !op_iter_done (&(ITER));					\        op_iter_next_maymustdef (&(KILLVAR),&(DEFVAR),&(ITER)))
end_define

begin_comment
comment|/* This macro will execute a loop over all the arguments of a PHI which    match FLAGS.   A use_operand_p is always returned via USEVAR.  FLAGS    can be either SSA_OP_USE or SSA_OP_VIRTUAL_USES or SSA_OP_ALL_USES.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_PHI_ARG
parameter_list|(
name|USEVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|for ((USEVAR) = op_iter_init_phiuse (&(ITER), STMT, FLAGS);	\        !op_iter_done (&(ITER));					\        (USEVAR) = op_iter_next_use (&(ITER)))
end_define

begin_comment
comment|/* This macro will execute a loop over a stmt, regardless of whether it is    a real stmt or a PHI node, looking at the USE nodes matching FLAGS.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_PHI_OR_STMT_USE
parameter_list|(
name|USEVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|for ((USEVAR) = (TREE_CODE (STMT) == PHI_NODE 		\ 		   ? op_iter_init_phiuse (&(ITER), STMT, FLAGS)	\ 		   : op_iter_init_use (&(ITER), STMT, FLAGS));	\        !op_iter_done (&(ITER));					\        (USEVAR) = op_iter_next_use (&(ITER)))
end_define

begin_comment
comment|/* This macro will execute a loop over a stmt, regardless of whether it is    a real stmt or a PHI node, looking at the DEF nodes matching FLAGS.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_PHI_OR_STMT_DEF
parameter_list|(
name|DEFVAR
parameter_list|,
name|STMT
parameter_list|,
name|ITER
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|for ((DEFVAR) = (TREE_CODE (STMT) == PHI_NODE 		\ 		   ? op_iter_init_phidef (&(ITER), STMT, FLAGS)	\ 		   : op_iter_init_def (&(ITER), STMT, FLAGS));	\        !op_iter_done (&(ITER));					\        (DEFVAR) = op_iter_next_def (&(ITER)))
end_define

begin_comment
comment|/* This macro returns an operand in STMT as a tree if it is the ONLY    operand matching FLAGS.  If there are 0 or more than 1 operand matching    FLAGS, then NULL_TREE is returned.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_SSA_TREE_OPERAND
parameter_list|(
name|STMT
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|single_ssa_tree_operand (STMT, FLAGS)
end_define

begin_comment
comment|/* This macro returns an operand in STMT as a use_operand_p if it is the ONLY    operand matching FLAGS.  If there are 0 or more than 1 operand matching    FLAGS, then NULL_USE_OPERAND_P is returned.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_SSA_USE_OPERAND
parameter_list|(
name|STMT
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|single_ssa_use_operand (STMT, FLAGS)
end_define

begin_comment
comment|/* This macro returns an operand in STMT as a def_operand_p if it is the ONLY    operand matching FLAGS.  If there are 0 or more than 1 operand matching    FLAGS, then NULL_DEF_OPERAND_P is returned.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_SSA_DEF_OPERAND
parameter_list|(
name|STMT
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|single_ssa_def_operand (STMT, FLAGS)
end_define

begin_comment
comment|/* This macro returns TRUE if there are no operands matching FLAGS in STMT.  */
end_comment

begin_define
define|#
directive|define
name|ZERO_SSA_OPERANDS
parameter_list|(
name|STMT
parameter_list|,
name|FLAGS
parameter_list|)
value|zero_ssa_operands (STMT, FLAGS)
end_define

begin_comment
comment|/* This macro counts the number of operands in STMT matching FLAGS.  */
end_comment

begin_define
define|#
directive|define
name|NUM_SSA_OPERANDS
parameter_list|(
name|STMT
parameter_list|,
name|FLAGS
parameter_list|)
value|num_ssa_operands (STMT, FLAGS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_SSA_OPERANDS_H  */
end_comment

end_unit

