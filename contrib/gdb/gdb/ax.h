begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for expressions designed to be executed on the agent    Copyright 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $Id: ax.h,v 1.3.20.1 1999/04/01 17:33:04 jimb Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AGENTEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|AGENTEXPR_H
end_define

begin_comment
comment|/* It's sometimes useful to be able to debug programs that you can't    really stop for more than a fraction of a second.  To this end, the    user can specify a tracepoint (like a breakpoint, but you don't    stop at it), and specify a bunch of expressions to record the    values of when that tracepoint is reached.  As the program runs,    GDB collects the values.  At any point (possibly while values are    still being collected), the user can display the collected values.     This is used with remote debugging; we don't really support it on    native configurations.     This means that expressions are being evaluated by the remote agent,    which doesn't have any access to the symbol table information, and    needs to be small and simple.     The agent_expr routines and datatypes are a bytecode language    designed to be executed by the agent.  Agent expressions work in    terms of fixed-width values, operators, memory references, and    register references.  You can evaluate a agent expression just given    a bunch of memory and register values to sniff at; you don't need    any symbolic information like variable names, types, etc.     GDB translates source expressions, whose meaning depends on    symbolic information, into agent bytecode expressions, whose meaning    is independent of symbolic information.  This means the agent can    evaluate them on the fly without reference to data only available    to the host GDB.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Agent expression data structures.  */
end_comment

begin_comment
comment|/* The type of an element of the agent expression stack.    The bytecode operation indicates which element we should access;    the value itself has no typing information.  GDB generates all    bytecode streams, so we don't have to worry about type errors.  */
end_comment

