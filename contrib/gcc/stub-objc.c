begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stub functions for Objective-C and Objective-C++ routines    that are called from within the C and C++ front-ends,    respectively.    Copyright (C) 1991, 1995, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_function
name|tree
name|objc_is_class_name
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|arg
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_is_id
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|arg
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_is_object_ptr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|arg
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 4133425 */
end_comment

begin_function
name|bool
name|objc_diagnose_private_ivar
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|arg
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4133425 */
end_comment

begin_function
name|tree
name|objc_lookup_ivar
parameter_list|(
name|tree
name|other
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|arg
parameter_list|)
parameter_list|)
block|{
comment|/* Just use whatever C/C++ found.  */
return|return
name|other
return|;
block|}
end_function

begin_function
name|void
name|objc_check_decl
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|decl
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 4281748 */
end_comment

begin_function
name|void
name|objc_check_global_decl
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|decl
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4281748 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4330422 */
end_comment

begin_function
name|tree
name|objc_non_volatilized_type
parameter_list|(
name|tree
name|type
parameter_list|)
block|{
return|return
name|type
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4330422 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4697411 */
end_comment

begin_function
name|void
name|objc_volatilize_component_ref
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|cref
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|type
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4697411 */
end_comment

begin_function
name|int
name|objc_is_reserved_word
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|ident
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL begin 4154928 */
end_comment

begin_function
name|tree
name|objc_common_type
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|type1
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|type2
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end 4154928 */
end_comment

begin_function
name|bool
name|objc_compare_types
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|ltyp
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|rtyp
parameter_list|)
parameter_list|,
comment|/* APPLE LOCAL begin radar 6231433 */
name|int
name|ARG_UNUSED
parameter_list|(
name|argno
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|callee
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
name|ARG_UNUSED
parameter_list|(
name|message
parameter_list|)
parameter_list|)
comment|/* APPLE LOCAL end radar 6231433 */
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 4229905 - radar 6231433 */
end_comment

begin_function
name|bool
name|objc_have_common_type
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|ltyp
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|rtyp
parameter_list|)
parameter_list|,
name|int
name|ARG_UNUSED
parameter_list|(
name|argno
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|callee
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
name|ARG_UNUSED
parameter_list|(
name|message
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4229905 - radar 6231433 */
end_comment

begin_function
name|void
name|objc_volatilize_decl
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|decl
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|bool
name|objc_type_quals_match
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|ltyp
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|rtyp
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|tree
name|objc_rewrite_function_call
parameter_list|(
name|tree
name|function
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|params
parameter_list|)
parameter_list|)
block|{
return|return
name|function
return|;
block|}
end_function

begin_function
name|tree
name|objc_message_selector
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|objc_declare_alias
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|alias
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|orig
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_declare_class
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|list
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
comment|/* APPLE LOCAL begin radar 4947311 - protocol attributes */
name|objc_declare_protocols
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|list
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|attributes
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_start_protocol
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|proto
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|protorefs
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|attributes
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4947311 - protocol attributes */
end_comment

begin_function
name|void
name|objc_start_class_interface
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|super
parameter_list|)
parameter_list|,
comment|/* APPLE LOCAL begin radar 4548636 */
name|tree
name|ARG_UNUSED
parameter_list|(
name|protos
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|attributes
parameter_list|)
parameter_list|)
comment|/* APPLE LOCAL end radar 4548636 */
block|{ }
end_function

begin_function
name|void
name|objc_start_category_interface
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|categ
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|protos
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_continue_interface
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_finish_interface
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_add_instance_variable
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|decl
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_set_visibility
parameter_list|(
name|int
name|ARG_UNUSED
parameter_list|(
name|vis
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_decl_stmt
name|void
name|objc_set_method_type
argument_list|(
expr|enum
name|tree_code
name|ARG_UNUSED
argument_list|(
name|code
argument_list|)
argument_list|)
block|{ }
end_decl_stmt

begin_function
name|void
name|objc_start_class_implementation
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|super
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_start_category_implementation
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|categ
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_continue_implementation
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_clear_super_receiver
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_finish_implementation
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
comment|/* APPLE LOCAL begin radar 3803157 - objc attribute */
name|objc_add_method_declaration
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|signature
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|attribute
parameter_list|)
parameter_list|)
comment|/* APPLE LOCAL end radar 3803157 - objc attribute */
block|{ }
end_function

