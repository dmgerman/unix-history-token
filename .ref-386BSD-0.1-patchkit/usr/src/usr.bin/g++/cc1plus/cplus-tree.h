begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  *  *	@(#)cplus-tree.h	6.4 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Definitions for C++ parsing and type checking.    Copyright (C) 1987 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@mcc.com)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* Borrow everything that is C from c-tree.h,    but do so by copy, not by inclusion, since c-tree.h defines    lang_identifier.  */
end_comment

begin_comment
comment|/* Definitions for C parsing and type checking.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Language-dependent contents of an identifier.  */
end_comment

begin_struct
struct|struct
name|lang_identifier
block|{
name|struct
name|tree_identifier
name|ignore
decl_stmt|;
name|tree
name|global_value
decl_stmt|,
name|local_value
decl_stmt|;
name|tree
name|class_value
decl_stmt|;
name|struct
name|lang_id2
modifier|*
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lang_id2
block|{
name|tree
name|label_value
decl_stmt|,
name|implicit_decl
decl_stmt|;
name|tree
name|error_locus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macros for access to language-specific slots in an identifier.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_GLOBAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->global_value)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_CLASS_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->class_value)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_LOCAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->local_value)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_AS_LIST
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((tree)((struct lang_identifier *)(NODE))->x)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_AS_LIST
parameter_list|(
name|NODE
parameter_list|,
name|LIST
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x = (struct lang_id2*)(LIST))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->label_value : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)permalloc (sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->label_value = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->implicit_decl : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)permalloc (sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->implicit_decl = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->error_locus : 0)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->x == 0 ? ((struct lang_identifier *)(NODE))->x = (struct lang_id2 *)permalloc (sizeof (struct lang_id2)) : 0, \    ((struct lang_identifier *)(NODE))->x->error_locus = (VALUE))
end_define

begin_comment
comment|/* Nonzero means reject anything that ANSI standard C forbids.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pedantic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_READONLY
parameter_list|(
name|type
parameter_list|)
value|TYPE_SEP_UNIT (type)
end_define

begin_comment
comment|/* in c-typeck.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref
argument_list|()
decl_stmt|,
name|build_conditional_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_compound_expr
argument_list|()
decl_stmt|,
name|build_compound_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_unary_op
argument_list|()
decl_stmt|,
name|build_binary_op
argument_list|()
decl_stmt|,
name|build_function_call
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_binary_op_nodefault
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_indirect_ref
argument_list|()
decl_stmt|,
name|build_array_ref
argument_list|()
decl_stmt|,
name|build_c_cast
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_modify_expr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|c_sizeof
argument_list|()
decl_stmt|,
name|c_alignof
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|store_init_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|digest_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_expand_start_case
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|default_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given two integer or real types, return the type for their sum.    Given two compatible ANSI C types, returns the merged type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|commontype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in c-decl.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_label
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* If non-zero, a VAR_DECL whose cleanup will cause a throw to the    next exception handler.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|exception_throw_decl
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|start_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_parm_decls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_parm_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushlevel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|poplevel
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|groktypename
argument_list|()
decl_stmt|,
name|lookup_name
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_label
argument_list|()
decl_stmt|,
name|define_label
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|implicitly_declare
argument_list|()
decl_stmt|,
name|getdecls
argument_list|()
decl_stmt|,
name|gettags
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|start_decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_decl
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|start_struct
argument_list|()
decl_stmt|,
name|finish_struct
argument_list|()
decl_stmt|,
name|xref_tag
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|finish_exception
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|grokfield
argument_list|()
decl_stmt|,
name|grokbitfield
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_enum
argument_list|()
decl_stmt|,
name|finish_enum
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_enumerator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_index_type
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|double_type_node
decl_stmt|,
name|long_double_type_node
decl_stmt|,
name|float_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|char_type_node
decl_stmt|,
name|unsigned_char_type_node
decl_stmt|,
name|signed_char_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|short_integer_type_node
decl_stmt|,
name|short_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_integer_type_node
decl_stmt|,
name|long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|,
name|long_long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|string_type_node
decl_stmt|,
name|char_array_type_node
decl_stmt|,
name|int_array_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ridpointers
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means `$' can be in an identifier.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dollars_in_ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means allow type mismatches in conditional expressions;    just make their values `void'.   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cond_mismatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't recognize the keyword `asm'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_asm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about implicit declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_implicit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about function definitions that default the return type    or that use a null return and have a return-type other than void.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_return_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means give string constants the type `const char *'    to get extra warnings from them.  These warnings will be too numerous    to be useful, except in thoroughly ANSIfied programs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_write_strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about sizeof(function) or addition/subtraction    of function pointers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_pointer_arith
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn for all old-style non-prototype function decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_strict_prototypes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about pointer casts that can drop a type qualifier    from the pointer target type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_cast_qual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means do some things the same way PCC does.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_traditional
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2 means write out only specific virtual function tables    and give them (C) public visibility.    1 means write out virtual function tables and give them    (C) public visibility.    0 means write out virtual function tables and give them    (C) static visibility.    -1 means declare virtual function tables extern.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write_virtuals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that we are in an "interface" section of the compiler.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interface_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we should attempt to elide constructors when possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_elide_constructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means if the type has methods, only output debugging    information if methods are actually written to the asm file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_minimal_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means recognize and handle exception handling constructs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_handle_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that member functions defined in class scope are    inline by default.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_default_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means recognize and handle exception handling constructs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means emit cadillac protocol.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cadillac
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CADILLAC
end_ifndef

begin_define
define|#
directive|define
name|cadillac_finish_anon_union
parameter_list|(
name|decl
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_finish_decl
parameter_list|(
name|decl
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_finish_enum
parameter_list|(
name|enumtype
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_finish_exception
parameter_list|(
name|e
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_finish_function
parameter_list|(
name|fndecl
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_finish_stmt
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_finish_struct
parameter_list|(
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_note_source
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_pop_class
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_pop_lang
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_pop_source
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_push_class
parameter_list|(
name|type
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_push_lang
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_push_source
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_start
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cadillac_start_decl
parameter_list|(
name|value
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_start_enum
parameter_list|(
name|ref
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_start_function
parameter_list|(
name|decl1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_start_struct
parameter_list|(
name|ref
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cadillac_switch_source
parameter_list|(
name|flag
parameter_list|)
end_define

begin_define
define|#
directive|define
name|init_cadillac
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* C++ language-specific tree codes.  */
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
name|cplus_tree_code
block|{
name|__DUMMY
init|=
name|LAST_AND_UNUSED_TREE_CODE
block|,
include|#
directive|include
file|"cplus-tree.def"
name|LAST_CPLUS_TREE_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_enum
enum|enum
name|languages
block|{
name|lang_c
block|,
name|lang_cplusplus
block|}
enum|;
end_enum

begin_comment
comment|/* Macros to make error reporting functions' lives easier.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NAME_STRING
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_POINTER (DECL_NAME (TYPE_NAME (NODE))))
end_define

begin_define
define|#
directive|define
name|TYPE_NAME_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_LENGTH (DECL_NAME (TYPE_NAME (NODE))))
end_define

begin_comment
comment|/* Virtual function addresses can be gotten from a virtual function    table entry using this macro.  */
end_comment

begin_define
define|#
directive|define
name|FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|)
define|\
value|TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY))))
end_define

begin_escape
end_escape

begin_enum
enum|enum
name|conversion_type
block|{
name|ptr_conv
block|,
name|constptr_conv
block|,
name|int_conv
block|,
name|real_conv
block|,
name|last_conversion_type
block|}
enum|;
end_enum

begin_comment
comment|/* Statistics show that while the GNU C++ compiler may generate    thousands of different types during a compilation run, it    generates relatively few (tens) of classtypes.  Because of this,    it is not costly to store a generous amount of information    in classtype nodes.  */
end_comment

