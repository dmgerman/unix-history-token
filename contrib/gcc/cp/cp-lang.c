begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-dependent hooks for C++.    Copyright 2001, 2002 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
specifier|static
name|bool
name|ok_to_generate_alias_set_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|cxx_warn_unused_global_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|tree
name|cp_expr_size
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|cp_var_mod_type_p
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
value|c_common_decode_option
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
name|LANG_HOOKS_UNSAVE_EXPR_NOW
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_UNSAVE_EXPR_NOW
value|cxx_unsave_expr_now
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_MAYBE_BUILD_CLEANUP
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_MAYBE_BUILD_CLEANUP
value|cxx_maybe_build_cleanup
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
name|LANG_HOOKS_INSERT_DEFAULT_ATTRIBUTES
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INSERT_DEFAULT_ATTRIBUTES
value|cxx_insert_default_attributes
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
name|LANG_HOOKS_DECL_PRINTABLE_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_PRINTABLE_NAME
value|cxx_printable_name
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
comment|/* Tree code classes.  */
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
file|"cp-tree.def"
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
file|"cp-tree.def"
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
file|"cp-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Check if a C++ type is safe for aliasing.    Return TRUE if T safe for aliasing FALSE otherwise.  */
end_comment

begin_function
specifier|static
name|bool
name|ok_to_generate_alias_set_for_type
parameter_list|(
name|t
parameter_list|)
name|tree
name|t
decl_stmt|;
block|{
if|if
condition|(
name|TYPE_PTRMEMFUNC_P
argument_list|(
name|t
argument_list|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|AGGREGATE_TYPE_P
argument_list|(
name|t
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|TREE_CODE
argument_list|(
name|t
argument_list|)
operator|==
name|RECORD_TYPE
operator|)
operator|||
operator|(
name|TREE_CODE
argument_list|(
name|t
argument_list|)
operator|==
name|UNION_TYPE
operator|)
condition|)
block|{
name|tree
name|fields
decl_stmt|;
comment|/* Backend-created structs are safe.  */
if|if
condition|(
operator|!
name|CLASS_TYPE_P
argument_list|(
name|t
argument_list|)
condition|)
return|return
name|true
return|;
comment|/* PODs are safe.  */
if|if
condition|(
operator|!
name|CLASSTYPE_NON_POD_P
argument_list|(
name|t
argument_list|)
condition|)
return|return
name|true
return|;
comment|/* Classes with virtual baseclasses are not.  */
if|if
condition|(
name|TYPE_USES_VIRTUAL_BASECLASSES
argument_list|(
name|t
argument_list|)
condition|)
return|return
name|false
return|;
comment|/* Recursively check the base classes.  */
if|if
condition|(
name|TYPE_BINFO
argument_list|(
name|t
argument_list|)
operator|!=
name|NULL
operator|&&
name|TYPE_BINFO_BASETYPES
argument_list|(
name|t
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|TREE_VEC_LENGTH
argument_list|(
name|TYPE_BINFO_BASETYPES
argument_list|(
name|t
argument_list|)
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
name|tree
name|binfo
init|=
name|TREE_VEC_ELT
argument_list|(
name|TYPE_BINFO_BASETYPES
argument_list|(
name|t
argument_list|)
argument_list|,
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok_to_generate_alias_set_for_type
argument_list|(
name|BINFO_TYPE
argument_list|(
name|binfo
argument_list|)
argument_list|)
condition|)
return|return
name|false
return|;
block|}
block|}
comment|/* Check all the fields.  */
for|for
control|(
name|fields
operator|=
name|TYPE_FIELDS
argument_list|(
name|t
argument_list|)
init|;
name|fields
condition|;
name|fields
operator|=
name|TREE_CHAIN
argument_list|(
name|fields
argument_list|)
control|)
block|{
if|if
condition|(
name|TREE_CODE
argument_list|(
name|fields
argument_list|)
operator|!=
name|FIELD_DECL
condition|)
continue|continue;
if|if
condition|(
operator|!
name|ok_to_generate_alias_set_for_type
argument_list|(
name|TREE_TYPE
argument_list|(
name|fields
argument_list|)
argument_list|)
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
elseif|else
if|if
condition|(
name|TREE_CODE
argument_list|(
name|t
argument_list|)
operator|==
name|ARRAY_TYPE
condition|)
return|return
name|ok_to_generate_alias_set_for_type
argument_list|(
name|TREE_TYPE
argument_list|(
name|t
argument_list|)
argument_list|)
return|;
else|else
comment|/* This should never happen, we dealt with all the aggregate 	   types that can appear in C++ above.  */
name|abort
argument_list|()
expr_stmt|;
block|}
else|else
return|return
name|true
return|;
block|}
end_function

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
if|if
condition|(
comment|/* It's not yet safe to use alias sets for some classes in C++.  */
operator|!
name|ok_to_generate_alias_set_for_type
argument_list|(
name|t
argument_list|)
comment|/* Nor is it safe to use alias sets for pointers-to-member 	 functions, due to the fact that there may be more than one 	 RECORD_TYPE type corresponding to the same pointer-to-member 	 type.  */
operator|||
name|TYPE_PTRMEMFUNC_P
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

begin_comment
comment|/* Called from check_global_declarations.  */
end_comment

begin_function
specifier|static
name|bool
name|cxx_warn_unused_global_decl
parameter_list|(
name|decl
parameter_list|)
name|tree
name|decl
decl_stmt|;
block|{
if|if
condition|(
name|TREE_CODE
argument_list|(
name|decl
argument_list|)
operator|==
name|FUNCTION_DECL
operator|&&
name|DECL_DECLARED_INLINE_P
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|DECL_IN_SYSTEM_HEADER
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|false
return|;
comment|/* Const variables take the place of #defines in C++.  */
if|if
condition|(
name|TREE_CODE
argument_list|(
name|decl
argument_list|)
operator|==
name|VAR_DECL
operator|&&
name|TREE_READONLY
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Langhook for expr_size: Tell the backend that the value of an expression    of non-POD class type does not include any tail padding; a derived class    might have allocated something there.  */
end_comment

begin_function
specifier|static
name|tree
name|cp_expr_size
parameter_list|(
name|exp
parameter_list|)
name|tree
name|exp
decl_stmt|;
block|{
if|if
condition|(
name|CLASS_TYPE_P
argument_list|(
name|TREE_TYPE
argument_list|(
name|exp
argument_list|)
argument_list|)
condition|)
block|{
comment|/* The backend should not be interested in the size of an expression 	 of a type with both of these set; all copies of such types must go 	 through a constructor or assignment op.  */
if|if
condition|(
name|TYPE_HAS_COMPLEX_INIT_REF
argument_list|(
name|TREE_TYPE
argument_list|(
name|exp
argument_list|)
argument_list|)
operator|&&
name|TYPE_HAS_COMPLEX_ASSIGN_REF
argument_list|(
name|TREE_TYPE
argument_list|(
name|exp
argument_list|)
argument_list|)
comment|/* But storing a CONSTRUCTOR isn't a copy.  */
operator|&&
name|TREE_CODE
argument_list|(
name|exp
argument_list|)
operator|!=
name|CONSTRUCTOR
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* This would be wrong for a type with virtual bases, but they are 	 caught by the abort above.  */
return|return
name|CLASSTYPE_SIZE_UNIT
argument_list|(
name|TREE_TYPE
argument_list|(
name|exp
argument_list|)
argument_list|)
return|;
block|}
else|else
comment|/* Use the default code.  */
return|return
name|lhd_expr_size
argument_list|(
name|exp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Returns true if T is a variably modified type, in the sense of C99.    This routine needs only check cases that cannot be handled by the    language-independent logic in tree-inline.c.  */
end_comment

begin_function
specifier|static
name|bool
name|cp_var_mod_type_p
parameter_list|(
name|tree
name|type
parameter_list|)
block|{
comment|/* If TYPE is a pointer-to-member, it is variably modified if either      the class or the member are variably modified.  */
if|if
condition|(
name|TYPE_PTRMEM_P
argument_list|(
name|type
argument_list|)
operator|||
name|TYPE_PTRMEMFUNC_P
argument_list|(
name|type
argument_list|)
condition|)
return|return
operator|(
name|variably_modified_type_p
argument_list|(
name|TYPE_PTRMEM_CLASS_TYPE
argument_list|(
name|type
argument_list|)
argument_list|)
operator|||
name|variably_modified_type_p
argument_list|(
name|TYPE_PTRMEM_POINTED_TO_TYPE
argument_list|(
name|type
argument_list|)
argument_list|)
operator|)
return|;
comment|/* All other types are not variably modified.  */
return|return
name|false
return|;
block|}
end_function

end_unit

