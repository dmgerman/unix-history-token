begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C++ parsing and type checking.    Copyright (C) 1987 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Borrow everything that is C from c-tree.h,    but do so by copy, not by inclusion, since c-tree.h defines    lang_identifier.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARANOID
end_ifndef

begin_define
define|#
directive|define
name|PARANOID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Language-dependent contents of an identifier.  */
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
decl_stmt|;
name|tree
name|class_value
decl_stmt|;
name|tree
name|class_template_info
decl_stmt|;
name|struct
name|lang_id2
modifier|*
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lang_id2
block|{
name|tree
name|label_value
decl_stmt|,
name|implicit_decl
decl_stmt|;
name|tree
name|type_desc
decl_stmt|,
name|as_list
decl_stmt|,
name|error_locus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macros for access to language-specific slots in an identifier.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|PARANOID
end_if

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

begin_define
define|#
directive|define
name|IDENTIFIER_CLASS_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->class_value)
end_define

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

begin_define
define|#
directive|define
name|IDENTIFIER_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->class_template_info)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IDENTIFIER_LANG_SPECIFIC_PTR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(my_friendly_assert (TREE_CODE (NODE) == IDENTIFIER_NODE, 325),	\    (struct lang_identifier *) (NODE))
end_define

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

begin_define
define|#
directive|define
name|IDENTIFIER_CLASS_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->class_value)
end_define

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

begin_define
define|#
directive|define
name|IDENTIFIER_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_LANG_SPECIFIC_PTR (NODE) -> class_template_info)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|PARANOID
end_if

begin_define
define|#
directive|define
name|IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_TYPE (NODE))
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|TYPE
parameter_list|)
value|(TREE_TYPE (NODE) = TYPE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(*IDENTIFIER_TYPE_VALUE_PTR(NODE))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
name|__inline
endif|#
directive|endif
specifier|static
name|tree
modifier|*
name|IDENTIFIER_TYPE_VALUE_PTR
parameter_list|(
name|NODE
parameter_list|)
name|tree
name|NODE
decl_stmt|;
block|{
return|return
operator|(
name|my_friendly_assert
argument_list|(
name|TREE_CODE
argument_list|(
name|NODE
argument_list|)
operator|==
name|IDENTIFIER_NODE
argument_list|,
literal|326
argument_list|)
operator|,
operator|&
name|TREE_TYPE
argument_list|(
name|NODE
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|SET_IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|TYPE
parameter_list|)
value|(IDENTIFIER_TYPE_VALUE(NODE)=TYPE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IDENTIFIER_HAS_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_TYPE (NODE) ? 1 : 0)
end_define

begin_function_decl
specifier|extern
name|tree
name|identifier_typedecl_value
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IDENTIFIER_TYPEDECL_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|identifier_typedecl_value (NODE)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->label_value : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->label_value = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->implicit_decl : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->implicit_decl = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_AS_DESC
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->type_desc : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_AS_DESC
parameter_list|(
name|NODE
parameter_list|,
name|DESC
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->type_desc = (DESC))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_AS_LIST
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->as_list : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_AS_LIST
parameter_list|(
name|NODE
parameter_list|,
name|LIST
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->as_list = (LIST))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->error_locus : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->error_locus = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1(NODE)
end_define

begin_comment
comment|/* Nonzero if this identifier is the prefix for a mangled C++ operator name.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_OPNAME_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_2(NODE)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_TYPENAME_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(! strncmp (IDENTIFIER_POINTER (NODE),			\ 	      IDENTIFIER_POINTER (ansi_opname[(int) TYPE_EXPR]),	\ 	      IDENTIFIER_LENGTH (ansi_opname[(int) TYPE_EXPR])))
end_define

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
value|TYPE_LANG_FLAG_0 (type)
end_define

begin_comment
comment|/* in tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|purpose_member
argument_list|()
decl_stmt|,
name|value_member
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|binfo_member
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-typeck.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref
argument_list|()
decl_stmt|,
name|build_conditional_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_compound_expr
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
name|build_binary_op_nodefault
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
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
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

begin_decl_stmt
specifier|extern
name|int
name|comptypes
argument_list|()
decl_stmt|,
name|compparms
argument_list|()
decl_stmt|,
name|compexcepttypes
argument_list|()
decl_stmt|;
end_decl_stmt

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
comment|/* in cp-decl.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_label
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* If non-zero, a VAR_DECL whose cleanup will cause a throw to the    next exception handler.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|exception_throw_decl
decl_stmt|;
end_decl_stmt

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
decl_stmt|,
name|xref_defn_tag
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|finish_exception
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|grokfield
argument_list|()
decl_stmt|,
name|grokbitfield
argument_list|()
decl_stmt|;
end_decl_stmt

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

begin_function_decl
specifier|extern
name|tree
name|make_anon_name
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not yet, should get fixed properly later */
end_comment

begin_endif
unit|extern tree make_type_decl ();
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|cplus_decl_attributes
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
comment|/* Subroutine of build_binary_op_nodefault, used for comparison operations.    See if the operands have both been converted from subword integer types    and, if so, perhaps change them both back to their original type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|shorten_compare
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

begin_escape
end_escape

begin_decl_stmt
specifier|extern
name|tree
name|double_type_node
decl_stmt|,
name|long_double_type_node
decl_stmt|,
name|float_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|char_type_node
decl_stmt|,
name|unsigned_char_type_node
decl_stmt|,
name|signed_char_type_node
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
decl_stmt|,
name|short_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_integer_type_node
decl_stmt|,
name|long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|,
name|long_long_unsigned_type_node
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
name|string_type_node
decl_stmt|,
name|char_array_type_node
decl_stmt|,
name|int_array_type_node
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
decl_stmt|,
name|signed_wchar_type_node
decl_stmt|,
name|unsigned_wchar_type_node
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
name|int
name|current_function_returns_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_function_return_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ridpointers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ansi_opname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ansi_assopname
index|[]
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
comment|/* For cross referencing.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gnu_xref
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For environments where you can use GNU binutils (as, ld in particular).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gnu_binutils
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
comment|/* Nonzero means warn about function definitions that default the return type    or that use a null return and have a return-type other than void.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_return_type
decl_stmt|,
name|explicit_warn_return_type
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
comment|/* Nonzero means warn about sizeof(function) or addition/subtraction    of function pointers.  */
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
comment|/* Nonzero means warn about suggesting putting in ()'s.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_parentheses
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
comment|/* Nonzero means warn about non virtual destructors in classes that have    virtual functions. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nonvdtor
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
comment|/* Nonzero means to treat bitfields as unsigned unless they say `signed'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_signed_bitfields
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3 means write out only virtuals function tables `defined'    in this implementation file.    2 means write out only specific virtual function tables    and give them (C) public visibility.    1 means write out virtual function tables and give them    (C) public visibility.    0 means write out virtual function tables and give them    (C) static visibility (default).    -1 means declare virtual function tables extern.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write_virtuals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* INTERFACE_ONLY nonzero means that we are in an "interface"    section of the compiler.  INTERFACE_UNKNOWN nonzero means    we cannot trust the value of INTERFACE_ONLY.  If INTERFACE_UNKNOWN    is zero and INTERFACE_ONLY is zero, it means that we are responsible    for exporting definitions that others might need.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interface_only
decl_stmt|,
name|interface_unknown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we should attempt to elide constructors when possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_elide_constructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means recognize and handle exception handling constructs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_handle_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means recognize and handle ansi-style exception handling constructs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ansi_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that member functions defined in class scope are    inline by default.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_default_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means emit cadillac protocol.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cadillac
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* C++ language-specific tree codes.  */
end_comment

begin_define
define|#
directive|define
name|DEFTREECODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|LENGTH
parameter_list|)
value|SYM,
end_define

begin_enum
enum|enum
name|cplus_tree_code
block|{
name|__DUMMY
init|=
name|LAST_AND_UNUSED_TREE_CODE
block|,
include|#
directive|include
file|"cp-tree.def"
name|LAST_CPLUS_TREE_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_enum
enum|enum
name|languages
block|{
name|lang_c
block|,
name|lang_cplusplus
block|}
enum|;
end_enum

begin_comment
comment|/* Macros to make error reporting functions' lives easier.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|PARANOID
end_if

begin_define
define|#
directive|define
name|TYPE_IDENTIFIER
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_NAME (TYPE_NAME (NODE)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TYPE_IDENTIFIER
parameter_list|(
name|NODE
parameter_list|)
value|(*TYPE_IDENTIFIER_PTR (NODE))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
name|__inline
endif|#
directive|endif
specifier|static
name|tree
modifier|*
name|TYPE_IDENTIFIER_PTR
parameter_list|(
name|NODE
parameter_list|)
name|tree
name|NODE
decl_stmt|;
block|{
return|return
operator|(
name|my_friendly_assert
argument_list|(
name|TREE_CODE_CLASS
argument_list|(
name|TREE_CODE
argument_list|(
name|NODE
argument_list|)
argument_list|)
operator|==
literal|'t'
argument_list|,
literal|327
argument_list|)
operator|,
operator|&
name|DECL_NAME
argument_list|(
name|TYPE_NAME
argument_list|(
name|NODE
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TYPE_NAME_STRING
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_POINTER (TYPE_IDENTIFIER (NODE)))
end_define

begin_define
define|#
directive|define
name|TYPE_NAME_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_LENGTH (TYPE_IDENTIFIER (NODE)))
end_define

begin_define
define|#
directive|define
name|TYPE_ASSEMBLER_NAME_STRING
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (TYPE_NAME  (NODE))))
end_define

begin_define
define|#
directive|define
name|TYPE_ASSEMBLER_NAME_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_LENGTH (DECL_ASSEMBLER_NAME (TYPE_NAME (NODE))))
end_define

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_2
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|(TREE_CODE (TYPE1) == TREE_CODE (TYPE2)	\&& IS_AGGR_TYPE (TYPE1)&IS_AGGR_TYPE (TYPE2))
end_define

begin_comment
comment|/* Macros which might want to be replaced by function calls.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* Virtual function addresses can be gotten from a virtual function    table entry using this macro.  */
end_comment

begin_define
define|#
directive|define
name|FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|)
define|\
value|TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY))))
end_define

