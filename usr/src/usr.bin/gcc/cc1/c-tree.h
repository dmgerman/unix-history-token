begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
decl_stmt|,
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
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->label_value)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->implicit_decl)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->error_locus)
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
comment|/* in c-typecheck.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref
argument_list|()
decl_stmt|,
name|build_conditional_expr
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
name|void
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
name|grokfield
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* Add qualifiers to a type, in the fashion for C.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|c_build_type_variant
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

end_unit

