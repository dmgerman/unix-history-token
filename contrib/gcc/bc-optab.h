begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Bytecode token definitions for GNU C-compiler.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bc_expand_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_expand_truth_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_expand_binary_operation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_expand_unary_operation
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|binary_operator
block|{
name|enum
name|bytecode_opcode
name|opcode
decl_stmt|;
name|enum
name|typecode
name|result
decl_stmt|;
name|enum
name|typecode
name|arg0
decl_stmt|;
name|enum
name|typecode
name|arg1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_plus_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_minus_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_mult_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_trunc_div_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_trunc_mod_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_rdiv_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_bit_and_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_bit_ior_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_bit_xor_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_lshift_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_rshift_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_truth_and_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_truth_or_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_lt_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_le_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_ge_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_gt_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_eq_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|binary_operator
name|optab_ne_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|unary_operator
block|{
name|enum
name|bytecode_opcode
name|opcode
decl_stmt|;
name|enum
name|typecode
name|result
decl_stmt|;
name|enum
name|typecode
name|arg0
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|unary_operator
name|optab_negate_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|unary_operator
name|optab_bit_not_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|unary_operator
name|optab_truth_not_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|increment_operator
block|{
name|enum
name|bytecode_opcode
name|opcode
decl_stmt|;
name|enum
name|typecode
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|increment_operator
name|optab_predecrement_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|increment_operator
name|optab_preincrement_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|increment_operator
name|optab_postdecrement_expr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|increment_operator
name|optab_postincrement_expr
index|[]
decl_stmt|;
end_decl_stmt

end_unit