begin_define
define|#
directive|define
name|SET_FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY)))) = (VALUE))
end_define

begin_define
define|#
directive|define
name|FUNCTION_ARG_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CHAIN (TYPE_ARG_TYPES (TREE_TYPE (NODE))))
end_define

begin_define
define|#
directive|define
name|PROMOTES_TO_AGGR_TYPE
parameter_list|(
name|NODE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|(((CODE) == TREE_CODE (NODE)			\&& IS_AGGR_TYPE (TREE_TYPE (NODE)))	\    || IS_AGGR_TYPE (NODE))
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|tree
name|fnaddr_from_vtable_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_fnaddr_from_vtable_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|function_arg_chain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|promotes_to_aggr_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_aggr_type_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|)
value|(fnaddr_from_vtable_entry (ENTRY))
end_define

begin_define
define|#
directive|define
name|SET_FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(set_fnaddr_from_vtable_entry (ENTRY, VALUE))
end_define

begin_comment
comment|/* #define TYPE_NAME_STRING(NODE) (type_name_string (NODE)) */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|(function_arg_chain (NODE))
end_define

begin_define
define|#
directive|define
name|PROMOTES_TO_AGGR_TYPE
parameter_list|(
name|NODE
parameter_list|,
name|CODE
parameter_list|)
value|(promotes_to_aggr_type (NODE, CODE))
end_define

begin_comment
comment|/* #define IS_AGGR_TYPE_2(TYPE1, TYPE2) (is_aggr_type_2 (TYPE1, TYPE2)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero iff TYPE is uniquely derived from PARENT.  Under MI, PARENT can be an    ambiguous base class of TYPE, and this macro will be false.  */
end_comment

begin_define
define|#
directive|define
name|UNIQUELY_DERIVED_FROM_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
value|(get_base_distance (PARENT, TYPE, 0, 0)>= 0)
end_define

begin_escape
end_escape

begin_enum
enum|enum
name|conversion_type
block|{
name|ptr_conv
block|,
name|constptr_conv
block|,
name|int_conv
block|,
name|real_conv
block|,
name|last_conversion_type
block|}
enum|;
end_enum

begin_comment
comment|/* Statistics show that while the GNU C++ compiler may generate    thousands of different types during a compilation run, it    generates relatively few (tens) of classtypes.  Because of this,    it is not costly to store a generous amount of information    in classtype nodes.  This struct must fill out to a multiple of 4 bytes.  */
end_comment

begin_struct
struct|struct
name|lang_type
block|{
struct|struct
block|{
name|unsigned
name|has_type_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_int_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_float_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_init_aggr
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_assignment
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_assignment
range|:
literal|1
decl_stmt|;
name|unsigned
name|needs_constructor
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_default_ctor
range|:
literal|1
decl_stmt|;
name|unsigned
name|uses_multiple_inheritance
range|:
literal|1
decl_stmt|;
name|unsigned
name|const_needs_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|ref_needs_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_const_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_const_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_const_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|vtable_needs_writing
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_new
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_delete
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_call_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_array_ref_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_arrow_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|local_typedecls
range|:
literal|1
decl_stmt|;
name|unsigned
name|interface_only
range|:
literal|1
decl_stmt|;
name|unsigned
name|interface_unknown
range|:
literal|1
decl_stmt|;
name|unsigned
name|needs_virtual_reinit
range|:
literal|1
decl_stmt|;
name|unsigned
name|declared_exception
range|:
literal|1
decl_stmt|;
name|unsigned
name|declared_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|being_defined
range|:
literal|1
decl_stmt|;
name|unsigned
name|redefined
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked2
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked3
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked4
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked5
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked6
range|:
literal|1
decl_stmt|;
name|unsigned
name|use_template
range|:
literal|2
decl_stmt|;
name|unsigned
name|debug_requested
range|:
literal|1
decl_stmt|;
name|unsigned
name|dynamic
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_method_call_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|private_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|alters_visibilities
range|:
literal|1
decl_stmt|;
name|unsigned
name|got_semicolon
range|:
literal|1
decl_stmt|;
name|unsigned
name|dummy
range|:
literal|1
decl_stmt|;
comment|/* The MIPS compiler gets it wrong if this struct also 	 does not fill out to a multiple of 4 bytes.  */
name|unsigned
name|n_vancestors
range|:
literal|16
decl_stmt|;
block|}
name|type_flags
struct|;
name|int
name|cid
decl_stmt|;
name|int
name|n_ancestors
decl_stmt|;
name|int
name|vsize
decl_stmt|;
name|int
name|max_depth
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbinfo
index|[
literal|2
index|]
decl_stmt|;
name|union
name|tree_node
modifier|*
name|baselink_vec
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vfields
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbases
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbase_size
decl_stmt|;
name|union
name|tree_node
modifier|*
name|tags
decl_stmt|;
name|char
modifier|*
name|memoized_table_entry
decl_stmt|;
name|char
modifier|*
name|search_slot
decl_stmt|;
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|unsigned
name|int
name|mode
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|char
name|size_unit
decl_stmt|;
name|unsigned
name|char
name|align
decl_stmt|;
name|unsigned
name|char
name|sep_unit
decl_stmt|;
name|union
name|tree_node
modifier|*
name|sep
decl_stmt|;
name|union
name|tree_node
modifier|*
name|size
decl_stmt|;
name|union
name|tree_node
modifier|*
name|base_init_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|abstract_virtuals
decl_stmt|;
name|union
name|tree_node
modifier|*
name|as_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|id_as_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|binfo_as_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vtbl_ptr
decl_stmt|;
name|union
name|tree_node
modifier|*
name|instance_variable
decl_stmt|;
name|union
name|tree_node
modifier|*
name|friend_classes
decl_stmt|;
name|char
modifier|*
name|mi_matrix
decl_stmt|;
name|union
name|tree_node
modifier|*
name|conversions
index|[
name|last_conversion_type
index|]
decl_stmt|;
name|union
name|tree_node
modifier|*
name|dossier
decl_stmt|;
ifdef|#
directive|ifdef
name|SOS
name|union
name|tree_node
modifier|*
name|typename_as_string
decl_stmt|;
name|union
name|tree_node
modifier|*
name|dynamic_filename
decl_stmt|;
name|union
name|tree_node
modifier|*
name|dynamic_table
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Indicates whether a template should be (or has been) expanded for this    class definition.  0=do, 1=did, 2=don't, 3=didn't.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_USE_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.use_template)
end_define

