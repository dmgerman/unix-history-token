begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for expressions stored in reversed prefix form, for GDB.    Copyright 1986, 1989, 1992, 1994 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EXPRESSION_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXPRESSION_H
value|1
end_define

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_comment
comment|/* Needed for "struct block" type. */
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
comment|/* Used when it's necessary to pass an opcode which will be ignored,      or to catch uninitialized values.  */
name|OP_NULL
block|,
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
name|BINOP_MOD
block|,
comment|/* mod (Knuth 1.2.4) */
name|BINOP_LSH
block|,
comment|/*<< */
name|BINOP_RSH
block|,
comment|/*>> */
name|BINOP_LOGICAL_AND
block|,
comment|/*&& */
name|BINOP_LOGICAL_OR
block|,
comment|/* || */
name|BINOP_BITWISE_AND
block|,
comment|/*& */
name|BINOP_BITWISE_IOR
block|,
comment|/* | */
name|BINOP_BITWISE_XOR
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
comment|/* For Modula-2 integer division DIV */
name|BINOP_INTDIV
block|,
name|BINOP_ASSIGN_MODIFY
block|,
comment|/* +=, -=, *=, and so on. 			   The following exp_element is another opcode, 			   a BINOP_, saying how to modify. 			   Then comes another BINOP_ASSIGN_MODIFY, 			   making three exp_elements in total.  */
comment|/* Modula-2 standard (binary) procedures */
name|BINOP_VAL
block|,
name|BINOP_INCL
block|,
name|BINOP_EXCL
block|,
comment|/* Concatenate two operands, such as character strings or bitstrings.      If the first operand is a integer expression, then it means concatenate      the second operand with itself that many times. */
name|BINOP_CONCAT
block|,
comment|/* For Chill and Pascal. */
name|BINOP_IN
block|,
comment|/* Returns 1 iff ARG1 IN ARG2. */
comment|/* This is the "colon operator" used various places in Chill. */
name|BINOP_RANGE
block|,
comment|/* This must be the highest BINOP_ value, for expprint.c.  */
name|BINOP_END
block|,
comment|/* Operates on three values computed by following subexpressions.  */
name|TERNOP_COND
block|,
comment|/* ?: */
comment|/* A sub-string/sub-array.  Chill syntax:  OP1(OP2:OP3).      Return elements OP2 through OP3 of OP1.  */
name|TERNOP_SLICE
block|,
comment|/* A sub-string/sub-array.  Chill syntax:  OP1(OP2 UP OP3).      Return OP3 elements of OP1, starting with element OP2. */
name|TERNOP_SLICE_COUNT
block|,
comment|/* Multidimensional subscript operator, such as Modula-2 x[a,b,...].      The dimensionality is encoded in the operator, like the number of      function arguments in OP_FUNCALL, I.E.<OP><dimension><OP>.      The value of the first following subexpression is subscripted      by each of the next following subexpressions, one per dimension. */
name|MULTI_SUBSCRIPT
block|,
comment|/* The OP_... series take immediate following arguments.      After the arguments come another OP_... (the same one)      so that the grouping can be recognized from the end.  */
comment|/* OP_LONG is followed by a type pointer in the next exp_element      and the long constant value in the following exp_element.      Then comes another OP_LONG.      Thus, the operation occupies four exp_elements.  */
name|OP_LONG
block|,
comment|/* OP_DOUBLE is similar but takes a DOUBLEST constant instead of a long.  */
name|OP_DOUBLE
block|,
comment|/* OP_VAR_VALUE takes one struct block * in the following element,      and one struct symbol * in the following exp_element, followed by      another OP_VAR_VALUE, making four exp_elements.  If the block is      non-NULL, evaluate the symbol relative to the innermost frame      executing in that block; if the block is NULL use the selected frame.  */
name|OP_VAR_VALUE
block|,
comment|/* OP_LAST is followed by an integer in the next exp_element.      The integer is zero for the last value printed,      or it is the absolute number of a history element.      With another OP_LAST at the end, this makes three exp_elements.  */
name|OP_LAST
block|,
comment|/* OP_REGISTER is followed by an integer in the next exp_element.      This is the number of a register to fetch (as an int).      With another OP_REGISTER at the end, this makes three exp_elements.  */
name|OP_REGISTER
block|,
comment|/* OP_INTERNALVAR is followed by an internalvar ptr in the next exp_element.      With another OP_INTERNALVAR at the end, this makes three exp_elements.  */
name|OP_INTERNALVAR
block|,
comment|/* OP_FUNCALL is followed by an integer in the next exp_element.      The integer is the number of args to the function call.      That many plus one values from following subexpressions      are used, the first one being the function.      The integer is followed by a repeat of OP_FUNCALL,      making three exp_elements.  */
name|OP_FUNCALL
block|,
comment|/* This is EXACTLY like OP_FUNCALL but is semantically different.        In F77, array subscript expressions, substring expressions      and function calls are  all exactly the same syntactically. They may       only be dismabiguated at runtime.  Thus this operator, which       indicates that we have found something of the form<name> (<stuff> ) */
name|OP_F77_UNDETERMINED_ARGLIST
block|,
comment|/* The following OP is a special one, it introduces a F77 complex      literal. It is followed by exactly two args that are doubles.  */
name|OP_COMPLEX
block|,
comment|/* OP_STRING represents a string constant.      Its format is the same as that of a STRUCTOP, but the string      data is just made into a string constant when the operation      is executed.  */
name|OP_STRING
block|,
comment|/* OP_BITSTRING represents a packed bitstring constant.      Its format is the same as that of a STRUCTOP, but the bitstring      data is just made into a bitstring constant when the operation      is executed.  */
name|OP_BITSTRING
block|,
comment|/* OP_ARRAY creates an array constant out of the following subexpressions.      It is followed by two exp_elements, the first containing an integer      that is the lower bound of the array and the second containing another      integer that is the upper bound of the array.  The second integer is      followed by a repeat of OP_ARRAY, making four exp_elements total.      The bounds are used to compute the number of following subexpressions      to consume, as well as setting the bounds in the created array constant.      The type of the elements is taken from the type of the first subexp,      and they must all match. */
name|OP_ARRAY
block|,
comment|/* UNOP_CAST is followed by a type pointer in the next exp_element.      With another UNOP_CAST at the end, this makes three exp_elements.      It casts the value of the following subexpression.  */
name|UNOP_CAST
block|,
comment|/* UNOP_MEMVAL is followed by a type pointer in the next exp_element      With another UNOP_MEMVAL at the end, this makes three exp_elements.      It casts the contents of the word addressed by the value of the      following subexpression.  */
name|UNOP_MEMVAL
block|,
comment|/* UNOP_... operate on one value from a following subexpression      and replace it with a result.  They take no immediate arguments.  */
name|UNOP_NEG
block|,
comment|/* Unary - */
name|UNOP_LOGICAL_NOT
block|,
comment|/* Unary ! */
name|UNOP_COMPLEMENT
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
name|UNOP_PLUS
block|,
comment|/* Unary plus */
name|UNOP_CAP
block|,
comment|/* Modula-2 standard (unary) procedures */
name|UNOP_CHR
block|,
name|UNOP_ORD
block|,
name|UNOP_ABS
block|,
name|UNOP_FLOAT
block|,
name|UNOP_HIGH
block|,
name|UNOP_MAX
block|,
name|UNOP_MIN
block|,
name|UNOP_ODD
block|,
name|UNOP_TRUNC
block|,
comment|/* Chill builtin functions. */
name|UNOP_LOWER
block|,
name|UNOP_UPPER
block|,
name|UNOP_LENGTH
block|,
name|UNOP_CARD
block|,
name|UNOP_CHMAX
block|,
name|UNOP_CHMIN
block|,
name|OP_BOOL
block|,
comment|/* Modula-2 builtin BOOLEAN type */
name|OP_M2_STRING
block|,
comment|/* Modula-2 string constants */
comment|/* STRUCTOP_... operate on a value from a following subexpression      by extracting a structure component specified by a string      that appears in the following exp_elements (as many as needed).      STRUCTOP_STRUCT is used for "." and STRUCTOP_PTR for "->".      They differ only in the error message given in case the value is      not suitable or the structure component specified is not found.       The length of the string follows the opcode, followed by      BYTES_TO_EXP_ELEM(length) elements containing the data of the      string, followed by the length again and the opcode again.  */
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
block|,
comment|/* Used to represent named structure field values in brace initializers      (or tuples as they are called in Chill).      The gcc C syntax is NAME:VALUE or .NAME=VALUE, the Chill syntax is      .NAME:VALUE.  Multiple labels (as in the Chill syntax      .NAME1,.NAME2:VALUE) is represented as if it were      .NAME1:(.NAME2:VALUE) (though that is not valid Chill syntax).       The NAME is represented as for STRUCTOP_STRUCT;  VALUE follows. */
name|OP_LABELED
block|,
comment|/* OP_TYPE is for parsing types, and used with the "ptype" command      so we can look up types that are qualified by scope, either with      the GDB "::" operator, or the Modula-2 '.' operator. */
name|OP_TYPE
block|,
comment|/* An un-looked-up identifier. */
name|OP_NAME
block|,
comment|/* An unparsed expression.  Used for Scheme (for now at least) */
name|OP_EXPRSTRING
block|}
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
name|DOUBLEST
name|doubleconst
decl_stmt|;
comment|/* Really sizeof (union exp_element) characters (or less for the last      element of a string).  */
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
name|struct
name|block
modifier|*
name|block
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|expression
block|{
specifier|const
name|struct
name|language_defn
modifier|*
name|language_defn
decl_stmt|;
comment|/* language it was entered in */
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

begin_comment
comment|/* Macros for converting between number of expression elements and bytes    to store that many expression elements. */
end_comment

begin_define
define|#
directive|define
name|EXP_ELEM_TO_BYTES
parameter_list|(
name|elements
parameter_list|)
define|\
value|((elements) * sizeof (union exp_element))
end_define

begin_define
define|#
directive|define
name|BYTES_TO_EXP_ELEM
parameter_list|(
name|bytes
parameter_list|)
define|\
value|(((bytes) + sizeof (union exp_element) - 1) / sizeof (union exp_element))
end_define

begin_comment
comment|/* From parse.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|expression
modifier|*
name|parse_expression
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|expression
modifier|*
name|parse_exp_1
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
expr|struct
name|block
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The innermost context required by the stack and register variables    we've encountered so far.  To use this, set it to NULL, then call    parse_<whatever>, then look at it.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|innermost_block
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From eval.c */
end_comment

begin_comment
comment|/* Values of NOSIDE argument to eval_subexp.  */
end_comment

begin_enum
enum|enum
name|noside
block|{
name|EVAL_NORMAL
block|,
name|EVAL_SKIP
block|,
comment|/* Only effect is to increment pos.  */
name|EVAL_AVOID_SIDE_EFFECTS
comment|/* Don't modify any variables or 				   call any functions.  The value 				   returned will have the correct 				   type, and will have an 				   approximately correct lvalue 				   type (inaccuracy: anything that is 				   listed as being in a register in 				   the function in which it was 				   declared will be lval_register).  */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|struct
name|value
modifier|*
name|evaluate_subexp_standard
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|expression
operator|*
operator|,
name|int
operator|*
operator|,
expr|enum
name|noside
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From expprint.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|print_expression
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
operator|,
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|op_string
name|PARAMS
argument_list|(
operator|(
expr|enum
name|exp_opcode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MAINTENANCE_CMDS
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_prefix_expression
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_postfix_expression
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|char
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
comment|/* MAINTENANCE_CMDS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (EXPRESSION_H) */
end_comment

end_unit