begin_struct
struct|struct
name|lang_type
block|{
comment|/* This must fill out to a multiple of 4 bytes.  */
struct|struct
block|{
name|unsigned
name|has_type_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_int_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_float_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_init_aggr
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_assignment
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_assignment
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_new
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_delete
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_wrapper_pred
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_method_call_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_call_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_array_ref_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|any_assigns_this
range|:
literal|1
decl_stmt|;
name|unsigned
name|none_assign_this
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked2
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked3
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked4
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked5
range|:
literal|1
decl_stmt|;
name|unsigned
name|marked6
range|:
literal|1
decl_stmt|;
name|unsigned
name|virtual_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|needs_constructor
range|:
literal|1
decl_stmt|;
name|unsigned
name|declared_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|private_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|const_needs_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|ref_needs_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|uses_virtual_base_classes
range|:
literal|1
decl_stmt|;
name|unsigned
name|uses_multiple_inheritance
range|:
literal|1
decl_stmt|;
name|unsigned
name|got_semicolon
range|:
literal|1
decl_stmt|;
name|unsigned
name|alters_visibilities
range|:
literal|1
decl_stmt|;
name|unsigned
name|needs_virtual_reinit
range|:
literal|1
decl_stmt|;
name|unsigned
name|asm_written
range|:
literal|1
decl_stmt|;
name|unsigned
name|declared_exception
range|:
literal|1
decl_stmt|;
name|unsigned
name|vtable_needs_writing
range|:
literal|1
decl_stmt|;
name|unsigned
name|local_typedecls
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_const_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|dynamic
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_default_ctor
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_const_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_const_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|interface_only
range|:
literal|1
decl_stmt|;
name|unsigned
name|interface_unknown
range|:
literal|1
decl_stmt|;
name|unsigned
name|dummy3
range|:
literal|2
decl_stmt|;
block|}
name|type_flags
struct|;
name|unsigned
name|n_parents
range|:
literal|16
decl_stmt|;
name|int
name|cid
decl_stmt|;
name|int
name|n_ancestors
decl_stmt|;
name|int
name|n_vancestors
decl_stmt|;
name|int
name|vsize
decl_stmt|;
name|union
name|tree_node
modifier|*
name|method_vec
decl_stmt|,
modifier|*
name|baselink_vec
decl_stmt|;
name|union
name|tree_node
modifier|*
name|offset
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vfield
decl_stmt|,
modifier|*
name|vfields
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbases
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbase_size
decl_stmt|;
name|union
name|tree_node
modifier|*
name|tags
decl_stmt|;
name|union
name|tree_node
modifier|*
name|main_class_variant
decl_stmt|;
name|union
name|tree_node
modifier|*
name|this_class_variant
decl_stmt|;
name|union
name|tree_node
modifier|*
name|next_class_variant
decl_stmt|;
name|void
modifier|*
name|memoized_table_entry
decl_stmt|;
name|unsigned
name|char
modifier|*
name|via_pub_or_virt
decl_stmt|;
name|union
name|tree_node
modifier|*
modifier|*
name|types
decl_stmt|;
name|void
modifier|*
name|search_slot
decl_stmt|;
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
name|unsigned
name|char
name|size_unit
decl_stmt|;
name|unsigned
name|char
name|align
decl_stmt|;
name|unsigned
name|char
name|sep_unit
decl_stmt|;
name|union
name|tree_node
modifier|*
name|sep
decl_stmt|;
name|union
name|tree_node
modifier|*
name|size
decl_stmt|;
name|union
name|tree_node
modifier|*
name|base_init_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|abstract_virtuals
decl_stmt|;
name|union
name|tree_node
modifier|*
name|as_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|as_id_list
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vtbl_ptr
decl_stmt|;
name|union
name|tree_node
modifier|*
name|instance_variable
decl_stmt|;
name|union
name|tree_node
modifier|*
name|friend_classes
decl_stmt|;
name|char
modifier|*
name|mi_matrix
decl_stmt|;
name|union
name|tree_node
modifier|*
name|conversions
index|[
name|last_conversion_type
index|]
decl_stmt|;
name|union
name|tree_node
modifier|*
name|wrap_type
decl_stmt|;
ifdef|#
directive|ifdef
name|SOS
name|union
name|tree_node
modifier|*
name|typename_as_string
decl_stmt|;
name|union
name|tree_node
modifier|*
name|dynamic_filename
decl_stmt|;
name|union
name|tree_node
modifier|*
name|dynamic_table
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Fields used for storing information before the class is defined.    After the class is defined, these fields hold other information.  */
end_comment

begin_comment
comment|/* List of friends which were defined inline in this class definition.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INLINE_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_NONCOPIED_PARTS (NODE))
end_define

begin_comment
comment|/* Nonzero for _CLASSTYPE means that the _CLASSTYPE either has    a special meaning for the assignment operator ("operator="),    or one of its fields (or base members) has a special meaning    defined.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_ASSIGNMENT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_assignment)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_ASSIGNMENT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_assignment)
end_define

begin_comment
comment|/* Nonzero for _CLASSTYPE means that operator new and delete are defined,    respectively.  */
end_comment

begin_define
define|#
directive|define
name|TREE_GETS_NEW
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_new)
end_define

begin_define
define|#
directive|define
name|TREE_GETS_DELETE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_delete)
end_define