begin_comment
comment|/* Fields used for storing information before the class is defined.    After the class is defined, these fields hold other information.  */
end_comment

begin_comment
comment|/* List of friends which were defined inline in this class definition.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INLINE_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_NONCOPIED_PARTS (NODE))
end_define

begin_comment
comment|/* Nonzero for _CLASSTYPE means that the _CLASSTYPE either has    a special meaning for the assignment operator ("operator="),    or one of its fields (or base members) has a special meaning    defined.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_ASSIGNMENT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_assignment)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_ASSIGNMENT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_assignment)
end_define

begin_comment
comment|/* Nonzero for _CLASSTYPE means that operator new and delete are defined,    respectively.  */
end_comment

begin_define
define|#
directive|define
name|TREE_GETS_NEW
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_new)
end_define

begin_define
define|#
directive|define
name|TREE_GETS_DELETE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_delete)
end_define

begin_comment
comment|/* Nonzero for TREE_LIST or _TYPE node means that this node is class-local.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NONLOCAL_FLAG
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_comment
comment|/* Nonzero for a _CLASSTYPE node which we know to be private.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PRIVATE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.private_attr)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node defines ways of converting    itself to other types.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_type_conversion)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node can convert itself to an    INTEGER_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_INT_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_int_conversion)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node can convert itself to an    REAL_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_REAL_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_float_conversion)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator=(X&).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_const_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_const_assign_ref)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node has an X(X&) constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_CONST_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_const_init_ref)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node has an X(X ...) constructor.    Note that there must be other arguments, or this constructor is flagged    as being erroneous.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_GETS_INIT_AGGR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_init_aggr)
end_define

begin_comment
comment|/* Nonzero means that this type is being defined.  I.e., the left brace    starting the definition of this type has been seen.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BEING_DEFINED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.being_defined)
end_define

begin_comment
comment|/* Nonzero means that this type has been redefined.  In this case, if    convenient, don't reprocess any methods that appear in its redefinition.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_REDEFINED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.redefined)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads the method call    operator.  In this case, all method calls go through `operator->()(...).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_METHOD_CALL_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_method_call_overloaded)
end_define

begin_comment
comment|/* The is the VAR_DECL that contains NODE's dossier.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DOSSIER
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->dossier)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator().  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_CALL_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_call_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator[].  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_ARRAY_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_array_ref_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator->.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_ARROW
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_arrow_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses    multiple inheritance.  If this is 0 for the root of a type    hierarchy, then we can use more efficient search techniques.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_MULTIPLE_INHERITANCE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.uses_multiple_inheritance)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses    virtual base classes.  If this is 0 for the root of a type    hierarchy, then we can use more efficient search techniques.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_VIRTUAL_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3(NODE))
end_define

begin_comment
comment|/* List of lists of member functions defined in this class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_METHOD_VEC
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_METHODS(NODE)
end_define

begin_comment
comment|/* Pointer from any member function to the head of the list of    member functions of the type that member function belongs to.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BASELINK_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->baselink_vec)
end_define

begin_comment
comment|/* Mark bits for depth-first and breath-first searches.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|PARANOID
end_if

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked2)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked3)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked4)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked5)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked6)
end_define

begin_comment
comment|/* Macros to modify the above flags */
end_comment

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED(NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED(NODE) = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED2(NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED2(NODE) = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED3(NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED3(NODE) = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED4(NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED4(NODE) = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED5(NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED5(NODE) = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED6(NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(CLASSTYPE_MARKED6(NODE) = 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 328), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 329), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked2)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 330), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked3)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 331), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked4)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 332), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked5)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 333), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked6)
end_define

begin_comment
comment|/* Macros to modify the above flags */
end_comment

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 334), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 335), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 336), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked2 = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 337), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked2 = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 338), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked3 = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 339), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked3 = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 340), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked4 = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 341), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked4 = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 342), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked5 = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 343), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked5 = 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 344), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked6 = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (NODE)) == 't', 345), TYPE_LANG_SPECIFIC(NODE)->type_flags.marked6 = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CLASSTYPE_TAGS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->tags)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_NAMES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->names)
end_define

begin_comment
comment|/* Remove when done merging.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELD
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_VFIELD(NODE)
end_define

begin_comment
comment|/* The number of virtual functions defined for this    _CLASSTYPE node.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VSIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vsize)
end_define

begin_comment
comment|/* The virtual base classes that this type uses.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vbases)
end_define

begin_comment
comment|/* The virtual function pointer fields that this type contains.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vfields)
end_define

begin_comment
comment|/* Number of baseclasses defined for this type.    0 means no base classes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_N_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_BINFO_BASETYPES (NODE) ? TREE_VEC_LENGTH (TYPE_BINFO_BASETYPES(NODE)) : 0)
end_define

begin_comment
comment|/* Memoize the number of super classes (base classes) tha this node    has.  That way we can know immediately (albeit conservatively how    large a multiple-inheritance matrix we need to build to find    derivation information.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_N_SUPERCLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->n_ancestors)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_N_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.n_vancestors)
end_define

begin_comment
comment|/* Record how deep the inheritance is for this class so `void*' conversions    are less favorable than a conversion to the most base type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MAX_DEPTH
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->max_depth)
end_define

begin_comment
comment|/* Used for keeping search-specific information.  Any search routine    which uses this must define what exactly this slot is used for.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SEARCH_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->search_slot)
end_define

begin_comment
comment|/* Entry for keeping memoization tables for this type to    hopefully speed up search routines.  Since it is a pointer,    it can mean almost anything.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MTABLE_ENTRY
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->memoized_table_entry)
end_define

begin_comment
comment|/* This is the total size of the baseclasses defined for this type.    Needed because it is desirable to layout such information    before beginning to process the class itself, and we    don't want to compute it second time when actually laying    out the type for real.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->size)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->size_unit)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MODE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->mode)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->align)
end_define

begin_comment
comment|/* This is the space needed for virtual base classes.  NULL if    there are no virtual basetypes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vbase_size)
end_define

begin_comment
comment|/* A cons list of structure elements which either have constructors    to be called, or virtual function table pointers which    need initializing.  Depending on what is being initialized,    the TREE_PURPOSE and TREE_VALUE fields have different meanings:     Member initialization:<FIELD_DECL, TYPE>    Base class construction:<NULL_TREE, BASETYPE>    Base class initialization:<BASE_INITIALIZATION, THESE_INITIALIZATIONS>    Whole type:<MEMBER_INIT, BASE_INIT>.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BASE_INIT_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->base_init_list)
end_define

begin_comment
comment|/* A cons list of virtual functions which cannot be inherited by    derived classes.  When deriving from this type, the derived    class must provide its own definition for each of these functions.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_ABSTRACT_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->abstract_virtuals)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALTERS_VISIBILITIES_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.alters_visibilities)
end_define

begin_comment
comment|/* Nonzero means that this aggr type has been `closed' by a semicolon.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_GOT_SEMICOLON
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->type_flags.got_semicolon)
end_define

begin_comment
comment|/* Nonzero means that the main virtual function table pointer needs to be    set because base constructors have placed the wrong value there.    If this is zero, it means that they placed the right value there,    and there is no need to change it.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NEEDS_VIRTUAL_REINIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.needs_virtual_reinit)
end_define

begin_comment
comment|/* Nonzero means that if this type has virtual functions, that    the virtual function table will be written out.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VTABLE_NEEDS_WRITING
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.vtable_needs_writing)
end_define

begin_comment
comment|/* Nonzero means that this type defines its own local type declarations.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_LOCAL_TYPEDECLS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.local_typedecls)
end_define

begin_comment
comment|/* Nonzero means that this type has an X() constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_DEFAULT_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_default_ctor)
end_define

begin_comment
comment|/* Many routines need to cons up a list of basetypes for visibility    checking.  This field contains a TREE_LIST node whose TREE_VALUE    is the main variant of the type, and whose TREE_VIA_PUBLIC    and TREE_VIA_VIRTUAL bits are correctly set.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_AS_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->as_list)
end_define

begin_comment
comment|/* Same, but cache a list whose value is the name of this type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_ID_AS_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->id_as_list)
end_define

begin_comment
comment|/* Same, but cache a list whose value is the binfo of this type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BINFO_AS_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->binfo_as_list)
end_define

begin_comment
comment|/* Slot in which to cache a copy of the local vtable pointer.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VTBL_PTR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vtbl_ptr)
end_define

begin_comment
comment|/* Hold the instance object associated with this method.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INST_VAR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->instance_variable)
end_define

begin_comment
comment|/* A list of class types with which this type is a friend.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_FRIEND_CLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->friend_classes)
end_define

begin_comment
comment|/* Keep an inheritance lattice around so we can quickly tell whether    a type is derived from another or not.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MI_MATRIX
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->mi_matrix)
end_define

begin_comment
comment|/* If there is exactly one conversion to a non-void, non-const pointer type,    remember that here.  If there are more than one, put    `error_mark_node' here.  If there are none, this holds NULL_TREE.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CONVERSION
parameter_list|(
name|NODE
parameter_list|,
name|KIND
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC(NODE)->conversions[(int) KIND])
end_define

begin_comment
comment|/* Nonzero means that class is "dynamic" in SOS sense.  (IRIA-specific.)  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DYNAMIC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.dynamic)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_comment
comment|/* The name of this type as a STRING.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TYPENAME_AS_STRING
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->typename_as_string)
end_define

begin_comment
comment|/* The name of the file which defines this type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DYNAMIC_FILENAME
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->dynamic_filename)
end_define

begin_comment
comment|/* The table of all member functions, linearized.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DYNAMIC_TABLE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->dynamic_table)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Say whether this node was declared as a "class" or a "struct".  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DECLARED_CLASS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.declared_class)
end_define

begin_comment
comment|/* Say whether this node was declared as a "class" or a "struct".  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DECLARED_EXCEPTION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.declared_exception)
end_define

begin_comment
comment|/* Nonzero if this class has const members which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_READONLY_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.const_needs_init)
end_define

begin_comment
comment|/* Nonzero if this class has ref members which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_REF_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.ref_needs_init)
end_define

begin_comment
comment|/* Nonzero if this class is included from a header file which employs    `#pragma interface', and it is not included in its implementation file.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_ONLY
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_only)
end_define

begin_comment
comment|/* Same as above, but for classes whose purpose we do not know.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown)
end_define

begin_comment
comment|/* Nonzero if a _DECL node requires us to output debug info for this class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DEBUG_REQUESTED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.debug_requested)
end_define

begin_escape
end_escape

begin_comment
comment|/* Additional macros for inheritance information.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBINFO
parameter_list|(
name|NODE
parameter_list|,
name|VIA_PUBLIC
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->vbinfo[VIA_PUBLIC])
end_define

begin_comment
comment|/* When following an binfo-specific chain, this is the cumulative    via-public flag.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VIA_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_5 (NODE)
end_define

begin_comment
comment|/* When building a matrix to determine by a single lookup    whether one class is derived from another or not,    this field is the index of the class in the table.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CID
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->cid)
end_define

begin_define
define|#
directive|define
name|BINFO_CID
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_CID(BINFO_TYPE(NODE))
end_define

begin_comment
comment|/* Nonzero means marked by DFS or BFS search, including searches    by `get_binfo' and `get_base_distance'.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED(BINFO_TYPE(NODE)):TREE_LANG_FLAG_0(NODE))
end_define

begin_comment
comment|/* Macros needed because of C compilers that don't allow conditional    expressions to be lvalues.  Grr!  */
end_comment