begin_union
union|union
name|agent_val
block|{
name|LONGEST
name|l
decl_stmt|;
name|DOUBLEST
name|d
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* A buffer containing a agent expression.  */
end_comment

begin_struct
struct|struct
name|agent_expr
block|{
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* number of characters used */
name|int
name|size
decl_stmt|;
comment|/* allocated size */
name|CORE_ADDR
name|scope
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The actual values of the various bytecode operations.     Other independent implementations of the agent bytecode engine will    rely on the exact values of these enums, and may not be recompiled    when we change this table.  The numeric values should remain fixed    whenever possible.  Thus, we assign them values explicitly here (to    allow gaps to form safely), and the disassembly table in    agentexpr.h behaves like an opcode map.  If you want to see them    grouped logically, see doc/agentexpr.texi.  */
end_comment

begin_enum
enum|enum
name|agent_op
block|{
name|aop_float
init|=
literal|0x01
block|,
name|aop_add
init|=
literal|0x02
block|,
name|aop_sub
init|=
literal|0x03
block|,
name|aop_mul
init|=
literal|0x04
block|,
name|aop_div_signed
init|=
literal|0x05
block|,
name|aop_div_unsigned
init|=
literal|0x06
block|,
name|aop_rem_signed
init|=
literal|0x07
block|,
name|aop_rem_unsigned
init|=
literal|0x08
block|,
name|aop_lsh
init|=
literal|0x09
block|,
name|aop_rsh_signed
init|=
literal|0x0a
block|,
name|aop_rsh_unsigned
init|=
literal|0x0b
block|,
name|aop_trace
init|=
literal|0x0c
block|,
name|aop_trace_quick
init|=
literal|0x0d
block|,
name|aop_log_not
init|=
literal|0x0e
block|,
name|aop_bit_and
init|=
literal|0x0f
block|,
name|aop_bit_or
init|=
literal|0x10
block|,
name|aop_bit_xor
init|=
literal|0x11
block|,
name|aop_bit_not
init|=
literal|0x12
block|,
name|aop_equal
init|=
literal|0x13
block|,
name|aop_less_signed
init|=
literal|0x14
block|,
name|aop_less_unsigned
init|=
literal|0x15
block|,
name|aop_ext
init|=
literal|0x16
block|,
name|aop_ref8
init|=
literal|0x17
block|,
name|aop_ref16
init|=
literal|0x18
block|,
name|aop_ref32
init|=
literal|0x19
block|,
name|aop_ref64
init|=
literal|0x1a
block|,
name|aop_ref_float
init|=
literal|0x1b
block|,
name|aop_ref_double
init|=
literal|0x1c
block|,
name|aop_ref_long_double
init|=
literal|0x1d
block|,
name|aop_l_to_d
init|=
literal|0x1e
block|,
name|aop_d_to_l
init|=
literal|0x1f
block|,
name|aop_if_goto
init|=
literal|0x20
block|,
name|aop_goto
init|=
literal|0x21
block|,
name|aop_const8
init|=
literal|0x22
block|,
name|aop_const16
init|=
literal|0x23
block|,
name|aop_const32
init|=
literal|0x24
block|,
name|aop_const64
init|=
literal|0x25
block|,
name|aop_reg
init|=
literal|0x26
block|,
name|aop_end
init|=
literal|0x27
block|,
name|aop_dup
init|=
literal|0x28
block|,
name|aop_pop
init|=
literal|0x29
block|,
name|aop_zero_ext
init|=
literal|0x2a
block|,
name|aop_swap
init|=
literal|0x2b
block|,
name|aop_trace16
init|=
literal|0x30
block|,
name|aop_last
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Functions for building expressions.  */
end_comment

begin_comment
comment|/* Allocate a new, empty agent expression.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|agent_expr
modifier|*
name|new_agent_expr
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a agent expression.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|free_agent_expr
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Append a simple operator OP to EXPR.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_simple
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
expr|enum
name|agent_op
name|OP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Append the floating-point prefix, for the next bytecode.  */
end_comment

begin_define
define|#
directive|define
name|ax_float
parameter_list|(
name|EXPR
parameter_list|)
value|(ax_simple ((EXPR), aop_float))
end_define

begin_comment
comment|/* Append a sign-extension instruction to EXPR, to extend an N-bit value.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_ext
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|int
name|N
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Append a zero-extension instruction to EXPR, to extend an N-bit value.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_zero_ext
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|int
name|N
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Append a trace_quick instruction to EXPR, to record N bytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_trace_quick
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|int
name|N
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Append a goto op to EXPR.  OP is the actual op (must be aop_goto or    aop_if_goto).  We assume we don't know the target offset yet,    because it's probably a forward branch, so we leave space in EXPR    for the target, and return the offset in EXPR of that space, so we    can backpatch it once we do know the target offset.  Use ax_label    to do the backpatching.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ax_goto
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
expr|enum
name|agent_op
name|OP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Suppose a given call to ax_goto returns some value PATCH.  When you    know the offset TARGET that goto should jump to, call 	ax_label (EXPR, PATCH, TARGET)    to patch TARGET into the ax_goto instruction.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_label
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|int
name|patch
operator|,
name|int
name|target
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble code to push a constant on the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_const_l
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|LONGEST
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ax_const_d
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|LONGEST
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble code to push the value of register number REG on the    stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_reg
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|,
name|int
name|REG
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Functions for printing out expressions, and otherwise debugging    things.  */
end_comment

begin_comment
comment|/* Disassemble the expression EXPR, writing to F.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_print
name|PARAMS
argument_list|(
operator|(
name|GDB_FILE
operator|*
name|f
operator|,
expr|struct
name|agent_expr
operator|*
name|EXPR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An entry in the opcode map.  */
end_comment

begin_struct
struct|struct
name|aop_map
block|{
comment|/* The name of the opcode.  Null means that this entry is not a      valid opcode --- a hole in the opcode space.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* All opcodes take no operands from the bytecode stream, or take      unsigned integers of various sizes.  If this is a positive number      n, then the opcode is followed by an n-byte operand, which should      be printed as an unsigned integer.  If this is zero, then the      opcode takes no operands from the bytecode stream.       If we get more complicated opcodes in the future, don't add other      magic values of this; that's a crock.  Add an `enum encoding'      field to this, or something like that.  */
name|int
name|op_size
decl_stmt|;
comment|/* The size of the data operated upon, in bits, for bytecodes that      care about that (ref and const).  Zero for all others.  */
name|int
name|data_size
decl_stmt|;
comment|/* Number of stack elements consumed, and number produced.  */
name|int
name|consumed
decl_stmt|,
name|produced
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Map of the bytecodes, indexed by bytecode number.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|aop_map
name|aop_map
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Different kinds of flaws an agent expression might have, as    detected by agent_reqs.  */
end_comment

begin_enum
enum|enum
name|agent_flaws
block|{
name|agent_flaw_none
init|=
literal|0
block|,
comment|/* code is good */
comment|/* There is an invalid instruction in the stream.  */
name|agent_flaw_bad_instruction
block|,
comment|/* There is an incomplete instruction at the end of the expression.  */
name|agent_flaw_incomplete_instruction
block|,
comment|/* agent_reqs was unable to prove that every jump target is to a      valid offset.  Valid offsets are within the bounds of the      expression, and to a valid instruction boundary.  */
name|agent_flaw_bad_jump
block|,
comment|/* agent_reqs was unable to prove to its satisfaction that, for each      jump target location, the stack will have the same height whether      that location is reached via a jump or by straight execution.  */
name|agent_flaw_height_mismatch
block|,
comment|/* agent_reqs was unable to prove that every instruction following      an unconditional jump was the target of some other jump.  */
name|agent_flaw_hole
block|}
enum|;
end_enum

begin_comment
comment|/* Structure describing the requirements of a bytecode expression.  */
end_comment

begin_struct
struct|struct
name|agent_reqs
block|{
comment|/* If the following is not equal to agent_flaw_none, the rest of the      information in this structure is suspect.  */
name|enum
name|agent_flaws
name|flaw
decl_stmt|;
comment|/* Number of elements left on stack at end; may be negative if expr      only consumes elements.  */
name|int
name|final_height
decl_stmt|;
comment|/* Maximum and minimum stack height, relative to initial height.  */
name|int
name|max_height
decl_stmt|,
name|min_height
decl_stmt|;
comment|/* Largest `ref' or `const' opcode used, in bits.  Zero means the      expression has no such instructions.  */
name|int
name|max_data_size
decl_stmt|;
comment|/* Bit vector of registers used.  Register R is used iff    	reg_mask[R / 8]& (1<< (R % 8))       is non-zero.  Note!  You may not assume that this bitmask is long      enough to hold bits for all the registers of the machine; the      agent expression code has no idea how many registers the machine      has.  However, the bitmask is reg_mask_len bytes long, so the      valid register numbers run from 0 to reg_mask_len * 8 - 1.         We're assuming eight-bit bytes.  So sue me.       The caller should free reg_list when done.  */
name|int
name|reg_mask_len
decl_stmt|;
name|unsigned
name|char
modifier|*
name|reg_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Given an agent expression AX, fill in an agent_reqs structure REQS    describing it.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ax_reqs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|agent_expr
operator|*
name|ax
operator|,
expr|struct
name|agent_reqs
operator|*
name|reqs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AGENTEXPR_H */
end_comment

end_unit