begin_comment
comment|/* Nonzero for TREE_LIST or _CLASSTYPE node means that the path to the    base class is via a `public' declaration, which preserves public    fields from the base class as public.    OVERLOADED.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.used_attr)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* Nonzero for TREE_LIST node means that the path to the    base class is via a `protected' declaration, which preserves    protected fields from the base class as protected.    OVERLOADED.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_PROTECTED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.literal_attr)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* Nonzero for a _CLASSTYPE node which we know to be private.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PRIVATE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.private_attr)
end_define

begin_comment
comment|/* Nonzero for a _CLASSTYPE node means that the derivation chain is via    a `virtual' declaration.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_VIRTUAL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.literal_attr)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node defines ways of converting    itself to other types.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_type_conversion)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node can convert itself to an    INTEGER_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_INT_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_int_conversion)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node can convert itself to an    REAL_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_REAL_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_float_conversion)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator=(X&).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_const_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_const_assign_ref)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node has an X(X&) constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_CONST_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_const_init_ref)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node has an X(X ...) constructor.    Note that there must be other arguments, or this constructor is flaged    as being erroneous.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_GETS_INIT_AGGR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_init_aggr)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads the method call    operator.  In this case, all method calls go through `operator->()(...).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_METHOD_CALL_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_method_call_overloaded)
end_define

begin_define
define|#
directive|define
name|TYPE_WRAP_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->wrap_type)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_WRAPPER
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->wrap_type == TYPE_MAIN_VARIANT (NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_NEEDS_WRAPPER
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->wrap_type != 0&& TYPE_LANG_SPECIFIC(NODE)->wrap_type != TYPE_MAIN_VARIANT (NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_WRAPPER_PRED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_wrapper_pred)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator().  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_CALL_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_call_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator[].  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_ARRAY_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_array_ref_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses    multiple inheritance.  If this is 0 for the root of a type    hierarchy, then we can use more efficient search techniques.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_MULTIPLE_INHERITANCE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.uses_multiple_inheritance)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses    virtual base classes.  If this is 0 for the root of a type    hierarchy, then we can use more efficient search techniques.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_VIRTUAL_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.uses_virtual_base_classes)
end_define

begin_comment
comment|/* List of lists of member functions defined in this class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_METHOD_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->method_vec)
end_define

begin_comment
comment|/* Pointer from any member function to the head of the list of    member functions of the type that member function belongs to.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BASELINK_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->baselink_vec)
end_define

begin_comment
comment|/* Nonzero if the Nth baseclass of this class is via `public'.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VIA_PUBLIC
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->via_pub_or_virt[N]&1)
end_define

begin_comment
comment|/* Nonzero if the Nth baseclass of this class is via `virtual'.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VIA_VIRTUAL
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
value|((TYPE_LANG_SPECIFIC(NODE)->via_pub_or_virt[N]&2)>>1)
end_define

begin_comment
comment|/* Accessor macros for the above two constructs.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VIAS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->via_pub_or_virt)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_VIAS
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|,
name|PUB
parameter_list|,
name|VIRT
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->via_pub_or_virt[N] = (PUB|(VIRT<<1)))
end_define

begin_comment
comment|/* Mark bits for depth-first and breath-first searches.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked2)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked3)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked4)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked5)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.marked6)
end_define

begin_comment
comment|/* When building a matrix to determine by a single lookup    whether one class is derived from another or not,    this field is the index of the class in the table.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CID
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(TYPE_MAIN_VARIANT (NODE))->cid)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_TAGS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->tags)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_NAMES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->names)
end_define

begin_comment
comment|/* When a class becomes a non-leftmost baseclass in a multiple    inheritance hierarchy, the number of bytes that subobjects    of this type are offset from the begining of the containing record.    This is an INTEGER_CST which holds the value of    DECL_OFFSET (TYPE_NAME (NODE)).     Note that for virtual base classes, the offset is only meaningful    for the construction and initialization of virtual baseclass pointers    and virtual function table entries.  Otherwise, the offset of a    virtual baseclass is irrelevant, since it is accessed through a    pointer, and not via a delta.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->offset)
end_define

begin_comment
comment|/* The virtual function table pointer field.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELD
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vfield)
end_define

begin_comment
comment|/* The number of virtual functions defined for this    _CLASSTYPE node.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VSIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vsize)
end_define

begin_comment
comment|/* The virtual base classes that this type uses.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vbases)
end_define

begin_comment
comment|/* The virtual function pointer fields that this type contains.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vfields)
end_define

begin_comment
comment|/* Number of baseclasses defined for this type.    0 means no base classes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_N_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->n_parents)
end_define

begin_comment
comment|/* Vector of base classes for this type.  This vector is    indexed starting at 1.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->types)
end_define

begin_comment
comment|/* Accessor macro for the Nth baseclass of type NODE.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BASECLASS
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->types[N])
end_define

begin_comment
comment|/* Memoize the number of super classes (base classes) tha this node    has.  That way we can know immediately (albeit conservatively how    large a multiple-inheritance matrix we need to build to find    derivation information.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_N_SUPERCLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->n_ancestors)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_N_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->n_vancestors)
end_define

begin_comment
comment|/* Used for keeping search-specific information.  Any search routine    which uses this must define what exactly this slot is used for.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SEARCH_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->search_slot)
end_define

begin_comment
comment|/* The canonical form of this base class.  It also happens to be    TYPE_MAIN_VARIANT.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MAIN_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->main_class_variant)
end_define

begin_comment
comment|/* For baseclasses with non-zero valued offsets, a chain of    such versions of this baseclass.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NEXT_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->next_class_variant)
end_define

begin_comment
comment|/* Entry for keeping memoization tables for this type to    hopefully speed up search routines.  Since it is a pointer,    it can mean almost anything.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MTABLE_ENTRY
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->memoized_table_entry)
end_define

begin_comment
comment|/* This is the total size of the baseclasses defined for this type.    Needed because it is desirable to layout such information    before begining to process the class itself, and we    don't want to compute it second time when actually laying    out the type for real.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->size)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->size_unit)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MODE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->mode)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->align)
end_define

begin_comment
comment|/* This is the space needed for virtual base classes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vbase_size)
end_define

begin_comment
comment|/* A cons list of structure elements which either have constructors    to be called, or virtual function table pointers which    need initializing.  Depending on what is being initialized,    the TREE_PURPOSE and TREE_VALUE fields have different meanings:     Member initialization:<FIELD_DECL, TYPE>    Base class construction:<NULL_TREE, BASETYPE>    Base class initialization:<BASE_INITIALIZAION, THESE_INITIALIZATIONS>    Whole type:<MEMBER_INIT, BASE_INIT>.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BASE_INIT_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->base_init_list)
end_define

begin_comment
comment|/* A cons list of virtual functions which cannot be inherited by    derived classes.  When deriving from this type, the derived    class must provide its own definition for each of these functions.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_ABSTRACT_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->abstract_virtuals)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALTERS_VISIBILITIES_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.alters_visibilities)
end_define

begin_comment
comment|/* Nonzero means that this aggr type has been `closed' by a semicolon.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_GOT_SEMICOLON
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->type_flags.got_semicolon)
end_define

begin_comment
comment|/* Nonzero means that the main virtual function table pointer needs to be    set because base constructors have placed the wrong value there.    If this is zero, it means that they placed the right value there,    and there is no need to change it.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NEEDS_VIRTUAL_REINIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.needs_virtual_reinit)
end_define

begin_comment
comment|/* Nonzero means that a member function has actually been output for    this type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_ASM_WRITTEN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.asm_written)
end_define

begin_comment
comment|/* Nonzero means that if this type has virtual functions, that    the virtual function table will be written out.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VTABLE_NEEDS_WRITING
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.vtable_needs_writing)
end_define

begin_comment
comment|/* Nonzero means that this type defines its own local type declarations.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_LOCAL_TYPEDECLS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.local_typedecls)
end_define

begin_comment
comment|/* Nonzero means that this type has an X() constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_DEFAULT_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_default_ctor)
end_define

begin_comment
comment|/* Many routines need to cons up a list of basetypes for visibility    checking.  This field contains a TREE_LIST node whose TREE_VALUE    is the main variant of the type, and whose TREE_VIA_PUBLIC    and TREE_VIA_VIRTUAL bits are correctly set.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_AS_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->as_list)
end_define

begin_comment
comment|/* Same, but cache a list whose value is the name of this type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_AS_ID_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->as_id_list)
end_define

begin_comment
comment|/* Slot in which to cache a copy of the local vtable pointer.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VTBL_PTR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vtbl_ptr)
end_define

begin_comment
comment|/* Hold the instance object associated with this method.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INST_VAR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->instance_variable)
end_define

begin_comment
comment|/* A list of class types with which this type is a friend.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_FRIEND_CLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->friend_classes)
end_define

begin_comment
comment|/* Keep an inheritance lattice around so we can quickly tell whether    a type is derived from another or not.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MI_MATRIX
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->mi_matrix)
end_define

begin_comment
comment|/* If there is exactly one conversion to a non-void, non-const pointer type,    remember that here.  If there are more than one, put    `error_mark_node' here.  If there are none, this holds NULL_TREE.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CONVERSION
parameter_list|(
name|NODE
parameter_list|,
name|KIND
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->conversions[KIND])
end_define

begin_comment
comment|/* Nonzero means that class is "dynamic" in SOS sense.  (IRIA-specific.)  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DYNAMIC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.dynamic)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_comment
comment|/* The name of this type as a STRING.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TYPENAME_AS_STRING
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->typename_as_string)
end_define

begin_comment
comment|/* The name of the file which defines this type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DYNAMIC_FILENAME
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->dynamic_filename)
end_define

begin_comment
comment|/* The table of all member functions, linearized.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DYNAMIC_TABLE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->dynamic_table)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Say whether this node was declared as a "class" or a "struct".  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DECLARED_CLASS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.declared_class)
end_define

begin_comment
comment|/* Say whether this node was declared as a "class" or a "struct".  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DECLARED_EXCEPTION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.declared_exception)
end_define

begin_comment
comment|/* Nonzero if this class has const members which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_READONLY_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.const_needs_init)
end_define

begin_comment
comment|/* Nonzero if this class has ref members which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_REF_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.ref_needs_init)
end_define

begin_comment
comment|/* Nonzero if this class is included from a header file which employs    `#pragma interface', and it is not included in its implementation file.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_ONLY
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_only)
end_define

begin_comment
comment|/* Same as above, but for classes whose purpose we do not know.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown)
end_define

begin_escape
end_escape

begin_comment
comment|/* Depending on a class's "owner" they may have different properties,    such as the offset which must be added to `this', and the    virtual function table with which they are initialized.  This is    managed by an association list of type TREE_LIST.  This is    the interfact to the association list.  */
end_comment

begin_comment
comment|/* The class's virtual function table.  */
end_comment

