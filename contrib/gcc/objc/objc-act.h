begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for objc-act.c.    Copyright (C) 1990, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_OBJC_ACT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_OBJC_ACT_H
end_define

begin_comment
comment|/*** Public Interface (procedures) ***/
end_comment

begin_function_decl
name|bool
name|objc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|objc_printable_name
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* used by yyparse */
end_comment

begin_function_decl
name|void
name|finish_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|start_class
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|continue_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_method_def
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|continue_method_def
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_method_def
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|start_protocol
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_protocol
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_build_throw_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_build_try_catch_finally_stmt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_build_synchronized_prologue
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_build_synchronized_epilogue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_build_try_prologue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_build_try_epilogue
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_build_catch_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_build_catch_epilogue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_build_finally_prologue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_build_finally_epilogue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|is_ivar
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_private
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_public
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|add_instance_variable
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|objc_add_method
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_super_receiver
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_clear_super_receiver
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_class_ivars_from_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_class_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_static_reference
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_object_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_message_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|finish_message_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_selector_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_ivar_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_keyword_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_method_decl
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_protocol_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_objc_string_object
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_declare_alias
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_declare_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_declare_protocols
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the following routines are used to implement statically typed objects */
end_comment

begin_function_decl
name|int
name|objc_comptypes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_check_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NeXT extensions */
end_comment

begin_function_decl
name|tree
name|build_encode_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Objective-C structures */
end_comment

begin_define
define|#
directive|define
name|CLASS_BINFO_ELTS
value|6
end_define

begin_define
define|#
directive|define
name|PROTOCOL_BINFO_ELTS
value|2
end_define

begin_comment
comment|/* KEYWORD_DECL */
end_comment

begin_define
define|#
directive|define
name|KEYWORD_KEY_NAME
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.name)
end_define

begin_define
define|#
directive|define
name|KEYWORD_ARG_NAME
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.arguments)
end_define

begin_comment
comment|/* INSTANCE_METHOD_DECL, CLASS_METHOD_DECL */
end_comment

begin_define
define|#
directive|define
name|METHOD_SEL_NAME
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.name)
end_define

begin_define
define|#
directive|define
name|METHOD_SEL_ARGS
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.arguments)
end_define

begin_define
define|#
directive|define
name|METHOD_ADD_ARGS
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.result)
end_define

begin_define
define|#
directive|define
name|METHOD_DEFINITION
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.initial)
end_define

begin_define
define|#
directive|define
name|METHOD_ENCODING
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.context)
end_define

begin_comment
comment|/* CLASS_INTERFACE_TYPE, CLASS_IMPLEMENTATION_TYPE,    CATEGORY_INTERFACE_TYPE, CATEGORY_IMPLEMENTATION_TYPE,    PROTOCOL_INTERFACE_TYPE */
end_comment

begin_define
define|#
directive|define
name|CLASS_NAME
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.name)
end_define

begin_define
define|#
directive|define
name|CLASS_SUPER_NAME
parameter_list|(
name|CLASS
parameter_list|)
value|(TYPE_CHECK (CLASS)->type.context)
end_define

begin_define
define|#
directive|define
name|CLASS_IVARS
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 0)
end_define

begin_define
define|#
directive|define
name|CLASS_RAW_IVARS
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 1)
end_define

begin_define
define|#
directive|define
name|CLASS_NST_METHODS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.minval)
end_define

begin_define
define|#
directive|define
name|CLASS_CLS_METHODS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.maxval)
end_define

begin_define
define|#
directive|define
name|CLASS_STATIC_TEMPLATE
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 2)
end_define

begin_define
define|#
directive|define
name|CLASS_CATEGORY_LIST
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 3)
end_define

begin_define
define|#
directive|define
name|CLASS_PROTOCOL_LIST
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 4)
end_define

begin_define
define|#
directive|define
name|CLASS_OWN_IVARS
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 5)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_NAME
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.name)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_LIST
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 0)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_NST_METHODS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.minval)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_CLS_METHODS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.maxval)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_FORWARD_DECL
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (CLASS), 1)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_DEFINED
parameter_list|(
name|CLASS
parameter_list|)
value|TREE_USED (CLASS)
end_define