begin_define
define|#
directive|define
name|SET_BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_0(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_0(NODE)=0))
end_define

begin_comment
comment|/* Nonzero means marked in building initialization list.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_BASEINIT_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_comment
comment|/* Modifier macros */
end_comment

begin_define
define|#
directive|define
name|SET_BINFO_BASEINIT_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_BASEINIT_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_comment
comment|/* Nonzero means marked in search through virtual inheritance hierarchy.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VBASE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_comment
comment|/* Modifier macros */
end_comment

begin_define
define|#
directive|define
name|SET_BINFO_VBASE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_VBASE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_comment
comment|/* Nonzero means marked in search for members or member functions.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_FIELDS_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED2 (BINFO_TYPE (NODE)):TREE_LANG_FLAG_2(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_FIELDS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED2(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_2(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_FIELDS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED2(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_2(NODE)=0))
end_define

begin_comment
comment|/* Nonzero means that this class is on a path leading to a new vtable.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):TREE_LANG_FLAG_3(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_3(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_3(NODE)=0))
end_define

begin_comment
comment|/* Nonzero means that this class has a new vtable.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):TREE_LANG_FLAG_4(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_4(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_4(NODE)=0))
end_define

begin_comment
comment|/* Nonzero means this class has initialized its virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VBASE_INIT_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED5(BINFO_TYPE(NODE)):TREE_LANG_FLAG_5(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_VBASE_INIT_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED5(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_5(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_VBASE_INIT_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED5(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_5(NODE)=0))
end_define

begin_escape
end_escape

begin_comment
comment|/* Accessor macros for the vfield slots in structures.  */
end_comment

begin_comment
comment|/* Get the assoc info that caused this vfield to exist.  */
end_comment

begin_define
define|#
directive|define
name|VF_BINFO_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_PURPOSE (NODE)
end_define

begin_comment
comment|/* Get that same information as a _TYPE.  */
end_comment

begin_define
define|#
directive|define
name|VF_BASETYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VALUE (NODE)
end_define

begin_comment
comment|/* Get the value of the top-most type dominating the non-`normal' vfields.  */
end_comment

begin_define
define|#
directive|define
name|VF_DERIVED_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(VF_BINFO_VALUE (NODE) ? BINFO_TYPE (VF_BINFO_VALUE (NODE)) : NULL_TREE)
end_define

begin_comment
comment|/* Get the value of the top-most type that's `normal' for the vfield.  */
end_comment

begin_define
define|#
directive|define
name|VF_NORMAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (NODE)
end_define

begin_escape
end_escape

begin_comment
comment|/* Nonzero for TREE_LIST node means that this list of things    is a list of parameters, as opposed to a list of expressions.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PARMLIST
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.unsigned_flag)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* Nonzero for FIELD_DECL node means that this FIELD_DECL is    a member of an anonymous union construct.  The name of the    union is .  */
end_comment

begin_define
define|#
directive|define
name|TREE_ANON_UNION_ELEM
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.regdecl_flag)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* For FUNCTION_TYPE or METHOD_TYPE, a list of the exceptions that    this type can raise.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_RAISES_EXCEPTIONS
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_NONCOPIED_PARTS (NODE)
end_define

begin_escape
end_escape