begin_define
define|#
directive|define
name|ASSOC_VTABLE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 2)
end_define

begin_define
define|#
directive|define
name|CLASS_ASSOC_VTABLE
parameter_list|(
name|NODE
parameter_list|)
value|ASSOC_VTABLE (TYPE_BASETYPES (NODE))
end_define

begin_comment
comment|/* The virtual functions in the virtual function table.  */
end_comment

begin_define
define|#
directive|define
name|ASSOC_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 3)
end_define

begin_define
define|#
directive|define
name|CLASS_ASSOC_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|ASSOC_VIRTUALS (TYPE_BASETYPES (NODE))
end_define

begin_comment
comment|/* The class's offset to be added to `this'.  */
end_comment

begin_define
define|#
directive|define
name|ASSOC_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 1)
end_define

begin_define
define|#
directive|define
name|CLASS_ASSOC_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|ASSOC_OFFSET (TYPE_BASETYPES (NODE))
end_define

begin_comment
comment|/* The association key.  */
end_comment

begin_define
define|#
directive|define
name|ASSOC_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 0)
end_define

begin_comment
comment|/* And its specific value.  */
end_comment

begin_define
define|#
directive|define
name|ASSOC_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (NODE)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ASSOC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_BASETYPES (NODE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Nonzero for TREE_LIST node means that this list of things    is a list of parameters, as opposed to a list of expressions.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PARMLIST
parameter_list|(
name|NODE
parameter_list|)
value|TREE_UNSIGNED (NODE)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* Nonzero for FIELD_DECL node means that this FIELD_DECL is    a member of an anonymous union construct.  The name of the    union is .  */
end_comment

begin_define
define|#
directive|define
name|TREE_ANON_UNION_ELEM
parameter_list|(
name|NODE
parameter_list|)
value|TREE_REGDECL (NODE)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* For FUNCTION_TYPE or METHOD_TYPE, a list of the exceptions that    this type can raise.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_RAISES_EXCEPTIONS
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_NONCOPIED_PARTS (NODE)
end_define

begin_escape
end_escape

begin_struct
struct|struct
name|lang_decl_flags
block|{
name|enum
name|languages
name|language
range|:
literal|8
decl_stmt|;
name|unsigned
name|this_private
range|:
literal|1
decl_stmt|;
name|unsigned
name|this_protected
range|:
literal|1
decl_stmt|;
name|unsigned
name|this_public
range|:
literal|1
decl_stmt|;
name|unsigned
name|operator_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|overloaded_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|constructor_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|returns_first_arg
range|:
literal|1
decl_stmt|;
name|unsigned
name|preserves_first_arg
range|:
literal|1
decl_stmt|;
name|unsigned
name|in_aggr
range|:
literal|1
decl_stmt|;
name|unsigned
name|friend_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|static_function
range|:
literal|1
decl_stmt|;
name|unsigned
name|const_memfunc
range|:
literal|1
decl_stmt|;
name|unsigned
name|volatile_memfunc
range|:
literal|1
decl_stmt|;
name|unsigned
name|abstract_virtual
range|:
literal|1
decl_stmt|;
name|unsigned
name|compiler_generated
range|:
literal|1
decl_stmt|;
name|unsigned
name|permanent_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|constructor_for_vbase_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|dummy7
range|:
literal|7
decl_stmt|;
name|tree
name|visibility
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lang_decl
block|{
name|struct
name|lang_decl_flags
name|decl_flags
decl_stmt|;
name|tree
name|original_name
decl_stmt|;
name|tree
name|vindex
decl_stmt|;
name|tree
name|vcontext
decl_stmt|;
name|tree
name|main_decl_variant
decl_stmt|;
name|struct
name|pending_inline
modifier|*
name|pending_inline_info
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbase_init_list
decl_stmt|;
ifdef|#
directive|ifdef
name|SOS
name|tree
name|dynamic_index
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Non-zero if NODE is a _DECL with TREE_READONLY set.  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_READONLY (NODE)&& *(tree_code_type[TREE_CODE (NODE)]) == 'd')
end_define

begin_comment
comment|/* For FUNCTION_DECLs: return the language in which this decl    was declared.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANGUAGE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.language)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_attr)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a constructor    for an object with virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_FOR_VBASE_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_for_vbase_attr)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that the constructor    is known to return a non-zero `this' unchanged.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RETURNS_FIRST_ARG
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.returns_first_arg)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this constructor is known to    not make any assignment to `this', and therefore can be trusted    to return it unchanged.  Otherwise, we must re-assign `current_class_decl'    after performing base initializations.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PRESERVES_THIS
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.preserves_first_arg)
end_define

begin_comment
comment|/* Nonzero for _DECL means that this decl appears in (or will appear    in) as a member in a RECORD_TYPE or UNION_TYPE node.  It is also for    detecting circularity in case members are multiply defined.  In the    case of a VAR_DECL, it is also used to determince how program storage    should be allocated.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_AGGR_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.in_aggr)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is just a    friend declaration, and should not be added to the list of    member functions for this class.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIEND_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.friend_attr)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is a static    member function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STATIC_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.static_function)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    has `this' as const X *const.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONST_MEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.const_memfunc)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    has `this' as volatile X *const.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VOLATILE_MEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.volatile_memfunc)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    exists only as part of an abstract class's interface.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ABSTRACT_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.abstract_virtual)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    was generated by the compiler.  This helps us give better    error messages.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COMPILER_GENERATED_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.compiler_generated)
end_define

begin_comment
comment|/* Nonzero if allocated on permanent_obstack.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* @@ Not currently used.  */
end_comment

begin_define
define|#
directive|define
name|LANG_DECL_PERMANENT
parameter_list|(
name|LANGDECL
parameter_list|)
value|((LANGDECL)->decl_flags.permanent_attr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero for FIELD_DECL node means that this FIELD_DECL is    a member of an anonymous union construct.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ANON_UNION_ELEM
parameter_list|(
name|NODE
parameter_list|)
value|TREE_REGDECL (NODE)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* For a FUNCTION_DECL: the name of the function before being overloaded.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ORIGINAL_NAME
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->original_name)
end_define

begin_comment
comment|/* Points back to the decl which caused this lang_decl to be allocated.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAIN_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->main_decl_variant)
end_define

begin_comment
comment|/* For a FUNCTION_DECL: if this function was declared inline inside of    a class declaration, this is where the text for the function is    squirreled away.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PENDING_INLINE_INFO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->pending_inline_info)
end_define

begin_comment
comment|/* Holds information about how virtual base classes should be initialized    by this constructor *if* this constructor is the one to perform    such initialization.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VBASE_INIT_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->vbase_init_list)
end_define

begin_comment
comment|/* Nonzero in INT_CST means that this int is negative by dint of    using a twos-complement negated operand.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NEGATED_INT
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
end_define

begin_comment
comment|/* Nonzero in any kind of _EXPR or _REF node means that it is a call    to a storage allocation routine.  If, later, alternate storage    is found to hold the object, this call can be ignored.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CALLS_NEW
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2 (NODE))
end_define

begin_comment
comment|/* Nonzero in IDENTIFIER_NODE means that this name is overloaded, and    should be looked up in a non-standard way.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OVERLOADED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
end_define

begin_define
define|#
directive|define
name|DECL_OVERLOADED
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.overloaded_attr)
end_define

begin_comment
comment|/* Nonzero if this (non-TYPE)_DECL has its virtual attribute set.    For a FUNCTION_DECL, this is when the function is a virtual function.    For a VAR_DECL, this is when the variable is a virtual function table.    For a FIELD_DECL, when the field is the field for the virtual function table.    For an IDENTIFIER_NODE, nonzero if any function with this name    has been declared virtual.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2 (NODE))
end_define

begin_comment
comment|/* Nonzero for FIELD_DECL means that this field is a    virtual baseclass field.  Used for printing debugging info.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VBASE_P
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.external_attr)
end_define

begin_comment
comment|/* Nonzero for FIELD_DECLs means that this field is private,    and can only be accessed within the scope of the class    which defines it (or its friends).  */
end_comment

begin_define
define|#
directive|define
name|TREE_PRIVATE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3 (NODE))
end_define

begin_comment
comment|/* Same, but tells if this field is private in current context.  */
end_comment

begin_define
define|#
directive|define
name|TREE_FIELD_PRIVATE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.this_private)
end_define

