begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default macros to initialize the lang_hooks data structure.    Copyright 2001, 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_LANG_HOOKS_DEF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_LANG_HOOKS_DEF_H
end_define

begin_include
include|#
directive|include
file|"hooks.h"
end_include

begin_struct_decl
struct_decl|struct
name|diagnostic_context
struct_decl|;
end_struct_decl

begin_comment
comment|/* Provide a hook routine for alias sets that always returns 1.  This is    used by languages that haven't deal with alias sets yet.  */
end_comment

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|hook_get_alias_set_0
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Note to creators of new hooks:     The macros in this file should NOT be surrounded by a    #ifdef...#endif pair, since this file declares the defaults.  Each    front end overrides any hooks it wishes to, in the file containing    its struct lang_hooks, AFTER including this file.  */
end_comment

begin_comment
comment|/* See langhooks.h for the definition and documentation of each hook.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|lhd_do_nothing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_do_nothing_t
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_do_nothing_i
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_do_nothing_f
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|lhd_post_options
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|lhd_get_alias_set
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_return_tree
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_return_null_tree_v
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_return_null_tree
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_do_nothing_iii_return_null_tree
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_safe_from_p
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_staticp
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_unsafe_for_reeval
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_clear_binding_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_print_tree_nothing
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
specifier|const
name|char
modifier|*
name|lhd_decl_printable_name
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|lhd_expand_expr
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_print_error_function
parameter_list|(
name|struct
name|diagnostic_context
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_set_decl_assembler_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|lhd_can_use_bit_fields_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|lhd_warn_unused_global_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_incomplete_type_error
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
name|lhd_type_promotes_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_register_builtin_type
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
name|bool
name|lhd_decl_ok_for_sibcall
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_expr_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|lhd_decl_uninit
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_get_callee_fndecl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|lhd_tree_size
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Declarations of default tree inlining hooks.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|lhd_tree_inlining_walk_subtrees
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|walk_tree_fn
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_inlining_cannot_inline_tree_fn
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_inlining_disregard_inline_limits
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_tree_inlining_add_pending_fn_decls
parameter_list|(
name|void
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_inlining_tree_chain_matters_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_inlining_auto_var_in_fn_p
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
name|lhd_tree_inlining_copy_res_decl_for_inlining
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_inlining_anon_aggr_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_inlining_start_inlining
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lhd_tree_inlining_end_inlining
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_tree_inlining_convert_parm_for_inlining
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

begin_function_decl
specifier|extern
name|void
name|lhd_initialize_diagnostics
parameter_list|(
name|struct
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lhd_callgraph_analyze_expr
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LANG_HOOKS_NAME
value|"GNU unknown"
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_IDENTIFIER_SIZE
value|sizeof (struct lang_identifier)
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_INIT
value|hook_bool_void_false
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FINISH
value|lhd_do_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PARSE_FILE
value|lhd_do_nothing_i
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_CLEAR_BINDING_STACK
value|lhd_clear_binding_stack
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_INIT_OPTIONS
value|hook_uint_uint_constcharptrptr_0
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_INITIALIZE_DIAGNOSTICS
value|lhd_initialize_diagnostics
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_HANDLE_OPTION
value|hook_int_size_t_constcharptr_int_0
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_MISSING_ARGUMENT
value|hook_bool_constcharptr_size_t_false
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_POST_OPTIONS
value|lhd_post_options
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_GET_ALIAS_SET
value|lhd_get_alias_set
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPAND_CONSTANT
value|lhd_return_tree
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPAND_EXPR
value|lhd_expand_expr
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_SAFE_FROM_P
value|lhd_safe_from_p
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FINISH_INCOMPLETE_DECL
value|lhd_do_nothing_t
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_UNSAFE_FOR_REEVAL
value|lhd_unsafe_for_reeval
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_STATICP
value|lhd_staticp
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DUP_LANG_SPECIFIC_DECL
value|lhd_do_nothing_t
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_UNSAVE_EXPR_NOW
value|lhd_unsave_expr_now
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_MAYBE_BUILD_CLEANUP
value|lhd_return_null_tree
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_SET_DECL_ASSEMBLER_NAME
value|lhd_set_decl_assembler_name
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_CAN_USE_BIT_FIELDS_P
value|lhd_can_use_bit_fields_p
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_HONOR_READONLY
value|false
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_NO_BODY_BLOCKS
value|false
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_STATISTICS
value|lhd_do_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_XNODE
value|lhd_print_tree_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_DECL
value|lhd_print_tree_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_TYPE
value|lhd_print_tree_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_IDENTIFIER
value|lhd_print_tree_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PRINT_ERROR_FUNCTION
value|lhd_print_error_function
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_PRINTABLE_NAME
value|lhd_decl_printable_name
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_GET_CALLEE_FNDECL
value|lhd_return_null_tree
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_EXPR_SIZE
value|lhd_expr_size
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_UNINIT
value|lhd_decl_uninit
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_SIZE
value|lhd_tree_size
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_INIT
value|lhd_do_nothing_f
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_FINAL
value|lhd_do_nothing_f
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_ENTER_NESTED
value|lhd_do_nothing_f
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_LEAVE_NESTED
value|lhd_do_nothing_f
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_RTL_EXPAND_START
value|lhd_do_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_RTL_EXPAND_STMT
value|(void (*) (tree)) abort
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_RTL_EXPAND_END
value|lhd_do_nothing
end_define

begin_comment
comment|/* Attribute hooks.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_ATTRIBUTE_TABLE
value|NULL
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_COMMON_ATTRIBUTE_TABLE
value|NULL
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FORMAT_ATTRIBUTE_TABLE
value|NULL
end_define

begin_comment
comment|/* Tree inlining hooks.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_WALK_SUBTREES
value|lhd_tree_inlining_walk_subtrees
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN
define|\
value|lhd_tree_inlining_cannot_inline_tree_fn
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS
define|\
value|lhd_tree_inlining_disregard_inline_limits
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS
define|\
value|lhd_tree_inlining_add_pending_fn_decls
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P
define|\
value|lhd_tree_inlining_tree_chain_matters_p
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P
define|\
value|lhd_tree_inlining_auto_var_in_fn_p
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING
define|\
value|lhd_tree_inlining_copy_res_decl_for_inlining
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P
define|\
value|lhd_tree_inlining_anon_aggr_type_p
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_VAR_MOD_TYPE_P
define|\
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_START_INLINING
define|\
value|lhd_tree_inlining_start_inlining
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_END_INLINING
define|\
value|lhd_tree_inlining_end_inlining
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_CONVERT_PARM_FOR_INLINING
define|\
value|lhd_tree_inlining_convert_parm_for_inlining
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_ESTIMATE_NUM_INSNS
define|\
value|NULL
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_INITIALIZER
value|{ \   LANG_HOOKS_TREE_INLINING_WALK_SUBTREES, \   LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN, \   LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS, \   LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS, \   LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P, \   LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P, \   LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING, \   LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P, \   LANG_HOOKS_TREE_INLINING_VAR_MOD_TYPE_P, \   LANG_HOOKS_TREE_INLINING_START_INLINING, \   LANG_HOOKS_TREE_INLINING_END_INLINING, \   LANG_HOOKS_TREE_INLINING_CONVERT_PARM_FOR_INLINING, \   LANG_HOOKS_TREE_INLINING_ESTIMATE_NUM_INSNS \ }
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_CALLGRAPH_ANALYZE_EXPR
value|lhd_callgraph_analyze_expr
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_CALLGRAPH_EXPAND_FUNCTION
value|NULL
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_CALLGRAPH_INITIALIZER
value|{ \   LANG_HOOKS_CALLGRAPH_ANALYZE_EXPR, \   LANG_HOOKS_CALLGRAPH_EXPAND_FUNCTION, \ }
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FUNCTION_INITIALIZER
value|{	\   LANG_HOOKS_FUNCTION_INIT,			\   LANG_HOOKS_FUNCTION_FINAL,			\   LANG_HOOKS_FUNCTION_ENTER_NESTED,		\   LANG_HOOKS_FUNCTION_LEAVE_NESTED		\ }
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_RTL_EXPAND_INITIALIZER
value|{	\   LANG_HOOKS_RTL_EXPAND_START,			\   LANG_HOOKS_RTL_EXPAND_STMT,			\   LANG_HOOKS_RTL_EXPAND_END			\ }
end_define

begin_comment
comment|/* Tree dump hooks.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|lhd_tree_dump_dump_tree
parameter_list|(
name|void
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lhd_tree_dump_type_quals
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_DUMP_DUMP_TREE_FN
value|lhd_tree_dump_dump_tree
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_DUMP_TYPE_QUALS_FN
value|lhd_tree_dump_type_quals
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_DUMP_INITIALIZER
value|{ \   LANG_HOOKS_TREE_DUMP_DUMP_TREE_FN, \   LANG_HOOKS_TREE_DUMP_TYPE_QUALS_FN \ }
end_define

begin_comment
comment|/* Types hooks.  There are no reasonable defaults for most of them,    so we create a compile-time error instead.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_MAKE_TYPE
value|make_node
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_INCOMPLETE_TYPE_ERROR
value|lhd_incomplete_type_error
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_TYPE_PROMOTES_TO
value|lhd_type_promotes_to
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_REGISTER_BUILTIN_TYPE
value|lhd_register_builtin_type
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_FOR_TYPES_INITIALIZER
value|{ \   LANG_HOOKS_MAKE_TYPE, \   LANG_HOOKS_TYPE_FOR_MODE, \   LANG_HOOKS_TYPE_FOR_SIZE, \   LANG_HOOKS_UNSIGNED_TYPE, \   LANG_HOOKS_SIGNED_TYPE, \   LANG_HOOKS_SIGNED_OR_UNSIGNED_TYPE, \   LANG_HOOKS_TYPE_PROMOTES_TO, \   LANG_HOOKS_REGISTER_BUILTIN_TYPE, \   LANG_HOOKS_INCOMPLETE_TYPE_ERROR \ }
end_define

begin_comment
comment|/* Declaration hooks.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_PUSHLEVEL
value|pushlevel
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_POPLEVEL
value|poplevel
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_GLOBAL_BINDINGS_P
value|global_bindings_p
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_INSERT_BLOCK
value|insert_block
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_SET_BLOCK
value|set_block
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PUSHDECL
value|pushdecl
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_GETDECLS
value|getdecls
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_BUILTIN_TYPE_DECLS
value|lhd_return_null_tree_v
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_WARN_UNUSED_GLOBAL_DECL
value|lhd_warn_unused_global_decl
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_WRITE_GLOBALS
value|write_global_declarations
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_PREPARE_ASSEMBLE_VARIABLE
value|NULL
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_OK_FOR_SIBCALL
value|lhd_decl_ok_for_sibcall
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DECLS
value|{ \   LANG_HOOKS_PUSHLEVEL, \   LANG_HOOKS_POPLEVEL, \   LANG_HOOKS_GLOBAL_BINDINGS_P, \   LANG_HOOKS_INSERT_BLOCK, \   LANG_HOOKS_SET_BLOCK, \   LANG_HOOKS_PUSHDECL, \   LANG_HOOKS_GETDECLS, \   LANG_HOOKS_BUILTIN_TYPE_DECLS, \   LANG_HOOKS_WARN_UNUSED_GLOBAL_DECL, \   LANG_HOOKS_WRITE_GLOBALS, \   LANG_HOOKS_PREPARE_ASSEMBLE_VARIABLE, \   LANG_HOOKS_DECL_OK_FOR_SIBCALL, \ }
end_define

begin_comment
comment|/* The whole thing.  The structure is defined in langhooks.h.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_INITIALIZER
value|{ \   LANG_HOOKS_NAME, \   LANG_HOOKS_IDENTIFIER_SIZE, \   LANG_HOOKS_TREE_SIZE, \   LANG_HOOKS_INIT_OPTIONS, \   LANG_HOOKS_INITIALIZE_DIAGNOSTICS, \   LANG_HOOKS_HANDLE_OPTION, \   LANG_HOOKS_MISSING_ARGUMENT, \   LANG_HOOKS_POST_OPTIONS, \   LANG_HOOKS_INIT, \   LANG_HOOKS_FINISH, \   LANG_HOOKS_PARSE_FILE, \   LANG_HOOKS_CLEAR_BINDING_STACK, \   LANG_HOOKS_GET_ALIAS_SET, \   LANG_HOOKS_EXPAND_CONSTANT, \   LANG_HOOKS_EXPAND_EXPR, \   LANG_HOOKS_TRUTHVALUE_CONVERSION, \   LANG_HOOKS_SAFE_FROM_P, \   LANG_HOOKS_FINISH_INCOMPLETE_DECL, \   LANG_HOOKS_UNSAFE_FOR_REEVAL, \   LANG_HOOKS_MARK_ADDRESSABLE, \   LANG_HOOKS_STATICP, \   LANG_HOOKS_DUP_LANG_SPECIFIC_DECL, \   LANG_HOOKS_UNSAVE_EXPR_NOW, \   LANG_HOOKS_MAYBE_BUILD_CLEANUP, \   LANG_HOOKS_SET_DECL_ASSEMBLER_NAME, \   LANG_HOOKS_CAN_USE_BIT_FIELDS_P, \   LANG_HOOKS_HONOR_READONLY, \   LANG_HOOKS_NO_BODY_BLOCKS, \   LANG_HOOKS_PRINT_STATISTICS, \   LANG_HOOKS_PRINT_XNODE, \   LANG_HOOKS_PRINT_DECL, \   LANG_HOOKS_PRINT_TYPE, \   LANG_HOOKS_PRINT_IDENTIFIER, \   LANG_HOOKS_DECL_PRINTABLE_NAME, \   LANG_HOOKS_GET_CALLEE_FNDECL, \   LANG_HOOKS_PRINT_ERROR_FUNCTION, \   LANG_HOOKS_EXPR_SIZE, \   LANG_HOOKS_DECL_UNINIT, \   LANG_HOOKS_ATTRIBUTE_TABLE, \   LANG_HOOKS_COMMON_ATTRIBUTE_TABLE, \   LANG_HOOKS_FORMAT_ATTRIBUTE_TABLE, \   LANG_HOOKS_FUNCTION_INITIALIZER, \   LANG_HOOKS_TREE_INLINING_INITIALIZER, \   LANG_HOOKS_CALLGRAPH_INITIALIZER, \   LANG_HOOKS_TREE_DUMP_INITIALIZER, \   LANG_HOOKS_DECLS, \   LANG_HOOKS_FOR_TYPES_INITIALIZER, \   LANG_HOOKS_RTL_EXPAND_INITIALIZER \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_LANG_HOOKS_DEF_H */
end_comment

end_unit

