begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C parsing and type checking.    Copyright (C) 1987, 1993, 1994, 1995, 1997, 1998,    1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_TREE_H
end_define

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_comment
comment|/* Language-dependent contents of an identifier.  */
end_comment

begin_comment
comment|/* The limbo_value is used for block level extern declarations, which need    to be type checked against subsequent extern declarations.  They can't    be referenced after they fall out of scope, so they can't be global.     The rid_code field is used for keywords.  It is in all    lang_identifier nodes, because some keywords are only special in a    particular context.  */
end_comment

begin_decl_stmt
name|struct
name|lang_identifier
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|c_common_identifier
name|common_id
decl_stmt|;
name|tree
name|symbol_value
decl_stmt|;
name|tree
name|tag_value
decl_stmt|;
name|tree
name|label_value
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The resulting tree type.  */
end_comment

begin_decl_stmt
name|union
name|lang_tree_node
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"TREE_CODE (&%h.generic) == IDENTIFIER_NODE"
argument_list|)
operator|,
name|chain_next
argument_list|(
literal|"TREE_CODE (&%h.generic) == INTEGER_TYPE ? (union lang_tree_node *)TYPE_NEXT_VARIANT (&%h.generic) : (union lang_tree_node *)TREE_CHAIN (&%h.generic)"
argument_list|)
operator|)
argument_list|)
block|{
name|union
name|tree_node
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|,
name|desc
argument_list|(
literal|"tree_node_structure (&%h)"
argument_list|)
operator|)
argument_list|)
name|generic
decl_stmt|;
name|struct
name|lang_identifier
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|identifier
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Language-specific declaration information.  */
end_comment

begin_decl_stmt
name|struct
name|lang_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The return types and parameter types may have variable size.      This is a list of any SAVE_EXPRs that need to be evaluated to      compute those sizes.  */
name|tree
name|pending_sizes
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Macros for access to language-specific slots in an identifier.  */
end_comment

begin_comment
comment|/* Each of these slots contains a DECL node or null.  */
end_comment

begin_comment
comment|/* The value of the identifier in the namespace of "ordinary identifiers"    (data objects, enum constants, functions, typedefs).  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_SYMBOL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->symbol_value)
end_define

begin_comment
comment|/* The value of the identifier in the namespace of struct, union,    and enum tags.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_TAG_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *) (NODE))->tag_value)
end_define

begin_comment
comment|/* The value of the identifier in the namespace of labels.  */
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
comment|/* In identifiers, C uses the following fields in a special way:    TREE_PUBLIC        to record that there was a previous local extern decl.    TREE_USED          to record that such a decl was used.    TREE_ADDRESSABLE   to record that the address of such a decl was used.  */
end_comment

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_READONLY
parameter_list|(
name|TYPE
parameter_list|)
value|TREE_LANG_FLAG_1 (TYPE)
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is volatile.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_VOLATILE
parameter_list|(
name|TYPE
parameter_list|)
value|TREE_LANG_FLAG_2 (TYPE)
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE or ENUMERAL_TYPE    nonzero if the definition of the type has already started.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_BEING_DEFINED
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_LANG_FLAG_0 (TYPE)
end_define

begin_comment
comment|/* In an incomplete RECORD_TYPE or UNION_TYPE, a list of variable    declarations whose type would be completed by completing that type.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_INCOMPLETE_VARS
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_VFIELD (TYPE)
end_define

begin_comment
comment|/* In an IDENTIFIER_NODE, nonzero if this identifier is actually a    keyword.  C_RID_CODE (node) is then the RID_* value of the keyword,    and C_RID_YYCODE is the token number wanted by Yacc.  */
end_comment

begin_define
define|#
directive|define
name|C_IS_RESERVED_WORD
parameter_list|(
name|ID
parameter_list|)
value|TREE_LANG_FLAG_0 (ID)
end_define

begin_comment
comment|/* In a RECORD_TYPE, a sorted array of the fields of the type.  */
end_comment

begin_decl_stmt
name|struct
name|lang_type
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|sorted_fields_type
modifier|*
name|GTY
argument_list|(
operator|(
name|reorder
argument_list|(
literal|"resort_sorted_fields"
argument_list|)
operator|)
argument_list|)
name|s
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Record whether a type or decl was written with nonconstant size.    Note that TYPE_SIZE may have simplified to a constant.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_VARIABLE_SIZE
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_LANG_FLAG_1 (TYPE)
end_define

begin_define
define|#
directive|define
name|C_DECL_VARIABLE_SIZE
parameter_list|(
name|TYPE
parameter_list|)
value|DECL_LANG_FLAG_0 (TYPE)
end_define

begin_comment
comment|/* Store a value in that field.  */
end_comment

begin_define
define|#
directive|define
name|C_SET_EXP_ORIGINAL_CODE
parameter_list|(
name|EXP
parameter_list|,
name|CODE
parameter_list|)
define|\
value|(TREE_COMPLEXITY (EXP) = (int) (CODE))
end_define

begin_comment
comment|/* Record whether a typedef for type `int' was actually `signed int'.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPEDEF_EXPLICITLY_SIGNED
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_1 (EXP)
end_define

begin_comment
comment|/* For a FUNCTION_DECL, nonzero if it was defined without an explicit    return type.  */
end_comment

