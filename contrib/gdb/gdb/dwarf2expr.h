begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dwarf2 Expression Evaluator    Copyright 2001, 2002, 2003 Free Software Foundation, Inc.    Contributed by Daniel Berlin (dan@dberlin.org)    This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DWARF2EXPR_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2EXPR_H
end_define

begin_comment
comment|/* The expression evaluator works with a dwarf_expr_context, describing    its current state and its callbacks.  */
end_comment

begin_struct
struct|struct
name|dwarf_expr_context
block|{
comment|/* The stack of values, allocated with xmalloc.  */
name|CORE_ADDR
modifier|*
name|stack
decl_stmt|;
comment|/* The number of values currently pushed on the stack, and the      number of elements allocated to the stack.  */
name|int
name|stack_len
decl_stmt|,
name|stack_allocated
decl_stmt|;
comment|/* An opaque argument provided by the caller, which will be passed      to all of the callback functions.  */
name|void
modifier|*
name|baton
decl_stmt|;
comment|/* Return the value of register number REGNUM.  */
name|CORE_ADDR
function_decl|(
modifier|*
name|read_reg
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
comment|/* Read LENGTH bytes at ADDR into BUF.  */
name|void
function_decl|(
modifier|*
name|read_mem
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
comment|/* Return the location expression for the frame base attribute, in      START and LENGTH.  The result must be live until the current      expression evaluation is complete.  */
name|void
function_decl|(
modifier|*
name|get_frame_base
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|start
parameter_list|,
name|size_t
modifier|*
name|length
parameter_list|)
function_decl|;
comment|/* Return the thread-local storage address for      DW_OP_GNU_push_tls_address.  */
name|CORE_ADDR
function_decl|(
modifier|*
name|get_tls_address
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|CORE_ADDR
name|offset
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
comment|/* Not yet implemented.  */
comment|/* Return the location expression for the dwarf expression      subroutine in the die at OFFSET in the current compilation unit.      The result must be live until the current expression evaluation      is complete.  */
block|unsigned char *(*get_subr) (void *baton, off_t offset, size_t *length);
comment|/* Return the `object address' for DW_OP_push_object_address.  */
block|CORE_ADDR (*get_object_address) (void *baton);
endif|#
directive|endif
comment|/* The current depth of dwarf expression recursion, via DW_OP_call*,      DW_OP_fbreg, DW_OP_push_object_address, etc., and the maximum      depth we'll tolerate before raising an error.  */
name|int
name|recursion_depth
decl_stmt|,
name|max_recursion_depth
decl_stmt|;
comment|/* Non-zero if the result is in a register.  The register number      will be on the expression stack.  */
name|int
name|in_reg
decl_stmt|;
comment|/* Initialization status of variable: Non-zero if variable has been      initialized; zero otherwise.  */
name|int
name|initialized
decl_stmt|;
comment|/* An array of pieces.  PIECES points to its first element;      NUM_PIECES is its length.       Each time DW_OP_piece is executed, we add a new element to the      end of this array, recording the current top of the stack, the      current in_reg flag, and the size given as the operand to      DW_OP_piece.  We then pop the top value from the stack, clear the      in_reg flag, and resume evaluation.       The Dwarf spec doesn't say whether DW_OP_piece pops the top value      from the stack.  We do, ensuring that clients of this interface      expecting to see a value left on the top of the stack (say, code      evaluating frame base expressions or CFA's specified with      DW_CFA_def_cfa_expression) will get an error if the expression      actually marks all the values it computes as pieces.       If an expression never uses DW_OP_piece, num_pieces will be zero.      (It would be nice to present these cases as expressions yielding      a single piece, with in_reg clear, so that callers need not      distinguish between the no-DW_OP_piece and one-DW_OP_piece cases.      But expressions with no DW_OP_piece operations have no value to      place in a piece's 'size' field; the size comes from the      surrounding data.  So the two cases need to be handled      separately.)  */
name|int
name|num_pieces
decl_stmt|;
name|struct
name|dwarf_expr_piece
modifier|*
name|pieces
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A piece of an object, as recorded by DW_OP_piece or DW_OP_bit_piece.  */
end_comment

begin_struct
struct|struct
name|dwarf_expr_piece
block|{
comment|/* If IN_REG is zero, then the piece is in memory, and VALUE is its address.      If IN_REG is non-zero, then the piece is in a register, and VALUE      is the register number.  */
name|int
name|in_reg
decl_stmt|;
comment|/* This piece's address or register number.  */
name|CORE_ADDR
name|value
decl_stmt|;
comment|/* The length of the piece, in bytes.  */
name|ULONGEST
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|dwarf_expr_context
modifier|*
name|new_dwarf_expr_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_dwarf_expr_context
parameter_list|(
name|struct
name|dwarf_expr_context
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_expr_push
parameter_list|(
name|struct
name|dwarf_expr_context
modifier|*
name|ctx
parameter_list|,
name|CORE_ADDR
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_expr_pop
parameter_list|(
name|struct
name|dwarf_expr_context
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwarf_expr_eval
parameter_list|(
name|struct
name|dwarf_expr_context
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|dwarf_expr_fetch
parameter_list|(
name|struct
name|dwarf_expr_context
modifier|*
name|ctx
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|read_uleb128
parameter_list|(
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf_end
parameter_list|,
name|ULONGEST
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|read_sleb128
parameter_list|(
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf_end
parameter_list|,
name|LONGEST
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|dwarf2_read_address
parameter_list|(
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf_end
parameter_list|,
name|int
modifier|*
name|bytes_read
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

