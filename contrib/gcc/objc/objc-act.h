begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for objc-act.c.    Copyright (C) 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*** Public Interface (procedures) ***/
end_comment

begin_comment
comment|/* used by yyparse */
end_comment

begin_decl_stmt
name|void
name|finish_file
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|start_class
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
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
name|tree
name|continue_class
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|finish_class
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|start_method_def
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|continue_method_def
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|finish_method_def
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|start_protocol
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
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
name|finish_protocol
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_objc_decls
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|is_ivar
name|PROTO
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
name|int
name|is_private
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_public
name|PROTO
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
name|add_instance_variable
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
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
name|tree
name|add_class_method
name|PROTO
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
name|add_instance_method
name|PROTO
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
name|get_super_receiver
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|get_class_ivars
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|get_class_reference
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|get_static_reference
name|PROTO
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
name|get_object_reference
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|build_message_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|build_selector_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|build_ivar_reference
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|build_keyword_decl
name|PROTO
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
name|tree
name|build_method_decl
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
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
name|tree
name|build_protocol_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|build_objc_string_object
name|PROTO
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
name|objc_ivar_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|objc_method_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|objc_declare_alias
name|PROTO
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
name|void
name|objc_declare_class
name|PROTO
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
name|objc_receiver_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the following routines are used to implement statically typed objects */
end_comment

begin_decl_stmt
name|int
name|objc_comptypes
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|objc_check_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NeXT extensions */
end_comment

begin_decl_stmt
name|tree
name|build_encode_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Objective-C structures */
end_comment

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
value|((CLASS)->type.context)
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
name|TYPE_PROTOCOL_LIST
parameter_list|(
name|TYPE
parameter_list|)
value|((TYPE)->type.context)
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
ifdef|#
directive|ifdef
name|OBJCPLUS
name|dummy_tree_code
init|=
name|LAST_CPLUS_TREE_CODE
block|,
else|#
directive|else
name|dummy_tree_code
init|=
name|LAST_AND_UNUSED_TREE_CODE
block|,
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

end_unit