begin_struct
struct|struct
name|lang_decl_flags
block|{
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|int
name|language
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|languages
name|language
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|operator_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|constructor_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|returns_first_arg
range|:
literal|1
decl_stmt|;
name|unsigned
name|preserves_first_arg
range|:
literal|1
decl_stmt|;
name|unsigned
name|friend_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|static_function
range|:
literal|1
decl_stmt|;
name|unsigned
name|const_memfunc
range|:
literal|1
decl_stmt|;
name|unsigned
name|volatile_memfunc
range|:
literal|1
decl_stmt|;
name|unsigned
name|abstract_virtual
range|:
literal|1
decl_stmt|;
name|unsigned
name|permanent_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|constructor_for_vbase_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|dummy
range|:
literal|13
decl_stmt|;
name|tree
name|visibility
decl_stmt|;
name|tree
name|context
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lang_decl
block|{
name|struct
name|lang_decl_flags
name|decl_flags
decl_stmt|;
name|struct
name|template_info
modifier|*
name|template_info
decl_stmt|;
name|tree
name|main_decl_variant
decl_stmt|;
name|struct
name|pending_inline
modifier|*
name|pending_inline_info
decl_stmt|;
name|tree
name|vbase_init_list
decl_stmt|;
name|tree
name|chain
decl_stmt|;
ifdef|#
directive|ifdef
name|SOS
name|tree
name|dynamic_index
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Non-zero if NODE is a _DECL with TREE_READONLY set.  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_READONLY (NODE)&& TREE_CODE_CLASS (TREE_CODE (NODE)) == 'd')
end_define

begin_comment
comment|/* For FUNCTION_DECLs: return the language in which this decl    was declared.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANGUAGE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.language)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_attr)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a constructor    for an object with virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_FOR_VBASE_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_for_vbase_attr)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that the constructor    is known to return a non-zero `this' unchanged.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RETURNS_FIRST_ARG
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.returns_first_arg)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this constructor is known to    not make any assignment to `this', and therefore can be trusted    to return it unchanged.  Otherwise, we must re-assign `current_class_decl'    after performing base initializations.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PRESERVES_THIS
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.preserves_first_arg)
end_define

begin_comment
comment|/* Nonzero for _DECL means that this decl appears in (or will appear    in) as a member in a RECORD_TYPE or UNION_TYPE node.  It is also for    detecting circularity in case members are multiply defined.  In the    case of a VAR_DECL, it is also used to determine how program storage    should be allocated.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_AGGR_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_3(NODE))
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is just a    friend declaration, and should not be added to the list of    member functions for this class.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIEND_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.friend_attr)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is a static    member function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STATIC_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.static_function)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    has `this' as const X *const.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONST_MEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.const_memfunc)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    has `this' as volatile X *const.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VOLATILE_MEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.volatile_memfunc)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    exists only as part of an abstract class's interface.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ABSTRACT_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.abstract_virtual)
end_define

begin_comment
comment|/* Nonzero if allocated on permanent_obstack.  */
end_comment

begin_define
define|#
directive|define
name|LANG_DECL_PERMANENT
parameter_list|(
name|LANGDECL
parameter_list|)
value|((LANGDECL)->decl_flags.permanent_attr)
end_define

begin_comment
comment|/* The _TYPE context in which this _DECL appears.  This field is used    only to compute visibility information.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CLASS_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.context)
end_define

begin_comment
comment|/* For a FUNCTION_DECL: the chain through which the next method    in the method chain is found.  We now use TREE_CHAIN to    link into the FIELD_DECL chain.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|DECL_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->chain)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECL_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CHAIN (NODE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Points back to the decl which caused this lang_decl to be allocated.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAIN_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->main_decl_variant)
end_define

begin_comment
comment|/* For a FUNCTION_DECL: if this function was declared inline inside of    a class declaration, this is where the text for the function is    squirreled away.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PENDING_INLINE_INFO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->pending_inline_info)
end_define

begin_comment
comment|/* Holds information about how virtual base classes should be initialized    by this constructor *if* this constructor is the one to perform    such initialization.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VBASE_INIT_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->vbase_init_list)
end_define

begin_comment
comment|/* For a TEMPLATE_DECL: template-specific information.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->template_info)
end_define

begin_comment
comment|/* Nonzero in INT_CST means that this int is negative by dint of    using a twos-complement negated operand.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NEGATED_INT
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_comment
comment|/* Nonzero in any kind of _EXPR or _REF node means that it is a call    to a storage allocation routine.  If, later, alternate storage    is found to hold the object, this call can be ignored.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CALLS_NEW
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
end_define

begin_comment
comment|/* Nonzero in any kind of _TYPE that uses multiple inheritance    or virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_COMPLEX_INHERITANCE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
end_define

begin_comment
comment|/* Nonzero in IDENTIFIER_NODE means that this name is overloaded, and    should be looked up in a non-standard way.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OVERLOADED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_define
define|#
directive|define
name|DECL_OVERLOADED
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_4 (NODE))
end_define

begin_comment
comment|/* Nonzero if this (non-TYPE)_DECL has its virtual attribute set.    For a FUNCTION_DECL, this is when the function is a virtual function.    For a VAR_DECL, this is when the variable is a virtual function table.    For a FIELD_DECL, when the field is the field for the virtual function table.    For an IDENTIFIER_NODE, nonzero if any function with this name    has been declared virtual.     For a _TYPE if it uses virtual functions (or is derived from    one that does).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2 (NODE))
end_define

begin_comment
comment|/* Same, but tells if this field is private in current context.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PRIVATE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_5 (NODE))
end_define

begin_comment
comment|/* Same, but tells if this field is private in current context.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PROTECTED
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_6(NODE))
end_define

begin_define
define|#
directive|define
name|DECL_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_7(NODE))
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
value|TREE_LANG_FLAG_4 (type)
end_define

begin_define
define|#
directive|define
name|C_DECL_VARIABLE_SIZE
parameter_list|(
name|type
parameter_list|)
value|DECL_LANG_FLAG_8 (type)
end_define

begin_comment
comment|/* Nonzero for _TYPE means that the _TYPE defines    at least one constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_1(NODE))
end_define

begin_comment
comment|/* When appearing in an INDIRECT_REF, it means that the tree structure    underneath is actually a call to a constructor.  This is needed    when the constructor must initialize local storage (which can    be automatically destroyed), rather than allowing it to allocate    space from the heap.     When appearing in a SAVE_EXPR, it means that underneath    is a call to a constructor.     When appearing in a CONSTRUCTOR, it means that it was    a GNU C constructor expression.     When appearing in a FIELD_DECL, it means that this field    has been duly initialized in its constructor.  */
end_comment

begin_define
define|#
directive|define
name|TREE_HAS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_4(NODE))
end_define

begin_comment
comment|/* Indicates that a NON_LVALUE_EXPR came from a C++ reference.    Used to generate more helpful error message in case somebody    tries to take its address.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REFERENCE_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3(NODE))
end_define

begin_comment
comment|/* Nonzero for _TYPE means that the _TYPE defines a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_2(NODE))
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that creating an object of this type    will involve a call to a constructor.  This can apply to objects    of ARRAY_TYPE if the type of the elements needs a constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_CONSTRUCTING
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_3(NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_NEEDS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.needs_constructor)
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that destroying an object of this type    will involve a call to a destructor.  This can apply to objects    of ARRAY_TYPE is the type of the elements needs a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_4(NODE))
end_define

begin_comment
comment|/* Nonzero for VAR_DECL node means that `external' was specified in    its declaration.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THIS_EXTERN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_2(NODE))
end_define

begin_comment
comment|/* Nonzero for SAVE_EXPR if used to initialize a PARM_DECL.  */
end_comment

begin_define
define|#
directive|define
name|PARM_DECL_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2(NODE))
end_define

begin_comment
comment|/* Nonzero in FUNCTION_DECL means it is really an operator.    Just used to communicate formatting information to dbxout.c.  */
end_comment

begin_define
define|#
directive|define
name|DECL_OPERATOR
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.operator_attr)
end_define

begin_comment
comment|/* Define fields and accessors for nodes representing declared names.  */
end_comment

begin_comment
comment|/* C++: A derived class may be able to directly use the virtual    function table of a base class.  When it does so, it may    still have a decl node used to access the virtual function    table (so that variables of this type can initialize their    virtual function table pointers by name).  When such thievery    is committed, know exactly which base class's virtual function    table is the one being stolen.  This effectively computes the    transitive closure.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VPARENT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.arguments)
end_define

begin_comment
comment|/* Make a slot so we can implement nested types.  This slot holds    the IDENTIFIER_NODE that uniquely names the nested type.  This    is for TYPE_DECLs only.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|PARANOID
end_if

begin_define
define|#
directive|define
name|DECL_NESTED_TYPENAME
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.arguments)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECL_NESTED_TYPENAME
parameter_list|(
name|NODE
parameter_list|)
value|(*DECL_NESTED_TYPENAME_PTR(NODE))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
name|__inline
endif|#
directive|endif
specifier|static
name|tree
modifier|*
name|DECL_NESTED_TYPENAME_PTR
parameter_list|(
name|NODE
parameter_list|)
name|tree
name|NODE
decl_stmt|;
block|{
return|return
operator|(
name|my_friendly_assert
argument_list|(
name|TREE_CODE_CLASS
argument_list|(
name|TREE_CODE
argument_list|(
name|NODE
argument_list|)
argument_list|)
operator|==
literal|'d'
argument_list|,
literal|346
argument_list|)
operator|,
operator|&
operator|(
name|NODE
operator|)
operator|->
name|decl
operator|.
name|arguments
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C++: all of these are overloaded!  These apply only to TYPE_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIENDLIST
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_INITIAL (NODE))
end_define

begin_define
define|#
directive|define
name|DECL_UNDEFINED_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.result)
end_define

begin_define
define|#
directive|define
name|DECL_WAITING_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|((tree)(NODE)->decl.rtl)
end_define

begin_define
define|#
directive|define
name|SET_DECL_WAITING_FRIENDS
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
value|((NODE)->decl.rtl=(struct rtx_def*)VALUE)
end_define

begin_comment
comment|/* The DECL_VISIBILITY is used to record under which context    special visibility rules apply.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VISIBILITY
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.visibility)
end_define

begin_comment
comment|/* C++: all of these are overloaded!    These apply to PARM_DECLs and VAR_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_REFERENCE_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|((tree)(NODE)->decl.arguments)
end_define

begin_define
define|#
directive|define
name|SET_DECL_REFERENCE_SLOT
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
value|((NODE)->decl.arguments=VAL)
end_define

begin_comment
comment|/* For local VAR_DECLs, holds index into gc-protected obstack.  */
end_comment

