begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-dependent hooks for Objective-C.    Copyright 2001 Free Software Foundation, Inc.    Contributed by Ziemowit Laski<zlaski@apple.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"c-tree.h"
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
file|"objc-act.h"
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
name|void
name|objc_init_options
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|objc_post_options
name|PARAMS
argument_list|(
operator|(
name|void
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
value|"GNU Objective-C"
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
value|objc_init
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
value|objc_init_options
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
value|objc_decode_option
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
value|objc_post_options
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
name|LANG_HOOKS_SET_YYDEBUG
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SET_YYDEBUG
value|c_set_yydebug
end_define

begin_comment
comment|/* Inlining hooks same as the C front end.  */
end_comment

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

begin_function
specifier|static
name|void
name|objc_init_options
parameter_list|()
block|{
name|c_common_init_options
argument_list|(
name|clk_objective_c
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Post-switch processing.  */
end_comment

begin_function
specifier|static
name|void
name|objc_post_options
parameter_list|()
block|{
name|c_common_post_options
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

