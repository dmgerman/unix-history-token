begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language hooks common to C++ and ObjC++ front ends.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.    Contributed by Ziemowit Laski<zlaski@apple.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CP_OBJCP_COMMON
end_ifndef

begin_define
define|#
directive|define
name|GCC_CP_OBJCP_COMMON
end_define

begin_comment
comment|/* In cp/cp-lang.c and objcp/objcp-lang.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|objcp_tsubst_copy_and_build
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tsubst_flags_t
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lang hooks that are shared between C++ and ObjC++ are defined here.  Hooks    specific to C++ or ObjC++ go in cp/cp-lang.c and objcp/objcp-lang.c,    respectively.  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_SIZE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_SIZE
value|cp_tree_size
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
value|cxx_finish
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_CLEAR_BINDING_STACK
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_CLEAR_BINDING_STACK
value|pop_everything
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
value|cxx_initialize_diagnostics
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
name|LANG_HOOKS_HANDLE_FILENAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_HANDLE_FILENAME
value|c_common_handle_filename
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
value|cxx_get_alias_set
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_EXPAND_CONSTANT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPAND_CONSTANT
value|cplus_expand_constant
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
value|cxx_expand_expr
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
name|LANG_HOOKS_STATICP
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_STATICP
value|cxx_staticp
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
value|cxx_dup_lang_specific_decl
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_SET_DECL_ASSEMBLER_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SET_DECL_ASSEMBLER_NAME
value|mangle_decl
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
value|cxx_mark_addressable
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PRINT_STATISTICS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_STATISTICS
value|cxx_print_statistics
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PRINT_XNODE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_XNODE
value|cxx_print_xnode
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PRINT_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_DECL
value|cxx_print_decl
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PRINT_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_TYPE
value|cxx_print_type
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
value|cxx_print_identifier
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
value|cxx_types_compatible_p
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_PRINT_ERROR_FUNCTION
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_ERROR_FUNCTION
value|cxx_print_error_function
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
value|cxx_warn_unused_global_decl
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
value|lhd_do_nothing
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_COMDAT_GROUP
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_COMDAT_GROUP
value|cxx_comdat_group
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FUNCTION_INIT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_INIT
value|cxx_push_function_context
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_FUNCTION_FINAL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_FINAL
value|cxx_pop_function_context
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
value|cp_missing_noreturn_ok_p
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
name|LANG_HOOKS_ATTRIBUTE_TABLE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_ATTRIBUTE_TABLE
value|cxx_attribute_table
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_WALK_SUBTREES
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_WALK_SUBTREES
define|\
value|cp_walk_subtrees
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
value|cp_cannot_inline_tree_fn
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS
define|\
value|cp_add_pending_fn_decls
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P
define|\
value|cp_auto_var_in_fn_p
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
value|anon_aggr_type_p
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
value|cp_var_mod_type_p
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
value|cp_dump_tree
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_DUMP_TYPE_QUALS_FN
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_DUMP_TYPE_QUALS_FN
value|cp_type_quals
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_EXPR_SIZE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPR_SIZE
value|cp_expr_size
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_CALLGRAPH_ANALYZE_EXPR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_CALLGRAPH_ANALYZE_EXPR
value|cxx_callgraph_analyze_expr
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
value|expand_body
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_MAKE_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_MAKE_TYPE
value|cxx_make_type
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
value|cxx_incomplete_type_error
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
value|cxx_type_promotes_to
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
name|LANG_HOOKS_GIMPLIFY_EXPR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_GIMPLIFY_EXPR
value|cp_gimplify_expr
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
value|cxx_omp_predetermined_sharing
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_OMP_CLAUSE_DEFAULT_CTOR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_OMP_CLAUSE_DEFAULT_CTOR
value|cxx_omp_clause_default_ctor
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_OMP_CLAUSE_COPY_CTOR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_OMP_CLAUSE_COPY_CTOR
value|cxx_omp_clause_copy_ctor
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_OMP_CLAUSE_ASSIGN_OP
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_OMP_CLAUSE_ASSIGN_OP
value|cxx_omp_clause_assign_op
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_OMP_CLAUSE_DTOR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_OMP_CLAUSE_DTOR
value|cxx_omp_clause_dtor
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_OMP_PRIVATIZE_BY_REFERENCE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_OMP_PRIVATIZE_BY_REFERENCE
value|cxx_omp_privatize_by_reference
end_define

begin_comment
comment|/* APPLE LOCAL begin radar 6353006  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_BUILD_GENERIC_BLOCK_STRUCT_TYPE
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_BUILD_GENERIC_BLOCK_STRUCT_TYPE
define|\
value|c_build_generic_block_struct_type
end_define

begin_comment
comment|/* APPLE LOCAL end radar 6353006  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_CP_OBJCP_COMMON */
end_comment

end_unit

