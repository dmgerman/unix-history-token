begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default macros to initialize the lang_hooks data structure.    Copyright 2001, 2002 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|hook_get_alias_set_0
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Note to creators of new hooks:     The macros in this file should NOT be surrounded by a    #ifdef...#endif pair, since this file declares the defaults.  Each    front end overrides any hooks it wishes to, in the file containing    its struct lang_hooks, AFTER including this file.     Prefix all default hooks with "lhd_".  */
end_comment

begin_comment
comment|/* See langhooks.h for the definition and documentation of each hook.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lhd_do_nothing
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
name|void
name|lhd_do_nothing_t
name|PARAMS
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
name|lhd_do_nothing_i
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
name|void
name|lhd_do_nothing_f
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lhd_decode_option
name|PARAMS
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
name|HOST_WIDE_INT
name|lhd_get_alias_set
name|PARAMS
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
name|lhd_return_tree
name|PARAMS
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
name|lhd_return_null_tree
name|PARAMS
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
name|lhd_safe_from_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lhd_staticp
name|PARAMS
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
name|lhd_unsafe_for_reeval
name|PARAMS
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
name|lhd_clear_binding_stack
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
name|void
name|lhd_print_tree_nothing
name|PARAMS
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
specifier|const
name|char
modifier|*
name|lhd_decl_printable_name
name|PARAMS
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
name|rtx
name|lhd_expand_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|,
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
name|void
name|lhd_print_error_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|diagnostic_context
operator|*
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
name|lhd_set_decl_assembler_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|lhd_can_use_bit_fields_p
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
name|bool
name|lhd_warn_unused_global_decl
name|PARAMS
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
name|lhd_incomplete_type_error
name|PARAMS
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
name|lhd_type_promotes_to
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|lhd_decl_ok_for_sibcall
name|PARAMS
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
name|lhd_expr_size
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declarations of default tree inlining hooks.  */
end_comment

begin_decl_stmt
name|tree
name|lhd_tree_inlining_walk_subtrees
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|int
operator|*
operator|,
name|walk_tree_fn
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_inlining_cannot_inline_tree_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_inlining_disregard_inline_limits
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|lhd_tree_inlining_add_pending_fn_decls
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_inlining_tree_chain_matters_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_inlining_auto_var_in_fn_p
name|PARAMS
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
name|tree
name|lhd_tree_inlining_copy_res_decl_for_inlining
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|void
operator|*
operator|,
name|int
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_inlining_anon_aggr_type_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_inlining_start_inlining
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lhd_tree_inlining_end_inlining
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|lhd_tree_inlining_convert_parm_for_inlining
name|PARAMS
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
name|void
name|write_global_declarations
name|PARAMS
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
value|lhd_do_nothing
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
value|lhd_do_nothing
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DECODE_OPTION
value|lhd_decode_option
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_POST_OPTIONS
value|hook_bool_void_false
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
name|LANG_HOOKS_INSERT_DEFAULT_ATTRIBUTES
value|lhd_do_nothing_t
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
name|LANG_HOOKS_EXPR_SIZE
value|lhd_expr_size
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
name|LANG_HOOKS_TREE_INLINING_INITIALIZER
value|{ \   LANG_HOOKS_TREE_INLINING_WALK_SUBTREES, \   LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN, \   LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS, \   LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS, \   LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P, \   LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P, \   LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING, \   LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P, \   LANG_HOOKS_TREE_INLINING_VAR_MOD_TYPE_P, \   LANG_HOOKS_TREE_INLINING_START_INLINING, \   LANG_HOOKS_TREE_INLINING_END_INLINING, \   LANG_HOOKS_TREE_INLINING_CONVERT_PARM_FOR_INLINING \ } \  #define LANG_HOOKS_FUNCTION_INITIALIZER {	\   LANG_HOOKS_FUNCTION_INIT,			\   LANG_HOOKS_FUNCTION_FINAL,			\   LANG_HOOKS_FUNCTION_ENTER_NESTED,		\   LANG_HOOKS_FUNCTION_LEAVE_NESTED		\ }
end_define

begin_comment
comment|/* Tree dump hooks.  */
end_comment

