begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C parsing and type checking.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

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
value|(((struct lang_identifier *)(NODE))->global_value)
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
value|(((struct lang_identifier *)(NODE))->local_value)
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
value|(((struct lang_identifier *)(NODE))->label_value)
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
value|(((struct lang_identifier *)(NODE))->limbo_value)
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
value|(((struct lang_identifier *)(NODE))->implicit_decl)
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
value|(((struct lang_identifier *)(NODE))->error_locus)
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
value|(TREE_COMPLEXITY (exp) = (int)(code))
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

begin_escape
end_escape

begin_comment
comment|/* in c-typecheck.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref
argument_list|()
decl_stmt|,
name|build_conditional_expr
argument_list|()
decl_stmt|,
name|build_compound_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_unary_op
argument_list|()
decl_stmt|,
name|build_binary_op
argument_list|()
decl_stmt|,
name|build_function_call
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|parser_build_binary_op
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_indirect_ref
argument_list|()
decl_stmt|,
name|build_array_ref
argument_list|()
decl_stmt|,
name|build_c_cast
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_modify_expr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|c_sizeof
argument_list|()
decl_stmt|,
name|c_alignof
argument_list|()
decl_stmt|,
name|c_alignof_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|store_init_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|digest_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_expand_start_case
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|default_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given two integer or real types, return the type for their sum.    Given two compatible ANSI C types, returns the merged type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|common_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in c-decl.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_label
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|start_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_parm_decls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_parm_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|combine_parm_decls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushlevel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|poplevel
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|groktypename
argument_list|()
decl_stmt|,
name|lookup_name
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_label
argument_list|()
decl_stmt|,
name|define_label
argument_list|()
decl_stmt|,
name|shadow_label
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|implicitly_declare
argument_list|()
decl_stmt|,
name|getdecls
argument_list|()
decl_stmt|,
name|gettags
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|start_decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_decl
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|start_struct
argument_list|()
decl_stmt|,
name|finish_struct
argument_list|()
decl_stmt|,
name|xref_tag
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|grokfield
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|start_enum
argument_list|()
decl_stmt|,
name|finish_enum
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_enumerator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_index_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Add qualifiers to a type, in the fashion for C.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|c_build_type_variant
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Declare a predefined function.  Return the declaration.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|builtin_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in c-common.c: */
end_comment

begin_comment
comment|/* Concatenate a list of STRING_CST nodes into one STRING_CST.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|combine_strings
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Validate the expression after `case' and apply default promotions.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|check_case_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Print an error message for invalid operands to arith operation CODE.    NOP_EXPR is used as a special case (see truthvalue_conversion).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|binary_op_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Subroutine of build_binary_op, used for comparison operations.    See if the operands have both been converted from subword integer types    and, if so, perhaps change them both back to their original type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|shorten_compare
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Read the rest of the current #-directive line.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_directive_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Prepare expr to be an argument of a TRUTH_NOT_EXPR,    or validate its data type for an `if' or `while' statement or ?..: exp. */
end_comment

begin_function_decl
specifier|extern
name|tree
name|truthvalue_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|maybe_objc_comptypes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_building_objc_message_expr
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Standard named or nameless data types of the C compiler.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|short_integer_type_node
decl_stmt|,
name|integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_integer_type_node
decl_stmt|,
name|long_long_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|short_unsigned_type_node
decl_stmt|,
name|unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_unsigned_type_node
decl_stmt|,
name|long_long_unsigned_type_node
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
name|unsigned_char_type_node
decl_stmt|,
name|signed_char_type_node
decl_stmt|,
name|char_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|wchar_type_node
decl_stmt|,
name|signed_wchar_type_node
decl_stmt|,
name|unsigned_wchar_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|float_type_node
decl_stmt|,
name|double_type_node
decl_stmt|,
name|long_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intQI_type_node
decl_stmt|,
name|unsigned_intQI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intHI_type_node
decl_stmt|,
name|unsigned_intHI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intSI_type_node
decl_stmt|,
name|unsigned_intSI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intDI_type_node
decl_stmt|,
name|unsigned_intDI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_type_node
decl_stmt|,
name|ptr_type_node
decl_stmt|,
name|const_ptr_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|string_type_node
decl_stmt|,
name|const_string_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|char_array_type_node
decl_stmt|,
name|int_array_type_node
decl_stmt|,
name|wchar_array_type_node
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
decl_stmt|,
name|double_ftype_double_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_ftype_int
decl_stmt|,
name|long_ftype_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_ftype_ptr_ptr_int
decl_stmt|,
name|int_ftype_ptr_ptr_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_ftype_ptr_int_int
decl_stmt|,
name|string_ftype_ptr_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|int_ftype_string_string
decl_stmt|,
name|int_ftype_cptr_cptr_sizet
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
comment|/* Nonzero means ignore `#ident' directives.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_ident
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
name|warn_write_strings
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
comment|/* Nonzero means do some things the same way PCC does.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_traditional
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
comment|/* Nonzero means this is a function to call to perform comptypes    on two record types.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|comptypes_record_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero means we are reading code that came from a system header file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|system_header_p
decl_stmt|;
end_decl_stmt

end_unit