begin_comment
comment|/* We need to distinguish TYPE_PROTOCOL_LISTs from TYPE_CONTEXTs, both of which    are stored in the same accessor slot.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PROTOCOL_LIST
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|((TYPE_CHECK (TYPE)->type.context			\&& TREE_CODE ((TYPE)->type.context) == TREE_LIST)	\ 	 ? (TYPE)->type.context : NULL_TREE)
end_define

begin_define
define|#
directive|define
name|SET_TYPE_PROTOCOL_LIST
parameter_list|(
name|TYPE
parameter_list|,
name|P
parameter_list|)
value|(TYPE_CHECK (TYPE)->type.context = (P))
end_define

begin_comment
comment|/* Set by `continue_class' and checked by `is_public'.  */
end_comment

begin_define
define|#
directive|define
name|TREE_STATIC_TEMPLATE
parameter_list|(
name|record_type
parameter_list|)
value|(TREE_PUBLIC (record_type))
end_define

begin_define
define|#
directive|define
name|TYPED_OBJECT
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) == RECORD_TYPE&& TREE_STATIC_TEMPLATE (type))
end_define

begin_define
define|#
directive|define
name|OBJC_TYPE_NAME
parameter_list|(
name|type
parameter_list|)
value|TYPE_NAME(type)
end_define

begin_comment
comment|/* Define the Objective-C or Objective-C++ language-specific tree codes.  */
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
value|SYM,
end_define

begin_enum
enum|enum
name|objc_tree_code
block|{
if|#
directive|if
name|defined
argument_list|(
name|GCC_CP_TREE_H
argument_list|)
name|LAST_BASE_TREE_CODE
init|=
name|LAST_CPLUS_TREE_CODE
block|,
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|GCC_C_TREE_H
argument_list|)
name|LAST_BASE_TREE_CODE
init|=
name|LAST_C_TREE_CODE
block|,
else|#
directive|else
error|#
directive|error
error|You must include<c-tree.h> or<cp/cp-tree.h> before<objc/objc-act.h>
endif|#
directive|endif
endif|#
directive|endif
include|#
directive|include
file|"objc-tree.def"
name|LAST_OBJC_TREE_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Hash tables to manage the global pool of method prototypes.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|hashed_entry
modifier|*
name|hash
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hashed_attribute
modifier|*
name|attr
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|hashed_attribute
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|attr
name|next
decl_stmt|;
name|tree
name|value
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|hashed_entry
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|attr
name|list
decl_stmt|;
name|hash
name|next
decl_stmt|;
name|tree
name|key
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GTY ((length (
literal|"SIZEHASHTABLE"
end_extern

begin_decl_stmt
unit|)))
name|hash
modifier|*
name|nst_method_hash_list
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY ((length (
literal|"SIZEHASHTABLE"
end_extern

begin_decl_stmt
unit|)))
name|hash
modifier|*
name|cls_method_hash_list
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIZEHASHTABLE
value|257
end_define

begin_comment
comment|/* Objective-C/Objective-C++ @implementation list.  */
end_comment

begin_decl_stmt
name|struct
name|imp_entry
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|imp_entry
modifier|*
name|next
decl_stmt|;
name|tree
name|imp_context
decl_stmt|;
name|tree
name|imp_template
decl_stmt|;
name|tree
name|class_decl
decl_stmt|;
comment|/* _OBJC_CLASS_<my_name>; */
name|tree
name|meta_decl
decl_stmt|;
comment|/* _OBJC_METACLASS_<my_name>; */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|imp_entry
modifier|*
name|imp_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|imp_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `@implementation' */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cat_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `@category' */
end_comment

begin_comment
comment|/* Objective-C/Objective-C++ global tree enumeration.  */
end_comment