begin_define
define|#
directive|define
name|C_FUNCTION_IMPLICIT_INT
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_1 (EXP)
end_define

begin_comment
comment|/* For a FUNCTION_DECL, nonzero if it was an implicit declaration.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_IMPLICIT
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_2 (EXP)
end_define

begin_comment
comment|/* Nonzero for a declaration of an external object which is not    currently in scope.  This is either a built-in declaration of    a library function, before a real declaration has been seen,    or a declaration that appeared in an inner scope that has ended.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_INVISIBLE
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_3 (EXP)
end_define

begin_comment
comment|/* Nonzero for a decl which either doesn't exist or isn't a prototype.    N.B. Could be simplified if all built-in decls had complete prototypes    (but this is presently difficult because some of them need FILE*).  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_ISNT_PROTOTYPE
parameter_list|(
name|EXP
parameter_list|)
define|\
value|(EXP == 0					\ 	|| (TYPE_ARG_TYPES (TREE_TYPE (EXP)) == 0	\&& !DECL_BUILT_IN (EXP)))
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
value|TYPE_BINFO (NODE)
end_define

begin_comment
comment|/* Values for the first parameter to poplevel.  */
end_comment

begin_define
define|#
directive|define
name|KEEP_NO
value|0
end_define

begin_define
define|#
directive|define
name|KEEP_YES
value|1
end_define

begin_define
define|#
directive|define
name|KEEP_MAYBE
value|2
end_define

begin_comment
comment|/* Save and restore the variables in this file and elsewhere    that keep track of the progress of compilation of the current function.    Used for nested functions.  */
end_comment

begin_decl_stmt
name|struct
name|language_function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|c_language_function
name|base
decl_stmt|;
name|int
name|returns_value
decl_stmt|;
name|int
name|returns_null
decl_stmt|;
name|int
name|returns_abnormally
decl_stmt|;
name|int
name|warn_about_return_type
decl_stmt|;
name|int
name|extern_inline
decl_stmt|;
name|int
name|x_in_iteration_stmt
decl_stmt|;
name|int
name|x_in_case_stmt
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* in c-parse.in */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_parse_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in c-aux-info.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|gen_aux_info_record
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in c-decl.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|c_in_iteration_stmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_in_case_stmt
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|global_bindings_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|getdecls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushlevel
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_expand_body
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_init_decl_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_dup_lang_specific_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_print_identifier
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_array_declarator
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_enumerator
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_for_loop_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_forward_parm_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|complete_array_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|declare_parm_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|undeclared_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|declare_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|define_label
parameter_list|(
name|location_t
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_enum
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_struct
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_parm_info
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|grokfield
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|groktypename
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|groktypename_in_parm_context
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|implicitly_declare
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_parm_level_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|keep_next_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pending_xref_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_push_function_context
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_pop_function_context
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_parm_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl_top_level
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushtag
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|set_array_declarator_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|shadow_tag
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|shadow_tag_warned
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_enum
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|start_function
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_struct
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_parm_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|xref_tag
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_begin_compound_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_expand_deferred_function
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_expand_decl_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_static_assembler_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_pointer_declarator
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|merge_translation_unit_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in c-objc-common.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|c_disregard_inline_limits
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_cannot_inline_tree_fn
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_objc_common_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_missing_noreturn_ok_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_objc_common_finish_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|defer_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_warn_unused_global_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

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
value|c_build_qualified_type ((TYPE),				  \ 			  ((CONST_P) ? TYPE_QUAL_CONST : 0) |	  \ 			  ((VOLATILE_P) ? TYPE_QUAL_VOLATILE : 0))
end_define

begin_define
define|#
directive|define
name|c_sizeof_nowarn
parameter_list|(
name|T
parameter_list|)
value|c_sizeof_or_alignof_type (T, SIZEOF_EXPR, 0)
end_define

begin_comment
comment|/* in c-typeck.c */
end_comment

begin_comment
comment|/* For use with comptypes.  */
end_comment

begin_enum
enum|enum
block|{
name|COMPARE_STRICT
init|=
literal|0
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|tree
name|require_complete_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comptypes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_size_in_bytes
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_mark_addressable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_incomplete_type_error
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_type_promotes_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_component_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_indirect_ref
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_array_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_external_ref
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|parser_build_binary_op
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_tree_expr_nonnegative_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|readonly_error
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_conditional_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_compound_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_cast_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_c_cast
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_modify_expr
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_init_value
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pedwarn_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|really_start_incremental_init
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_init_level
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pop_init_level
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_init_index
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_init_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_init_element
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_compound_literal
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|pedwarn_c90
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pedwarn_c99
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|c_start_case
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_finish_case
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|simple_asm_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_asm_stmt
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_convert_parm_for_inlining
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a call to a noreturn function is seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_abnormally
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
comment|/* In c-decl.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_finish_incomplete_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|get_current_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_mark_locals_volatile
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_write_global_declarations
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|static_ctors
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|static_dtors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In order for the format checking to accept the C frontend    diagnostic framework extensions, you must include this file before    toplev.h, not after.  */
end_comment

begin_define
define|#
directive|define
name|GCC_DIAG_STYLE
value|__gcc_cdiag__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_C_TREE_H */
end_comment

end_unit

