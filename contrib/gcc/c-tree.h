begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C parsing and type checking.    Copyright (C) 1987, 93, 94, 95, 97, 98, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_C_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|_C_TREE_H
end_define

begin_comment
comment|/* Language-dependent contents of an identifier.  */
end_comment

begin_comment
comment|/* The limbo_value is used for block level extern declarations, which need    to be type checked against subsequent extern declarations.  They can't    be referenced after they fall out of scope, so they can't be global.  */
end_comment

begin_struct
struct|struct
name|lang_identifier
block|{
name|struct
name|tree_identifier
name|ignore
decl_stmt|;
name|tree
name|global_value
decl_stmt|,
name|local_value
decl_stmt|,
name|label_value
decl_stmt|,
name|implicit_decl
decl_stmt|;
name|tree
name|error_locus
decl_stmt|,
name|limbo_value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macros for access to language-specific slots in an identifier.  */
end_comment

begin_comment
comment|/* Each of these slots contains a DECL node or null.  */
end_comment

begin_comment
comment|/* This represents the value which the identifier has in the    file-scope namespace.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_GLOBAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->global_value)
end_define

begin_comment
comment|/* This represents the value which the identifier has in the current    scope.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_LOCAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->local_value)
end_define

begin_comment
comment|/* This represents the value which the identifier has as a label in    the current label scope.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->label_value)
end_define

begin_comment
comment|/* This records the extern decl of this identifier, if it has had one    at any point in this compilation.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_LIMBO_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->limbo_value)
end_define

begin_comment
comment|/* This records the implicit function decl of this identifier, if it    has had one at any point in this compilation.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->implicit_decl)
end_define

begin_comment
comment|/* This is the last function in which we printed an "undefined variable"    message for this identifier.  Value is a FUNCTION_DECL or null.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->error_locus)
end_define

begin_comment
comment|/* In identifiers, C uses the following fields in a special way:    TREE_PUBLIC        to record that there was a previous local extern decl.    TREE_USED          to record that such a decl was used.    TREE_ADDRESSABLE   to record that the address of such a decl was used.  */
end_comment

begin_comment
comment|/* Nonzero means reject anything that ANSI standard C forbids.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pedantic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_READONLY
parameter_list|(
name|type
parameter_list|)
value|TREE_LANG_FLAG_1 (type)
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is volatile.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_VOLATILE
parameter_list|(
name|type
parameter_list|)
value|TREE_LANG_FLAG_2 (type)
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE or ENUMERAL_TYPE    nonzero if the definition of the type has already started.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_BEING_DEFINED
parameter_list|(
name|type
parameter_list|)
value|TYPE_LANG_FLAG_0 (type)
end_define

begin_comment
comment|/* C types are partitioned into three subsets: object, function, and    incomplete types.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_OBJECT_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) != FUNCTION_TYPE&& TYPE_SIZE (type))
end_define

begin_define
define|#
directive|define
name|C_TYPE_FUNCTION_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) == FUNCTION_TYPE)
end_define

begin_define
define|#
directive|define
name|C_TYPE_INCOMPLETE_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) != FUNCTION_TYPE&& TYPE_SIZE (type) == 0)
end_define

begin_comment
comment|/* For convenience we define a single macro to identify the class of    object or incomplete types.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_OBJECT_OR_INCOMPLETE_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(!C_TYPE_FUNCTION_P (type))
end_define

begin_comment
comment|/* In a RECORD_TYPE, a sorted array of the fields of the type.  */
end_comment

begin_struct
struct|struct
name|lang_type
block|{
name|int
name|len
decl_stmt|;
name|tree
name|elts
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Mark which labels are explicitly declared.    These may be shadowed, and may be referenced from nested functions.  */
end_comment

begin_define
define|#
directive|define
name|C_DECLARED_LABEL_FLAG
parameter_list|(
name|label
parameter_list|)
value|TREE_LANG_FLAG_1 (label)
end_define

begin_comment
comment|/* Record whether a type or decl was written with nonconstant size.    Note that TYPE_SIZE may have simplified to a constant.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_VARIABLE_SIZE
parameter_list|(
name|type
parameter_list|)
value|TYPE_LANG_FLAG_1 (type)
end_define

begin_define
define|#
directive|define
name|C_DECL_VARIABLE_SIZE
parameter_list|(
name|type
parameter_list|)
value|DECL_LANG_FLAG_0 (type)
end_define

begin_comment
comment|/* Record in each node resulting from a binary operator    what operator was specified for it.  */
end_comment

begin_define
define|#
directive|define
name|C_EXP_ORIGINAL_CODE
parameter_list|(
name|exp
parameter_list|)
value|((enum tree_code) TREE_COMPLEXITY (exp))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Not used.  */
end_comment

begin_comment
comment|/* Record whether a decl for a function or function pointer has    already been mentioned (in a warning) because it was called    but didn't have a prototype.  */
end_comment

begin_define
define|#
directive|define
name|C_MISSING_PROTOTYPE_WARNED
parameter_list|(
name|decl
parameter_list|)
value|DECL_LANG_FLAG_2(decl)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Store a value in that field.  */
end_comment

begin_define
define|#
directive|define
name|C_SET_EXP_ORIGINAL_CODE
parameter_list|(
name|exp
parameter_list|,
name|code
parameter_list|)
define|\
value|(TREE_COMPLEXITY (exp) = (int) (code))
end_define

begin_comment
comment|/* Record whether a typedef for type `int' was actually `signed int'.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPEDEF_EXPLICITLY_SIGNED
parameter_list|(
name|exp
parameter_list|)
value|DECL_LANG_FLAG_1 ((exp))
end_define

begin_comment
comment|/* Nonzero for a declaration of a built in function if there has been no    occasion that would declare the function in ordinary C.    Using the function draws a pedantic warning in this case.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_ANTICIPATED
parameter_list|(
name|exp
parameter_list|)
value|DECL_LANG_FLAG_3 ((exp))
end_define

begin_comment
comment|/* For FUNCTION_TYPE, a hidden list of types of arguments.  The same as    TYPE_ARG_TYPES for functions with prototypes, but created for functions    without prototypes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ACTUAL_ARG_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_NONCOPIED_PARTS (NODE)
end_define

begin_comment
comment|/* In a FIELD_DECL, nonzero if the decl was originally a bitfield.  */
end_comment

begin_define
define|#
directive|define
name|DECL_C_BIT_FIELD
parameter_list|(
name|NODE
parameter_list|)
value|DECL_LANG_FLAG_4 (NODE)
end_define

begin_comment
comment|/* Nonzero if the type T promotes to itself.    ANSI C states explicitly the list of types that promote;    in particular, short promotes to int even if they have the same width.  */
end_comment

begin_define
define|#
directive|define
name|C_PROMOTING_INTEGER_TYPE_P
parameter_list|(
name|t
parameter_list|)
define|\
value|(TREE_CODE ((t)) == INTEGER_TYPE				\&& (TYPE_MAIN_VARIANT (t) == char_type_node			\        || TYPE_MAIN_VARIANT (t) == signed_char_type_node	\        || TYPE_MAIN_VARIANT (t) == unsigned_char_type_node	\        || TYPE_MAIN_VARIANT (t) == short_integer_type_node	\        || TYPE_MAIN_VARIANT (t) == short_unsigned_type_node))
end_define

begin_comment
comment|/* In a VAR_DECL, means the variable is really an iterator.  */
end_comment

begin_define
define|#
directive|define
name|ITERATOR_P
parameter_list|(
name|D
parameter_list|)
value|(DECL_LANG_FLAG_4(D))
end_define

begin_comment
comment|/* In a VAR_DECL for an iterator, means we are within    an explicit loop over that iterator.  */
end_comment

begin_define
define|#
directive|define
name|ITERATOR_BOUND_P
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.readonly_flag)
end_define

begin_escape
end_escape

begin_comment
comment|/* in c-lang.c and objc-act.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|lookup_interface
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|is_class_name
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_objc_check_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_file
name|PROTO
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
name|maybe_objc_comptypes
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|maybe_building_objc_message_expr
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|maybe_objc_method_name
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|recognize_objc_keyword
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_objc_string
name|PROTO
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* in c-aux-info.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_aux_info_record
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in c-common.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|declare_function_name
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|decl_attributes
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_function_format_info
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_function_format
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_get_alias_set
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_apply_type_quals_to_decl
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print an error message for invalid operands to arith operation CODE.    NOP_EXPR is used as a special case (see truthvalue_conversion).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|binary_op_error
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_expand_expr_stmt
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_expand_start_cond
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_expand_start_else
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_expand_end_cond
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Validate the expression after `case' and apply default promotions.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|check_case_value
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate a list of STRING_CST nodes into one STRING_CST.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|combine_strings
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|constant_expression_warning
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_and_check
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|overflow_warning
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unsigned_conversion_warning
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read the rest of the current #-directive line.  */
end_comment

begin_if
if|#
directive|if
name|USE_CPPLIB
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_directive_line
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_DIRECTIVE_LINE
parameter_list|()
value|get_directive_line ()
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_directive_line
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_DIRECTIVE_LINE
parameter_list|()
value|get_directive_line (finput)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Subroutine of build_binary_op, used for comparison operations.    See if the operands have both been converted from subword integer types    and, if so, perhaps change them both back to their original type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|shorten_compare
name|PROTO
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
expr|enum
name|tree_code
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare expr to be an argument of a TRUTH_NOT_EXPR,    or validate its data type for an `if' or `while' statement or ?..: exp. */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|truthvalue_conversion
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_for_mode
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_for_size
name|PROTO
argument_list|(
operator|(
name|unsigned
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in c-convert.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|convert
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in c-decl.c */
end_comment

begin_comment
comment|/* Standard named or nameless data types of the C compiler.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|char_array_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|char_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|const_ptr_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|const_string_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|default_function_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|double_ftype_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|double_ftype_double_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|float_type_node
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|>=
literal|64
end_if

begin_decl_stmt
specifier|extern
name|tree
name|intTI_type_node
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|intDI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intHI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intQI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intSI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_array_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_ftype_cptr_cptr_sizet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_ftype_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_ftype_ptr_ptr_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_ftype_string_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_ftype_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_float_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_long_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ptr_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ptrdiff_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|short_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|short_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|signed_char_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|signed_wchar_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|string_ftype_ptr_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|string_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_char_type_node
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|>=
literal|64
end_if

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_intTI_type_node
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_intDI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_intHI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_intQI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_intSI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_wchar_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_ftype_ptr_int_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_ftype_ptr_ptr_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|wchar_array_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|wchar_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|boolean_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|boolean_true_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|boolean_false_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_enumerator
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare a predefined function.  Return the declaration.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|builtin_function
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|,
expr|enum
name|built_in_function
name|function_
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add qualifiers to a type, in the fashion for C.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|c_build_qualified_type
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|c_build_type_variant
parameter_list|(
name|TYPE
parameter_list|,
name|CONST_P
parameter_list|,
name|VOLATILE_P
parameter_list|)
define|\
value|c_build_qualified_type (TYPE, 				  \ 			  ((CONST_P) ? TYPE_QUAL_CONST : 0) |	  \ 			  ((VOLATILE_P) ? TYPE_QUAL_VOLATILE : 0))
end_define

begin_decl_stmt
specifier|extern
name|int
name|c_decode_option
name|PROTO
argument_list|(
operator|(
name|int
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
name|void
name|c_mark_varargs
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|check_identifier
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_parm_order
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|combine_parm_decls
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|complete_array_type
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|declare_parm_level
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|define_label
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_block
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_decl_top_level
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_enum
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_function
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_struct
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_parm_info
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|getdecls
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|gettags
name|PROTO
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
name|global_bindings_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grokfield
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|groktypename
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|groktypename_in_parm_context
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|implicitly_declare
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_parm_level_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_decl_processing
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insert_block
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keep_next_level
name|PROTO
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
name|kept_level_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_label
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name_current_level
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name_current_level_global
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|maybe_build_cleanup
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|parmlist_tags_warning
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pending_xref_error
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_c_function_context
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_label_level
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|poplevel
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_lang_decl
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_lang_identifier
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_lang_type
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_c_function_context
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_label_level
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_parm_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pushdecl
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pushdecl_top_level
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushlevel
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushtag
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_block
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|shadow_label
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shadow_record_fields
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shadow_tag
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shadow_tag_warned
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_enum
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|start_function
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_struct
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|store_parm_decls
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|xref_tag
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in c-typeck.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|require_complete_type
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|incomplete_type_error
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given two integer or real types, return the type for their sum.    Given two compatible ANSI C types, returns the merged type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|common_type
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comptypes
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|self_promoting_args_p
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_sizeof
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_sizeof_nowarn
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_size_in_bytes
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_alignof
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_alignof_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|default_conversion
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_indirect_ref
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_array_ref
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_function_call
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|parser_build_binary_op
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_binary_op
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_unary_op
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lvalue_p
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lvalue_or_else
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|readonly_warning
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mark_addressable
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_conditional_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_compound_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_c_cast
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_modify_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|initializer_constant_valid_p
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|store_init_value
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|error_init
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pedwarn_init
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|start_init
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_init
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|really_start_incremental_init
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_init_level
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pop_init_level
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_init_index
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_init_label
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process_init_element
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_expand_asm_operands
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_expand_return
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_expand_start_case
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in c-iterate.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_iterators
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|iterator_expand
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|iterator_for_loop_start
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|iterator_for_loop_end
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|iterator_for_loop_record
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_iterator_stack
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_iterator_stack
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a return statement that specifies a return value is seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a return statement with no argument is seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means the expression being parsed will never be evaluated.    This is a count, since unevaluated expressions can nest.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|skip_evaluation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means `$' can be in an identifier.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dollars_in_ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means allow type mismatches in conditional expressions;    just make their values `void'.   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cond_mismatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't recognize the keyword `asm'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_asm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means environment is hosted (i.e., not freestanding) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_hosted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about implicit declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_implicit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means give string constants the type `const char *'    to get extra warnings from them.  These warnings will be too numerous    to be useful, except in thoroughly ANSIfied programs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_const_strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about sizeof (function) or addition/subtraction    of function pointers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_pointer_arith
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn for all old-style non-prototype function decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_strict_prototypes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about multiple (redundant) decls for the same single    variable or function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_redundant_decls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about extern declarations of objects not at    file-scope level and about *all* declarations of functions (whether    extern or static) not at file-scope level.  Note that we exclude    implicit function declarations.  To get warnings about those, use    -Wimplicit.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nested_externs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about pointer casts that can drop a type qualifier    from the pointer target type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_cast_qual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when casting a function call to a type that does    not match the return type (e.g. (float)sqrt() or (anything*)malloc()    when there is no previous declaration of sqrt or malloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_bad_function_cast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about functions which might be candidates for attribute noreturn. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_missing_noreturn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about traditional constructs whose meanings changed in ANSI C.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_traditional
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about *printf or *scanf format/argument anomalies. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|warn_format_extra_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about a subscript that has type char.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_char_subscripts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if a type conversion is done that might have confusing results.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_conversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if main is suspicious. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_main
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means do some things the same way PCC does.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_traditional
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means use the ISO C9x dialect of C.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_isoc9x
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to allow single precision math even if we're generally    being traditional. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_allow_single_precision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about suggesting putting in ()'s.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_parentheses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if initializer is not completely bracketed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_missing_braces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about comparison of signed and unsigned values.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_sign_compare
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about multicharacter constants.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_multichar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about long long.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_long_long
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we are reading code that came from a system header file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|system_header_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero enables objc features.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doing_objc_thang
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In c-decl.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|finish_incomplete_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _C_TREE_H */
end_comment

end_unit