begin_decl_stmt
name|int
name|lhd_tree_dump_dump_tree
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lhd_tree_dump_type_quals
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|LANG_HOOKS_FOR_TYPES_INITIALIZER
value|{ \   LANG_HOOKS_MAKE_TYPE, \   LANG_HOOKS_TYPE_FOR_MODE, \   LANG_HOOKS_TYPE_FOR_SIZE, \   LANG_HOOKS_UNSIGNED_TYPE, \   LANG_HOOKS_SIGNED_TYPE, \   LANG_HOOKS_SIGNED_OR_UNSIGNED_TYPE, \   LANG_HOOKS_TYPE_PROMOTES_TO, \   LANG_HOOKS_INCOMPLETE_TYPE_ERROR \ }
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
name|LANG_HOOKS_DECL_OK_FOR_SIBCALL
value|lhd_decl_ok_for_sibcall
end_define

begin_define
define|#
directive|define
name|LANG_HOOKS_DECLS
value|{ \   LANG_HOOKS_PUSHLEVEL, \   LANG_HOOKS_POPLEVEL, \   LANG_HOOKS_GLOBAL_BINDINGS_P, \   LANG_HOOKS_INSERT_BLOCK, \   LANG_HOOKS_SET_BLOCK, \   LANG_HOOKS_PUSHDECL, \   LANG_HOOKS_GETDECLS, \   LANG_HOOKS_WARN_UNUSED_GLOBAL_DECL, \   LANG_HOOKS_WRITE_GLOBALS, \   LANG_HOOKS_DECL_OK_FOR_SIBCALL, \ }
end_define

begin_comment
comment|/* The whole thing.  The structure is defined in langhooks.h.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_INITIALIZER
value|{ \   LANG_HOOKS_NAME, \   LANG_HOOKS_IDENTIFIER_SIZE, \   LANG_HOOKS_INIT_OPTIONS, \   LANG_HOOKS_DECODE_OPTION, \   LANG_HOOKS_POST_OPTIONS, \   LANG_HOOKS_INIT, \   LANG_HOOKS_FINISH, \   LANG_HOOKS_PARSE_FILE, \   LANG_HOOKS_CLEAR_BINDING_STACK, \   LANG_HOOKS_GET_ALIAS_SET, \   LANG_HOOKS_EXPAND_CONSTANT, \   LANG_HOOKS_EXPAND_EXPR, \   LANG_HOOKS_TRUTHVALUE_CONVERSION, \   LANG_HOOKS_INSERT_DEFAULT_ATTRIBUTES, \   LANG_HOOKS_SAFE_FROM_P, \   LANG_HOOKS_FINISH_INCOMPLETE_DECL, \   LANG_HOOKS_UNSAFE_FOR_REEVAL, \   LANG_HOOKS_MARK_ADDRESSABLE, \   LANG_HOOKS_STATICP, \   LANG_HOOKS_DUP_LANG_SPECIFIC_DECL, \   LANG_HOOKS_UNSAVE_EXPR_NOW, \   LANG_HOOKS_MAYBE_BUILD_CLEANUP, \   LANG_HOOKS_SET_DECL_ASSEMBLER_NAME, \   LANG_HOOKS_CAN_USE_BIT_FIELDS_P, \   LANG_HOOKS_HONOR_READONLY, \   LANG_HOOKS_PRINT_STATISTICS, \   LANG_HOOKS_PRINT_XNODE, \   LANG_HOOKS_PRINT_DECL, \   LANG_HOOKS_PRINT_TYPE, \   LANG_HOOKS_PRINT_IDENTIFIER, \   LANG_HOOKS_DECL_PRINTABLE_NAME, \   LANG_HOOKS_PRINT_ERROR_FUNCTION, \   LANG_HOOKS_EXPR_SIZE, \   LANG_HOOKS_ATTRIBUTE_TABLE, \   LANG_HOOKS_COMMON_ATTRIBUTE_TABLE, \   LANG_HOOKS_FORMAT_ATTRIBUTE_TABLE, \   LANG_HOOKS_FUNCTION_INITIALIZER, \   LANG_HOOKS_TREE_INLINING_INITIALIZER, \   LANG_HOOKS_TREE_DUMP_INITIALIZER, \   LANG_HOOKS_DECLS, \   LANG_HOOKS_FOR_TYPES_INITIALIZER \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_LANG_HOOKS_DEF_H */
end_comment

end_unit