begin_define
define|#
directive|define
name|DECL_GC_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.result)
end_define

begin_comment
comment|/* Accessor macros for C++ template decl nodes.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_IS_CLASS
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_RESULT(NODE) == NULL_TREE)
end_define

begin_define
define|#
directive|define
name|DECL_TEMPLATE_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_ARGUMENTS(NODE)
end_define

begin_comment
comment|/* For class templates.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_MEMBERS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_INITIAL(NODE)
end_define

begin_comment
comment|/* For function, method, class-data templates.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_RESULT
parameter_list|(
name|NODE
parameter_list|)
value|DECL_RESULT(NODE)
end_define

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INSTANTIATIONS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_VINDEX(NODE)
end_define

begin_comment
comment|/* ...and for unexpanded-parameterized-type nodes.  */
end_comment

begin_define
define|#
directive|define
name|UPT_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_PURPOSE(TYPE_VALUES(NODE))
end_define

begin_define
define|#
directive|define
name|UPT_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VALUE(TYPE_VALUES(NODE))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_define
define|#
directive|define
name|DECL_DINDEX
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->dynamic_index)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* An enumeration of the kind of tags that C++ accepts.  */
end_comment

begin_enum
enum|enum
name|tag_types
block|{
name|record_type
block|,
name|class_type
block|,
name|union_type
block|,
name|enum_type
block|,
name|exception_type
block|}
enum|;
end_enum