begin_enum
enum|enum
name|objc_tree_index
block|{
name|OCTI_STATIC_NST
block|,
name|OCTI_STATIC_NST_DECL
block|,
name|OCTI_SELF_ID
block|,
name|OCTI_UCMD_ID
block|,
name|OCTI_UNUSED_LIST
block|,
name|OCTI_ELLIPSIS_NODE
block|,
name|OCTI_SELF_DECL
block|,
name|OCTI_UMSG_DECL
block|,
name|OCTI_UMSG_SUPER_DECL
block|,
name|OCTI_UMSG_STRET_DECL
block|,
name|OCTI_UMSG_SUPER_STRET_DECL
block|,
name|OCTI_GET_CLASS_DECL
block|,
name|OCTI_GET_MCLASS_DECL
block|,
name|OCTI_SUPER_TYPE
block|,
name|OCTI_SEL_TYPE
block|,
name|OCTI_ID_TYPE
block|,
name|OCTI_CLS_TYPE
block|,
name|OCTI_NST_TYPE
block|,
name|OCTI_PROTO_TYPE
block|,
name|OCTI_CLS_CHAIN
block|,
name|OCTI_ALIAS_CHAIN
block|,
name|OCTI_INTF_CHAIN
block|,
name|OCTI_PROTO_CHAIN
block|,
name|OCTI_IMPL_CHAIN
block|,
name|OCTI_CLS_REF_CHAIN
block|,
name|OCTI_SEL_REF_CHAIN
block|,
name|OCTI_IVAR_CHAIN
block|,
name|OCTI_CLS_NAMES_CHAIN
block|,
name|OCTI_METH_VAR_NAMES_CHAIN
block|,
name|OCTI_METH_VAR_TYPES_CHAIN
block|,
name|OCTI_SYMBOLS_DECL
block|,
name|OCTI_NST_VAR_DECL
block|,
name|OCTI_CLS_VAR_DECL
block|,
name|OCTI_NST_METH_DECL
block|,
name|OCTI_CLS_METH_DECL
block|,
name|OCTI_CLS_DECL
block|,
name|OCTI_MCLS_DECL
block|,
name|OCTI_SEL_TABLE_DECL
block|,
name|OCTI_MODULES_DECL
block|,
name|OCTI_STRG_DECL
block|,
name|OCTI_INTF_CTX
block|,
name|OCTI_IMPL_CTX
block|,
name|OCTI_METH_CTX
block|,
name|OCTI_IVAR_CTX
block|,
name|OCTI_IMPL_TEMPL
block|,
name|OCTI_CLS_TEMPL
block|,
name|OCTI_CAT_TEMPL
block|,
name|OCTI_UPRIV_REC
block|,
name|OCTI_PROTO_TEMPL
block|,
name|OCTI_SEL_TEMPL
block|,
name|OCTI_UCLS_SUPER_REF
block|,
name|OCTI_UUCLS_SUPER_REF
block|,
name|OCTI_METH_TEMPL
block|,
name|OCTI_IVAR_TEMPL
block|,
name|OCTI_SYMTAB_TEMPL
block|,
name|OCTI_MODULE_TEMPL
block|,
name|OCTI_SUPER_TEMPL
block|,
name|OCTI_OBJ_REF
block|,
name|OCTI_METH_PROTO_TEMPL
block|,
name|OCTI_FUNCTION1_TEMPL
block|,
name|OCTI_FUNCTION2_TEMPL
block|,
name|OCTI_OBJ_ID
block|,
name|OCTI_CLS_ID
block|,
name|OCTI_ID_ID
block|,
name|OCTI_CNST_STR_ID
block|,
name|OCTI_CNST_STR_TYPE
block|,
name|OCTI_CNST_STR_GLOB_ID
block|,
name|OCTI_STRING_CLASS_DECL
block|,
name|OCTI_SUPER_DECL
block|,
name|OCTI_UMSG_NONNIL_DECL
block|,
name|OCTI_UMSG_NONNIL_STRET_DECL
block|,
name|OCTI_STORAGE_CLS
block|,
name|OCTI_EXCEPTION_EXTRACT_DECL
block|,
name|OCTI_EXCEPTION_TRY_ENTER_DECL
block|,
name|OCTI_EXCEPTION_TRY_EXIT_DECL
block|,
name|OCTI_EXCEPTION_MATCH_DECL
block|,
name|OCTI_EXCEPTION_THROW_DECL
block|,
name|OCTI_SYNC_ENTER_DECL
block|,
name|OCTI_SYNC_EXIT_DECL
block|,
name|OCTI_SETJMP_DECL
block|,
name|OCTI_EXCDATA_TEMPL
block|,
name|OCTI_STACK_EXCEPTION_DATA_DECL
block|,
name|OCTI_LOCAL_EXCEPTION_DECL
block|,
name|OCTI_RETHROW_EXCEPTION_DECL
block|,
name|OCTI_EVAL_ONCE_DECL
block|,
name|OCTI_EXCEPTION_BLK_STACK
block|,
name|OCTI_CATCH_TYPE
block|,
name|OCTI_MAX
block|}
enum|;
end_enum

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|objc_global_trees
index|[
name|OCTI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of classes with list of their static instances.  */
end_comment

begin_define
define|#
directive|define
name|objc_static_instances
value|objc_global_trees[OCTI_STATIC_NST]
end_define

begin_comment
comment|/* The declaration of the array administrating the static instances.  */
end_comment

begin_define
define|#
directive|define
name|static_instances_decl
value|objc_global_trees[OCTI_STATIC_NST_DECL]
end_define

begin_comment
comment|/* Some commonly used instances of "identifier_node".  */
end_comment

begin_define
define|#
directive|define
name|self_id
value|objc_global_trees[OCTI_SELF_ID]
end_define

begin_define
define|#
directive|define
name|ucmd_id
value|objc_global_trees[OCTI_UCMD_ID]
end_define

begin_define
define|#
directive|define
name|unused_list
value|objc_global_trees[OCTI_UNUSED_LIST]
end_define

begin_define
define|#
directive|define
name|objc_ellipsis_node
value|objc_global_trees[OCTI_ELLIPSIS_NODE]
end_define

begin_define
define|#
directive|define
name|self_decl
value|objc_global_trees[OCTI_SELF_DECL]
end_define

begin_define
define|#
directive|define
name|umsg_decl
value|objc_global_trees[OCTI_UMSG_DECL]
end_define

begin_define
define|#
directive|define
name|umsg_super_decl
value|objc_global_trees[OCTI_UMSG_SUPER_DECL]
end_define

begin_define
define|#
directive|define
name|umsg_stret_decl
value|objc_global_trees[OCTI_UMSG_STRET_DECL]
end_define

begin_define
define|#
directive|define
name|umsg_super_stret_decl
value|objc_global_trees[OCTI_UMSG_SUPER_STRET_DECL]
end_define

begin_define
define|#
directive|define
name|objc_get_class_decl
value|objc_global_trees[OCTI_GET_CLASS_DECL]
end_define

begin_define
define|#
directive|define
name|objc_get_meta_class_decl
define|\
value|objc_global_trees[OCTI_GET_MCLASS_DECL]
end_define

begin_define
define|#
directive|define
name|super_type
value|objc_global_trees[OCTI_SUPER_TYPE]
end_define

begin_define
define|#
directive|define
name|selector_type
value|objc_global_trees[OCTI_SEL_TYPE]
end_define

begin_define
define|#
directive|define
name|id_type
value|objc_global_trees[OCTI_ID_TYPE]
end_define

begin_define
define|#
directive|define
name|objc_class_type
value|objc_global_trees[OCTI_CLS_TYPE]
end_define

begin_define
define|#
directive|define
name|instance_type
value|objc_global_trees[OCTI_NST_TYPE]
end_define

begin_define
define|#
directive|define
name|protocol_type
value|objc_global_trees[OCTI_PROTO_TYPE]
end_define

begin_comment
comment|/* Type checking macros.  */
end_comment

begin_define
define|#
directive|define
name|IS_ID
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_MAIN_VARIANT (TYPE) == TYPE_MAIN_VARIANT (id_type))
end_define