begin_comment
comment|/* Nonzero for FIELD_DECLs means that this field is protected,    and can only be accessed within the scope of the class    which defines it, its friends, or if there is a path in    the type hierarchy from the current class scope to    the one that defines it. */
end_comment

begin_define
define|#
directive|define
name|TREE_PROTECTED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_4 (NODE))
end_define

begin_comment
comment|/* Same, but tells if this field is private in current context.  */
end_comment

begin_define
define|#
directive|define
name|TREE_FIELD_PROTECTED
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.this_protected)
end_define

begin_define
define|#
directive|define
name|TREE_FIELD_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.this_public)
end_define

begin_comment
comment|/* Nonzero for _TYPE means that the _TYPE defines    at least one constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1(NODE))
end_define

begin_comment
comment|/* When appearing in an INDIRECT_REF, it means that the tree structure    underneath is actually a call to a constructor.  This is needed    when the constructor must initialize local storage (which can    be automatically destroyed), rather than allowing it to allocate    space from the heap.     When appearing in a SAVE_EXPR, it means that underneath    is a call to a constructor.     When appearing in a CONSTRUCTOR, it means that it was    a GNU C constructor expression.     When appearing in a FIELD_DECL, it means that this field    has been duly initialized in its constructor.  */
end_comment

begin_define
define|#
directive|define
name|TREE_HAS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1(NODE))
end_define

begin_comment
comment|/* Nonzero for _TYPE means that the _TYPE defines a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2(NODE))
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that creating an object of this type    will involve a call to a constructor.  This can apply to objects    of ARRAY_TYPE if the type of the elements needs a constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_CONSTRUCTING
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3(NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_NEEDS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.needs_constructor)
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that destroying an object of this type    will involve a call to a destructor.  This can apply to objects    of ARRAY_TYPE is the type of the elements needs a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_4(NODE))
end_define

begin_comment
comment|/* Nonzero for VAR_DECL node means that `external' was specified in    its declaration.  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXTERNAL
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1(NODE))
end_define

begin_comment
comment|/* Nonzero for SAVE_EXPR if used to initialize a PARM_DECL.  */
end_comment

begin_define
define|#
directive|define
name|PARM_DECL_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3(NODE))
end_define

begin_comment
comment|/* Nonzero in FUNCTION_DECL means it is really an operator.    Just used to communicate formatting information to dbxout.c.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OPERATOR
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.operator_attr)
end_define

begin_comment
comment|/* Nonzero for _TYPEs means that the argument defines or uses a    virtual function table for some of its methods.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.virtual_attr)
end_define

begin_comment
comment|/* May be useful for optimization using strictness analysis.    TYPE_ANY_ASSIGNS_THIS nonzero means that there is one constructor    within the hierarchy of TYPE which is known to assign to `this'.     TYPE_NONE_ASSIGNS_THIS nonzero means that it is known that    no constructor within the hierarchy of TYPE makes an assignment    to `this'.     Both of these can be zero, in which case it just means that we don't    have sufficient information yet.  They cannot, however, both be nonzero.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ANY_ASSIGNS_THIS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.any_assigns_this)
end_define

begin_define
define|#
directive|define
name|TYPE_NONE_ASSIGN_THIS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.none_assign_this)
end_define

begin_comment
comment|/* Define fields and accessors for nodes representing declared names.  */
end_comment

begin_comment
comment|/* C++: A derived class may be able to directly use the virtual    function table of a base class.  When it does so, it may    still have a decl node used to access the virtual function    table (so that variables of this type can initialize their    virtual function table pointers by name).  When such thievery    is commited, know exactly which base class's virtual function    table is the one being stolen.  This effectively computes the    transitive closure.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VPARENT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.arguments)
end_define

begin_comment
comment|/* C++: all of these are overloaded!  These apply only to TYPE_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIENDLIST
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.voffset)
end_define

begin_define
define|#
directive|define
name|DECL_UNDEFINED_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.context)
end_define

begin_define
define|#
directive|define
name|DECL_WAITING_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|((tree)(NODE)->decl.rtl)
end_define

begin_define
define|#
directive|define
name|SET_DECL_WAITING_FRIENDS
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
value|((NODE)->decl.rtl=(struct rtx_def*)VALUE)
end_define

begin_comment
comment|/* C++: all of these are overloaded! These apply only to FIELD_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STATIC_NAME
parameter_list|(
name|NODE
parameter_list|)
value|((tree)(NODE)->decl.offset)
end_define

begin_define
define|#
directive|define
name|SET_DECL_STATIC_NAME
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
value|((NODE)->decl.offset = (int)VAL)
end_define

begin_comment
comment|/* The DECL_VISIBILITY is used to record under which context    special visibility rules apply.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VISIBILITY
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.visibility)
end_define

begin_comment
comment|/* The DECL_VINDEX is used for FUNCTION_DECLS in two different ways.    Before the struct containing the FUNCTION_DECL is laid out,    DECL_VINDEX may point to a FUNCTION_DECL in a base class which    is the FUNCTION_DECL which this FUNCTION_DECL will replace as a virtual    function.  When the class is laid out, this pointer is changed    to an INT_CST node which is suitable for use as an index    into the virtual function table.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VINDEX
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->vindex)
end_define

begin_define
define|#
directive|define
name|SET_DECL_VINDEX
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->vindex = VAL)
end_define

begin_comment
comment|/* DECL_VCONTEXT is the *first* baseclass in which this FUNCTION_DECL    is defined.  Contrast this with DECL_CONTEXT (or DECL_FIELD_CONTEXT),    which is the *last* such baseclass.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VCONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->vcontext)
end_define

begin_comment
comment|/* DECL_FCONTEXT is the *first* baseclass in which this FIELD_DECL    is defined.  This only applies to vfield and vbase decls.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_FCONTEXT
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE) = (struct lang_decl *)(VALUE))
end_define

begin_define
define|#
directive|define
name|DECL_FCONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|((tree)DECL_LANG_SPECIFIC(NODE))
end_define

begin_comment
comment|/* For static member functions, which can never be virtual,    we need to know to what class the method belongs.  This    is where we stash the information.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STATIC_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->vcontext)
end_define

begin_comment
comment|/* C++: all of these are overloaded!    These apply to PARM_DECLs and VAR_DECLs and RESULT_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_REFERENCE_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|((tree)(NODE)->decl.arguments)
end_define

begin_define
define|#
directive|define
name|SET_DECL_REFERENCE_SLOT
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
value|((NODE)->decl.arguments=VAL)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_define
define|#
directive|define
name|DECL_DINDEX
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->dynamic_index)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* An enumeration of the kind of tags that C++ accepts.  */
end_comment

begin_enum
enum|enum
name|tag_types
block|{
name|record_type
block|,
name|class_type
block|,
name|union_type
block|,
name|enum_type
block|,
name|exception_type
block|}
enum|;
end_enum