begin_function
name|void
comment|/* APPLE LOCAL begin radar 3803157 - objc attribute */
name|objc_start_method_definition
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|signature
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|attribute
parameter_list|)
parameter_list|)
comment|/* APPLE LOCAL end radar 3803157 - objc attribute */
block|{ }
end_function

begin_function
name|void
name|objc_finish_method_definition
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|fndecl
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|tree
name|objc_build_keyword_decl
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|selector
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|typename
parameter_list|)
parameter_list|,
comment|/* APPLE LOCAL begin radar 4157812 */
name|tree
name|ARG_UNUSED
parameter_list|(
name|identifier
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|attribute
parameter_list|)
parameter_list|)
comment|/* APPLE LOCAL end radar 4157812 */
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_method_signature
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|rettype
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|selectors
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|optparms
parameter_list|)
parameter_list|,
name|bool
name|ARG_UNUSED
parameter_list|(
name|ellipsis
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_encode_expr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_protocol_expr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_selector_expr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_message_expr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_string_object
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|str
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_get_class_reference
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 4291785 */
end_comment

begin_function
name|tree
name|objc_get_interface_ivars
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|fieldlist
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|objc_detect_field_duplicates
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|fieldlist
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4291785 */
end_comment

begin_function
name|tree
name|objc_get_protocol_qualified_type
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|protos
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|objc_static_init_needed_p
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_generate_static_init_call
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|ctors
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|objc_is_public
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|identifier
parameter_list|)
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL begin C* language */
end_comment

begin_function
name|void
name|objc_set_method_opt
parameter_list|(
name|int
name|ARG_UNUSED
parameter_list|(
name|opt
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|tree
name|objc_build_component_ref
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|datum
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|component
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_foreach_components
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|receiver
parameter_list|)
parameter_list|,
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|enumState_decl
parameter_list|)
parameter_list|,
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|items_decl
parameter_list|)
parameter_list|,
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|limit_decl
parameter_list|)
parameter_list|,
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|startMutations_decl
parameter_list|)
parameter_list|,
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|counter_decl
parameter_list|)
parameter_list|,
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|countByEnumeratingWithState
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end C* language */
end_comment

begin_comment
comment|/* APPLE LOCAL begin C* property (Radar 4436866) */
end_comment