begin_define
define|#
directive|define
name|IS_PROTOCOL_QUALIFIED_ID
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(IS_ID (TYPE)&& TYPE_PROTOCOL_LIST (TYPE))
end_define

begin_define
define|#
directive|define
name|IS_SUPER
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == POINTER_TYPE&& TREE_TYPE (TYPE) == objc_super_template)
end_define

begin_define
define|#
directive|define
name|class_chain
value|objc_global_trees[OCTI_CLS_CHAIN]
end_define

begin_define
define|#
directive|define
name|alias_chain
value|objc_global_trees[OCTI_ALIAS_CHAIN]
end_define

begin_define
define|#
directive|define
name|interface_chain
value|objc_global_trees[OCTI_INTF_CHAIN]
end_define

begin_define
define|#
directive|define
name|protocol_chain
value|objc_global_trees[OCTI_PROTO_CHAIN]
end_define

begin_define
define|#
directive|define
name|implemented_classes
value|objc_global_trees[OCTI_IMPL_CHAIN]
end_define

begin_comment
comment|/* Chains to manage selectors that are referenced and defined in the    module.  */
end_comment

begin_define
define|#
directive|define
name|cls_ref_chain
value|objc_global_trees[OCTI_CLS_REF_CHAIN]
end_define

begin_comment
comment|/* Classes referenced.  */
end_comment