begin_comment
comment|/* Zero means prototype weakly, as in ANSI C (no args means nothing).    Each language context defines how this variable should be set.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strict_prototype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strict_prototypes_lang_c
decl_stmt|,
name|strict_prototypes_lang_cplusplus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that if a label exists, and no other identifier    applies, use the value of the label.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_labels_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to collect statistics which might be expensive    and to print them when we are done.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_detailed_statistics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn in function declared in derived class has the    same name as a virtual in the base class, but fails to match the    type signature of any virtual function in the base class.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_overloaded_virtual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cplus-decl{2}.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|void_list_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|default_function_type
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|define_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_member_type
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|vtable_entry_type
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_vtable_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vfn_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|typedecl_for_tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|identifier_class_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|complete_array_type
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|coerce_new_type
argument_list|()
decl_stmt|,
name|coerce_delete_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A node that is a list (length 1) of error_mark_nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_mark_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ptr_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|class_type_node
decl_stmt|,
name|record_type_node
decl_stmt|,
name|union_type_node
decl_stmt|,
name|enum_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|exception_type_node
decl_stmt|,
name|unknown_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_temp_name
argument_list|()
decl_stmt|,
name|get_temp_aggr
argument_list|()
decl_stmt|,
name|get_temp_regvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|cleanup_after_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_type_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_force
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_convert_decl_to_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lang_printable_name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The largest size a virtual function table can be.    Must be a (power of 2).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VINDEX_MAX
end_ifndef

begin_define
define|#
directive|define
name|VINDEX_MAX
value|((unsigned)128)
end_define

begin_comment
comment|/* This is the integer ~ (vindex_max - 1).  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|vtbl_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Array type `(void *)[]' */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|vtbl_type_node
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|get_parm_types
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|grokopexpr
argument_list|()
decl_stmt|,
name|getaggrs
argument_list|()
decl_stmt|,
name|groktypefield
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grok_method_quals
argument_list|()
decl_stmt|,
name|grok_enum_decls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|finish_anon_union
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|,
name|long_long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For building calls to `delete'.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|integer_two_node
decl_stmt|,
name|integer_three_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_first_matching_virtual
argument_list|()
decl_stmt|,
name|get_abstract_virtuals
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cplus-typeck.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_x_conditional_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|merge_component_comparisons
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_x_unary_op
argument_list|()
decl_stmt|,
name|build_x_binary_op
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_component_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_function_call
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_x_indirect_ref
argument_list|()
decl_stmt|,
name|build_x_array_ref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_modify_expr
argument_list|()
decl_stmt|,
name|build_x_modify_op_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_m_component_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_component_type_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_arrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_component_ref_1
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|datatype
argument_list|()
decl_stmt|,
name|unary_complex_lvalue
argument_list|()
decl_stmt|,
name|target_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_return_stmt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|actualparameterlist
argument_list|()
decl_stmt|,
name|commonparms
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|cplus_size_in_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|cplus_sizeof
argument_list|()
decl_stmt|,
name|cplus_sizeof_nowarn
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|error_mark_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cplus-type2.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|basetype_or_else
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in tree.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_let
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|decl_type_context
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-tree.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_array_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_method_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_classtype_variant
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|hash_tree_cons
argument_list|()
decl_stmt|,
name|hash_tree_chain
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|list_hash_lookup_or_cons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|layout_basetypes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|copy_to_permanent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-except.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_exception_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_exception_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_exception_object
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_exception_variant
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|lookup_exception_type
argument_list|()
decl_stmt|,
name|lookup_exception_cname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|lookup_exception_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cplus_expand_start_catch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cplus_expand_end_try
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-class.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_class_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|prev_class_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_lang_name
decl_stmt|,
name|lang_name_cplusplus
decl_stmt|,
name|lang_name_c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|do_identifier
argument_list|()
decl_stmt|,
name|hack_identifier
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|hack_operator
argument_list|()
decl_stmt|,
name|hack_wrapper
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_pointer_to
argument_list|()
decl_stmt|,
name|convert_pointer_to_vbase
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_to_reference
argument_list|()
decl_stmt|,
name|convert_to_aggr
argument_list|()
decl_stmt|,
name|convert_aggr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_new
argument_list|()
decl_stmt|,
name|build_x_delete
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_new
argument_list|()
decl_stmt|,
name|build_vec_new
argument_list|()
decl_stmt|,
name|build_delete
argument_list|()
decl_stmt|,
name|build_vec_delete
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|make_destructor_name
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_scoped_ref
argument_list|()
decl_stmt|,
name|build_vfield_ref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_method_call
argument_list|()
decl_stmt|,
name|build_overload_call
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_type_pathname
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|start_method
argument_list|()
decl_stmt|,
name|start_type_method
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|finish_method
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|lookup_field
argument_list|()
decl_stmt|,
name|lookup_fnfields
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushclass
argument_list|()
decl_stmt|,
name|popclass
argument_list|()
decl_stmt|,
name|pushclasstype
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_operator_fnname
argument_list|()
decl_stmt|,
name|build_opfncall
argument_list|()
decl_stmt|,
name|build_type_conversion
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_wrapper
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Points to the name of that function. May not be the DECL_NAME    of CURRENT_FUNCTION_DECL due to overloading */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|original_function_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IS_AGGR_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|(TREE_CODE (t) == RECORD_TYPE || TREE_CODE (t) == UNION_TYPE)
end_define

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_CODE
parameter_list|(
name|t
parameter_list|)
define|\
value|(t == RECORD_TYPE || t == UNION_TYPE)
end_define

begin_decl_stmt
specifier|extern
name|tree
name|build_decl_overload
argument_list|()
decl_stmt|,
name|build_typename_overload
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_destructor_call
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|,
name|current_class_type
decl_stmt|,
name|current_class_decl
decl_stmt|,
name|C_C_D
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_vtable_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cplus-init.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|resolve_offset_ref
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|purpose_member
argument_list|()
decl_stmt|,
name|value_member
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|check_base_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_member_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|global_base_init_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_base_init_list
decl_stmt|,
name|current_member_init_list
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_decl_stmt
specifier|extern
name|tree
name|get_linktable_name
argument_list|()
decl_stmt|,
name|get_dtable_name
argument_list|()
decl_stmt|,
name|get_sos_dtable
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|tree
name|get_member_function
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_member_call
argument_list|()
decl_stmt|,
name|build_offset_ref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_assigns_this
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_just_assigned_this
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_parms_stored
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cannot use '$' up front, because this confuses gdb.    Note that any format of this kind *must* make the    format for `this' lexicgraphically less than any other    parameter name, i.e. "$this" is less than anything else can be.     Note that all forms in which the '$' is significant are long enough    for direct indexing.  */
end_comment

begin_comment
comment|/* Define NO_DOLLAR_IN_LABEL in your favorite tm file if your assembler    doesn't allow '$' in symbol names.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOLLAR_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|JOINER
value|'$'
end_define

begin_define
define|#
directive|define
name|THIS_NAME
value|"$t"
end_define

begin_define
define|#
directive|define
name|VPTR_NAME
value|"$v"
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|"$eh_throw"
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_DECL_FORMAT
value|"_$_%s"
end_define

begin_define
define|#
directive|define
name|WRAPPER_DECL_FORMAT
value|"__W$%s"
end_define

begin_define
define|#
directive|define
name|WRAPPER_PRED_DECL_FORMAT
value|"__P$%s"
end_define

begin_define
define|#
directive|define
name|ANTI_WRAPPER_DECL_FORMAT
value|"__w$%s"
end_define

begin_define
define|#
directive|define
name|IN_CHARGE_NAME
value|"__in$chrg"
end_define

begin_define
define|#
directive|define
name|AUTO_VTABLE_NAME
value|"__vtbl$me__"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"_$tmp_"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_FORMAT
value|"_$tmp_%d"
end_define

begin_define
define|#
directive|define
name|OPERATOR_ASSIGN_FORMAT
value|"op$assign_%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_MODIFY_FORMAT
value|"op$modify"
end_define

begin_define
define|#
directive|define
name|OPERATOR_METHOD_FORMAT
value|"op$method_call"
end_define

begin_define
define|#
directive|define
name|OPERATOR_NEW_FORMAT
value|"op$new"
end_define

begin_define
define|#
directive|define
name|OPERATOR_DELETE_FORMAT
value|"op$delete"
end_define

begin_define
define|#
directive|define
name|OPERATOR_FORMAT
value|"op$%s"
end_define

begin_define
define|#
directive|define
name|VTBL_PTR_TYPE
value|"$vtbl_ptr_type"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_FORMAT
value|"_vt$%s"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"_vptr$"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"_vptr$%s"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME
value|"_vb$"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"_vb$%s"
end_define

begin_define
define|#
directive|define
name|STATIC_NAME_FORMAT
value|"_%s$%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_TYPENAME_FORMAT
value|"type$"
end_define

begin_define
define|#
directive|define
name|FILE_FUNCTION_FORMAT
value|"_GLOBAL_$D$%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"$_%d"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_DOLLAR_IN_LABEL */
end_comment

