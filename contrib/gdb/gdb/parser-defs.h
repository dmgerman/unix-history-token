begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parser definitions for GDB.    Copyright (C) 1986, 1989, 1990, 1991 Free Software Foundation, Inc.    Modified from expread.y by the Department of Computer Science at the    State University of New York at Buffalo.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_struct
struct|struct
name|std_regs
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|regnum
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|std_regs
name|std_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|num_std_regs
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt
name|PARAMS
argument_list|(
operator|(
expr|union
name|exp_element
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_opcode
name|PARAMS
argument_list|(
operator|(
expr|enum
name|exp_opcode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_sym
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_longcst
name|PARAMS
argument_list|(
operator|(
name|LONGEST
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_dblcst
name|PARAMS
argument_list|(
operator|(
name|DOUBLEST
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_intern
name|PARAMS
argument_list|(
operator|(
expr|struct
name|internalvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_string
name|PARAMS
argument_list|(
operator|(
expr|struct
name|stoken
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_bitstring
name|PARAMS
argument_list|(
operator|(
expr|struct
name|stoken
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_elt_block
name|PARAMS
argument_list|(
operator|(
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_exp_msymbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|minimal_symbol
operator|*
operator|,
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_dollar_variable
name|PARAMS
argument_list|(
operator|(
expr|struct
name|stoken
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|parse_nested_classes_for_hpacc
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|find_template_name_end
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
name|void
name|start_arglist
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
name|int
name|end_arglist
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
name|char
modifier|*
name|copy_name
name|PARAMS
argument_list|(
operator|(
expr|struct
name|stoken
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_type
name|PARAMS
argument_list|(
operator|(
expr|enum
name|type_pieces
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_type_int
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|type_pieces
name|pop_type
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
name|int
name|pop_type_int
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
name|int
name|length_of_subexp
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|follow_types
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* For a binary operator:  1 iff right associate.      For a unary operator:  1 iff postfix. */
name|int
name|right_assoc
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PARSER_DEFS_H */
end_comment

end_unit