begin_comment
comment|/* Zero means prototype weakly, as in ANSI C (no args means nothing).    Each language context defines how this variable should be set.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strict_prototype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strict_prototypes_lang_c
decl_stmt|,
name|strict_prototypes_lang_cplusplus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that if a label exists, and no other identifier    applies, use the value of the label.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_labels_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to collect statistics which might be expensive    and to print them when we are done.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_detailed_statistics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn in function declared in derived class has the    same name as a virtual in the base class, but fails to match the    type signature of any virtual function in the base class.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_overloaded_virtual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cp-decl{2}.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|void_list_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_zero_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|default_function_type
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|define_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_member_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_push_scope
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_builtin_type
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|vtable_entry_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|__t_desc_type_node
decl_stmt|,
name|__i_desc_type_node
decl_stmt|,
name|__m_desc_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|class_star_type_node
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_vtable_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vfn_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|typedecl_for_tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|identifier_class_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|constructor_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|complete_array_type
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|coerce_new_type
argument_list|()
decl_stmt|,
name|coerce_delete_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A node that is a list (length 1) of error_mark_nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_mark_list
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
name|class_type_node
decl_stmt|,
name|record_type_node
decl_stmt|,
name|union_type_node
decl_stmt|,
name|enum_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|exception_type_node
decl_stmt|,
name|unknown_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_temp_name
argument_list|()
decl_stmt|,
name|get_temp_aggr
argument_list|()
decl_stmt|,
name|get_temp_regvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|cleanup_after_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_type_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_force
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_convert_decl_to_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lang_printable_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fndecl_as_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|build_overload_name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The largest size a virtual function table can be.    Must be a (power of 2).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VINDEX_MAX
end_ifndef

begin_define
define|#
directive|define
name|VINDEX_MAX
value|((unsigned)128)
end_define

begin_comment
comment|/* This is the integer ~ (vindex_max - 1).  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|vtbl_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Array type `(void *)[]' */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|vtbl_type_node
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|get_parm_types
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|grokopexpr
argument_list|()
decl_stmt|,
name|getaggrs
argument_list|()
decl_stmt|,
name|groktypefield
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grok_method_quals
argument_list|()
decl_stmt|,
name|grok_enum_decls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|finish_anon_union
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|,
name|long_long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For building calls to `delete'.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|integer_two_node
decl_stmt|,
name|integer_three_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_first_matching_virtual
argument_list|()
decl_stmt|,
name|get_abstract_virtuals
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cp-typeck.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_x_conditional_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|merge_component_comparisons
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_x_unary_op
argument_list|()
decl_stmt|,
name|build_x_binary_op
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_component_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_function_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|require_complete_type
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_x_indirect_ref
argument_list|()
decl_stmt|,
name|build_x_array_ref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_modify_expr
argument_list|()
decl_stmt|,
name|build_x_modify_op_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_m_component_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_component_type_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_arrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_component_ref_1
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|datatype
argument_list|()
decl_stmt|,
name|unary_complex_lvalue
argument_list|()
decl_stmt|,
name|target_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_return_stmt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|convert_arguments
argument_list|()
decl_stmt|,
name|commonparms
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|cplus_size_in_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|cplus_sizeof
argument_list|()
decl_stmt|,
name|cplus_sizeof_nowarn
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|error_not_base_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-type2.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|binfo_or_else
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|my_friendly_abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error_with_aggr_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in tree.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_let
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|decl_type_context
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-tree.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_array_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_method_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_classtype_variant
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|hash_tree_cons
argument_list|()
decl_stmt|,
name|hash_tree_chain
argument_list|()
decl_stmt|,
name|hash_chainon
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|list_hash_lookup_or_cons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|layout_basetypes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|copy_to_permanent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_decl_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|break_out_cleanups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|break_out_calls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|array_type_nelts_total
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|array_type_nelts_top
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-except.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_exception_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_exception_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_exception_object
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_exception_variant
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|lookup_exception_type
argument_list|()
decl_stmt|,
name|lookup_exception_cname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|lookup_exception_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cplus_expand_start_catch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cplus_expand_end_try
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_exception_decl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-class.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_class_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_lang_name
decl_stmt|,
name|lang_name_cplusplus
decl_stmt|,
name|lang_name_c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_pointer_to
argument_list|()
decl_stmt|,
name|convert_pointer_to_vbase
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_to_reference
argument_list|()
decl_stmt|,
name|convert_to_aggr
argument_list|()
decl_stmt|,
name|convert_aggr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_new
argument_list|()
decl_stmt|,
name|build_x_delete
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_new
argument_list|()
decl_stmt|,
name|build_vec_new
argument_list|()
decl_stmt|,
name|build_delete
argument_list|()
decl_stmt|,
name|build_vec_delete
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|make_destructor_name
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_scoped_ref
argument_list|()
decl_stmt|,
name|build_vfield_ref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_method_call
argument_list|()
decl_stmt|,
name|build_overload_call
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_type_pathname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_method
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_method
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|lookup_field
argument_list|()
decl_stmt|,
name|lookup_nested_field
argument_list|()
decl_stmt|,
name|lookup_fnfields
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushclass
argument_list|()
decl_stmt|,
name|popclass
argument_list|()
decl_stmt|,
name|pushclasstype
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_operator_fnname
argument_list|()
decl_stmt|,
name|build_opfncall
argument_list|()
decl_stmt|,
name|build_type_conversion
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to the name of that function. May not be the DECL_NAME    of CURRENT_FUNCTION_DECL due to overloading */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|original_function_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IS_AGGR_TYPE
parameter_list|(
name|t
parameter_list|)
value|(TYPE_LANG_FLAG_5 (t))
end_define

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_CODE
parameter_list|(
name|t
parameter_list|)
define|\
value|(t == RECORD_TYPE || t == UNION_TYPE)
end_define

begin_decl_stmt
specifier|extern
name|tree
name|build_decl_overload
argument_list|()
decl_stmt|,
name|build_typename_overload
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_destructor_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|resolve_scope_to_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_scoped_method_call
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|,
name|current_class_type
decl_stmt|,
name|current_class_decl
decl_stmt|,
name|C_C_D
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_vtable_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cp-init.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|resolve_offset_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_base_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_member_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|global_base_init_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_base_init_list
decl_stmt|,
name|current_member_init_list
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_decl_stmt
specifier|extern
name|tree
name|get_linktable_name
argument_list|()
decl_stmt|,
name|get_dtable_name
argument_list|()
decl_stmt|,
name|get_sos_dtable
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|tree
name|get_member_function
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_member_call
argument_list|()
decl_stmt|,
name|build_offset_ref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_virtual_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|current_function_assigns_this
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_just_assigned_this
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_parms_stored
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Here's where we control how name mangling takes place.  */
end_comment

begin_define
define|#
directive|define
name|OPERATOR_ASSIGN_FORMAT
value|"__a%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_FORMAT
value|"__%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_TYPENAME_FORMAT
value|"__op"
end_define

begin_comment
comment|/* Cannot use '$' up front, because this confuses gdb    (names beginning with '$' are gdb-local identifiers).     Note that all forms in which the '$' is significant are long enough    for direct indexing (meaning that if we know there is a '$'    at a particular location, we can index into the string at    any other location that provides distinguishing characters).  */
end_comment

begin_comment
comment|/* Define NO_DOLLAR_IN_LABEL in your favorite tm file if your assembler    doesn't allow '$' in symbol names.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOLLAR_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|JOINER
value|'$'
end_define

begin_define
define|#
directive|define
name|VPTR_NAME
value|"$v"
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|"$eh_throw"
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_DECL_PREFIX
value|"_$_"
end_define

begin_define
define|#
directive|define
name|IN_CHARGE_NAME
value|"__in$chrg"
end_define

begin_define
define|#
directive|define
name|AUTO_VTABLE_NAME
value|"__vtbl$me__"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"_$tmp_"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_FORMAT
value|"_$tmp_%d"
end_define

begin_define
define|#
directive|define
name|VTBL_PTR_TYPE
value|"$vtbl_ptr_type"
end_define

begin_define
define|#
directive|define
name|VTABLE_BASE
value|"$vb"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_FORMAT
value|"_vt$%s"
end_define

begin_define
define|#
directive|define
name|VFIELD_BASE
value|"$vf"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"_vptr$"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"_vptr$%s"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME
value|"_vb$"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"_vb$%s"
end_define

begin_define
define|#
directive|define
name|STATIC_NAME_FORMAT
value|"_%s$%s"
end_define

begin_define
define|#
directive|define
name|FILE_FUNCTION_FORMAT
value|"_GLOBAL_$D$%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"$_%d"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_DOLLAR_IN_LABEL */
end_comment

begin_define
define|#
directive|define
name|JOINER
value|'.'
end_define

begin_define
define|#
directive|define
name|VPTR_NAME
value|".v"
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|".eh_throw"
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_DECL_PREFIX
value|"_._"
end_define

begin_define
define|#
directive|define
name|IN_CHARGE_NAME
value|"__in.chrg"
end_define

begin_define
define|#
directive|define
name|AUTO_VTABLE_NAME
value|"__vtbl.me__"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"_.tmp_"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_FORMAT
value|"_.tmp_%d"
end_define

begin_define
define|#
directive|define
name|VTBL_PTR_TYPE
value|".vtbl_ptr_type"
end_define

begin_define
define|#
directive|define
name|VTABLE_BASE
value|".vb"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_FORMAT
value|"_vt.%s"
end_define

begin_define
define|#
directive|define
name|VFIELD_BASE
value|".vf"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"_vptr."
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"_vptr.%s"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME
value|"_vb."
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"_vb.%s"
end_define

begin_define
define|#
directive|define
name|STATIC_NAME_FORMAT
value|"_%s.%s"
end_define

begin_define
define|#
directive|define
name|FILE_FUNCTION_FORMAT
value|"_GLOBAL_.D.%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"._%d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_DOLLAR_IN_LABEL */
end_comment

begin_define
define|#
directive|define
name|THIS_NAME
value|"this"
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_NAME_FORMAT
value|"~%s"
end_define

begin_define
define|#
directive|define
name|FILE_FUNCTION_PREFIX_LEN
value|9
end_define

begin_define
define|#
directive|define
name|VTABLE_DELTA_NAME
value|"delta"
end_define

begin_define
define|#
directive|define
name|VTABLE_DELTA2_NAME
value|"delta2"
end_define

begin_define
define|#
directive|define
name|VTABLE_INDEX_NAME
value|"index"
end_define

begin_define
define|#
directive|define
name|VTABLE_PFN_NAME
value|"pfn"
end_define

begin_define
define|#
directive|define
name|EXCEPTION_CLEANUP_NAME
value|"exception cleanup"
end_define

begin_define
define|#
directive|define
name|THIS_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(strcmp(IDENTIFIER_POINTER (ID_NODE), "this") == 0)
end_define

begin_define
define|#
directive|define
name|VPTR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == JOINER)
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[3] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[2] == 't'\&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[3] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[2] == 'b'\&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

begin_define
define|#
directive|define
name|OPERATOR_TYPENAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(IDENTIFIER_POINTER (ID_NODE)[0] == '_'	\&& IDENTIFIER_POINTER (ID_NODE)[1] == '_'	\&& IDENTIFIER_POINTER (ID_NODE)[2] == 'o'	\&& IDENTIFIER_POINTER (ID_NODE)[3] == 'p')
end_define

begin_define
define|#
directive|define
name|TEMP_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, sizeof (AUTO_TEMP_NAME)-1))
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VFIELD_NAME, sizeof(VFIELD_NAME)-1))
end_define

begin_comment
comment|/* For anonymous aggregate types, we need some sort of name to    hold on to.  In practice, this should not appear, but it should    not be harmful if it does.  */
end_comment

begin_define
define|#
directive|define
name|ANON_AGGRNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1] == '_')
end_define

begin_define
define|#
directive|define
name|ANON_PARMNAME_FORMAT
value|"_%d"
end_define

begin_define
define|#
directive|define
name|ANON_PARMNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[1]<= '9')
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the sets of attributes that member functions and baseclasses    can have.  These are sensible combinations of {public,private,protected}    cross {virtual,non-virtual}.  */
end_comment

begin_enum
enum|enum
name|visibility_type
block|{
name|visibility_default
block|,
name|visibility_public
block|,
name|visibility_private
block|,
name|visibility_protected
block|,
name|visibility_default_virtual
block|,
name|visibility_public_virtual
block|,
name|visibility_private_virtual
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|visibility_type
name|compute_visibility
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-lex.c  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_unit_name
decl_stmt|,
name|current_unit_language
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|operator_name_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Things for handling inline functions.  */
end_comment

begin_struct
struct|struct
name|pending_inline
block|{
name|struct
name|pending_inline
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next in chain */
name|int
name|lineno
decl_stmt|;
comment|/* line number we got the text from */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* name of file we were processing */
name|tree
name|fndecl
decl_stmt|;
comment|/* FUNCTION_DECL that brought us here */
name|int
name|token
decl_stmt|;
comment|/* token we were scanning */
name|int
name|token_value
decl_stmt|;
comment|/* value of token we were scanning (YYSTYPE) */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* pointer to character stream */
name|int
name|len
decl_stmt|;
comment|/* length of stream */
name|tree
name|parm_vec
decl_stmt|,
name|bindings
decl_stmt|;
comment|/* in case this is derived from a template */
name|unsigned
name|int
name|can_free
range|:
literal|1
decl_stmt|;
comment|/* free this after we're done with it? */
name|unsigned
name|int
name|deja_vu
range|:
literal|1
decl_stmt|;
comment|/* set iff we don't want to see it again.  */
name|unsigned
name|int
name|interface
range|:
literal|2
decl_stmt|;
comment|/* 0=interface 1=unknown 2=implementation */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|tree
name|combine_strings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-method.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pending_inline
modifier|*
name|pending_inlines
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|print_fndecl_with_types
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|hack_identifier
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|hack_operator
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 1 for -fall-virtual: make every member function (except    constructors) lay down in the virtual function table.    Calls can then either go through the virtual function table or not,    depending on whether we know what function will actually be called.     2 for -fSOS: make every member function (including constructors)    lay down in the virtual function table.  All calls go through the    virtual function table: this takes the place of using a linker.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_all_virtual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Positive values means that we cannot make optimizing assumptions about    `this'.  Negative values means we know `this' to be of static type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_this_is_variable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls whether enums and ints freely convert.    1 means with complete freedom.    0 means enums can convert to ints, but not vice-versa.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_int_enum_equivalence
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means layout structures so that we can do garbage collection.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate 'dossiers' that give run-time type information.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_dossier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current end of entries in the gc obstack for stack pointer variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_obstack_index
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag saying whether we have used the obstack in this function or not.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_obstack_usage
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|overload_flags
block|{
name|NO_SPECIAL
init|=
literal|0
block|,
name|DTOR_FLAG
block|,
name|OP_FLAG
block|,
name|TYPENAME_FLAG
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|tree
name|default_conversion
argument_list|()
decl_stmt|,
name|pushdecl
argument_list|()
decl_stmt|,
name|pushdecl_top_level
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|push_overloaded_decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_overloaded_decl_top_level
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|make_instance_name
argument_list|()
decl_stmt|,
name|do_decl_overload
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|maybe_build_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_instantiated_decl
argument_list|()
decl_stmt|,
name|instantiate_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|require_instantiated_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vtbl_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_anon_parm_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|resolves_to_fixed_type_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_friend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|grokclassfn
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|current_class_decl
decl_stmt|,
name|C_C_D
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PARM_DECL: the class instance variable */
end_comment

begin_comment
comment|/* The following two can be derived from the previous one */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IDENTIFIER_NODE: name of current class */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* _TYPE: the type of the current class */
end_comment

begin_comment
comment|/* Some macros for char-based bitfields.  */
end_comment

begin_define
define|#
directive|define
name|B_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3] |= (1<< (x&7)))
end_define