begin_define
define|#
directive|define
name|JOINER
value|'.'
end_define

begin_define
define|#
directive|define
name|THIS_NAME
value|".t"
end_define

begin_define
define|#
directive|define
name|VPTR_NAME
value|".v"
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|".eh_throw"
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_DECL_FORMAT
value|"_._%s"
end_define

begin_define
define|#
directive|define
name|WRAPPER_DECL_FORMAT
value|"__W.%s"
end_define

begin_define
define|#
directive|define
name|WRAPPER_PRED_DECL_FORMAT
value|"__P.%s"
end_define

begin_define
define|#
directive|define
name|ANTI_WRAPPER_DECL_FORMAT
value|"__w.%s"
end_define

begin_define
define|#
directive|define
name|IN_CHARGE_NAME
value|"__in.chrg"
end_define

begin_define
define|#
directive|define
name|AUTO_VTABLE_NAME
value|"__vtbl.me__"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"_.tmp_"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_FORMAT
value|"_.tmp_%d"
end_define

begin_define
define|#
directive|define
name|OPERATOR_ASSIGN_FORMAT
value|"op.assign_%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_MODIFY_FORMAT
value|"op.modify"
end_define

begin_define
define|#
directive|define
name|OPERATOR_METHOD_FORMAT
value|"op.method_call"
end_define

begin_define
define|#
directive|define
name|OPERATOR_NEW_FORMAT
value|"op.new"
end_define

begin_define
define|#
directive|define
name|OPERATOR_DELETE_FORMAT
value|"op.delete"
end_define

begin_define
define|#
directive|define
name|OPERATOR_FORMAT
value|"op.%s"
end_define

begin_define
define|#
directive|define
name|VTBL_PTR_TYPE
value|".vtbl_ptr_type"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_FORMAT
value|"_vt.%s"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"_vptr."
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"_vptr.%s"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME
value|"_vb."
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"_vb.%s"
end_define

begin_define
define|#
directive|define
name|STATIC_NAME_FORMAT
value|"_%s.%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_TYPENAME_FORMAT
value|"type."
end_define

begin_define
define|#
directive|define
name|FILE_FUNCTION_FORMAT
value|"_GLOBAL_.D.%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"._%d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_DOLLAR_IN_LABEL */
end_comment

begin_define
define|#
directive|define
name|DESTRUCTOR_NAME_FORMAT
value|"~%s"
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME_FORMAT
value|"()%s"
end_define

begin_define
define|#
directive|define
name|WRAPPER_PRED_NAME_FORMAT
value|"()?%s"
end_define

begin_define
define|#
directive|define
name|ANTI_WRAPPER_NAME_FORMAT
value|"~()%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_MODIFY_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|OPERATOR_METHOD_LENGTH
value|13
end_define

begin_define
define|#
directive|define
name|OPERATOR_NEW_LENGTH
value|5
end_define

begin_define
define|#
directive|define
name|OPERATOR_DELETE_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|EXCEPTION_NAME_LENGTH
value|12
end_define

begin_define
define|#
directive|define
name|FILE_FUNCTION_PREFIX_LEN
value|9
end_define

begin_define
define|#
directive|define
name|VTABLE_DELTA_NAME
value|"delta"
end_define

begin_define
define|#
directive|define
name|VTABLE_DELTA2_NAME
value|"delta2"
end_define

begin_define
define|#
directive|define
name|VTABLE_INDEX_NAME
value|"index"
end_define

begin_define
define|#
directive|define
name|VTABLE_PFN_NAME
value|"pfn"
end_define

begin_define
define|#
directive|define
name|EXCEPTION_CLEANUP_NAME
value|"exception cleanup"
end_define

begin_define
define|#
directive|define
name|THIS_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1] == 't')
end_define

begin_define
define|#
directive|define
name|VPTR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == JOINER)
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[2] == 'W' \&& IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)
end_define

begin_define
define|#
directive|define
name|WRAPPER_PRED_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[2] == 'P' \&& IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)
end_define

begin_define
define|#
directive|define
name|ANTI_WRAPPER_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[2] == 'w' \&& IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)
end_define

begin_define
define|#
directive|define
name|WRAPPER_OR_ANTI_WRAPPER_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(IDENTIFIER_POINTER (ID_NODE)[1] == '_' \&& (IDENTIFIER_POINTER (ID_NODE)[2]|('W'^'w')) == 'w' \&& IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)
end_define

begin_define
define|#
directive|define
name|OPERATOR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[2] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1])
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[3] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[2] == 't'\&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[3] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[2] == 'b'\&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

begin_define
define|#
directive|define
name|OPERATOR_TYPENAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[4] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[3] \&& IDENTIFIER_POINTER (ID_NODE)[2] \&& IDENTIFIER_POINTER (ID_NODE)[1])
end_define

begin_define
define|#
directive|define
name|TEMP_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, sizeof (AUTO_TEMP_NAME)-1))
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VFIELD_NAME, sizeof(VFIELD_NAME)-1))
end_define

begin_comment
comment|/* For anonymous aggregate types, we need some sort of name to    hold on to.  In practice, this should not appear, but it should    not be harmful if it does.  */
end_comment

begin_define
define|#
directive|define
name|ANON_AGGRNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER)
end_define

begin_define
define|#
directive|define
name|ANON_PARMNAME_FORMAT
value|"_%d"
end_define

begin_define
define|#
directive|define
name|ANON_PARMNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[1]<= '9')
end_define

begin_enum
enum|enum
name|visibility_type
block|{
name|visibility_default
block|,
name|visibility_public
block|,
name|visibility_private
block|,
name|visibility_protected
block|,
name|visibility_default_virtual
block|,
name|visibility_public_virtual
block|,
name|visibility_private_virtual
block|, }
enum|;
end_enum

begin_function_decl
name|enum
name|visibility_type
name|compute_visibility
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-lex.c  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_unit_name
decl_stmt|,
name|current_unit_language
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|operator_name_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Things for handling inline functions.  */
end_comment