begin_define
define|#
directive|define
name|sel_ref_chain
value|objc_global_trees[OCTI_SEL_REF_CHAIN]
end_define

begin_comment
comment|/* Selectors referenced.  */
end_comment

begin_define
define|#
directive|define
name|objc_ivar_chain
value|objc_global_trees[OCTI_IVAR_CHAIN]
end_define

begin_comment
comment|/* Chains to manage uniquing of strings.  */
end_comment

begin_define
define|#
directive|define
name|class_names_chain
value|objc_global_trees[OCTI_CLS_NAMES_CHAIN]
end_define

begin_define
define|#
directive|define
name|meth_var_names_chain
value|objc_global_trees[OCTI_METH_VAR_NAMES_CHAIN]
end_define

begin_define
define|#
directive|define
name|meth_var_types_chain
value|objc_global_trees[OCTI_METH_VAR_TYPES_CHAIN]
end_define

begin_comment
comment|/* Backend data declarations.  */
end_comment

begin_define
define|#
directive|define
name|UOBJC_SYMBOLS_decl
value|objc_global_trees[OCTI_SYMBOLS_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_INSTANCE_VARIABLES_decl
value|objc_global_trees[OCTI_NST_VAR_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_CLASS_VARIABLES_decl
value|objc_global_trees[OCTI_CLS_VAR_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_INSTANCE_METHODS_decl
value|objc_global_trees[OCTI_NST_METH_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_CLASS_METHODS_decl
value|objc_global_trees[OCTI_CLS_METH_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_CLASS_decl
value|objc_global_trees[OCTI_CLS_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_METACLASS_decl
value|objc_global_trees[OCTI_MCLS_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_SELECTOR_TABLE_decl
value|objc_global_trees[OCTI_SEL_TABLE_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_MODULES_decl
value|objc_global_trees[OCTI_MODULES_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_STRINGS_decl
value|objc_global_trees[OCTI_STRG_DECL]
end_define

begin_comment
comment|/* The following are used when compiling a class implementation.    implementation_template will normally be an interface, however if    none exists this will be equal to objc_implementation_context...it is    set in start_class.  */
end_comment

begin_define
define|#
directive|define
name|objc_interface_context
value|objc_global_trees[OCTI_INTF_CTX]
end_define

begin_define
define|#
directive|define
name|objc_implementation_context
value|objc_global_trees[OCTI_IMPL_CTX]
end_define

begin_define
define|#
directive|define
name|objc_method_context
value|objc_global_trees[OCTI_METH_CTX]
end_define

begin_define
define|#
directive|define
name|objc_ivar_context
value|objc_global_trees[OCTI_IVAR_CTX]
end_define

begin_define
define|#
directive|define
name|implementation_template
value|objc_global_trees[OCTI_IMPL_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_class_template
value|objc_global_trees[OCTI_CLS_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_category_template
value|objc_global_trees[OCTI_CAT_TEMPL]
end_define

begin_define
define|#
directive|define
name|uprivate_record
value|objc_global_trees[OCTI_UPRIV_REC]
end_define

begin_define
define|#
directive|define
name|objc_protocol_template
value|objc_global_trees[OCTI_PROTO_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_selector_template
value|objc_global_trees[OCTI_SEL_TEMPL]
end_define

begin_define
define|#
directive|define
name|ucls_super_ref
value|objc_global_trees[OCTI_UCLS_SUPER_REF]
end_define

begin_define
define|#
directive|define
name|uucls_super_ref
value|objc_global_trees[OCTI_UUCLS_SUPER_REF]
end_define

begin_define
define|#
directive|define
name|umsg_nonnil_decl
value|objc_global_trees[OCTI_UMSG_NONNIL_DECL]
end_define

begin_define
define|#
directive|define
name|umsg_nonnil_stret_decl
value|objc_global_trees[OCTI_UMSG_NONNIL_STRET_DECL]
end_define

begin_define
define|#
directive|define
name|objc_storage_class
value|objc_global_trees[OCTI_STORAGE_CLS]
end_define

begin_define
define|#
directive|define
name|objc_exception_extract_decl
define|\
value|objc_global_trees[OCTI_EXCEPTION_EXTRACT_DECL]
end_define

begin_define
define|#
directive|define
name|objc_exception_try_enter_decl
define|\
value|objc_global_trees[OCTI_EXCEPTION_TRY_ENTER_DECL]
end_define

begin_define
define|#
directive|define
name|objc_exception_try_exit_decl
define|\
value|objc_global_trees[OCTI_EXCEPTION_TRY_EXIT_DECL]
end_define

begin_define
define|#
directive|define
name|objc_exception_match_decl
define|\
value|objc_global_trees[OCTI_EXCEPTION_MATCH_DECL]
end_define

begin_define
define|#
directive|define
name|objc_exception_throw_decl
define|\
value|objc_global_trees[OCTI_EXCEPTION_THROW_DECL]
end_define

begin_define
define|#
directive|define
name|objc_sync_enter_decl
value|objc_global_trees[OCTI_SYNC_ENTER_DECL]
end_define

begin_define
define|#
directive|define
name|objc_sync_exit_decl
value|objc_global_trees[OCTI_SYNC_EXIT_DECL]
end_define

begin_define
define|#
directive|define
name|objc_exception_data_template
define|\
value|objc_global_trees[OCTI_EXCDATA_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_setjmp_decl
value|objc_global_trees[OCTI_SETJMP_DECL]
end_define

begin_define
define|#
directive|define
name|objc_stack_exception_data
define|\
value|objc_global_trees[OCTI_STACK_EXCEPTION_DATA_DECL]
end_define

begin_define
define|#
directive|define
name|objc_caught_exception
value|objc_global_trees[OCTI_LOCAL_EXCEPTION_DECL]
end_define

begin_define
define|#
directive|define
name|objc_rethrow_exception
value|objc_global_trees[OCTI_RETHROW_EXCEPTION_DECL]
end_define

begin_define
define|#
directive|define
name|objc_eval_once
value|objc_global_trees[OCTI_EVAL_ONCE_DECL]
end_define

begin_define
define|#
directive|define
name|objc_exception_block_stack
define|\
value|objc_global_trees[OCTI_EXCEPTION_BLK_STACK]
end_define

begin_define
define|#
directive|define
name|objc_catch_type
value|objc_global_trees[OCTI_CATCH_TYPE]
end_define

begin_define
define|#
directive|define
name|objc_method_template
value|objc_global_trees[OCTI_METH_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_ivar_template
value|objc_global_trees[OCTI_IVAR_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_symtab_template
value|objc_global_trees[OCTI_SYMTAB_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_module_template
value|objc_global_trees[OCTI_MODULE_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_super_template
value|objc_global_trees[OCTI_SUPER_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_object_reference
value|objc_global_trees[OCTI_OBJ_REF]
end_define

begin_define
define|#
directive|define
name|objc_method_prototype_template
define|\
value|objc_global_trees[OCTI_METH_PROTO_TEMPL]
end_define

begin_define
define|#
directive|define
name|function1_template
value|objc_global_trees[OCTI_FUNCTION1_TEMPL]
end_define

begin_define
define|#
directive|define
name|function2_template
value|objc_global_trees[OCTI_FUNCTION2_TEMPL]
end_define

begin_define
define|#
directive|define
name|objc_object_id
value|objc_global_trees[OCTI_OBJ_ID]
end_define

begin_define
define|#
directive|define
name|objc_class_id
value|objc_global_trees[OCTI_CLS_ID]
end_define

begin_define
define|#
directive|define
name|objc_id_id
value|objc_global_trees[OCTI_ID_ID]
end_define

begin_define
define|#
directive|define
name|constant_string_id
value|objc_global_trees[OCTI_CNST_STR_ID]
end_define

begin_define
define|#
directive|define
name|constant_string_type
value|objc_global_trees[OCTI_CNST_STR_TYPE]
end_define

begin_define
define|#
directive|define
name|constant_string_global_id
define|\
value|objc_global_trees[OCTI_CNST_STR_GLOB_ID]
end_define

begin_define
define|#
directive|define
name|string_class_decl
value|objc_global_trees[OCTI_STRING_CLASS_DECL]
end_define

begin_define
define|#
directive|define
name|UOBJC_SUPER_decl
value|objc_global_trees[OCTI_SUPER_DECL]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_OBJC_ACT_H */
end_comment

end_unit