begin_define
define|#
directive|define
name|B_CLR
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3]&= ~(1<< (x&7)))
end_define

begin_define
define|#
directive|define
name|B_TST
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3]& (1<< (x&7)))
end_define

begin_comment
comment|/* These are uses as bits in flags passed to build_method_call    to control its error reporting behavior.     LOOKUP_PROTECT means flag visibility violations.    LOOKUP_COMPLAIN mean complain if no suitable member function      matching the arguments is found.    LOOKUP_NORMAL is just a combination of these two.    LOOKUP_AGGR requires the instance to be of aggregate type.    LOOKUP_NONVIRTUAL means make a direct call to the member function found    LOOKUP_GLOBAL means search through the space of overloaded functions,      rather than the space of member functions.    LOOKUP_HAS_IN_CHARGE means that the "in charge" variable is already      in the parameter list.    LOOKUP_PROTECTED_OK means that even if the constructor we find appears      to be non-visible to current scope, call it anyway.    LOOKUP_DYNAMIC means call dynamic functions, a la SOS.    LOOKUP_NO_CONVERSION means that user-defined conversions are not      permitted.  Built-in conversions are permitted.    LOOKUP_DESTRUCTOR means explicit call to destructor.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PROTECT
value|(1)
end_define

begin_define
define|#
directive|define
name|LOOKUP_COMPLAIN
value|(2)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NORMAL
value|(3)
end_define

begin_define
define|#
directive|define
name|LOOKUP_AGGR
value|(4)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NONVIRTUAL
value|(8)
end_define

begin_define
define|#
directive|define
name|LOOKUP_GLOBAL
value|(16)
end_define

begin_define
define|#
directive|define
name|LOOKUP_HAS_IN_CHARGE
value|(32)
end_define

begin_define
define|#
directive|define
name|LOOKUP_SPECULATIVELY
value|(64)
end_define

begin_define
define|#
directive|define
name|LOOKUP_PROTECTED_OK
value|(128)
end_define

begin_define
define|#
directive|define
name|LOOKUP_DYNAMIC
value|(256)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NO_CONVERSION
value|(512)
end_define

begin_define
define|#
directive|define
name|LOOKUP_DESTRUCTOR
value|(512)
end_define

begin_comment
comment|/* Anatomy of a DECL_FRIENDLIST (which is a TREE_LIST):    purpose = friend name (IDENTIFIER_NODE);    value = TREE_LIST of FUNCTION_DECLS;    chain, type = EMPTY;  */
end_comment

begin_define
define|#
directive|define
name|FRIEND_NAME
parameter_list|(
name|LIST
parameter_list|)
value|(TREE_PURPOSE (LIST))
end_define

begin_define
define|#
directive|define
name|FRIEND_DECLS
parameter_list|(
name|LIST
parameter_list|)
value|(TREE_VALUE (LIST))
end_define

begin_decl_stmt
specifier|extern
name|tree
name|get_temp_name
argument_list|()
decl_stmt|,
name|get_temp_aggr
argument_list|()
decl_stmt|,
name|get_temp_regvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|get_decl_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_method_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_type_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_functional_cast
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|decl_constant_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* These macros are for accessing the fields of TEMPLATE...PARM nodes.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_TPARMLIST
parameter_list|(
name|NODE
parameter_list|)
value|TREE_PURPOSE (TYPE_FIELDS (NODE))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_IDX
parameter_list|(
name|NODE
parameter_list|)
value|TREE_INT_CST_LOW (TREE_VALUE (TYPE_FIELDS (NODE)))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_SET_INFO
parameter_list|(
name|NODE
parameter_list|,
name|P
parameter_list|,
name|I
parameter_list|)
define|\
value|(TYPE_FIELDS (NODE) = build_tree_list (P, build_int_2 (I, 0)))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_CONST_TPARMLIST
parameter_list|(
name|NODE
parameter_list|)
value|(*(tree*)&TREE_INT_CST_LOW(NODE))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_CONST_IDX
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_INT_CST_HIGH(NODE))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_CONST_SET_INFO
parameter_list|(
name|NODE
parameter_list|,
name|P
parameter_list|,
name|I
parameter_list|)
define|\
value|(TEMPLATE_CONST_TPARMLIST (NODE) = saved_parmlist, \    TEMPLATE_CONST_IDX (NODE) = I)
end_define

begin_comment
comment|/* in cp-init.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|resolve_offset_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vbase_delete
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-lex.c  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|operator_name_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compiler_error_with_decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_opid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_identifier
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|arbitrate_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Indexed by TREE_CODE, these tables give C-looking names to    operators represented by TREE_CODES.  For example,    opname_tab[(int) MINUS_EXPR] == "-".  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|opname_tab
decl_stmt|,
modifier|*
modifier|*
name|assignop_tab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_lang_decl
argument_list|()
decl_stmt|,
name|build_lang_field_decl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|make_lang_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cons_up_default_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-convert.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|convert_from_reference
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-search.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|init_vbase_pointers
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_vbase_pointer
argument_list|()
decl_stmt|,
name|build_vbase_path
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_fnfield
argument_list|()
decl_stmt|,
name|next_baselink
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_vbase_vtables_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_binfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_vbase_types
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_baselinks
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|make_binfo
argument_list|()
decl_stmt|,
name|copy_binfo
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binfo_value
argument_list|()
decl_stmt|,
name|virtual_member
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|virtual_offset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|reverse_path
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-gc.c  */
end_comment

begin_function_decl
name|tree
name|protect_value_from_gc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_headof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_classof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_t_desc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_i_desc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_m_desc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-template.c  */
end_comment

begin_comment
comment|/* PARM_VEC is a vector of template parameters, either IDENTIFIER_NODEs or    PARM_DECLs.  BINDINGS, if non-null, is a vector of bindings for those    parameters.  */
end_comment

begin_struct
struct|struct
name|template_info
block|{
comment|/* Vector of template parameters, either PARM_DECLs or IDENTIFIER_NODEs.  */
name|tree
name|parm_vec
decl_stmt|;
comment|/* If non-null, a vector of bindings for the template parms.  */
name|tree
name|bindings
decl_stmt|;
comment|/* Text of template, and length.  */
name|char
modifier|*
name|text
decl_stmt|;
name|int
name|length
decl_stmt|;
comment|/* Where it came from.  */
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|lineno
decl_stmt|;
comment|/* What kind of aggregate -- struct, class, or null.  */
name|tree
name|aggr
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|tree
name|end_template_parm_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|process_template_parm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_template_class
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_template
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_class_template
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|processing_template_decl
decl_stmt|,
name|processing_template_defn
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PRINT_LANG_DECL
end_define

begin_define
define|#
directive|define
name|PRINT_LANG_TYPE
end_define

begin_define
define|#
directive|define
name|UNKNOWN_TYPE
value|LANG_TYPE
end_define

begin_comment
comment|/* in cp-xref.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|GNU_xref_start_scope
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|GNU_xref_end_scope
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* -- end of C++ */
end_comment

end_unit

