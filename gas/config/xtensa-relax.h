begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Table of relaxations for Xtensa assembly.    Copyright 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,     MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XTENSA_RELAX_H
end_ifndef

begin_define
define|#
directive|define
name|XTENSA_RELAX_H
end_define

begin_include
include|#
directive|include
file|"xtensa-isa.h"
end_include

begin_comment
comment|/* Data structures for the table-driven relaxations for Xtensa processors.    See xtensa-relax.c for details.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|transition_list
name|TransitionList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|transition_table
name|TransitionTable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|transition_rule
name|TransitionRule
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|precondition_list
name|PreconditionList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|precondition
name|Precondition
typedef|;
end_typedef

begin_struct
struct|struct
name|transition_table
block|{
name|int
name|num_opcodes
decl_stmt|;
name|TransitionList
modifier|*
modifier|*
name|table
decl_stmt|;
comment|/* Possible transitions for each opcode.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|transition_list
block|{
name|TransitionRule
modifier|*
name|rule
decl_stmt|;
name|TransitionList
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|precondition_list
block|{
name|Precondition
modifier|*
name|precond
decl_stmt|;
name|PreconditionList
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Operand types and constraints on operands:  */
end_comment

begin_typedef
typedef|typedef
name|enum
name|op_type
name|OpType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|cmp_op
name|CmpOp
typedef|;
end_typedef

begin_enum
enum|enum
name|op_type
block|{
name|OP_CONSTANT
block|,
name|OP_OPERAND
block|,
name|OP_OPERAND_LOW8
block|,
comment|/* Sign-extended low 8 bits of immed.  */
name|OP_OPERAND_HI24S
block|,
comment|/* high 24 bits of immed, 				   plus 0x100 if low 8 bits are signed.  */
name|OP_OPERAND_F32MINUS
block|,
comment|/* 32 - immed.  */
name|OP_LITERAL
block|,
name|OP_LABEL
block|}
enum|;
end_enum

begin_enum
enum|enum
name|cmp_op
block|{
name|OP_EQUAL
block|,
name|OP_NOTEQUAL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|precondition
block|{
name|CmpOp
name|cmp
decl_stmt|;
name|int
name|op_num
decl_stmt|;
name|OpType
name|typ
decl_stmt|;
comment|/* CONSTANT: op_data is a constant. 				   OPERAND: operand op_num must equal op_data. 				   Cannot be LITERAL or LABEL.  */
name|int
name|op_data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|build_op
name|BuildOp
typedef|;
end_typedef

begin_struct
struct|struct
name|build_op
block|{
name|int
name|op_num
decl_stmt|;
name|OpType
name|typ
decl_stmt|;
name|unsigned
name|op_data
decl_stmt|;
comment|/* CONSTANT: op_data is the value to encode. 				   OPERAND: op_data is the field in the 				   source instruction to take the value from 				   and encode in the op_num field here. 				   LITERAL or LABEL: op_data is the ordinal 				   that identifies the appropriate one, i.e., 				   there can be more than one literal or 				   label in an expansion.  */
name|BuildOp
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|build_instr
name|BuildInstr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|instr_type
name|InstrType
typedef|;
end_typedef

begin_enum
enum|enum
name|instr_type
block|{
name|INSTR_INSTR
block|,
name|INSTR_LITERAL_DEF
block|,
name|INSTR_LABEL_DEF
block|}
enum|;
end_enum

begin_struct
struct|struct
name|build_instr
block|{
name|InstrType
name|typ
decl_stmt|;
name|unsigned
name|id
decl_stmt|;
comment|/* LITERAL_DEF or LABEL_DEF: an ordinal to 				   identify which one.  */
name|xtensa_opcode
name|opcode
decl_stmt|;
comment|/* unused for LITERAL_DEF or LABEL_DEF.  */
name|BuildOp
modifier|*
name|ops
decl_stmt|;
name|BuildInstr
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|transition_rule
block|{
name|xtensa_opcode
name|opcode
decl_stmt|;
name|PreconditionList
modifier|*
name|conditions
decl_stmt|;
name|BuildInstr
modifier|*
name|to_instr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|TransitionTable
modifier|*
name|xg_build_simplify_table
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
name|TransitionTable
modifier|*
name|xg_build_widen_table
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
name|bfd_boolean
name|xg_has_userdef_op_fn
name|PARAMS
argument_list|(
operator|(
name|OpType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|xg_apply_userdef_op_fn
name|PARAMS
argument_list|(
operator|(
name|OpType
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XTENSA_RELAX_H */
end_comment

end_unit