begin_function
name|void
name|objc_set_property_attr
parameter_list|(
name|int
name|ARG_UNUSED
parameter_list|(
name|code
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|identifier
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_add_property_variable
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|prop
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL radar 5285911 */
end_comment

begin_comment
comment|/* Stub for objc_build_getter_call is removed. */
end_comment

begin_function
name|tree
name|objc_build_setter_call
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|lhs
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|rhs
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end C* property (Radar 4436866) */
end_comment

begin_function
name|tree
name|objc_get_class_ivars
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_throw_stmt
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_build_synchronized
parameter_list|(
name|location_t
name|ARG_UNUSED
parameter_list|(
name|start_locus
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|body
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|objc_begin_try_stmt
parameter_list|(
name|location_t
name|ARG_UNUSED
parameter_list|(
name|try_locus
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|body
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_begin_catch_clause
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|decl
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_finish_catch_clause
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|objc_build_finally_clause
parameter_list|(
name|location_t
name|ARG_UNUSED
parameter_list|(
name|finally_locus
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|body
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|tree
name|objc_finish_try_stmt
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|tree
name|objc_generate_write_barrier
argument_list|(
name|tree
name|ARG_UNUSED
argument_list|(
name|lhs
argument_list|)
argument_list|,
expr|enum
name|tree_code
name|ARG_UNUSED
argument_list|(
name|modifycode
argument_list|)
argument_list|,
name|tree
name|ARG_UNUSED
argument_list|(
name|rhs
argument_list|)
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/* APPLE LOCAL begin radar 5276085 */
end_comment

begin_function
name|void
name|objc_weak_reference_expr
parameter_list|(
name|tree
modifier|*
name|ARG_UNUSED
parameter_list|(
name|expr
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_function
name|tree
name|objc_build_weak_reference_tree
parameter_list|(
name|tree
name|expr
parameter_list|)
block|{
return|return
name|expr
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 5276085 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin C* warnings to easy porting to new abi */
end_comment

begin_function
name|void
name|diagnose_selector_cast
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|cast_type
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|sel_exp
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL end C* warnings to easy porting to new abi */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4441049 */
end_comment

begin_function
name|tree
name|objc_v2_component_ref_field_offset
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|exp
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_v2_bitfield_ivar_bitpos
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|exp
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4441049 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4507230 */
end_comment

begin_function
name|bool
name|objc_type_valid_for_messaging
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|exp
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4507230 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 3803157 - objc attribute */
end_comment

begin_decl_stmt
name|bool
name|objc_method_decl
argument_list|(
expr|enum
name|tree_code
name|ARG_UNUSED
argument_list|(
name|opcode
argument_list|)
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/* APPLE LOCAL end radar 3803157 - objc attribute */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4708210 (for_objc_collection in 4.2) */
end_comment

begin_function
name|void
name|objc_finish_foreach_loop
parameter_list|(
name|location_t
name|ARG_UNUSED
parameter_list|(
name|location
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|cond
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|for_body
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|blab
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|clab
parameter_list|)
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4708210 (for_objc_collection in 4.2) */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 5847976 */
end_comment

begin_function
name|int
name|objc_is_gcable_type
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|type
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 5847976 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4592503 */
end_comment

begin_function
name|void
name|objc_checkon_weak_attribute
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|decl
parameter_list|)
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 4592503 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4712269 */
end_comment

begin_decl_stmt
name|tree
name|objc_build_incr_decr_setter_call
argument_list|(
expr|enum
name|tree_code
name|ARG_UNUSED
argument_list|(
name|code
argument_list|)
argument_list|,
name|tree
name|ARG_UNUSED
argument_list|(
name|lhs
argument_list|)
argument_list|,
name|tree
name|ARG_UNUSED
argument_list|(
name|inc
argument_list|)
argument_list|)
block|{
return|return
name|NULL_TREE
return|;
block|}
end_decl_stmt

begin_comment
comment|/* APPLE LOCAL end radar 4712269 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin objc new property */
end_comment

begin_function
name|void
name|objc_declare_property_impl
parameter_list|(
name|int
name|ARG_UNUSED
parameter_list|(
name|code
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|tree_list
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 5285911 */
end_comment

begin_function
name|tree
name|objc_build_property_reference_expr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|datum
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|component
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|bool
name|objc_property_reference_expr
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|exp
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 5285911 */
end_comment

begin_comment
comment|/* APPLE LOCAL end objc new property */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 4985544 */
end_comment

begin_decl_stmt
name|bool
name|objc_check_format_nsstring
argument_list|(
name|tree
name|ARG_UNUSED
argument_list|(
name|argument
argument_list|)
argument_list|,
name|unsigned
name|HOST_WIDE_INT
name|ARG_UNUSED
argument_list|(
name|format_num
argument_list|)
argument_list|,
name|bool
operator|*
name|ARG_UNUSED
argument_list|(
name|no_add_attrs
argument_list|)
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/* APPLE LOCAL end radar 4985544 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 5202926 */
end_comment

begin_function
name|bool
name|objc_anonymous_local_objc_name
parameter_list|(
specifier|const
name|char
modifier|*
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 5195402 */
end_comment

begin_function
name|bool
name|objc_check_nsstring_pointer_type
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|type
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 5195402 */
end_comment

begin_comment
comment|/* APPLE LOCAL end radar 5202926 */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 5782740 - blocks */
end_comment

begin_function
name|bool
name|block_requires_copying
parameter_list|(
name|tree
name|exp
parameter_list|)
block|{
comment|/* APPLE LOCAL begin radar 6175959 */
name|tree
name|type
init|=
name|TREE_TYPE
argument_list|(
name|exp
argument_list|)
decl_stmt|;
return|return
name|TREE_CODE
argument_list|(
name|type
argument_list|)
operator|==
name|BLOCK_POINTER_TYPE
operator|||
operator|(
name|POINTER_TYPE_P
argument_list|(
name|type
argument_list|)
operator|&&
name|lookup_attribute
argument_list|(
literal|"NSObject"
argument_list|,
name|TYPE_ATTRIBUTES
argument_list|(
name|type
argument_list|)
argument_list|)
operator|)
return|;
comment|/* APPLE LOCAL end radar 6175959 */
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 5782740 - blocks */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 5802025 */
end_comment

begin_function
name|tree
name|objc_build_property_getter_func_call
parameter_list|(
name|tree
name|object
parameter_list|)
block|{
return|return
name|object
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 5802025 */
end_comment

end_unit

