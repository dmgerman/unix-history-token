begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-specific hook definitions for C front end.    Copyright (C) 1991, 1995, 1997, 1998,    1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"langhooks-def.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|c_init
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|c_init_options
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
name|c_post_options
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ### When changing hooks, consider if ObjC needs changing too!! ### */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_NAME
value|"GNU C"
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
value|c_init
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
value|c_init_options
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
value|c_decode_option
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
value|c_post_options
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
comment|/* ### When changing hooks, consider if ObjC needs changing too!! ### */
end_comment

begin_comment
comment|/* Each front end provides its own.  */
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
comment|/* Post-switch processing.  */
end_comment

begin_function
specifier|static
name|void
name|c_post_options
parameter_list|()
block|{
name|c_common_post_options
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|c_init_options
parameter_list|()
block|{
name|c_common_init_options
argument_list|(
name|clk_c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|c_init
parameter_list|(
name|filename
parameter_list|)
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
block|{
return|return
name|c_objc_common_init
argument_list|(
name|filename
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Used by c-lex.c, but only for objc.  */
end_comment

begin_function
name|tree
name|lookup_interface
parameter_list|(
name|arg
parameter_list|)
name|tree
name|arg
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|is_class_name
parameter_list|(
name|arg
parameter_list|)
name|tree
name|arg
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|maybe_objc_check_decl
parameter_list|(
name|decl
parameter_list|)
name|tree
name|decl
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{ }
end_function

begin_function
name|int
name|maybe_objc_comptypes
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|,
name|reflexive
parameter_list|)
name|tree
name|lhs
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|tree
name|rhs
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|int
name|reflexive
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
name|tree
name|maybe_building_objc_message_expr
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|recognize_objc_keyword
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Used by c-typeck.c (build_external_ref), but only for objc.  */
end_comment

begin_function
name|tree
name|lookup_objc_ivar
parameter_list|(
name|id
parameter_list|)
name|tree
name|id
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|finish_file
parameter_list|()
block|{
name|c_objc_common_finish_file
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

