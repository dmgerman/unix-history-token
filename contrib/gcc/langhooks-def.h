begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default macros to initialize the lang_hooks data structure.    Copyright 2001 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|void
name|lhd_set_yydebug
name|PARAMS
argument_list|(
operator|(
name|int
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
value|lhd_do_nothing
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
name|LANG_HOOKS_SAFE_FROM_P
value|lhd_safe_from_p
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
name|LANG_HOOKS_SET_YYDEBUG
value|lhd_set_yydebug
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
name|LANG_HOOKS_TREE_INLINING_INITIALIZER
value|{ \   LANG_HOOKS_TREE_INLINING_WALK_SUBTREES, \   LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN, \   LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS, \   LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS, \   LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P, \   LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P, \   LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING, \   LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P, \   LANG_HOOKS_TREE_INLINING_START_INLINING, \   LANG_HOOKS_TREE_INLINING_END_INLINING \ }
end_define

begin_comment
unit|\
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
unit|\
comment|/* The whole thing.  The structure is defined in langhooks.h.  */
end_comment

begin_define
define|#
directive|define
name|LANG_HOOKS_INITIALIZER
value|{ \   LANG_HOOKS_NAME, \   LANG_HOOKS_IDENTIFIER_SIZE, \   LANG_HOOKS_INIT_OPTIONS, \   LANG_HOOKS_DECODE_OPTION, \   LANG_HOOKS_POST_OPTIONS, \   LANG_HOOKS_INIT, \   LANG_HOOKS_FINISH, \   LANG_HOOKS_CLEAR_BINDING_STACK, \   LANG_HOOKS_GET_ALIAS_SET, \   LANG_HOOKS_EXPAND_CONSTANT, \   LANG_HOOKS_SAFE_FROM_P, \   LANG_HOOKS_STATICP, \   LANG_HOOKS_HONOR_READONLY, \   LANG_HOOKS_PRINT_STATISTICS, \   LANG_HOOKS_PRINT_XNODE, \   LANG_HOOKS_PRINT_DECL, \   LANG_HOOKS_PRINT_TYPE, \   LANG_HOOKS_PRINT_IDENTIFIER, \   LANG_HOOKS_SET_YYDEBUG, \   LANG_HOOKS_TREE_INLINING_INITIALIZER, \   LANG_HOOKS_TREE_DUMP_INITIALIZER \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_LANG_HOOKS_DEF_H */
end_comment

end_unit

