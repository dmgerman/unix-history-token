begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for insn-output.c.  These functions are defined in recog.c.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Operand-predicate functions.  */
end_comment

begin_function_decl
name|int
name|general_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|push_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|indirect_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|immediate_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|address_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nonmemory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nonimmediate_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|offsettable_address_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|adj_offsettable_operand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Output a string of assembler code.    Defined in final.c.  */
end_comment

begin_function_decl
name|void
name|output_asm_insn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* When outputting assembler code, indicates which alternative    of the constraints was actually satisfied.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|which_alternative
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When outputting delayed branch sequences, this rtx holds the    sequence being output.  It is null when no delayed branch    sequence is being output, so it can be used as a test in the    insn output code.     This variable is defined  in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|final_sequence
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled pops its args on return.    May affect compilation of return insn or of function epilogue.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_pops_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to be given an address    where the value should be stored.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to    return the address of where it has put a structure value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pcc_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to be passed a static chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_needs_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call setjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_setjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call alloca,    either as a subroutine or builtin.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the current function returns a pointer type */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If function's args have a fixed size, this is that size, in bytes.    Otherwise, it is -1.    May affect compilation of return insn or of function epilogue.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes the prologue should push and pretend that the caller pushed them.    The prologue must do this, but only if parms can be passed in registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_pretend_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of function now being compiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_name
decl_stmt|;
end_decl_stmt

end_unit