begin_struct
struct|struct
name|pending_inline
block|{
name|struct
name|pending_inline
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next in chain */
name|int
name|lineno
decl_stmt|;
comment|/* line number we got the text from */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* name of file we were processing */
name|tree
name|fndecl
decl_stmt|;
comment|/* FUNCTION_DECL that brought us here */
name|int
name|token
decl_stmt|;
comment|/* token we were scanning */
name|int
name|token_value
decl_stmt|;
comment|/* value of token we were scanning (YYSTYPE) */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* pointer to character stream */
name|int
name|len
decl_stmt|;
comment|/* length of stream */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|tree
name|combine_strings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-method.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|wrapper_name
decl_stmt|,
name|wrapper_pred_name
decl_stmt|,
name|anti_wrapper_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pending_inline
modifier|*
name|pending_inlines
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|print_fndecl_with_types
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 1 for -fall-virtual: make every member function (except    constructors) lay down in the virtual function table.    Calls can then either go through the virtual function table or not,    depending on whether we know what function will actually be called.     2 for -fSOS: make every member function (including constructors)    lay down in the virtual function table.  All calls go through the    virtual function table: this takes the place of using a linker.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_all_virtual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that we cannot make optimizing assumptions about `this'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_this_is_variable
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|overload_flags
block|{
name|NO_SPECIAL
init|=
literal|0
block|,
name|DTOR_FLAG
block|,
name|OP_FLAG
block|,
name|TYPENAME_FLAG
block|,
name|WRAPPER_FLAG
block|,
name|WRAPPER_PRED_FLAG
block|,
name|ANTI_WRAPPER_FLAG
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|tree
name|default_conversion
argument_list|()
decl_stmt|,
name|pushdecl
argument_list|()
decl_stmt|,
name|pushdecl_top_level
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_instance_name
argument_list|()
decl_stmt|,
name|do_decl_overload
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|maybe_build_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_instantiated_decl
argument_list|()
decl_stmt|,
name|instantiate_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|require_instantiated_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vtbl_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_anon_parm_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|resolves_to_fixed_type_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_friend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|grokclassfn
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|current_class_decl
decl_stmt|,
name|C_C_D
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PARM_DECL: the class instance variable */
end_comment

begin_comment
comment|/* The following two can be derived from the previous one */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IDENTIFIER_NODE: name of current class */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* _TYPE: the type of the current class */
end_comment

begin_comment
comment|/* The following structure is used when comparing various alternatives    for overloading.  The unsigned quantity `strikes.i' is used    for fast comparison of two possibilities.  This number is an    aggregate of four constituents:       EVIL: if this is non-zero, then the candidate should not be considered      USER: if this is non-zero, then a user-defined type conversion is needed      B_OR_D: if this is non-zero, then use a base pointer instead of the              type of the pointer we started with.      EASY: if this is non-zero, then we have a builtin conversion            (such as int to long, int to float, etc) to do.     If two candidates require user-defined type conversions, and the    type conversions are not identical, then an ambiguity error    is reported.     If two candidates agree on user-defined type conversions,    and one uses pointers of strictly higher type (derived where    another uses base), then that alternative is silently chosen.     If two candidates have a non-monotonic derived/base pointer    relationship, and/or a non-monotonic easy conversion relationship,    then a warning is emitted to show which paths are possible, and    which one is being chosen.     For example:     int i;    double x;     overload f;    int f (int, int);    double f (double, double);     f (i, x);	// draws a warning     struct B    {      f (int);    } *bb;    struct D : B    {      f (double);    } *dd;     dd->f (x);	// exact match    dd->f (i);	// draws warning     Note that this technique really only works for 255 arguments.  Perhaps    this is not enough.  */
end_comment

begin_struct
struct|struct
name|candidate
block|{
name|tree
name|function
decl_stmt|;
comment|/* A FUNCTION_DECL */
name|unsigned
name|char
name|evil
decl_stmt|;
comment|/* ~0 if this will never convert.  */
name|unsigned
name|char
name|user
decl_stmt|;
comment|/* ~0 if at least one user-defined type conv.  */
name|unsigned
name|short
name|b_or_d
decl_stmt|;
comment|/* count number of derived->base conv.  */
name|unsigned
name|short
name|easy
decl_stmt|;
comment|/* count number of builtin type conv.  */
name|tree
name|arg
decl_stmt|;
comment|/* an _EXPR node that is first parm to function */
name|unsigned
name|short
modifier|*
name|harshness
decl_stmt|;
comment|/* Indexed by argument number, encodes 				   evil, user, b_or_d, and easy strikes for 				   that argument. 				   At end of array, we store the index+1 where we 				   started using default parameters, or 0 				   if there are none.  */
union|union
block|{
name|tree
name|field
decl_stmt|;
comment|/* If no evil strikes, the FUNCTION_DECL of 				   the function (if a member function).  */
name|int
name|bad_arg
decl_stmt|;
comment|/* the index of the first bad argument: 				   0 if no bad arguements> 0 is first bad argument 				   -1 if extra actual arguments 				   -2 if too few actual arguments. 				   -3 if const/non const method mismatch.  */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rank_for_overload
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|candidate
modifier|*
name|ideal_candidate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Some macros for char-based bitfields.  */
end_comment

begin_define
define|#
directive|define
name|B_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3] |= (1<< (x&7)))
end_define

begin_define
define|#
directive|define
name|B_CLR
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3]&= ~(1<< (x&7)))
end_define

begin_define
define|#
directive|define
name|B_TST
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3]& (1<< (x&7)))
end_define

begin_comment
comment|/* These are uses as bits in flags passed to build_method_call    to control its error reporting behavior.     LOOKUP_PROTECT means flag visibility violations.    LOOKUP_COMPLAIN mean complain if no suitable member function      matching the arguments is found.    LOOKUP_NORMAL is just a combination of these two.    LOOKUP_AGGR requires the instance to be of aggregate type.    LOOKUP_NONVIRTUAL means make a direct call to the member function found    LOOKUP_GLOBAL means search through the space of overloaded functions,      rather than the space of member functions.    LOOKUP_HAS_IN_CHARGE means that the "in charge" variable is already      in the parameter list.    LOOKUP_PROTECTED_OK means that even if the constructor we find appears      to be non-visibile to current scope, call it anyway.    LOOKUP_DYNAMIC means call dynamic functions, a la SOS.    LOOKUP_NO_CONVERSION means that user-defined conversions are not      permitted.  Built-in conversions are permitted.    LOOKUP_DESTRUCTOR means explicit call to destructor.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PROTECT
value|(1)
end_define

begin_define
define|#
directive|define
name|LOOKUP_COMPLAIN
value|(2)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NORMAL
value|(3)
end_define

begin_define
define|#
directive|define
name|LOOKUP_AGGR
value|(4)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NONVIRTUAL
value|(8)
end_define

begin_define
define|#
directive|define
name|LOOKUP_GLOBAL
value|(16)
end_define

begin_define
define|#
directive|define
name|LOOKUP_HAS_IN_CHARGE
value|(32)
end_define

begin_define
define|#
directive|define
name|LOOKUP_SPECULATIVELY
value|(64)
end_define

begin_define
define|#
directive|define
name|LOOKUP_PROTECTED_OK
value|(128)
end_define

begin_define
define|#
directive|define
name|LOOKUP_DYNAMIC
value|(256)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NO_CONVERSION
value|(512)
end_define

begin_define
define|#
directive|define
name|LOOKUP_DESTRUCTOR
value|(512)
end_define

begin_comment
comment|/* Anatomy of a DECL_FRIENDLIST (which is a TREE_LIST):    purpose = friend name (IDENTIFIER_NODE);    value = TREE_LIST of FUNCTION_DECLS;    chain, type = EMPTY;  */
end_comment

begin_define
define|#
directive|define
name|FRIEND_NAME
parameter_list|(
name|LIST
parameter_list|)
value|(TREE_PURPOSE (LIST))
end_define

begin_define
define|#
directive|define
name|FRIEND_DECLS
parameter_list|(
name|LIST
parameter_list|)
value|(TREE_VALUE (LIST))
end_define

begin_decl_stmt
specifier|extern
name|tree
name|get_temp_name
argument_list|()
decl_stmt|,
name|get_temp_aggr
argument_list|()
decl_stmt|,
name|get_temp_regvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|build_method_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_type_conversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_functional_cast
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_scoped_method_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|decl_constant_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-init.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|resolve_offset_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_with_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-lex.c  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|operator_name_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_base_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_opid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Indexed by TREE_CODE, these tables give C-looking names to    operators represented by TREE_CODES.  For example,    opname_tab[(int) MINUS_EXPR] == "-".  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|opname_tab
decl_stmt|,
modifier|*
modifier|*
name|assignop_tab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_lang_decl
argument_list|()
decl_stmt|,
name|build_lang_field_decl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|make_lang_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cons_up_default_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-convert.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|convert_from_reference
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in cplus-search.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|init_vbase_pointers
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_vbase_pointer
argument_list|()
decl_stmt|,
name|build_vbase_path
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_fnfield
argument_list|()
decl_stmt|,
name|next_baselink
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|get_base_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_vbase_types
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_baselinks
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_wrapper
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|make_assoc
argument_list|()
decl_stmt|,
name|copy_assoc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|assoc_value
argument_list|()
decl_stmt|,
name|virtual_member
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PRINT_LANG_DECL
end_define

begin_define
define|#
directive|define
name|PRINT_LANG_TYPE
end_define

begin_define
define|#
directive|define
name|UNKNOWN_TYPE
value|LANG_TYPE
end_define

begin_decl_stmt
specifier|extern
name|union
name|tree_node
name|ERROR_MARK_NODE
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|error_mark_node
value|(&ERROR_MARK_NODE)
end_define

begin_comment
comment|/* -- end of C++ */
end_comment

end_unit

