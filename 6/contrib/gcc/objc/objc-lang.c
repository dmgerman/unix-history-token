begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-dependent hooks for Objective-C.    Copyright 2001, 2002, 2003 Free Software Foundation, Inc.    Contributed by Ziemowit Laski<zlaski@apple.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
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
name|enum
name|c_language_kind
name|c_language
init|=
name|clk_objc
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
value|c_common_init_options
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
name|LANG_HOOKS_TRUTHVALUE_CONVERSION
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TRUTHVALUE_CONVERSION
value|c_common_truthvalue_conversion
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
name|LANG_HOOKS_UNSAFE_FOR_REEVAL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_UNSAFE_FOR_REEVAL
value|c_common_unsafe_for_reeval
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
name|LANG_HOOKS_SET_DECL_ASSEMBLER_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_SET_DECL_ASSEMBLER_NAME
value|c_static_assembler_name
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
name|LANG_HOOKS_DUP_LANG_SPECIFIC_DECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DUP_LANG_SPECIFIC_DECL
value|c_dup_lang_specific_decl
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
name|LANG_HOOKS_DECL_PRINTABLE_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_PRINTABLE_NAME
value|objc_printable_name
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
name|LANG_HOOKS_DECL_UNINIT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_UNINIT
value|c_decl_uninit
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
name|LANG_HOOKS_RTL_EXPAND_STMT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_RTL_EXPAND_STMT
value|expand_stmt
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
name|LANG_HOOKS_TREE_INLINING_ESTIMATE_NUM_INSNS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_TREE_INLINING_ESTIMATE_NUM_INSNS
value|c_estimate_num_insns
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
name|LANG_HOOKS_WRITE_GLOBALS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_WRITE_GLOBALS
value|c_write_global_declarations
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
comment|/* Define the special tree codes that we use.  */
end_comment

begin_comment
comment|/* Table indexed by tree code giving a string containing a character    classifying the tree code.  */
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
value|TYPE,
end_define

begin_decl_stmt
specifier|const
name|char
name|tree_code_type
index|[]
init|=
block|{
include|#
directive|include
file|"tree.def"
literal|'x'
block|,
include|#
directive|include
file|"c-common.def"
literal|'x'
block|,
include|#
directive|include
file|"objc-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Table indexed by tree code giving number of expression    operands beyond the fixed part of the node structure.    Not used for types or decls.  */
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
value|LENGTH,
end_define

begin_decl_stmt
specifier|const
name|unsigned
name|char
name|tree_code_length
index|[]
init|=
block|{
include|#
directive|include
file|"tree.def"
literal|0
block|,
include|#
directive|include
file|"c-common.def"
literal|0
block|,
include|#
directive|include
file|"objc-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Names of tree components.    Used for printing out the tree and error messages.  */
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
name|LEN
parameter_list|)
value|NAME,
end_define

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|tree_code_name
index|[]
init|=
block|{
include|#
directive|include
file|"tree.def"
literal|"@@dummy"
block|,
include|#
directive|include
file|"c-common.def"
literal|"@@dummy"
block|,
include|#
directive|include
file|"objc-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

end_unit

