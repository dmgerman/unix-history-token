begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-dependent hooks for C++.    Copyright 2001 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"cp-tree.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_include
include|#
directive|include
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"langhooks-def.h"
end_include

begin_decl_stmt
specifier|static
name|HOST_WIDE_INT
name|cxx_get_alias_set
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_NAME
value|"GNU C++"
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_INIT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INIT
value|cxx_init
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
value|cxx_init_options
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_DECODE_OPTION
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DECODE_OPTION
value|cxx_decode_option
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
value|cxx_post_options
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
name|LANG_HOOKS_SAFE_FROM_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SAFE_FROM_P
value|c_safe_from_p
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
name|LANG_HOOKS_SET_YYDEBUG
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SET_YYDEBUG
value|cxx_set_yydebug
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
name|LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P
define|\
value|cp_is_overload_p
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
name|LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING
define|\
value|cp_copy_res_decl_for_inlining
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
name|LANG_HOOKS_TREE_INLINING_START_INLINING
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_START_INLINING
value|cp_start_inlining
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_TREE_INLINING_END_INLINING
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_END_INLINING
value|cp_end_inlining
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

begin_comment
comment|/* Each front end provides its own hooks, for toplev.c.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|lang_hooks
name|lang_hooks
init|=
name|LANG_HOOKS_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Special routine to get the alias set for C++.  */
end_comment

begin_function
specifier|static
name|HOST_WIDE_INT
name|cxx_get_alias_set
parameter_list|(
name|t
parameter_list|)
name|tree
name|t
decl_stmt|;
block|{
comment|/* It's not yet safe to use alias sets for classes in C++ because      the TYPE_FIELDs list for a class doesn't mention base classes.  */
if|if
condition|(
name|AGGREGATE_TYPE_P
argument_list|(
name|t
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|c_common_get_alias_set
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

end_unit

