begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for expressions stored in reversed prefix form, for GDB.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Definitions for saved C expressions.  */
end_comment

begin_comment
comment|/* An expression is represented as a vector of union exp_element's.    Each exp_element is an opcode, except that some opcodes cause    the following exp_element to be treated as a long or double constant    or as a variable.  The opcodes are obeyed, using a stack for temporaries.    The value is left on the temporary stack at the end.  */
end_comment

begin_comment
comment|/* When it is necessary to include a string,    it can occupy as many exp_elements as it needs.    We find the length of the string using strlen,    divide to find out how many exp_elements are used up,    and skip that many.  Strings, like numbers, are indicated    by the preceding opcode.  */
end_comment

begin_enum
enum|enum
name|exp_opcode
block|{
comment|/* BINOP_... operate on two values computed by following subexpressions,    replacing them by one result value.  They take no immediate arguments.  */
name|BINOP_ADD
block|,
comment|/* + */
name|BINOP_SUB
block|,
comment|/* - */
name|BINOP_MUL
block|,
comment|/* * */
name|BINOP_DIV
block|,
comment|/* / */
name|BINOP_REM
block|,
comment|/* % */
name|BINOP_LSH
block|,
comment|/*<< */
name|BINOP_RSH
block|,
comment|/*>> */
name|BINOP_AND
block|,
comment|/*&& */
name|BINOP_OR
block|,
comment|/* || */
name|BINOP_LOGAND
block|,
comment|/*& */
name|BINOP_LOGIOR
block|,
comment|/* | */
name|BINOP_LOGXOR
block|,
comment|/* ^ */
name|BINOP_EQUAL
block|,
comment|/* == */
name|BINOP_NOTEQUAL
block|,
comment|/* != */
name|BINOP_LESS
block|,
comment|/*< */
name|BINOP_GTR
block|,
comment|/*> */
name|BINOP_LEQ
block|,
comment|/*<= */
name|BINOP_GEQ
block|,
comment|/*>= */
name|BINOP_REPEAT
block|,
comment|/* @ */
name|BINOP_ASSIGN
block|,
comment|/* = */
name|BINOP_COMMA
block|,
comment|/* , */
name|BINOP_SUBSCRIPT
block|,
comment|/* x[y] */
name|BINOP_EXP
block|,
comment|/* Exponentiation */
comment|/* C++.  */
name|BINOP_MIN
block|,
comment|/*<? */
name|BINOP_MAX
block|,
comment|/*>? */
name|BINOP_SCOPE
block|,
comment|/* :: */
comment|/* STRUCTOP_MEMBER is used for pointer-to-member constructs.      X . * Y translates into X STRUCTOP_MEMBER Y.  */
name|STRUCTOP_MEMBER
block|,
comment|/* STRUCTOP_MPTR is used for pointer-to-member constructs      when X is a pointer instead of an aggregate.  */
name|STRUCTOP_MPTR
block|,
comment|/* end of C++.  */
name|BINOP_END
block|,
name|BINOP_ASSIGN_MODIFY
block|,
comment|/* +=, -=, *=, and so on. 			   The following exp_element is another opcode, 			   a BINOP_, saying how to modify. 			   Then comes another BINOP_ASSIGN_MODIFY, 			   making three exp_elements in total.  */
comment|/* Operates on three values computed by following subexpressions.  */
name|TERNOP_COND
block|,
comment|/* ?: */
comment|/* The OP_... series take immediate following arguments.    After the arguments come another OP_... (the same one)    so that the grouping can be recognized from the end.  */
comment|/* OP_LONG is followed by a type pointer in the next exp_element    and the long constant value in the following exp_element.    Then comes another OP_LONG.    Thus, the operation occupies four exp_elements.  */
name|OP_LONG
block|,
comment|/* OP_DOUBLE is similar but takes a double constant instead of a long one.  */
name|OP_DOUBLE
block|,
comment|/* OP_VAR_VALUE takes one struct symbol * in the following exp_element,    followed by another OP_VAR_VALUE, making three exp_elements.  */
name|OP_VAR_VALUE
block|,
comment|/* OP_LAST is followed by an integer in the next exp_element.    The integer is zero for the last value printed,    or it is the absolute number of a history element.    With another OP_LAST at the end, this makes three exp_elements.  */
name|OP_LAST
block|,
comment|/* OP_REGISTER is followed by an integer in the next exp_element.    This is the number of a register to fetch (as an int).    With another OP_REGISTER at the end, this makes three exp_elements.  */
name|OP_REGISTER
block|,
comment|/* OP_INTERNALVAR is followed by an internalvar ptr in the next exp_element.    With another OP_INTERNALVAR at the end, this makes three exp_elements.  */
name|OP_INTERNALVAR
block|,
comment|/* OP_FUNCALL is followed by an integer in the next exp_element.    The integer is the number of args to the function call.    That many plus one values from following subexpressions    are used, the first one being the function.    The integer is followed by a repeat of OP_FUNCALL,    making three exp_elements.  */
name|OP_FUNCALL
block|,
comment|/* OP_STRING represents a string constant.    Its format is the same as that of a STRUCTOP, but the string    data is just made into a string constant when the operation    is executed.  */
name|OP_STRING
block|,
comment|/* UNOP_CAST is followed by a type pointer in the next exp_element.    With another UNOP_CAST at the end, this makes three exp_elements.    It casts the value of the following subexpression.  */
name|UNOP_CAST
block|,
comment|/* UNOP_MEMVAL is followed by a type pointer in the next exp_element    With another UNOP_MEMVAL at the end, this makes three exp_elements.    It casts the contents of the word addressed by the value of the    following subexpression.  */
name|UNOP_MEMVAL
block|,
comment|/* UNOP_... operate on one value from a following subexpression    and replace it with a result.  They take no immediate arguments.  */
name|UNOP_NEG
block|,
comment|/* Unary - */
name|UNOP_ZEROP
block|,
comment|/* Unary ! */
name|UNOP_LOGNOT
block|,
comment|/* Unary ~ */
name|UNOP_IND
block|,
comment|/* Unary * */
name|UNOP_ADDR
block|,
comment|/* Unary& */
name|UNOP_PREINCREMENT
block|,
comment|/* ++ before an expression */
name|UNOP_POSTINCREMENT
block|,
comment|/* ++ after an expression */
name|UNOP_PREDECREMENT
block|,
comment|/* -- before an expression */
name|UNOP_POSTDECREMENT
block|,
comment|/* -- after an expression */
name|UNOP_SIZEOF
block|,
comment|/* Unary sizeof (followed by expression) */
comment|/* STRUCTOP_... operate on a value from a following subexpression    by extracting a structure component specified by a string    that appears in the following exp_elements (as many as needed).    STRUCTOP_STRUCT is used for "." and STRUCTOP_PTR for "->".    They differ only in the error message given in case the value is    not suitable or the structure component specified is not found.     The length of the string follows in the next exp_element,    (after the string), followed by another STRUCTOP_... code.  */
name|STRUCTOP_STRUCT
block|,
name|STRUCTOP_PTR
block|,
comment|/* C++ */
comment|/* OP_THIS is just a placeholder for the class instance variable.      It just comes in a tight (OP_THIS, OP_THIS) pair.  */
name|OP_THIS
block|,
comment|/* OP_SCOPE surrounds a type name and a field name.  The type      name is encoded as one element, but the field name stays as      a string, which, of course, is variable length.  */
name|OP_SCOPE
block|,  }
enum|;
end_enum

begin_union
union|union
name|exp_element
block|{
name|enum
name|exp_opcode
name|opcode
decl_stmt|;
name|struct
name|symbol
modifier|*
name|symbol
decl_stmt|;
name|LONGEST
name|longconst
decl_stmt|;
name|double
name|doubleconst
decl_stmt|;
name|char
name|string
decl_stmt|;
name|struct
name|type
modifier|*
name|type
decl_stmt|;
name|struct
name|internalvar
modifier|*
name|internalvar
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|expression
block|{
name|int
name|nelts
decl_stmt|;
name|union
name|exp_element
name|elts
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|expression
modifier|*
name|parse_c_expression
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|expression
modifier|*
name|parse_c_1
parameter_list|()
function_decl|;
end_function_decl

end_unit

