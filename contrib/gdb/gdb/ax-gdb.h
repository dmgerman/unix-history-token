begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GDB-specific functions for operating on agent expressions    Copyright 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $Id: ax-gdb.h,v 1.3.20.1 1999/04/01 17:33:04 jimb Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AX_GDB_H
end_ifndef

begin_define
define|#
directive|define
name|AX_GDB_H
end_define

begin_escape
end_escape

begin_comment
comment|/* Types and enums */
end_comment

begin_comment
comment|/* GDB stores expressions in the form of a flattened tree (struct    expression), so we just walk that tree and generate agent bytecodes    as we go along.     GDB's normal evaluation uses struct value, which contains the    expression's value as well as its address or the register it came    from.  The `+' operator uses the value, whereas the unary `&'    operator will use the address portion.  The `=' operator will use    the address or register number of its left hand side.     The issues are different when generating agent bytecode.  Given a    variable reference expression, we should not necessarily generate    code to fetch its value, because the next operator may be `=' or    unary `&'.  Instead, when we recurse on a subexpression, we    indicate whether we want that expression to produce an lvalue or an    rvalue.  If we requested an lvalue, then the recursive call tells    us whether it generated code to compute an address on the stack, or    whether the lvalue lives in a register.     The `axs' prefix here means `agent expression, static', because    this is all static analysis of the expression, i.e. analysis which    doesn't depend on the contents of memory and registers.  */
end_comment

begin_comment
comment|/* Different kinds of agent expression static values.  */
end_comment

begin_enum
enum|enum
name|axs_lvalue_kind
block|{
comment|/* We generated code to compute the subexpression's value.      Constants and arithmetic operators yield this.  */
name|axs_rvalue
block|,
comment|/* We generated code to yield the subexpression's value's address on      the top of the stack.  If the caller needs an rvalue, it should      call require_rvalue to produce the rvalue from this address.  */
name|axs_lvalue_memory
block|,
comment|/* We didn't generate any code, and the stack is undisturbed,      because the subexpression's value lives in a register; u.reg is      the register number.  If the caller needs an rvalue, it should      call require_rvalue to produce the rvalue from this register      number.  */
name|axs_lvalue_register
block|}
enum|;
end_enum

begin_comment
comment|/* Structure describing what we got from a subexpression.  Think of    this as parallel to value.h's enum lval_type, except that we're    describing a value which will exist when the expression is    evaluated in the future, not a value we have in our hand.  */
end_comment

begin_struct
struct|struct
name|axs_value
block|{
name|enum
name|axs_lvalue_kind
name|kind
decl_stmt|;
comment|/* see above */
comment|/* The type of the subexpression.  Even if lvalue == axs_lvalue_memory,      this is the type of the value itself; the value on the stack is a      "pointer to" an object of this type. */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
union|union
block|{
comment|/* if kind == axs_lvalue_register, this is the register number */
name|int
name|reg
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Translating GDB expressions into agent expressions.  */
end_comment

begin_comment
comment|/* Given a GDB expression EXPR, translate it into the agent bytecode,    and return it.  FLAGS are from enum expr_to_agent_flags.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|agent_expr
modifier|*
name|expr_to_agent
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
name|EXPR
operator|,
expr|struct
name|axs_value
operator|*
name|VALUE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a GDB expression EXPR denoting an lvalue in memory, produce a    string of agent bytecode which will leave its address and size on    the top of stack.  Return the agent expression.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|agent_expr
modifier|*
name|expr_to_address_and_size
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
name|EXPR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a GDB expression EXPR, return bytecode to trace its value.    The result will use the `trace' and `trace_quick' bytecodes to    record the value of all memory touched by the expression, and leave    no values on the stack.  The caller can then use the ax_reqs    function to discover which registers the expression uses.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|agent_expr
modifier|*
name|gen_trace_for_expr
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
expr|struct
name|expression
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AX_GDB_H */
end_comment

end_unit

