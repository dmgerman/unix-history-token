begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for objc-actions.c.    Copyright (C) 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*** Public Interface (procedures) ***/
end_comment

begin_comment
comment|/* used by compile_file */
end_comment

begin_decl_stmt
name|void
name|init_objc
argument_list|()
decl_stmt|,
name|finish_objc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by yyparse */
end_comment

begin_function_decl
name|tree
name|start_class
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|continue_class
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_class
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_method_def
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|continue_method_def
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_method_def
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_objc_decls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|is_ivar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_public
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|add_instance_variable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|add_class_method
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|add_instance_method
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_super_receiver
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_class_ivars
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_class_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_static_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_message_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_selector_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_ivar_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_keyword_decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_method_decl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero enables objc features.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doing_objc_thang
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the following routines are used to implement statically typed objects */
end_comment

begin_function_decl
name|tree
name|lookup_interface
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_comptypes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_check_decl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* NeXT extensions */
end_comment

begin_function_decl
name|tree
name|build_encode_expr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* used by rest_of_compilation.  */
end_comment

begin_function_decl
name|void
name|genPrototype
parameter_list|()
function_decl|;
end_function_decl

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
comment|/* INTERFACE_TYPE, IMPLEMENTATION_TYPE, CATEGORY_TYPE */
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
value|((CLASS)->type.binfo)
end_define

begin_define
define|#
directive|define
name|CLASS_IVARS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.maxval)
end_define

begin_define
define|#
directive|define
name|CLASS_RAW_IVARS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.noncopied_parts)
end_define

begin_define
define|#
directive|define
name|CLASS_NST_METHODS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.next_variant)
end_define

begin_define
define|#
directive|define
name|CLASS_CLS_METHODS
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.main_variant)
end_define

begin_define
define|#
directive|define
name|CLASS_STATIC_TEMPLATE
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.context)
end_define

begin_define
define|#
directive|define
name|CLASS_CATEGORY_LIST
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS)->type.minval)
end_define

begin_comment
comment|/* Define the Objective-C language-specific tree codes.  */
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
name|dummy_tree_code
init|=
name|LAST_AND_UNUSED_TREE_CODE
block|,
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

