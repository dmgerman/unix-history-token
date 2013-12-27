begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language hooks common to C and ObjC front ends.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.    Contributed by Ziemowit Laski<zlaski@apple.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_OBJC_COMMON
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_OBJC_COMMON
end_define

begin_comment
comment|/* In c-objc-common.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_initialize_diagnostics
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lang hooks that are shared between C and ObjC are defined here.  Hooks    specific to C or ObjC go in c-lang.c and objc/objc-lang.c, respectively.  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_IDENTIFIER_SIZE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_IDENTIFIER_SIZE
value|C_SIZEOF_STRUCT_LANG_IDENTIFIER
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FINISH
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FINISH
value|c_common_finish
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_INIT_OPTIONS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INIT_OPTIONS
value|c_common_init_options
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_INITIALIZE_DIAGNOSTICS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INITIALIZE_DIAGNOSTICS
value|c_initialize_diagnostics
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_HANDLE_OPTION
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_HANDLE_OPTION
value|c_common_handle_option
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_MISSING_ARGUMENT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_MISSING_ARGUMENT
value|c_common_missing_argument
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_POST_OPTIONS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_POST_OPTIONS
value|c_common_post_options
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_GET_ALIAS_SET
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_GET_ALIAS_SET
value|c_common_get_alias_set
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_EXPAND_EXPR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPAND_EXPR
value|c_expand_expr
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_EXPAND_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPAND_DECL
value|c_expand_decl
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_MARK_ADDRESSABLE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_MARK_ADDRESSABLE
value|c_mark_addressable
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PARSE_FILE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PARSE_FILE
value|c_common_parse_file
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FINISH_INCOMPLETE_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FINISH_INCOMPLETE_DECL
value|c_finish_incomplete_decl
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_REDUCE_BIT_FIELD_OPERATIONS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_REDUCE_BIT_FIELD_OPERATIONS
value|true
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_STATICP
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_STATICP
value|c_staticp
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_NO_BODY_BLOCKS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_NO_BODY_BLOCKS
value|true
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_WARN_UNUSED_GLOBAL_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_WARN_UNUSED_GLOBAL_DECL
value|c_warn_unused_global_decl
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PRINT_IDENTIFIER
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_IDENTIFIER
value|c_print_identifier
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TYPES_COMPATIBLE_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TYPES_COMPATIBLE_P
value|c_types_compatible_p
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FUNCTION_ENTER_NESTED
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_ENTER_NESTED
value|c_push_function_context
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FUNCTION_LEAVE_NESTED
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_LEAVE_NESTED
value|c_pop_function_context
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FUNCTION_MISSING_NORETURN_OK_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_MISSING_NORETURN_OK_P
value|c_missing_noreturn_ok_p
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_DUP_LANG_SPECIFIC_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DUP_LANG_SPECIFIC_DECL
value|c_dup_lang_specific_decl
end_define

begin_comment
comment|/* Attribute hooks.  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_COMMON_ATTRIBUTE_TABLE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_COMMON_ATTRIBUTE_TABLE
value|c_common_attribute_table
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FORMAT_ATTRIBUTE_TABLE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FORMAT_ATTRIBUTE_TABLE
value|c_common_format_attribute_table
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN
define|\
value|c_cannot_inline_tree_fn
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS
define|\
value|c_disregard_inline_limits
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P
define|\
value|anon_aggr_type_p
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_CONVERT_PARM_FOR_INLINING
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_CONVERT_PARM_FOR_INLINING
define|\
value|c_convert_parm_for_inlining
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_DUMP_DUMP_TREE_FN
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_DUMP_DUMP_TREE_FN
value|c_dump_tree
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_CALLGRAPH_EXPAND_FUNCTION
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_CALLGRAPH_EXPAND_FUNCTION
value|c_expand_body
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TYPE_FOR_MODE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TYPE_FOR_MODE
value|c_common_type_for_mode
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TYPE_FOR_SIZE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TYPE_FOR_SIZE
value|c_common_type_for_size
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_SIGNED_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SIGNED_TYPE
value|c_common_signed_type
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_UNSIGNED_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_UNSIGNED_TYPE
value|c_common_unsigned_type
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_SIGNED_OR_UNSIGNED_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SIGNED_OR_UNSIGNED_TYPE
value|c_common_signed_or_unsigned_type
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_INCOMPLETE_TYPE_ERROR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INCOMPLETE_TYPE_ERROR
value|c_incomplete_type_error
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TYPE_PROMOTES_TO
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TYPE_PROMOTES_TO
value|c_type_promotes_to
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_REGISTER_BUILTIN_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_REGISTER_BUILTIN_TYPE
value|c_register_builtin_type
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TO_TARGET_CHARSET
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TO_TARGET_CHARSET
value|c_common_to_target_charset
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_EXPR_TO_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPR_TO_DECL
value|c_expr_to_decl
end_define

begin_comment
comment|/* The C front end's scoping structure is very different from    that expected by the language-independent code; it is best    to disable getdecls.    This means it must also provide its own write_globals.  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_GETDECLS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_GETDECLS
value|lhd_return_null_tree_v
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_WRITE_GLOBALS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_WRITE_GLOBALS
value|c_write_global_declarations
end_define

begin_comment
comment|/* Hooks for tree gimplification.  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_GIMPLIFY_EXPR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_GIMPLIFY_EXPR
value|c_gimplify_expr
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_OMP_PREDETERMINED_SHARING
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_OMP_PREDETERMINED_SHARING
value|c_omp_predetermined_sharing
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_VAR_MOD_TYPE_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_VAR_MOD_TYPE_P
value|c_vla_unspec_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_C_OBJC_COMMON */
end_comment

end_unit

