begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parser definitions for GDB.     Copyright 1986, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996,    1997, 1998, 1999, 2000, 2002 Free Software Foundation, Inc.     Modified from expread.y by the Department of Computer Science at the    State University of New York at Buffalo.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PARSER_DEFS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|PARSER_DEFS_H
value|1
end_define

begin_include
include|#
directive|include
file|"doublest.h"
end_include

begin_struct_decl
struct_decl|struct
name|block
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|expression
modifier|*
name|expout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expout_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expout_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If this is nonzero, this block is used as the lexical context    for symbol names.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|expression_context_block
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If expression_context_block is non-zero, then this is the PC within    the block that we want to evaluate expressions at.  When debugging    C or C++ code, we use this to find the exact line we're at, and    then look up the macro definitions active at that point.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|expression_context_pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The innermost context required by the stack and register variables    we've encountered so far. */
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
comment|/* The block in which the most recently discovered symbol was found.    FIXME: Should be declared along with lookup_symbol in symtab.h; is not    related specifically to parsing.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|block_found
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of arguments seen so far in innermost function call.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arglist_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A string token, either a char-string or bit-string.  Char-strings are    used, for example, for the names of symbols. */
end_comment

begin_struct
struct|struct
name|stoken
block|{
comment|/* Pointer to first byte of char-string or first bit of bit-string */
name|char
modifier|*
name|ptr
decl_stmt|;
comment|/* Length of string in bytes for char-string or bits for bit-string */
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ttype
block|{
name|struct
name|stoken
name|stoken
decl_stmt|;
name|struct
name|type
modifier|*
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|symtoken
block|{
name|struct
name|stoken
name|stoken
decl_stmt|;
name|struct
name|symbol
modifier|*
name|sym
decl_stmt|;
name|int
name|is_a_field_of_this
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|objc_class_str
block|{
name|struct
name|stoken
name|stoken
decl_stmt|;
name|struct
name|type
modifier|*
name|type
decl_stmt|;
name|int
name|class
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For parsing of complicated types.    An array should be preceded in the list by the size of the array.  */
end_comment

begin_enum
enum|enum
name|type_pieces
block|{
name|tp_end
init|=
operator|-
literal|1
block|,
name|tp_pointer
block|,
name|tp_reference
block|,
name|tp_array
block|,
name|tp_function
block|,
name|tp_const
block|,
name|tp_volatile
block|,
name|tp_space_identifier
block|}
enum|;
end_enum

begin_comment
comment|/* The stack can contain either an enum type_pieces or an int.  */
end_comment

begin_union
union|union
name|type_stack_elt
block|{
name|enum
name|type_pieces
name|piece
decl_stmt|;
name|int
name|int_val
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|union
name|type_stack_elt
modifier|*
name|type_stack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|type_stack_depth
decl_stmt|,
name|type_stack_size
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|write_exp_elt
parameter_list|(
name|union
name|exp_element
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_opcode
parameter_list|(
name|enum
name|exp_opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_sym
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_longcst
parameter_list|(
name|LONGEST
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_dblcst
parameter_list|(
name|DOUBLEST
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_intern
parameter_list|(
name|struct
name|internalvar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_string
parameter_list|(
name|struct
name|stoken
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_bitstring
parameter_list|(
name|struct
name|stoken
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_elt_block
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_exp_msymbol
parameter_list|(
name|struct
name|minimal_symbol
modifier|*
parameter_list|,
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_dollar_variable
parameter_list|(
name|struct
name|stoken
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|parse_nested_classes_for_hpacc
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|find_template_name_end
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_arglist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|end_arglist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|copy_name
parameter_list|(
name|struct
name|stoken
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_type
parameter_list|(
name|enum
name|type_pieces
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_type_int
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_type_address_space
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|type_pieces
name|pop_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pop_type_int
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|length_of_subexp
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dump_subexp
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dump_subexp_body_standard
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|operator_length
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|operator_length_standard
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|op_name_standard
parameter_list|(
name|enum
name|exp_opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|follow_types
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* During parsing of a C expression, the pointer to the next character    is in this variable.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lexptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After a token has been recognized, this variable points to it.      Currently used only for error reporting.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prev_lexptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tokens that refer to names do so with explicit pointer and length,    so they can share the storage that lexptr is parsing.     When it is necessary to pass a name to a function that expects    a null-terminated string, the substring is copied out    into a block of storage that namecopy points to.     namecopy is allocated once, guaranteed big enough, for each parsing.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|namecopy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current depth in parentheses within the expression.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|paren_depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means stop parsing on first comma (if not within parentheses).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|comma_terminates
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* These codes indicate operator precedences for expression printing,    least tightly binding first.  */
end_comment

begin_comment
comment|/* Adding 1 to a precedence value is done for binary operators,    on the operand which is more tightly bound, so that operators    of equal precedence within that operand will get parentheses.  */
end_comment

begin_comment
comment|/* PREC_HYPER and PREC_ABOVE_COMMA are not the precedence of any operator;    they are used as the "surrounding precedence" to force    various kinds of things to be parenthesized.  */
end_comment

begin_enum
enum|enum
name|precedence
block|{
name|PREC_NULL
block|,
name|PREC_COMMA
block|,
name|PREC_ABOVE_COMMA
block|,
name|PREC_ASSIGN
block|,
name|PREC_LOGICAL_OR
block|,
name|PREC_LOGICAL_AND
block|,
name|PREC_BITWISE_IOR
block|,
name|PREC_BITWISE_AND
block|,
name|PREC_BITWISE_XOR
block|,
name|PREC_EQUAL
block|,
name|PREC_ORDER
block|,
name|PREC_SHIFT
block|,
name|PREC_ADD
block|,
name|PREC_MUL
block|,
name|PREC_REPEAT
block|,
name|PREC_HYPER
block|,
name|PREC_PREFIX
block|,
name|PREC_SUFFIX
block|,
name|PREC_BUILTIN_FUNCTION
block|}
enum|;
end_enum

begin_comment
comment|/* Table mapping opcodes into strings for printing operators    and precedences of the operators.  */
end_comment

begin_struct
struct|struct
name|op_print
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|enum
name|exp_opcode
name|opcode
decl_stmt|;
comment|/* Precedence of operator.  These values are used only by comparisons.  */
name|enum
name|precedence
name|precedence
decl_stmt|;
comment|/* For a binary operator:  1 iff right associate.        For a unary operator:  1 iff postfix. */
name|int
name|right_assoc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information needed to print, prefixify, and evaluate expressions for     a given language.  */
end_comment

begin_struct
struct|struct
name|exp_descriptor
block|{
comment|/* Print subexpression.  */
name|void
function_decl|(
modifier|*
name|print_subexp
function_decl|)
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|enum
name|precedence
parameter_list|)
function_decl|;
comment|/* Returns number of exp_elements needed to represent an operator and        the number of subexpressions it takes.  */
name|void
function_decl|(
modifier|*
name|operator_length
function_decl|)
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/* Name of this operator for dumping purposes.  */
name|char
modifier|*
function_decl|(
modifier|*
name|op_name
function_decl|)
parameter_list|(
name|enum
name|exp_opcode
parameter_list|)
function_decl|;
comment|/* Dump the rest of this (prefix) expression after the operator        itself has been printed.  See dump_subexp_body_standard in        (expprint.c).  */
name|int
function_decl|(
modifier|*
name|dump_subexp_body
function_decl|)
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Evaluate an expression.  */
name|struct
name|value
modifier|*
function_decl|(
modifier|*
name|evaluate_exp
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|expression
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|enum
name|noside
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Default descriptor containing standard definitions of all    elements.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|exp_descriptor
name|exp_descriptor_standard
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions used by language-specific extended operators to (recursively)    print/dump subexpressions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_subexp
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|enum
name|precedence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_subexp_standard
parameter_list|(
name|struct
name|expression
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|enum
name|precedence
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Function used to avoid direct calls to fprintf    in the code generated by the bison parser.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|parser_fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PARSER_DEFS_H */
end_comment

end_unit

